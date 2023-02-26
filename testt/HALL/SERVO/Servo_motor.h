

#ifndef HALL_SERVO_MOTOR_SERVO_MOTOR_H_
#define HALL_SERVO_MOTOR_SERVO_MOTOR_H_
#include "..\..\HALL\SERVO\Servo_motor_CFG.h"
/*-----------------SERVO MOTOR FUNCTIONS PROTOTYPE------------------*/
void Servo_INIT(void);
/*-----------------SERVO LOOK RIGHT------------------*/
void Servo_Rot_Right(Uint8 angle);
/*-----------------SERVO LOOK LEFT------------------*/
void Servo_Rot_Left(Uint8 angle);
/*----------------DEFAULTE POSITION -------------------*/
void Servo_Zero(void);


#endif /* HALL_SERVO_MOTOR_SERVO_MOTOR_H_ */
