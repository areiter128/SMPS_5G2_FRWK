/*
 * File:   p33SMPS_crc.c
 * Author: M91406
 *
 * Created on December 16, 2019, 3:14 PM
 */


#include "p33SMPS_crc.h"

volatile uint16_t smpsCRC_Initialize (volatile CRC_t crc_config) {

    volatile uint16_t fres=1;
    volatile uint32_t *regptr32;
    
    // Reset CRC module control and data registers
    CRCCONL = CRC_CRCCON_REG_DISPOSE_MASK;   // Reset CRC Configuration Register LOW
    CRCCONH = CRC_CRCCON_REG_DISPOSE_MASK;   // Reset CRC Configuration Register HIGH
    CRCDATL = CRC_CRCDATL_REG_DISPOSE_MASK;   // Reset CRC DATA Register LOW
    CRCDATH = CRC_CRCDATH_REG_DISPOSE_MASK;   // Reset CRC DATA Register HIGH
    CRCWDATL = CRC_CRCWDATL_REG_DISPOSE_MASK;  // Reset CRC Result Register LOW
    CRCWDATH = CRC_CRCWDATH_REG_DISPOSE_MASK;  // Reset CRC Result Register HIGH
    CRCXORL = CRC_CRCXORL_REG_DISPOSE_MASK;   // Reset CRC XOR Polynomial Register LOW
    CRCXORH = CRC_CRCXORH_REG_DISPOSE_MASK;   // Reset CRC XOR Polynomial Register HIGH

    // Write user configuration
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&CRCCONL); // Get target address
    *regptr32 = (crc_config.crccon.value & CRC_CRCCON_REG_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr32 & CRC_CRCCON_REG_WRITE_MASK) == (crc_config.crccon.value & CRC_CRCCON_REG_WRITE_MASK)); // Test if written value matches parameter

    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&CRCXORL); // Get target address
    *regptr32 = (crc_config.crcxor.value & CRC_CRCXOR_REG_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr32 & CRC_CRCXOR_REG_WRITE_MASK) == (crc_config.crcxor.value & CRC_CRCXOR_REG_WRITE_MASK)); // Test if written value matches parameter
    
    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&CRCDATL); // Get target address
    *regptr32 = (crc_config.crcdat.value & CRC_CRCDAT_REG_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr32 & CRC_CRCDAT_REG_WRITE_MASK) == (crc_config.crcdat.value & CRC_CRCDAT_REG_WRITE_MASK)); // Test if written value matches parameter

    regptr32 = (volatile uint32_t*) ((volatile uint8_t*)&CRCWDATL); // Get target address
    *regptr32 = (crc_config.crcwdat.value & CRC_CRCWDAT_REG_WRITE_MASK); // write value with bit-mask
    fres &= ((*regptr32 & CRC_CRCWDAT_REG_WRITE_MASK) == (crc_config.crcwdat.value & CRC_CRCWDAT_REG_WRITE_MASK)); // Test if written value matches parameter

    return(fres);
}

volatile uint16_t smpsCRC_GetStandard_Data8CRC16(
        volatile uint8_t *data, volatile uint8_t start, volatile uint8_t length)
{
    volatile uint16_t i=0;
    volatile uint16_t fifo_buf=0;
    volatile uint16_t crc_buf=0;
    volatile uint16_t data_size=0;
    volatile bool is_odd=false;

    // Reset configuration registers
    CRCCONL = 0;
    CRCCONH = 0;
    CRCDATL = 0;
    CRCDATH = 0;
    
    // Initialize configuration registers for standard CRC calculation
    CRCCONLbits.CRCEN = 1; // enable CRC
    CRCCONLbits.MOD = 1; // 0=Legacy Mode, 1=Alternate Mode
    CRCCONLbits.CRCISEL = 0; // interrupt when all shifts are done
    CRCCONLbits.LENDIAN = 1; // 1=little endian, 0=big endian
    CRCCONHbits.DWIDTH = (16-1); // 16-bit data width (even if 8-bit data is used)
    CRCCONHbits.PLEN = (16-1); // 16-bit polynomial order

    // Set polynomial and seed
    CRCCONLbits.CRCGO = 1; // start CRC calculation 
    CRCXORL = CRC16_STANDARD_POLYNOMIAL; // set polynomial
    CRCXORH = 0;
    CRCWDATL = CRC16_STANDARD_SEED_VALUE;// set initial value
    CRCWDATH = 0;
    
    // Check if data length is odd or even
    
    is_odd = (bool) (length & 0x01); // data length is even if least significant bit = 0
                                     // data length is odd if least significant bit = 1
    if(is_odd) 
        data_size = (length & 0xFE); // capture largest even length
    else
        data_size = length; // copy data length as is
    
    // Calculate CRC16 across defined data array by always 
    // loading two bytes into 16-bit wide FIFO buffer
    for (i=start; i<(start+data_size); i+=2)
    {
        fifo_buf = ((data[i+1] << 8) | data[i]); // merge two data bytes

        while(CRCCONLbits.CRCFUL);  // wait if FIFO is full
        _CRCIF = 0;                 // clear the interrupt flag
        CRCDATL = fifo_buf;         // load 16-bit word data into FIFO 
        while(!_CRCIF);             // Wait until all shifts have been completed
        
    }
    
    // Read CRC result of even number of bytes
    CRCCONLbits.CRCGO = 0; // hold CRC calculation
    crc_buf = CRCWDATL; // get CRC result 
    
    // Processing a standard polynomial produces a reversed 
    // bit order of the result. The following macro reverses
    // the bit order of the 16-bit wide CRC result
    crc_buf = ReverseBitOrder16b(crc_buf);
    
    // If data length was odd, process last byte manually
    // in reverse order to finish up CRC result
    if(is_odd) {    

        crc_buf ^= data[start+length-1];

        for (i = 0; i < 8; ++i) // Process last 8-bit of last, odd data byte
        {
            if (crc_buf & 0x0001)
                crc_buf = (crc_buf >> 1) ^ CRC16_STANDARD_REV_POLYNOMIAL;
            else
                crc_buf = (crc_buf >> 1);
        }
    }
    
    return(crc_buf);
}


