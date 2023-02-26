/*
 * DC_Motor_CFG.h
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#ifndef HALL_DC_MOTOR_DC_MOTOR_CFG_H_
#define HALL_DC_MOTOR_DC_MOTOR_CFG_H_

#include "..\..\MCAL\DIO\DIO.h"

/*---------------- dc-motor 1 control  -------------------*/
#define M1_PORT              DIO_PORTB
#define M1_PWM_PIN           DIO_PIN_3
#define M1_DIR_PIN1          DIO_PIN_4
#define M1_DIR_PIN2          DIO_PIN_5
/*---------------- dc-motor2 control  -------------------*/
#define M2_PORT              DIO_PORTB
#define M2_PWM_PIN           DIO_PIN_3
#define M2_DIR_PIN1          DIO_PIN_6
#define M2_DIR_PIN2          DIO_PIN_7



#endif /* HALL_DC_MOTOR_DC_MOTOR_CFG_H_ */
