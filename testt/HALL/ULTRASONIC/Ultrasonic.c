#include "..\..\HALL\ULTRASONIC\ultrasonic.h"

Uint8 sensor_working=0;
Uint8 rising_edge=0;
Uint32 timer_counter=0;
Uint32 distance;
Uint8 ult_val = 0;
/*----------------ULTRASONIC INITIALIZATION -------------------*/
void ultrasonic_init(void){

	TRIGER_DDR|=(1<<TRIGER);
	ECHO_DDR&=~(1<<ECHO);
	ECHO_PULLUP|=(1<<ECHO);
	enable_ex_interrupt();
	TCCR2 = 0x02;
	/* Initializing the timer with zero */
	TCNT2 = 0x00;
	/* Timer overflow interrupt enable*/
	TIMSK |=(1<<TOIE2);
	return;
}
/*----------------ENABLE EXTERNAL INTERRUPT  -------------------*/
void enable_ex_interrupt(void){

	MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
	GICR  |= (1<<INT1);			// Enable INT1 interrupts.

	return;
}
/*----------------ULTRASONIC TRIGER -------------------*/
void ultra_triger(void){
	if(!sensor_working){
		TRIGER_PORT|=(1<<TRIGER);
		_delay_us(15);
		TRIGER_PORT&=~(1<<TRIGER);
		sensor_working=1;
	}
}

ISR(INT1_vect) //// INTERRUPT SERVICE ROUTINE
{
	if(sensor_working==1){
		if(rising_edge==0){
			TCNT2=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else{
			ult_val = 0;
			distance=(timer_counter*256+TCNT2)/116.6;
			if(distance <= 30)
			{
				ult_val = 1;
			}
			timer_counter=0;
			rising_edge=0;
		}
	}
}
ISR(TIMER2_OVF_vect){
	timer_counter++;
	if(timer_counter >730){
		TCNT2=0x00;
		sensor_working=0;
		rising_edge=0;
		timer_counter=0;
	}
}
