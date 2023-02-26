/*
 * Servo_motor.c
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#include "..\..\HALL\SERVO\servo_motor.h"


/*----------------SERVO MOTOR INITIALIZATION -------------------*/
void Servo_INIT(void)
{
	Servo_Zero();
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM) 
	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).
	//DDRD|=(1<<PD4)|(1<<PD5);
	DIO_SetPinDir(Control_port, Control_pin, DIO_PIN_OUT);
}

/*-----------------SERVO LOOK LEFT------------------*/
void Servo_Rot_Left(Uint8 angle)
{
	
	
	switch(angle)
	{
	case 1: OCR1A=475; break; // angle 60

	case 2: OCR1A=550; break; // angle 30

	case 3: OCR1A=900; break; // angle 0

	default: break;

	}

}
/*-----------------SERVO LOOK RIGHT------------------*/
void Servo_Rot_Right(Uint8 angle)
{
	switch(angle)
	{
//	case 0: OCR1A=375; break; // zero car
		
	case 1: OCR1A=275; break; // angle 120

	case 2: OCR1A=200; break; // angle 150

	case 3: OCR1A=50; break; // angle 180
	
	default: break;

    }


}
/*----------------DEFAULTE POSITION -------------------*/
void Servo_Zero(void)
{
	OCR1A=375; // zero car
}

