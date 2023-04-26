#include "usart.h"

static char* bufferIn;
static char* bufferOut;
static uint8_t index, i;

void usartInit(uint32_t BAUDRATE){
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1; 
    if(_XTAL_FREQ <= 4000000){

        SPBRG = (unsigned char)((_XTAL_FREQ/(BAUDRATE*16.0))-1.0);
        TXSTA = 0x24;
    }
    else{
        SPBRG = (unsigned char)((_XTAL_FREQ/(BAUDRATE*64.0))-1.0);
        TXSTA = 0x20;
    }
    RCSTA = 0x90;
}

void usartPutc(char chr){
    TXREG = chr;
    while(!TRMT);
}
void usartPuts(char *str){
    while(*str){usartPutc(*str++);}
}
char usartGetc(void){
    if(!OERR){
        CREN =  0;
        NOP();
        CREN = 1;        
    }
    return RCREG;
}

bool usartKbit(void){
    if(RCIF){return true;  RCIF = 0;}
    else{    return false; RCIF = 0;}
}
