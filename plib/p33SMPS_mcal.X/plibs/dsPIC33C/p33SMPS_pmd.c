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
/*!p33MP_gpio.c
 * ***************************************************************************
 *
 * File:   p33MP_gpio.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/
/*!p33SMPS_pmd.c
 * ***************************************************************************
 *
 * File:   p33SMPS_pmd.c
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

#include "p33SMPS_pmd.h"

inline volatile uint16_t pmd_reset(pmd_enable_setting_e power_on_state) {
    
    volatile uint16_t regval=0;
    
    if (power_on_state == PMD_POWER_OFF)
    { regval = 0xFFFF; }
    
    #ifdef PMDCON
    _PMDLOCK = 1; // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #endif
    
    #ifdef PMD1
        PMD1 = (regval & PMD1_VALID_DATA_MASK);   // disable all peripherals in PMD1 register
    #endif
    #ifdef PMD2
        PMD2 = (regval & PMD2_VALID_DATA_MASK);   // disable all peripherals in PMD2 register
    #endif
    #ifdef PMD3
        PMD3 = (regval & PMD3_VALID_DATA_MASK);   // disable all peripherals in PMD3 register
    #endif
    #ifdef PMD4
        PMD4 = (regval & PMD4_VALID_DATA_MASK);   // disable all peripherals in PMD4 register
    #endif
    #ifdef PMD5
        PMD5 = (regval & PMD5_VALID_DATA_MASK);   // disable all peripherals in PMD5 register
    #endif
    #ifdef PMD6
        PMD6 = (regval & PMD6_VALID_DATA_MASK);   // disable all peripherals in PMD6 register
    #endif
    #ifdef PMD7
        PMD7 = (regval & PMD7_VALID_DATA_MASK);   // disable all peripherals in PMD7 register
    #endif
    #ifdef PMD8
        PMD8 = (regval & PMD8_VALID_DATA_MASK);   // disable all peripherals in PMD8 register
    #endif
    #ifdef PMD9
        PMD9 = (regval & PMD9_VALID_DATA_MASK);   // disable all peripherals in PMD9 register
    #endif

    #ifdef PMDCON
    _PMDLOCK = 0; // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #endif
        
        
    return(1);

}

