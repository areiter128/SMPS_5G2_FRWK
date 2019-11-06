/*LICENSE *****************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright (R) 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
 * right to use, modify, copy and distribute Software only when embedded on a Microchip 
 * microcontroller or digital signal controller, which is integrated into your product or third 
 * party product (pursuant to the sublicense terms in the accompanying license agreement).
 *
 * You should refer to the license agreement accompanying this Software for additional information 
 * regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR 
 * IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR 
 * OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT  
 * LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS  
 * OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY  
 * THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * ***********************************************************************************************/

#include <xc.h> // Device header file
#include <stdint.h>

#include "p33SMPS_hsadc.h"


/*@@p33EGS_adc.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33ExxGS-ADC SFRs
 *
 * Description:
 * The SMPS ADC module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all majority required settings.
 * ***********************************************************************************************/


/*@@hsadc_module_power_up()
 * *****************************************************************************************************
 * Summary:
 * Turns on the base power of the ADC module 
 *
 * Parameters: 
 *   (none)
 *
 * Description:
 * 
 * *****************************************************************************************************/

uint16_t hsadc_module_power_up(void)
{
    volatile uint16_t fres=0;
    
        #if defined (_ABGMD)
        _ABGMD = 0;         // Turn on power to analog bandgap reference
        fres = (1-_ABGMD);
        #endif
        #if defined (_ADCMD)
        _ADCMD = 0; 		// Turn on power to ADC module
        fres &= (1-_ADCMD);
        #endif
        return(fres);

} 

/*@@hsadc_module_power_down()
 * *****************************************************************************************************
 * Summary:
 * Turns off the base power of the ADC module 
 *
 * Parameters: 
 *   (none)
 *
 * Description:
 * 
 * *****************************************************************************************************/

uint16_t hsadc_module_power_down(void)
{
    #if defined (_ADCMD)
    _ADCMD = 1; 		// Turn on power to PWM channel #1
    return(_ADCMD);
    #else
    return(1);
    #endif

}

/*@@hsadc_init_adc
 * ************************************************************************************************
 * Summary:
 * Initializes the basic ADC configuration
 *
 * Parameters:
 *	regADCON1L	= holds the register value for the ADCON register
 *				  => bit 15 of the ADCON1L register, which enables/disables the ADC module,
 *					 will automatically be masked out. Please enable the PWM module by 
 *					 calling hsadc_enable()
 *	regADCON1H	= 
 *	regADCON2L	= 
 *	regADCON2H	= 
 *	regADCON3L	= 
 *	regADCON3H	= 
 *	regADCON4L	= 
 *	regADCON4H	= 
 *	regADCON5L	= 
 *	regADCON5H	= 
 *
 * Description:
 * Basic options like clock source, early interrupts, format options, sampling order and modes
 * are set here.
 * ***********************************************************************************************/

uint16_t hsadc_init_adc_module(REGBLK_ADCON1_t cfgADCON1, 
                        REGBLK_ADCON2_t cfgADCON2, 
                        REGBLK_ADCON3_t cfgADCON3,
                        REGBLK_ADCON4_t cfgADCON4,
                        REGBLK_ADCON5_t cfgADCON5
                        )
{
    volatile uint16_t fres = 1;
    volatile uint32_t *regptr32;
    volatile uint32_t regbuf32;
    
	// Reset all ADC configuration registers to defaults

	ADCON1L	= REG_ADCON1L_RESET;			// Disable and reset ADC configuration register 1 low
	ADCON1H	= REG_ADCON1H_RESET;			// Disable and reset ADC configuration register 1 high
	ADCON2L	= REG_ADCON2L_RESET;			// Disable and reset ADC configuration register 2 low
	ADCON2H	= REG_ADCON2H_RESET;			// Disable and reset ADC configuration register 2 high
    ADCON3L = REG_ADCON3L_RESET;			// Disable and reset ADC configuration register 3 low
    ADCON3H = REG_ADCON3H_RESET;			// Disable and reset ADC configuration register 3 high
    #if defined (ADCON4L) && defined (ADCON4H)  // Registers ADCON4L/H are only available if ADC has dedicated cores
    ADCON4L = REG_ADCON4L_RESET;			// Disable and reset ADC configuration register 4 low
    ADCON4H = REG_ADCON4H_RESET;			// Disable and reset ADC configuration register 4 high
    #endif
    ADCON5L = REG_ADCON5L_RESET;			// Disable and reset ADC configuration register 5 low
    ADCON5H = REG_ADCON5H_RESET;			// Disable and reset ADC configuration register 5 high
    
	// Setting ADC configuration block #1 according to user settings.
	// Please note:
	//   ADC ENABLE is masked out! The ADC has to be enabled by the user in software.
		
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&ADCON1L);
    *regptr32 = (cfgADCON1.value & (REG_ADCON1_OFF_STATE_WRITE_MASK));
    regbuf32 = *regptr32;
    if(regbuf32 == (cfgADCON1.value & REG_ADCON1_OFF_STATE_WRITE_MASK))
    { fres = 1; }
    else
    { fres = 0; }
    
	// Setting ADC configuration block #2 according to user settings.
    
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&ADCON2L);
    *regptr32 = (cfgADCON2.value & (REG_ADCON2_VALID_DATA_WRITE_MASK));
    regbuf32 = *regptr32;
    if(regbuf32 == (cfgADCON2.value & REG_ADCON2_VALID_DATA_WRITE_MASK))
    { fres &= 1; }
    else
    { fres = 0; }

	// Setting ADC configuration block #3 according to user settings.
    
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&ADCON3L);
    *regptr32 = (cfgADCON3.value & (REG_ADCON3_VALID_DATA_WRITE_MASK));
    regbuf32 = *regptr32;
    if(regbuf32 == (cfgADCON3.value & REG_ADCON3_VALID_DATA_WRITE_MASK))
    { fres &= 1; }
    else
    { fres = 0; }

	// Setting ADC configuration block #3 according to user settings.
    #if defined(ADCON4L)
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&ADCON4L);
    *regptr32 = (cfgADCON4.value & (REG_ADCON4_VALID_DATA_WRITE_MASK));
    regbuf32 = *regptr32;
    if(regbuf32 == (cfgADCON4.value & REG_ADCON4_VALID_DATA_WRITE_MASK))
    { fres &= 1; }
    else
    { fres = 0; }
    #endif
    
	// Setting ADC configuration block #5 according to user settings.
    
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&ADCON5L);
    *regptr32 = (cfgADCON5.value & (REG_ADCON5_VALID_DATA_WRITE_MASK));
    regbuf32 = *regptr32;
    if(regbuf32 == (cfgADCON5.value & REG_ADCON5_VALID_DATA_WRITE_MASK))
    { fres &= 1; }
    else
    { fres = 0; }


    // Return 1=success, 0=failure
	return(fres);

}

/*@@hsadc_init_adc_core
 * ************************************************************************************************
 * Summary:
 * Initializes an individual ADC Core configuration
 *
 * Parameters:
 *	regADCORExL	= holds the register value for the ADCORExL register
 *	regADCORExH	= holds the register value for the ADCORExL register
 *
 * Description:
 * Basic options like conversion delay, early interrupt period, ADC resolution and input clock
 * dividers are set here.
 * ***********************************************************************************************/

uint16_t hsadc_init_adc_core(uint16_t index, uint16_t regADCORExL, uint16_t regADCORExH)
{

volatile uint16_t *regptr;
volatile uint16_t reg_buf=0;

#if defined (ADCORE0L)
volatile uint16_t reg_offset=0;
#endif

	if (index >= ADC_CORE_COUNT) return(0);

    if(index != ADC_SHARED_CORE_INDEX)
    {
        // dedicated cores have their individual configuration 
        // registers ADCORExL and ADCORExH
        
        #if defined (ADCORE0L)
        // Dual core devices like dsPIC33CH only have shared cores on the master side.
        // Only slave cores have multiple, dedicated cores
        
        reg_offset = ( index * ADC_ADCORE_REG_OFFSET );
        regptr = (volatile uint16_t *)&ADCORE0L + reg_offset;
        reg_buf = (regADCORExL & REG_ADCORExL_VALID_DATA_MSK);
        if((*regptr & REG_ADCORExL_VALID_DATA_MSK) != reg_buf)
        { *regptr = reg_buf; }

        regptr = (volatile uint16_t *)&ADCORE0H + reg_offset;
        reg_buf = (regADCORExH & REG_ADCORExH_VALID_DATA_MSK);
        if((*regptr & REG_ADCORExH_VALID_DATA_MSK) != reg_buf)
        { *regptr = reg_buf; }

        #endif
        
    }
    else
    {
    
        // the configuration of the shared core is incorporated into 
        // the generic registers ADCON2L and ADCON2H
        // Unfortunately register assignments of xxxH and xxxL are reversed
        // for shared and dedicated cores.... So don't get confused !!!
        
        regptr = (volatile uint16_t *)&ADCON2L;
        reg_buf = (*regptr & REG_ADCON2L_REF_CFG_MASK);  // Read bandgap reference register bits
        reg_buf |= (regADCORExH & REG_ADCON2L_SHRADC_CFG_MASK);
        if((*regptr & REG_ADCON2L_SHRADC_CFG_MASK) != (reg_buf & REG_ADCON2L_SHRADC_CFG_MASK))
        { *regptr = reg_buf; }

        
        regptr = (volatile uint16_t *)&ADCON2H;
        reg_buf = (*regptr & REG_ADCON2H_REF_CFG_MASK);  // Read bandgap reference register bits
        reg_buf |= (regADCORExL & REG_ADCON2H_SHRADC_CFG_MASK);
        if((*regptr & REG_ADCON2H_SHRADC_CFG_MASK) != (reg_buf & REG_ADCON2H_SHRADC_CFG_MASK))
        { *regptr = reg_buf; }
    
    }

    return(1);
    
}

/*@@hsadc_module_enable()
 * ************************************************************************************************
 * Summary:
 * Enables the ADC module
 *
 * Parameters: (none)
 *
 * Description:
 * The ADC module has a start-up time of a couple of micro seconds. Therefore the 
 * enable-instruction is followed by a short delay loop.
 * ***********************************************************************************************/

uint16_t hsadc_module_enable(void)
{

    volatile uint16_t fres = 0;
    
	ADCON1Lbits.ADON	= ADC_ON; 	// Enable ADC module
    
    if(ADCON1Lbits.ADON){
        fres = hsadc_check_adc_cores_ready(); 
        return(fres);
    }
    else{ return(0); }
	return(ADCON1Lbits.ADON);
	 
}

/*@@hsadc_module_disable()
 * ************************************************************************************************
 * Summary:
 * Disables the ADC module
 *
 * Parameters: (none)
 *
 * Description:
 * Disables the entire ADC module, which will also affect the port registers. Fault states 
 * at certain pins will be lost as every pin will be re-configured as GPIO.
 * ***********************************************************************************************/

uint16_t hsadc_module_disable(void)
{

	ADCON1Lbits.ADON = ADC_OFF;			// Disable ADC module 

	return(1 - ADCON1Lbits.ADON);

}

/*@@hsadc_reset()
 * ************************************************************************************************
 * Summary:
 * Resets ADC configuration
 *
 * Parameters:	(none)
 *
 * Description:
 * Resets the entire ADC configuration including the port control registers. All ANx-inputs will
 * become GPIOs.
 * ***********************************************************************************************/

uint16_t hsadc_reset(void)
{
	// Reset all ADC configuration registers to defaults

	ADCON1Lbits.ADON = ADC_OFF;				// Disable ADC
  
	ADCON1L	= REG_ADCON1L_RESET;			// Disable and reset ADC configuration register 1 low
	ADCON1H	= REG_ADCON1H_RESET;			// Disable and reset ADC configuration register 1 high
	ADCON2L	= REG_ADCON2L_RESET;			// Disable and reset ADC configuration register 2 low
	ADCON2H	= REG_ADCON2H_RESET;			// Disable and reset ADC configuration register 2 high
    ADCON3L = REG_ADCON3L_RESET;			// Disable and reset ADC configuration register 3 low
    ADCON3H = REG_ADCON3H_RESET;			// Disable and reset ADC configuration register 3 high
    #if defined (ADCON4L)
    ADCON4L = REG_ADCON4L_RESET;			// Disable and reset ADC configuration register 4 low
    #endif
    #if defined (ADCON4H)
    ADCON4H = REG_ADCON4H_RESET;			// Disable and reset ADC configuration register 4 high
    #endif
    ADCON5L = REG_ADCON5L_RESET;			// Disable and reset ADC configuration register 5 low
    ADCON5H = REG_ADCON5H_RESET;			// Disable and reset ADC configuration register 5 high
    
	return(1);
}

/*@@hsadc_power_on_adc_core()
 * ************************************************************************************************
 * Summary:
 * Turns on a single ADC core considering warm-up time
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral require a self calibration procedure 
 * to meet the values given in the data sheet. The following function performs the self
 * calibration of the given ADC core.
 * ***********************************************************************************************/

uint16_t hsadc_check_adc_cores_ready(void)
{
    volatile uint16_t timeout = 0, rdy_compare = 0, reg_buf = 0;
    
    reg_buf = (ADCON5L & 0x00FF);
    rdy_compare = (reg_buf << 8);

    while( (((ADCON5L << 8) & 0xFF00) != rdy_compare) && (timeout++ < 0xFFFE) );
    if(timeout == 0xFFFF) return(0);
    else return(1);

}

/*@@hsadc_calibrate_adc_core()
 * ************************************************************************************************
 * Summary:
 * Calls the ADC calibration of a single ADC core
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral require a self calibration procedure 
 * to meet the values given in the data sheet. The following function performs the self
 * calibration of the given ADC core.
 * ***********************************************************************************************/
#if defined (__P33SMPS_EP__)
uint16_t hsadc_calibrate_adc_core(uint16_t index, uint16_t calib_mode)
{
	volatile uint16_t timeout=0;
    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;
    
    if (index >= ADC_CORE_COUNT) return(0);
    
    reg_offset = ((index >> 1) * ADC_ADCAL_REG_OFFSET);   // Index is divided by 2 due to shared registers
    regptr = (volatile uint16_t *)&ADCAL0L + reg_offset;
    
    // differentiate between odd and even indices due to shared registers
    if (index == ADC_SHARED_CORE_INDEX) {

        regptr = (volatile uint16_t *)&ADCAL1H;

        if ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0)
        {
            *regptr |= REG_ADCALx_HB_CALxEN_SET_MSK;  // Enable calibration
            *regptr &= REG_ADCALx_HB_CALxSKIP_CLR_MSK;  // Initiate calibration
            *regptr &= ((calib_mode << 8) | REG_ADCALx_HB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
            *regptr |= REG_ADCALx_HB_CALxRUN_SET_MSK;  // Initiate calibration

            // Wait until ADC core calibration has completed
            while( ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
            if((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure

            *regptr &= REG_ADCALx_HB_CALxEN_CLR_MSK;  // Disable calibration
        }
        
    }
    else if(index & 0x0001) {
        // Odd index (1, 3, 5, ...) and shared ADC bits are located in the high-byte of the register word
        
        if ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0)
        {
            *regptr |= REG_ADCALx_HB_CALxEN_SET_MSK;  // Enable calibration
            *regptr &= REG_ADCALx_HB_CALxSKIP_CLR_MSK;  // Initiate calibration
            *regptr &= ((calib_mode << 8) | REG_ADCALx_HB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
            *regptr |= REG_ADCALx_HB_CALxRUN_SET_MSK;  // Initiate calibration

            // Wait until ADC core calibration has completed
            while( ((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
            if((*regptr & REG_ADCALx_HB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure

            *regptr &= REG_ADCALx_HB_CALxEN_CLR_MSK;  // Disable calibration
        }
    }
    else{
        // Even index (0, 2, 4, ...) bits are located in the low-byte of the register word
        
        if ((*regptr & REG_ADCALx_LB_CALxRDY_SET_MSK) == 0)
        {
            *regptr |= REG_ADCALx_LB_CALxEN_SET_MSK;  // Enable calibration
            *regptr &= REG_ADCALx_LB_CALxSKIP_CLR_MSK;  // Initiate calibration
            *regptr &= (calib_mode | REG_ADCALx_LB_CALxDIFF_CLR_MSK);  // Set calibration mode (differential or single ended))
            *regptr |= REG_ADCALx_LB_CALxRUN_SET_MSK;  // Initiate calibration

            // Wait until ADC core calibration has completed
            while( ((*regptr & REG_ADCALx_LB_CALxRDY_SET_MSK) == 0) && (timeout++<5000));
            if((*regptr & REG_ADCALx_LB_CALxRDY_SET_MSK) == 0) return(0);  // If core doesn't enter READY state, return failure

            *regptr &= REG_ADCALx_LB_CALxEN_CLR_MSK;  // Disable calibration
        }
    }
	
	return(1);
	
}
#endif
/*@@hsadc_power_on_adc_core()
 * ************************************************************************************************
 * Summary:
 * Turns on a single ADC core considering warm-up time
 *
 * Parameters:	(none)
 *
 * Description:
 * The individual ADC cores of the ADC peripheral require a self calibration procedure 
 * to meet the values given in the data sheet. The following function performs the self
 * calibration of the given ADC core.
 * ***********************************************************************************************/

uint16_t hsadc_power_on_adc_core(uint16_t index)
{
    volatile uint16_t *regptr;
    volatile uint16_t reg_buf=0;
    
    if (index >= ADC_CORE_COUNT) return(0);
    
    regptr = (volatile uint16_t *)&ADCON5L;
    
    // Power on ADC core x 
    if(index == ADC_SHARED_CORE_INDEX) { 
      // Shared Core Power Setting is located in Bit #7, while all others are 
      // enumerated on Bits #0 = dedicated core #0, #1 = dedicated core #1, etc
        reg_buf  = (REG_ADCON5L_SHRPWR_ON & REG_ADCON5L_VALID_DATA_WRITE_MASK);
        
    }
    else {
      // Dedicated core power on enable bits are set based on the index/bit position 
        reg_buf  = ((0x0001 << index) & REG_ADCON5L_VALID_DATA_WRITE_MASK);
    }

    if(!(*regptr & reg_buf))   // if bit hasn't been set yet...
    { *regptr |= reg_buf; } // write to register

    
    reg_buf <<= 8;   // Shift selected bit up into the high-word of ADCON5L for the status check
    
    
    // Set pointer onto ADC core enable register ADCON3H
    regptr = (volatile uint16_t *)&ADCON3H;
    
    // Power on ADC core x 
    if(index == ADC_SHARED_CORE_INDEX) { 
      // Shared Core Power Setting is located in Bit #7, while all others are 
      // enumerated on Bits #0 = dedicated core #0, #1 = dedicated core #1, etc
        reg_buf  = (REG_ADCON3_SHREN_ON & REG_ADCON3H_VALID_DATA_WRITE_MSK);
        
    }
    else {
      // Dedicated core power on enable bits are set based on the index/bit position 
        reg_buf  = ((0x0001 << index) & REG_ADCON3H_VALID_DATA_WRITE_MSK);
    }

    if(!(*regptr & reg_buf)) // if bit hasn't been set yet...
    { *regptr |= reg_buf; } // write to register
    
	return(1);
	
}

/*@@hsadc_set_adc_core_trigger()
 * ************************************************************************************************
 * Summary:
 * Configures interrupt trigger setting of an individual Analog Input
 *
 * Parameters:
 * Returns: 	1: success, 0: failure
 *
 * Description:
 * 
 * ***********************************************************************************************/

uint16_t hsadc_set_adc_input_trigger_source(uint16_t index, uint16_t trigger_source)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;
    
    if (index >= ADC_ANINPUT_COUNT) return(0);

    reg_offset = ((index >> 1) * ADC_ADTRIG_REG_OFFSET);   // Index is divided by 2 due to shared registers
    regptr = (volatile uint16_t *)&ADTRIG0L + reg_offset;

    if (index & 0x0001) {
    // Odd analog input numbers are located in the high-byte of the register word
        reg_buf = ((trigger_source << 8) & REG_ADTRIGx_VALID_DATA_MSK);
        *regptr |= reg_buf;
    }
    else{
    // Even analog input numbers are located in the low-byte of the register word
        reg_buf = (trigger_source & REG_ADTRIGx_VALID_DATA_MSK);
        *regptr |= reg_buf;

    }

    return(1);
}

/*@@hsadc_set_adc_input_interrupt()
 * ************************************************************************************************
 * Summary:
 * configures the interrupt generation of a single ADC core
 *
 * Parameters:	
 *     - index: 
 *         index of the ADC input (e.g. 0 for AN, 1 for AN1, etc)
 *     - interrupt_enable: 
 *         0 = no interrupt will be generated
 *         1 = interrupt will be generated
 *     - early_interrupt_enable: 
 *         0 = interrupt will be triggered after conversion is complete
 *         1 = interrupt will be triggered n TADs before conversion is complete
 * 
 * Returns:
 *     0: failure
 *     1: success
 * 
 * Description:
 * The individual ADC cores of the ADC peripheral support the generation of interrupts. Further
 * Those interrupts can be "pulled-in" to compensate the interrupt latency of the controller
 * ***********************************************************************************************/

uint16_t hsadc_set_adc_input_interrupt(uint16_t index, uint16_t interrupt_enable, uint16_t early_interrupt_enable)
{
    volatile uint16_t *regptr;
    
    if (index >= ADC_ANINPUT_COUNT) return(0);
    
    if (index<16) {   

        // Setting the Early Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADEIEL;
        *regptr |= (early_interrupt_enable << index);

        // Setting the Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADIEL;
        *regptr |= (interrupt_enable << index);
    }
    else {

        index -= 16;

        #ifdef ADEIEH
        // Setting the Early Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADEIEH;
        *regptr |= (early_interrupt_enable << index);

        // Setting the Interrupt Enable Bit
        regptr = (volatile uint16_t *)&ADIEH;
        *regptr |= (interrupt_enable << index);
        #else
        return(0);
        #endif
    }
    
	return(1);
	
}

/*@@hsadc_init_adc_comp
 * ************************************************************************************************
 * Summary:
 * Initializes an individual digital ADC Comparator configuration
 *
 * Parameters:
 *	regADCMPxCON = holds the register value for the ADC comparator configuration register (ADCMPxCON)
 *	regADCMP0ENx = holds the register value for the ADC input used as data input
 *  regADCMPxLO = holds the compare value for the lower trip point threshold
 *  regADCMPxHI = holds the compare value for the upper trip point threshold
 * 
 * Description:
 * The ADC peripheral features a digital comparator, which compares the latest sample of a dedicated
 * ANx input with given upper and lower threshold values. If the values is outside the given range,
 * an interrupt will be triggered (if enabled).
 * This routine allows configuration of the comparator, the input source and its thresholds.
 * ***********************************************************************************************/

uint16_t hsadc_init_adc_comp(uint16_t index, uint16_t input_no, uint16_t regADCMPxCON, uint16_t regADCMPxLO, uint16_t regADCMPxHI)
{

volatile uint16_t *regptr;
volatile uint16_t reg_offset=0;

	if (index >= REG_ADCMP_COUNT) return(0);

    // ADC Comparator Configuration
    reg_offset = ( index * REG_ADCMP_REG_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0CON + reg_offset;
    *regptr = (regADCMPxCON & REG_ADCMPxCON_VALID_DATA_WR_MSK);

    // Lower Threshold Compare Value
    reg_offset = ( index * REG_ADCMPxLO_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0LO + reg_offset;
    *regptr = (regADCMPxLO & REG_ADCMPxLO_VALID_DATA_MASK);

    // Upper Threshold Compare Value
    reg_offset = ( index * REG_ADCMPxHI_OFFSET );
    regptr = (volatile uint16_t *)&ADCMP0HI + reg_offset;
    *regptr = (regADCMPxHI & REG_ADCMPxHI_VALID_DATA_MASK);
    
    // Assigning ANx inputs for the comparison
    if (input_no < 16) {   

        // Enabling the corresponding analog input comparator input
        reg_offset = ( index * REG_ADCMPxEN_REG_OFFSET );
        regptr = (volatile uint16_t *)&ADCMP0ENL + reg_offset;
        *regptr = (1 << input_no);

    }
    else if (input_no < 32) {

        input_no -= 16;

        #ifdef ADCMP0ENH
        // Enabling the corresponding analog input comparator input
        reg_offset = ( index * REG_ADCMPxEN_REG_OFFSET );
        regptr = (volatile uint16_t *)&ADCMP0ENH + reg_offset;
        *regptr = (1 << input_no);
        #else
        return(0);
        #endif
    }
    else { return(0); }
    
    return(1);
    
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// EOF
