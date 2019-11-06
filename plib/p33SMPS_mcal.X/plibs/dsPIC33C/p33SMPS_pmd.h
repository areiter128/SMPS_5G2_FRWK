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
/*!p33MP_gpio.c
 * ***************************************************************************
 *
 * File:   p33MP_gpio.c
 * Author: M91406
 *
 * Created on October 27, 2017, 11:24 AM
 * ***************************************************************************/
/*!p33SMPS_pmd.h
 * ***************************************************************************
 *
 * File:   p33SMPS_pmd.h
 * Author: M91406
 *
 * Created on October 25, 2017, 4:18 PM
 * 
 * Revision:
 * 
 * ***************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _MCAL_P33_SMPS_PDM_H_
#define	_MCAL_P33_SMPS_PDM_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "../p33SMPS_devices.h"

// Direct control macros for peripheral modules
#define PMD_TIMER1_POWER_ON   {_T1MD = 0}
#define PMD_TIMER1_POWER_OFF  {_T1MD = 1}

#define PMD_QEI_POWER_ON      {_QEIMD = 0}
#define PMD_QEI_POWER_OFF     {_QEIMD = 1}

#define PMD_HSPWM_POWER_ON    {_PWMMD = 0}
#define PMD_HSPWM_POWER_OFF   {_PWMMD = 1}

#define PMD_HSADC_POWER_ON    {_ADCMD = 0}
#define PMD_HSADC_POWER_OFF   {_ADCMD = 1}

#define PMD_CMP1_POWER_ON     {_CMP1MD = 0}
#define PMD_CMP1_POWER_OFF    {_CMP1MD = 1}
#define PMD_CMP2_POWER_ON     {_CMP2MD = 0}
#define PMD_CMP2_POWER_OFF    {_CMP2MD = 1}
#define PMD_CMP3_POWER_ON     {_CMP3MD = 0}
#define PMD_CMP3_POWER_OFF    {_CMP3MD = 1}
#define PMD_CMP4_POWER_ON     {_CMP4MD = 0}
#define PMD_CMP4_POWER_OFF    {_CMP4MD = 1}

#define PMD_PTG_POWER_ON      {_PTGMD = 0}
#define PMD_PTG_POWER_OFF     {_PTGMD = 1}

#define PMD_CLC1_POWER_ON     {_CLC1MD = 0}
#define PMD_CLC1_POWER_OFF    {_CLC1MD = 1}
#define PMD_CLC2_POWER_ON     {_CLC2MD = 0}
#define PMD_CLC2_POWER_OFF    {_CLC2MD = 1}
#define PMD_CLC3_POWER_ON     {_CLC3MD = 0}
#define PMD_CLC3_POWER_OFF    {_CLC3MD = 1}
#define PMD_CLC4_POWER_ON     {_CLC4MD = 0}
#define PMD_CLC4_POWER_OFF    {_CLC4MD = 1}

#define PMD_SCCP1_POWER_ON    {_CCP1MD = 0}
#define PMD_SCCP1_POWER_OFF   {_CCP1MD = 1}
#define PMD_SCCP2_POWER_ON    {_CCP2MD = 0}
#define PMD_SCCP2_POWER_OFF   {_CCP2MD = 1}
#define PMD_SCCP3_POWER_ON    {_CCP3MD = 0}
#define PMD_SCCP3_POWER_OFF   {_CCP3MD = 1}
#define PMD_SCCP4_POWER_ON    {_CCP4MD = 0}
#define PMD_SCCP4_POWER_OFF   {_CCP4MD = 1}
#define PMD_SCCP5_POWER_ON    {_CCP5MD = 0}
#define PMD_SCCP5_POWER_OFF   {_CCP5MD = 1}
#define PMD_SCCP6_POWER_ON    {_CCP6MD = 0}
#define PMD_SCCP6_POWER_OFF   {_CCP6MD = 1}
#define PMD_SCCP7_POWER_ON    {_CCP7MD = 0}
#define PMD_SCCP7_POWER_OFF   {_CCP7MD = 1}
#define PMD_SCCP8_POWER_ON    {_CCP8MD = 0}
#define PMD_SCCP8_POWER_OFF   {_CCP8MD = 1}

#define PMD_REFCLK_POWER_ON   {_REFOMD = 0}
#define PMD_REFCLK_POWER_OFF  {_REFOMD = 1}

#define PMD_BIAS_POWER_ON     {_BIASMD = 0}
#define PMD_BIAS_POWER_OFF    {_BIASMD = 1}

#define PMD_I2C1_POWER_ON     {_I2C1MD = 0}
#define PMD_I2C1_POWER_OFF    {_I2C1MD = 1}
#define PMD_I2C2_POWER_ON     {_I2C2MD = 0}
#define PMD_I2C2_POWER_OFF    {_I2C2MD = 1}

#define PMD_UART1_POWER_ON    {_U1MD = 0}
#define PMD_UART1_POWER_OFF   {_U1MD = 1}
#define PMD_UART2_POWER_ON    {_U2MD = 0}
#define PMD_UART2_POWER_OFF   {_U2MD = 1}

#define PMD_SPI1_POWER_ON     {_SPI1MD = 0}
#define PMD_SPI1_POWER_OFF    {_SPI1MD = 1}
#define PMD_SPI2_POWER_ON     {_SPI2MD = 0}
#define PMD_SPI2_POWER_OFF    {_SPI2MD = 1}

#define PMD_CAN1_POWER_ON     {_C1MD = 0}
#define PMD_CAN1_POWER_OFF    {_C1MD = 1}
#define PMD_CAN2_POWER_ON     {_C2MD = 0}
#define PMD_CAN2_POWER_OFF    {_C2MD = 1}

#define PMD_SENT1_POWER_ON    {_SENT1MD = 0}
#define PMD_SENT1_POWER_OFF   {_SENT1MD = 1}
#define PMD_SENT2_POWER_ON    {_SENT2MD = 0}
#define PMD_SENT2_POWER_OFF   {_SENT2MD = 1}

#define PMD_CRC_POWER_ON      {_CRCMD = 0}
#define PMD_CRC_POWER_OFF     {_CRCMD = 1}

#define PMD_DMA0_POWER_ON     {_DMA0MD = 0}
#define PMD_DMA0_POWER_OFF    {_DMA0MD = 1}
#define PMD_DMA1_POWER_ON     {_DMA1MD = 0}
#define PMD_DMA1_POWER_OFF    {_DMA1MD = 1}
#define PMD_DMA2_POWER_ON     {_DMA2MD = 0}
#define PMD_DMA2_POWER_OFF    {_DMA2MD = 1}
#define PMD_DMA3_POWER_ON     {_DMA3MD = 0}
#define PMD_DMA3_POWER_OFF    {_DMA3MD = 1}
#define PMD_DMA4_POWER_ON     {_DMA4MD = 0}
#define PMD_DMA4_POWER_OFF    {_DMA4MD = 1}
#define PMD_DMA5_POWER_ON     {_DMA5MD = 0}
#define PMD_DMA5_POWER_OFF    {_DMA5MD = 1}

// enum for power states
typedef enum
{
    PMD_POWER_ON = 0, 
    PMD_POWER_OFF = 1
}pmd_enable_setting_e;

#if defined (__P33SMPS_CK__)
    #define PMD1_VALID_DATA_MASK    0b0000111011111011
    #define PMD2_VALID_DATA_MASK    0b0000000111111111
    #define PMD3_VALID_DATA_MASK    0b0000000110101110
    #define PMD4_VALID_DATA_MASK    0b0000000000001000
    #define PMD5_VALID_DATA_MASK    0b0000000000000000
    #define PMD6_VALID_DATA_MASK    0b0000111100000001
    #define PMD7_VALID_DATA_MASK    0b0000011100001000
    #define PMD8_VALID_DATA_MASK    0b0011100100111110
#else
    #pragma message "=== selected device is not defined and may not be supported ==="
#endif

// global prototypes
extern volatile uint16_t pmd_reset(pmd_enable_setting_e power_on_state);

#endif	/* MCAL_P33_SMPS_PDM_H */

