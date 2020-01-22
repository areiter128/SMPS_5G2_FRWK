/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
 */

/* 
 * File:   p33SMPS_plib.h
 * Author: M91406
 * Comments: This common library header triage the library files based on device selection
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __P33SMPS_PERIPHERAL_LIBRARY_H__
#define	__P33SMPS_PERIPHERAL_LIBRARY_H__

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // For uint16_t definition                      
#include <stdbool.h>  // For true/false definition   

#include "plibs/p33SMPS_devices.h" // Triage dsPIC33 device families

// include peripheral library headers for the selected device
#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

#include "plibs/dsPIC33C/p33SMPS_cpu_macros.h"
#include "plibs/dsPIC33C/p33SMPS_crc.h"
#include "plibs/dsPIC33C/p33SMPS_dsp.h"
#include "plibs/dsPIC33C/p33SMPS_gpio.h"
#include "plibs/dsPIC33C/p33SMPS_hsadc.h"
#include "plibs/dsPIC33C/p33SMPS_hspwm_c.h"
#include "plibs/dsPIC33C/p33SMPS_irq.h"
#include "plibs/dsPIC33C/p33SMPS_mailboxes.h"
#include "plibs/dsPIC33C/p33SMPS_oscillator.h"
#include "plibs/dsPIC33C/p33SMPS_pmd.h"
#include "plibs/dsPIC33C/p33SMPS_pps.h"
#include "plibs/dsPIC33C/p33SMPS_timer.h"
#include "plibs/dsPIC33C/p33SMPS_uart.h"

#else
  #pragma message "p33SMPS_plib Warning: selected device is currently not supported by the peripheral libraries"
#endif

// peripheral library global data structures
extern volatile OSCILLATOR_SYSTEM_FREQUENCIES_t system_frequencies;



#endif	/* __P33SMPS_PERIPHERAL_LIBRARY_H__ */

