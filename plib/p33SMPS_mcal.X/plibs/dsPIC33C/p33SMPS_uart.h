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

#ifndef _MCAL_P33_SMPS_UART_H_
#define _MCAL_P33_SMPS_UART_H_

#include <stdint.h>

#include "../p33SMPS_devices.h"
#include "p33SMPS_oscillator.h"
#include "p33SMPS_oscillator_default_cfg.h"

/*@@p33FGS_uart.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS UART SFRs
 *
 * Description:
 * The UART module offers a number of registers and configuration options. This additional
 * header file contains defines for all required settings.
 * ***********************************************************************************************/

// Device specific properties
#if defined (__P33SMPS_EP2__)
	#define UART_UART_COUNT	1
	#define UART_INDEX_REG_OFFSET	0x0008

#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
	#define UART_UART_COUNT	2
	#define UART_INDEX_REG_OFFSET	0x0008

#elif defined (__P33SMPS_CH__) 

    #if defined (__P33SMPS_CH_SLV__) 
        #define UART_UART_COUNT	1
        #define UART_INDEX_REG_OFFSET	0x0014

    #elif defined (__P33SMPS_CH_MSTR__) 
        #define UART_UART_COUNT	2
        #define UART_INDEX_REG_OFFSET	0x0014
    #endif

#elif defined (__P33SMPS_CK__)
	#define UART_UART_COUNT	3
	#define UART_INDEX_REG_OFFSET	0x0014

#else
	//#error === selected device not supported ===

#endif

#if defined (__P33SMPS_EP__) 

    #define UART_UxMODE_REG_DISPOSE_MASK     0x0000
    #define UART_UxSTA_REG_DISPOSE_MASK      0x0000

    #define UART_UxMODE_REG_WRITE_MASK		 0xBBFF
    #define UART_UxMODE_REG_READ_MASK		 0xBBFF
    #define UART_UxMODE_REG_OFF_MASK         0x3BFF

    #define UART_UxSTA_REG_WRITE_MASK        0xECE1
    #define UART_UxSTA_REG_RESET_WRITE_MASK  0xECE3
    #define UART_UxSTA_REG_READ_MASK         0xEFFF

    #define UART_UxBRG_REG_WRITE_MASK        0xFFFF
    #define UART_UxBRG_REG_READ_MASK         0xFFFF

    #define UxBRGL(x)    ((uint16_t)(FCY / (16 * x)) - 1)
    #define UxBRGH(x)    ((uint16_t)(FCY / (4 * x)) - 1)

#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__) 

    #define UART_UxMODE_REG_DISPOSE_MASK     0x0000
    #define UART_UxMODE_REG_READ_MASK		 0xBBFF
    #define UART_UxMODE_REG_WRITE_MASK		 0xBBFF
    #define UART_UxMODE_REG_OFF_MASK         0x3BFF

    #define UART_UxMODEH_REG_DISPOSE_MASK    0x0000
    #define UART_UxMODEH_REG_READ_MASK		 0xCFFF
    #define UART_UxMODEH_REG_WRITE_MASK		 0x8FFF

    #define UART_UxSTA_REG_DISPOSE_MASK      0x0000
    #define UART_UxSTA_REG_READ_MASK         0xFFFF
    #define UART_UxSTA_REG_WRITE_MASK        0xFF37
    #define UART_UxSTA_REG_RESET_WRITE_MASK  0xFFC8

    #define UART_UxSTAH_REG_DISPOSE_MASK     0x883F
    #define UART_UxSTAH_REG_READ_MASK        0x77FF
    #define UART_UxSTAH_REG_WRITE_MASK       0x77C0
    #define UART_UxSTAH_REG_RESET_WRITE_MASK 0x883F

    #define UART_UxBRG_REG_WRITE_MASK        0xFFFF
    #define UART_UxBRG_REG_READ_MASK         0xFFFF

    #define UART_UxBRGH_REG_WRITE_MASK       0x000F
    #define UART_UxBRGH_REG_READ_MASK        0x000F

//    #define UART_UxBRGL(x)    ((uint16_t)(((float)FCY / (16.0 * (float)x)) - 1.0))
//    #define UART_UxBRGH(x)    ((uint16_t)(((float)FCY / (4.0 * (float)x)) - 1.0))

    #define UART_UxP1_REG_WRITE_MASK         0x01FF
    #define UART_UxP1_REG_READ_MASK          0x01FF

    #define UART_UxP2_REG_WRITE_MASK         0x01FF
    #define UART_UxP2_REG_READ_MASK          0x01FF

    #define UART_UxP3_REG_WRITE_MASK         0xFFFF
    #define UART_UxP3_REG_READ_MASK          0xFFFF

    #define UART_UxP3H_REG_WRITE_MASK        0x00FF
    #define UART_UxP3H_REG_READ_MASK         0x00FF

    #define UART_UxTXCHK_REG_WRITE_MASK      0x00FF
    #define UART_UxTXCHK_REG_READ_MASK       0x00FF

    #define UART_UxRXCHK_REG_WRITE_MASK      0x00FF
    #define UART_UxRXCHK_REG_READ_MASK       0x00FF


#else

    #pragma message "Gap in SMPS UART driver device support. Please review file."
    
#endif

// Interrupt Flag-Bits & Priorities
#if ( UART_UART_COUNT >= 1 )

    #define UART1_RX_ISR_FLAG		_U1RXIF	// UART1 RX interrupt flag
    #define UART1_RX_ISR_PRIORITY	_U1RXIP	// UART1 RX interrupt priority
    #define UART1_RX_ISR_ENABLE     _U1RXIE	// UART1 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 2 )

    #define UART2_RX_ISR_FLAG		_U2RXIF	// UART2 RX interrupt flag
    #define UART2_RX_ISR_PRIORITY	_U2RXIP	// UART2 RX interrupt priority
    #define UART2_RX_ISR_ENABLE     _U2RXIE	// UART2 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 3 )

    #define UART3_RX_ISR_FLAG		_U3RXIF	// UART3 RX interrupt flag
    #define UART3_RX_ISR_PRIORITY	_U3RXIP	// UART3 RX interrupt priority
    #define UART3_RX_ISR_ENABLE     _U3RXIE	// UART3 RX interrupt service routine enable

#endif

#if ( UART_UART_COUNT >= 4 )
  #error === no device support ===
#endif

typedef enum
{
    UART_ISR_PRIORITY_0 = 0, // UART interrupt service routine priority level #0 (main loop))
    UART_ISR_PRIORITY_1 = 1, // UART interrupt service routine priority level #1
    UART_ISR_PRIORITY_2 = 2, // UART interrupt service routine priority level #2
    UART_ISR_PRIORITY_3 = 3, // UART interrupt service routine priority level #3
    UART_ISR_PRIORITY_4 = 4, // UART interrupt service routine priority level #4
    UART_ISR_PRIORITY_5 = 5, // UART interrupt service routine priority level #5
    UART_ISR_PRIORITY_6 = 6, // UART interrupt service routine priority level #6
    UART_ISR_PRIORITY_7 = 7  // UART interrupt service routine priority level #7
}UART_ISR_PRIORITY_e;

typedef enum
{
    UART_ISR_DISABLED = 0,   // Disable UART interrupt service routine
    UART_ISR_ENABLED  = 1    // Enable UART interrupt service routine
}UART_ISR_ENABLE_STATE_e;

typedef enum
{
    UART_BAUDRATE_75 = 75,
    UART_BAUDRATE_110 = 110,
    UART_BAUDRATE_134 = 134,
    UART_BAUDRATE_150 = 150,
    UART_BAUDRATE_300 = 300,
    UART_BAUDRATE_600 = 600,
    UART_BAUDRATE_1200 = 1200,
    UART_BAUDRATE_1800 = 1800,
    UART_BAUDRATE_2400 = 2400,
    UART_BAUDRATE_4800 = 4800,
    UART_BAUDRATE_7200 = 7200,
    UART_BAUDRATE_9600 = 9600,
    UART_BAUDRATE_14400 = 14400,
    UART_BAUDRATE_19200 = 19200,
    UART_BAUDRATE_38400 = 38400,
    UART_BAUDRATE_57600 = 57600,
    UART_BAUDRATE_115200 = 115200,
    UART_BAUDRATE_128000 = 128000,
    UART_BAUDRATE_256000 = 256000,
    UART_BAUDRATE_512000 = 512000,
    UART_BAUDRATE_1024000 = 1024000
}UART_BAUDRATE_SETTING_e;

typedef enum
{
    UART_DATA_BITS_7 = 7,
    UART_DATA_BITS_8 = 8,
    UART_DATA_BITS_9 = 9
}UART_DATA_BIT_SETTING_e;

typedef enum
{
    UART_STOP_BITS_1 = 1,
    UART_STOP_BITS_15 = 15,
    UART_STOP_BITS_2 = 2
}UART_STOP_BIT_SETTING_e;

typedef enum
{
    UART_PARITY_NONE,
    UART_PARITY_ODD,
    UART_PARITY_EVEN,
}UART_PARITY_SETTING_e;

// Generic Defines

typedef enum
{
    UART_ENABLED_ON  = 1,
    UART_ENABLED_OFF = 0
}UART_ENABLED_STATE_e;

#if defined (__P33SMPS_EP__)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// UxMODE: UARTx MODE REGISTER
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Full Register Bit Fields
    typedef enum
    {
        REG_UARTEN_ON           = 0b1000000000000000,
        REG_UARTEN_OFF          = 0b0000000000000000,

        REG_USIDL_ACTIVE        = 0b0000000000000000,
        REG_USIDL_STOP          = 0b0010000000000000,

        REG_IREN_ON             = 0b0001000000000000,
        REG_IREN_OFF            = 0b0000000000000000,

        REG_RTSMD_SIMPLEX       = 0b0000100000000000,
        REG_RTSMD_FLOW_CONTROL  = 0b0000000000000000,

        REG_UEN_TX_RX_BCLK      = 0b0000001100000000,
        REG_UEN_TX_RX_CTS_RTS	= 0b0000001000000000,
        REG_UEN_TX_RX_RTS       = 0b0000000100000000,
        REG_UEN_TX_RX           = 0b0000000000000000,

        REG_WAKE_ENABLED        = 0b0000000010000000,		
        REG_WAKE_DISABLED       = 0b0000000000000000,		

        REG_LPBACK_ENABLED      = 0b0000000001000000,		
        REG_LPBACK_DISABLED     = 0b0000000000000000,		

        REG_ABAUD_ENABLED       = 0b0000000000100000,		
        REG_ABAUD_DISABLED      = 0b0000000000000000,		

        REG_URXINV_ENABLED      = 0b0000000000010000,		
        REG_URXINV_DISABLED     = 0b0000000000000000,		

        REG_BRGH_HIGH_SPEED     = 0b0000000000001000,		
        REG_BRGH_STANDARD       = 0b0000000000000000,		

        REG_PDSEL_9_DBITS_NO_PARITY    = 0b0000000000000110,		
        REG_PDSEL_8_DBITS_ODD_PARITY   = 0b0000000000000100,		
        REG_PDSEL_8_DBITS_EVEN_PARITY  = 0b0000000000000010,		
        REG_PDSEL_8_DBITS_NO_PARITY    = 0b0000000000000000,		

        REG_STSEL_2_STOP_BIT    = 0b0000000000000001,		
        REG_STSEL_1_STOP_BIT    = 0b0000000000000000		

    }REG_UxMODE_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UARTEN_ON           = 0b1,
        UARTEN_OFF          = 0b0,

        USIDL_ACTIVE        = 0b0,
        USIDL_STOP          = 0b1,

        IREN_ON             = 0b1,
        IREN_OFF            = 0b0,

        RTSMD_SIMPLEX       = 0b1,
        RTSMD_FLOW_CONTROL  = 0b0,

        UEN_TX_RX_BCLK      = 0b11,
        UEN_TX_RX_CTS_RTS	= 0b10,
        UEN_TX_RX_RTS       = 0b01,
        UEN_TX_RX           = 0b00,

        WAKE_ENABLED        = 0b1,		
        WAKE_DISABLED       = 0b0,		

        LPBACK_ENABLED      = 0b1,		
        LPBACK_DISABLED     = 0b0,		

        ABAUD_ENABLED       = 0b1,		
        ABAUD_DISABLED      = 0b0,		

        URXINV_ENABLED      = 0b1,		
        URXINV_DISABLED     = 0b0,		

        BRGH_HIGH_SPEED     = 0b1,		
        BRGH_STANDARD       = 0b0,		

        PDSEL_9_DBITS_NO_PARITY    = 0b11,		
        PDSEL_8_DBITS_ODD_PARITY   = 0b10,		
        PDSEL_8_DBITS_EVEN_PARITY  = 0b01,		
        PDSEL_8_DBITS_NO_PARITY    = 0b00,		

        STSEL_2_STOP_BIT    = 0b1,		
        STSEL_1_STOP_BIT    = 0b0		

    }REG_UxMODE_FLAGS_e;

    typedef struct
    {
        volatile unsigned stel  :1;	// Bit #0: Stop Bit Selection bit
        volatile unsigned pdsel	:2;	// Bit #1-2: Parity and Data Selection bits
        volatile unsigned brgh  :1;	// Bit #3: High Baud Rate Enable bit
        volatile unsigned uxinv	:1;	// Bit #4: UARTx Receive Polarity Inversion bit
        volatile unsigned abaud	:1;	// Bit #5: Auto-Baud Enable bit
        volatile unsigned lpback:1; // Bit #6: UARTx Loopback Mode Select bit
        volatile unsigned wake	:1;	// Bit #7: Wake-up on Start Bit Detect During Sleep Mode Enable bit
        volatile unsigned uen	:2;	// Bit #8-9: UARTx Pin Enable bits
        volatile unsigned		:1;	// Bit #10: reserved
        volatile unsigned rtsmd	:1;	// Bit #11: Mode Selection for UxRTS Pin bit
        volatile unsigned iren	:1;	// Bit #12: IrDA® Encoder and Decoder Enable bit
        volatile unsigned usidl	:1;	// Bit #13: UARTx Stop in Idle Mode bit
        volatile unsigned		:1;	// Bit #14: reserved
        volatile unsigned uarten:1;	// Bit #15: UARTx Enable bit
    }__attribute__((packed))UxMODE_CONTROL_REGISTER_BIT_FIELD_t;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  UxSTA - Register Flags
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
// UxSTA: UARTx STATUS AND CONTROL REGISTER
    
    // Full Register Bit Fields
    typedef enum
    {
        REG_UTXISEL_BUF_EMTPY   = 0b1000000000000000,
        REG_UTXISEL_TX_COMPLETE = 0b0010000000000000,
        REG_UTXISEL_BUF_CUE     = 0b0000000000000000,

        REG_UTXINV_ON           = 0b0100000000000000,
        REG_UTXINV_OFF          = 0b0000000000000000,

        REG_UTXBRK_ON           = 0b0000100000000000,
        REG_UTXBRK_OFF          = 0b0000000000000000,

        REG_UTXEN_ON            = 0b0000010000000000,
        REG_UTXEN_OFF           = 0b0000000000000000,

        REG_UTXBF_FULL          = 0b0000001000000000,
        REG_UTXBF_EMPTY         = 0b0000000000000000,
            
        REG_TRMT_ON             = 0b0000000100000000,
        REG_TRMT_OFF            = 0b0000000000000000,
            
        REG_URXISEL_BUF_FULL    = 0b0000000011000000,
        REG_URXISEL_BUF_75      = 0b0000000010000000,
        REG_URXISEL_BUF_RECEIVE = 0b0000000001000000,

        REG_ADDEN_ENABLED      = 0b0000000000100000,		
        REG_ADDEN_DISABLED     = 0b0000000000000000,		

        REG_RIDLE_IDLE         = 0b0000000000010000,		
        REG_RIDLE_ACTIVE       = 0b0000000000000000,		

        REG_PERR_DETECTED      = 0b0000000000001000,		
        REG_PERR_NONE          = 0b0000000000000000,		

        REG_FERR_DETECTED      = 0b0000000000000100,		
        REG_FERR_NONE          = 0b0000000000000000,		
            
        REG_OERR_DETECTED      = 0b0000000000000010,		
        REG_OERR_NONE          = 0b0000000000000000,		
        REG_OERR_RESET         = 0b1111111111111101,
            
        REG_URXDA_DATA_READY   = 0b0000000000000001,		
        REG_URXDA_NO_DATA      = 0b0000000000000000		

    }REG_UxSTA_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UTXISEL1_BUF_EMTPY   = 0b1,
        UTXISEL1_TX_COMPLETE = 0b0,
        UTXISEL1_BUF_CUE     = 0b0,

        UTXISEL0_BUF_EMTPY   = 0b0,
        UTXISEL0_TX_COMPLETE = 0b1,
        UTXISEL0_BUF_CUE     = 0b0,
    
        UTXINV_ON           = 0b1,
        UTXINV_OFF          = 0b0,

        UTXBRK_ON           = 0b1,
        UTXBRK_OFF          = 0b0,

        UTXEN_ON            = 0b1,
        UTXEN_OFF           = 0b0,

        UTXBF_ON            = 0b1,
        UTXBF_OFF           = 0b0,
            
        TRMT_ON             = 0b1,
        TRMT_OFF            = 0b0,
            
        URXISEL_BUF_FULL    = 0b11,
        URXISEL_BUF_75      = 0b10,
        URXISEL_BUF_RECEIVE = 0b01,

        ADDEN_ENABLED      = 0b1,		
        ADDEN_DISABLED     = 0b0,		

        RIDLE_ENABLED      = 0b1,		
        RIDLE_DISABLED     = 0b0,		

        PERR_ENABLED       = 0b1,		
        PERR_DISABLED      = 0b0,		

        FERR_ENABLED       = 0b1,		
        FERR_DISABLED      = 0b0,		
            
        OERR_ENABLED       = 0b1,		
        OERR_DISABLED      = 0b0,		
            
        URXDA_ENABLED      = 0b1,		
        URXDA_DISABLED     = 0b0		

    }REG_UxSTA_FLAGS_e;

    typedef struct
    {
        volatile unsigned urxda :1;	// Bit #0: UARTx Receive Buffer Data Available bit (read-only)
        volatile unsigned oerr	:1;	// Bit #1: Receive Buffer Overrun Error Status bit (clear/read-only)
        volatile unsigned ferr	:1;	// Bit #2: Framing Error Status bit (read-only)
        volatile unsigned perr  :1;	// Bit #3: Parity Error Status bit (read-only)
        volatile unsigned ridle	:1;	// Bit #4: Receiver Idle bit (read-only)
        volatile unsigned adden	:1;	// Bit #5: Address Character Detect bit (bit 8 of received data = 1)
        volatile unsigned urxisel:2; // Bit #6-7: UARTx Receive Interrupt Mode Selection bits
        volatile unsigned trmt	:1;	// Bit #8: Transmit Shift Register Empty bit (read-only)
        volatile unsigned utsbf	:1;	// Bit #9: UARTx Transmit Buffer Full Status bit (read-only)
        volatile unsigned utxen	:1;	// Bit #10: UARTx Transmit Enable bit
        volatile unsigned utxbrk:1;	// Bit #11: UARTx Transmit Break bit
        volatile unsigned		:1;	// Bit #12: reserved
        volatile unsigned utxiseldl0:1;	// Bit #13: UARTx Transmission Interrupt Mode Selection bit 0
        volatile unsigned utxinv:1;	// Bit #14: UARTx Transmit Polarity Inversion bit
        volatile unsigned utxiseldl1:1;	// Bit #15: UARTx Transmission Interrupt Mode Selection bit 1
    }__attribute__((packed))UxSTA_CONTROL_REGISTER_BIT_FIELD_t;

    
#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// UxMODE: UARTx MODE REGISTER
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Full Register Bit Fields
    typedef enum
    {
        REG_UARTEN_ENABLED      = 0b1000000000000000,   // UART Enable bit
        REG_UARTEN_DISABLED     = 0b0000000000000000,

        REG_USIDL_ACTIVE        = 0b0000000000000000,   // UART Stop in Idle Mode bit
        REG_USIDL_STOP          = 0b0010000000000000,

        REG_WAKE_ENABLED        = 0b0001000000000000,   // Wake-up Enable bit
        REG_WAKE_DISABLED       = 0b0000000000000000,

        REG_RXBIMD_DMX_LIN      = 0b0000100000000000,  // Receive Break Interrupt Mode bit
        REG_RXBIMD_DEFAULT      = 0b0000000000000000,

        REG_BRKOVR_ON           = 0b0000001000000000,   // Send Break Software Override bit
        REG_BRKOVR_OFF      	= 0b0000000000000000,

        REG_UTXBRK_ENABLED      = 0b0000000100000000,   // UART Transmit Break bit
        REG_UTXBRK_DISABLED     = 0b0000000000000000,		

        REG_BRGH_HIGH_SPEED     = 0b0000000010000000,	// High Baud Rate Select bit
        REG_BRGH_DEFAULT        = 0b0000000000000000,		

        REG_ABAUD_ENABLED       = 0b0000000001000000,	// Auto-Baud Detect Enable bit (read-only when MOD<3:0> = 1xxx)
        REG_ABAUD_DISABLED      = 0b0000000000000000,		

        REG_UTXEN_ENABLED       = 0b0000000000100000,	// UART Transmit Enable bit
        REG_UTXEN_DISABLED      = 0b0000000000000000,		

        REG_URXEN_ENABLED       = 0b0000000000010000,	// UART Receive Enable bit
        REG_URXEN_DISABLED      = 0b0000000000000000,		

        REG_MOD_SMART_CARD      = 0b0000000000001111,	// UART Mode bits
        REG_MOD_IRDA            = 0b0000000000001110,
        REG_MOD_LIN_MSTR_SLV    = 0b0000000000001100,
        REG_MOD_LIN_SLV         = 0b0000000000001011,
        REG_MOD_DMX             = 0b0000000000001010,
        REG_MOD_ASYNC_9B_NONE   = 0b0000000000000100,
        REG_MOD_ASYNC_8B_EVEN   = 0b0000000000000011,
        REG_MOD_ASYNC_8B_ODD    = 0b0000000000000010,
        REG_MOD_ASYNC_8B_NONE   = 0b0000000000000000,
        REG_MOD_ASYNC_7B_NONE   = 0b0000000000000001

    }REG_UxMODE_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UARTEN_ENABLED      = 0b1,   // UART Enable bit
        UARTEN_DISABLED     = 0b0,

        USIDL_ACTIVE        = 0b0,   // UART Stop in Idle Mode bit
        USIDL_STOP          = 0b1,

        WAKE_ENABLED        = 0b1,   // Wake-up Enable bit
        WAKE_DISABLED       = 0b0,

        RXBIMD_DMX_LIN      = 0b1,  // Receive Break Interrupt Mode bit
        RXBIMD_DEFAULT      = 0b0,

        BRKOVR_ON           = 0b1,   // Send Break Software Override bit
        BRKOVR_OFF      	= 0b0,

        UTXBRK_ENABLED      = 0b1,   // UART Transmit Break bit
        UTXBRK_DISABLED     = 0b0,		

        BRGH_HIGH_SPEED     = 0b1,	// High Baud Rate Select bit
        BRGH_DEFAULT        = 0b0,		

        ABAUD_ENABLED       = 0b1,	// Auto-Baud Detect Enable bit (read-only when MOD<3:0> = 1xxx)
        ABAUD_DISABLED      = 0b0,		

        UTXEN_ENABLED       = 0b1,	// UART Transmit Enable bit
        UTXEN_DISABLED      = 0b0,		

        URXEN_ENABLED       = 0b1,	// UART Receive Enable bit
        URXEN_DISABLED      = 0b0,		

        MOD_SMART_CARD      = 0b1111,	// UART Mode bits
        MOD_IRDA            = 0b1110,
        MOD_LIN_MSTR_SLV    = 0b1100,
        MOD_LIN_SLV         = 0b1011,
        MOD_DMX             = 0b1010,
        MOD_ASYNC_9B_NONE   = 0b0100,
        MOD_ASYNC_8B_EVEN   = 0b0011,
        MOD_ASYNC_8B_ODD    = 0b0010,
        MOD_ASYNC_8B_NONE   = 0b0000,
        MOD_ASYNC_7B_NONE   = 0b0001

    }REG_UxMODE_FLAGS_e;

    typedef struct
    {
        volatile unsigned mod	:4;	// Bit #3-0: UART Mode bits
        volatile unsigned urxen	:1;	// Bit #4: UART Receive Enable bit
        volatile unsigned utxen :1; // Bit #5: UART Transmit Enable bit
        volatile unsigned abaud	:1;	// Bit #6: Auto-Baud Enable bit
        volatile unsigned brgh	:1;	// Bit #7: High Baud Rate Enable bit
        volatile unsigned utxbrk:1;	// Bit #8: UART Transmit Break bit
        volatile unsigned brkovr:1;	// Bit #9: Send Break Software Override bit
        volatile unsigned       :1;	// Bit #10: reserved
        volatile unsigned rxbimd:1;	// Bit #11: Receive Break Interrupt Mode bit
        volatile unsigned wake	:1;	// Bit #12: Wake-up on Start Bit Detect During Sleep Mode Enable bit
        volatile unsigned usidl	:1;	// Bit #13: UARTx Stop in Idle Mode bit
        volatile unsigned		:1;	// Bit #14: reserved
        volatile unsigned uarten:1;	// Bit #15: UARTx Enable bit
    }__attribute__((packed))UxMODE_CONTROL_REGISTER_BIT_FIELD_t;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// UxMODEH: UARTx MODE REGISTER HIGH
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Full Register Bit Fields
    typedef enum
    {
        REG_SLPEN_ENABLED       = 0b1000000000000000,   // Run During Sleep Enable bit
        REG_SLPEN_DISABLED      = 0b0000000000000000,

        REG_ACTIVE_RUN          = 0b0100000000000000,   // UART Running Status bit
        REG_ACTIVE_STOP         = 0b0000000000000000,

        REG_BCLKMOD_FRACTIONAL  = 0b0000100000000000,   // Baud Clock Generation Mode Select bit
        REG_BCLKMOD_DIV_BY_CNT  = 0b0000000000000000,

        REG_BCLKSEL_AFVCO_DIV3  = 0b0000010000000000,   // Baud Clock Source Selection bits = ACLK/3
        REG_BCLKSEL_FOSC        = 0b0000010000000000,   // Baud Clock Source Selection bits = FOSC
        REG_BCLKSEL_FOSC_DIV2   = 0b0000000000000000,   // Baud Clock Source Selection bits = FOSC/2 = Peripheral Clock

        REG_HALFDPLX_HALF       = 0b0000000100000000,   // UART Half-Duplex Selection Mode bit
        REG_HALFDPLX_FULL   	= 0b0000000000000000,

        REG_RUNOVF_ENABLED      = 0b0000000010000000,   // Run During Overflow Condition Mode bit
        REG_RUNOVF_DISABLED     = 0b0000000000000000,		

        REG_URXINV_ACTIVE_LOW   = 0b0000000001000000,	// UART Receive Polarity bit
        REG_URXINV_ACTIVE_HIGH  = 0b0000000000000000,		

        REG_STSEL_2_SBIT_1_CHK  = 0b0000000000110000,	// Number of Stop Bits Selection bits
        REG_STSEL_2_SBIT_2_CHK  = 0b0000000000100000,
        REG_STSEL_15_SBIT_15_CHK = 0b0000000000010000,
        REG_STSEL_1_SBIT_1_CHK  = 0b0000000000000000,		

        REG_C0EN_ENABLED        = 0b0000000000001000,	// Enable Legacy Checksum (C0) Transmit and Receive bit
        REG_C0EN_DISABLED       = 0b0000000000000000,		

        REG_UTXINV_ACTIVE_LOW   = 0b0000000000000100,	// UART Transmit Polarity bit
        REG_UTXINV_ACTIVE_HIGH  = 0b0000000000000000,		

        REG_FLO_RTS_CTS         = 0b0000000000000010,	// Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
        REG_FLO_XON_XOFF        = 0b0000000000000001,
        REG_FLO_NONE            = 0b0000000000000000

    }REG_UxMODEH_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum {
        SLPEN_ENABLED       = 0b1,  // Run During Sleep Mode
        SLPEN_DISABLED      = 0b0   // Suspend During Sleep Mode
    }REG_UxMODEH_SLPEN_FLAG_e;     // Run During Sleep Enable bit
    
    typedef enum {
        ACTIVE_RUN          = 0b1,  // UART clock request is active (user can not update the UxMODE/UxMODEH registers)
        ACTIVE_STOP         = 0b0   // UART clock request is not active (user can update the UxMODE/UxMODEH registers)
    }REG_UxMODEH_ACTIVE_FLAG_e;     // UART Running Status bit

    typedef enum {
        BCLKMOD_FRACTIONAL  = 0b1,  // Uses fractional Baud Rate Generation
        BCLKMOD_DIV_BY_CNT  = 0b0   // Uses legacy divide-by-x counter for baud clock generation
    }REG_UxMODEH_BCLKMOD_FLAG_e;    // Baud Clock Generation Mode Select bit

    typedef enum {
        BCLKSEL_AFVCO_DIV3  = 0b11, // Baud Clock Source Selection bits = ACLK/3
        BCLKSEL_FOSC        = 0b01, // Baud Clock Source Selection bits = FOSC = CPU Clock
        BCLKSEL_FOSC_DIV2   = 0b00, // Baud Clock Source Selection bits = FOSC/2 = Peripheral Clock
    }REG_UxMODEH_BCLKSEL_FLAG_e;    // Baud Clock Source Selection bits

    typedef enum {
        HALFDPLX_HALF       = 0b1,   // UART Half-Duplex Selection Mode bit
        HALFDPLX_FULL   	= 0b0,

        RUNOVF_ENABLED      = 0b1,   // Run During Overflow Condition Mode bit
        RUNOVF_DISABLED     = 0b0,		

        URXINV_ACTIVE_LOW   = 0b1,	// UART Receive Polarity bit
        URXINV_ACTIVE_HIGH  = 0b0,		

        STSEL_2_SBIT_1_CHK  = 0b11,	// Number of Stop Bits Selection bits
        STSEL_2_SBIT_2_CHK  = 0b10,
        STSEL_15_SBIT_15_CHK= 0b01,
        STSEL_1_SBIT_1_CHK  = 0b00,		

        C0EN_ENABLED        = 0b1,	// Enable Legacy Checksum (C0) Transmit and Receive bit
        C0EN_DISABLED       = 0b0,		

        UTXINV_ACTIVE_LOW   = 0b1,	// UART Transmit Polarity bit
        UTXINV_ACTIVE_HIGH  = 0b0,		

        FLO_RTS_CTS         = 0b10,	// Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
        FLO_XON_XOFF        = 0b01,
        FLO_NONE            = 0b00

    }REG_UxMODEH_FLAGS_e;

    typedef struct
    {
        volatile unsigned flo	:2;	// Bit #1-0: Flow Control Enable bits (only valid when MOD<3:0> = 0xxx)
        volatile unsigned utxinv:1;	// Bit #2: UART Transmit Polarity bit
        volatile unsigned c0en  :1; // Bit #3: Enable Legacy Checksum (C0) Transmit and Receive bit
        volatile unsigned stsel	:2;	// Bit #5-4: Number of Stop Bits Selection bits
        volatile unsigned urxinv:1;	// Bit #6: UART Receive Polarity bit
        volatile unsigned runovf:1;	// Bit #7: Run During Overflow Condition Mode bit
        volatile unsigned halfdplx:1;	// Bit #8: UART Half-Duplex Selection Mode bit
        volatile unsigned bclksel:2;	// Bit #10-9: Baud Clock Source Selection bits
        volatile REG_UxMODEH_BCLKMOD_FLAG_e bclkmod:1;	// Bit #11: Baud Clock Generation Mode Select bit
        volatile unsigned		:1;	// Bit #12: reserved
        volatile unsigned		:1;	// Bit #13: reserved
        volatile REG_UxMODEH_ACTIVE_FLAG_e active:1;	// Bit #14: UART Running Status bit
        volatile REG_UxMODEH_SLPEN_FLAG_e slpen :1;	// Bit #15: Run During Sleep Enable bit
    }__attribute__((packed))UxMODEH_CONTROL_REGISTER_BIT_FIELD_t;

    
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// UxSTA: UARTx STATUS AND CONTROL REGISTER
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // Full Register Bit Fields
    typedef enum
    {
        REG_TXMTIE_ENABLED      = 0b1000000000000000,   // Transmit Shifter Empty Interrupt Enable bit
        REG_TXMTIE_DISABLED     = 0b0000000000000000,

        REG_PERIE_ENABLED       = 0b0100000000000000,   // Parity Error Interrupt Enable bit
        REG_PERIE_DISABLED      = 0b0000000000000000,
            
        REG_ABDOVE_ENABLED      = 0b0010000000000000,   // Auto-Baud Rate Acquisition Interrupt Enable bit
        REG_ABDOVE_DISABLED     = 0b0000000000000000,

        REG_CERIE_ENABLED       = 0b0001000000000000,   // Checksum Error Interrupt Enable bit
        REG_CERIE_DISABLED      = 0b0000000000000000,

        REG_FERIE_ENABLED       = 0b0000100000000000,   // Framing Error Interrupt Enable bit
        REG_FERIE_DISABLED      = 0b0000000000000000,
            
        REG_RXBKIE_ENABLED      = 0b0000010000000000,   // Receive Break Interrupt Enable bit
        REG_RXBKIE_DISABLED     = 0b0000000000000000,
            
        REG_OERIE_ENABLED       = 0b0000001000000000,   // Receive Buffer Overflow Interrupt Enable bit
        REG_OERIE_DISABLED      = 0b0000000000000000,
            
        REG_TXCIE_ENABLED       = 0b0000000100000000,   // Transmit Collision Interrupt Enable bit
        REG_TXCIE_DISABLED      = 0b0000000000000000,

        REG_TRMT_EMPTY          = 0b0000000010000000,   // Transmit Shifter Empty Interrupt Flag bit (read-only)
        REG_TRMT_BUSY           = 0b0000000000000000,

        REG_PERR_ACTIVE         = 0b0000000001000000,   // Parity Error/Address Received/Forward Frame Interrupt Flag bit
        REG_PERR_NOT_ACTIVE     = 0b0000000000000000,

        REG_ABDOVF_ACTIVE       = 0b0000000000100000,   // Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
        REG_ABDOVF_NOT_ACTIVE   = 0b0000000000000000,

        REG_CERIF_ACTIVE        = 0b0000000000010000,   // Checksum Error Interrupt Flag bit (must be cleared by software)
        REG_CERIF_NOT_ACTIVE    = 0b0000000000000000,

        REG_FERR_ACTIVE         = 0b0000000000001000,   // Framing Error Interrupt Flag bit
        REG_FERR_NOT_ACTIVE     = 0b0000000000000000,
            
        REG_RXBKIF_ACTIVE       = 0b0000000000000100,   // Receive Break Interrupt Flag bit (must be cleared by software)
        REG_RXBKIF_NOT_ACTIVE   = 0b0000000000000000,

        REG_OERR_ACTIVE         = 0b0000000000000010,   // Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
        REG_OERR_NOT_ACTIVE     = 0b0000000000000000,

        REG_TXCIF_ACTIVE        = 0b0000000000000001,   // Transmit Collision Interrupt Flag bit (must be cleared by software)
        REG_TXCIF_NOT_ACTIVE    = 0b0000000000000000,

    }REG_UxSTA_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        TXMTIE_ENABLED      = 0b1,   // Transmit Shifter Empty Interrupt Enable bit
        TXMTIE_DISABLED     = 0b0,

        PERIE_ENABLED       = 0b1,   // Parity Error Interrupt Enable bit
        PERIE_DISABLED      = 0b0,
            
        ABDOVE_ENABLED      = 0b1,   // Auto-Baud Rate Acquisition Interrupt Enable bit
        ABDOVE_DISABLED     = 0b0,

        CERIE_ENABLED       = 0b1,   // Checksum Error Interrupt Enable bit
        CERIE_DISABLED      = 0b0,

        FERIE_ENABLED       = 0b1,   // Framing Error Interrupt Enable bit
        FERIE_DISABLED      = 0b0,
            
        RXBKIE_ENABLED      = 0b1,   // Receive Break Interrupt Enable bit
        RXBKIE_DISABLED     = 0b0,
            
        OERIE_ENABLED       = 0b1,   // Receive Buffer Overflow Interrupt Enable bit
        OERIE_DISABLED      = 0b0,
            
        TXCIE_ENABLED       = 0b1,   // Transmit Collision Interrupt Enable bit
        TXCIE_DISABLED      = 0b0,

        TRMT_EMPTY          = 0b1,   // Transmit Shifter Empty Interrupt Flag bit (read-only)
        TRMT_BUSY           = 0b0,

        PERR_ACTIVE         = 0b1,   // Parity Error/Address Received/Forward Frame Interrupt Flag bit
        PERR_NOT_ACTIVE     = 0b0,

        ABDOVF_ACTIVE       = 0b1,   // Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
        ABDOVF_NOT_ACTIVE   = 0b0,

        CERIF_ACTIVE        = 0b1,   // Checksum Error Interrupt Flag bit (must be cleared by software)
        CERIF_NOT_ACTIVE    = 0b0,

        FERR_ACTIVE         = 0b1,   // Framing Error Interrupt Flag bit
        FERR_NOT_ACTIVE     = 0b0,
            
        RXBKIF_ACTIVE       = 0b1,   // Receive Break Interrupt Flag bit (must be cleared by software)
        RXBKIF_NOT_ACTIVE   = 0b0,

        OERR_ACTIVE         = 0b1,   // Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
        OERR_NOT_ACTIVE     = 0b0,

        TXCIF_ACTIVE        = 0b1,   // Transmit Collision Interrupt Flag bit (must be cleared by software)
        TXCIF_NOT_ACTIVE    = 0b0,

    }REG_UxSTA_FLAGS_e;

    typedef struct
    {
        volatile unsigned txcif :1;	// Bit #0: Transmit Collision Interrupt Flag bit (must be cleared by software)
        volatile unsigned oerr	:1;	// Bit #1: Receive Buffer Overflow Interrupt Flag bit (must be cleared by software)
        volatile unsigned rxbkif:1;	// Bit #2: Receive Break Interrupt Flag bit (must be cleared by software)
        volatile unsigned ferr  :1;	// Bit #3: Framing Error Interrupt Flag bit
        volatile unsigned cerif	:1;	// Bit #4: Checksum Error Interrupt Flag bit (must be cleared by software)
        volatile unsigned abdovf:1;	// Bit #5: Auto-Baud Rate Acquisition Interrupt Flag bit (must be cleared by software)
        volatile unsigned perr  :1; // Bit #6: Parity Error/Address Received/Forward Frame Interrupt Flag bit
        volatile unsigned trmt	:1;	// Bit #7: Transmit Shift Register Empty bit (read-only)
        volatile unsigned txcie	:1;	// Bit #8: Transmit Collision Interrupt Enable bit
        volatile unsigned oerie	:1;	// Bit #9: Receive Buffer Overflow Interrupt Enable bit
        volatile unsigned rxbkie:1;	// Bit #10: Receive Break Interrupt Enable bit
        volatile unsigned ferie :1;	// Bit #11: Framing Error Interrupt Enable bit
        volatile unsigned cerie :1;	// Bit #12: Checksum Error Interrupt Enable bit
        volatile unsigned abdove:1;	// Bit #13: Auto-Baud Rate Acquisition Interrupt Enable bit
        volatile unsigned perie :1;	// Bit #14: Parity Error Interrupt Enable bit
        volatile unsigned txmtie:1;	// Bit #15: Transmit Shifter Empty Interrupt Enable bit
    }__attribute__((packed))UxSTA_CONTROL_REGISTER_BIT_FIELD_t;


        
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// UxSTAH: UARTx STATUS AND CONTROL REGISTER HIGH
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // Full Register Bit Fields
    typedef enum
    {
        REG_UTXISEL_1_OPEN       = 0b0111000000000000,   // UART Transmit Interrupt Select bits
        REG_UTXISEL_2_OPEN       = 0b0110000000000000,
        REG_UTXISEL_3_OPEN       = 0b0101000000000000,
        REG_UTXISEL_4_OPEN       = 0b0100000000000000,
        REG_UTXISEL_5_OPEN       = 0b0011000000000000,
        REG_UTXISEL_6_OPEN       = 0b0010000000000000,
        REG_UTXISEL_7_OPEN       = 0b0001000000000000,
        REG_UTXISEL_8_OPEN       = 0b0000000000000000,

        REG_URXISEL_1_WORD       = 0b0000011100000000,   // UART Receive Interrupt Select bits
        REG_URXISEL_2_WORD       = 0b0000011000000000,
        REG_URXISEL_3_WORD       = 0b0000010100000000,
        REG_URXISEL_4_WORD       = 0b0000010000000000,
        REG_URXISEL_5_WORD       = 0b0000001100000000,
        REG_URXISEL_6_WORD       = 0b0000001000000000,
        REG_URXISEL_7_WORD       = 0b0000000100000000,
        REG_URXISEL_8_WORD       = 0b0000000000000000,

        REG_TXWRE_OVERRUN        = 0b0000000010000000,  // TX Write Transmit Error Status bit
        REG_TXWRE_NONE           = 0b0000000000000000,
            
        REG_STPMD_IF_LAST_STOP   = 0b0000000001000000,  // Stop Bit Detection Mode bit
        REG_STPMD_IF_FIRST_STOP  = 0b0000000000000000,

        REG_UTXBE_EMPFY          = 0b0000000000100000,  // UART TX Buffer Empty Status bit
        REG_UTXBE_FULL           = 0b0000000000000000,

        REG_UTXBF_FULL           = 0b0000000000010000,  // UART TX Buffer Full Status bit
        REG_UTXBF_EMPFY          = 0b0000000000000000,

        REG_RIDLE_IDLE           = 0b0000000000001000,  // Receive Idle bit
        REG_RIDLE_BUSY           = 0b0000000000000000,
            
        REG_XON_ACTIVE           = 0b0000000000000100,  // UART in XON Mode bit
        REG_XON_NONE             = 0b0000000000000000,

        REG_URXBE_EMPTY          = 0b0000000000000010,  // UART RX Buffer Empty Status bit
        REG_URXBE_FULL           = 0b0000000000000000,
            
        REG_URXBF_FULL           = 0b0000000000000001,  // UART RX Buffer Full Status bit
        REG_URXBF_EMPTY          = 0b0000000000000000,

    }REG_UxSTAH_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        UTXISEL_1_OPEN       = 0b111,   // UART Transmit Interrupt Select bits
        UTXISEL_2_OPEN       = 0b110,
        UTXISEL_3_OPEN       = 0b101,
        UTXISEL_4_OPEN       = 0b100,
        UTXISEL_5_OPEN       = 0b011,
        UTXISEL_6_OPEN       = 0b010,
        UTXISEL_7_OPEN       = 0b001,
        UTXISEL_8_OPEN       = 0b000,

        URXISEL_1_WORD       = 0b111,   // UART Receive Interrupt Select bits
        URXISEL_2_WORD       = 0b110,
        URXISEL_3_WORD       = 0b101,
        URXISEL_4_WORD       = 0b100,
        URXISEL_5_WORD       = 0b011,
        URXISEL_6_WORD       = 0b010,
        URXISEL_7_WORD       = 0b001,
        URXISEL_8_WORD       = 0b000,

        TXWRE_OVERRUN        = 0b1,  // TX Write Transmit Error Status bit
        TXWRE_NONE           = 0b0,
            
        STPMD_IF_LAST_STOP   = 0b1,  // Stop Bit Detection Mode bit
        STPMD_IF_FIRST_STOP  = 0b0,

        UTXBE_EMPFY          = 0b1,  // UART TX Buffer Empty Status bit
        UTXBE_FULL           = 0b0,

        UTXBF_FULL           = 0b1,  // UART TX Buffer Full Status bit
        UTXBF_EMPFY          = 0b0,

        RIDLE_IDLE           = 0b1,  // Receive Idle bit
        RIDLE_BUSY           = 0b0,
            
        XON_ACTIVE           = 0b1,  // UART in XON Mode bit
        XON_NONE             = 0b0,

        URXBE_EMPTY          = 0b1,  // UART RX Buffer Empty Status bit
        URXBE_FULL           = 0b0,
            
        URXBF_FULL           = 0b1,  // UART RX Buffer Full Status bit
        URXBF_EMPTY          = 0b0,

    }REG_UxSTAH_FLAGS_e;

    typedef struct
    {
        volatile unsigned urxbf :1;	// Bit #0: UART RX Buffer Full Status bit
        volatile unsigned urxbe	:1;	// Bit #1: UART RX Buffer Empty Status bit
        volatile unsigned xon   :1;	// Bit #2: UART in XON Mode bit
        volatile unsigned ridle :1;	// Bit #3: Receive Idle bit
        volatile unsigned utxbf	:1;	// Bit #4: UART TX Buffer Full Status bit
        volatile unsigned utxbe :1;	// Bit #5: UART TX Buffer Empty Status bit
        volatile unsigned stpmd :1; // Bit #6: Stop Bit Detection Mode bit
        volatile unsigned txwre	:1;	// Bit #7: TX Write Transmit Error Status bit
        volatile unsigned urxisel:3;	// Bit #10-8: UART Receive Interrupt Select bits
        volatile unsigned 	    :1;	// Bit #11: reserved
        volatile unsigned utxisel:3;	// Bit #14-12: UART Transmit Interrupt Select bits
        volatile unsigned       :1;	// Bit #15: reserved
    }__attribute__((packed))UxSTAH_CONTROL_REGISTER_BIT_FIELD_t;
    
    
#else
    #pragma message "Gap in device support detected. Please review UART driver file."
#endif

typedef union 
{
	volatile REG_UxMODE_BIT_FIELD_e value;
	volatile UxMODE_CONTROL_REGISTER_BIT_FIELD_t bits;
}UxMODE_CONTROL_REGISTER_t;

#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)
typedef union 
{
	volatile REG_UxMODEH_BIT_FIELD_e value;
	volatile UxMODEH_CONTROL_REGISTER_BIT_FIELD_t bits;
}UxMODEH_CONTROL_REGISTER_t;
#endif

typedef union 
{
	volatile REG_UxSTA_BIT_FIELD_e value;
	volatile UxSTA_CONTROL_REGISTER_BIT_FIELD_t bits;
}UxSTA_CONTROL_REGISTER_t;

#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)
typedef union 
{
	volatile REG_UxSTAH_BIT_FIELD_e value;
	volatile UxSTAH_CONTROL_REGISTER_BIT_FIELD_t bits;
}UxSTAH_CONTROL_REGISTER_t;
#endif

// Prototypes

extern volatile uint32_t smps_uart_get_baudrate(uint16_t uart_instance, uint32_t baudrate);
extern volatile uint16_t smps_uart_init(uint16_t uart_instance, UxMODE_CONTROL_REGISTER_t regUxMODE, UxSTA_CONTROL_REGISTER_t regUxSTA);
extern volatile uint8_t  smps_uart_read(volatile uint16_t uart_instance);
extern volatile uint16_t smps_uart_write(uint16_t uart_instance, uint8_t txData);
extern volatile uint16_t smps_uart_get_status(volatile uint16_t uart_instance);

extern volatile uint16_t smps_uart_enable(uint16_t uart_instance);
extern volatile uint16_t smps_uart_disable(uint16_t uart_instance);
extern volatile uint16_t smps_uart_dispose(uint16_t uart_instance);

extern volatile uint16_t smps_uart_power_on(uint16_t uart_instance);
extern volatile uint16_t smps_uart_power_off(uint16_t uart_instance);

extern volatile uint16_t smps_uart_open_port(uint16_t uart_instance, 
    UART_BAUDRATE_SETTING_e baud, UART_DATA_BIT_SETTING_e data_bits, UART_PARITY_SETTING_e parity, UART_STOP_BIT_SETTING_e stop_bits, 
    UART_ISR_PRIORITY_e isr_priority);


#endif  /* _MCAL_P33_SMPS_UART_H_ */
// End of File
