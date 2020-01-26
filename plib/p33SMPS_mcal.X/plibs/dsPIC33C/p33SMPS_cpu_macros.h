/*LICENSE *********************************************************************
 *
 * Software License Agreement
 *
 * Copyright � 2016 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/
 
#ifndef _APPLICATION_LAYER_DEFINES_H_
#define _APPLICATION_LAYER_DEFINES_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer types header file
#include <stdbool.h> // include standard boolean types header file
#include <stddef.h> // include standard definition types header file

/* ***************************************************************************************
 *	Generic Macros
 * **************************************************************************************/

#define WDT_RESET		asm volatile ("CRLWDT\n")
#define PWRSAV_IDLE		asm volatile ("PWRSAV #1\n")
#define PWRSAV_SLEEP	asm volatile ("PWRSAV #0\n")
#define CPU_RESET		asm volatile ("RESET\n")

/*!ALTWREG_SWAP()
 * ********************************************************************************
 * Summary: Swaps the current working register set
 * 
 * Parameters:
 *      uint16_t x: New Working Register Set (Target)
 * 
 * Returns: 
 *      uint16_t:   Previous Working Register Set (Origin)
 * 
 * ********************************************************************************/
#define ALTWREG_SWAP(NEW_WREG_SET) __extension__ ({ \
    volatile uint16_t __new_wreg_set = (NEW_WREG_SET), __old_wreg_set; \
    __asm__ ("ctxtswp %1;\n\t" : "=d" (__old_wreg_set) : "d" (__new_wreg_set)); __old_wreg_set; \
})    


#endif  /* _APPLICATION_LAYER_DEFINES_H_ */

