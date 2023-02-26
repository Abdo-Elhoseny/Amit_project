/*
 * LCD.h
 *
 * Author : Hossam Elbahrawy
 */

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "..\..\HALL\LCD\lcd_config.h"

/*----------------CLEAR LCD -------------------*/
#define LCD_CMD_CLEAR_DISPLAY	             0x01
/*----------------CURSOR HOME POSITION -------------------*/
#define LCD_CMD_CURSOR_HOME		             0x02

// Display control
#define LCD_CMD_DISPLAY_OFF                0x08
#define LCD_CMD_DISPLAY_NO_CURSOR          0x0c
#define LCD_CMD_DISPLAY_CURSOR_NO_BLINK    0x0E
#define LCD_CMD_DISPLAY_CURSOR_BLINK       0x0F

// Function set
/*---------------- 4-BIT CONFIGURATION -------------------*/
#define LCD_CMD_4BIT_2ROW_5X7              0x28
/*---------------- 8-BIT CONFIGURATION -------------------*/
#define LCD_CMD_8BIT_2ROW_5X7              0x38

//functions prototype
/*---------------- LCD INITIALIZATION -------------------*/
void lcd_init(void);
/*---------------- LCD SEND COMMAND -------------------*/
void lcd_send_command (uint8_t );
/*---------------- LCD WRITE CHARACTER -------------------*/
void lcd_write_character(uint8_t );
/*---------------- LCD WRITE WORD -------------------*/
void lcd_write_word(uint8_t[]);
/*---------------- CLEAR LCD -------------------*/
void lcd_clear(void);
/*---------------- ENABLE COURSER -------------------*/
void lcd_set_courser(uint8_t,uint8_t);
/*---------------- SET POSITION -------------------*/
void lcd_goto_xy (uint8_t , uint8_t );



#endif /* LCD_H_ */
