/*
 * dio_register.h
 *
 *  Created on: Dec 5, 2022
 *      Author: MohamedAyman
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

/*******************
 * DIO-REGISTERS
*******************/
#define DDRA *((volatile uint8 *)0x3A)
#define PINA *((volatile uint8 *)0x39)
#define PORTA *((volatile uint8 *)0x3B)

#define DDRB *((volatile uint8 *)0x37)
#define PINB *((volatile uint8 *)0x36)
#define PORTB *((volatile uint8 *)0x38)

#define DDRC *((volatile uint8 *)0x34)
#define PINC *((volatile uint8 *)0x33)
#define PORTC *((volatile uint8 *)0x35)

#define DDRD *((volatile uint8*)0x31)
#define PORTD *((volatile uint8*)0x32)
#define PIND *((volatile uint8*) 0x30)
/*******************/

#endif /* MCAL_DIO_DIO_REGISTER_H_ */
