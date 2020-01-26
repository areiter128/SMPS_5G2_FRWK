/*LICENSE *****************************************************************************************
 *
 * Software License Agreement
 *
 * Copyright (R) 2018 Microchip Technology Inc.  All rights reserved. Microchip licenses to you the
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

#ifndef MCAL_P33SMPS_HSPWM_H
#define MCAL_P33SMPS_HSPWM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h> // include standard integer types header file
#include <stdbool.h> // include standard boolean types header file

#include "../p33SMPS_devices.h" // DEVICES header to derive device-dependent properties

/*!p33MP_hspwm.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33CH/CKxxMP-PWM SFRs
 *
 * Description:
 * The SMPS PWM module offers a large number of registers and configuration options. This additional
 * header file contains defines for all required settings. This additional
 * header file contains defines for all required bit-settings of all related registers.
 * This file is an additional header file on top of the generic device header file.
 * ***********************************************************************************************/

#define HSPWM_OVERRIDE_ENABLE     1
#define HSPWM_OVERRIDE_DISABLE    0

#define HSPWM_PMD_POWER_ENABLE    0
#define HSPWM_PMD_POWER_DISABLE   1

#define _HSPWM_POWER_ENABLE     {_PWMMD = 0;}
#define _HSPWM_POWER_DISABLE    {_PWMMD = 1;}


#define REG_PGxPER_VALID_DATA_WRITE_MASK   0xFFFF
#define REG_PGxPER_VALID_DATA_READ_MASK    0xFFFF
#define REG_PGxDC_VALID_DATA_WRITE_MASK    0xFFFF
#define REG_PGxDC_VALID_DATA_READ_MASK     0xFFFF
#define REG_PGxPHASE_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxPHASE_VALID_DATA_READ_MASK  0xFFFF

/* ===========================================================================
 * PCLKCON: PWM MODULE CONTROL REGISTER
 * ===========================================================================*/
#define REG_PCLKCON_VALID_DATA_WRITE_MASK 0xC133
#define REG_PCLKCON_VALID_DATA_READ_MASK  0xC133

#define REG_PCLKCON_MCLKSEL_AFPLLO     0b0000000000000011
#define REG_PCLKCON_MCLKSEL_FPLLO      0b0000000000000010
#define REG_PCLKCON_MCLKSEL_AFVCO_BY_2 0b0000000000000001
#define REG_PCLKCON_MCLKSEL_FOSC       0b0000000000000000

typedef enum {
    PCLKCON_MCLKSEL_AFPLLO = 0b11, // AFPLLO ? Auxiliary PLL post-divider output
    PCLKCON_MCLKSEL_FPLLO = 0b10, // FPLLO ? Primary PLL post-divider output
    PCLKCON_MCLKSEL_AFVCO_BY_2 = 0b01, // AFVCO/2 ? Auxiliary VCO/2
    PCLKCON_MCLKSEL_FOSC = 0b00 // FOSC
} PCLKCON_MCLKSEL_e; // PWM Master Clock Selection bits

#define REG_PCLKCON_DIVSEL_DIV_16 0b0000000000110000
#define REG_PCLKCON_DIVSEL_DIV_8  0b0000000000100000
#define REG_PCLKCON_DIVSEL_DIV_4  0b0000000000010000
#define REG_PCLKCON_DIVSEL_DIV_2  0b0000000000000000

typedef enum {
    PCLKCON_DIVSEL_DIV_16 = 0b11, // Divide ratio is 1:16
    PCLKCON_DIVSEL_DIV_8 = 0b10, // Divide ratio is 1:8
    PCLKCON_DIVSEL_DIV_4 = 0b01, // Divide ratio is 1:4
    PCLKCON_DIVSEL_DIV_2 = 0b00 // Divide ratio is 1:2
} PCLKCON_DIVSEL_e; // PWM Clock Divider Selection bits

#define REG_PCLKCON_LOCK_LOCKED   0b0000000100000000
#define REG_PCLKCON_LOCK_UNLOCKED 0b0000000000000000

typedef enum {
    PCLKCON_LOCK_LOCKED = 0b1, // Write-protected registers and bits are locked
    PCLKCON_LOCK_UNLOCKED = 0b0 // Write-protected registers and bits are unlocked
} PCLKCON_LOCK_e; // Register write-protection lock bit

#define REG_PCLKCON_HRERR_ERROR      0b0100000000000000
#define REG_PCLKCON_HRERR_NO_ERROR   0b0000000000000000

typedef enum {
    PCLKCON_HRERR_ERROR = 0b1, // An error has occurred; PWM signals will have limited resolution
    PCLKCON_HRERR_NO_ERROR = 0b0 // No error has occurred; PWM signals will have full resolution when HRRDY = 1
} PCLKCON_HRERR_e; // High-Resolution Error bit

#define REG_PCLKCON_HRRDY_READY  0b1000000000000000
#define REG_PCLKCON_HRRDY_WAIT   0b0000000000000000

typedef enum {
    PCLKCON_HRRDY_READY = 0b1, // The high-resolution circuitry is ready
    PCLKCON_HRRDY_WAIT = 0b0 // The high-resolution circuitry is not ready
} PCLKCON_HRRDY_e; // High-Resolution Ready bit


typedef union {
    struct {
        volatile PCLKCON_MCLKSEL_e MCLKSEL : 2; // PWM Master Clock Selection bits
        volatile unsigned : 2;
        volatile PCLKCON_DIVSEL_e DIVSEL : 2; // PWM Clock Divider Selection bits
        volatile unsigned : 2;
        volatile PCLKCON_LOCK_e LOCK : 1; // Register write protection Lock bit
        volatile unsigned : 5;
        volatile PCLKCON_HRERR_e HRERR : 1; // High-Resolution Error bit
        volatile PCLKCON_HRRDY_e HRRDY : 1; // High-Resolution Ready bit
    } __attribute__((packed)) bits; // PWM CLOCK CONTROL REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} PCLKCON_t; // PWM CLOCK CONTROL REGISTER

/* ===========================================================================
 * FSCL: FREQUENCY SCALE REGISTER
 * ===========================================================================*/
#define REG_FSCL_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_FSCL_VALID_DATA_READ_MASK  0xFFFF

typedef union {
    struct {
        volatile uint16_t FSCL; // <15:0>: Frequency Scale Register
    } __attribute__((packed)) bits;   // PWM FREQUENCY SCALE REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} FSCL_t;   // PWM FREQUENCY SCALE REGISTER

/* ===========================================================================
 * FSMINPER: FREQUENCY SCALING MINIMUM PERIOD REGISTER
 * ===========================================================================*/
#define REG_FSMINPER_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_FSMINPER_VALID_DATA_READ_MASK  0xFFFF

typedef union {
    struct {
        volatile uint16_t FSMINPER; // <15:0>: Frequency Scaling Minimum Period Register bits
    } __attribute__((packed)) bits;   // PWM FREQUENCY SCALING MINIMUM PERIOD REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} FSMINPER_t;   // PWM FREQUENCY SCALING MINIMUM PERIOD REGISTER

/* ===========================================================================
 * MPHASE: MASTER PHASE REGISTER
 * ===========================================================================*/
#define REG_MPHASE_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_MPHASE_VALID_DATA_READ_MASK  0xFFFF

typedef union {
    struct {
        volatile uint16_t MPHASE; // <15:0>: Master Phase Register bits
    } __attribute__((packed)) bits;   // MPHASE: MASTER PHASE REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} MPHASE_t;   // MPHASE: MASTER PHASE REGISTER

/* ===========================================================================
 * MDC: MASTER DUTY CYCLE REGISTER
 * ===========================================================================*/
#define REG_MDC_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_MDC_VALID_DATA_READ_MASK  0xFFFF

typedef union {
    struct {
        volatile uint16_t MDC; // <15:0>: Master Duty Cycle Register bits
    } __attribute__((packed)) bits;   // MDC: MASTER DUTY CYCLE REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} MDC_t;   // MDC: MASTER DUTY CYCLE REGISTER

/* ===========================================================================
 * MPER: MASTER PERIOD REGISTER
 * ===========================================================================*/
#define REG_MPER_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_MPER_VALID_DATA_READ_MASK  0xFFFF

typedef union {
    struct {
        volatile uint16_t MPER; // <15:0>: Master Period Register bits
    } __attribute__((packed)) MPER_t;   // MPER: MASTER PERIOD REGISTER
    volatile uint16_t value; // 16-bit register direct write access
} MPER_t;   // MPER: MASTER PERIOD REGISTER

/* ===========================================================================
 * LFSR: LINEAR FEEDBACK SHIFT REGISTER
 * ===========================================================================*/
#define REG_LFSR_VALID_DATA_WRITE_MASK 0x7FFF
#define REG_LFSR_VALID_DATA_READ_MASK  0x7FFF

typedef union {
    struct {
        volatile uint16_t LFSR; // Bit <14:0>: Linear Feedback Shift Register bits
        volatile unsigned  : 1; // Bit 15: (reserved)
    } __attribute__((packed)) bits;   // LFSR: LINEAR FEEDBACK SHIFT REGISTER
    volatile uint16_t value; // 16-bit register direct read/write access
} LFSR_t;   // LFSR: LINEAR FEEDBACK SHIFT REGISTER

/* ======================================================================================================
 * CMBTRIGL/H: COMBINATIONAL TRIGGER REGISTER LOW/HIGH
 * =================================================================================================== */
#define REG_CMBTRIGy_VALID_DATA_WRITE_MASK 0x00FF
#define REG_CMBTRIGy_VALID_DATA_READ_MASK  0x00FF

#define REG_CMBTRIG_VALID_DATA_WRITE_MASK 0x00FF00FF
#define REG_CMBTRIG_VALID_DATA_READ_MASK  0x00FF00FF

#define REG_CMBTRIG_CTA_PG1_ENABLE_ON  0b0000000000000001 // Enable Trigger Output from PWM Generator #1 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG1_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #1 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG2_ENABLE_ON  0b0000000000000010 // Enable Trigger Output from PWM Generator #2 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG2_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #2 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG3_ENABLE_ON  0b0000000000000100 // Enable Trigger Output from PWM Generator #3 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG3_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #3 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG4_ENABLE_ON  0b0000000000001000 // Enable Trigger Output from PWM Generator #4 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG4_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #4 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG5_ENABLE_ON  0b0000000000010000 // Enable Trigger Output from PWM Generator #5 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG5_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #5 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG6_ENABLE_ON  0b0000000000100000 // Enable Trigger Output from PWM Generator #6 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG6A_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #6 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG7_ENABLE_ON  0b0000000001000000 // Enable Trigger Output from PWM Generator #7 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG7_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #7 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG8_ENABLE_ON  0b0000000010000000 // Enable Trigger Output from PWM Generator #8 as Source for Combinational Trigger A
#define REG_CMBTRIG_CTA_PG8_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #8 as Source for Combinational Trigger A

#define REG_CMBTRIG_CTB_PG1_ENABLE_ON  0b0000000000000001 // Enable Trigger Output from PWM Generator #1 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG1_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #1 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG2_ENABLE_ON  0b0000000000000010 // Enable Trigger Output from PWM Generator #2 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG2_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #2 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG3_ENABLE_ON  0b0000000000000100 // Enable Trigger Output from PWM Generator #3 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG3_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #3 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG4_ENABLE_ON  0b0000000000001000 // Enable Trigger Output from PWM Generator #4 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG4_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #4 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG5_ENABLE_ON  0b0000000000010000 // Enable Trigger Output from PWM Generator #5 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG5_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #5 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG6_ENABLE_ON  0b0000000000100000 // Enable Trigger Output from PWM Generator #6 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG6_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #6 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG7_ENABLE_ON  0b0000000001000000 // Enable Trigger Output from PWM Generator #7 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG7_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #7 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG8_ENABLE_ON  0b0000000010000000 // Enable Trigger Output from PWM Generator #8 as Source for Combinational Trigger B
#define REG_CMBTRIG_CTB_PG8_ENABLE_OFF 0b0000000000000000 // Disable Trigger Output from PWM Generator #8 as Source for Combinational Trigger B

typedef enum {
    CMBTRIG_CTy_PGx_ENABLED  = 0b1, // Enable Trigger Output from PWM Generator x as Source for Combinational Trigger A
    CMBTRIG_CTy_PGx_DISABLED = 0b0  // Disable Trigger Output from PWM Generator x as Source for Combinational Trigger A
} CMBTRIG_CTy_PGx_ENABLE_e; // Enables specified PWM generator X trigger signal to be OR?d into the Combinatorial Trigger A signal

typedef struct {
    
    // CMBTRIGL/H
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG8_CTRIG_EN : 1; // Bit 0: Trigger Output from PWM Generator 8 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG7_CTRIG_EN : 1; // Bit 1: Trigger Output from PWM Generator 7 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG6_CTRIG_EN : 1; // Bit 2: Trigger Output from PWM Generator 6 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG5_CTRIG_EN : 1; // Bit 3: Trigger Output from PWM Generator 5 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG4_CTRIG_EN : 1; // Bit 4: Trigger Output from PWM Generator 4 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG3_CTRIG_EN : 1; // Bit 5: Trigger Output from PWM Generator 3 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG2_CTRIG_EN : 1; // Bit 6: Trigger Output from PWM Generator 2 as Source for Combinatorial Trigger A
    volatile CMBTRIG_CTy_PGx_ENABLE_e PG1_CTRIG_EN : 1; // Bit 7: Trigger Output from PWM Generator 1 as Source for Combinatorial Trigger A
    volatile unsigned : 8;  // Bit 15-8: (reserved)

} __attribute__((packed)) CMBTRIGy_ENABLE_t; // COMBINATIONAL TRIGGER REGISTER ENABLE BITS

typedef union {
    struct {
        volatile CMBTRIGy_ENABLE_t CTBxEN; // COMBINATIONAL TRIGGER ENABLE REGISTER bits
        volatile CMBTRIGy_ENABLE_t CTAxEN; // COMBINATIONAL TRIGGER ENABLE REGISTER bits
    } __attribute__((packed)) CMBTRIGy_t;  // COMBINATIONAL TRIGGER ENABLE REGISTER 
    volatile uint32_t value; // register value
} CMBTRIGy_t;  // COMBINATIONAL TRIGGER ENABLE REGISTER 

/* ===========================================================================
 * LOGCONy: COMBINATORIAL PWM LOGIC CONTROL REGISTER y (y=A, B, C, D ,E or F)
 * ===========================================================================*/
#define REG_LOGCONy_VALID_DATA_WRITE_MASK 0xFFF7
#define REG_LOGCONy_VALID_DATA_READ_MASK  0xFFF7

#define REG_LOGCON_PWMS1_PWM8L	0b1111000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM8L
#define REG_LOGCON_PWMS1_PWM8H	0b1110000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM8H
#define REG_LOGCON_PWMS1_PWM7L	0b1101000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM7L
#define REG_LOGCON_PWMS1_PWM7H	0b1100000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM7H
#define REG_LOGCON_PWMS1_PWM6L	0b1011000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM6L
#define REG_LOGCON_PWMS1_PWM6H	0b1010000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM6H
#define REG_LOGCON_PWMS1_PWM5L	0b1001000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM5L
#define REG_LOGCON_PWMS1_PWM5H	0b1000000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM5H
#define REG_LOGCON_PWMS1_PWM4L	0b0111000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM4L
#define REG_LOGCON_PWMS1_PWM4H	0b0110000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM4H
#define REG_LOGCON_PWMS1_PWM3L	0b0101000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM3L
#define REG_LOGCON_PWMS1_PWM3H	0b0100000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM3H
#define REG_LOGCON_PWMS1_PWM2L	0b0011000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM2L
#define REG_LOGCON_PWMS1_PWM2H	0b0010000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM2H
#define REG_LOGCON_PWMS1_PWM1L	0b0001000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM1L
#define REG_LOGCON_PWMS1_PWM1H	0b0000000000000000  // Combinatorial PWM Logic Source #1 Selection is PWM1H

#define REG_LOGCON_PWMS2_PWM8L	0b0000111100000000  // Combinatorial PWM Logic Source #2 Selection is PWM8L
#define REG_LOGCON_PWMS2_PWM8H	0b0000111000000000  // Combinatorial PWM Logic Source #2 Selection is PWM8H
#define REG_LOGCON_PWMS2_PWM7L	0b0000110100000000  // Combinatorial PWM Logic Source #2 Selection is PWM7L
#define REG_LOGCON_PWMS2_PWM7H	0b0000110000000000  // Combinatorial PWM Logic Source #2 Selection is PWM7H
#define REG_LOGCON_PWMS2_PWM6L	0b0000101100000000  // Combinatorial PWM Logic Source #2 Selection is PWM6L
#define REG_LOGCON_PWMS2_PWM6H	0b0000101000000000  // Combinatorial PWM Logic Source #2 Selection is PWM6H
#define REG_LOGCON_PWMS2_PWM5L	0b0000100100000000  // Combinatorial PWM Logic Source #2 Selection is PWM5L
#define REG_LOGCON_PWMS2_PWM5H	0b0000100000000000  // Combinatorial PWM Logic Source #2 Selection is PWM5H
#define REG_LOGCON_PWMS2_PWM4L	0b0000011100000000  // Combinatorial PWM Logic Source #2 Selection is PWM4L
#define REG_LOGCON_PWMS2_PWM4H	0b0000011000000000  // Combinatorial PWM Logic Source #2 Selection is PWM4H
#define REG_LOGCON_PWMS2_PWM3L	0b0000010100000000  // Combinatorial PWM Logic Source #2 Selection is PWM3L
#define REG_LOGCON_PWMS2_PWM3H	0b0000010000000000  // Combinatorial PWM Logic Source #2 Selection is PWM3H
#define REG_LOGCON_PWMS2_PWM2L	0b0000001100000000  // Combinatorial PWM Logic Source #2 Selection is PWM2L
#define REG_LOGCON_PWMS2_PWM2H	0b0000001000000000  // Combinatorial PWM Logic Source #2 Selection is PWM2H
#define REG_LOGCON_PWMS2_PWM1L	0b0000000100000000  // Combinatorial PWM Logic Source #2 Selection is PWM1L
#define REG_LOGCON_PWMS2_PWM1H	0b0000000000000000  // Combinatorial PWM Logic Source #2 Selection is PWM1H

typedef enum {
    LOGCON_PWMSx_PWM8L = 0b1111, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM8L
    LOGCON_PWMSx_PWM8H = 0b1110, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM8H
    LOGCON_PWMSx_PWM7L = 0b1101, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM7L
    LOGCON_PWMSx_PWM7H = 0b1100, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM7H
    LOGCON_PWMSx_PWM6L = 0b1011, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM6L
    LOGCON_PWMSx_PWM6H = 0b1010, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM6H
    LOGCON_PWMSx_PWM5L = 0b1001, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM5L
    LOGCON_PWMSx_PWM5H = 0b1000, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM5H
    LOGCON_PWMSx_PWM4L = 0b0111, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM4L
    LOGCON_PWMSx_PWM4H = 0b0110, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM4H
    LOGCON_PWMSx_PWM3L = 0b0101, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM3L
    LOGCON_PWMSx_PWM3H = 0b0100, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM3H
    LOGCON_PWMSx_PWM2L = 0b0011, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM2L
    LOGCON_PWMSx_PWM2H = 0b0010, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM2H
    LOGCON_PWMSx_PWM1L = 0b0001, // Combinatorial PWM Logic Source #1 or #2 Selection is PWM1L
    LOGCON_PWMSx_PWM1H = 0b0000  // Combinatorial PWM Logic Source #1 or #2 Selection is PWM1H
} LOGCON_SRC_e; // List of comCinatorial PWM Logic Sources


#define REG_LOGCON_S1yPOL_INVETED       0b0000000010000000 // Combinatorial PWM Logic Source #1 Polarity is inverted
#define REG_LOGCON_S1yPOL_NOT_INVETED   0b0000000000000000 // Combinatorial PWM Logic Source #1 Polarity is not inverted
#define REG_LOGCON_S2yPOL_INVETED       0b0000000001000000 // Combinatorial PWM Logic Source #2 Polarity is inverted
#define REG_LOGCON_S2yPOL_NOT_INVETED   0b0000000000000000 // Combinatorial PWM Logic Source #2 Polarity is not inverted

typedef enum {
    LOGCON_SxPOL_INVETED = 1,       // Combinatorial PWM Logic Source Polarity is inverted
    LOGCON_SxPOL_NOT_INVETED = 0    // Combinatorial PWM Logic Source Polarity is not inverted
}LOGCON_SPOL_e; // Combinatorial PWM Logic Source Polarity bit


#define REG_LOGCON_PWMLF_S1_XOR_S2  0b0000000000100000  // PWMS1y ^ PWMS2y (XOR)
#define REG_LOGCON_PWMLF_S1_AND_S2  0b0000000000010000  // PWMS1y & PWMS2y (AND)
#define REG_LOGCON_PWMLF_S1_OR_S2   0b0000000000000000  // PWMS1y | PWMS2y (OR)

typedef enum {
    LOGCON_PWMLF_S1_XOR_S2 = 0b010, // PWMS1y ^ PWMS2y (XOR)
    LOGCON_PWMLF_S1_AND_S2 = 0b001, // PWMS1y & PWMS2y (AND)
    LOGCON_PWMLF_S1_OR_S2  = 0b000  // PWMS1y | PWMS2y (OR)
}LOGCON_LOGFUN_e; // Combinatorial PWM Logic Source Polarity bit


#define REG_LOGCON_PWMLFD_PWM8   0b0000000000000111  // Logic function is assigned to PWM8H or PWM8L pin
#define REG_LOGCON_PWMLFD_PWM7   0b0000000000000110  // Logic function is assigned to PWM7H or PWM7L pin
#define REG_LOGCON_PWMLFD_PWM6   0b0000000000000101  // Logic function is assigned to PWM6H or PWM6L pin
#define REG_LOGCON_PWMLFD_PWM5   0b0000000000000100  // Logic function is assigned to PWM5H or PWM5L pin
#define REG_LOGCON_PWMLFD_PWM4   0b0000000000000011  // Logic function is assigned to PWM4H or PWM4L pin
#define REG_LOGCON_PWMLFD_PWM3   0b0000000000000010  // Logic function is assigned to PWM3H or PWM3L pin
#define REG_LOGCON_PWMLFD_PWM2   0b0000000000000001  // Logic function is assigned to PWM2H or PWM2L pin
#define REG_LOGCON_PWMLFD_NONE   0b0000000000000000  // No assignment, combinatorial PWM logic function is disabled

typedef enum {
    LOGCON_PWMLFD_PWM8 = 0b111, // Logic function is assigned to PWM8H or PWM8L pin
    LOGCON_PWMLFD_PWM7 = 0b110, // Logic function is assigned to PWM7H or PWM7L pin
    LOGCON_PWMLFD_PWM6 = 0b101, // Logic function is assigned to PWM6H or PWM6L pin
    LOGCON_PWMLFD_PWM5 = 0b100, // Logic function is assigned to PWM5H or PWM5L pin
    LOGCON_PWMLFD_PWM4 = 0b011, // Logic function is assigned to PWM4H or PWM4L pin
    LOGCON_PWMLFD_PWM3 = 0b010, // Logic function is assigned to PWM3H or PWM3L pin
    LOGCON_PWMLFD_PWM2 = 0b001, // Logic function is assigned to PWM2H or PWM2L pin
    LOGCON_PWMLFD_NONE = 0b000, // No assignment, combinatorial PWM logic function is disabled    LOGCON_SxPOL_INVETED = 1,       // Combinatorial PWM Logic Source Polarity is inverted
}LOGCON_LOGDIR_e; // Combinatorial PWM Logic Destination Selection bits


typedef union {
    struct {
        volatile LOGCON_LOGDIR_e PWMLFD : 3; // Bit 2-0: Combinatorial PWM Logic Function Selection bits
        volatile unsigned : 1;              // Bit 3: (reserved)
        volatile LOGCON_LOGFUN_e PWMLF : 2; // Bit 5-4: Combinatorial PWM Logic Function Selection bits
        volatile LOGCON_SPOL_e S2POL : 1;   // Bit 6: Combinatorial PWM Logic Source #2 Polarity bit
        volatile LOGCON_SPOL_e S1POL : 1;   // Bit 7: Combinatorial PWM Logic Source #1 Polarity bit
        volatile LOGCON_SRC_e  PWMS2 : 4;   // Bit 11-8:  Combinatorial PWM Logic Source #2 Selection bits
        volatile LOGCON_SRC_e  PWMS1 : 4;   // Bit 15-12: Combinatorial PWM Logic Source #1 Selection bits
    } __attribute__((packed)) bits; // COMBINATIONAL TRIGGER REGISTERS HIGH and LOW
    volatile uint32_t value;  // Combinatorial PWM Logic control register value
} LOGCONy_t; // COMBINATIONAL PWM LOGIC CONTROL REGISTERS HIGH and LOW


/* ===========================================================================
 * PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER y (y=A, B, C, D ,E or F)
 * ===========================================================================*/
#define REG_PWMEVTy_VALID_DATA_WRITE_MASK 0xF0F7
#define REG_PWMEVTy_VALID_DATA_READ_MASK 0xF0F7

#define REG_PWMEVTy_EVTyPGS_PG8 0b0000000000000111 // PG8 is event source
#define REG_PWMEVTy_EVTyPGS_PG7 0b0000000000000110 // PG7 is event source
#define REG_PWMEVTy_EVTyPGS_PG6 0b0000000000000101 // PG6 is event source
#define REG_PWMEVTy_EVTyPGS_PG5 0b0000000000000100 // PG5 is event source
#define REG_PWMEVTy_EVTyPGS_PG4 0b0000000000000011 // PG4 is event source
#define REG_PWMEVTy_EVTyPGS_PG3 0b0000000000000010 // PG3 is event source
#define REG_PWMEVTy_EVTyPGS_PG2 0b0000000000000001 // PG2 is event source
#define REG_PWMEVTy_EVTyPGS_PG1 0b0000000000000000 // PG1 is event source

typedef enum {
    PWMEVTy_EVTyPGS_PG8 = 0b111, // PG8 is event source
    PWMEVTy_EVTyPGS_PG7 = 0b110, // PG7 is event source
    PWMEVTy_EVTyPGS_PG6 = 0b101, // PG6 is event source
    PWMEVTy_EVTyPGS_PG5 = 0b100, // PG5 is event source
    PWMEVTy_EVTyPGS_PG4 = 0b011, // PG4 is event source
    PWMEVTy_EVTyPGS_PG3 = 0b010, // PG3 is event source
    PWMEVTy_EVTyPGS_PG2 = 0b001, // PG2 is event source
    PWMEVTy_EVTyPGS_PG1 = 0b000  // PG1 is event source
}EVTyPGS_e; // PWM Event Source Selection bits


#define REG_PWMEVTy_EVTySEL_HIGH_RED_ERROR 0b0000000011110000 // High-resolution error event signal
#define REG_PWMEVTy_EVTySEL_ADC_TRIGGER_2 0b0000000010010000 // ADC Trigger 2 signal
#define REG_PWMEVTy_EVTySEL_ADC_TRIGGER_1 0b0000000010000000 // ADC Trigger 1 signal
#define REG_PWMEVTy_EVTySEL_STEER 0b0000000001110000 // STEER signal (available in Push-Pull Output modes only)(4)
#define REG_PWMEVTy_EVTySEL_CAHALF 0b0000000001100000 // CAHALF signal (available in Center-Aligned modes only)(4)
#define REG_PWMEVTy_EVTySEL_PCI_FAULT 0b0000000001010000 // PCI Fault active output signal
#define REG_PWMEVTy_EVTySEL_PCI_CL 0b0000000001000000 // PCI current-limit active output signal
#define REG_PWMEVTy_EVTySEL_PCI_FF 0b0000000000110000 // PCI feed-forward active output signal
#define REG_PWMEVTy_EVTySEL_PCI_SYNC 0b0000000000100000 // PCI Sync active output signal
#define REG_PWMEVTy_EVTySEL_PWM_OUT 0b0000000000010000 // PWM Generator output signal(3)
#define REG_PWMEVTy_EVTySEL_PGTRGSEL 0b0000000000000000 // Source is selected by the PGTRGSEL<2:0> bits    

typedef enum {
    PWMEVTy_EVTySEL_HIGH_RED_ERROR = 0b1111, // High-resolution error event signal
    PWMEVTy_EVTySEL_ADC_TRIGGER_2 = 0b1001, // ADC Trigger 2 signal
    PWMEVTy_EVTySEL_ADC_TRIGGER_1 = 0b1000, // ADC Trigger 1 signal
    PWMEVTy_EVTySEL_STEER = 0b0111, // STEER signal (available in Push-Pull Output modes only)(4)
    PWMEVTy_EVTySEL_CAHALF = 0b0110, // CAHALF signal (available in Center-Aligned modes only)(4)
    PWMEVTy_EVTySEL_PCI_FAULT = 0b0101, // PCI Fault active output signal
    PWMEVTy_EVTySEL_PCI_CL = 0b0100, // PCI current-limit active output signal
    PWMEVTy_EVTySEL_PCI_FF = 0b0011, // PCI feed-forward active output signal
    PWMEVTy_EVTySEL_PCI_SYNC = 0b0010, // PCI Sync active output signal
    PWMEVTy_EVTySEL_PWM_OUT = 0b0001, // PWM Generator output signal(3)
    PWMEVTy_EVTySEL_PGTRGSEL = 0b0000 // Source is selected by the PGTRGSEL<2:0> bits    
}EVTySEL_e; // PWM Event Selection bits

#define REG_PWMEVTy_EVTySYNC_SYSCLK_SYNC 0b0001000000000000 // Event output signal is synchronized to the system clock
#define REG_PWMEVTy_EVTySYNC_NO_SYNC 0b0000000000000000  //  Event output is not synchronized to the system clock

typedef enum {
    PWMEVTy_EVTySYNC_SYSCLK_SYNC = 0b1, // Event output signal is synchronized to the system clock
    PWMEVTy_EVTySYNC_NO_SYNC = 0b0  // Event output is not synchronized to the system clock
}EVTySYNC_e; // PWM Event Output Sync bit

#define REG_PWMEVTy_EVTySTRD_NO_STRETCH 0b0010000000000000 // Event output signal pulse width is not stretched
#define REG_PWMEVTy_EVTySTRD_8CLK_STRECH 0b0000000000000000  // Event output signal is stretched to 8 PWM clock cycles minimum(

typedef enum {
    PWMEVTy_EVTySTRD_NO_STRETCH = 0b1, // Event output signal pulse width is not stretched
    PWMEVTy_EVTySTRD_8CLK_STRECH = 0b0  // Event output signal is stretched to 8 PWM clock cycles minimum(
}EVTySTRD_e; // PWM Event Output Stretch Disable bit

#define REG_PWMEVTy_EVTyPOL_ACTIVE_LOW 0b0100000000000000 // Event output signal is active-low
#define REG_PWMEVTy_EVTyPOL_ACTIVE_HIGH 0b0000000000000000  // Event output signal is active-high

typedef enum {
    PWMEVTy_EVTyPOL_ACTIVE_LOW = 0b1, // Event output signal is active-low
    PWMEVTy_EVTyPOL_ACTIVE_HIGH = 0b0  // Event output signal is active-high
}EVTyPOL_e; // PWM Event Output Polarity bit

#define REG_PWMEVTy_EVTyOEN_ENABLE 0b1000000000000000 // // Event output signal is output on PWMEVTy pin
#define REG_PWMEVTy_EVTyOEN_DISABLE 0b0000000000000000 // Event output signal is internal only

typedef enum {
    PWMEVTy_EVTyOEN_ENABLE = 0b1, // Event output signal is output on PWMEVTy pin
    PWMEVTy_EVTyOEN_DISABLE = 0b0 // Event output signal is internal only
}EVTyOEN_e; // PWM Event Output Polarity bit

typedef union {
    struct {
        volatile EVTyOEN_e EVTyOEN : 1; // PWM Event Output Enable bit
        volatile EVTyPOL_e EVTyPOL : 1; // PWM Event Output Polarity bit
        volatile EVTySTRD_e EVTySTRD : 1; // PWM Event Output Stretch Disable bit
        volatile EVTySYNC_e EVTySYNC : 1; // PWM Event Output Sync bit
        volatile unsigned : 4; // reserved
        volatile EVTySEL_e EVTySEL : 4; // PWM Event Selection bits
        volatile unsigned : 1; // reserved
        volatile EVTyPGS_e EVTyPGS : 3; // PWM Event Source Selection bits
    } __attribute__((packed)) bits; // PWM EVENT OUTPUT CONTROL REGISTER A, B, C, D, E or F
    volatile uint32_t value; // EVENT OUTPUT CONTROL REGISTER DIRECT READ/WRITE
}PWMEVTy_t; // PWM EVENT OUTPUT CONTROL REGISTER CONFIGURATION

/* ******************************************************************************************************
 * ******************************************************************************************************
 * 
 *                              PWM GENERATOR #1 to #n REGISTERS 
 * 
 * ******************************************************************************************************
 * *************************************************************************************************** */


/* ======================================================================================================
 * PGxCONL/H: PWM GENERATOR x CONTROL REGISTER LOW/HIGH
 * =================================================================================================== */
#define REG_PGxCON_VALID_DATA_WRITE_MASK 0xEF4F879F
#define REG_PGxCON_VALID_DATA_READ_MASK  0xEF4F879F

#define REG_PGCON_MODSEL_DUAL_EDGE_CAM_DUAL_UPDT    0b0000000000000111
#define REG_PGCON_MODSEL_DUAL_EDGE_CAM_SNG_UPDT     0b0000000000000110
#define REG_PGCON_MODSEL_DBL_UPDATE_CAM             0b0000000000000101
#define REG_PGCON_MODSEL_CENTER_ALIGNED             0b0000000000000100
#define REG_PGCON_MODSEL_INDEPENDENT_EDGE_DUAL_OUT  0b0000000000000010
#define REG_PGCON_MODSEL_VARIABLE_PHASE             0b0000000000000001
#define REG_PGCON_MODSEL_INDEPENDENT_EDGE           0b0000000000000000

typedef enum {
    PGCON_MODSEL_DUAL_EDGE_CAM_DUAL_UPDT = 0b111, // Dual Edge Center-Aligned PWM mode (interrupt/register update twice per cycle)
    PGCON_MODSEL_DUAL_EDGE_CAM_SNG_UPDT = 0b110, // Dual Edge Center-Aligned PWM mode (interrupt/register update once per cycle)
    PGCON_MODSEL_DBL_UPDATE_CAM = 0b101, // Double-Update Center-Aligned PWM mode
    PGCON_MODSEL_CENTER_ALIGNED = 0b100, // Center-Aligned PWM mode
    PGCON_MODSEL_INDEPENDENT_EDGE_DUAL_OUT = 0b010, // Independent Edge PWM mode, dual output
    PGCON_MODSEL_VARIABLE_PHASE = 0b001, // Variable Phase PWM mode
    PGCON_MODSEL_INDEPENDENT_EDGE = 0b000 // Independent Edge PWM mode
} PGCON_MODSEL_e; // Mode Selection bits

#define REG_PGCON_CLKSEL_MSTR_FSCALE   0b0000000000011000
#define REG_PGCON_CLKSEL_MSTR_CLKDIV   0b0000000000010000
#define REG_PGCON_CLKSEL_BY_MCLKSEL    0b0000000000001000
#define REG_PGCON_CLKSEL_NONE          0b0000000000000000

typedef enum {
    PGCON_CLKSEL_MSTR_FSCALE = 0b11, // PWM Generator uses Master clock scaled by frequency scaling circuit
    PGCON_CLKSEL_MSTR_CLKDIV = 0b10, // PWM Generator uses Master clock divided by clock divider circuit
    PGCON_CLKSEL_BY_MCLKSEL = 0b01, // PWM Generator uses Master clock selected by the MCLKSEL<1:0> (PCLKCON<1:0>) control bits
    PGCON_CLKSEL_NONE = 0b00 // No clock selected, PWM Generator is in lowest power state (default)
} PGCON_CLKSEL_e; // Clock Selection bits


#define REG_PGCON_HREN_HIGH_RES   0b0000000010000000
#define REG_PGCON_HREN_STANDARD   0b0000000000000000

typedef enum {
    PGCON_HREN_HIGH_RES = 0b1, // PWM Generator x operates in High-Resolution mode
    PGCON_HREN_STANDARD = 0b0 // PWM Generator x operates in standard resolution
} PGCON_HREN_e; // PWM Generator x High-Resolution Enable bit

#define REG_PGCON_TRGCNT_8_PWM_CYCLES    0b0000011100000000
#define REG_PGCON_TRGCNT_7_PWM_CYCLES    0b0000011000000000
#define REG_PGCON_TRGCNT_6_PWM_CYCLES    0b0000010100000000
#define REG_PGCON_TRGCNT_5_PWM_CYCLES    0b0000010000000000
#define REG_PGCON_TRGCNT_4_PWM_CYCLES    0b0000001100000000
#define REG_PGCON_TRGCNT_3_PWM_CYCLES    0b0000001000000000
#define REG_PGCON_TRGCNT_2_PWM_CYCLES    0b0000000100000000
#define REG_PGCON_TRGCNT_1_PWM_CYCLES    0b0000000000000000

typedef enum {
    PGCON_TRGCNT_8_PWM_CYCLES = 0b111, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_7_PWM_CYCLES = 0b110, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_6_PWM_CYCLES = 0b101, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_5_PWM_CYCLES = 0b100, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_4_PWM_CYCLES = 0b011, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_3_PWM_CYCLES = 0b010, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_2_PWM_CYCLES = 0b001, // PWM Generator produces 8 PWM cycles after triggered
    PGCON_TRGCNT_1_PWM_CYCLES = 0b000 // PWM Generator produces 8 PWM cycles after triggered
} PGCON_TRGCNT_e; // Trigger Count Select bits


#define REG_PGCON_ON_PWM_ENABLED     0b1000000000000000
#define REG_PGCON_ON_PWM_DISABLED    0b0000000000000000
#define REG_PGCON_ON_PWM_RESET       0b0111111111111111

typedef enum {
    PGCON_ON_PWM_ENABLED = 0b1, // PWM Generator is enabled
    PGCON_ON_PWM_DISABLED = 0b0 // PWM Generator is disabled
} PGCON_ON_e; // PWM module enable bit


#define REG_PGCON_SOCS_TRG_PCISYNC  0b0000000000001111
#define REG_PGCON_SOCS_PWM4_8       0b0000000000000100
#define REG_PGCON_SOCS_PWM3_7       0b0000000000000011
#define REG_PGCON_SOCS_PWM2_6       0b0000000000000010
#define REG_PGCON_SOCS_PWM1_5       0b0000000000000001
#define REG_PGCON_SOCS_LOCAL_EOC    0b0000000000000000

typedef enum {
    PGCON_SOCS_TRG_PCISYNC = 0b1111, // TRIG bit or PCI Sync function only (no hardware trigger source is selected)
    PGCON_SOCS_PWM4_8 = 0b0100, // PWM4(8) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM3_7 = 0b0011, // PWM3(7) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM2_6 = 0b0010, // PWM2(6) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_PWM1_5 = 0b0001, // PWM1(5) PG1 or PG5 trigger output selected by PGTRGSEL<2:0> (PGxEVT<2:0>)
    PGCON_SOCS_LOCAL_EOC = 0b0000 // Local EOC ? PWM Generator is self-triggered
} PGCON_SOCS_e; // Start-of-Cycle Selection bits

#define REG_PGCON_TRGMOD_REPEAT     0b0000000001000000
#define REG_PGCON_TRGMOD_SINGLE     0b0000000000000000

typedef enum {
    PGCON_TRGMOD_REPEAT = 0b1, // PWM Generator operates in Retriggerable mode
    PGCON_TRGMOD_SINGLE = 0b0 // PWM Generator operates in Single Trigger mode
} PGCON_TRGMOD_e; // PWM Generator Trigger Mode Selection bit

#define REG_PGCON_UPDMOD_SLV_IMMEDIATE  0b0000001100000000
#define REG_PGCON_UPDMOD_SLV_SOC        0b0000001000000000
#define REG_PGCON_UPDMOD_IMMEDIATE      0b0000000100000000
#define REG_PGCON_UPDMOD_SOC            0b0000000000000000

typedef enum {
    PGCON_UPDMOD_SLV_IMMEDIATE = 0b011, // Slaved immediate update when MSTEN = 1 and UPDATE = 1
    PGCON_UPDMOD_SLV_SOC = 0b010, // Slaved SOC update at start of next PWM cycle when MSTEN = 1 and UPDATE = 1
    PGCON_UPDMOD_IMMEDIATE = 0b001, // Immediate update when UPDATE = 1
    PGCON_UPDMOD_SOC = 0b000 // SOC update at start of next PWM cycle
} PGCON_UPDMOD_e; // PWM Buffer Update Mode Selection bits

#define REG_PGCON_MSTEN_MASTER          0b0000100000000000
#define REG_PGCON_MSTEN_NO_BROADCAST    0b0000000000000000

typedef enum {
    PGCON_MSTEN_BROADCAST = 0b1, // PWM Generator broadcasts software set/clear of the UPDATE status bit and EOC signal to other PWM Generators
    PGCON_MSTEN_NO_BROADCAST = 0b0 // PWM Generator does not broadcast the UPDATE status bit state or EOC signal
} PGCON_MSTEN_e; // Master Update Enable bit

#define REG_PGCON_MPHSEL_MASTER          0b0010000000000000
#define REG_PGCON_MPHSEL_INDEPENDENT     0b0000000000000000

typedef enum {
    PGCON_MPHSEL_MASTER = 0b1, // PWM Generator uses the MPHASE register instead of PGxPHASE
    PGCON_MPHSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxPHASE register
} PGCON_MPHSEL_e; // Master Phase Register Select bit

#define REG_PGCON_MPERSEL_MASTER         0b0100000000000000
#define REG_PGCON_MPERSEL_INDEPENDENT    0b0000000000000000

typedef enum {
    PGCON_MPERSEL_MASTER = 0b1, // PWM Generator uses the MPER register instead of PGxPER
    PGCON_MPERSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxPER register
} PGCON_MPERSEL_e; // Master Period Register Select bit

#define REG_PGCON_MDCSEL_MASTER         0b1000000000000000
#define REG_PGCON_MDCSEL_INDEPENDENT    0b0000000000000000

typedef enum {
    PGCON_MDCSEL_MASTER = 0b1, // PWM Generator uses the MDC register instead of PGxDC
    PGCON_MDCSEL_INDEPENDENT = 0b0 // PWM Generator uses the PGxDC register
} PGCON_MDCSEL_e; // Master Duty Cycle Register Select bit

typedef union {
    struct {
        volatile PGCON_MODSEL_e MODSEL : 3; // Mode Selection bits
        volatile PGCON_CLKSEL_e CLKSEL : 2; // Clock Selection bits
        volatile unsigned : 2; // reserved
        volatile PGCON_HREN_e HREN : 1; // PWM Generator x High-Resolution Enable bit
        volatile PGCON_TRGCNT_e TRGCNT : 3; // Trigger Count Select bits
        volatile unsigned : 4; // reserved
        volatile PGCON_ON_e ON : 1; // PWM module enable bit

        volatile PGCON_SOCS_e SOCS : 4; // Start-of-Cycle Selection bits
        volatile unsigned : 2; // reserved
        volatile PGCON_TRGMOD_e TRGMOD : 2; // PWM Generator Trigger Mode Selection bit
        volatile PGCON_UPDMOD_e UPDMOD : 3; // PWM Buffer Update Mode Selection bits
        volatile PGCON_MSTEN_e MSTEN : 1; // Master Update Enable bit
        volatile unsigned : 1; // reserved
        volatile PGCON_MPHSEL_e MPHSEL : 1; // Master Phase Register Select bit
        volatile PGCON_MPERSEL_e MPERSEL : 1; // Master Period Register Select bit
        volatile PGCON_MDCSEL_e MDCSEL : 1; // Master Duty Cycle Register Select bit
    } __attribute__((packed)) bits;
    volatile uint32_t value;
} PGxCON_t;


/* ===========================================================================
 * PGxSTAT: PWM GENERATOR x STATUS REGISTER
 * ===========================================================================*/
#define REG_PGxSTAT_VALID_DATA_WRITE_MASK  0xF0E8
#define REG_PGxSTAT_VALID_DATA_READ_MASK   0xFF37
#define REG_PGxSTAT_VALID_DATA_RESET_MASK  0x0F17


#define REG_PGSTAT_TRIG_ACTIVE   0b0000000000000001
#define REG_PGSTAT_TRIG_NONE     0b0000000000000000

typedef enum {
    PGSTAT_TRIG_ACTIVE = 0b1, // PWM Generator is triggered and PWM cycle is in progress
    PGSTAT_TRIG_NONE = 0b0 // No PWM cycle is in progress
}PGSTAT_TRIG_t;     // PWM Trigger Status bit

#define REG_PGSTAT_CAHALF_2ND_CYCLE   0b0000000000000010
#define REG_PGSTAT_CAHALF_1ST_CYCLE   0b0000000000000000

typedef enum {
    PGSTAT_CAHALF_2ND_CYCLE = 0b1, // PWM Generator is in 2nd half of time base cycle
    PGSTAT_CAHALF_1ST_CYCLE = 0b0 // PWM Generator is in 1st half of time base cycle
}PGSTAT_CAHALF_t;     // Half Cycle Status bit (Center-Aligned modes only)

#define REG_PGSTAT_STEER_2ND_CYCLE    0b0000000000000100
#define REG_PGSTAT_STEER_1ST_CYCLE    0b0000000000000000

typedef enum {
    PGSTAT_STEER_2ND_CYCLE = 0b1, // PWM Generator is in 2nd cycle of Push-Pull mode
    PGSTAT_STEER_1ST_CYCLE = 0b0 // PWM Generator is in 1st cycle of Push-Pull mode
}PGSTAT_STEER_t;     // Output Steering Status bit (Push-Pull Output mode only)

#define REG_PGSTAT_UPDREQ_GO      0b0000000000001000
#define REG_PGSTAT_UPDREQ_STOP    0b0000000000000000

typedef enum {
    PGSTAT_UPDREQ_GO = 0b1, // User software writes a ?1? to this bit location to request a PWM Data register update
    PGSTAT_UPDREQ_STOP = 0b0 // The bit location always reads as ?0?. The UPDATE status bit will indicate ?1? when an update is pending.
}PGSTAT_UPDREQ_t;     // PWM Data Register Update Request bit

#define REG_PGSTAT_UPDATE_PENDING   0b0000000000010000
#define REG_PGSTAT_UPDATE_COMPLETE  0b0000000000000000

typedef enum {
    PGSTAT_UPDATE_GO = 0b1, // PWM Data register update is pending ? user Data registers are not writable
    PGSTAT_UPDATE_COMPLETE = 0b0 // No PWM Data register update is pending
}PGSTAT_UPDATE_t;     // PWM Data Register Update Status/Control bit

#define REG_PGSTAT_CAP_DATA_AVAILABLE 0b0000000000100000
#define REG_PGSTAT_CAP_NO_DATA        0b0000000000000000

typedef enum {
    PGSTAT_CAP_DATA_AVAILABLE = 0b1, // PWM Generator time base value has been captured in PGxCAP
    PGSTAT_CAP_NO_DATA = 0b0 // No capture has occurred
}PGSTAT_CAP_t;     // PWM time base capture status bit

#define REG_PGSTAT_TRSET_GO        0b0000000010000000
#define REG_PGSTAT_TRSET_STOP      0b0000000001000000
#define REG_PGSTAT_TRSET_NONE      0b0000000000000000

typedef enum {
    PGSTAT_TRSET_GO = 0b10, // User software writes a ?1? to this bit location to trigger a PWM Generator cycle 
    PGSTAT_TRSET_STOP = 0b01, // User software writes a ?1? to this bit location to stop a PWM Generator cycle 
    PGSTAT_TRSET_NONE = 0b00 // The bit location always reads as ?0?. The TRIG bit will indicate ?1? when the PWM Generator is triggered and ?0? when the PWM Generator is not triggered
}PGSTAT_TRSET_t;     // PWM Generator Software Trigger Set/Clear control bits

#define REG_PGSTAT_FFACT_ACTIVE    0b0000000100000000
#define REG_PGSTAT_FFACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_FFACT_ACTIVE = 0b1, // PCI feed-forward output is active
    PGSTAT_FFACT_INACTIVE = 0b0 // PCI feed-forward output is inactive
}PGSTAT_FFACT_t;     // PCI feed-forward Status bit

#define REG_PGSTAT_CLACT_ACTIVE    0b0000001000000000
#define REG_PGSTAT_CLACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_CLACT_ACTIVE = 0b1, // PCI current-limit output is active
    PGSTAT_CLACT_INACTIVE = 0b0 // PCI current-limit output is inactive
}PGSTAT_CLACT_t;     // PCI current-limit Status bit

#define REG_PGSTAT_FLTACT_ACTIVE    0b0000010000000000
#define REG_PGSTAT_FLTACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_FLTACT_ACTIVE = 0b1, // PCI Fault output is active
    PGSTAT_FLTACT_INACTIVE = 0b0 // PCI Fault output is inactive
}PGSTAT_FLTACT_t;     // PCI Fault Status bit

#define REG_PGSTAT_SACT_ACTIVE    0b0000100000000000
#define REG_PGSTAT_SACT_INACTIVE  0b0000000000000000

typedef enum {
    PGSTAT_SACT_ACTIVE = 0b1, // PCI Sync output is active
    PGSTAT_SACT_INACTIVE = 0b0 // PCI Sync output is inactive
}PGSTAT_SACT_t;     // PCI Sync Status bit

#define REG_PGSTAT_FFEVT_ACTIVE   0b0001000000000000
#define REG_PGSTAT_FFEVT_NONE     0b0000000000000000

typedef enum {
    PGSTAT_FFEVT_ACTIVE = 0b1, // A PCI feed-forward event has occurred (rising edge on PCI feed-forward output or PCI feed-forward output is high when module is enabled)
    PGSTAT_FFEVT_NONE = 0b0 // No PCI feed-forward event has occurred
}PGSTAT_FFEVT_t;     // PCI Feed-Forward Active Status bit

#define REG_PGSTAT_CLEVT_ACTIVE   0b0010000000000000
#define REG_PGSTAT_CLEVT_NONE     0b0000000000000000

typedef enum {
    PGSTAT_CLEVT_ACTIVE = 0b1, // A PCI current-limit event has occurred (rising edge on PCI current-limit output or PCI current-limit output is high when module is enabled)
    PGSTAT_CLEVT_NONE = 0b0 // No PCI current-limit event has occurred
}PGSTAT_CLEVT_t;     // PCI Current-Limit Status bit

#define REG_PGSTAT_FLTEVT_ACTIVE  0b0100000000000000
#define REG_PGSTAT_FLTEVT_NONE    0b0000000000000000

typedef enum {
    PGSTAT_FLTEVT_ACTIVE = 0b1, // A PCI Fault event has occurred (rising edge on PCI Fault output or PCI Fault output is high when module is enabled)
    PGSTAT_FLTEVT_NONE = 0b0 // No PCI Fault event has occurred
}PGSTAT_FLTEVT_t;     // PCI Fault Active Status bit

#define REG_PGSTAT_SEVT_ACTIVE  0b1000000000000000
#define REG_PGSTAT_SEVT_NONE    0b0000000000000000

typedef enum {
    PGSTAT_SEVT_ACTIVE = 0b1, // A PCI Sync event has occurred (rising edge on PCI Sync output or PCI Sync output is high when module is enabled)
    PGSTAT_SEVT_NONE = 0b0 // No PCI Sync event has occurred
}PGSTAT_SEVT_t;     // PCI Sync Event bit

typedef union {
    struct {
        volatile PGSTAT_TRIG_t TRIG : 1; // PWM trigger status bit
        volatile PGSTAT_CAHALF_t CAHALF : 1; // Half Cycle Status bit (Center-Aligned modes only)
        volatile PGSTAT_STEER_t STEER : 1; // Output Steering Status bit (Push-Pull Output mode only)
        volatile PGSTAT_UPDREQ_t UPDREQ : 1; // PWM Data Register Update Request bit
        volatile PGSTAT_UPDATE_t UPDATE : 1; // PWM Data Register Update Status/Control bit
        volatile PGSTAT_CAP_t CAP : 1; // PWM time base capture status bit
        volatile PGSTAT_TRSET_t TRSET : 2; // PWM Generator Software Trigger Set/Clear control bits

        volatile PGSTAT_FFACT_t FFACT : 1; // PCI Fault Active Status bit
        volatile PGSTAT_CLACT_t CLACT : 1; // PCI Current-Limit Status bit
        volatile PGSTAT_FLTACT_t FLTACT : 1; // PCI Fault Status bit
        volatile PGSTAT_SACT_t SACT : 1; // PCI Sync Status bit
        volatile PGSTAT_FFEVT_t FFEVT : 1; // PCI Feed-Forward Active Status bit
        volatile PGSTAT_CLEVT_t CLEVT : 1; // PCI Current-Limit Status bit
        volatile PGSTAT_FLTEVT_t FLTEVT : 1; // PCI Fault Active Status bit
        volatile PGSTAT_SEVT_t SEVT : 1; // PCI Sync Event Status bit
    } __attribute__((packed)) bits;

    volatile uint16_t value;
} PGxSTAT_t;

/* ===========================================================================
 * PGxIOCONL/H: PWM GENERATOR x I/O CONTROL REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PGxIOCON_VALID_DATA_WRITE_MASK  0x713FFFFF
#define REG_PGxIOCON_VALID_DATA_READ_MASK  0x713FFFFF


#define REG_IOCON_CLMOD_ENABLED         0b1000000000000000
#define REG_IOCON_CLMOD_DISABLED        0b0000000000000000

typedef enum {
    IOCON_CLMOD_ENABLED = 0b1, // If PCI current limit is active, then the PWMxH and PWMxL output signals are inverted (bit flipping), and the CLDAT<1:0> bits are not used
    IOCON_CLMOD_DISABLED = 0b0 // If PCI current limit is active, then the CLDAT<1:0> bits define the PWM output levels
} IOCON_CLMOD_e; // Current-Limit Mode Select bit

#define REG_IOCON_SWAP_ENABLED          0b0100000000000000
#define REG_IOCON_SWAP_DISABLED         0b0000000000000000

typedef enum {
    IOCON_SWAP_ENABLED = 0b1, // The PWMxH signal is connected to the PWMxL pin and the PWMxL signal is connected to the PWMxH pin
    IOCON_SWAP_DISABLED = 0b0 // PWMxH/L signals are mapped to their respective pins
} IOCON_SWAP_e; // Swap PWM Signals to PWMxH and PWMxL Device Pins bit

#define REG_IOCON_OSYNC_UPDMOD          0b0000001000000000
#define REG_IOCON_OSYNC_IMMEDIATE       0b0000000100000000
#define REG_IOCON_OSYNC_PWM             0b0000000000000000

#define REG_IOCON_OVREN_COMP_SET        0b0011000000000000
#define REG_IOCON_OVREN_COMP_RESET      0b1100111111111111
#define REG_IOCON_OVREN_COMP_ENABLED    0b0011000000000000
#define REG_IOCON_OVREN_COMP_DISABLED   0b0000000000000000

#define REG_IOCON_OVRENH_ENABLED        0b0010000000000000
#define REG_IOCON_OVRENH_RESET          0b1101111111111111
#define REG_IOCON_OVRENH_DISABLED       0b0000000000000000
#define REG_IOCON_OVRENL_ENABLED        0b0001000000000000
#define REG_IOCON_OVRENL_RESET          0b1110111111111111
#define REG_IOCON_OVRENL_DISABLED       0b0000000000000000

typedef enum {
    IOCON_OVRENx_ENABLED = 0b1, // OVRDATx provides data for output on the PWMxX pin
    IOCON_OVRENx_DISABLED = 0b0 // PWM Generator provides data for the PWMxX pin
} IOCON_OVRENx_e; // Override Enable for PWMxH/PWMxL Pin bit

typedef enum {
    IOCON_OSYNC_UPDMOD = 0b10, // User output overrides via the OVRENH/L and OVRDAT<1:0> bits occur when specified by the UPDMOD<2:0> bits in the PGxCONH register
    IOCON_OSYNC_IMMEDIATE = 0b01, // User output overrides via the OVRENH/L and OVRDAT<1:0> bits occur immediately (as soon as possible)
    IOCON_OSYNC_PWM = 0b00 // User output overrides via the OVRENH/L and OVRDAT<1:0> bits are synchronized to the local PWM time base (next Start-of-Cycle)
} IOCON_OSYNC_e; // User Output Override Synchronization Control bits

#define REG_IOCON_OVRDAT_HIGH_HIGH      0b0000110000000000
#define REG_IOCON_OVRDAT_HIGH_LOW       0b0000100000000000
#define REG_IOCON_OVRDAT_LOW_HIGH       0b0000010000000000
#define REG_IOCON_OVRDAT_LOW_LOW        0b0000000000000000

typedef enum {
    IOCON_OVRDAT_HIGH_HIGH = 0b11, // Override state of PWMxH=HIGH, override state of PWMxL=HIGH
    IOCON_OVRDAT_HIGH_LOW = 0b10, // Override state of PWMxH=HIGH, override state of PWMxL=LOW
    IOCON_OVRDAT_LOW_HIGH = 0b01, // Override state of PWMxH=LOW, override state of PWMxL=HIGH
    IOCON_OVRDAT_LOW_LOW = 0b00 // Override state of PWMxH=LOW, override state of PWMxL=LOW
} IOCON_OVRDAT_e; /* Data for PWMxH/PWMxL Pins if Override is Enabled bits:
                                    * If OVERENH = 1, then OVRDAT1 provides data for PWMxH
                                    * If OVERENL = 1, then OVRDAT0 provides data for PWMxL */

#define REG_IOCON_FLTDAT_HIGH_HIGH      0b0000110000000000
#define REG_IOCON_FLTDAT_HIGH_LOW       0b0000100000000000
#define REG_IOCON_FLTDAT_LOW_HIGH       0b0000010000000000
#define REG_IOCON_FLTDAT_LOW_LOW        0b0000000000000000

typedef enum {
    IOCON_FLTDAT_HIGH_HIGH = 0b11, // Fault state of PWMxH=HIGH, Fault state of PWMxL=HIGH
    IOCON_FLTDAT_HIGH_LOW = 0b10, // Fault state of PWMxH=HIGH, Fault state of PWMxL=LOW
    IOCON_FLTDAT_LOW_HIGH = 0b01, // Fault state of PWMxH=LOW, Fault state of PWMxL=HIGH
    IOCON_FLTDAT_LOW_LOW = 0b00 // Fault state of PWMxH=LOW, Fault state of PWMxL=LOW
} IOCON_FLTDAT_e; /* Data for PWMxH/PWMxL Pins if Fault Event is Active bits:
                                    * If Fault is active, then FLTDAT1 provides data for PWMxH  
                                    * If Fault is active, then FLTDAT0 provides data for PWMxL */

#define REG_IOCON_CLDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_CLDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_CLDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_CLDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_CLDAT_HIGH_HIGH = 0b11, // Current limit state of PWMxH=HIGH, Current limit state of PWMxL=HIGH
    IOCON_CLDAT_HIGH_LOW = 0b10, // Current limit state of PWMxH=HIGH, Current limit state of PWMxL=LOW
    IOCON_CLDAT_LOW_HIGH = 0b01, // Current limit state of PWMxH=LOW, Current limit state of PWMxL=HIGH
    IOCON_CLDAT_LOW_LOW = 0b00 // Current limit state of PWMxH=LOW, Current limit state of PWMxL=LOW
} IOCON_CLDAT_e; /* Data for PWMxH/PWMxL Pins if Current-Limit Event is Active bits:
                                    * If current limit is active, then CLDAT1 provides data for PWMxH  
                                    * If current limit is active, then CLDAT0 provides data for PWMxL */

#define REG_IOCON_FFDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_FFDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_FFDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_FFDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_FFDAT_HIGH_HIGH = 0b11, // Feed-forward state of PWMxH=HIGH, Feed-forward state of PWMxL=HIGH
    IOCON_FFDAT_HIGH_LOW = 0b10, // Feed-forward state of PWMxH=HIGH, Feed-forward state of PWMxL=LOW
    IOCON_FFDAT_LOW_HIGH = 0b01, // Feed-forward state of PWMxH=LOW, Feed-forward state of PWMxL=HIGH
    IOCON_FFDAT_LOW_LOW = 0b00 // Feed-forward state of PWMxH=LOW, Feed-forward state of PWMxL=LOW
} IOCON_FFDAT_e; /* Data for PWMxH/PWMxL Pins if Feed-Forward Event is Active bits
                                    * If feed-forward is active, then FFDAT1 provides data for PWMxH
                                    * If feed-forward is active, then FFDAT0 provides data for PWMxL. */

#define REG_IOCON_DBDAT_HIGH_HIGH       0b0000110000000000
#define REG_IOCON_DBDAT_HIGH_LOW        0b0000100000000000
#define REG_IOCON_DBDAT_LOW_HIGH        0b0000010000000000
#define REG_IOCON_DBDAT_LOW_LOW         0b0000000000000000

typedef enum {
    IOCON_DBDAT_HIGH_HIGH = 0b11, // Debug mode state of PWMxH=HIGH, Debug mode state of PWMxL=HIGH
    IOCON_DBDAT_HIGH_LOW = 0b10, // Debug mode state of PWMxH=HIGH, Debug mode state of PWMxL=LOW
    IOCON_DBDAT_LOW_HIGH = 0b01, // Debug mode state of PWMxH=LOW, Debug mode state of PWMxL=HIGH
    IOCON_DBDAT_LOW_LOW = 0b00 // Debug mode state of PWMxH=LOW, Debug mode state of PWMxL=LOW
} IOCON_DBDAT_e; /* Data for PWMxH/PWMxL Pins if Debug Mode is Active and PTFRZ = 1 bits
                                    * If Debug mode is active and PTFRZ = 1, then DBDAT1 provides data for PWMxH
                                    * If Debug mode is active and PTFRZ = 1, then DBDAT0 provides data for PWMxL */

#define REG_IOCON_POLH_ACTIVE_HIGH  0b0000000000000000
#define REG_IOCON_POLH_ACTIVE_LOW   0b0000000000000010
#define REG_IOCON_POLL_ACTIVE_HIGH  0b0000000000000000
#define REG_IOCON_POLL_ACTIVE_LOW   0b0000000000000001

typedef enum {
    IOCON_POLx_ACTIVE_HIGH = 0b0, // Output pin is active-high
    IOCON_POLx_ACTIVE_LOW = 0b1 // Output pin is active-low
} IOCON_POLx_e; // PWMxL/PWMxH Output Polarity bit

#define REG_IOCON_PENH_PGx          0b0000000000001000
#define REG_IOCON_PENH_GPIO         0b0000000000000000
#define REG_IOCON_PENL_PGx          0b0000000000000100
#define REG_IOCON_PENL_GPIO         0b0000000000000000

#define REG_IOCON_PENH_GPIO_ENABLE  0b1111111111110111
#define REG_IOCON_PENH_GPIO_DISABLE 0b0000000000001000
#define REG_IOCON_PENL_GPIO_ENABLE  0b1111111111111011
#define REG_IOCON_PENL_GPIO_DISABLE 0b0000000000000100

#define REG_IOCON_PENx_COMP_PGx     0b0000000000001100
#define REG_IOCON_PENx_COMP_GPIO    0b0000000000000000

typedef enum {
    IOCON_PENx_PGx = 0b1, // PWM Generator controls the PWMxL/PWMxH output pin
    IOCON_PENx_GPIO = 0b0 // PWMxX is normal GPIO
} IOCON_PENx_e; // PWMxL/PWMxH Output Port Enable bit

#define REG_IOCON_PMOD_PUSH_PULL        0b0000000000100000
#define REG_IOCON_PMOD_INDEPENDENT      0b0000000000010000
#define REG_IOCON_PMOD_COMPLEMENTARY    0b0000000000000000

typedef enum {
    IOCON_PMOD_PUSH_PULL = 0b10, // PWM Generator outputs operate in Push-Pull mode
    IOCON_PMOD_INDEPENDENT = 0b01, // PWM Generator outputs operate in Independent mode
    IOCON_PMOD_COMPLEMENTARY = 0b00 // PWM Generator outputs operate in Complementary mode
} IOCON_PMOD_e; // PWM Generator Output Mode Selection bits

#define REG_IOCON_DTCMPSEL_PCI_FEED_FORWARD   0b0000000100000000
#define REG_IOCON_DTCMPSEL_PCI_SYNC           0b0000000000000000

typedef enum {
    IOCON_DTCMPSEL_PCI_FEED_FORWARD = 0b1, // Dead-time compensation is controlled by PCI feed-forward limit logic
    IOCON_DTCMPSEL_PCI_SYNC = 0b0 // Dead-time compensation is controlled by PCI Sync logic
} IOCON_DTCMPSEL_e; // Dead-Time Compensation Select bit

#define REG_IOCON_CAPSRC_PCI_FAULT          0b0100000000000000
#define REG_IOCON_CAPSRC_PCI_CURRENT_LIMIT  0b0011000000000000
#define REG_IOCON_CAPSRC_PCI_FEED_FORWARD   0b0010000000000000
#define REG_IOCON_CAPSRC_PCI_SYNC           0b0001000000000000
#define REG_IOCON_CAPSRC_NONE               0b0000000000000000

typedef enum {
    IOCON_CAPSRC_PCI_FAULT = 0b100, // Capture time base value at assertion of selected PCI Fault signal
    IOCON_CAPSRC_PCI_CURRENT_LIMIT = 0b011, // Capture time base value at assertion of selected PCI current-limit signal
    IOCON_CAPSRC_PCI_FEED_FORWARD = 0b010, // Capture time base value at assertion of selected PCI feed-forward signal
    IOCON_CAPSRC_PCI_SYNC = 0b001, // Capture time base value at assertion of selected PCI Sync signal
    IOCON_CAPSRC_NONE = 0b000 // No hardware source selected for time base capture ? software only
} IOCON_CAPSRC_e; // Time Base Capture Source Selection bits

typedef union {
    struct {
        volatile IOCON_DBDAT_e DBDAT : 2; // Data for PWMxH/PWMxL Pins if Debug Mode is Active and PTFRZ = 1 bits
        volatile IOCON_FFDAT_e FFDAT : 2; // Data for PWMxH/PWMxL Pins if Feed-Forward Event is Active bits
        volatile IOCON_CLDAT_e CLDAT : 2; // Data for PWMxH/PWMxL Pins if Current-Limit Event is Active bits
        volatile IOCON_FLTDAT_e FLTDAT : 2; // Data for PWMxH/PWMxL Pins if Fault Event is Active bits
        volatile IOCON_OSYNC_e OSYNC : 2; // User Output Override Synchronization Control bits
        volatile IOCON_OVRDAT_e OVRDAT : 2; // Data for PWMxH/PWMxL Pins if Override is Enabled bits
        volatile IOCON_OVRENx_e OVRENL : 1; // User Override Enable for PWMxH Pin bit
        volatile IOCON_OVRENx_e OVRENH : 1; // User Override Enable for PWMxL Pin bit
        volatile IOCON_SWAP_e SWAP : 1; // Swap PWM Signals to PWMxH and PWMxL Device Pins bit
        volatile IOCON_CLMOD_e CLMOD : 1; // Current-Limit Mode Select bit

        volatile IOCON_POLx_e POLL : 1; // PWMxL Output Polarity bit
        volatile IOCON_POLx_e POLH : 1; // PWMxH Output Polarity bit
        volatile IOCON_PENx_e PENL : 1; // PWMxL Output Port Enable bit
        volatile IOCON_PENx_e PENH : 1; // PWMxH Output Port Enable bit
        volatile IOCON_PMOD_e PMOD : 2; // PWM Generator Output Mode Selection bits
        volatile unsigned : 2; // reserved
        volatile IOCON_DTCMPSEL_e DTCMPSEL : 1; // Dead-Time Compensation Select bit
        volatile unsigned : 3; // reserved
        volatile IOCON_CAPSRC_e CAPSRC : 3; // Time Base Capture Source Selection bits

    } __attribute__((packed)) bits;
    volatile uint32_t value;
} PGxIOCON_t;

/* ===========================================================================
 * PGxEVTx: PWM GENERATOR x EVENT REGISTER HIGH/LOW
 * ===========================================================================*/

#define REG_PGxEVTy_VALID_DATA_WRITE_MASK  0xF3FFFF1F
#define REG_PGxEVTy_VALID_DATA_READ_MASK   0xF3FFFF1F

#define REG_PGEVT_FLTIEN_ENABLED  0b1000000000000000 // Fault interrupt is enabled
#define REG_PGEVT_FLTIEN_DISABLED 0b0000000000000000 // Fault interrupt is disabled

typedef enum {
    PGEVT_FLTIEN_ENABLED  = 0b1, // Fault interrupt is enabled
    PGEVT_FLTIEN_DISABLED = 0b0  // Fault interrupt is disabled
}PGEVT_FLTIEN_e;  // PCI Fault Interrupt Enable bit

#define REG_PGEVT_CLIEN_ENABLED  0b0100000000000000 // Current-limit interrupt is enabled
#define REG_PGEVT_CLIEN_DISABLED 0b0000000000000000  // Current-limit interrupt is disabled

typedef enum {
    PGEVT_CLIEN_ENABLED  = 0b1, // Current-limit interrupt is enabled
    PGEVT_CLIEN_DISABLED = 0b0  // Current-limit interrupt is disabled
}PGEVT_CLIEN_e;  // PCI Current-limit Interrupt Enable bit

#define REG_PGEVT_FFIEN_ENABLED  0b0010000000000000 // Feed-forward interrupt is enabled
#define REG_PGEVT_FFIEN_DISABLED 0b0000000000000000  // Feed-forward interrupt is disabled

typedef enum {
    PGEVT_FFIEN_ENABLED  = 0b1, // Feed-forward interrupt is enabled
    PGEVT_FFIEN_DISABLED = 0b0  // Feed-forward interrupt is disabled
}PGEVT_FFIEN_e;  // PCI Feed-Forward Interrupt Enable bit

#define REG_PGEVT_SIEN_ENABLED  0b0001000000000000 // Sync interrupt is enabled
#define REG_PGEVT_SIEN_DISABLED 0b0000000000000000  // Sync interrupt is disabled

typedef enum {
    PGEVT_SIEN_ENABLED  = 0b1, // Sync interrupt is enabled
    PGEVT_SIEN_DISABLED = 0b0  // Sync interrupt is disabled
}PGEVT_SIEN_e;  // PCI Sync Interrupt Enable bit

#define REG_PGEVT_IEVTSEL_NONE     0b0000001100000000 // Time base interrupts are disabled (Sync, Fault, current-limit and feed-forward events can be independently enabled)
#define REG_PGEVT_IEVTSEL_ADCTR1   0b0000001000000000 // Interrupts CPU at ADC Trigger 1 event
#define REG_PGEVT_IEVTSEL_PGxTRIGA 0b0000000100000000 // Interrupts CPU at TRIGA compare event
#define REG_PGEVT_IEVTSEL_EOC      0b0000000000000000 // Interrupts CPU at EOC

typedef enum {
    PGEVT_IEVTSEL_NONE     = 0b11, // Time base interrupts are disabled (Sync, Fault, current-limit and feed-forward events can be independently enabled)
    PGEVT_IEVTSEL_ADCTR1   = 0b10, // Interrupts CPU at ADC Trigger 1 event
    PGEVT_IEVTSEL_PGxTRIGA = 0b01, // Interrupts CPU at TRIGA compare event
    PGEVT_IEVTSEL_EOC      = 0b00   // Interrupts CPU at EOC
}PGEVT_IEVTSEL_e;     // Interrupt Event Selection bits

#define REG_PGEVT_ADTR2EN3_PGxTRIGC_ENABLED  0b1 // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN3_PGxTRIGC_DISABLED 0b0 // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN3_PGxTRIGC_ENABLED = 0b1, // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN3_PGxTRIGC_DISABLED = 0b0 // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN3_e;

#define REG_PGEVT_ADTR2EN2_PGxTRIGB_ENABLED  0b1 // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN2_PGxTRIGB_DISABLED 0b0 // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN2_PGxTRIGB_ENABLED = 0b1, // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN2_PGxTRIGB_DISABLED = 0b0 // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN2_e;

#define REG_PGEVT_ADTR2EN1_PGxTRIGA_ENABLED 0b1 // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 2
#define REG_PGEVT_ADTR2EN1_PGxTRIGA_DISABLED 0b0 // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 2

typedef enum {
    PGEVT_ADTR2EN1_PGxTRIGA_ENABLED = 0b1, // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR2EN1_PGxTRIGA_DISABLED = 0b0 // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR2EN1_e;

#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_0	0b0000000000000000	//ADC trigger offset by 0 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_1	0b0000000000000001	//ADC trigger offset by 1 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_2	0b0000000000000010	//ADC trigger offset by 2 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_3	0b0000000000000011	//ADC trigger offset by 3 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_4	0b0000000000000100	//ADC trigger offset by 4 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_5	0b0000000000000101	//ADC trigger offset by 5 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_6	0b0000000000000110	//ADC trigger offset by 6 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_7	0b0000000000000111	//ADC trigger offset by 7 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_8	0b0000000000001000	//ADC trigger offset by 8 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_9	0b0000000000001001	//ADC trigger offset by 9 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_10	0b0000000000001010	//ADC trigger offset by 10 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_11	0b0000000000001011	//ADC trigger offset by 11 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_12	0b0000000000001100	//ADC trigger offset by 12 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_13	0b0000000000001101	//ADC trigger offset by 13 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_14	0b0000000000001110	//ADC trigger offset by 14 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_15	0b0000000000001111	//ADC trigger offset by 15 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_16	0b0000000000010000	//ADC trigger offset by 16 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_17	0b0000000000010001	//ADC trigger offset by 17 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_18	0b0000000000010010	//ADC trigger offset by 18 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_19	0b0000000000010011	//ADC trigger offset by 19 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_20	0b0000000000010100	//ADC trigger offset by 20 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_21	0b0000000000010101	//ADC trigger offset by 21 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_22	0b0000000000010110	//ADC trigger offset by 22 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_23	0b0000000000010111	//ADC trigger offset by 23 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_24	0b0000000000011000	//ADC trigger offset by 24 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_25	0b0000000000011001	//ADC trigger offset by 25 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_26	0b0000000000011010	//ADC trigger offset by 26 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_27	0b0000000000011011	//ADC trigger offset by 27 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_28	0b0000000000011100	//ADC trigger offset by 28 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_29	0b0000000000011101	//ADC trigger offset by 29 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_30	0b0000000000011110	//ADC trigger offset by 30 trigger events
#define REG_PGEVT_ADTR1OFS_OFFSET_EVENTS_31	0b0000000000011111	//ADC trigger offset by 31 trigger events

typedef enum {
    PGEVT_ADTR1OFS_OFFSET_EVENTS_0	=	0b00000,	//ADC trigger offset by 0 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_1	=	0b00001,	//ADC trigger offset by 1 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_2	=	0b00010,	//ADC trigger offset by 2 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_3	=	0b00011,	//ADC trigger offset by 3 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_4	=	0b00100,	//ADC trigger offset by 4 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_5	=	0b00101,	//ADC trigger offset by 5 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_6	=	0b00110,	//ADC trigger offset by 6 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_7	=	0b00111,	//ADC trigger offset by 7 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_8	=	0b01000,	//ADC trigger offset by 8 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_9	=	0b01001,	//ADC trigger offset by 9 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_10	=	0b01010,	//ADC trigger offset by 10 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_11	=	0b01011,	//ADC trigger offset by 11 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_12	=	0b01100,	//ADC trigger offset by 12 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_13	=	0b01101,	//ADC trigger offset by 13 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_14	=	0b01110,	//ADC trigger offset by 14 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_15	=	0b01111,	//ADC trigger offset by 15 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_16	=	0b10000,	//ADC trigger offset by 16 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_17	=	0b10001,	//ADC trigger offset by 17 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_18	=	0b10010,	//ADC trigger offset by 18 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_19	=	0b10011,	//ADC trigger offset by 19 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_20	=	0b10100,	//ADC trigger offset by 20 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_21	=	0b10101,	//ADC trigger offset by 21 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_22	=	0b10110,	//ADC trigger offset by 22 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_23	=	0b10111,	//ADC trigger offset by 23 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_24	=	0b11000,	//ADC trigger offset by 24 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_25	=	0b11001,	//ADC trigger offset by 25 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_26	=	0b11010,	//ADC trigger offset by 26 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_27	=	0b11011,	//ADC trigger offset by 27 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_28	=	0b11100,	//ADC trigger offset by 28 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_29	=	0b11101,	//ADC trigger offset by 29 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_30	=	0b11110,	//ADC trigger offset by 30 trigger events
    PGEVT_ADTR1OFS_OFFSET_EVENTS_31	=	0b11111 	//ADC trigger offset by 31 trigger events
}PGEVT_ADTR1OFS_e; // ADC Trigger 1 Offset Selection bits

#define REG_PGEVT_ADTR1PS_POSTSCALE_1   0b0000000000000000	//ADC Trigger PostScaler = 1:0
#define REG_PGEVT_ADTR1PS_POSTSCALE_2   0b0000100000000000	//ADC Trigger PostScaler = 1:1
#define REG_PGEVT_ADTR1PS_POSTSCALE_3   0b0001000000000000	//ADC Trigger PostScaler = 1:2
#define REG_PGEVT_ADTR1PS_POSTSCALE_4   0b0001100000000000	//ADC Trigger PostScaler = 1:3
#define REG_PGEVT_ADTR1PS_POSTSCALE_5   0b0010000000000000	//ADC Trigger PostScaler = 1:4
#define REG_PGEVT_ADTR1PS_POSTSCALE_6   0b0010100000000000	//ADC Trigger PostScaler = 1:5
#define REG_PGEVT_ADTR1PS_POSTSCALE_7   0b0011000000000000	//ADC Trigger PostScaler = 1:6
#define REG_PGEVT_ADTR1PS_POSTSCALE_8   0b0011100000000000	//ADC Trigger PostScaler = 1:7
#define REG_PGEVT_ADTR1PS_POSTSCALE_9   0b0100000000000000	//ADC Trigger PostScaler = 1:8
#define REG_PGEVT_ADTR1PS_POSTSCALE_10	0b0100100000000000	//ADC Trigger PostScaler = 1:9
#define REG_PGEVT_ADTR1PS_POSTSCALE_11	0b0101000000000000	//ADC Trigger PostScaler = 1:10
#define REG_PGEVT_ADTR1PS_POSTSCALE_12	0b0101100000000000	//ADC Trigger PostScaler = 1:11
#define REG_PGEVT_ADTR1PS_POSTSCALE_13	0b0110000000000000	//ADC Trigger PostScaler = 1:12
#define REG_PGEVT_ADTR1PS_POSTSCALE_14	0b0110100000000000	//ADC Trigger PostScaler = 1:13
#define REG_PGEVT_ADTR1PS_POSTSCALE_15	0b0111000000000000	//ADC Trigger PostScaler = 1:14
#define REG_PGEVT_ADTR1PS_POSTSCALE_16	0b0111100000000000	//ADC Trigger PostScaler = 1:15
#define REG_PGEVT_ADTR1PS_POSTSCALE_17	0b1000000000000000	//ADC Trigger PostScaler = 1:16
#define REG_PGEVT_ADTR1PS_POSTSCALE_18	0b1000100000000000	//ADC Trigger PostScaler = 1:17
#define REG_PGEVT_ADTR1PS_POSTSCALE_19	0b1001000000000000	//ADC Trigger PostScaler = 1:18
#define REG_PGEVT_ADTR1PS_POSTSCALE_20	0b1001100000000000	//ADC Trigger PostScaler = 1:19
#define REG_PGEVT_ADTR1PS_POSTSCALE_21	0b1010000000000000	//ADC Trigger PostScaler = 1:20
#define REG_PGEVT_ADTR1PS_POSTSCALE_22	0b1010100000000000	//ADC Trigger PostScaler = 1:21
#define REG_PGEVT_ADTR1PS_POSTSCALE_23	0b1011000000000000	//ADC Trigger PostScaler = 1:22
#define REG_PGEVT_ADTR1PS_POSTSCALE_24	0b1011100000000000	//ADC Trigger PostScaler = 1:23
#define REG_PGEVT_ADTR1PS_POSTSCALE_25	0b1100000000000000	//ADC Trigger PostScaler = 1:24
#define REG_PGEVT_ADTR1PS_POSTSCALE_26	0b1100100000000000	//ADC Trigger PostScaler = 1:25
#define REG_PGEVT_ADTR1PS_POSTSCALE_27	0b1101000000000000	//ADC Trigger PostScaler = 1:26
#define REG_PGEVT_ADTR1PS_POSTSCALE_28	0b1101100000000000	//ADC Trigger PostScaler = 1:27
#define REG_PGEVT_ADTR1PS_POSTSCALE_29	0b1110000000000000	//ADC Trigger PostScaler = 1:28
#define REG_PGEVT_ADTR1PS_POSTSCALE_30	0b1110100000000000	//ADC Trigger PostScaler = 1:29
#define REG_PGEVT_ADTR1PS_POSTSCALE_31	0b1111000000000000	//ADC Trigger PostScaler = 1:30
#define REG_PGEVT_ADTR1PS_POSTSCALE_32	0b1111100000000000	//ADC Trigger PostScaler = 1:31

typedef enum {
    PGEVT_ADTR1PS_POSTSCALE_1	 =	0b00000,	//ADC Trigger PostScaler = 1:0
    PGEVT_ADTR1PS_POSTSCALE_2	 =	0b00001,	//ADC Trigger PostScaler = 1:1
    PGEVT_ADTR1PS_POSTSCALE_3	 =	0b00010,	//ADC Trigger PostScaler = 1:2
    PGEVT_ADTR1PS_POSTSCALE_4	 =	0b00011,	//ADC Trigger PostScaler = 1:3
    PGEVT_ADTR1PS_POSTSCALE_5	 =	0b00100,	//ADC Trigger PostScaler = 1:4
    PGEVT_ADTR1PS_POSTSCALE_6	 =	0b00101,	//ADC Trigger PostScaler = 1:5
    PGEVT_ADTR1PS_POSTSCALE_7	 =	0b00110,	//ADC Trigger PostScaler = 1:6
    PGEVT_ADTR1PS_POSTSCALE_8	 =	0b00111,	//ADC Trigger PostScaler = 1:7
    PGEVT_ADTR1PS_POSTSCALE_9	 =	0b01000,	//ADC Trigger PostScaler = 1:8
    PGEVT_ADTR1PS_POSTSCALE_10 =	0b01001,	//ADC Trigger PostScaler = 1:9
    PGEVT_ADTR1PS_POSTSCALE_11 =	0b01010,	//ADC Trigger PostScaler = 1:10
    PGEVT_ADTR1PS_POSTSCALE_12 =	0b01011,	//ADC Trigger PostScaler = 1:11
    PGEVT_ADTR1PS_POSTSCALE_13 =	0b01100,	//ADC Trigger PostScaler = 1:12
    PGEVT_ADTR1PS_POSTSCALE_14 =	0b01101,	//ADC Trigger PostScaler = 1:13
    PGEVT_ADTR1PS_POSTSCALE_15 =	0b01110,	//ADC Trigger PostScaler = 1:14
    PGEVT_ADTR1PS_POSTSCALE_16 =	0b01111,	//ADC Trigger PostScaler = 1:15
    PGEVT_ADTR1PS_POSTSCALE_17 =	0b10000,	//ADC Trigger PostScaler = 1:16
    PGEVT_ADTR1PS_POSTSCALE_18 =	0b10001,	//ADC Trigger PostScaler = 1:17
    PGEVT_ADTR1PS_POSTSCALE_19 =	0b10010,	//ADC Trigger PostScaler = 1:18
    PGEVT_ADTR1PS_POSTSCALE_20 =	0b10011,	//ADC Trigger PostScaler = 1:19
    PGEVT_ADTR1PS_POSTSCALE_21 =	0b10100,	//ADC Trigger PostScaler = 1:20
    PGEVT_ADTR1PS_POSTSCALE_22 =	0b10101,	//ADC Trigger PostScaler = 1:21
    PGEVT_ADTR1PS_POSTSCALE_23 =	0b10110,	//ADC Trigger PostScaler = 1:22
    PGEVT_ADTR1PS_POSTSCALE_24 =	0b10111,	//ADC Trigger PostScaler = 1:23
    PGEVT_ADTR1PS_POSTSCALE_25 =	0b11000,	//ADC Trigger PostScaler = 1:24
    PGEVT_ADTR1PS_POSTSCALE_26 =	0b11001,	//ADC Trigger PostScaler = 1:25
    PGEVT_ADTR1PS_POSTSCALE_27 =	0b11010,	//ADC Trigger PostScaler = 1:26
    PGEVT_ADTR1PS_POSTSCALE_28 =	0b11011,	//ADC Trigger PostScaler = 1:27
    PGEVT_ADTR1PS_POSTSCALE_29 =	0b11100,	//ADC Trigger PostScaler = 1:28
    PGEVT_ADTR1PS_POSTSCALE_30 =	0b11101,	//ADC Trigger PostScaler = 1:29
    PGEVT_ADTR1PS_POSTSCALE_31 =	0b11110,	//ADC Trigger PostScaler = 1:30
    PGEVT_ADTR1PS_POSTSCALE_32 =	0b11111 	//ADC Trigger PostScaler = 1:31
}PGEVT_ADTR1PS_e;  // ADC Trigger 1 Post-Scaler Selection bits


#define REG_PGEVT_ADTR1EN3_PGxTRIGC_ENABLED  0b0000010000000000 // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN3_PGxTRIGC_DISABLED 0b0000000000000000  // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN3_PGxTRIGC_ENABLED = 0b1, // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 3
    PGEVT_ADTR1EN3_PGxTRIGC_DISABLED = 0b0  // PGxTRIGC register compare event is disabled as trigger source for ADC Trigger 3
}PGEVT_ADTR1EN3_e;  // ADC Trigger 3 Source is PGxTRIGC Compare Event Enable bit
    
#define REG_PGEVT_ADTR1EN2_PGxTRIGB_ENABLED  0b0000001000000000 // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN2_PGxTRIGB_DISABLED 0b0000000000000000  // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN2_PGxTRIGB_ENABLED = 0b1, // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 2
    PGEVT_ADTR1EN2_PGxTRIGB_DISABLED = 0b0  // PGxTRIGB register compare event is disabled as trigger source for ADC Trigger 2
}PGEVT_ADTR1EN2_e;  // ADC Trigger 2 Source is PGxTRIGB Compare Event Enable bit
    
#define REG_PGEVT_ADTR1EN1_PGxTRIGA_ENABLED  0b0000000100000000 // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 1
#define REG_PGEVT_ADTR1EN1_PGxTRIGA_DISABLED 0b0000000000000000  // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 1

typedef enum {
    PGEVT_ADTR1EN1_PGxTRIGA_ENABLED = 0b1, // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 1
    PGEVT_ADTR1EN1_PGxTRIGA_DISABLED = 0b0  // PGxTRIGA register compare event is disabled as trigger source for ADC Trigger 1
}PGEVT_ADTR1EN1_e;  // ADC Trigger 1 Source is PGxTRIGA Compare Event Enable bit

typedef enum {
    PGEVT_ADTRxEN_PGxTRIGA = 0b001, // PGxTRIGA register compare event is enabled as trigger source for ADC Trigger 1 or 2
    PGEVT_ADTRxEN_PGxTRIGB = 0b010, // PGxTRIGB register compare event is enabled as trigger source for ADC Trigger 1 or 2
    PGEVT_ADTRxEN_PGxTRIGC = 0b100, // PGxTRIGC register compare event is enabled as trigger source for ADC Trigger 1 or 2
    PGEVT_ADTRxEN_NONE = 0b000  // PGxTRIGn register compare event used as trigger source for ADC Trigger 1 or 2
}PGEVT_ADTRxEN_e;  // ADC Trigger 1 or 2 Source is PGxTRIGA/B/C Compare Event Enable bit


#define REG_PGEVT_UPDTRG_PGxTRIGA   0b0000000000011000 // A write of the PGxTRIGA register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_PGxPHASE   0b0000000000010000 // A write of the PGxPHASE register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_PGxDC      0b0000000000001000 // A write of the PGxDC register automatically sets the UPDATE bit
#define REG_PGEVT_UPDTRG_UPDATE_BIT 0b0000000000000000  // User must set the UPDATE bit (PGxSTAT<4>) manually

typedef enum {
    PGEVT_UPDTRG_PGxTRIGA = 0b11, // A write of the PGxTRIGA register automatically sets the UPDATE bit
    PGEVT_UPDTRG_PGxPHASE = 0b10, // A write of the PGxPHASE register automatically sets the UPDATE bit
    PGEVT_UPDTRG_PGxDC = 0b01, // A write of the PGxDC register automatically sets the UPDATE bit
    PGEVT_UPDTRG_UPDATE_BIT = 0b00 // User must set the UPDATE bit (PGxSTAT<4>) manually
}PGEVT_UPDTRG_e;  // Update Trigger Select bits

#define REG_PGEVT_PGTRGSEL_PGxTRIGC 0b0000000000000011 // PGxTRIGC compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_PGxTRIGB 0b0000000000000010 // PGxTRIGB compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_PGxTRIGA 0b0000000000000001 // PGxTRIGA compare event is the PWM Generator trigger
#define REG_PGEVT_PGTRGSEL_EOC      0b0000000000000000 // EOC event is the PWM Generator trigger

typedef enum {
    PGEVT_PGTRGSEL_PGxTRIGC = 0b011, // PGxTRIGC compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_PGxTRIGB = 0b010, // PGxTRIGB compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_PGxTRIGA = 0b001, // PGxTRIGA compare event is the PWM Generator trigger
    PGEVT_PGTRGSEL_EOC = 0b000 // EOC event is the PWM Generator trigger
}PGEVT_PGTRGSEL_e;   // PWM Generator Trigger Output Selection bits


typedef union {
    struct {

        volatile PGEVT_PGTRGSEL_e PGTRGSEL : 3; // PWM Generator Trigger Output Selection bits(1)
        volatile PGEVT_UPDTRG_e UPDTRG : 2;     // Update Trigger Select bits
        volatile unsigned : 3;            // reserved
    //    volatile PGEVT_ADTR1EN1_e ADTR1EN1 : 1; // ADC Trigger 1 Source is PGxTRIGA Compare Event Enable bit
    //    volatile PGEVT_ADTR1EN2_e ADTR1EN2 : 1; // ADC Trigger 2 Source is PGxTRIGB Compare Event Enable bit
    //    volatile PGEVT_ADTR1EN3_e ADTR1EN3 : 1; // ADC Trigger 3 Source is PGxTRIGC Compare Event Enable bit
        volatile PGEVT_ADTRxEN_e  ADTR1EN : 3;   // ADC Trigger 1 Source is PGxTRIGA/B/C Compare Event 
        volatile PGEVT_ADTR1PS_e  ADTR1PS : 5;   // ADC Trigger 1 Post-Scaler Selection bits

        volatile PGEVT_ADTR1OFS_e ADTR1OFS : 5; // ADC Trigger 1 Offset Selection bits
    //    volatile PGEVT_ADTR2EN1_e ADTR2EN1 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
    //    volatile PGEVT_ADTR2EN2_e ADTR2EN2 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
    //    volatile PGEVT_ADTR2EN3_e ADTR2EN3 : 1; // ADC Trigger 2 Source is PGxTRIGA Compare Event Enable bit
        volatile PGEVT_ADTRxEN_e ADTR2EN : 3;   // ADC Trigger 2 Source is PGxTRIGA/B/C Compare Event 
        volatile PGEVT_IEVTSEL_e IEVTSEL : 2;   // Interrupt Event Selection bits
        volatile unsigned : 2;            // reserved
        volatile PGEVT_SIEN_e SIEN : 1;         // PCI Sync Interrupt Enable bit
        volatile PGEVT_FFIEN_e FFIEN: 1;        // PCI Feed-Forward Interrupt Enable bit
        volatile PGEVT_CLIEN_e CLIEN: 1;        // PCI Current-Limit Interrupt Enable bit
        volatile PGEVT_FLTIEN_e FLTIEN: 1;      // PCI Fault Interrupt Enable bit

    } __attribute__((packed)) bits;
    volatile uint32_t value;
}PGxEVT_t;


/* ===========================================================================
 * PGxyPCIL: PWM GENERATOR xy PCI REGISTER LOW (x = PWM GENERATOR #; y = F, CL, FF OR S)
 * ===========================================================================*/
#define REG_PGxyPCIL_VALID_DATA_WRITE_MASK  0xFFFF
#define REG_PGxyPCIL_VALID_DATA_READ_MASK   0xFFFF

#define REG_PGxyPCIH_VALID_DATA_WRITE_MASK  0xF7FF
#define REG_PGxyPCIH_VALID_DATA_READ_MASK   0xF7FF

#define REG_PGxyPCI_VALID_DATA_WRITE_MASK  0xF7FFFFFF
#define REG_PGxyPCI_VALID_DATA_READ_MASK   0xF7FFFFFF


#define REG_PGxyPCIL_TSYNCDIS_IMMEDIATE  0b1000000000000000 // Termination of latched PCI occurs immediately
#define REG_PGxyPCIL_TSYNCDIS_EOC        0b0000000000000000 // Termination of latched PCI occurs at PWM EOC

typedef enum {
    PGxyPCI_TSYNCDIS_IMMEDIATE = 0b1, // Termination of latched PCI occurs immediately
    PGxyPCI_TSYNCDIS_EOC       = 0b0  // Termination of latched PCI occurs at PWM EOC
}PGxyPCIL_TSYNCDIS_e; // Termination Synchronization Disable 

#define REG_PGxyPCIL_TERM_PCI_SRC_9     0b0111000000000000 // Termination Event Selection: PCI Source #9
#define REG_PGxyPCIL_TERM_PCI_SRC_8     0b0110000000000000 // Termination Event Selection: PCI Source #8
#define REG_PGxyPCIL_TERM_PCI_SRC_1     0b0101000000000000 // Termination Event Selection: PCI Source #1
#define REG_PGxyPCIL_TERM_PGxTRIGC      0b0100000000000000 // Termination Event Selection: PGxTRIGC
#define REG_PGxyPCIL_TERM_PGxTRIGB      0b0011000000000000 // Termination Event Selection: PGxTRIGB
#define REG_PGxyPCIL_TERM_PGxTRIGA      0b0010000000000000 // Termination Event Selection: PGxTRIGA
#define REG_PGxyPCIL_TERM_AUTO          0b0001000000000000 // Termination Event Selection: Auto-Terminate
#define REG_PGxyPCIL_TERM_MANUAL        0b0000000000000000 // Termination Event Selection: Manual Terminate

typedef enum {
    PGxyPCI_TERM_PCI_SRC_9 = 0b111, // Termination Event Selection: PCI Source #9
    PGxyPCI_TERM_PCI_SRC_8 = 0b110, // Termination Event Selection: PCI Source #8
    PGxyPCI_TERM_PCI_SRC_1 = 0b101, // Termination Event Selection: PCI Source #1
    PGxyPCI_TERM_PGxTRIGC  = 0b100, // Termination Event Selection: PGxTRIGC
    PGxyPCI_TERM_PGxTRIGB  = 0b011, // Termination Event Selection: PGxTRIGB
    PGxyPCI_TERM_PGxTRIGA  = 0b010, // Termination Event Selection: PGxTRIGA
    PGxyPCI_TERM_AUTO      = 0b001, // Termination Event Selection: Auto-Terminate
    PGxyPCI_TERM_MANUAL    = 0b000  // Termination Event Selection: Manual Terminate
}PGxyPCIL_TERM_e; // Termination Event Selectiona

#define REG_PGxyPCIL_AQPS_INVERTED      0b0000100000000000 // Acceptance Qualifier Polarity: Inverted
#define REG_PGxyPCIL_AQPS_NOT_INVERTED  0b0000000000000000 // Acceptance Qualifier Polarity: Not inverted

typedef enum {
    PGxyPCI_AQPS_INVERTED = 0b1,       // Acceptance Qualifier Polarity: Inverted
    PGxyPCI_AQPS_NOT_INVERTED  = 0b0   // Acceptance Qualifier Polarity: Not inverted
}PGxyPCIL_AQPS_e; // Acceptance Qualifier Polarity Select bit 


#define REG_PGxyPCIL_AQSS_SWPCI         0b0000011100000000 // SWPCI control bit only (qualifier forced to ?0?)
#define REG_PGxyPCIL_AQSS_PCI_SRC_9     0b0000011000000000 // Selects PCI Source #9
#define REG_PGxyPCIL_AQSS_PCI_SRC_8     0b0000010100000000 // Selects PCI Source #8
#define REG_PGxyPCIL_AQSS_PCI_SRC_1     0b0000010000000000 // Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
#define REG_PGxyPCIL_AQSS_PWM_TRIG      0b0000001100000000 // PWM Generator is triggered
#define REG_PGxyPCIL_AQSS_LEB_ON        0b0000001000000000 // LEB is active
#define REG_PGxyPCIL_AQSS_DC_ON         0b0000000100000000 // Duty cycle is active (base PWM Generator signal)
#define REG_PGxyPCIL_AQSS_NONE          0b0000000000000000 // No acceptance qualifier is used (qualifier forced to ?1?)

typedef enum {
    PGxyPCI_AQSS_SWPCI     = 0b111, // SWPCI control bit only (qualifier forced to ?0?)
    PGxyPCI_AQSS_PCI_SRC_9 = 0b110, // Selects PCI Source #9
    PGxyPCI_AQSS_PCI_SRC_8 = 0b101, // Selects PCI Source #8
    PGxyPCI_AQSS_PCI_SRC_1 = 0b100, // Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
    PGxyPCI_AQSS_PWM_TRIG  = 0b011, // PWM Generator is triggered
    PGxyPCI_AQSS_LEB_ON    = 0b010, // LEB is active
    PGxyPCI_AQSS_DC_ON     = 0b001, // Duty cycle is active (base PWM Generator signal)
    PGxyPCI_AQSS_NONE      = 0b000  // No acceptance qualifier is used (qualifier forced to ?1?)
}PGxyPCIL_AQSS_e; // Acceptance Qualifier Source Selection bits


#define REG_PGxyPCIL_SWTERM_TERMINATE   0b0000000010000000 // PCI Software Termination: Terminate
#define REG_PGxyPCIL_SWTERM_RUN         0b0000000000000000 // PCI Software Termination: Run

typedef enum {
    PGxyPCI_SWTERM_TERMINATE = 0b1,       // PCI Software Termination: Terminate
    PGxyPCI_SWTERM_RUN  = 0b0             // PCI Software Termination: Run
}PGxyPCIL_SWTERM_e; // PCI Software Termination bit

#define REG_PGxyPCIL_PSYNC_PWM_EOC      0b0000000001000000 // PCI source is synchronized to PWM EOC
#define REG_PGxyPCIL_PSYNC_NONE         0b0000000000000000 // PCI source is not synchronized to PWM EOC

typedef enum {
    PGxyPCI_PSYNC_PWM_EOC = 0b1,       // PCI source is synchronized to PWM EOC
    PGxyPCI_PSYNC_NONE  = 0b0          // PCI source is not synchronized to PWM EOC
}PGxyPCIL_PSYNC_e; // PCI Synchronization Control

#define REG_PGxyPCIL_PPS_INVERTED       0b0000000000100000 // PCI Polarity Selection: Inverted
#define REG_PGxyPCIL_PPS_NOT_INVERTED   0b0000000000000000 // PCI Polarity Selection: not inverted

typedef enum {
    PGxyPCI_PPS_INVERTED = 0b1,        // PCI Polarity Selection: Inverted
    PGxyPCI_PPS_NOT_INVERTED  = 0b0    // PCI Polarity Selection: not inverted
}PGxyPCIL_PPS_e; // PCI Polarity Selection


#define REG_PGxyPCIL_PSS_CLC1       0b0000000000011111	// PCI Source Selection: CLC1
//#define REG_PGxyPCIL_PSS_         0b0000000000011110	// PCI Source Selection: Reserved
#define REG_PGxyPCIL_PSS_CMP3OUT    0b0000000000011101	// PCI Source Selection: Comparator 3 output
#define REG_PGxyPCIL_PSS_CMP2OUT    0b0000000000011100	// PCI Source Selection: Comparator 2 output
#define REG_PGxyPCIL_PSS_CMP1OUT    0b0000000000011011	// PCI Source Selection: Comparator 1 output
#define REG_PGxyPCIL_PSS_PWMEVTD    0b0000000000011010	// PCI Source Selection: PWM Event D
#define REG_PGxyPCIL_PSS_PWMEVTC    0b0000000000011001	// PCI Source Selection: PWM Event C
#define REG_PGxyPCIL_PSS_PWMEVTB    0b0000000000011000	// PCI Source Selection: PWM Event B
#define REG_PGxyPCIL_PSS_PWMEVTA    0b0000000000010111	// PCI Source Selection: PWM Event A
#define REG_PGxyPCIL_PSS_PCI_P22    0b0000000000010110	// PCI Source Selection: Device pin, PCI<22>
#define REG_PGxyPCIL_PSS_PCI_P21    0b0000000000010101	// PCI Source Selection: Device pin, PCI<21>
#define REG_PGxyPCIL_PSS_PCI_P20    0b0000000000010100	// PCI Source Selection: Device pin, PCI<20>
#define REG_PGxyPCIL_PSS_PCI_P19    0b0000000000010011	// PCI Source Selection: Device pin, PCI<19>
#define REG_PGxyPCIL_PSS_PCI_RP18   0b0000000000010010	// PCI Source Selection: RPn input, PCI18R
#define REG_PGxyPCIL_PSS_PCI_RP17   0b0000000000010001	// PCI Source Selection: RPn input, PCI17R
#define REG_PGxyPCIL_PSS_PCI_RP16   0b0000000000010000	// PCI Source Selection: RPn input, PCI16R
#define REG_PGxyPCIL_PSS_PCI_RP15   0b0000000000001111	// PCI Source Selection: RPn input, PCI15R
#define REG_PGxyPCIL_PSS_PCI_RP14   0b0000000000001110	// PCI Source Selection: RPn input, PCI14R
#define REG_PGxyPCIL_PSS_PCI_RP13   0b0000000000001101	// PCI Source Selection: RPn input, PCI13R
#define REG_PGxyPCIL_PSS_PCI_RP12   0b0000000000001100	// PCI Source Selection: RPn input, PCI12R
#define REG_PGxyPCIL_PSS_PCI_RP11   0b0000000000001011	// PCI Source Selection: RPn input, PCI11R
#define REG_PGxyPCIL_PSS_PCI_RP10   0b0000000000001010	// PCI Source Selection: RPn input, PCI10R
#define REG_PGxyPCIL_PSS_PCI_RP9    0b0000000000001001	// PCI Source Selection: RPn input, PCI9R
#define REG_PGxyPCIL_PSS_PCI_RP8    0b0000000000001000	// PCI Source Selection: RPn input, PCI8R
//#define REG_PGxyPCIL_PSS_         0b0000000000000111	// PCI Source Selection: Reserved
//#define REG_PGxyPCIL_PSS_         0b0000000000000110	// PCI Source Selection: Reserved
//#define REG_PGxyPCIL_PSS_         0b0000000000000101	// PCI Source Selection: Reserved
//#define REG_PGxyPCIL_PSS_         0b0000000000000100	// PCI Source Selection: Reserved
#define REG_PGxyPCIL_PSS_CMBTRGB    0b0000000000000011	// PCI Source Selection: Internally connected to Combo Trigger B
#define REG_PGxyPCIL_PSS_CMBTRGA    0b0000000000000010	// PCI Source Selection: Internally connected to Combo Trigger A
#define REG_PGxyPCIL_PSS_PWMPCI_MUX 0b0000000000000001	// PCI Source Selection: Internally connected to the output of PWMPCI<2:0> MUX
#define REG_PGxyPCIL_PSS_VSS        0b0000000000000000	// PCI Source Selection: Tied to ?0?

typedef enum {
    PGxyPCI_PSS_CLC1      = 0b11111,	// PCI Source Selection: CLC1
    //PGxyPCI_PSS_        = 0b11110,	// PCI Source Selection: Reserved
    PGxyPCI_PSS_CMP3OUT   = 0b11101,	// PCI Source Selection: Comparator 3 output
    PGxyPCI_PSS_CMP2OUT   = 0b11100,	// PCI Source Selection: Comparator 2 output
    PGxyPCI_PSS_CMP1OUT   = 0b11011,	// PCI Source Selection: Comparator 1 output
    PGxyPCI_PSS_PWMEVTD   = 0b11010,	// PCI Source Selection: PWM Event D
    PGxyPCI_PSS_PWMEVTC   = 0b11001,	// PCI Source Selection: PWM Event C
    PGxyPCI_PSS_PWMEVTB   = 0b11000,	// PCI Source Selection: PWM Event B
    PGxyPCI_PSS_PWMEVTA   = 0b10111,	// PCI Source Selection: PWM Event A
    PGxyPCI_PSS_PCI_P22   = 0b10110,	// PCI Source Selection: Device pin, PCI<22>
    PGxyPCI_PSS_PCI_P21   = 0b10101,	// PCI Source Selection: Device pin, PCI<21>
    PGxyPCI_PSS_PCI_P20   = 0b10100,	// PCI Source Selection: Device pin, PCI<20>
    PGxyPCI_PSS_PCI_P19   = 0b10011,	// PCI Source Selection: Device pin, PCI<19>
    PGxyPCI_PSS_PCI_RP18  = 0b10010,	// PCI Source Selection: RPn input, PCI18R
    PGxyPCI_PSS_PCI_RP17  = 0b10001,	// PCI Source Selection: RPn input, PCI17R
    PGxyPCI_PSS_PCI_RP16  = 0b10000,	// PCI Source Selection: RPn input, PCI16R
    PGxyPCI_PSS_PCI_RP15  = 0b01111,	// PCI Source Selection: RPn input, PCI15R
    PGxyPCI_PSS_PCI_RP14  = 0b01110,	// PCI Source Selection: RPn input, PCI14R
    PGxyPCI_PSS_PCI_RP13  = 0b01101,	// PCI Source Selection: RPn input, PCI13R
    PGxyPCI_PSS_PCI_RP12  = 0b01100,	// PCI Source Selection: RPn input, PCI12R
    PGxyPCI_PSS_PCI_RP11  = 0b01011,	// PCI Source Selection: RPn input, PCI11R
    PGxyPCI_PSS_PCI_RP10  = 0b01010,	// PCI Source Selection: RPn input, PCI10R
    PGxyPCI_PSS_PCI_RP9   = 0b01001,	// PCI Source Selection: RPn input, PCI9R
    PGxyPCI_PSS_PCI_RP8   = 0b01000,	// PCI Source Selection: RPn input, PCI8R
    //PGxyPCI_PSS_        = 0b00111,	// PCI Source Selection: Reserved
    //PGxyPCI_PSS_        = 0b00110,	// PCI Source Selection: Reserved
    //PGxyPCI_PSS_        = 0b00101,	// PCI Source Selection: Reserved
    //PGxyPCI_PSS_        = 0b00100,	// PCI Source Selection: Reserved
    PGxyPCI_PSS_CMBTRGB   = 0b00011,	// PCI Source Selection: Internally connected to Combo Trigger B
    PGxyPCI_PSS_CMBTRGA   = 0b00010,	// PCI Source Selection: Internally connected to Combo Trigger A
    PGxyPCI_PSS_PWMPCI_MX = 0b00001,	// PCI Source Selection: Internally connected to the output of PWMPCI<2:0> MUX
    PGxyPCI_PSS_VSS       = 0b00000	// PCI Source Selection: Tied to ?0?
}PGxyPCIL_PSS_e; // PCI Polarity Selection


#define REG_PGxyPCIH_BPEN_ENABLED   0b1000000000000000  // PCI Bypass Enable bit: bypass active
#define REG_PGxyPCIH_BPEN_DISABLED  0b0000000000000000  // PCI Bypass Enable bit: bypass inactive

typedef enum {
    PGxyPCI_BPEN_ENABLED  = 0b1, // PCI Bypass Enable bit: bypass active
    PGxyPCI_BPEN_DISABLED = 0b0  // PCI Bypass Enable bit: bypass inactive
} PGxyPCIH_BPEN_e;
    
#define REG_PGxyPCIH_BPSEL_PG8      0b0111000000000000 // PCI control is sourced from PWM Generator 8 PCI logic
#define REG_PGxyPCIH_BPSEL_PG7      0b0110000000000000 // PCI control is sourced from PWM Generator 7 PCI logic
#define REG_PGxyPCIH_BPSEL_PG6      0b0101000000000000 // PCI control is sourced from PWM Generator 6 PCI logic
#define REG_PGxyPCIH_BPSEL_PG5      0b0100000000000000 // PCI control is sourced from PWM Generator 5 PCI logic
#define REG_PGxyPCIH_BPSEL_PG4      0b0011000000000000 // PCI control is sourced from PWM Generator 4 PCI logic
#define REG_PGxyPCIH_BPSEL_PG3      0b0010000000000000 // PCI control is sourced from PWM Generator 3 PCI logic
#define REG_PGxyPCIH_BPSEL_PG2      0b0001000000000000 // PCI control is sourced from PWM Generator 2 PCI logic
#define REG_PGxyPCIH_BPSEL_PG1      0b0000000000000000 // PCI control is sourced from PWM Generator 1 PCI logic

typedef enum {
    PGxyPCI_BPSEL_PG8 = 0b111, // PCI control is sourced from PWM Generator 8 PCI logic
    PGxyPCI_BPSEL_PG7 = 0b110, // PCI control is sourced from PWM Generator 7 PCI logic
    PGxyPCI_BPSEL_PG6 = 0b101, // PCI control is sourced from PWM Generator 6 PCI logic
    PGxyPCI_BPSEL_PG5 = 0b100, // PCI control is sourced from PWM Generator 5 PCI logic
    PGxyPCI_BPSEL_PG4 = 0b011, // PCI control is sourced from PWM Generator 4 PCI logic
    PGxyPCI_BPSEL_PG3 = 0b010, // PCI control is sourced from PWM Generator 3 PCI logic
    PGxyPCI_BPSEL_PG2 = 0b001, // PCI control is sourced from PWM Generator 2 PCI logic
    PGxyPCI_BPSEL_PG1 = 0b000  // PCI control is sourced from PWM Generator 1 PCI logic
} PGxyPCIH_BPSEL_e;


#define PGxyPCIH_REG_ACP_

//#define PGxyPCIH_REG_ACP_                 0b0000011100000000 // Reserved
//#define PGxyPCIH_REG_ACP_                 0b0000011000000000 // Reserved
#define REG_PGxyPCIH_REG_ACP_LATCHED_ANY    0b0000010100000000 // Latched any edge
#define REG_PGxyPCIH_REG_ACP_LATCHED_RISE   0b0000010000000000 // Latched rising edge
#define REG_PGxyPCIH_REG_ACP_LATCHED        0b0000001100000000 // Latched
#define REG_PGxyPCIH_REG_ACP_ANY_EDGE       0b0000001000000000 // Any edge
#define REG_PGxyPCIH_REG_ACP_RISE_EDGE      0b0000000100000000 // Rising edge
#define REG_PGxyPCIH_REG_ACP_LEVEL          0b0000000000000000 // Level-sensitive

typedef enum {
    //PGxyPCIH_REG_ACP_  = 0b111	// Reserved
    //PGxyPCIH_REG_ACP_  = 0b110	// Reserved
    PGxyPCI_REG_ACP_LATCHED_ANY  = 0b101, // Latched any edge 0b0000010100000000 // Latched any edge
    PGxyPCI_REG_ACP_LATCHED_RISE = 0b100, // Latched rising edge
    PGxyPCI_REG_ACP_LATCHED      = 0b011, // Latched
    PGxyPCI_REG_ACP_ANY_EDGE     = 0b010, // Any edge
    PGxyPCI_REG_ACP_RISE_EDGE    = 0b001, // Rising edge
    PGxyPCI_REG_ACP_LEVEL        = 0b000  // Level-sensitive
} PGxyPCIH_ACP_e; // PCI Acceptance Criteria Selection bits


#define REG_PGxyPCIH_SWPCI_HIGH     0b0000000010000000  // Drives a ?1? to PCI logic assigned to by the SWPCIM<1:0> control bits
#define REG_PGxyPCIH_SWPCI_LOW      0b0000000000000000  // Drives a ?0? to PCI logic assigned to by the SWPCIM<1:0> control bits

typedef enum {
    PGxyPCI_SWPCI_HIGH  = 0b1, // Drives a ?1? to PCI logic assigned to by the SWPCIM<1:0> control bits
    PGxyPCI_SWPCI_LOW   = 0b0  // Drives a ?0? to PCI logic assigned to by the SWPCIM<1:0> control bits
} PGxyPCIH_SWPCI_e;
   
//#define REG_PGxyPCIH_SWPCIM_      0b0000000001100000 // Reserved
#define REG_PGxyPCIH_SWPCIM_TQ      0b0000000001000000 // SWPCI bit is assigned to termination qualifier logic
#define REG_PGxyPCIH_SWPCIM_AQ      0b0000000000100000 // SWPCI bit is assigned to acceptance qualifier logic
#define REG_PGxyPCIH_SWPCIM_PCI     0b0000000000000000 // SWPCI bit is assigned to PCI acceptance logic

typedef enum {
    PGxyPCI_SWPCIM_TQ  = 0b10, // SWPCI bit is assigned to termination qualifier logic
    PGxyPCI_SWPCIM_AQ  = 0b01, // SWPCI bit is assigned to acceptance qualifier logic
    PGxyPCI_SWPCIM_PCI = 0b00  // SWPCI bit is assigned to PCI acceptance logic
} PGxyPCIH_SWPCIM_e;

#define REG_PGxyPCIH_LATMOD_RESET   0b0000000000010000  // SR latch is Reset-dominant in Latched Acceptance modes
#define REG_PGxyPCIH_LATMOD_SET     0b0000000000000000  // SR latch is Set-dominant in Latched Acceptance modes

typedef enum {
    PGxyPCI_LATMOD_RESET  = 0b1, // SR latch is Reset-dominant in Latched Acceptance modes
    PGxyPCI_LATMOD_SET    = 0b0  // SR latch is Set-dominant in Latched Acceptance modes
} PGxyPCIH_LATMOD_e;

#define REG_PGxyPCIH_TQPS_INVERTED      0b0000000000001000 // Termination Qualifier Polarity Selection: Inverted
#define REG_PGxyPCIH_TQPS_NOT_INVERTED  0b0000000000000000 // Termination Qualifier Polarity Selection: not inverted

typedef enum {
    PGxyPCI_TQPS_INVERTED = 0b1,        // Termination Qualifier Polarity Selection: Inverted
    PGxyPCI_TQPS_NOT_INVERTED  = 0b0    // Termination Qualifier Polarity Selection: not inverted
}PGxyPCIH_TQPS_e; // Termination Qualifier Polarity Selection bit

#define REG_PGxyPCIH_TQSS_SWPCI         0b0000000000000111 // SWPCI control bit only (qualifier forced to ?0?)
#define REG_PGxyPCIH_TQSS_PCI_SRC_9     0b0000000000000110 // Selects PCI Source #9
#define REG_PGxyPCIH_TQSS_PCI_SRC_8     0b0000000000000101 // Selects PCI Source #8
#define REG_PGxyPCIH_TQSS_PCI_SRC_1     0b0000000000000100 // Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
#define REG_PGxyPCIH_TQSS_PWM_TRIG      0b0000000000000011 // PWM Generator is triggered
#define REG_PGxyPCIH_TQSS_LEB_ON        0b0000000000000010 // LEB is active
#define REG_PGxyPCIH_TQSS_DC_ON         0b0000000000000001 // Duty cycle is active (base PWM Generator signal)
#define REG_PGxyPCIH_TQSS_NONE          0b0000000000000000 // No acceptance qualifier is used (qualifier forced to ?1?)

typedef enum {
    PGxyPCI_TQSS_SWPCI     = 0b111, // SWPCI control bit only (qualifier forced to ?0?)
    PGxyPCI_TQSS_PCI_SRC_9 = 0b110, // Selects PCI Source #9
    PGxyPCI_TQSS_PCI_SRC_8 = 0b101, // Selects PCI Source #8
    PGxyPCI_TQSS_PCI_SRC_1 = 0b100, // Selects PCI Source #1 (PWM Generator output selected by the PWMPCI<2:0> bits)
    PGxyPCI_TQSS_PWM_TRIG  = 0b011, // PWM Generator is triggered
    PGxyPCI_TQSS_LEB_ON    = 0b010, // LEB is active
    PGxyPCI_TQSS_DC_ON     = 0b001, // Duty cycle is active (base PWM Generator signal)
    PGxyPCI_TQSS_NONE      = 0b000  // No termination qualifier is used (qualifier forced to ?1?)
}PGxyPCIH_TQSS_e; // Termination Qualifier Source Selection bits


typedef union {
    struct {
        volatile PGxyPCIL_PSS_e PSS : 5;            // Bit 4-0: PCI Source Selection bits
        volatile PGxyPCIL_PPS_e PPS : 1;            // Bit 5: PCI Polarity Select bit
        volatile PGxyPCIL_PSYNC_e PSYNC : 1;        // Bit 6: PCI Synchronization Control
        volatile PGxyPCIL_SWTERM_e SWTERM : 1;      // Bit 7: PCI Software Termination bit
        volatile PGxyPCIL_AQSS_e AQSS : 3;          // Bit 10-8: Acceptance Qualifier Source Selection bits
        volatile PGxyPCIL_AQPS_e AQPS : 1;          // Bit 11: Acceptance Qualifier Polarity Select bit
        volatile PGxyPCIL_TERM_e TERM : 3;          // Bit 14-12: Termination Event Selection bits
        volatile PGxyPCIL_TSYNCDIS_e TSYNCDIS: 1;   // Bit 15: PCI Fault Interrupt Enable bit

        volatile PGxyPCIH_TQSS_e TQSS : 3;          // Bit 2-0: Termination Qualifier Source Selection bits
        volatile PGxyPCIH_TQPS_e TQPS : 1;          // Bit 3: Termination Qualifier Polarity Select bit
        volatile PGxyPCIH_LATMOD_e LATMOD : 1;      // Bit 4: PCI SR Latch Mode bit
        volatile PGxyPCIH_SWPCIM_e SWPCIM : 2;      // Bit 6-5: Software PCI Control Mode bits
        volatile PGxyPCIH_SWPCI_e SWPCI : 1;        // Bit 7: Software PCI Control bit
        volatile PGxyPCIH_ACP_e ACP : 3;            // Bit 10-8: PCI Acceptance Criteria Selection bits
        volatile unsigned : 1;                      // (reserved)
        volatile PGxyPCIH_BPSEL_e BPSEL : 3;        // Bit 14-12: PCI Bypass Source Selection bits
        volatile PGxyPCIH_BPEN_e BPEN : 1;          // Bit 15: PCI Bypass Enable bit
    } __attribute__((packed)) bits; // PGxyPCIL: PWM GENERATOR xy PCI REGISTER HIGH/LOW
    volatile uint32_t value; // Direct read/write access to both registers
}PGxyPCI_t;  // PGxyPCIL: PWM GENERATOR xy PCI REGISTER HIGH/LOW
                    // (x = PWM GENERATOR #; y = F, CL, FF OR S) 


/* ===========================================================================
 * PGxLEBH: PWM GENERATOR x LEADING-EDGE BLANKING REGISTER HIGH
 * ===========================================================================*/
#define REG_PGxLEBCON_VALID_DATA_WRITE_MASK 0x070F
#define REG_PGxLEBCON_VALID_DATA_READ_MASK 0x070F

#define REG_LEBCON_PWMPCI_PG8   0b0000011100000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG7   0b0000011000000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG6   0b0000010100000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG5   0b0000010000000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG4   0b0000001100000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG3   0b0000001000000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG2   0b0000000100000000 // PWM Generator #8 output is made available to PCI logic 
#define REG_LEBCON_PWMPCI_PG1   0b0000000000000000 // PWM Generator #8 output is made available to PCI logic 

typedef enum {
    LEBCON_PWMPCI_PG8 = 0b111, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG7 = 0b110, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG6 = 0b101, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG5 = 0b100, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG4 = 0b011, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG3 = 0b010, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG2 = 0b001, // PWM Generator #8 output is made available to PCI logic 
    LEBCON_PWMPCI_PG1 = 0b000  // PWM Generator #8 output is made available to PCI logic 
}PGxLEBCON_PWMPCI_e; // PWM Source for PCI Selection bits

#define REG_PGxLEBCON_LEBTRG_PHR_ENABLE  0b0000000000001000  // Selected edge of PWMx will trigger the LEB duration counter
#define REG_PGxLEBCON_LEBTRG_PHR_DISABLE 0b0000000000000000  // LEB ignores the selected edge of PWMx
#define REG_PGxLEBCON_LEBTRG_PHF_ENABLE  0b0000000000000100  // Selected edge of PWMx will trigger the LEB duration counter
#define REG_PGxLEBCON_LEBTRG_PHF_DISABLE 0b0000000000000000  // LEB ignores the selected edge of PWMx
#define REG_PGxLEBCON_LEBTRG_PLR_ENABLE  0b0000000000000010  // Selected edge of PWMx will trigger the LEB duration counter
#define REG_PGxLEBCON_LEBTRG_PLR_DISABLE 0b0000000000000000  // LEB ignores the selected edge of PWMx
#define REG_PGxLEBCON_LEBTRG_PLF_ENABLE  0b0000000000000001  // Selected edge of PWMx will trigger the LEB duration counter
#define REG_PGxLEBCON_LEBTRG_PLF_DISABLE 0b0000000000000000  // LEB ignores the selected edge of PWMx

typedef enum {
    PGxLEBCON_LEBTRG_ENABLE  = 0b1, // Selected edge of PWMx will trigger the LEB duration counter
    PGxLEBCON_LEBTRG_DISABLE = 0b0  // LEB ignores the selected edge of PWMx
} PGxLEBCON_LEBTRG_e;

typedef union {
    struct {

        volatile PGxLEBCON_LEBTRG_e PLF : 1;    // Bit 0: PWMxL Falling Edge Trigger Enable bit
        volatile PGxLEBCON_LEBTRG_e PLR : 1;    // Bit 1: PWMxL Rising Edge Trigger Enable bit
        volatile PGxLEBCON_LEBTRG_e PHF : 1;    // Bit 2: PWMxH Falling Edge Trigger Enable bit
        volatile PGxLEBCON_LEBTRG_e PHR : 1;    // Bit 3: PWMxH Rising Edge Trigger Enable bit
        volatile unsigned : 4;                  // Bit 7-4:  (reserved)
        volatile PGxLEBCON_PWMPCI_e PWMPCI : 3; // Bit 10-8: PWM Source for PCI Selection bits
        volatile unsigned : 5;                  // Bit 15-11: (reserved)

    } __attribute__((packed)) bits; // PGxLEBH: PWM GENERATOR x LEADING-EDGE BLANKING REGISTER HIGH
    volatile uint16_t value; // Direct read/write access to both registers
}PGxLEBCON_t;   // PGxLEBH: PWM GENERATOR x LEADING-EDGE BLANKING REGISTER HIGH


/* ===========================================================================
 * PGxDTL/H: PWM GENERATOR x DEAD-TIME REGISTER LOW/HIGH
 * ===========================================================================*/
#define REG_PGxDT_VALID_DATA_WRITE_MASK 0x3FFF3FFF
#define REG_PGxDT_VALID_DATA_READ_MASK 0x3FFF3FFF

/* ********************************************************************************
 * COMPILER v1.35 ISSUE:
 * 
 * The reserved two MSBs of the two 16-bit values are causing the compiler to fail
 * and have therefore been taken out for the time being. To prevent writing invalid
 * values to DTL and DTH, it's recommended to use the REG_PGxDT_VALID_DATA_WRITE_MASK
 * above.
 * 
 * Weirdly this doesn't seem to be an issue with all other data structures in this
 * or similar driver header files. Investigation is on-going (09/06/2018 AR, M91406)
 * 
 * typedef struct {
 *     volatile unsigned DT_FALLING : 14; // dead time low-side PWM output
 *     volatile unsigned  : 2; // reserved
 *     volatile unsigned DT_RISING : 14; // dead time high-side PWM output
 *     volatile unsigned  : 2; // reserved
 * }PGxDT_t;
 *
 * ******************************************************************************** */

typedef union {
    struct {
        volatile uint16_t DT_FALLING : 16; // dead time low-side PWM output
        volatile uint16_t DT_RISING : 16; // dead time high-side PWM output
    } bits;
    volatile uint32_t value;
} PGxDTxy_t;


/* ===========================================================================
 * PGxDC: PWM GENERATOR x DUTY CYCLE REGISTER
 * ===========================================================================*/
#define REG_PGxDC_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxDC_VALID_DATA_READ_MASK 0xFFFF

typedef union {
    struct {
        volatile unsigned DC : 16; // duty cycle time period common PWM modes
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxDC_t;

/* ===========================================================================
 * PGxDCA: PWM GENERATOR x DUTY CYCLE ADJUSTMENT REGISTER
 * ===========================================================================*/
#define REG_PGxDCA_VALID_DATA_WRITE_MASK 0x00FF
#define REG_PGxDCA_VALID_DATA_READ_MASK 0x00FF

typedef union {
    struct {
        volatile unsigned DCA : 8; // duty cycle time period common PWM modes
        volatile unsigned : 8; // reserved
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxDCA_t;


/* ===========================================================================
 * PGxDC: PWM GENERATOR x PERIOD REGISTER
 * ===========================================================================*/
#define REG_PGxPER_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxPER_VALID_DATA_READ_MASK 0xFFFF

typedef union {
    struct {
        volatile unsigned PER : 16; // PWM period PWM ticks
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxPER_t;

/* ===========================================================================
 * PGxDC: PWM GENERATOR x PHASE REGISTER
 * ===========================================================================*/
#define REG_PGxPHASE_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxPHASE_VALID_DATA_READ_MASK 0xFFFF


typedef union {
    struct {
        volatile unsigned PHASE : 16; // PWM period PWM ticks
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxPHASE_t;


/* ===========================================================================
 * PGxLEBL: PWM GENERATOR x LEADING-EDGE BLANKING REGISTER LOW
 * ===========================================================================*/
#define REG_PGxLEB_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxLEB_VALID_DATA_READ_MASK 0xFFFF

typedef union {
    struct {
        volatile unsigned LEB : 16; // PWM period PWM ticks
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxLEB_t;

/* ===========================================================================
 * PGxTRIGA: PWM GENERATOR x TRIGGER y REGISTER (x = PWM Generator, y = A, B or C)
 * ===========================================================================*/
#define REG_PGxTRIGy_VALID_DATA_WRITE_MASK 0xFFFF
#define REG_PGxTRIGy_VALID_DATA_READ_MASK 0xFFFF

typedef union {
    struct {
        volatile unsigned TRG : 16; // PWM trigger PWM ticks
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxTRGy_t;


/* ===========================================================================
 * PGxDC: PWM GENERATOR x CAPTURE REGISTER
 * ===========================================================================*/
#define REG_PGxCAP_VALID_DATA_WRITE_MASK 0x0000
#define REG_PGxCAP_VALID_DATA_READ_MASK 0xFFFF

typedef union {
    struct {
        volatile unsigned CAP : 16; // PWM capture PWM ticks
    } __attribute__((packed)) bits;
    volatile uint16_t value;
} PGxCAP_t;



/*!HSPWM Global Data Structures 
 * ********************************************************************************
 * Summary:
 * Global data structures for PWM module and PWM channel register sets
 * 
 * Description:
 * Global data structures of the PWM module base registers and the PWM generator
 * register set are used to configure specific channels by using pre-configurations
 * loaded into 'arteficial' register maps. 
 *  
 * ******************************************************************************** */

typedef struct {
    volatile PCLKCON_t PCLKCON;  // PCLKCON: PWM CLOCK CONTROL REGISTER
    volatile FSCL_t FSCL;        // FSCL: FREQUENCY SCALE REGISTER
    volatile FSMINPER_t FSMINPER; // FSMINPER: FREQUENCY SCALING MINIMUM PERIOD REGISTER
    volatile MPHASE_t MPHASE; // MPHASE: MASTER PHASE REGISTER
    volatile MDC_t MDC; // MDC: MASTER DUTY CYCLE REGISTER
    volatile MPER_t MPER; // MPER: MASTER PERIOD REGISTER
    volatile LFSR_t LFSR; // LFSR: LINEAR FEEDBACK SHIFT REGISTER
    volatile CMBTRIGy_t CMBTRIG; // CMBTRIGL/H: COMBINATIONAL TRIGGER REGISTER LOW & HIGH
    volatile LOGCONy_t LOGCONA;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile LOGCONy_t LOGCONB;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile LOGCONy_t LOGCONC;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile LOGCONy_t LOGCOND;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile LOGCONy_t LOGCONE;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile LOGCONy_t LOGCONF;  // LOGCONy: COMBINATORIAL PWM LOGIC CONTROLREGISTER A
    volatile PWMEVTy_t PWMEVTA; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER A
    volatile PWMEVTy_t PWMEVTB; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER B
    volatile PWMEVTy_t PWMEVTC; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER C
    volatile PWMEVTy_t PWMEVTD; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER D
    volatile PWMEVTy_t PWMEVTE; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER E
    volatile PWMEVTy_t PWMEVTF; // PWMEVTy: PWM EVENT OUTPUT CONTROL REGISTER F
} __attribute__((packed)) HSPWM_C_MODULE_CONFIG_t;   // GENERIC PWM MODULE BASE REGISTERS


typedef struct {
    volatile PGxCON_t PGxCON; // PWM GENERATOR x CONTROL REGISTER LOW/HIGH
    volatile PGxSTAT_t PGxSTAT; // PWM GENERATOR x STATUS REGISTER
    volatile PGxIOCON_t PGxIOCON; // PWM GENERATOR x I/O CONTROL REGISTER LOW/HIGH
    volatile PGxEVT_t PGxEVT; // PWM GENERATOR x EVENT REGISTER LOW/HIGH
    volatile PGxyPCI_t PGxFPCI; // PWM GENERATOR x FAULT PCI REGISTER LOW(HIGH)
    volatile PGxyPCI_t PGxCLPCI; // PWM GENERATOR x CURRENT LIMIT PCI REGISTER LOW/HIGH
    volatile PGxyPCI_t PGxFFPCI; // PWM GENERATOR x FEED FORWARD PCI REGISTER LOW/HIGH
    volatile PGxyPCI_t PGxSPCI; // PWM GENERATOR x SOFTWARE PCI REGISTER LOW/HIGH
    volatile PGxLEB_t PGxLEB; // PWM GENERATOR x LEADING-EDGE BLANKING REGISTER LOW
    volatile PGxLEBCON_t PGxLEBCON; // PWM GENERATOR x LEADING-EDGE BLANKING REGISTER HIGH
    volatile PGxPHASE_t PGxPHASE; // PWM GENERATOR x PHASE REGISTER
    volatile PGxDC_t PGxDC; // PWM GENERATOR x DUTY CYCLE REGISTER
    volatile PGxDCA_t PGxDCA; // PWM GENERATOR x DUTY CYCLE ADJUSTMENT REGISTER
    volatile PGxPER_t PGxPER; // PWM GENERATOR x PERIOD REGISTER
    volatile PGxTRGy_t PGxTRIGA; // PWM GENERATOR x TRIGGER A REGISTER
    volatile PGxTRGy_t PGxTRIGB; // PWM GENERATOR x TRIGGER B REGISTER
    volatile PGxTRGy_t PGxTRIGC; // PWM GENERATOR x TRIGGER C REGISTER
    volatile PGxDTxy_t PGxDT; // PWM GENERATOR x DEAD-TIME REGISTER LOW/HIGH
    volatile PGxCAP_t PGxCAP; // PWM GENERATOR x CAPTURE REGISTER
} HSPWM_C_GENERATOR_CONFIG_t;   // INDIVIDUAL PWM GENERATOR REGISTERS


// Prototypes

extern volatile uint16_t hspwm_init_pwm_module(HSPWM_C_MODULE_CONFIG_t pwm_config);
extern volatile uint16_t hspwm_init_pwm_generator(uint16_t instance, HSPWM_C_GENERATOR_CONFIG_t pg_config);

extern volatile uint16_t hspwm_init_independent_pwm (
    uint16_t instance,
    PCLKCON_t regPCLK,
    PGxCON_t regPGxCON,
    PGxEVT_t regPGxEVT,
    PGxIOCON_t regPGxIOCON,
    PGxDTxy_t regPGxDT
    );

extern volatile uint16_t hspwm_init_pwm_timing (
    uint16_t channel,
    uint16_t regPGxPER,
    uint16_t regPGxDC,
    uint16_t regPGxPHASE
    );
extern volatile uint16_t hspwm_set_duty_cycle(
    uint16_t instance, 
    uint16_t regPGxDC, 
    uint16_t regPGxDCA
    );

extern volatile uint16_t smpsHSPWM_PowerUp(void);
extern volatile uint16_t smpsHSPWM_PowerDown(void);
extern volatile uint16_t smpsHSPWM_Enable(volatile uint16_t instance, volatile bool wait_for_hres);
extern volatile uint16_t smpsHSPWM_Disable(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_OVR_Hold(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_OVR_Release(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_OVR_ReleaseHighSide(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_OVR_ReleaseLowSide(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_SetGPIO_HighSide(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_ResetGPIO_HighSide(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_SetGPIO_LowSide(volatile uint16_t instance);
extern volatile uint16_t smpsHSPWM_ResetGPIO_LowSide(volatile uint16_t instance);

#endif
// End of File MCAL_P33SMPS_HSPWM_H
