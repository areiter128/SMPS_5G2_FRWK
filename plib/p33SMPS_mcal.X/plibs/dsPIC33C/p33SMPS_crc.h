/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
 */

/* 
 * File:   p33SMPS_crc.h
 * Author: M91406
 * Comments: Peripheral Driver Module for the CRC Hardware Accelerator
 * Revision history: 1.0 (initial version)
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _MCAL_P33_SMPS_CRC_H_
#define	_MCAL_P33_SMPS_CRC_H_

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../p33SMPS_plib.h" // PLIB header required to get access to oscillator driver declarations
#include "../p33SMPS_devices.h" // DEVICES header to derive device-dependent properties


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* ===========================================================================
 * CRCCONH/L: CRC CONTROL REGISTER HIGH/LOW
 * ===========================================================================*/

    #define CRC_CRCCONL_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCCONL_REG_READ_MASK       (uint16_t)0xBFFC
    #define CRC_CRCCONL_REG_WRITE_MASK      (uint16_t)0xA03C
    
    #define CRC_CRCCONH_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCCONH_REG_READ_MASK       (uint16_t)0x1F1F
    #define CRC_CRCCONH_REG_WRITE_MASK      (uint16_t)0x1F1F
    
    #define CRC_CRCCON_REG_DISPOSE_MASK     (uint16_t)0x00000000
    #define CRC_CRCCON_REG_READ_MASK        (uint16_t)0x1F1FBFFC
    #define CRC_CRCCON_REG_WRITE_MASK       (uint16_t)0x1F1FA03C
    
    
    #define REG_CRCCON_CRCEN_ENABLED  0b1000000000000000 // Enables module
    #define REG_CRCCON_CRCEN_DISABLED 0b0000000000000000 // Disables module
    
    typedef enum {
        CRCCON_CRCEN_ENABLED = 1, // Enables module
        CRCCON_CRCEN_DISABLED = 0 // Disables module
    }CRCCON_CRCEN_e; // CRC Enable bit
    
    #define REG_CRCCON_CSIDL_HOLD   0b0010000000000000 // Discontinues module operation when device enters Idle mode
    #define REG_CRCCON_CSIDL_RUN    0b0000000000000000 // Continues module operation in Idle mode

    typedef enum {
        CRCCON_CSIDL_HOLD = 1, // Discontinues module operation when device enters Idle mode
        CRCCON_CSIDL_RUN = 0   // Continues module operation in Idle mode
    }CRCCON_CSIDL_e; // CRC Stop in Idle Mode bit
    
    #define REG_CRCCON_CRCFUL_FULL     0b0000000010000000 // FIFO is full
    #define REG_CRCCON_CRCFUL_NOT_FULL 0b0000000000000000 // FIFO is not full

    typedef enum {
        CRCCON_CRCFUL_FULL = 1,     // FIFO is full
        CRCCON_CRCFUL_NOT_FULL = 0  // FIFO is not full
    }CRCCON_CRCFUL_e; // CRC FIFO Full bit
    
    #define REG_CRCCON_CRCMPT_EMPTY     0b0000000001000000 // FIFO is empty
    #define REG_CRCCON_CRCMPT_NOT_EMPTY 0b0000000000000000 // FIFO is not empty

    typedef enum {
        CRCCON_CRCMPT_EMPTY = 1,    // FIFO is empty
        CRCCON_CRCMPT_NOT_EMPTY = 0 // FIFO is not empty
    }CRCCON_CRCMPT_e; // CRC FIFO Empty bit

    #define REG_CRCCON_CRCISEL_BUSY     0b0000000000100000 // Interrupt on FIFO is empty; the final word of data is still shifting through the CRC
    #define REG_CRCCON_CRCISEL_READY    0b0000000000000000 // Interrupt on shift is complete and results are ready

    typedef enum {
        CRCCON_CRCISEL_BUSY = 1,    // Interrupt on FIFO is empty; the final word of data is still shifting through the CRC
        CRCCON_CRCISEL_READY = 0    // Interrupt on shift is complete and results are ready
    }CRCCON_CRCISEL_e; // CRC Interrupt Selection bit
    
    #define REG_CRCCON_CRCGO_RUN        0b0000000000010000 // Starts CRC serial shifter is running
    #define REG_CRCCON_CRCGO_HALT       0b0000000000000000 // CRC serial shifter is turned off

    typedef enum {
        CRCCON_CRCGO_RUN = 1,       // Starts CRC serial shifter is running
        CRCCON_CRCGO_HALT = 0       // CRC serial shifter is turned off
    }CRCCON_CRCGO_e; // CRC Start bit

    #define REG_CRCCON_LENDIAN_LITTLE   0b0000000000001000 // Data word is shifted into the FIFO, starting with the LSb (little-endian)
    #define REG_CRCCON_LENDIAN_e        0b0000000000000000 // Data word is shifted into the FIFO, starting with the MSb (big-endian)

    typedef enum {
        CRCCON_LENDIAN_LITLE = 1,    // Data word is shifted into the FIFO, starting with the LSb (little-endian)
        CRCCON_LENDIAN_BIG = 0       // Data word is shifted into the FIFO, starting with the MSb (big-endian)
    }CRCCON_LENDIAN_e; // Data Shift Direction Select bit
    
    #define REG_CRCCON_MOD_ALT_MODE     0b0000000000000100 // Alternate mode
    #define REG_CRCCON_MOD_LEGACY       0b0000000000000000 // Legacy mode bit

    typedef enum {
        CRCCON_MOD_ALT_MODE = 1,    // Alternate mode
        CRCCON_MOD_LEGACY = 0       // Legacy mode bit
    }CRCCON_MOD_e; // CRC Calculation Mode bit
    
    #define REG_CRCCON_DWIDTH_1   0b0000000000000000  // data word width =  1 bit
    #define REG_CRCCON_DWIDTH_2   0b0000000100000000  // data word width =  2 bit
    #define REG_CRCCON_DWIDTH_3   0b0000001000000000  // data word width =  3 bit
    #define REG_CRCCON_DWIDTH_4   0b0000001100000000  // data word width =  4 bit
    #define REG_CRCCON_DWIDTH_5   0b0000010000000000  // data word width =  5 bit
    #define REG_CRCCON_DWIDTH_6   0b0000010100000000  // data word width =  6 bit
    #define REG_CRCCON_DWIDTH_7   0b0000011000000000  // data word width =  7 bit
    #define REG_CRCCON_DWIDTH_8   0b0000011100000000  // data word width =  8 bit
    #define REG_CRCCON_DWIDTH_9   0b0000100000000000  // data word width =  9 bit
    #define REG_CRCCON_DWIDTH_10  0b0000100100000000  // data word width = 10 bit
    #define REG_CRCCON_DWIDTH_11  0b0000101000000000  // data word width = 11 bit
    #define REG_CRCCON_DWIDTH_12  0b0000101100000000  // data word width = 12 bit
    #define REG_CRCCON_DWIDTH_13  0b0000110000000000  // data word width = 13 bit
    #define REG_CRCCON_DWIDTH_14  0b0000110100000000  // data word width = 14 bit
    #define REG_CRCCON_DWIDTH_15  0b0000111000000000  // data word width = 15 bit
    #define REG_CRCCON_DWIDTH_16  0b0000111100000000  // data word width = 16 bit
    #define REG_CRCCON_DWIDTH_17  0b0001000000000000  // data word width = 17 bit
    #define REG_CRCCON_DWIDTH_18  0b0001000100000000  // data word width = 18 bit
    #define REG_CRCCON_DWIDTH_19  0b0001001000000000  // data word width = 19 bit
    #define REG_CRCCON_DWIDTH_20  0b0001001100000000  // data word width = 20 bit
    #define REG_CRCCON_DWIDTH_21  0b0001010000000000  // data word width = 21 bit
    #define REG_CRCCON_DWIDTH_22  0b0001010100000000  // data word width = 22 bit
    #define REG_CRCCON_DWIDTH_23  0b0001011000000000  // data word width = 23 bit
    #define REG_CRCCON_DWIDTH_24  0b0001011100000000  // data word width = 24 bit
    #define REG_CRCCON_DWIDTH_25  0b0001100000000000  // data word width = 25 bit
    #define REG_CRCCON_DWIDTH_26  0b0001100100000000  // data word width = 26 bit
    #define REG_CRCCON_DWIDTH_27  0b0001101000000000  // data word width = 27 bit
    #define REG_CRCCON_DWIDTH_28  0b0001101100000000  // data word width = 28 bit
    #define REG_CRCCON_DWIDTH_29  0b0001110000000000  // data word width = 29 bit
    #define REG_CRCCON_DWIDTH_30  0b0001110100000000  // data word width = 30 bit
    #define REG_CRCCON_DWIDTH_31  0b0001111000000000  // data word width = 31 bit
    #define REG_CRCCON_DWIDTH_32  0b0001111100000000  // data word width = 32 bit
    
    typedef enum {
        CRCCON_DWIDTH_1  = 0,   // data word width =   1  bit
        CRCCON_DWIDTH_2  = 1,   // data word width =   2  bit
        CRCCON_DWIDTH_3  = 2,   // data word width =   3  bit
        CRCCON_DWIDTH_4  = 3,   // data word width =   4  bit
        CRCCON_DWIDTH_5  = 4,   // data word width =   5  bit
        CRCCON_DWIDTH_6  = 5,   // data word width =   6  bit
        CRCCON_DWIDTH_7  = 6,   // data word width =   7  bit
        CRCCON_DWIDTH_8  = 7,   // data word width =   8  bit
        CRCCON_DWIDTH_9  = 8,   // data word width =   9  bit
        CRCCON_DWIDTH_10 = 9,   // data word width =  10  bit
        CRCCON_DWIDTH_11 = 10,  // data word width =  11  bit
        CRCCON_DWIDTH_12 = 11,  // data word width =  12  bit
        CRCCON_DWIDTH_13 = 12,  // data word width =  13  bit
        CRCCON_DWIDTH_14 = 13,  // data word width =  14  bit
        CRCCON_DWIDTH_15 = 14,  // data word width =  15  bit
        CRCCON_DWIDTH_16 = 15,  // data word width =  16  bit
        CRCCON_DWIDTH_17 = 16,  // data word width =  17  bit
        CRCCON_DWIDTH_18 = 17,  // data word width =  18  bit
        CRCCON_DWIDTH_19 = 18,  // data word width =  19  bit
        CRCCON_DWIDTH_20 = 19,  // data word width =  20  bit
        CRCCON_DWIDTH_21 = 20,  // data word width =  21  bit
        CRCCON_DWIDTH_22 = 21,  // data word width =  22  bit
        CRCCON_DWIDTH_23 = 22,  // data word width =  23  bit
        CRCCON_DWIDTH_24 = 23,  // data word width =  24  bit
        CRCCON_DWIDTH_25 = 24,  // data word width =  25  bit
        CRCCON_DWIDTH_26 = 25,  // data word width =  26  bit
        CRCCON_DWIDTH_27 = 26,  // data word width =  27  bit
        CRCCON_DWIDTH_28 = 27,  // data word width =  28  bit
        CRCCON_DWIDTH_29 = 28,  // data word width =  29  bit
        CRCCON_DWIDTH_30 = 29,  // data word width =  30  bit
        CRCCON_DWIDTH_31 = 30,  // data word width =  31  bit
        CRCCON_DWIDTH_32 = 31   // data word width =  32  bit
    } CRCCON_DWIDTH_e; // Data Word Width Configuration bits

    #define REG_CRCCON_PLEN_1   0b0000000000000000  // Polynomial Length =   1  bit
    #define REG_CRCCON_PLEN_2   0b0000000000000001  // Polynomial Length =   2  bit
    #define REG_CRCCON_PLEN_3   0b0000000000000010  // Polynomial Length =   3  bit
    #define REG_CRCCON_PLEN_4   0b0000000000000011  // Polynomial Length =   4  bit
    #define REG_CRCCON_PLEN_5   0b0000000000000100  // Polynomial Length =   5  bit
    #define REG_CRCCON_PLEN_6   0b0000000000000101  // Polynomial Length =   6  bit
    #define REG_CRCCON_PLEN_7   0b0000000000000110  // Polynomial Length =   7  bit
    #define REG_CRCCON_PLEN_8   0b0000000000000111  // Polynomial Length =   8  bit
    #define REG_CRCCON_PLEN_9   0b0000000000001000  // Polynomial Length =   9  bit
    #define REG_CRCCON_PLEN_10  0b0000000000001001  // Polynomial Length =  10  bit
    #define REG_CRCCON_PLEN_11  0b0000000000001010  // Polynomial Length =  11  bit
    #define REG_CRCCON_PLEN_12  0b0000000000001011  // Polynomial Length =  12  bit
    #define REG_CRCCON_PLEN_13  0b0000000000001100  // Polynomial Length =  13  bit
    #define REG_CRCCON_PLEN_14  0b0000000000001101  // Polynomial Length =  14  bit
    #define REG_CRCCON_PLEN_15  0b0000000000001110  // Polynomial Length =  15  bit
    #define REG_CRCCON_PLEN_16  0b0000000000001111  // Polynomial Length =  16  bit
    #define REG_CRCCON_PLEN_17  0b0000000000010000  // Polynomial Length =  17  bit
    #define REG_CRCCON_PLEN_18  0b0000000000010001  // Polynomial Length =  18  bit
    #define REG_CRCCON_PLEN_19  0b0000000000010010  // Polynomial Length =  19  bit
    #define REG_CRCCON_PLEN_20  0b0000000000010011  // Polynomial Length =  20  bit
    #define REG_CRCCON_PLEN_21  0b0000000000010100  // Polynomial Length =  21  bit
    #define REG_CRCCON_PLEN_22  0b0000000000010101  // Polynomial Length =  22  bit
    #define REG_CRCCON_PLEN_23  0b0000000000010110  // Polynomial Length =  23  bit
    #define REG_CRCCON_PLEN_24  0b0000000000010111  // Polynomial Length =  24  bit
    #define REG_CRCCON_PLEN_25  0b0000000000011000  // Polynomial Length =  25  bit
    #define REG_CRCCON_PLEN_26  0b0000000000011001  // Polynomial Length =  26  bit
    #define REG_CRCCON_PLEN_27  0b0000000000011010  // Polynomial Length =  27  bit
    #define REG_CRCCON_PLEN_28  0b0000000000011011  // Polynomial Length =  28  bit
    #define REG_CRCCON_PLEN_29  0b0000000000011100  // Polynomial Length =  29  bit
    #define REG_CRCCON_PLEN_30  0b0000000000011101  // Polynomial Length =  30  bit
    #define REG_CRCCON_PLEN_31  0b0000000000011110  // Polynomial Length =  31  bit
    #define REG_CRCCON_PLEN_32  0b0000000000011111  // Polynomial Length =  32  bit
    
    typedef enum {
        CRCCON_PLEN_1  = 0,   // Polynomial Length =  1 bit
        CRCCON_PLEN_2  = 1,   // Polynomial Length =  2 bit
        CRCCON_PLEN_3  = 2,   // Polynomial Length =  3 bit
        CRCCON_PLEN_4  = 3,   // Polynomial Length =  4 bit
        CRCCON_PLEN_5  = 4,   // Polynomial Length =  5 bit
        CRCCON_PLEN_6  = 5,   // Polynomial Length =  6 bit
        CRCCON_PLEN_7  = 6,   // Polynomial Length =  7 bit
        CRCCON_PLEN_8  = 7,   // Polynomial Length =  8 bit
        CRCCON_PLEN_9  = 8,   // Polynomial Length =  9 bit
        CRCCON_PLEN_10 = 9,   // Polynomial Length = 10 bit
        CRCCON_PLEN_11 = 10,  // Polynomial Length = 11 bit
        CRCCON_PLEN_12 = 11,  // Polynomial Length = 12 bit
        CRCCON_PLEN_13 = 12,  // Polynomial Length = 13 bit
        CRCCON_PLEN_14 = 13,  // Polynomial Length = 14 bit
        CRCCON_PLEN_15 = 14,  // Polynomial Length = 15 bit
        CRCCON_PLEN_16 = 15,  // Polynomial Length = 16 bit
        CRCCON_PLEN_17 = 16,  // Polynomial Length = 17 bit
        CRCCON_PLEN_18 = 17,  // Polynomial Length = 18 bit
        CRCCON_PLEN_19 = 18,  // Polynomial Length = 19 bit
        CRCCON_PLEN_20 = 19,  // Polynomial Length = 20 bit
        CRCCON_PLEN_21 = 20,  // Polynomial Length = 21 bit
        CRCCON_PLEN_22 = 21,  // Polynomial Length = 22 bit
        CRCCON_PLEN_23 = 22,  // Polynomial Length = 23 bit
        CRCCON_PLEN_24 = 23,  // Polynomial Length = 24 bit
        CRCCON_PLEN_25 = 24,  // Polynomial Length = 25 bit
        CRCCON_PLEN_26 = 25,  // Polynomial Length = 26 bit
        CRCCON_PLEN_27 = 26,  // Polynomial Length = 27 bit
        CRCCON_PLEN_28 = 27,  // Polynomial Length = 28 bit
        CRCCON_PLEN_29 = 28,  // Polynomial Length = 29 bit
        CRCCON_PLEN_30 = 29,  // Polynomial Length = 30 bit
        CRCCON_PLEN_31 = 30,  // Polynomial Length = 31 bit
        CRCCON_PLEN_32 = 31   // Polynomial Length = 32 bit
    } CRCCON_PLEN_e; // Polynomial Length Configuration bits

    typedef union {
        
        struct {
            
            volatile unsigned : 2;              // bit 1-0: (reserved)
            volatile CRCCON_MOD_e mod :1;       // bit 2: CRC Calculation Mode bit
            volatile CRCCON_LENDIAN_e lendian :1; // bit 3: Data Shift Direction Select bit
            volatile CRCCON_CRCGO_e crcgo :1;   // bit 4: CRC Start bit (control bit to start shifter)
            volatile CRCCON_CRCISEL_e crcisel :1; // bit 5: CRC Interrupt Selection bit
            volatile CRCCON_CRCMPT_e crcmpt :1; // bit 6: CRC FIFO Empty bit (read only)
            volatile CRCCON_CRCFUL_e crcful :1; // bit 7: CRC FIFO Full bit (read only)
            volatile uint16_t vword : 5;        // bit 12-8: Pointer Value bits (read only)
                                                //         Indicates the number of valid words in the FIFO. 
                                                //         Has a maximum value of 8 when PLEN<4:0> greater or
                                                //         equal 7 or 16 when PLEN <PLEN<4:0> greater or equal 7
            volatile CRCCON_CSIDL_e csidl :1;   // bit 13: CRC Stop in Idle Mode bit
            volatile unsigned : 1;              // bit 14: (reserved)
            volatile CRCCON_CRCEN_e crcen :1;   // bit 15: CRC Enable bit

            volatile CRCCON_PLEN_e plen :5;     // Polynomial Length Configuration bits
            volatile unsigned : 3;              // bit 7-5: (reserved)
            volatile CRCCON_DWIDTH_e dwidth :5; // Data Word Width Configuration bits
            volatile unsigned : 3;              // bit 15-13: (reserved)
        }__attribute__((packed)) bits; // CRCCON register bit field
        
        volatile uint32_t value; // CRCCON register full register access
        
    } CRCCON_t; // CRCCONH/L: CRC CONTROL REGISTER HIGH/LOW

/* ===========================================================================
 * CRCXORH/L: CRC XOR POLYNOMIAL REGISTER, HIGH/LOW WORD
 * ===========================================================================*/
    
    #define CRC_CRCXORL_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCXORL_REG_READ_MASK       (uint16_t)0xFFFE
    #define CRC_CRCXORL_REG_WRITE_MASK      (uint16_t)0xFFFE
    
    #define CRC_CRCXORH_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCXORH_REG_READ_MASK       (uint16_t)0xFFFF
    #define CRC_CRCXORH_REG_WRITE_MASK      (uint16_t)0xFFFF
    
    #define CRC_CRCXOR_REG_DISPOSE_MASK     (uint16_t)0x00000000
    #define CRC_CRCXOR_REG_READ_MASK        (uint16_t)0xFFFFFFFE
    #define CRC_CRCXOR_REG_WRITE_MASK       (uint16_t)0xFFFFFFFE
    
    typedef union {
        
        struct {
            volatile uint16_t crcxorl  :16; // CRCXORL: CRC XOR POLYNOMIAL REGISTER, LOW WORD
            volatile uint16_t crcxorh  :16; // CRCXORH: CRC XOR POLYNOMIAL REGISTER, HIGH WORD
        }__attribute__((packed)) bytes; // CRCXOR register high/low words;
        
        volatile uint32_t value; // CRCXOR register full register access
        
    } CRCXOR_t; // CRC XOR POLYNOMIAL REGISTER;
    

/* ===========================================================================
 * CRCDATH/L: CRC DATA REGISTER, HIGH/LOW WORD
 * ===========================================================================*/
    
    #define CRC_CRCDATL_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCDATL_REG_READ_MASK       (uint16_t)0xFFFF
    #define CRC_CRCDATL_REG_WRITE_MASK      (uint16_t)0xFFFF
    
    #define CRC_CRCDATH_REG_DISPOSE_MASK    (uint16_t)0x0000
    #define CRC_CRCDATH_REG_READ_MASK       (uint16_t)0xFFFF
    #define CRC_CRCDATH_REG_WRITE_MASK      (uint16_t)0xFFFF
    
    #define CRC_CRCDAT_REG_DISPOSE_MASK     (uint16_t)0x00000000
    #define CRC_CRCDAT_REG_READ_MASK        (uint16_t)0xFFFFFFFF
    #define CRC_CRCDAT_REG_WRITE_MASK       (uint16_t)0xFFFFFFFF
    
    typedef union {
        
        struct {
            volatile uint16_t crcdatl  :16; // CRCDATL: CRC Data Low Register, LOW WORD
            volatile uint16_t crcdath  :16; // CRCDATH: CRC Data Low Register, HIGH WORD
        }__attribute__((packed)) bytes; // CRCDAT register high/low words;
        
        volatile uint32_t value; //  CRCDAT register full register access
        
    } CRCDAT_t; // CRC Data Register

/* ===========================================================================
 * CRCWDATH/L: CRCWDATL: CRC SHIFT REGISTER, HIGH/LOW WORD
 * ===========================================================================*/
    
    #define CRC_CRCWDATL_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define CRC_CRCWDATL_REG_READ_MASK      (uint16_t)0xFFFF
    #define CRC_CRCWDATL_REG_WRITE_MASK     (uint16_t)0xFFFF
    
    #define CRC_CRCWDATH_REG_DISPOSE_MASK   (uint16_t)0x0000
    #define CRC_CRCWDATH_REG_READ_MASK      (uint16_t)0xFFFF
    #define CRC_CRCWDATH_REG_WRITE_MASK     (uint16_t)0xFFFF
    
    #define CRC_CRCWDAT_REG_DISPOSE_MASK    (uint16_t)0x00000000
    #define CRC_CRCWDAT_REG_READ_MASK       (uint16_t)0xFFFFFFFF
    #define CRC_CRCWDAT_REG_WRITE_MASK      (uint16_t)0xFFFFFFFF
    
    typedef union {
        
        struct {
            volatile uint16_t crcwdatl  :16; // CRCWDATL: CRC Shift Register, LOW WORD (write only)
            volatile uint16_t crcwdath  :16; // CRCWDATH: CRC Shift Register, HIGH WORD (write only)
        }__attribute__((packed)) bytes; // CRCWDAT register high/low words (write only)
        
        volatile uint32_t value; //  CRCWDAT register full register access
        
    } CRCWDAT_t; // CRC Shift Register (write only)

    
/* ===========================================================================
 * CRC REGISTER BLOCK OBJECT
 * ===========================================================================*/
    
    typedef struct {
        volatile CRCCON_t crccon;
        volatile CRCXOR_t crcxor;
        volatile CRCDAT_t crcdat;
        volatile CRCWDAT_t crcwdat;
    } CRC_t;
    
/* ===========================================================================
 * ABSTRACT CRC CONFIGURATION BLOCK OBJECT 
 * ===========================================================================*/
    
    typedef struct {
        volatile CRCCON_DWIDTH_e  data_width;   // Data width (e.g. 5, 7, 8, 9, 12, 15, 16, etc...)
        volatile CRCCON_PLEN_e    poly_length;  // Polynomial Bit Length (e.g. 8-bit, 16-bit or 32-bit)
        volatile uint32_t         polynomial;   // Polynomial Bit Pattern
        volatile uint32_t         seed;         // CRC seed value (e.g. 0x0000 or 0xFFFF)
        volatile CRCCON_LENDIAN_e lendian; // Flag bit indicating that CRC result needs to be reversed
        volatile bool             reverse_bits; // Flag bit indicating that CRC result needs to be reversed
    } CRC_CONFIG_t; // CRC module configuration
    

/* ===========================================================================
 * GLOBAL INLINE ASSEMLBY MACROS
 * ===========================================================================*/

#define SwapWordBytes(x) __extension__ ({ \
    volatile uint16_t __x = (x), __v; \
    __asm__ ("swap %0;\n\t" : "=d" (__v) : "d" (__x)); __v; \
})    

#define ReverseBitOrder16b(x) __extension__ ({ \
    volatile uint16_t __x = (x), __v; \
    __asm__ ( \
        "clr w4 \n" \
        "RBO16LP: do #15, RBO16LPE \n" \
        "sl w4, #1, w4 \n" \
        "btsc %0, #0 \n" \
        "bset w4, #0 \n" \
        "RBO16LPE: rrnc %0, %0 \n" \
        "mov w4, %0 \n" : "=d" (__v) : "d" (__x)); __v; \
})
    
/* ===========================================================================
 * GLOBAL FUNCTION CALL PROTOTYPES
 * ===========================================================================*/

#define CRC16_STANDARD_POLYNOMIAL ((unsigned short)0x8005) // Standard Polynomial 0x8005 (= reverse 0xA001)
#define CRC16_STANDARD_REV_POLYNOMIAL ((unsigned short)0xA001) // Standard Polynomial 0x8005 (= reverse 0xA001)
#define CRC16_STANDARD_SEED_VALUE ((unsigned short)0x0000) // non-direct of 0x0000   
    
extern volatile uint16_t smpsCRC_Initialize (volatile CRC_t crc_config);
extern volatile uint16_t smpsCRC_GetStandard_Data8CRC16(
        volatile uint8_t *data, volatile uint8_t start, volatile uint8_t length);

//extern volatile uint16_t smpsCRC_GetCRC16(
//        volatile uint16_t polynomial, volatile uint16_t seed,
//        volatile uint8_t *data, volatile uint8_t start, volatile uint8_t length);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* _MCAL_P33_SMPS_CRC_H_ */

