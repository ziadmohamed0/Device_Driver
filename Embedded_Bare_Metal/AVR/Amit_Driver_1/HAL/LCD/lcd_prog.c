/*
 * lcd_prog.c
 *
 *  Created on: Sep 15, 2023
 *      Author: hp
 */
#include "../../SERV/std_type.h"
#include "../../Serv/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "lcd_conf.h"
#include "lcd_init.h"
#include "util/delay.h"
//#include <stdio.h>


#if LCD_MODE  == LCD_8_BIT_MODE

void LCD_vidInit(){
	DIO_vidSetPortDir(LCD_PORT,OUTPUT_PORT);
	DIO_vidSetPinDir(RS,OUTPUT_PIN);
	DIO_vidSetPinDir(E,OUTPUT_PIN);
	_delay_ms(40);
	LCD_vidWriteCmd(BIT_8_MODE);
	_delay_ms(1);
	LCD_vidWriteCmd(DISPLAY_ON);
	_delay_ms(1);
	LCD_vidWriteCmd(CLEAR_DIS);
	_delay_ms(2);
	LCD_vidWriteCmd(ENTRY_MODE_INC);
}


void LCD_vidWriteCmd(uint8 u8CmdCopy){
	DIO_vidSetPinVal(RS,LOW_PIN);
	DIO_vidSetPinVal(E,HIGH_PIN);
	DIO_vidSetPortVal(LCD_PORT,u8CmdCopy);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vidWriteChar(uint8 u8CharCopy){
	DIO_vidSetPinVal(RS,HIGH_PIN);
	DIO_vidSetPinVal(E,HIGH_PIN);
	DIO_vidSetPortVal(LCD_PORT,u8CharCopy);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vidClrDisp(){
	DIO_vidSetPinVal(RS,LOW_PIN);
	DIO_vidSetPinVal(E,HIGH_PIN);
	DIO_vidSetPortVal(LCD_PORT,CLEAR_DIS);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vidShiftLeft(){
	DIO_vidSetPinVal(RS,LOW_PIN);
	DIO_vidSetPortVal(LCD_PORT,SHIFT_DIS_L);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vidShiftRight(){
	DIO_vidSetPinVal(RS,LOW_PIN);
	DIO_vidSetPortVal(LCD_PORT,SHIFT_DIS_R);
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vidWriteStr(uint8 *u8StrCopy){
	DIO_vidSetPinVal(RS,HIGH_PIN);
	while(((*u8StrCopy) != '\0')){
		DIO_vidSetPinVal(E,HIGH_PIN);
		DIO_vidSetPortVal(LCD_PORT,(*(u8StrCopy++)));
		_delay_ms(1);
		DIO_vidSetPinVal(E,LOW_PIN);
	}
}

void LCD_vidWriteInt(sint32 u32NumCopy){
	uint8 arr[11]={0};
	sint8 i=0;
	if(u32NumCopy < 0){
		LCD_vidWriteChar('-');
		u32NumCopy *= -1;
	}

	while(u32NumCopy){
		arr[i]=(uint8)(u32NumCopy%10);
		u32NumCopy /=10;
		i++;
	}

	for(i=i-1;i>=0;i--){
		LCD_vidWriteChar((arr[i]+'0'));
	}


}

void LCD_vidGoto(uint8 u8RowCopy,uint8 u8ColCopy){
	uint8 add=0;
	switch(u8RowCopy){
	case 0 : add=u8ColCopy;  break;
	case 1 : add=u8ColCopy+0x40;  break;
	}
	LCD_vidWriteCmd((add+AD_DDRAM));
}


void LCD_vidWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc){
	LCD_vidWriteCmd((AD_CGRAM + ((u8Loc-1)*8)));
	uint8 i=0;
	for(i=0;i<8;i++){
		LCD_vidWriteChar(u8Pattern[i]);
	}
}




#elif LCD_MODE  == LCD_4_BIT_MODE

/********************* D4 D5 D6 D7 *************/
uint8 LCD_Data_Pin[4]={4,5,6,7};
uint8 i=0;

void LCD_vid4BitInit(){
	DIO_vidSetPinSDir(LCD_Data_Pin,4,OUTPUT_PIN);

	DIO_vidSetPinDir(10,OUTPUT_PIN);
	DIO_vidSetPinVal(10,LOW_PIN);

	DIO_vidSetPinDir(RS,OUTPUT_PIN);
	DIO_vidSetPinDir(E,OUTPUT_PIN);
	_delay_ms(40);
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],(GET_BIT(BIT_4_MODE,(4+i))));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	LCD_vid4BitWriteCmd(BIT_4_MODE);
	_delay_ms(1);
	LCD_vid4BitWriteCmd(DISPLAY_ON);
	_delay_ms(1);
	LCD_vid4BitWriteCmd(CLEAR_DIS);
	_delay_ms(2);
	LCD_vid4BitWriteCmd(ENTRY_MODE_INC);

}
void LCD_vid4BitWriteCmd(uint8 u8CmdCopy){
	uint8 i=0;
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],(GET_BIT(u8CmdCopy,(4+i))));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],(GET_BIT(u8CmdCopy,(i))));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vid4BitWriteChar(uint8 u8CharCopy){
	uint8 i=0;
	DIO_vidSetPinVal(RS,HIGH_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((u8CharCopy >> (i+4))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((u8CharCopy >> (i))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vid4BitClrDisp(){
	uint8 i=0;
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((CLEAR_DIS >> (i+4))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((CLEAR_DIS >> (i))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vid4BitShiftLeft(){
	uint8 i=0;
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((SHIFT_DIS_L >> (i+4))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((SHIFT_DIS_L >> (i))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vid4BitShiftRight(){
	uint8 i=0;
	DIO_vidSetPinVal(RS,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((SHIFT_DIS_R >> (i+4))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
	for(i=0;i<4;i++){
		DIO_vidSetPinVal(LCD_Data_Pin[i],((SHIFT_DIS_R >> (i))& 0x01));
	}
	DIO_vidSetPinVal(E,HIGH_PIN);
	_delay_ms(1);
	DIO_vidSetPinVal(E,LOW_PIN);
}
void LCD_vid4BitWriteInt(sint32 u32NumCopy){
	uint8 arr[11]={0};
	sint8 i=0;
	if(u32NumCopy <0){
		LCD_vid4BitWriteChar('-');
		u32NumCopy *= -1;
	}

	while(u32NumCopy){
		arr[i]=(uint8)(u32NumCopy%10);
		u32NumCopy /=10;
		i++;
	}

	for(i=i-1;i>=0;i--){
		LCD_vid4BitWriteChar((arr[i]+'0'));
	}
}
void LCD_vid4BitWriteStr(uint8 *u8StrCopy){
	while(((*u8StrCopy) != '\0')){
		LCD_vid4BitWriteChar((*(u8StrCopy++)));
	}
}
void LCD_vid4BitGoto(uint8 u8RowCopy,uint8 u8ColCopy){
	uint8 add=0;
	switch(u8RowCopy){
	case 0 : add=u8ColCopy;  break;
	case 1 : add=u8ColCopy+0x40;  break;
	}
	LCD_vid4BitWriteCmd((add+AD_DDRAM));
}
void LCD_vid4BitWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc){
	LCD_vid4BitWriteCmd((AD_CGRAM + ((u8Loc-1)*8)));
	uint8 i=0;
	for(i=0;i<8;i++){
		LCD_vid4BitWriteChar(u8Pattern[i]);
	}
}

#endif
