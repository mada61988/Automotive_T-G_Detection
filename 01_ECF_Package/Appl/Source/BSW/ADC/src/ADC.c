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


void ADC_Init (void)
{
	// ADC Enable
	SET_BIT(ADCSRA_Reg,7);

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA_Reg,2);
	SET_BIT(ADCSRA_Reg,1);
	SET_BIT(ADCSRA_Reg,0);


	// Referance Voltage as AVCC with external capacitor
	CLR_BIT(ADMUX_Reg,7);
	SET_BIT(ADMUX_Reg,6);

	// ADC Data Rgith Adjustment
	CLR_BIT(ADMUX_Reg,5);
}

uint16 ADC_Read (uint8 channel)
{
	// ADC Channel Selection
	channel &= 0x07;
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= channel;

	// Start Single Convertion
	SET_BIT(ADCSRA_Reg,6);

	//wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));

	//ADC Flag Clear
	SET_BIT(ADCSRA_Reg,4);

	return ADC;
}
