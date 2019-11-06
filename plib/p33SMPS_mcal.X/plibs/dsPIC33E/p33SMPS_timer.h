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
/*@@p33MP_timer.h
 * ***************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxGS Timer SFRs
 *
 * Description:
 * The timer module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 *
 * File:   p33SMPS_timer.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

#ifndef MCAL_P33_SMPS_TIMER_H
#define MCAL_P33_SMPS_TIMER_H

#include <stdint.h>
#include "p33SMPS_devices.h"

/*@@p33FGS_timer.h
 * ************************************************************************************************
 * Summary:
 * Header file with additional defines for the dsPIC33FxxGS timer SFRs
 *
 * Description:
 * The timer module offers a number of registers and configuration options. This additional
 * header file contains defines for all required settings.
 * ***********************************************************************************************/

// Device specific properties
#if   defined (__P33SMPS_FJA__) 
	#define GSTMR_TIMER_COUNT	2
#elif defined (__P33SMPS_FJ__)
	#define GSTMR_TIMER_COUNT	3
#elif defined (__P33SMPS_FJC__)
	#define GSTMR_TIMER_COUNT	5
#elif defined (__P33SMPS_EP2__)
	#define GSTMR_TIMER_COUNT	3
#elif defined (__P33SMPS_EP5__) || defined (__P33SMPS_EP7__)
	#define GSTMR_TIMER_COUNT	5
#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)
	#define GSTMR_TIMER_COUNT	1

#else
	#error === selected device not supported ===
#endif

#if defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJC__) || defined (_P33SMPS_UAEG_) || \
    defined (__P33SMPS_EP__) 

    #define TIMER1_TCON_REG_WRITE_MASK		0xA076
    #define TIMER2_4_TCON_REG_WRITE_MASK	0xA07A
    #define TIMERx_TCON_REG_WRITE_MASK		0xA072

    #define TIMER1_TCON_REG_READ_MASK		0xA076
    #define TIMER2_4_TCON_REG_READ_MASK     0xA07A
    #define TIMERx_TCON_REG_READ_MASK		0xA072


#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    // Bit masks for register read and write operations
    #define TIMER1_TCON_REG_WRITE_MASK    0b1011001110110110
    #define TIMER1_TCON_REG_READ_MASK     0b1011111110110110

    #define TIMER2_4_TCON_REG_WRITE_MASK  0b1011001100110010
    #define TIMER2_4_TCON_REG_READ_MASK   0b1011111100110010

    #define TIMERx_TCON_REG_WRITE_MASK    0b1011001100110010
    #define TIMERx_TCON_REG_READ_MASK     0b1011111100110010
    
#endif

// Interrupt Flag-Bits & Priorities
#if ( GSTMR_TIMER_COUNT >=	1 )
  #define TIMER1_ISR_FLAG		IFS0bits.T1IF	// Timer1 interrupt flag
  #define TIMER1_ISR_PRIORITY	IPC0bits.T1IP	// Timer1 interrupt priority
  #define TIMER1_ISR_ENABLE		IEC0bits.T1IE	// Timer1 interrupt service routine enable
#endif
#if ( GSTMR_TIMER_COUNT >=	2 )
  #define TIMER2_ISR_FLAG		IFS0bits.T2IF	// Timer2 interrupt flag
  #define TIMER2_ISR_PRIORITY	IPC1bits.T2IP	// Timer2 interrupt priority
  #define TIMER2_ISR_ENABLE		IEC0bits.T2IE	// Timer2 interrupt service routine enable
#endif
#if ( GSTMR_TIMER_COUNT >=	3 )
  #define TIMER3_ISR_FLAG		IFS0bits.T3IF	// Timer3 interrupt flag
  #define TIMER3_ISR_PRIORITY	IPC2bits.T3IP	// Timer3 interrupt priority
  #define TIMER3_ISR_ENABLE		IEC0bits.T3IE	// Timer3 interrupt service routine enable
#endif
#if ( GSTMR_TIMER_COUNT >=	4 )
  #define TIMER4_ISR_FLAG		IFS1bits.T4IF	// Timer4 interrupt flag
  #define TIMER4_ISR_PRIORITY	IPC6bits.T4IP	// Timer4 interrupt priority
  #define TIMER4_ISR_ENABLE		IEC1bits.T4IE	// Timer4 interrupt service routine enable
#endif
#if ( GSTMR_TIMER_COUNT >=	5 )
  #define TIMER5_ISR_FLAG		IFS1bits.T5IF	// Timer5 interrupt flag
  #define TIMER5_ISR_PRIORITY	IPC7bits.T5IP	// Timer5 interrupt priority
  #define TIMER5_ISR_ENABLE		IEC1bits.T5IE	// Timer5 interrupt service routine enable
#endif

typedef enum
{
  TIMER_ISR_PRIORITY_0 = 0, // Timer interrupt service routine priority level #0 (main loop))
  TIMER_ISR_PRIORITY_1 = 1, // Timer interrupt service routine priority level #1
  TIMER_ISR_PRIORITY_2 = 2, // Timer interrupt service routine priority level #2
  TIMER_ISR_PRIORITY_3 = 3, // Timer interrupt service routine priority level #3
  TIMER_ISR_PRIORITY_4 = 4, // Timer interrupt service routine priority level #4
  TIMER_ISR_PRIORITY_5 = 5, // Timer interrupt service routine priority level #5
  TIMER_ISR_PRIORITY_6 = 6, // Timer interrupt service routine priority level #6
  TIMER_ISR_PRIORITY_7 = 7  // Timer interrupt service routine priority level #7
}TIMER_ISR_PRIORITY_e;

typedef enum
{
  TIMER_ISR_DISABLED = 0,   // Disable Timer interrupt service routine
  TIMER_ISR_ENABLED  = 1   // Enable Timer interrupt service routine
}TIMER_ISR_ENABLE_STATE_e;

// Generic Defines

typedef enum
{
    TIMER_ENABLED_ON  = 1,
    TIMER_ENABLED_OFF = 0
}TIMER_ENABLED_STATE_e;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  TxCON - Register Flags
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#if defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (_P33SMPS_FJC_) || \
    defined (__P33SMPS_EP__)

    // Full Register Bit Fields
    typedef enum
    {
        REG_TON_ON			= 0b1000000000000000,
        REG_TON_OFF			= 0b0000000000000000,

        REG_TSIDL_ON		= 0b0000000000000000,
        REG_TSIDL_OFF		= 0b0010000000000000,

        REG_TGATE_ON		= 0b0000000001000000,
        REG_TGATE_OFF		= 0b0000000000000000,

        REG_TCKPS_1_to_1	= 0b0000000000000000,
        REG_TCKPS_1_to_8	= 0b0000000000010000,
        REG_TCKPS_1_to_64	= 0b0000000000100000,
        REG_TCKPS_1_to_256	= 0b0000000000110000,

        REG_T32_32BIT		= 0b0000000000001000,		// Timer 2 and 4 only
        REG_T32_16BIT		= 0b0000000000000000,		// Timer 2 and 4 only

        REG_TSYNC_EXTERNAL	= 0b0000000000000100,		// Timer 1 only
        REG_TSYNC_NONE		= 0b0000000000000000,		// Timer 1 only

        REG_TCS_EXTERNAL	= 0b0000000000000010,
        REG_TCS_INTERNAL	= 0b0000000000000000
    }REG_TxCON_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        TON_ENABLED		= 0b1,
        TON_DISABLED	= 0b0,

        TSIDL_CONTINUE	= 0b0,
        TSIDL_STOP		= 0b1,

        TGATE_ENABLED	= 0b1,
        TGATE_DISABLED	= 0b0,

        TCKPS_DIV_1_to_1	= 0b00,
        TCKPS_DIV_1_to_8	= 0b01,
        TCKPS_DIV_1_to_64	= 0b10,
        TCKPS_DIV_1_to_256	= 0b11,

        T32_32BIT		= 0b1,		// Timer 2 and 4 only
        T32_16BIT		= 0b0,		// Timer 2 and 4 only

        TSYNC_EXTERNAL	= 0b1,		// Timer 1 only
        TSYNC_NONE		= 0b0,		// Timer 1 only

        TCS_EXTERNAL	= 0b1,
        TCS_INTERNAL	= 0b0
    }REG_TxCON_FLAGS_e;

    typedef struct
    {
        volatile unsigned		:1;	// Bit #0: reserved
        volatile unsigned tcs	:1;	// Bit #1: Timer X Clock Source Select bit
        volatile unsigned tsync	:1;	// Bit #2: Timer1 External Clock Input Synchronization Select bit
        volatile unsigned t32	:1;	// Bit #3: 32-Bit Timer X Mode Select bit on Timer 2 and Timer 4 only
        volatile unsigned tckps	:2;	// Bit #4/5: Timer X Input Clock Pre-Scale Select bits
        volatile unsigned tgate	:1;	// Bit #6: Timer X Gated Time Accumulation Enable bit
        volatile unsigned		:1;	// Bit #7: reserved
        volatile unsigned		:1;	// Bit #8: reserved
        volatile unsigned		:1;	// Bit #9:  reserved
        volatile unsigned		:1;	// Bit #10: reserved
        volatile unsigned		:1;	// Bit #11: reserved
        volatile unsigned		:1;	// Bit #12: reserved
        volatile unsigned tsidl :1;	// Bit #13: Timer X Stop in Idle Mode bit
        volatile unsigned		:1;	// Bit #14: reserved
        volatile unsigned ton   :1;	// Bit #15: Timer X On bit
    }__attribute__((packed))TxCON_CONTROL_REGISTER_BIT_FIELD_t;

#elif defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    // Full Register Bit Fields
    typedef enum
    {
        REG_TON_ON			= 0b1000000000000000,
        REG_TON_OFF			= 0b0000000000000000,

        REG_TSIDL_ON		= 0b0000000000000000,
        REG_TSIDL_OFF		= 0b0010000000000000,

        REG_TMWDIS_DISABLED = 0b0001000000000000,
        REG_TMWDIS_ENABLED  = 0b0000000000000000,

        REG_TMWIP_PENDING   = 0b0000100000000000,
        REG_TMWIP_COMPLETE  = 0b0000000000000000,

        REG_PRWIP_PENDING   = 0b0000010000000000,
        REG_PRWIP_COMPLETE  = 0b0000000000000000,

        REG_TECS_FRC        = 0b0000001100000000,
        REG_TECS_2_TCY      = 0b0000001000000000, 
        REG_TECS_TCY        = 0b0000000100000000,
        REG_TECS_TxCK       = 0b0000000000000000,
            
        REG_TGATE_ON		= 0b0000000010000000,
        REG_TGATE_OFF		= 0b0000000000000000,

        REG_TCKPS_1_to_1	= 0b0000000000000000,
        REG_TCKPS_1_to_8	= 0b0000000000010000,
        REG_TCKPS_1_to_64	= 0b0000000000100000,
        REG_TCKPS_1_to_256	= 0b0000000000110000,

        REG_TSYNC_EXTERNAL	= 0b0000000000000100,		// Timer 1 only
        REG_TSYNC_NONE		= 0b0000000000000000,		// Timer 1 only

        REG_TCS_EXTERNAL	= 0b0000000000000010,
        REG_TCS_INTERNAL	= 0b0000000000000000
    }REG_TxCON_BIT_FIELD_e;

    // Single Register Bit Fields
    typedef enum
    {
        TON_ENABLED		= 0b1,
        TON_DISABLED	= 0b0,

        TSIDL_CONTINUE	= 0b0,
        TSIDL_STOP		= 0b1,

        TMWDIS_DISABLED = 0b1,
        TMWDIS_ENABLED  = 0b0,

        TMWIP_PENDING   = 0b1,
        TMWIP_COMPLETE  = 0b0,

        PRWIP_PENDING   = 0b1,
        PRWIP_COMPLETE  = 0b0,

        TECS_FRC        = 0b11,
        TECS_2_TCY      = 0b10, 
        TECS_TCY        = 0b01,
        TECS_TxCK       = 0b00,
            
        TGATE_ENABLED	= 0b1,
        TGATE_DISABLED	= 0b0,

        TCKPS_DIV_1_to_1	= 0b00,
        TCKPS_DIV_1_to_8	= 0b01,
        TCKPS_DIV_1_to_64	= 0b10,
        TCKPS_DIV_1_to_256	= 0b11,

        TSYNC_EXTERNAL	= 0b1,		// Timer 1 only
        TSYNC_NONE		= 0b0,		// Timer 1 only

        TCS_EXTERNAL	= 0b1,
        TCS_INTERNAL	= 0b0
    }REG_TxCON_FLAGS_e;

    typedef struct
    {
        volatile unsigned		 :1;	// Bit #0: reserved
        volatile unsigned tcs	 :1;	// Bit #1: Timer X Clock Source Select bit
        volatile unsigned tsync	 :1;	// Bit #2: Timer X External Clock Input Synchronization Select bit
        volatile unsigned    	 :1;	// Bit #3: reserved
        volatile unsigned tckps	 :2;	// Bit #4/5: Timer X Input Clock Pre-Scale Select bits
        volatile unsigned		 :1;	// Bit #6: reserved
        volatile unsigned tgate	 :1;	// Bit #7: Timer X Gated Time Accumulation Enable bit
        volatile unsigned tecs   :2;	// Bit #8/9: Timer X Extended Clock Select bits
        volatile unsigned prwip  :1;	// Bit #10: Asynchronous Period Write in Progress bit
        volatile unsigned tmwip  :1;	// Bit #11: Asynchronous Timer X Write in Progress bit
        volatile unsigned tmwdis :1;	// Bit #12: Asynchronous Timer X Write Disable bit
        volatile unsigned tsidl  :1;	// Bit #13: Timer X Stop in Idle Mode bit
        volatile unsigned		 :1;	// Bit #14: reserved
        volatile unsigned ton    :1;	// Bit #15: Timer X On bit
    }__attribute__((packed))TxCON_CONTROL_REGISTER_BIT_FIELD_t;

#else
    #error === selected device not supported by peripheral driver libraries ===
#endif

typedef union 
{
	volatile REG_TxCON_BIT_FIELD_e reg_block;
	volatile TxCON_CONTROL_REGISTER_BIT_FIELD_t flags;
}TxCON_CONTROL_REGISTER_t;


// Prototypes

extern uint16_t gstmr_init_timer16b(uint16_t index, TxCON_CONTROL_REGISTER_t regTCON, uint32_t period, TIMER_ISR_PRIORITY_e isr_priority);
extern uint16_t gstmr_get_tmr_config(uint16_t index, TxCON_CONTROL_REGISTER_t *regTCON, uint32_t period, TIMER_ISR_PRIORITY_e *isr_priority);
extern uint16_t gstmr_enable(uint16_t index, TIMER_ISR_ENABLE_STATE_e isr_enable);
extern uint16_t gstmr_disable(uint16_t index);
extern uint16_t gstmr_reset(uint16_t index);



#endif  /* MCAL_P33_SMPS_TIMER_H */
// End of File
