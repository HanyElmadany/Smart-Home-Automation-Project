/*
 * MOTOR.h
 *
 * Created: 10/13/2020 8:50:22 PM
 *  Author: Hany Elmadany
 */ 

#include "../../MCAL/Standard.h"
#ifndef MOTOR_H_
#define MOTOR_H_

void Motor_Init(void);
void Motor_move_forward(void);
void Motor_move_backward(void);
void Motor_set_speed_left (uint8 speed);
void Motor_set_speed_right (uint8 speed);
void Motor_move_right(uint8 left_speed);
void Motor_move_left(uint8 right_speed);
void Motor_stop(void);




#endif /* MOTOR_H_ */