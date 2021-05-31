/*
 * PWM.h
 *
 * Created: 3/12/2020 11:42:02 AM
 *  Author: Hany Elmadany
 */ 

#include "../Timer/TIMER.h"

#ifndef PWM_H_
#define PWM_H_

void PWM_init(TIMER_ID timer_number);
void PWM_SetDutyValue(uint8 duty_value, TIMER_ID timer_number);
void PWM_SetDutyCycle(uint8 duty_cycle, TIMER_ID timer_number);

#endif /* PWM_H_ */