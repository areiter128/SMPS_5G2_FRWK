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
 * Driver file for the dsPIC33CxxMPxxx UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. 
 * This additional driver file contains initialization routines for all 
 * required settings.
 *
 * File:   p33SMPS_uart.c
 * Author: M91406
 *
 * Created on October 26, 2017, 1:10 PM
 * 
 * Revision:
 * 17/10/26  initial version
 * 19/07/23  added baudrate calculation
 * 
 * ***************************************************************************/
 
// Device header file
#include <xc.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "p33SMPS_uart.h"

#define SMPS_UART_IO_TIMEOUT        5000    // wait for n while cycles before terminating poll-attempt
#define SMPS_UART_ACTIVE_TIMEOUT    10000   // wait for n while cycles before terminating poll-attempt

/*@@p33MP_uart.c
 * ************************************************************************************************
 * Summary:
 * Driver file for the dsPIC33xxxMP UART SFRs
 *
 * Description:
 * The uart module offers a number of registers and configuration options. This additional
 * driver file contains initialization routines for all required settings.
 * ***********************************************************************************************/

volatile uint16_t* smpsUART_GetHandle(volatile uint16_t uart_instance)
{
    volatile uint16_t* fres=0;
    
    // MODE is the first SFR of each UART register block.
    // This is the start address for all library operations
    switch (uart_instance) {
        #ifdef U1MODE
        case 1:
            fres = ((volatile uint16_t*)&U1MODE);
            break;
        #endif
        #ifdef U2MODE
        case 2:
            fres = ((volatile uint16_t*)&U2MODE);
            break;
        #endif
        #ifdef U3MODE
        case 3:
            fres = ((volatile uint16_t*)&U3MODE);
            break;
        #endif
        #ifdef U4MODE
        case 4:
            fres = ((volatile uint16_t*)&U4MODE);
            break;
        #endif
        default:
            break;
    }
    
    return(fres);
}

/*!smps_uart_init
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 * uint16_t      uart_instance = selects the register address range of the target UART unit
 * UART_CONFIG_t config
 *
 * Description:
 * This routine is setting the uart configuration. This routine needs to be called before a UART
 * port is opened to ensure the baudrate settings and hardware flow control is applied properly.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_Initialize(volatile uint16_t uart_instance, volatile UART_CONFIG_t config)
{

    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;
    
    if (!(smpsUART_PowerOn(uart_instance))) return(0); // Make sure power to peripheral is turned on

    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    ux_regbuf = (volatile UART_CONFIG_t*)smpsUART_GetHandle(uart_instance); // Capture start of the UART register block
    
    // Write user configuration to SFR and check if value is correct
    ux_regbuf->mode.value = (config.mode.value & UART_UxMODE_VALID_DATA_MASK);
    fres &= ((ux_regbuf->mode.value & UART_UxMODE_VALID_DATA_MASK) == (config.mode.value & UART_UxMODE_VALID_DATA_MASK)); // Test     

    ux_regbuf->status.value = (config.status.value & UART_UxSTA_VALID_DATA_MASK);
    fres &= ((ux_regbuf->status.value & UART_UxSTA_VALID_DATA_MASK) == (config.status.value & UART_UxSTA_VALID_DATA_MASK)); // Test     

    ux_regbuf->baudrate.value = (config.status.value & UART_UxBRG_VALID_DATA_MASK);
    fres &= ((ux_regbuf->baudrate.value & UART_UxBRG_VALID_DATA_MASK) == (config.baudrate.value & UART_UxBRG_VALID_DATA_MASK)); // Test     

    ux_regbuf->p1.value = (config.p1.value & UART_UxP1_VALID_DATA_MASK);
    fres &= ((ux_regbuf->p1.value & UART_UxP1_VALID_DATA_MASK) == (config.p1.value & UART_UxP1_VALID_DATA_MASK)); // Test     

    ux_regbuf->p2.value = (config.p2.value & UART_UxP2_VALID_DATA_MASK);
    fres &= ((ux_regbuf->p2.value & UART_UxP2_VALID_DATA_MASK) == (config.p2.value & UART_UxP2_VALID_DATA_MASK)); // Test     

    ux_regbuf->p3.value = (config.p3.value & UART_UxP3_VALID_DATA_MASK);
    fres &= ((ux_regbuf->p3.value & UART_UxP3_VALID_DATA_MASK) == (config.p3.value & UART_UxP3_VALID_DATA_MASK)); // Test     

    ux_regbuf->tx_chk.value = (config.tx_chk.value & UART_UxTXCHK_VALID_DATA_MASK);
    fres &= ((ux_regbuf->tx_chk.value & UART_UxTXCHK_VALID_DATA_MASK) == (config.tx_chk.value & UART_UxTXCHK_VALID_DATA_MASK)); // Test     

    ux_regbuf->rx_chk.value = (config.rx_chk.value & UART_UxRXCHK_VALID_DATA_MASK);
    fres &= ((ux_regbuf->rx_chk.value & UART_UxRXCHK_VALID_DATA_MASK) == (config.rx_chk.value & UART_UxRXCHK_VALID_DATA_MASK)); // Test     

    ux_regbuf->sccon.value = (config.sccon.value & UART_UxSCCON_VALID_DATA_MASK);
    fres &= ((ux_regbuf->sccon.value & UART_UxSCCON_VALID_DATA_MASK) == (config.sccon.value & UART_UxSCCON_VALID_DATA_MASK)); // Test     

    ux_regbuf->scint.value = (config.scint.value & UART_UxSCINT_VALID_DATA_MASK);
    fres &= ((ux_regbuf->scint.value & UART_UxSCINT_VALID_DATA_MASK) == (config.scint.value & UART_UxSCINT_VALID_DATA_MASK)); // Test     

    ux_regbuf->abaud_int.value = (config.abaud_int.value & UART_UxINT_VALID_DATA_MASK);
    fres &= ((ux_regbuf->abaud_int.value & UART_UxINT_VALID_DATA_MASK) == (config.abaud_int.value & UART_UxINT_VALID_DATA_MASK)); // Test     
    
    return(fres);
}

/*@@smps_uart_open_port
 * ************************************************************************************************
 * Summary:
 * Initializes a specific UART unit
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This function is the default UART initialization for RS232 communication. It emulates
 * the generic function call of the form [e.g. COM1, 9600, 8, N, 1, NONE] commonly used to open 
 * a UART port.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_OpenPort(volatile UART_t* uart)
{
    volatile uint16_t fres=1;
    volatile uint16_t timeout=0;
    
    volatile UART_CONFIG_t *ux_regbuf;
    
    volatile UxMODE_t uxmode_config;
    volatile UxSTA_t  uxsta_config;
    
    // Make sure power to peripheral is turned on
    if (!(smpsUART_PowerOn(uart->instance))) return(0); 

    // Check if the requested UART does exists on the recently selected device
    if (uart->instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    uart->handle = (volatile uint16_t*)smpsUART_GetHandle(uart->instance); // Capture start of the UART register block
    ux_regbuf = (volatile UART_CONFIG_t*)uart->handle;
    
    // Initialize UART objects
    uxmode_config.value = UART_UxMODE_REG_DISPOSE_MASK;   // Clear UART Mode configuration
    uxsta_config.value  = UART_UxSTA_REG_DISPOSE_MASK; // Clear UART Status configuration
    
    // Set data bits and parity
    switch (uart->data_bits)
    {
        case UART_DATA_BITS_7:
            uxmode_config.bits.mod = UxMODE_MOD_ASYNC_7B_NONE;
            break;
            
        case UART_DATA_BITS_8:
            
            switch (uart->parity)
            {
                case UART_PARITY_NONE:
                    uxmode_config.bits.mod = UxMODE_MOD_ASYNC_8B_NONE;
                    break;

                case UART_PARITY_ODD:
                    uxmode_config.bits.mod = UxMODE_MOD_ASYNC_8B_ODD;
                    break;

                case UART_PARITY_EVEN:
                    uxmode_config.bits.mod = UxMODE_MOD_ASYNC_8B_EVEN;
                    break;
            }
            
            break;
            
        case UART_DATA_BITS_9:
            uxmode_config.bits.mod = UxMODE_MOD_ASYNC_9B_NONE;
            break;

        default:    // invalid setting 
            return(0); // => exit and return error code
            break;
    } 
    
    // set stop-bits
    switch(uart->stop_bits)
    {
        case UART_STOP_BITS_1:
            uxmode_config.bits.stsel = UxMODE_STSEL_1_SBIT_1_CHK;
            break;
            
        case UART_STOP_BITS_15:
            uxmode_config.bits.stsel = UxMODE_STSEL_15_SBIT_15_CHK;
            break;

        case UART_STOP_BITS_2:
            uxmode_config.bits.stsel = UxMODE_STSEL_2_SBIT_2_CHK;
            break;

        default:    // invalid setting
            return(0); // => exit and return error code
            break;
    }        
    
    // set flow control
    switch(uart->flow_control)    
    {
        case UxMODE_FLO_NONE:
            uxmode_config.bits.flo = UxMODE_FLO_NONE;
            break;
        case UxMODE_FLO_RTS_CTS:
            uxmode_config.bits.flo = UxMODE_FLO_RTS_CTS;
            break;
        case UxMODE_FLO_XON_XOFF:
            uxmode_config.bits.flo = UxMODE_FLO_XON_XOFF;
            break;
        default:    // invalid setting
            return(0); // => exit and return error code
            break;
    }
    
    // =======================================
    // Set default UART configuration
    uxmode_config.bits.abaud = UxMODE_ABAUD_DISABLED;   // Disable Auto Baud option
    
    uxmode_config.bits.urxen = UxMODE_URXEN_DISABLED;   // Disable receiving messages
    uxmode_config.bits.utxen = UxMODE_UTXEN_DISABLED;   // Disable sending messages
    uxmode_config.bits.uarten = UxMODE_UARTEN_DISABLED; // Disable UART while writing configuration

    // By default use Peripheral Clock Fosc and fractional mode
    uxmode_config.bits.bclksel = UxMODE_BCLKSEL_FOSC;
    uxmode_config.bits.bclkmod = UxMODE_BCLKMOD_FRACTIONAL;
    
    ux_regbuf->mode.value = (uxmode_config.value & UART_UxMODE_VALID_DATA_MASK); // write value with bit-mask
    fres &= ((ux_regbuf->mode.value & UART_UxMODE_VALID_DATA_MASK) == (uxmode_config.value & UART_UxMODE_VALID_DATA_MASK)); // Test if written value matches parameter

    // =======================================
    // Calculate the baud rate 
    fres &= smpsUART_SetBaudrate(uart->instance, uart->baudrate);

    // ========================================

    // Setup FIFO buffers
    uxsta_config.bits.urxisel = (uart->rx_buffer.fifo_isr_mark);
    uxsta_config.bits.utxisel = (uart->tx_buffer.fifo_isr_mark);
    
    // Clear FIFO buffers
    uxsta_config.bits.urxbe = 0; // Clear UxRX Buffer Empty bit
    uxsta_config.bits.urxbf = 1; // Set UxRX Buffer Full bit
    uxsta_config.bits.utxbe = 0; // Clear UxTX Buffer Empty
    uxsta_config.bits.utxbf = 1; // Set UxTX Buffer Full bit

    ux_regbuf->status.value = (uxsta_config.value & UART_UxSTA_VALID_DATA_MASK); // write value with bit-mask
    fres &= ((ux_regbuf->status.value & UART_UxSTA_VALID_DATA_MASK) == (uxsta_config.value & UART_UxSTA_VALID_DATA_MASK)); // Test     
    
    uxsta_config.bits.urxbf = 0; // Clear UxRX Buffer Full bit
    uxsta_config.bits.urxbe = 1; // Set UxRX Buffer Empty bit
    uxsta_config.bits.utxbf = 0; // Clear UxTX Buffer Full bit
    uxsta_config.bits.utxbe = 1; // Set UxTX Buffer Empty

    ux_regbuf->status.value = (uxsta_config.value & UART_UxSTA_VALID_DATA_MASK); // write value with bit-mask
    fres &= ((ux_regbuf->status.value & UART_UxSTA_VALID_DATA_MASK) == (uxsta_config.value & UART_UxSTA_VALID_DATA_MASK)); // Test     

    // Set default status bits
    uart->rx_buffer.status.buffer_empty = true;;
    uart->rx_buffer.status.buffer_full = false;
    uart->rx_buffer.status.buffer_overun = false;
    uart->rx_buffer.status.msg_complete = true;

    uart->tx_buffer.status.buffer_empty = false;
    uart->tx_buffer.status.buffer_full = false;
    uart->tx_buffer.status.buffer_overun = false;
    uart->tx_buffer.status.msg_complete = true;
    
    // Enable UART
    ux_regbuf->mode.bits.uarten = UxMODE_UARTEN_ENABLED; // Enable UART
    ux_regbuf->mode.bits.urxen = UxMODE_URXEN_ENABLED;   // Enable receiving messages
    ux_regbuf->mode.bits.utxen = UxMODE_UTXEN_ENABLED;   // Enable sending messages
    
    while((!ux_regbuf->mode.bits.active) && (timeout < SMPS_UART_ACTIVE_TIMEOUT));
    fres &= (bool)(timeout < SMPS_UART_ACTIVE_TIMEOUT);
    
    if (!fres) uart->handle = NULL; // Clear handle if configuration failed
    
 return(fres);

}

/*!smpsUART_Read
 * ************************************************************************************************
 * Summary:
 * Reads one byte from the input buffer 
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is reading one byte from the selected UART receive buffer
 * ***********************************************************************************************/

volatile uint16_t smpsUART_ReadFIFO(volatile UART_t* uart) 
{

    volatile uint16_t fres=0;

    volatile UART_CONFIG_t *ux_regbuf;
    volatile uint16_t rx_buf=0;
    volatile uint16_t uxrxif=0;

    
    // Check if the requested UART does exists on the recently selected device
    if (uart->instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Check if user data buffer is available
    if(uart->tx_buffer.buffer == NULL) return(0);
    
    // Capture UARTx SFRs
    if(uart->handle == NULL) return(0);
    ux_regbuf = (volatile UART_CONFIG_t*)uart->handle; // Capture start of the UART register block
    
    // Capture RECEIVE ISR flag bit
    switch (uart->instance){
        #ifdef U1MODE
        case 1: uxrxif = _U1RXIF; break; // Receive interrupt of UART1
        #endif
        #ifdef U2MODE
        case 2: uxrxif = _U2RXIF; break; // Receive interrupt of UART2
        #endif
        #ifdef U3MODE
        case 3: uxrxif = _U3RXIF; break; // Receive interrupt of UART3
        #endif
        #ifdef U4MODE
        case 4: uxrxif = _U4RXIF; break; // Receive interrupt of UART4
        #endif
        default: uxrxif = 0; break;
    }

    // Check if message has been received
    if((ux_regbuf->status.value & UART_UxSTA_MESSAGE_RECEIVED) || (uxrxif)) // check if buffer is full
    {
        // Read entire FIFO buffer
        while(!(ux_regbuf->status.value & UART_UxSTA_MESSAGE_READ)) // while buffer is not empty...
        {
            // Read a byte from RECEIVE buffer
            rx_buf = (volatile uint16_t) ux_regbuf->rx_reg.value; 
            fres = 1; // Set function return value indicating new data
            
            // IF there is space left in the user data buffer, copy data into user data buffer
            if(uart->rx_buffer.pointer < uart->rx_buffer.size) {
            // if the receive buffer is not filled yet...
                
                uart->rx_buffer.buffer[uart->rx_buffer.pointer++] = (volatile uint8_t)rx_buf; // Read receive buffer

                uart->rx_buffer.status.buffer_empty = false;    // Clear BUFFER EMPTY status bit
                uart->rx_buffer.status.buffer_full = false; // Clear BUFFER FULL status bit
                uart->rx_buffer.status.buffer_overun = false;   // Clear OVERRUN status bit
            }
            else if (uart->rx_buffer.pointer == uart->rx_buffer.size) { 
                uart->rx_buffer.status.buffer_full = true;  // Set BUFFER FULL status bit
            }
            else{ 
            // If the buffer is full, set overflow status bit
                uart->rx_buffer.status.buffer_overun = true;   // Set OVERRUN status bit
            }
            
        }
            
        // Clear UART RECEIVE ISR Flag Bit
        switch (uart->instance) {
            #ifdef _U1RXIF
            case 1: _U1RXIF = 0; break; // Clear UART1 Receive Interrupt Flag Bit
            #endif
            #ifdef _U2RXIF
            case 2: _U2RXIF = 0; break; // Clear UART2 Receive Interrupt Flag Bit
            #endif
            #ifdef _U3RXIF
            case 3: _U3RXIF = 0; break; // Clear UART3 Receive Interrupt Flag Bit
            #endif
            #ifdef _U4RXIF
            case 4: _U4RXIF = 0; break; // Clear UART4 Receive Interrupt Flag Bit
            #endif
            default:
                break;
        }
        
    }

    // Check for ISR Flag Bits which need to be reset
    if ((ux_regbuf->status.value & UART_UxSTA_ISR_FLAGS_MASK))
    {
        Nop();
        
        ux_regbuf->status.bits.trmt = 0; // Clear Transmit Shifter Empty Interrupt Flag bit
        ux_regbuf->status.bits.txcif = 0; // Clear Transmit Collision Interrupt Enable bit
        ux_regbuf->status.bits.rxbkif = 0; // Clear Receive Break Interrupt Flag bit
        ux_regbuf->status.bits.ferr = 0; // Clear Framing Error Interrupt Flag bit
        ux_regbuf->status.bits.perr = 0; // Clear Parity Error/Address Received/Forward Frame Interrupt Flag bit
        ux_regbuf->status.bits.cerif = 0; // Clear Checksum Error Interrupt Flag bit
        ux_regbuf->status.bits.oerr = 0; // Clear Receive Buffer Overflow Interrupt Flag bit
        ux_regbuf->status.bits.abdovf = 0; // Clear Auto-Baud Rate Acquisition Interrupt Flag bit
        
        // Clear UART ERROR ISR Flag Bit
        switch (uart->instance) {
            #ifdef _U1EIF
            case 1: _U1EIF = 0; break; // Clear UART1 Error Interrupt Flag Bit
            #endif
            #ifdef _U2EIF
            case 2: _U2EIF = 0; break; // Clear UART2 Error Interrupt Flag Bit
            #endif
            #ifdef _U3EIF
            case 3: _U3EIF = 0; break; // Clear UART3 Error Interrupt Flag Bit
            #endif
            #ifdef _U4EIF
            case 4: _U4EIF = 0; break; // Clear UART4 Error Interrupt Flag Bit
            #endif
            default:
                break;
        }
        
        
    }

    // If user buffer has been assigned, check for BUFFER EMPTY status
    uart->rx_buffer.status.buffer_empty =(volatile bool)(uart->rx_buffer.pointer == 0);
    
    
    { return(fres); } // no data has been received
    
}

/*!smpsUART_Write
 * ************************************************************************************************
 * Summary:
 * Writes one byte to the output buffer 
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is writing one byte to the selected UART transmit buffer
 * ***********************************************************************************************/

volatile uint16_t smpsUART_WriteFIFO(volatile UART_t* uart)
{
    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;
    volatile uint16_t pack_size_counter=0; 

    
    // Check if the requested UART does exists on the recently selected device
    if (uart->instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Check if user data buffer is available
    if(uart->tx_buffer.buffer == NULL) return(0);
    
    // Capture UARTx SFRs
    if(uart->handle == NULL) return(0);
    ux_regbuf = (volatile UART_CONFIG_t*)uart->handle; // Capture start of the UART register block
    
    // Send message frame
    while ((!ux_regbuf->status.bits.utxbf) && (uart->tx_buffer.pointer < uart->tx_buffer.data_size)) 
    {
        
        // Clear MESSAGE COMPLETE flag bit indicating TRANSMISSION IN PPROGRESS
        uart->tx_buffer.status.msg_complete = false;
        fres = 1;
        
        // Write a byte to TRANSMIT buffer
        ux_regbuf->tx_reg.value = 
            (volatile uint8_t)uart->tx_buffer.buffer[uart->tx_buffer.pointer++]; 

        if ((uart->tx_buffer.pointer >= uart->tx_buffer.size) || 
            (pack_size_counter++ >= uart->tx_buffer.package_size)){
        // Protection against overrunning absolute buffer size
            break;
        }

    }

    // If complete message buffer has been sent, set MESSAGE COMPLETE flag bit
    if (uart->tx_buffer.pointer >= uart->tx_buffer.data_size) { 
        uart->tx_buffer.status.msg_complete = true; // Set Message Complete flag bit
        uart->tx_buffer.pointer = 0; // Reset frame pointer to beginning of buffer
        uart->tx_buffer.data_size = 0; // Reset frame pointer to beginning of buffer
    }
        
    // Check for ISR Flag Bits which need to be reset
    if ((ux_regbuf->status.value & UART_UxSTA_ISR_FLAGS_MASK))
    {
        Nop();
        
        ux_regbuf->status.bits.trmt = 0; // Clear Transmit Shifter Empty Interrupt Flag bit
        ux_regbuf->status.bits.txcif = 0; // Clear Transmit Collision Interrupt Enable bit
        ux_regbuf->status.bits.rxbkif = 0; // Clear Receive Break Interrupt Flag bit
        ux_regbuf->status.bits.ferr = 0; // Clear Framing Error Interrupt Flag bit
        ux_regbuf->status.bits.perr = 0; // Clear Parity Error/Address Received/Forward Frame Interrupt Flag bit
        ux_regbuf->status.bits.cerif = 0; // Clear Checksum Error Interrupt Flag bit
        ux_regbuf->status.bits.oerr = 0; // Clear Receive Buffer Overflow Interrupt Flag bit
        ux_regbuf->status.bits.abdovf = 0; // Clear Auto-Baud Rate Acquisition Interrupt Flag bit
        
        // Clear UART ERROR ISR Flag Bit
        switch (uart->instance) {
            #ifdef _U1EIF
            case 1: _U1EIF = 0; break; // Clear UART1 Error Interrupt Flag Bit
            #endif
            #ifdef _U2EIF
            case 2: _U2EIF = 0; break; // Clear UART2 Error Interrupt Flag Bit
            #endif
            #ifdef _U3EIF
            case 3: _U3EIF = 0; break; // Clear UART3 Error Interrupt Flag Bit
            #endif
            #ifdef _U4EIF
            case 4: _U4EIF = 0; break; // Clear UART4 Error Interrupt Flag Bit
            #endif
            default:
                break;
        }
        
        
    }
    
    { return(fres); } // no data has been received
    
}


/*!smpsUART_GetStatus
 * ************************************************************************************************
 * Summary:
 * Reads the status of the given UART unit
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is reading the status information form the status register of the selected UART 
 * ***********************************************************************************************/

volatile uint32_t smpsUART_GetStatus(volatile UART_t uart)
{
    
    volatile UART_CONFIG_t *ux_regbuf;

    // Check if the requested UART does exists on the recently selected device
    if (uart.instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    if(uart.handle == NULL) return(0);                  // If UART is not initialized, exit here
    ux_regbuf = (volatile UART_CONFIG_t*)uart.handle;   // Capture start of the UART register block

    return(ux_regbuf->status.value); // Return status bits
}

/*!smpsUART_Enable
 * ************************************************************************************************
 * Summary:
 * Enables a specific, pre-configured UART unit 
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is enabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_Enable(volatile UART_t uart)
{
    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;
 
    if (!(smpsUART_PowerOn(uart.instance))) return(0); // Make sure power to peripheral is turned on

    // Check if the requested UART does exists on the recently selected device
    if (uart.instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    if(uart.handle == NULL) return(0);                  // If UART is not initialized, exit here
    ux_regbuf = (volatile UART_CONFIG_t*)uart.handle;   // Capture start of the UART register block

    // Set ENABLE bit
    ux_regbuf->mode.bits.uarten = 1; // Enable UART
    fres = (volatile uint16_t)(ux_regbuf->mode.bits.uarten); // Read Enable-Bit
    
 return(fres);

}

/*!smpsUART_Disable
 * ************************************************************************************************
 * Summary:
 * Disables a specific, pre-configured UART unit 
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is disabling the selected UART as it was configured previously.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_Disable(volatile UART_t uart)
{
    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;

    // Check if the requested UART does exists on the recently selected device
    if (uart.instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    if(uart.handle == NULL) return(0);                  // If UART is not initialized, exit here
    ux_regbuf = (volatile UART_CONFIG_t*)uart.handle;   // Capture start of the UART register block

    // Capture MODE registers
    ux_regbuf->mode.bits.uarten = 0; // Disable UART
    fres = (1-ux_regbuf->mode.bits.uarten); // Read Enable-Bit

    return(fres);

}


/*!smpsUART_Close
 * ************************************************************************************************
 * Summary:
 * Closes a specific UART peripheral
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is disabling the selected UART peripheral but keeps it powered and
 * all configuration bits in place (except status bits)
 * ***********************************************************************************************/

volatile uint16_t smpsUART_Close(volatile UART_t* uart)
{
    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;
 
    // Check if the requested UART does exists on the recently selected device
    if (uart->instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    if(uart->handle == NULL) return(0);                  // If UART is not initialized, exit here
    ux_regbuf = (volatile UART_CONFIG_t*)uart->handle;   // Capture start of the UART register block

    // Shut down UART peripheral
    ux_regbuf->mode.bits.uarten = 0; // Turn off UART
    ux_regbuf->mode.value = UART_UxMODE_REG_DISPOSE_MASK; // Reset all mode registers
    fres = (1-ux_regbuf->mode.bits.uarten); // Read Enable-Bit
    
    // Clear STATUS registers
    ux_regbuf->status.value = UART_UxSTA_REG_DISPOSE_MASK; // Reset all status registers
    
    return(fres);

}


/*!smpsUART_Dispose
 * ************************************************************************************************
 * Summary:
 * Disposes a specific UART unit 
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *
 * Description:
 * This routine is disabling the selected UART, resets its entire configuration and powers down
 * the module. No further writes to registers of this peripheral can be made until it is 
 * initialized again.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_Dispose(volatile UART_t* uart)
{
    volatile uint16_t fres=0;
    volatile UART_CONFIG_t *ux_regbuf;
 

    // Check if the requested UART does exists on the recently selected device
    if (uart->instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Capture UARTx SFRs
    if(uart->handle == NULL) return(0);                  // If UART is not initialized, exit here
    ux_regbuf = (volatile UART_CONFIG_t*)uart->handle;   // Capture start of the UART register block

    // Shut down UART peripheral
    ux_regbuf->mode.bits.uarten = 0; // Turn off UART
    ux_regbuf->mode.value = UART_UxMODE_REG_DISPOSE_MASK; // Reset all mode registers
    fres = (1-ux_regbuf->mode.bits.uarten); // Read Enable-Bit
    
    // Clear STATUS registers
    ux_regbuf->status.value = UART_UxSTA_REG_DISPOSE_MASK; // Reset all status registers
    
    // Clear Baudrate registers
    ux_regbuf->baudrate.value = UART_UxBRG_REG_DISPOSE_MASK; // Reset all status registers

    // Turn-Off Power
    fres &= smpsUART_PowerOff(uart->instance);  // Turn off power to UART instance
    if (fres) uart->handle = NULL;              // Clear handle
    
    return(fres);

}


/*!smpsUART_PowerOn
 * ************************************************************************************************
 * Summary:
 * Turns on the power to a given UART unit 
 *
 * Parameters:
 * uint16_t uart_instance: UART peripheral instance (e.g. 1=UART1, 2=UART2, etc.)
 *
 * Returns:
 *  uint16_t: 1=success, 0=failure
 *
 * Description:
 * This routine is enabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_PowerOn(volatile uint16_t uart_instance)
{

    volatile uint16_t fres=0;
    
    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 1; 
    fres = _PMDLOCK;
    #endif

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(uart_instance == 1) { _U1MD = 0; fres |= (1-_U1MD); }
    #endif
    #ifdef _U2MD
        if(uart_instance == 2) { _U2MD = 0; fres |= (1-_U2MD); }
    #endif
    #ifdef _U3MD
        if(uart_instance == 3) { _U3MD = 0; fres |= (1-_U3MD); }
    #endif
    #ifdef _U4MD
        if(uart_instance == 4) { _U4MD = 0; fres |= (1-_U4MD); }
    #endif

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 0; 
    fres |= (1-_PMDLOCK);
    #endif
    
 return(fres);

}


/*!smpsUART_PowerOff
 * ************************************************************************************************
 * Summary:
 * Turns off the power to a given UART unit 
 *
 * Parameters:
 * uint16_t uart_instance: UART peripheral instance (e.g. 1=UART1, 2=UART2, etc.)
 *
 * Returns:
 *  uint16_t: 1=success, 0=failure
 * 
 * Description:
 * This routine is disabling the power supply to the user-defined UART module.
 * ***********************************************************************************************/

volatile uint16_t smpsUART_PowerOff(volatile uint16_t uart_instance)
{
    volatile uint16_t fres=0;
    

    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 1; 
    fres = _PMDLOCK;
    #endif

    // Turn on power to peripheral module
    #ifdef _U1MD
        if(uart_instance == 1) { _U1MD = 1; fres |= (_U1MD); }
    #endif
    #ifdef _U2MD
        if(uart_instance == 2) { _U2MD = 1; fres |= (_U2MD); }
    #endif
    #ifdef _U3MD
        if(uart_instance == 3) { _U3MD = 1; fres |= (_U3MD); }
    #endif
    #ifdef _U4MD
        if(uart_instance == 4) { _U4MD = 1; fres |= (_U4MD); }
    #endif

    // Peripheral Module Disable-bits (1=can be set, 0=cannot be set) in software
    #ifdef PMDCON
    _PMDLOCK = 0; 
    fres |= (1-_PMDLOCK);
    #endif
    
    return(fres);

}

/*!smpsUART_GetBaudrateRegValue
 * ************************************************************************************************
 * Summary:
 * Calculates the SFR register value required to achieve the given baud rate
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *  uint32_t baud = user given baud rate (e.g. 9600)
 * 
 * Returns:
 *  uint32_t baudrate = register value for [UxBRGH]+[UxBRG] registers
 *
 * Description:
 * This routine reads the most recent oscillator and UART configuration and 
 * calculates the SFR value to program the selected UART peripheral for 
 * a certain, user defined baud rate.
 * 
 * This routine only calculates the required SFR value but does not program it into the target
 * peripheral. Please use function smpsUART_OpenPort(...) to apply the new baud rate setting.
 * 
 * Please note:
 * When the system clock or main oscillator settings are changed, this routine has to be
 * called again to adjust the baud rate for the new clock source frequency.
 * ************************************************************************************************/
volatile uint32_t smpsUART_GetBaudrateRegValue(volatile uint16_t uart_instance, uint32_t baud) {
    
    volatile UART_CONFIG_t *ux_regbuf;
    volatile uint32_t baudclk=0;

    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid
    
    // Capture UARTx SFRs
    ux_regbuf = (volatile UART_CONFIG_t*)smpsUART_GetHandle(uart_instance); // Capture start of the UART register block
    
    // Get frequency based on input clock selection setting

    switch (ux_regbuf->mode.bits.bclksel) {
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
    
    if(ux_regbuf->mode.bits.bclkmod) { // Baud Clock Generation Mode Selection (bit 11)
    // When in fractional baud rate generation mode, the BRG register setting
    // is calculated by [BRG_VALUE] = [f_source] / [BAUDRATE]
        
        baudclk = (volatile uint32_t)((float)baudclk / (float)baud);
        
    }
    else {
    // When in legacy divide-by-x counter baud rate generation mode
        
        if (ux_regbuf->mode.bits.brgh) {   // Filter on BRGH bit
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

/*!smpsUART_SetBaudrate
 * ************************************************************************************************
 * Summary:
 * Sets the desired UART baud rate
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 *  uint32_t baud = user given baud rate (e.g. 9600)
 * 
 * Returns:
 *  uint16_t: 1=success, 0=failure
 *
 * Description:
 * This routine calculates the required register values to meet the user defined
 * baud rate, based on the most recent oscillator settings. When the system clock 
 * or main oscillator settings have changed, this routine has to be
 * called again to adjust the baud rate for the new clock source frequency.
 * 
 * PLEASE NOTE:
 * The UART MODE registers need to be initialized before this function is called
 * as the value depends on its settings. Calling this function without correctly
 * initialized MODE registers will result in unpredictable results.
 * ************************************************************************************************/

volatile uint16_t smpsUART_SetBaudrate(volatile uint16_t uart_instance, uint32_t baud) {

    volatile uint16_t fres=1;
    volatile UART_CONFIG_t *ux_regbuf;
    volatile uint32_t baudrate=0;

    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid
    
    // Capture UARTx SFRs
    ux_regbuf = (volatile UART_CONFIG_t*)smpsUART_GetHandle(uart_instance); // Capture start of the UART register block
    
    // Calculate the baud rate register value
    baudrate = smpsUART_GetBaudrateRegValue(uart_instance, baud);
    
    // Set the baud rate register
    ux_regbuf->baudrate.value = (baudrate & UART_UxBRG_REG_WRITE_MASK); // write value with bit-mask
    fres &= ((ux_regbuf->baudrate.value & UART_UxBRG_REG_WRITE_MASK) == (baudrate & UART_UxBRG_REG_WRITE_MASK)); // Test if written value matches parameter
    
    return(fres);
}

/*!smpsUART_GetBaudrate
 * ************************************************************************************************
 * Summary:
 * Gets the most recent UART baud rate
 *
 * Parameters:
 * UART_t   uart = UART object specified by user
 * 
 * Returns:
 *  uint32_t: UART Baud Rate (e.g. 9600)
 *
 * Description:
 * This routine calculates the required register values to meet the user defined
 * baud rate, based on the most recent oscillator settings. When the system clock 
 * or main oscillator settings have changed, this routine has to be
 * called again to adjust the baud rate for the new clock source frequency.
 * 
 * PLEASE NOTE:
 * The UART MODE registers need to be initialized before this function is called
 * as the value depends on its settings. Calling this function without correctly
 * initialized MODE registers will result in unpredictable results.
 * ************************************************************************************************/

volatile uint32_t smpsUART_GetBaudrate(volatile uint16_t uart_instance) {

    volatile UART_CONFIG_t *ux_regbuf;
    volatile uint32_t baudrate=0, f_source=0;
    
    // Check if the requested UART does exists on the recently selected device
    if (uart_instance > UART_UART_COUNT) return(0);     // Check if index is valid
    
    // Capture UARTx SFRs
    ux_regbuf = (volatile UART_CONFIG_t*)smpsUART_GetHandle(uart_instance); // Capture start of the UART register block
    
    // Get frequency based on input clock selection setting

    switch (ux_regbuf->mode.bits.bclksel) {
        case 0b00:  // FOSC/2 (= peripheral clock)
            f_source = system_frequencies.fp; 
            break;
        case 0b01:  // (reserved) => invalid
            return(0); 
            break;
        case 0b10:  // FOSC (= CPU clock)
            f_source = system_frequencies.fosc; 
            break;
        case 0b11:  // AFVCO/3 (=auxiliary PLL output divided by 3)
            f_source = (volatile uint32_t)((float)system_frequencies.fvco / 3.0);
            break;
    }
    
    if(ux_regbuf->mode.bits.bclkmod) { // Baud Clock Generation Mode Selection (bit 11)
    // When in fractional baud rate generation mode, the baud rate
    // is calculated by [BAUDRATE] = [f_source] / [BRG_VALUE]
        
        baudrate = (volatile uint32_t)((float)f_source / (float)ux_regbuf->baudrate.value);
        
    }
    else if (ux_regbuf->baudrate.value > 0) {
    // When in legacy divide-by-x counter baud rate generation mode
        
        if (ux_regbuf->mode.bits.brgh) {   // Filter on BRGH bit
        // High Speed: Baud rate is baudclk/4
            baudrate = (volatile uint32_t)((float)f_source / (4.0 * (float)ux_regbuf->baudrate.value));
        }
        else {
        // Low Speed: Baud rate is baudclk/16
            baudrate = (volatile uint32_t)((float)f_source / (16.0 * (float)ux_regbuf->baudrate.value));
        }
    
    }
    else {
    // When Baudrate register is zero, zero baud rate variable too
        baudrate = 0;
    }
        
    // Return calculation result
    return(baudrate);
}

/*!smpsUART_GetStandardCRC16
 * ************************************************************************************************
 * Summary:
 * Calculates the Cyclic Redundancy Checksum across an 8-bit data array
 *
 * Parameters:
 *  uint8_t *buffer: Pointer to 8-bit data buffer
 *  uint8_t start:   Start-index where CRC calculation should start
 *  uint8_t length:  Number of bytes over which CRC should be calculated across
 * 
 * Returns:
 *  uint8_t: CRC result 
 *
 * Description:
 * This routine calculates the CRC16 result across a given number of 8-bit data cells
 * in an 8-bit data array. This function also support calculations across a sub-section
 * of an array by specifying a start and length parameter.
 * 
 * Example:
 * 
 * In this example the CRC is calculated across the cells 1 to 5 of the array 'my_array', 
 * where 'start' specifies the start index within the array and 'length' specifies the 
 * length of the range counted from the specified start index.
 * 
 *      my_array[8] = [0], [1], [2], [3], [4], [5], [...], [n]
 *                          |                   |
 *      start:              1                   |
 *      length:             1    2    3    4    5
 * 
 *      function call: [CRC] = smpsUART_GetStandardCRC16( &my_array, 1, 5);
 * 
 * ************************************************************************************************/

volatile uint16_t smpsUART_GetStandardCRC16(volatile uint8_t *buffer, volatile uint8_t start, volatile uint8_t length)
{
    volatile uint16_t cnt1=0, cnt2=0, crc=0; // declare calculation auxiliary variables
    
    for (cnt1 = start; cnt1 < (start+length); cnt1++) 
    {
        crc ^= buffer[cnt1];
        
        for (cnt2 = 0; cnt2 < 8; ++cnt2)
        {
            if ((crc & 1) == 1)
                crc = (crc >> 1) ^ 0xA001;
            else
                crc = (crc >> 1);
        }
        
    }
    
    return(crc);
}


/*!UxEInterrupt
 * ************************************************************************************************
 * Summary:
 * UART error interrupt service routines for UART1 to UARTn
 *
 * Parameters:
 * (none)
 * 
 * Returns:
 *  (none)
 *
 * Description:
 * This library provides interrupt service routines (ISR) for 'UART Error', 'UART Receive' and
 * 'UART Transmit'. These ISRs are used for internal purposes.
 * ************************************************************************************************/
//#ifdef U1MODE
//void __attribute__((__interrupt__, auto_psv)) _U1EInterrupt()
//{
//    Nop();
//    _U1RXIF = 0; // Clear interrupt flag bit
//}
//#endif
//#ifdef U2MODE
//void __attribute__((__interrupt__, auto_psv)) _U2EInterrupt()
//{
//    Nop();
//    _U2RXIF = 0; // Clear interrupt flag bit
//}
//#endif
//#ifdef U3MODE
//void __attribute__((__interrupt__, auto_psv)) _U3EInterrupt()
//{
//    Nop();
//    _U3RXIF = 0; // Clear interrupt flag bit
//}
//#endif
//#ifdef U4MODE
//void __attribute__((__interrupt__, auto_psv)) _U4EInterrupt()
//{
//    Nop();
//    _U4RXIF = 0; // Clear interrupt flag bit
//}
//#endif
//
//void __attribute__((__interrupt__, auto_psv)) _U1RXInterrupt()
//{
//    Nop();
//    _U1TXIF = 0; // Clear interrupt flag bit
//}
//
//void __attribute__((__interrupt__, auto_psv)) _U1TXInterrupt()
//{
//    Nop();
//    _U1EIF = 0; // Clear interrupt flag bit
//}

// EOF
