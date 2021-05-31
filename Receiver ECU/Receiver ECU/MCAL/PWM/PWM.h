/*
 * PWM.h
 *
 * Created: 10/13/2020 8:52:01 PM
 *  Author: Hany Elmadany
 */ 


#include "../Timer/TIMER.h"
#ifndef PWM_H_
#define PWM_H_

void PWM_init(TIMER_ID timer_number);
void PWM_SetDutyValue(uint8 duty_value, TIMER_ID timer_number);
void PWM_SetDutyCycle(uint8 duty_cycle, TIMER_ID timer_number);

#endif /* PWM_H_ */