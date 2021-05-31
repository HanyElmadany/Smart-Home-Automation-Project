/*
 * USART_Config.h
 *
 * Created: 3/14/2020 5:57:19 PM
 *  Author: Hany Elmadany
 */ 

#include "../Standard.h"
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_
#ifndef F_CPU
#define F_CPU 1000000ul
#include <util/delay.h>
#endif
#include <avr/io.h>

typedef enum{
	Synchronous,
	Asynchronous_Normal_Speed,
	Asynchronous_Double_Speed,
}Operation;

typedef enum{
	TX_Mode,
	RX_Mode,
	TX_RX_Mode
}Duplex;

typedef enum{
	Rate_2400   = 2400,
	Rate_4800   = 4800,
	Rate_9600   = 9600,
	Rate_14_4k  = 14400,
	Rate_19_2k  = 19200,
	Rate_28_8k  = 28800,
	Rate_38_4k  = 38400,
	Rate_57_6k  = 57600,
	Rate_76_8k  = 76800,
	Rate_115_2k = 115200,
	Rate_230_4k = 230400,
	Rate_250k   = 250000,
	Rate_500k   = 500000,
	Rate_1M     = 1000000
}Baud_Rate;

typedef enum{
	Char_5_Bits,
	Char_6_Bits,
	Char_7_Bits,
	Char_8_Bits,
	Char_9_Bits
}Character;

typedef enum{
	No_Parity,
	Even_Parity,
	Odd_Parity
}Parity;

typedef enum{
	One_Bit,
	Two_Bits
}Stop;

typedef enum{
	TX_Rising_Edge,
	TX_Falling_Edge
}Polirity;

typedef enum{
	RX_Complete_Int_Enable,
	TX_Complete_Int_Enable,
	Data_Reg_Empty_Int_Enable
}interrupt_Set;

 typedef struct{
	Operation	Operation_Mode;
	Duplex		Duplex_Select;
	Baud_Rate	BuadRate;
	Character	Character_Size;
	Parity		Parity_Mode;
	Stop		Stop_Bit;
	Polirity	Clock_Polirity;
	interrupt_Set	interrupt_Select;
}Struct_USART;

typedef enum{
	Parity_Error,
	Data_OverFlow,
	Frame_Error,
	Correct
}RX_Data_Status;

 typedef struct{
	RX_Data_Status Detection;
	uint8 Data;
}Struct_Status;






#endif /* USART_CONFIG_H_ */