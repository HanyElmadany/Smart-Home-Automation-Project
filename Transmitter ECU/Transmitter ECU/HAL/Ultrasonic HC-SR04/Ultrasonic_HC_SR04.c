/*
 * Ultrasonic_HC_SR04.c
 *
 * Created: 3/13/2020 9:51:10 AM
 *  Author: Hany Elmadany
 */ 
#define F_CPU 1000000UL
#include "../../MCAL/DIO/DIO_Source/DIO.h"
#include "../../MCAL/Timer/TIMER.h"
#include <util/delay.h>
#include "Ultrasonic_HC_SR04.h"


uint8 Timer_over_flow = ZER0_INITIALIZER;

void Ultrasonic_Init(void)
{
	GLOBAL_INTERRUPT_ENABLE();
	Timer1_Enable_Normal_operation();
	Timer1_Enable_Overflow_Int();
}
void Ultrasonic_send_trigger(void)
{
	DIO_Write(ULTRASONIC_TRIGGER_PIN, HIGH);
	_delay_us(10);
	DIO_Write(ULTRASONIC_TRIGGER_PIN, LOW);
}
void Ultrasonic_Get_Distance(uint16* ptr_distance)
{
	uint32 count;
	void Timer_Over_flow_INC(void)
	{
		Timer_over_flow++;
	}
	void Timer_Over_flow_CLEAR(void)
	{
		Timer_over_flow = 0;
	}
	Timer1_SetCallBack_OverFlag(Timer_Over_flow_INC);
	
	Timer1_CaptureOn_RisingEdge();
	while (0 == Timer1_Read_InputCaptureFlag())      // wait for rising edge
	Timer1_CaptureOn_FallingEdge();
	Timer_Over_flow_CLEAR();
	while (0 == Timer1_Read_InputCaptureFlag());    // wait for falling edge
	count = ICR1 + (65535 * Timer_over_flow);     // 65535 capacity of timer1 16 bit registers
	* ptr_distance = (uint16)count/58;
}


