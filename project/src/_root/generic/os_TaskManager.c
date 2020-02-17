/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * ***************************************************************************/
/*!os_TaskManager.c
 *****************************************************************************
 * File:   os_TaskManager.c
 *
 * Summary:
 * Task manager initialization, operation mode switch-over and task execution routines
 *
 * Description:	
 * This file holds all routines of the basic scheduler functions covering scheduler 
 * settings initialization, basic task execution with time measurement and the 
 * operation mode switch over routine. CPU meter and time quota fault detection
 * are located in the main loop.
 * 
 *
 * References:
 * -
 *
 * See also:
 * os_Scheduler.c
 * os_Scheduler.h
 * 
 * Revision history: 
 * 07/27/16     Initial version
 * Author: M91406
 * Comments:
 *****************************************************************************/


#include <xc.h>
#include <stdint.h>
#include <stddef.h>

#include "_root/config/task_manager_config.h"
#include "_root/generic/os_TaskManager.h"
#include "apl/config/UserTasks.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Private declarations for internal functions
#define CaptureStackFrame(x) __extension__ ({ \
    volatile uint16_t* __x = (x), __v; \
    __asm__ ( \
        "mov %0, w0 \n" \
        "mov w14, [w0] \n" \
        "mov w15, [w0+2] \n" \
         : "=d" (__v) : "d" (__x)); __v; \
})

#define RestoreStackFrame(x) __extension__ ({ \
    volatile uint16_t* __x = (x), __v; \
    __asm__ ( \
        "ctxtswp #0;\n\t" \
        "mov %0, w0 \n" \
        "mov [w0], w14 \n" \
        "mov [w0+2], w15 \n" \
        "goto TASK_MGR_JUMP_TARGET \n" \
        : "=d" (__v) : "d" (__x)); __v; \
})

// Data structure used as WREG data buffer of the Rescue Timer
typedef struct {
    volatile uint16_t wreg14;   // Frame pointer buffer
    volatile uint16_t wreg15;   // Stack pointer buffer
    volatile uint16_t cpu_stat; // CPU Status register SR
} __attribute__((packed)) WREG_SET_t;

volatile WREG_SET_t rescue_state;   // Rescue state data structure
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Private label for resetting a task queue
#define TASK_ZERO   0   

// Task Manager
volatile TASK_MANAGER_t task_mgr; // Declare a data structure holding the settings of the task manager
volatile TASKMGR_TASK_CONTROL_t tasks[TASK_TABLE_SIZE]; // Array of task object declared in UserTasks.c/h

//------------------------------------------------------------------------------
// execute task manager scheduler
//------------------------------------------------------------------------------

volatile uint16_t os_ProcessTaskQueue(void) {

    volatile uint16_t f_ret = 1; // This function return value
    volatile uint16_t retval = 0; // User-Function return value buffer
    volatile uint32_t t_start = 0, t_stop = 0, t_buf = 0; // Timing control variables

    // The task manager scheduler runs through the currently selected task queue in n steps.
    // After the last item of each queue the operation mode switch-over check is performed and the 
    // task tick index is reset to zero, which causes the first task of the queue to be called at 
    // the next scheduler tick.

    // Indices 0 ... (n-1) are calling queued user tasks
    task_mgr.task_queue.active_task_id = task_mgr.task_queue.active_queue[task_mgr.task_queue.active_index]; // Pick next task in the queue

    // Determine error code for the upcoming task
    task_mgr.proc_code.segment.op_mode = (uint8_t)(task_mgr.op_mode.value);    // log operation mode
    task_mgr.proc_code.segment.task_id = (uint8_t)(task_mgr.task_queue.active_task_id);   // log upcoming task-ID

    // Capture task start time for time quota monitoring
    t_start = *task_mgr.os_timer.reg_counter; // Capture timer counter before task execution

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // THIS IS WHERE THE NEXT TASK IS CALLED
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        CaptureStackFrame((volatile uint16_t*)&rescue_state); // Capture recent stack frame
        rescue_state.cpu_stat = SR;              // Capture CPU status register
        
        *task_mgr.os_timer.reg_period = task_mgr.os_timer.rescue_period; // Program Rescue Timer period
        TASK_MGR_TMR_IE = true; // Enable Rescue timer interrupt
    
        // Execute next task in the queue
        if ((tasks[task_mgr.task_queue.active_task_id].enabled) && 
            (Task_Table[task_mgr.task_queue.active_task_id] != NULL)) {
            retval = Task_Table[task_mgr.task_queue.active_task_id](); // Execute currently selected task
        }

        Nop();  // A few NOPs distance from the previous IF statement 
        Nop();  // are required in code optimization level #3
        
        __asm__ ("TASK_MGR_JUMP_TARGET: \n");   // This is the label used by the rescue timer when 
                                                // an active task is being killed
        
        TASK_MGR_TMR_IE = false;                // Disable Rescue timer interrupt
        SR = rescue_state.cpu_stat;             // Restore CPU status register
        *task_mgr.os_timer.reg_period = task_mgr.os_timer.master_period; // Program OS Timer period
        
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    
    // Capture time to determine elapsed task executing time
    t_stop = *task_mgr.os_timer.reg_counter;
    
    // Copy return value into process code for fault analysis
    tasks[task_mgr.task_queue.active_task_id].return_value = retval;
    task_mgr.task_queue.active_retval = retval;

    // Check if OS task period timer has overrun while the recent task was executed
    if(TASK_MGR_TMR_IF)
    { 
        task_mgr.status.bits.task_mgr_period_overrun = true; // Set task manager period overrun flag bit

        // if timer has overrun while executing task, try to capture the total elapsed time
        // assuming the timer only overran once (status horizon)
        
        t_stop = (*task_mgr.os_timer.reg_period - t_stop); // capture expired time until end of timer period
        t_buf = (t_stop + t_start); // add elapsed time into the new period in 32-bit number space
        if (t_buf > 0xFFFF) // Check for 16-bit boundary
        { t_buf = 0xFFFF; } // Saturate execution time result at unsigned 16-bit maximum to prevent overrun
        
    }
    else // if timer has not overrun...
    { 
        task_mgr.status.bits.task_mgr_period_overrun = false; // Clear task manager period overrun flag bit
        
        if(t_stop > t_start) // if 
        { t_buf = (t_stop - t_start); } // measure most recent task time
        else
        { f_ret = 0; }
    }

    // Track individual task execution time
    tasks[task_mgr.task_queue.active_task_id].task_period = (volatile uint16_t)t_buf; // capture execution time
    task_mgr.task_queue.active_task_time = (volatile uint16_t)t_buf; // capture execution time
    
    // If execution time exceeds previous period maximum, override maximum time buffer value
    if((volatile uint16_t)t_buf > tasks[task_mgr.task_queue.active_task_id].task_period_max)
        tasks[task_mgr.task_queue.active_task_id].task_period_max = (volatile uint16_t)t_buf; 

    // If execution time exceeds global OS maximum period, override global maximum time buffer value
    if((volatile uint16_t)t_buf > task_mgr.os_timer.task_period_max)
        task_mgr.os_timer.task_period_max = (volatile uint16_t)t_buf; 
    
    return (f_ret);
}


//------------------------------------------------------------------------------
// Check operation mode status and switch op mode if needed
//------------------------------------------------------------------------------

volatile uint16_t os_CheckOperationModeStatus(void) {

    volatile uint16_t i=0;
    
    // Specific conditions and op-mode switch-overs during system startup
    if (task_mgr.op_mode.value == OP_MODE_UNKNOWN)
    // if, for some reason, the operating mode has been cleared, restart the operating system
    {
        task_mgr.op_mode.value = OP_MODE_BOOT;
    }
    else if ((task_mgr.pre_op_mode.value == OP_MODE_BOOT) && (task_mgr.op_mode.value == OP_MODE_BOOT)) 
     // Boot-up task queue is only run once
    {
        task_mgr.op_mode.value = OP_MODE_FIRMWARE_INIT;
    } 
    else if ((task_mgr.pre_op_mode.value == OP_MODE_FIRMWARE_INIT) && (task_mgr.op_mode.value == OP_MODE_FIRMWARE_INIT)) 
    // device resources start-up task queue is only run once before ending in FAULT mode.
    // only when all fault flags have been cleared the system will be able to enter startup-mode
    // to enter normal operation.
    { 
        task_mgr.op_mode.value = OP_MODE_STARTUP_SEQUENCE; // put system into Fault mode to make sure all FAULT flags are cleared before entering normal operation
    }
    else if ((task_mgr.pre_op_mode.value == OP_MODE_STARTUP_SEQUENCE) && (task_mgr.op_mode.value == OP_MODE_STARTUP_SEQUENCE)) 
    // system-level start-up task queue is only run once before ending in NORMAL mode.
    { 
        task_mgr.status.bits.startup_sequence_complete = true;
        task_mgr.op_mode.value = OP_MODE_IDLE;
    }
    
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Skip execution if operation mode has not changed
    if (task_mgr.pre_op_mode.value != task_mgr.op_mode.value) {

        // If a change was detected, select the task queue and reset settings and flags
        switch (task_mgr.op_mode.value) {
            
            case OP_MODE_BOOT:
                // Switch to initialization mode operation
                task_mgr.task_queue.active_queue = task_queue_boot; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_boot[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_boot_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_boot_size-1); // Load most recent task queue UBound
                
                // Do not perform any user function during switch-over to this mode
                task_mgr.op_mode_switch_over_function = NULL; 

                break;

            case OP_MODE_FIRMWARE_INIT:
                // Switch to device startup mode operation (launching and enabling peripherals)
                task_mgr.task_queue.active_queue = task_queue_firmware_init; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_firmware_init[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_firmware_init_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_firmware_init_size-1); // Load most recent task queue UBound

                // Do not perform any user function during switch-over to this mode
                task_mgr.op_mode_switch_over_function = NULL; 

                break;

            case OP_MODE_STARTUP_SEQUENCE:
                // Switch to system startup mode operation (launching external systems / power sequencing / soft-start)
                task_mgr.task_queue.active_queue = task_queue_startup_sequence; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_startup_sequence[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_startup_sequence_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_startup_sequence_size-1); // Load most recent task queue UBound

                // Do not perform any user function during switch-over to this mode
                task_mgr.op_mode_switch_over_function = NULL; 

                break;

            case OP_MODE_IDLE:
                // Switch to normal operation
                task_mgr.task_queue.active_queue = task_queue_idle; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_idle[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_idle_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_idle_size-1); // Load most recent task queue UBound

                // Execute user function before switching to this operating mode
                task_mgr.op_mode_switch_over_function = &task_queue_idle_init; 

                break;

            case OP_MODE_RUN:
                // Switch to normal operation
                task_mgr.task_queue.active_queue = task_queue_run; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_run[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_run_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_run_size-1); // Load most recent task queue UBound

                // Execute user function before switching to this operating mode
                task_mgr.op_mode_switch_over_function = &task_queue_run_init; 
                
                break;

            case OP_MODE_FAULT:
                // Switch to fault mode operation
                task_mgr.task_queue.active_queue = task_queue_fault; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_fault[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_fault_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_fault_size-1); // Load most recent task queue UBound

                // set global fault override flag bit
                task_mgr.status.bits.fault_override = true; 
                
                // Execute user function before switching to this operating mode
                task_mgr.op_mode_switch_over_function = &task_queue_fault_init; 
                
                break;

            case OP_MODE_STANDBY:
                // Switch to standby mode operation 
                task_mgr.task_queue.active_queue = task_queue_standby; // Set task queue BOOT
                task_mgr.task_queue.active_task_id = task_queue_standby[0]; // Set task ID to first task of queue
                task_mgr.task_queue.active_index = 0; // Reset task queue pointer
                task_mgr.task_queue.size = task_queue_standby_size; // Load most recent task queue size
                task_mgr.task_queue.ubound = (task_queue_standby_size-1); // Load most recent task queue UBound
                
                // Execute user function before switching to this operating mode
                task_mgr.op_mode_switch_over_function = &task_queue_standby_init; 
                
                break;

            default: // OP_MODE_IDLE
                // Switch to idle operation as fallback default
                task_mgr.op_mode.value = OP_MODE_IDLE;
                break;
                
        }
        
        // Clear all task timing information from recent queue tasks
        for (i=0; i<task_mgr.task_queue.size; i++)
        {
            tasks[task_mgr.task_queue.active_queue[i]].return_value = 0;
            tasks[task_mgr.task_queue.active_queue[i]].task_period = 0;
            tasks[task_mgr.task_queue.active_queue[i]].task_period_max = 0;
        }
        
        // Execute Op-Mope transition Function (if available)
        if(task_mgr.op_mode_switch_over_function != NULL) // If op-mode switch-over function has been defined, ...
        { task_mgr.op_mode_switch_over_function(); } // Execute user function before switching to this operating mode
        
        // Set Op-Mode switch complete and raise flag
        task_mgr.pre_op_mode.value = task_mgr.op_mode.value; // Sync OpMode Flags
        task_mgr.status.bits.queue_switch = true; // set queue switch flag for one queue execution loop

    }
    else // if operating mode has not changed, reset task queue change flag bit
    {
        task_mgr.status.bits.queue_switch = false; // reset queue switch flag for one queue execution loop
    }

    return (1);
}


// ======================================================================================================
// Basic Task Manager Structure Initialization
// ==============================================================================================

volatile uint16_t os_TaskManager_Initialize(void) {

    volatile uint16_t fres = 1;
    volatile uint16_t i=0;

    // initialize private flag variable pre-op-mode used by task_CheckOperationModeStatus to identify changes in op_mode
    task_mgr.pre_op_mode.value = OP_MODE_BOOT;

    // Initialize basic Task Manager Status
    task_mgr.op_mode.value = OP_MODE_BOOT; // Set operation mode to STANDBY
    task_mgr.proc_code.value = 0; // Reset process code
    task_mgr.task_queue.active_queue = task_queue_boot; // Set task queue INIT
    task_mgr.task_queue.size   = task_queue_boot_size;
    task_mgr.task_queue.ubound = (task_queue_boot_size-1);
    task_mgr.task_queue.active_task_id = task_mgr.task_queue.active_queue[0]; // Set task ID to DEFAULT (IDle Task))
    task_mgr.task_queue.active_index = 0; // Reset task queue pointer
    task_mgr.os_timer.task_period_max = 0; // Reset maximum task time meter result

    task_mgr.status.bits.queue_switch = false;
    task_mgr.status.bits.startup_sequence_complete = false;
    task_mgr.status.bits.fault_override = false;
    
    // Scheduler Timer Configuration
    task_mgr.os_timer.index = TASK_MGR_TIMER_INDEX; // Index of the timer peripheral used
    task_mgr.os_timer.reg_counter = &TASK_MGR_TIMER_COUNTER_REGISTER;
    task_mgr.os_timer.reg_period = &TASK_MGR_TIMER_PERIOD_REGISTER;
    task_mgr.os_timer.master_period = TASK_MGR_MASTER_PERIOD; // Global task execution period 
    task_mgr.os_timer.rescue_period = TASK_MGR_RESCUE_PERIOD; // Global task rescue period 

    // CPU Load Monitor Configuration
    task_mgr.cpu_load.load = 0;
    task_mgr.cpu_load.load_max_buffer = 0;
    task_mgr.cpu_load.ticks = 0;
    task_mgr.cpu_load.loop_nomblk = TASK_MGR_CPU_LOAD_NOMBLK;
    task_mgr.cpu_load.load_factor = TASK_MGR_CPU_LOAD_FACTOR;

    // Initialize all defined task objects
    for (i=0; i<task_table_size; i++)
    {
        tasks[i].id = i;                // Set task ID
        tasks[i].time_quota = TASK_MGR_MASTER_PERIOD; // Set default execution time quota
        tasks[i].task_period = 0;       // Clear most recent execution period buffer
        tasks[i].task_period_max = 0;   // Clear overall maximum execution period buffer
        tasks[i].return_value = 0;      // Clear most recent return value buffer
        tasks[i].enabled = true;        // Enable task execution
    }
    
    
    #if (USE_TASK_EXECUTION_CLOCKOUT_PIN == 1)
        TS_CLOCKOUT_PIN_INIT_OUTPUT;
    #endif

    return (fres);
}


/*!task_Idle
 * ***********************************************************************************************
 * Summary:
 * Source file of idle task
 * 
 * Description:
 * This function is used to register a global function call of the default idle task. The idle task 
 * only executes a single Nop() and is used to keep scheduler tick intervals open.
 * 
 * History:
 * 07/28/2017	File created
 * 11/04/2019   Moved task_IDle to os_TaskManager.c as OS built-in standard task
 * ***********************************************************************************************/

volatile uint16_t task_Idle(void) {
// Idle tasks might be required to free up additional CPU load for higher
// priority processes. THerefore it's recommended to leave at least 
// one Idle cycle in each task list
    Nop();
    return(1);
}

/*!_RescueTimer_Interrupt()
 * ************************************************************************************************
 * Summary:
 * Kills the active task and returns to os_ProcessTaskQueue
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * In this interrupt service routine the most recent task is killed and a jump back to function
 * os_ProcessTaskQueue is enforced, right after the task function call to enable error handling.
 * ***********************************************************************************************/

void __attribute__((__interrupt__, auto_psv)) _RescueTimer_Interrupt() 
{
    TASK_MGR_TMR_IE = 0; // Disable timer interrupt (fall back to polling on IF bit in scheduler)
    task_mgr.status.bits.rescue_timer_overrun = true; // Set task manager period overrun flag bit
    tasks[task_mgr.task_queue.active_task_id].enabled = false; // Disable broken task
    RestoreStackFrame((volatile uint16_t*)&rescue_state); // Restore frame and stack pointer and 
                                             // jump back to os_ProcessTaskQueue())
}

// END OF FILE



