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
/*!p33SMPS_gpio.c
 * ***************************************************************************
 *
 * File:   p33SMPS_gpio.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/

/* ToDo: 
 * Port E registers had to be disabled because of failing compilation of user project.
 * THe library project configuration is set for the superset device of supported families.
 * When a smaller device is specified in the user project, compilation fails.
 */

#include "p33SMPS_gpio.h"

// Private Function Prototypes
volatile uint16_t gpio_write_config(volatile GPIO_REGISTER_TYPE_e reg_type, volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg);
volatile uint16_t gpio_clear_config(volatile GPIO_REGISTER_TYPE_e reg_type, volatile bool bit_value);


inline volatile uint16_t gpio_init(void) {

    volatile uint16_t fres = 1;
    
    fres &= gpio_clear_config(GPIO_ANSEL, false); // reset port pin analog/digital input setting
    fres &= gpio_clear_config(GPIO_TRIS, true);   // reset port pin weak pull-up resistor setting
    fres &= gpio_clear_config(GPIO_LAT, false);   // reset port pin weak pull-down resistor setting
    fres &= gpio_clear_config(GPIO_ODC, false);   // reset port pin open drain setting
    fres &= gpio_clear_config(GPIO_CNPU, false);  // reset port pin logic direction setting
    fres &= gpio_clear_config(GPIO_CNPD, false);  // reset port pin latch setting
    
    return (fres);
    
}


inline volatile uint16_t gpio_set_io_config(volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg) {
    
    volatile uint16_t fres = 1;

    fres &= gpio_write_config(GPIO_ANSEL, pin_cfg);
    fres &= gpio_write_config(GPIO_TRIS, pin_cfg);
    fres &= gpio_write_config(GPIO_LAT, pin_cfg);
    fres &= gpio_write_config(GPIO_ODC, pin_cfg);
    fres &= gpio_write_config(GPIO_CNPU, pin_cfg);
    fres &= gpio_write_config(GPIO_CNPD, pin_cfg);
    
    return(fres);
}



inline volatile uint16_t gpio_clear_config(volatile GPIO_REGISTER_TYPE_e reg_type, volatile bool bit_value) {
    
    volatile uint16_t fres = 1;
    volatile uint16_t regval = 0;
    
    // ToDo: Device port detection is not working across projects. 
    // Currently this only can be resolved by adding devices to the project configuration
    // Thus, port numbers from A-E have been added as default. This will cause compiler errors
    // when using smaller devices. 
    
    if ( bit_value ) regval = 0xFFFF;
    
    /* Reset all device pins to digital function */
    
    switch (reg_type) {

        case GPIO_ANSEL: 
            
            #ifdef ANSELA
            ANSELA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (ANSELA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ANSELB
            ANSELB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (ANSELB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ANSELC
            ANSELC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (ANSELC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ANSELD
            ANSELD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (ANSELD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef ANSELE
//            ANSELE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (ANSELE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif

            break;
                
        case GPIO_TRIS: 
            
            #ifdef TRISA
            TRISA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (TRISA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef TRISB
            TRISB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (TRISB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef TRISC
            TRISC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (TRISC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef TRISD
            TRISD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (TRISD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef TRISE
//            TRISE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (TRISE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif

            break;

        case GPIO_LAT: 
            
            #ifdef LATA
            LATA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (LATA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef LATB
            LATB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (LATB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef LATC
            LATC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (LATC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef LATD
            LATD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (LATD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef LATE
//            LATE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (LATE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif

            break;

        case GPIO_ODC: 
            
            #ifdef ODCA
            ODCA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (ODCA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ODCB
            ODCB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (ODCB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ODCC
            ODCC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (ODCC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef ODCD
            ODCD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (ODCD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef ODCE
//            ODCE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (ODCE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif

            break;

        case GPIO_CNPU: 

            #ifdef CNPUA
            CNPUA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (CNPUA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPUB
            CNPUB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (CNPUB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPUC
            CNPUC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (CNPUC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPUD
            CNPUD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (CNPUD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef CNPUE
//            CNPUE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (CNPUE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif

            break;

        case GPIO_CNPD: 
            
            #ifdef CNPDA
            CNPDA = (regval & REG_PORTA_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTA_VALID_DATA_WRITE_MSK) == (CNPDA & REG_PORTA_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPDB
            CNPDB = (regval & REG_PORTB_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTB_VALID_DATA_WRITE_MSK) == (CNPDB & REG_PORTB_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPDC
            CNPDC = (regval & REG_PORTC_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTC_VALID_DATA_WRITE_MSK) == (CNPDC & REG_PORTC_VALID_DATA_WRITE_MSK));
            #endif
            #ifdef CNPDD
            CNPDD = (regval & REG_PORTD_VALID_DATA_WRITE_MSK);
            fres &= (volatile bool)((regval & REG_PORTD_VALID_DATA_WRITE_MSK) == (CNPDD & REG_PORTD_VALID_DATA_WRITE_MSK));
            #endif
//            #ifdef CNPDE
//            CNPDE = (regval & REG_PORTE_VALID_DATA_WRITE_MSK);
//            fres &= (volatile bool)((regval & REG_PORTE_VALID_DATA_WRITE_MSK) == (CNPDE & REG_PORTE_VALID_DATA_WRITE_MSK));
//            #endif
            
            break;

        default:
            return(0);
            break;
    }


    // Return success/failure
    return(fres);
}

inline volatile uint16_t gpio_write_config(volatile GPIO_REGISTER_TYPE_e reg_type, volatile GPIO_DEVICE_PIN_CONFIG_t pin_cfg) {
    
    volatile uint16_t fres = 1;
    volatile uint16_t *regptr16;
    volatile uint16_t regbuf = 0;
    volatile uint16_t regval = 0;
    volatile uint16_t regmask = 0;
    
    switch(reg_type) {
        
        case GPIO_ANSEL:

            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.ad_select << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef ANSELA
                    regptr16 = (volatile uint16_t *)&ANSELA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
                case 1:
                    #ifdef ANSELB
                    regptr16 = (volatile uint16_t *)&ANSELB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef ANSELC
                    regptr16 = (volatile uint16_t *)&ANSELC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef ANSELD
                    regptr16 = (volatile uint16_t *)&ANSELD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
//                case 4:
//                    #ifdef ANSELE
//                    regptr16 = (volatile uint16_t *)&ANSELE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.ad_select) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }
            
            break;
            
        case GPIO_TRIS:

            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.io_select << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef TRISA
                    regptr16 = (volatile uint16_t *)&TRISA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
                case 1:
                    #ifdef TRISB
                    regptr16 = (volatile uint16_t *)&TRISB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef TRISC
                    regptr16 = (volatile uint16_t *)&TRISC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef TRISD
                    regptr16 = (volatile uint16_t *)&TRISD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
//                case 4:
//                    #ifdef TRISE
//                    regptr16 = (volatile uint16_t *)&TRISE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.io_select) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }

            break;
            
        case GPIO_LAT:

            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.hl_select << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef LATA
                    regptr16 = (volatile uint16_t *)&LATA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
                case 1:
                    #ifdef LATB
                    regptr16 = (volatile uint16_t *)&LATB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef LATC
                    regptr16 = (volatile uint16_t *)&LATC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef LATD
                    regptr16 = (volatile uint16_t *)&LATD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
//                case 4:
//                    #ifdef LATE
//                    regptr16 = (volatile uint16_t *)&LATE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.hl_select) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }

            break;
            
        case GPIO_ODC:

            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.odpp_select << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef ODCA
                    regptr16 = (volatile uint16_t *)&ODCA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
                case 1:
                    #ifdef ODCB
                    regptr16 = (volatile uint16_t *)&ODCB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef ODCC
                    regptr16 = (volatile uint16_t *)&ODCC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef ODCD
                    regptr16 = (volatile uint16_t *)&ODCD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
//                case 4:
//                    #ifdef ODCE
//                    regptr16 = (volatile uint16_t *)&ODCE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.odpp_select) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }

            break;
            
        case GPIO_CNPU:

            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.wpu_enable << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef CNPUA
                    regptr16 = (volatile uint16_t *)&CNPUA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                case 1:
                    #ifdef CNPUB
                    regptr16 = (volatile uint16_t *)&CNPUB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef CNPUC
                    regptr16 = (volatile uint16_t *)&CNPUC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef CNPUD
                    regptr16 = (volatile uint16_t *)&CNPUD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
//                case 4:
//                    #ifdef CNPUE
//                    regptr16 = (volatile uint16_t *)&CNPUE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.wpu_enable) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }

            break;
            
        case GPIO_CNPD:
            
            // Determine register bit value
            regval = ((volatile uint16_t)pin_cfg.bits.wpd_enable << (volatile uint16_t)pin_cfg.bits.pin);

            switch(pin_cfg.bits.port) {
                
                case 0:
                    #ifdef CNPDA
                    regptr16 = (volatile uint16_t *)&CNPDA;
                    regmask = REG_PORTA_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                    
                case 1:
                    #ifdef CNPDB
                    regptr16 = (volatile uint16_t *)&CNPDB;
                    regmask = REG_PORTB_VALID_DATA_WRITE_MSK;
                    #endif
                    break;

                case 2:
                    #ifdef CNPDC
                    regptr16 = (volatile uint16_t *)&CNPDC;
                    regmask = REG_PORTC_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
                case 3:
                    #ifdef CNPDD
                    regptr16 = (volatile uint16_t *)&CNPDD;
                    regmask = REG_PORTD_VALID_DATA_WRITE_MSK;
                    #endif
                    break;
                
//                case 4:
//                    #ifdef CNPDE
//                    regptr16 = (volatile uint16_t *)&CNPDE;
//                    regmask = REG_PORTE_VALID_DATA_WRITE_MSK;
//                    #endif
//                    break;
                    
                default:
                    return(0);
                    break;
            }
            
            // Read current register value
            regbuf = (*regptr16 & regmask);
            
            // Change Port-Pin-bit
            if(pin_cfg.bits.wpd_enable) {
                regbuf |= regval; // Set bit
            }
            else { 
                regbuf &= (0xFFFF ^ regval); // Clear bit
            }

            break;
            
        default:
            return(0);
            break;
    }
    
    
    // Write value to register and check contents
    *regptr16 = (regbuf & regmask);
    fres = (volatile bool)((*regptr16 & regmask) == regbuf);
    
    return(fres);

}

