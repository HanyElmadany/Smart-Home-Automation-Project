/*
 * SPI.h
 *
 * Created: 10/6/2020 6:16:15 PM
 *  Author: Hany Elmadany
 */ 

#include "../Standard.h"
#ifndef SPI_H_
#define SPI_H_

typedef enum{SLAVE, MASTER}SPI_MODE;

void SPI_Init(SPI_MODE);
void SPI_Send_Data(uint8 data);
uint8 SPI_Read_Data();
void SPI_Send_String(uint8 *str);
void SPI_Read_String(uint8 *str);

#endif /* SPI_H_ */