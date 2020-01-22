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
/*@@p33MP_uart.h
 * ***************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxGS UART SFRs
 *
 * Description:
 * The UART module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 *
 * File:   p33SMPS_uart.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

#ifndef MCAL_P33SMPS_UART_H
#define MCAL_P33SMPS_UART_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../p33SMPS_plib.h" // PLIB header required to get access to oscillator driver declarations
#include "../p33SMPS_devices.h" // DEVICES header to derive device-dependent properties

/*!p33SMPS_uart.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS UART SFRs
 *
 * Description:
 * The UART module offers a number of registers and configuration options. This additional
 * header file contains defines for all required settings.
 * ***********************************************************************************************/

// Device specific properties
#if defined (__P33SMPS_CH__) 

    #if defined (__P33SMPS_CH_SLV__) 
        #define UART_UART_COUNT 1
        #define UART_INDEX_REG_OFFSET 0x0014

    #elif defined (__P33SMPS_CH_MSTR__) 
        #define UART_UART_COUNT 2
        #define UART_INDEX_REG_OFFSET 0x0014
    #endif

#elif defined (__P33SMPS_CK__)

    #define UART_UART_COUNT 3
    #define SMPS_UART1   1
    #define SMPS_UART2   2
    #define SMPS_UART3   3

#else
 //#error === selected device not supported by this library ===

#endif

// Interrupt Flag-Bits & Priorities
#if ( UART_UART_COUNT >= 1 )

    #define UART1_RX_ISR_FLAG  _U1RXIF // UART1 RX interrupt flag
    #define UART1_RX_ISR_PRIORITY _U1RXIP // UART1 RX interrupt priority
    #define UART1_RX_ISR_ENABLE     _U1RXIE // UART1 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 2 )

    #define UART2_RX_ISR_FLAG  _U2RXIF // UART2 RX interrupt flag
    #define UART2_RX_ISR_PRIORITY _U2RXIP // UART2 RX interrupt priority
    #define UART2_RX_ISR_ENABLE     _U2RXIE // UART2 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 3 )

    #define UART3_RX_ISR_FLAG  _U3RXIF // UART3 RX interrupt flag
    #define UART3_RX_ISR_PRIORITY _U3RXIP // UART3 RX interrupt priority
    #define UART3_RX_ISR_ENABLE     _U3RXIE // UART3 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 4 )
  #pragma message "=== selected UART instance is not supported by this device ==="
#endif


#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__) 



#else

    #pragma message "Gap in SMPS UART driver device support. Please review file."
    
#endif

#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

/* ===========================================================================
 * UxMODE: UARTx CONFIGURATION REGISTER
 * ===========================================================================*/

    #define UART_UxMODEL_REG_DISPOSE_MASK   (uint16_t)0x0000 // Bitmask used to reset register
    #define UART_UxMODEL_REG_READ_MASK      (uint16_t)0xBBFF // Bitmask filtering active bits (excludes reserved and unimplemented bits)
    #define UART_UxMODEL_REG_WRITE_MASK     (uint16_t)0xBBFF // Bitmask filtering active bits (excludes reserved and unimplemented bits
    #define UART_UxMODEL_REG_OFF_MASK       (uint16_t)0x3BFF // Bitmask  forcing ENABLE bit to OFF
    
   // Full Register Bit Fields
    typedef enum {
        
        REG_UxMODE_UARTEN_ENABLED      = 0b1000000000000000, // UART Enable bit
        REG_UxMODE_UARTEN_DISABLED     = 0b0000000000000000,

        REG_UxMODE_USIDL_ACTIVE        = 0b0000000000000000, // UART Stop in Idle Mode bit
        REG_UxMODE_USIDL_STOP          = 0b0010000000000000,

        REG_UxMODE_WAKE_ENABLED        = 0b0001000000000000, // Wake-up Enable bit
        REG_UxMODE_WAKE_DISABLED       = 0b0000000000000000,

        REG_UxMODE_RXBIMD_DMX_LIN      = 0b0000100000000000, // Receive Break Interrupt Mode bit
        REG_UxMODE_RXBIMD_DEFAULT      = 0b0000000000000000,

        REG_UxMODE_BRKOVR_ON           = 0b0000001000000000, // Send Break Software Override bit
        REG_UxMODE_BRKOVR_OFF          = 0b0000000000000000,

        REG_UxMODE_UTXBRK_ENABLED      = 0b0000000100000000, // UART Transmit Break bit
        REG_UxMODE_UTXBRK_DISABLED     = 0b0000000000000000,  

        REG_UxMODE_BRGH_HIGH_SPEED     = 0b0000000010000000, // High Baud Rate Select bit
        REG_UxMODE_BRGH_DEFAULT        = 0b0000000000000000,  

        REG_UxMODE_ABAUD_ENABLED       = 0b0000000001000000, // Auto-Baud Detect Enable bit (read-only when MOD<3:0> = 1xxx)
        REG_UxMODE_ABAUD_DISABLED      = 0b0000000000000000,  

        REG_UxMODE_UTXEN_ENABLED       = 0b0000000000100000, // UART Transmit Enable bit
        REG_UxMODE_UTXEN_DISABLED      = 0b0000000000000000,  

        REG_UxMODE_URXEN_ENABLED       = 0b0000000000010000, // UART Receive Enable bit
        REG_UxMODE_URXEN_DISABLED      = 0b0000000000000000,  

        REG_UxMODE_MOD_SMART_CARD      = 0b0000000000001111, // UART Mode bits
        REG_UxMODE_MOD_IRDA            = 0b0000000000001110,
        REG_UxMODE_MOD_LIN_MSTR_SLV    = 0b0000000000001100,
        REG_UxMODE_MOD_LIN_SLV         = 0b0000000000001011,
        REG_UxMODE_MOD_DMX             = 0b0000000000001010,
        REG_UxMODE_MOD_ASYNC_9B_NONE   = 0b0000000000000100,
        REG_UxMODE_MOD_ASYNC_8B_EVEN   = 0b0000000000000011,
        REG_UxMODE_MOD_ASYNC_8B_ODD    = 0b0000000000000010,
        REG_UxMODE_MOD_ASYNC_8B_NONE   = 0b0000000000000000,
        REG_UxMODE_MOD_ASYNC_7B_NONE   = 0b0000000000000001

    } REG_UxMODEL_FLAGS_e;

    // Single Register Bit Fields
    typedef enum {
        UxMODE_UARTEN_ENABLED      = 0b1, // UART is ready to transmit and receive
        UxMODE_UARTEN_DISABLED     = 0b0  // UART state machine, FIFO Buffer Pointers and counters are reset; registers are readable and writable
    } UxMODE_UARTEN_e; // UART Enable bit
            
    typedef enum {
        UxMODE_USIDL_ACTIVE        = 0b0, // Discontinues module operation when device enters Idle mode
        UxMODE_USIDL_STOP          = 0b1  // Continues module operation in Idle mode
    } UxMODE_USIDL_e; // UART Stop in Idle Mode bit
    
    typedef enum {
        UxMODE_WAKE_ENABLED        = 0b1, // Module will continue to sample the RX pin
        UxMODE_WAKE_DISABLED       = 0b0  // RX pin is not monitored nor rising edge detected
    } UxMODE_WAKE_e; // Wake-up Enable bit
    
    typedef enum {
        UxMODE_RXBIMD_DMX_LIN      = 0b1, // RXBKIF flag when a minimum of 23(DMX)/11 (asynchronous or LIN/J2602) low bit periods are detected
        UxMODE_RXBIMD_DEFAULT      = 0b0  // RXBKIF flag when the Break makes a low-to-high transition after being low for at least 23/11 bit periods
    } UxMODE_RXBIMD_e; // Receive Break Interrupt Mode bit
    
    typedef enum {
        UxMODE_BRKOVR_ON           = 0b1, // Makes the TX line active (Output 0 when UTXINV = 0, Output 1 when UTXINV = 1)
        UxMODE_BRKOVR_OFF          = 0b0  // TX line is driven by the shifter
    } UxMODE_BRKOVR_e; // Send Break Software Override bit
    
    typedef enum {
        UxMODE_UTXBRK_ENABLED      = 0b1, // Sends Sync Break on next transmission; cleared by hardware upon completion (R/HS/HC in DMX and LIN mode)
        UxMODE_UTXBRK_DISABLED     = 0b0  // Sync Break transmission is disabled or has completed
    } UxMODE_UTXBRK_e; // UART Transmit Break bit
    
    typedef enum {
        UxMODE_BRGH_HIGH_SPEED     = 0b1, // High Speed: Baud rate is BAUDCLK/4
        UxMODE_BRGH_DEFAULT        = 0b0  // Low Speed:  Baud rate is BAUDCLK/16
    } UxMODE_BRGH_e; // High Baud Rate Select bit
    
    typedef enum {
        UxMODE_ABAUD_ENABLED       = 0b1, // Enables baud rate measurement on the next character ? requires reception of a Sync field (55h); cleared in hardware upon completion
        UxMODE_ABAUD_DISABLED      = 0b0  // Baud rate measurement is disabled or has completed
    } UxMODE_ABAUD_e; // Auto-Baud Detect Enable bit (read-only when MOD[3:0] = 1xxx)
    
    typedef enum {
        UxMODE_UTXEN_ENABLED       = 0b1, // Transmit enabled ? except during Auto-Baud Detection
        UxMODE_UTXEN_DISABLED      = 0b0  // Transmit disabled ? all transmit counters, pointers and state machines are reset; TX buffer is not flushed, status bits are not reset
    } UxMODE_UTXEN_e; // UART Transmit Enable bit
    
    typedef enum {
        UxMODE_URXEN_ENABLED       = 0b1, // Receive enabled ? except during Auto-Baud Detection
        UxMODE_URXEN_DISABLED      = 0b0  // Receive disabled ? all receive counters, pointers and state machines are reset; RX buffer is not flushed, status bits are not reset 
    } UxMODE_URXEN_e; // UART Transmit Enable bit

    typedef enum {
        UxMODE_MOD_SMART_CARD      = 0b1111, // Smart card mode
        UxMODE_MOD_IRDA            = 0b1110, // IrDA mode
        UxMODE_MOD_LIN_MSTR_SLV    = 0b1100, // LIN Master/Slave mode
        UxMODE_MOD_LIN_SLV         = 0b1011, // LIN Slave only mode
        UxMODE_MOD_DMX             = 0b1010, // DMX mode
        UxMODE_MOD_ASYNC_9B_NONE   = 0b0100, // Asynchronous 9-bit UART with address detect, ninth bit = 1 signals address
        UxMODE_MOD_ASYNC_8B_EVEN   = 0b0011, // Asynchronous 8-bit UART without address detect, ninth bit is used as an even parity bit
        UxMODE_MOD_ASYNC_8B_ODD    = 0b0010, // Asynchronous 8-bit UART without address detect, ninth bit is used as an odd parity bit
        UxMODE_MOD_ASYNC_8B_NONE   = 0b0000, // Asynchronous 7-bit UART mode
        UxMODE_MOD_ASYNC_7B_NONE   = 0b0001  // Asynchronous 8-bit UART mode
    }UxMODE_MOD_e; // UART Mode selection bits

    typedef union {

        struct {

            volatile UxMODE_MOD_e    mod   :4; // Bit #3-0: UART Mode bits
            volatile UxMODE_URXEN_e  urxen :1; // Bit #4: UART Receive Enable bit
            volatile UxMODE_UTXEN_e  utxen :1; // Bit #5: UART Transmit Enable bit
            volatile UxMODE_ABAUD_e  abaud :1; // Bit #6: Auto-Baud Enable bit
            volatile UxMODE_BRGH_e   brgh  :1; // Bit #7: High Baud Rate Enable bit
            volatile UxMODE_UTXBRK_e utxbrk:1; // Bit #8: UART Transmit Break bit
            volatile UxMODE_BRKOVR_e brkovr:1; // Bit #9: Send Break Software Override bit
            volatile unsigned              :1; // Bit #10: reserved
            volatile UxMODE_RXBIMD_e rxbimd:1; // Bit #11: Receive Break Interrupt Mode bit
            volatile UxMODE_WAKE_e   wake  :1; // Bit #12: Wake-up on Start Bit Detect During Sleep Mode Enable bit
            volatile UxMODE_USIDL_e  usidl :1; // Bit #13: UARTx Stop in Idle Mode bit
            volatile unsigned              :1; // Bit #14: reserved
            volatile UxMODE_UARTEN_e uarten:1; // Bit #15: UARTx Enable bit

        }__attribute__((packed)) bits; // UxMODE register bit field
        
        volatile uint16_t value; // UxMODE register full register access
        
    } UxMODEL_t; // UxMODEL: UARTx CONFIGURATION REGISTER LOW

/* ===========================================================================
 * UxMODEH: UARTx CONFIGURATION REGISTER HIGH
 * ===========================================================================*/

    #define UART_UxMODEH_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define UART_UxMODEH_REG_READ_MASK      (uint16_t)0xCFFF
    #define UART_UxMODEH_REG_WRITE_MASK     (uint16_t)0x8FFF

    #define UART_UxMODEH_REG_BCLKSEL_FILTER (uint16_t)0x0600
    
    
    // Full Register Bit Fields
    typedef enum {
        
        REG_UxMODEH_SLPEN_ENABLED       = 0b1000000000000000,   // UART BRG clock runs during Sleep
        REG_UxMODEH_SLPEN_DISABLED      = 0b0000000000000000,

        REG_UxMODEH_ACTIVE_RUN          = 0b0100000000000000,   // UART Running Status bit
        REG_UxMODEH_ACTIVE_STOP         = 0b0000000000000000,

        REG_UxMODEH_BCLKMOD_FRACTIONAL  = 0b0000100000000000,   // Baud Clock Generation Mode Select bit
        REG_UxMODEH_BCLKMOD_DIV_BY_CNT  = 0b0000000000000000,

        REG_UxMODEH_BCLKSEL_AFVCO_DIV3  = 0b0000011000000000,   // Baud Clock Source Selection bits = ACLK/3
        REG_UxMODEH_BCLKSEL_FOSC        = 0b0000010000000000,   // Baud Clock Source Selection bits = FOSC
        REG_UxMODEH_BCLKSEL_FOSC_DIV2   = 0b0000000000000000,   // Baud Clock Source Selection bits = FOSC/2 = Peripheral Clock

        REG_UxMODEH_HALFDPLX_HALF       = 0b0000000100000000,   // UART Half-Duplex Selection Mode bit
        REG_UxMODEH_HALFDPLX_FULL       = 0b0000000000000000,

        REG_UxMODEH_RUNOVF_ENABLED      = 0b0000000010000000,   // Run During Overflow Condition Mode bit
        REG_UxMODEH_RUNOVF_DISABLED     = 0b0000000000000000,  

        REG_UxMODEH_URXINV_ACTIVE_LOW   = 0b0000000001000000, // UART Receive Polarity bit
        REG_UxMODEH_URXINV_ACTIVE_HIGH  = 0b0000000000000000,  

        REG_UxMODEH_STSEL_2_SBIT_1_CHK  = 0b0000000000110000, // Number of Stop Bits Selection bits
        REG_UxMODEH_STSEL_2_SBIT_2_CHK  = 0b0000000000100000,
        REG_UxMODEH_STSEL_15_SBIT_15_CHK = 0b0000000000010000,
        REG_UxMODEH_STSEL_1_SBIT_1_CHK  = 0b0000000000000000,  

        REG_UxMODEH_C0EN_ENABLED        = 0b0000000000001000, // Enable Legacy Checksum (C0) Transmit and Receive bit
        REG_UxMODEH_C0EN_DISABLED       = 0b0000000000000000,  

        REG_UxMODEH_UTXINV_ACTIVE_LOW   = 0b0000000000000100, // UART Transmit Polarity bit
        REG_UxMODEH_UTXINV_ACTIVE_HIGH  = 0b0000000000000000,  

        REG_UxMODEH_FLO_RTS_CTS         = 0b0000000000000010, // Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
        REG_UxMODEH_FLO_XON_XOFF        = 0b0000000000000001,
        REG_UxMODEH_FLO_NONE            = 0b0000000000000000

    } REG_UxMODEH_FLAGS_e;

    // Single Register Bit Fields
    typedef enum {
        UxMODE_SLPEN_ENABLED       = 0b1,  // Run During Sleep Mode
        UxMODE_SLPEN_DISABLED      = 0b0   // Suspend During Sleep Mode
    } UxMODE_SLPEN_e;     // Run During Sleep Enable bit
    
    typedef enum {
        UxMODE_ACTIVE_RUN          = 0b1,  // UART clock request is active (user can not update the UxMODE/UxMODEH registers)
        UxMODE_ACTIVE_STOP         = 0b0   // UART clock request is not active (user can update the UxMODE/UxMODEH registers)
    } UxMODE_ACTIVE_e;     // UART Running Status bit

    typedef enum {
        UxMODE_BCLKMOD_FRACTIONAL  = 0b1,  // Uses fractional Baud Rate Generation
        UxMODE_BCLKMOD_DIV_BY_CNT  = 0b0   // Uses legacy divide-by-x counter for baud clock generation
    } UxMODE_BCLKMOD_e;    // Baud Clock Generation Mode Select bit

    typedef enum {
        UxMODE_BCLKSEL_AFVCO_DIV3  = 0b11, // Baud Clock Source Selection bits = ACLK/3
        UxMODE_BCLKSEL_FOSC        = 0b10, // Baud Clock Source Selection bits = FOSC = CPU Clock
        UxMODE_BCLKSEL_FOSC_DIV2   = 0b00  // Baud Clock Source Selection bits = FOSC/2 = Peripheral Clock
    } UxMODE_BCLKSEL_e;    // Baud Clock Source Selection bits

    typedef enum {
        UxMODE_HALFDPLX_HALF       = 0b1, // Half-Duplex mode: UxTX is driven as an output when transmitting and tri-stated when TX is Idle
        UxMODE_HALFDPLX_FULL       = 0b0  // Full-Duplex mode: UxTX is driven as an output at all times when both UARTEN and UTXEN are set
    } UxMODE_HALFDPLX_e;    // UART Half-Duplex Selection Mode bit

    typedef enum {
        UxMODE_RUNOVF_ENABLED      = 0b1, // When an Overflow Error (OERR) condition is detected, the RX shifter continues to run so as to
                                          // remain synchronized with incoming RX data; data are not transferred to UxRXREG when it is full
                                          // (i.e., no UxRXREG data are overwritten)
        UxMODE_RUNOVF_DISABLED     = 0b0  // When an Overflow Error (OERR) condition is detected, the RX shifter stops accepting new data (Legacy mode) 
    } UxMODE_RUNOVF_e;    // Run During Overflow Condition Mode bit
    
    typedef enum {
        UxMODE_URXINV_ACTIVE_LOW   = 0b1, // Inverts RX polarity; Idle state is low
        UxMODE_URXINV_ACTIVE_HIGH  = 0b0  // Input is not inverted; Idle state is high
    } UxMODE_URXINV_e;    // UART Receive Polarity bit
    
    typedef enum {
        UxMODE_STSEL_2_SBIT_1_CHK  = 0b11, // 2 Stop bits sent, 1 checked at receive
        UxMODE_STSEL_2_SBIT_2_CHK  = 0b10, // 2 Stop bits sent, 2 checked at receive
        UxMODE_STSEL_15_SBIT_15_CHK= 0b01, // 1.5 Stop bits sent, 1.5 checked at receive
        UxMODE_STSEL_1_SBIT_1_CHK  = 0b00  // 1 Stop bit sent, 1 checked at receive
    } UxMODE_STSEL_e;    // Number of Stop Bits Selection bits
    
    typedef enum {
        UxMODE_C0EN_MODE1          = 0b1, // Checksum Mode 1 (enhanced LIN checksum in LIN mode; add all TX/RX words in all other modes)
        UxMODE_C0EN_MODE0          = 0b0  // Checksum Mode 0 (legacy LIN checksum in LIN mode; not used in all other modes)
    } UxMODE_C0EN_e;    // Enable Legacy Checksum (C0) Transmit and Receive bit
    
    typedef enum {
        UxMODE_UTXINV_ACTIVE_LOW   = 0b1, // Inverts TX polarity; TX is low in Idle state
        UxMODE_UTXINV_ACTIVE_HIGH  = 0b0  // Output data are not inverted; TX output is high in Idle state
    } UxMODE_UTXINV_e;    // UART Transmit Polarity bit
    
    typedef enum {
        UxMODE_FLO_RTS_CTS         = 0b10, // RTS-DSR (for TX side)/CTS-DTR (for RX side) hardware flow control
        UxMODE_FLO_XON_XOFF        = 0b01, // XON/XOFF software flow control
        UxMODE_FLO_NONE            = 0b00  // Flow control off
    } UxMODE_FLO_e;    // Flow Control Enable bits (only valid when MOD[3:0] = 0xxx)

    typedef union {
        
        struct {
            
            volatile UxMODE_FLO_e      flo     :2; // Bit #1-0: Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
            volatile UxMODE_UTXINV_e   utxinv  :1; // Bit #2: UART Transmit Polarity bit
            volatile UxMODE_C0EN_e     c0en    :1; // Bit #3: Enable Legacy Checksum (C0) Transmit and Receive bit
            volatile UxMODE_STSEL_e    stsel   :2; // Bit #5-4: Number of Stop Bits Selection bits
            volatile UxMODE_URXINV_e   urxinv  :1; // Bit #6: UART Receive Polarity bit
            volatile UxMODE_RUNOVF_e   runovf  :1; // Bit #7: Run During Overflow Condition Mode bit
            volatile UxMODE_HALFDPLX_e halfdplx:1; // Bit #8: UART Half-Duplex Selection Mode bit
            volatile UxMODE_BCLKSEL_e  bclksel :2; // Bit #10-9: Baud Clock Source Selection bits
            volatile UxMODE_BCLKMOD_e  bclkmod :1; // Bit #11: Baud Clock Generation Mode Select bit
            volatile unsigned                  :1; // Bit #12: reserved
            volatile unsigned                  :1; // Bit #13: reserved
            volatile UxMODE_ACTIVE_e   active  :1; // Bit #14: UART Running Status bit
            volatile UxMODE_SLPEN_e    slpen   :1; // Bit #15: Run During Sleep Enable bit
            
        }__attribute__((packed)) bits; // UxMODEH register bit field
        
        volatile uint16_t value; // UxMODEH register full register access
        
    } UxMODEH_t; // UxMODEH: UARTx CONFIGURATION REGISTER HIGH
    
/* ===========================================================================
 * MERGED UxMODE+UxMODEH: UARTx CONFIGURATION REGISTER HIGH/LOW
 * ===========================================================================*/

    #define UART_UxMODE_REG_DISPOSE_MASK    (uint32_t)0x00000000
    #define UART_UxMODE_VALID_DATA_MASK     (uint32_t)0x8FFFBBFF
    
    typedef union {
        
        struct {

            volatile UxMODE_MOD_e      mod     :4; // Bit #3-0: UART Mode bits
            volatile UxMODE_URXEN_e    urxen   :1; // Bit #4: UART Receive Enable bit
            volatile UxMODE_UTXEN_e    utxen   :1; // Bit #5: UART Transmit Enable bit
            volatile UxMODE_ABAUD_e    abaud   :1; // Bit #6: Auto-Baud Enable bit
            volatile UxMODE_BRGH_e     brgh    :1; // Bit #7: High Baud Rate Enable bit
            volatile UxMODE_UTXBRK_e   utxbrk  :1; // Bit #8: UART Transmit Break bit
            volatile UxMODE_BRKOVR_e   brkovr  :1; // Bit #9: Send Break Software Override bit
            volatile unsigned :1; // Bit #10: reserved
            volatile UxMODE_RXBIMD_e   rxbimd  :1; // Bit #11: Receive Break Interrupt Mode bit
            volatile UxMODE_WAKE_e     wake    :1; // Bit #12: Wake-up on Start Bit Detect During Sleep Mode Enable bit
            volatile UxMODE_USIDL_e    usidl   :1; // Bit #13: UARTx Stop in Idle Mode bit
            volatile unsigned :1; // Bit #14: reserved
            volatile UxMODE_UARTEN_e   uarten  :1; // Bit #15: UARTx Enable bit

            volatile UxMODE_FLO_e      flo     :2; // Bit #1-0: Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
            volatile UxMODE_UTXINV_e   utxinv  :1; // Bit #2: UART Transmit Polarity bit
            volatile UxMODE_C0EN_e     c0en    :1; // Bit #3: Enable Legacy Checksum (C0) Transmit and Receive bit
            volatile UxMODE_STSEL_e    stsel   :2; // Bit #5-4: Number of Stop Bits Selection bits
            volatile UxMODE_URXINV_e   urxinv  :1; // Bit #6: UART Receive Polarity bit
            volatile UxMODE_RUNOVF_e   runovf  :1; // Bit #7: Run During Overflow Condition Mode bit
            volatile UxMODE_HALFDPLX_e halfdplx:1; // Bit #8: UART Half-Duplex Selection Mode bit
            volatile UxMODE_BCLKSEL_e  bclksel :2; // Bit #10-9: Baud Clock Source Selection bits
            volatile UxMODE_BCLKMOD_e  bclkmod :1; // Bit #11: Baud Clock Generation Mode Select bit
            volatile unsigned :1; // Bit #12: reserved
            volatile unsigned :1; // Bit #13: reserved
            volatile UxMODE_ACTIVE_e   active  :1; // Bit #14: UART Running Status bit
            volatile UxMODE_SLPEN_e    slpen   :1; // Bit #15: Run During Sleep Enable bit
            
        }__attribute__((packed)) bits; // UxMODEH/L register bit field
        
        volatile uint32_t value; // UxMODEH/L register full register access
        
    } UxMODE_t; // UxMODE: UARTx CONFIGURATION REGISTER HIGH/LOW
    
/* ===========================================================================
 * UxSTA: UARTx STATUS AND CONTROL REGISTER
 * ===========================================================================*/
    
    #define UART_UxSTAL_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxSTAL_REG_READ_MASK         (uint16_t)0xFFFF
    #define UART_UxSTAL_REG_WRITE_MASK        (uint16_t)0xFF37
    #define UART_UxSTAL_REG_RESET_WRITE_MASK  (uint16_t)0xFFC8

    // Full Register Bit Fields
    typedef enum {
        REG_UxSTAL_TXMTIE_ENABLED      = 0b1000000000000000,   // Transmit Shifter Empty Interrupt Enable bit
        REG_UxSTAL_TXMTIE_DISABLED     = 0b0000000000000000,

        REG_UxSTAL_PERIE_ENABLED       = 0b0100000000000000,   // Parity Error Interrupt Enable bit
        REG_UxSTAL_PERIE_DISABLED      = 0b0000000000000000,
            
        REG_UxSTAL_ABDOVE_ENABLED      = 0b0010000000000000,   // Auto-Baud Rate Acquisition Interrupt Enable bit
        REG_UxSTAL_ABDOVE_DISABLED     = 0b0000000000000000,

        REG_UxSTAL_CERIE_ENABLED       = 0b0001000000000000,   // Checksum Error Interrupt Enable bit
        REG_UxSTAL_CERIE_DISABLED      = 0b0000000000000000,

        REG_UxSTAL_FERIE_ENABLED       = 0b0000100000000000,   // Framing Error Interrupt Enable bit
        REG_UxSTAL_FERIE_DISABLED      = 0b0000000000000000,
            
        REG_UxSTAL_RXBKIE_ENABLED      = 0b0000010000000000,   // Receive Break Interrupt Enable bit
        REG_UxSTAL_RXBKIE_DISABLED     = 0b0000000000000000,
            
        REG_UxSTAL_OERIE_ENABLED       = 0b0000001000000000,   // Receive Buffer Overflow Interrupt Enable bit
        REG_UxSTAL_OERIE_DISABLED      = 0b0000000000000000,
            
        REG_UxSTAL_TXCIE_ENABLED       = 0b0000000100000000,   // Transmit Collision Interrupt Enable bit
        REG_UxSTAL_TXCIE_DISABLED      = 0b0000000000000000,

        REG_UxSTAL_TRMT_EMPTY          = 0b0000000010000000,   // Transmit Shifter Empty Interrupt Flag bit (read-only)
        REG_UxSTAL_TRMT_BUSY           = 0b0000000000000000,

        REG_UxSTAL_PERR_ACTIVE         = 0b0000000001000000,   // Parity Error/Address Received/Forward Frame Interrupt Flag bit
        REG_UxSTAL_PERR_NOT_ACTIVE     = 0b0000000000000000,

        REG_UxSTAL_ABDOVF_ACTIVE       = 0b0000000000100000,   // Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
        REG_UxSTAL_ABDOVF_NOT_ACTIVE   = 0b0000000000000000,

        REG_UxSTAL_CERIF_ACTIVE        = 0b0000000000010000,   // Checksum Error Interrupt Flag bit (must be cleared by software)
        REG_UxSTAL_CERIF_NOT_ACTIVE    = 0b0000000000000000,

        REG_UxSTALFERR_ACTIVE          = 0b0000000000001000,   // Framing Error Interrupt Flag bit
        REG_UxSTALFERR_NOT_ACTIVE      = 0b0000000000000000,
            
        REG_UxSTAL_RXBKIF_ACTIVE       = 0b0000000000000100,   // Receive Break Interrupt Flag bit (must be cleared by software)
        REG_UxSTAL_RXBKIF_NOT_ACTIVE   = 0b0000000000000000,

        REG_UxSTAL_OERR_ACTIVE         = 0b0000000000000010,   // Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
        REG_UxSTAL_OERR_NOT_ACTIVE     = 0b0000000000000000,

        REG_UxSTALTXCIF_ACTIVE         = 0b0000000000000001,   // Transmit Collision Interrupt Flag bit (must be cleared by software)
        REG_UxSTALTXCIF_NOT_ACTIVE     = 0b0000000000000000

    }REG_UxSTAL_FLAGS_e;

    // Single Register Bit Fields
    typedef enum {
        UxSTA_TXMTIE_ENABLED      = 0b1, // Interrupt is enabled
        UxSTA_TXMTIE_DISABLED     = 0b0  // Interrupt is disabled
    } UxSTA_TXMTIE_e; // Transmit Shifter Empty Interrupt Enable bit
    
    typedef enum {
        UxSTA_PERIE_ENABLED       = 0b1, // Interrupt is enabled
        UxSTA_PERIE_DISABLED      = 0b0  // Interrupt is disabled
    } UxSTA_PERIE_e; // Parity Error Interrupt Enable bit
            
    typedef enum {
        UxSTA_ABDOVE_ENABLED      = 0b1, // Interrupt is enabled
        UxSTA_ABDOVE_DISABLED     = 0b0  // Interrupt is disabled
    } UxSTA_ABDOVE_e; // Auto-Baud Rate Acquisition Interrupt Enable bit
    
    typedef enum {
        UxSTA_CERIE_ENABLED       = 0b1, // Interrupt is enabled
        UxSTA_CERIE_DISABLED      = 0b0  // Interrupt is disabled
    } UxSTA_CERIE_e; // Checksum Error Interrupt Enable bit
    
    typedef enum {
        UxSTA_FERIE_ENABLED       = 0b1, // Interrupt is enabled
        UxSTA_FERIE_DISABLED      = 0b0  // Interrupt is disabled
    } UxSTA_FERIE_e; // Framing Error Interrupt Enable bit
    
    typedef enum {
        UxSTA_RXBKIE_ENABLED      = 0b1, // Interrupt is enabled
        UxSTA_RXBKIE_DISABLED     = 0b0  // Interrupt is disabled
    } UxSTA_RXBKIE_e; // Receive Break Interrupt Enable bit
    
    typedef enum {
        UxSTA_OERIE_ENABLED       = 0b1, // Interrupt is enabled
        UxSTA_OERIE_DISABLED      = 0b0  // Interrupt is disabled
    } UxSTA_OERIE_e; // Receive Buffer Overflow Interrupt Enable bit
    
    typedef enum {
        UxSTA_TXCIE_ENABLED       = 0b1, // Interrupt is enabled
        UxSTA_TXCIE_DISABLED      = 0b0  // Interrupt is disabled
    } UxSTA_TXCIE_e; // Transmit Collision Interrupt Enable bit
    
    typedef enum {
        UxSTA_TRMT_EMPTY          = 0b1, // Transmit Shift Register (TSR) is empty (end of last Stop bit when STPMD = 1 or middle of first Stop bit when STPMD = 0)
        UxSTA_TRMT_BUSY           = 0b0  // Transmit Shift Register is not empty
    } UxSTA_TRMT_e; // Transmit Shifter Empty Interrupt Flag bit (read-only)
    
    typedef enum {
        UxSTA_PERR_ACTIVE         = 0b1, // LIN and Parity Modes: Parity error detected
                                         // Address Mode: Address received
                                         // All Other Modes: not used
        UxSTA_PERR_NOT_ACTIVE     = 0b0  // LIN and Parity Modes: No parity error detected
                                         // Address Mode: No address detected
                                         // All Other Modes: not used
    } UxSTA_PERR_e; // Parity Error/Address Received/Forward Frame Interrupt Flag bit
    
    typedef enum {
        UxSTA_ABDOVF_ACTIVE       = 0b1, // BRG rolled over during the auto-baud rate acquisition sequence (must be cleared in software)
        UxSTA_ABDOVF_NOT_ACTIVE   = 0b0  // BRG has not rolled over during the auto-baud rate acquisition sequence
    } UxSTA_ABDOVF_e; // Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
    
    typedef enum {
        UxSTA_CERIF_ACTIVE        = 0b1, // Checksum error
        UxSTA_CERIF_NOT_ACTIVE    = 0b0  // No checksum error
    } UxSTA_CERIF_e; // Checksum Error Interrupt Flag bit (must be cleared by software)
    
    typedef enum {
        UxSTA_FERR_ACTIVE         = 0b1, // Framing Error: Inverted level of the Stop bit corresponding to the topmost character in the buffer;
                                         // propagates through the buffer with the received character
        UxSTA_FERR_NOT_ACTIVE     = 0b0  // No framing error
    } UxSTA_FERR_e; // Framing Error Interrupt Flag bit
    
    typedef enum {
        UxSTA_RXBKIF_ACTIVE       = 0b1, // A Break was received
        UxSTA_RXBKIF_NOT_ACTIVE   = 0b0  // No Break was detected
    } UxSTA_RXBKIF_e; // Receive Break Interrupt Flag bit (must be cleared by software)
    
    typedef enum {
        UxSTA_OERR_ACTIVE         = 0b1, // Receive buffer has overflowed
        UxSTA_OERR_NOT_ACTIVE     = 0b0  // Receive buffer has not overflowed
    } UxSTA_OERR_e; // Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
    
    typedef enum {
        UxSTA_TXCIF_ACTIVE        = 0b1, // Transmitted word is not equal to the received word
        UxSTA_TXCIF_NOT_ACTIVE    = 0b0  // Transmitted word is equal to the received word
    } UxSTA_TXCIF_e; // Transmit Collision Interrupt Flag bit (must be cleared by software)

    
    typedef union {
        
        struct {
            volatile UxSTA_TXCIF_e  txcif :1; // Bit #0: Transmit Collision Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_OERR_e   oerr  :1; // Bit #1: Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_RXBKIF_e rxbkif:1; // Bit #2: Receive Break Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_FERR_e   ferr  :1; // Bit #3: Framing Error Interrupt Flag bit
            volatile UxSTA_CERIF_e  cerif :1; // Bit #4: Checksum Error Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_ABDOVF_e abdovf:1; // Bit #5: Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_PERR_e   perr  :1; // Bit #6: Parity Error/Address Received/Forward Frame Interrupt Flag bit
            volatile UxSTA_TRMT_e   trmt  :1; // Bit #7: Transmit Shift Register Empty bit (read-only)
            volatile UxSTA_TXCIE_e  txcie :1; // Bit #8: Transmit Collision Interrupt Enable bit
            volatile UxSTA_OERIE_e  oerie :1; // Bit #9: Receive Buffer Overflow Interrupt Enable bit
            volatile UxSTA_RXBKIE_e rxbkie:1; // Bit #10: Receive Break Interrupt Enable bit
            volatile UxSTA_FERIE_e  ferie :1; // Bit #11: Framing Error Interrupt Enable bit
            volatile UxSTA_CERIE_e  cerie :1; // Bit #12: Checksum Error Interrupt Enable bit
            volatile UxSTA_ABDOVE_e abdove:1; // Bit #13: Auto-Baud Rate Acquisition Interrupt Enable bit
            volatile UxSTA_PERIE_e  perie :1; // Bit #14: Parity Error Interrupt Enable bit
            volatile UxSTA_TXMTIE_e txmtie:1; // Bit #15: Transmit Shifter Empty Interrupt Enable bit
        }__attribute__((packed)) bits; // UxSTA register bit field
        
        volatile uint16_t value; // UxSTA register full register access
        
    } UxSTAL_t; // UxSTA: UARTx STATUS REGISTER LOW

    
/* ===========================================================================
 * UxSTA: UARTx STATUS AND CONTROL REGISTER
 * ===========================================================================*/
    
    #define UART_UxSTAH_REG_DISPOSE_MASK     (uint16_t)0x883F
    #define UART_UxSTAH_REG_READ_MASK        (uint16_t)0x77FF
    #define UART_UxSTAH_REG_WRITE_MASK       (uint16_t)0x77C0
    #define UART_UxSTAH_REG_RESET_WRITE_MASK (uint16_t)0x883F
    
    // Full Register Bit Fields
    typedef enum
    {
        REG_UxSTAH_UTXISEL_1_OPEN       = 0b0111000000000000,   // UART Transmit Interrupt Select bits
        REG_UxSTAH_UTXISEL_2_OPEN       = 0b0110000000000000,
        REG_UxSTAH_UTXISEL_3_OPEN       = 0b0101000000000000,
        REG_UxSTAH_UTXISEL_4_OPEN       = 0b0100000000000000,
        REG_UxSTAH_UTXISEL_5_OPEN       = 0b0011000000000000,
        REG_UxSTAH_UTXISEL_6_OPEN       = 0b0010000000000000,
        REG_UxSTAH_UTXISEL_7_OPEN       = 0b0001000000000000,
        REG_UxSTAH_UTXISEL_8_OPEN       = 0b0000000000000000,

        REG_UxSTAH_URXISEL_1_WORD       = 0b0000011100000000,   // UART Receive Interrupt Select bits
        REG_UxSTAH_URXISEL_2_WORD       = 0b0000011000000000,
        REG_UxSTAH_URXISEL_3_WORD       = 0b0000010100000000,
        REG_UxSTAH_URXISEL_4_WORD       = 0b0000010000000000,
        REG_UxSTAH_URXISEL_5_WORD       = 0b0000001100000000,
        REG_UxSTAH_URXISEL_6_WORD       = 0b0000001000000000,
        REG_UxSTAH_URXISEL_7_WORD       = 0b0000000100000000,
        REG_UxSTAH_URXISEL_8_WORD       = 0b0000000000000000,

        REG_UxSTAH_TXWRE_OVERRUN        = 0b0000000010000000,  // TX Write Transmit Error Status bit
        REG_UxSTAH_TXWRE_NONE           = 0b0000000000000000,
            
        REG_UxSTAH_STPMD_IF_LAST_STOP   = 0b0000000001000000,  // Stop Bit Detection Mode bit
        REG_UxSTAH_STPMD_IF_FIRST_STOP  = 0b0000000000000000,

        REG_UxSTAH_UTXBE_EMPFY          = 0b0000000000100000,  // UART TX Buffer Empty Status bit
        REG_UxSTAH_UTXBE_FULL           = 0b0000000000000000,

        REG_UxSTAH_UTXBF_FULL           = 0b0000000000010000,  // UART TX Buffer Full Status bit
        REG_UxSTAH_UTXBF_EMPFY          = 0b0000000000000000,

        REG_UxSTAH_RIDLE_IDLE           = 0b0000000000001000,  // Receive Idle bit
        REG_UxSTAH_RIDLE_BUSY           = 0b0000000000000000,
            
        REG_UxSTAH_XON_ACTIVE           = 0b0000000000000100,  // UART in XON Mode bit
        REG_UxSTAH_XON_NONE             = 0b0000000000000000,

        REG_UxSTAH_URXBE_EMPTY          = 0b0000000000000010,  // UART RX Buffer Empty Status bit
        REG_UxSTAH_URXBE_FULL           = 0b0000000000000000,
            
        REG_UxSTAH_URXBF_FULL           = 0b0000000000000001,  // UART RX Buffer Full Status bit
        REG_UxSTAH_URXBF_EMPTY          = 0b0000000000000000

    }REG_UxSTAH_FLAGS_e;

    // Single Register Bit Fields
    typedef enum {
        UxSTA_UTXISEL_1_OPEN       = 0b111, // Sets transmit interrupt when there is  one empty slot left in the buffer
        UxSTA_UTXISEL_2_OPEN       = 0b110, // Sets transmit interrupt when there are two empty slot left in the buffer
        UxSTA_UTXISEL_3_OPEN       = 0b101, // Sets transmit interrupt when there are three empty slot left in the buffer
        UxSTA_UTXISEL_4_OPEN       = 0b100, // Sets transmit interrupt when there are four empty slot left in the buffer
        UxSTA_UTXISEL_5_OPEN       = 0b011, // Sets transmit interrupt when there are five empty slot left in the buffer
        UxSTA_UTXISEL_6_OPEN       = 0b010, // Sets transmit interrupt when there are six empty slot left in the buffer
        UxSTA_UTXISEL_7_OPEN       = 0b001, // Sets transmit interrupt when there are seven empty slot left in the buffer
        UxSTA_UTXISEL_8_OPEN       = 0b000  // Sets transmit interrupt when there are eight empty slot left in the buffer
    } UxSTA_UTXISEL_e; // UART Transmit Interrupt Select bits
    
    typedef enum {
        UxSTA_URXISEL_1_WORD       = 0b000, // Triggers receive interrupt when there is one word or more in the buffer
        UxSTA_URXISEL_2_WORD       = 0b001, // Triggers receive interrupt when there are two words or more in the buffer
        UxSTA_URXISEL_3_WORD       = 0b010, // Triggers receive interrupt when there are three words or more in the buffer
        UxSTA_URXISEL_4_WORD       = 0b011, // Triggers receive interrupt when there are four words or more in the buffer
        UxSTA_URXISEL_5_WORD       = 0b100, // Triggers receive interrupt when there are five words or more in the buffer
        UxSTA_URXISEL_6_WORD       = 0b101, // Triggers receive interrupt when there are six words or more in the buffer
        UxSTA_URXISEL_7_WORD       = 0b110, // Triggers receive interrupt when there are seven words or more in the buffer
        UxSTA_URXISEL_8_WORD       = 0b111  // Triggers receive interrupt when there are eight words in the buffer; RX buffer is full
    } UxSTA_URXISEL_e; // UART Receive Interrupt Select bits
                       // Note: The receive watermark interrupt is not set if PERR or FERR is set and the corresponding IE bit is set.
    
    typedef enum {
        UxSTA_TXWRE_OVERRUN        = 0b1, // LIN and Parity Modes: A new byte was written when the buffer was full or when P2[8:0] = 0 (must be cleared by software)
                                          // Address Detect Mode: A new byte was written when the buffer was full or to P1[8:0] when P1x was full (must be cleared by software)
                                          // Other Modes: A new byte was written when the buffer was full (must be cleared by software)
        UxSTA_TXWRE_NONE           = 0b0  // All Modes: No error
    } UxSTA_TXWRE_e; // TX Write Transmit Error Status bit
    
    typedef enum {
        UxSTA_STPMD_IF_LAST_STOP   = 0b1, // Triggers RXIF at the end of the last Stop bit
        UxSTA_STPMD_IF_FIRST_STOP  = 0b0  // Triggers RXIF in the middle of the first (or second, depending on the STSEL[1:0] setting) Stop bit
    } UxSTA_STPMD_e; // Stop Bit Detection Mode bit
    
    typedef enum {
        UxSTA_UTXBE_EMPFY          = 0b1, // Transmit buffer is empty; writing ?1? when UTXEN = 0 will reset the TX FIFO Pointers and counters
        UxSTA_UTXBE_FULL           = 0b0  // Transmit buffer is not empty
    } UxSTA_UTXBE_e; // UART TX Buffer Empty Status bit
    
    typedef enum {
        UxSTA_UTXBF_FULL           = 0b1, // Transmit buffer is full
        UxSTA_UTXBF_EMPFY          = 0b0  // Transmit buffer is not full
    } UxSTA_UTXBF_e; // UART TX Buffer Full Status bit
    
    typedef enum {
        UxSTA_RIDLE_IDLE           = 0b1, // UART RX line is in the Idle state
        UxSTA_RIDLE_BUSY           = 0b0  // UART RX line is receiving something
    } UxSTA_RIDLE_e; // Receive Idle bit
    
    typedef enum {
        UxSTA_XON_ACTIVE           = 0b1, // UART has received XON
        UxSTA_XON_NONE             = 0b0  // UART has not received XON or XOFF was received
    } UxSTA_XON_e; // UART in XON Mode bit
                   // Note: Only valid when FLO[1:0] control bits are set to XON/XOFF mode.
    
    typedef enum {
        UxSTA_URXBE_EMPTY          = 0b1, // Receive buffer is empty; writing ?1? when URXEN = 0 will reset the RX FIFO Pointers and counters
        UxSTA_URXBE_FULL           = 0b0  // Receive buffer is not empty
    } UxSTA_URXBE_e; // UART RX Buffer Empty Status bit
    
    typedef enum {
        UxSTA_URXBF_FULL           = 0b1, // Receive buffer is full
        UxSTA_URXBF_EMPTY          = 0b0  // Receive buffer is not full
    } UxSTA_URXBF_e; // UART RX Buffer Full Status bit
    
    typedef union {

        struct {
            volatile UxSTA_URXBF_e   urxbf   :1; // Bit #0: UART RX Buffer Full Status bit
            volatile UxSTA_URXBE_e   urxbe   :1; // Bit #1: UART RX Buffer Empty Status bit
            volatile UxSTA_XON_e     xon     :1; // Bit #2: UART in XON Mode bit
            volatile UxSTA_RIDLE_e   ridle   :1; // Bit #3: Receive Idle bit
            volatile UxSTA_UTXBF_e   utxbf   :1; // Bit #4: UART TX Buffer Full Status bit
            volatile UxSTA_UTXBE_e   utxbe   :1; // Bit #5: UART TX Buffer Empty Status bit
            volatile UxSTA_STPMD_e   stpmd   :1; // Bit #6: Stop Bit Detection Mode bit
            volatile UxSTA_TXWRE_e   txwre   :1; // Bit #7: TX Write Transmit Error Status bit
            volatile UxSTA_URXISEL_e urxisel :3; // Bit #10-8: UART Receive Interrupt Select bits
            volatile unsigned :1; // Bit #11: reserved
            volatile UxSTA_UTXISEL_e utxisel :3; // Bit #14-12: UART Transmit Interrupt Select bits
            volatile unsigned :1; // Bit #15: reserved
        }__attribute__((packed)) bits; // UxSTAH register bit field
        
        volatile uint16_t value; // UxSTAH register full register access

    } UxSTATH_t;

/* ===========================================================================
 * MERGED UxSTA+UxSTAH: UARTx STATUS REGISTER HIGH/LOW
 * ===========================================================================*/

    #define UART_UxSTA_VALID_DATA_MASK  (uint32_t)0x77C0FF00 // Data validation bit mask in UxSTA and UxSTAH
    #define UART_UxSTA_VALID_READ_MASK  (uint32_t)0x77FFFFFF // Valid data bits in UxSTA and UxSTAH
    #define UART_UxSTA_REG_DISPOSE_MASK (uint32_t)0x00000000 // Clearing UxSTA and UxSTAH registers
    #define UART_UxSTA_MESSAGE_RECEIVED (uint32_t)0x00010000 // URXBF: UART RX Buffer Full Status bit
    #define UART_UxSTA_MESSAGE_READ     (uint32_t)0x00020000 // URXBE: UART RX Buffer Empty Status bit
    #define UART_UxSTA_TX_BUFFER_EMPTY  (uint32_t)0x00200000 // UTXBE: UART TX Buffer Empty Status bit
    #define UART_UxSTA_TX_BUFFER_FULL   (uint32_t)0x00100000 // UTXBF: UART TX Buffer Full Status bit
    #define UART_UxSTA_ISR_FLAGS_MASK   (uint32_t)0x0000003F

    typedef union {
        
        struct {
            volatile UxSTA_TXCIF_e   txcif   :1; // Bit #0: Transmit Collision Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_OERR_e    oerr    :1; // Bit #1: Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_RXBKIF_e  rxbkif  :1; // Bit #2: Receive Break Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_FERR_e    ferr    :1; // Bit #3: Framing Error Interrupt Flag bit
            volatile UxSTA_CERIF_e   cerif   :1; // Bit #4: Checksum Error Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_ABDOVF_e  abdovf  :1; // Bit #5: Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
            volatile UxSTA_PERR_e    perr    :1; // Bit #6: Parity Error/Address Received/Forward Frame Interrupt Flag bit
            volatile UxSTA_TRMT_e    trmt    :1; // Bit #7: Transmit Shift Register Empty bit (read-only)
            volatile UxSTA_TXCIE_e   txcie   :1; // Bit #8: Transmit Collision Interrupt Enable bit
            volatile UxSTA_OERIE_e   oerie   :1; // Bit #9: Receive Buffer Overflow Interrupt Enable bit
            volatile UxSTA_RXBKIE_e  rxbkie  :1; // Bit #10: Receive Break Interrupt Enable bit
            volatile UxSTA_FERIE_e   ferie   :1; // Bit #11: Framing Error Interrupt Enable bit
            volatile UxSTA_CERIE_e   cerie   :1; // Bit #12: Checksum Error Interrupt Enable bit
            volatile UxSTA_ABDOVE_e  abdove  :1; // Bit #13: Auto-Baud Rate Acquisition Interrupt Enable bit
            volatile UxSTA_PERIE_e   perie   :1; // Bit #14: Parity Error Interrupt Enable bit
            volatile UxSTA_TXMTIE_e  txmtie  :1; // Bit #15: Transmit Shifter Empty Interrupt Enable bit
            
            volatile UxSTA_URXBF_e   urxbf   :1; // Bit #0: UART RX Buffer Full Status bit
            volatile UxSTA_URXBE_e   urxbe   :1; // Bit #1: UART RX Buffer Empty Status bit
            volatile UxSTA_XON_e     xon     :1; // Bit #2: UART in XON Mode bit
            volatile UxSTA_RIDLE_e   ridle   :1; // Bit #3: Receive Idle bit
            volatile UxSTA_UTXBF_e   utxbf   :1; // Bit #4: UART TX Buffer Full Status bit
            volatile UxSTA_UTXBE_e   utxbe   :1; // Bit #5: UART TX Buffer Empty Status bit
            volatile UxSTA_STPMD_e   stpmd   :1; // Bit #6: Stop Bit Detection Mode bit
            volatile UxSTA_TXWRE_e   txwre   :1; // Bit #7: TX Write Transmit Error Status bit
            volatile UxSTA_URXISEL_e urxisel :3; // Bit #10-8: UART Receive Interrupt Select bits
            volatile unsigned :1; // Bit #11: reserved
            volatile UxSTA_UTXISEL_e utxisel :3; // Bit #14-12: UART Transmit Interrupt Select bits
            volatile unsigned :1; // Bit #15: reserved
        }__attribute__((packed)) bits; // UxSTAH/L register bit field
        
        volatile uint32_t value; // UxSTAH/L register full register access
        
    } UxSTA_t; // UxSTA: UARTx STATUS REGISTER HIGH/LOW
    
    
/* ===========================================================================
 * UxBRG: UARTx BAUD RATE REGISTER
 * ===========================================================================*/

    #define UART_UxBRGL_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxBRGL_REG_WRITE_MASK        (uint16_t)0xFFFF
    #define UART_UxBRGL_REG_READ_MASK         (uint16_t)0xFFFF

    #define UART_UxBRGH_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxBRGH_REG_WRITE_MASK        (uint16_t)0x000F
    #define UART_UxBRGH_REG_READ_MASK         (uint16_t)0x000F

    #define UART_UxBRG_VALID_DATA_MASK        (uint32_t)0x000FFFFF
    #define UART_UxBRG_REG_DISPOSE_MASK       (uint32_t)0x00000000
    #define UART_UxBRG_REG_WRITE_MASK         (uint32_t)0x000FFFFF
    #define UART_UxBRG_REG_READ_MASK          (uint32_t)0x000FFFFF

    typedef union {
        
        struct {
            volatile uint16_t brgl :16; // Baud Rate LOW  Divisor bits
            volatile uint16_t brgh :16; // Baud Rate HIGH Divisor bits
        }__attribute__((packed)) bits; // UxBRG register bit field
        
        volatile uint32_t value; // UxBRG register full register access
        
    } UxBRG_t; // UxBRG: UARTx BAUD RATE REGISTER
    
/* ===========================================================================
 * UxRXREG: UARTx RECEIVE BUFFER REGISTER
 * ===========================================================================*/

    #define UART_UxRXREG_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxRXREG_REG_WRITE_MASK        (uint16_t)0x00FF
    #define UART_UxRXREG_REG_READ_MASK         (uint16_t)0x00FF

    typedef union {
        
        struct {
            volatile uint8_t txreg :8; // Bit #7-0: Transmitted Character Data bits 7-0
            volatile unsigned      :8; // Bit #15-8: unimplemented
        }__attribute__((packed)) bits; // UxRXREG register bit field
        
        volatile uint16_t value; // UxRXREG register full register access
        
    } UxRXREG_t; // UxRXREG: UARTx RECEIVE BUFFER REGISTER
    
    
/* ===========================================================================
 * UxTXREG: UARTx TRANSMIT BUFFER REGISTER
 * ===========================================================================*/

    #define UART_UxTXREG_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxTXREG_REG_WRITE_MASK        (uint16_t)0x80FF
    #define UART_UxTXREG_REG_READ_MASK         (uint16_t)0x80FF

    // Full Register Bit Fields
    typedef enum {
        REG_UxTXREG_LAST_IS_LAST_BYTE     = 0b1000000000000000,  // Last Byte Indicator for Smart Card Support bit
        REG_UxTXREG_LAST_IS_NOT_LAST_BYTE = 0b0000000000000000   // Last Byte Indicator for Smart Card Support bit
    } REG_UxTXREG_FLAGS_e; 
    
    typedef union {
        
        struct {
            volatile uint8_t txreg :8; // Bit #7-0: Transmitted Character Data bits 7-0
            volatile unsigned      :7; // Bit #14-8: unimplemented
            volatile bool last     :1; // Bit #15: Last Byte Indicator for Smart Card Support bit
        }__attribute__((packed)) bits; // UxTXREG register bit field
        
        volatile uint16_t value; // UxTXREG register full register access
        
    } UxTXREG_t; // UxTXREG: UARTx TRANSMIT BUFFER REGISTER
    
/* ===========================================================================
 * UxP1: UARTx TIMING PARAMETER 1 REGISTER    
 * ===========================================================================*/

    #define UART_UxP1_VALID_DATA_MASK       (uint16_t)0x01FF
    #define UART_UxP1_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxP1_REG_WRITE_MASK        (uint16_t)0x01FF
    #define UART_UxP1_REG_READ_MASK         (uint16_t)0x01FF

    typedef union {
        
        struct {
            volatile uint16_t p1 :9; // Bit #8-0: Parameter 1 bits
                                     // DMX TX:
                                     //     Number of Bytes to Transmit ? 1 (not including Start code).
                                     // LIN Master TX:
                                     //     PID to transmit (bits<5:0>).
                                     // Asynchronous TX with Address Detect:
                                     //     Address to transmit. A ?1? is automatically inserted into bit 9 (bits<7:0>).
                                     // Smart Card Mode:
                                     //     Guard Time Counter bits. This counter is operated on the bit clock whose period is always equal to one
                                     //     ETU (bits<8:0>).
                                     // Other Modes:
                                     //     Not used.    
            volatile unsigned :7;    // Bit #15-9: unimplemented
        }__attribute__((packed)) bits; // UxP1 register bit field
        
        volatile uint16_t value; // UxP1 register full register access
        
    } UxP1_t; // UxP1: UARTx TIMING PARAMETER 1 REGISTER
    
    
/* ===========================================================================
 * UxP2: UARTx TIMING PARAMETER 2 REGISTER    
 * ===========================================================================*/

    #define UART_UxP2_VALID_DATA_MASK       (uint16_t)0x01FF
    
    #define UART_UxP2_REG_DISPOSE_MASK      (uint16_t)0x0000
    #define UART_UxP2_REG_WRITE_MASK        (uint16_t)0x01FF
    #define UART_UxP2_REG_READ_MASK         (uint16_t)0x01FF

    typedef union {
        
        struct {
            volatile uint16_t p2 :9; // Bit #8-0: Parameter 2 bits
                                     // DMX RX:
                                     //     The first byte number to receive ? 1, not including Start code (bits<8:0>).
                                     // LIN Slave TX:
                                     //     Number of bytes to transmit (bits<7:0>).
                                     //     Asynchronous RX with Address Detect:
                                     //     Address to start matching (bits<7:0>).
                                     // Smart Card Mode:
                                     //     Block Time Counter bits. This counter is operated on the bit clock whose period is always equal to
                                     //     one ETU (bits<8:0>).
                                     // Other Modes:
                                     //     Not used.
            volatile unsigned :7;    // Bit #15-9: unimplemented
            
        }__attribute__((packed)) bits; // UxP2 register bit field
        
        volatile uint16_t value; // UxP2 register full register access
        
    } UxP2_t; // UxP2: UARTx TIMING PARAMETER 2 REGISTER


/* ===========================================================================
 * UxP3: UARTx TIMING PARAMETER 3 REGISTER    
 * ===========================================================================*/

    #define UART_UxP3L_VALID_DATA_MASK      (uint16_t)0xFFFF
    #define UART_UxP3L_REG_DISPOSE_MASK     (uint16_t)0x0000
    #define UART_UxP3L_REG_WRITE_MASK       (uint16_t)0xFFFF
    #define UART_UxP3L_REG_READ_MASK        (uint16_t)0xFFFF

    #define UART_UxP3H_VALID_DATA_MASK      (uint16_t)0x00FF
    #define UART_UxP3H_REG_DISPOSE_MASK     (uint16_t)0x0000
    #define UART_UxP3H_REG_WRITE_MASK       (uint16_t)0x00FF
    #define UART_UxP3H_REG_READ_MASK        (uint16_t)0x00FF

    #define UART_UxP3_VALID_DATA_MASK       (uint32_t)0x00FFFFFF
    #define UART_UxP3_REG_DISPOSE_MASK      (uint32_t)0x00000000
    #define UART_UxP3_REG_WRITE_MASK        (uint32_t)0x00FFFFFF
    #define UART_UxP3_REG_READ_MASK         (uint32_t)0x00FFFFFF

    typedef union {
        
        struct {
            volatile uint16_t p3l :16; // Bit #15-0: Parameter 3 bits
                                       // DMX RX:
                                       //     The first byte number to receive ? 1, not including Start code (bits<8:0>).
                                       // LIN Slave TX:
                                       //     Number of bytes to transmit (bits<7:0>).
                                       //     Asynchronous RX with Address Detect:
                                       //     Address to start matching (bits<7:0>).
                                       // Smart Card Mode:
                                       //     Block Time Counter bits. This counter is operated on the bit clock whose period is always equal to
                                       //     one ETU (bits<8:0>).
                                       // Other Modes:
                                       //     Not used.
            volatile uint8_t p3h :8 ;  // Bit #23-16: Parameter 3 bits
                                       // Smart Card Mode:
                                       //     Waiting Time Counter bits (bits<23:16>).
                                       // Other Modes:
                                       //     Not used.
            volatile unsigned :8;      // Bit #31-24: unimplemented
        }__attribute__((packed)) bits; // UxP3 register bit field
        
        volatile uint32_t value; // UxP3 register full register access
        
    } UxP3_t; // UxP3: UARTx TIMING PARAMETER 3 REGISTER

/* ===========================================================================
 * UxTXCHK: UARTx TRANSMIT CHECKSUM REGISTER
 * ===========================================================================*/
    
    #define UART_UxTXCHK_VALID_DATA_MASK    (uint16_t)0x00FF
    #define UART_UxTXCHK_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define UART_UxTXCHK_REG_WRITE_MASK     (uint16_t)0x00FF
    #define UART_UxTXCHK_REG_READ_MASK      (uint16_t)0x00FF

    typedef union {
        
        struct {
            volatile uint8_t txchk :8; // Bit #7-0: Transmit Checksum bits (calculated from TX words)
                                       // LIN Modes:
                                       //     C0EN = 1: Sum of all transmitted data + addition carries, including PID.
                                       //     C0EN = 0: Sum of all transmitted data + addition carries, excluding PID.
                                       // LIN Slave:
                                       //     Cleared when Break is detected.
                                       // LIN Master/Slave:
                                       //     Cleared when Break is detected.
                                       // Other Modes:
                                       //     C0EN = 1: Sum of every byte transmitted + addition carries.
                                       //     C0EN = 0: Value remains unchanged
            volatile unsigned :8;      // Bit #15-8: unimplemented
        }__attribute__((packed)) bits; // UxTXCHK register bit field
        
        volatile uint16_t value; // UxTXCHK register full register access
        
    } UxTXCHK_t; // UxTXCHK: UARTx TRANSMIT CHECKSUM REGISTER
    
/* ===========================================================================
 * UxRXCHK: UARTx RECEIVE CHECKSUM REGISTER
 * ===========================================================================*/

    #define UART_UxRXCHK_VALID_DATA_MASK    (uint16_t)0x00FF
    #define UART_UxRXCHK_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define UART_UxRXCHK_REG_WRITE_MASK     (uint16_t)0x00FF
    #define UART_UxRXCHK_REG_READ_MASK      (uint16_t)0x00FF

    typedef union {
        
        struct {
            volatile uint8_t rxchk :8; // Bit #7-0: Receive Checksum bits (calculated from RX words)
                                       // LIN Modes:
                                       //     C0EN = 1: Sum of all received data + addition carries, including PID.
                                       //     C0EN = 0: Sum of all received data + addition carries, excluding PID.
                                       // LIN Slave:
                                       //     Cleared when Break is detected.
                                       // LIN Master/Slave:
                                       //     Cleared when Break is detected.
                                       // Other Modes:
                                       //     C0EN = 1: Sum of every byte received + addition carries.
                                       //     C0EN = 0: Value remains unchanged.
            volatile unsigned :8;      // Bit #15-8: unimplemented
        }__attribute__((packed)) bits; // UxRXCHK register bit field
        
        volatile uint16_t value; // UxRXCHK register full register access
        
    } UxRXCHK_t; // UxRXCHK: UARTx RECEIVE CHECKSUM REGISTER
     
/* ===========================================================================
 * UxSCCON: UARTx SMART CARD CONFIGURATION REGISTER
 * ===========================================================================*/

    #define UART_UxSCCON_VALID_DATA_MASK    (uint16_t)0x003E
    #define UART_UxSCCON_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define UART_UxSCCON_REG_WRITE_MASK     (uint16_t)0x003E
    #define UART_UxSCCON_REG_READ_MASK      (uint16_t)0x003E

    // Full Register Bit Fields
    typedef enum {
        
        REG_UxSCCON_T0PD_V1         = 0b0000000000000010, // T = 1
        REG_UxSCCON_T0PD_V0         = 0b0000000000000000, // T = 0

        REG_UxSCCON_PRTCL_2_ETU     = 0b0000000000000100, // Two ETU
        REG_UxSCCON_PRTCL_1_ETU     = 0b0000000000000000, // One ETU

        REG_UxSCCON_CONV_2_INVERSE  = 0b0000000000001000, // Inverse logic convention
        REG_UxSCCON_CONV_1_DIRECT   = 0b0000000000000000, // Direct logic convention

        REG_UxSCCON_TXRPT_4_REPEATS = 0b0000000000110000, // Retransmit the error byte four times
        REG_UxSCCON_TXRPT_3_REPEATS = 0b0000000000100000, // Retransmit the error byte three times
        REG_UxSCCON_TXRPT_2_REPEATS = 0b0000000000010000, // Retransmit the error byte twice
        REG_UxSCCON_TXRPT_1_REPEATS = 0b0000000000000000  // Retransmit the error byte once
            
    } REG_UART_UxSCCON_FLAGS_e;
    
    // Single bit fields
    typedef enum {
        UxSCCON_T0PD_V1 = 0b1, // T = 1
        UxSCCON_T0PD_V0 = 0b0  // T = 0
    }UxSCCON_PRTCL_e;  // Smart Card Protocol Selection bit

    typedef enum {
        UxSCCON_PRTCL_2_ETU = 0b1, // Two ETU
        UxSCCON_PRTCL_1_ETU = 0b0  // One ETU
    }UxSCCON_T0PD_e; // Pull-Down Duration for T = 0 Error Handling bit

    typedef enum {
        UxSCCON_CONV_2_INVERSE = 0b1, // Inverse logic convention
        UxSCCON_CONV_1_DIRECT  = 0b0  // Direct logic convention
    }UxSCCON_CONV_e;  // Logic Convention Selection bit
    
    typedef enum {
        UxSCCON_TXRPT_4_REPEATS = 0b11, // Retransmit the error byte four times
        UxSCCON_TXRPT_3_REPEATS = 0b10, // Retransmit the error byte three times
        UxSCCON_TXRPT_2_REPEATS = 0b01, // Retransmit the error byte twice
        UxSCCON_TXRPT_1_REPEATS = 0b00  // Retransmit the error byte once
    } UxSCCON_TXRPT_e;  // Transmit Repeat Selection bits
    
    typedef union {
        
        struct {
            volatile unsigned              : 1; // Bit #0: unimplemented
            volatile UxSCCON_PRTCL_e prtcl : 1; // Bit #1: Smart Card Protocol Selection bit
            volatile UxSCCON_T0PD_e  t0pd  : 1; // Bit #2: Pull-Down Duration for T = 0 Error Handling bit
            volatile UxSCCON_CONV_e  conv  : 1; // Bit #3: Logic Convention Selection bit
            volatile UxSCCON_TXRPT_e txrpt : 2; // Bit #5-4: Transmit Repeat Selection bits
            volatile unsigned              :10; // Bit #15-6: unimplemented
        } __attribute__((packed)) bits; // UxSCCON register bit field
        
        volatile uint16_t value; // UxSCCON register full register access
        
    } UxSCCON_t; // UxSCCON: UARTx SMART CARD CONFIGURATION REGISTER
            
/* ===========================================================================
 * UxSCINT: UARTx SMART CARD INTERRUPT REGISTER
 * ===========================================================================*/

    #define UART_UxSCINT_VALID_DATA_MASK    (uint16_t)0x3737
    #define UART_UxSCINT_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define UART_UxSCINT_REG_WRITE_MASK     (uint16_t)0x3737
    #define UART_UxSCINT_REG_READ_MASK      (uint16_t)0x3737
    
    // Full Register Bit Fields
    typedef enum {
        
        REG_UxSCINT_GTCIE_ENABLED   = 0b0000000000000001, // Guard Time Counter interrupt is enabled
        REG_UxSCINT_GTCIE_DISABLED  = 0b0000000000000000, // Guard Time Counter interrupt is disabled

        REG_UxSCINT_WTCIE_ENABLED   = 0b0000000000000010, // Waiting Time Counter interrupt is enabled
        REG_UxSCINT_WTCIE_DISABLED  = 0b0000000000000000, // Waiting Time Counter Interrupt is disabled

        REG_UxSCINT_BTCIE_ENABLED   = 0b0000000000000100, // Block Time Counter interrupt is enabled
        REG_UxSCINT_BTCIE_DISABLED  = 0b0000000000000000, // Block Time Counter interrupt is disabled
            
        REG_UxSCINT_TXRPTIE_ENABLED = 0b0000000000010000, // An interrupt is invoked when a line error is detected after the last retransmit per TXRPT<1:0> has been completed
        REG_UxSCINT_TXRPTIE_DISABLED= 0b0000000000000000, // Interrupt is disabled
            
        REG_UxSCINT_RXRPTIE_ENABLED = 0b0000000000100000, // An interrupt is invoked when a parity error has persisted after the same character has been received five times (four retransmits)
        REG_UxSCINT_RXRPTIE_DISABLED= 0b0000000000000000, // Interrupt is disabled

        REG_UxSCINT_GTCIF_ENABLED   = 0b0000000100000000, // Guard Time Counter has reached 0
        REG_UxSCINT_GTCIF_DISABLED  = 0b0000000000000000, // Guard Time Counter has not reached 0

        REG_UxSCINT_WTCIF_ENABLED   = 0b0000001000000000, // Waiting Time Counter has reached 0
        REG_UxSCINT_WTCIF_DISABLED  = 0b0000000000000000, // Waiting Time Counter has not reached 0
            
        REG_UxSCINT_BTCIF_ENABLED   = 0b0000010000000000, // Block Time Counter has reached 0
        REG_UxSCINT_BTCIF_DISABLED  = 0b0000000000000000, // Block Time Counter has not reached 0

        REG_UxSCINT_TXRPTIF_ENABLED = 0b0001000000000000, // Line error has been detected after the last retransmit per TXRPT<1:0>
        REG_UxSCINT_TXRPTIF_DISABLED= 0b0000000000000000, // Flag is cleared
            
        REG_UxSCINT_RXRPTIF_ENABLED = 0b0010000000000000, // Parity error has persisted after the same character has been received five times (four retransmits)
        REG_UxSCINT_RXRPTIF_DISABLED= 0b0000000000000000  // Flag is cleared

    } REG_UxSCINT_FLAGS_e; // UxSCINT: UARTx SMART CARD INTERRUPT REGISTER
    
    // Single Bit Fields
    typedef enum {
        UxSCINT_GTCIE_ENABLED   = 0b1, // Guard Time Counter interrupt is enabled
        UxSCINT_GTCIE_DISABLED  = 0b0  // Guard Time Counter interrupt is disabled
    } UxSCINT_GTCIE_e; // Guard Time Counter interrupt enable bit
    
    typedef enum {
        UxSCINT_WTCIE_ENABLED   = 0b1, // Waiting Time Counter interrupt is enabled
        UxSCINT_WTCIE_DISABLED  = 0b0  // Waiting Time Counter interrupt is disabled
    } UxSCINT_WTCIE_e; // Waiting Time Counter interrupt enable bit

    typedef enum {
        UxSCINT_BTCIE_ENABLED   = 0b1, // Block Time Counter interrupt is enabled
        UxSCINT_BTCIE_DISABLED  = 0b0  // Block Time Counter interrupt is disabled
    } UxSCINT_BTCIE_e; // Block Time Counter interrupt enable bit

    typedef enum {
        UxSCINT_TXRPTIE_ENABLED   = 0b1, // An interrupt is invoked when a line error is detected after the last retransmit per TXRPT<1:0> has been completed
        UxSCINT_TXRPTIE_DISABLED  = 0b0  // Interrupt is disabled
    } UxSCINT_TXRPTIE_e; // Transmit Repeat Interrupt Enable bit

    typedef enum {
        UxSCINT_RXRPTIE_ENABLED   = 0b1, // An interrupt is invoked when a parity error has persisted after the same character has been received five times (four retransmits)
        UxSCINT_RXRPTIE_DISABLED  = 0b0  // Interrupt is disabled
    } UxSCINT_RXRPTIE_e; // Receive Repeat Interrupt Enable bit

    typedef enum {
        UxSCINT_GTCIF_ENABLED   = 0b1, // Guard Time Counter has reached 0
        UxSCINT_GTCIF_DISABLED  = 0b0  // Guard Time Counter has not reached 0
    } UxSCINT_GTCIF_e; // Guard Time Counter Interrupt Flag bit

    typedef enum {
        UxSCINT_WTCIF_ENABLED   = 0b1, // Waiting Time Counter has reached 0
        UxSCINT_WTCIF_DISABLED  = 0b0  // Waiting Time Counter has not reached 0
    } UxSCINT_WTCIF_e; // Waiting Time Counter Interrupt Flag bit

    typedef enum {
        UxSCINT_BTCIF_ENABLED   = 0b1, // Block Time Counter has reached 0
        UxSCINT_BTCIF_DISABLED  = 0b0  // Block Time Counter has not reached 0
    } UxSCINT_BTCIF_e; // Block Time Counter Interrupt Flag bit

    typedef enum {
        UxSCINT_TXRPTIF_ENABLED = 0b1, // Line error has been detected after the last retransmit per TXRPT<1:0>
        UxSCINT_TXRPTIF_DISABLED= 0b0  // Flag is cleared
    } UxSCINT_TXRPTIF_e; // Transmit Repeat Interrupt Flag bit
            
    typedef enum {
        UxSCINT_RXRPTIF_ENABLED = 0b1, // Parity error has persisted after the same character has been received five times (four retransmits)
        UxSCINT_RXRPTIF_DISABLED= 0b0  // Flag is cleared
    } UxSCINT_RXRPTIF_e; // Receive Repeat Interrupt Flag bit
    
    typedef union {
        
        struct {
            
            volatile UxSCINT_GTCIE_e   gtcie   : 1; // Bit #0:  Guard Repeat Interrupt Enable bit
            volatile UxSCINT_WTCIE_e   wtcie   : 1; // Bit #1:  Waiting Repeat Interrupt Enable bit
            volatile UxSCINT_BTCIE_e   btcie   : 1; // Bit #2:  Block Repeat Interrupt Enable bit
            volatile unsigned                  : 1; // Bit #3:  unimplemented
            volatile UxSCINT_TXRPTIE_e txrptie : 1; // Bit #4:  Transmit Repeat Interrupt Enable bit
            volatile UxSCINT_RXRPTIE_e rxrptie : 1; // Bit #5:  Receive Repeat Interrupt Enable bit
            volatile unsigned                  : 2; // Bit #7-6: unimplemented
            volatile UxSCINT_GTCIF_e   gtcif   : 1; // Bit #8:  Guard Repeat Interrupt Flag bit
            volatile UxSCINT_WTCIF_e   wtcif   : 1; // Bit #9:  Waiting Repeat Interrupt Flag bit
            volatile UxSCINT_BTCIF_e   btcif   : 1; // Bit #10: Block Repeat Interrupt Flag bit
            volatile unsigned                  : 1; // Bit #11: unimplemented
            volatile UxSCINT_TXRPTIF_e txrptif : 1; // Bit #12: Transmit Repeat Interrupt Flag bit
            volatile UxSCINT_RXRPTIF_e rxrptif : 1; // Bit #13: Receive Repeat Interrupt Flag bit
            volatile unsigned                  : 2; // Bit #15-14: unimplemented

        } __attribute__((packed)) bits; // UxSCINT register bit field
        
        volatile uint16_t value; // UxSCINT register full register access
        
    } UxSCINT_t; // UxSCINT: UARTx SMART CARD INTERRUPT REGISTER
    
/* ===========================================================================
 * UxINT: UARTx INTERRUPT REGISTER
 * ===========================================================================*/

    #define UART_UxINT_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define UART_UxINT_REG_WRITE_MASK      (uint16_t)0x00C4
    #define UART_UxINT_REG_READ_MASK       (uint16_t)0x00C4

    // Full Register Bit Fields
    typedef enum {

        REG_UxINT_ABDIE_ENABLED  = 0b0000000000000001, // Allows ABDIF to set an event interrupt
        REG_UxINT_ABDIE_DISABLED = 0b0000000000000000, // ABDIF does not set an event interrupt

        REG_UxINT_ABDIF_SET      = 0b0000000000000001, // Sets when ABD sequence makes the final ?1?-to-?0? transition; triggers event interrupt (must be cleared by software)
        REG_UxINT_ABDIF_CLEAR    = 0b0000000000000000, // ABAUD is not enabled or ABAUD is enabled but auto-baud has not completed

        REG_UxINT_WUIF_SET       = 0b0000000000000001, // Sets when WAKE = 1 and RX makes a ?1?-to-?0? transition; triggers event interrupt (must be cleared by software)
        REG_UxINT_WUIF_CLEAR     = 0b0000000000000000  // WAKE is not enabled or WAKE is enabled, but no wake-up event has occurred

    } REG_UxINT_FLAGS_e;

    // Single Bit Fields
    typedef enum {
        UxINT_ABDIE_ENABLED  = 0b1, // Allows ABDIF to set an event interrupt
        UxINT_ABDIE_DISABLED = 0b0  // ABDIF does not set an event interrupt
    } UxINT_ABDIE_e; // Auto-Baud Completed Interrupt Enable Flag bit

    typedef enum {
        UxINT_ABDIF_SET      = 0b1, // Sets when ABD sequence makes the final ?1?-to-?0? transition; triggers event interrupt (must be cleared by software)
        UxINT_ABDIF_CLEAR    = 0b0  // ABAUD is not enabled or ABAUD is enabled but auto-baud has not completed
    } UxINT_ABDIF_e; // Auto-Baud Completed Interrupt Flag bit

    typedef enum {
        UxINT_WUIF_SET       = 0b1, // Sets when WAKE = 1 and RX makes a ?1?-to-?0? transition; triggers event interrupt (must be cleared by software)
        UxINT_WUIF_CLEAR     = 0b0  // WAKE is not enabled or WAKE is enabled, but no wake-up event has occurred
    } UxINT_WUIF_e; // Wake-up Interrupt Flag bit

    typedef union {
        
        struct {
            
            volatile unsigned            : 2;// Bit #1-0 Unimplemented: Read as ?0?
            volatile UxINT_ABDIE_e abdie : 1; // Bit #2 ABDIE: Auto-Baud Completed Interrupt Enable Flag bit
            volatile unsigned            : 3; // Bit #5-3 Unimplemented: Read as ?0?
            volatile UxINT_ABDIF_e adbif : 1; // Bit #6 ABDIF: Auto-Baud Completed Interrupt Flag bit
            volatile UxINT_WUIF_e  wuif  : 1; // Bit #7 WUIF: Wake-up Interrupt Flag bit
            volatile unsigned            : 8; // Bit #15-8 Unimplemented: Read as ?0?

        } __attribute__((packed)) bits; // UxINT register bit field
        
        volatile uint16_t value; // UxINT register full register access
        
    } UxINT_t; // UxINT: UARTx INTERRUPT REGISTER
    
/* ===========================================================================
 * UART OBJECTS
 * ===========================================================================*/

    #define UART_UxINT_VALID_DATA_MASK  0x00C4
    
    typedef struct {
        volatile UxMODE_t  mode;     // UxMODE: UARTx CONFIGURATION REGISTER HIGH/LOW (32-Bit)
        volatile UxSTA_t   status;   // UxSTA: UARTx STATUS REGISTER HIGH/LOW (32-Bit)
        volatile UxBRG_t   baudrate; // UxBRG: UARTx BAUD RATE REGISTER HIGH/LOW (32-Bit)
        volatile UxRXREG_t rx_reg;   // UxRXREG: UARTx RECEIVE BUFFER REGISTER (16-bit)
        volatile unsigned  :16;      // (reserved/empty)
        volatile UxTXREG_t tx_reg;   // UxTXREG: UARTx TRANSMIT BUFFER REGISTER (16-bit)
        volatile unsigned  :16;      // (reserved/empty)
        volatile UxP1_t    p1;       // UxP1: UARTx TIMING PARAMETER 1 REGISTER (16-bit)
        volatile UxP2_t    p2;       // UxP2: UARTx TIMING PARAMETER 2 REGISTER (16-bit)
        volatile UxP3_t    p3;       // UxP3: UARTx TIMING PARAMETER 3 REGISTER HIGH/LOW (32-Bit)
        volatile UxTXCHK_t tx_chk;   // UxTXCHK: UARTx TRANSMIT CHECKSUM REGISTER (16-bit)
        volatile UxRXCHK_t rx_chk;   // UxRXCHK: UARTx RECEIVE CHECKSUM REGISTER (16-bit)
        volatile UxSCCON_t sccon;    // UxSCCON: UARTx SMART CARD CONFIGURATION REGISTER (16-bit)
        volatile UxSCINT_t scint;    // UxSCINT: UARTx SMART CARD INTERRUPT REGISTER (16-bit)
        volatile UxINT_t   abaud_int; // UxINT: UARTx INTERRUPT REGISTER (16-bit)
    } __attribute__((packed)) UART_CONFIG_t;
    
    /* ===========================================================================
     * Generic UART defines for Standard UART user objects
     * ===========================================================================*/
    
    typedef enum {
        UART_ISR_PRIORITY_0 = 0, // UART interrupt service routine priority level #0 (main loop))
        UART_ISR_PRIORITY_1 = 1, // UART interrupt service routine priority level #1
        UART_ISR_PRIORITY_2 = 2, // UART interrupt service routine priority level #2
        UART_ISR_PRIORITY_3 = 3, // UART interrupt service routine priority level #3
        UART_ISR_PRIORITY_4 = 4, // UART interrupt service routine priority level #4
        UART_ISR_PRIORITY_5 = 5, // UART interrupt service routine priority level #5
        UART_ISR_PRIORITY_6 = 6, // UART interrupt service routine priority level #6
        UART_ISR_PRIORITY_7 = 7  // UART interrupt service routine priority level #7
    }UART_ISR_PRIORITY_e;

    typedef enum {
        UART_ISR_DISABLED = 0,   // Disable UART interrupt service routine
        UART_ISR_ENABLED  = 1    // Enable UART interrupt service routine
    }UART_ISR_ENABLE_STATE_e;

    typedef enum {
        UART_BAUDRATE_75      = 75,
        UART_BAUDRATE_110     = 110,
        UART_BAUDRATE_134     = 134,
        UART_BAUDRATE_150     = 150,
        UART_BAUDRATE_300     = 300,
        UART_BAUDRATE_600     = 600,
        UART_BAUDRATE_1200    = 1200,
        UART_BAUDRATE_1800    = 1800,
        UART_BAUDRATE_2400    = 2400,
        UART_BAUDRATE_4800    = 4800,
        UART_BAUDRATE_7200    = 7200,
        UART_BAUDRATE_9600    = 9600,
        UART_BAUDRATE_14400   = 14400,
        UART_BAUDRATE_19200   = 19200,
        UART_BAUDRATE_38400   = 38400,
        UART_BAUDRATE_57600   = 57600,
        UART_BAUDRATE_115200  = 115200,
        UART_BAUDRATE_128000  = 128000,
        UART_BAUDRATE_256000  = 256000,
        UART_BAUDRATE_512000  = 512000,
        UART_BAUDRATE_1024000 = 1024000
    }UART_BAUDRATE_SETTING_e;

    typedef enum {
        UART_DATA_BITS_7 = 7,   // Seven data bits
        UART_DATA_BITS_8 = 8,   // Eight data bits
        UART_DATA_BITS_9 = 9    // Nine data bits
    }UART_DATA_BIT_SETTING_e;   // UART Data Bits Settings

    typedef enum {
        UART_STOP_BITS_1 = 1,   // One Stop-Bit
        UART_STOP_BITS_15 = 15, // 1.5 Stop-Bits
        UART_STOP_BITS_2 = 2    // Two Stop-Bits
    }UART_STOP_BIT_SETTING_e;   // UART Stop-Bit Settings

    typedef enum {
        UART_PARITY_NONE = 0,   // No Parity 
        UART_PARITY_ODD = 1,    // Odd Parity
        UART_PARITY_EVEN = 2    // Even Parity
    }UART_PARITY_SETTING_e;     // UART Parity Settings
    
    typedef enum {
        UART_FLOW_CONTROL_NONE = 0,
        UART_FLOW_CONTROL_XON_XOFF = 1,
        UART_FLOW_CONTROL_HARDWARE = 2
    }UART_FLOW_CONTROL_SETTING_e;

    typedef enum {
        UART_FIFO_SIZE_1_BYTE = 0,  // Interrupt will be triggered after 1 Byte
        UART_FIFO_SIZE_2_BYTE = 1,  // Interrupt will be triggered after 2 Byte
        UART_FIFO_SIZE_3_BYTE = 2,  // Interrupt will be triggered after 3 Byte
        UART_FIFO_SIZE_4_BYTE = 3,  // Interrupt will be triggered after 4 Byte
        UART_FIFO_SIZE_5_BYTE = 4,  // Interrupt will be triggered after 5 Byte
        UART_FIFO_SIZE_6_BYTE = 5,  // Interrupt will be triggered after 6 Byte
        UART_FIFO_SIZE_7_BYTE = 6,  // Interrupt will be triggered after 7 Byte
        UART_FIFO_SIZE_8_BYTE = 7   // Interrupt will be triggered after 8 Byte
    }UART_FIFO_ISR_MARK_e;          // FIFO Buffer Level (number of bytes) at which the buffer will be read/written
                                    // This level will also be used to trigger a RECEIVE/TRANSMIT interrupt
    
    typedef struct {
        volatile bool buffer_empty : 1; // Bit 0: Buffer empty status bit
        volatile bool buffer_full  : 1; // Bit 1: Buffer full status bit
        volatile unsigned          : 6; // Bit 7-2: (reserved)
        volatile bool buffer_overun: 1; // Bit 8: Buffer Overrun status bit
        volatile unsigned          : 6; // Bit 14-9: (reserved)
        volatile bool msg_complete : 1; // Bit 15: Message Complete
    } __attribute__((packed))UART_DATBUF_STATUS_t;
    
    typedef struct {
        volatile UART_DATBUF_STATUS_t status; // Status word of user buffer
        volatile uint8_t* buffer;    // Pointer to user RECEIVE buffer
        volatile uint16_t size;      // Absolute size of buffer array in <byte>
        volatile uint16_t data_size; // size of recently loaded data array in <byte>
        volatile uint16_t pointer;   // Pointer to next free cell of buffer array
        volatile UART_FIFO_ISR_MARK_e fifo_isr_mark; // FIFO buffer level at which an interrupt should be triggered
        volatile uint16_t package_size; // User-defined data package size sent at a time (Tx only, 0=single byte transmission)
    }UART_DATA_BUFFER_t;
    
    typedef struct {
        volatile uint16_t*                   handle;        // Pointer to UART SFR register bank
        volatile uint16_t                    instance;      // Port-Number (e.g. 1=UART1, 2=UART2, etc)
        volatile UART_BAUDRATE_SETTING_e     baudrate;      // Baud-Rate 75-1024000
        volatile UART_DATA_BIT_SETTING_e     data_bits;     // 7, 8 or 9 data bits
        volatile UART_PARITY_SETTING_e       parity;        // None, Odd, Even
        volatile UART_STOP_BIT_SETTING_e     stop_bits;     // 1, 1.5 or 2 stop bits
        volatile UART_FLOW_CONTROL_SETTING_e flow_control;  // None, Xon/Xoff or Hardware
        volatile UART_DATA_BUFFER_t          rx_buffer;     // User RECEIVE buffer
        volatile UART_DATA_BUFFER_t          tx_buffer;     // User TRANSMIT buffer
    } UART_t;

#else
    #pragma message "Gap in device support detected. Please review UART driver file."
#endif

    
// Prototypes
extern volatile uint16_t smpsUART_OpenPort(volatile UART_t* uart);
extern volatile uint16_t smpsUART_Close(volatile UART_t* uart);
extern volatile uint16_t smpsUART_Dispose(volatile UART_t* uart);

extern volatile uint16_t smpsUART_Initialize(volatile uint16_t uart_instance, volatile UART_CONFIG_t config);
    
extern volatile uint16_t smpsUART_SetBaudrate(volatile uint16_t uart_instance, uint32_t baud);
extern volatile uint32_t smpsUART_GetBaudrate(volatile uint16_t uart_instance);
extern volatile uint32_t smpsUART_GetBaudrateRegValue(volatile uint16_t uart_instance, uint32_t baud);

extern volatile uint16_t smpsUART_ReadFIFO(volatile UART_t* uart);
extern volatile uint16_t smpsUART_WriteFIFO(volatile UART_t* uart);
extern volatile uint32_t smpsUART_GetStatus(volatile UART_t uart);

extern volatile uint16_t smpsUART_Enable(volatile UART_t uart);
extern volatile uint16_t smpsUART_Disable(volatile UART_t uart);

extern volatile uint16_t smpsUART_PowerOn(volatile uint16_t uart_instance);
extern volatile uint16_t smpsUART_PowerOff(volatile uint16_t uart_instance);

extern volatile uint16_t smpsUART_GetStandardCRC16(volatile uint8_t *buffer, volatile uint8_t start, volatile uint8_t length);

#endif  /* __MCAL_P33SMPS_UART_H__ */
// End of File
