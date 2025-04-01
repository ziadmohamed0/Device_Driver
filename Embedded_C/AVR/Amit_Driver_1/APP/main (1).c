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
//#include "../HAL/BCD/bcd_init.h"
#include <util/delay.h>


void fun(void);
volatile uint8 s = 0;

int main(){
//uint8 i;
	LCD_vid4BitInit();
	keypad_vidInit();
	HEXT_vidInit(INT0,RISSING);
	ISR_FUN_INT0=fun;

	while(1){
//		if(keypad_u8Stat(&i)){
//			LCD_vid4BitWriteCmd(CLEAR_DIS);
//			LCD_vid4BitWriteChar(i);
//		}
		LCD_vid4BitWriteChar('f');
	}
	return 0;
}


void fun(void){
	LCD_vid4BitWriteCmd(CLEAR_DIS);
	LCD_vid4BitGoto(0,5);

//	s++;
}
