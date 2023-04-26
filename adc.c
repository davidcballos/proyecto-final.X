#include "adc.h"

void adc_setupChannel(uint8_t adc_port){
    ADCON1 = adc_port;
}
void adc_setup(uint8_t freq_acq){
    ADCON2 = freq_acq | 0x80;
}
uint16_t adc_read(uint8_t channel){
    ADCON0bits.CHS = channel;                 //SELECCIONAMOS EL CANAL DE LECTURA DEL ADC
    ADCON0bits.ADON = 1;
    ADCON0bits.GODONE = 1;
    while(ADCON0bits.GODONE);
    return (uint16_t)((ADRESH<<8)|ADRESL);
}
