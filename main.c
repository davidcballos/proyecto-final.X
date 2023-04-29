/*
 * File:   main.c
 * Author: David
 *
 * Created on 31 de marzo de 2023, 06:38 PM
 */


#include <pic18f4550.h>
#include "main.h"
#include "usart.h"
#include "adc.h"
//un texto mas
void secuencia3 (void);
void secuencia (void);
void secuencia2(void);
void apagar(void);
char buffer[30];
uint8_t lm35,adc;
float temp,volts;
char dato;

void __interrupt() recive(){
    if(PIR1bits.RCIF){
        PIR1bits.RCIF = 0;
        dato= usartGetc();
    }
}

void main (void){
    OscillatorInit();
    usartInit(9600);
    TRISB = 0x00;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.RCIE=1;
    PIR1bits.RCIF=0;
    adc_setup(__64_TOSC | __6_TAD);
    adc_setupChannel(AN0 | VSS_VDD);
    LATB = 0x00;
    while(true){
       lm35 = adc_read(0);
       sprintf(buffer,"TEMP:%d\n\r",lm35);
       usartPuts(buffer);
       __delay_ms(500);
//       temp = (lm35*5.0)/1023.0;
//       sprintf(buffer,"ADC:%u \n\r",lm35);
//       usartPuts(buffer);
//        lm35 =adc_read(0);
//        sprintf(buffer,"TEMP:%2.1f\n\r",temp);
//        usartPuts(buffer);
//          __delay_ms(500);   
    
        switch(dato){           
            case 'A': LATB0 = 1; break;
            case 'B': LATB0 = 0; break;
            case 'C': LATB1 = 1; break;
            case 'D': LATB1 = 0; break;
            case 'E': LATB2 = 1; break;
            case 'F': LATB2 = 0; break;
            case 'G': LATB3 = 1; break;
            case 'H': LATB3 = 0; break;
            case 'I': LATB4 = 1; break;
            case 'J': LATB4 = 0; break;
            case 'K': LATB5 = 1; break;
            case 'L': LATB5 = 0; break;
            case 'M': LATB6 = 1; break;
            case 'N': LATB6 = 0; break;
            case 'O': LATB7 = 1; break;
            case 'P': LATB7 = 0; break;
            case 'Q': secuencia();break;
            case 'R': secuencia2(); break;
            case 'S': LATB =0; break;

        
        }
       }
       
    }
       


void secuencia(){
   
      do{
    LATBbits.LB0^=1;
    __delay_ms(50);
    LATBbits.LB1^=1;
    __delay_ms(50);
    LATBbits.LB2^=1;
    __delay_ms(50);
    LATBbits.LB3^=1;
    __delay_ms(50);
    LATBbits.LB4^=1;
    __delay_ms(50);
    LATBbits.LB5^=1;
    __delay_ms(50);
    LATBbits.LB6^=1;
    __delay_ms(50);
    LATBbits.LB7^=1;
    __delay_ms(50);
    }while(dato=='S');
   
   
}

void secuencia2(){
    do{
    LATBbits.LB7^=1;
    __delay_ms(50);
    LATBbits.LB6^=1;
    __delay_ms(50);
    LATBbits.LB5^=1;
    __delay_ms(50);
    LATBbits.LB4^=1;
    __delay_ms(50);
    LATBbits.LB3^=1;
    __delay_ms(50);
    LATBbits.LB2^=1;
    __delay_ms(50);
    LATBbits.LB1^=1;
    __delay_ms(50);
    LATBbits.LB0^=1;
    __delay_ms(50);
    }while(dato=='S');
    
}

void muestreo (){
	int i=0;
	
	for(i=0; i<10; i++){
		printf("%d\n",i);
	}
//texto para crear lina de codigo 
//con 2 lineas de codigos
