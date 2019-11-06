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

#ifndef _P33SMPS_HSADC_H_
#define _P33SMPS_HSADC_H_

#include <stdint.h>
#include <math.h>

#include "p33SMPS_devices.h"
#include "syscfg_scaling.h"

/*@@p33SMPS_hsadc.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS-ADC SFRs
 *
 * Description:
 * The SMPS ADC module offers a number of registers and configuration options. This additional
 * header file contains defines for all required bit-settings. This additional
 * header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * ***********************************************************************************************/

// Device-specific Defines

#if defined (__P33SMPS_EP2__)

#define ADC_CORE_COUNT          3					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       12                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1
#define ADC_ADCBUF_REG_OFFSET   1

#define ADC_ADTRIG_REG_OFFSET   1   

#define REG_AN_INPUT_L_MSK         0b0000111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000000

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP5__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       12                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b0000111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000000

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP504__) 

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b1111111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP505__) 

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b1111111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP506__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       22                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1


#define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000111111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP702__) || defined (__P33SMPS_EP802__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       11                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b0000111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000000

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP704__) || defined (__P33SMPS_EP804__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       17                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b1111111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP705__) || defined (__P33SMPS_EP805__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       19                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

#define REG_AN_INPUT_L_MSK         0b1111111111111111
#define REG_AN_INPUT_H_MSK         0b0000000000000111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4

#elif defined (__P33SMPS_EP706__) || defined (__P33SMPS_EP806__) || \
      defined (__P33SMPS_EP708__) || defined (__P33SMPS_EP808__)

#define ADC_CORE_COUNT          5					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       22                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1


#define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000111111

#define REG_ADCMP_COUNT         2
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4


#elif defined (__P33SMPS_CH502__)

#if defined (__P33SMPS_CH_MSTR__)

#define ADC_CORE_COUNT          1					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       12                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b0000111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000000

#elif defined (__P33SMPS_CH_SLV1__)

#define ADC_CORE_COUNT          3					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       11                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b0000011111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000000

#endif

#elif defined (__P33SMPS_CH503__) || defined (__P33SMPS_CH505__)

#if defined (__P33SMPS_CH_MSTR__)

#define ADC_CORE_COUNT          1					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       16                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000000

#elif defined (__P33SMPS_CH_SLV1__)

#define ADC_CORE_COUNT          3					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       15                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b0111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000000

#endif

#elif defined (__P33SMPS_CH506__) || defined (__P33SMPS_CH508__)

#if defined (__P33SMPS_CH_MSTR__)

#define ADC_CORE_COUNT          1					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       16                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000000

#elif defined (__P33SMPS_CH_SLV1__)

#define ADC_CORE_COUNT          3					// Number of ADC Cores available
#define ADC_ANINPUT_COUNT       18                  // Number of analog inputs
#define ADC_SHARED_CORE_INDEX   (ADC_CORE_COUNT - 1)    // Arteficially assigned index for shared ADC core

#define REG_ADC_CHANNEL_L_MSK   0b1111111111111111
#define REG_ADC_CHANNEL_H_MSK   0b0000000000000011

#endif

#define ADC_ADCONL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCORE_REG_OFFSET   2

#define ADC_ADMODL_REG_OFFSET   2
#define ADC_ADCONH_REG_OFFSET   2
#define ADC_ADCAL_REG_OFFSET    1

#define ADC_ADTRIG_REG_OFFSET   1

// bits are added for each dedicated core, shared core is always available (highest index)
#if (ADC_CORE_COUNT > 1)
    #define ADCDORE_REGISTER_BIT_MASK   ((uint32_t)(pow(2, (ADC_CORE_COUNT-1)) - 1) | 0x0080) 
#else
    #define ADCDORE_REGISTER_BIT_MASK   ((uint32_t)0x0080) // only the shared core is present
#endif

// Digital Comparators
#define REG_ADCMP_COUNT         4
#define REG_ADCMP_REG_OFFSET    2
#define REG_ADCMPxEN_REG_OFFSET 4
#define REG_ADCMPxLO_OFFSET     4
#define REG_ADCMPxHI_OFFSET     4


#else

#error === selected device is not defined any may not be supported ===

#endif

// Thie following define is used for bit masks and configuration registers depending on the number
// of available ADc cores and will be used by multiple defines throughout the library
#define ADCON4_VALID_ADCDORE_BIT_MASK       (uint32_t)(ADCDORE_REGISTER_BIT_MASK)


// Device-specific Defines
#ifndef DEVICE_VDD

DEVICE_VDD 3.300 // if device VDD is not defined in this project, define it for standard value of 3.3V
#endif

#define ADC_VREF        DEVICE_VDD     // ADC reference voltage in [V]
#define ADC_RES_BIT     12.0    // ADC resolution in integer
#define ADC_RES         (uint16_t)(pow(2, ADC_RES_BIT)-1)    // ADC resolution in integer
#define ADC_SCALER      (float)(((float)(ADC_RES))/((float)(ADC_VREF))) // ADC Scaling in ticks/V

#define ADC_ANx_INTERRUPT_ENABLE        1       // Bit setting for enabled interrupts of a dedicated analog input
#define ADC_ANx_INTERRUPT_DISABLE       0       // Bit setting for disabled interrupts of a dedicated analog input

#define ADC_ANx_EARLY_INTERRUPT_ENABLE  1       // Bit setting for enabled early interrupts of a dedicated analog input
#define ADC_ANx_EARLY_INTERRUPT_DISABLE 0       // Bit setting for disabled early interrupts of a dedicated analog input

// General Flags
#define ADC_OFF							0b0		// Flag is used to shut down the adc module
#define ADC_ON							0b1		// Flag is used to enable the adc module

// REGISTER ADCON1L/H: ANALOG-TO-DIGITAL CONTROL REGISTER 1 LOW/HIGH

#define REG_ADCON1_VALID_DATA_WRITE_MASK	0x00E0A000 		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON1_VALID_DATA_READ_MASK     0x00E0A000		// Bit mask used to read unimplemented bits as zero
#define REG_ADCON1_OFF_STATE_WRITE_MASK     0x00E02000 		// Bit mask used to set unimplemented bits to zero

// REGISTER ADCON1L: ANALOG-TO-DIGITAL CONTROL REGISTER 1 LOW

#define REG_ADCON1L_VALID_DATA_WRITE_MASK	0b1010000000000000		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON1L_VALID_DATA_READ_MASK	0b1010000000000000		// Bit mask used to read unimplemented bits as zero
#define REG_ADCON1L_DISABLED_MASK           0b0111111111111111
#define REG_ADCON1L_RESET                   0b0000000000000000      // Reset ADCON 1 Low Register

// REGISTER ADCON1H: ANALOG-TO-DIGITAL CONTROL REGISTER 1 HIGH

#define REG_ADCON1H_RESET                   0b0000000001100000      // Reset ADCON 1 High Register
#define REG_ADCON1H_VALID_DATA_READ_MASK	0b0000000011100000		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON1H_VALID_DATA_WRITE_MASK	0b0000000011100000		// Bit mask used to read unimplemented bits as zero



#define REG_ADCON1L_ADON_ENABLED		0b1000000000000000      // Turn ADC Module On
#define REG_ADCON1L_ADON_DISABLED		0b0000000000000000      // Turn ADC Module Off

typedef enum {
    ADCON1_ADON_ENABLED = 0b1, // ADC module is enabled
    ADCON1_ADON_DISABLED = 0b0 // ADC module is disabled
} ADCON1_ADON_e; // ADC Enable bit

#define REG_ADCON1_ADSIDL_STOP			0b0010000000000000      // Module Discontinues Operation in Idle Mode
#define REG_ADCON1_ADSIDL_RUN			0b0000000000000000      // Module Continues Operation in Idle Mode

typedef enum {
    ADCON1_ADSIDL_STOP = 0b1, // Discontinues module operation when device enters Idle mode
    ADCON1_ADSIDL_RUN = 0b0 // Continues module operation in Idle mode
} ADCON1_ADSIDL_e; // ADC Stop in Idle Mode bit


// REGISTER ADCON1H: ANALOG-TO-DIGITAL CONTROL REGISTER 1 HIGH

#define REG_ADCON1H_FORM_FRACTIONAL		0b0000000010000000      // Result Number Format = Fractional
#define REG_ADCON1H_FORM_INTEGER		0b0000000000000000      // Result Number Format = Integer

typedef enum {
    ADCON1_FORM_FRACTIONAL = 0b1, // Fractional Data Output Format
    ADCON1_FORM_INTEGER = 0b0 // Integer Data Output Format
} ADCON1_FORM_e; // Fractional Data Output Format bit

#define REG_ADCON1H_SHRRES_12BIT        0b0000000001100000      // Set for 12-bit operation
#define REG_ADCON1H_SHRRES_10BIT        0b0000000001000000      // Set for 10-bit operation
#define REG_ADCON1H_SHRRES_8BIT         0b0000000000100000      // Set for 8-bit operation
#define REG_ADCON1H_SHRRES_6BIT         0b0000000000000000      // Set for 6-bit operation

typedef enum {
    ADCON1_SHRRES_12BIT = 0b11, // 12-bit resolution
    ADCON1_SHRRES_10BIT = 0b10, // 10-bit resolution
    ADCON1_SHRRES_8BIT = 0b01, // 8-bit resolution
    ADCON1_SHRRES_6BIT = 0b00 // 6-bit resolution
} ADCON1_SHRRES_e; // Shared ADC Core Resolution Selection bits

typedef struct {
    volatile unsigned : 13;
    volatile ADCON1_ADSIDL_e ADSIDL : 1; // ADC Stop in Idle Mode bit
    volatile unsigned : 1;
    volatile ADCON1_ADON_e ADON : 1; // ADC Enable bit

    volatile unsigned : 5;
    volatile ADCON1_SHRRES_e SHRRES : 2; // Shared ADC Core Resolution Selection bits
    volatile ADCON1_FORM_e FORM : 1; // Fractional Data Output Format bit
    volatile unsigned : 8;

} __attribute__((packed))ADCON1_t; // ADCON1: ADC CONTROL REGISTER 1 HIGH/LOW

typedef union {
    volatile uint32_t value;
    volatile ADCON1_t ADCON1;
} REGBLK_ADCON1_t;


// REGISTERS ADCON2L/H: ANALOG-TO-DIGITAL CONTROL REGISTER 2 LOW/HIGH

#define REG_ADCON2_VALID_DATA_WRITE_MASK  0xC3FFD77F		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON2_VALID_DATA_READ_MASK   0xC3FFD77F		// Bit mask used to set unimplemented bits to zero


// REGISTER ADCON2L: ANALOG-TO-DIGITAL CONTROL REGISTER 2 HIGH

#define REG_ADCON2L_RESET               0b0000000000000000      // Reset ADCON 2 Low Register
#define REG_ADCON2L_VALID_DATA_MSK		0b1101011101111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON2L_SHRADC_CFG_MASK     0b0001011101111111      // Bit-Mask eliminating all bits not concerning the shared ADC core configuration
#define REG_ADCON2L_REF_CFG_MASK        0b1100000000000000      // Bit-Mask eliminating all bits not concerning the bandgap reference configuration

// REGISTER ADCON2H: ANALOG-TO-DIGITAL CONTROL REGISTER 2 HIGH

#define REG_ADCON2H_RESET               0b0000000000000000      // Reset ADCON 2 High Register
#define REG_ADCON2H_VALID_DATA_MSK		0b1100001111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON2H_SHRADC_CFG_MASK     0b0000001111111111      // Bit-Mask eliminating all bits not concerning the shared ADC core configuration
#define REG_ADCON2H_REF_CFG_MASK        0b1100000000000000      // Bit-Mask eliminating all bits not concerning the bandgap reference configuration
#define REG_ADCON2H_REF_STAT_READ_MASK  0b1100000000000000      // Bit-Mask for reading the bandgap reference status bits


#define REG_ADCON2L_REFCIE_ON           0b1000000000000000      // Interrupt on Band Gap & Reference Voltage Ready
#define REG_ADCON2L_REFCIE_OFF          0b0000000000000000      // No Interrupt on Band Gap & Reference Voltage Ready

typedef enum {
    ADCON2_REFCIE_ON = 0b1, // Common interrupt will be generated when the band gap becomes ready
    ADCON2_REFCIE_OFF = 0b0 // Common interrupt is disabled for the band gap ready event
} ADCON2_REFCIE_e; // Band Gap and Reference Voltage Ready Common Interrupt Enable bit

#define REG_ADCON2L_REFERCIE_ON         0b0100000000000000      // Interrupt on Band Gap or Reference Voltage Error
#define REG_ADCON2L_REFERCIE_OFF        0b0000000000000000      // No Interrupt on Band Gap or Reference Voltage Error

typedef enum {
    ADCON2_REFERCIE_ON = 0b1, // Common interrupt will be generated when a band gap or reference voltage error is detected
    ADCON2_REFERCIE_OFF = 0b0 // Common interrupt is disabled for the band gap and reference voltage error event
} ADCON2_REFERCIE_e; // Band Gap or Reference Voltage Error Common Interrupt Enable bit

#define REG_ADCON2L_EIEN_ON             0b0001000000000000      // Early Interrupts Enabled
#define REG_ADCON2L_EIEN_OFF            0b0000000000000000      // Early Interrupts Disabled

typedef enum {
    ADCON2_EIEN_ON = 0b1, // The early interrupt feature is enabled for the input channel interrupts (when the EISTATx flag is set)
    ADCON2_EIEN_OFF = 0b0 // The individual interrupts are generated when conversion is done (when the ANxRDY flag is set)
} ADCON2_EIEN_e; // Early Interrupts Enable bit


#define REG_ADCON2L_SHREISEL_8TAD       0b0000011100000000      // Early Interrupts 8 TADs before READY
#define REG_ADCON2L_SHREISEL_7TAD       0b0000011000000000      // Early Interrupts 7 TADs before READY
#define REG_ADCON2L_SHREISEL_6TAD       0b0000010100000000      // Early Interrupts 6 TADs before READY
#define REG_ADCON2L_SHREISEL_5TAD       0b0000010000000000      // Early Interrupts 5 TADs before READY
#define REG_ADCON2L_SHREISEL_4TAD       0b0000001100000000      // Early Interrupts 4 TADs before READY
#define REG_ADCON2L_SHREISEL_3TAD       0b0000001000000000      // Early Interrupts 3 TADs before READY
#define REG_ADCON2L_SHREISEL_2TAD       0b0000000100000000      // Early Interrupts 2 TADs before READY
#define REG_ADCON2L_SHREISEL_1TAD       0b0000000000000000      // Early Interrupts 1 TADs before READY

typedef enum {
    ADCON2_SHREISEL_8TAD = 0b111, // Early interrupt is set and interrupt is generated 8 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_7TAD = 0b110, // Early interrupt is set and interrupt is generated 7 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_6TAD = 0b101, // Early interrupt is set and interrupt is generated 6 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_5TAD = 0b100, // Early interrupt is set and interrupt is generated 5 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_4TAD = 0b011, // Early interrupt is set and interrupt is generated 4 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_3TAD = 0b010, // Early interrupt is set and interrupt is generated 3 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_2TAD = 0b001, // Early interrupt is set and interrupt is generated 2 TADCORE clocks prior to when the data is ready
    ADCON2_SHREISEL_1TAD = 0b000 // Early interrupt is set and interrupt is generated 1 TADCORE clocks prior to when the data is ready
} ADCON2_SHREISEL_e; // Shared Core Early Interrupt Time Selection bits

#define REG_SHRADCS_MSK                 0b0000000001111111      // Bit-Mask to filter on clock divider value bits
#define REG_SHRADCS(clkdiv)             ((clkdiv >> 1) & REG_SHRADCS_MSK) 	// Shared ADC Core Input Clock Divider bits. (clkdiv indicates the effective divider ratio)

typedef enum {
    ADCON2_SHRADCS_DIV_MIN = 0b0000000, // 2 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV2 = 0b0000001, // 2 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV4 = 0b0000010, // 4 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV6 = 0b0000011, // 6 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV8 = 0b0000100, // 8 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV10 = 0b0000101, // 10 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV12 = 0b0000110, // 12 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV14 = 0b0000111, // 14 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV16 = 0b0001000, // 16 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV18 = 0b0001001, // 18 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV20 = 0b0001010, // 20 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV22 = 0b0001011, // 22 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV24 = 0b0001100, // 24 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV26 = 0b0001101, // 26 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV28 = 0b0001110, // 28 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV30 = 0b0001111, // 30 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV32 = 0b0010000, // 32 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV34 = 0b0010001, // 34 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV36 = 0b0010010, // 36 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV38 = 0b0010011, // 38 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV40 = 0b0010100, // 40 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV42 = 0b0010101, // 42 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV44 = 0b0010110, // 44 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV46 = 0b0010111, // 46 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV48 = 0b0011000, // 48 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV50 = 0b0011001, // 50 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV52 = 0b0011010, // 52 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV54 = 0b0011011, // 54 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV56 = 0b0011100, // 56 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV58 = 0b0011101, // 58 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV60 = 0b0011110, // 60 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV62 = 0b0011111, // 62 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV64 = 0b0100000, // 64 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV66 = 0b0100001, // 66 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV68 = 0b0100010, // 68 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV70 = 0b0100011, // 70 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV72 = 0b0100100, // 72 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV74 = 0b0100101, // 74 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV76 = 0b0100110, // 76 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV78 = 0b0100111, // 78 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV80 = 0b0101000, // 80 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV82 = 0b0101001, // 82 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV84 = 0b0101010, // 84 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV86 = 0b0101011, // 86 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV88 = 0b0101100, // 88 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV90 = 0b0101101, // 90 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV92 = 0b0101110, // 92 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV94 = 0b0101111, // 94 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV96 = 0b0110000, // 96 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV98 = 0b0110001, // 98 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV100 = 0b0110010, // 100 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV102 = 0b0110011, // 102 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV104 = 0b0110100, // 104 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV106 = 0b0110101, // 106 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV108 = 0b0110110, // 108 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV110 = 0b0110111, // 110 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV112 = 0b0111000, // 112 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV114 = 0b0111001, // 114 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV116 = 0b0111010, // 116 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV118 = 0b0111011, // 118 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV120 = 0b0111100, // 120 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV122 = 0b0111101, // 122 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV124 = 0b0111110, // 124 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV126 = 0b0111111, // 126 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV128 = 0b1000000, // 128 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV130 = 0b1000001, // 130 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV132 = 0b1000010, // 132 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV134 = 0b1000011, // 134 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV136 = 0b1000100, // 136 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV138 = 0b1000101, // 138 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV140 = 0b1000110, // 140 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV142 = 0b1000111, // 142 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV144 = 0b1001000, // 144 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV146 = 0b1001001, // 146 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV148 = 0b1001010, // 148 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV150 = 0b1001011, // 150 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV152 = 0b1001100, // 152 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV154 = 0b1001101, // 154 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV156 = 0b1001110, // 156 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV158 = 0b1001111, // 158 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV160 = 0b1010000, // 160 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV162 = 0b1010001, // 162 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV164 = 0b1010010, // 164 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV166 = 0b1010011, // 166 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV168 = 0b1010100, // 168 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV170 = 0b1010101, // 170 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV172 = 0b1010110, // 172 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV174 = 0b1010111, // 174 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV176 = 0b1011000, // 176 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV178 = 0b1011001, // 178 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV180 = 0b1011010, // 180 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV182 = 0b1011011, // 182 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV184 = 0b1011100, // 184 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV186 = 0b1011101, // 186 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV188 = 0b1011110, // 188 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV190 = 0b1011111, // 190 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV192 = 0b1100000, // 192 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV194 = 0b1100001, // 194 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV196 = 0b1100010, // 196 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV198 = 0b1100011, // 198 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV200 = 0b1100100, // 200 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV202 = 0b1100101, // 202 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV204 = 0b1100110, // 204 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV206 = 0b1100111, // 206 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV208 = 0b1101000, // 208 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV210 = 0b1101001, // 210 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV212 = 0b1101010, // 212 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV214 = 0b1101011, // 214 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV216 = 0b1101100, // 216 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV218 = 0b1101101, // 218 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV220 = 0b1101110, // 220 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV222 = 0b1101111, // 222 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV224 = 0b1110000, // 224 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV226 = 0b1110001, // 226 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV228 = 0b1110010, // 228 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV230 = 0b1110011, // 230 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV232 = 0b1110100, // 232 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV234 = 0b1110101, // 234 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV236 = 0b1110110, // 236 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV238 = 0b1110111, // 238 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV240 = 0b1111000, // 240 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV242 = 0b1111001, // 242 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV244 = 0b1111010, // 244 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV246 = 0b1111011, // 246 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV248 = 0b1111100, // 248 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV250 = 0b1111101, // 250 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV252 = 0b1111110, // 252 source clock periods (TCORESRC) per TAD clock period (TADCORE)
    ADCON2_SHRADCS_DIV254 = 0b1111111 // 254 source clock periods (TCORESRC) per TAD clock period (TADCORE)
} ADCON2_SHRADCS_e; // ADC source clock divider selection


#define REG_ADCON2_REFRDY_READY     0b1000000000000000   // Band gap is ready
#define REG_ADCON2_REFRDY_NOT_READY 0b0000000000000000   // Band gap is not ready

typedef enum {
    ADCON2_REFRDY_READY = 0b1, // Band gap is ready
    ADCON2_REFRDY_NOT_READY = 0b0 // Band gap is not ready
} ADCON2_REFRDY_e; // Band Gap and Reference Voltage Ready Flag bit

#define REG_ADCON2_REFERR_FAIL      0b0100000000000000   // Band gap failure after ADC peripehral was enabled
#define REG_ADCON2_REFERR_OK        0b0000000000000000   // No Band gap / reference voltage error was detected

typedef enum {
    ADCON2_REFERR_FAIL = 0b1, // Band gap failure after the ADC module was enabled (ADON = 1)
    ADCON2_REFERR_OK = 0b0 // No band gap error was detected
} ADCON2_REFERR_e; // Band Gap or Reference Voltage Error Flag bit

typedef struct {
    volatile unsigned : 14;
    volatile ADCON2_REFERR_e REFERR : 1; // Band Gap/Vref error flag bit
    volatile ADCON2_REFRDY_e REFRDY : 1; // Band Gap/Vref status flag bit
} __attribute__((packed))ADCON2_REFSTAT_t; // Band Gap Reference status


#define REG_ADCON2H_SHRSAMC_MSK         0b0000001111111111      // Bit-Mask to filter on clock periods value bits
#define REG_ADCON2H_SHRSAMC(Tdaclk)     ((Tdaclk-2) & REG_ADCON2H_SHRSAMC_MSK) 		// Shared ADC Core Sample Time Selection bits

typedef enum {
    ADCON2_SHRSAMC_0002 = 0b0000000000, // Sampling time of 2 TADCORE clock periods
    ADCON2_SHRSAMC_0003 = 0b0000000001, // Sampling time of 3 TADCORE clock periods
    ADCON2_SHRSAMC_0004 = 0b0000000010, // Sampling time of 4 TADCORE clock periods
    ADCON2_SHRSAMC_0005 = 0b0000000011, // Sampling time of 5 TADCORE clock periods
    ADCON2_SHRSAMC_0006 = 0b0000000100, // Sampling time of 6 TADCORE clock periods
    ADCON2_SHRSAMC_0007 = 0b0000000101, // Sampling time of 7 TADCORE clock periods
    ADCON2_SHRSAMC_0008 = 0b0000000110, // Sampling time of 8 TADCORE clock periods
    ADCON2_SHRSAMC_0009 = 0b0000000111, // Sampling time of 9 TADCORE clock periods
    ADCON2_SHRSAMC_0010 = 0b0000001000, // Sampling time of 10 TADCORE clock periods
    ADCON2_SHRSAMC_0011 = 0b0000001001, // Sampling time of 11 TADCORE clock periods
    ADCON2_SHRSAMC_0012 = 0b0000001010, // Sampling time of 12 TADCORE clock periods
    ADCON2_SHRSAMC_0013 = 0b0000001011, // Sampling time of 13 TADCORE clock periods
    ADCON2_SHRSAMC_0014 = 0b0000001100, // Sampling time of 14 TADCORE clock periods
    ADCON2_SHRSAMC_0015 = 0b0000001101, // Sampling time of 15 TADCORE clock periods
    ADCON2_SHRSAMC_0016 = 0b0000001110, // Sampling time of 16 TADCORE clock periods
    ADCON2_SHRSAMC_0017 = 0b0000001111, // Sampling time of 17 TADCORE clock periods
    ADCON2_SHRSAMC_0018 = 0b0000010000, // Sampling time of 18 TADCORE clock periods
    ADCON2_SHRSAMC_0019 = 0b0000010001, // Sampling time of 19 TADCORE clock periods
    ADCON2_SHRSAMC_0020 = 0b0000010010, // Sampling time of 20 TADCORE clock periods
    ADCON2_SHRSAMC_0021 = 0b0000010011, // Sampling time of 21 TADCORE clock periods
    ADCON2_SHRSAMC_0022 = 0b0000010100, // Sampling time of 22 TADCORE clock periods
    ADCON2_SHRSAMC_0023 = 0b0000010101, // Sampling time of 23 TADCORE clock periods
    ADCON2_SHRSAMC_0024 = 0b0000010110, // Sampling time of 24 TADCORE clock periods
    ADCON2_SHRSAMC_0025 = 0b0000010111, // Sampling time of 25 TADCORE clock periods
    ADCON2_SHRSAMC_0026 = 0b0000011000, // Sampling time of 26 TADCORE clock periods
    ADCON2_SHRSAMC_0027 = 0b0000011001, // Sampling time of 27 TADCORE clock periods
    ADCON2_SHRSAMC_0028 = 0b0000011010, // Sampling time of 28 TADCORE clock periods
    ADCON2_SHRSAMC_0029 = 0b0000011011, // Sampling time of 29 TADCORE clock periods
    ADCON2_SHRSAMC_0030 = 0b0000011100, // Sampling time of 30 TADCORE clock periods
    ADCON2_SHRSAMC_0031 = 0b0000011101, // Sampling time of 31 TADCORE clock periods
    ADCON2_SHRSAMC_0032 = 0b0000011110, // Sampling time of 32 TADCORE clock periods
    ADCON2_SHRSAMC_0033 = 0b0000011111, // Sampling time of 33 TADCORE clock periods
    ADCON2_SHRSAMC_0034 = 0b0000100000, // Sampling time of 34 TADCORE clock periods
    ADCON2_SHRSAMC_0035 = 0b0000100001, // Sampling time of 35 TADCORE clock periods
    ADCON2_SHRSAMC_0036 = 0b0000100010, // Sampling time of 36 TADCORE clock periods
    ADCON2_SHRSAMC_0037 = 0b0000100011, // Sampling time of 37 TADCORE clock periods
    ADCON2_SHRSAMC_0038 = 0b0000100100, // Sampling time of 38 TADCORE clock periods
    ADCON2_SHRSAMC_0039 = 0b0000100101, // Sampling time of 39 TADCORE clock periods
    ADCON2_SHRSAMC_0040 = 0b0000100110, // Sampling time of 40 TADCORE clock periods
    ADCON2_SHRSAMC_0041 = 0b0000100111, // Sampling time of 41 TADCORE clock periods
    ADCON2_SHRSAMC_0042 = 0b0000101000, // Sampling time of 42 TADCORE clock periods
    ADCON2_SHRSAMC_0043 = 0b0000101001, // Sampling time of 43 TADCORE clock periods
    ADCON2_SHRSAMC_0044 = 0b0000101010, // Sampling time of 44 TADCORE clock periods
    ADCON2_SHRSAMC_0045 = 0b0000101011, // Sampling time of 45 TADCORE clock periods
    ADCON2_SHRSAMC_0046 = 0b0000101100, // Sampling time of 46 TADCORE clock periods
    ADCON2_SHRSAMC_0047 = 0b0000101101, // Sampling time of 47 TADCORE clock periods
    ADCON2_SHRSAMC_0048 = 0b0000101110, // Sampling time of 48 TADCORE clock periods
    ADCON2_SHRSAMC_0049 = 0b0000101111, // Sampling time of 49 TADCORE clock periods
    ADCON2_SHRSAMC_0050 = 0b0000110000, // Sampling time of 50 TADCORE clock periods
    ADCON2_SHRSAMC_0051 = 0b0000110001, // Sampling time of 51 TADCORE clock periods
    ADCON2_SHRSAMC_0052 = 0b0000110010, // Sampling time of 52 TADCORE clock periods
    ADCON2_SHRSAMC_0053 = 0b0000110011, // Sampling time of 53 TADCORE clock periods
    ADCON2_SHRSAMC_0054 = 0b0000110100, // Sampling time of 54 TADCORE clock periods
    ADCON2_SHRSAMC_0055 = 0b0000110101, // Sampling time of 55 TADCORE clock periods
    ADCON2_SHRSAMC_0056 = 0b0000110110, // Sampling time of 56 TADCORE clock periods
    ADCON2_SHRSAMC_0057 = 0b0000110111, // Sampling time of 57 TADCORE clock periods
    ADCON2_SHRSAMC_0058 = 0b0000111000, // Sampling time of 58 TADCORE clock periods
    ADCON2_SHRSAMC_0059 = 0b0000111001, // Sampling time of 59 TADCORE clock periods
    ADCON2_SHRSAMC_0060 = 0b0000111010, // Sampling time of 60 TADCORE clock periods
    ADCON2_SHRSAMC_0061 = 0b0000111011, // Sampling time of 61 TADCORE clock periods
    ADCON2_SHRSAMC_0062 = 0b0000111100, // Sampling time of 62 TADCORE clock periods
    ADCON2_SHRSAMC_0063 = 0b0000111101, // Sampling time of 63 TADCORE clock periods
    ADCON2_SHRSAMC_0064 = 0b0000111110, // Sampling time of 64 TADCORE clock periods
    ADCON2_SHRSAMC_0065 = 0b0000111111, // Sampling time of 65 TADCORE clock periods
    ADCON2_SHRSAMC_0066 = 0b0001000000, // Sampling time of 66 TADCORE clock periods
    ADCON2_SHRSAMC_0067 = 0b0001000001, // Sampling time of 67 TADCORE clock periods
    ADCON2_SHRSAMC_0068 = 0b0001000010, // Sampling time of 68 TADCORE clock periods
    ADCON2_SHRSAMC_0069 = 0b0001000011, // Sampling time of 69 TADCORE clock periods
    ADCON2_SHRSAMC_0070 = 0b0001000100, // Sampling time of 70 TADCORE clock periods
    ADCON2_SHRSAMC_0071 = 0b0001000101, // Sampling time of 71 TADCORE clock periods
    ADCON2_SHRSAMC_0072 = 0b0001000110, // Sampling time of 72 TADCORE clock periods
    ADCON2_SHRSAMC_0073 = 0b0001000111, // Sampling time of 73 TADCORE clock periods
    ADCON2_SHRSAMC_0074 = 0b0001001000, // Sampling time of 74 TADCORE clock periods
    ADCON2_SHRSAMC_0075 = 0b0001001001, // Sampling time of 75 TADCORE clock periods
    ADCON2_SHRSAMC_0076 = 0b0001001010, // Sampling time of 76 TADCORE clock periods
    ADCON2_SHRSAMC_0077 = 0b0001001011, // Sampling time of 77 TADCORE clock periods
    ADCON2_SHRSAMC_0078 = 0b0001001100, // Sampling time of 78 TADCORE clock periods
    ADCON2_SHRSAMC_0079 = 0b0001001101, // Sampling time of 79 TADCORE clock periods
    ADCON2_SHRSAMC_0080 = 0b0001001110, // Sampling time of 80 TADCORE clock periods
    ADCON2_SHRSAMC_0081 = 0b0001001111, // Sampling time of 81 TADCORE clock periods
    ADCON2_SHRSAMC_0082 = 0b0001010000, // Sampling time of 82 TADCORE clock periods
    ADCON2_SHRSAMC_0083 = 0b0001010001, // Sampling time of 83 TADCORE clock periods
    ADCON2_SHRSAMC_0084 = 0b0001010010, // Sampling time of 84 TADCORE clock periods
    ADCON2_SHRSAMC_0085 = 0b0001010011, // Sampling time of 85 TADCORE clock periods
    ADCON2_SHRSAMC_0086 = 0b0001010100, // Sampling time of 86 TADCORE clock periods
    ADCON2_SHRSAMC_0087 = 0b0001010101, // Sampling time of 87 TADCORE clock periods
    ADCON2_SHRSAMC_0088 = 0b0001010110, // Sampling time of 88 TADCORE clock periods
    ADCON2_SHRSAMC_0089 = 0b0001010111, // Sampling time of 89 TADCORE clock periods
    ADCON2_SHRSAMC_0090 = 0b0001011000, // Sampling time of 90 TADCORE clock periods
    ADCON2_SHRSAMC_0091 = 0b0001011001, // Sampling time of 91 TADCORE clock periods
    ADCON2_SHRSAMC_0092 = 0b0001011010, // Sampling time of 92 TADCORE clock periods
    ADCON2_SHRSAMC_0093 = 0b0001011011, // Sampling time of 93 TADCORE clock periods
    ADCON2_SHRSAMC_0094 = 0b0001011100, // Sampling time of 94 TADCORE clock periods
    ADCON2_SHRSAMC_0095 = 0b0001011101, // Sampling time of 95 TADCORE clock periods
    ADCON2_SHRSAMC_0096 = 0b0001011110, // Sampling time of 96 TADCORE clock periods
    ADCON2_SHRSAMC_0097 = 0b0001011111, // Sampling time of 97 TADCORE clock periods
    ADCON2_SHRSAMC_0098 = 0b0001100000, // Sampling time of 98 TADCORE clock periods
    ADCON2_SHRSAMC_0099 = 0b0001100001, // Sampling time of 99 TADCORE clock periods
    ADCON2_SHRSAMC_0100 = 0b0001100010, // Sampling time of 100 TADCORE clock periods
    ADCON2_SHRSAMC_0101 = 0b0001100011, // Sampling time of 101 TADCORE clock periods
    ADCON2_SHRSAMC_0102 = 0b0001100100, // Sampling time of 102 TADCORE clock periods
    ADCON2_SHRSAMC_0103 = 0b0001100101, // Sampling time of 103 TADCORE clock periods
    ADCON2_SHRSAMC_0104 = 0b0001100110, // Sampling time of 104 TADCORE clock periods
    ADCON2_SHRSAMC_0105 = 0b0001100111, // Sampling time of 105 TADCORE clock periods
    ADCON2_SHRSAMC_0106 = 0b0001101000, // Sampling time of 106 TADCORE clock periods
    ADCON2_SHRSAMC_0107 = 0b0001101001, // Sampling time of 107 TADCORE clock periods
    ADCON2_SHRSAMC_0108 = 0b0001101010, // Sampling time of 108 TADCORE clock periods
    ADCON2_SHRSAMC_0109 = 0b0001101011, // Sampling time of 109 TADCORE clock periods
    ADCON2_SHRSAMC_0110 = 0b0001101100, // Sampling time of 110 TADCORE clock periods
    ADCON2_SHRSAMC_0111 = 0b0001101101, // Sampling time of 111 TADCORE clock periods
    ADCON2_SHRSAMC_0112 = 0b0001101110, // Sampling time of 112 TADCORE clock periods
    ADCON2_SHRSAMC_0113 = 0b0001101111, // Sampling time of 113 TADCORE clock periods
    ADCON2_SHRSAMC_0114 = 0b0001110000, // Sampling time of 114 TADCORE clock periods
    ADCON2_SHRSAMC_0115 = 0b0001110001, // Sampling time of 115 TADCORE clock periods
    ADCON2_SHRSAMC_0116 = 0b0001110010, // Sampling time of 116 TADCORE clock periods
    ADCON2_SHRSAMC_0117 = 0b0001110011, // Sampling time of 117 TADCORE clock periods
    ADCON2_SHRSAMC_0118 = 0b0001110100, // Sampling time of 118 TADCORE clock periods
    ADCON2_SHRSAMC_0119 = 0b0001110101, // Sampling time of 119 TADCORE clock periods
    ADCON2_SHRSAMC_0120 = 0b0001110110, // Sampling time of 120 TADCORE clock periods
    ADCON2_SHRSAMC_0121 = 0b0001110111, // Sampling time of 121 TADCORE clock periods
    ADCON2_SHRSAMC_0122 = 0b0001111000, // Sampling time of 122 TADCORE clock periods
    ADCON2_SHRSAMC_0123 = 0b0001111001, // Sampling time of 123 TADCORE clock periods
    ADCON2_SHRSAMC_0124 = 0b0001111010, // Sampling time of 124 TADCORE clock periods
    ADCON2_SHRSAMC_0125 = 0b0001111011, // Sampling time of 125 TADCORE clock periods
    ADCON2_SHRSAMC_0126 = 0b0001111100, // Sampling time of 126 TADCORE clock periods
    ADCON2_SHRSAMC_0127 = 0b0001111101, // Sampling time of 127 TADCORE clock periods
    ADCON2_SHRSAMC_0128 = 0b0001111110, // Sampling time of 128 TADCORE clock periods
    ADCON2_SHRSAMC_0129 = 0b0001111111, // Sampling time of 129 TADCORE clock periods
    ADCON2_SHRSAMC_0130 = 0b0010000000, // Sampling time of 130 TADCORE clock periods
    ADCON2_SHRSAMC_0131 = 0b0010000001, // Sampling time of 131 TADCORE clock periods
    ADCON2_SHRSAMC_0132 = 0b0010000010, // Sampling time of 132 TADCORE clock periods
    ADCON2_SHRSAMC_0133 = 0b0010000011, // Sampling time of 133 TADCORE clock periods
    ADCON2_SHRSAMC_0134 = 0b0010000100, // Sampling time of 134 TADCORE clock periods
    ADCON2_SHRSAMC_0135 = 0b0010000101, // Sampling time of 135 TADCORE clock periods
    ADCON2_SHRSAMC_0136 = 0b0010000110, // Sampling time of 136 TADCORE clock periods
    ADCON2_SHRSAMC_0137 = 0b0010000111, // Sampling time of 137 TADCORE clock periods
    ADCON2_SHRSAMC_0138 = 0b0010001000, // Sampling time of 138 TADCORE clock periods
    ADCON2_SHRSAMC_0139 = 0b0010001001, // Sampling time of 139 TADCORE clock periods
    ADCON2_SHRSAMC_0140 = 0b0010001010, // Sampling time of 140 TADCORE clock periods
    ADCON2_SHRSAMC_0141 = 0b0010001011, // Sampling time of 141 TADCORE clock periods
    ADCON2_SHRSAMC_0142 = 0b0010001100, // Sampling time of 142 TADCORE clock periods
    ADCON2_SHRSAMC_0143 = 0b0010001101, // Sampling time of 143 TADCORE clock periods
    ADCON2_SHRSAMC_0144 = 0b0010001110, // Sampling time of 144 TADCORE clock periods
    ADCON2_SHRSAMC_0145 = 0b0010001111, // Sampling time of 145 TADCORE clock periods
    ADCON2_SHRSAMC_0146 = 0b0010010000, // Sampling time of 146 TADCORE clock periods
    ADCON2_SHRSAMC_0147 = 0b0010010001, // Sampling time of 147 TADCORE clock periods
    ADCON2_SHRSAMC_0148 = 0b0010010010, // Sampling time of 148 TADCORE clock periods
    ADCON2_SHRSAMC_0149 = 0b0010010011, // Sampling time of 149 TADCORE clock periods
    ADCON2_SHRSAMC_0150 = 0b0010010100, // Sampling time of 150 TADCORE clock periods
    ADCON2_SHRSAMC_0151 = 0b0010010101, // Sampling time of 151 TADCORE clock periods
    ADCON2_SHRSAMC_0152 = 0b0010010110, // Sampling time of 152 TADCORE clock periods
    ADCON2_SHRSAMC_0153 = 0b0010010111, // Sampling time of 153 TADCORE clock periods
    ADCON2_SHRSAMC_0154 = 0b0010011000, // Sampling time of 154 TADCORE clock periods
    ADCON2_SHRSAMC_0155 = 0b0010011001, // Sampling time of 155 TADCORE clock periods
    ADCON2_SHRSAMC_0156 = 0b0010011010, // Sampling time of 156 TADCORE clock periods
    ADCON2_SHRSAMC_0157 = 0b0010011011, // Sampling time of 157 TADCORE clock periods
    ADCON2_SHRSAMC_0158 = 0b0010011100, // Sampling time of 158 TADCORE clock periods
    ADCON2_SHRSAMC_0159 = 0b0010011101, // Sampling time of 159 TADCORE clock periods
    ADCON2_SHRSAMC_0160 = 0b0010011110, // Sampling time of 160 TADCORE clock periods
    ADCON2_SHRSAMC_0161 = 0b0010011111, // Sampling time of 161 TADCORE clock periods
    ADCON2_SHRSAMC_0162 = 0b0010100000, // Sampling time of 162 TADCORE clock periods
    ADCON2_SHRSAMC_0163 = 0b0010100001, // Sampling time of 163 TADCORE clock periods
    ADCON2_SHRSAMC_0164 = 0b0010100010, // Sampling time of 164 TADCORE clock periods
    ADCON2_SHRSAMC_0165 = 0b0010100011, // Sampling time of 165 TADCORE clock periods
    ADCON2_SHRSAMC_0166 = 0b0010100100, // Sampling time of 166 TADCORE clock periods
    ADCON2_SHRSAMC_0167 = 0b0010100101, // Sampling time of 167 TADCORE clock periods
    ADCON2_SHRSAMC_0168 = 0b0010100110, // Sampling time of 168 TADCORE clock periods
    ADCON2_SHRSAMC_0169 = 0b0010100111, // Sampling time of 169 TADCORE clock periods
    ADCON2_SHRSAMC_0170 = 0b0010101000, // Sampling time of 170 TADCORE clock periods
    ADCON2_SHRSAMC_0171 = 0b0010101001, // Sampling time of 171 TADCORE clock periods
    ADCON2_SHRSAMC_0172 = 0b0010101010, // Sampling time of 172 TADCORE clock periods
    ADCON2_SHRSAMC_0173 = 0b0010101011, // Sampling time of 173 TADCORE clock periods
    ADCON2_SHRSAMC_0174 = 0b0010101100, // Sampling time of 174 TADCORE clock periods
    ADCON2_SHRSAMC_0175 = 0b0010101101, // Sampling time of 175 TADCORE clock periods
    ADCON2_SHRSAMC_0176 = 0b0010101110, // Sampling time of 176 TADCORE clock periods
    ADCON2_SHRSAMC_0177 = 0b0010101111, // Sampling time of 177 TADCORE clock periods
    ADCON2_SHRSAMC_0178 = 0b0010110000, // Sampling time of 178 TADCORE clock periods
    ADCON2_SHRSAMC_0179 = 0b0010110001, // Sampling time of 179 TADCORE clock periods
    ADCON2_SHRSAMC_0180 = 0b0010110010, // Sampling time of 180 TADCORE clock periods
    ADCON2_SHRSAMC_0181 = 0b0010110011, // Sampling time of 181 TADCORE clock periods
    ADCON2_SHRSAMC_0182 = 0b0010110100, // Sampling time of 182 TADCORE clock periods
    ADCON2_SHRSAMC_0183 = 0b0010110101, // Sampling time of 183 TADCORE clock periods
    ADCON2_SHRSAMC_0184 = 0b0010110110, // Sampling time of 184 TADCORE clock periods
    ADCON2_SHRSAMC_0185 = 0b0010110111, // Sampling time of 185 TADCORE clock periods
    ADCON2_SHRSAMC_0186 = 0b0010111000, // Sampling time of 186 TADCORE clock periods
    ADCON2_SHRSAMC_0187 = 0b0010111001, // Sampling time of 187 TADCORE clock periods
    ADCON2_SHRSAMC_0188 = 0b0010111010, // Sampling time of 188 TADCORE clock periods
    ADCON2_SHRSAMC_0189 = 0b0010111011, // Sampling time of 189 TADCORE clock periods
    ADCON2_SHRSAMC_0190 = 0b0010111100, // Sampling time of 190 TADCORE clock periods
    ADCON2_SHRSAMC_0191 = 0b0010111101, // Sampling time of 191 TADCORE clock periods
    ADCON2_SHRSAMC_0192 = 0b0010111110, // Sampling time of 192 TADCORE clock periods
    ADCON2_SHRSAMC_0193 = 0b0010111111, // Sampling time of 193 TADCORE clock periods
    ADCON2_SHRSAMC_0194 = 0b0011000000, // Sampling time of 194 TADCORE clock periods
    ADCON2_SHRSAMC_0195 = 0b0011000001, // Sampling time of 195 TADCORE clock periods
    ADCON2_SHRSAMC_0196 = 0b0011000010, // Sampling time of 196 TADCORE clock periods
    ADCON2_SHRSAMC_0197 = 0b0011000011, // Sampling time of 197 TADCORE clock periods
    ADCON2_SHRSAMC_0198 = 0b0011000100, // Sampling time of 198 TADCORE clock periods
    ADCON2_SHRSAMC_0199 = 0b0011000101, // Sampling time of 199 TADCORE clock periods
    ADCON2_SHRSAMC_0200 = 0b0011000110, // Sampling time of 200 TADCORE clock periods
    ADCON2_SHRSAMC_0201 = 0b0011000111, // Sampling time of 201 TADCORE clock periods
    ADCON2_SHRSAMC_0202 = 0b0011001000, // Sampling time of 202 TADCORE clock periods
    ADCON2_SHRSAMC_0203 = 0b0011001001, // Sampling time of 203 TADCORE clock periods
    ADCON2_SHRSAMC_0204 = 0b0011001010, // Sampling time of 204 TADCORE clock periods
    ADCON2_SHRSAMC_0205 = 0b0011001011, // Sampling time of 205 TADCORE clock periods
    ADCON2_SHRSAMC_0206 = 0b0011001100, // Sampling time of 206 TADCORE clock periods
    ADCON2_SHRSAMC_0207 = 0b0011001101, // Sampling time of 207 TADCORE clock periods
    ADCON2_SHRSAMC_0208 = 0b0011001110, // Sampling time of 208 TADCORE clock periods
    ADCON2_SHRSAMC_0209 = 0b0011001111, // Sampling time of 209 TADCORE clock periods
    ADCON2_SHRSAMC_0210 = 0b0011010000, // Sampling time of 210 TADCORE clock periods
    ADCON2_SHRSAMC_0211 = 0b0011010001, // Sampling time of 211 TADCORE clock periods
    ADCON2_SHRSAMC_0212 = 0b0011010010, // Sampling time of 212 TADCORE clock periods
    ADCON2_SHRSAMC_0213 = 0b0011010011, // Sampling time of 213 TADCORE clock periods
    ADCON2_SHRSAMC_0214 = 0b0011010100, // Sampling time of 214 TADCORE clock periods
    ADCON2_SHRSAMC_0215 = 0b0011010101, // Sampling time of 215 TADCORE clock periods
    ADCON2_SHRSAMC_0216 = 0b0011010110, // Sampling time of 216 TADCORE clock periods
    ADCON2_SHRSAMC_0217 = 0b0011010111, // Sampling time of 217 TADCORE clock periods
    ADCON2_SHRSAMC_0218 = 0b0011011000, // Sampling time of 218 TADCORE clock periods
    ADCON2_SHRSAMC_0219 = 0b0011011001, // Sampling time of 219 TADCORE clock periods
    ADCON2_SHRSAMC_0220 = 0b0011011010, // Sampling time of 220 TADCORE clock periods
    ADCON2_SHRSAMC_0221 = 0b0011011011, // Sampling time of 221 TADCORE clock periods
    ADCON2_SHRSAMC_0222 = 0b0011011100, // Sampling time of 222 TADCORE clock periods
    ADCON2_SHRSAMC_0223 = 0b0011011101, // Sampling time of 223 TADCORE clock periods
    ADCON2_SHRSAMC_0224 = 0b0011011110, // Sampling time of 224 TADCORE clock periods
    ADCON2_SHRSAMC_0225 = 0b0011011111, // Sampling time of 225 TADCORE clock periods
    ADCON2_SHRSAMC_0226 = 0b0011100000, // Sampling time of 226 TADCORE clock periods
    ADCON2_SHRSAMC_0227 = 0b0011100001, // Sampling time of 227 TADCORE clock periods
    ADCON2_SHRSAMC_0228 = 0b0011100010, // Sampling time of 228 TADCORE clock periods
    ADCON2_SHRSAMC_0229 = 0b0011100011, // Sampling time of 229 TADCORE clock periods
    ADCON2_SHRSAMC_0230 = 0b0011100100, // Sampling time of 230 TADCORE clock periods
    ADCON2_SHRSAMC_0231 = 0b0011100101, // Sampling time of 231 TADCORE clock periods
    ADCON2_SHRSAMC_0232 = 0b0011100110, // Sampling time of 232 TADCORE clock periods
    ADCON2_SHRSAMC_0233 = 0b0011100111, // Sampling time of 233 TADCORE clock periods
    ADCON2_SHRSAMC_0234 = 0b0011101000, // Sampling time of 234 TADCORE clock periods
    ADCON2_SHRSAMC_0235 = 0b0011101001, // Sampling time of 235 TADCORE clock periods
    ADCON2_SHRSAMC_0236 = 0b0011101010, // Sampling time of 236 TADCORE clock periods
    ADCON2_SHRSAMC_0237 = 0b0011101011, // Sampling time of 237 TADCORE clock periods
    ADCON2_SHRSAMC_0238 = 0b0011101100, // Sampling time of 238 TADCORE clock periods
    ADCON2_SHRSAMC_0239 = 0b0011101101, // Sampling time of 239 TADCORE clock periods
    ADCON2_SHRSAMC_0240 = 0b0011101110, // Sampling time of 240 TADCORE clock periods
    ADCON2_SHRSAMC_0241 = 0b0011101111, // Sampling time of 241 TADCORE clock periods
    ADCON2_SHRSAMC_0242 = 0b0011110000, // Sampling time of 242 TADCORE clock periods
    ADCON2_SHRSAMC_0243 = 0b0011110001, // Sampling time of 243 TADCORE clock periods
    ADCON2_SHRSAMC_0244 = 0b0011110010, // Sampling time of 244 TADCORE clock periods
    ADCON2_SHRSAMC_0245 = 0b0011110011, // Sampling time of 245 TADCORE clock periods
    ADCON2_SHRSAMC_0246 = 0b0011110100, // Sampling time of 246 TADCORE clock periods
    ADCON2_SHRSAMC_0247 = 0b0011110101, // Sampling time of 247 TADCORE clock periods
    ADCON2_SHRSAMC_0248 = 0b0011110110, // Sampling time of 248 TADCORE clock periods
    ADCON2_SHRSAMC_0249 = 0b0011110111, // Sampling time of 249 TADCORE clock periods
    ADCON2_SHRSAMC_0250 = 0b0011111000, // Sampling time of 250 TADCORE clock periods
    ADCON2_SHRSAMC_0251 = 0b0011111001, // Sampling time of 251 TADCORE clock periods
    ADCON2_SHRSAMC_0252 = 0b0011111010, // Sampling time of 252 TADCORE clock periods
    ADCON2_SHRSAMC_0253 = 0b0011111011, // Sampling time of 253 TADCORE clock periods
    ADCON2_SHRSAMC_0254 = 0b0011111100, // Sampling time of 254 TADCORE clock periods
    ADCON2_SHRSAMC_0255 = 0b0011111101, // Sampling time of 255 TADCORE clock periods
    ADCON2_SHRSAMC_0256 = 0b0011111110, // Sampling time of 256 TADCORE clock periods
    ADCON2_SHRSAMC_0257 = 0b0011111111, // Sampling time of 257 TADCORE clock periods
    ADCON2_SHRSAMC_0258 = 0b0100000000, // Sampling time of 258 TADCORE clock periods
    ADCON2_SHRSAMC_0259 = 0b0100000001, // Sampling time of 259 TADCORE clock periods
    ADCON2_SHRSAMC_0260 = 0b0100000010, // Sampling time of 260 TADCORE clock periods
    ADCON2_SHRSAMC_0261 = 0b0100000011, // Sampling time of 261 TADCORE clock periods
    ADCON2_SHRSAMC_0262 = 0b0100000100, // Sampling time of 262 TADCORE clock periods
    ADCON2_SHRSAMC_0263 = 0b0100000101, // Sampling time of 263 TADCORE clock periods
    ADCON2_SHRSAMC_0264 = 0b0100000110, // Sampling time of 264 TADCORE clock periods
    ADCON2_SHRSAMC_0265 = 0b0100000111, // Sampling time of 265 TADCORE clock periods
    ADCON2_SHRSAMC_0266 = 0b0100001000, // Sampling time of 266 TADCORE clock periods
    ADCON2_SHRSAMC_0267 = 0b0100001001, // Sampling time of 267 TADCORE clock periods
    ADCON2_SHRSAMC_0268 = 0b0100001010, // Sampling time of 268 TADCORE clock periods
    ADCON2_SHRSAMC_0269 = 0b0100001011, // Sampling time of 269 TADCORE clock periods
    ADCON2_SHRSAMC_0270 = 0b0100001100, // Sampling time of 270 TADCORE clock periods
    ADCON2_SHRSAMC_0271 = 0b0100001101, // Sampling time of 271 TADCORE clock periods
    ADCON2_SHRSAMC_0272 = 0b0100001110, // Sampling time of 272 TADCORE clock periods
    ADCON2_SHRSAMC_0273 = 0b0100001111, // Sampling time of 273 TADCORE clock periods
    ADCON2_SHRSAMC_0274 = 0b0100010000, // Sampling time of 274 TADCORE clock periods
    ADCON2_SHRSAMC_0275 = 0b0100010001, // Sampling time of 275 TADCORE clock periods
    ADCON2_SHRSAMC_0276 = 0b0100010010, // Sampling time of 276 TADCORE clock periods
    ADCON2_SHRSAMC_0277 = 0b0100010011, // Sampling time of 277 TADCORE clock periods
    ADCON2_SHRSAMC_0278 = 0b0100010100, // Sampling time of 278 TADCORE clock periods
    ADCON2_SHRSAMC_0279 = 0b0100010101, // Sampling time of 279 TADCORE clock periods
    ADCON2_SHRSAMC_0280 = 0b0100010110, // Sampling time of 280 TADCORE clock periods
    ADCON2_SHRSAMC_0281 = 0b0100010111, // Sampling time of 281 TADCORE clock periods
    ADCON2_SHRSAMC_0282 = 0b0100011000, // Sampling time of 282 TADCORE clock periods
    ADCON2_SHRSAMC_0283 = 0b0100011001, // Sampling time of 283 TADCORE clock periods
    ADCON2_SHRSAMC_0284 = 0b0100011010, // Sampling time of 284 TADCORE clock periods
    ADCON2_SHRSAMC_0285 = 0b0100011011, // Sampling time of 285 TADCORE clock periods
    ADCON2_SHRSAMC_0286 = 0b0100011100, // Sampling time of 286 TADCORE clock periods
    ADCON2_SHRSAMC_0287 = 0b0100011101, // Sampling time of 287 TADCORE clock periods
    ADCON2_SHRSAMC_0288 = 0b0100011110, // Sampling time of 288 TADCORE clock periods
    ADCON2_SHRSAMC_0289 = 0b0100011111, // Sampling time of 289 TADCORE clock periods
    ADCON2_SHRSAMC_0290 = 0b0100100000, // Sampling time of 290 TADCORE clock periods
    ADCON2_SHRSAMC_0291 = 0b0100100001, // Sampling time of 291 TADCORE clock periods
    ADCON2_SHRSAMC_0292 = 0b0100100010, // Sampling time of 292 TADCORE clock periods
    ADCON2_SHRSAMC_0293 = 0b0100100011, // Sampling time of 293 TADCORE clock periods
    ADCON2_SHRSAMC_0294 = 0b0100100100, // Sampling time of 294 TADCORE clock periods
    ADCON2_SHRSAMC_0295 = 0b0100100101, // Sampling time of 295 TADCORE clock periods
    ADCON2_SHRSAMC_0296 = 0b0100100110, // Sampling time of 296 TADCORE clock periods
    ADCON2_SHRSAMC_0297 = 0b0100100111, // Sampling time of 297 TADCORE clock periods
    ADCON2_SHRSAMC_0298 = 0b0100101000, // Sampling time of 298 TADCORE clock periods
    ADCON2_SHRSAMC_0299 = 0b0100101001, // Sampling time of 299 TADCORE clock periods
    ADCON2_SHRSAMC_0300 = 0b0100101010, // Sampling time of 300 TADCORE clock periods
    ADCON2_SHRSAMC_0301 = 0b0100101011, // Sampling time of 301 TADCORE clock periods
    ADCON2_SHRSAMC_0302 = 0b0100101100, // Sampling time of 302 TADCORE clock periods
    ADCON2_SHRSAMC_0303 = 0b0100101101, // Sampling time of 303 TADCORE clock periods
    ADCON2_SHRSAMC_0304 = 0b0100101110, // Sampling time of 304 TADCORE clock periods
    ADCON2_SHRSAMC_0305 = 0b0100101111, // Sampling time of 305 TADCORE clock periods
    ADCON2_SHRSAMC_0306 = 0b0100110000, // Sampling time of 306 TADCORE clock periods
    ADCON2_SHRSAMC_0307 = 0b0100110001, // Sampling time of 307 TADCORE clock periods
    ADCON2_SHRSAMC_0308 = 0b0100110010, // Sampling time of 308 TADCORE clock periods
    ADCON2_SHRSAMC_0309 = 0b0100110011, // Sampling time of 309 TADCORE clock periods
    ADCON2_SHRSAMC_0310 = 0b0100110100, // Sampling time of 310 TADCORE clock periods
    ADCON2_SHRSAMC_0311 = 0b0100110101, // Sampling time of 311 TADCORE clock periods
    ADCON2_SHRSAMC_0312 = 0b0100110110, // Sampling time of 312 TADCORE clock periods
    ADCON2_SHRSAMC_0313 = 0b0100110111, // Sampling time of 313 TADCORE clock periods
    ADCON2_SHRSAMC_0314 = 0b0100111000, // Sampling time of 314 TADCORE clock periods
    ADCON2_SHRSAMC_0315 = 0b0100111001, // Sampling time of 315 TADCORE clock periods
    ADCON2_SHRSAMC_0316 = 0b0100111010, // Sampling time of 316 TADCORE clock periods
    ADCON2_SHRSAMC_0317 = 0b0100111011, // Sampling time of 317 TADCORE clock periods
    ADCON2_SHRSAMC_0318 = 0b0100111100, // Sampling time of 318 TADCORE clock periods
    ADCON2_SHRSAMC_0319 = 0b0100111101, // Sampling time of 319 TADCORE clock periods
    ADCON2_SHRSAMC_0320 = 0b0100111110, // Sampling time of 320 TADCORE clock periods
    ADCON2_SHRSAMC_0321 = 0b0100111111, // Sampling time of 321 TADCORE clock periods
    ADCON2_SHRSAMC_0322 = 0b0101000000, // Sampling time of 322 TADCORE clock periods
    ADCON2_SHRSAMC_0323 = 0b0101000001, // Sampling time of 323 TADCORE clock periods
    ADCON2_SHRSAMC_0324 = 0b0101000010, // Sampling time of 324 TADCORE clock periods
    ADCON2_SHRSAMC_0325 = 0b0101000011, // Sampling time of 325 TADCORE clock periods
    ADCON2_SHRSAMC_0326 = 0b0101000100, // Sampling time of 326 TADCORE clock periods
    ADCON2_SHRSAMC_0327 = 0b0101000101, // Sampling time of 327 TADCORE clock periods
    ADCON2_SHRSAMC_0328 = 0b0101000110, // Sampling time of 328 TADCORE clock periods
    ADCON2_SHRSAMC_0329 = 0b0101000111, // Sampling time of 329 TADCORE clock periods
    ADCON2_SHRSAMC_0330 = 0b0101001000, // Sampling time of 330 TADCORE clock periods
    ADCON2_SHRSAMC_0331 = 0b0101001001, // Sampling time of 331 TADCORE clock periods
    ADCON2_SHRSAMC_0332 = 0b0101001010, // Sampling time of 332 TADCORE clock periods
    ADCON2_SHRSAMC_0333 = 0b0101001011, // Sampling time of 333 TADCORE clock periods
    ADCON2_SHRSAMC_0334 = 0b0101001100, // Sampling time of 334 TADCORE clock periods
    ADCON2_SHRSAMC_0335 = 0b0101001101, // Sampling time of 335 TADCORE clock periods
    ADCON2_SHRSAMC_0336 = 0b0101001110, // Sampling time of 336 TADCORE clock periods
    ADCON2_SHRSAMC_0337 = 0b0101001111, // Sampling time of 337 TADCORE clock periods
    ADCON2_SHRSAMC_0338 = 0b0101010000, // Sampling time of 338 TADCORE clock periods
    ADCON2_SHRSAMC_0339 = 0b0101010001, // Sampling time of 339 TADCORE clock periods
    ADCON2_SHRSAMC_0340 = 0b0101010010, // Sampling time of 340 TADCORE clock periods
    ADCON2_SHRSAMC_0341 = 0b0101010011, // Sampling time of 341 TADCORE clock periods
    ADCON2_SHRSAMC_0342 = 0b0101010100, // Sampling time of 342 TADCORE clock periods
    ADCON2_SHRSAMC_0343 = 0b0101010101, // Sampling time of 343 TADCORE clock periods
    ADCON2_SHRSAMC_0344 = 0b0101010110, // Sampling time of 344 TADCORE clock periods
    ADCON2_SHRSAMC_0345 = 0b0101010111, // Sampling time of 345 TADCORE clock periods
    ADCON2_SHRSAMC_0346 = 0b0101011000, // Sampling time of 346 TADCORE clock periods
    ADCON2_SHRSAMC_0347 = 0b0101011001, // Sampling time of 347 TADCORE clock periods
    ADCON2_SHRSAMC_0348 = 0b0101011010, // Sampling time of 348 TADCORE clock periods
    ADCON2_SHRSAMC_0349 = 0b0101011011, // Sampling time of 349 TADCORE clock periods
    ADCON2_SHRSAMC_0350 = 0b0101011100, // Sampling time of 350 TADCORE clock periods
    ADCON2_SHRSAMC_0351 = 0b0101011101, // Sampling time of 351 TADCORE clock periods
    ADCON2_SHRSAMC_0352 = 0b0101011110, // Sampling time of 352 TADCORE clock periods
    ADCON2_SHRSAMC_0353 = 0b0101011111, // Sampling time of 353 TADCORE clock periods
    ADCON2_SHRSAMC_0354 = 0b0101100000, // Sampling time of 354 TADCORE clock periods
    ADCON2_SHRSAMC_0355 = 0b0101100001, // Sampling time of 355 TADCORE clock periods
    ADCON2_SHRSAMC_0356 = 0b0101100010, // Sampling time of 356 TADCORE clock periods
    ADCON2_SHRSAMC_0357 = 0b0101100011, // Sampling time of 357 TADCORE clock periods
    ADCON2_SHRSAMC_0358 = 0b0101100100, // Sampling time of 358 TADCORE clock periods
    ADCON2_SHRSAMC_0359 = 0b0101100101, // Sampling time of 359 TADCORE clock periods
    ADCON2_SHRSAMC_0360 = 0b0101100110, // Sampling time of 360 TADCORE clock periods
    ADCON2_SHRSAMC_0361 = 0b0101100111, // Sampling time of 361 TADCORE clock periods
    ADCON2_SHRSAMC_0362 = 0b0101101000, // Sampling time of 362 TADCORE clock periods
    ADCON2_SHRSAMC_0363 = 0b0101101001, // Sampling time of 363 TADCORE clock periods
    ADCON2_SHRSAMC_0364 = 0b0101101010, // Sampling time of 364 TADCORE clock periods
    ADCON2_SHRSAMC_0365 = 0b0101101011, // Sampling time of 365 TADCORE clock periods
    ADCON2_SHRSAMC_0366 = 0b0101101100, // Sampling time of 366 TADCORE clock periods
    ADCON2_SHRSAMC_0367 = 0b0101101101, // Sampling time of 367 TADCORE clock periods
    ADCON2_SHRSAMC_0368 = 0b0101101110, // Sampling time of 368 TADCORE clock periods
    ADCON2_SHRSAMC_0369 = 0b0101101111, // Sampling time of 369 TADCORE clock periods
    ADCON2_SHRSAMC_0370 = 0b0101110000, // Sampling time of 370 TADCORE clock periods
    ADCON2_SHRSAMC_0371 = 0b0101110001, // Sampling time of 371 TADCORE clock periods
    ADCON2_SHRSAMC_0372 = 0b0101110010, // Sampling time of 372 TADCORE clock periods
    ADCON2_SHRSAMC_0373 = 0b0101110011, // Sampling time of 373 TADCORE clock periods
    ADCON2_SHRSAMC_0374 = 0b0101110100, // Sampling time of 374 TADCORE clock periods
    ADCON2_SHRSAMC_0375 = 0b0101110101, // Sampling time of 375 TADCORE clock periods
    ADCON2_SHRSAMC_0376 = 0b0101110110, // Sampling time of 376 TADCORE clock periods
    ADCON2_SHRSAMC_0377 = 0b0101110111, // Sampling time of 377 TADCORE clock periods
    ADCON2_SHRSAMC_0378 = 0b0101111000, // Sampling time of 378 TADCORE clock periods
    ADCON2_SHRSAMC_0379 = 0b0101111001, // Sampling time of 379 TADCORE clock periods
    ADCON2_SHRSAMC_0380 = 0b0101111010, // Sampling time of 380 TADCORE clock periods
    ADCON2_SHRSAMC_0381 = 0b0101111011, // Sampling time of 381 TADCORE clock periods
    ADCON2_SHRSAMC_0382 = 0b0101111100, // Sampling time of 382 TADCORE clock periods
    ADCON2_SHRSAMC_0383 = 0b0101111101, // Sampling time of 383 TADCORE clock periods
    ADCON2_SHRSAMC_0384 = 0b0101111110, // Sampling time of 384 TADCORE clock periods
    ADCON2_SHRSAMC_0385 = 0b0101111111, // Sampling time of 385 TADCORE clock periods
    ADCON2_SHRSAMC_0386 = 0b0110000000, // Sampling time of 386 TADCORE clock periods
    ADCON2_SHRSAMC_0387 = 0b0110000001, // Sampling time of 387 TADCORE clock periods
    ADCON2_SHRSAMC_0388 = 0b0110000010, // Sampling time of 388 TADCORE clock periods
    ADCON2_SHRSAMC_0389 = 0b0110000011, // Sampling time of 389 TADCORE clock periods
    ADCON2_SHRSAMC_0390 = 0b0110000100, // Sampling time of 390 TADCORE clock periods
    ADCON2_SHRSAMC_0391 = 0b0110000101, // Sampling time of 391 TADCORE clock periods
    ADCON2_SHRSAMC_0392 = 0b0110000110, // Sampling time of 392 TADCORE clock periods
    ADCON2_SHRSAMC_0393 = 0b0110000111, // Sampling time of 393 TADCORE clock periods
    ADCON2_SHRSAMC_0394 = 0b0110001000, // Sampling time of 394 TADCORE clock periods
    ADCON2_SHRSAMC_0395 = 0b0110001001, // Sampling time of 395 TADCORE clock periods
    ADCON2_SHRSAMC_0396 = 0b0110001010, // Sampling time of 396 TADCORE clock periods
    ADCON2_SHRSAMC_0397 = 0b0110001011, // Sampling time of 397 TADCORE clock periods
    ADCON2_SHRSAMC_0398 = 0b0110001100, // Sampling time of 398 TADCORE clock periods
    ADCON2_SHRSAMC_0399 = 0b0110001101, // Sampling time of 399 TADCORE clock periods
    ADCON2_SHRSAMC_0400 = 0b0110001110, // Sampling time of 400 TADCORE clock periods
    ADCON2_SHRSAMC_0401 = 0b0110001111, // Sampling time of 401 TADCORE clock periods
    ADCON2_SHRSAMC_0402 = 0b0110010000, // Sampling time of 402 TADCORE clock periods
    ADCON2_SHRSAMC_0403 = 0b0110010001, // Sampling time of 403 TADCORE clock periods
    ADCON2_SHRSAMC_0404 = 0b0110010010, // Sampling time of 404 TADCORE clock periods
    ADCON2_SHRSAMC_0405 = 0b0110010011, // Sampling time of 405 TADCORE clock periods
    ADCON2_SHRSAMC_0406 = 0b0110010100, // Sampling time of 406 TADCORE clock periods
    ADCON2_SHRSAMC_0407 = 0b0110010101, // Sampling time of 407 TADCORE clock periods
    ADCON2_SHRSAMC_0408 = 0b0110010110, // Sampling time of 408 TADCORE clock periods
    ADCON2_SHRSAMC_0409 = 0b0110010111, // Sampling time of 409 TADCORE clock periods
    ADCON2_SHRSAMC_0410 = 0b0110011000, // Sampling time of 410 TADCORE clock periods
    ADCON2_SHRSAMC_0411 = 0b0110011001, // Sampling time of 411 TADCORE clock periods
    ADCON2_SHRSAMC_0412 = 0b0110011010, // Sampling time of 412 TADCORE clock periods
    ADCON2_SHRSAMC_0413 = 0b0110011011, // Sampling time of 413 TADCORE clock periods
    ADCON2_SHRSAMC_0414 = 0b0110011100, // Sampling time of 414 TADCORE clock periods
    ADCON2_SHRSAMC_0415 = 0b0110011101, // Sampling time of 415 TADCORE clock periods
    ADCON2_SHRSAMC_0416 = 0b0110011110, // Sampling time of 416 TADCORE clock periods
    ADCON2_SHRSAMC_0417 = 0b0110011111, // Sampling time of 417 TADCORE clock periods
    ADCON2_SHRSAMC_0418 = 0b0110100000, // Sampling time of 418 TADCORE clock periods
    ADCON2_SHRSAMC_0419 = 0b0110100001, // Sampling time of 419 TADCORE clock periods
    ADCON2_SHRSAMC_0420 = 0b0110100010, // Sampling time of 420 TADCORE clock periods
    ADCON2_SHRSAMC_0421 = 0b0110100011, // Sampling time of 421 TADCORE clock periods
    ADCON2_SHRSAMC_0422 = 0b0110100100, // Sampling time of 422 TADCORE clock periods
    ADCON2_SHRSAMC_0423 = 0b0110100101, // Sampling time of 423 TADCORE clock periods
    ADCON2_SHRSAMC_0424 = 0b0110100110, // Sampling time of 424 TADCORE clock periods
    ADCON2_SHRSAMC_0425 = 0b0110100111, // Sampling time of 425 TADCORE clock periods
    ADCON2_SHRSAMC_0426 = 0b0110101000, // Sampling time of 426 TADCORE clock periods
    ADCON2_SHRSAMC_0427 = 0b0110101001, // Sampling time of 427 TADCORE clock periods
    ADCON2_SHRSAMC_0428 = 0b0110101010, // Sampling time of 428 TADCORE clock periods
    ADCON2_SHRSAMC_0429 = 0b0110101011, // Sampling time of 429 TADCORE clock periods
    ADCON2_SHRSAMC_0430 = 0b0110101100, // Sampling time of 430 TADCORE clock periods
    ADCON2_SHRSAMC_0431 = 0b0110101101, // Sampling time of 431 TADCORE clock periods
    ADCON2_SHRSAMC_0432 = 0b0110101110, // Sampling time of 432 TADCORE clock periods
    ADCON2_SHRSAMC_0433 = 0b0110101111, // Sampling time of 433 TADCORE clock periods
    ADCON2_SHRSAMC_0434 = 0b0110110000, // Sampling time of 434 TADCORE clock periods
    ADCON2_SHRSAMC_0435 = 0b0110110001, // Sampling time of 435 TADCORE clock periods
    ADCON2_SHRSAMC_0436 = 0b0110110010, // Sampling time of 436 TADCORE clock periods
    ADCON2_SHRSAMC_0437 = 0b0110110011, // Sampling time of 437 TADCORE clock periods
    ADCON2_SHRSAMC_0438 = 0b0110110100, // Sampling time of 438 TADCORE clock periods
    ADCON2_SHRSAMC_0439 = 0b0110110101, // Sampling time of 439 TADCORE clock periods
    ADCON2_SHRSAMC_0440 = 0b0110110110, // Sampling time of 440 TADCORE clock periods
    ADCON2_SHRSAMC_0441 = 0b0110110111, // Sampling time of 441 TADCORE clock periods
    ADCON2_SHRSAMC_0442 = 0b0110111000, // Sampling time of 442 TADCORE clock periods
    ADCON2_SHRSAMC_0443 = 0b0110111001, // Sampling time of 443 TADCORE clock periods
    ADCON2_SHRSAMC_0444 = 0b0110111010, // Sampling time of 444 TADCORE clock periods
    ADCON2_SHRSAMC_0445 = 0b0110111011, // Sampling time of 445 TADCORE clock periods
    ADCON2_SHRSAMC_0446 = 0b0110111100, // Sampling time of 446 TADCORE clock periods
    ADCON2_SHRSAMC_0447 = 0b0110111101, // Sampling time of 447 TADCORE clock periods
    ADCON2_SHRSAMC_0448 = 0b0110111110, // Sampling time of 448 TADCORE clock periods
    ADCON2_SHRSAMC_0449 = 0b0110111111, // Sampling time of 449 TADCORE clock periods
    ADCON2_SHRSAMC_0450 = 0b0111000000, // Sampling time of 450 TADCORE clock periods
    ADCON2_SHRSAMC_0451 = 0b0111000001, // Sampling time of 451 TADCORE clock periods
    ADCON2_SHRSAMC_0452 = 0b0111000010, // Sampling time of 452 TADCORE clock periods
    ADCON2_SHRSAMC_0453 = 0b0111000011, // Sampling time of 453 TADCORE clock periods
    ADCON2_SHRSAMC_0454 = 0b0111000100, // Sampling time of 454 TADCORE clock periods
    ADCON2_SHRSAMC_0455 = 0b0111000101, // Sampling time of 455 TADCORE clock periods
    ADCON2_SHRSAMC_0456 = 0b0111000110, // Sampling time of 456 TADCORE clock periods
    ADCON2_SHRSAMC_0457 = 0b0111000111, // Sampling time of 457 TADCORE clock periods
    ADCON2_SHRSAMC_0458 = 0b0111001000, // Sampling time of 458 TADCORE clock periods
    ADCON2_SHRSAMC_0459 = 0b0111001001, // Sampling time of 459 TADCORE clock periods
    ADCON2_SHRSAMC_0460 = 0b0111001010, // Sampling time of 460 TADCORE clock periods
    ADCON2_SHRSAMC_0461 = 0b0111001011, // Sampling time of 461 TADCORE clock periods
    ADCON2_SHRSAMC_0462 = 0b0111001100, // Sampling time of 462 TADCORE clock periods
    ADCON2_SHRSAMC_0463 = 0b0111001101, // Sampling time of 463 TADCORE clock periods
    ADCON2_SHRSAMC_0464 = 0b0111001110, // Sampling time of 464 TADCORE clock periods
    ADCON2_SHRSAMC_0465 = 0b0111001111, // Sampling time of 465 TADCORE clock periods
    ADCON2_SHRSAMC_0466 = 0b0111010000, // Sampling time of 466 TADCORE clock periods
    ADCON2_SHRSAMC_0467 = 0b0111010001, // Sampling time of 467 TADCORE clock periods
    ADCON2_SHRSAMC_0468 = 0b0111010010, // Sampling time of 468 TADCORE clock periods
    ADCON2_SHRSAMC_0469 = 0b0111010011, // Sampling time of 469 TADCORE clock periods
    ADCON2_SHRSAMC_0470 = 0b0111010100, // Sampling time of 470 TADCORE clock periods
    ADCON2_SHRSAMC_0471 = 0b0111010101, // Sampling time of 471 TADCORE clock periods
    ADCON2_SHRSAMC_0472 = 0b0111010110, // Sampling time of 472 TADCORE clock periods
    ADCON2_SHRSAMC_0473 = 0b0111010111, // Sampling time of 473 TADCORE clock periods
    ADCON2_SHRSAMC_0474 = 0b0111011000, // Sampling time of 474 TADCORE clock periods
    ADCON2_SHRSAMC_0475 = 0b0111011001, // Sampling time of 475 TADCORE clock periods
    ADCON2_SHRSAMC_0476 = 0b0111011010, // Sampling time of 476 TADCORE clock periods
    ADCON2_SHRSAMC_0477 = 0b0111011011, // Sampling time of 477 TADCORE clock periods
    ADCON2_SHRSAMC_0478 = 0b0111011100, // Sampling time of 478 TADCORE clock periods
    ADCON2_SHRSAMC_0479 = 0b0111011101, // Sampling time of 479 TADCORE clock periods
    ADCON2_SHRSAMC_0480 = 0b0111011110, // Sampling time of 480 TADCORE clock periods
    ADCON2_SHRSAMC_0481 = 0b0111011111, // Sampling time of 481 TADCORE clock periods
    ADCON2_SHRSAMC_0482 = 0b0111100000, // Sampling time of 482 TADCORE clock periods
    ADCON2_SHRSAMC_0483 = 0b0111100001, // Sampling time of 483 TADCORE clock periods
    ADCON2_SHRSAMC_0484 = 0b0111100010, // Sampling time of 484 TADCORE clock periods
    ADCON2_SHRSAMC_0485 = 0b0111100011, // Sampling time of 485 TADCORE clock periods
    ADCON2_SHRSAMC_0486 = 0b0111100100, // Sampling time of 486 TADCORE clock periods
    ADCON2_SHRSAMC_0487 = 0b0111100101, // Sampling time of 487 TADCORE clock periods
    ADCON2_SHRSAMC_0488 = 0b0111100110, // Sampling time of 488 TADCORE clock periods
    ADCON2_SHRSAMC_0489 = 0b0111100111, // Sampling time of 489 TADCORE clock periods
    ADCON2_SHRSAMC_0490 = 0b0111101000, // Sampling time of 490 TADCORE clock periods
    ADCON2_SHRSAMC_0491 = 0b0111101001, // Sampling time of 491 TADCORE clock periods
    ADCON2_SHRSAMC_0492 = 0b0111101010, // Sampling time of 492 TADCORE clock periods
    ADCON2_SHRSAMC_0493 = 0b0111101011, // Sampling time of 493 TADCORE clock periods
    ADCON2_SHRSAMC_0494 = 0b0111101100, // Sampling time of 494 TADCORE clock periods
    ADCON2_SHRSAMC_0495 = 0b0111101101, // Sampling time of 495 TADCORE clock periods
    ADCON2_SHRSAMC_0496 = 0b0111101110, // Sampling time of 496 TADCORE clock periods
    ADCON2_SHRSAMC_0497 = 0b0111101111, // Sampling time of 497 TADCORE clock periods
    ADCON2_SHRSAMC_0498 = 0b0111110000, // Sampling time of 498 TADCORE clock periods
    ADCON2_SHRSAMC_0499 = 0b0111110001, // Sampling time of 499 TADCORE clock periods
    ADCON2_SHRSAMC_0500 = 0b0111110010, // Sampling time of 500 TADCORE clock periods
    ADCON2_SHRSAMC_0501 = 0b0111110011, // Sampling time of 501 TADCORE clock periods
    ADCON2_SHRSAMC_0502 = 0b0111110100, // Sampling time of 502 TADCORE clock periods
    ADCON2_SHRSAMC_0503 = 0b0111110101, // Sampling time of 503 TADCORE clock periods
    ADCON2_SHRSAMC_0504 = 0b0111110110, // Sampling time of 504 TADCORE clock periods
    ADCON2_SHRSAMC_0505 = 0b0111110111, // Sampling time of 505 TADCORE clock periods
    ADCON2_SHRSAMC_0506 = 0b0111111000, // Sampling time of 506 TADCORE clock periods
    ADCON2_SHRSAMC_0507 = 0b0111111001, // Sampling time of 507 TADCORE clock periods
    ADCON2_SHRSAMC_0508 = 0b0111111010, // Sampling time of 508 TADCORE clock periods
    ADCON2_SHRSAMC_0509 = 0b0111111011, // Sampling time of 509 TADCORE clock periods
    ADCON2_SHRSAMC_0510 = 0b0111111100, // Sampling time of 510 TADCORE clock periods
    ADCON2_SHRSAMC_0511 = 0b0111111101, // Sampling time of 511 TADCORE clock periods
    ADCON2_SHRSAMC_0512 = 0b0111111110, // Sampling time of 512 TADCORE clock periods
    ADCON2_SHRSAMC_0513 = 0b0111111111, // Sampling time of 513 TADCORE clock periods
    ADCON2_SHRSAMC_0514 = 0b1000000000, // Sampling time of 514 TADCORE clock periods
    ADCON2_SHRSAMC_0515 = 0b1000000001, // Sampling time of 515 TADCORE clock periods
    ADCON2_SHRSAMC_0516 = 0b1000000010, // Sampling time of 516 TADCORE clock periods
    ADCON2_SHRSAMC_0517 = 0b1000000011, // Sampling time of 517 TADCORE clock periods
    ADCON2_SHRSAMC_0518 = 0b1000000100, // Sampling time of 518 TADCORE clock periods
    ADCON2_SHRSAMC_0519 = 0b1000000101, // Sampling time of 519 TADCORE clock periods
    ADCON2_SHRSAMC_0520 = 0b1000000110, // Sampling time of 520 TADCORE clock periods
    ADCON2_SHRSAMC_0521 = 0b1000000111, // Sampling time of 521 TADCORE clock periods
    ADCON2_SHRSAMC_0522 = 0b1000001000, // Sampling time of 522 TADCORE clock periods
    ADCON2_SHRSAMC_0523 = 0b1000001001, // Sampling time of 523 TADCORE clock periods
    ADCON2_SHRSAMC_0524 = 0b1000001010, // Sampling time of 524 TADCORE clock periods
    ADCON2_SHRSAMC_0525 = 0b1000001011, // Sampling time of 525 TADCORE clock periods
    ADCON2_SHRSAMC_0526 = 0b1000001100, // Sampling time of 526 TADCORE clock periods
    ADCON2_SHRSAMC_0527 = 0b1000001101, // Sampling time of 527 TADCORE clock periods
    ADCON2_SHRSAMC_0528 = 0b1000001110, // Sampling time of 528 TADCORE clock periods
    ADCON2_SHRSAMC_0529 = 0b1000001111, // Sampling time of 529 TADCORE clock periods
    ADCON2_SHRSAMC_0530 = 0b1000010000, // Sampling time of 530 TADCORE clock periods
    ADCON2_SHRSAMC_0531 = 0b1000010001, // Sampling time of 531 TADCORE clock periods
    ADCON2_SHRSAMC_0532 = 0b1000010010, // Sampling time of 532 TADCORE clock periods
    ADCON2_SHRSAMC_0533 = 0b1000010011, // Sampling time of 533 TADCORE clock periods
    ADCON2_SHRSAMC_0534 = 0b1000010100, // Sampling time of 534 TADCORE clock periods
    ADCON2_SHRSAMC_0535 = 0b1000010101, // Sampling time of 535 TADCORE clock periods
    ADCON2_SHRSAMC_0536 = 0b1000010110, // Sampling time of 536 TADCORE clock periods
    ADCON2_SHRSAMC_0537 = 0b1000010111, // Sampling time of 537 TADCORE clock periods
    ADCON2_SHRSAMC_0538 = 0b1000011000, // Sampling time of 538 TADCORE clock periods
    ADCON2_SHRSAMC_0539 = 0b1000011001, // Sampling time of 539 TADCORE clock periods
    ADCON2_SHRSAMC_0540 = 0b1000011010, // Sampling time of 540 TADCORE clock periods
    ADCON2_SHRSAMC_0541 = 0b1000011011, // Sampling time of 541 TADCORE clock periods
    ADCON2_SHRSAMC_0542 = 0b1000011100, // Sampling time of 542 TADCORE clock periods
    ADCON2_SHRSAMC_0543 = 0b1000011101, // Sampling time of 543 TADCORE clock periods
    ADCON2_SHRSAMC_0544 = 0b1000011110, // Sampling time of 544 TADCORE clock periods
    ADCON2_SHRSAMC_0545 = 0b1000011111, // Sampling time of 545 TADCORE clock periods
    ADCON2_SHRSAMC_0546 = 0b1000100000, // Sampling time of 546 TADCORE clock periods
    ADCON2_SHRSAMC_0547 = 0b1000100001, // Sampling time of 547 TADCORE clock periods
    ADCON2_SHRSAMC_0548 = 0b1000100010, // Sampling time of 548 TADCORE clock periods
    ADCON2_SHRSAMC_0549 = 0b1000100011, // Sampling time of 549 TADCORE clock periods
    ADCON2_SHRSAMC_0550 = 0b1000100100, // Sampling time of 550 TADCORE clock periods
    ADCON2_SHRSAMC_0551 = 0b1000100101, // Sampling time of 551 TADCORE clock periods
    ADCON2_SHRSAMC_0552 = 0b1000100110, // Sampling time of 552 TADCORE clock periods
    ADCON2_SHRSAMC_0553 = 0b1000100111, // Sampling time of 553 TADCORE clock periods
    ADCON2_SHRSAMC_0554 = 0b1000101000, // Sampling time of 554 TADCORE clock periods
    ADCON2_SHRSAMC_0555 = 0b1000101001, // Sampling time of 555 TADCORE clock periods
    ADCON2_SHRSAMC_0556 = 0b1000101010, // Sampling time of 556 TADCORE clock periods
    ADCON2_SHRSAMC_0557 = 0b1000101011, // Sampling time of 557 TADCORE clock periods
    ADCON2_SHRSAMC_0558 = 0b1000101100, // Sampling time of 558 TADCORE clock periods
    ADCON2_SHRSAMC_0559 = 0b1000101101, // Sampling time of 559 TADCORE clock periods
    ADCON2_SHRSAMC_0560 = 0b1000101110, // Sampling time of 560 TADCORE clock periods
    ADCON2_SHRSAMC_0561 = 0b1000101111, // Sampling time of 561 TADCORE clock periods
    ADCON2_SHRSAMC_0562 = 0b1000110000, // Sampling time of 562 TADCORE clock periods
    ADCON2_SHRSAMC_0563 = 0b1000110001, // Sampling time of 563 TADCORE clock periods
    ADCON2_SHRSAMC_0564 = 0b1000110010, // Sampling time of 564 TADCORE clock periods
    ADCON2_SHRSAMC_0565 = 0b1000110011, // Sampling time of 565 TADCORE clock periods
    ADCON2_SHRSAMC_0566 = 0b1000110100, // Sampling time of 566 TADCORE clock periods
    ADCON2_SHRSAMC_0567 = 0b1000110101, // Sampling time of 567 TADCORE clock periods
    ADCON2_SHRSAMC_0568 = 0b1000110110, // Sampling time of 568 TADCORE clock periods
    ADCON2_SHRSAMC_0569 = 0b1000110111, // Sampling time of 569 TADCORE clock periods
    ADCON2_SHRSAMC_0570 = 0b1000111000, // Sampling time of 570 TADCORE clock periods
    ADCON2_SHRSAMC_0571 = 0b1000111001, // Sampling time of 571 TADCORE clock periods
    ADCON2_SHRSAMC_0572 = 0b1000111010, // Sampling time of 572 TADCORE clock periods
    ADCON2_SHRSAMC_0573 = 0b1000111011, // Sampling time of 573 TADCORE clock periods
    ADCON2_SHRSAMC_0574 = 0b1000111100, // Sampling time of 574 TADCORE clock periods
    ADCON2_SHRSAMC_0575 = 0b1000111101, // Sampling time of 575 TADCORE clock periods
    ADCON2_SHRSAMC_0576 = 0b1000111110, // Sampling time of 576 TADCORE clock periods
    ADCON2_SHRSAMC_0577 = 0b1000111111, // Sampling time of 577 TADCORE clock periods
    ADCON2_SHRSAMC_0578 = 0b1001000000, // Sampling time of 578 TADCORE clock periods
    ADCON2_SHRSAMC_0579 = 0b1001000001, // Sampling time of 579 TADCORE clock periods
    ADCON2_SHRSAMC_0580 = 0b1001000010, // Sampling time of 580 TADCORE clock periods
    ADCON2_SHRSAMC_0581 = 0b1001000011, // Sampling time of 581 TADCORE clock periods
    ADCON2_SHRSAMC_0582 = 0b1001000100, // Sampling time of 582 TADCORE clock periods
    ADCON2_SHRSAMC_0583 = 0b1001000101, // Sampling time of 583 TADCORE clock periods
    ADCON2_SHRSAMC_0584 = 0b1001000110, // Sampling time of 584 TADCORE clock periods
    ADCON2_SHRSAMC_0585 = 0b1001000111, // Sampling time of 585 TADCORE clock periods
    ADCON2_SHRSAMC_0586 = 0b1001001000, // Sampling time of 586 TADCORE clock periods
    ADCON2_SHRSAMC_0587 = 0b1001001001, // Sampling time of 587 TADCORE clock periods
    ADCON2_SHRSAMC_0588 = 0b1001001010, // Sampling time of 588 TADCORE clock periods
    ADCON2_SHRSAMC_0589 = 0b1001001011, // Sampling time of 589 TADCORE clock periods
    ADCON2_SHRSAMC_0590 = 0b1001001100, // Sampling time of 590 TADCORE clock periods
    ADCON2_SHRSAMC_0591 = 0b1001001101, // Sampling time of 591 TADCORE clock periods
    ADCON2_SHRSAMC_0592 = 0b1001001110, // Sampling time of 592 TADCORE clock periods
    ADCON2_SHRSAMC_0593 = 0b1001001111, // Sampling time of 593 TADCORE clock periods
    ADCON2_SHRSAMC_0594 = 0b1001010000, // Sampling time of 594 TADCORE clock periods
    ADCON2_SHRSAMC_0595 = 0b1001010001, // Sampling time of 595 TADCORE clock periods
    ADCON2_SHRSAMC_0596 = 0b1001010010, // Sampling time of 596 TADCORE clock periods
    ADCON2_SHRSAMC_0597 = 0b1001010011, // Sampling time of 597 TADCORE clock periods
    ADCON2_SHRSAMC_0598 = 0b1001010100, // Sampling time of 598 TADCORE clock periods
    ADCON2_SHRSAMC_0599 = 0b1001010101, // Sampling time of 599 TADCORE clock periods
    ADCON2_SHRSAMC_0600 = 0b1001010110, // Sampling time of 600 TADCORE clock periods
    ADCON2_SHRSAMC_0601 = 0b1001010111, // Sampling time of 601 TADCORE clock periods
    ADCON2_SHRSAMC_0602 = 0b1001011000, // Sampling time of 602 TADCORE clock periods
    ADCON2_SHRSAMC_0603 = 0b1001011001, // Sampling time of 603 TADCORE clock periods
    ADCON2_SHRSAMC_0604 = 0b1001011010, // Sampling time of 604 TADCORE clock periods
    ADCON2_SHRSAMC_0605 = 0b1001011011, // Sampling time of 605 TADCORE clock periods
    ADCON2_SHRSAMC_0606 = 0b1001011100, // Sampling time of 606 TADCORE clock periods
    ADCON2_SHRSAMC_0607 = 0b1001011101, // Sampling time of 607 TADCORE clock periods
    ADCON2_SHRSAMC_0608 = 0b1001011110, // Sampling time of 608 TADCORE clock periods
    ADCON2_SHRSAMC_0609 = 0b1001011111, // Sampling time of 609 TADCORE clock periods
    ADCON2_SHRSAMC_0610 = 0b1001100000, // Sampling time of 610 TADCORE clock periods
    ADCON2_SHRSAMC_0611 = 0b1001100001, // Sampling time of 611 TADCORE clock periods
    ADCON2_SHRSAMC_0612 = 0b1001100010, // Sampling time of 612 TADCORE clock periods
    ADCON2_SHRSAMC_0613 = 0b1001100011, // Sampling time of 613 TADCORE clock periods
    ADCON2_SHRSAMC_0614 = 0b1001100100, // Sampling time of 614 TADCORE clock periods
    ADCON2_SHRSAMC_0615 = 0b1001100101, // Sampling time of 615 TADCORE clock periods
    ADCON2_SHRSAMC_0616 = 0b1001100110, // Sampling time of 616 TADCORE clock periods
    ADCON2_SHRSAMC_0617 = 0b1001100111, // Sampling time of 617 TADCORE clock periods
    ADCON2_SHRSAMC_0618 = 0b1001101000, // Sampling time of 618 TADCORE clock periods
    ADCON2_SHRSAMC_0619 = 0b1001101001, // Sampling time of 619 TADCORE clock periods
    ADCON2_SHRSAMC_0620 = 0b1001101010, // Sampling time of 620 TADCORE clock periods
    ADCON2_SHRSAMC_0621 = 0b1001101011, // Sampling time of 621 TADCORE clock periods
    ADCON2_SHRSAMC_0622 = 0b1001101100, // Sampling time of 622 TADCORE clock periods
    ADCON2_SHRSAMC_0623 = 0b1001101101, // Sampling time of 623 TADCORE clock periods
    ADCON2_SHRSAMC_0624 = 0b1001101110, // Sampling time of 624 TADCORE clock periods
    ADCON2_SHRSAMC_0625 = 0b1001101111, // Sampling time of 625 TADCORE clock periods
    ADCON2_SHRSAMC_0626 = 0b1001110000, // Sampling time of 626 TADCORE clock periods
    ADCON2_SHRSAMC_0627 = 0b1001110001, // Sampling time of 627 TADCORE clock periods
    ADCON2_SHRSAMC_0628 = 0b1001110010, // Sampling time of 628 TADCORE clock periods
    ADCON2_SHRSAMC_0629 = 0b1001110011, // Sampling time of 629 TADCORE clock periods
    ADCON2_SHRSAMC_0630 = 0b1001110100, // Sampling time of 630 TADCORE clock periods
    ADCON2_SHRSAMC_0631 = 0b1001110101, // Sampling time of 631 TADCORE clock periods
    ADCON2_SHRSAMC_0632 = 0b1001110110, // Sampling time of 632 TADCORE clock periods
    ADCON2_SHRSAMC_0633 = 0b1001110111, // Sampling time of 633 TADCORE clock periods
    ADCON2_SHRSAMC_0634 = 0b1001111000, // Sampling time of 634 TADCORE clock periods
    ADCON2_SHRSAMC_0635 = 0b1001111001, // Sampling time of 635 TADCORE clock periods
    ADCON2_SHRSAMC_0636 = 0b1001111010, // Sampling time of 636 TADCORE clock periods
    ADCON2_SHRSAMC_0637 = 0b1001111011, // Sampling time of 637 TADCORE clock periods
    ADCON2_SHRSAMC_0638 = 0b1001111100, // Sampling time of 638 TADCORE clock periods
    ADCON2_SHRSAMC_0639 = 0b1001111101, // Sampling time of 639 TADCORE clock periods
    ADCON2_SHRSAMC_0640 = 0b1001111110, // Sampling time of 640 TADCORE clock periods
    ADCON2_SHRSAMC_0641 = 0b1001111111, // Sampling time of 641 TADCORE clock periods
    ADCON2_SHRSAMC_0642 = 0b1010000000, // Sampling time of 642 TADCORE clock periods
    ADCON2_SHRSAMC_0643 = 0b1010000001, // Sampling time of 643 TADCORE clock periods
    ADCON2_SHRSAMC_0644 = 0b1010000010, // Sampling time of 644 TADCORE clock periods
    ADCON2_SHRSAMC_0645 = 0b1010000011, // Sampling time of 645 TADCORE clock periods
    ADCON2_SHRSAMC_0646 = 0b1010000100, // Sampling time of 646 TADCORE clock periods
    ADCON2_SHRSAMC_0647 = 0b1010000101, // Sampling time of 647 TADCORE clock periods
    ADCON2_SHRSAMC_0648 = 0b1010000110, // Sampling time of 648 TADCORE clock periods
    ADCON2_SHRSAMC_0649 = 0b1010000111, // Sampling time of 649 TADCORE clock periods
    ADCON2_SHRSAMC_0650 = 0b1010001000, // Sampling time of 650 TADCORE clock periods
    ADCON2_SHRSAMC_0651 = 0b1010001001, // Sampling time of 651 TADCORE clock periods
    ADCON2_SHRSAMC_0652 = 0b1010001010, // Sampling time of 652 TADCORE clock periods
    ADCON2_SHRSAMC_0653 = 0b1010001011, // Sampling time of 653 TADCORE clock periods
    ADCON2_SHRSAMC_0654 = 0b1010001100, // Sampling time of 654 TADCORE clock periods
    ADCON2_SHRSAMC_0655 = 0b1010001101, // Sampling time of 655 TADCORE clock periods
    ADCON2_SHRSAMC_0656 = 0b1010001110, // Sampling time of 656 TADCORE clock periods
    ADCON2_SHRSAMC_0657 = 0b1010001111, // Sampling time of 657 TADCORE clock periods
    ADCON2_SHRSAMC_0658 = 0b1010010000, // Sampling time of 658 TADCORE clock periods
    ADCON2_SHRSAMC_0659 = 0b1010010001, // Sampling time of 659 TADCORE clock periods
    ADCON2_SHRSAMC_0660 = 0b1010010010, // Sampling time of 660 TADCORE clock periods
    ADCON2_SHRSAMC_0661 = 0b1010010011, // Sampling time of 661 TADCORE clock periods
    ADCON2_SHRSAMC_0662 = 0b1010010100, // Sampling time of 662 TADCORE clock periods
    ADCON2_SHRSAMC_0663 = 0b1010010101, // Sampling time of 663 TADCORE clock periods
    ADCON2_SHRSAMC_0664 = 0b1010010110, // Sampling time of 664 TADCORE clock periods
    ADCON2_SHRSAMC_0665 = 0b1010010111, // Sampling time of 665 TADCORE clock periods
    ADCON2_SHRSAMC_0666 = 0b1010011000, // Sampling time of 666 TADCORE clock periods
    ADCON2_SHRSAMC_0667 = 0b1010011001, // Sampling time of 667 TADCORE clock periods
    ADCON2_SHRSAMC_0668 = 0b1010011010, // Sampling time of 668 TADCORE clock periods
    ADCON2_SHRSAMC_0669 = 0b1010011011, // Sampling time of 669 TADCORE clock periods
    ADCON2_SHRSAMC_0670 = 0b1010011100, // Sampling time of 670 TADCORE clock periods
    ADCON2_SHRSAMC_0671 = 0b1010011101, // Sampling time of 671 TADCORE clock periods
    ADCON2_SHRSAMC_0672 = 0b1010011110, // Sampling time of 672 TADCORE clock periods
    ADCON2_SHRSAMC_0673 = 0b1010011111, // Sampling time of 673 TADCORE clock periods
    ADCON2_SHRSAMC_0674 = 0b1010100000, // Sampling time of 674 TADCORE clock periods
    ADCON2_SHRSAMC_0675 = 0b1010100001, // Sampling time of 675 TADCORE clock periods
    ADCON2_SHRSAMC_0676 = 0b1010100010, // Sampling time of 676 TADCORE clock periods
    ADCON2_SHRSAMC_0677 = 0b1010100011, // Sampling time of 677 TADCORE clock periods
    ADCON2_SHRSAMC_0678 = 0b1010100100, // Sampling time of 678 TADCORE clock periods
    ADCON2_SHRSAMC_0679 = 0b1010100101, // Sampling time of 679 TADCORE clock periods
    ADCON2_SHRSAMC_0680 = 0b1010100110, // Sampling time of 680 TADCORE clock periods
    ADCON2_SHRSAMC_0681 = 0b1010100111, // Sampling time of 681 TADCORE clock periods
    ADCON2_SHRSAMC_0682 = 0b1010101000, // Sampling time of 682 TADCORE clock periods
    ADCON2_SHRSAMC_0683 = 0b1010101001, // Sampling time of 683 TADCORE clock periods
    ADCON2_SHRSAMC_0684 = 0b1010101010, // Sampling time of 684 TADCORE clock periods
    ADCON2_SHRSAMC_0685 = 0b1010101011, // Sampling time of 685 TADCORE clock periods
    ADCON2_SHRSAMC_0686 = 0b1010101100, // Sampling time of 686 TADCORE clock periods
    ADCON2_SHRSAMC_0687 = 0b1010101101, // Sampling time of 687 TADCORE clock periods
    ADCON2_SHRSAMC_0688 = 0b1010101110, // Sampling time of 688 TADCORE clock periods
    ADCON2_SHRSAMC_0689 = 0b1010101111, // Sampling time of 689 TADCORE clock periods
    ADCON2_SHRSAMC_0690 = 0b1010110000, // Sampling time of 690 TADCORE clock periods
    ADCON2_SHRSAMC_0691 = 0b1010110001, // Sampling time of 691 TADCORE clock periods
    ADCON2_SHRSAMC_0692 = 0b1010110010, // Sampling time of 692 TADCORE clock periods
    ADCON2_SHRSAMC_0693 = 0b1010110011, // Sampling time of 693 TADCORE clock periods
    ADCON2_SHRSAMC_0694 = 0b1010110100, // Sampling time of 694 TADCORE clock periods
    ADCON2_SHRSAMC_0695 = 0b1010110101, // Sampling time of 695 TADCORE clock periods
    ADCON2_SHRSAMC_0696 = 0b1010110110, // Sampling time of 696 TADCORE clock periods
    ADCON2_SHRSAMC_0697 = 0b1010110111, // Sampling time of 697 TADCORE clock periods
    ADCON2_SHRSAMC_0698 = 0b1010111000, // Sampling time of 698 TADCORE clock periods
    ADCON2_SHRSAMC_0699 = 0b1010111001, // Sampling time of 699 TADCORE clock periods
    ADCON2_SHRSAMC_0700 = 0b1010111010, // Sampling time of 700 TADCORE clock periods
    ADCON2_SHRSAMC_0701 = 0b1010111011, // Sampling time of 701 TADCORE clock periods
    ADCON2_SHRSAMC_0702 = 0b1010111100, // Sampling time of 702 TADCORE clock periods
    ADCON2_SHRSAMC_0703 = 0b1010111101, // Sampling time of 703 TADCORE clock periods
    ADCON2_SHRSAMC_0704 = 0b1010111110, // Sampling time of 704 TADCORE clock periods
    ADCON2_SHRSAMC_0705 = 0b1010111111, // Sampling time of 705 TADCORE clock periods
    ADCON2_SHRSAMC_0706 = 0b1011000000, // Sampling time of 706 TADCORE clock periods
    ADCON2_SHRSAMC_0707 = 0b1011000001, // Sampling time of 707 TADCORE clock periods
    ADCON2_SHRSAMC_0708 = 0b1011000010, // Sampling time of 708 TADCORE clock periods
    ADCON2_SHRSAMC_0709 = 0b1011000011, // Sampling time of 709 TADCORE clock periods
    ADCON2_SHRSAMC_0710 = 0b1011000100, // Sampling time of 710 TADCORE clock periods
    ADCON2_SHRSAMC_0711 = 0b1011000101, // Sampling time of 711 TADCORE clock periods
    ADCON2_SHRSAMC_0712 = 0b1011000110, // Sampling time of 712 TADCORE clock periods
    ADCON2_SHRSAMC_0713 = 0b1011000111, // Sampling time of 713 TADCORE clock periods
    ADCON2_SHRSAMC_0714 = 0b1011001000, // Sampling time of 714 TADCORE clock periods
    ADCON2_SHRSAMC_0715 = 0b1011001001, // Sampling time of 715 TADCORE clock periods
    ADCON2_SHRSAMC_0716 = 0b1011001010, // Sampling time of 716 TADCORE clock periods
    ADCON2_SHRSAMC_0717 = 0b1011001011, // Sampling time of 717 TADCORE clock periods
    ADCON2_SHRSAMC_0718 = 0b1011001100, // Sampling time of 718 TADCORE clock periods
    ADCON2_SHRSAMC_0719 = 0b1011001101, // Sampling time of 719 TADCORE clock periods
    ADCON2_SHRSAMC_0720 = 0b1011001110, // Sampling time of 720 TADCORE clock periods
    ADCON2_SHRSAMC_0721 = 0b1011001111, // Sampling time of 721 TADCORE clock periods
    ADCON2_SHRSAMC_0722 = 0b1011010000, // Sampling time of 722 TADCORE clock periods
    ADCON2_SHRSAMC_0723 = 0b1011010001, // Sampling time of 723 TADCORE clock periods
    ADCON2_SHRSAMC_0724 = 0b1011010010, // Sampling time of 724 TADCORE clock periods
    ADCON2_SHRSAMC_0725 = 0b1011010011, // Sampling time of 725 TADCORE clock periods
    ADCON2_SHRSAMC_0726 = 0b1011010100, // Sampling time of 726 TADCORE clock periods
    ADCON2_SHRSAMC_0727 = 0b1011010101, // Sampling time of 727 TADCORE clock periods
    ADCON2_SHRSAMC_0728 = 0b1011010110, // Sampling time of 728 TADCORE clock periods
    ADCON2_SHRSAMC_0729 = 0b1011010111, // Sampling time of 729 TADCORE clock periods
    ADCON2_SHRSAMC_0730 = 0b1011011000, // Sampling time of 730 TADCORE clock periods
    ADCON2_SHRSAMC_0731 = 0b1011011001, // Sampling time of 731 TADCORE clock periods
    ADCON2_SHRSAMC_0732 = 0b1011011010, // Sampling time of 732 TADCORE clock periods
    ADCON2_SHRSAMC_0733 = 0b1011011011, // Sampling time of 733 TADCORE clock periods
    ADCON2_SHRSAMC_0734 = 0b1011011100, // Sampling time of 734 TADCORE clock periods
    ADCON2_SHRSAMC_0735 = 0b1011011101, // Sampling time of 735 TADCORE clock periods
    ADCON2_SHRSAMC_0736 = 0b1011011110, // Sampling time of 736 TADCORE clock periods
    ADCON2_SHRSAMC_0737 = 0b1011011111, // Sampling time of 737 TADCORE clock periods
    ADCON2_SHRSAMC_0738 = 0b1011100000, // Sampling time of 738 TADCORE clock periods
    ADCON2_SHRSAMC_0739 = 0b1011100001, // Sampling time of 739 TADCORE clock periods
    ADCON2_SHRSAMC_0740 = 0b1011100010, // Sampling time of 740 TADCORE clock periods
    ADCON2_SHRSAMC_0741 = 0b1011100011, // Sampling time of 741 TADCORE clock periods
    ADCON2_SHRSAMC_0742 = 0b1011100100, // Sampling time of 742 TADCORE clock periods
    ADCON2_SHRSAMC_0743 = 0b1011100101, // Sampling time of 743 TADCORE clock periods
    ADCON2_SHRSAMC_0744 = 0b1011100110, // Sampling time of 744 TADCORE clock periods
    ADCON2_SHRSAMC_0745 = 0b1011100111, // Sampling time of 745 TADCORE clock periods
    ADCON2_SHRSAMC_0746 = 0b1011101000, // Sampling time of 746 TADCORE clock periods
    ADCON2_SHRSAMC_0747 = 0b1011101001, // Sampling time of 747 TADCORE clock periods
    ADCON2_SHRSAMC_0748 = 0b1011101010, // Sampling time of 748 TADCORE clock periods
    ADCON2_SHRSAMC_0749 = 0b1011101011, // Sampling time of 749 TADCORE clock periods
    ADCON2_SHRSAMC_0750 = 0b1011101100, // Sampling time of 750 TADCORE clock periods
    ADCON2_SHRSAMC_0751 = 0b1011101101, // Sampling time of 751 TADCORE clock periods
    ADCON2_SHRSAMC_0752 = 0b1011101110, // Sampling time of 752 TADCORE clock periods
    ADCON2_SHRSAMC_0753 = 0b1011101111, // Sampling time of 753 TADCORE clock periods
    ADCON2_SHRSAMC_0754 = 0b1011110000, // Sampling time of 754 TADCORE clock periods
    ADCON2_SHRSAMC_0755 = 0b1011110001, // Sampling time of 755 TADCORE clock periods
    ADCON2_SHRSAMC_0756 = 0b1011110010, // Sampling time of 756 TADCORE clock periods
    ADCON2_SHRSAMC_0757 = 0b1011110011, // Sampling time of 757 TADCORE clock periods
    ADCON2_SHRSAMC_0758 = 0b1011110100, // Sampling time of 758 TADCORE clock periods
    ADCON2_SHRSAMC_0759 = 0b1011110101, // Sampling time of 759 TADCORE clock periods
    ADCON2_SHRSAMC_0760 = 0b1011110110, // Sampling time of 760 TADCORE clock periods
    ADCON2_SHRSAMC_0761 = 0b1011110111, // Sampling time of 761 TADCORE clock periods
    ADCON2_SHRSAMC_0762 = 0b1011111000, // Sampling time of 762 TADCORE clock periods
    ADCON2_SHRSAMC_0763 = 0b1011111001, // Sampling time of 763 TADCORE clock periods
    ADCON2_SHRSAMC_0764 = 0b1011111010, // Sampling time of 764 TADCORE clock periods
    ADCON2_SHRSAMC_0765 = 0b1011111011, // Sampling time of 765 TADCORE clock periods
    ADCON2_SHRSAMC_0766 = 0b1011111100, // Sampling time of 766 TADCORE clock periods
    ADCON2_SHRSAMC_0767 = 0b1011111101, // Sampling time of 767 TADCORE clock periods
    ADCON2_SHRSAMC_0768 = 0b1011111110, // Sampling time of 768 TADCORE clock periods
    ADCON2_SHRSAMC_0769 = 0b1011111111, // Sampling time of 769 TADCORE clock periods
    ADCON2_SHRSAMC_0770 = 0b1100000000, // Sampling time of 770 TADCORE clock periods
    ADCON2_SHRSAMC_0771 = 0b1100000001, // Sampling time of 771 TADCORE clock periods
    ADCON2_SHRSAMC_0772 = 0b1100000010, // Sampling time of 772 TADCORE clock periods
    ADCON2_SHRSAMC_0773 = 0b1100000011, // Sampling time of 773 TADCORE clock periods
    ADCON2_SHRSAMC_0774 = 0b1100000100, // Sampling time of 774 TADCORE clock periods
    ADCON2_SHRSAMC_0775 = 0b1100000101, // Sampling time of 775 TADCORE clock periods
    ADCON2_SHRSAMC_0776 = 0b1100000110, // Sampling time of 776 TADCORE clock periods
    ADCON2_SHRSAMC_0777 = 0b1100000111, // Sampling time of 777 TADCORE clock periods
    ADCON2_SHRSAMC_0778 = 0b1100001000, // Sampling time of 778 TADCORE clock periods
    ADCON2_SHRSAMC_0779 = 0b1100001001, // Sampling time of 779 TADCORE clock periods
    ADCON2_SHRSAMC_0780 = 0b1100001010, // Sampling time of 780 TADCORE clock periods
    ADCON2_SHRSAMC_0781 = 0b1100001011, // Sampling time of 781 TADCORE clock periods
    ADCON2_SHRSAMC_0782 = 0b1100001100, // Sampling time of 782 TADCORE clock periods
    ADCON2_SHRSAMC_0783 = 0b1100001101, // Sampling time of 783 TADCORE clock periods
    ADCON2_SHRSAMC_0784 = 0b1100001110, // Sampling time of 784 TADCORE clock periods
    ADCON2_SHRSAMC_0785 = 0b1100001111, // Sampling time of 785 TADCORE clock periods
    ADCON2_SHRSAMC_0786 = 0b1100010000, // Sampling time of 786 TADCORE clock periods
    ADCON2_SHRSAMC_0787 = 0b1100010001, // Sampling time of 787 TADCORE clock periods
    ADCON2_SHRSAMC_0788 = 0b1100010010, // Sampling time of 788 TADCORE clock periods
    ADCON2_SHRSAMC_0789 = 0b1100010011, // Sampling time of 789 TADCORE clock periods
    ADCON2_SHRSAMC_0790 = 0b1100010100, // Sampling time of 790 TADCORE clock periods
    ADCON2_SHRSAMC_0791 = 0b1100010101, // Sampling time of 791 TADCORE clock periods
    ADCON2_SHRSAMC_0792 = 0b1100010110, // Sampling time of 792 TADCORE clock periods
    ADCON2_SHRSAMC_0793 = 0b1100010111, // Sampling time of 793 TADCORE clock periods
    ADCON2_SHRSAMC_0794 = 0b1100011000, // Sampling time of 794 TADCORE clock periods
    ADCON2_SHRSAMC_0795 = 0b1100011001, // Sampling time of 795 TADCORE clock periods
    ADCON2_SHRSAMC_0796 = 0b1100011010, // Sampling time of 796 TADCORE clock periods
    ADCON2_SHRSAMC_0797 = 0b1100011011, // Sampling time of 797 TADCORE clock periods
    ADCON2_SHRSAMC_0798 = 0b1100011100, // Sampling time of 798 TADCORE clock periods
    ADCON2_SHRSAMC_0799 = 0b1100011101, // Sampling time of 799 TADCORE clock periods
    ADCON2_SHRSAMC_0800 = 0b1100011110, // Sampling time of 800 TADCORE clock periods
    ADCON2_SHRSAMC_0801 = 0b1100011111, // Sampling time of 801 TADCORE clock periods
    ADCON2_SHRSAMC_0802 = 0b1100100000, // Sampling time of 802 TADCORE clock periods
    ADCON2_SHRSAMC_0803 = 0b1100100001, // Sampling time of 803 TADCORE clock periods
    ADCON2_SHRSAMC_0804 = 0b1100100010, // Sampling time of 804 TADCORE clock periods
    ADCON2_SHRSAMC_0805 = 0b1100100011, // Sampling time of 805 TADCORE clock periods
    ADCON2_SHRSAMC_0806 = 0b1100100100, // Sampling time of 806 TADCORE clock periods
    ADCON2_SHRSAMC_0807 = 0b1100100101, // Sampling time of 807 TADCORE clock periods
    ADCON2_SHRSAMC_0808 = 0b1100100110, // Sampling time of 808 TADCORE clock periods
    ADCON2_SHRSAMC_0809 = 0b1100100111, // Sampling time of 809 TADCORE clock periods
    ADCON2_SHRSAMC_0810 = 0b1100101000, // Sampling time of 810 TADCORE clock periods
    ADCON2_SHRSAMC_0811 = 0b1100101001, // Sampling time of 811 TADCORE clock periods
    ADCON2_SHRSAMC_0812 = 0b1100101010, // Sampling time of 812 TADCORE clock periods
    ADCON2_SHRSAMC_0813 = 0b1100101011, // Sampling time of 813 TADCORE clock periods
    ADCON2_SHRSAMC_0814 = 0b1100101100, // Sampling time of 814 TADCORE clock periods
    ADCON2_SHRSAMC_0815 = 0b1100101101, // Sampling time of 815 TADCORE clock periods
    ADCON2_SHRSAMC_0816 = 0b1100101110, // Sampling time of 816 TADCORE clock periods
    ADCON2_SHRSAMC_0817 = 0b1100101111, // Sampling time of 817 TADCORE clock periods
    ADCON2_SHRSAMC_0818 = 0b1100110000, // Sampling time of 818 TADCORE clock periods
    ADCON2_SHRSAMC_0819 = 0b1100110001, // Sampling time of 819 TADCORE clock periods
    ADCON2_SHRSAMC_0820 = 0b1100110010, // Sampling time of 820 TADCORE clock periods
    ADCON2_SHRSAMC_0821 = 0b1100110011, // Sampling time of 821 TADCORE clock periods
    ADCON2_SHRSAMC_0822 = 0b1100110100, // Sampling time of 822 TADCORE clock periods
    ADCON2_SHRSAMC_0823 = 0b1100110101, // Sampling time of 823 TADCORE clock periods
    ADCON2_SHRSAMC_0824 = 0b1100110110, // Sampling time of 824 TADCORE clock periods
    ADCON2_SHRSAMC_0825 = 0b1100110111, // Sampling time of 825 TADCORE clock periods
    ADCON2_SHRSAMC_0826 = 0b1100111000, // Sampling time of 826 TADCORE clock periods
    ADCON2_SHRSAMC_0827 = 0b1100111001, // Sampling time of 827 TADCORE clock periods
    ADCON2_SHRSAMC_0828 = 0b1100111010, // Sampling time of 828 TADCORE clock periods
    ADCON2_SHRSAMC_0829 = 0b1100111011, // Sampling time of 829 TADCORE clock periods
    ADCON2_SHRSAMC_0830 = 0b1100111100, // Sampling time of 830 TADCORE clock periods
    ADCON2_SHRSAMC_0831 = 0b1100111101, // Sampling time of 831 TADCORE clock periods
    ADCON2_SHRSAMC_0832 = 0b1100111110, // Sampling time of 832 TADCORE clock periods
    ADCON2_SHRSAMC_0833 = 0b1100111111, // Sampling time of 833 TADCORE clock periods
    ADCON2_SHRSAMC_0834 = 0b1101000000, // Sampling time of 834 TADCORE clock periods
    ADCON2_SHRSAMC_0835 = 0b1101000001, // Sampling time of 835 TADCORE clock periods
    ADCON2_SHRSAMC_0836 = 0b1101000010, // Sampling time of 836 TADCORE clock periods
    ADCON2_SHRSAMC_0837 = 0b1101000011, // Sampling time of 837 TADCORE clock periods
    ADCON2_SHRSAMC_0838 = 0b1101000100, // Sampling time of 838 TADCORE clock periods
    ADCON2_SHRSAMC_0839 = 0b1101000101, // Sampling time of 839 TADCORE clock periods
    ADCON2_SHRSAMC_0840 = 0b1101000110, // Sampling time of 840 TADCORE clock periods
    ADCON2_SHRSAMC_0841 = 0b1101000111, // Sampling time of 841 TADCORE clock periods
    ADCON2_SHRSAMC_0842 = 0b1101001000, // Sampling time of 842 TADCORE clock periods
    ADCON2_SHRSAMC_0843 = 0b1101001001, // Sampling time of 843 TADCORE clock periods
    ADCON2_SHRSAMC_0844 = 0b1101001010, // Sampling time of 844 TADCORE clock periods
    ADCON2_SHRSAMC_0845 = 0b1101001011, // Sampling time of 845 TADCORE clock periods
    ADCON2_SHRSAMC_0846 = 0b1101001100, // Sampling time of 846 TADCORE clock periods
    ADCON2_SHRSAMC_0847 = 0b1101001101, // Sampling time of 847 TADCORE clock periods
    ADCON2_SHRSAMC_0848 = 0b1101001110, // Sampling time of 848 TADCORE clock periods
    ADCON2_SHRSAMC_0849 = 0b1101001111, // Sampling time of 849 TADCORE clock periods
    ADCON2_SHRSAMC_0850 = 0b1101010000, // Sampling time of 850 TADCORE clock periods
    ADCON2_SHRSAMC_0851 = 0b1101010001, // Sampling time of 851 TADCORE clock periods
    ADCON2_SHRSAMC_0852 = 0b1101010010, // Sampling time of 852 TADCORE clock periods
    ADCON2_SHRSAMC_0853 = 0b1101010011, // Sampling time of 853 TADCORE clock periods
    ADCON2_SHRSAMC_0854 = 0b1101010100, // Sampling time of 854 TADCORE clock periods
    ADCON2_SHRSAMC_0855 = 0b1101010101, // Sampling time of 855 TADCORE clock periods
    ADCON2_SHRSAMC_0856 = 0b1101010110, // Sampling time of 856 TADCORE clock periods
    ADCON2_SHRSAMC_0857 = 0b1101010111, // Sampling time of 857 TADCORE clock periods
    ADCON2_SHRSAMC_0858 = 0b1101011000, // Sampling time of 858 TADCORE clock periods
    ADCON2_SHRSAMC_0859 = 0b1101011001, // Sampling time of 859 TADCORE clock periods
    ADCON2_SHRSAMC_0860 = 0b1101011010, // Sampling time of 860 TADCORE clock periods
    ADCON2_SHRSAMC_0861 = 0b1101011011, // Sampling time of 861 TADCORE clock periods
    ADCON2_SHRSAMC_0862 = 0b1101011100, // Sampling time of 862 TADCORE clock periods
    ADCON2_SHRSAMC_0863 = 0b1101011101, // Sampling time of 863 TADCORE clock periods
    ADCON2_SHRSAMC_0864 = 0b1101011110, // Sampling time of 864 TADCORE clock periods
    ADCON2_SHRSAMC_0865 = 0b1101011111, // Sampling time of 865 TADCORE clock periods
    ADCON2_SHRSAMC_0866 = 0b1101100000, // Sampling time of 866 TADCORE clock periods
    ADCON2_SHRSAMC_0867 = 0b1101100001, // Sampling time of 867 TADCORE clock periods
    ADCON2_SHRSAMC_0868 = 0b1101100010, // Sampling time of 868 TADCORE clock periods
    ADCON2_SHRSAMC_0869 = 0b1101100011, // Sampling time of 869 TADCORE clock periods
    ADCON2_SHRSAMC_0870 = 0b1101100100, // Sampling time of 870 TADCORE clock periods
    ADCON2_SHRSAMC_0871 = 0b1101100101, // Sampling time of 871 TADCORE clock periods
    ADCON2_SHRSAMC_0872 = 0b1101100110, // Sampling time of 872 TADCORE clock periods
    ADCON2_SHRSAMC_0873 = 0b1101100111, // Sampling time of 873 TADCORE clock periods
    ADCON2_SHRSAMC_0874 = 0b1101101000, // Sampling time of 874 TADCORE clock periods
    ADCON2_SHRSAMC_0875 = 0b1101101001, // Sampling time of 875 TADCORE clock periods
    ADCON2_SHRSAMC_0876 = 0b1101101010, // Sampling time of 876 TADCORE clock periods
    ADCON2_SHRSAMC_0877 = 0b1101101011, // Sampling time of 877 TADCORE clock periods
    ADCON2_SHRSAMC_0878 = 0b1101101100, // Sampling time of 878 TADCORE clock periods
    ADCON2_SHRSAMC_0879 = 0b1101101101, // Sampling time of 879 TADCORE clock periods
    ADCON2_SHRSAMC_0880 = 0b1101101110, // Sampling time of 880 TADCORE clock periods
    ADCON2_SHRSAMC_0881 = 0b1101101111, // Sampling time of 881 TADCORE clock periods
    ADCON2_SHRSAMC_0882 = 0b1101110000, // Sampling time of 882 TADCORE clock periods
    ADCON2_SHRSAMC_0883 = 0b1101110001, // Sampling time of 883 TADCORE clock periods
    ADCON2_SHRSAMC_0884 = 0b1101110010, // Sampling time of 884 TADCORE clock periods
    ADCON2_SHRSAMC_0885 = 0b1101110011, // Sampling time of 885 TADCORE clock periods
    ADCON2_SHRSAMC_0886 = 0b1101110100, // Sampling time of 886 TADCORE clock periods
    ADCON2_SHRSAMC_0887 = 0b1101110101, // Sampling time of 887 TADCORE clock periods
    ADCON2_SHRSAMC_0888 = 0b1101110110, // Sampling time of 888 TADCORE clock periods
    ADCON2_SHRSAMC_0889 = 0b1101110111, // Sampling time of 889 TADCORE clock periods
    ADCON2_SHRSAMC_0890 = 0b1101111000, // Sampling time of 890 TADCORE clock periods
    ADCON2_SHRSAMC_0891 = 0b1101111001, // Sampling time of 891 TADCORE clock periods
    ADCON2_SHRSAMC_0892 = 0b1101111010, // Sampling time of 892 TADCORE clock periods
    ADCON2_SHRSAMC_0893 = 0b1101111011, // Sampling time of 893 TADCORE clock periods
    ADCON2_SHRSAMC_0894 = 0b1101111100, // Sampling time of 894 TADCORE clock periods
    ADCON2_SHRSAMC_0895 = 0b1101111101, // Sampling time of 895 TADCORE clock periods
    ADCON2_SHRSAMC_0896 = 0b1101111110, // Sampling time of 896 TADCORE clock periods
    ADCON2_SHRSAMC_0897 = 0b1101111111, // Sampling time of 897 TADCORE clock periods
    ADCON2_SHRSAMC_0898 = 0b1110000000, // Sampling time of 898 TADCORE clock periods
    ADCON2_SHRSAMC_0899 = 0b1110000001, // Sampling time of 899 TADCORE clock periods
    ADCON2_SHRSAMC_0900 = 0b1110000010, // Sampling time of 900 TADCORE clock periods
    ADCON2_SHRSAMC_0901 = 0b1110000011, // Sampling time of 901 TADCORE clock periods
    ADCON2_SHRSAMC_0902 = 0b1110000100, // Sampling time of 902 TADCORE clock periods
    ADCON2_SHRSAMC_0903 = 0b1110000101, // Sampling time of 903 TADCORE clock periods
    ADCON2_SHRSAMC_0904 = 0b1110000110, // Sampling time of 904 TADCORE clock periods
    ADCON2_SHRSAMC_0905 = 0b1110000111, // Sampling time of 905 TADCORE clock periods
    ADCON2_SHRSAMC_0906 = 0b1110001000, // Sampling time of 906 TADCORE clock periods
    ADCON2_SHRSAMC_0907 = 0b1110001001, // Sampling time of 907 TADCORE clock periods
    ADCON2_SHRSAMC_0908 = 0b1110001010, // Sampling time of 908 TADCORE clock periods
    ADCON2_SHRSAMC_0909 = 0b1110001011, // Sampling time of 909 TADCORE clock periods
    ADCON2_SHRSAMC_0910 = 0b1110001100, // Sampling time of 910 TADCORE clock periods
    ADCON2_SHRSAMC_0911 = 0b1110001101, // Sampling time of 911 TADCORE clock periods
    ADCON2_SHRSAMC_0912 = 0b1110001110, // Sampling time of 912 TADCORE clock periods
    ADCON2_SHRSAMC_0913 = 0b1110001111, // Sampling time of 913 TADCORE clock periods
    ADCON2_SHRSAMC_0914 = 0b1110010000, // Sampling time of 914 TADCORE clock periods
    ADCON2_SHRSAMC_0915 = 0b1110010001, // Sampling time of 915 TADCORE clock periods
    ADCON2_SHRSAMC_0916 = 0b1110010010, // Sampling time of 916 TADCORE clock periods
    ADCON2_SHRSAMC_0917 = 0b1110010011, // Sampling time of 917 TADCORE clock periods
    ADCON2_SHRSAMC_0918 = 0b1110010100, // Sampling time of 918 TADCORE clock periods
    ADCON2_SHRSAMC_0919 = 0b1110010101, // Sampling time of 919 TADCORE clock periods
    ADCON2_SHRSAMC_0920 = 0b1110010110, // Sampling time of 920 TADCORE clock periods
    ADCON2_SHRSAMC_0921 = 0b1110010111, // Sampling time of 921 TADCORE clock periods
    ADCON2_SHRSAMC_0922 = 0b1110011000, // Sampling time of 922 TADCORE clock periods
    ADCON2_SHRSAMC_0923 = 0b1110011001, // Sampling time of 923 TADCORE clock periods
    ADCON2_SHRSAMC_0924 = 0b1110011010, // Sampling time of 924 TADCORE clock periods
    ADCON2_SHRSAMC_0925 = 0b1110011011, // Sampling time of 925 TADCORE clock periods
    ADCON2_SHRSAMC_0926 = 0b1110011100, // Sampling time of 926 TADCORE clock periods
    ADCON2_SHRSAMC_0927 = 0b1110011101, // Sampling time of 927 TADCORE clock periods
    ADCON2_SHRSAMC_0928 = 0b1110011110, // Sampling time of 928 TADCORE clock periods
    ADCON2_SHRSAMC_0929 = 0b1110011111, // Sampling time of 929 TADCORE clock periods
    ADCON2_SHRSAMC_0930 = 0b1110100000, // Sampling time of 930 TADCORE clock periods
    ADCON2_SHRSAMC_0931 = 0b1110100001, // Sampling time of 931 TADCORE clock periods
    ADCON2_SHRSAMC_0932 = 0b1110100010, // Sampling time of 932 TADCORE clock periods
    ADCON2_SHRSAMC_0933 = 0b1110100011, // Sampling time of 933 TADCORE clock periods
    ADCON2_SHRSAMC_0934 = 0b1110100100, // Sampling time of 934 TADCORE clock periods
    ADCON2_SHRSAMC_0935 = 0b1110100101, // Sampling time of 935 TADCORE clock periods
    ADCON2_SHRSAMC_0936 = 0b1110100110, // Sampling time of 936 TADCORE clock periods
    ADCON2_SHRSAMC_0937 = 0b1110100111, // Sampling time of 937 TADCORE clock periods
    ADCON2_SHRSAMC_0938 = 0b1110101000, // Sampling time of 938 TADCORE clock periods
    ADCON2_SHRSAMC_0939 = 0b1110101001, // Sampling time of 939 TADCORE clock periods
    ADCON2_SHRSAMC_0940 = 0b1110101010, // Sampling time of 940 TADCORE clock periods
    ADCON2_SHRSAMC_0941 = 0b1110101011, // Sampling time of 941 TADCORE clock periods
    ADCON2_SHRSAMC_0942 = 0b1110101100, // Sampling time of 942 TADCORE clock periods
    ADCON2_SHRSAMC_0943 = 0b1110101101, // Sampling time of 943 TADCORE clock periods
    ADCON2_SHRSAMC_0944 = 0b1110101110, // Sampling time of 944 TADCORE clock periods
    ADCON2_SHRSAMC_0945 = 0b1110101111, // Sampling time of 945 TADCORE clock periods
    ADCON2_SHRSAMC_0946 = 0b1110110000, // Sampling time of 946 TADCORE clock periods
    ADCON2_SHRSAMC_0947 = 0b1110110001, // Sampling time of 947 TADCORE clock periods
    ADCON2_SHRSAMC_0948 = 0b1110110010, // Sampling time of 948 TADCORE clock periods
    ADCON2_SHRSAMC_0949 = 0b1110110011, // Sampling time of 949 TADCORE clock periods
    ADCON2_SHRSAMC_0950 = 0b1110110100, // Sampling time of 950 TADCORE clock periods
    ADCON2_SHRSAMC_0951 = 0b1110110101, // Sampling time of 951 TADCORE clock periods
    ADCON2_SHRSAMC_0952 = 0b1110110110, // Sampling time of 952 TADCORE clock periods
    ADCON2_SHRSAMC_0953 = 0b1110110111, // Sampling time of 953 TADCORE clock periods
    ADCON2_SHRSAMC_0954 = 0b1110111000, // Sampling time of 954 TADCORE clock periods
    ADCON2_SHRSAMC_0955 = 0b1110111001, // Sampling time of 955 TADCORE clock periods
    ADCON2_SHRSAMC_0956 = 0b1110111010, // Sampling time of 956 TADCORE clock periods
    ADCON2_SHRSAMC_0957 = 0b1110111011, // Sampling time of 957 TADCORE clock periods
    ADCON2_SHRSAMC_0958 = 0b1110111100, // Sampling time of 958 TADCORE clock periods
    ADCON2_SHRSAMC_0959 = 0b1110111101, // Sampling time of 959 TADCORE clock periods
    ADCON2_SHRSAMC_0960 = 0b1110111110, // Sampling time of 960 TADCORE clock periods
    ADCON2_SHRSAMC_0961 = 0b1110111111, // Sampling time of 961 TADCORE clock periods
    ADCON2_SHRSAMC_0962 = 0b1111000000, // Sampling time of 962 TADCORE clock periods
    ADCON2_SHRSAMC_0963 = 0b1111000001, // Sampling time of 963 TADCORE clock periods
    ADCON2_SHRSAMC_0964 = 0b1111000010, // Sampling time of 964 TADCORE clock periods
    ADCON2_SHRSAMC_0965 = 0b1111000011, // Sampling time of 965 TADCORE clock periods
    ADCON2_SHRSAMC_0966 = 0b1111000100, // Sampling time of 966 TADCORE clock periods
    ADCON2_SHRSAMC_0967 = 0b1111000101, // Sampling time of 967 TADCORE clock periods
    ADCON2_SHRSAMC_0968 = 0b1111000110, // Sampling time of 968 TADCORE clock periods
    ADCON2_SHRSAMC_0969 = 0b1111000111, // Sampling time of 969 TADCORE clock periods
    ADCON2_SHRSAMC_0970 = 0b1111001000, // Sampling time of 970 TADCORE clock periods
    ADCON2_SHRSAMC_0971 = 0b1111001001, // Sampling time of 971 TADCORE clock periods
    ADCON2_SHRSAMC_0972 = 0b1111001010, // Sampling time of 972 TADCORE clock periods
    ADCON2_SHRSAMC_0973 = 0b1111001011, // Sampling time of 973 TADCORE clock periods
    ADCON2_SHRSAMC_0974 = 0b1111001100, // Sampling time of 974 TADCORE clock periods
    ADCON2_SHRSAMC_0975 = 0b1111001101, // Sampling time of 975 TADCORE clock periods
    ADCON2_SHRSAMC_0976 = 0b1111001110, // Sampling time of 976 TADCORE clock periods
    ADCON2_SHRSAMC_0977 = 0b1111001111, // Sampling time of 977 TADCORE clock periods
    ADCON2_SHRSAMC_0978 = 0b1111010000, // Sampling time of 978 TADCORE clock periods
    ADCON2_SHRSAMC_0979 = 0b1111010001, // Sampling time of 979 TADCORE clock periods
    ADCON2_SHRSAMC_0980 = 0b1111010010, // Sampling time of 980 TADCORE clock periods
    ADCON2_SHRSAMC_0981 = 0b1111010011, // Sampling time of 981 TADCORE clock periods
    ADCON2_SHRSAMC_0982 = 0b1111010100, // Sampling time of 982 TADCORE clock periods
    ADCON2_SHRSAMC_0983 = 0b1111010101, // Sampling time of 983 TADCORE clock periods
    ADCON2_SHRSAMC_0984 = 0b1111010110, // Sampling time of 984 TADCORE clock periods
    ADCON2_SHRSAMC_0985 = 0b1111010111, // Sampling time of 985 TADCORE clock periods
    ADCON2_SHRSAMC_0986 = 0b1111011000, // Sampling time of 986 TADCORE clock periods
    ADCON2_SHRSAMC_0987 = 0b1111011001, // Sampling time of 987 TADCORE clock periods
    ADCON2_SHRSAMC_0988 = 0b1111011010, // Sampling time of 988 TADCORE clock periods
    ADCON2_SHRSAMC_0989 = 0b1111011011, // Sampling time of 989 TADCORE clock periods
    ADCON2_SHRSAMC_0990 = 0b1111011100, // Sampling time of 990 TADCORE clock periods
    ADCON2_SHRSAMC_0991 = 0b1111011101, // Sampling time of 991 TADCORE clock periods
    ADCON2_SHRSAMC_0992 = 0b1111011110, // Sampling time of 992 TADCORE clock periods
    ADCON2_SHRSAMC_0993 = 0b1111011111, // Sampling time of 993 TADCORE clock periods
    ADCON2_SHRSAMC_0994 = 0b1111100000, // Sampling time of 994 TADCORE clock periods
    ADCON2_SHRSAMC_0995 = 0b1111100001, // Sampling time of 995 TADCORE clock periods
    ADCON2_SHRSAMC_0996 = 0b1111100010, // Sampling time of 996 TADCORE clock periods
    ADCON2_SHRSAMC_0997 = 0b1111100011, // Sampling time of 997 TADCORE clock periods
    ADCON2_SHRSAMC_0998 = 0b1111100100, // Sampling time of 998 TADCORE clock periods
    ADCON2_SHRSAMC_0999 = 0b1111100101, // Sampling time of 999 TADCORE clock periods
    ADCON2_SHRSAMC_1000 = 0b1111100110, // Sampling time of 1000 TADCORE clock periods
    ADCON2_SHRSAMC_1001 = 0b1111100111, // Sampling time of 1001 TADCORE clock periods
    ADCON2_SHRSAMC_1002 = 0b1111101000, // Sampling time of 1002 TADCORE clock periods
    ADCON2_SHRSAMC_1003 = 0b1111101001, // Sampling time of 1003 TADCORE clock periods
    ADCON2_SHRSAMC_1004 = 0b1111101010, // Sampling time of 1004 TADCORE clock periods
    ADCON2_SHRSAMC_1005 = 0b1111101011, // Sampling time of 1005 TADCORE clock periods
    ADCON2_SHRSAMC_1006 = 0b1111101100, // Sampling time of 1006 TADCORE clock periods
    ADCON2_SHRSAMC_1007 = 0b1111101101, // Sampling time of 1007 TADCORE clock periods
    ADCON2_SHRSAMC_1008 = 0b1111101110, // Sampling time of 1008 TADCORE clock periods
    ADCON2_SHRSAMC_1009 = 0b1111101111, // Sampling time of 1009 TADCORE clock periods
    ADCON2_SHRSAMC_1010 = 0b1111110000, // Sampling time of 1010 TADCORE clock periods
    ADCON2_SHRSAMC_1011 = 0b1111110001, // Sampling time of 1011 TADCORE clock periods
    ADCON2_SHRSAMC_1012 = 0b1111110010, // Sampling time of 1012 TADCORE clock periods
    ADCON2_SHRSAMC_1013 = 0b1111110011, // Sampling time of 1013 TADCORE clock periods
    ADCON2_SHRSAMC_1014 = 0b1111110100, // Sampling time of 1014 TADCORE clock periods
    ADCON2_SHRSAMC_1015 = 0b1111110101, // Sampling time of 1015 TADCORE clock periods
    ADCON2_SHRSAMC_1016 = 0b1111110110, // Sampling time of 1016 TADCORE clock periods
    ADCON2_SHRSAMC_1017 = 0b1111110111, // Sampling time of 1017 TADCORE clock periods
    ADCON2_SHRSAMC_1018 = 0b1111111000, // Sampling time of 1018 TADCORE clock periods
    ADCON2_SHRSAMC_1019 = 0b1111111001, // Sampling time of 1019 TADCORE clock periods
    ADCON2_SHRSAMC_1020 = 0b1111111010, // Sampling time of 1020 TADCORE clock periods
    ADCON2_SHRSAMC_1021 = 0b1111111011, // Sampling time of 1021 TADCORE clock periods
    ADCON2_SHRSAMC_1022 = 0b1111111100, // Sampling time of 1022 TADCORE clock periods
    ADCON2_SHRSAMC_1023 = 0b1111111101, // Sampling time of 1023 TADCORE clock periods
    ADCON2_SHRSAMC_1024 = 0b1111111110, // Sampling time of 1024 TADCORE clock periods
    ADCON2_SHRSAMC_1025 = 0b1111111111 // Sampling time of 1025 TADCORE clock periods
} ADCON2_SHRSAMC_e; // Shared ADC Core Sample Time Selection bits

typedef struct {
    volatile ADCON2_SHRADCS_e SHRADCS : 7; // Shared ADC Core Input Clock Divider
    volatile unsigned : 1;
    volatile ADCON2_SHREISEL_e SHREISEL : 3; // Shared Core Early Interrupt Time Selection
    volatile unsigned : 1;
    volatile ADCON2_EIEN_e EIEN : 1; // Early Interrupts Enable
    volatile unsigned : 1;
    volatile ADCON2_REFERCIE_e REFERCIE : 1; // Band Gap or Reference Voltage Error Common Interrupt Enable
    volatile ADCON2_REFCIE_e REFCIE : 1; // Band Gap and Reference Voltage Ready Common Interrupt Enable

    volatile ADCON2_SHRSAMC_e SHRSAMC : 10; // Shared ADC Core Sample Time Selection bits
    volatile unsigned : 4;
    volatile ADCON2_REFERR_e REFERR : 1; // Band Gap or Reference Voltage Error Flag bit
    volatile ADCON2_REFRDY_e REFRDY : 1; // Band Gap Reference status

} __attribute__((packed)) ADCON2_t; // ADCON2L: ADC CONTROL REGISTER 2 LOW

typedef union {
    volatile uint32_t value;
    volatile ADCON2_t ADCON2;
} REGBLK_ADCON2_t;

// REGISTERS ADCON3L/H: ANALOG-TO-DIGITAL CONTROL REGISTER 3 LOW/HIGH

// the least significant bits of the valid data mask cover the enable bits of dedicated ADC cores
// As the number of ADC cores differ, tailored bit masks are required
#define REG_ADCON3_VALID_DATA_WRITE_MASK  ((0xFF80FABF) | (uint32_t)(ADCDORE_REGISTER_BIT_MASK << 16))
#define REG_ADCON3_VALID_DATA_READ_MASK   ((0xFF80FABF) | (uint32_t)(ADCDORE_REGISTER_BIT_MASK << 16))

#define REG_ADCON3L_RESET                 0b0000010101000000 // Reset ADCON 3 Low Register
#define REG_ADCON3L_VALID_DATA_WRITE_MASK 0b1111101010111111 // Bit mask used to set unimplemented bits to zero
#define REG_ADCON3L_VALID_DATA_READ_MASK  0b1111111111111111 // Bit mask used to set unimplemented bits to zero

#define REG_ADCON3H_RESET                0b1100000000000000      // Reset ADCON 3 High Register
#define REG_ADCON3H_VALID_DATA_WRITE_MSK (0xFF80 | (uint16_t)ADCDORE_REGISTER_BIT_MASK)	// Bit mask used to set unimplemented bits to zero
#define REG_ADCON3H_VALID_DATA_READ_MSK  (0xFF80 | (uint16_t)ADCDORE_REGISTER_BIT_MASK)	// Bit mask used to set unimplemented bits to zero

#define REG_ADCON3L_REFSEL_AVDD_AVSS    0b0000000000000000      // Vref = AVDD to AVSS

typedef enum {
    ADCON3_REFSEL_AVDD_AVSS = 0b000 // VDD to VSS is ADC reference voltage source
} ADCON3_REFSEL_e; // ADC Reference Voltage Selection

#define REG_ADCON3L_SUSPEND_ON          0b0001000000000000      // All ADC triggers are disabled
#define REG_ADCON3L_SUSPEND_OFF         0b0000000000000000      // All ADC triggers are enabled

typedef enum {
    ADCON3_SUSPEND_HOLD = 0b1, // All new trigger events for all ADC cores are disabled 
    ADCON3_SUSPEND_RUN = 0b0 // All ADC cores can be triggered 
} ADCON3_SUSPEND_e; // All ADC Core Triggers Disable

#define REG_ADCON3L_SUSPCIE_ON          0b0000100000000000      // Suspend Interrupt Enabled
#define REG_ADCON3L_SUSPCIE_OFF         0b0000000000000000      // Suspend Interrupt Disabled

typedef enum {
    ADCON3_SUSPCIE_ENABLED = 0b1, // Common interrupt will be generated when ADC core triggers are suspended (SUSPEND bit = 1) and all previous conversions are finished (SUSPRDY bit becomes set)
    ADCON3_SUSPCIE_DISABLED = 0b0 // Common interrupt is not generated for suspend ADC cores event
} ADCON3_SUSPCIE_e; // Suspend All ADC Cores Common Interrupt Enable

#define REG_ADCON3L_SUSPRDY_ON          0b0000010000000000      // READ ONLY: Suspend Status ON
#define REG_ADCON3L_SUSPRDY_OFF         0b0000000000000000      // READ ONLY: Suspend Status OFF

typedef enum {
    ADCON3_SUSPRDY_SUSPENDED = 0b1, // ADC core is suspended (SUSPEND bit = 1) and has no conversions in progress
    ADCON3_SUSPRDY_RUNNING = 0b0 // ADC cores are running or have previous conversions in progress
} ADCON3_SUSPRDY_e; // All ADC Cores Suspended Flag

#define REG_ADCON3L_SHRSAMP_SWTRIG      0b0000001000000000      // Individual Software Trigger for shared Core
#define REG_ADCON3L_SHRSAMP_HWTRIG      0b0000000000000000      // Individual Software Trigger for shared Core disabled

typedef enum {
    ADCON3_SHRSAMP_SWTRIG = 0b1, // Shared ADC core samples an analog input specified by the CNVCHSEL<5:0> bits
    ADCON3_SHRSAMP_HWTRIG = 0b0 // Sampling is controlled by the shared ADC core hardware
} ADCON3_SHRSAMP_e; /* Shared ADC Core Sampling Direct Control
This bit should be used with the individual channel conversion trigger controlled by the CNVRTCH bit.
It connects an analog input, specified by the CNVCHSEL<5:0> bits, to the shared ADC core and allows
extending the sampling time. This bit is not controlled by hardware and must be cleared before the
conversion starts (setting CNVRTCH to 1). */

#define REG_ADCON3L_CNVRTCH_GO          0b0000000100000000      // Individual Software Trigger Status Bit ON (GO) =< will be cleared by hardware when executed
#define REG_ADCON3L_CNVRTCH_READY       0b0000000000000000      // Individual Software Trigger Status Bit OFF (READY for next trigger)

typedef enum {
    ADCON3_CNVRTCH_GO = 0b1, // Single trigger is generated for an analog input specified by the CNVCHSEL<5:0> bits; when the bit is set, it is automatically cleared by hardware on the next instruction cycle
    ADCON3_CNVRTCH_READY = 0b0 // Next individual channel conversion trigger can be generated
} ADCON3_CNVRTCH_e; // Software Individual Channel Conversion Trigger


#define REG_ADCON3L_SWLCTRG_ON          0b0000000010000000      // Software Level-Sensitive Common Trigger ON
#define REG_ADCON3L_SWLCTRG_OFF         0b0000000000000000      // Software Level-Sensitive Common Trigger OFF

typedef enum {
    ADCON3_SWLCTRG_LVLTRG_BY_SW = 0b1, // Triggers are continuously generated for all channels with the software; level-sensitive common trigger selected as a source in the ADTRIGnL and ADTRIGnH registers
    ADCON3_SWLCTRG_LVLTRG_BY_HW = 0b0 // No software, level-sensitive common triggers are generated
} ADCON3_SWLCTRG_e; // Software Level-Sensitive Common Trigger Mode Selection

#define REG_ADCON3L_SWCTRG_ON           0b0000000001000000      // Software Common Trigger ON
#define REG_ADCON3L_SWCTRG_OFF          0b0000000000000000      // Software Common Trigger OFF

typedef enum {
    ADCON3_SWCTRG_GO = 0b1, // Single trigger is generated for all channels with the software; common trigger selected as a source in the ADTRIGnL and ADTRIGnH registers; when the bit is set, it is automatically cleared by hardware on the next instruction cycle
    ADCON3_SWCTRG_READY = 0b0 // Ready to generate the next software common trigger
} ADCON3_SWCTRG_e; // Software Common Trigger

#define REG_ADCON3L_CNVCHSEL_MSK        0b0000000000111111      // Channel Number Mask
#define REG_ADCON3L_CNVCHSEL(channel)   (channel & REG_ADCON3L_CNVCHSEL_MSK)   // Channel Number

typedef enum {
    ADCON3_CNVCHSEL_AN0 = 0b000000, // ADC input AN0 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN1 = 0b000001, // ADC input AN1 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN2 = 0b000010, // ADC input AN2 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN3 = 0b000011, // ADC input AN3 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN4 = 0b000100, // ADC input AN4 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN5 = 0b000101, // ADC input AN5 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN6 = 0b000110, // ADC input AN6 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN7 = 0b000111, // ADC input AN7 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN8 = 0b001000, // ADC input AN8 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN9 = 0b001001, // ADC input AN9 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN10 = 0b001010, // ADC input AN10 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN11 = 0b001011, // ADC input AN11 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN12 = 0b001100, // ADC input AN12 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN13 = 0b001101, // ADC input AN13 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN14 = 0b001110, // ADC input AN14 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN15 = 0b001111, // ADC input AN15 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN16 = 0b010000, // ADC input AN16 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN17 = 0b010001, // ADC input AN17 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN18 = 0b010010, // ADC input AN18 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN19 = 0b010011, // ADC input AN19 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN20 = 0b010100, // ADC input AN20 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN21 = 0b010101, // ADC input AN21 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN22 = 0b010110, // ADC input AN22 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN23 = 0b010111, // ADC input AN23 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN24 = 0b011000, // ADC input AN24 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN25 = 0b011001, // ADC input AN25 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN26 = 0b011010, // ADC input AN26 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN27 = 0b011011, // ADC input AN27 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN28 = 0b011100, // ADC input AN28 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN29 = 0b011101, // ADC input AN29 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN30 = 0b011110, // ADC input AN30 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN31 = 0b011111, // ADC input AN31 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN32 = 0b100000, // ADC input AN32 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN33 = 0b100001, // ADC input AN33 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN34 = 0b100010, // ADC input AN34 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN35 = 0b100011, // ADC input AN35 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN36 = 0b100100, // ADC input AN36 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN37 = 0b100101, // ADC input AN37 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN38 = 0b100110, // ADC input AN38 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN39 = 0b100111, // ADC input AN39 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN40 = 0b101000, // ADC input AN40 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN41 = 0b101001, // ADC input AN41 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN42 = 0b101010, // ADC input AN42 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN43 = 0b101011, // ADC input AN43 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN44 = 0b101100, // ADC input AN44 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN45 = 0b101101, // ADC input AN45 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN46 = 0b101110, // ADC input AN46 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN47 = 0b101111, // ADC input AN47 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN48 = 0b110000, // ADC input AN48 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN49 = 0b110001, // ADC input AN49 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN50 = 0b110010, // ADC input AN50 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN51 = 0b110011, // ADC input AN51 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN52 = 0b110100, // ADC input AN52 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN53 = 0b110101, // ADC input AN53 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN54 = 0b110110, // ADC input AN54 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN55 = 0b110111, // ADC input AN55 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN56 = 0b111000, // ADC input AN56 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN57 = 0b111001, // ADC input AN57 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN58 = 0b111010, // ADC input AN58 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN59 = 0b111011, // ADC input AN59 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN60 = 0b111100, // ADC input AN60 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN61 = 0b111101, // ADC input AN61 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN62 = 0b111110, // ADC input AN62 will be triggered by the Software Individual Channel Conversion Trigger
    ADCON3_CNVCHSEL_AN63 = 0b111111 // ADC input AN63 will be triggered by the Software Individual Channel Conversion Trigger
} ADCON3_CNVCHSEL_e; // Channel Number Selection for Software Individual Channel Conversion Trigger


// REGISTER ADCON3H: ANALOG-TO-DIGITAL CONTROL REGISTER 3 HIGH

#if defined (__P33SMPS_EP__)

#define REG_ADCON3H_CLKSEL_APLL         0b1100000000000000      // ADC Module Clock Input Selection
#define REG_ADCON3H_CLKSEL_FRC          0b1000000000000000
#define REG_ADCON3H_CLKSEL_FOSC         0b0100000000000000
#define REG_ADCON3H_CLKSEL_FSYS         0b0000000000000000

typedef enum {
    ADCON3_CLKSEL_APLL = 0b11, // Auxiliary PLL Output
    ADCON3_CLKSEL_FRC = 0b10, // FRC Oscillator
    ADCON3_CLKSEL_FOSC = 0b01, // System Clock FOSC
    ADCON3_CLKSEL_FSYS = 0b00 // System Clock
} ADCON3_CLKSEL_e;

#elif defined (__P33SMPS_CH__) ||  defined (__P33SMPS_CK__)

#define REG_ADCON3_CLKSEL_FVCO_DIV_4    0b1100000000000000 // FVCO/4 PLL Feedback Click Output
#define REG_ADCON3_CLKSEL_AFVCODIV      0b1000000000000000 // AFVCODIV Auxiliary Clock (recommended)
#define REG_ADCON3_CLKSEL_FOSC          0b0100000000000000 // System Clock FOSC
#define REG_ADCON3_CLKSEL_FOSC_DIV_2    0b0000000000000000 // Peripheral Clock FP (FOSC/2)

typedef enum {
    ADCON3_CLKSEL_FVCO_DIV_4 = 0b11, // FVCO/4 PLL Feedback Click Output
    ADCON3_CLKSEL_AFVCODIV = 0b10, // AFVCODIV Auxiliary Clock (recommended)
    ADCON3_CLKSEL_FOSC = 0b01, // System Clock FOSC
    ADCON3_CLKSEL_FOSC_DIV_2 = 0b00 // Peripheral Clock FP (FOSC/2)
} ADCON3_CLKSEL_e; // ADC Module Clock Source Selection

#endif

#define REG_ADCON3_CLKDIV_MSK          0b0011111100000000      // Source Clock Divider Filter Mask
#define REG_ADCON3_CLKDIV(clkdiv)  (((clkdiv-1) << 8) & REG_ADCON3H_CLKDIV_MSK)  // Source Clock Divider Value

typedef enum {
    ADCON3_CLKDIV_1 = 0b000000, // ADC Module Clock Source Divider of 1 Source Clock Periods
    ADCON3_CLKDIV_2 = 0b000001, // ADC Module Clock Source Divider of 2 Source Clock Periods
    ADCON3_CLKDIV_3 = 0b000010, // ADC Module Clock Source Divider of 3 Source Clock Periods
    ADCON3_CLKDIV_4 = 0b000011, // ADC Module Clock Source Divider of 4 Source Clock Periods
    ADCON3_CLKDIV_5 = 0b000100, // ADC Module Clock Source Divider of 5 Source Clock Periods
    ADCON3_CLKDIV_6 = 0b000101, // ADC Module Clock Source Divider of 6 Source Clock Periods
    ADCON3_CLKDIV_7 = 0b000110, // ADC Module Clock Source Divider of 7 Source Clock Periods
    ADCON3_CLKDIV_8 = 0b000111, // ADC Module Clock Source Divider of 8 Source Clock Periods
    ADCON3_CLKDIV_9 = 0b001000, // ADC Module Clock Source Divider of 9 Source Clock Periods
    ADCON3_CLKDIV_10 = 0b001001, // ADC Module Clock Source Divider of 10 Source Clock Periods
    ADCON3_CLKDIV_11 = 0b001010, // ADC Module Clock Source Divider of 11 Source Clock Periods
    ADCON3_CLKDIV_12 = 0b001011, // ADC Module Clock Source Divider of 12 Source Clock Periods
    ADCON3_CLKDIV_13 = 0b001100, // ADC Module Clock Source Divider of 13 Source Clock Periods
    ADCON3_CLKDIV_14 = 0b001101, // ADC Module Clock Source Divider of 14 Source Clock Periods
    ADCON3_CLKDIV_15 = 0b001110, // ADC Module Clock Source Divider of 15 Source Clock Periods
    ADCON3_CLKDIV_16 = 0b001111, // ADC Module Clock Source Divider of 16 Source Clock Periods
    ADCON3_CLKDIV_17 = 0b010000, // ADC Module Clock Source Divider of 17 Source Clock Periods
    ADCON3_CLKDIV_18 = 0b010001, // ADC Module Clock Source Divider of 18 Source Clock Periods
    ADCON3_CLKDIV_19 = 0b010010, // ADC Module Clock Source Divider of 19 Source Clock Periods
    ADCON3_CLKDIV_20 = 0b010011, // ADC Module Clock Source Divider of 20 Source Clock Periods
    ADCON3_CLKDIV_21 = 0b010100, // ADC Module Clock Source Divider of 21 Source Clock Periods
    ADCON3_CLKDIV_22 = 0b010101, // ADC Module Clock Source Divider of 22 Source Clock Periods
    ADCON3_CLKDIV_23 = 0b010110, // ADC Module Clock Source Divider of 23 Source Clock Periods
    ADCON3_CLKDIV_24 = 0b010111, // ADC Module Clock Source Divider of 24 Source Clock Periods
    ADCON3_CLKDIV_25 = 0b011000, // ADC Module Clock Source Divider of 25 Source Clock Periods
    ADCON3_CLKDIV_26 = 0b011001, // ADC Module Clock Source Divider of 26 Source Clock Periods
    ADCON3_CLKDIV_27 = 0b011010, // ADC Module Clock Source Divider of 27 Source Clock Periods
    ADCON3_CLKDIV_28 = 0b011011, // ADC Module Clock Source Divider of 28 Source Clock Periods
    ADCON3_CLKDIV_29 = 0b011100, // ADC Module Clock Source Divider of 29 Source Clock Periods
    ADCON3_CLKDIV_30 = 0b011101, // ADC Module Clock Source Divider of 30 Source Clock Periods
    ADCON3_CLKDIV_31 = 0b011110, // ADC Module Clock Source Divider of 31 Source Clock Periods
    ADCON3_CLKDIV_32 = 0b011111, // ADC Module Clock Source Divider of 32 Source Clock Periods
    ADCON3_CLKDIV_33 = 0b100000, // ADC Module Clock Source Divider of 33 Source Clock Periods
    ADCON3_CLKDIV_34 = 0b100001, // ADC Module Clock Source Divider of 34 Source Clock Periods
    ADCON3_CLKDIV_35 = 0b100010, // ADC Module Clock Source Divider of 35 Source Clock Periods
    ADCON3_CLKDIV_36 = 0b100011, // ADC Module Clock Source Divider of 36 Source Clock Periods
    ADCON3_CLKDIV_37 = 0b100100, // ADC Module Clock Source Divider of 37 Source Clock Periods
    ADCON3_CLKDIV_38 = 0b100101, // ADC Module Clock Source Divider of 38 Source Clock Periods
    ADCON3_CLKDIV_39 = 0b100110, // ADC Module Clock Source Divider of 39 Source Clock Periods
    ADCON3_CLKDIV_40 = 0b100111, // ADC Module Clock Source Divider of 40 Source Clock Periods
    ADCON3_CLKDIV_41 = 0b101000, // ADC Module Clock Source Divider of 41 Source Clock Periods
    ADCON3_CLKDIV_42 = 0b101001, // ADC Module Clock Source Divider of 42 Source Clock Periods
    ADCON3_CLKDIV_43 = 0b101010, // ADC Module Clock Source Divider of 43 Source Clock Periods
    ADCON3_CLKDIV_44 = 0b101011, // ADC Module Clock Source Divider of 44 Source Clock Periods
    ADCON3_CLKDIV_45 = 0b101100, // ADC Module Clock Source Divider of 45 Source Clock Periods
    ADCON3_CLKDIV_46 = 0b101101, // ADC Module Clock Source Divider of 46 Source Clock Periods
    ADCON3_CLKDIV_47 = 0b101110, // ADC Module Clock Source Divider of 47 Source Clock Periods
    ADCON3_CLKDIV_48 = 0b101111, // ADC Module Clock Source Divider of 48 Source Clock Periods
    ADCON3_CLKDIV_49 = 0b110000, // ADC Module Clock Source Divider of 49 Source Clock Periods
    ADCON3_CLKDIV_50 = 0b110001, // ADC Module Clock Source Divider of 50 Source Clock Periods
    ADCON3_CLKDIV_51 = 0b110010, // ADC Module Clock Source Divider of 51 Source Clock Periods
    ADCON3_CLKDIV_52 = 0b110011, // ADC Module Clock Source Divider of 52 Source Clock Periods
    ADCON3_CLKDIV_53 = 0b110100, // ADC Module Clock Source Divider of 53 Source Clock Periods
    ADCON3_CLKDIV_54 = 0b110101, // ADC Module Clock Source Divider of 54 Source Clock Periods
    ADCON3_CLKDIV_55 = 0b110110, // ADC Module Clock Source Divider of 55 Source Clock Periods
    ADCON3_CLKDIV_56 = 0b110111, // ADC Module Clock Source Divider of 56 Source Clock Periods
    ADCON3_CLKDIV_57 = 0b111000, // ADC Module Clock Source Divider of 57 Source Clock Periods
    ADCON3_CLKDIV_58 = 0b111001, // ADC Module Clock Source Divider of 58 Source Clock Periods
    ADCON3_CLKDIV_59 = 0b111010, // ADC Module Clock Source Divider of 59 Source Clock Periods
    ADCON3_CLKDIV_60 = 0b111011, // ADC Module Clock Source Divider of 60 Source Clock Periods
    ADCON3_CLKDIV_61 = 0b111100, // ADC Module Clock Source Divider of 61 Source Clock Periods
    ADCON3_CLKDIV_62 = 0b111101, // ADC Module Clock Source Divider of 62 Source Clock Periods
    ADCON3_CLKDIV_63 = 0b111110, // ADC Module Clock Source Divider of 63 Source Clock Periods
    ADCON3_CLKDIV_64 = 0b111111 // ADC Module Clock Source Divider of 64 Source Clock Periods
} ADCON3_CLKDIV_e; // ADC Module Clock Source Divider

#define REG_ADCON3_SHREN_ON            0b0000000010000000      // Shared ADC Core Enabled
#define REG_ADCON3_SHREN_OFF           0b0000000000000000      // Shared ADC Core Disabled

typedef enum {
    ADCON3_SHREN_ENABLED = 0b1, // Shared ADC Core is enabled
    ADCON3_SHREN_DISABLED = 0b0 // Shared ADC Core is disabled
} ADCON3_SHREN_e; // Shared ADC Core Enable

#if (ADC_CORE_COUNT > 6)
#define REG_ADCON3H_C3EN_ENABLED        0b0000000000001000      // Dedicated ADC Core #4 Enabled
#define REG_ADCON3H_C3EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #4 Disabled
#endif

#if (ADC_CORE_COUNT > 5)
#define REG_ADCON3H_C3EN_ENABLED        0b0000000000001000      // Dedicated ADC Core #3 Enabled
#define REG_ADCON3H_C3EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #3 Disabled
#endif

#if (ADC_CORE_COUNT > 4)
#define REG_ADCON3H_C2EN_ENABLED        0b0000000000000100      // Dedicated ADC Core #2 Enabled
#define REG_ADCON3H_C2EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #2 Disabled
#endif

#if (ADC_CORE_COUNT > 3)
#define REG_ADCON3H_C2EN_ENABLED        0b0000000000000100      // Dedicated ADC Core #2 Enabled
#define REG_ADCON3H_C2EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #2 Disabled
#endif

#if (ADC_CORE_COUNT > 2)
#define REG_ADCON3H_C1EN_ENABLED        0b0000000000000010      // Dedicated ADC Core #1 Enabled
#define REG_ADCON3H_C1EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #1 Disabled
#endif

#if (ADC_CORE_COUNT > 1)
#define REG_ADCON3H_C0EN_ENABLED        0b0000000000000001      // Dedicated ADC Core #0 Enabled
#define REG_ADCON3H_C0EN_DISABLED       0b0000000000000000      // Dedicated ADC Core #0 Disabled
#endif

typedef enum {
    ADCON3_CxEN_ENABLED = 0b1, // Dedicated ADC Core n is enabled
    ADCON3_CxEN_DISABLED = 0b0 // Dedicated ADC Core n is disabled
} ADCON3_CxEN_e; // Dedicated ADC Core Enable

typedef struct {
    volatile ADCON3_CNVCHSEL_e CNVCHSEL : 6; // Channel Number Selection for Software Individual Channel Conversion Trigger bits
    volatile ADCON3_SWCTRG_e SWCTRG : 1; // Software Common Trigger
    volatile ADCON3_SWLCTRG_e SWLCTRG : 1; // Software Level-Sensitive Common Trigger
    volatile ADCON3_CNVRTCH_e CNVRTCH : 1; // Software Individual Channel Conversion Trigger
    volatile ADCON3_SHRSAMP_e SHRSAMP : 1; // Shared ADC Core Sampling Direct Control
    volatile ADCON3_SUSPRDY_e SUSPRDY : 1; // All ADC Cores Suspended Flag
    volatile ADCON3_SUSPCIE_e SUSPCIE : 1; // Suspend All ADC Cores Common Interrupt Enable bit
    volatile ADCON3_SUSPEND_e SUSPEND : 1; // All ADC Core Triggers Disable bit
    volatile ADCON3_REFSEL_e REFSEL : 3; // ADC Reference Voltage Selection

    #if (ADC_CORE_COUNT > 1)
    volatile ADCON3_CxEN_e C0EN : 1; // Dedicated ADC Core #0 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 2)
    volatile ADCON3_CxEN_e C1EN : 1; // Dedicated ADC Core #1 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 3)
    volatile ADCON3_CxEN_e C2EN : 1; // Dedicated ADC Core #2 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 4)
    volatile ADCON3_CxEN_e C3EN : 1; // Dedicated ADC Core #3 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 5)
    volatile ADCON3_CxEN_e C4EN : 1; // Dedicated ADC Core #4 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 6)
    volatile ADCON3_CxEN_e C5EN : 1; // Dedicated ADC Core #5 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 7)
    volatile ADCON3_CxEN_e C6EN : 1; // Dedicated ADC Core #6 Enable
    #else
    volatile unsigned : 1; // reserved
    #endif

    volatile ADCON3_SHREN_e SHREN : 1; // Shared ADC Core Enable

    volatile ADCON3_CLKDIV_e CLKDIV : 6; // ADC module source clock divider
    volatile ADCON3_CLKSEL_e CLKSEL : 2; // ADC module source clock selection

} __attribute__((packed))ADCON3_t;

typedef union {
    volatile uint32_t value;
    volatile ADCON3_t ADCON3;
} REGBLK_ADCON3_t;


#if (ADC_CORE_COUNT > 1)
// REGISTER ADCON4: ANALOG-TO-DIGITAL CONTROL REGISTER 4 LOW/HIGH

#define REG_ADCON4_VALID_DATA_WRITE_MASK    (uint32_t)(0xFFFF0000 | ADCDORE_REGISTER_BIT_MASK)
#define REG_ADCON4_VALID_DATA_READ_MASK     REG_ADCON4_VALID_DATA_WRITE_MASK

#define REG_ADCON4L_RESET                   0b0000000000000000  // Reset ADCON 4 Low Register
#define REG_ADCON4L_VALID_DATA_WRITE_MASK   0b0000111100001111  // Bit mask used to set unimplemented bits to zero
#define REG_ADCON4L_VALID_DATA_READ_MASK    0b0000111100001111	// Bit mask used to set unimplemented bits to zero

#define REG_ADCON4H_RESET                   0b0000000000000000  // Reset ADCON 4 High Register
#define REG_ADCON4H_VALID_DATA_WRITE_MASK	0b0000000011111111	// Bit mask used to set unimplemented bits to zero
#define REG_ADCON4H_VALID_DATA_READ_MASK	0b0000000011111111	// Bit mask used to set unimplemented bits to zero

#define REG_SYNCTRGSHR_SYNC_TO_SOURCE   0b0100000000000000      // Shared Core synchronized to source clock
#define REG_SYNCTRGSHR_INDEPENDENT      0b0000000000000000      // Shared Core not synchronized to source clock

#if (ADC_CORE_COUNT > 7)
#define REG_SYNCTRG6_SYNC_TO_SOURCE     0b0100000000000000      // Dedicated Core #6 synchronized to source clock
#define REG_SYNCTRG6_INDEPENDENT        0b0000000000000000      // Dedicated Core #6 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 6)
#define REG_SYNCTRG5_SYNC_TO_SOURCE     0b0010000000000000      // Dedicated Core #5 synchronized to source clock
#define REG_SYNCTRG5_INDEPENDENT        0b0000000000000000      // Dedicated Core #5 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 5)
#define REG_SYNCTRG4_SYNC_TO_SOURCE     0b0001000000000000      // Dedicated Core #4 synchronized to source clock
#define REG_SYNCTRG4_INDEPENDENT        0b0000000000000000      // Dedicated Core #4 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 4)
#define REG_SYNCTRG3_SYNC_TO_SOURCE     0b0000100000000000      // Dedicated Core #3 synchronized to source clock
#define REG_SYNCTRG3_INDEPENDENT        0b0000000000000000      // Dedicated Core #3 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 3)
#define REG_SYNCTRG2_SYNC_TO_SOURCE     0b0000010000000000      // Dedicated Core #2 synchronized to source clock
#define REG_SYNCTRG2_INDEPENDENT        0b0000000000000000      // Dedicated Core #2 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 2)
#define REG_SYNCTRG1_SYNC_TO_SOURCE     0b0000001000000000      // Dedicated Core #1 synchronized to source clock
#define REG_SYNCTRG1_INDEPENDENT        0b0000000000000000      // Dedicated Core #1 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 1)
#define REG_SYNCTRG0_SYNC_TO_SOURCE     0b0000000100000000      // Dedicated Core #0 synchronized to source clock
#define REG_SYNCTRG0_INDEPENDENT        0b0000000000000000      // Dedicated Core #0 not synchronized to source clock
#endif

typedef enum {
    ADCON4_SYNCTRGx_SYNC_TO_SOURCE = 0b1, // ADC core clock is synchronized to selected source clock
    ADCON4_SYNCTRGx_INDEPENDENT = 0b0 // ADC core clock is not synchronized to selected source clock
} ADCON4_SYNCTRGx_e; // ADC core clock synchronization

#if (ADC_CORE_COUNT > 7)
#define REG_SAMC6EN_ENABLED            0b0000100000000000      // Core #6 synchronized to source clock
#define REG_SAMC6EN_DISABLED           0b0000000000000000      // Core #6 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 6)
#define REG_SAMC5EN_ENABLED            0b0000100000000000      // Core #5 synchronized to source clock
#define REG_SAMC5EN_DISABLED           0b0000000000000000      // Core #5 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 5)
#define REG_SAMC4EN_ENABLED            0b0000100000000000      // Core #4 synchronized to source clock
#define REG_SAMC4EN_DISABLED           0b0000000000000000      // Core #4 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 4)
#define REG_SAMC3EN_ENABLED            0b0000100000000000      // Core #3 synchronized to source clock
#define REG_SAMC3EN_DISABLED           0b0000000000000000      // Core #3 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 3)
#define REG_SAMC2EN_ENABLED            0b0000010000000000      // Core #2 synchronized to source clock
#define REG_SAMC2EN_DISABLED           0b0000000000000000      // Core #2 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 2)
#define REG_SAMC1EN_ENABLED            0b0000001000000000      // Core #1 synchronized to source clock
#define REG_SAMC1EN_DISABLED           0b0000000000000000      // Core #1 not synchronized to source clock
#endif
#if (ADC_CORE_COUNT > 1)
#define REG_SAMC0EN_ENABLED            0b0000000100000000      // Core #0 synchronized to source clock
#define REG_SAMC0EN_DISABLED           0b0000000000000000      // Core #0 not synchronized to source clock
#endif

typedef enum {
    ADCON4_SAMCxEN_ENABLED = 0b1, // After trigger, the conversion will be delayed and the ADC core will continue sampling during the time specified by the SAMC<9:0> bits in the ADCORE1L register
    ADCON4_SAMCxEN_DISABLED = 0b0 // After trigger, the sampling will be stopped immediately and the conversion will be started on the next core clock cycle
} ADCON4_SAMCxEN_e; // Dedicated ADC Core 1 Conversion Delay Enable


// REGISTER ADCON4H: ANALOG-TO-DIGITAL CONTROL REGISTER 4 HIGH

#define REG_C3CHS_AN3                   0b0000000000000000      // AN3 Input Default Selection
#define REG_C3CHS_AN15                  0b0000000001000000      // AN15 Input Selection

#define REG_C2CHS_AN2                   0b0000000000000000      // AN2 Input Default Selection
#define REG_C2CHS_VREF_BGAP             0b0000000000100000      // VREF Band Gap Input Selection
#define REG_C2CHS_AN11                  0b0000000000010000      // AN11 Input Selection

#define REG_C1CHS_AN1                   0b0000000000000000      // AN1 Band Gap Input Selection
#define REG_C1CHS_PGA2                  0b0000000000001000      // PGA2 Input Selection
#define REG_C1CHS_AN18                  0b0000000000000100      // AN18 Input Selection
#define REG_C1CHS_AN1ALT                0b0000000000001100      // AN1 Input Alternative Selection

#define REG_C0CHS_AN0                   0b0000000000000000      // AN0 Band Gap Input Selection
#define REG_C0CHS_PGA1                  0b0000000000000010      // PGA1 Input Selection
#define REG_C0CHS_AN7                   0b0000000000000001      // AN7 Input Selection
#define REG_C0CHS_AN0ALT                0b0000000000000011      // AN0 Input Alternative Selection

#if defined (__P33SMPS_EP2__)

#define REG_ADCON4_C1CHS_PGA2 0b0000000000001100 // Dedicated ADC Core 1 Input is PGA2 output
#define REG_ADCON4_C1CHS_PGA1 0b0000000000001000 // Dedicated ADC Core 1 Input is PGA1 output
#define REG_ADCON4_C1CHS_AN8  0b0000000000000100 // Dedicated ADC Core 1 Input is AN8 input
#define REG_ADCON4_C1CHS_AN1  0b0000000000000000 // Dedicated ADC Core 1 Input is AN1 input

typedef enum {
    ADCON4_C1CHS_PGA2 = 0b11, // Dedicated ADC Core 1 Input is PGA2 output
    ADCON4_C1CHS_PGA1 = 0b10, // Dedicated ADC Core 1 Input is PGA1 output
    ADCON4_C1CHS_AN8 = 0b01, // Dedicated ADC Core 1 Input is AN8 input
    ADCON4_C1CHS_AN1 = 0b00 // Dedicated ADC Core 1 Input is AN1 input
} ADCON4_C1CHS_e; // Dedicated ADC Core 1 Input Channel Selection

#define REG_ADCON4_C1CHS_PGA2 0b0000000000001100 // Dedicated ADC Core 1 Input is PGA2 output
#define REG_ADCON4_C1CHS_PGA1 0b0000000000001000 // Dedicated ADC Core 1 Input is PGA1 output
#define REG_ADCON4_C1CHS_AN7  0b0000000000000100 // Dedicated ADC Core 1 Input is AN7 input
#define REG_ADCON4_C1CHS_AN0  0b0000000000000000 // Dedicated ADC Core 1 Input is AN0 input

typedef enum {
    ADCON4_C0CHS_PGA2 = 0b11, // Dedicated ADC Core 1 Input is PGA2 output
    ADCON4_C0CHS_PGA1 = 0b10, // Dedicated ADC Core 1 Input is PGA1 output
    ADCON4_C0CHS_AN7 = 0b01, // Dedicated ADC Core 1 Input is AN7 input
    ADCON4_C0CHS_AN3 = 0b00 // Dedicated ADC Core 1 Input is AN0 input
} ADCON4_C0CHS_e; // Dedicated ADC Core 0 Input Channel Selection


#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

#define REG_ADCON4_C3CHS_AN15 0b0000000001000000 // Dedicated ADC Core 3 Input is AN15 input
#define REG_ADCON4_C3CHS_AN3  0b0000000000000000 // Dedicated ADC Core 3 Input is AN3 input

typedef enum {
    ADCON4_C3CHS_AN15 = 0b01, // Dedicated ADC Core 3 Input is AN15 input
    ADCON4_C3CHS_AN3 = 0b00 // Dedicated ADC Core 3 Input is AN3 input
} ADCON4_C3CHS_e; // Dedicated ADC Core 3 Input Channel Selection

#define REG_ADCON4_C2CHS_VREF 0b0000000000100000 // Dedicated ADC Core 3 Input is VREF
#define REG_ADCON4_C2CHS_AN11 0b0000000000010000 // Dedicated ADC Core 3 Input is AN11 input
#define REG_ADCON4_C2CHS_AN2  0b0000000000000000 // Dedicated ADC Core 3 Input is AN3 input

typedef enum {
    ADCON4_C2CHS_VREF = 0b10, // Dedicated ADC Core 1 Input is VREF (internal)
    ADCON4_C2CHS_AN11 = 0b01, // Dedicated ADC Core 1 Input is AN11 input
    ADCON4_C2CHS_AN2 = 0b00 // Dedicated ADC Core 1 Input is AN2 input
} ADCON4_C2CHS_e; // Dedicated ADC Core 2 Input Channel Selection

#define REG_ADCON4_C1CHS_AN1ALT 0b0000000000001100 // Dedicated ADC Core 1 Input is alternative input AN1ALT
#define REG_ADCON4_C1CHS_PGA2   0b0000000000001000 // Dedicated ADC Core 1 Input is PGA2 output (internal)
#define REG_ADCON4_C1CHS_AN18   0b0000000000000100 // Dedicated ADC Core 1 Input is AN18 input
#define REG_ADCON4_C1CHS_AN1    0b0000000000000000 // Dedicated ADC Core 1 Input is AN1 input

typedef enum {
    ADCON4_C1CHS_AN1ALT = 0b11, // Dedicated ADC Core 1 Input is alternative input AN1ALT
    ADCON4_C1CHS_PGA2 = 0b10, // Dedicated ADC Core 1 Input is PGA2 output (internal)
    ADCON4_C1CHS_AN18 = 0b01, // Dedicated ADC Core 1 Input is AN18 input
    ADCON4_C1CHS_AN1 = 0b00 // Dedicated ADC Core 1 Input is AN1 input
} ADCON4_C1CHS_e; // Dedicated ADC Core 1 Input Channel Selection

#define REG_ADCON4_C0CHS_AN0ALT 0b0000000000000011 // Dedicated ADC Core 1 Input is alternative input AN0ALT
#define REG_ADCON4_C0CHS_PGA1   0b0000000000000010 // Dedicated ADC Core 1 Input is PGA1 output (internal)
#define REG_ADCON4_C0CHS_AN7    0b0000000000000001 // Dedicated ADC Core 1 Input is AN7 input
#define REG_ADCON4_C0CHS_AN0    0b0000000000000000 // Dedicated ADC Core 1 Input is AN0 input

typedef enum {
    ADCON4_C0CHS_AN0ALT = 0b11, // Dedicated ADC Core 1 Input is alternative input AN0ALT
    ADCON4_C0CHS_PGA1 = 0b10, // Dedicated ADC Core 1 Input is PGA1 output (internal)
    ADCON4_C0CHS_AN7 = 0b01, // Dedicated ADC Core 1 Input is AN7 input
    ADCON4_C0CHS_AN0 = 0b00 // Dedicated ADC Core 1 Input is AN0 input
} ADCON4_C0CHS_e; // Dedicated ADC Core 0 Input Channel Selection

#elif defined (__P33SMPS_CH_SLV__)

typedef enum {
    ADCON4_C1CHS_S1ANC1 = 0b11, // Dedicated ADC Core 1 Input is Slave Core #1 positive differential input of AN1 
    ADCON4_C1CHS_SPGA2 = 0b10, // Dedicated ADC Core 1 Input is Slave Core #1 PGA2 output
    ADCON4_C1CHS_S1ANA1 = 0b01, // Dedicated ADC Core 1 Input is Slave Core #1 alternative AN1 input
    ADCON4_C1CHS_S1AN1 = 0b00 // Dedicated ADC Core 1 Input is Slave Core #1 AN1 input
} ADCON4_C1CHS_e; // Dedicated ADC Core 1 Input Channel Selection

typedef enum {
    ADCON4_C0CHS_S1ANC0 = 0b11, // Dedicated ADC Core 1 Input is Slave Core #01 positive differential input of AN0 
    ADCON4_C0CHS_SPGA1 = 0b10, // Dedicated ADC Core 1 Input is Slave Core #0 PGA1 output
    ADCON4_C0CHS_S1ANA0 = 0b01, // Dedicated ADC Core 1 Input is Slave Core #0 alternative AN0 input
    ADCON4_C0CHS_S1AN0 = 0b00 // Dedicated ADC Core 1 Input is Slave Core #0 AN0 input
} ADCON4_C0CHS_e; // Dedicated ADC Core 0 Input Channel Selection

#endif

typedef struct {
    #if (ADC_CORE_COUNT > 1)
    volatile ADCON4_SAMCxEN_e SAMC0EN : 1; // Dedicated ADC Core 0 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 2)
    volatile ADCON4_SAMCxEN_e SAMC1EN : 1; // Dedicated ADC Core 1 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 3)
    volatile ADCON4_SAMCxEN_e SAMC2EN : 1; // Dedicated ADC Core 2 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 4)
    volatile ADCON4_SAMCxEN_e SAMC3EN : 1; // Dedicated ADC Core 3 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 5)
    volatile ADCON4_SAMCxEN_e SAMC4EN : 1; // Dedicated ADC Core 4 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 6)
    volatile ADCON4_SAMCxEN_e SAMC5EN : 1; // Dedicated ADC Core 5 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 7)
    volatile ADCON4_SAMCxEN_e SAMC6EN : 1; // Dedicated ADC Core 6 Conversion Delay Enable
    #else
    volatile unsigned : 1; // reserved
    #endif

    volatile unsigned : 1; // reserved
    
    #if (ADC_CORE_COUNT > 1)
    volatile ADCON4_SYNCTRGx_e SYNCTRG0 : 1; // ADC Core 0 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 2)
    volatile ADCON4_SYNCTRGx_e SYNCTRG1 : 1; // ADC Core 1 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 3)
    volatile ADCON4_SYNCTRGx_e SYNCTRG2 : 1; // ADC Core 2 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 4)
    volatile ADCON4_SYNCTRGx_e SYNCTRG3 : 1; // ADC Core 3 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 5)
    volatile ADCON4_SYNCTRGx_e SYNCTRG4 : 1; // ADC Core 4 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 6)
    volatile ADCON4_SYNCTRGx_e SYNCTRG5 : 1; // ADC Core 5 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_CORE_COUNT > 7)
    volatile ADCON4_SYNCTRGx_e SYNCTRG6 : 1; // ADC Core 6 clock synchronization
    #else
    volatile unsigned : 1; // reserved
    #endif

    volatile unsigned : 1; // reserved

    #if (ADC_CORE_COUNT > 1)
    volatile ADCON4_C0CHS_e C0CHS : 2; // ADC Core 0 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 2)
    volatile ADCON4_C1CHS_e C1CHS : 2; // ADC Core 1 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 3)
    volatile ADCON4_C2CHS_e C2CHS : 2; // ADC Core 2 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 4)
    volatile ADCON4_C3CHS_e C3CHS : 2; // ADC Core 3 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 5)
    volatile ADCON4_C3CHS_e C4CHS : 2; // ADC Core 4 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 6)
    volatile ADCON4_C3CHS_e C5CHS : 2; // ADC Core 5 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif
    #if (ADC_CORE_COUNT > 7)
    volatile ADCON4_C3CHS_e C6CHS : 2; // ADC Core 6 analog input selection
    #else
    volatile unsigned : 2; // reserved
    #endif

    volatile unsigned : 2; // reserved

} __attribute__((packed)) ADCON4_t;

#else

// this dummy-memory space will fill the gap when a device doesn't have dedicated ADc cores
// and therefore related registers are not implemented
typedef struct {
    volatile uint32_t: 32; // reserved
} __attribute__((packed)) ADCON4_t;

#endif // end of ADCON4 defines, whcih are only available if dedicated ADC cores are present

typedef union {
    volatile uint32_t value;
    volatile ADCON4_t ADCON4;
} REGBLK_ADCON4_t;

// REGISTERS ADCON5L/H: ANALOG-TO-DIGITAL CONTROL REGISTER 5 LOW/HIGH

#define REG_ADCON5_VALID_DATA_WRITE_MASK    (uint32_t)(0x0F000000 | (ADCDORE_REGISTER_BIT_MASK << 16) | (ADCDORE_REGISTER_BIT_MASK << 8) | ADCDORE_REGISTER_BIT_MASK)
#define REG_ADCON5_VALID_DATA_READ_MASK     (uint32_t)(0x0F000000 | (ADCDORE_REGISTER_BIT_MASK << 16) | ADCDORE_REGISTER_BIT_MASK)

#define REG_ADCON5L_RESET                   0b0000000000000000          // Reset ADCON 5 Low Register (all ADC cores turned off)
#define REG_ADCON5L_VALID_DATA_WRITE_MASK	(uint16_t)ADCDORE_REGISTER_BIT_MASK	// Bit mask used to set unimplemented bits to zero
#define REG_ADCON5L_VALID_DATA_READ_MASK	(uint16_t)((ADCDORE_REGISTER_BIT_MASK << 8) | ADCDORE_REGISTER_BIT_MASK)	// Bit mask used to set unimplemented bits to zero

#define REG_ADCON5H_RESET                   (0x0F00)      // Reset ADCON 5 High Register (maximum warm-up time, all ADC CORE READY ISRs off)
#define REG_ADCON5H_VALID_DATA_WRITE_MASK	(uint16_t)(0x0F00 | ADCDORE_REGISTER_BIT_MASK)		// Bit mask used to set unimplemented bits to zero
#define REG_ADCON5H_VALID_DATA_READ_MASK	(uint16_t)(0x0F00 | ADCDORE_REGISTER_BIT_MASK)		// Bit mask used to set unimplemented bits to zero

#define REG_ADCON5L_SHRRDY_PWROK        0b1000000000000000      // Sharder ADC Core powered and ready
#define REG_ADCON5L_SHRRDY_OFF          0b1000000000000000      // Sharder ADC Core is not powered

#if (ADC_CORE_COUNT > 1)
#define REG_ADCON5L_C0RDY_PWROK         0b0000000100000000      // Dedicated ADC Core #0 powered and ready
#define REG_ADCON5L_C0RDY_FF            0b0000000000000000      // Dedicated ADC Core #0 is not powered
#endif
#if (ADC_CORE_COUNT > 2)
#define REG_ADCON5L_C1RDY_PWROK         0b0000001000000000      // Dedicated ADC Core #1 powered and ready
#define REG_ADCON5L_C1RDY_FF            0b0000000000000000      // Dedicated ADC Core #1 is not powered
#endif
#if (ADC_CORE_COUNT > 3)
#define REG_ADCON5L_C2RDY_PWROK         0b0000010000000000      // Dedicated ADC Core #2 powered and ready
#define REG_ADCON5L_C2RDY_FF            0b0000000000000000      // Dedicated ADC Core #2 is not powered
#endif
#if (ADC_CORE_COUNT > 4)
#define REG_ADCON5L_C3RDY_PWROK         0b0000100000000000      // Dedicated ADC Core #3 powered and ready
#define REG_ADCON5L_C3RDY_FF            0b0000000000000000      // Dedicated ADC Core #3 is not powered
#endif
#if (ADC_CORE_COUNT > 5)
#define REG_ADCON5L_C4RDY_PWROK         0b0001000000000000      // Dedicated ADC Core #4 powered and ready
#define REG_ADCON5L_C4RDY_FF            0b0000000000000000      // Dedicated ADC Core #4 is not powered
#endif
#if (ADC_CORE_COUNT > 6)
#define REG_ADCON5L_C5RDY_PWROK         0b0010000000000000      // Dedicated ADC Core #5 powered and ready
#define REG_ADCON5L_C5RDY_FF            0b0000000000000000      // Dedicated ADC Core #5 is not powered
#endif
#if (ADC_CORE_COUNT > 7)
#define REG_ADCON5L_C6RDY_PWROK         0b0100000000000000      // Dedicated ADC Core #6 powered and ready
#define REG_ADCON5L_C6RDY_FF            0b0000000000000000      // Dedicated ADC Core #6 is not powered
#endif

#define RES_ADCON5L_CxRDY(adc_core)     (uint16_t)(pow(2, adc_core) << 8) // the shared core is always treated as "Core #7"

typedef enum {
    ADCON5_CxRDY_STAT_PWROK = 0b1, // ADC Core #n powered and ready
    ADCON5_CxRDY_OFF = 0b0 // ADC Core is turned off/not powered
} ADCON5_CxRDY_e;


#define REG_ADCON5L_SHRPWR_ON           0b0000000010000000      // Shared ADC Core switched on
#define REG_ADCON5L_SHRPWR_OFF          0b0000000000000000      // Shared ADC Core switched off

#if (ADC_CORE_COUNT > 1)
#define REG_ADCON5L_C0PWR_ON            0b0000000000000001      // Dedicated ADC Core #0 powered
#define REG_ADCON5L_C0PWR_OFF           0b0000000000000000      // Dedicated ADC Core #0 switched off
#endif
#if (ADC_CORE_COUNT > 2)
#define REG_ADCON5L_C1PWR_ON            0b0000000000000010      // Dedicated ADC Core #1 powered
#define REG_ADCON5L_C1PWR_OFF           0b0000000000000000      // Dedicated ADC Core #1 switched off
#endif
#if (ADC_CORE_COUNT > 3)
#define REG_ADCON5L_C2PWR_ON            0b0000000000000100      // Dedicated ADC Core #2 powered
#define REG_ADCON5L_C2PWR_OFF           0b0000000000000000      // Dedicated ADC Core #2 switched off
#endif
#if (ADC_CORE_COUNT > 4)
#define REG_ADCON5L_C3PWR_ON            0b0000000000001000      // Dedicated ADC Core #3 powered
#define REG_ADCON5L_C3PWR_OFF           0b0000000000000000      // Dedicated ADC Core #3 switched off
#endif
#if (ADC_CORE_COUNT > 5)
#define REG_ADCON5L_C4PWR_ON            0b0000000000010000      // Dedicated ADC Core #4 powered
#define REG_ADCON5L_C4PWR_OFF           0b0000000000000000      // Dedicated ADC Core #4 switched off
#endif
#if (ADC_CORE_COUNT > 6)
#define REG_ADCON5L_C5PWR_ON            0b0000000000100000      // Dedicated ADC Core #5 powered
#define REG_ADCON5L_C5PWR_OFF           0b0000000000000000      // Dedicated ADC Core #5 switched off
#endif
#if (ADC_CORE_COUNT > 7)
#define REG_ADCON5L_C6PWR_ON            0b0000000001000000      // Dedicated ADC Core #6 powered
#define REG_ADCON5L_C6PWR_OFF           0b0000000000000000      // Dedicated ADC Core #6 switched off
#endif

#define RES_ADCON5L_CxPWR(adc_core)     (uint16_t)(pow(2.0, adc_core)) // the shared core is always treated as "Core #7"

typedef enum {
    ADCON5_CxPWR_ON = 0b1, // ADC Core #n powered 
    ADCON5_CxPWR_OFF = 0b0 // ADC Core is turned off/not powered
} ADCON5_CxPWR_e;

// REGISTER ADCON5H: ANALOG-TO-DIGITAL CONTROL REGISTER 5 HIGH

#define REG_ADCON5H_WARMTIME_CLK_32768	0b0000111100000000	// ADC Power Up Delay 0f 32768 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_16384	0b0000111000000000	// ADC Power Up Delay 0f 16384 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_8192	0b0000110100000000	// ADC Power Up Delay 0f 8192 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_4096	0b0000110000000000	// ADC Power Up Delay 0f 4096 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_2048	0b0000101100000000	// ADC Power Up Delay 0f 2048 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_1024	0b0000101000000000	// ADC Power Up Delay 0f 1024 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_512	0b0000100100000000	// ADC Power Up Delay 0f 512 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_256	0b0000100000000000	// ADC Power Up Delay 0f 256 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_128	0b0000011100000000	// ADC Power Up Delay 0f 128 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_64		0b0000011000000000	// ADC Power Up Delay 0f 64 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_32		0b0000010100000000	// ADC Power Up Delay 0f 32 ATADCORE cycles
#define REG_ADCON5H_WARMTIME_CLK_16		0b0000010000000000	// ADC Power Up Delay 0f 16 ATADCORE cycles

typedef enum {
    ADCON5H_WARMTIME_CLK_32768 = 0b1111, // 32768 Source Clock Periods
    ADCON5H_WARMTIME_CLK_16384 = 0b1110, // 16384 Source Clock Periods
    ADCON5H_WARMTIME_CLK_8192 = 0b1101, // 8192 Source Clock Periods
    ADCON5H_WARMTIME_CLK_4096 = 0b1100, // 4096 Source Clock Periods
    ADCON5H_WARMTIME_CLK_2048 = 0b1011, // 2048 Source Clock Periods
    ADCON5H_WARMTIME_CLK_1024 = 0b1010, // 1024 Source Clock Periods
    ADCON5H_WARMTIME_CLK_512 = 0b1001, // 512 Source Clock Periods
    ADCON5H_WARMTIME_CLK_256 = 0b1000, // 256 Source Clock Periods
    ADCON5H_WARMTIME_CLK_128 = 0b0111, // 128 Source Clock Periods
    ADCON5H_WARMTIME_CLK_64 = 0b0110, // 64 Source Clock Periods
    ADCON5H_WARMTIME_CLK_32 = 0b0101, // 32 Source Clock Periods
    ADCON5H_WARMTIME_CLK_16 = 0b0100 // 16 Source Clock Periods    
} ADCON5_WARMTIME_e;


#define REG_ADCON5L_SHRCIE_ENABLED      0b0000000010000000      // Shared ADC Core Ready Interrupt enabled
#define REG_ADCON5L_SHRCIE_DISABLED     0b0000000000000000      // Shared ADC Core Ready Interrupt disabled

#if (ADC_CORE_COUNT > 1)
#define REG_ADCON5L_C0CIE_ENABLED            0b0000000000000001      // Dedicated ADC Core #0 Ready Interrupt enabled
#define REG_ADCON5L_C0CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #0 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 2)
#define REG_ADCON5L_C1CIE_ENABLED            0b0000000000000010      // Dedicated ADC Core #1 Ready Interrupt enabled
#define REG_ADCON5L_C1CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #1 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 3)
#define REG_ADCON5L_C2CIE_ENABLED            0b0000000000000100      // Dedicated ADC Core #2 Ready Interrupt enabled
#define REG_ADCON5L_C2CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #2 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 4)
#define REG_ADCON5L_C3CIE_ENABLED            0b0000000000001000      // Dedicated ADC Core #3 Ready Interrupt enabled
#define REG_ADCON5L_C3CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #3 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 5)
#define REG_ADCON5L_C4CIE_ENABLED            0b0000000000010000      // Dedicated ADC Core #4 Ready Interrupt enabled
#define REG_ADCON5L_C4CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #4 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 6)
#define REG_ADCON5L_C5CIE_ENABLED            0b0000000000100000      // Dedicated ADC Core #5 Ready Interrupt enabled
#define REG_ADCON5L_C5CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #5 Ready Interrupt disabled
#endif
#if (ADC_CORE_COUNT > 7)
#define REG_ADCON5L_C6CIE_ENABLED            0b0000000001000000      // Dedicated ADC Core #6 Ready Interrupt enabled
#define REG_ADCON5L_C6CIE_DISABLED           0b0000000000000000      // Dedicated ADC Core #6 Ready Interrupt disabled
#endif

#define RES_ADCON5L_CxCIE(adc_core)     (uint16_t)(pow(2, adc_core)) // the shared core is always treated as "Core #7"

typedef enum {
    ADCON5L_CxCIE_ENABLED = 0b1, // ADC Core #n Ready Interrupt enabled
    ADCON5L_CxCIE_DISABLED = 0b0 // ADC Core #n Ready Interrupt disabled
} ADCON5_CxCIE_e;

typedef struct {
#if (ADC_CORE_COUNT > 1)
    volatile ADCON5_CxPWR_e C0PWR : 1; // Dedicated ADC Core #0 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 2)
    volatile ADCON5_CxPWR_e C1PWR : 1; // Dedicated ADC Core #1 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 3)
    volatile ADCON5_CxPWR_e C2PWR : 1; // Dedicated ADC Core #2 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 4)
    volatile ADCON5_CxPWR_e C3PWR : 1; // Dedicated ADC Core #3 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 5)
    volatile ADCON5_CxPWR_e C4PWR : 1; // Dedicated ADC Core #4 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 6)
    volatile ADCON5_CxPWR_e C5PWR : 1; // Dedicated ADC Core #5 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 7)
    volatile ADCON5_CxPWR_e C6PWR : 1; // Dedicated ADC Core #6 Power Enable
#else
    volatile unsigned : 1; // reserved
#endif
    
    volatile ADCON5_CxPWR_e SHRPWR : 1; // Shared ADC Core Power Enable

#if (ADC_CORE_COUNT > 1)
    volatile ADCON5_CxRDY_e C0RDY : 1; // Dedicated ADC Core #0 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 2)
    volatile ADCON5_CxRDY_e C1RDY : 1; // Dedicated ADC Core #1 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 3)
    volatile ADCON5_CxRDY_e C2RDY : 1; // Dedicated ADC Core #2 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 4)
    volatile ADCON5_CxRDY_e C3RDY : 1; // Dedicated ADC Core #3 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 5)
    volatile ADCON5_CxRDY_e C4RDY : 1; // Dedicated ADC Core #4 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 6)
    volatile ADCON5_CxRDY_e C5RDY : 1; // Dedicated ADC Core #5 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 7)
    volatile ADCON5_CxRDY_e C6RDY : 1; // Dedicated ADC Core #6 "Powered & Ready" Status
#else
    volatile unsigned : 1; // reserved
#endif
    
    volatile ADCON5_CxRDY_e SHRRDY : 1; // Shared ADC Core "Powered & Ready" Status

#if (ADC_CORE_COUNT > 1)
    volatile ADCON5_CxCIE_e C0CIE : 1; // Dedicated ADC Core #0 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 2)
    volatile ADCON5_CxCIE_e C1CIE : 1; // Dedicated ADC Core #1 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 3)
    volatile ADCON5_CxCIE_e C2CIE : 1; // Dedicated ADC Core #2 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 4)
    volatile ADCON5_CxCIE_e C3CIE : 1; // Dedicated ADC Core #3 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 5)
    volatile ADCON5_CxCIE_e C4CIE : 1; // Dedicated ADC Core #4 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 6)
    volatile ADCON5_CxCIE_e C5CIE : 1; // Dedicated ADC Core #5 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
#if (ADC_CORE_COUNT > 7)
    volatile ADCON5_CxCIE_e C6CIE : 1; // Dedicated ADC Core #6 Ready Common Interrupt Enable
#else
    volatile unsigned : 1; // reserved
#endif
    
    volatile ADCON5_CxCIE_e SHRCIE : 1; // Shared ADC Core Ready Common Interrupt Enable

    volatile ADCON5_WARMTIME_e WARMTIME : 4; // ADC Dedicated Core x Power-up Delay
    volatile unsigned : 4; // reserved

} __attribute__((packed)) ADCON5_t;

typedef union {
    volatile uint32_t value;
    volatile ADCON5_t ADCON5;
} REGBLK_ADCON5_t;


// REGISTER 19-11: ADCORExL: DEDICATED ADC CORE x CONTROL REGISTER LOW

#define REG_ADCORExL_RESET              0b0000001111111111      // Reset ADCOREx Low Register
#define REG_ADCORExL_VALID_DATA_MSK		0b0000001111111111		// Bit mask used to set unimplemented bits to zero

#define REG_SAMC_MSK                    0b0000001111111111      // ADCOREx Conversion Delay Filter Mask
#define REG_SAMC(x)						((x-2) & REG_SAMC_MSK) 		// ADCOREx Conversion Delay Value

// REGISTER 19-12: ADCORExH: DEDICATED ADC CORE x CONTROL REGISTER HIGH

#define REG_ADCORExH_RESET              0b0000000000000000      // Reset ADCOREx High Register
#define REG_ADCORExH_VALID_DATA_MSK		0b0001111101111111		// Bit mask used to set unimplemented bits to zero

#define REG_EISEL_8TAD                  0b0001110000000000      // ADCOREx Early Interrupt 8 TADs before ready
#define REG_EISEL_7TAD                  0b0001100000000000      // ADCOREx Early Interrupt 7 TADs before ready
#define REG_EISEL_6TAD                  0b0001010000000000      // ADCOREx Early Interrupt 6 TADs before ready
#define REG_EISEL_5TAD                  0b0001000000000000      // ADCOREx Early Interrupt 5 TADs before ready
#define REG_EISEL_4TAD                  0b0000110000000000      // ADCOREx Early Interrupt 4 TADs before ready
#define REG_EISEL_3TAD                  0b0000100000000000      // ADCOREx Early Interrupt 3 TADs before ready
#define REG_EISEL_2TAD                  0b0000010000000000      // ADCOREx Early Interrupt 2 TADs before ready
#define REG_EISEL_1TAD                  0b0000000000000000      // ADCOREx Early Interrupt 1 TADs before ready

#define REG_ADC_RES_12BIT               0b0000001100000000      // ADC Core Resolution = 12bit
#define REG_ADC_RES_10BIT               0b0000001000000000      // ADC Core Resolution = 10bit
#define REG_ADC_RES_8BIT                0b0000000100000000      // ADC Core Resolution = 8bit
#define REG_ADC_RES_6BIT                0b0000000000000000      // ADC Core Resolution = 6bit

#define REG_ADCS_MSK                    0b0000000001111111      // ADC Core Clock Divider Filter Mask
#define REG_ADCS(x)                     ((x-2) & REG_ADCS_MSK)  		// ADC Core Clock Divider Value

// REGISTER 19-13: ADLVLTRGL: ADC LEVEL_SENSITIVE TRIGGER CONTROL REGISTER LOW

#define REG_ADLVLTRGL_RESET             0b0000000000000000      // Reset ADLVLTRGL Low Register
#define REG_ADLVLTRGL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADLVLTRGL_AN0_LEVEL         0b0000000000000001      // AN0 is Level-Triggered
#define REG_ADLVLTRGL_AN0_EDGE          0b0000000000000000      // AN0 is Edge-Triggered
#define REG_ADLVLTRGL_AN1_LEVEL         0b0000000000000010      // AN1 is Level-Triggered
#define REG_ADLVLTRGL_AN1_EDGE          0b0000000000000000      // AN1 is Edge-Triggered
#define REG_ADLVLTRGL_AN2_LEVEL         0b0000000000000100      // AN2 is Level-Triggered
#define REG_ADLVLTRGL_AN2_EDGE          0b0000000000000000      // AN2 is Edge-Triggered
#define REG_ADLVLTRGL_AN3_LEVEL         0b0000000000001000      // AN3 is Level-Triggered
#define REG_ADLVLTRGL_AN3_EDGE          0b0000000000000000      // AN3 is Edge-Triggered
#define REG_ADLVLTRGL_AN4_LEVEL         0b0000000000010000      // AN4 is Level-Triggered
#define REG_ADLVLTRGL_AN4_EDGE          0b0000000000000000      // AN4 is Edge-Triggered
#define REG_ADLVLTRGL_AN5_LEVEL         0b0000000000100000      // AN5 is Level-Triggered
#define REG_ADLVLTRGL_AN5_EDGE          0b0000000000000000      // AN5 is Edge-Triggered
#define REG_ADLVLTRGL_AN6_LEVEL         0b0000000001000000      // AN6 is Level-Triggered
#define REG_ADLVLTRGL_AN6_EDGE          0b0000000000000000      // AN6 is Edge-Triggered
#define REG_ADLVLTRGL_AN7_LEVEL         0b0000000010000000      // AN7 is Level-Triggered
#define REG_ADLVLTRGL_AN7_EDGE          0b0000000000000000      // AN7 is Edge-Triggered
#define REG_ADLVLTRGL_AN8_LEVEL         0b0000000100000000      // AN8 is Level-Triggered
#define REG_ADLVLTRGL_AN8_EDGE          0b0000000000000000      // AN8 is Edge-Triggered
#define REG_ADLVLTRGL_AN9_LEVEL         0b0000001000000000      // AN9 is Level-Triggered
#define REG_ADLVLTRGL_AN9_EDGE          0b0000000000000000      // AN9 is Edge-Triggered
#define REG_ADLVLTRGL_AN10_LEVEL        0b0000010000000000      // AN10 is Level-Triggered
#define REG_ADLVLTRGL_AN10_EDGE         0b0000000000000000      // AN10 is Edge-Triggered
#define REG_ADLVLTRGL_AN11_LEVEL        0b0000100000000000      // AN11 is Level-Triggered
#define REG_ADLVLTRGL_AN11_EDGE         0b0000000000000000      // AN11 is Edge-Triggered
#define REG_ADLVLTRGL_AN12_LEVEL        0b0001000000000000      // AN12 is Level-Triggered
#define REG_ADLVLTRGL_AN12_EDGE         0b0000000000000000      // AN12 is Edge-Triggered
#define REG_ADLVLTRGL_AN13_LEVEL        0b0010000000000000      // AN13 is Level-Triggered
#define REG_ADLVLTRGL_AN13_EDGE         0b0000000000000000      // AN13 is Edge-Triggered
#define REG_ADLVLTRGL_AN14_LEVEL        0b0100000000000000      // AN14 is Level-Triggered
#define REG_ADLVLTRGL_AN14_EDGE         0b0000000000000000      // AN14 is Edge-Triggered
#define REG_ADLVLTRGL_AN15_LEVEL        0b1000000000000000      // AN15 is Level-Triggered
#define REG_ADLVLTRGL_AN15_EDGE         0b0000000000000000      // AN15 is Edge-Triggered

// REGISTER 19-14: ADLVLTRGH: ADC LEVEL_SENSITIVE TRIGGER CONTROL REGISTER HIGH

#define REG_ADLVLTRGH_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADLVLTRGH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADLVLTRGH_AN16_LEVEL        0b0000000000000001      // AN16 is Level-Triggered
#define REG_ADLVLTRGH_AN16_EDGE         0b0000000000000000      // AN16 is Edge-Triggered
#define REG_ADLVLTRGH_AN17_LEVEL        0b0000000000000010      // AN17 is Level-Triggered
#define REG_ADLVLTRGH_AN17_EDGE         0b0000000000000000      // AN17 is Edge-Triggered
#define REG_ADLVLTRGH_AN18_LEVEL        0b0000000000000100      // AN18 is Level-Triggered
#define REG_ADLVLTRGH_AN18_EDGE         0b0000000000000000      // AN18 is Edge-Triggered
#define REG_ADLVLTRGH_AN19_LEVEL        0b0000000000001000      // AN19 is Level-Triggered
#define REG_ADLVLTRGH_AN19_EDGE         0b0000000000000000      // AN19 is Edge-Triggered
#define REG_ADLVLTRGH_AN20_LEVEL        0b0000000000010000      // AN20 is Level-Triggered
#define REG_ADLVLTRGH_AN20_EDGE         0b0000000000000000      // AN20 is Edge-Triggered
#define REG_ADLVLTRGH_AN21_LEVEL        0b0000000000100000      // AN21 is Level-Triggered
#define REG_ADLVLTRGH_AN21_EDGE         0b0000000000000000      // AN21 is Edge-Triggered
#define REG_ADLVLTRGH_AN22_LEVEL        0b0000000001000000      // AN22 is Level-Triggered
#define REG_ADLVLTRGH_AN22_EDGE         0b0000000000000000      // AN22 is Edge-Triggered
#define REG_ADLVLTRGH_AN23_LEVEL        0b0000000010000000      // AN23 is Level-Triggered
#define REG_ADLVLTRGH_AN23_EDGE         0b0000000000000000      // AN23 is Edge-Triggered
#define REG_ADLVLTRGH_AN24_LEVEL        0b0000000100000000      // AN24 is Level-Triggered
#define REG_ADLVLTRGH_AN24_EDGE         0b0000000000000000      // AN24 is Edge-Triggered
#define REG_ADLVLTRGH_AN25_LEVEL        0b0000001000000000      // AN25 is Level-Triggered
#define REG_ADLVLTRGH_AN25_EDGE         0b0000000000000000      // AN25 is Edge-Triggered
#define REG_ADLVLTRGH_AN26_LEVEL        0b0000010000000000      // AN26 is Level-Triggered
#define REG_ADLVLTRGH_AN26_EDGE         0b0000000000000000      // AN26 is Edge-Triggered
#define REG_ADLVLTRGH_AN27_LEVEL        0b0000100000000000      // AN27 is Level-Triggered
#define REG_ADLVLTRGH_AN27_EDGE         0b0000000000000000      // AN27 is Edge-Triggered
#define REG_ADLVLTRGH_AN28_LEVEL        0b0001000000000000      // AN28 is Level-Triggered
#define REG_ADLVLTRGH_AN28_EDGE         0b0000000000000000      // AN28 is Edge-Triggered
#define REG_ADLVLTRGH_AN29_LEVEL        0b0010000000000000      // AN29 is Level-Triggered
#define REG_ADLVLTRGH_AN29_EDGE         0b0000000000000000      // AN29 is Edge-Triggered
#define REG_ADLVLTRGH_AN30_LEVEL        0b0100000000000000      // AN30 is Level-Triggered
#define REG_ADLVLTRGH_AN30_EDGE         0b0000000000000000      // AN30 is Edge-Triggered
#define REG_ADLVLTRGH_AN31_LEVEL        0b1000000000000000      // AN31 is Level-Triggered
#define REG_ADLVLTRGH_AN31_EDGE         0b0000000000000000      // AN31 is Edge-Triggered


// REGISTER 19-15: ADEIEH: ADC EARLY INTERRUPT ENABLE REGISTER LOW

#define REG_ADEIEL_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEIEL_AN0_ON               0b0000000000000001      // Early Interrupt Enabled for AN0 
#define REG_ADEIEL_AN0_OFF              0b0000000000000000      // Early Interrupt Disabled for AN0 
#define REG_ADEIEL_AN1_ON               0b0000000000000010      // Early Interrupt Enabled for AN1
#define REG_ADEIEL_AN1_OFF              0b0000000000000000      // Early Interrupt Disabled for AN1 
#define REG_ADEIEL_AN2_ON               0b0000000000000100      // Early Interrupt Enabled for AN2
#define REG_ADEIEL_AN2_OFF              0b0000000000000000      // Early Interrupt Disabled for AN2 
#define REG_ADEIEL_AN3_ON               0b0000000000001000      // Early Interrupt Enabled for AN3
#define REG_ADEIEL_AN3_OFF              0b0000000000000000      // Early Interrupt Disabled for AN3 
#define REG_ADEIEL_AN4_ON               0b0000000000010000      // Early Interrupt Enabled for AN4
#define REG_ADEIEL_AN4_OFF              0b0000000000000000      // Early Interrupt Disabled for AN4 
#define REG_ADEIEL_AN5_ON               0b0000000000100000      // Early Interrupt Enabled for AN5
#define REG_ADEIEL_AN5_OFF              0b0000000000000000      // Early Interrupt Disabled for AN5 
#define REG_ADEIEL_AN6_ON               0b0000000001000000      // Early Interrupt Enabled for AN6
#define REG_ADEIEL_AN6_OFF              0b0000000000000000      // Early Interrupt Disabled for AN6 
#define REG_ADEIEL_AN7_ON               0b0000000010000000      // Early Interrupt Enabled for AN7
#define REG_ADEIEL_AN7_OFF              0b0000000000000000      // Early Interrupt Disabled for AN7 
#define REG_ADEIEL_AN8_ON               0b0000000100000000      // Early Interrupt Enabled for AN8
#define REG_ADEIEL_AN8_OFF              0b0000000000000000      // Early Interrupt Disabled for AN8 
#define REG_ADEIEL_AN9_ON               0b0000001000000000      // Early Interrupt Enabled for AN9
#define REG_ADEIEL_AN9_OFF              0b0000000000000000      // Early Interrupt Disabled for AN9 
#define REG_ADEIEL_AN10_ON              0b0000010000000000      // Early Interrupt Enabled for AN10 
#define REG_ADEIEL_AN10_OFF             0b0000000000000000      // Early Interrupt Disabled for AN10 
#define REG_ADEIEL_AN11_ON              0b0000100000000000      // Early Interrupt Enabled for AN11
#define REG_ADEIEL_AN11_OFF             0b0000000000000000      // Early Interrupt Disabled for AN11 
#define REG_ADEIEL_AN12_ON              0b0001000000000000      // Early Interrupt Enabled for AN12
#define REG_ADEIEL_AN12_OFF             0b0000000000000000      // Early Interrupt Disabled for AN12 
#define REG_ADEIEL_AN13_ON              0b0010000000000000      // Early Interrupt Enabled for AN13
#define REG_ADEIEL_AN13_OFF             0b0000000000000000      // Early Interrupt Disabled for AN13 
#define REG_ADEIEL_AN14_ON              0b0100000000000000      // Early Interrupt Enabled for AN14
#define REG_ADEIEL_AN14_OFF             0b0000000000000000      // Early Interrupt Disabled for AN14 
#define REG_ADEIEL_AN15_ON              0b1000000000000000      // Early Interrupt Enabled for AN15
#define REG_ADEIEL_AN15_OFF             0b0000000000000000      // Early Interrupt Disabled for AN15

// REGISTER 19-16: ADEIEH: ADC EARLY INTERRUPT ENABLE REGISTER HIGH

#define REG_ADEIEH_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEIEH_AN16_ON              0b0000000000000001      // Early Interrupt Enabled for AN16
#define REG_ADEIEH_AN16_OFF             0b0000000000000000      // Early Interrupt Disabled for AN16 
#define REG_ADEIEH_AN17_ON              0b0000000000000010      // Early Interrupt Enabled for AN17
#define REG_ADEIEH_AN17_OFF             0b0000000000000000      // Early Interrupt Disabled for AN17 
#define REG_ADEIEH_AN18_ON              0b0000000000000100      // Early Interrupt Enabled for AN18
#define REG_ADEIEH_AN18_OFF             0b0000000000000000      // Early Interrupt Disabled for AN18 
#define REG_ADEIEH_AN19_ON              0b0000000000001000      // Early Interrupt Enabled for AN19
#define REG_ADEIEH_AN19_OFF             0b0000000000000000      // Early Interrupt Disabled for AN19 
#define REG_ADEIEH_AN20_ON              0b0000000000010000      // Early Interrupt Enabled for AN20
#define REG_ADEIEH_AN20_OFF             0b0000000000000000      // Early Interrupt Disabled for AN20 
#define REG_ADEIEH_AN21_ON              0b0000000000100000      // Early Interrupt Enabled for AN21
#define REG_ADEIEH_AN21_OFF             0b0000000000000000      // Early Interrupt Disabled for AN21 
#define REG_ADEIEH_AN22_ON              0b0000000001000000      // Early Interrupt Enabled for AN22
#define REG_ADEIEH_AN22_OFF             0b0000000000000000      // Early Interrupt Disabled for AN22 
#define REG_ADEIEH_AN23_ON              0b0000000010000000      // Early Interrupt Enabled for AN23
#define REG_ADEIEH_AN23_OFF             0b0000000000000000      // Early Interrupt Disabled for AN23 
#define REG_ADEIEH_AN24_ON              0b0000000100000000      // Early Interrupt Enabled for AN24
#define REG_ADEIEH_AN24_OFF             0b0000000000000000      // Early Interrupt Disabled for AN24 
#define REG_ADEIEH_AN25_ON              0b0000001000000000      // Early Interrupt Enabled for AN25
#define REG_ADEIEH_AN25_OFF             0b0000000000000000      // Early Interrupt Disabled for AN25 
#define REG_ADEIEH_AN26_ON              0b0000010000000000      // Early Interrupt Enabled for AN26
#define REG_ADEIEH_AN26_OFF             0b0000000000000000      // Early Interrupt Disabled for AN26 
#define REG_ADEIEH_AN27_ON              0b0000100000000000      // Early Interrupt Enabled for AN27
#define REG_ADEIEH_AN27_OFF             0b0000000000000000      // Early Interrupt Disabled for AN27 
#define REG_ADEIEH_AN28_ON              0b0001000000000000      // Early Interrupt Enabled for AN28
#define REG_ADEIEH_AN28_OFF             0b0000000000000000      // Early Interrupt Disabled for AN28 
#define REG_ADEIEH_AN29_ON              0b0010000000000000      // Early Interrupt Enabled for AN29
#define REG_ADEIEH_AN29_OFF             0b0000000000000000      // Early Interrupt Disabled for AN29 
#define REG_ADEIEH_AN30_ON              0b0100000000000000      // Early Interrupt Enabled for AN30
#define REG_ADEIEH_AN30_OFF             0b0000000000000000      // Early Interrupt Disabled for AN30 
#define REG_ADEIEH_AN31_ON              0b1000000000000000      // Early Interrupt Enabled for AN31
#define REG_ADEIEH_AN31_OFF             0b0000000000000000      // Early Interrupt Disabled for AN31

typedef enum {
    ADEIE_ANx_ON = 0b1,      // Early Interrupt Enabled for ANx 
    ADEIE_ANx_OFF = 0b0      // Early Interrupt Disabled for ANx 
}ADEIE_EIEN_e; 

typedef struct {
    volatile ADEIE_EIEN_e AN0EIE : 1; // Enable/Disable AN0 Early Interrupt
    volatile ADEIE_EIEN_e AN1EIE : 1; // Enable/Disable AN1 Early Interrupt
    volatile ADEIE_EIEN_e AN2EIE : 1; // Enable/Disable AN2 Early Interrupt
    volatile ADEIE_EIEN_e AN3EIE : 1; // Enable/Disable AN3 Early Interrupt
    volatile ADEIE_EIEN_e AN4EIE : 1; // Enable/Disable AN4 Early Interrupt
    volatile ADEIE_EIEN_e AN5EIE : 1; // Enable/Disable AN5 Early Interrupt
    volatile ADEIE_EIEN_e AN6EIE : 1; // Enable/Disable AN6 Early Interrupt
    volatile ADEIE_EIEN_e AN7EIE : 1; // Enable/Disable AN7 Early Interrupt
    #if (ADC_ANINPUT_COUNT > 7)
    volatile ADEIE_EIEN_e AN8EIE : 1; // Enable/Disable AN8 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 8)
    volatile ADEIE_EIEN_e AN9EIE : 1; // Enable/Disable AN9 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 9)
    volatile ADEIE_EIEN_e AN10EIE : 1; // Enable/Disable AN10 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 10)
    volatile ADEIE_EIEN_e AN11EIE : 1; // Enable/Disable AN11 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 11)
    volatile ADEIE_EIEN_e AN12EIE : 1; // Enable/Disable AN12 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 12)
    volatile ADEIE_EIEN_e AN13EIE : 1; // Enable/Disable AN13 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 13)
    volatile ADEIE_EIEN_e AN14EIE : 1; // Enable/Disable AN14 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif

    #if (ADC_ANINPUT_COUNT > 14)
    volatile ADEIE_EIEN_e AN15EIE : 1; // Enable/Disable AN15 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif

    #if (ADC_ANINPUT_COUNT > 15)
    volatile ADEIE_EIEN_e AN16EIE : 1; // Enable/Disable AN16 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    
    #if (ADC_ANINPUT_COUNT > 16)
    volatile ADEIE_EIEN_e AN17EIE : 1; // Enable/Disable AN17 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 17)
    volatile ADEIE_EIEN_e AN18EIE : 1; // Enable/Disable AN18 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 18)
    volatile ADEIE_EIEN_e AN19EIE : 1; // Enable/Disable AN19 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 19)
    volatile ADEIE_EIEN_e AN20EIE : 1; // Enable/Disable AN20 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 20)
    volatile ADEIE_EIEN_e AN21EIE : 1; // Enable/Disable AN21 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 21)
    volatile ADEIE_EIEN_e AN22EIE : 1; // Enable/Disable AN22 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 22)
    volatile ADEIE_EIEN_e AN23EIE : 1; // Enable/Disable AN23 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 23)
    volatile ADEIE_EIEN_e AN24EIE : 1; // Enable/Disable AN24 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 24)
    volatile ADEIE_EIEN_e AN25EIE : 1; // Enable/Disable AN25 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 25)
    volatile ADEIE_EIEN_e AN26EIE : 1; // Enable/Disable AN26 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 26)
    volatile ADEIE_EIEN_e AN27EIE : 1; // Enable/Disable AN27 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 27)
    volatile ADEIE_EIEN_e AN28EIE : 1; // Enable/Disable AN28 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 28)
    volatile ADEIE_EIEN_e AN29EIE : 1; // Enable/Disable AN29 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 29)
    volatile ADEIE_EIEN_e AN30EIE : 1; // Enable/Disable AN30 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 30)
    volatile ADEIE_EIEN_e AN31EIE : 1; // Enable/Disable AN31 Early Interrupt
    #else
    volatile unsigned : 1; // reserved
    #endif

}__attribute__((packed))ADEIE_t;

typedef union {
    volatile uint32_t value;
    volatile ADEIE_t ADEIE;
} REGBLK_ADEIE_t;


// REGISTER 19-17: ADEISTATL: ADC EARLY INTERRUPT STATUS REGISTER LOW

#define REG_ADEISTATL_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEISTATL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEISTATL_AN0_SET           0b0000000000000001      // Early Interrupt Status SET for AN0 
#define REG_ADEISTATL_AN0_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN0 
#define REG_ADEISTATL_AN1_SET           0b0000000000000010      // Early Interrupt Status SET for AN1
#define REG_ADEISTATL_AN1_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN1 
#define REG_ADEISTATL_AN2_SET           0b0000000000000100      // Early Interrupt Status SET for AN2
#define REG_ADEISTATL_AN2_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN2 
#define REG_ADEISTATL_AN3_SET           0b0000000000001000      // Early Interrupt Status SET for AN3
#define REG_ADEISTATL_AN3_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN3 
#define REG_ADEISTATL_AN4_SET           0b0000000000010000      // Early Interrupt Status SET for AN4
#define REG_ADEISTATL_AN4_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN4 
#define REG_ADEISTATL_AN5_SET           0b0000000000100000      // Early Interrupt Status SET for AN5
#define REG_ADEISTATL_AN5_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN5 
#define REG_ADEISTATL_AN6_SET           0b0000000001000000      // Early Interrupt Status SET for AN6
#define REG_ADEISTATL_AN6_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN6 
#define REG_ADEISTATL_AN7_SET           0b0000000010000000      // Early Interrupt Status SET for AN7
#define REG_ADEISTATL_AN7_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN7 
#define REG_ADEISTATL_AN8_SET           0b0000000100000000      // Early Interrupt Status SET for AN8
#define REG_ADEISTATL_AN8_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN8 
#define REG_ADEISTATL_AN9_SET           0b0000001000000000      // Early Interrupt Status SET for AN9
#define REG_ADEISTATL_AN9_CLR           0b0000000000000000      // Early Interrupt Status CLEARED for AN9 
#define REG_ADEISTATL_AN10_SET          0b0000010000000000      // Early Interrupt Status SET for AN10 
#define REG_ADEISTATL_AN10_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN10 
#define REG_ADEISTATL_AN11_SET          0b0000100000000000      // Early Interrupt Status SET for AN11
#define REG_ADEISTATL_AN11_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN11 
#define REG_ADEISTATL_AN12_SET          0b0001000000000000      // Early Interrupt Status SET for AN12
#define REG_ADEISTATL_AN12_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN12 
#define REG_ADEISTATL_AN13_SET          0b0010000000000000      // Early Interrupt Status SET for AN13
#define REG_ADEISTATL_AN13_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN13 
#define REG_ADEISTATL_AN14_SET          0b0100000000000000      // Early Interrupt Status SET for AN14
#define REG_ADEISTATL_AN14_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN14 
#define REG_ADEISTATL_AN15_SET          0b1000000000000000      // Early Interrupt Status SET for AN15
#define REG_ADEISTATL_AN15_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN15


// REGISTER 19-18: ADEISTATH: ADC EARLY INTERRUPT STATUS REGISTER HIGH

#define REG_ADEISTATH_RESET             0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADEISTATH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADEISTATH_AN16_SET          0b0000000000000001      // Early Interrupt Status SET for AN16
#define REG_ADEISTATH_AN16_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN16 
#define REG_ADEISTATH_AN17_SET          0b0000000000000010      // Early Interrupt Status SET for AN17
#define REG_ADEISTATH_AN17_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN17 
#define REG_ADEISTATH_AN18_SET          0b0000000000000100      // Early Interrupt Status SET for AN18
#define REG_ADEISTATH_AN18_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN18 
#define REG_ADEISTATH_AN19_SET          0b0000000000001000      // Early Interrupt Status SET for AN19
#define REG_ADEISTATH_AN19_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN19 
#define REG_ADEISTATH_AN20_SET          0b0000000000010000      // Early Interrupt Status SET for AN20
#define REG_ADEISTATH_AN20_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN20 
#define REG_ADEISTATH_AN21_SET          0b0000000000100000      // Early Interrupt Status SET for AN21
#define REG_ADEISTATH_AN21_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN21 
#define REG_ADEISTATH_AN22_SET          0b0000000001000000      // Early Interrupt Status SET for AN22
#define REG_ADEISTATH_AN22_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN22 
#define REG_ADEISTATH_AN23_SET          0b0000000010000000      // Early Interrupt Status SET for AN23
#define REG_ADEISTATH_AN23_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN23 
#define REG_ADEISTATH_AN24_SET          0b0000000100000000      // Early Interrupt Status SET for AN24
#define REG_ADEISTATH_AN24_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN24 
#define REG_ADEISTATH_AN25_SET          0b0000001000000000      // Early Interrupt Status SET for AN25
#define REG_ADEISTATH_AN25_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN25 
#define REG_ADEISTATH_AN26_SET          0b0000010000000000      // Early Interrupt Status SET for AN26
#define REG_ADEISTATH_AN26_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN26 
#define REG_ADEISTATH_AN27_SET          0b0000100000000000      // Early Interrupt Status SET for AN27
#define REG_ADEISTATH_AN27_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN27 
#define REG_ADEISTATH_AN28_SET          0b0001000000000000      // Early Interrupt Status SET for AN28
#define REG_ADEISTATH_AN28_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN28 
#define REG_ADEISTATH_AN29_SET          0b0010000000000000      // Early Interrupt Status SET for AN29
#define REG_ADEISTATH_AN29_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN29 
#define REG_ADEISTATH_AN30_SET          0b0100000000000000      // Early Interrupt Status SET for AN30
#define REG_ADEISTATH_AN30_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN30 
#define REG_ADEISTATH_AN31_SET          0b1000000000000000      // Early Interrupt Status SET for AN31
#define REG_ADEISTATH_AN31_CLR          0b0000000000000000      // Early Interrupt Status CLEARED for AN31


// REGISTER 19-19: ADMOD0L: ADC INPUT MODE CONTROL REGISTER 0 LOW

#define REG_ADMOD0L_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADMOD0L_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD0L_AN0_DIFF             0b0000000000000010      // AN0 operates in Differential mode
#define REG_ADMOD0L_AN0_SNGE             0b0000000000000000      // AN0 operates in single ended mode
#define REG_ADMOD0L_AN1_DIFF             0b0000000000001000      // AN1 operates in Differential mode
#define REG_ADMOD0L_AN1_SNGE             0b0000000000000000      // AN1 operates in single ended mode
#define REG_ADMOD0L_AN2_DIFF             0b0000000000100000      // AN2 operates in Differential mode
#define REG_ADMOD0L_AN2_SNGE             0b0000000000000000      // AN2 operates in single ended mode
#define REG_ADMOD0L_AN3_DIFF             0b0000000010000000      // AN3 operates in Differential mode
#define REG_ADMOD0L_AN3_SNGE             0b0000000000000000      // AN3 operates in single ended mode
#define REG_ADMOD0L_AN4_DIFF             0b0000001000000000      // AN4 operates in Differential mode
#define REG_ADMOD0L_AN4_SNGE             0b0000000000000000      // AN4 operates in single ended mode
#define REG_ADMOD0L_AN5_DIFF             0b0000100000000000      // AN5 operates in Differential mode
#define REG_ADMOD0L_AN5_SNGE             0b0000000000000000      // AN5 operates in single ended mode
#define REG_ADMOD0L_AN6_DIFF             0b0010000000000000      // AN6 operates in Differential mode
#define REG_ADMOD0L_AN6_SNGE             0b0000000000000000      // AN6 operates in single ended mode
#define REG_ADMOD0L_AN7_DIFF             0b1000000000000000      // AN7 operates in Differential mode
#define REG_ADMOD0L_AN7_SNGE             0b0000000000000000      // AN7 operates in single ended mode

#define REG_ADMOD0L_AN0_SIGNED           0b0000000000000001      // In differential mode AN0 output will be signed
#define REG_ADMOD0L_AN0_UNSIGNED         0b0000000000000000      // In differential mode AN0 output will be unsigned
#define REG_ADMOD0L_AN1_SIGNED           0b0000000000000100      // In differential mode AN1 output will be signed
#define REG_ADMOD0L_AN1_UNSIGNED         0b0000000000000000      // In differential mode AN1 output will be unsigned
#define REG_ADMOD0L_AN2_SIGNED           0b0000000000010000      // In differential mode AN2 output will be signed
#define REG_ADMOD0L_AN2_UNSIGNED         0b0000000000000000      // In differential mode AN2 output will be unsigned
#define REG_ADMOD0L_AN3_SIGNED           0b0000000001000000      // In differential mode AN3 output will be signed
#define REG_ADMOD0L_AN3_UNSIGNED         0b0000000000000000      // In differential mode AN3 output will be unsigned
#define REG_ADMOD0L_AN4_SIGNED           0b0000000100000000      // In differential mode AN4 output will be signed
#define REG_ADMOD0L_AN4_UNSIGNED         0b0000000000000000      // In differential mode AN4 output will be unsigned
#define REG_ADMOD0L_AN5_SIGNED           0b0000010000000000      // In differential mode AN5 output will be signed
#define REG_ADMOD0L_AN5_UNSIGNED         0b0000000000000000      // In differential mode AN5 output will be unsigned
#define REG_ADMOD0L_AN6_SIGNED           0b0001000000000000      // In differential mode AN6 output will be signed
#define REG_ADMOD0L_AN6_UNSIGNED         0b0000000000000000      // In differential mode AN6 output will be unsigned
#define REG_ADMOD0L_AN7_SIGNED           0b0100000000000000      // In differential mode AN7 output will be signed
#define REG_ADMOD0L_AN7_UNSIGNED         0b0000000000000000      // In differential mode AN7 output will be unsigned


// REGISTER 19-20: ADMOD0H: ADC INPUT MODE CONTROL REGISTER 0 HIGH

#define REG_ADMOD0H_RESET                0b0000000000000000      // Reset ADMOD0H High Register
#define REG_ADMOD0H_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD0H_AN8_DIFF             0b0000000000000010      // AN8 operates in Differential mode
#define REG_ADMOD0H_AN8_SNGE             0b0000000000000000      // AN8 operates in single ended mode
#define REG_ADMOD0H_AN9_DIFF             0b0000000000001000      // AN9 operates in Differential mode
#define REG_ADMOD0H_AN9_SNGE             0b0000000000000000      // AN9 operates in single ended mode
#define REG_ADMOD0H_AN10_DIFF            0b0000000000100000      // AN10 operates in Differential mode
#define REG_ADMOD0H_AN10_SNGE            0b0000000000000000      // AN10 operates in single ended mode
#define REG_ADMOD0H_AN11_DIFF            0b0000000010000000      // AN11 operates in Differential mode
#define REG_ADMOD0H_AN11_SNGE            0b0000000000000000      // AN11 operates in single ended mode
#define REG_ADMOD0H_AN12_DIFF            0b0000001000000000      // AN12 operates in Differential mode
#define REG_ADMOD0H_AN12_SNGE            0b0000000000000000      // AN12 operates in single ended mode
#define REG_ADMOD0H_AN13_DIFF            0b0000100000000000      // AN13 operates in Differential mode
#define REG_ADMOD0H_AN13_SNGE            0b0000000000000000      // AN13 operates in single ended mode
#define REG_ADMOD0H_AN14_DIFF            0b0010000000000000      // AN14 operates in Differential mode
#define REG_ADMOD0H_AN14_SNGE            0b0000000000000000      // AN14 operates in single ended mode
#define REG_ADMOD0H_AN15_DIFF            0b1000000000000000      // AN15 operates in Differential mode
#define REG_ADMOD0H_AN15_SNGE            0b0000000000000000      // AN15 operates in single ended mode

#define REG_ADMOD0H_AN8_SIGNED           0b0000000000000001      // In differential mode AN8 output will be signed
#define REG_ADMOD0H_AN8_UNSIGNED         0b0000000000000000      // In differential mode AN8 output will be unsigned
#define REG_ADMOD0H_AN9_SIGNED           0b0000000000000100      // In differential mode AN9 output will be signed
#define REG_ADMOD0H_AN9_UNSIGNED         0b0000000000000000      // In differential mode AN9 output will be unsigned
#define REG_ADMOD0H_AN10_SIGNED          0b0000000000010000      // In differential mode AN10 output will be signed
#define REG_ADMOD0H_AN10_UNSIGNED        0b0000000000000000      // In differential mode AN10 output will be unsigned
#define REG_ADMOD0H_AN11_SIGNED          0b0000000001000000      // In differential mode AN11 output will be signed
#define REG_ADMOD0H_AN11_UNSIGNED        0b0000000000000000      // In differential mode AN11 output will be unsigned
#define REG_ADMOD0H_AN12_SIGNED          0b0000000100000000      // In differential mode AN12 output will be signed
#define REG_ADMOD0H_AN12_UNSIGNED        0b0000000000000000      // In differential mode AN12 output will be unsigned
#define REG_ADMOD0H_AN13_SIGNED          0b0000010000000000      // In differential mode AN13 output will be signed
#define REG_ADMOD0H_AN13_UNSIGNED        0b0000000000000000      // In differential mode AN13 output will be unsigned
#define REG_ADMOD0H_AN14_SIGNED          0b0001000000000000      // In differential mode AN14 output will be signed
#define REG_ADMOD0H_AN14_UNSIGNED        0b0000000000000000      // In differential mode AN14 output will be unsigned
#define REG_ADMOD0H_AN15_SIGNED          0b0100000000000000      // In differential mode AN15 output will be signed
#define REG_ADMOD0H_AN15_UNSIGNED        0b0000000000000000      // In differential mode AN15 output will be unsigned


// REGISTER 19-21: ADMOD1L: ADC INPUT MODE CONTROL REGISTER 1 LOW

#define REG_ADMOD1L_RESET                0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADMOD1L_VALID_DATA_MSK		 0b0000111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD1L_AN16_DIFF            0b0000000000000010      // AN16 operates in Differential mode
#define REG_ADMOD1L_AN16_SNGE            0b0000000000000000      // AN16 operates in single ended mode
#define REG_ADMOD1L_AN17_DIFF            0b0000000000001000      // AN17 operates in Differential mode
#define REG_ADMOD1L_AN17_SNGE            0b0000000000000000      // AN17 operates in single ended mode
#define REG_ADMOD1L_AN18_DIFF            0b0000000000100000      // AN18 operates in Differential mode
#define REG_ADMOD1L_AN18_SNGE            0b0000000000000000      // AN18 operates in single ended mode
#define REG_ADMOD1L_AN19_DIFF            0b0000000010000000      // AN19 operates in Differential mode
#define REG_ADMOD1L_AN19_SNGE            0b0000000000000000      // AN19 operates in single ended mode
#define REG_ADMOD1L_AN20_DIFF            0b0000001000000000      // AN20 operates in Differential mode
#define REG_ADMOD1L_AN20_SNGE            0b0000000000000000      // AN20 operates in single ended mode
#define REG_ADMOD1L_AN21_DIFF            0b0000100000000000      // AN21 operates in Differential mode
#define REG_ADMOD1L_AN21_SNGE            0b0000000000000000      // AN21 operates in single ended mode
#define REG_ADMOD1L_AN22_DIFF            0b0010000000000000      // AN22 operates in Differential mode
#define REG_ADMOD1L_AN22_SNGE            0b0000000000000000      // AN22 operates in single ended mode
#define REG_ADMOD1L_AN23_DIFF            0b1000000000000000      // AN23 operates in Differential mode
#define REG_ADMOD1L_AN23_SNGE            0b0000000000000000      // AN23 operates in single ended mode

#define REG_ADMOD1L_AN16_SIGNED          0b0000000000000001      // In differential mode AN8 output will be signed
#define REG_ADMOD1L_AN16_UNSIGNED        0b0000000000000000      // In differential mode AN8 output will be unsigned
#define REG_ADMOD1L_AN17_SIGNED          0b0000000000000100      // In differential mode AN9 output will be signed
#define REG_ADMOD1L_AN17_UNSIGNED        0b0000000000000000      // In differential mode AN9 output will be unsigned
#define REG_ADMOD1L_AN18_SIGNED          0b0000000000010000      // In differential mode AN10 output will be signed
#define REG_ADMOD1L_AN18_UNSIGNED        0b0000000000000000      // In differential mode AN10 output will be unsigned
#define REG_ADMOD1L_AN19_SIGNED          0b0000000001000000      // In differential mode AN11 output will be signed
#define REG_ADMOD1L_AN19_UNSIGNED        0b0000000000000000      // In differential mode AN11 output will be unsigned
#define REG_ADMOD1L_AN20_SIGNED          0b0000000100000000      // In differential mode AN12 output will be signed
#define REG_ADMOD1L_AN20_UNSIGNED        0b0000000000000000      // In differential mode AN12 output will be unsigned
#define REG_ADMOD1L_AN21_SIGNED          0b0000010000000000      // In differential mode AN13 output will be signed
#define REG_ADMOD1L_AN21_UNSIGNED        0b0000000000000000      // In differential mode AN13 output will be unsigned
#define REG_ADMOD1L_AN22_SIGNED          0b0001000000000000      // In differential mode AN14 output will be signed
#define REG_ADMOD1L_AN22_UNSIGNED        0b0000000000000000      // In differential mode AN14 output will be unsigned
#define REG_ADMOD1L_AN23_SIGNED          0b0100000000000000      // In differential mode AN15 output will be signed
#define REG_ADMOD1L_AN23_UNSIGNED        0b0000000000000000      // In differential mode AN15 output will be unsigned


#ifdef ADMOD1H
// REGISTER 19-xx: ADMOD1H: ADC INPUT MODE CONTROL REGISTER 1 HIGH

#define REG_ADMOD1H_RESET                0b0000000000000000      // Reset ADMOD0H High Register
#define REG_ADMOD1H_VALID_DATA_MSK		 0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADMOD1H_AN24_DIFF            0b0000000000000010      // AN24 operates in Differential mode
#define REG_ADMOD1H_AN24_SNGE            0b0000000000000000      // AN24 operates in single ended mode
#define REG_ADMOD1H_AN25_DIFF            0b0000000000001000      // AN25 operates in Differential mode
#define REG_ADMOD1H_AN25_SNGE            0b0000000000000000      // AN25 operates in single ended mode
#define REG_ADMOD1H_AN26_DIFF            0b0000000000100000      // AN26 operates in Differential mode
#define REG_ADMOD1H_AN26_SNGE            0b0000000000000000      // AN26 operates in single ended mode
#define REG_ADMOD1H_AN27_DIFF            0b0000000010000000      // AN27 operates in Differential mode
#define REG_ADMOD1H_AN27_SNGE            0b0000000000000000      // AN27 operates in single ended mode
#define REG_ADMOD1H_AN28_DIFF            0b0000001000000000      // AN28 operates in Differential mode
#define REG_ADMOD1H_AN28_SNGE            0b0000000000000000      // AN28 operates in single ended mode
#define REG_ADMOD1H_AN29_DIFF            0b0000100000000000      // AN29 operates in Differential mode
#define REG_ADMOD1H_AN29_SNGE            0b0000000000000000      // AN29 operates in single ended mode
#define REG_ADMOD1H_AN30_DIFF            0b0010000000000000      // AN30 operates in Differential mode
#define REG_ADMOD1H_AN30_SNGE            0b0000000000000000      // AN30 operates in single ended mode
#define REG_ADMOD1H_AN31_DIFF            0b1000000000000000      // AN31 operates in Differential mode
#define REG_ADMOD1H_AN31_SNGE            0b0000000000000000      // AN31 operates in single ended mode

#define REG_ADMOD1H_AN24_SIGNED          0b0000000000000001      // In differential mode AN24 output will be signed
#define REG_ADMOD1H_AN24_UNSIGNED        0b0000000000000000      // In differential mode AN24 output will be unsigned
#define REG_ADMOD1H_AN25_SIGNED          0b0000000000000100      // In differential mode AN25 output will be signed
#define REG_ADMOD1H_AN25_UNSIGNED        0b0000000000000000      // In differential mode AN25 output will be unsigned
#define REG_ADMOD1H_AN26_SIGNED          0b0000000000010000      // In differential mode AN26 output will be signed
#define REG_ADMOD1H_AN26_UNSIGNED        0b0000000000000000      // In differential mode AN26 output will be unsigned
#define REG_ADMOD1H_AN27_SIGNED          0b0000000001000000      // In differential mode AN27 output will be signed
#define REG_ADMOD1H_AN27_UNSIGNED        0b0000000000000000      // In differential mode AN27 output will be unsigned
#define REG_ADMOD1H_AN28_SIGNED          0b0000000100000000      // In differential mode AN28 output will be signed
#define REG_ADMOD1H_AN28_UNSIGNED        0b0000000000000000      // In differential mode AN28 output will be unsigned
#define REG_ADMOD1H_AN29_SIGNED          0b0000010000000000      // In differential mode AN29 output will be signed
#define REG_ADMOD1H_AN29_UNSIGNED        0b0000000000000000      // In differential mode AN29 output will be unsigned
#define REG_ADMOD1H_AN30_SIGNED          0b0001000000000000      // In differential mode AN30 output will be signed
#define REG_ADMOD1H_AN30_UNSIGNED        0b0000000000000000      // In differential mode AN30 output will be unsigned
#define REG_ADMOD1H_AN31_SIGNED          0b0100000000000000      // In differential mode AN31 output will be signed
#define REG_ADMOD1H_AN31_UNSIGNED        0b0000000000000000      // In differential mode AN31 output will be unsigned

#endif

// REGISTER 19-22: ADIEL: ADC INTERRUPT ENABLE REGISTER LOW

#define REG_ADIEL_RESET                 0b0000000000000000      // Reset ADIEL Low Register
#define REG_ADIEL_VALID_DATA_MSK		0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADIEL_AN0_ON                0b0000000000000001      // Interrupt enabled for AN0 
#define REG_ADIEL_AN0_OFF               0b0000000000000000      // Interrupt disabled for AN0 
#define REG_ADIEL_AN1_ON                0b0000000000000010      // Interrupt enabled for AN1
#define REG_ADIEL_AN1_OFF               0b0000000000000000      // Interrupt disabled for AN1 
#define REG_ADIEL_AN2_ON                0b0000000000000100      // Interrupt enabled for AN2
#define REG_ADIEL_AN2_OFF               0b0000000000000000      // Interrupt disabled for AN2 
#define REG_ADIEL_AN3_ON                0b0000000000001000      // Interrupt enabled for AN3
#define REG_ADIEL_AN3_OFF               0b0000000000000000      // Interrupt disabled for AN3 
#define REG_ADIEL_AN4_ON                0b0000000000010000      // Interrupt enabled for AN4
#define REG_ADIEL_AN4_OFF               0b0000000000000000      // Interrupt disabled for AN4 
#define REG_ADIEL_AN5_ON                0b0000000000100000      // Interrupt enabled for AN5
#define REG_ADIEL_AN5_OFF               0b0000000000000000      // Interrupt disabled for AN5 
#define REG_ADIEL_AN6_ON                0b0000000001000000      // Interrupt enabled for AN6
#define REG_ADIEL_AN6_OFF               0b0000000000000000      // Interrupt disabled for AN6 
#define REG_ADIEL_AN7_ON                0b0000000010000000      // Interrupt enabled for AN7
#define REG_ADIEL_AN7_OFF               0b0000000000000000      // Interrupt disabled for AN7 
#define REG_ADIEL_AN8_ON                0b0000000100000000      // Interrupt enabled for AN8
#define REG_ADIEL_AN8_OFF               0b0000000000000000      // Interrupt disabled for AN8 
#define REG_ADIEL_AN9_ON                0b0000001000000000      // Interrupt enabled for AN9
#define REG_ADIEL_AN9_OFF               0b0000000000000000      // Interrupt disabled for AN9 
#define REG_ADIEL_AN10_ON               0b0000010000000000      // Interrupt enabled for AN10 
#define REG_ADIEL_AN10_OFF              0b0000000000000000      // Interrupt disabled for AN10 
#define REG_ADIEL_AN11_ON               0b0000100000000000      // Interrupt enabled for AN11
#define REG_ADIEL_AN11_OFF              0b0000000000000000      // Interrupt disabled for AN11 
#define REG_ADIEL_AN12_ON               0b0001000000000000      // Interrupt enabled for AN12
#define REG_ADIEL_AN12_OFF              0b0000000000000000      // Interrupt disabled for AN12 
#define REG_ADIEL_AN13_ON               0b0010000000000000      // Interrupt enabled for AN13
#define REG_ADIEL_AN13_OFF              0b0000000000000000      // Interrupt disabled for AN13 
#define REG_ADIEL_AN14_ON               0b0100000000000000      // Interrupt enabled for AN14
#define REG_ADIEL_AN14_OFF              0b0000000000000000      // Interrupt disabled for AN14 
#define REG_ADIEL_AN15_ON               0b1000000000000000      // Interrupt enabled for AN15
#define REG_ADIEL_AN15_OFF              0b0000000000000000      // Interrupt disabled for AN15


// REGISTER 19-23: ADIEH: ADC INTERRUPT ENABLE REGISTER HIGH

#define REG_ADIEH_RESET                 0b0000000000000000      // Reset ADIEH High Register
#define REG_ADIEH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADIEH_AN16_ON               0b0000000000000001      // Interrupt enabled for AN16
#define REG_ADIEH_AN16_OFF              0b0000000000000000      // Interrupt disabled for AN16 
#define REG_ADIEH_AN17_ON               0b0000000000000010      // Interrupt enabled for AN17
#define REG_ADIEH_AN17_OFF              0b0000000000000000      // Interrupt disabled for AN17 
#define REG_ADIEH_AN18_ON               0b0000000000000100      // Interrupt enabled for AN18
#define REG_ADIEH_AN18_OFF              0b0000000000000000      // Interrupt disabled for AN18 
#define REG_ADIEH_AN19_ON               0b0000000000001000      // Interrupt enabled for AN19
#define REG_ADIEH_AN19_OFF              0b0000000000000000      // Interrupt disabled for AN19 
#define REG_ADIEH_AN20_ON               0b0000000000010000      // Interrupt enabled for AN20
#define REG_ADIEH_AN20_OFF              0b0000000000000000      // Interrupt disabled for AN20 
#define REG_ADIEH_AN21_ON               0b0000000000100000      // Interrupt enabled for AN21
#define REG_ADIEH_AN21_OFF              0b0000000000000000      // Interrupt disabled for AN21 
#define REG_ADIEH_AN22_ON               0b0000000001000000      // Interrupt enabled for AN22
#define REG_ADIEH_AN22_OFF              0b0000000000000000      // Interrupt disabled for AN22 
#define REG_ADIEH_AN23_ON               0b0000000010000000      // Interrupt enabled for AN23
#define REG_ADIEH_AN23_OFF              0b0000000000000000      // Interrupt disabled for AN23 
#define REG_ADIEH_AN24_ON               0b0000000100000000      // Interrupt enabled for AN24
#define REG_ADIEH_AN24_OFF              0b0000000000000000      // Interrupt disabled for AN24 
#define REG_ADIEH_AN25_ON               0b0000001000000000      // Interrupt enabled for AN25
#define REG_ADIEH_AN25_OFF              0b0000000000000000      // Interrupt disabled for AN25 
#define REG_ADIEH_AN26_ON               0b0000010000000000      // Interrupt enabled for AN26
#define REG_ADIEH_AN26_OFF              0b0000000000000000      // Interrupt disabled for AN26 
#define REG_ADIEH_AN27_ON               0b0000100000000000      // Interrupt enabled for AN27
#define REG_ADIEH_AN27_OFF              0b0000000000000000      // Interrupt disabled for AN27 
#define REG_ADIEH_AN28_ON               0b0001000000000000      // Interrupt enabled for AN28
#define REG_ADIEH_AN28_OFF              0b0000000000000000      // Interrupt disabled for AN28 
#define REG_ADIEH_AN29_ON               0b0010000000000000      // Interrupt enabled for AN29
#define REG_ADIEH_AN29_OFF              0b0000000000000000      // Interrupt disabled for AN29 
#define REG_ADIEH_AN30_ON               0b0100000000000000      // Interrupt enabled for AN30
#define REG_ADIEH_AN30_OFF              0b0000000000000000      // Interrupt disabled for AN30 
#define REG_ADIEH_AN31_ON               0b1000000000000000      // Interrupt enabled for AN31
#define REG_ADIEH_AN31_OFF              0b0000000000000000      // Interrupt disabled for AN31


typedef enum {
    ADIE_ANx_ON = 0b1,      // Interrupt Generation Enabled for ANx 
    ADIE_ANx_OFF = 0b0      // Interrupt Generation Disabled for ANx 
}ADIE_IE_e; 

typedef struct {
    volatile ADIE_IE_e AN0IE : 1; // Enable/Disable AN0 Interrupt Generation
    volatile ADIE_IE_e AN1IE : 1; // Enable/Disable AN1 Interrupt Generation
    volatile ADIE_IE_e AN2IE : 1; // Enable/Disable AN2 Interrupt Generation
    volatile ADIE_IE_e AN3IE : 1; // Enable/Disable AN3 Interrupt Generation
    volatile ADIE_IE_e AN4IE : 1; // Enable/Disable AN4 Interrupt Generation
    volatile ADIE_IE_e AN5IE : 1; // Enable/Disable AN5 Interrupt Generation
    volatile ADIE_IE_e AN6IE : 1; // Enable/Disable AN6 Interrupt Generation
    volatile ADIE_IE_e AN7IE : 1; // Enable/Disable AN7 Interrupt Generation
    #if (ADC_ANINPUT_COUNT > 7)
    volatile ADIE_IE_e AN8IE : 1; // Enable/Disable AN8 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 8)
    volatile ADIE_IE_e AN9IE : 1; // Enable/Disable AN9 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 9)
    volatile ADIE_IE_e AN10IE : 1; // Enable/Disable AN10 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 10)
    volatile ADIE_IE_e AN11IE : 1; // Enable/Disable AN11 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 11)
    volatile ADIE_IE_e AN12IE : 1; // Enable/Disable AN12 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 12)
    volatile ADIE_IE_e AN13IE : 1; // Enable/Disable AN13 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 13)
    volatile ADIE_IE_e AN14IE : 1; // Enable/Disable AN14 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif

    #if (ADC_ANINPUT_COUNT > 14)
    volatile ADIE_IE_e AN15IE : 1; // Enable/Disable AN15 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif

    #if (ADC_ANINPUT_COUNT > 15)
    volatile ADIE_IE_e AN16IE : 1; // Enable/Disable AN16 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    
    #if (ADC_ANINPUT_COUNT > 16)
    volatile ADIE_IE_e AN17IE : 1; // Enable/Disable AN17 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 17)
    volatile ADIE_IE_e AN18IE : 1; // Enable/Disable AN18 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 18)
    volatile ADIE_IE_e AN19IE : 1; // Enable/Disable AN19 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 19)
    volatile ADIE_IE_e AN20IE : 1; // Enable/Disable AN20 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 20)
    volatile ADIE_IE_e AN21IE : 1; // Enable/Disable AN21 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 21)
    volatile ADIE_IE_e AN22IE : 1; // Enable/Disable AN22 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 22)
    volatile ADIE_IE_e AN23IE : 1; // Enable/Disable AN23 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 23)
    volatile ADIE_IE_e AN24IE : 1; // Enable/Disable AN24 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 24)
    volatile ADIE_IE_e AN25IE : 1; // Enable/Disable AN25 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 25)
    volatile ADIE_IE_e AN26IE : 1; // Enable/Disable AN26 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 26)
    volatile ADIE_IE_e AN27IE : 1; // Enable/Disable AN27 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 27)
    volatile ADIE_IE_e AN28IE : 1; // Enable/Disable AN28 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 28)
    volatile ADIE_IE_e AN29IE : 1; // Enable/Disable AN29 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 29)
    volatile ADIE_IE_e AN30IE : 1; // Enable/Disable AN30 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif
    #if (ADC_ANINPUT_COUNT > 30)
    volatile ADIE_IE_e AN31IE : 1; // Enable/Disable AN31 Interrupt Generation
    #else
    volatile unsigned : 1; // reserved
    #endif

}__attribute__((packed))ADIE_t;

typedef union {
    volatile uint32_t value;
    volatile ADIE_t ADIE;
} REGBLK_ADIE_t;



// REGISTER 19-24: ADSTATL: ADC DATA READY STATUS REGISTER LOW

#define REG_ADSTATL_RESET               0b0000000000000000      // Reset ADSTATL Low Register
#define REG_ADSTATL_VALID_DATA_MSK		0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADSTATL_AN0_SET             0b0000000000000001      // DATA READY bit is set for AN0 
#define REG_ADSTATL_AN0_CLR             0b0000000000000000      // DATA READY bit is cleared for AN0 
#define REG_ADSTATL_AN1_SET             0b0000000000000010      // DATA READY bit is set AN1
#define REG_ADSTATL_AN1_CLR             0b0000000000000000      // DATA READY bit is cleared for AN1 
#define REG_ADSTATL_AN2_SET             0b0000000000000100      // DATA READY bit is set for AN2
#define REG_ADSTATL_AN2_CLR             0b0000000000000000      // DATA READY bit is cleared for AN2 
#define REG_ADSTATL_AN3_SET             0b0000000000001000      // DATA READY bit is set for AN3
#define REG_ADSTATL_AN3_CLR             0b0000000000000000      // DATA READY bit is cleared for AN3 
#define REG_ADSTATL_AN4_SET             0b0000000000010000      // DATA READY bit is set for AN4
#define REG_ADSTATL_AN4_CLR             0b0000000000000000      // DATA READY bit is cleared for AN4 
#define REG_ADSTATL_AN5_SET             0b0000000000100000      // DATA READY bit is set for AN5
#define REG_ADSTATL_AN5_CLR             0b0000000000000000      // DATA READY bit is cleared for AN5 
#define REG_ADSTATL_AN6_SET             0b0000000001000000      // DATA READY bit is set for AN6
#define REG_ADSTATL_AN6_CLR             0b0000000000000000      // DATA READY bit is cleared for AN6 
#define REG_ADSTATL_AN7_SET             0b0000000010000000      // DATA READY bit is set for AN7
#define REG_ADSTATL_AN7_CLR             0b0000000000000000      // DATA READY bit is cleared for AN7 
#define REG_ADSTATL_AN8_SET             0b0000000100000000      // DATA READY bit is set for AN8
#define REG_ADSTATL_AN8_CLR             0b0000000000000000      // DATA READY bit is cleared for AN8 
#define REG_ADSTATL_AN9_SET             0b0000001000000000      // DATA READY bit is set for AN9
#define REG_ADSTATL_AN9_CLR             0b0000000000000000      // DATA READY bit is cleared for AN9 
#define REG_ADSTATL_AN10_SET            0b0000010000000000      // DATA READY bit is set for AN10 
#define REG_ADSTATL_AN10_CLR            0b0000000000000000      // DATA READY bit is cleared for AN10 
#define REG_ADSTATL_AN11_SET            0b0000100000000000      // DATA READY bit is set for AN11
#define REG_ADSTATL_AN11_CLR            0b0000000000000000      // DATA READY bit is cleared for AN11 
#define REG_ADSTATL_AN12_SET            0b0001000000000000      // DATA READY bit is set for AN12
#define REG_ADSTATL_AN12_CLR            0b0000000000000000      // DATA READY bit is cleared for AN12 
#define REG_ADSTATL_AN13_SET            0b0010000000000000      // DATA READY bit is set for AN13
#define REG_ADSTATL_AN13_CLR            0b0000000000000000      // DATA READY bit is cleared for AN13 
#define REG_ADSTATL_AN14_SET            0b0100000000000000      // DATA READY bit is set for AN14
#define REG_ADSTATL_AN14_CLR            0b0000000000000000      // DATA READY bit is cleared for AN14 
#define REG_ADSTATL_AN15_SET            0b1000000000000000      // DATA READY bit is set for AN15
#define REG_ADSTATL_AN15_CLR            0b0000000000000000      // DATA READY bit is cleared for AN15


// REGISTER 19-25: ADSTATH: ADC DATA READY STATUS REGISTER HIGH

#define REG_ADSTATH_RESET               0b0000000000000000      // Reset ADLVLTRGH High Register
#define REG_ADSTATH_VALID_DATA_MSK		0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADSTATH_AN16_SET            0b0000000000000001      // DATA READY bit is set for AN16
#define REG_ADSTATH_AN16_CLR            0b0000000000000000      // DATA READY bit is cleared for AN16 
#define REG_ADSTATH_AN17_SET            0b0000000000000010      // DATA READY bit is set for AN17
#define REG_ADSTATH_AN17_CLR            0b0000000000000000      // DATA READY bit is cleared for AN17 
#define REG_ADSTATH_AN18_SET            0b0000000000000100      // DATA READY bit is set for AN18
#define REG_ADSTATH_AN18_CLR            0b0000000000000000      // DATA READY bit is cleared for AN18 
#define REG_ADSTATH_AN19_SET            0b0000000000001000      // DATA READY bit is set for AN19
#define REG_ADSTATH_AN19_CLR            0b0000000000000000      // DATA READY bit is cleared for AN19 
#define REG_ADSTATH_AN20_SET            0b0000000000010000      // DATA READY bit is set for AN20
#define REG_ADSTATH_AN20_CLR            0b0000000000000000      // DATA READY bit is cleared for AN20 
#define REG_ADSTATH_AN21_SET            0b0000000000100000      // DATA READY bit is set for AN21
#define REG_ADSTATH_AN21_CLR            0b0000000000000000      // DATA READY bit is cleared for AN21 
#define REG_ADSTATH_AN22_SET            0b0000000001000000      // DATA READY bit is set for AN22
#define REG_ADSTATH_AN22_CLR            0b0000000000000000      // DATA READY bit is cleared for AN22 
#define REG_ADSTATH_AN23_SET            0b0000000010000000      // DATA READY bit is set for AN23
#define REG_ADSTATH_AN23_CLR            0b0000000000000000      // DATA READY bit is cleared for AN23 
#define REG_ADSTATH_AN24_SET            0b0000000100000000      // DATA READY bit is set for AN24
#define REG_ADSTATH_AN24_CLR            0b0000000000000000      // DATA READY bit is cleared for AN24 
#define REG_ADSTATH_AN25_SET            0b0000001000000000      // DATA READY bit is set for AN25
#define REG_ADSTATH_AN25_CLR            0b0000000000000000      // DATA READY bit is cleared for AN25 
#define REG_ADSTATH_AN26_SET            0b0000010000000000      // DATA READY bit is set for AN26
#define REG_ADSTATH_AN26_CLR            0b0000000000000000      // DATA READY bit is cleared for AN26 
#define REG_ADSTATH_AN27_SET            0b0000100000000000      // DATA READY bit is set for AN27
#define REG_ADSTATH_AN27_CLR            0b0000000000000000      // DATA READY bit is cleared for AN27 
#define REG_ADSTATH_AN28_SET            0b0001000000000000      // DATA READY bit is set for AN28
#define REG_ADSTATH_AN28_CLR            0b0000000000000000      // DATA READY bit is cleared for AN28 
#define REG_ADSTATH_AN29_SET            0b0010000000000000      // DATA READY bit is set for AN29
#define REG_ADSTATH_AN29_CLR            0b0000000000000000      // DATA READY bit is cleared for AN29 
#define REG_ADSTATH_AN30_SET            0b0100000000000000      // DATA READY bit is set for AN30
#define REG_ADSTATH_AN30_CLR            0b0000000000000000      // DATA READY bit is cleared for AN30 
#define REG_ADSTATH_AN31_SET            0b1000000000000000      // DATA READY bit is set for AN31
#define REG_ADSTATH_AN31_CLR            0b0000000000000000      // DATA READY bit is cleared for AN31


// REGISTER 19-26: ADTRGxH: ADC CHANNEL x TRIGGER SELECTION REGISTER 

#define REG_ADTRIGx_VALID_DATA_MSK          0b0001111100011111 // =0x1F1F
#define REG_ADTRIGxH_VALID_DATA_MSK         0b0001111100000000 // =0x1F00


#define REG_ADTRIGxH_TRGSRC_ADTRG31         0b0001111100000000 // ADC Trigger #31 (PPS input))

#if defined (__P33SMPS_EP__)

#if defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

#define REG_ADTRIGxH_TRGSRC_PTG             0b0001111000000000 // PTG Trigger Output 12
#define REG_ADTRIGxH_TRGSRC_CLC2            0b0001010100000000 // CLC2 output
#define REG_ADTRIGxH_TRGSRC_CLC1            0b0000101100000000 // CLC1 output

#define REG_ADTRIGxH_TRGSRC_PWM6_CLTRG      0b0001110100000000 // PWM Generator 6 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM6_SEC        0b0001010000000000 // PWM Generator 6 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM6_PRIM       0b0000101000000000 // PWM Generator 6 primary trigger

#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

#define REG_ADTRIGxH_TRGSRC_OC2_TRG         0b0001011100000000 // Output Compare 2 trigger

#define REG_ADTRIGxH_TRGSRC_PWM5_CLTRG      0b0001110000000000 // PWM Generator 5 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM5_SEC        0b0001001100000000 // PWM Generator 5 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM5_PRIM       0b0000100100000000 // PWM Generator 5 primary trigger

#define REG_ADTRIGxH_TRGSRC_PWM4_CLTRG      0b0001101100000000 // PWM Generator 4 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM4_SEC        0b0001001000000000 // PWM Generator 4 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM4_PRIM       0b0000100000000000 // PWM Generator 4 primary trigger

#endif

#define REG_ADTRIGxH_TRGSRC_OC1_TRG         0b0001011000000000 // Output Compare 1 trigger

#define REG_ADTRIGxH_TRGSRC_TMR2_PER        0b0000110100000000 // Timer2 period match
#define REG_ADTRIGxH_TRGSRC_TMR1_PER        0b0000110000000000 // Timer1 period match

#define REG_ADTRIGxH_TRGSRC_PWM3_CLTRG      0b0001101000000000 // PWM Generator 3 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM3_SEC        0b0001000100000000 // PWM Generator 3 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM3_PRIM       0b0000011100000000 // PWM Generator 3 primary trigger

#define REG_ADTRIGxH_TRGSRC_PWM2_CLTRG      0b0001100100000000 // PWM Generator 2 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM2_SEC        0b0001000000000000 // PWM Generator 2 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM2_PRIM       0b0000011000000000 // PWM Generator 2 primary trigger

#define REG_ADTRIGxH_TRGSRC_PWM1_CLTRG      0b0001100000000000 // PWM Generator 1 current-limit trigger
#define REG_ADTRIGxH_TRGSRC_PWM1_SEC        0b0000111100000000 // PWM Generator 1 secondary trigger
#define REG_ADTRIGxH_TRGSRC_PWM1_PRIM       0b0000010100000000 // PWM Generator 1 primary trigger

#define REG_ADTRIGxH_TRGSRC_PWMSEV_SEC      0b0000111000000000 // PWM secondary Special Event Trigger
#define REG_ADTRIGxH_TRGSRC_PWMSEV_PRIM     0b0000010000000000 // PWM Special Event Trigger        

#elif defined (__P33SMPS_CH__)

#define REG_ADTRIGxH_TRGSRC_MSTR_PTG        0b0001111000000000 // Master PTG
#define REG_ADTRIGxH_TRGSRC_SLV_CLC1        0b0001110100000000 // Slave CLC1
#define REG_ADTRIGxH_TRGSRC_MSTR_CLC1       0b0001110000000000 // Master CLC1
#define REG_ADTRIGxH_TRGSRC_SLV_PWM8_TRIG2  0b0001101100000000 // Slave PWM8 Trigger 2
#define REG_ADTRIGxH_TRGSRC_SLV_PWM5_TRIG2  0b0001101000000000 // Slave PWM5 Trigger 2
#define REG_ADTRIGxH_TRGSRC_SLV_PWM3_TRIG2  0b0001100100000000 // Slave PWM3 Trigger 2
#define REG_ADTRIGxH_TRGSRC_SLV_PWM1_TRIG2  0b0001100000000000 // Slave PWM1 Trigger 2
#define REG_ADTRIGxH_TRGSRC_SCCP4_PWM       0b0001011100000000 // Master SCCP4 PWM interrupt
#define REG_ADTRIGxH_TRGSRC_SCCP3_PWM       0b0001011000000000 // Master SCCP3 PWM interrupt
#define REG_ADTRIGxH_TRGSRC_SCCP2_PWM       0b0001010100000000 // Master SCCP2 PWM interrupt
#define REG_ADTRIGxH_TRGSRC_SCCP1_PWM       0b0001010000000000 // Master SCCP1 PWM interrupt

#define REG_ADTRIGxH_TRGSRC_MSTR_PWM4_TRIG2 0b0000101100000000 // Master PWM4 Trigger 2
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM4_TRIG1 0b0000101000000000 // Master PWM4 Trigger 1
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM3_TRIG2 0b0000100100000000 // Master PWM3 Trigger 2
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM3_TRIG1 0b0000100000000000 // Master PWM3 Trigger 1
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM2_TRIG2 0b0000011100000000 // Master PWM2 Trigger 2
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM2_TRIG1 0b0000011000000000 // Master PWM2 Trigger 1
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM1_TRIG2 0b0000010100000000 // Master PWM1 Trigger 2
#define REG_ADTRIGxH_TRGSRC_MSTR_PWM1_TRIG1 0b0000010000000000 // Master PWM1 Trigger 1

#elif defined (__P33SMPS_CK__)

#define REG_ADTRIGxH_TRGSRC_PTG             0b0001111000000000 // PTG
#define REG_ADTRIGxH_TRGSRC_CLC2            0b0001110100000000 // CLC2
#define REG_ADTRIGxH_TRGSRC_CLC1            0b0001110000000000 // CLC1
#define REG_ADTRIGxH_TRGSRC_MCCP9           0b0001101100000000 // MCCP9
#define REG_ADTRIGxH_TRGSRC_SCCP7           0b0001101000000000 // SCCP7
#define REG_ADTRIGxH_TRGSRC_SCCP6           0b0001100100000000 // SCCP6
#define REG_ADTRIGxH_TRGSRC_SCCP5           0b0001100000000000 // SCCP5
#define REG_ADTRIGxH_TRGSRC_SCCP4           0b0001011100000000 // SCCP4
#define REG_ADTRIGxH_TRGSRC_SCCP3           0b0001011000000000 // SCCP3
#define REG_ADTRIGxH_TRGSRC_SCCP2           0b0001010100000000 // SCCP2
#define REG_ADTRIGxH_TRGSRC_SCCP1           0b0001010000000000 // SCCP1
#define REG_ADTRIGxH_TRGSRC_PWM8_TRIG2      0b0001001100000000 // PWM8 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM8_TRIG1      0b0001001000000000 // PWM8 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM7_TRIG2      0b0001000100000000 // PWM7 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM7_TRIG1      0b0001000000000000 // PWM7 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM6_TRIG2      0b0000111100000000 // PWM6 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM6_TRIG1      0b0000111000000000 // PWM6 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM5_TRIG2      0b0000110100000000 // PWM5 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM5_TRIG1      0b0000110000000000 // PWM5 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM4_TRIG2      0b0000101100000000 // PWM4 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM4_TRIG1      0b0000101000000000 // PWM4 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM3_TRIG2      0b0000100100000000 // PWM3 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM3_TRIG1      0b0000100000000000 // PWM3 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM2_TRIG2      0b0000011100000000 // PWM2 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM2_TRIG1      0b0000011000000000 // PWM2 Trigger 1
#define REG_ADTRIGxH_TRGSRC_PWM1_TRIG2      0b0000010100000000 // PWM1 Trigger 2
#define REG_ADTRIGxH_TRGSRC_PWM1_TRIG1      0b0000010000000000 // PWM1 Trigger 1

#endif

#define REG_ADTRIGxH_TRGSRC_LSWTRG          0b0000001000000000 // Level software trigger
#define REG_ADTRIGxH_TRGSRC_CSWTRG          0b0000000100000000 // Common Software Trigger
#define REG_ADTRIGxH_TRGSRC_NONE            0b0000000000000000 // No trigger is selected


// REGISTER 19-26: ADTRGxL: ADC CHANNEL x TRIGGER SELECTION REGISTER LOW

#define REG_ADTRIGxL_VALID_DATA_MSK         0b0000000000011111 // =0x001F


#define REG_ADTRIGxL_TRGSRC_ADTRG31         0b0000000000011111 // ADC Trigger #31 (PPS input))

#if defined (__P33SMPS_EP__)

#if defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

#define REG_ADTRIGxL_TRGSRC_PTG             0b0000000000011110 // PTG Trigger Output 12
#define REG_ADTRIGxL_TRGSRC_CLC2            0b0000000000010101 // CLC2 output
#define REG_ADTRIGxL_TRGSRC_CLC1            0b0000000000001011 // CLC1 output

#define REG_ADTRIGxL_TRGSRC_PWM6_CLTRG      0b0000000000011101 // PWM Generator 6 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM6_SEC        0b0000000000010100 // PWM Generator 6 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM6_PRIM       0b0000000000001010 // PWM Generator 6 primary trigger

#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

#define REG_ADTRIGxL_TRGSRC_OC2_TRG         0b0000000000010111 // Output Compare 2 trigger

#define REG_ADTRIGxL_TRGSRC_PWM5_CLTRG      0b0000000000011100 // PWM Generator 5 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM5_SEC        0b0000000000010011 // PWM Generator 5 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM5_PRIM       0b0000000000001001 // PWM Generator 5 primary trigger

#define REG_ADTRIGxL_TRGSRC_PWM4_CLTRG      0b0000000000011011 // PWM Generator 4 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM4_SEC        0b0000000000010010 // PWM Generator 4 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM4_PRIM       0b0000000000001000 // PWM Generator 4 primary trigger

#endif

#define REG_ADTRIGxL_TRGSRC_OC1_TRG         0b0000000000010110 // Output Compare 1 trigger

#define REG_ADTRIGxL_TRGSRC_TMR2_PER        0b0000000000001101 // Timer2 period match
#define REG_ADTRIGxL_TRGSRC_TMR1_PER        0b0000000000001100 // Timer1 period match

#define REG_ADTRIGxL_TRGSRC_PWM3_CLTRG      0b0000000000011010 // PWM Generator 3 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM3_SEC        0b0000000000010001 // PWM Generator 3 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM3_PRIM       0b0000000000000111 // PWM Generator 3 primary trigger

#define REG_ADTRIGxL_TRGSRC_PWM2_CLTRG      0b0000000000011001 // PWM Generator 2 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM2_SEC        0b0000000000010000 // PWM Generator 2 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM2_PRIM       0b0000000000000110 // PWM Generator 2 primary trigger

#define REG_ADTRIGxL_TRGSRC_PWM1_CLTRG      0b0000000000011000 // PWM Generator 1 current-limit trigger
#define REG_ADTRIGxL_TRGSRC_PWM1_SEC        0b0000000000001111 // PWM Generator 1 secondary trigger
#define REG_ADTRIGxL_TRGSRC_PWM1_PRIM       0b0000000000000101 // PWM Generator 1 primary trigger

#define REG_ADTRIGxL_TRGSRC_PWMSEV_SEC      0b0000000000001110 // PWM secondary Special Event Trigger
#define REG_ADTRIGxL_TRGSRC_PWMSEV_PRIM     0b0000000000000100 // PWM Special Event Trigger        

#elif defined (__P33SMPS_CH__)

#define REG_ADTRIGxL_TRGSRC_MSTR_PTG        0b0000000000011110 // Master PTG
#define REG_ADTRIGxL_TRGSRC_SLV_CLC1        0b0000000000011101 // Slave CLC1
#define REG_ADTRIGxL_TRGSRC_MSTR_CLC1       0b0000000000011100 // Master CLC1
#define REG_ADTRIGxL_TRGSRC_SLV_PWM8_TRIG2  0b0000000000011011 // Slave PWM8 Trigger 2
#define REG_ADTRIGxL_TRGSRC_SLV_PWM5_TRIG2  0b0000000000011010 // Slave PWM5 Trigger 2
#define REG_ADTRIGxL_TRGSRC_SLV_PWM3_TRIG2  0b0000000000011001 // Slave PWM3 Trigger 2
#define REG_ADTRIGxL_TRGSRC_SLV_PWM1_TRIG2  0b0000000000011000 // Slave PWM1 Trigger 2
#define REG_ADTRIGxL_TRGSRC_SCCP4_PWM       0b0000000000010111 // Master SCCP4 PWM interrupt
#define REG_ADTRIGxL_TRGSRC_SCCP3_PWM       0b0000000000010110 // Master SCCP3 PWM interrupt
#define REG_ADTRIGxL_TRGSRC_SCCP2_PWM       0b0000000000010101 // Master SCCP2 PWM interrupt
#define REG_ADTRIGxL_TRGSRC_SCCP1_PWM       0b0000000000010100 // Master SCCP1 PWM interrupt

#define REG_ADTRIGxL_TRGSRC_MSTR_PWM4_TRIG2 0b0000000000001011 // Master PWM4 Trigger 2
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM4_TRIG1 0b0000000000001010 // Master PWM4 Trigger 1
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM3_TRIG2 0b0000000000001001 // Master PWM3 Trigger 2
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM3_TRIG1 0b0000000000001000 // Master PWM3 Trigger 1
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM2_TRIG2 0b0000000000000111 // Master PWM2 Trigger 2
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM2_TRIG1 0b0000000000000110 // Master PWM2 Trigger 1
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM1_TRIG2 0b0000000000000101 // Master PWM1 Trigger 2
#define REG_ADTRIGxL_TRGSRC_MSTR_PWM1_TRIG1 0b0000000000000100 // Master PWM1 Trigger 1

#elif defined (__P33SMPS_CK__)

#define REG_ADTRIGxL_TRGSRC_PTG             0b0000000000011110 // PTG
#define REG_ADTRIGxL_TRGSRC_CLC2            0b0000000000011101 // CLC2
#define REG_ADTRIGxL_TRGSRC_CLC1            0b0000000000011100 // CLC1
#define REG_ADTRIGxL_TRGSRC_MCCP9           0b0000000000011011 // MCCP9
#define REG_ADTRIGxL_TRGSRC_SCCP7           0b0000000000011010 // SCCP7
#define REG_ADTRIGxL_TRGSRC_SCCP6           0b0000000000011001 // SCCP6
#define REG_ADTRIGxL_TRGSRC_SCCP5           0b0000000000011000 // SCCP5
#define REG_ADTRIGxL_TRGSRC_SCCP4           0b0000000000010111 // SCCP4
#define REG_ADTRIGxL_TRGSRC_SCCP3           0b0000000000010110 // SCCP3
#define REG_ADTRIGxL_TRGSRC_SCCP2           0b0000000000010101 // SCCP2
#define REG_ADTRIGxL_TRGSRC_SCCP1           0b0000000000010100 // SCCP1
#define REG_ADTRIGxL_TRGSRC_PWM8_TRIG2      0b0000000000010011 // PWM8 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM8_TRIG1      0b0000000000010010 // PWM8 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM7_TRIG2      0b0000000000010001 // PWM7 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM7_TRIG1      0b0000000000010000 // PWM7 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM6_TRIG2      0b0000000000001111 // PWM6 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM6_TRIG1      0b0000000000001110 // PWM6 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM5_TRIG2      0b0000000000001101 // PWM5 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM5_TRIG1      0b0000000000001100 // PWM5 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM4_TRIG2      0b0000000000001011 // PWM4 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM4_TRIG1      0b0000000000001010 // PWM4 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM3_TRIG2      0b0000000000001001 // PWM3 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM3_TRIG1      0b0000000000001000 // PWM3 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM2_TRIG2      0b0000000000000111 // PWM2 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM2_TRIG1      0b0000000000000110 // PWM2 Trigger 1
#define REG_ADTRIGxL_TRGSRC_PWM1_TRIG2      0b0000000000000101 // PWM1 Trigger 2
#define REG_ADTRIGxL_TRGSRC_PWM1_TRIG1      0b0000000000000100 // PWM1 Trigger 1

#endif

#define REG_ADTRIGxL_TRGSRC_LSWTRG          0b0000000000000010 // Level software trigger
#define REG_ADTRIGxL_TRGSRC_CSWTRG          0b0000000000000001 // Common Software Trigger
#define REG_ADTRIGxL_TRGSRC_NONE            0b0000000000000000 // No trigger is selected

typedef enum {
    ADTRIGx_TRGSRC_ADTRG31 = 0b11111, // ADC Trigger #31 (PPS input))

#if defined (__P33SMPS_EP__)

#if defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

    ADTRIGx_TRGSRC_PTG = 0b11110, // PTG Trigger Output 12
    ADTRIGx_TRGSRC_CLC2 = 0b10101, // CLC2 output
    ADTRIGx_TRGSRC_CLC1 = 0b01011, // CLC1 output

    ADTRIGx_TRGSRC_PWM6_CLTRG = 0b11101, // PWM Generator 6 current-limit trigger
    ADTRIGx_TRGSRC_PWM6_SEC = 0b10100, // PWM Generator 6 secondary trigger
    ADTRIGx_TRGSRC_PWM6_PRIM = 0b01010, // PWM Generator 6 primary trigger

#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__) || defined (__P33SMPS_EP8__)

    ADTRIGx_TRGSRC_OC2_TRG = 0b10111, // Output Compare 2 trigger

    ADTRIGx_TRGSRC_PWM5_CLTRG = 0b11100, // PWM Generator 5 current-limit trigger
    ADTRIGx_TRGSRC_PWM5_SEC = 0b10011, // PWM Generator 5 secondary trigger
    ADTRIGx_TRGSRC_PWM5_PRIM = 0b01001, // PWM Generator 5 primary trigger

    ADTRIGx_TRGSRC_PWM4_CLTRG = 0b11011, // PWM Generator 4 current-limit trigger
    ADTRIGx_TRGSRC_PWM4_SEC = 0b10010, // PWM Generator 4 secondary trigger
    ADTRIGx_TRGSRC_PWM4_PRIM = 0b01000, // PWM Generator 4 primary trigger

#endif

    ADTRIGx_TRGSRC_OC1_TRG = 0b10110, // Output Compare 1 trigger

    ADTRIGx_TRGSRC_TMR2_PER = 0b01101, // Timer2 period match
    ADTRIGx_TRGSRC_TMR1_PER = 0b01100, // Timer1 period match

    ADTRIGx_TRGSRC_PWM3_CLTRG = 0b11010, // PWM Generator 3 current-limit trigger
    ADTRIGx_TRGSRC_PWM3_SEC = 0b10001, // PWM Generator 3 secondary trigger
    ADTRIGx_TRGSRC_PWM3_PRIM = 0b00111, // PWM Generator 3 primary trigger

    ADTRIGx_TRGSRC_PWM2_CLTRG = 0b11001, // PWM Generator 2 current-limit trigger
    ADTRIGx_TRGSRC_PWM2_SEC = 0b10000, // PWM Generator 2 secondary trigger
    ADTRIGx_TRGSRC_PWM2_PRIM = 0b00110, // PWM Generator 2 primary trigger

    ADTRIGx_TRGSRC_PWM1_CLTRG = 0b11000, // PWM Generator 1 current-limit trigger
    ADTRIGx_TRGSRC_PWM1_SEC = 0b01111, // PWM Generator 1 secondary trigger
    ADTRIGx_TRGSRC_PWM1_PRIM = 0b00101, // PWM Generator 1 primary trigger

    ADTRIGx_TRGSRC_PWMSEV_SEC = 0b01110, // PWM secondary Special Event Trigger
    ADTRIGx_TRGSRC_PWMSEV_PRIM = 0b00100, // PWM Special Event Trigger        

#elif defined (__P33SMPS_CH__)

    ADTRIGx_TRGSRC_MSTR_PTG = 0b11110, // Master PTG
    ADTRIGx_TRGSRC_SLV_CLC1 = 0b11101, // Slave CLC1
    ADTRIGx_TRGSRC_MSTR_CLC1 = 0b11100, // Master CLC1
    ADTRIGx_TRGSRC_SLV_PWM8_TRIG2 = 0b11011, // Slave PWM8 Trigger 2
    ADTRIGx_TRGSRC_SLV_PWM5_TRIG2 = 0b11010, // Slave PWM5 Trigger 2
    ADTRIGx_TRGSRC_SLV_PWM3_TRIG2 = 0b11001, // Slave PWM3 Trigger 2
    ADTRIGx_TRGSRC_SLV_PWM1_TRIG2 = 0b11000, // Slave PWM1 Trigger 2
    ADTRIGx_TRGSRC_SCCP4_PWM = 0b10111, // Master SCCP4 PWM interrupt
    ADTRIGx_TRGSRC_SCCP3_PWM = 0b10110, // Master SCCP3 PWM interrupt
    ADTRIGx_TRGSRC_SCCP2_PWM = 0b10101, // Master SCCP2 PWM interrupt
    ADTRIGx_TRGSRC_SCCP1_PWM = 0b10100, // Master SCCP1 PWM interrupt

    ADTRIGx_TRGSRC_MSTR_PWM4_TRIG2 = 0b01011, // Master PWM4 Trigger 2
    ADTRIGx_TRGSRC_MSTR_PWM4_TRIG1 = 0b01010, // Master PWM4 Trigger 1
    ADTRIGx_TRGSRC_MSTR_PWM3_TRIG2 = 0b01001, // Master PWM3 Trigger 2
    ADTRIGx_TRGSRC_MSTR_PWM3_TRIG1 = 0b01000, // Master PWM3 Trigger 1
    ADTRIGx_TRGSRC_MSTR_PWM2_TRIG2 = 0b00111, // Master PWM2 Trigger 2
    ADTRIGx_TRGSRC_MSTR_PWM2_TRIG1 = 0b00110, // Master PWM2 Trigger 1
    ADTRIGx_TRGSRC_MSTR_PWM1_TRIG2 = 0b00101, // Master PWM1 Trigger 2
    ADTRIGx_TRGSRC_MSTR_PWM1_TRIG1 = 0b00100, // Master PWM1 Trigger 1

#elif defined (__P33SMPS_CK__)

    ADTRIGx_TRGSRC_PTG = 0b11110, // PTG
    ADTRIGx_TRGSRC_CLC2 = 0b11101, // CLC2
    ADTRIGx_TRGSRC_CLC1 = 0b11100, // CLC1
    ADTRIGx_TRGSRC_MCCP9 = 0b11011, // MCCP9
    ADTRIGx_TRGSRC_SCCP7 = 0b11010, // SCCP7
    ADTRIGx_TRGSRC_SCCP6 = 0b11001, // SCCP6
    ADTRIGx_TRGSRC_SCCP5 = 0b11000, // SCCP5
    ADTRIGx_TRGSRC_SCCP4 = 0b10111, // SCCP4
    ADTRIGx_TRGSRC_SCCP3 = 0b10110, // SCCP3
    ADTRIGx_TRGSRC_SCCP2 = 0b10101, // SCCP2
    ADTRIGx_TRGSRC_SCCP1 = 0b10100, // SCCP1
    ADTRIGx_TRGSRC_PWM8_TRIG2 = 0b10011, // PWM8 Trigger 2
    ADTRIGx_TRGSRC_PWM8_TRIG1 = 0b10010, // PWM8 Trigger 1
    ADTRIGx_TRGSRC_PWM7_TRIG2 = 0b10001, // PWM7 Trigger 2
    ADTRIGx_TRGSRC_PWM7_TRIG1 = 0b10000, // PWM7 Trigger 1
    ADTRIGx_TRGSRC_PWM6_TRIG2 = 0b01111, // PWM6 Trigger 2
    ADTRIGx_TRGSRC_PWM6_TRIG1 = 0b01110, // PWM6 Trigger 1
    ADTRIGx_TRGSRC_PWM5_TRIG2 = 0b01101, // PWM5 Trigger 2
    ADTRIGx_TRGSRC_PWM5_TRIG1 = 0b01100, // PWM5 Trigger 1
    ADTRIGx_TRGSRC_PWM4_TRIG2 = 0b01011, // PWM4 Trigger 2
    ADTRIGx_TRGSRC_PWM4_TRIG1 = 0b01010, // PWM4 Trigger 1
    ADTRIGx_TRGSRC_PWM3_TRIG2 = 0b01001, // PWM3 Trigger 2
    ADTRIGx_TRGSRC_PWM3_TRIG1 = 0b01000, // PWM3 Trigger 1
    ADTRIGx_TRGSRC_PWM2_TRIG2 = 0b00111, // PWM2 Trigger 2
    ADTRIGx_TRGSRC_PWM2_TRIG1 = 0b00110, // PWM2 Trigger 1
    ADTRIGx_TRGSRC_PWM1_TRIG2 = 0b00101, // PWM1 Trigger 2
    ADTRIGx_TRGSRC_PWM1_TRIG1 = 0b00100, // PWM1 Trigger 1

#endif

    ADTRIGx_TRGSRC_LSWTRG = 0b00010, // Level software trigger
    ADTRIGx_TRGSRC_CSWTRG = 0b00001, // Common Software Trigger
    ADTRIGx_TRGSRC_NONE = 0b00000 // No trigger is selected

} ADTRIG_TRGSRC_e;


// REGISTER 19-27: ADCAL0L: ADC CALIBRATION REGISTER 0 LOW

#define REG_ADCAL0L_RESET               0b0000000000000000      // ADC core #0 & #1 calibration reset
#define REG_ADCAL0L_VALID_DATA_MSK		0b1000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL0L_CAL1RDY_DONE        0b1000000000000000      // ADC core #1 calibration completed
#define REG_ADCAL0L_CAL1RDY_PEND        0b0000000000000000      // ADC core #1 calibration pending

#define REG_ADCAL0L_CAL1SKIP_BYPASS     0b0000100000000000      // ADC core #1 calibration will be skipped
#define REG_ADCAL0L_CAL1SKIP_CALIB      0b0000000000000000      // ADC core #1 calibration will be performed

#define REG_ADCAL0L_CAL1DIFF_DIFF       0b0000010000000000      // ADC core #1 differential input calibration 
#define REG_ADCAL0L_CAL1DIFF_SNGM       0b0000000000000000      // ADC core #1 single ended input calibration 

#define REG_ADCAL0L_CAL1EN_UNLOCKED     0b0000001000000000      // ADC core #1 calibration bits accessable
#define REG_ADCAL0L_CAL1EN_LOCKED       0b0000000000000000      // ADC core #1 calibration bits blocked 

#define REG_ADCAL0L_CAL1RUN_EXECUTE     0b0000000100000000      // ADC core #1 execute calibration 
#define REG_ADCAL0L_CAL1RUN_READY       0b0000000000000000      // ADC core #1 ready for calibration 

#define REG_ADCAL0L_CAL0RDY_DONE        0b0000000010000000      // ADC core #0 calibration completed
#define REG_ADCAL0L_CAL0RDY_PEND        0b0000000000000000      // ADC core #0 calibration pending

#define REG_ADCAL0L_CAL0SKIP_BYPASS     0b0000000000001000      // ADC core #0 calibration will be skipped
#define REG_ADCAL0L_CAL0SKIP_CALIB      0b0000000000000000      // ADC core #0 calibration will be performed

#define REG_ADCAL0L_CAL0DIFF_DIFF       0b0000000000000100      // ADC core #0 differential input calibration 
#define REG_ADCAL0L_CAL0DIFF_SNGM       0b0000000000000000      // ADC core #0 single ended input calibration 

#define REG_ADCAL0L_CAL0EN_UNLOCKED     0b0000000000000010      // ADC core #0 calibration bits accessable
#define REG_ADCAL0L_CAL0EN_LOCKED       0b0000000000000000      // ADC core #0 calibration bits blocked 

#define REG_ADCAL0L_CAL0RUN_EXECUTE     0b0000000000000001      // ADC core #0 execute calibration 
#define REG_ADCAL0L_CAL0RUN_READY       0b0000000000000000      // ADC core #0 ready for calibration 


// REGISTER 19-28: ADCAL0H: ADC CALIBRATION REGISTER 0 HIGH
#define REG_ADCAL0H_RESET               0b0000000000000000      // ADC core #2 & #3 calibration reset
#define REG_ADCAL0H_VALID_DATA_MSK		0b1000111110001111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL0H_CAL3RDY_DONE        0b1000000000000000      // ADC core #3 calibration completed
#define REG_ADCAL0H_CAL3RDY_PEND        0b0000000000000000      // ADC core #3 calibration pending

#define REG_ADCAL0H_CAL3SKIP_BYPASS     0b0000100000000000      // ADC core #3 calibration will be skipped
#define REG_ADCAL0H_CAL3SKIP_CALIB      0b0000000000000000      // ADC core #3 calibration will be performed

#define REG_ADCAL0H_CAL3DIFF_DIFF       0b0000010000000000      // ADC core #3 differential input calibration 
#define REG_ADCAL0H_CAL3DIFF_SNGM       0b0000000000000000      // ADC core #3 single ended input calibration 

#define REG_ADCAL0H_CAL3EN_UNLOCKED     0b0000001000000000      // ADC core #3 calibration bits accessable
#define REG_ADCAL0H_CAL3EN_LOCKED       0b0000000000000000      // ADC core #3 calibration bits blocked 

#define REG_ADCAL0H_CAL3RUN_EXECUTE     0b0000000100000000      // ADC core #3 execute calibration 
#define REG_ADCAL0H_CAL3RUN_READY       0b0000000000000000      // ADC core #3 ready for calibration 

#define REG_ADCAL0H_CAL2RDY_DONE        0b0000000010000000      // ADC core #2 calibration completed
#define REG_ADCAL0H_CAL2RDY_PEND        0b0000000000000000      // ADC core #2 calibration pending

#define REG_ADCAL0H_CAL2SKIP_BYPASS     0b0000000000001000      // ADC core #2 calibration will be skipped
#define REG_ADCAL0H_CAL2SKIP_CALIB      0b0000000000000000      // ADC core #2 calibration will be performed

#define REG_ADCAL0H_CAL2DIFF_DIFF       0b0000000000000100      // ADC core #2 differential input calibration 
#define REG_ADCAL0H_CAL2DIFF_SNGM       0b0000000000000000      // ADC core #2 single ended input calibration 

#define REG_ADCAL0H_CAL2EN_UNLOCKED     0b0000000000000010      // ADC core #2 calibration bits accessable
#define REG_ADCAL0H_CAL2EN_LOCKED       0b0000000000000000      // ADC core #2 calibration bits blocked 

#define REG_ADCAL0H_CAL2RUN_EXECUTE     0b0000000000000001      // ADC core #2 execute calibration 
#define REG_ADCAL0H_CAL2RUN_READY       0b0000000000000000      // ADC core #2 ready for calibration 


// REGISTER 19-29: ADCAL1H: ADC CALIBRATION REGISTER 1 HIGH
#define REG_ADCAL1H_RESET               0b0000000000000000      // ADC shared core calibration reset
#define REG_ADCAL1H_VALID_DATA_MSK		0b1000111100000000		// Bit mask used to set unimplemented bits to zero

#define REG_ADCAL1H_CSHRRDY_DONE        0b1000000000000000      // ADC shared core calibration completed
#define REG_ADCAL1H_CSHRRDY_PEND        0b0000000000000000      // ADC shared core calibration pending

#define REG_ADCAL1H_CSHRSKIP_BYPASS     0b0000100000000000      // ADC shared core calibration will be skipped
#define REG_ADCAL1H_CSHRSKIP_CALIB      0b0000000000000000      // ADC shared core calibration will be performed

#define REG_ADCAL1H_CSHRDIFF_DIFF       0b0000010000000000      // ADC shared core differential input calibration 
#define REG_ADCAL1H_CSHRDIFF_SNGM       0b0000000000000000      // ADC shared core single ended input calibration 

#define REG_ADCAL1H_CSHREN_UNLOCKED     0b0000001000000000      // ADC shared core calibration bits accessable
#define REG_ADCAL1H_CSHREN_LOCKED       0b0000000000000000      // ADC shared core calibration bits blocked 

#define REG_ADCAL1H_CSHRRUN_EXECUTE     0b0000000100000000      // ADC shared core execute calibration 
#define REG_ADCAL1H_CSHRRUN_READY       0b0000000000000000      // ADC shared core ready for calibration 


// EXTENSION TO REGISTERS 19-27/28/29: ADCAL0L/ADCAL0H/ADCAL1L: ADC CALIBRATION REGISTERS
#define REG_ADCALx_LB_VALID_DATA_MSK	 0b0000000010001111		// Low Byte Bit mask used to set unimplemented bits to zero
#define REG_ADCALx_VALID_DATA_MSK		 0b1000111110001111		// Word Bit mask used to set unimplemented bits to zero

#define REG_ADC_CALIB_MODE_SINGLE_ENDED  0b1000101110001011 // Single Ended Mode Calibration
#define REG_ADC_CALIB_MODE_DIFFERENTIAL  0b1000111110001111 // Differenial Mode Calibration

#define REG_ADCALx_LB_CALxRDY_SET_MSK    0b0000000010000000
#define REG_ADCALx_LB_CALxRDY_CLR_MSK   (0b1111111101111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxSKIP_SET_MSK   0b0000000000001000
#define REG_ADCALx_LB_CALxSKIP_CLR_MSK  (0b1111111111110111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxDIFF_SET_MSK   0b0000000000000100
#define REG_ADCALx_LB_CALxDIFF_CLR_MSK  (0b1111111111111011 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxEN_SET_MSK     0b0000000000000010
#define REG_ADCALx_LB_CALxEN_CLR_MSK    (0b1111111111111101 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_LB_CALxRUN_SET_MSK    0b0000000000000001
#define REG_ADCALx_LB_CALxRUN_CLR_MSK   (0b1111111111111110 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_VALID_DATA_MSK	 0b1000111100000000		// High Byte Bit mask used to set unimplemented bits to zero

#define REG_ADCALx_HB_CALxRDY_SET_MSK    0b1000000000000000
#define REG_ADCALx_HB_CALxRDY_CLR_MSK   (0b0111111111111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxSKIP_SET_MSK   0b0000100000000000
#define REG_ADCALx_HB_CALxSKIP_CLR_MSK  (0b1111011111111111  & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxDIFF_SET_MSK   0b0000010000000000
#define REG_ADCALx_HB_CALxDIFF_CLR_MSK  (0b1111101111111111 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxEN_SET_MSK     0b0000001000000000
#define REG_ADCALx_HB_CALxEN_CLR_MSK    (0b1111110111111111 & REG_ADCALx_VALID_DATA_MSK)

#define REG_ADCALx_HB_CALxRUN_SET_MSK    0b0000000100000000
#define REG_ADCALx_HB_CALxRUN_CLR_MSK   (0b1111111011111111 & REG_ADCALx_VALID_DATA_MSK)


// REGISTER 19-30: ADCMPxCON: ADC DIGITAL COMPARATOR x CONTROL REGISTER

#define REG_ADCMPxCON_RESET             0b0000000000000000      // ADC Digital Comparator Configuration Reset
#define REG_ADCMPxCON_VALID_DATA_RD_MSK	0b0001111111111111		// Bit mask used to set unimplemented bits to zero
#define REG_ADCMPxCON_VALID_DATA_WR_MSK	0b0000000011011111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxLO_RESET              0b0000000000000000      // ADC Digital Comparator Lower Compare Value Reset
#define REG_ADCMPxLO_VALID_DATA_MASK    0b1111111111111111      // Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxHI_RESET              0b0000000000000000      // ADC Digital Comparator Upper Compare Value Reset
#define REG_ADCMPxHI_VALID_DATA_MASK    0b1111111111111111      // Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxCON_CHNL_MSK			0b0001111100000000		// ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL(x)        ((x << 8) & REG_ADCMPxCON_CHNL_MSK)    // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_NO(x)     ((x & REG_ADCMPxCON_CHNL_MSK) >> 8)    // Macro to extract the active ANx input channel no

#define REG_ADCMPxCON_CHNL_AN31         0b0001111100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN30         0b0001111000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN29         0b0001110100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN28         0b0001110000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN27         0b0001101100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN26         0b0001101000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN25         0b0001100100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN24         0b0001100000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN23         0b0001011100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN22         0b0001011000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN21         0b0001010100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN20         0b0001010000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN19         0b0001001100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN18         0b0001001000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN17         0b0001000100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN16         0b0001000000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN15         0b0000111100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN14         0b0000111000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN13         0b0000110100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN12         0b0000110000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN11         0b0000101100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN10         0b0000101000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN9          0b0000100100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN8          0b0000100000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN7          0b0000011100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN6          0b0000011000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN5          0b0000010100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN4          0b0000010000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN3          0b0000001100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN2          0b0000001000000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN1          0b0000000100000000      // ADC Input Number used for comparison
#define REG_ADCMPxCON_CHNL_AN0          0b0000000000000000      // ADC Input Number used for comparison

#define REG_ADCMPxCON_CMPEN_ON          0b0000000010000000      // ADC Digital Comparator Enabled
#define REG_ADCMPxCON_CMPEN_OFF         0b0000000000000000      // ADC Digital Comparator Disabled

#define REG_ADCMPxCON_IE_ON             0b0000000001000000      // ADC Digital Comparator Common Interrupt Enabled
#define REG_ADCMPxCON_IE_OFF            0b0000000000000000      // ADC Digital Comparator Common Interrupt Disabled

#define REG_ADCMPxCON_STAT_ACTIVE       0b0000000000100000      // ADC Digital Comparator Common Interrupt Active
#define REG_ADCMPxCON_STAT_READY        0b0000000000000000      // ADC Digital Comparator Common Interrupt Pending

#define REG_ADCMPxCON_BTWN_ON           0b0000000000010000      // Generate Interrupt when ADC buffer between min & max
#define REG_ADCMPxCON_BTWN_OFF          0b0000000000000000      // No Interrupt when ADC buffer between min & max

#define REG_ADCMPxCON_HIHI_ON           0b0000000000001000      // Generate Interrupt when ADC buffer >= max
#define REG_ADCMPxCON_HIHI_OFF          0b0000000000000000      // No Interrupt when ADC buffer >= max

#define REG_ADCMPxCON_HILO_ON           0b0000000000000100      // Generate Interrupt when ADC buffer < min
#define REG_ADCMPxCON_HILO_OFF          0b0000000000000000      // No Interrupt when ADC buffer < min

#define REG_ADCMPxCON_LOHI_ON           0b0000000000000010      // Generate Interrupt when ADC buffer > min
#define REG_ADCMPxCON_LOHI_OFF          0b0000000000000000      // No Interrupt when ADC buffer > min

#define REG_ADCMPxCON_LOLO_ON           0b0000000000000001      // Generate Interrupt when ADC buffer < min
#define REG_ADCMPxCON_LOLO_OFF          0b0000000000000000      // No Interrupt when ADC buffer < min

// REGISTER 19-31: ADCMPxENL: ADC DIGITAL COMPARATOR x CHANNEL ENABLE REGISTER LOW

#define REG_ADCMPxENL_RESET             0b0000000000000000      // Reset ADCMPxENL Register
#define REG_ADCMPxENL_VALID_DATA_MSK	0b1111111111111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxENL_AN0_ON            0b0000000000000001      // Interrupt enabled for AN0 
#define REG_ADCMPxENL_AN0_OFF           0b0000000000000000      // Interrupt disabled for AN0 
#define REG_ADCMPxENL_AN1_ON            0b0000000000000010      // Interrupt enabled for AN1
#define REG_ADCMPxENL_AN1_OFF           0b0000000000000000      // Interrupt disabled for AN1 
#define REG_ADCMPxENL_AN2_ON            0b0000000000000100      // Interrupt enabled for AN2
#define REG_ADCMPxENL_AN2_OFF           0b0000000000000000      // Interrupt disabled for AN2 
#define REG_ADCMPxENL_AN3_ON            0b0000000000001000      // Interrupt enabled for AN3
#define REG_ADCMPxENL_AN3_OFF           0b0000000000000000      // Interrupt disabled for AN3 
#define REG_ADCMPxENL_AN4_ON            0b0000000000010000      // Interrupt enabled for AN4
#define REG_ADCMPxENL_AN4_OFF           0b0000000000000000      // Interrupt disabled for AN4 
#define REG_ADCMPxENL_AN5_ON            0b0000000000100000      // Interrupt enabled for AN5
#define REG_ADCMPxENL_AN5_OFF           0b0000000000000000      // Interrupt disabled for AN5 
#define REG_ADCMPxENL_AN6_ON            0b0000000001000000      // Interrupt enabled for AN6
#define REG_ADCMPxENL_AN6_OFF           0b0000000000000000      // Interrupt disabled for AN6 
#define REG_ADCMPxENL_AN7_ON            0b0000000010000000      // Interrupt enabled for AN7
#define REG_ADCMPxENL_AN7_OFF           0b0000000000000000      // Interrupt disabled for AN7 
#define REG_ADCMPxENL_AN8_ON            0b0000000100000000      // Interrupt enabled for AN8
#define REG_ADCMPxENL_AN8_OFF           0b0000000000000000      // Interrupt disabled for AN8 
#define REG_ADCMPxENL_AN9_ON            0b0000001000000000      // Interrupt enabled for AN9
#define REG_ADCMPxENL_AN9_OFF           0b0000000000000000      // Interrupt disabled for AN9 
#define REG_ADCMPxENL_AN10_ON           0b0000010000000000      // Interrupt enabled for AN10 
#define REG_ADCMPxENL_AN10_OFF          0b0000000000000000      // Interrupt disabled for AN10 
#define REG_ADCMPxENL_AN11_ON           0b0000100000000000      // Interrupt enabled for AN11
#define REG_ADCMPxENL_AN11_OFF          0b0000000000000000      // Interrupt disabled for AN11 
#define REG_ADCMPxENL_AN12_ON           0b0001000000000000      // Interrupt enabled for AN12
#define REG_ADCMPxENL_AN12_OFF          0b0000000000000000      // Interrupt disabled for AN12 
#define REG_ADCMPxENL_AN13_ON           0b0010000000000000      // Interrupt enabled for AN13
#define REG_ADCMPxENL_AN13_OFF          0b0000000000000000      // Interrupt disabled for AN13 
#define REG_ADCMPxENL_AN14_ON           0b0100000000000000      // Interrupt enabled for AN14
#define REG_ADCMPxENL_AN14_OFF          0b0000000000000000      // Interrupt disabled for AN14 
#define REG_ADCMPxENL_AN15_ON           0b1000000000000000      // Interrupt enabled for AN15
#define REG_ADCMPxENL_AN15_OFF          0b0000000000000000      // Interrupt disabled for AN15

// REGISTER 19-32: ADCMPxENH: ADC DIGITAL COMPARATOR x CHANNEL ENABLE REGISTER HIGH

#define REG_ADCMPxENH_RESET             0b0000000000000000      // Reset ADCMPxENH High Register
#define REG_ADCMPxENH_VALID_DATA_MSK	0b0000000000111111		// Bit mask used to set unimplemented bits to zero

#define REG_ADCMPxENH_AN16_ON           0b0000000000000001      // Interrupt enabled for AN16
#define REG_ADCMPxENH_AN16_OFF          0b0000000000000000      // Interrupt disabled for AN16 
#define REG_ADCMPxENH_AN17_ON           0b0000000000000010      // Interrupt enabled for AN17
#define REG_ADCMPxENH_AN17_OFF          0b0000000000000000      // Interrupt disabled for AN17 
#define REG_ADCMPxENH_AN18_ON           0b0000000000000100      // Interrupt enabled for AN18
#define REG_ADCMPxENH_AN18_OFF          0b0000000000000000      // Interrupt disabled for AN18 
#define REG_ADCMPxENH_AN19_ON           0b0000000000001000      // Interrupt enabled for AN19
#define REG_ADCMPxENH_AN19_OFF          0b0000000000000000      // Interrupt disabled for AN19 
#define REG_ADCMPxENH_AN20_ON           0b0000000000010000      // Interrupt enabled for AN20
#define REG_ADCMPxENH_AN20_OFF          0b0000000000000000      // Interrupt disabled for AN20 
#define REG_ADCMPxENH_AN21_ON           0b0000000000100000      // Interrupt enabled for AN21
#define REG_ADCMPxENH_AN21_OFF          0b0000000000000000      // Interrupt disabled for AN21 
#define REG_ADCMPxENH_AN22_ON           0b0000000001000000      // Interrupt enabled for AN22
#define REG_ADCMPxENH_AN22_OFF          0b0000000000000000      // Interrupt disabled for AN22 
#define REG_ADCMPxENH_AN23_ON           0b0000000010000000      // Interrupt enabled for AN23
#define REG_ADCMPxENH_AN23_OFF          0b0000000000000000      // Interrupt disabled for AN23 
#define REG_ADCMPxENH_AN24_ON           0b0000000100000000      // Interrupt enabled for AN24
#define REG_ADCMPxENH_AN24_OFF          0b0000000000000000      // Interrupt disabled for AN24 
#define REG_ADCMPxENH_AN25_ON           0b0000001000000000      // Interrupt enabled for AN25
#define REG_ADCMPxENH_AN25_OFF          0b0000000000000000      // Interrupt disabled for AN25 
#define REG_ADCMPxENH_AN26_ON           0b0000010000000000      // Interrupt enabled for AN26
#define REG_ADCMPxENH_AN26_OFF          0b0000000000000000      // Interrupt disabled for AN26 
#define REG_ADCMPxENH_AN27_ON           0b0000100000000000      // Interrupt enabled for AN27
#define REG_ADCMPxENH_AN27_OFF          0b0000000000000000      // Interrupt disabled for AN27 
#define REG_ADCMPxENH_AN28_ON           0b0001000000000000      // Interrupt enabled for AN28
#define REG_ADCMPxENH_AN28_OFF          0b0000000000000000      // Interrupt disabled for AN28 
#define REG_ADCMPxENH_AN29_ON           0b0010000000000000      // Interrupt enabled for AN29
#define REG_ADCMPxENH_AN29_OFF          0b0000000000000000      // Interrupt disabled for AN29 
#define REG_ADCMPxENH_AN30_ON           0b0100000000000000      // Interrupt enabled for AN30
#define REG_ADCMPxENH_AN30_OFF          0b0000000000000000      // Interrupt disabled for AN30 
#define REG_ADCMPxENH_AN31_ON           0b1000000000000000      // Interrupt enabled for AN31
#define REG_ADCMPxENH_AN31_OFF          0b0000000000000000      // Interrupt disabled for AN31


// REGISTER 19-33: ADFLxCON: ADC DIGITAL FILTER x CONTROL REGISTER

#define REG_ADFLxCON_RESET                  0b0000000000000000      // Reset ADFLxCON Register
#define REG_ADFLxCON_VALID_DATA_MSK			0b1111111100011111		// Bit mask used to set unimplemented bits to zero

#define REG_ADFLxCON_FLEN_ON                0b1000000000000000      // Digital filter enabled
#define REG_ADFLxCON_FLEN_OFF               0b0000000000000000      // Digital filter disabled

#define REG_ADFLxCON_MODE_LEFT_ALIGN_256X   0b0111110000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_128X   0b0111100000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_64X    0b0111010000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_32X    0b0111000000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_16     0b0110110000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_8X     0b0110100000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_4X     0b0110010000000000      // Digital filter result alignment left
#define REG_ADFLxCON_MODE_LEFT_ALIGN_2X     0b0110000000000000      // Digital filter result alignment left

#define REG_ADFLxCON_MODE_RIGHT_ALIGN_128X  0b0001110000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_32X   0b0001100000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_8X    0b0001010000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_2X    0b0001000000000000      // Digital filter result alignment right

#define REG_ADFLxCON_MODE_RIGHT_ALIGN_256X  0b0000110000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_64X   0b0000100000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_16X   0b0000010000000000      // Digital filter result alignment right
#define REG_ADFLxCON_MODE_RIGHT_ALIGN_4X    0b0000000000000000      // Digital filter result alignment right

#define REG_ADFLxCON_IE_ON                  0b0000001000000000      // Digital filter result ready interrupt enabled
#define REG_ADFLxCON_IE_OFF                 0b0000000000000000      // Digital filter result ready interrupt disabled

#define REG_ADFLxCON_RDY_READY              0b0000000100000000      // Digital filter result ready 
#define REG_ADFLxCON_RDY_PEND               0b0000000000000000      // Digital filter result pending

#define REG_ADFLxCON_INPUT_MSK              0b0000000001111111      // ADC Core Clock Divider Filter Mask
#define REG_ADFLxCON_INPUT(x)            (x & REG_ADFLxCON_INPUT_MSK)     // Digital Filter ADC Input Number

#define REG_ADFLxCON_INPUT_AN31             0b0000000000011111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN30             0b0000000000011110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN29             0b0000000000011101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN28             0b0000000000011100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN27             0b0000000000011011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN26             0b0000000000011010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN25             0b0000000000011001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN24             0b0000000000011000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN23             0b0000000000010111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN22             0b0000000000010110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN21             0b0000000000010101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN20             0b0000000000010100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN19             0b0000000000010011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN18             0b0000000000010010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN17             0b0000000000010001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN16             0b0000000000010000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN15             0b0000000000001111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN14             0b0000000000001110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN13             0b0000000000001101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN12             0b0000000000001100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN11             0b0000000000001011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN10             0b0000000000001010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN9              0b0000000000001001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN8              0b0000000000001000      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN7              0b0000000000000111      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN6              0b0000000000000110      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN5              0b0000000000000101      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN4              0b0000000000000100      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN3              0b0000000000000011      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN2              0b0000000000000010      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN1              0b0000000000000001      // Digital Filter ADC Input Number 
#define REG_ADFLxCON_INPUT_AN0              0b0000000000000000      // Digital Filter ADC Input Number 




// Prototypes
extern inline uint16_t hsadc_module_power_up(void);
extern inline uint16_t hsadc_module_power_down(void);

extern inline uint16_t hsadc_init_adc_module
(
    REGBLK_ADCON1_t cfgADCON1,
    REGBLK_ADCON2_t cfgADCON2,
    REGBLK_ADCON3_t cfgADCON3,
    REGBLK_ADCON4_t cfgADCON4,
    REGBLK_ADCON5_t cfgADCON5
    );

extern inline uint16_t hsadc_init_adc_core(uint16_t index, uint16_t regADCORExL, uint16_t regADCORExH);

extern inline uint16_t hsadc_power_on_adc_core(uint16_t index);
extern inline uint16_t hsadc_module_enable(void);
extern inline uint16_t hsadc_module_disable(void);
extern inline uint16_t hsadc_reset(void);
extern inline uint16_t hsadc_check_adc_cores_ready(void);

#if defined (__P33SMPS_EP__)
extern inline uint16_t hsadc_calibrate_adc_core(uint16_t index, uint16_t calib_mode);
#endif

extern inline uint16_t hsadc_set_adc_input_trigger_source(uint16_t index, uint16_t interrupt_trigger);
extern inline uint16_t hsadc_set_adc_input_interrupt(uint16_t index, uint16_t interrupt_enable, uint16_t early_interrupt_enable);

extern inline uint16_t hsadc_init_adc_comp(uint16_t index, uint16_t input_no, uint16_t regADCMPxCON, uint16_t regADCMPxLO, uint16_t regADCMPxHI);




#endif   /* end of _P33SMPS_HSADC_H_ */
