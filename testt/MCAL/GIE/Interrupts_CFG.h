/*
 * Interrupts_CFG.h
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#ifndef MCAL_GIE_INTERRUPTS_CFG_H_
#define MCAL_GIE_INTERRUPTS_CFG_H_

#include "..\..\LIBRARY\stdTypes.h"
#include "..\..\LIBRARY\Bit_Math.h"
/*Global Interrupt Selection*/
#define GLOBAL_INT                Disable

/*Timer0 Interrupt Selection*/
#define TIMER0_OVF_INT            Disable
#define TIMER0_OCR_INT            Disable

/*Timer1 Interrupt Selection*/
#define TIMER1_OVF_INT            Disable
#define TIMER1_OCR_INT            Disable

/*Timer2 Interrupt Selection*/
#define TIMER2_OVF_INT            Disable
#define TIMER2_OCR_INT            Disable

/*I2C Interrupt Selection*/
#define I2C_INT                   Disable


#endif /* MCAL_GIE_INTERRUPTS_CFG_H_ */
