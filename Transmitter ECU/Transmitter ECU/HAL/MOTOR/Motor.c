/*
 * Motor.c
 *
 * Created: 3/13/2020 4:48:31 PM
 *  Author: Hany Elmadany
 */
#include "Motor.h"
#include "../../MCAL/PWM/PWM.h"
#include "../../MCAL/DIO/DIO_Source/DIO.h"

void Motor_Init(void)
{
	PWM_init(TIMER0);
	PWM_init(TIMER2);
}

void Motor_move_forward(void)
{	//clockwise direction 
	DIO_Set_Channel(MOTOR_A_1);  // left motor
	DIO_Clr_Channel(MOTOR_A_2);
	DIO_Set_Channel(MOTOR_B_1);  //right motor
	DIO_Clr_Channel(MOTOR_B_2);
}

void Motor_move_backward(void)
{
	//counter clockwise direction
	DIO_Set_Channel(MOTOR_A_2);
	DIO_Clr_Channel(MOTOR_A_1);
	DIO_Set_Channel(MOTOR_B_2);
	DIO_Clr_Channel(MOTOR_B_1);	
}

void Motor_set_speed_left (uint8 speed)
{	//MOTOR_A
	PWM_SetDutyCycle(speed,TIMER0);
}

void Motor_set_speed_right (uint8 speed)
{	//MOTOR_B
	PWM_SetDutyCycle(speed,TIMER2);
}

void Motor_move_right(uint8 left_speed)
{
	Motor_set_speed_right(0);
	Motor_set_speed_left(left_speed);
}
void Motor_move_left(uint8 right_speed)
{
	Motor_set_speed_left(0);
	Motor_set_speed_right(right_speed);
}
void Motor_stop(void)
{
	Motor_set_speed_left(0);
	Motor_set_speed_right(0);
}