/*
 * PWM.c
 *
 * Created: 10/13/2020 8:52:08 PM
 *  Author: Hany Elmadany
 */ 
#include "PWM.h"
#include "../REG_Atmega32.h"
#include "../Standard.h"
#include "../Timer/TIMER.h"

//Initializes the PWM in fast mode
void PWM_init(TIMER_ID timer_number)
{
	switch (timer_number)
	{
		case TIMER0:
		{								  
			Timer_Disable(TIMER0);
			Timer_init(TIMER0,FAST_PWM,CLEAR_OC,PRESCALER_1);   // non inverting mode
			Timer_SetTimerStartValue(TIMER0,ZER0_INITIALIZER);        // init timer value with ZER0 
		}break;
		case TIMER2:
		{
			Timer_Disable(TIMER2);
			Timer_init(TIMER2,FAST_PWM,CLEAR_OC,PRESCALER_1); 
			Timer_SetTimerStartValue(TIMER2,ZER0_INITIALIZER);
		}break;
	}
}


//The duty value. A value between 0 (0 %) and 255 (100 %)
void PWM_SetDutyValue(uint8 duty_value, TIMER_ID timer_number)
{
	switch (timer_number)
	{
		case TIMER0:
		{ /*Output Compare Register  OCR0
		   * contains an 8-bit value that is continuously compared
		   * with the counter value (TCNT0). A match can be used to
		   * generate an output compare interrupt
		   * */
			OCR0 = duty_value;
		}break;
		case TIMER2:
		{ 
			OCR2 = duty_value;
		}break;
	}
}

//The duty cycle value. A value between (0 %) and (100 %)
void PWM_SetDutyCycle(uint8 duty_cycle, TIMER_ID timer_number)
{
	uint8 PWM_Actual_Duty;	               //duty cycle is represented by a number from 0->255
	PWM_Actual_Duty = (duty_cycle * TIMER_MAX_VALUE) / DUTY_CYCLE_MAX_VALUE;
	/*Output Compare Register OCRx
	* contains an 8-bit value that is continuously compared
	* with the counter value (TCNTx). A match can be used to
	* generate an output compare interrupt
	*/
	switch(timer_number)
	{

		case TIMER0:
		{
			OCR0 = PWM_Actual_Duty;
		}break;

		case TIMER2:
		{
			OCR2 = PWM_Actual_Duty;
		}break;
	}
}

