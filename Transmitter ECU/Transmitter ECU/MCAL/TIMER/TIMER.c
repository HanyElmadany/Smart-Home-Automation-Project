/*
 * TIMER.c
 *
 * Created: 3/11/2020 10:47:24 AM
 *  Author: Hany
 */ 

#include "TIMER.h"
#include "../REG_Atmega32.h"

void (*call_back_fun1)(void);
void (*call_back_fun2)(void);
void (*call_back_fun3)(void);
void (*call_back_fun4)(void);
void (*call_back_fun5)(void);


void Timer_init(TIMER_ID timer_number, TIMER_MODE mode, COMPARE_OUTPUT_MODE oc_pin_state, PRESCALER prescaler)
{
	Timer_Set_Mode(timer_number,mode);
	Timer_Set_COM(timer_number,oc_pin_state);
	Timer_Set_Prescaler(timer_number,prescaler);
}
void Timer_Set_Mode(TIMER_ID timer_number, TIMER_MODE mode)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			switch (mode)
			{
				case NORMAL:
				{
					CLR_BIT(TCCR0,WGM00);
					CLR_BIT(TCCR0,WGM01);
				}break;
				case CTC:
				{
					CLR_BIT(TCCR0,WGM00);
					SET_BIT(TCCR0,WGM01);
				}break;
				case PWM_PHASE_CORRECT:
				{
					SET_BIT(TCCR0,WGM00);
					CLR_BIT(TCCR0,WGM01);
				}break;
				case FAST_PWM:
				{
					SET_BIT(TCCR0,WGM00);
					SET_BIT(TCCR0,WGM01);
				}break;
			}
		}break;
		case TIMER2:
		{
			switch (mode)
			{
				case NORMAL:
				{
					CLR_BIT(TCCR2,WGM20);
					CLR_BIT(TCCR2,WGM21);
				}break;
				case CTC:
				{
					CLR_BIT(TCCR2,WGM20);
					SET_BIT(TCCR2,WGM21);
				}break;
				case PWM_PHASE_CORRECT:
				{
					SET_BIT(TCCR2,WGM20);
					CLR_BIT(TCCR2,WGM21);
				}break;
				case FAST_PWM:
				{
					SET_BIT(TCCR2,WGM20);
					SET_BIT(TCCR2,WGM21);
				}break;
			}
		}break;
	}
}
void Timer_Set_COM(TIMER_ID timer_number, COMPARE_OUTPUT_MODE oc_pin_state)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			switch (oc_pin_state)
			{
				case OC_DISCONNECTED:
				{
					CLR_BIT(TCCR0,COM00);
					CLR_BIT(TCCR0,COM01);
				}break;
				case CLEAR_OC:
				{
					CLR_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
				}break;
				case SET_OC:
				{
					SET_BIT(TCCR0,COM00);
					SET_BIT(TCCR0,COM01);
				}break;
				case TOG_OC:
				{
					if (0 == GET_BIT(TCCR0,WGM00))
					{
						SET_BIT(TCCR0,COM00);
						CLR_BIT(TCCR0,COM01);
					}
				}break;
			}
		}break;
		case TIMER2:
		{
			switch (oc_pin_state)
			{
				case OC_DISCONNECTED:
				{
					CLR_BIT(TCCR2,COM20);
					CLR_BIT(TCCR2,COM21);
				}break;
				case CLEAR_OC:
				{
					CLR_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
				}break;
				case SET_OC:
				{
					SET_BIT(TCCR2,COM20);
					SET_BIT(TCCR2,COM21);
				}break;
				case TOG_OC:
				{
					if (0 == GET_BIT(TCCR2,WGM20))
					{
						SET_BIT(TCCR2,COM20);
						CLR_BIT(TCCR2,COM21);
					}
				}break;
			}
		}break;
	}
}
void Timer_Set_Prescaler(TIMER_ID timer_number, PRESCALER prescaler)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			switch (prescaler)
			{
				case CLK_SOURCE_DISCONNECTED:
				{
					CLR_BIT(TCCR0,CS00);
					CLR_BIT(TCCR0,CS01);
					CLR_BIT(TCCR0,CS02);
				}break;
				case PRESCALER_1:
				{
					SET_BIT(TCCR0,CS00);
					CLR_BIT(TCCR0,CS01);
					CLR_BIT(TCCR0,CS02);
				}break;
				case PRESCALER_8:
				{
					CLR_BIT(TCCR0,CS00);
					SET_BIT(TCCR0,CS01);
					CLR_BIT(TCCR0,CS02);
				}break;
				case PRESCALER_32:
				{
					// do nothing (For timer2 only)
				}break;
				case PRESCALER_64:
				{
					SET_BIT(TCCR0,CS00);
					SET_BIT(TCCR0,CS01);
					CLR_BIT(TCCR0,CS02);
				}break;
				case PRESCALER_128:
				{
					// do nothing (For timer2 only)
				}break;
				case PRESCALER_256:
				{
					CLR_BIT(TCCR0,CS00);
					CLR_BIT(TCCR0,CS01);
					SET_BIT(TCCR0,CS02);
				}break;
				case PRESCALER_1024:
				{
					SET_BIT(TCCR0,CS00);
					CLR_BIT(TCCR0,CS01);
					SET_BIT(TCCR0,CS02);
				}break;
				case EXTERNAL_CLK_FAIL_EDGE:
				{
					CLR_BIT(TCCR0,CS00);
					SET_BIT(TCCR0,CS01);
					SET_BIT(TCCR0,CS02);
				}break;
				case EXTERNAL_CLK_RISE_EDGE:
				{
					SET_BIT(TCCR0,CS00);
					SET_BIT(TCCR0,CS01);
					SET_BIT(TCCR0,CS02);
				}break;
			}
		}break;
		case TIMER2:
		{
			switch (prescaler)
			{
				case CLK_SOURCE_DISCONNECTED:
				{
					CLR_BIT(TCCR2,CS20);
					CLR_BIT(TCCR2,CS21);
					CLR_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_1:
				{
					SET_BIT(TCCR2,CS20);
					CLR_BIT(TCCR2,CS21);
					CLR_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_8:
				{
					CLR_BIT(TCCR2,CS20);
					SET_BIT(TCCR2,CS21);
					CLR_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_32:
				{
					SET_BIT(TCCR2,CS20);
					SET_BIT(TCCR2,CS21);
					CLR_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_64:
				{
					CLR_BIT(TCCR2,CS20);
					CLR_BIT(TCCR2,CS21);
					SET_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_128:
				{
					SET_BIT(TCCR2,CS20);
					CLR_BIT(TCCR2,CS21);
					SET_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_256:
				{
					CLR_BIT(TCCR2,CS20);
					SET_BIT(TCCR2,CS21);
					SET_BIT(TCCR2,CS22);
				}break;
				case PRESCALER_1024:
				{
					SET_BIT(TCCR2,CS20);
					SET_BIT(TCCR2,CS21);
					SET_BIT(TCCR2,CS22);
				}break;
				case EXTERNAL_CLK_FAIL_EDGE:
				{
					// do nothing (For timer0 only)
				}break;
				case EXTERNAL_CLK_RISE_EDGE:
				{
					// do nothing (For timer0 only)
				}break;
			}
		}break;
	}
}
void Timer_SetTimerStartValue(TIMER_ID timer_number, uint8 start_value)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			TCNT0 = start_value;
		}break;
		case TIMER2:
		{
			TCNT2 = start_value;
		}break;
	}
}
uint8 Timer_GetTimerCounts(TIMER_ID timer_number)
{
	uint8 return_value =0;
	switch (timer_number)
	{
		
		case TIMER0:
		{
			return_value = TCNT0;
		}break;
		case TIMER2:
		{
			return_value = TCNT2;
		}break;
	}
	return return_value;
}
void Timer_Enable_Int(TIMER_ID timer_number, INT_TYPE int_type)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			switch (int_type)
			{
				case OVERFLOW:
				{
					SET_BIT(TIMSK, 0);
				}break;
				case COMPARE:
				{
					SET_BIT(TIMSK, 1);
				}break;
			}
		}break;
		
		case TIMER2:
		{
			switch (int_type)
			{
				case OVERFLOW:
				{
					SET_BIT(TIMSK, 6);
				}break;
				case COMPARE:
				{
					SET_BIT(TIMSK, 7);
				}break;
			}
		}break;
	}
	GLOBAL_INTERRUPT_ENABLE();
}
void Timer_Disable_Int(TIMER_ID timer_number, INT_TYPE int_type)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			switch (int_type)
			{
				case OVERFLOW:
				{
					CLR_BIT(TIMSK, 0);
				}break;
				case COMPARE:
				{
					CLR_BIT(TIMSK, 1);
				}break;
			}
		}break;
		
		case TIMER2:
		{
			switch (int_type)
			{
				case OVERFLOW:
				{
					CLR_BIT(TIMSK, 6);
				}break;
				case COMPARE:
				{
					CLR_BIT(TIMSK, 7);
				}break;
			}
		}break;
	}
}
void Timer_SetCallBack (TIMER_ID timer_number, void (*ptr_to_fun) (void), INT_TYPE int_type)
{
	switch(timer_number)
	{
		case TIMER0:
		switch(int_type)
		{
			case COMPARE:
			call_back_fun1 = ptr_to_fun;
			break;
			case OVERFLOW:
			call_back_fun2 = ptr_to_fun;
			break;
		}break;

		case TIMER2:
		switch(int_type)
		{
			case COMPARE:
			{
				call_back_fun3 = ptr_to_fun;
			}break;
			case OVERFLOW:
			{
				call_back_fun4 = ptr_to_fun;
			}break;
		}break;
	}
}
void Timer_Disable(TIMER_ID timer_number)
{
	switch (timer_number)
	{
		case TIMER0:
		{
			TCCR0 = ZER0_INITIALIZER;
		}break;
		case TIMER2:
		{
			TCCR2 = ZER0_INITIALIZER;
		}break;
	}
}

void Timer1_CaptureOn_RisingEdge(void)
{
	TCCR1B = 0x41;                     //Capture on rising edge, No prescaler
	TCNT1 = ZER0_INITIALIZER;          // Clear Timer counter
	SET_BIT(TIMSK,TOIE1);            //Enable timer1 overflow interrupt
	CLR_BIT(TIFR,ICF1);             //Clear ICP flag
	CLR_BIT(TIFR,TOV1);     //Clear Timer Overflow flag
}
void Timer1_CaptureOn_FallingEdge(void)
{
	TCCR1B = 0x01;                     //Capture on rising edge, No prescaler
	TCNT1 = ZER0_INITIALIZER;          // Clear Timer counter
	SET_BIT(TIMSK,TOIE1);            //Enable timer1 overflow interrupt
	CLR_BIT(TIFR,ICF1);             //Clear ICP flag
	CLR_BIT(TIFR,TOV1);     //Clear Timer Overflow flag
}
uint8 Timer1_Read_InputCaptureFlag(void)
{
	return GET_BIT(TIFR,ICF1);
}
void Timer1_SetCallBack_OverFlag(void(*ptr_to_fun)(void))
{
	call_back_fun5 = ptr_to_fun;
}

void Timer1_Enable_Overflow_Int (void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_Enable_Normal_operation(void)
{
	TCCR1A = ZER0_INITIALIZER;
}

ISR(VECT_TIMER0_COMP)
{
	call_back_fun1();
}

ISR(VECT_TIMER0_OVF){
	call_back_fun2();
}
ISR(VECT_TIMER1_OVF)
{
	call_back_fun5();
}
ISR(VECT_TIMER2_COMP){
	call_back_fun3();
}

ISR(VECT_TIMER2_OVF){
	call_back_fun4();
}