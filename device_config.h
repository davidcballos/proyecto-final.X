/* 
 * File:   device_config.h
 * Author: JoelCF
 *
 * Created on January 13, 2023, 6:05 PM
 */

#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

#define _XTAL_FREQ      48000000UL

#include "main.h"


//bits IRCF2:IRCF0
#define INTOSC_8_MHZ        7  
#define INTOSC_4_MHZ        6  
#define INTOSC_2_MHZ        5  
#define INTOSC_1_MHZ        4  
#define INTOSC_500_kHZ      3  
#define INTOSC_250_kHZ      2  
#define INTOSC_125_kHZ      1  
#define INTOSC_31_kHZ       0  

//bits SCS1:SCS0
#define INTERNAL_OSCILLATOR 2
#define TIMER1_OSCILLATOR   1
#define PRIMARY_OSCILLATOR  0

#define CLK_TYPE            PRIMARY_OSCILLATOR
#define INTOSC_FREQ         (INTOSC_8_MHZ<<4)

void OscillatorInit(void);


#endif	/* DEVICE_CONFIG_H */

