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
/*@@p33SMPS_uart.c
 * ***************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxMP UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 *
 * File:   p33SMPS_uart.c
 * Author: M91406
 *
 * Created on October 26, 2017, 1:10 PM
 * 
 * Revision:
 * 17/10/26		initial version
 * 19/07/23		added baudrate calculation
 * 
 * ***************************************************************************/

// Device header file
#include <xc.h>
#include <stdint.h>

#include "../../p33SMPS_plib.h"
#include "p33SMPS_uart.h"

#define SMPS_UART_IO_TIMEOUT   5000    // wait for n while cycles before terminating poll-attempt

/*@@p33MP_uart.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxMP UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 * ***********************************************************************************************/


/*@@smps_uart_init
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *	regUxMODE     = Basic UART unit configuration
 *	regUxSTA      = Enhanced UART unit configuration and status bits
 *
 * Description:
 * This routine is setting the uart configuration. This routine needs to be called before a UART
 * port is opened to ensure the baudrate settings and hardware flow control is applied properly.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_init(uint16_t uart_instance, UxMODE_CONTROL_REGISTER_t regUxMODE, UxSTA_CONTROL_REGISTER_t regUxSTA)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;

    if (!(smps_uart_power_on(uart_instance))) return(0); // Make sure power to peripheral is turned on
	if (uart_instance > UART_UART_COUNT) return(0);
    
	reg_offset = ((uart_instance-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    *regptr = (((uint16_t)regUxMODE.value & UART_UxMODE_REG_WRITE_MASK) & UART_UxMODE_REG_OFF_MASK);	// UART ENABLE is masked out !!!
    
    regptr  = (volatile uint16_t *)&U1STA;
    *regptr = ((uint16_t)regUxSTA.value & UART_UxSTA_REG_WRITE_MASK);	// may reset all status bits

    return(1);
}

/*@@smps_uart_open_port
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *	baud          = baudrate of the selected UART unit
 *	data_bits     = number of data bits of the selected UART unit
 *	parity        = parity setting of the selected UART unit
 *	stop_bits     = number of stop bits of the selected UART unit
 * isr_priority   = interrupt service routine priority of this UART unit
 *
 * Description:
 * This routine is setting the timer pre-scaler in accordance to apply the
 * desired period using a 16-bit time base. Therefore the 16bit mode is enforced
 * and any pre-scaler settings will be ignored. The timer will remain disabled after
 * initialization and has to be enabled by the user.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_open_port(uint16_t uart_instance, 
    UART_BAUDRATE_SETTING_e baud, UART_DATA_BIT_SETTING_e data_bits, UART_PARITY_SETTING_e parity, UART_STOP_BIT_SETTING_e stop_bits, 
    UART_ISR_PRIORITY_e isr_priority)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
    volatile uint32_t brg_buf=0;

    if (!(smps_uart_power_on(uart_instance))) return(0); // Make sure power to peripheral is turned on
	if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid
    
    // Determine SFR offset depending on given index
	reg_offset = ((uart_instance - 1) * (volatile uint16_t)UART_INDEX_REG_OFFSET);

    // Set data bits and parity
    if((data_bits == UART_DATA_BITS_7) && (parity == UART_PARITY_NONE))
    { reg_buf |= REG_MOD_ASYNC_7B_NONE; }
    
    else if((data_bits == UART_DATA_BITS_8) && (parity == UART_PARITY_NONE)) 
    { reg_buf |= REG_MOD_ASYNC_8B_NONE; }

    else if((data_bits == UART_DATA_BITS_8) && (parity == UART_PARITY_ODD)) 
    { reg_buf |= REG_MOD_ASYNC_8B_ODD; }
    
    else if((data_bits == UART_DATA_BITS_8) && (parity == UART_PARITY_EVEN)) 
    { reg_buf |= REG_MOD_ASYNC_8B_EVEN; }
    
    else if((data_bits == UART_DATA_BITS_9) && (parity == UART_PARITY_NONE))
    { reg_buf |= REG_MOD_ASYNC_9B_NONE; }

    else    // invalid setting
    { return(0); }        
    
    // set stop-bits
    switch(stop_bits)
    {
        case UART_STOP_BITS_1:
            reg_buf |= REG_STSEL_1_SBIT_1_CHK;
            break;
            
        case UART_STOP_BITS_15:
            reg_buf |= REG_STSEL_15_SBIT_15_CHK;
            break;

        case UART_STOP_BITS_2:
            reg_buf |= REG_STSEL_2_SBIT_2_CHK;
            break;

        default:    // invalid setting
            return(0);
            break;
    }        
    
    // =======================================
    // Calculate the baud rate 
//    brg_buf = UART_UxBRGL(baud);  // replaced by runtime calculation
    // ToDo: select fractional or legacy mode with 4x or 16x multiplier depending on baud rate value
    brg_buf = smps_uart_get_baudrate(uart_instance, baud);
    
    // ========================================
    
    if(brg_buf < 0xFFFF) { 
        reg_buf |= REG_BRGH_DEFAULT; 
    }
    else { 
//        brg_buf = UART_UxBRGH(baud);
        reg_buf |= REG_BRGH_HIGH_SPEED; 
    }

    // Set up interrupt
    switch(uart_instance)
    {
        case 1:
            _U1RXIF = 0;
            _U1RXIP = isr_priority;
            if(isr_priority > 0) {_U1RXIE = 1; }
            else {_U1RXIE = 0; }
/*
            _U1TXIF = 0;
            _U1TXIP = isr_priority;
            if(isr_priority > 0) {_U1TXIE = 1; }
            else {_U1TXIE = 0; }

            _U1EIF = 0;
            _U1EIP = isr_priority;
            if(isr_priority > 0) {_U1EIE = 0; }
            else {_U1EIE = 0; }
*/
            break;

        #if defined (U2MODE)
        case 2:
            _U2RXIF = 0;
            _U2RXIP = isr_priority;
            if(isr_priority > 0) {_U2RXIE = 1; }
            else {_U2RXIE = 0; }
/*
            _U2TXIF = 0;
            _U2TXIP = isr_priority;
            if(isr_priority > 0) {_U2TXIE = 0; }
            else {_U2TXIE = 0; }

            _U2EIF = 0;
            _U2EIP = isr_priority;
            if(isr_priority > 0) {_U2EIE = 0; }
            else {_U2EIE = 0; }
*/           
            break;
        #endif
            
        #if defined (U3MODE)
        case 3:
            _U3RXIF = 0;
            _U3RXIP = isr_priority;
            if(isr_priority > 0) {_U3RXIE = 1; }
            else {_U3RXIE = 0; }
/*
            _U3TXIF = 0;
            _U3TXIP = isr_priority;
            if(isr_priority > 0) {_U3TXIE = 0; }
            else {_U3TXIE = 0; }

            _U3EIF = 0;
            _U3EIP = isr_priority;
            if(isr_priority > 0) {_U3EIE = 0; }
            else {_U3EIE = 0; }
*/            
            break;
        #endif

        #if defined (U4MODE)
        case 4:
            _U4RXIF = 0;
            _U4RXIP = isr_priority;
            if(isr_priority > 0) {_U4RXIE = 1; }
            else {_U4RXIE = 0; }
/*
            _U4TXIF = 0;
            _U4TXIP = isr_priority;
            if(isr_priority > 0) {_U4TXIE = 0; }
            else {_U4TXIE = 0; }

            _U4EIF = 0;
            _U4EIP = isr_priority;
            if(isr_priority > 0) {_U4EIE = 0; }
            else {_U4EIE = 0; }
*/            
            break;
        #endif
            
        default:
            break;
    }
    
    // Set the baud rate register
    regptr  = (volatile uint16_t *)&U1BRG + reg_offset;
    *regptr = ((volatile uint16_t)brg_buf & UART_UxBRG_REG_WRITE_MASK);	
    regptr  = (volatile uint16_t *)&U1BRGH + reg_offset;
    *regptr = ((volatile uint16_t)((brg_buf >> 16) & UART_UxBRGH_REG_WRITE_MASK));	
    
    // Set basic configuration
    regptr  = (volatile uint16_t *)&U1MODE + reg_offset;
    *regptr = ((reg_buf & UART_UxMODE_REG_WRITE_MASK) | REG_UARTEN_ENABLED);	// UART ENABLE is on

    // set status register to enable transmit buffer
    regptr  = (volatile uint16_t *)&U1STA + reg_offset;
    *regptr = ((reg_buf & UART_UxSTA_REG_WRITE_MASK) | REG_UTXEN_ENABLED);	// UART TX ENABLE is on
    
	return(1);

}

/*@@smps_uart_read
 * ************************************************************************************************
 * Summary:
 * Reads one byte from the input buffer 
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *
 * Description:
 * This routine is reading one byte from the selected UART receive buffer
 * ***********************************************************************************************/

inline volatile uint8_t smps_uart_read(volatile uint16_t uart_instance)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
    volatile uint16_t timeout=0;

    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Determine SFR offset depending on given index
	reg_offset = ((uart_instance - 1) * (volatile uint16_t)UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1STA + reg_offset;
    reg_buf = (*regptr & UART_UxSTA_REG_READ_MASK);
    
    while((!(reg_buf & REG_URXBF_FULL)) && (timeout++ < SMPS_UART_IO_TIMEOUT));
    if((timeout < SMPS_UART_IO_TIMEOUT)) 
    {
        regptr  = (volatile uint16_t *)&U1RXREG + reg_offset;
        reg_buf = *regptr;
        return (reg_buf);   // return byte received
    }
    else
    { return(0); }
}

/*@@smps_uart_write
 * ************************************************************************************************
 * Summary:
 * Writes one byte to the output buffer 
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *  txData        = data byte to send
 *
 * Description:
 * This routine is writing one byte to the selected UART transmit buffer
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_write(uint16_t uart_instance, uint8_t txData)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
    volatile uint16_t timeout=0;

    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Determine SFR offset depending on given index
	reg_offset = ((uart_instance - 1) * (volatile uint16_t)UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1STA + reg_offset;
    reg_buf = (*regptr & UART_UxSTA_REG_READ_MASK);
    
    // wait until buffer is clear
    while((reg_buf & REG_UTXBF_FULL) && (timeout++ < SMPS_UART_IO_TIMEOUT));
    if(timeout < SMPS_UART_IO_TIMEOUT) 
    { 
        regptr  = (volatile uint16_t *)&U1TXREG + reg_offset;
        *regptr = txData;    // Write the data byte to the USART.
        return(1);
    }
    else
    { return(0); }
}


/*@@smps_uart_get_status
 * ************************************************************************************************
 * Summary:
 * Reads the status of the given UART unit
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *
 * Description:
 * This routine is reading the status information form the status register of the selected UART 
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_get_status(volatile uint16_t uart_instance)
{
    
    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;

    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Determine SFR offset depending on given index
	reg_offset = ((uart_instance - 1) * (volatile uint16_t)UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1STA + reg_offset;
    reg_buf = (*regptr & UART_UxSTA_REG_READ_MASK);
    
    //    if (reg_buf & REG_OERR_DETECTED)
    //    {
    //        reg_buf &= REG_OERR_RESET;
    //        *regptr = ((volatile uint16_t)reg_buf & UART_UxSTA_REG_RESET_WRITE_MASK);
    //    }

    return(reg_buf);
}

/*@@smps_uart_enable
 * ************************************************************************************************
 * Summary:
 * Enables a specific, pre-configured UART unit 
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *
 * Description:
 * This routine is enabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_enable(uint16_t uart_instance)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
	
    if (!(smps_uart_power_on(uart_instance))) return(0); // Make sure power to peripheral is turned on
	if (uart_instance > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((uart_instance-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    reg_buf = (*regptr | REG_UARTEN_ENABLED);
    *regptr = (reg_buf & UART_UxMODE_REG_WRITE_MASK);	

	return(1);

}

/*@@smps_uart_disable
 * ************************************************************************************************
 * Summary:
 * Disables a specific, pre-configured UART unit 
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *
 * Description:
 * This routine is disabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_disable(uint16_t uart_instance)
{

    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0, reg_buf=0;
	
	if (uart_instance > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((uart_instance-1) * UART_INDEX_REG_OFFSET);

    regptr  = (volatile uint16_t *)&U1MODE;
    reg_buf = (*regptr & UART_UxMODE_REG_OFF_MASK);
    *regptr = (reg_buf & UART_UxMODE_REG_WRITE_MASK);	

	return(1);

}


/*@@smps_uart_dispose
 * ************************************************************************************************
 * Summary:
 * Resets a specific UART unit 
 *
 * Parameters:
 *	uart_instance = selects the register address range of the target UART unit
 *
 * Description:
 * This routine is disabling the selected UART and resets its entire configuration.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_dispose(uint16_t uart_instance)
{
	
    volatile uint16_t *regptr;
    volatile uint16_t reg_offset=0;
	
	if (uart_instance > UART_UART_COUNT) return(0); // Skip if index is out of range

	reg_offset = ((uart_instance-1) * UART_INDEX_REG_OFFSET);
	
    regptr  = (volatile uint16_t *)&U1MODE;
    *regptr = UART_UxMODE_REG_DISPOSE_MASK;
    
    regptr  = (volatile uint16_t *)&U1STA;
    *regptr = UART_UxSTA_REG_DISPOSE_MASK;	
    
    smps_uart_power_off(uart_instance);
    
	return(1);

}

/*@@smps_uart_power_on
 * ************************************************************************************************
 * Summary:
 * Turns on the power to a given UART unit 
 *
 * Parameters:
 *	uart_instance = selects the PMD register-bit of the target UART unit
 *
 * Description:
 * This routine is enabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_power_on(uint16_t uart_instance)
{

	if (uart_instance > UART_UART_COUNT) return(0); // Skip if index is out of range

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 1; 
    #endif

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(uart_instance == 1) { _U1MD = 0; }
    #endif
    #ifdef _U2MD
        if(uart_instance == 2) { _U2MD = 0; }
    #endif
    #ifdef _U3MD
        if(uart_instance == 3) { _U3MD = 0; }
    #endif
    #ifdef _U4MD
        if(index == 4) { _U4MD = 0; }
    #endif

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 0; 
    #endif
    
	return(1);

}


/*@@smps_uart_power_off
 * ************************************************************************************************
 * Summary:
 * Turns off the power to a given UART unit 
 *
 * Parameters:
 *	uart_instance = selects the PMD register-bit of the target UART unit
 *
 * Description:
 * This routine is disabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

inline volatile uint16_t smps_uart_power_off(uint16_t uart_instance)
{

	if (uart_instance > UART_UART_COUNT) return(0); // Skip if index is out of range

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 1; 
    #endif

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(uart_instance == 1) { _U1MD = 1; }
    #endif
    #ifdef _U2MD
        if(uart_instance == 2) { _U2MD = 1; }
    #endif
    #ifdef _U3MD
        if(uart_instance == 3) { _U3MD = 1; }
    #endif
    #ifdef _U4MD
        if(index == 4) { _U4MD = 1; }
    #endif

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 0; 
    #endif
    
	return(1);

}

/*@@smps_uart_get_baudrate
 * ************************************************************************************************
 * Summary:
 * Calculates the SFR register value required to achieve the given baud rate
 *
 * Parameters:
 *	uint16_t uart_instance = selects the index of the UART peripheral to use
 *  uint32_t baud = user given baud rate (e.g. 9600)
 *
 * Description:
 * This routine reads the most recent oscillator and UART configuration and 
 * calculates the SFR value to program the selected UART peripheral for 
 * a certain, user defined baud rate.
 * 
 * This routine only calculates the required SFR value but does not program it into the target
 * peripheral. Please use function smps_uart_open_port(...) to apply the new baud rate setting.
 * 
 * Please note:
 * When the system clock or main oscillator settings are changed, this routine has to be
 * called again to adjust the baud rate for the new clock source frequency.
 * ************************************************************************************************/
volatile uint32_t smps_uart_get_baudrate(uint16_t uart_instance, uint32_t baud) {
    
    volatile uint16_t* regptr;
    volatile uint16_t reg_offset = 0;
    volatile uint16_t reg_buf = 0;
    volatile uint32_t baudclk = 0;
    
    // Determine register address offset based on UART instance
    reg_offset = (uart_instance - 1) * ((volatile uint16_t*)&U2MODE - (volatile uint16_t*)&U1MODE);
    
    // Get register bank address offset
    regptr = (volatile uint16_t*)&U1MODEH + reg_offset;
    reg_buf = *regptr;
    
    // Get frequency based on input clock selection setting
    baudclk = ((reg_buf & 0x0600) >> 9); 
    switch (baudclk) {
        case 0b00:  // FOSC/2 (= peripheral clock)
            baudclk = system_frequencies.fp; 
            break;
        case 0b01:  // (reserved) => invalid
            return(0); 
            break;
        case 0b10:  // FOSC (= CPU clock)
            baudclk = system_frequencies.fosc; 
            break;
        case 0b11:  // AFVCO/3 (=auxiliary PLL output divided by 3)
            baudclk = (volatile uint32_t)((float)system_frequencies.fvco / 3.0);
            break;
    }
    
    if(reg_buf & 0x0800) { // Baud Clock Generation Mode Selection (bit 11)
    // When in fractional baud rate generation mode, the BRG register setting
    // is calculated by [f_source] / [BAUDRATE]
        
        baudclk = (volatile uint32_t)((float)baudclk / (float)baud);
        
    }
    else {
    // When in legacy divide-by-x counter baud rate generation mode
        
        regptr = (volatile uint16_t*)&U1MODE + reg_offset;
        reg_buf = *regptr;

        if (reg_buf & 0x0080) {   // Filter on BRGH bit
        // High Speed: Baud rate is baudclk/4
            
            baudclk = (volatile uint32_t)((float)baudclk / (4.0 * (float)baud));

        }
        else {
        // Low Speed: Baud rate is baudclk/16

            baudclk = (volatile uint32_t)((float)baudclk / (16.0 * (float)baud));
            
        }
    
    }

    // Return calculation result
    return((volatile uint32_t)baudclk);
    
}



// EOF
