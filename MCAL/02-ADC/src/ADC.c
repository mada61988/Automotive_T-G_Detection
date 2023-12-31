/*
 * ADC.c
 *
 *  Created on: Sep 8, 2018
 *      Author: hp
 */
#include <avr/io.h>
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "ADC_Register.h"
#include "ADC.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"

#include "dio_register.h"
#include <util/delay.h>
#include <avr/interrupt.h>




void ADC_Init (void)
{
	// ADC Enable
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	SET_BIT(ADCSRA,ADCSRA_ADSC);
	// Referance Voltage as AVCC with external capacitor
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	// ADC Use Left adjust 
	SET_BIT(ADMUX,ADMUX_ADLAR);
}

uint16 ADC_u8ReadChannel (uint8  u8Channel)
{
	
	//Clear the MUX bits in ADMUX Reg
	ADMUX &= 0b11100000;

	//Set the required chanel in ADMUX
	ADMUX |= u8Channel;

	//Start Conversion in Single conversion mode
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	// Polling(busy waiting) until conversion completed
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	// clear conversion clear flag
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	//uint16 res = ((((uint16)ADCL_Reg & 0xC0) >> 6) & (uint16)3) & (((uint16)ADCH_Reg)<< 2) ;
	//uint16 res = (uint16)((ADCL_Reg >> (uint8)6) & (uint8)3) & (uint16)(ADCH_Reg << (uint8)2);
	return ADCH_Reg;

	
	
}



 
