/*
 * HC-06_Bluetooth_Module.h
 *
 * Created: 10/7/2020 2:08:30 PM
 *  Author: Hany Elmadany
 */ 

#include "../../MCAL/Standard.h"
#ifndef HC-06_BLUETOOTH_MODULE_H_
#define HC-06_BLUETOOTH_MODULE_H_

void Bluetooth_Init ();
void Bluetooth_Send (uint8 data);
uint8 Bluetooth_Read ();



#endif /* HC-06 BLUETOOTH MODULE_H_ */