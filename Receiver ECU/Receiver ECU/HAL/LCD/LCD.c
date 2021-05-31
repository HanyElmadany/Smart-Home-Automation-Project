/*
 * LCD.c
 *
 * Created: 10/13/2020 5:56:12 PM
 *  Author: Hany Elmadany
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Source/DIO.h"
#include "LCD.h"
#include "LCD_Config.h"


void LCD_Send_cmd (uint8 cmd)
{
	#ifdef LCD_MODE_8BIT
	DIO_vWritePort(LCD_8BIT_PORT, cmd);
	#endif
	
	#ifdef LCD_MODE_4BIT
	uint8 data_bus;
	data_bus = cmd & (0xF0);
	DIO_vWritePin(LCD_DB4_PORT, LCD_DB4_PIN, ( ( data_bus & (1<<4) ) >> 4 ) );
	DIO_vWritePin(LCD_DB5_PORT, LCD_DB5_PIN, ( ( data_bus & (1<<5) ) >> 5 ) );
	DIO_vWritePin(LCD_DB6_PORT, LCD_DB6_PIN, ( ( data_bus & (1<<6) ) >> 6 ) );
	DIO_vWritePin(LCD_DB7_PORT, LCD_DB7_PIN, ( ( data_bus & (1<<7) ) >> 7 ) );
	DIO_vWritePin(LCD_RS_PORT, LCD_RS, LOW);
	LCD_vEnable();
	data_bus = ( cmd & (0x0F) ) << 4;
	DIO_vWritePin(LCD_DB4_PORT, LCD_DB4_PIN, ( ( data_bus & (1<<4) ) >> 4 ) );
	DIO_vWritePin(LCD_DB5_PORT, LCD_DB5_PIN, ( ( data_bus & (1<<5) ) >> 5 ) );
	DIO_vWritePin(LCD_DB6_PORT, LCD_DB6_PIN, ( ( data_bus & (1<<6) ) >> 6 ) );
	DIO_vWritePin(LCD_DB7_PORT, LCD_DB7_PIN, ( ( data_bus & (1<<7) ) >> 7 ) );
	#endif
	
	DIO_vWritePin(LCD_RS_PORT, LCD_RS, LOW);     // 0 to RS cause we will send command not data
	LCD_vEnable();
}



void LCD_vInit (void)
{
	
	DIO_vSetPinDir(LCD_RS_PORT, LCD_RS, OUTPUT);
	DIO_vSetPinDir(LCD_RW_PORT, LCD_RW, OUTPUT);
	DIO_vWritePin(LCD_RW_PORT, LCD_RW, LOW);      // RW always be 0 cause we will write only...
	DIO_vSetPinDir(LCD_EN_PORT, LCD_EN, OUTPUT);
	
	#ifdef LCD_MODE_8BIT
	#ifndef LCD_MODE_4BIT
	DIO_vSetportDir(LCD_8BIT_PORT, OUTPUT);
	LCD_Send_cmd(0x38);
	#endif
	#endif
	
	#ifdef LCD_MODE_4BIT
	#ifndef LCD_MODE_8BIT
	DIO_vSetPinDir(LCD_DB4_PORT, LCD_DB4_PIN, OUTPUT);
	DIO_vSetPinDir(LCD_DB5_PORT, LCD_DB5_PIN, OUTPUT);
	DIO_vSetPinDir(LCD_DB6_PORT, LCD_DB6_PIN, OUTPUT);
	DIO_vSetPinDir(LCD_DB7_PORT, LCD_DB7_PIN, OUTPUT);
	LCD_Send_cmd(0x33);
	LCD_Send_cmd(0x32);
	LCD_Send_cmd(0x28);
	#endif
	#endif
	
	LCD_Send_cmd(0x0F);
	LCD_Send_cmd(0x01);
	_delay_ms(20);
}




void LCD_vEnable (void)
{
	DIO_vWritePin(LCD_EN_PORT, LCD_EN, HIGH);
	_delay_ms(5);
	DIO_vWritePin(LCD_EN_PORT, LCD_EN, LOW);
	_delay_ms(5);
}

void LCD_vWrite_char (uint8 data)
{
	#ifdef LCD_MODE_8BIT
	DIO_vWritePort(LCD_8BIT_PORT, data);
	#endif
	
	#ifdef LCD_MODE_4BIT
	uint8 data_bus;
	data_bus = data & (0xF0);
	DIO_vWritePin(LCD_DB4_PORT, LCD_DB4_PIN, ( ( data_bus & (1<<4) ) >> 4 ) );
	DIO_vWritePin(LCD_DB5_PORT, LCD_DB5_PIN, ( ( data_bus & (1<<5) ) >> 5 ) );
	DIO_vWritePin(LCD_DB6_PORT, LCD_DB6_PIN, ( ( data_bus & (1<<6) ) >> 6 ) );
	DIO_vWritePin(LCD_DB7_PORT, LCD_DB7_PIN, ( ( data_bus & (1<<7) ) >> 7 ) );
	DIO_vWritePin(LCD_RS_PORT, LCD_RS, LOW);
	LCD_vEnable();
	data_bus = ( data & (0x0F) ) << 4;
	DIO_vWritePin(LCD_DB4_PORT, LCD_DB4_PIN, ( ( data_bus & (1<<4) ) >> 4 ) );
	DIO_vWritePin(LCD_DB5_PORT, LCD_DB5_PIN, ( ( data_bus & (1<<5) ) >> 5 ) );
	DIO_vWritePin(LCD_DB6_PORT, LCD_DB6_PIN, ( ( data_bus & (1<<6) ) >> 6 ) );
	DIO_vWritePin(LCD_DB7_PORT, LCD_DB7_PIN, ( ( data_bus & (1<<7) ) >> 7 ) );
	#endif
	
	DIO_vWritePin(LCD_RS_PORT, LCD_RS, HIGH);
	LCD_vEnable();
}

void LCD_vWrite_string (uint8 * data)
{
	
	for (uint8 i = 0; data[i] != '\0'; i++ )
	{
		LCD_vWrite_char(data[i]);
	}
}

void LCD_vShift_Cursor_Right (void)
{
	LCD_Send_cmd(0x14);
}

void LCD_vShift_Cursor_Left (void)
{
	LCD_Send_cmd(0x10);
}

void LCD_vClear_Display (void)
{
	LCD_Send_cmd(0x01);
}

void LCD_vCursor_SecondLine (void)
{
	LCD_Send_cmd(0xC0);
}