/*****
- HEADERGUARD:
*****/
#ifndef ADC_REG_H
#define ADC_REG_H



#define ADCH 	*((volatile uint8*)0x25) 		// ADC High Register
#define ADCL 	*((volatile uint8*)0x24) 		// ADC Low Register


#define ADMUX 	*((volatile uint8*)0x27) 	// ADC Multiplexer Register
#define ADMUX_REFS1     7
#define ADMUX_REFS0     7
#define ADMUX_ADLAR     5

#define ADCSRA 	*((volatile uint8*)0x26) 	// ADC Control And Status Register
#define ADCSRA_ADEN     7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2     2
#define ADCSRA_ADPS1     1
#define ADCSRA_ADPS0     0

#endif