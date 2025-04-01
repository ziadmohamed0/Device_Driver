/*
 * LCD_prog.c
 *
 *  Created on: Nov 1, 2024
 *      Author: s
 */

#include "../Drivers/LCD_init.h"
#include <string.h>
#include <stdio.h>

static void LCD_send4Bits(uint8_t copyCMD);
static void LCD_sendEnableSignal4Bits();


void HALL_LCD_4bit_init(void) {
    HAL_Delay(1);
    HALL_LCD_4bit_sendCMD(_LCD_8_BIT_MODE);
    HAL_Delay(1);
    HALL_LCD_4bit_sendCMD(_LCD_8_BIT_MODE);
    HAL_Delay(20);
    HALL_LCD_4bit_sendCMD(_LCD_8_BIT_MODE);
    HALL_LCD_4bit_sendCMD(_LCD_CLEAR_DIS);
    HALL_LCD_4bit_sendCMD(_LCD_RETURN_HOME);
    HALL_LCD_4bit_sendCMD(_LCD_ENTERY_INC);
    HALL_LCD_4bit_sendCMD(_LCD_DISPLAY_ON);
    HALL_LCD_4bit_sendCMD(_LCD_4_BIT_MODE);
    HALL_LCD_4bit_sendCMD(0x80);
}

void HALL_LCD_4bit_sendCMD(uint8_t copyCMD) {
   HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, Low);
   LCD_send4Bits(copyCMD >> 4);
   LCD_sendEnableSignal4Bits();
   LCD_send4Bits(copyCMD);
   LCD_sendEnableSignal4Bits();
}

void HALL_LCD_4bit_goto(uint8_t copyRow, uint8_t copyColumn) {
   switch (copyRow) {
   	   case RAW1 : HALL_LCD_4bit_sendCMD(0x80 + copyColumn); break;
   	   case RAW2 : HALL_LCD_4bit_sendCMD(0xc0 + copyColumn); break;
   	   case RAW3 : HALL_LCD_4bit_sendCMD(0x94 + copyColumn); break;
   	   case RAW4 : HALL_LCD_4bit_sendCMD(0xd4 + copyColumn); break;
   }
}

void HALL_LCD_4bit_sendChar(uint8_t copyData) {
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, High);
   LCD_send4Bits(copyData >> 4);
   LCD_sendEnableSignal4Bits();
   LCD_send4Bits(copyData);
   LCD_sendEnableSignal4Bits();
}

void HALL_LCD_4bit_sendCharPos(uint8_t copyRow, uint8_t copyColumn, uint8_t copyData) {
   HALL_LCD_4bit_goto(copyRow, copyColumn);
   HALL_LCD_4bit_sendChar(copyData);
}

void HALL_LCD_4bit_sendSTR(uint8_t *copyData) {
   while (*copyData) {
	   HALL_LCD_4bit_sendChar(*copyData++);
   }
}

void HALL_LCD_4bit_sendSTRPos(uint8_t copyRow, uint8_t copyColumn, uint8_t *copyData) {
	HALL_LCD_4bit_goto(copyRow, copyColumn);
    while(*copyData) {
    	HALL_LCD_4bit_sendChar(*copyData++);
    }
}

void HALL_LCD_4bit_sendInt(uint32_t u32NumCopy) {
	uint8_t arr[11]={0};
	uint8_t i=0;
	if(u32NumCopy < 0){
		HALL_LCD_4bit_sendChar('-');
		u32NumCopy *= -1;
	}

	while(u32NumCopy){
		arr[i]=(uint8_t)(u32NumCopy%10);
		u32NumCopy /=10;
		i++;
	}

	for(i=i-1;i>=0;i--){
		HALL_LCD_4bit_sendChar((arr[i]+'0'));
	}
}

static void LCD_send4Bits(uint8_t copyData) {

	uint8_t val1 = ((copyData >> 0) & (uint8_t)0x01);
	uint8_t val2 = ((copyData >> 1) & (uint8_t)0x01);
	uint8_t val3 = ((copyData >> 2) & (uint8_t)0x01);
	uint8_t val4 = ((copyData >> 3) & (uint8_t)0x01);

    HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, val1);
    HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, val2);
    HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, val3);
    HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, val4);
}
static void LCD_sendEnableSignal4Bits() {
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, High);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, Low);
}
