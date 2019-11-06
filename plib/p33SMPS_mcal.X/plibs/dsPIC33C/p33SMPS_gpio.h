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
/*!p33SMPS_gpio.h
 * ***************************************************************************
 *
 * File:   p33SMPS_gpio.h
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __MCAL_P33_SMPS_GPIO_H__
#define	__MCAL_P33_SMPS_GPIO_H__

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

#include "../p33SMPS_devices.h"

typedef enum {
    GPIO_ANSEL = 0b000, // Analog/Digital Selection
    GPIO_TRIS  = 0b001, // Input/Output Selection
    GPIO_LAT   = 0b010, // High/Low Selection
    GPIO_ODC   = 0b011, // Open Drain/Push-Pull Selection
    GPIO_CNPU  = 0b100, // Weak Pull-Up Enable/Disable Selection
    GPIO_CNPD  = 0b101  // Weak Pull-Up Enable/Disable Selection
}GPIO_REGISTER_TYPE_e;

typedef enum {
    GPIO_PORT_A  = 0b000,  // GPIO is at port #0
    GPIO_PORT_B  = 0b001,  // GPIO is at port #1
    GPIO_PORT_C  = 0b010,  // GPIO is at port #2
    GPIO_PORT_D  = 0b011,  // GPIO is at port #3
    GPIO_PORT_E  = 0b100,  // GPIO is at port #4
    GPIO_PORT_F  = 0b101,  // GPIO is at port #5
    GPIO_PORT_G  = 0b110,  // GPIO is at port #6
    GPIO_PORT_H  = 0b111   // GPIO is at port #7
}GPIOx_PORT_e; // GPIO port index selection

typedef enum {
    GPIO_PIN_0  = 0b0000,  // GPIO is at port pin #0
    GPIO_PIN_1  = 0b0001,  // GPIO is at port pin #1
    GPIO_PIN_2  = 0b0010,  // GPIO is at port pin #2
    GPIO_PIN_3  = 0b0011,  // GPIO is at port pin #3
    GPIO_PIN_4  = 0b0100,  // GPIO is at port pin #4
    GPIO_PIN_5  = 0b0101,  // GPIO is at port pin #5
    GPIO_PIN_6  = 0b0110,  // GPIO is at port pin #6
    GPIO_PIN_7  = 0b0111,  // GPIO is at port pin #7
    GPIO_PIN_8  = 0b1000,  // GPIO is at port pin #8
    GPIO_PIN_9  = 0b1001,  // GPIO is at port pin #9
    GPIO_PIN_10 = 0b1010,  // GPIO is at port pin #10
    GPIO_PIN_11 = 0b1011,  // GPIO is at port pin #11
    GPIO_PIN_12 = 0b1100,  // GPIO is at port pin #12
    GPIO_PIN_13 = 0b1101,  // GPIO is at port pin #13
    GPIO_PIN_14 = 0b1110,  // GPIO is at port pin #14
    GPIO_PIN_15 = 0b1111,  // GPIO is at port pin #15
}GPIOx_PIN_e; // GPIO port pin index selection

typedef enum {
    GPIO_ANSEL_ANALOG      = 0b1,  // GPIO is analog input
    GPIO_ANSEL_ANx_DIGITAL = 0b0    // GPIO is digital I/O
}ANSELx_AD_e; // GPIO digital/analog selection

typedef enum {
    GPIO_TRIS_INPUT  = 0b1,  // GPIO is digital input
    GPIO_TRIS_OUTPUT = 0b0   // GPIOis digital output
}TRISx_IO_e; // GPIO digital input/output selection

typedef enum {
    GPIO_LAT_HIGH = 0b1,  // GPIO in digital mode HIGH
    GPIO_LAT_LOW  = 0b0   // GPIO in digital mode LOW
}LATx_HL_e; // GPIO HIGH/LOW selection

typedef enum {
    GPIO_ODC_OPEN_DRAIN = 0b1,  // GPIO is in open drain mode
    GPIO_ODC_PUSH_PULL  = 0b0   // GPIO is in push-pull mode
}ODCx_ODPP_e; // GPIO open drain/push-pull selection

typedef enum {
    GPIO_CNPU_ENABLED = 0b1,  // GPIO weak pull-up resistor enabled
    GPIO_CNPU_DISABLED  = 0b0 // GPIO weak pull-up resistor disabled
}CNPUx_ENABLE_e; // GPIO weak pull-up resistor enabled/disabled selection

typedef enum {
    GPIO_CNPD_ENABLED = 0b1,  // GPIO weak pull-down resistor enabled
    GPIO_CNPD_DISABLED  = 0b0 // GPIO weak pull-down resistor disabled
}CNPDx_ENABLE_e; // GPIO weak pull-down resistor enabled/disabled selection

/*!GPIO_CONFIG_t
 * ****************************************************************************************
 * The GPIO_CONFIG_t data structure holds all setting of a general purpose input/output (GPIO)
 * These settings can be set for any device pin. Some pin functions might not be available
 * such as analog inputs or remappable pins.
 * Please refer to the device data sheet for details.
 * ****************************************************************************************/
typedef struct {
    volatile GPIOx_PORT_e port : 3;      // Bit 2-0: Port index (0-7)
    volatile GPIOx_PIN_e  pin : 4;       // Bit 6-3: Port pin index (0-15)
    volatile ANSELx_AD_e  ad_select : 1; // Bit 7: ANSELx analog/digital selection (1/0)
    volatile TRISx_IO_e   io_select : 1; // Bit 8: TRISx input/output selection (1/0)
    volatile LATx_HL_e    hl_select : 1; // Bit 9: LATx high/low selection (1/0)
    volatile ODCx_ODPP_e  odpp_select : 1;   // Bit 10: ODCx open drain/push-pull mode selection (1/0)
    volatile CNPUx_ENABLE_e  wpu_enable : 1; // Bit 11: CNPUx weak pull-up resistor enabled/disabled selection (1/0)
    volatile CNPDx_ENABLE_e  wpd_enable : 1; // Bit 12: CNPDx weak pull-down resistor enabled/disabled selection (1/0)
    volatile unsigned : 1;               // Bit 13: (reserved)
    volatile unsigned : 1;               // Bit 14: (reserved)
    volatile unsigned : 1;               // Bit 15: (reserved)
}__attribute__((packed))GPIO_CONFIG_t;

typedef union {
    volatile GPIO_CONFIG_t bits;
    volatile uint16_t value;
}GPIO_DEVICE_PIN_CONFIG_t; // Device pin configuration



// ==============================================================================================
// PUBLIC FUNCTION PROTOTYPES
// ==============================================================================================


extern volatile uint16_t gpio_ansel_init(void);
extern volatile uint16_t gpio_cnpu_init(void);
extern volatile uint16_t gpio_cnpd_init(void);
extern volatile uint16_t gpio_odc_init(void);
extern volatile uint16_t gpio_tris_init(void);
extern volatile uint16_t gpio_lat_init(void);

extern volatile uint16_t gpio_init(void);


extern volatile uint16_t gpio_tris_config(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
extern volatile uint16_t gpio_set_tris(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
extern volatile uint16_t gpio_set_lat(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
extern volatile uint16_t gpio_set_odc(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
extern volatile uint16_t gpio_set_cnpu(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
extern volatile uint16_t gpio_set_cnpd(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);

extern volatile uint16_t gpio_set_io_config(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);


/* ********************************************************************************************** */
/* DEVICE SPECIFIC PIN-MAPPING                                                                    */
/* ********************************************************************************************** */

#if defined (__P33SMPS_CK__)
    
    // Generic device pin filter masks
    #define REG_PORTA_VALID_DATA_WRITE_MSK  0x001F
    #define REG_PORTA_VALID_DATA_READ_MSK   0x001F

    #define REG_PORTB_VALID_DATA_WRITE_MSK  0x039F
    #define REG_PORTB_VALID_DATA_READ_MSK   0x039F

    #define REG_PORTC_VALID_DATA_WRITE_MSK  0x00CF
    #define REG_PORTC_VALID_DATA_READ_MSK   0x00CF

    #define REG_PORTD_VALID_DATA_WRITE_MSK  0x2C00
    #define REG_PORTD_VALID_DATA_READ_MSK   0x2C00

    #define REG_PORTE_VALID_DATA_WRITE_MSK  0x000F
    #define REG_PORTE_VALID_DATA_READ_MSK   0x000F


    // Analog Pin declarations
    #ifdef ANSELA
      #define AN0_PORT  0  // Analog input ANx port register index
      #define AN0_PIN  0  // Analog input ANx port register bit index
      #define ANSEL_AN0_PORT  ANSELA  // Analog input ANx ANSEL port register
      #define ANSEL_AN0  _ANSELA0  // Analog input ANx ANSEL direct access
      #define ANSEL_AN0_DIGITAL  { asm volatile ("bclr _ANSELA, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN0_ANALOG  { asm volatile ("bset _ANSELA, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN0_INPUT  { asm volatile ("bset _TRISA, #0 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN0_OUTPUT  { asm volatile ("bclr _TRISA, #0 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN0_HIGH  { asm volatile ("bset _LATA, #0 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN0_LOW  { asm volatile ("bclr _LATA, #0 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN0_HIGH  { asm volatile ("bset _ODCA, #0 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN0_LOW  { asm volatile ("bclr _ODCA, #0 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN0_HIGH  { asm volatile ("bset _CNPUA, #0 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN0_LOW  { asm volatile ("bclr _CNPUA, #0 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN0_HIGH  { asm volatile ("bset _CNPDA, #0 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN0_LOW  { asm volatile ("bclr _CNPDA, #0 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN1_PORT  1  // Analog input ANx port register index
      #define AN1_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_AN1_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN1  _ANSELB2  // Analog input ANx ANSEL direct access
      #define ANSEL_AN1_DIGITAL  { asm volatile ("bclr _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN1_ANALOG  { asm volatile ("bset _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN1_INPUT  { asm volatile ("bset _TRISB, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN1_OUTPUT  { asm volatile ("bclr _TRISB, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN1_HIGH  { asm volatile ("bset _LATB, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN1_LOW  { asm volatile ("bclr _LATB, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN1_HIGH  { asm volatile ("bset _ODCB, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN1_LOW  { asm volatile ("bclr _ODCB, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN1_HIGH  { asm volatile ("bset _CNPUB, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN1_LOW  { asm volatile ("bclr _CNPUB, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN1_HIGH  { asm volatile ("bset _CNPDB, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN1_LOW  { asm volatile ("bclr _CNPDB, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN2_PORT  1  // Analog input ANx port register index
      #define AN2_PIN  7  // Analog input ANx port register bit index
      #define ANSEL_AN2_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN2  _ANSELB7  // Analog input ANx ANSEL direct access
      #define ANSEL_AN2_DIGITAL  { asm volatile ("bclr _ANSELB, #7 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN2_ANALOG  { asm volatile ("bset _ANSELB, #7 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN2_INPUT  { asm volatile ("bset _TRISB, #7 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN2_OUTPUT  { asm volatile ("bclr _TRISB, #7 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN2_HIGH  { asm volatile ("bset _LATB, #7 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN2_LOW  { asm volatile ("bclr _LATB, #7 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN2_HIGH  { asm volatile ("bset _ODCB, #7 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN2_LOW  { asm volatile ("bclr _ODCB, #7 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN2_HIGH  { asm volatile ("bset _CNPUB, #7 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN2_LOW  { asm volatile ("bclr _CNPUB, #7 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN2_HIGH  { asm volatile ("bset _CNPDB, #7 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN2_LOW  { asm volatile ("bclr _CNPDB, #7 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELA
      #define AN3_PORT  0  // Analog input ANx port register index
      #define AN3_PIN  3  // Analog input ANx port register bit index
      #define ANSEL_AN3_PORT  ANSELA  // Analog input ANx ANSEL port register
      #define ANSEL_AN3  _ANSELA3  // Analog input ANx ANSEL direct access
      #define ANSEL_AN3_DIGITAL  { asm volatile ("bclr _ANSELA, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN3_ANALOG  { asm volatile ("bset _ANSELA, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN3_INPUT  { asm volatile ("bset _TRISA, #3 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN3_OUTPUT  { asm volatile ("bclr _TRISA, #3 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN3_HIGH  { asm volatile ("bset _LATA, #3 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN3_LOW  { asm volatile ("bclr _LATA, #3 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN3_HIGH  { asm volatile ("bset _ODCA, #3 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN3_LOW  { asm volatile ("bclr _ODCA, #3 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN3_HIGH  { asm volatile ("bset _CNPUA, #3 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN3_LOW  { asm volatile ("bclr _CNPUA, #3 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN3_HIGH  { asm volatile ("bset _CNPDA, #3 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN3_LOW  { asm volatile ("bclr _CNPDA, #3 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELA
      #define AN4_PORT  0  // Analog input ANx port register index
      #define AN4_PIN  4  // Analog input ANx port register bit index
      #define ANSEL_AN4_PORT  ANSELA  // Analog input ANx ANSEL port register
      #define ANSEL_AN4  _ANSELA4  // Analog input ANx ANSEL direct access
      #define ANSEL_AN4_DIGITAL  { asm volatile ("bclr _ANSELA, #4 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN4_ANALOG  { asm volatile ("bset _ANSELA, #4 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN4_INPUT  { asm volatile ("bset _TRISA, #4 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN4_OUTPUT  { asm volatile ("bclr _TRISA, #4 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN4_HIGH  { asm volatile ("bset _LATA, #4 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN4_LOW  { asm volatile ("bclr _LATA, #4 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN4_HIGH  { asm volatile ("bset _ODCA, #4 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN4_LOW  { asm volatile ("bclr _ODCA, #4 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN4_HIGH  { asm volatile ("bset _CNPUA, #4 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN4_LOW  { asm volatile ("bclr _CNPUA, #4 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN4_HIGH  { asm volatile ("bset _CNPDA, #4 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN4_LOW  { asm volatile ("bclr _CNPDA, #4 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN5_PORT  1  // Analog input ANx port register index
      #define AN5_PIN  0  // Analog input ANx port register bit index
      #define ANSEL_AN5_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN5  _ANSELB0  // Analog input ANx ANSEL direct access
      #define ANSEL_AN5_DIGITAL  { asm volatile ("bclr _ANSELB, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN5_ANALOG  { asm volatile ("bset _ANSELB, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN5_INPUT  { asm volatile ("bset _TRISB, #0 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN5_OUTPUT  { asm volatile ("bclr _TRISB, #0 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN5_HIGH  { asm volatile ("bset _LATB, #0 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN5_LOW  { asm volatile ("bclr _LATB, #0 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN5_HIGH  { asm volatile ("bset _ODCB, #0 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN5_LOW  { asm volatile ("bclr _ODCB, #0 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN5_HIGH  { asm volatile ("bset _CNPUB, #0 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN5_LOW  { asm volatile ("bclr _CNPUB, #0 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN5_HIGH  { asm volatile ("bset _CNPDB, #0 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN5_LOW  { asm volatile ("bclr _CNPDB, #0 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN6_PORT  1  // Analog input ANx port register index
      #define AN6_PIN  1  // Analog input ANx port register bit index
      #define ANSEL_AN6_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN6  _ANSELB1  // Analog input ANx ANSEL direct access
      #define ANSEL_AN6_DIGITAL  { asm volatile ("bclr _ANSELB, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN6_ANALOG  { asm volatile ("bset _ANSELB, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN6_INPUT  { asm volatile ("bset _TRISB, #1 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN6_OUTPUT  { asm volatile ("bclr _TRISB, #1 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN6_HIGH  { asm volatile ("bset _LATB, #1 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN6_LOW  { asm volatile ("bclr _LATB, #1 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN6_HIGH  { asm volatile ("bset _ODCB, #1 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN6_LOW  { asm volatile ("bclr _ODCB, #1 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN6_HIGH  { asm volatile ("bset _CNPUB, #1 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN6_LOW  { asm volatile ("bclr _CNPUB, #1 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN6_HIGH  { asm volatile ("bset _CNPDB, #1 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN6_LOW  { asm volatile ("bclr _CNPDB, #1 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN7_PORT  1  // Analog input ANx port register index
      #define AN7_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_AN7_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN7  _ANSELB2  // Analog input ANx ANSEL direct access
      #define ANSEL_AN7_DIGITAL  { asm volatile ("bclr _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN7_ANALOG  { asm volatile ("bset _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN7_INPUT  { asm volatile ("bset _TRISB, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN7_OUTPUT  { asm volatile ("bclr _TRISB, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN7_HIGH  { asm volatile ("bset _LATB, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN7_LOW  { asm volatile ("bclr _LATB, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN7_HIGH  { asm volatile ("bset _ODCB, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN7_LOW  { asm volatile ("bclr _ODCB, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN7_HIGH  { asm volatile ("bset _CNPUB, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN7_LOW  { asm volatile ("bclr _CNPUB, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN7_HIGH  { asm volatile ("bset _CNPDB, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN7_LOW  { asm volatile ("bclr _CNPDB, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN8_PORT  1  // Analog input ANx port register index
      #define AN8_PIN  3  // Analog input ANx port register bit index
      #define ANSEL_AN8_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN8  _ANSELB3  // Analog input ANx ANSEL direct access
      #define ANSEL_AN8_DIGITAL  { asm volatile ("bclr _ANSELB, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN8_ANALOG  { asm volatile ("bset _ANSELB, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN8_INPUT  { asm volatile ("bset _TRISB, #3 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN8_OUTPUT  { asm volatile ("bclr _TRISB, #3 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN8_HIGH  { asm volatile ("bset _LATB, #3 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN8_LOW  { asm volatile ("bclr _LATB, #3 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN8_HIGH  { asm volatile ("bset _ODCB, #3 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN8_LOW  { asm volatile ("bclr _ODCB, #3 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN8_HIGH  { asm volatile ("bset _CNPUB, #3 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN8_LOW  { asm volatile ("bclr _CNPUB, #3 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN8_HIGH  { asm volatile ("bset _CNPDB, #3 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN8_LOW  { asm volatile ("bclr _CNPDB, #3 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELA
      #define AN9_PORT  0  // Analog input ANx port register index
      #define AN9_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_AN9_PORT  ANSELA  // Analog input ANx ANSEL port register
      #define ANSEL_AN9  _ANSELA2  // Analog input ANx ANSEL direct access
      #define ANSEL_AN9_DIGITAL  { asm volatile ("bclr _ANSELA, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN9_ANALOG  { asm volatile ("bset _ANSELA, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN9_INPUT  { asm volatile ("bset _TRISA, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN9_OUTPUT  { asm volatile ("bclr _TRISA, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN9_HIGH  { asm volatile ("bset _LATA, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN9_LOW  { asm volatile ("bclr _LATA, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN9_HIGH  { asm volatile ("bset _ODCA, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN9_LOW  { asm volatile ("bclr _ODCA, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN9_HIGH  { asm volatile ("bset _CNPUA, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN9_LOW  { asm volatile ("bclr _CNPUA, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN9_HIGH  { asm volatile ("bset _CNPDA, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN9_LOW  { asm volatile ("bclr _CNPDA, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN10_PORT  1  // Analog input ANx port register index
      #define AN10_PIN  8  // Analog input ANx port register bit index
      #define ANSEL_AN10_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN10  _ANSELB8  // Analog input ANx ANSEL direct access
      #define ANSEL_AN10_DIGITAL  { asm volatile ("bclr _ANSELB, #8 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN10_ANALOG  { asm volatile ("bset _ANSELB, #8 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN10_INPUT  { asm volatile ("bset _TRISB, #8 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN10_OUTPUT  { asm volatile ("bclr _TRISB, #8 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN10_HIGH  { asm volatile ("bset _LATB, #8 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN10_LOW  { asm volatile ("bclr _LATB, #8 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN10_HIGH  { asm volatile ("bset _ODCB, #8 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN10_LOW  { asm volatile ("bclr _ODCB, #8 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN10_HIGH  { asm volatile ("bset _CNPUB, #8 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN10_LOW  { asm volatile ("bclr _CNPUB, #8 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN10_HIGH  { asm volatile ("bset _CNPDB, #8 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN10_LOW  { asm volatile ("bclr _CNPDB, #8 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELB
      #define AN11_PORT  1  // Analog input ANx port register index
      #define AN11_PIN  9  // Analog input ANx port register bit index
      #define ANSEL_AN11_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_AN11  _ANSELB9  // Analog input ANx ANSEL direct access
      #define ANSEL_AN11_DIGITAL  { asm volatile ("bclr _ANSELB, #9 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN11_ANALOG  { asm volatile ("bset _ANSELB, #9 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN11_INPUT  { asm volatile ("bset _TRISB, #9 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN11_OUTPUT  { asm volatile ("bclr _TRISB, #9 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN11_HIGH  { asm volatile ("bset _LATB, #9 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN11_LOW  { asm volatile ("bclr _LATB, #9 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN11_HIGH  { asm volatile ("bset _ODCB, #9 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN11_LOW  { asm volatile ("bclr _ODCB, #9 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN11_HIGH  { asm volatile ("bset _CNPUB, #9 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN11_LOW  { asm volatile ("bclr _CNPUB, #9 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN11_HIGH  { asm volatile ("bset _CNPDB, #9 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN11_LOW  { asm volatile ("bclr _CNPDB, #9 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN12_PORT  2  // Analog input ANx port register index
      #define AN12_PIN  0  // Analog input ANx port register bit index
      #define ANSEL_AN12_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN12  _ANSELC0  // Analog input ANx ANSEL direct access
      #define ANSEL_AN12_DIGITAL  { asm volatile ("bclr _ANSELC, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN12_ANALOG  { asm volatile ("bset _ANSELC, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN12_INPUT  { asm volatile ("bset _TRISC, #0 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN12_OUTPUT  { asm volatile ("bclr _TRISC, #0 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN12_HIGH  { asm volatile ("bset _LATC, #0 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN12_LOW  { asm volatile ("bclr _LATC, #0 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN12_HIGH  { asm volatile ("bset _ODCC, #0 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN12_LOW  { asm volatile ("bclr _ODCC, #0 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN12_HIGH  { asm volatile ("bset _CNPUC, #0 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN12_LOW  { asm volatile ("bclr _CNPUC, #0 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN12_HIGH  { asm volatile ("bset _CNPDC, #0 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN12_LOW  { asm volatile ("bclr _CNPDC, #0 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN13_PORT  2  // Analog input ANx port register index
      #define AN13_PIN  1  // Analog input ANx port register bit index
      #define ANSEL_AN13_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN13  _ANSELC1  // Analog input ANx ANSEL direct access
      #define ANSEL_AN13_DIGITAL  { asm volatile ("bclr _ANSELC, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN13_ANALOG  { asm volatile ("bset _ANSELC, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN13_INPUT  { asm volatile ("bset _TRISC, #1 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN13_OUTPUT  { asm volatile ("bclr _TRISC, #1 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN13_HIGH  { asm volatile ("bset _LATC, #1 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN13_LOW  { asm volatile ("bclr _LATC, #1 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN13_HIGH  { asm volatile ("bset _ODCC, #1 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN13_LOW  { asm volatile ("bclr _ODCC, #1 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN13_HIGH  { asm volatile ("bset _CNPUC, #1 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN13_LOW  { asm volatile ("bclr _CNPUC, #1 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN13_HIGH  { asm volatile ("bset _CNPDC, #1 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN13_LOW  { asm volatile ("bclr _CNPDC, #1 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN14_PORT  2  // Analog input ANx port register index
      #define AN14_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_AN14_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN14  _ANSELC2  // Analog input ANx ANSEL direct access
      #define ANSEL_AN14_DIGITAL  { asm volatile ("bclr _ANSELC, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN14_ANALOG  { asm volatile ("bset _ANSELC, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN14_INPUT  { asm volatile ("bset _TRISC, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN14_OUTPUT  { asm volatile ("bclr _TRISC, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN14_HIGH  { asm volatile ("bset _LATC, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN14_LOW  { asm volatile ("bclr _LATC, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN14_HIGH  { asm volatile ("bset _ODCC, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN14_LOW  { asm volatile ("bclr _ODCC, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN14_HIGH  { asm volatile ("bset _CNPUC, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN14_LOW  { asm volatile ("bclr _CNPUC, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN14_HIGH  { asm volatile ("bset _CNPDC, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN14_LOW  { asm volatile ("bclr _CNPDC, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN15_PORT  2  // Analog input ANx port register index
      #define AN15_PIN  3  // Analog input ANx port register bit index
      #define ANSEL_AN15_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN15  _ANSELC3  // Analog input ANx ANSEL direct access
      #define ANSEL_AN15_DIGITAL  { asm volatile ("bclr _ANSELC, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN15_ANALOG  { asm volatile ("bset _ANSELC, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN15_INPUT  { asm volatile ("bset _TRISC, #3 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN15_OUTPUT  { asm volatile ("bclr _TRISC, #3 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN15_HIGH  { asm volatile ("bset _LATC, #3 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN15_LOW  { asm volatile ("bclr _LATC, #3 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN15_HIGH  { asm volatile ("bset _ODCC, #3 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN15_LOW  { asm volatile ("bclr _ODCC, #3 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN15_HIGH  { asm volatile ("bset _CNPUC, #3 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN15_LOW  { asm volatile ("bclr _CNPUC, #3 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN15_HIGH  { asm volatile ("bset _CNPDC, #3 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN15_LOW  { asm volatile ("bclr _CNPDC, #3 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN16_PORT  2  // Analog input ANx port register index
      #define AN16_PIN  7  // Analog input ANx port register bit index
      #define ANSEL_AN16_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN16  _ANSELC7  // Analog input ANx ANSEL direct access
      #define ANSEL_AN16_DIGITAL  { asm volatile ("bclr _ANSELC, #7 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN16_ANALOG  { asm volatile ("bset _ANSELC, #7 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN16_INPUT  { asm volatile ("bset _TRISC, #7 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN16_OUTPUT  { asm volatile ("bclr _TRISC, #7 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN16_HIGH  { asm volatile ("bset _LATC, #7 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN16_LOW  { asm volatile ("bclr _LATC, #7 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN16_HIGH  { asm volatile ("bset _ODCC, #7 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN16_LOW  { asm volatile ("bclr _ODCC, #7 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN16_HIGH  { asm volatile ("bset _CNPUC, #7 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN16_LOW  { asm volatile ("bclr _CNPUC, #7 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN16_HIGH  { asm volatile ("bset _CNPDC, #7 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN16_LOW  { asm volatile ("bclr _CNPDC, #7 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELC
      #define AN17_PORT  2  // Analog input ANx port register index
      #define AN17_PIN  6  // Analog input ANx port register bit index
      #define ANSEL_AN17_PORT  ANSELC  // Analog input ANx ANSEL port register
      #define ANSEL_AN17  _ANSELC6  // Analog input ANx ANSEL direct access
      #define ANSEL_AN17_DIGITAL  { asm volatile ("bclr _ANSELC, #6 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN17_ANALOG  { asm volatile ("bset _ANSELC, #6 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN17_INPUT  { asm volatile ("bset _TRISC, #6 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN17_OUTPUT  { asm volatile ("bclr _TRISC, #6 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN17_HIGH  { asm volatile ("bset _LATC, #6 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN17_LOW  { asm volatile ("bclr _LATC, #6 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN17_HIGH  { asm volatile ("bset _ODCC, #6 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN17_LOW  { asm volatile ("bclr _ODCC, #6 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN17_HIGH  { asm volatile ("bset _CNPUC, #6 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN17_LOW  { asm volatile ("bclr _CNPUC, #6 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN17_HIGH  { asm volatile ("bset _CNPDC, #6 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN17_LOW  { asm volatile ("bclr _CNPDC, #6 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELD
      #define AN18_PORT  3  // Analog input ANx port register index
      #define AN18_PIN  10  // Analog input ANx port register bit index
      #define ANSEL_AN18_PORT  ANSELD  // Analog input ANx ANSEL port register
      #define ANSEL_AN18  _ANSELD10  // Analog input ANx ANSEL direct access
      #define ANSEL_AN18_DIGITAL  { asm volatile ("bclr _ANSELD, #10 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN18_ANALOG  { asm volatile ("bset _ANSELD, #10 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN18_INPUT  { asm volatile ("bset _TRISD, #10 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN18_OUTPUT  { asm volatile ("bclr _TRISD, #10 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN18_HIGH  { asm volatile ("bset _LATD, #10 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN18_LOW  { asm volatile ("bclr _LATD, #10 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN18_HIGH  { asm volatile ("bset _ODCD, #10 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN18_LOW  { asm volatile ("bclr _ODCD, #10 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN18_HIGH  { asm volatile ("bset _CNPUD, #10 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN18_LOW  { asm volatile ("bclr _CNPUD, #10 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN18_HIGH  { asm volatile ("bset _CNPDD, #10 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN18_LOW  { asm volatile ("bclr _CNPDD, #10 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELD
      #define AN19_PORT  3  // Analog input ANx port register index
      #define AN19_PIN  11  // Analog input ANx port register bit index
      #define ANSEL_AN19_PORT  ANSELD  // Analog input ANx ANSEL port register
      #define ANSEL_AN19  _ANSELD11  // Analog input ANx ANSEL direct access
      #define ANSEL_AN19_DIGITAL  { asm volatile ("bclr _ANSELD, #11 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN19_ANALOG  { asm volatile ("bset _ANSELD, #11 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN19_INPUT  { asm volatile ("bset _TRISD, #11 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN19_OUTPUT  { asm volatile ("bclr _TRISD, #11 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN19_HIGH  { asm volatile ("bset _LATD, #11 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN19_LOW  { asm volatile ("bclr _LATD, #11 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN19_HIGH  { asm volatile ("bset _ODCD, #11 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN19_LOW  { asm volatile ("bclr _ODCD, #11 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN19_HIGH  { asm volatile ("bset _CNPUD, #11 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN19_LOW  { asm volatile ("bclr _CNPUD, #11 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN19_HIGH  { asm volatile ("bset _CNPDD, #11 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN19_LOW  { asm volatile ("bclr _CNPDD, #11 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
/*
    #ifdef ANSELE
      #define AN20_PORT  4  // Analog input ANx port register index
      #define AN20_PIN  0  // Analog input ANx port register bit index
      #define ANSEL_AN20_PORT  ANSELE  // Analog input ANx ANSEL port register
      #define ANSEL_AN20  _ANSELE0  // Analog input ANx ANSEL direct access
      #define ANSEL_AN20_DIGITAL  { asm volatile ("bclr _ANSELE, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN20_ANALOG  { asm volatile ("bset _ANSELE, #0 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN20_INPUT  { asm volatile ("bset _TRISE, #0 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN20_OUTPUT  { asm volatile ("bclr _TRISE, #0 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN20_HIGH  { asm volatile ("bset _LATE, #0 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN20_LOW  { asm volatile ("bclr _LATE, #0 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN20_HIGH  { asm volatile ("bset _ODCE, #0 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN20_LOW  { asm volatile ("bclr _ODCE, #0 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN20_HIGH  { asm volatile ("bset _CNPUE, #0 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN20_LOW  { asm volatile ("bclr _CNPUE, #0 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN20_HIGH  { asm volatile ("bset _CNPDE, #0 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN20_LOW  { asm volatile ("bclr _CNPDE, #0 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELE
      #define AN21_PORT  4  // Analog input ANx port register index
      #define AN21_PIN  1  // Analog input ANx port register bit index
      #define ANSEL_AN21_PORT  ANSELE  // Analog input ANx ANSEL port register
      #define ANSEL_AN21  _ANSELE1  // Analog input ANx ANSEL direct access
      #define ANSEL_AN21_DIGITAL  { asm volatile ("bclr _ANSELE, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN21_ANALOG  { asm volatile ("bset _ANSELE, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN21_INPUT  { asm volatile ("bset _TRISE, #1 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN21_OUTPUT  { asm volatile ("bclr _TRISE, #1 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN21_HIGH  { asm volatile ("bset _LATE, #1 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN21_LOW  { asm volatile ("bclr _LATE, #1 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN21_HIGH  { asm volatile ("bset _ODCE, #1 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN21_LOW  { asm volatile ("bclr _ODCE, #1 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN21_HIGH  { asm volatile ("bset _CNPUE, #1 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN21_LOW  { asm volatile ("bclr _CNPUE, #1 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN21_HIGH  { asm volatile ("bset _CNPDE, #1 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN21_LOW  { asm volatile ("bclr _CNPDE, #1 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELE
      #define AN22_PORT  4  // Analog input ANx port register index
      #define AN22_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_AN22_PORT  ANSELE  // Analog input ANx ANSEL port register
      #define ANSEL_AN22  _ANSELE2  // Analog input ANx ANSEL direct access
      #define ANSEL_AN22_DIGITAL  { asm volatile ("bclr _ANSELE, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN22_ANALOG  { asm volatile ("bset _ANSELE, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN22_INPUT  { asm volatile ("bset _TRISE, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN22_OUTPUT  { asm volatile ("bclr _TRISE, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN22_HIGH  { asm volatile ("bset _LATE, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN22_LOW  { asm volatile ("bclr _LATE, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN22_HIGH  { asm volatile ("bset _ODCE, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN22_LOW  { asm volatile ("bclr _ODCE, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN22_HIGH  { asm volatile ("bset _CNPUE, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN22_LOW  { asm volatile ("bclr _CNPUE, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN22_HIGH  { asm volatile ("bset _CNPDE, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN22_LOW  { asm volatile ("bclr _CNPDE, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELE
      #define AN23_PORT  4  // Analog input ANx port register index
      #define AN23_PIN  3  // Analog input ANx port register bit index
      #define ANSEL_AN23_PORT  ANSELE  // Analog input ANx ANSEL port register
      #define ANSEL_AN23  _ANSELE3  // Analog input ANx ANSEL direct access
      #define ANSEL_AN23_DIGITAL  { asm volatile ("bclr _ANSELE, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_AN23_ANALOG  { asm volatile ("bset _ANSELE, #3 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_AN23_INPUT  { asm volatile ("bset _TRISE, #3 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_AN23_OUTPUT  { asm volatile ("bclr _TRISE, #3 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_AN23_HIGH  { asm volatile ("bset _LATE, #3 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_AN23_LOW  { asm volatile ("bclr _LATE, #3 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_AN23_HIGH  { asm volatile ("bset _ODCE, #3 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_AN23_LOW  { asm volatile ("bclr _ODCE, #3 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_AN23_HIGH  { asm volatile ("bset _CNPUE, #3 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_AN23_LOW  { asm volatile ("bclr _CNPUE, #3 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_AN23_HIGH  { asm volatile ("bset _CNPDE, #3 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_AN23_LOW  { asm volatile ("bclr _CNPDE, #3 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
*/
    #ifdef ANSELB
      #define ANA0_PORT  1  // Analog input ANx port register index
      #define ANA0_PIN  2  // Analog input ANx port register bit index
      #define ANSEL_ANA0_PORT  ANSELB  // Analog input ANx ANSEL port register
      #define ANSEL_ANA0  _ANSELB2  // Analog input ANx ANSEL direct access
      #define ANSEL_ANA0_DIGITAL  { asm volatile ("bclr _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_ANA0_ANALOG  { asm volatile ("bset _ANSELB, #2 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_ANA0_INPUT  { asm volatile ("bset _TRISB, #2 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_ANA0_OUTPUT  { asm volatile ("bclr _TRISB, #2 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_ANA0_HIGH  { asm volatile ("bset _LATB, #2 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_ANA0_LOW  { asm volatile ("bclr _LATB, #2 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_ANA0_HIGH  { asm volatile ("bset _ODCB, #2 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_ANA0_LOW  { asm volatile ("bclr _ODCB, #2 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_ANA0_HIGH  { asm volatile ("bset _CNPUB, #2 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_ANA0_LOW  { asm volatile ("bclr _CNPUB, #2 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_ANA0_HIGH  { asm volatile ("bset _CNPDB, #2 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_ANA0_LOW  { asm volatile ("bclr _CNPDB, #2 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif
    #ifdef ANSELA
      #define ANA1_PORT  0  // Analog input ANx port register index
      #define ANA1_PIN  1  // Analog input ANx port register bit index
      #define ANSEL_ANA1_PORT  ANSELA  // Analog input ANx ANSEL port register
      #define ANSEL_ANA1  _ANSELA1  // Analog input ANx ANSEL direct access
      #define ANSEL_ANA1_DIGITAL  { asm volatile ("bclr _ANSELA, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define ANSEL_ANA1_ANALOG  { asm volatile ("bset _ANSELA, #1 \n"); }  // Set analog input ANx for digital function in ANSEL register
      #define TRIS_ANA1_INPUT  { asm volatile ("bset _TRISA, #1 \n"); }  // Set pin ANx as input in TRIS register
      #define TRIS_ANA1_OUTPUT  { asm volatile ("bclr _TRISA, #1 \n"); }  // Set pin ANx as output in TRIS register
      #define LAT_ANA1_HIGH  { asm volatile ("bset _LATA, #1 \n"); }  // Set pin ANx HIGH in digital mode in LAT register
      #define LAT_ANA1_LOW  { asm volatile ("bclr _LATA, #1 \n"); }  // Set pin ANx LOW in digital mode in LAT register
      #define ODC_ANA1_HIGH  { asm volatile ("bset _ODCA, #1 \n"); }  // Set pin ANx in Open Drain mode in ODC register
      #define ODC_ANA1_LOW  { asm volatile ("bclr _ODCA, #1 \n"); }  // Set pin ANx in Push-Pull mode in ODC register
      #define CNPU_ANA1_HIGH  { asm volatile ("bset _CNPUA, #1 \n"); }  // Enable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPU_ANA1_LOW  { asm volatile ("bclr _CNPUA, #1 \n"); }  // Disable weak pull-up resistor pin at pin ANx in CNPU register
      #define CNPD_ANA1_HIGH  { asm volatile ("bset _CNPDA, #1 \n"); }  // Enable weak pull-down resistor pin at pin ANx in CNPD register
      #define CNPD_ANA1_LOW  { asm volatile ("bclr _CNPDA, #1 \n"); }  // Disable weak pull-down resistor pin at pin ANx in CNPD register
    #endif

/*!ANSELx_REG_e
 * ****************************************************************************************
 * The ANSELx_REG_e enumeration represents ANSELx port register banks with integer numbers,
 * where 0=ANSELA, 1=ANSELB, 2=ANSELC, 3=ANSELD and 4=ANSELE.
 *
 * The range of registers will be expanded when larger pin-count devices are released.
 * ****************************************************************************************/
    typedef enum {
        #ifdef ANSELA
        ANSEL_REG_AN0 = 0, // Analog input AN0 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN1 = 1, // Analog input AN1 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN2 = 1, // Analog input AN2 ANSEL register index
        #endif
        #ifdef ANSELA
        ANSEL_REG_AN3 = 0, // Analog input AN3 ANSEL register index
        #endif
        #ifdef ANSELA
        ANSEL_REG_AN4 = 0, // Analog input AN4 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN5 = 1, // Analog input AN5 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN6 = 1, // Analog input AN6 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN7 = 1, // Analog input AN7 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN8 = 1, // Analog input AN8 ANSEL register index
        #endif
        #ifdef ANSELA
        ANSEL_REG_AN9 = 0, // Analog input AN9 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN10 = 1, // Analog input AN10 ANSEL register index
        #endif
        #ifdef ANSELB
        ANSEL_REG_AN11 = 1, // Analog input AN11 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN12 = 2, // Analog input AN12 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN13 = 2, // Analog input AN13 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN14 = 2, // Analog input AN14 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN15 = 2, // Analog input AN15 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN16 = 2, // Analog input AN16 ANSEL register index
        #endif
        #ifdef ANSELC
        ANSEL_REG_AN17 = 2, // Analog input AN17 ANSEL register index
        #endif
        #ifdef ANSELD
        ANSEL_REG_AN18 = 3, // Analog input AN18 ANSEL register index
        #endif
        #ifdef ANSELD
        ANSEL_REG_AN19 = 3, // Analog input AN19 ANSEL register index
        #endif
//        #ifdef ANSELE
//        ANSEL_REG_AN20 = 4, // Analog input AN20 ANSEL register index
//        #endif
//        #ifdef ANSELE
//        ANSEL_REG_AN21 = 4, // Analog input AN21 ANSEL register index
//        #endif
//        #ifdef ANSELE
//        ANSEL_REG_AN22 = 4, // Analog input AN22 ANSEL register index
//        #endif
//        #ifdef ANSELE
//        ANSEL_REG_AN23 = 4, // Analog input AN23 ANSEL register index
//        #endif
        #ifdef ANSELB
        ANSEL_REG_ANA0 = 1, // Analog input ANA0 ANSEL register index
        #endif
        #ifdef ANSELA
        ANSEL_REG_ANA1 = 0, // Analog input ANA1 ANSEL register index
        #endif
    }ANSELx_REG_e;  // ANSELx Register index where 0=Port A, 1=Port B, 2=Port C , 3=Port D, 4=Port E

/*!ANSELx_PIN_e
 * ****************************************************************************************
 * The ANSELx_PIN_e enumeration represents ANSELx port register pin index with integer numbers,
 * where 0=ANSELx0, 1=ANSELx1, 2=ANSELx2, etc.
 *
 * The range of indices is limited to 0-15.
 * ****************************************************************************************/
    typedef enum {
        #ifdef ANSELA
        ANSEL_PIN_AN0 = 0, // Analog input AN0 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN1 = 2, // Analog input AN1 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN2 = 7, // Analog input AN2 ANSEL register bit index
        #endif
        #ifdef ANSELA
        ANSEL_PIN_AN3 = 3, // Analog input AN3 ANSEL register bit index
        #endif
        #ifdef ANSELA
        ANSEL_PIN_AN4 = 4, // Analog input AN4 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN5 = 0, // Analog input AN5 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN6 = 1, // Analog input AN6 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN7 = 2, // Analog input AN7 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN8 = 3, // Analog input AN8 ANSEL register bit index
        #endif
        #ifdef ANSELA
        ANSEL_PIN_AN9 = 2, // Analog input AN9 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN10 = 8, // Analog input AN10 ANSEL register bit index
        #endif
        #ifdef ANSELB
        ANSEL_PIN_AN11 = 9, // Analog input AN11 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN12 = 0, // Analog input AN12 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN13 = 1, // Analog input AN13 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN14 = 2, // Analog input AN14 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN15 = 3, // Analog input AN15 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN16 = 7, // Analog input AN16 ANSEL register bit index
        #endif
        #ifdef ANSELC
        ANSEL_PIN_AN17 = 6, // Analog input AN17 ANSEL register bit index
        #endif
        #ifdef ANSELD
        ANSEL_PIN_AN18 = 10, // Analog input AN18 ANSEL register bit index
        #endif
        #ifdef ANSELD
        ANSEL_PIN_AN19 = 11, // Analog input AN19 ANSEL register bit index
        #endif
//        #ifdef ANSELE
//        ANSEL_PIN_AN20 = 0, // Analog input AN20 ANSEL register bit index
//        #endif
//        #ifdef ANSELE
//        ANSEL_PIN_AN21 = 1, // Analog input AN21 ANSEL register bit index
//        #endif
//        #ifdef ANSELE
//        ANSEL_PIN_AN22 = 2, // Analog input AN22 ANSEL register bit index
//        #endif
//        #ifdef ANSELE
//        ANSEL_PIN_AN23 = 3, // Analog input AN23 ANSEL register bit index
//        #endif
        #ifdef ANSELB
        ANSEL_PIN_ANA0 = 2, // Analog input ANA0 ANSEL register bit index
        #endif
        #ifdef ANSELA
        ANSEL_PIN_ANA1 = 1, // Analog input ANA1 ANSEL register bit index
        #endif
    }ANSELx_PIN_e;  // ANSELx Register index where 0=Port A, 1=Port B, 2=Port C , 3=Port D, 4=Port E


#else
    #pragma message "selected device not supported by GPIO peripheral driver libraries"

#endif



#endif	/* __MCAL_P33_SMPS_GPIO_H__ */

