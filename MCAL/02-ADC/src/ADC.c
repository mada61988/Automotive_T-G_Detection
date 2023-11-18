/*
 * ADC.c
 *
 *  Created on: Sep 8, 2018
 *      Author: hp
 */
#include <avr/io.h>
#include "Platform_Types.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include "RTE_ADC.h"

void ADC_Init (void)
{
	// ADC Enable
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);


	// Referance Voltage as AVCC with external capacitor
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);

	// ADC Use left adjust 
	SET_BIT(ADMUX,ADMUX_ADLAR);
}

void ADC_u8ReadChannel (uint8 u8Channel)
{
	//Clear the MUX bits in ADMUX Reg
	ADMUX &= 0b11100000;

	//Set the required chanel in ADMUX
	ADMUC |= u8Channel;

	//Start Conversion in Single conversion mode
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	// Polling(busy waiting) until conversion completed
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	// clear conversion clear flag
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	//return ADCH;

	//Send result to App through RTE 
	Rte_Write_PpSrADCSendTempResult_P(ADCH);
}
