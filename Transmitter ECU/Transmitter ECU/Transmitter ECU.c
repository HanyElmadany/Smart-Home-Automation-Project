/*
 * Transmitter_ECU.c
 *
 * Created: 10/7/2020 11:09:10 AM
 *  Author: Hany Elmadany
 */ 

# define F_CPU 16000000UL
#include <util/delay.h>
#include "MCAL/Standard.h"
#include "MCAL/REG_Atmega32.h"
#include "MCAL/SPI/SPI.h"
#include "MCAL/DIO/DIO_Source/DIO.h"
#include "HAL/MOTOR/Motor.h"
#define LED1_ON 1
#define LED1_OFF 2
#define LED2_ON 3
#define LED2_OFF 4
#define WINDOW_OPEN 5
#define WINDOW_CLOSE 6
#define WINDOW_OFF 0
#define MOTOR_ON 1
#define MOTOR_OFF 0
#define MOTOR_DUTY_CYCLE 30
#define ENABLE_EXTERNAL_INT0()  SET_BIT(GICR,INT0)
int main(void)
{
	//SET_BIT(MCUCR,ISC01);
	//ENABLE_EXTERNAL_INT0();
	//GLOBAL_INTERRUPT_ENABLE();
	DIO_Init();
	Motor_Init();	
	SPI_Init(SLAVE);
	uint8 spi_read;
	uint8 motor_for_flag = MOTOR_OFF;
	uint8 motor_back_flag = MOTOR_OFF;
    while(1)
    {
		spi_read = SPI_Read_Data();
		
		switch (spi_read)
		{
			case LED1_ON:
				{
				DIO_Write(actuator1,HIGH);
				}break;
			case LED1_OFF:
				{
					DIO_Write(actuator1,LOW);
				}break;
			case LED2_ON:
				{
					DIO_Write(actuator2,HIGH);
				}break;
			case LED2_OFF:
				{
					DIO_Write(actuator2,LOW);
				}break;
			case WINDOW_OPEN:
				{
					if (motor_back_flag == MOTOR_OFF)
						{
							Motor_set_speed_left(MOTOR_DUTY_CYCLE);
							Motor_set_speed_right(MOTOR_DUTY_CYCLE);
							Motor_move_forward();
							motor_for_flag = MOTOR_ON;
						}
					else if (motor_back_flag == MOTOR_ON)
						{
							Motor_stop();
							motor_back_flag = MOTOR_OFF;
						}
				}break;
			case WINDOW_CLOSE:
				{
					if (motor_for_flag == MOTOR_OFF)
						{
							Motor_set_speed_left(MOTOR_DUTY_CYCLE);
							Motor_set_speed_right(MOTOR_DUTY_CYCLE);
							Motor_move_backward();
							motor_back_flag = MOTOR_ON;
						}
					else if (motor_for_flag == MOTOR_ON)
						{
							Motor_stop();
							motor_for_flag = MOTOR_OFF;
						}
					}break;
			case WINDOW_OFF:
			{
				Motor_stop();
				motor_for_flag = MOTOR_OFF;
				motor_back_flag = MOTOR_OFF;
			}break;
		}
	}
	
}
/*ISR (INT0_vect_num)
{
	Motor_stop();
}*/
