/*
 * File:   task_scheduler.c
 * Author: M91406
 *
 * Created on May 17, 2019, 9:17 PM
 */


#include "_root/generic/os_Scheduler.h" 

/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/
volatile bool run_scheduler = true;     // Flag used to reset the main loop, forcing a warm reset when set != 1

#if __DEBUG
volatile uint16_t task_time_buffer[CPU_LOAD_DEBUG_BUFFER_LENGTH];
volatile uint16_t cpu_time_buffer[CPU_LOAD_DEBUG_BUFFER_LENGTH];
#endif

/*!OS_Execute
 * ************************************************************************************************
 * Summary:
 * Main scheduler function
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * This scheduler represents the main() loop of the embedded firmware. When 
 * it's called, it's executed continuously until the flag "run_scheduler" is 
 * set to FALSE by any external process.
 * ***********************************************************************************************/
#if (START_OS_BEFORE_MAIN==0)
volatile uint16_t OS_Execute(void) {
#else
void __attribute__((user_init)) OS_Execute(void) {
    Nop(); // When the scheduler is configured as ((user_init)) and executed before 
    Nop(); // main(), this NOPs provide a start address for the debugger to step in.
    Nop();
#endif

    // Local variables
    volatile uint16_t fres = 1;  // Internal test variable tracking return values of sub-functions
    volatile uint32_t dmt_cnt = 0; // Buffer for dead man timer counter check
    volatile uint16_t tmr_cnt = 0; // Buffer variable for system timer check
    
    #if (USE_TASK_MANAGER_TIMING_DEBUG_ARRAYS == 1)
    volatile uint16_t cnt=0; // In debug mode , this counter is used to fill profiling arrays
    #endif
    

    // Right after system reset, first check for root-cause of previous device reset
    fres &= CheckCPUResetRootCause();

    // Initialize essential chip features and peripheral modules to boot up system
    #if ((EXECUTE_MCC_SYSTEM_INITIALIZE == 0) && (EXECUTE_DEVICE_RESET == 1))
    fres &= DEVICE_Reset();
    #endif

    // The User Startup Code might be required in some designs to enable 
    #if (EXECUTE_USER_STARTUP_CODE == 1)
    fres &= ExecuteUserStartupCode();
    #endif
    
    // Initialize CPU Clock, CPU/DSP, Interrupt Controller and User-Defined GPIO settings
    #if (EXECUTE_MCC_SYSTEM_INITIALIZE == 0)
    fres &= CLOCK_Initialize();
    fres &= DEVICE_Initialize();
    #endif
    
    // Initialize task manager and OS and user defined fault objects
    fres &= OS_Initialize();

    DMTCONbits.ON = 1;  // Enable Dead Man Timer
    
    // after the basic steps, the rest of the configuration runs as part of the scheduler,
    // where execution can be monitored and faults can be properly handled.
    while (run_scheduler) 
    {
      
        // Clear Dead Man Timer counter
        if(DMTSTATbits.WINOPN) {
            DMTPRECLRbits.STEP1 = 0b01000000;
            DMTCLRbits.STEP2 = 0b00001000;
        }
        
        task_mgr.cpu_load.ticks = 0; // Clear CPU tick counter

        // Wait for timer to expire before calling the next task
        while ((!TASK_MGR_TMR_IF) && (*task_mgr.os_timer.reg_counter != tmr_cnt))
        {
            task_mgr.cpu_load.ticks++;                          // Increment CPU tick counter
            tmr_cnt = *task_mgr.os_timer.reg_counter;           // Capture system timer counter
        }

        dmt_cnt = (((uint32_t)DMTCNTH << 16) | DMTCNTL);    // Capture Dead Man Timer counter
        
#if (USE_TASK_EXECUTION_CLOCKOUT_PIN == 1)
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH; // Drive debug pin high
#endif
#endif

        // Calculate CPU load based on incremented ticks during while loop
        task_mgr.cpu_load.ticks *= task_mgr.cpu_load.loop_nomblk;    // Calculate the accumulated CPU cycles
        task_mgr.cpu_load.load  = (1000 - (uint16_t)((task_mgr.cpu_load.ticks * task_mgr.cpu_load.load_factor)>>16));
        task_mgr.cpu_load.load_max_buffer |= task_mgr.cpu_load.load;


        TASK_MGR_TMR_IF = 0; // Reset timer ISR flag bit

        
#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                  // Drive debug pin low
#endif
#endif
        
        // Call most recent task with execution time measurement
        fres &= os_ProcessTaskQueue();     // Step through pre-defined task lists

#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH;                 // Drive debug pin high
#endif
#endif

        // Capture the most recent system status to respond to changes in 
        // user defined, system level states. (calls user-code module)
        fres &= APPLICATION_CaptureSystemStatus();

        
#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                 // Drive debug pin high
#endif
#endif

        // 'fres'-check is mapped into the operating system component check status bit
        task_mgr.status.bits.os_component_check = fres;
        
        // call the fault handler to check all defined fault objects
        fres &= exec_FaultCheckAll();
        
#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH;                 // Drive debug pin low
#endif
#endif

    
        // Reset Watchdog Timer
        // ToDo: Move swdt_reset(); out to task queues
        // ToDo: Add windowed WDT option to library
        // ToDo: Add compile switch for option __DEBUG to disable watchdog in debug sessions
        //Remove: fres &= swdt_reset();
        

        // if the active queue pointer is at/beyond the queue boundary, roll-over and/or switch task list
        if ( ((task_mgr.task_queue.active_index + 1) > (task_mgr.task_queue.ubound)) ||
             (task_mgr.pre_op_mode.value != task_mgr.op_mode.value) )
        // Check for list boundary or operating mode switch
        {
            // at the roll-over point (one tick above the array size) the operation mode switch check
            // is executed by default

            fres &= os_CheckOperationModeStatus();
            task_mgr.task_queue.active_index = 0; // If end of list has been reached, jump back to first item
            task_mgr.task_queue.active_task_id = tasks[task_mgr.task_queue.active_index].id;
        }
        // if the active queue pointer is within the queue boundary
        else
        {
            task_mgr.task_queue.active_index++; // Increment task queue pointer
        }

        
#if (USE_TASK_EXECUTION_CLOCKOUT_PIN == 1)
#ifdef TS_CLOCKOUT_PIN_WR
TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                  // Drive debug pin low
#endif
#endif
        
#if (USE_TASK_MANAGER_TIMING_DEBUG_ARRAYS == 1)
// In debugging mode CPU load and task time is measured and logged in two arrays
// to examine the recent code execution profile
#pragma message "CPU Meter and Task Execution Profile Arrays are available"

if(cnt == CPU_LOAD_DEBUG_BUFFER_LENGTH)
{
    Nop();  // place breakpoint here to hold firmware when arrays are filled
    Nop();
    Nop();
    cnt = 0;
}
else
{
    task_time_buffer[cnt] = task_mgr.task_queue.active_task_time;   // Log task most recent time
    cpu_time_buffer[cnt] = task_mgr.cpu_load.load;    // Log most recent CPU Load
    cnt++;                                      // Increment array index
}
#endif
        
    }   // End of main loop
    // =====================================================================
    
    // =====================================================================
    // When the scheduler has been terminated by an internal error or software command,
    // the interrupt and traps status is captured and a warm CPU reset is initiated
    
    CaptureCPUInterruptStatus(); // Capture all relevant interrupt and reset status bits
    traplog.status.bits.sw_reset = true; // Set flag bit indicating CPU was restarted by software
    traplog.reset_count++;  // Increment the persistent soft-reset counter to stop restarting after certain number of restart attempts

    // To prevent that the CPU ends up restarting endlessly, the traplog object 
    // tracks the number or CPU resets and stalls here after a user defined number
    // of attempts defined by TASK_MGR_CPU_RESET_LIMIT
    
    if (traplog.reset_count < TASK_MGR_CPU_RESET_LIMIT) {
    // Initiate CPU Reset
        CPU_RESET;    
    }
    else {
    // If CPU has been reset a user defined number of attempts 
    // defined by TASK_MGR_CPU_RESET_LIMIT, the software is stalled 
    // here
        while (1)  
        { Nop(); Nop(); Nop(); }
    }
    
// if this code line is ever reached, something really bad had happened...
#if (START_OS_BEFORE_MAIN==0)
    return(0);   
#else
    return;
#endif

}

