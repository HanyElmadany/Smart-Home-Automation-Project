/*
 * LCD.h
 *
 * Created: 10/13/2020 5:56:20 PM
 *  Author: Hany Elmadany
 */ 


#include "../../MCAL/Standard.h"
#ifndef LCD_H_
#define LCD_H_

void LCD_Send_cmd (uint8 cmd);
void LCD_vInit (void);
void LCD_vEnable (void);
void LCD_vWrite_char (uint8 data);
void LCD_vWrite_string (uint8 * data);
void LCD_vShift_Cursor_Right (void);
void LCD_vShift_Cursor_Left (void);
void LCD_vClear_Display (void);
void LCD_vCursor_SecondLine (void);




#endif /* LCD_H_ */