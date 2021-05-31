/*
 * Receiver_ECU.c
 *
 * Created: 10/7/2020 6:43:44 PM
 *  Author: Hany Elmadany
 */ 
# define F_CPU 16000000UL
#include <util/delay.h>
#include "MCAL/REG_Atmega32.h"
#include "MCAL/DIO/DIO_Source/DIO.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/USART/USART.h"
#include "HAL/HC-06 Bluetooth Module/HC06_BLUETOOTH_MODULE.h"
#include "HAL/LCD/LCD.h"
#define LED1_ON 1
#define LED1_OFF 2
#define LED2_ON 3
#define LED2_OFF 4
#define WINDOW_OPEN 5
#define WINDOW_CLOSE 6
#define WINDOW_OFF 0
#define MOTOR_ON 1
#define MOTOR_OFF 0
#define USART_READ_DELAY_MS 10
int main(void)
{
	LCD_vInit();
	DIO_Init();
	Bluetooth_Init ();
	SPI_Init(MASTER);
	uint8 bluetooth_signal;
	uint8 motor_for_flag = MOTOR_OFF;
	uint8 motor_back_flag = MOTOR_OFF;
	
	while(1)
	{
		bluetooth_signal = Bluetooth_Read();
		_delay_ms(USART_READ_DELAY_MS);
		SPI_Send_Data(bluetooth_signal);
		
		switch (bluetooth_signal)
		{
			case LED1_ON:
				{
					LCD_vClear_Display();
					LCD_vWrite_string("LED 1 ON");
				}break;
			case LED1_OFF:
				{
					LCD_vClear_Display();
					LCD_vWrite_string("LED 1 OFF");
				}break;
			case LED2_ON:
				{
					LCD_vClear_Display();
					LCD_vWrite_string("LED 2 ON");
				}break;
			case LED2_OFF:
				{
					LCD_vClear_Display();
					LCD_vWrite_string("LED 2 OFF");
				}break;
			case WINDOW_OPEN:
				{
					if (motor_back_flag == MOTOR_OFF)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Window Opening");
						motor_for_flag = MOTOR_ON;
					}
					else if (motor_back_flag == MOTOR_ON)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Motor Stopped");
						LCD_vCursor_SecondLine();
						LCD_vWrite_string("Press again");
						motor_back_flag = MOTOR_OFF;
					}
				}break;
			case WINDOW_CLOSE:
				{
					if (motor_for_flag == MOTOR_OFF)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Window Closing");
					motor_back_flag = MOTOR_ON;
					}
					else if (motor_for_flag == MOTOR_ON)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Motor Stopped");
						LCD_vCursor_SecondLine();
						LCD_vWrite_string("Press again");
						motor_for_flag = MOTOR_OFF;
					}
				}break;
			case WINDOW_OFF:
				{
					if (motor_for_flag == MOTOR_ON)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Window Opened");
					}
					else if (motor_back_flag == MOTOR_ON)
					{
						LCD_vClear_Display();
						LCD_vWrite_string("Window Closed");
					}
						motor_for_flag = MOTOR_OFF;
						motor_back_flag = MOTOR_OFF;
						
				}break;
		}
	}
}

	
    
	
	


