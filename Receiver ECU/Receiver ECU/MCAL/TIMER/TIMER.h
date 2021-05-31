/*
 * TIMER.h
 *
 * Created: 10/13/2020 8:53:57 PM
 *  Author: Hany Elmadany
 */ 

#include "../Standard.h"
#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_MAX_VALUE 255
#define DUTY_CYCLE_MAX_VALUE 100


typedef enum{TIMER0, TIMER2}TIMER_ID;
typedef enum{NORMAL, CTC, PWM_PHASE_CORRECT, FAST_PWM}TIMER_MODE;
typedef enum{OC_DISCONNECTED, CLEAR_OC, SET_OC, TOG_OC}COMPARE_OUTPUT_MODE;
typedef enum{CLK_SOURCE_DISCONNECTED, PRESCALER_1, PRESCALER_8,PRESCALER_32, PRESCALER_64,PRESCALER_128, PRESCALER_256,
PRESCALER_1024, EXTERNAL_CLK_FAIL_EDGE, EXTERNAL_CLK_RISE_EDGE}PRESCALER;
typedef enum{OVERFLOW, COMPARE}INT_TYPE;

void Timer_init(TIMER_ID timer_number, TIMER_MODE mode, COMPARE_OUTPUT_MODE oc_pin_state, PRESCALER prescaler);
void Timer_Set_Mode(TIMER_ID timer_number, TIMER_MODE mode);
void Timer_Set_COM(TIMER_ID timer_number, COMPARE_OUTPUT_MODE oc_pin_state);
void Timer_Set_Prescaler(TIMER_ID timer_number, PRESCALER prescaler);
void Timer_SetCallBack (TIMER_ID timer_number, void (*ptr_to_fun) (void), INT_TYPE int_type);
void Timer_SetTimerStartValue(TIMER_ID timer_number, uint8 start_value);
uint8 Timer_GetTimerCounts(uint8 timer_number);
void Timer_Enable_Int(TIMER_ID timer_number, INT_TYPE int_type);
void Timer_Disable_Int(TIMER_ID timer_number, INT_TYPE int_type);
void Timer_Disable(TIMER_ID timer_number);

void Timer1_Enable_Normal_operation(void);
void Timer1_Enable_Overflow_Int (void);
void Timer1_CaptureOn_RisingEdge(void);
void Timer1_CaptureOn_FallingEdge(void);
uint8 Timer1_Read_InputCaptureFlag(void);
void Timer1_SetCallBack_OverFlag(void(*ptr_to_fun)(void));




#endif /* TIMER_H_ */