#ifndef _ULTRA_H_
#define _ULTRA_H_

#include "..\..\MCAL\DIO\DIO.h"


/*-----------------TRIGER PIN------------------*/
#define   TRIGER_DDR    DDRD
#define   TRIGER_PORT   PORTD
#define   TRIGER        0
/*-----------------ECHO PIN------------------*/
#define   ECHO_DDR      DDRD
#define   ECHO_PULLUP   PORTD
#define   ECHO          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);


#endif
