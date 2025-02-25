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
#include "../HAL/HEXT_INT/HEXT_Init.h"
#include "../HAL/HTIMER0/HTIMER_Init.h"
//#include "../HAL/BCD/bcd_init.h"
#include <util/delay.h>


void fun(void);
volatile uint16 s = 0;
volatile uint8 x = 'A';
int main(){
	LCD_vid4BitInit();
	DIO_vidSetPinDir(11,OUTPUT_PIN);

	HTIMER0_vidInit();
//	HTIMER0_vidOVRInterruptEnable();
//	HTIMER0_OVF_INT = fun;
	HTIMER0_vidWriteCOMPOCR0(200);
	HTIMER0_vidStart();
	while(1){
//		if(keypad_u8Stat(&i)){
//			LCD_vid4BitWriteCmd(CLEAR_DIS);
//			LCD_vid4BitWriteChar(i);
//		}
//		LCD_vid4BitWriteChar('f');
	}
	return 0;
}


//void fun(void){
////	s++;
////	if(s== 1954){
////		LCD_vid4BitWriteCmd(CLEAR_DIS);
////		LCD_vid4BitWriteChar(x++);
////		s = 0;
////		HTIMER0_vidWriteOVRTCNT0(224);
////	}
//
//}
