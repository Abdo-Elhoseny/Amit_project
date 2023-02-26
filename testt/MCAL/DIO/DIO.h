/*
 * DIO.h
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#define F_CPU 16000000UL // 16 MHz clock speed
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include "..\..\LIBRARY\stdTypes.h"
#include "..\..\LIBRARY\Bit_Math.h"
/*Port Selection*/
#define DIO_PORTA        0
#define DIO_PORTB        1
#define DIO_PORTC        2
#define DIO_PORTD        3
/*Pin Selection*/
#define DIO_PIN_0        0
#define DIO_PIN_1        1
#define DIO_PIN_2        2
#define DIO_PIN_3        3
#define DIO_PIN_4        4
#define DIO_PIN_5        5
#define DIO_PIN_6        6
#define DIO_PIN_7        7
#define DIO_ALL_PINs     8
/*Direction Selection*/
#define DIO_PIN_IN       0x00
#define DIO_PIN_OUT      0xff
/*Output Value Selection*/
#define DIO_PIN_OFF      0x00
#define DIO_PIN_ON       0xff
#define PIN_ON 0
#define PIN_OFF 1
/*---------------- pin control functions prototype -------------------*/
/*---------------- set pin direction -------------------*/
void DIO_SetPinDir(Uint8 port, Uint8 pin, Uint8 dir);
/*---------------- set pin value -------------------*/
void DIO_SetPinVal(Uint8 port, Uint8 pin, Uint8 val);
/*---------------- toggle pin -------------------*/
void DIO_TogglePin(Uint8 port, Uint8 pin);
/*---------------- get pin value -------------------*/
Uint8 DIO_GetPinVal(Uint8 port, Uint8 pin);
/*---------------- set pin as input with pull-up resistor -------------------*/
void DIO_SetPullup(Uint8 port, Uint8 pin);



#endif /* MCAL_DIO_DIO_H_ */
