/*!Software License Agreement
 * ************************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright © 2012 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
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
/*!irq.h
 * ************************************************************************************************
 * Summary:
 * Generic Interrupt Configuration Driver Module (header file)
 *
 * Description:
 * This additional header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * 
 * See Also:
 *	p33EGS_irq.c
 * ***********************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _P33GS_INTERRUPT_CONFIG_DEF_H_
#define	_P33GS_INTERRUPT_CONFIG_DEF_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#include "../p33SMPS_devices.h"


//#if defined (__P33SMPS_EP__) || defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

// Defines for gsirq_soft_traps_initialize(...)
#define ACCA_OVERFLOW_TRAP_ENABLED                  1
#define ACCA_OVERFLOW_TRAP_DISABLED                 0
#define ACCB_OVERFLOW_TRAP_ENABLED                  1
#define ACCB_OVERFLOW_TRAP_DISABLED                 0
#define ACCx_CATASTROPHIC_OVERFLOW_TRAP_ENABLED     1
#define ACCx_CATASTROPHIC_OVERFLOW_TRAP_DISABLED    0


// INTCON1 Configuration Bits
#define REG_INTCON1_WRITE_BIT_MSK           0b1000011100000000      // First interrupt configuration register for write operations (no status bits)
#define REG_INTCON1_VALID_BIT_MSK           0b1111111111011110      // First interrupt configuration register for read operations (incl. status bits)

#define REG_INTCON1_NSTDIS_ENABLED          0b0000000000000000      // Nested Interrupts enabled
#define REG_INTCON1_NSTDIS_DISABLED         0b1000000000000000      // Nested Interrupts disabled

typedef enum {
    INTCON1_NSTDIS_ENABLED  = 0b1, // Nested Interrupts enabled
    INTCON1_NSTDIS_DISABLED = 0b0  // Nested Interrupts disabled
} INTCON1_NSTDIS_e;

#define REG_INTCON1_OVATE_ENABLED           0b0000010000000000      // Accumulator A overflow trap enable
#define REG_INTCON1_OVATE_DISABLED          0b0000000000000000      // Accumulator A overflow trap disable

typedef enum {
    INTCON1_OVATE_ENABLED  = 0b1, // Accumulator A overflow trap enabled
    INTCON1_OVATE_DISABLED = 0b0  // Accumulator A overflow trap disabled
} INTCON1_OVATE_e;

#define REG_INTCON1_OVBTE_ENABLED           0b0000001000000000      // Accumulator B overflow trap enable
#define REG_INTCON1_OVBTE_DISABLED          0b0000000000000000      // Accumulator B overflow trap disable

typedef enum {
    INTCON1_OVBTE_ENABLED  = 0b1, // Accumulator B overflow trap enabled
    INTCON1_OVBTE_DISABLED = 0b0  // Accumulator B overflow trap disabled
} INTCON1_OVBTE_e;

#define REG_INTCON1_COVTE_ENABLED           0b0000000100000000      // Accumulator catastrophic overflow trap enable
#define REG_INTCON1_COVTE_DISABLED          0b0000000000000000      // Accumulator catastrophic overflow trap disable

typedef enum {
    INTCON1_COVTE_ENABLED  = 0b1, // Accumulator catastrophic overflow trap enabled
    INTCON1_COVTE_DISABLED = 0b0  // Accumulator catastrophic overflow trap disabled
} INTCON1_COVTE_e;

// INTCON1 Flag Bits
#define REG_INTCON1_OVAERR_FLAG_SET         0b0100000000000000      // Accumulator A overflow trap flag bit is set
#define REG_INTCON1_OVAERR_FLAG_CLEAR       0b0000000000000000      // Accumulator A overflow trap flag bit is cleared

typedef enum {
    INTCON1_OVAERR_FLAG_SET  = 0b1, // Accumulator A overflow trap flag bit is set
    INTCON1_OVAERR_FLAG_CLEAR = 0b0  // Accumulator A overflow trap flag bit is cleared
} INTCON1_OVAERR_e;

#define REG_INTCON1_OVBERR_FLAG_SET         0b0010000000000000      // Accumulator B overflow trap flag bit is set
#define REG_INTCON1_OVBERR_FLAG_CLEAR       0b0000000000000000      // Accumulator B overflow trap flag bit is cleared

typedef enum {
    INTCON1_OVBERR_FLAG_SET  = 0b1, // Accumulator B overflow trap flag bit is set
    INTCON1_OVBERR_FLAG_CLEAR = 0b0  // Accumulator B overflow trap flag bit is cleared
} INTCON1_OVBERR_e;

#define REG_INTCON1_COVAERR_FLAG_SET        0b0001000000000000      // Accumulator A catastrophic overflow trap flag bit is set
#define REG_INTCON1_COVAERR_FLAG_CLEAR      0b0000000000000000      // Accumulator A catastrophic overflow trap flag bit is cleared

typedef enum {
    INTCON1_COVAERR_FLAG_SET  = 0b1, // Accumulator A catastrophic overflow trap flag bit is set
    INTCON1_COVAERR_FLAG_CLEAR = 0b0  // Accumulator A catastrophic overflow trap flag bit is cleared
} INTCON1_COVAERR_e;

#define REG_INTCON1_COVBERR_FLAG_SET        0b0000100000000000      // Accumulator B catastrophic overflow trap flag bit is set
#define REG_INTCON1_COVBERR_FLAG_CLEAR      0b0000000000000000      // Accumulator B catastrophic overflow trap flag bit is cleared

typedef enum {
    INTCON1_COVBERR_FLAG_SET  = 0b1, // Accumulator A catastrophic overflow trap flag bit is set
    INTCON1_COVBERR_FLAG_CLEAR = 0b0  // Accumulator A catastrophic overflow trap flag bit is cleared
} INTCON1_COVBERR_e;

// ======================================================================================================
// INTCON1 Status Bits
// ======================================================================================================
#define REG_INTCON1_STATUS_READ_MSK     0b0000000011011110

#define REG_INTCON1_SFTACERR_SET        0b0000000010000000   // Shift Accumulator Error Status bit set
#define REG_INTCON1_SFTACERR_CLEAR      0b0000000000000000   // Shift Accumulator Error Status bit cleared

typedef enum {
    INTCON1_SFTACERR_FLAG_SET  = 0b1, // Shift Accumulator Error Status bit set
    INTCON1_SFTACERR_FLAG_CLEAR = 0b0  // Shift Accumulator Error Status bit cleared
} INTCON1_SFTACERR_e;

#define REG_INTCON1_DIV0ERR_SET        0b0000000001000000
#define REG_INTCON1_DIV0ERR_CLEAR      0b0000000000000000

typedef enum {
    INTCON1_DIV0ERR_FLAG_SET  = 0b1, // Divide-by-Zero Error Status bit set
    INTCON1_DIV0ERR_FLAG_CLEAR = 0b0  // Divide-by-Zero Error Status bit cleared
} INTCON1_DIV0ERR_e;

#define REG_INTCON1_DMACERR_SET        0b0000000000100000
#define REG_INTCON1_DMACERR_CLEAR      0b0000000000000000

typedef enum {
    INTCON1_DMACERR_FLAG_SET  = 0b1, // DMA Controller Trap Status bit set
    INTCON1_DMACERR_FLAG_CLEAR = 0b0  // DMA Controller Trap Status bit cleared
} INTCON1_DMACERR_e;

#define REG_INTCON1_MATHERR_SET        0b0000000000010000  // Divide-by-Zero Error Status bit set
#define REG_INTCON1_MATHERR_CLEAR      0b0000000000000000  // Divide-by-Zero Error Status bit cleared

typedef enum {
    INTCON1_MATHERR_FLAG_SET  = 0b1, // Math Error Status bit set
    INTCON1_MATHERR_FLAG_CLEAR = 0b0  // Math Error Status bit cleared
} INTCON1_MATHERR_e;

#define REG_INTCON1_ADDRERR_SET        0b0000000000001000 // Address Error Trap Status bit set
#define REG_INTCON1_ADDRERR_CLEAR      0b0000000000000000 // Address Error Trap Status bit cleared

typedef enum {
    INTCON1_ADDRERR_FLAG_SET  = 0b1, // Address Error Trap Status bit set
    INTCON1_ADDRERR_FLAG_CLEAR = 0b0 // Address Error Trap Status bit cleared
} INTCON1_ADDRERR_e;

#define REG_INTCON1_STKERR_SET         0b0000000000000100 // Stack Error Trap Status bit set
#define REG_INTCON1_STKERR_CLEAR       0b0000000000000000 // Stack Error Trap Status bit cleared

typedef enum {
    INTCON1_STKERR_FLAG_SET  = 0b1, // Stack Error Trap Status bit set
    INTCON1_STKERR_FLAG_CLEAR = 0b0 // Stack Error Trap Status bit cleared
} INTCON1_STKERR_e;

#define REG_INTCON1_OSCFAIL_SET        0b0000000000000010 // Oscillator Failure Trap Status bit set
#define REG_INTCON1_OSCFAIL_CLEAR      0b0000000000000000 // Oscillator Failure Trap Status bit cleared

typedef enum {
    INTCON1_OSCFAIL_FLAG_SET  = 0b1, // Oscillator Failure Trap Status bit set
    INTCON1_OSCFAIL_FLAG_CLEAR = 0b0  // Oscillator Failure Trap Status bit cleared
} INTCON1_OSCFAIL_e;

typedef union {

    struct {
        volatile unsigned : 1;                  // Bit 0: (reserved)
        volatile INTCON1_OSCFAIL_e OSCFAIL : 1; // Bit 1: Oscillator Failure Trap Status bit
        volatile INTCON1_STKERR_e  STKERR : 1; // Bit 2: Stack Error Trap Status bit
        volatile INTCON1_ADDRERR_e ADDRERR : 1; // Bit 3: Address Error Trap Status bit
        volatile INTCON1_MATHERR_e MATHERR : 1; // Bit 4: Math Error Status bit
        volatile INTCON1_DMACERR_e DMACERR : 1; // Bit 5: DMA Controller Trap Status bit
        volatile INTCON1_DIV0ERR_e DIV0ERR : 1; // Bit 6: Divide-by-Zero Error Status bit
        volatile INTCON1_SFTACERR_e SFTACERR : 1; // Bit 7: Shift Accumulator Error Status bit
        volatile INTCON1_COVTE_e   COVTE : 1; // Bit 8: Catastrophic Overflow Trap Enable bit
        volatile INTCON1_OVBTE_e   OVBTE : 1; // Bit 9: Accumulator B Overflow Trap Enable bit
        volatile INTCON1_OVATE_e   OVATE : 1; // Bit 10: Accumulator A Overflow Trap Enable bit
        volatile INTCON1_COVBERR_e COVBERR : 1; // Bit 11: Accumulator B Catastrophic Overflow Trap Flag bit
        volatile INTCON1_COVAERR_e COVAERR : 1; // Bit 12: Accumulator A Catastrophic Overflow Trap Flag bit
        volatile INTCON1_OVBERR_e  OVBERR : 1; // Bit 13: Accumulator B Overflow Trap Flag bit
        volatile INTCON1_OVAERR_e  OVAERR : 1; // Bit 14: Accumulator A Overflow Trap Flag bit
        volatile INTCON1_NSTDIS_e  NSTDIS : 1; // Bit 15: Interrupt Nesting Disable bit
    } __attribute__((packed)) bits;
    volatile uint16_t value;
}INTCON1_t; // INTCON1: INTERRUPT CONTROL REGISTER 1


// ======================================================================================================
// INTCON2 Configuration Bits
// ======================================================================================================
#define REG_INTCON2_WRITE_BIT_MSK   0b1110000100010111      // Second interrupt configuration register for write operations (no status bits)
#define REG_INTCON2_VALID_BIT_MSK   0b1110000100010111      // Second interrupt configuration register for read operations (incl. status bits)

#define REG_INTCON2_GIE_ENABLED     0b1000000000000000      // Global Interrupt Enables
#define REG_INTCON2_GIE_DISABLED    0b0000000000000000      // Global Interrupt Disabled

typedef enum {
    INTCON2_GIE_ENABLE  = 0b1, // Global Interrupt Enabled
    INTCON2_GIE_DISABLED = 0b0 // Global Interrupt Disabled
} INTCON2_GIE_e; // Global Interrupt Enable bit

#define REG_INTCON2_STAT_DISI_SET       0b0100000000000000
#define REG_INTCON2_STAT_DISI_CLEAR     0b0000000000000000

typedef enum {
    INTCON2_DISI_SET  = 0b1, // DISI instruction is active
    INTCON2_DISI_CLEARED = 0b0 // DISI instruction is not active
} INTCON2_DISI_e; // DISI Instruction Status bit

#define REG_INTCON2_SWTRAP_ENABLED  0b0010000000000000      // Software Trap Status Enabled
#define REG_INTCON2_SWTRAP_DISABLED 0b0000000000000000      // Software Trap Status Disabled

typedef enum {
    INTCON2_SWTRAP_ENABLE  = 0b1, // Software Trap Status Enabled
    INTCON2_SWTRAP_DISABLED = 0b0 // Software Trap Status Disabled
} INTCON2_SWTRAP_e; // Software Trap Status bit

#define REG_INTCON2_AIVTEN_ENABLE   0b0000000100000000 // Alternate Interrupt Vector Table Enabled
#define REG_INTCON2_AIVTEN_DISABLE  0b0000000000000000 // Alternate Interrupt Vector Table Disabled

typedef enum {
    INTCON2_AIVTEN_ENABLE  = 0b1, // Alternate Interrupt Vector Table Enabled
    INTCON2_AIVTEN_DISABLED = 0b0 // Alternate Interrupt Vector Table Disabled
} INTCON2_AIVTEN_e; // Alternate Interrupt Vector Table Enable bit

#if defined (_INT7EP)
#define REG_INTCON2_INT7EP_FALLING      0b0000000010000000 // External Interrupt 7 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT7EP_RISING       0b0000000000000000 // External Interrupt 7 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT6EP)
#define REG_INTCON2_INT6EP_FALLING      0b0000000001000000 // External Interrupt 6 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT6EP_RISING       0b0000000000000000 // External Interrupt 6 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT5EP)
#define REG_INTCON2_INT5EP_FALLING      0b0000000000100000 // External Interrupt 5 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT5EP_RISING       0b0000000000000000 // External Interrupt 5 Edge Detect Polarity Select bit Rising
#endif
#ifdef _INT4EP
#define REG_INTCON2_INT4EP_FALLING      0b0000000000010000 // External Interrupt 4 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT4EP_RISING       0b0000000000000000 // External Interrupt 4 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT3EP)
#define REG_INTCON2_INT3EP_FALLING      0b0000000000001000 // External Interrupt 3 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT3EP_RISING       0b0000000000000000 // External Interrupt 3 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT2EP)
#define REG_INTCON2_INT2EP_FALLING      0b0000000000000100 // External Interrupt 2 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT2EP_RISING       0b0000000000000000 // External Interrupt 2 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT1EP)
#define REG_INTCON2_INT1EP_FALLING      0b0000000000000010 // External Interrupt 1 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT1EP_RISING       0b0000000000000000 // External Interrupt 1 Edge Detect Polarity Select bit Rising
#endif
#if defined (_INT0EP)
#define REG_INTCON2_INT0EP_FALLING      0b0000000000000001 // External Interrupt 0 Edge Detect Polarity Select Falling
#define REG_INTCON2_INT0EP_RISING       0b0000000000000000 // External Interrupt 0 Edge Detect Polarity Select bit Rising
#endif

typedef enum {
    INTCON2_INTxEP_FALLING  = 0b1, // External Interrupt x Edge Detect Polarity Select Falling
    INTCON2_INTxEP_RISING = 0b0 // External Interrupt x Edge Detect Polarity Select bit Rising
} INTCON2_INTxEP_e; // External Interrupt x Edge Detect Polarity Select bit

typedef union {
    struct {
        #if defined (_INT0EP)
        volatile INTCON2_INTxEP_e INT0EP : 1; // Bit 0: External Interrupt 0 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT1EP)
        volatile INTCON2_INTxEP_e INT1EP : 1; // Bit 1: External Interrupt 1 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT2EP)
        volatile INTCON2_INTxEP_e INT2EP : 1; // Bit 2: External Interrupt 2 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT3EP)
        volatile INTCON2_INTxEP_e INT3EP : 1; // Bit 3: External Interrupt 3 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT4EP)
        volatile INTCON2_INTxEP_e INT4EP : 1; // Bit 4: External Interrupt 4 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT5EP)
        volatile INTCON2_INTxEP_e INT5EP : 1; // Bit 5: External Interrupt 5 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT6EP)
        volatile INTCON2_INTxEP_e INT6EP : 1; // Bit 6: External Interrupt 6 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        #if defined (_INT7EP)
        volatile INTCON2_INTxEP_e INT7EP : 1; // Bit 7: External Interrupt 7 Edge Detect Polarity Select bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif

        volatile INTCON2_AIVTEN_e AIVTEN : 1; // Bit 8: Alternate Interrupt Vector Table Enable bit
        volatile unsigned : 4;                // Bit 12-9: (reserved)
        volatile INTCON2_SWTRAP_e SWTRAP : 1; // Bit 13: Software Trap Status bit
        volatile INTCON2_DISI_e   DISI   : 1; // Bit 14: DISI Instruction Status bit
        volatile INTCON2_GIE_e    GIE    : 1; // Bit 15: Global Interrupt Enable bit

    } __attribute__((packed)) bits; // INTCON2: INTERRUPT CONTROL REGISTER 2
    volatile uint16_t value;
}INTCON2_t; // INTCON2: INTERRUPT CONTROL REGISTER 2


// ======================================================================================================
// INTCON3 Configuration Bits
// ======================================================================================================

#if defined (_CAN2)
  #define REG_INTCON3_WRITE_BIT_MSK           0b0000001101010001      // Third interrupt configuration register for write operations (no status bits)
  #define REG_INTCON3_VALID_BIT_MSK           0b0000001101010001      // Third interrupt configuration register for read operations (incl. status bits)
#elif defined (_CAN)
  #define REG_INTCON3_WRITE_BIT_MSK           0b0000001100010001      // Third interrupt configuration register for write operations (no status bits)
  #define REG_INTCON3_VALID_BIT_MSK           0b0000001100010001      // Third interrupt configuration register for read operations (incl. status bits)
#else
  #define REG_INTCON3_WRITE_BIT_MSK           0b0000000100010001      // Third interrupt configuration register for write operations (no status bits)
  #define REG_INTCON3_VALID_BIT_MSK           0b0000000100010001      // Third interrupt configuration register for read operations (incl. status bits)
#endif

#define REG_INTCON3_NAE_SET            0b0000000100000000
#define REG_INTCON3_NAE_CLEAR          0b0000000000000000

typedef enum {
    INTCON3_NAE_SET = 0b1,  // NVM address error soft trap has occurred
    INTCON3_NAE_CLEAR = 0b0 // NVM address error soft trap has not occurred
}INTCON3_NAE_e; // NVM Address Error Soft Trap Status bit

#define REG_INTCON3_CAN_SET            0b0000001000000000
#define REG_INTCON3_CAN_CLEAR          0b0000000000000000
#define REG_INTCON3_CAN2_SET           0b0000000001000000
#define REG_INTCON3_CAN2_CLEAR         0b0000000000000000

typedef enum {
    INTCON3_CANx_SET = 0b1,  // CANx address error soft trap has occurred
    INTCON3_CANx_CLEAR = 0b0 // CANx address error soft trap has not occurred
}INTCON3_CANx_e; // CAN2 Address Error Soft Trap Status bit

#define REG_INTCON3_DOOVR_SET          0b0000000000010000
#define REG_INTCON3_DOOVR_CLEAR        0b0000000000000000

typedef enum {
    INTCON3_DOOVR_SET = 0b1,  // DO stack overflow soft trap has occurred
    INTCON3_DOOVR_CLEAR = 0b0 // DO stack overflow soft trap has not occurred
}INTCON3_DOOVR_e; // DO Stack Overflow Soft Trap Status bit

#define REG_INTCON3_APLL_SET           0b0000000000000001
#define REG_INTCON3_APLL_CLEAR         0b0000000000000000

typedef enum {
    INTCON3_APLL_SET = 0b1,  // APLL lock soft trap has occurred
    INTCON3_APLL_CLEAR = 0b0 // APLL lock soft trap has not occurred
}INTCON3_APLL_e; // Auxiliary PLL Loss of Lock Soft Trap Status bit

typedef union {
    struct {
        volatile INTCON3_APLL_e APLL : 1;   // Bit 0: Auxiliary PLL Loss of Lock Soft Trap Status bit
        volatile unsigned : 1;              // Bit 1: (reserved)
        volatile unsigned : 1;              // Bit 2: (reserved)
        volatile unsigned : 1;              // Bit 3: (reserved)
        volatile INTCON3_DOOVR_e DOOVR : 1; // Bit 4: DO Stack Overflow Soft Trap Status bit
        volatile unsigned : 1;              // Bit 5: (reserved)
        #if defined (_CAN2)
        volatile INTCON3_CANx_e CAN2 : 1;   // Bit 6: CAN2 Address Error Soft Trap Status bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        volatile unsigned : 1;              // Bit 7: (reserved)
        volatile INTCON3_NAE_e NAE : 1;     // Bit 8: NVM Address Error Soft Trap Status bit
        #if defined (_CAN)
        volatile INTCON3_CANx_e CAN : 1;    // Bit 9: CAN  Address Error Soft Trap Status bit
        #else
        volatile unsigned : 1; // (reserved)
        #endif
        volatile unsigned : 1;              // Bit 10: (reserved)
        volatile unsigned : 1;              // Bit 11: (reserved)
        volatile unsigned : 1;              // Bit 12: (reserved)
        volatile unsigned : 1;              // Bit 13: (reserved)
        volatile unsigned : 1;              // Bit 14: (reserved)
        volatile unsigned : 1;              // Bit 15: (reserved)
    } __attribute__((packed)) bits; // INTCON3: INTERRUPT CONTROL REGISTER 3
    volatile uint16_t value;
}INTCON3_t; // INTCON3: INTERRUPT CONTROL REGISTER 3

// ======================================================================================================
// INTCON4 Configuration Bits
// ======================================================================================================

#define REG_INTCON4_WRITE_BIT_MSK       0b0000000000000000      // Fourth interrupt configuration register for write operations (no status bits)
#define REG_INTCON4_VALID_BIT_MSK       0b0000000000000001      // Fourth interrupt configuration register for read operations (incl. status bits)

#define REG_INTCON4_STAT_SGHT_SET       0b0000000000000001
#define REG_INTCON4_SGHT_CLEAR          0b0000000000000000

typedef enum {
    INTCON4_SGHT_SET = 0b1,  // Software generated hard trap has occurred
    INTCON4_SGHT_CLEAR = 0b0 // Software generated hard trap has not occurred
}INTCON4_SGHT_e; // Software Generated Hard Trap Status bit

#if defined (_ECCDBE)
#define REG_INTCON4_ECCDBE_SET          0b0000000000000010
#define REG_INTCON4_ECCDBE_CLEAR        0b0000000000000000

typedef enum {
    INTCON4_ECCDBE_SET = 0b1,  // ECC double-bit error trap has occurred
    INTCON4_ECCDBE_CLEAR = 0b0 // ECC double-bit error trap has not occurred
}INTCON4_ECCDBE_e; // ECC Double-Bit Error Trap bit
#endif

typedef union {
    struct {
        volatile INTCON4_SGHT_e SGHT : 1;       // Bit 0: Software Generated Hard Trap Status bit
        #if defined (_ECCDBE)
        volatile INTCON4_ECCDBE_e ECCDBE : 1;   // Bit 1: ECC Double-Bit Error Trap bit
        #else
        volatile unsigned : 1; (reserved)
        #endif
        volatile unsigned : 1;                  // Bit 2: (reserved)
        volatile unsigned : 1;                  // Bit 3: (reserved)
        volatile unsigned : 1;                  // Bit 4: (reserved)
        volatile unsigned : 1;                  // Bit 5: (reserved)
        volatile unsigned : 1;                  // Bit 6: (reserved)
        volatile unsigned : 1;                  // Bit 7: (reserved)
        volatile unsigned : 1;                  // Bit 8: (reserved)
        volatile unsigned : 1;                  // Bit 9: (reserved)
        volatile unsigned : 1;                  // Bit 10: (reserved)
        volatile unsigned : 1;                  // Bit 11: (reserved)
        volatile unsigned : 1;                  // Bit 12: (reserved)
        volatile unsigned : 1;                  // Bit 13: (reserved)
        volatile unsigned : 1;                  // Bit 14: (reserved)
        volatile unsigned : 1;                  // Bit 15: (reserved)
    } __attribute__((packed)) bits; // INTCON4: INTERRUPT CONTROL REGISTER 4
    volatile uint16_t value;
}INTCON4_t; // INTCON4: INTERRUPT CONTROL REGISTER 4



// INTTREG: INTERRUPT CONTROL AND STATUS REGISTER

#if defined(_VHOLD)
#define REG_INTTREG_VALID_BIT_MSK   0b0010111111111111      // Fourth interrupt configuration register for read operations (incl. status bits)
#else
#define REG_INTTREG_VALID_BIT_MSK   0b0000111111111111      // Fourth interrupt configuration register for read operations (incl. status bits)
#endif
        
#define REG_INTTREG_ILR_MSK     0b0000111100000000
#define REG_INTTREG_ILR(x)      ((x << 8) & REG_INTTREG_ILR_MSK)

#define REG_INTTREG_ILR_15      0b0000111100000000
#define REG_INTTREG_ILR_14      0b0000111000000000
#define REG_INTTREG_ILR_13      0b0000110100000000
#define REG_INTTREG_ILR_12      0b0000110000000000
#define REG_INTTREG_ILR_11      0b0000101100000000
#define REG_INTTREG_ILR_10      0b0000101000000000
#define REG_INTTREG_ILR_9       0b0000100100000000
#define REG_INTTREG_ILR_8       0b0000100000000000
#define REG_INTTREG_ILR_7       0b0000011100000000
#define REG_INTTREG_ILR_6       0b0000011000000000
#define REG_INTTREG_ILR_5       0b0000010100000000
#define REG_INTTREG_ILR_4       0b0000010000000000
#define REG_INTTREG_ILR_3       0b0000001100000000
#define REG_INTTREG_ILR_2       0b0000001000000000
#define REG_INTTREG_ILR_1       0b0000000100000000
#define REG_INTTREG_ILR_0       0b0000000000000000

typedef enum {
    INTTREG_ILR_15 = 0b1111, // CPU Interrupt Priority Level is 15
    INTTREG_ILR_14 = 0b1110, // CPU Interrupt Priority Level is 14
    INTTREG_ILR_13 = 0b1101, // CPU Interrupt Priority Level is 13
    INTTREG_ILR_12 = 0b1100, // CPU Interrupt Priority Level is 12
    INTTREG_ILR_11 = 0b1011, // CPU Interrupt Priority Level is 11
    INTTREG_ILR_10 = 0b1010, // CPU Interrupt Priority Level is 10
    INTTREG_ILR_9  = 0b1001, // CPU Interrupt Priority Level is 9
    INTTREG_ILR_8  = 0b1000, // CPU Interrupt Priority Level is 8
    INTTREG_ILR_7  = 0b0111, // CPU Interrupt Priority Level is 7
    INTTREG_ILR_6  = 0b0110, // CPU Interrupt Priority Level is 6
    INTTREG_ILR_5  = 0b0101, // CPU Interrupt Priority Level is 5
    INTTREG_ILR_4  = 0b0100, // CPU Interrupt Priority Level is 4
    INTTREG_ILR_3  = 0b0011, // CPU Interrupt Priority Level is 3
    INTTREG_ILR_2  = 0b0010, // CPU Interrupt Priority Level is 2
    INTTREG_ILR_1  = 0b0001, // CPU Interrupt Priority Level is 1
    INTTREG_ILR_0  = 0b0000  // CPU Interrupt Priority Level is 0
}INTTREG_ILR_e;

#define REG_INTTREG_VECNUM_MSK  0b0000000011111111      // Fourth interrupt configuration register for read operations (incl. status bits)
#define REG_INTTREG_VECNUM(x)   (x & REG_INTTREG_VECNUM_MSK)

typedef enum {
    INTTREG_VECNUM_OSCERR = 0b00000000, // Oscillator fail trap
    INTTREG_VECNUM_ADDRERR = 0b00000001, // Address error trap
    INTTREG_VECNUM_HARD_TRAP = 0b00000010, // Generic hard trap
    INTTREG_VECNUM_STKERR = 0b00000011, // Stack error trap
    INTTREG_VECNUM_MATHERR = 0b00000100, // Math error trap
    INTTREG_VECNUM_5   = 0b00000101, // (reserved)
    INTTREG_VECNUM_SOFT_TRAP = 0b00000110, // Generic soft error trap
    INTTREG_VECNUM_7   = 0b00000111, // (reserved)
    INTTREG_VECNUM_INT0 = 0b00001000, // INT0 ? External Interrupt 0
    INTTREG_VECNUM_IC1 = 0b00001001, // IC1 ? Input Capture 1
    INTTREG_VECNUM_10  = 0b00001010, // (reserved)
    INTTREG_VECNUM_11  = 0b00001011, // (reserved)
    INTTREG_VECNUM_12  = 0b00001100, // (reserved)
    INTTREG_VECNUM_13  = 0b00001101, // (reserved)
    INTTREG_VECNUM_14  = 0b00001110, // (reserved)
    INTTREG_VECNUM_15  = 0b00001111, // (reserved)
    INTTREG_VECNUM_16  = 0b00010000, // (reserved)
    INTTREG_VECNUM_17  = 0b00010001, // (reserved)
    INTTREG_VECNUM_18  = 0b00010010, // (reserved)
    INTTREG_VECNUM_19  = 0b00010011, // (reserved)
    INTTREG_VECNUM_20  = 0b00010100, // (reserved)
    INTTREG_VECNUM_21  = 0b00010101, // (reserved)
    INTTREG_VECNUM_22  = 0b00010110, // (reserved)
    INTTREG_VECNUM_23  = 0b00010111, // (reserved)
    INTTREG_VECNUM_24  = 0b00011000, // (reserved)
    INTTREG_VECNUM_25  = 0b00011001, // (reserved)
    INTTREG_VECNUM_26  = 0b00011010, // (reserved)
    INTTREG_VECNUM_27  = 0b00011011, // (reserved)
    INTTREG_VECNUM_28  = 0b00011100, // (reserved)
    INTTREG_VECNUM_29  = 0b00011101, // (reserved)
    INTTREG_VECNUM_30  = 0b00011110, // (reserved)
    INTTREG_VECNUM_31  = 0b00011111, // (reserved)
    INTTREG_VECNUM_32  = 0b00100000, // (reserved)
    INTTREG_VECNUM_33  = 0b00100001, // (reserved)
    INTTREG_VECNUM_34  = 0b00100010, // (reserved)
    INTTREG_VECNUM_35  = 0b00100011, // (reserved)
    INTTREG_VECNUM_36  = 0b00100100, // (reserved)
    INTTREG_VECNUM_37  = 0b00100101, // (reserved)
    INTTREG_VECNUM_38  = 0b00100110, // (reserved)
    INTTREG_VECNUM_39  = 0b00100111, // (reserved)
    INTTREG_VECNUM_40  = 0b00101000, // (reserved)
    INTTREG_VECNUM_41  = 0b00101001, // (reserved)
    INTTREG_VECNUM_42  = 0b00101010, // (reserved)
    INTTREG_VECNUM_43  = 0b00101011, // (reserved)
    INTTREG_VECNUM_44  = 0b00101100, // (reserved)
    INTTREG_VECNUM_45  = 0b00101101, // (reserved)
    INTTREG_VECNUM_46  = 0b00101110, // (reserved)
    INTTREG_VECNUM_47  = 0b00101111, // (reserved)
    INTTREG_VECNUM_48  = 0b00110000, // (reserved)
    INTTREG_VECNUM_49  = 0b00110001, // (reserved)
    INTTREG_VECNUM_50  = 0b00110010, // (reserved)
    INTTREG_VECNUM_51  = 0b00110011, // (reserved)
    INTTREG_VECNUM_52  = 0b00110100, // (reserved)
    INTTREG_VECNUM_53  = 0b00110101, // (reserved)
    INTTREG_VECNUM_54  = 0b00110110, // (reserved)
    INTTREG_VECNUM_55  = 0b00110111, // (reserved)
    INTTREG_VECNUM_56  = 0b00111000, // (reserved)
    INTTREG_VECNUM_57  = 0b00111001, // (reserved)
    INTTREG_VECNUM_58  = 0b00111010, // (reserved)
    INTTREG_VECNUM_59  = 0b00111011, // (reserved)
    INTTREG_VECNUM_60  = 0b00111100, // (reserved)
    INTTREG_VECNUM_61  = 0b00111101, // (reserved)
    INTTREG_VECNUM_62  = 0b00111110, // (reserved)
    INTTREG_VECNUM_63  = 0b00111111, // (reserved)
    INTTREG_VECNUM_64  = 0b01000000, // (reserved)
    INTTREG_VECNUM_65  = 0b01000001, // (reserved)
    INTTREG_VECNUM_66  = 0b01000010, // (reserved)
    INTTREG_VECNUM_67  = 0b01000011, // (reserved)
    INTTREG_VECNUM_68  = 0b01000100, // (reserved)
    INTTREG_VECNUM_69  = 0b01000101, // (reserved)
    INTTREG_VECNUM_70  = 0b01000110, // (reserved)
    INTTREG_VECNUM_71  = 0b01000111, // (reserved)
    INTTREG_VECNUM_72  = 0b01001000, // (reserved)
    INTTREG_VECNUM_73  = 0b01001001, // (reserved)
    INTTREG_VECNUM_74  = 0b01001010, // (reserved)
    INTTREG_VECNUM_75  = 0b01001011, // (reserved)
    INTTREG_VECNUM_76  = 0b01001100, // (reserved)
    INTTREG_VECNUM_77  = 0b01001101, // (reserved)
    INTTREG_VECNUM_78  = 0b01001110, // (reserved)
    INTTREG_VECNUM_79  = 0b01001111, // (reserved)
    INTTREG_VECNUM_80  = 0b01010000, // (reserved)
    INTTREG_VECNUM_81  = 0b01010001, // (reserved)
    INTTREG_VECNUM_82  = 0b01010010, // (reserved)
    INTTREG_VECNUM_83  = 0b01010011, // (reserved)
    INTTREG_VECNUM_84  = 0b01010100, // (reserved)
    INTTREG_VECNUM_85  = 0b01010101, // (reserved)
    INTTREG_VECNUM_86  = 0b01010110, // (reserved)
    INTTREG_VECNUM_87  = 0b01010111, // (reserved)
    INTTREG_VECNUM_88  = 0b01011000, // (reserved)
    INTTREG_VECNUM_89  = 0b01011001, // (reserved)
    INTTREG_VECNUM_90  = 0b01011010, // (reserved)
    INTTREG_VECNUM_91  = 0b01011011, // (reserved)
    INTTREG_VECNUM_92  = 0b01011100, // (reserved)
    INTTREG_VECNUM_93  = 0b01011101, // (reserved)
    INTTREG_VECNUM_94  = 0b01011110, // (reserved)
    INTTREG_VECNUM_95  = 0b01011111, // (reserved)
    INTTREG_VECNUM_96  = 0b01100000, // (reserved)
    INTTREG_VECNUM_97  = 0b01100001, // (reserved)
    INTTREG_VECNUM_98  = 0b01100010, // (reserved)
    INTTREG_VECNUM_99  = 0b01100011, // (reserved)
    INTTREG_VECNUM_100 = 0b01100100, // (reserved)
    INTTREG_VECNUM_101 = 0b01100101, // (reserved)
    INTTREG_VECNUM_102 = 0b01100110, // (reserved)
    INTTREG_VECNUM_103 = 0b01100111, // (reserved)
    INTTREG_VECNUM_104 = 0b01101000, // (reserved)
    INTTREG_VECNUM_105 = 0b01101001, // (reserved)
    INTTREG_VECNUM_106 = 0b01101010, // (reserved)
    INTTREG_VECNUM_107 = 0b01101011, // (reserved)
    INTTREG_VECNUM_108 = 0b01101100, // (reserved)
    INTTREG_VECNUM_109 = 0b01101101, // (reserved)
    INTTREG_VECNUM_110 = 0b01101110, // (reserved)
    INTTREG_VECNUM_111 = 0b01101111, // (reserved)
    INTTREG_VECNUM_112 = 0b01110000, // (reserved)
    INTTREG_VECNUM_113 = 0b01110001, // (reserved)
    INTTREG_VECNUM_114 = 0b01110010, // (reserved)
    INTTREG_VECNUM_115 = 0b01110011, // (reserved)
    INTTREG_VECNUM_116 = 0b01110100, // (reserved)
    INTTREG_VECNUM_117 = 0b01110101, // (reserved)
    INTTREG_VECNUM_118 = 0b01110110, // (reserved)
    INTTREG_VECNUM_119 = 0b01110111, // (reserved)
    INTTREG_VECNUM_120 = 0b01111000, // (reserved)
    INTTREG_VECNUM_121 = 0b01111001, // (reserved)
    INTTREG_VECNUM_122 = 0b01111010, // (reserved)
    INTTREG_VECNUM_123 = 0b01111011, // (reserved)
    INTTREG_VECNUM_124 = 0b01111100, // (reserved)
    INTTREG_VECNUM_125 = 0b01111101, // (reserved)
    INTTREG_VECNUM_126 = 0b01111110, // (reserved)
    INTTREG_VECNUM_127 = 0b01111111, // (reserved)
    INTTREG_VECNUM_128 = 0b10000000, // (reserved)
    INTTREG_VECNUM_129 = 0b10000001, // (reserved)
    INTTREG_VECNUM_130 = 0b10000010, // (reserved)
    INTTREG_VECNUM_131 = 0b10000011, // (reserved)
    INTTREG_VECNUM_132 = 0b10000100, // (reserved)
    INTTREG_VECNUM_133 = 0b10000101, // (reserved)
    INTTREG_VECNUM_134 = 0b10000110, // (reserved)
    INTTREG_VECNUM_135 = 0b10000111, // (reserved)
    INTTREG_VECNUM_136 = 0b10001000, // (reserved)
    INTTREG_VECNUM_137 = 0b10001001, // (reserved)
    INTTREG_VECNUM_138 = 0b10001010, // (reserved)
    INTTREG_VECNUM_139 = 0b10001011, // (reserved)
    INTTREG_VECNUM_140 = 0b10001100, // (reserved)
    INTTREG_VECNUM_141 = 0b10001101, // (reserved)
    INTTREG_VECNUM_142 = 0b10001110, // (reserved)
    INTTREG_VECNUM_143 = 0b10001111, // (reserved)
    INTTREG_VECNUM_144 = 0b10010000, // (reserved)
    INTTREG_VECNUM_145 = 0b10010001, // (reserved)
    INTTREG_VECNUM_146 = 0b10010010, // (reserved)
    INTTREG_VECNUM_147 = 0b10010011, // (reserved)
    INTTREG_VECNUM_148 = 0b10010100, // (reserved)
    INTTREG_VECNUM_149 = 0b10010101, // (reserved)
    INTTREG_VECNUM_150 = 0b10010110, // (reserved)
    INTTREG_VECNUM_151 = 0b10010111, // (reserved)
    INTTREG_VECNUM_152 = 0b10011000, // (reserved)
    INTTREG_VECNUM_153 = 0b10011001, // (reserved)
    INTTREG_VECNUM_154 = 0b10011010, // (reserved)
    INTTREG_VECNUM_155 = 0b10011011, // (reserved)
    INTTREG_VECNUM_156 = 0b10011100, // (reserved)
    INTTREG_VECNUM_157 = 0b10011101, // (reserved)
    INTTREG_VECNUM_158 = 0b10011110, // (reserved)
    INTTREG_VECNUM_159 = 0b10011111, // (reserved)
    INTTREG_VECNUM_160 = 0b10100000, // (reserved)
    INTTREG_VECNUM_161 = 0b10100001, // (reserved)
    INTTREG_VECNUM_162 = 0b10100010, // (reserved)
    INTTREG_VECNUM_163 = 0b10100011, // (reserved)
    INTTREG_VECNUM_164 = 0b10100100, // (reserved)
    INTTREG_VECNUM_165 = 0b10100101, // (reserved)
    INTTREG_VECNUM_166 = 0b10100110, // (reserved)
    INTTREG_VECNUM_167 = 0b10100111, // (reserved)
    INTTREG_VECNUM_168 = 0b10101000, // (reserved)
    INTTREG_VECNUM_169 = 0b10101001, // (reserved)
    INTTREG_VECNUM_170 = 0b10101010, // (reserved)
    INTTREG_VECNUM_171 = 0b10101011, // (reserved)
    INTTREG_VECNUM_172 = 0b10101100, // (reserved)
    INTTREG_VECNUM_173 = 0b10101101, // (reserved)
    INTTREG_VECNUM_174 = 0b10101110, // (reserved)
    INTTREG_VECNUM_175 = 0b10101111, // (reserved)
    INTTREG_VECNUM_176 = 0b10110000, // (reserved)
    INTTREG_VECNUM_177 = 0b10110001, // (reserved)
    INTTREG_VECNUM_178 = 0b10110010, // (reserved)
    INTTREG_VECNUM_179 = 0b10110011, // (reserved)
    INTTREG_VECNUM_180 = 0b10110100, // (reserved)
    INTTREG_VECNUM_181 = 0b10110101, // (reserved)
    INTTREG_VECNUM_182 = 0b10110110, // (reserved)
    INTTREG_VECNUM_183 = 0b10110111, // (reserved)
    INTTREG_VECNUM_184 = 0b10111000, // (reserved)
    INTTREG_VECNUM_185 = 0b10111001, // (reserved)
    INTTREG_VECNUM_186 = 0b10111010, // (reserved)
    INTTREG_VECNUM_187 = 0b10111011, // (reserved)
    INTTREG_VECNUM_188 = 0b10111100, // (reserved)
    INTTREG_VECNUM_189 = 0b10111101, // (reserved)
    INTTREG_VECNUM_190 = 0b10111110, // (reserved)
    INTTREG_VECNUM_191 = 0b10111111, // (reserved)
    INTTREG_VECNUM_192 = 0b11000000, // (reserved)
    INTTREG_VECNUM_193 = 0b11000001, // (reserved)
    INTTREG_VECNUM_194 = 0b11000010, // (reserved)
    INTTREG_VECNUM_195 = 0b11000011, // (reserved)
    INTTREG_VECNUM_196 = 0b11000100, // (reserved)
    INTTREG_VECNUM_197 = 0b11000101, // (reserved)
    INTTREG_VECNUM_198 = 0b11000110, // (reserved)
    INTTREG_VECNUM_199 = 0b11000111, // (reserved)
    INTTREG_VECNUM_200 = 0b11001000, // (reserved)
    INTTREG_VECNUM_201 = 0b11001001, // (reserved)
    INTTREG_VECNUM_202 = 0b11001010, // (reserved)
    INTTREG_VECNUM_203 = 0b11001011, // (reserved)
    INTTREG_VECNUM_204 = 0b11001100, // (reserved)
    INTTREG_VECNUM_205 = 0b11001101, // (reserved)
    INTTREG_VECNUM_206 = 0b11001110, // (reserved)
    INTTREG_VECNUM_207 = 0b11001111, // (reserved)
    INTTREG_VECNUM_208 = 0b11010000, // (reserved)
    INTTREG_VECNUM_209 = 0b11010001, // (reserved)
    INTTREG_VECNUM_210 = 0b11010010, // (reserved)
    INTTREG_VECNUM_211 = 0b11010011, // (reserved)
    INTTREG_VECNUM_212 = 0b11010100, // (reserved)
    INTTREG_VECNUM_213 = 0b11010101, // (reserved)
    INTTREG_VECNUM_214 = 0b11010110, // (reserved)
    INTTREG_VECNUM_215 = 0b11010111, // (reserved)
    INTTREG_VECNUM_216 = 0b11011000, // (reserved)
    INTTREG_VECNUM_217 = 0b11011001, // (reserved)
    INTTREG_VECNUM_218 = 0b11011010, // (reserved)
    INTTREG_VECNUM_219 = 0b11011011, // (reserved)
    INTTREG_VECNUM_220 = 0b11011100, // (reserved)
    INTTREG_VECNUM_221 = 0b11011101, // (reserved)
    INTTREG_VECNUM_222 = 0b11011110, // (reserved)
    INTTREG_VECNUM_223 = 0b11011111, // (reserved)
    INTTREG_VECNUM_224 = 0b11100000, // (reserved)
    INTTREG_VECNUM_225 = 0b11100001, // (reserved)
    INTTREG_VECNUM_226 = 0b11100010, // (reserved)
    INTTREG_VECNUM_227 = 0b11100011, // (reserved)
    INTTREG_VECNUM_228 = 0b11100100, // (reserved)
    INTTREG_VECNUM_229 = 0b11100101, // (reserved)
    INTTREG_VECNUM_230 = 0b11100110, // (reserved)
    INTTREG_VECNUM_231 = 0b11100111, // (reserved)
    INTTREG_VECNUM_232 = 0b11101000, // (reserved)
    INTTREG_VECNUM_233 = 0b11101001, // (reserved)
    INTTREG_VECNUM_234 = 0b11101010, // (reserved)
    INTTREG_VECNUM_235 = 0b11101011, // (reserved)
    INTTREG_VECNUM_236 = 0b11101100, // (reserved)
    INTTREG_VECNUM_237 = 0b11101101, // (reserved)
    INTTREG_VECNUM_238 = 0b11101110, // (reserved)
    INTTREG_VECNUM_239 = 0b11101111, // (reserved)
    INTTREG_VECNUM_240 = 0b11110000, // (reserved)
    INTTREG_VECNUM_241 = 0b11110001, // (reserved)
    INTTREG_VECNUM_242 = 0b11110010, // (reserved)
    INTTREG_VECNUM_243 = 0b11110011, // (reserved)
    INTTREG_VECNUM_244 = 0b11110100, // (reserved)
    INTTREG_VECNUM_245 = 0b11110101, // (reserved)
    INTTREG_VECNUM_246 = 0b11110110, // (reserved)
    INTTREG_VECNUM_247 = 0b11110111, // (reserved)
    INTTREG_VECNUM_248 = 0b11111000, // (reserved)
    INTTREG_VECNUM_249 = 0b11111001, // (reserved)
    INTTREG_VECNUM_250 = 0b11111010, // (reserved)
    INTTREG_VECNUM_251 = 0b11111011, // (reserved)
    INTTREG_VECNUM_252 = 0b11111100, // (reserved)
    INTTREG_VECNUM_253 = 0b11111101, // (reserved)
    INTTREG_VECNUM_254 = 0b11111110, // (reserved)
    INTTREG_VECNUM_255 = 0b11111111, // (reserved)
}INTTREG_VECNUM_e;

typedef enum {
    INTTREG_VHOLD_ENABLED = 0b1, // VECNUM<7:0> bits read current value of vector number encoding tree (i.e., highest priority pending interrupt)
    INTTREG_VHOLD_DISABLED = 0b0  // Vector number latched into VECNUM<7:0> at Interrupt Acknowledge and retained until next IACK
}INTTREG_VHOLD_e;

typedef union {
    struct {
        volatile INTTREG_VECNUM_e VECNUM : 8;   // Bit 7-0: Vector Number of Pending Interrupt bits
        volatile INTTREG_ILR_e ILR : 4;         // Bit 11-8: New CPU Interrupt Priority Level bits
        volatile unsigned : 1;                  // Bit 12: (reserved)
        volatile INTTREG_VHOLD_e VHOLD : 1;     // Bit 13: Vector Number Capture Enable bit
        volatile unsigned : 1;                  // Bit 14: (reserved)
        volatile unsigned : 1;                  // Bit 15: (reserved)
    } __attribute__((packed)) bits; // INTTREG: INTERRUPT CONTROL AND STATUS REGISTER
    volatile uint16_t value;
}INTTREG_t; // INTTREG: INTERRUPT CONTROL AND STATUS REGISTER

typedef struct {
    INTCON1_t intcon1; // INTCON1: INTERRUPT CONTROL REGISTER 1
    INTCON2_t intcon2; // INTCON2: INTERRUPT CONTROL REGISTER 2
    INTCON3_t intcon3; // INTCON3: INTERRUPT CONTROL REGISTER 3
    INTCON4_t intcon4; // INTCON4: INTERRUPT CONTROL REGISTER 4
    INTTREG_t inttreg; // INTERRUPT CONTROL AND STATUS REGISTER
}INTERRUPT_CONFIG_t; // Interrupt Controller Configuration Register Set


extern volatile uint16_t gsirq_irq_initialize(volatile INTERRUPT_CONFIG_t intcon);
extern volatile uint16_t gsirq_get_current_irq_priority_level(void);
extern volatile uint16_t gsirq_get_current_irq_vector(void);
extern volatile uint16_t gsirq_soft_traps_initialize(
                    uint16_t accumulator_a_overflow_trap_enable, 
                    uint16_t accumulator_b_overflow_trap_enable, 
                    uint16_t accumulator_catastrophic_overflow_trap_enable
                    );


#endif	/* _P33GS_INTERRUPT_CONFIG_DEF_H_ */

