/*
 * REG_Atmega32.h
 *
 * Created: 3/8/2020 2:06:02 PM
 *  Author: Hany
 */ 


#ifndef REG_ATMEGA32_H_
#define REG_ATMEGA32_H_


#include "Standard.h"
                  //Atmega32 Registers
/************************************************************/
#define PORTA   *(volatile uint8*)(0x3B)
#define DDRA    *(volatile uint8*)(0x3A)
#define PINA    *(volatile uint8*)(0x39)
#define PORTB   *(volatile uint8*)(0x38)
#define DDRB    *(volatile uint8*)(0x37)
#define PINB    *(volatile uint8*)(0x36)
#define PORTC   *(volatile uint8*)(0x35)
#define DDRC    *(volatile uint8*)(0x34)
#define PINC    *(volatile uint8*)(0x33)
#define PORTD   *(volatile uint8*)(0x32)
#define DDRD    *(volatile uint8*)(0x31)
#define PIND    *(volatile uint8*)(0x30)
/************************************************************/
                  //Timers Registers
#define TCCR0   *(volatile uint8*)(0x53)
#define TCNT0   *(volatile uint8*)(0x52)
#define OCR0    *(volatile uint8*)(0x5C)
#define TIMSK   *(volatile uint8*)(0x59)
#define TIFR    *(volatile uint8*)(0x58)
#define TCCR1A  *(volatile uint8*)(0x4F)
#define TCCR1B	*(volatile uint8*)(0x4E)
#define TCNT1	*(volatile uint16*)(0x4C)
#define OCR1A	*(volatile uint16*)(0x4A)
#define OCR1B	*(volatile uint16*)(0x48)
#define ICR1	*(volatile uint16*)(0x46)
#define TCCR2	*(volatile uint8*)(0x45)
#define TCNT2	*(volatile uint8*)(0x44)
#define OCR2	*(volatile uint8*)(0x43)
#define SREG	*(volatile uint8*)(0x5F)
/************************************************************/
                   //USART Registers

#define UDR	    *(volatile uint8*)(0x2C)
#define UCSRA	*(volatile uint8*)(0x2B)
#define UCSRB	*(volatile uint8*)(0x2A)
#define UCSRC	*(volatile uint8*)(0x40)
#define UBRRH	*(volatile uint8*)(0x40)
#define UBRRL	*(volatile uint8*)(0x29)
/************************************************************/
				  //External interrupts Registers
#define GICR	 *(volatile uint8*)(0x5B)
#define GIFR	 *(volatile uint8*)(0x5A)
#define MCUCR	 *(volatile uint8*)(0x55)
/************************************************************/
                   //SPI Registers
				   
#define SPCR	*(volatile uint8*)(0x2D)
#define SPSR	*(volatile uint8*)(0x2E)
#define SPDR	*(volatile uint8*)(0x2F)
/************************************************************/

#define vect(x) __vector_##x
#define ISR(vect_no, ...)            \
void vect(vect_no) (void) __attribute__ ((signal)); \
void vect(vect_no) (void)
#define GLOBAL_INTERRUPT_ENABLE()   (SET_BIT(SREG,7))
#define GLOBAL_INTERRUPT_DISABLE()  (CLR_BIT(SREG,7))
/************************************************************/
               // Interrupt vectors Table
/************************************************************/
#define VECT_TIMER0_COMP	10
#define VECT_TIMER0_OVF		11
#define VECT_TIMER1_CAPT	6
#define VECT_TIMER1_COMPA	7
#define VECT_TIMER1_COMPB	8
#define VECT_TIMER1_OVF		9
#define VECT_TIMER2_COMP	4
#define VECT_TIMER2_OVF		5
#define SPI_vect_num       12
#define INT2_vect_num		3
#define INT0_vect_num		1
/************************************************************/
            //enum type for pins and ports
typedef enum{P0, P1, P2, P3, P4, P5, P6, P7}PIN_ID;
typedef enum{PORT_A, PORT_B, PORT_C, PORT_D}PORT_ID;
/************************************************************/
                       //MACROS
/************************************************************/
#define INPUT 0
#define OUTPUT 1
#define ENABLE_PULLUP 1
#define DISABLE_PULLUP 0
#define OC0_PIN 3
#define OC2_PIN 7
/************************************************************/
                 // Timers bits macros
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0
/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0
/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0
/************************************************************/
              // USART bits
/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

/* ACSR */
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIC    2
#define ACIS1   1
#define ACIS0   0

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0
/************************************************************/
                 //External interrupts
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define JTD     7
#define ISC2    6
/* bit 5 reserved */
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0
/************************************************************/
              // SPI bits
/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0
/************************************************************/
#endif /* REG_ATMEGA32_H_ */