/* 
 * File:   main.h
 * Author: JoelCF
 *
 * Created on January 13, 2023, 6:07 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "device_config.h"

typedef enum{
    OUTPUT,
    INPUT
}PIN_MODE;

typedef enum{
    LOW,
    HIGH
}PIN_VALUE;

typedef enum{
    COMMAND,
    DATA
}LCD_MODE;

#endif	/* MAIN_H */

