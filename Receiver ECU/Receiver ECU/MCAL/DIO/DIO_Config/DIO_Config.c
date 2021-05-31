/*
 * DIO_Config.c
 *
 * Created: 3/8/2020 2:07:20 PM
 *  Author: Hany Elmadany
 */ 

#include "../../REG_Atmega32.h"
#include "../DIO_Source/DIO.h"
#define DONT_CARE 2
DIO_CONFIG DIO_CONFIG_ARR[number_of_channels]=
{
	
		/*Control slave output pin
		{
			PORT_B,
			P4,
			OUTPUT,
			LOW,
			DONT_CARE
		},*/
		//MOTOR A pin 1 (MOTOR_A_1)
		{
			PORT_A,
			P0,
			OUTPUT,
			LOW,
			DONT_CARE
		},
		//MOTOR A pin 2 (MOTOR_A_2)
		{
			PORT_A,
			P1,
			OUTPUT,
			LOW,
			DONT_CARE
		},
		//MOTOR B pin 1 (MOTOR_B_1)
		{
			PORT_B,
			P0,
			OUTPUT,
			LOW,
			DONT_CARE
		},
		//MOTOR B pin 2 (MOTOR_B_2)
		{
			PORT_B,
			P1,
			OUTPUT,
			LOW,
			DONT_CARE
		},
		//CS pin (Control Slave)
		{
			PORT_B,
			P0,
			OUTPUT,
			HIGH,
			DONT_CARE
		}
	
};