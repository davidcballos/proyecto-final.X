/* 
 * File:   adc.h
 * Author: JoelCF
 *
 * Created on March 24, 2023, 3:54 PM
 */

#ifndef ADC_H
#define	ADC_H

#include "main.h"

/* A/D Configuration Ports bits
 *   Function:
 * adc_setupChannel(analog Port bit);
 */
#define     NO_ANALOG       0x0F
#define     AN0             0x0E
#define     AN0_AN1         0x0D
#define     AN0_TO_AN2      0x0C
#define     AN0_TO_AN3      0x0B
#define     AN0_TO_AN4      0x0A
#define     AN0_TO_AN5      0x09
#define     AN0_TO_AN6      0x08
#define     AN0_TO_AN7      0x07
#define     AN0_TO_AN8      0x06
#define     AN0_TO_AN9      0x05
#define     AN0_TO_AN10     0x04
#define     AN0_TO_AN11     0x03
#define     ALL_ANALOGS     0x02

/*   ADC reference:
 *   Function:
 * adc_setupChannel(analog Port bit | reference);
 */
#define PVREF_NVREF     0x30
#define NVREF_VDD       0x20
#define VSS_PVREF       0x10
#define VSS_VDD         0x00   


/* Device Operating Frequencies
 *    Function:
 *  adc_setup(Freq);
 */
#define __2_TOSC        0x00       //2.5 MHz
#define __4_TOSC        0x04       //5   MHz
#define __8_TOSC        0x01       //10  MHz
#define __16_TOSC       0x05       //20  MHz
#define __32_TOSC       0x02       //40  MHz
#define __64_TOSC       0x06       //48  MHz
#define __RC            0x07       //1   MHz

/*
 * TAC Acquisition Time Select
 * Function:    0011 0 000
 * adc_setup(TAD config|TAC config)
 */
#define __0_TAD         0x00
#define __2_TAD         0x08
#define __4_TAD         0x10
#define __6_TAD         0x18
#define __8_TAD         0x20
#define __12_TAD        0x28
#define __16_TAD        0x30
#define __20_TAD        0x38

/*Analog Channel Select bits.
 * Function:
 * val = adc_read(select channel);
 * 
 */ 
#define SET_CH0         0
#define SET_CH1         1
#define SET_CH2         2
#define SET_CH3         3
#define SET_CH4         4
#define SET_CH5         5
#define SET_CH6         6
#define SET_CH7         7
#define SET_CH8         8
#define SET_CH9         9
#define SET_CH10        10
#define SET_CH11        11
#define SET_CH12        12


void adc_setupChannel(uint8_t adc_port);
void adc_setup(uint8_t freq_acq);
uint16_t adc_read(uint8_t channel);

#endif	/* ADC_H */

