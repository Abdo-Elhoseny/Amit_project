/*
 * DC_Motor.c
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */

#include "..\..\HALL\DC_MOTOR\DC_Motor.h"

/*DC_Motor1 Functions implementation*/
void DC_Motors_INIT(void)
{

	/*DC motor1 pins direction*/
	DIO_SetPinDir(M1_PORT, M1_DIR_PIN1, DIO_PIN_OUT);
	DIO_SetPinDir(M1_PORT, M1_DIR_PIN2, DIO_PIN_OUT);

	/*DC motor1 pins value*/
	DIO_SetPinVal(M1_PORT, M1_DIR_PIN1, DIO_PIN_OFF);
	DIO_SetPinVal(M1_PORT, M1_DIR_PIN2, DIO_PIN_OFF);
	
	
	/*DC motor2 pins direction*/
	DIO_SetPinDir(M2_PORT, M2_DIR_PIN1, DIO_PIN_OUT);
	DIO_SetPinDir(M2_PORT, M2_DIR_PIN2, DIO_PIN_OUT);

	/*DC motor2 pins value*/
	DIO_SetPinVal(M2_PORT, M2_DIR_PIN1, DIO_PIN_OFF);
	DIO_SetPinVal(M2_PORT, M2_DIR_PIN2, DIO_PIN_OFF);
	
	/*timer0*/
	 // DDRB=0b11111111; // ensure that Pin3 in POrt B is output as this is the OC0 pin that wll produce the PWM.
	 DIO_SetPinDir(DIO_PORTB, DIO_PIN_3, DIO_PIN_OUT);

	 OCR0=0;//Initialization to ocr0

	 //TCCR0=0b01110101; //Configure TCCR0 as explained in the article
	 TCCR0=0x65;

	 TIMSK=0x00;//no flags used



}

void DC_Motor1_START(Uint16 speed, DC_Motor_Dir dir)
{
	OCR0=speed;//speed (pwm value)
	switch(dir)
	{
		case  Clock_Wise:
		DIO_SetPinVal(M1_PORT, M1_DIR_PIN1, DIO_PIN_ON);
		DIO_SetPinVal(M1_PORT, M1_DIR_PIN2, DIO_PIN_OFF);
		break;
		case Anti_Clock_Wise:
		DIO_SetPinVal(M1_PORT, M1_DIR_PIN1, DIO_PIN_OFF);
		DIO_SetPinVal(M1_PORT, M1_DIR_PIN2, DIO_PIN_ON);
		break;
		default:
		break;
	}

}


void DC_Motor2_START(Uint16 speed, DC_Motor_Dir dir)
{
	
	OCR0=speed;//speed (pwm value)
	switch(dir)
	{
		case  Clock_Wise:
		DIO_SetPinVal(M2_PORT, M2_DIR_PIN1, DIO_PIN_ON);
		DIO_SetPinVal(M2_PORT, M2_DIR_PIN2, DIO_PIN_OFF);
		break;
		case Anti_Clock_Wise:
		DIO_SetPinVal(M2_PORT, M2_DIR_PIN1, DIO_PIN_OFF);
		DIO_SetPinVal(M2_PORT, M2_DIR_PIN2, DIO_PIN_ON);
		break;
		default:
		break;
	}

}
/*---------------- move car forward -------------------*/
void DC_Forward(void)
{
	//lcd_clear lcd_write moveing forward
	DC_Motor1_START(140, Clock_Wise);
	DC_Motor2_START(140, Clock_Wise);
}

/*---------------- car stop -------------------*/
void DC_STOP(void)
{
	//lcd_clear lcd_write car stop
	DIO_SetPinVal(M1_PORT, M1_DIR_PIN1, DIO_PIN_OFF);
	DIO_SetPinVal(M1_PORT, M1_DIR_PIN2, DIO_PIN_OFF);
	
	DIO_SetPinVal(M2_PORT, M2_DIR_PIN1, DIO_PIN_OFF);
	DIO_SetPinVal(M2_PORT, M2_DIR_PIN2, DIO_PIN_OFF);
}

/*---------------- turn car left -------------------*/
void DC_Rot_Left(Uint16 angle)
{
	    //lcd_clear lcd_write turning left
		DC_Motor1_START(140, Anti_Clock_Wise);
		DC_Motor2_START(140, Clock_Wise);
		switch (angle)
		{
			case 1: _delay_ms(370); DC_STOP(); break;  
			
			case 2: _delay_ms(370*2); DC_STOP(); break;
			
			case 3: _delay_ms(370*3); DC_STOP(); break;
			
			default: DC_STOP(); break;
		}
	
}
/*---------------- turn car right -------------------*/
void DC_Rot_Right(Uint16 angle)
{
       //lcd_clear lcd_write turning right	
	   DC_Motor1_START(140, Clock_Wise);
	   DC_Motor2_START(140, Anti_Clock_Wise);
	   switch (angle)
	   {
		case 1: _delay_ms(370); DC_STOP(); break; 
		
		case 2: _delay_ms(370*2); DC_STOP(); break; 
		
		case 3: _delay_ms(370*3); DC_STOP(); break; 
		
		default: DC_STOP(); break;  
	   }

}
/*---------------- turn car 180 degree -------------------*/
void DC_Rot_180(void)
{
	 ///lcd_clear lcd_write turning 180
	 DC_Motor1_START(140, Clock_Wise);
	 DC_Motor2_START(140, Anti_Clock_Wise);
	  _delay_ms(370*6); 
	  DC_STOP();
}

