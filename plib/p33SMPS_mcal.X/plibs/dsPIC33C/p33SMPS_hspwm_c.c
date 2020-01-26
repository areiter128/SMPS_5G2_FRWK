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

// Include Header Files
#include "p33SMPS_hspwm_c.h"

/*!p33MP_hspwm.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33CxxxMPxxx-PWM SFRs
 *
 * Description:
 * The SMPS PWM module offers a large number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 * ***********************************************************************************************/

/*!hspwm_power_enable
 * ************************************************************************************************
 * Summary:
 * Enables the bias power to the high resolution PWM module
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * PICmicro controllers offer so-called PERIPHERAL MODULE DISABLE (PMD) registers turning on/off
 * the bias power to on-chip peripheral blocks. This routine enables the bias power to the high-
 * resolution PWM module.
 * ***********************************************************************************************/
volatile uint16_t smpsHSPWM_PowerUp(void) {
// enable power to peripheral

    #ifdef PMDCON
    _PMDLOCK = 1;  // Unlock PMDx WRITE events
    #endif
    
    _HSPWM_POWER_ENABLE; // Power up PWM

    #ifdef PMDCON
    _PMDLOCK = 0;  // Lock PMDx WRITE events
    #endif

    return(1 - _PWMMD);
}

/*!hspwm_power_disable
 * ************************************************************************************************
 * Summary:
 * Disables the bias power to the high resolution PWM module
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * PICmicro controllers offer so-called PERIPHERAL MODULE DISABLE (PMD) registers turning on/off
 * the bias power to on-chip peripheral blocks. This routine disables the bias power to the high-
 * resolution PWM module.
 * ***********************************************************************************************/
volatile uint16_t smpsHSPWM_PowerDown(void) {
// disable power to peripheral
    
    #ifdef PMDCON
    _PMDLOCK = 1;  // Unlock PMDx WRITE events
    #endif

    _HSPWM_POWER_DISABLE;

    #ifdef PMDCON
    _PMDLOCK = 0;  // Unlock PMDx WRITE events
    #endif

    return(1 - _PWMMD);
}

/*!hspwm_init_pwm_module
 * ************************************************************************************************
 * Summary:
 * Writes a complete PWM module base register set configuration
 *
 * Parameters:
 *	HSPWM_C_MODULE_CONFIG_t pwm_config
 * 
 * Description:
 * The high resolution PWM module of the dsPICs have basic registers determining parameters
 * for all PWM generators, such as input clock selection and dividers, PWM resolution and 
 * logic combination of PWM generator outputs. These basic registers are merged into the 
 * data structure HSPWM_C_MODULE_CONFIG_t. This data structure can be used to set/load a 
 * default configuration in user code. This routine can be used to write this complete PWM
 * base register configuration at once while still every write process is monitored and 
 * checked.
 * ***********************************************************************************************/
volatile uint16_t hspwm_init_pwm_module ( HSPWM_C_MODULE_CONFIG_t pwm_config ) {

    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint32_t *regptr32;

    // Ensure power to PWM module is ON
    if (!smpsHSPWM_PowerUp()) return(0);
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &PCLKCON; // Get target address
    *regptr16 = (pwm_config.PCLKCON.value & REG_PCLKCON_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PCLKCON_VALID_DATA_WRITE_MASK) == (pwm_config.PCLKCON.value & REG_PCLKCON_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &FSCL; // Get target address
    *regptr16 = (pwm_config.FSCL.value & REG_FSCL_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_FSCL_VALID_DATA_WRITE_MASK) == (pwm_config.FSCL.value & REG_FSCL_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &FSMINPER; // Get target address
    *regptr16 = (pwm_config.FSMINPER.value & REG_FSMINPER_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_FSMINPER_VALID_DATA_WRITE_MASK) == (pwm_config.FSMINPER.value & REG_FSMINPER_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &MPHASE; // Get target address
    *regptr16 = (pwm_config.MPHASE.value & REG_MPHASE_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_MPHASE_VALID_DATA_WRITE_MASK) == (pwm_config.MPHASE.value & REG_MPHASE_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &MDC; // Get target address
    *regptr16 = (pwm_config.MDC.value & REG_MDC_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_MDC_VALID_DATA_WRITE_MASK) == (pwm_config.MDC.value & REG_MDC_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &MPER; // Get target address
    *regptr16 = (pwm_config.MPER.value & REG_MPER_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_MPER_VALID_DATA_WRITE_MASK) == (pwm_config.MPER.value & REG_MPER_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &LFSR; // Get target address
    *regptr16 = (pwm_config.LFSR.value & REG_LFSR_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LFSR_VALID_DATA_WRITE_MASK) == (pwm_config.LFSR.value & REG_LFSR_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&CMBTRIGL); // Get target address
    *regptr32 = (pwm_config.CMBTRIG.value & REG_CMBTRIG_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr32 & REG_CMBTRIG_VALID_DATA_WRITE_MASK) == (pwm_config.CMBTRIG.value & REG_CMBTRIG_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCONA; // Get target address
    *regptr16 = (pwm_config.LOGCONA.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCONA.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCONB; // Get target address
    *regptr16 = (pwm_config.LOGCONB.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCONB.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCONC; // Get target address
    *regptr16 = (pwm_config.LOGCONC.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCONC.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCOND; // Get target address
    *regptr16 = (pwm_config.LOGCOND.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCOND.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCONE; // Get target address
    *regptr16 = (pwm_config.LOGCONE.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCONE.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &LOGCONF; // Get target address
    *regptr16 = (pwm_config.LOGCONF.value & REG_LOGCONy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_LOGCONy_VALID_DATA_WRITE_MASK) == (pwm_config.LOGCONF.value & REG_LOGCONy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter
    
    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTA; // Get target address
    *regptr16 = (pwm_config.PWMEVTA.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTA.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTB; // Get target address
    *regptr16 = (pwm_config.PWMEVTB.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTB.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTC; // Get target address
    *regptr16 = (pwm_config.PWMEVTC.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTC.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTD; // Get target address
    *regptr16 = (pwm_config.PWMEVTD.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTD.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTE; // Get target address
    *regptr16 = (pwm_config.PWMEVTE.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTE.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    // write register configuration
    regptr16 = (volatile uint16_t*) &PWMEVTF; // Get target address
    *regptr16 = (pwm_config.PWMEVTF.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr16 & REG_PWMEVTy_VALID_DATA_WRITE_MASK) == (pwm_config.PWMEVTF.value & REG_PWMEVTy_VALID_DATA_WRITE_MASK)); // Test if written value matches parameter

    return(fres);
}

/*!hspwm_init_pwm_generator
 * ************************************************************************************************
 * Summary:
 * Writes a complete PWM generator register set configuration
 *
 * Parameters:
 *	HSPWM_C_MODULE_CONFIG_t pg_config
 * 
 * Description:
 * Each PWM generator of the high resolution PWM module of the dsPICs have an identical set of
 * configuration and status registers. These registers are merged into the data structure 
 * HSPWM_C_GENERATOR_CONFIG_t. This data structure can be used to set/load a default configuration 
 * in user code. This routine can be used to write this complete PWM generator register configuration 
 * at once while still every write process is monitored and checked.
 * ***********************************************************************************************/
volatile uint16_t hspwm_init_pwm_generator ( uint16_t instance, HSPWM_C_GENERATOR_CONFIG_t pg_config ) {

    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint32_t *regptr32;
    volatile uint16_t reg_offset;

    // determine register offset
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL); 

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1CONL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxCON.value & REG_PGxCON_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxCON_VALID_DATA_WRITE_MASK) == (pg_config.PGxCON.value & REG_PGxCON_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1STAT + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxSTAT.value & REG_PGxSTAT_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxSTAT_VALID_DATA_WRITE_MASK) == (pg_config.PGxSTAT.value & REG_PGxSTAT_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxIOCON.value & REG_PGxIOCON_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxIOCON_VALID_DATA_WRITE_MASK) == (pg_config.PGxIOCON.value & REG_PGxIOCON_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1EVTL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxEVT.value & REG_PGxEVTy_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxEVTy_VALID_DATA_WRITE_MASK) == (pg_config.PGxEVT.value & REG_PGxEVTy_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1FPCIL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxFPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxyPCI_VALID_DATA_WRITE_MASK) == (pg_config.PGxFPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1CLPCIL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxCLPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxyPCI_VALID_DATA_WRITE_MASK) == (pg_config.PGxCLPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1FFPCIL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxFFPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxyPCI_VALID_DATA_WRITE_MASK) == (pg_config.PGxFFPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1SPCIL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxSPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxyPCI_VALID_DATA_WRITE_MASK) == (pg_config.PGxSPCI.value & REG_PGxyPCI_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1LEBL + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxLEB.value & REG_PGxLEB_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxLEB_VALID_DATA_WRITE_MASK) == (pg_config.PGxLEB.value & REG_PGxLEB_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1LEBH + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxLEBCON.value & REG_PGxLEBCON_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxLEBCON_VALID_DATA_WRITE_MASK) == (pg_config.PGxLEBCON.value & REG_PGxLEBCON_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1PHASE + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxPHASE.value & REG_PGxPHASE_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxPHASE_VALID_DATA_WRITE_MASK) == (pg_config.PGxPHASE.value & REG_PGxPHASE_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DC + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxDC.value & REG_PGxDC_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxDC_VALID_DATA_WRITE_MASK) == (pg_config.PGxDC.value & REG_PGxDC_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DCA + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxDCA.value & REG_PGxDCA_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxDCA_VALID_DATA_WRITE_MASK) == (pg_config.PGxDCA.value & REG_PGxDCA_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1PER + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxPER.value & REG_PGxPER_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxPER_VALID_DATA_WRITE_MASK) == (pg_config.PGxPER.value & REG_PGxPER_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1TRIGA + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxTRIGA.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxTRIGy_VALID_DATA_WRITE_MASK) == (pg_config.PGxTRIGA.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1TRIGB + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxTRIGB.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxTRIGy_VALID_DATA_WRITE_MASK) == (pg_config.PGxTRIGB.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1TRIGC + reg_offset); // capture register address
    *regptr16 = (pg_config.PGxTRIGC.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr16 & REG_PGxTRIGy_VALID_DATA_WRITE_MASK) == (pg_config.PGxTRIGC.value & REG_PGxTRIGy_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM generator instance register configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1DTL + reg_offset); // capture register address
    *regptr32 = (pg_config.PGxDT.value & REG_PGxDT_VALID_DATA_WRITE_MASK); // write value to registers
    fres &= ((*regptr32 & REG_PGxDT_VALID_DATA_WRITE_MASK) == (pg_config.PGxDT.value & REG_PGxDT_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    
    return(fres);
}


/*!hspwm_init_independent_pwm
 * ************************************************************************************************
 * Summary:
 * Sets the basic configuration of a PWM generator 
 *
 * Parameters:
 *	(none)
 * 
 * Description:
 * This PWM instance configuration includes PWMxH/PWMxL outputs, selection of clock source and dividers,
 * dead times and events. Each instance configuration disables the instance by default. the PWM instance 
 * needs to be enabled by using the function call "hspwm_enable_pwm(instance)".
 * ***********************************************************************************************/

volatile uint16_t hspwm_init_independent_pwm(
            uint16_t instance, 
            PCLKCON_t regPCLK, 
            PGxCON_t regPGxCON, 
            PGxEVT_t regPGxEVT,
            PGxIOCON_t regPGxIOCON, 
            PGxDTxy_t regPGxDT
    )
{
    
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint32_t *regptr32;
    volatile uint16_t reg_offset;

    // write clock configuration
    regptr16 = (volatile uint16_t*) &PCLKCON;
    *regptr16 = (regPCLK.value & REG_PCLKCON_VALID_DATA_WRITE_MASK);

    // Test if written value matches parameter
    fres &= ((*regptr16 & REG_PCLKCON_VALID_DATA_READ_MASK) == (regPCLK.value & REG_PCLKCON_VALID_DATA_WRITE_MASK));
    
    // write PWM instance configuration
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    *regptr32 = (regPGxCON.value & REG_PGxCON_VALID_DATA_WRITE_MASK);
    fres &= ((*regptr32 & REG_PGxCON_VALID_DATA_WRITE_MASK) == (regPGxCON.value & REG_PGxCON_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write PWM instance event configuration
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2EVTL - (volatile uint16_t)&PG1EVTL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1EVTL + reg_offset);
    *regptr32 = (regPGxEVT.value & REG_PGxEVTy_VALID_DATA_WRITE_MASK);
    fres &= ((*regptr32 & REG_PGxEVTy_VALID_DATA_WRITE_MASK) == (regPGxEVT.value & REG_PGxEVTy_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write IO configuration
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    *regptr32 = (regPGxIOCON.value & REG_PGxIOCON_VALID_DATA_WRITE_MASK);
    fres &= ((*regptr32 & REG_PGxIOCON_VALID_DATA_WRITE_MASK) == (regPGxIOCON.value & REG_PGxIOCON_VALID_DATA_WRITE_MASK)); // read and compare register values

    // write dead time
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2DTL - (volatile uint16_t)&PG1DTL);
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&PG1DTL + reg_offset);
    *regptr32 = (regPGxDT.value & REG_PGxDT_VALID_DATA_WRITE_MASK);
    fres &= ((*regptr32 & REG_PGxDT_VALID_DATA_WRITE_MASK) == (regPGxDT.value & REG_PGxDT_VALID_DATA_WRITE_MASK)); // read and compare register values
    
    return(fres);

}

/*!hspwm_init_pwm_timing
 * ************************************************************************************************
 * Summary:
 * Sets the basic signal timing configuration of a PWM generator 
 *
 * Parameters:
 *	uint16_t instance:    Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *  uint16_t regPGxPER:   PWM generator period register setting the switching period 
 *  uint16_t regPGxDC:    PWM generator duty cycle register setting the switching signal on-time 
 *  uint16_t regPGxPHASE: PWM generator phase register setting the switching signal phase shift
 * 
 * Description:
 * This function defines the PWM instance switching frequency signal timing, such as frequency/period,
 * duty cycle/on-time and phase shift.
 * ***********************************************************************************************/

volatile uint16_t hspwm_init_pwm_timing(uint16_t instance, uint16_t regPGxPER, uint16_t regPGxDC, uint16_t regPGxPHASE)
{
    
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;

    // write PWM Period
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2PER - (volatile uint16_t)&PG1PER);
    regptr16 = (volatile uint16_t*)((volatile uint8_t*)&PG1PER + reg_offset);
    *regptr16 = (regPGxPER & REG_PGxPER_VALID_DATA_WRITE_MASK);

    // Test if written value matches parameter
    fres &= ((*regptr16 & REG_PGxPER_VALID_DATA_READ_MASK) == (regPGxPER & REG_PGxPER_VALID_DATA_WRITE_MASK));
    
    // write Duty Cycle
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2DC - (volatile uint16_t)&PG1DC);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DC + reg_offset);
    *regptr16 = regPGxDC;

    // Test if written value matches parameter
    fres &= ((*regptr16 & REG_PGxDC_VALID_DATA_READ_MASK) == (regPGxDC & REG_PGxDC_VALID_DATA_WRITE_MASK));
    
    // write Phase Shift
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2PHASE - (volatile uint16_t)&PG1PHASE);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1PHASE + reg_offset);
    *regptr16 = regPGxPHASE;
    
    // Test if written value matches parameter
    fres &= ((*regptr16 & REG_PGxPHASE_VALID_DATA_READ_MASK) == (regPGxPHASE & REG_PGxPHASE_VALID_DATA_WRITE_MASK));

    return(fres);

}

/*!hspwm_set_duty_cycle
 * ************************************************************************************************
 * Summary:
 * Writes a new duty cycle value to the individual duty cycle register of the specified PWM instance 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * Writes a new duty cycle value to the individual duty cycle register of the PWM generator 
 * specified by parameter 'instance'.
 * ***********************************************************************************************/

volatile uint16_t hspwm_set_duty_cycle(uint16_t instance, uint16_t regPGxDC, uint16_t regPGxDCA)
{
    volatile uint16_t fres=0;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;

    // write Duty Cycle
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2DC - (volatile uint16_t)&PG1DC);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DC + reg_offset);
    *regptr16 = regPGxDC;

    // write Duty Cycle Adjustment
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2DCA - (volatile uint16_t)&PG1DCA);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1DCA + reg_offset);
    *regptr16 = regPGxDCA;

    // Test if written value matches parameter
    fres = ((*regptr16 & REG_PGxDCA_VALID_DATA_READ_MASK) == (regPGxDCA & REG_PGxDCA_VALID_DATA_WRITE_MASK));
    
    return(fres);
}

/*!hspwm_enable_pwm
 * ************************************************************************************************
 * Summary:
 * Enables a PWM generator 
 *
 * Parameters:
 *	uint16_t instance:    Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *  bool wait_for_hres:   PWM generator period register setting the switching period 
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 * 
 * Description:
 * This function enables a PWM generator defined by parameter INSTANCE. If high resolution mode is 
 * enabled, this function waits until the high resolution ready bit is set before enabling the PWM
 * generator. This waiting period is timeout protected.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_Enable(volatile uint16_t instance, volatile bool wait_for_hres)
{
    volatile uint16_t fres = 1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;
    volatile uint16_t timeout=0;
    
    if(wait_for_hres)   // I high resolution mode, first check if the feature is coming up correctly
    {
        while((PCLKCONbits.HRRDY == PCLKCON_HRRDY_WAIT) &&  // Wait for READY bit
          (PCLKCONbits.HRERR == PCLKCON_HRERR_NO_ERROR) &&  // Observe ERROR bit
            (timeout++ < 5000))                             // Increment timeout counter
            {
                Nop();
                Nop();
                Nop();
            }

        if(timeout >= 5000) // if High Resolution Ready Bit has not been set
        { return(0); }      // skip ENABLE and return failure code

    }

    // Set ENABLE bit of given PWM generator
    reg_offset = (instance-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = (reg_buf | REG_PGCON_ON_PWM_ENABLED);
    
    fres &= (volatile uint16_t)(volatile bool)(*regptr16 & REG_PGCON_ON_PWM_ENABLED);
    
    return(fres);

}

/*!hspwm_disable_pwm
 * ************************************************************************************************
 * Summary:
 * Disables a PWM generator 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function disables a PWM generator defined by parameter INSTANCE.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_Disable(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2CONL - (volatile uint16_t)&PG1CONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1CONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_PGCON_ON_PWM_RESET;
    
    fres &= (volatile uint16_t)(volatile bool)(*regptr16 & REG_PGCON_ON_PWM_ENABLED);
    
    return(fres);
}
/*!hspwm_ovr_hold
 * ************************************************************************************************
 * Summary:
 * Overrides both PWM outputs (H/L) of the specified PWM instance 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function disables both outputs PWMxH and PWMxL of the PWM generator defined by 
 * parameter 'instance'. While in override mode, the PWM module is still running and thus
 * keeps generating triggers for other peripherals (e.g. ADC). Only the PWM outputs PWMxH and PWMxL
 * are forced to a permanent pin state defined by register bits PGxIOCONL->OVRDAT.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_OVR_Hold(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = (reg_buf | REG_IOCON_OVREN_COMP_SET);
    
    fres &= (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_OVREN_COMP_SET);
    
    return(fres);
}

/*!hspwm_ovr_release
 * ************************************************************************************************
 * Summary:
 * Releases both PWM outputs (H/L) of the specified PWM instance 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function enables both outputs PWMxH and PWMxL of the PWM generator defined by 
 * parameter 'instance' by releasing them from override conditions.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_OVR_Release(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_OVREN_COMP_RESET;
    
    fres &= (1 - (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_OVREN_COMP_SET));
    
    return(fres);
}

/*!hspwm_ovr_release_high_side
 * ************************************************************************************************
 * Summary:
 * Releases the high-side PWM output PWMxH of the specified PWM instance 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function enables the high-side PWM output PWMxH of the PWM generator defined by 
 * parameter 'instance' by releasing them from override conditions.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_OVR_ReleaseHighSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_OVRENH_RESET;
    
    fres &= (1 - (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_OVRENH_ENABLED));
    
    return(fres);
}

/*!hspwm_ovr_release_low_side
 * ************************************************************************************************
 * Summary:
 * Releases the low-side PWM output PWMxL of the specified PWM instance 
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function enables the low-side PWM output PWMxL of the PWM generator defined by 
 * parameter 'instance' by releasing them from override conditions.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_OVR_ReleaseLowSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONL - (volatile uint16_t)&PG1IOCONL);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONL + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_OVRENL_RESET;
    
    fres &= (1 - (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_OVRENL_ENABLED));
    
    return(fres);
}

/*!hspwm_set_gpio_high_side
 * ************************************************************************************************
 * Summary:
 * Revokes pin-ownership of output PWMxH of a PWM generator making it a GPIO
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function revokes the pin-ownership of output PWMxH from the specified PWM generator 
 * defined by parameter 'instance'. The output pin PWMxH becomes a general purpose IO, which 
 * can be controlled by port latch (LATx), port (PORTx) and i/o direction registers (TRIS).
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_SetGPIO_HighSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONH - (volatile uint16_t)&PG1IOCONH);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONH + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_PENH_GPIO_ENABLE;
    
    fres &= (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_PENH_GPIO_DISABLE);
    
    return(fres);
}

/*!hspwm_reset_gpio_high_side
 * ************************************************************************************************
 * Summary:
 * Assigns the pin-ownership of output PWMxH to the PWM generator
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function assigns the pin-ownership of output PWMxH to the specified PWM generator defined by 
 * parameter 'instance'. General power control registers, such as port latch (LATx), port (PORTx) 
 * and i/o direction registers (TRIS), will have no effect on the output pin.
 * ***********************************************************************************************/
     
volatile uint16_t smpsHSPWM_ResetGPIO_HighSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONH - (volatile uint16_t)&PG1IOCONH);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONH + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf | REG_IOCON_PENH_GPIO_DISABLE;
    
    fres &= 1 - (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_PENH_GPIO_DISABLE);
    
    return(fres);
}

/*!hspwm_set_gpio_low_side
 * ************************************************************************************************
 * Summary:
 * Revokes pin-ownership of output PWMxL of a PWM generator making it a GPIO
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function revokes the pin-ownership of output PWMxL from the specified PWM generator 
 * defined by parameter 'instance'. The output pin PWMxL becomes a general purpose IO, which 
 * can be controlled by port latch (LATx), port (PORTx) and i/o direction registers (TRIS).
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_SetGPIO_LowSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONH - (volatile uint16_t)&PG1IOCONH);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONH + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf & REG_IOCON_PENL_GPIO_ENABLE;
    
    fres &= (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_PENL_GPIO_DISABLE);
    
    return(fres);
}

/*!hspwm_reset_gpio_low_side
 * ************************************************************************************************
 * Summary:
 * Assigns the pin-ownership of output PWMxL to the PWM generator
 *
 * Parameters:
 *	uint16_t instance:  Index of the PWM generator addressed (e.g. 1 for PWM1, 2 for PWM2, etc.)
 *
 * Returns:
 *  uint16_t            a 16-bit unsigned integer number indicating if the write process was 
 *                      executed successfully (0: failure, 1: success)
 *  
 * Description:
 * This function assigns the pin-ownership of output PWMxL to the specified PWM generator defined by 
 * parameter 'instance'. General power control registers, such as port latch (LATx), port (PORTx) 
 * and i/o direction registers (TRIS), will have no effect on the output pin.
 * ***********************************************************************************************/

volatile uint16_t smpsHSPWM_ResetGPIO_LowSide(volatile uint16_t instance)
{
    volatile uint16_t fres=1;
    volatile uint16_t *regptr16;
    volatile uint16_t reg_offset;
    volatile uint16_t reg_buf=0;

    reg_offset = (instance-1) * ((volatile uint16_t)&PG2IOCONH - (volatile uint16_t)&PG1IOCONH);
    regptr16 = (volatile uint16_t*) ((volatile uint8_t*)&PG1IOCONH + reg_offset);
    reg_buf = *regptr16;
    *regptr16 = reg_buf | REG_IOCON_PENL_GPIO_DISABLE;
    
    fres &= (1 - (volatile uint16_t)(volatile bool)(*regptr16 & REG_IOCON_PENL_GPIO_DISABLE));
    
    return(fres);
}
/* *****************************************************************************************************
 * *****************************************************************************************************/

