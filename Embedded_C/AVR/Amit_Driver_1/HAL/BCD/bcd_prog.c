/*
 * bcd_prog.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "bcd_conf.h"
#include "bcd_init.h"

extern uint8 Pin_arr[4];


void BCD_vidInit(){
	DIO_vidSetPinSDir(Pin_arr,4,OUTPUT_PIN);
	DIO_vidSetPinDir(EN_PIN1,OUTPUT_PIN);
	DIO_vidSetPinDir(EN_PIN2,OUTPUT_PIN);
}

void BCD_vidDisply(uint8 Copyu8Num){
	for(uint8 j = 0; j < 4; j++){
		DIO_vidSetPinVal(Pin_arr[j],GET_BIT(Copyu8Num,j));
	}
}




void BCD_vidEnable(uint8 Copyu8Sel){
	switch (Copyu8Sel){
	case EN1:DIO_vidSetPinVal(EN_PIN1,HIGH_PIN);
	         DIO_vidSetPinVal(EN_PIN2,LOW_PIN);break;
	case EN2:DIO_vidSetPinVal(EN_PIN1,LOW_PIN);
	         DIO_vidSetPinVal(EN_PIN2,HIGH_PIN);break;
	}
}



//void BCD_vidEnDis(uint8 Copyu8Sel,uint8 Copyu8Stat){
//	switch(Copyu8Stat){
//	case ENABLE:DIO_vidSetPinVal(Copyu8Sel,HIGH_PIN);break;
//	case DISABLE:DIO_vidSetPinVal(Copyu8Sel,LOW_PIN);break;
//	}
//
//}
