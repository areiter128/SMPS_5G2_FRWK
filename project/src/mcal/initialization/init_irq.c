/*
 * File:   init_irq.c
 * Author: M91406
 *
 * Created on August 3, 2018, 9:50 AM
 */

#include "mcal/mcal.h"

volatile uint16_t IRQ_initialize(void)
{

    volatile uint16_t fres = 0;
    volatile INTERRUPT_CONFIG_t irq_config;
    
    irq_config.intcon1.value = IRQ_INTCON1_CFG; // Reset all interrupt status bits
    irq_config.intcon2.value = IRQ_INTCON2_CFG; // Reset all interrupt status bits
    irq_config.intcon3.value = IRQ_INTCON3_CFG; // Reset all interrupt status bits
    irq_config.intcon4.value = IRQ_INTCON4_CFG; // Reset all interrupt status bits
    irq_config.inttreg.value = IRQ_INTTREG_CFG; // Reset all interrupt status bits
    
    fres = smpsIRQ_Initialize(irq_config);
    fres &= smpsIRQ_SoftTrapsInitialize(false, false, false);

    return(fres);
}
