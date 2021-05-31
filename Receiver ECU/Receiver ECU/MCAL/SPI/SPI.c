/*
 * SPI.c
 *
 * Created: 10/6/2020 6:16:28 PM
 *  Author: Hany Elmadany
 */ 
#include "../REG_Atmega32.h"
#include "../DIO/DIO_Source/DIO.h"
#include "SPI.h"

void SPI_Init(SPI_MODE mode)
{
	
	switch (mode)
	{
		case MASTER:
			{
				SET_BIT(DDRB,P4);             // Slave Select 
				SET_BIT(DDRB,P5);            // MOSI (Master output)
				SET_BIT(DDRB,P7);           // SCK (Master Clock output)
				CLR_BIT(DDRB,P6);	       // MISO (Master input)
				SET_BIT(SPCR,MSTR);       // Master / Slave select
				SET_BIT(SPCR,SPR1);      // set prescaler to 64
				SET_BIT(SPCR,SPE);     // SPI Enable
				SET_BIT(SPCR,SPIE);   // enable interrupt
				SET_BIT(SPCR,DORD);
				
			}
			break;
		case SLAVE:
			{
				CLR_BIT(DDRB,P4);           // Slave Select
				CLR_BIT(DDRB,P5);          // MOSI (Slave input)
				CLR_BIT(DDRB,P7);         // SCK (Master Clock output)
				SET_BIT(DDRB,P6);	     // MISO (Slave output)
				CLR_BIT(SPCR,MSTR);     // Master / Slave select
				SET_BIT(SPCR,SPE);     // SPI Enable
				SET_BIT(SPCR,SPIE);   // enable interrupt
				//SET_BIT(SPCR,DORD);
			}
			break;
	}
	
}

void SPI_Send_Data(uint8 data)
{
	DIO_Write(CS,LOW);
	SPDR = data;
	while(GET_BIT(SPSR,SPIF)==0);
	DIO_Write(CS,HIGH);
}

uint8 SPI_Read_Data()
{
	SPDR = 0xFF;
	while(GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}

void SPI_Send_String(uint8 *str)
{
	while(*str)
	{
		SPI_Send_Data(*str);
		str++;
	}
}

void SPI_Read_String(uint8 *str)
{
	uint8 i = 0;
	str[i] = SPI_Read_Data();
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_Read_Data();
	}
	str[i] = '\0';
}