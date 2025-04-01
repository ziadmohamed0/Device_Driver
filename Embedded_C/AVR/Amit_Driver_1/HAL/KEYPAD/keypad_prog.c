/*
 * keypad_prog.c
 *
 *  Created on: Sep 16, 2023
 *      Author: hp
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "keypad_confg.h"
#include "keypad_init.h"
#include "util/delay.h"



extern uint8 Pattern[NO_ROW][NO_COL];
extern uint8 Row_Pin[NO_ROW];
extern uint8 Col_Pin[NO_COL];

void keypad_vidInit(){
	DIO_vidSetPinSDir(Row_Pin,NO_ROW,INPUT_PIN);
	DIO_vidSetPinSDir(Col_Pin,NO_COL,OUTPUT_PIN);
	DIO_vidSetPinSVal(Row_Pin,NO_ROW,HIGH_PIN);
	DIO_vidSetPinSVal(Col_Pin,NO_COL,HIGH_PIN);
}

uint8 keypad_u8Stat(uint8 *ptr){
	uint8 i,j;
	uint8 flag=0;
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(Col_Pin[i],LOW_PIN);
		for(j=0;j<4;j++){
			if(DIO_u8GetPinVal(Row_Pin[j]) == 0){

				*ptr = Pattern[j][i];
				flag=1;
//				_delay_ms(20);
				while(DIO_u8GetPinVal(Row_Pin[j])==0);
//				if(DIO_u8GetPinVal(Row_Pin[j]) == 0){
//					*ptr = Pattern[j][i];
//				}
				_delay_ms(20);
				DIO_vidSetPinVal(Col_Pin[i],HIGH_PIN);
				return flag;
			}
		}
		DIO_vidSetPinVal(Col_Pin[i],HIGH_PIN);
	}
	return flag;
}
