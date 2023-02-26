/*
 * testt.c
 *
 * Created: 2/25/2023 3:53:39 PM
 * Author : aladd
 */ 

#include "Servo_motor.h"
#include "Ultrasonic.h"
#include "DC_Motor.h"
#include "Buzzer.h"
#include "LCD.h"

Uint16 count_r = 1 , count_l = 1 , x = 1;
extern Uint8 ult_val;


int main(void)
{
	
	
	lcd_init(); //////// lcd initialization
	DC_Motors_INIT(); //////// DC-Motors initialization
	Servo_INIT(); //////// servo-motor initialization
	Buzzer_Init();//////// buzzer initialization
	ultrasonic_init();//////// UltrasonicSensor initialization
	sei();
	
	while(1)
	{
		lcd_clear();
		lcd_write_word("Forward");
		//DC_Forward();
		_delay_ms(500);
		
		while (1)
		{
			ultra_triger();
			_delay_ms(15);
			if ( ult_val == 1) {break;}
		}
		
		lcd_clear();
		lcd_write_word("stop");
		DC_STOP();
		_delay_ms(500);
		x = 1;
		while (1)
		{
			Servo_Rot_Left(count_r);
			_delay_ms(500);
			ultra_triger();
			_delay_ms(15);
			if ((ult_val == 0) && (count_r < 4) )
			{
				lcd_clear();
				lcd_write_word("turning left");
				DC_Rot_Left(count_r);
				_delay_ms(500);
				count_r = 1;
				count_l = 1;
				Servo_Zero();
				break;
			}
			count_r ++;
			if (count_r >= 4)
			{
				Servo_Rot_Right(count_l);
				_delay_ms(100);
				if (ult_val == 0)
				{
					lcd_clear();
					lcd_write_word("turning right");
					DC_Rot_Right(count_l);
					_delay_ms(500);
					count_r = 1;
					count_l = 1;
					Servo_Zero();
					break;
				}
				count_l ++;
			}
			
			if ((count_r >=4) && (count_l >=4) && (x == 1))
			{
				_delay_ms(500);
				Servo_Zero();
				lcd_clear();
				lcd_write_word("turning 180 degree");
				DC_Rot_180();
				count_r = 1;
				count_l = 1;
				x ++;
				
			}
			else if ((count_r >=4) && (count_l >=4) && (x >= 2))
			{
				while (1)
				{
					lcd_clear();
					lcd_write_word("stop");
					Buzzer_Toggle();
					_delay_ms(200);
				}
			}
		}
	}
}
