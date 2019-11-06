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
/* @@p33SMPS_oscillator.c
 * ***************************************************************************
 *
 * File:   p33SMPS_oscillator.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/

/* ************************************************************************************************
 * PRIVATE DEFINES
 * ************************************************************************************************/

#include <stdint.h>
#include "p33SMPS_oscillator.h"

/* ************************************************************************************************
 * PRIVATE DEFINES
 * ************************************************************************************************/
#define OSC_CLKSW_TIMEOUT	5000	// value to set the timeout for clock switching operations



/*@@init_FOSC(OSC_CONFIG_t osc_config)
 * ************************************************************************************************
 * Summary:
 * Initializes the major oscillator and the PLL module step by step by using clock switching
 * in software. Each step is tested and verified
 *
 * Parameters:
 *	OSC_CONFIG_t osc_config (includes oscillator type and PLL configuration)
 *
 * Returns:
 *  0 = unspecified clock failure detected
 *  1 = clock switch successful
 *  2 = clock switch failed
 *  4 = currently selected clock differs from selected clock source
 *  8 = PLL didn't lock in within given time frame
 *
 * Description:
 * Microchip's 16-Bit devices offer a safe 2-step start-up mode, using the internal FRC during power up, 
 * followed by a user defined switch-over to the desired oscillator. 
 * Though this can also be done in hardware automatically, this software-version of the switch-over offers
 * a better solution to verify each step and enables the user to implement some error handling in the case
 * of failure.
 * This function can be used to select a new oscillator at runtime. Each configuration step
 * will be verified before the next step is performed.
 *
 * Please Note:
 * If a oscillator switch-over is performed, additional settings in the _FOSCSEL and _FOSC
 * registers of the configuration bits may be required
 * ************************************************************************************************/

int16_t init_FOSC(OSC_CONFIG_t osc_config)
{

uint16_t i=0, err=0;

    // Set oscillator tuning
	#if defined (__P33SMPS_CH_MSTR__)	// only dsPIC33CH Master Core allows FRC tuning => Slave running on the same clock
	
    // => FRC Oscillator tuning is only available on the master core
    if(osc_config.frc_tune != OSCTUNbits.TUN)      // If oscillator tuning is requested...
    {
    	OSCTUNbits.TUN = osc_config.frc_tune;           // Set Tuning Register for FRC Oscillator
    }
    
    #endif

    // Set FRC divider
    if(osc_config.frc_div != CLKDIVbits.FRCDIV)         // If fast RC oscillator scaling is requested...
    {
    	CLKDIVbits.FRCDIV = osc_config.frc_div;       // Set FRC frequency divider
    }

    // Unlock registers 
    // Note: clock switching must be enabled in config bits ( FCKSM0<1:0> = 0b0x )
    if (OSCCONbits.CLKLOCK)
    {
        OSCCONbits.CLKLOCK = 0; 
    }

    // Switch to target oscillator
	if ((OSCCONbits.COSC != osc_config.osc_type) && (OSCCONbits.CLKLOCK == 0))
	{
	// Switch to desired system clock, if clock switching is enabled

	    __builtin_write_OSCCONH(osc_config.osc_type);           // Specify the new oscillator (e.g.: PRIMARY XT w/ PLL)
    	__builtin_write_OSCCONL(OSCCON | 0x01);  	// Set Switch Command to perform the switch-over

		// Make sure that the desired oscillator is available 
		// and the switch-over was successfully performed

    	// Wait for Clock switch to occur
        while ((OSCCONbits.OSWEN != 0) && (i<OSC_CLKSW_TIMEOUT))
        { i++; }
        if (i>=OSC_CLKSW_TIMEOUT) err = 1;
        i=0;    // reset counter

		while((OSCCONbits.COSC != OSCCONbits.NOSC) && (i<OSC_CLKSW_TIMEOUT))	// Wait for switch-over to
		{ i++; }																// selected Oscillator
        if (i>=OSC_CLKSW_TIMEOUT) err |= 1;
        i=0;    // reset counter
	
		if ((OSCCONbits.OSWEN == 1) || (OSCCONbits.COSC != OSCCONbits.NOSC) || (err==1)) 	// Error occurred? 
		{ return(OSCERR_CSF); }									// => If yes, return error code
																

	}
	else if ((OSCCONbits.COSC != osc_config.osc_type) && (OSCCONbits.CLKLOCK == 1))
	{ // If clock switching is disabled, and the current clock differs from the desired clock,
	  // return error code

			return(OSCERR_CSD);
	}

	#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)
	// Configure PLL pre-scaler, PLL post-scaler, PLL divisor
    
    CLKDIVbits.PLLPRE	= osc_config.N1;		// N1 (non zero)
	PLLFBDbits.PLLFBDIV	= osc_config.M;         // M  = PLLFBD 
    PLLDIVbits.POST1DIV	= osc_config.N2;        // N2 (non zero)
    PLLDIVbits.POST2DIV = osc_config.N3;        // N3 (non zero)

	PLLDIVbits.VCODIV   = osc_config.VCODIV;    // FVCO Scaler 1:n

	#elif defined (__P33SMPS_FJ__) || defined (__P33SMPS_FJA__) || defined (__P33SMPS_FJC__) || \
	      defined (__P33SMPS_EP__)

    CLKDIVbits.PLLPRE	= osc_config.N1;		// N1 (non zero)
	PLLFBD				= (osc_config.M - 2);   // M  = PLLFBD 
    CLKDIVbits.PLLPOST	= osc_config.N2;        // N2 (non zero)

	#endif
    
    // Lock registers against accidental changes
    OSCCONbits.CLKLOCK = 1;
    
    while((OSCCONbits.LOCK != 1) && (i<OSC_CLKSW_TIMEOUT))		// Wait 5000 while loops for PLL to Lock
	{ i++; }
	
	if ((OSCCONbits.LOCK != 1) || (i>=OSC_CLKSW_TIMEOUT))		// Error occurred? 
	{ return OSCERR_PLL_LCK; }						// => If yes, return error code

// Return Success/Failure
	return((1 - OSCCONbits.CF));					// Return oscillator fail status bit
													// (1=Success, 0=Failure)

}

/*@@init_AUXCLK(AUXOSC_CONFIG_t aux_clock_config)
 * ************************************************************************************************
 * Summary:
 * Initializes the auxiliary clock and its PLL module step by step 
 * in software. Each step is tested and verified
 *
 * Parameters:
 *	AUXOSC_CONFIG_t aux_clock_config (includes oscillator settings and PLL configuration)
 *
 * Returns:
 *  0 = unspecified clock failure detected
 *  1 = clock switch successful
 *  2 = clock switch failed
 *  4 = currently selected clock differs from selected clock source
 *  8 = PLL didn't lock in within given time frame
 *
 * Description:
 * The auxiliary clock is generated by a separate PLL module, which is driven
 * from one of the main clock signals or PLL outputs. This auxiliary clock can
 * be used to drive ADCs, PWM, DACs and other peripherals. Each of them might
 * have individual requirements. Please refer to the specific peripheral sections
 * in the device data sheet to learn how to configure the auxiliary clock.
 *
 * ************************************************************************************************/

int16_t init_AUXCLK(AUXOSC_CONFIG_t aux_clock_config)
{
    volatile uint16_t i=0;
    
	#if defined (__P33SMPS_CH__) || defined (__P33SMPS_CK__)

    // Select clock input source (either primary oscillator or internal FRC)
    ACLKCON1bits.FRCSEL = aux_clock_config.FRCSEL;
	
    // Set Enable-bit of Auxiliary PLL 
    ACLKCON1bits.APLLEN = aux_clock_config.APLLEN;

    // Set AVCO divider of Auxiliary PLL 
    APLLDIV1bits.AVCODIV   = aux_clock_config.AVCODIV;  // AVCO Scaler 1:n

    // Configure APLL pre-scaler, APLL post-scaler, APLL divisor
    ACLKCON1bits.APLLPRE   = aux_clock_config.N1;		// N1 (non zero)
	APLLFBD1bits.APLLFBDIV = aux_clock_config.M;        // M  = APLLFBD 
    APLLDIV1bits.APOST1DIV = aux_clock_config.N2;       // N2 (non zero)
    APLLDIV1bits.APOST2DIV = aux_clock_config.N3;       // N3 (non zero)

    // if user has not enabled the APLL module, exit here
    if(!ACLKCON1bits.APLLEN)
    { return(1); }
        
    // Wait 5000 while loops for APLL to Lock
    while((ACLKCON1bits.APLLCK != 1) && (i++<OSC_CLKSW_TIMEOUT));		
	
	if (ACLKCON1bits.APLLCK != 1)	// PLL still not locked in? 
	{ return OSCERR_APLL_LCK; } // => If yes, return error code
    else
    { return(ACLKCON1bits.APLLCK); }

    #endif
    
}
 
 


