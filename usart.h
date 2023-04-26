/* 
 * File:   usart.h
 * Author: JoelCF
 *
 * Created on March 20, 2023, 1:16 PM
 */

#ifndef USART_H
#define	USART_H

#include "main.h"


void  usartInit(uint32_t BAUDRATE);
void  usartPutc(char chr);
void  usartPuts(char *str);
char  usartGetc(void);
bool  usartKbit(void);

#endif	/* USART_H */

