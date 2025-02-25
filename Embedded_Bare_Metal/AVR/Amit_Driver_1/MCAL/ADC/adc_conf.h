/*
 * adc_conf.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#ifndef MCAL_ADC_ADC_CONF_H_
#define MCAL_ADC_ADC_CONF_H_


#define ADC_AREF       0
#define ADC_AVCC       1
#define ADC_INTERNAL   2
#define ADC_VOLT   ADC_AVCC



#define ADC_DIVISION_FACTOR_2        (uint8)0x01
#define ADC_DIVISION_FACTOR_4        (uint8)0x02
#define ADC_DIVISION_FACTOR_8        (uint8)0x03
#define ADC_DIVISION_FACTOR_16       (uint8)0x04
#define ADC_DIVISION_FACTOR_32       (uint8)0x05
#define ADC_DIVISION_FACTOR_64       (uint8)0x06
#define ADC_DIVISION_FACTOR_128      (uint8)0x07

#define ADC_PRESCALER   ADC_DIVISION_FACTOR_64


/*---------CHANNEL CLEAR MASK-------*/

#define ADC_CLEAR_MASK  (uint8)0xE0
#endif /* MCAL_ADC_ADC_CONF_H_ */
