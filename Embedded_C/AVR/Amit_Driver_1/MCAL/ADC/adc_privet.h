/*
 * adc_privet.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#ifndef MCAL_ADC_ADC_PRIVET_H_
#define MCAL_ADC_ADC_PRIVET_H_



#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		    \
	void vector(void)





#define ADMUX    *((volatile uint8 *)0x27)
#define ADCSRA   *((volatile uint8 *)0x26)
#define ADCH     *((volatile uint8 *)0x25)
#define ADCL     *((volatile uint8 *)0x24)
#define SFIOR    *((volatile uint8 *)0x50)
#define SREG     *((volatile uint8 *)0x5F)

/*-------ADMUX_REG--------*/
#define ADMUX_ADLAR   (uint8)5
#define ADMUX_REFS0   (uint8)6
#define ADMUX_REFS1   (uint8)7



/*------ADCSRA-------*/
#define ADCSRA_ADEN     (uint8)7
#define ADCSRA_ADSC     (uint8)6
#define ADCSRA_ADATE    (uint8)5
#define ADCSRA_ADIF     (uint8)4
#define ADCSRA_ADIE     (uint8)3
#define ADCSRA_ADPS2    (uint8)2
#define ADCSRA_ADPS1    (uint8)1
#define ADCSRA_ADPS0    (uint8)0


/*-------SREG-------*/
#define GIE   7

#endif /* MCAL_ADC_ADC_PRIVET_H_ */
