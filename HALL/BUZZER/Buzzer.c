#include "..\..\HALL\BUZZER\Buzzer.h"

/*---------------Buzzer functions--------------*/
void Buzzer_Init(void)
{
	DIO_SetPinDir(Buzzer_Port, Buzzer_Pin, DIO_PIN_ON);
	DIO_SetPinVal(Buzzer_Port, Buzzer_Pin, DIO_PIN_OFF);
}
/*---------------- buzzer on -------------------*/
void Buzzer_ON(void)
{
	DIO_SetPinVal(Buzzer_Port, Buzzer_Pin, PIN_ON);
}
/*---------------- buzzer off -------------------*/
void Buzzer_OFF(void)
{
	DIO_SetPinVal(Buzzer_Port, Buzzer_Pin, PIN_OFF);
}
/*---------------- toggle  buzzer -------------------*/
void Buzzer_Toggle(void)
{
	DIO_TogglePin(Buzzer_Port, Buzzer_Pin);
}
