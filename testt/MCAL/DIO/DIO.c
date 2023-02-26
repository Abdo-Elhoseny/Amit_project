/*
 * DIO.c
 *
 *  Created on: Dec 17, 2022
 *      Author: essam
 */


#include "..\..\MCAL\DIO\DIO.h"
/*---------------- set pin direction -------------------*/
void DIO_SetPinDir(Uint8 port, Uint8 pin, Uint8 dir)
{
	switch (dir)
	{
		case DIO_PIN_IN: ///////set pin as input
		if (pin >=0 && pin <=7)
		{
			switch (port)
			{
				case DIO_PORTA: ////////port A pins
				Clear_Bit(DDRA, pin);
				break;
				case DIO_PORTB: ////////port B pins
				Clear_Bit(DDRB, pin);
				break;
				case DIO_PORTC: ////////port C pins
				Clear_Bit(DDRC, pin);
				break;
				case DIO_PORTD: ////////port D pins
				Clear_Bit(DDRD, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			switch (port)
			{
				case DIO_PORTA: ////////port A pins
				DDRA = dir;
				break;
				case DIO_PORTB: ////////port B pins
				DDRB = dir;
				break;
				case DIO_PORTC: ////////port C pins
				DDRC = dir;
				break;
				case DIO_PORTD: ////////port D pins
				DDRD = dir;
				break;
				default:   //MISRA C rules
				break;
			}
		}
		break;
		case DIO_PIN_OUT:///////set pin as output
		if (pin >=0 && pin <=7)
		{
			switch (port)
			{
				case DIO_PORTA:
				Set_Bit(DDRA, pin);
				break;
				case DIO_PORTB:
				Set_Bit(DDRB, pin);
				break;
				case DIO_PORTC:
				Set_Bit(DDRC, pin);
				break;
				case DIO_PORTD:
				Set_Bit(DDRD, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			switch (port)
			{
				case DIO_PORTA:
				DDRA = dir;
				break;
				case DIO_PORTB:
				DDRB = dir;
				break;
				case DIO_PORTC:
				DDRC = dir;
				break;
				case DIO_PORTD:
				DDRD = dir;
				break;
				default:   //MISRA C rules
				break;
			}
		}
		break;
		default:   //MISRA C rules
		break;
	}
}
/*---------------- set pin value -------------------*/
void DIO_SetPinVal(Uint8 port, Uint8 pin, Uint8 val)
{
	switch (val)
	{
		case DIO_PIN_OFF:
		if (pin >=0 && pin <=7)
		{
			DIO_SetPinDir(port, pin, DIO_PIN_OUT); //////// set pin as output
			switch (port)
			{
				case DIO_PORTA: ////////port A pins
				Clear_Bit(PORTA, pin);
				break;
				case DIO_PORTB:////////port B pins
				Clear_Bit(PORTB, pin);
				break;
				case DIO_PORTC: ////////port C pins
				Clear_Bit(PORTC, pin);
				break;
				case DIO_PORTD: ////////port D pins
				Clear_Bit(PORTD, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			DIO_SetPinDir(port, DIO_ALL_PINs, DIO_PIN_OUT); /////set all port pins as output
			switch (port)
			{
				case DIO_PORTA:
				PORTA = val;
				break;
				case DIO_PORTB:
				PORTB = val;
				break;
				case DIO_PORTC:
				PORTC = val;
				break;
				case DIO_PORTD:
				PORTD = val;
				break;
				default:   //MISRA C rules
				break;
			}
		}
		break;
		case DIO_PIN_ON:
		if (pin >=0 && pin <=7)
		{
			DIO_SetPinDir(port, pin, DIO_PIN_OUT);
			switch (port)
			{
				case DIO_PORTA:
				Set_Bit(PORTA, pin);
				break;
				case DIO_PORTB:
				Set_Bit(PORTB, pin);
				break;
				case DIO_PORTC:
				Set_Bit(PORTC, pin);
				break;
				case DIO_PORTD:
				Set_Bit(PORTD, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			DIO_SetPinDir(port, DIO_ALL_PINs, DIO_PIN_OUT);
			switch (port)
			{
				case DIO_PORTA:
				PORTA = val;
				break;
				case DIO_PORTB:
				PORTB = val;
				break;
				case DIO_PORTC:
				PORTC = val;
				break;
				case DIO_PORTD:
				PORTD = val;
				break;
				default:   //MISRA C rules
				break;
			}
		}
		break;
		default:   //MISRA C rules
		break;
	}
}

void DIO_TogglePin(Uint8 port, Uint8 pin)
{
	if (pin >=0 && pin <=7)
	{
		DIO_SetPinDir(port, pin, DIO_PIN_OUT);
		switch (port)
		{
			case DIO_PORTA:
			Toggle_Bit(PORTA, pin);
			break;
			case DIO_PORTB:
			Toggle_Bit(PORTB, pin);
			break;
			case DIO_PORTC:
			Toggle_Bit(PORTC, pin);
			break;
			case DIO_PORTD:
			Toggle_Bit(PORTD, pin);
			break;
			default:   //MISRA C rules
			break;
		}
	}
	else
	{
		DIO_SetPinDir(port, DIO_ALL_PINs, DIO_PIN_OUT);
		switch (port)
		{
			case DIO_PORTA:
			PORTA ^= 0xff;
			break;
			case DIO_PORTB:
			PORTB ^= 0xff;
			break;
			case DIO_PORTC:
			PORTC ^= 0xff;
			break;
			case DIO_PORTD:
			PORTD ^= 0xff;
			break;
			default:   //MISRA C rules
			break;
		}
	}
}
Uint8 DIO_GetPinVal(Uint8 port, Uint8 pin)
{
	Uint8 val = 0;
		if (pin >=0 && pin <=7)
		{
			DIO_SetPinDir(port, pin, DIO_PIN_IN);
			switch (port)
			{
				case DIO_PORTA:
				val = Get_Bit(PINA, pin);
				break;
				case DIO_PORTB:
				val = Get_Bit(PINB, pin);
				break;
				case DIO_PORTC:
				val = Get_Bit(PINC, pin);
				break;
				case DIO_PORTD:
				val = Get_Bit(PIND, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			DIO_SetPinDir(port, DIO_ALL_PINs, DIO_PIN_IN);
			switch (port)
			{
				case DIO_PORTA:
				val = PINA;
				break;
				case DIO_PORTB:
				val = PINB;
				break;
				case DIO_PORTC:
				val = PINC;
				break;
				case DIO_PORTD:
				val = PIND;
				break;
				default:   //MISRA C rules
				break;
			}
		}
	return val;
}
void DIO_SetPullup(Uint8 port, Uint8 pin)
{
		if (pin >=0 && pin <=7)
		{
			DIO_SetPinDir(port, pin, DIO_PIN_IN);
			switch (port)
			{
				case DIO_PORTA:
				Set_Bit(PORTA, pin);
				break;
				case DIO_PORTB:
				Set_Bit(PORTB, pin);
				break;
				case DIO_PORTC:
				Set_Bit(PORTC, pin);
				break;
				case DIO_PORTD:
				Set_Bit(PORTD, pin);
				break;
				default:   //MISRA C rules
				break;
			}
		}
		else
		{
			DIO_SetPinDir(port, DIO_ALL_PINs, DIO_PIN_IN);
			switch (port)
			{
				case DIO_PORTA:
				PORTA = 0xff;
				break;
				case DIO_PORTB:
				PORTB = 0xff;
				break;
				case DIO_PORTC:
				PORTC = 0xff;
				break;
				case DIO_PORTD:
				PORTD = 0xff;
				break;
				default:   //MISRA C rules
				break;
			}
		}
}

