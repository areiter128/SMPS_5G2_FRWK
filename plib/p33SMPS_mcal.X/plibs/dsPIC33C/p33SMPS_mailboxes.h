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
/*!p33SMPS_gpio.h
 * ***************************************************************************
 *
 * File:   p33SMPS_mailboxes.h
 * Author: M91406
 *
 * Created on October 04, 2018, 11:24 AM
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __MCAL_P33_SMPS_MAILBOXES_H__
#define	__MCAL_P33_SMPS_MAILBOXES_H__

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

#include "../p33SMPS_devices.h"

#if defined (__P33SMPS_CH_MSTR__)

// Mailbox declarations for master core
    #define MAILBOX0        MSI1MBX0D   // common declaration for master and slave core
    #define MAILBOX1        MSI1MBX1D   // common declaration for master and slave core
    #define MAILBOX2        MSI1MBX2D   // common declaration for master and slave core
    #define MAILBOX3        MSI1MBX3D   // common declaration for master and slave core
    #define MAILBOX4        MSI1MBX4D   // common declaration for master and slave core
    #define MAILBOX5        MSI1MBX5D   // common declaration for master and slave core
    #define MAILBOX6        MSI1MBX6D   // common declaration for master and slave core
    #define MAILBOX7        MSI1MBX7D   // common declaration for master and slave core
    #define MAILBOX8        MSI1MBX8D   // common declaration for master and slave core
    #define MAILBOX9        MSI1MBX9D   // common declaration for master and slave core
    #define MAILBOX10       MSI1MBX10D  // common declaration for master and slave core
    #define MAILBOX11       MSI1MBX11D  // common declaration for master and slave core
    #define MAILBOX12       MSI1MBX12D  // common declaration for master and slave core
    #define MAILBOX13       MSI1MBX13D  // common declaration for master and slave core
    #define MAILBOX14       MSI1MBX14D  // common declaration for master and slave core
    #define MAILBOX15       MSI1MBX15D  // common declaration for master and slave core

#elif defined (__P33SMPS_CH_SLV__)

// Mailbox declarations for slave core
    #define MAILBOX0        SI1MBX0D   // common declaration for master and slave core
    #define MAILBOX1        SI1MBX1D   // common declaration for master and slave core
    #define MAILBOX2        SI1MBX2D   // common declaration for master and slave core
    #define MAILBOX3        SI1MBX3D   // common declaration for master and slave core
    #define MAILBOX4        SI1MBX4D   // common declaration for master and slave core
    #define MAILBOX5        SI1MBX5D   // common declaration for master and slave core
    #define MAILBOX6        SI1MBX6D   // common declaration for master and slave core
    #define MAILBOX7        SI1MBX7D   // common declaration for master and slave core
    #define MAILBOX8        SI1MBX8D   // common declaration for master and slave core
    #define MAILBOX9        SI1MBX9D   // common declaration for master and slave core
    #define MAILBOX10       SI1MBX10D  // common declaration for master and slave core
    #define MAILBOX11       SI1MBX11D  // common declaration for master and slave core
    #define MAILBOX12       SI1MBX12D  // common declaration for master and slave core
    #define MAILBOX13       SI1MBX13D  // common declaration for master and slave core
    #define MAILBOX14       SI1MBX14D  // common declaration for master and slave core
    #define MAILBOX15       SI1MBX15D  // common declaration for master and slave core

#endif

extern volatile uint16_t smpsMBX_ResetAll(void);

#endif	/* __MCAL_P33_SMPS_GPIO_H__ */

