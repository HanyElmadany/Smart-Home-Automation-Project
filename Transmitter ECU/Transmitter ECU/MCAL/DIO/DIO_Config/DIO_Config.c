/*
 * DIO_Config.c
 *
 * Created: 3/8/2020 2:07:20 PM
 *  Author: Hany
 */ 

#include "../../REG_Atmega32.h"
#include "../DIO_Source/DIO.h"
#define DONT_CARE 2
DIO_CONFIG DIO_CONFIG_ARR[number_of_channels]=
{
	
		//Actuator 1 pin
		{
			PORT_C,
			P0,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//Actuator 2 pin
		{
			PORT_C,
			P1,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//MOTOR A pin 1 (MOTOR_A_1)
		{
			PORT_A,
			P0,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//MOTOR A pin 2 (MOTOR_A_2)
		{
			PORT_A,
			P1,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//MOTOR B pin 1 (MOTOR_B_1)
		{
			PORT_A,
			P2,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//MOTOR B pin 2 (MOTOR_B_2)
		{
			PORT_A,
			P3,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//OC0
		{
			PORT_B,
			P3,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//OC2
		{
			PORT_D,
			P7,
			OUTPUT,
			LOW,
			DONT_CARE,
		},
		//INT0 pin
		{
			PORT_D,
			P2,
			INPUT,
			DONT_CARE,
			ENABLE_PULLUP,
		}
		
	
};