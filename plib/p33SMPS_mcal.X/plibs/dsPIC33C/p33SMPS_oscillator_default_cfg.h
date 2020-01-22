/* ****************************************************************************************************
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
 * *****************************************************************************************************
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 * *****************************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MCAL_P33SMPS_DEVCFG_OSCILLATOR_H
#define	MCAL_P33SMPS_DEVCFG_OSCILLATOR_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

/*@@System Oscillator Settings
 * ************************************************************************************************
 * Summary:
 * Predefined settings for standard oscillator configurations
 *
 * Description:
 * These defines are used to setup the oscillator using predefined settings to achieve common
 * system clock speeds/frequencies. By selecting one of the given MIPS_xx options, all required register
 * values for scalers and gating options will be selected and adjusted accordingly.
 * ***********************************************************************************************/

#if defined (__P33SMPS_EP__)
    #define CPU_PERFORMANCE 	C_70MIPS	// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)  
#elif defined (__P33SMPS_CH_MSTR__)
    #define CPU_PERFORMANCE 	C_90MIPS	// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)  
#elif defined (__P33SMPS_CH_SLV__) || defined (__P33SMPS_CK__)
    #define CPU_PERFORMANCE 	C_100MIPS	// Device speed selection (MIPS40, MIPS50, MIPS60, MIPS70)  
#endif


#define USE_EXTERNAL_OSC 0 // 0: use internal FRC oscillator, 1: use external oscillator
#if (USE_EXTERNAL_OSC == 1)
    EXT_OSC_FREQ        8000000 // Specify frequency of the external oscillator in [Hz]
#endif
        
/*@@System Oscillator Settings
 * ************************************************************************************************
 * Summary:
 * Predefined settings for standard oscillator configurations
 *
 * Description:
 * These defines are used to setup the oscillator using predefined settings to achieve common
 * system clock speeds/frequencies. By selecting one of the given MIPS_xx options, all required register
 * values for scalers and gating options will be selected and adjusted accordingly.
 * ***********************************************************************************************/

/* device speed definitions */

#define C_40MIPS 1 // Specification flag for 40 MIPS
#define C_50MIPS 2 // Specification flag for 50 MIPS
#define C_60MIPS 3 // Specification flag for 60 MIPS
#define C_70MIPS 4 // Specification flag for 70 MIPS
#define C_80MIPS 5 // Specification flag for 80 MIPS
#define C_90MIPS 6 // Specification flag for 90 MIPS
#define C_100MIPS 7 // Specification flag for 100 MIPS
        
#if (CPU_PERFORMANCE == C_40MIPS)

#if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
    #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_80
    #define OSC_PLLDIV_N2     PLLDIV_POST2DIV_N2N3_4
    #define OSC_PLLDIV_N3     PLLDIV_POST2DIV_N2N3_1

#elif defined (__P33SMPS_FJ__) defined (__P33SMPS_FJC__) || defined (__P33SMPS_EP__)

    #define OSCPLL_N1		CLKDIV_PLLDIV_N1_2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
    #define OSCPLL_M		PLLFBD_PLLFBDIV_M_43	// PLLDIV<8:0> PLL Feedback Divisor value M
    #define OSCPLL_N2		CLKDIV_PLLPOST_N2_2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

#else
    #pragma message "Device performance of 40 MIPS might exceed device limit"
#endif

#elif (CPU_PERFORMANCE == C_50MIPS)

    #if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

        #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_100
        #define OSC_PLLDIV_N2     OSC_PLLDIV_N2_4
        #define OSC_PLLDIV_N3     OSC_PLLDIV_N3_1

    #elif defined (__P33SMPS_FJ__) defined (__P33SMPS_FJC__) || defined (__P33SMPS_EP__)

        #define OSCPLL_N1		CLKDIV_PLLDIV_N1_2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
        #define OSCPLL_M		PLLFBD_PLLFBDIV_M_53	// PLLDIV<8:0> PLL Feedback Divisor value M
        #define OSCPLL_N2		CLKDIV_PLLPOST_N2_2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

    #else
        #pragma message "Device performance of 50 MIPS might exceed device limit"
    #endif

#elif (CPU_PERFORMANCE == C_60MIPS)

    #if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

        #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_120
        #define OSC_PLLDIV_N2     OSC_PLLDIV_N2_4
        #define OSC_PLLDIV_N3     OSC_PLLDIV_N3_1

    #elif defined (__P33SMPS_EP__)

        #define OSCPLL_N1		CLKDIV_PLLDIV_N1_2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
        #define OSCPLL_M		PLLFBD_PLLFBDIV_M_64	// PLLDIV<8:0> PLL Feedback Divisor value M
        #define OSCPLL_N2		CLKDIV_PLLPOST_N2_2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

    #else
        #pragma message "Device performance of 60 MIPS might exceed device limit"
    #endif

#elif (CPU_PERFORMANCE == C_70MIPS)

    #if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

        #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_140
        #define OSC_PLLDIV_N2     PLLDIV_POST2DIV_N2N3_4
        #define OSC_PLLDIV_N3     PLLDIV_POST2DIV_N2N3_1

    #elif defined (__P33SMPS_EP__)

        #define OSCPLL_N1		CLKDIV_PLLDIV_N1_2		// PLLPRE<4:0> PLL Phase Detector Input Divider value N1
        #define OSCPLL_M		PLLFBD_PLLFBDIV_M_74	// PLLDIV<8:0> PLL Feedback Divisor value M
        #define OSCPLL_N2		CLKDIV_PLLPOST_N2_2		// PLLPOST<1:0> PLL VCO Output Divider Select value N2

    #else
        #pragma message "Device performance of 70 MIPS might exceed device limit"
    #endif

#elif (CPU_PERFORMANCE == C_80MIPS)

    #if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

        #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_160
        #define OSC_PLLDIV_N2     PLLDIV_POST2DIV_N2N3_4
        #define OSC_PLLDIV_N3     PLLDIV_POST2DIV_N2N3_1

    #else
        #pragma message "Device performance of 80 MIPS might exceed device limit"
    #endif

#elif (CPU_PERFORMANCE == C_90MIPS)

    #if defined(__P33SMPS_CH__) || defined (__P33SMPS_CK__)

        #define OSC_PLLDIV_N1 CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M  PLLFBD_PLLFBDIV_M_180
        #define OSC_PLLDIV_N2 PLLDIV_POST2DIV_N2N3_4
        #define OSC_PLLDIV_N3 PLLDIV_POST2DIV_N2N3_1

    #else
        #pragma message "Device performance of 90 MIPS might exceed device limit"
    #endif

#elif (CPU_PERFORMANCE == C_100MIPS)

    #if defined(__P33SMPS_CH_SLV__) || defined(__P33SMPS_CK__)

        #define OSC_PLLDIV_N1     CLKDIV_PLLDIV_N1_1
        #define OSC_PLLDIV_M      PLLFBD_PLLFBDIV_M_200
        #define OSC_PLLDIV_N2     PLLDIV_POST2DIV_N2N3_4
        #define OSC_PLLDIV_N3     PLLDIV_POST2DIV_N2N3_1

    #else
        #pragma message "Device performance of 100 MIPS might exceed device limit"
    #endif

#else
    #error === CPU_PERFORMANCE has not been set or setting is not supported ===
#endif


#define OSC_FREQUENCY		OSC_FREQ    

#if defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__) || \
    defined (__P33SMPS_EP__)

    // FRC Output Frequency in Hertz (incl. OSCTUN)
    #define AUXOSCFREQUENCY	((uint32_t)(OSC_FRC_FREQ + (OSC_FRC_TUN * (OSC_TUN_SCALER * OSC_FRC_FREQ))))

    // PWM Counter Frequency in Hertz (~960 MHz max.)
    #define F_ACLK  ((uint32_t)(AUXOSCFREQUENCY * 16.0 * 8.0))

    // PWM Resolution in Seconds (~1.042 ns max.)
    #define T_ACLK  ((float)(1.0/(float)(F_ACLK)))  

    // PLL Output Frequency in Hertz (~70 MHz max.)
    #define FOSC    ((uint32_t)(((OSCFREQUENCY / OSCPLL_N1) * OSCPLL_M) / OSCPLL_N2))

#elif defined (__P33SMPS_CH__) ||  defined (__P33SMPS_CK__)

    // FRC Output Frequency in Hertz (incl. OSCTUN)
    #define AUXOSCFREQUENCY	((uint32_t)(OSC_FRC_FREQ + (OSC_FRC_TUN * (OSC_TUN_SCALER * OSC_FRC_FREQ))))

    // APLL Output Frequency in Hertz (500 MHz max. for 4 GHz PWM clock => High Resolution PWM needs to be enabled in the PWM module)
    #define ACLK_PLLDIV_N1     ACLKCON_APLLDIV_N1_1
    #define ACLK_PLLDIV_M      APLLFBD_APLLFBDIV_M_125
    #define ACLK_PLLDIV_N2     APLLDIV_POST2DIV_N2N3_2
    #define ACLK_PLLDIV_N3     APLLDIV_POST2DIV_N2N3_1
        
//    #define F_ACLK  (uint32_t)(((float)AUXOSCFREQUENCY * (float)ACLK_PLLDIV_M) / ((float)ACLK_PLLDIV_N1 * (float)ACLK_PLLDIV_N2 * (float)ACLK_PLLDIV_N3))

    // PWM Resolution in Seconds (~1.042 ns max.)
//    #define T_ACLK  ((float)(1.0/(float)(F_ACLK)))  

    // PLL Output Frequency in Hertz (~100 MHz max.)
//    #define FOSC    (uint32_t)((((float)OSC_FREQUENCY * (float)OSC_PLLDIV_M) / ((float)OSC_PLLDIV_N1 * (float)OSC_PLLDIV_N2 * (float)OSC_PLLDIV_N3)) / 2.0)

#else
    #error === CPU oscillator frequency macros cannot be determined for this device ===
#endif

// Operating Frequency in Hertz (~100 MHz max.)
//#define FCY     ((uint32_t)(FOSC / 2))

// Instruction Cycle in Seconds
//#define TCY     ((float)(1.0/(float)(FCY)))


            
#endif	/* MCAL_P33SMPS_DEVCFG_OSCILLATOR_H */

