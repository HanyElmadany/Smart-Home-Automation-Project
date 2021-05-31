/*
 * HC_06_Bluetooth_Module.c
 *
 * Created: 10/7/2020 2:08:14 PM
 *  Author: Hany Elmadany
 */ 

#include "../../MCAL/USART/USART.h"
#include "HC06_BLUETOOTH_MODULE.h"
void Bluetooth_Init ()
{
	 
		Struct_USART bluetooth_config;
		bluetooth_config.Operation_Mode= Asynchronous_Normal_Speed;
		bluetooth_config.Duplex_Select= TX_RX_Mode;
		bluetooth_config.BuadRate= Rate_9600;
		bluetooth_config.Character_Size= Char_8_Bits;
		bluetooth_config.Parity_Mode= No_Parity;
		bluetooth_config.Stop_Bit= One_Bit;
		bluetooth_config.Clock_Polirity= TX_Rising_Edge;
	    bluetooth_config.interrupt_Select= RX_Complete_Int_Enable;
	
	USART_Init(bluetooth_config);
}

void Bluetooth_Send (uint8 data)
{
	 USART_Transmit(data);
}

uint8 Bluetooth_Read()
{
	return USART_Receive();
}