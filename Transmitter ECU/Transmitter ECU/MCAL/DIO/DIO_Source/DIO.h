/*
 * DIO.h
 *
 * Created: 3/8/2020 2:08:06 PM
 *  Author: Hany
 */ 

#include "../../REG_Atmega32.h"
#include "../DIO_Config/DIO_Config.h"

#ifndef DIO_H_
#define DIO_H_
/******************************************************************/
// make struct that have all we need to config DIO
typedef struct
{
	PORT_ID port_name;
	PIN_ID pin_num;
	uint8 dir;
	uint8 init_value;
	uint8 pullup_state;
}DIO_CONFIG;
/******************************************************************/
//Functions prototype
void DIO_Init(void);
void DIO_set_dir(channel_id channel);
void DIO_Write(channel_id channel, uint8 value);
void DIO_read(channel_id channel, uint8* value_ptr);
void DIO_pullup(channel_id channel);
void DIO_Set_Channel(channel_id channel);
void DIO_Clr_Channel(channel_id channel);
void DIO_Tog_Channel(channel_id channel);
/******************************************************************/
extern DIO_CONFIG DIO_CONFIG_ARR[number_of_channels]; 

#endif /* DIO_H_ */