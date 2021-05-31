/*
 * DIO.h
 *
 * Created: 3/8/2020 2:08:06 PM
 *  Author: Hany Elmadany
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
/******************************************************************/
					//another way
/******************************************************************/
/* Base addresses for each PORT (base address is the address of PINx,
   address of DDRx is (base+1) & address of PORTx is (base+2)*/
#define A (0x39)
#define B (0x36)
#define C (0x33)
#define D (0x30)

// For AVR we need to set the bit for output and clear the bit for input
#define OUTPUT 1
#define INPUT 0

// we only have two possibilities to write on port or pin (0 to low voltage OR 1 to high voltage)

#define	HIGH 1
#define	LOW 0



// functions prototypes
void DIO_vSetPinDir (uint8 base, uint8 pin_number, uint8 state);             // function to set pinx direction
void DIO_vSetportDir (uint8 base, uint8 state);                             // function to set portx direction
void DIO_vWritePin (uint8 base, uint8 pin_number, uint8 voltage);          // function to write to pinx
void DIO_vWritePort (uint8 base, uint8 voltage);                          // function to write to portx
uint8 DIO_u8ReadPin (uint8 base, uint8 pin_number);                      // function to read from the pinx
uint8 DIO_u8ReadPort (uint8 base);                                      // function to read from the portx
void DIO_vToggPin (uint8 base, uint8 pin_number);                      // function to toggle pinx
void DIO_vToggPort (uint8 base);                                      // function to toggle portx

/******************************************************************/

#endif /* DIO_H_ */