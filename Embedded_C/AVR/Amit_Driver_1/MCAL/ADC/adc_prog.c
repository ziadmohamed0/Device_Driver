/*
 * adc_prog.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "adc_privet.h"
#include "adc_conf.h"
#include "adc_init.h"

ISR(__vector_16)
{
	ADC_CAB_INT();
}


void ADC_vidInit(){
#if ADC_VOLT == ADC_AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLT == ADC_AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLT == ADC_INTERNAL
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif
//	CLEAR(ADMUX,ADLAR);   // RIGHT
	SET_BIT(ADCSRA,ADCSRA_ADEN);  // Enable Pin
	ADCSRA |= ADC_PRESCALER; //Prescaler
}

uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy){
	uint16 Res=0;
	ADMUX &= ADC_CLEAR_MASK;
	ADMUX |= ChannelCopy;
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while((GET_BIT(ADCSRA,ADCSRA_ADSC)));
	Res = ADCL;
	Res |= (ADCH << 8);
	return Res;
}


void ADC_vidEnable(){
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
void ADC_vidDisable(){
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_vidInterruptEnable(){
	SET_BIT(SREG,GIE);
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}
void ADC_vidClrFlag(){
	SET_BIT(ADCSRA,ADCSRA_ADIF);
}
void ADC_vidInterruptDisable(){
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}


