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
/*!p33SMPS_gpio.c
 * ***************************************************************************
 *
 * File:   p33SMPS_mailboxes.c
 * Author: M91406
 *
 * Created on October 04, 2018, 11:24 AM
 * ***************************************************************************/


#include "p33SMPS_mailboxes.h"

/*!smpsMBX_Reset
 * ***************************************************************************
 * Summary: Resets all mailbox registers in dual core devices
 * 
 * Parameters:
 *     (none)
 * 
 * Returns:
 *      uint16_t:   0 = failure
 *                  1 = success
 * 
 * Description:
 * This function clears all mailbox registers in Dual Core devices.
 * 
 * Please Note:
 * Mailbox registers are assigned to a certain core at compile time using 
 * FUSES (configuration bits). Only the assigned core has WRITE access while 
 * the register appears as "READ ONLY" to the other.
 * 
 * As access to these registers may be restricted dependent on this 
 * assignment, only the registers which have WRITE access will be cleared.
 * 
 * ***************************************************************************/

volatile uint16_t smpsMBX_ResetAll(void) {

    #if defined (__P33SMPS_CH__)

    /* Reset all mailboxes */
    
	MAILBOX0 = 0x0000;
	MAILBOX1 = 0x0000;
	MAILBOX2 = 0x0000;
	MAILBOX3 = 0x0000;
	MAILBOX4 = 0x0000;
	MAILBOX5 = 0x0000;
	MAILBOX6 = 0x0000;
	MAILBOX7 = 0x0000;
	MAILBOX8 = 0x0000;
	MAILBOX9 = 0x0000;
	MAILBOX10 = 0x0000;
	MAILBOX11 = 0x0000;
	MAILBOX12 = 0x0000;
	MAILBOX13 = 0x0000;
	MAILBOX14 = 0x0000;
	MAILBOX15 = 0x0000;
        
    #endif
    
    return(1);
}


