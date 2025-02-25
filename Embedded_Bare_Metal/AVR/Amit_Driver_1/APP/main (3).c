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
#include "../HAL/HTIMER2/HTIMER2_Init.h"
//#include "../HAL/BCD/bcd_init.h"
#include <util/delay.h>


void fun(void);
//volatile uint16 s = 0;
volatile uint8 x = 0;
int main(){
	LCD_vid4BitInit();
	LCD_vid4BitWriteChar('0');
	LCD_vid4BitWriteChar('0');
	LCD_vid4BitGoto(0,2);
	LCD_vid4BitWriteChar('S');
//	DIO_vidSetPinDir(11,OUTPUT_PIN);
	HTIMER2_vidInit();
	HTIMER2_vidOVRInterruptEnable();
	HTIMER2_OVF_INT = fun;

	HTIMER2_vidStart();
	while(1){
		if(x == 61){
			LCD_vid4BitGoto(0,0);
			LCD_vid4BitWriteStr("  ");
			x = 0;
		}
	}
	return 0;
}


void fun(void){
	LCD_vid4BitGoto(0,0);
	LCD_vid4BitWriteInt(x++);
}
