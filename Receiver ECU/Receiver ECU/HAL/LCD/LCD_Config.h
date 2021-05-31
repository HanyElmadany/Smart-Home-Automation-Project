/*
 * LCD_Config.h
 *
 * Created: 10/13/2020 6:01:02 PM
 *  Author: Hany Elmadany
 */ 

#include "../../MCAL/DIO/DIO_Source/DIO.h"
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

// MACROS defined by the user
#define LCD_MODE_8BIT                               // select 8-bit operation
//#define LCD_MODE_4BIT                               // select 4-bit operation
#define LCD_EN_PORT C                              // select Enable port
#define LCD_EN 0                                  // select E pin
#define LCD_RS_PORT C                            // select RS port
#define LCD_RS 2                                // select RS pin
#define LCD_RW_PORT C                          // select RW port
#define LCD_RW 1                              // select RW pin
#define LCD_8BIT_PORT A                     // select LCD pins port (FOR 8 BIT OPERATION)
#define LCD_DB4_PORT A
#define LCD_DB4_PIN 0
#define LCD_DB5_PORT A
#define LCD_DB5_PIN 1
#define LCD_DB6_PORT A
#define LCD_DB6_PIN 2
#define LCD_DB7_PORT A
#define LCD_DB7_PIN 3

#ifdef LCD_MODE_8BIT
#ifdef LCD_MODE_4BIT
#error 2 operation modes defined
#endif
#endif

#ifndef LCD_MODE_8BIT
#ifndef LCD_MODE_4BIT
#error Please define LCD operation mode
#endif
#endif

#ifndef LCD_8BIT_PORT
#error Please define LCD pins port FOR 8BIT OPERATION
#endif

#ifndef LCD_EN_PORT
#error Please define Enable port
#endif

#ifndef LCD_EN
#error Please define Enable pin
#endif

#ifndef LCD_RS_PORT
#error Please define RS port
#endif

#ifndef LCD_RS
#error Please define RS pin
#endif

#ifndef LCD_RW_PORT
#error Please define RW port
#endif

#ifndef LCD_RW
#error Please define RW pin
#endif


#ifdef LCD_MODE_4BIT

#ifndef LCD_DB4_PIN
#error Please define LCD DB4 pin
#endif

#ifndef LCD_DB5_PIN
#error Please define LCD DB5 pin
#endif

#ifndef LCD_DB6_PIN
#error Please define LCD DB6 pin
#endif

#ifndef LCD_DB7_PIN
#error Please define LCD DB7 pin
#endif

#endif

#endif /* LCD_CONFIG_H_ */