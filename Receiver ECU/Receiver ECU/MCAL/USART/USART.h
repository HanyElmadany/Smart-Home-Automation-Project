/*
 * USART.h
 *
 * Created: 3/14/2020 5:51:20 PM
 *  Author: Hany Elmadany
 */ 

#include "USART_Config.h"
#include "../Standard.h"

#ifndef USART_H_
#define USART_H_


void USART_Init(Struct_USART);
uint8 USART_Receive(void);
uint16 USART_Receive_9bit(void);
void USART_Transmit(uint8 Send_Data);
void USART_Transmit_String(uint8* Array_String);
void USART_Transmit_9Bit(uint16 Data_9bit);
void USART_Disable(void);
Struct_Status USART_Rx_Error_Detection(void);




#endif /* USART_H_ */