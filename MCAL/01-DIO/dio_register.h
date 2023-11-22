/**************************************************************************/
/************************DIO-Register Interfacing File**********************/
/**************************************************************************/

/******HeaderGuard******/
#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

/***VolatileModifier**/
/* Used to stop the Compiler Optimization, When the Compliler creates a copy of the register defined, and use it in the While loop, to consume the timing. So the register value will not be checked in every while loop.
*/

/*****RegistersDeclarations*****/ 
#define DDRA_REG *((volatile uint8 *)0x3A) 
#define PORTA_REG *((volatile uint8 *)0x3B)
#define PINA_REG *((volatile uint8 *)0x39)

#define DDRB_REG  *((volatile uint8 *)0x37)
#define PORTB_REG *((volatile uint8 *)0x38)	
#define PINB_REG  *((volatile uint8 *)0x36)

#define DDRC_REG  *((volatile uint8 *)0x34)
#define PORTC_REG *((volatile uint8 *)0x35)
#define PINC_REG  *((volatile uint8 *)0x33)

#define DDRD_REG  *((volatile uint8 *)0x31)
#define PORTD_REG *((volatile uint8 *)0x32)
#define PIND_REG  *((volatile uint8 *)0x30)

#endif 