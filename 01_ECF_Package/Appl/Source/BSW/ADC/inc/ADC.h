/*
 * ADC.h
 *
 *  Created on: Sep 8, 2018
 *      Author: hp
 */


#ifndef ADC_H_
#define ADC_H_

#define ADMUX_Reg 	*((volatile uint8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile uint8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile uint8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile uint8*)0x24) 		// ADC Low Register


extern void ADC_Init (void); // ADC Initialization And Enable
extern uint16 ADC_Read (uint8); // Read From The ADC Channel


#endif /* ADC_INITIALIZATION_H_ */



