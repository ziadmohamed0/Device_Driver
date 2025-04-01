/*
 * adc_init.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Bunny
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_



//#define ADC_CHANNEL1       (uint8)0x00
//#define ADC_CHANNEL2       (uint8)0x01
//#define ADC_CHANNEL3       (uint8)0x02
//#define ADC_CHANNEL4       (uint8)0x03
//#define ADC_CHANNEL5       (uint8)0x04
//#define ADC_CHANNEL6       (uint8)0x05
//#define ADC_CHANNEL7       (uint8)0x06
//#define ADC_CHANNEL8       (uint8)0x07


typedef enum{
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7,
	ADC_CHANNEL8
}ADC_CHANNEL;




void (*ADC_CAB_INT)(void);


void ADC_vidInit();
uint16 ADC_u16ReadDigitalVal(ADC_CHANNEL ChannelCopy);


void ADC_vidInterruptEnable();
void ADC_vidInterruptDisable();
void ADC_vidClrFlag();


void ADC_vidEnable();
void ADC_vidDisable();


#endif /* MCAL_ADC_ADC_INIT_H_ */
