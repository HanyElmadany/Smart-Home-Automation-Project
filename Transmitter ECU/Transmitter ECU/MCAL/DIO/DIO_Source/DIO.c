/*
 * DIO.c
 *
 * Created: 3/8/2020 2:07:54 PM
 *  Author: Hany
 */ 

#include "DIO.h"
void DIO_Init(void)
{
	DIO_CONFIG* channel_ptr = NULL;
	
	for(channel_id channel = 0; channel < number_of_channels; channel++)
	{
		channel_ptr = &DIO_CONFIG_ARR[channel];
		DIO_set_dir(channel);
		if (OUTPUT == channel_ptr->dir)
		{
			DIO_Write(channel, channel_ptr->init_value);
		}
		else
		{
			DIO_pullup(channel);
		}
		
	}
	
}
void DIO_set_dir(channel_id channel)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			if (INPUT == channel_ptr->dir)
			{
				CLR_BIT(DDRA,channel_ptr->pin_num);
			}
			else
			{
				SET_BIT(DDRA,channel_ptr->pin_num);
			}
		}break;
		case PORT_B:
		{
			if (INPUT == channel_ptr->dir)
			{
				CLR_BIT(DDRB,channel_ptr->pin_num);
			}
			else
			{
				SET_BIT(DDRB,channel_ptr->pin_num);
			}
		}break;
		case PORT_C:
		{
			if (INPUT == channel_ptr->dir)
			{
				CLR_BIT(DDRC,channel_ptr->pin_num);
			}
			else
			{
				SET_BIT(DDRC,channel_ptr->pin_num);
			}
		}break;
		case PORT_D:
		{
			if (INPUT == channel_ptr->dir)
			{
				CLR_BIT(DDRD,channel_ptr->pin_num);
			}
			else
			{
				SET_BIT(DDRD,channel_ptr->pin_num);
			}
		}break;
	}
}
void DIO_Write(channel_id channel, uint8 value)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			if (HIGH == value)
			{
				SET_BIT(PORTA,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTA,channel_ptr->pin_num);
			}
		}break;
		case PORT_B:
		{
			if (HIGH == value)
			{
				SET_BIT(PORTB,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTB,channel_ptr->pin_num);
			}
		}break;
		case PORT_C:
		{
			if (HIGH == value)
			{
				SET_BIT(PORTC,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTC,channel_ptr->pin_num);
			}
		}break;
		case PORT_D:
		{
			if (HIGH == value)
			{
				SET_BIT(PORTD,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTD,channel_ptr->pin_num);
			}
		}break;
		
	}
}
void DIO_read(channel_id channel, uint8* value_ptr)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch(channel_ptr->port_name)
	{
		case PORT_A:
		{
			* value_ptr = GET_BIT(PINA,channel_ptr->pin_num);
		}break;
		case PORT_B:
		{
			* value_ptr = GET_BIT(PINB,channel_ptr->pin_num);
		}break;
		case PORT_C:
		{
			* value_ptr = GET_BIT(PINC,channel_ptr->pin_num);
		}break;
		case PORT_D:
		{
			* value_ptr = GET_BIT(PIND,channel_ptr->pin_num);
		}break;
	}
}
void DIO_pullup(channel_id channel)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			if (ENABLE_PULLUP == channel_ptr->pullup_state)
			{
				SET_BIT(PORTA,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTA,channel_ptr->pin_num);
			}			
		}break;
		case PORT_B:
		{
			if (ENABLE_PULLUP == channel_ptr->pullup_state)
			{
				SET_BIT(PORTB,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTB,channel_ptr->pin_num);
			}
		}break;
		case PORT_C:
		{
			if (ENABLE_PULLUP == channel_ptr->pullup_state)
			{
				SET_BIT(PORTC,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTC,channel_ptr->pin_num);
			}
		}break;
		case PORT_D:
		{
			if (ENABLE_PULLUP == channel_ptr->pullup_state)
			{
				SET_BIT(PORTD,channel_ptr->pin_num);
			}
			else
			{
				CLR_BIT(PORTD,channel_ptr->pin_num);
			}
		}break;
	}
}
void DIO_Set_Channel(channel_id channel)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			SET_BIT(PORTA,channel_ptr->pin_num);
		}break;
		case PORT_B:
		{
			SET_BIT(PORTB,channel_ptr->pin_num);
		}break;
		case PORT_C:
		{
			SET_BIT(PORTC,channel_ptr->pin_num);
		}break;
		case PORT_D:
		{
			SET_BIT(PORTD,channel_ptr->pin_num);
		}break;
	}
}
void DIO_Clr_Channel(channel_id channel)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			CLR_BIT(PORTA,channel_ptr->pin_num);
		}break;
		case PORT_B:
		{
			CLR_BIT(PORTB,channel_ptr->pin_num);
		}break;
		case PORT_C:
		{
			CLR_BIT(PORTC,channel_ptr->pin_num);
		}break;
		case PORT_D:
		{
			CLR_BIT(PORTD,channel_ptr->pin_num);
		}break;
	}
}
void DIO_Tog_Channel(channel_id channel)
{
	DIO_CONFIG* channel_ptr = &DIO_CONFIG_ARR[channel];
	switch (channel_ptr->port_name)
	{
		case PORT_A:
		{
			TOG_BIT(PORTA,channel_ptr->pin_num);
		}break;
		case PORT_B:
		{
			TOG_BIT(PORTB,channel_ptr->pin_num);
		}break;
		case PORT_C:
		{
			TOG_BIT(PORTC,channel_ptr->pin_num);
		}break;
		case PORT_D:
		{
			TOG_BIT(PORTD,channel_ptr->pin_num);
		}break;
	}
}