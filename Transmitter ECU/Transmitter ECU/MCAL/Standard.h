/*
 * std.h
 *
 * Created: 3/8/2020 2:06:18 PM
 *  Author: Hany
 */ 


#ifndef STD_H_
#define STD_H_






//Standard types
/****************************************/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
/****************************************/

//MACROS
/********************************************************************************************************************************/
//Standard MACROS
#define NULL ((void *)0)
#define ZER0_INITIALIZER 0x00
#define LOW 0
#define HIGH 1
// PORTS MACROS
#define SET_REG(REG) (REG = 0xFF)                                                     // set register
#define CLR_REG(REG) (REG = 0)                                                       //clear register
#define TOG_REG(REG) (REG ^= 0xFF)                                                  //toggle register
#define ROL_REG(REG,NUM) ( REG = ( REG<<(NUM%8) ) | ( REG>>8-(NUM%8) ) )           //rotate register to the left by NUM
#define ROR_REG(REG,NUM) ( REG = ( REG>>(NUM%8) ) | ( REG<<8-(NUM%8) ) )          //rotate register to the right by NUM
// BITS MACROS
#define SET_BIT(REG,BIT) ( REG |= (1<<BIT) )                                    //Set bit
#define CLR_BIT(REG,BIT) ( REG &= ~(1<<BIT) )                                  //Clear bit
#define GET_BIT(REG,BIT) ( (REG & (1<<BIT) ) >> BIT )                         //Get bit
#define TOG_BIT(REG,BIT) ( REG ^= (1<<BIT) )                                 //Toggle bit
/********************************************************************************************************************************/



#endif /* STD_H_ */