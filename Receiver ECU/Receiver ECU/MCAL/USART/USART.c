/*
 * USART.c
 *
 * Created: 3/14/2020 5:51:27 PM
 *  Author: Hany Elmadany
 */ 

# define F_CPU 1000000UL
#include <util/delay.h>
#include "USART_Config.h"
#include "USART.h"
#include "../REG_Atmega32.h"
void USART_Init(Struct_USART USART_Config)
{ 
	//Initialize USART registers for ATmega32
	uint16 UBRR;
	uint8 Mode;
	if (USART_Config.Operation_Mode == Asynchronous_Double_Speed)
	{
		Mode = 8;
	}
	else 
	{
		Mode = 16;
	}
	CLR_BIT(UBRRH,URSEL);
	UBRR  = (F_CPU/Mode/USART_Config.BuadRate) -1;
	UBRRL = (uint8)UBRR;
	UBRRH = (uint8)(UBRR >> 8);
	CLR_BIT(UCSRC,URSEL);
	
	switch(USART_Config.Operation_Mode)
	{
		case Synchronous:
		{
			SET_BIT(UCSRC,UMSEL);
			CLR_BIT(UCSRA,U2X);
		}break;
		
		case Asynchronous_Normal_Speed:
		{
			CLR_BIT(UCSRC,UMSEL);
			CLR_BIT(UCSRA,U2X);
		}break;
		case Asynchronous_Double_Speed:
		{
			CLR_BIT(UCSRC,UMSEL);
			SET_BIT(UCSRA,U2X);
		}break;
	}
	
	switch(USART_Config.Duplex_Select)
	{
		case TX_Mode:
		{
			SET_BIT(UCSRB,TXEN);
		}break;
		case RX_Mode:
		{
			SET_BIT(UCSRB,RXEN);
		}break;
		case TX_RX_Mode:
		{
			SET_BIT(UCSRB,TXEN);
			SET_BIT(UCSRB,RXEN);
		}break;
		default:
		{
			SET_BIT(UCSRB,TXEN);
		}break; 
	}
	
	switch(USART_Config.Character_Size)
	{
		case Char_5_Bits:
		{
			CLR_BIT(UCSRB,UCSZ2);
			CLR_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRC,UCSZ0);
		}break;
		case Char_6_Bits:
		{
			CLR_BIT(UCSRB,UCSZ2);
			CLR_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);			
		}break;
		case Char_7_Bits:
		{
			CLR_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			CLR_BIT(UCSRC,UCSZ0);			
		}break;
		case Char_8_Bits:
		{
			CLR_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
		}break;
		case Char_9_Bits:
		{
			SET_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
		}break;
		default:
		{
			CLR_BIT(UCSRB,UCSZ2);
			SET_BIT(UCSRC,UCSZ1);
			SET_BIT(UCSRC,UCSZ0);
		}break;
	}
	
	switch(USART_Config.Parity_Mode)
	{
		case No_Parity:
		{
			CLR_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
		}break;
		case Even_Parity:
		{
			SET_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
		}break;
		case Odd_Parity:
		{
			SET_BIT(UCSRC,UPM1);
			SET_BIT(UCSRC,UPM0);
		}break;
		default:
		{
			CLR_BIT(UCSRC,UPM1);
			CLR_BIT(UCSRC,UPM0);
		}break;
	}
	
	switch(USART_Config.Stop_Bit){
		case One_Bit:
		{
			CLR_BIT(UCSRC,USBS);
		}break;
		case Two_Bits:
		{
			SET_BIT(UCSRC,USBS);
		}break;
		default:
		{
			CLR_BIT(UCSRC,USBS);
		}break;
	}

	switch(USART_Config.Clock_Polirity){
		case TX_Falling_Edge:
		{
			SET_BIT(UCSRC,UCPOL);
		}break;
		case TX_Rising_Edge:
		{
			CLR_BIT(UCSRC,UCPOL);
		}break;
		default:
		{
			CLR_BIT(UCSRC,UCPOL);
		}break;
	}
	
	switch(USART_Config.interrupt_Select)
	{
		case RX_Complete_Int_Enable:
		{
			SET_BIT(UCSRB,RXCIE);
		}break;
		case TX_Complete_Int_Enable:
		{
			SET_BIT(UCSRB,TXCIE);
		}break;
		case Data_Reg_Empty_Int_Enable:
		{
			SET_BIT(UCSRB,UDRIE);
		}break;
		default:
		{
			CLR_BIT(UCSRB,RXCIE);
			SET_BIT(UCSRB,TXCIE);
			SET_BIT(UCSRB,UDRIE);
		}break;
	}
}


Struct_Status USART_Rx_Error_Detection( void )
{//Function receive the data of the USART and check if there is possible errors or not
	Struct_Status Data_Error;
	while (!( GET_BIT(UCSRA,RXC) ));		//	Wait for the data to be received	
	
	if( (GET_BIT(UCSRA,FE) == 0) && (GET_BIT(UCSRA,DOR) == 0) && (GET_BIT(UCSRA,PE) == 0) )
	{
		Data_Error.Detection = Correct;
	}
	else if ((GET_BIT(UCSRA,FE)) != 0)
	{
		Data_Error.Detection = Frame_Error;
	}
	else if ((GET_BIT(UCSRA,DOR)) != 0)
	{
		Data_Error.Detection = Data_OverFlow;
	}
	else if ((GET_BIT(UCSRA,PE)) != 0)
	{
		Data_Error.Detection = Parity_Error;
	}
	Data_Error.Data = UDR;
	return Data_Error;
}


uint8 USART_Receive( void )
{//Function receive the data of the UDR register
	while (!(GET_BIT(UCSRA,RXC)));		//	Wait for the data to be received
	return UDR;
}

uint16 USART_Receive_9bit( void )
{//Function receive the data of the UDR register if the frame structure is 9-bit
	uint16 Data_9bit = 0;
	while (!GET_BIT(UCSRA,RXC));
	Data_9bit |= ((UCSRB & (1 << RXB8)) << 8);
	Data_9bit |= UDR;
	return Data_9bit;
}


void USART_Transmit( uint8 Data )
{//Function Transmit the data to the UDR register
	while (!(GET_BIT(UCSRA,UDRE)));	/*	Wait for the Buffer register to be Free.(1)	*/	
	UDR = Data;				
}


void USART_Transmit_9Bit( uint16 Data_9bit )
{//Function Transmit the data to the UDR register if the frame structure is 9-bit
	while(!(GET_BIT(UCSRA,UDRE)));
	UCSRB |= ((Data_9bit & (1U << 8)) << TXB8);
	UDR = Data_9bit;
}


void USART_Transmit_String( uint8* String )
{ //Function Transmit the data in the form of array of char to the UDR register
	uint8 Index = 0;
	while (String[Index] != '\0')
	{
		USART_Transmit(String[Index++]);
	}
}


void USART_Disable( void )
{//Function used to disable the USART and override the USART pins to the default state
	CLR_BIT(UCSRB,TXEN);          	
	CLR_BIT(UCSRB,RXEN);
}