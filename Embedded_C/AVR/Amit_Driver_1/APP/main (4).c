/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Bunny
 */


#include "../SERV/std_type.h"
#include "../SERV/bit_math.h"
#include "../MCAL/DIO/dio_init.h"
#include "../HAL/LCD/lcd_init.h"
#include "../HAL/KEYPAD/keypad_init.h"
#include "../MCAL/ADC/adc_init.h"
#include "../MCAL/TIMER1/TIMER1_Init.h"
//#include "../HAL/HEXT_INT/HEXT_Init.h"
//#include "../HAL/HTIMER0/HTIMER_Init.h"
//#include "../HAL/HTIMER2/HTIMER2_Init.h"
//#include "../HAL/BCD/bcd_init.h"
#include <util/delay.h>



int main(){
	sint32 x ;
	DIO_vidSetPinDir(PD5,OUTPUT_PIN);
//	LCD_vid4BitInit();
//	ADC_vidInit();
	TIMER1_vidInit();
	TIMER1_vidICRWrite(19999);
	TIMER1_vidStart();
//HTIMER0_vidInit();

//	DIO_vidSetPinDir(PA0,INPUT_PIN);
//	DIO_vidSetPinDir(PA1,INPUT_PIN);
//	DIO_vidSetPinDir(PB3,OUTPUT_PIN);
//	DIO_vidSetPinDir(PB6,OUTPUT_PIN);
//	DIO_vidSetPinDir(PB7,OUTPUT_PIN);
//	DIO_vidSetPinVal(PB6,HIGH_PIN);
//	DIO_vidSetPinVal(PB7,LOW_PIN);
//HTIMER0_vidStart();

	while(1){

		TIMER1_vidOCRAWrite((((float32)90/180)+1)*1000);
		_delay_ms(2000);
		TIMER1_vidOCRAWrite((((float32)180/180)+1)*1000);
		_delay_ms(2000);
		TIMER1_vidOCRAWrite((((float32)0/180)+1)*1000);
		_delay_ms(2000);
		TIMER1_vidOCRAWrite((((float32)45/180)+1)*1000);
		_delay_ms(2000);
//		x = ADC_u16ReadDigitalVal(ADC_CHANNEL2);
//		LCD_vid4BitWriteInt(x);
//
//		HTIMER0_vidWriteCOMPOCR0((uint8)((float32) x * 0.25));
//		_delay_ms(100);
//		LCD_vid4BitClrDisp();
//		for(x = 0 ; x < 255 ; x++ ){
//			HTIMER0_vidWriteCOMPOCR0(x);
//			_delay_ms(50);
//		}


	}
	return 0;
}

