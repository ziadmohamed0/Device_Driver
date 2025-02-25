/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Bunny
 */


#include "../SERV/std_type.h"
#include "../SERV/bit_math.h"
#include "../MCAL/DIO/dio_init.h"
#include "../MCAL/TIMER1/TIMER1_Init.h"
#include "../HAL/LCD/lcd_init.h"
#include "../HAL/KEYPAD/keypad_init.h"
#include "../HAL/HTIMER2/HTIMER2_Init.h"
#include <util/delay.h>

void Timer2_INT();
volatile uint8 LCD_On = 0,Go=0;
int main(){
	DIO_vidSetPinDir(PD5,OUTPUT_PIN);
	DIO_vidSetPinDir(PC6,INPUT_PIN);
	DIO_vidSetPinDir(PC7,INPUT_PIN);
	uint8 Keypad_Val = 0,keypad_flag=0,Pass_cou = 0;
	uint8 LCD_Wel[] = "Welcome in Home";
	uint8 LCD_pas[] = "Enter password : ";
	uint8 LCD_Admin[] = "Enter Admin Pass : ";
	uint8 LCD_Wrong[] = "Wrong password ";
	uint32 def_pass = 9854;
	uint32 Admin_pass= 5555;
	uint32 input_pass  = 0;
	LCD_vid4BitInit();
	keypad_vidInit();
	TIMER1_vidInit();
	HTIMER2_vidInit();
	HTIMER2_OVF_INT = Timer2_INT;
	TIMER1_vidICRWrite(19999);
	TIMER1_vidOCRAWrite(2000);
	while(1){
		keypad_flag = keypad_u8Stat(&Keypad_Val);
		if(Pass_cou < 3){
			if(Keypad_Val == 'N' && keypad_flag == 1){
				LCD_vid4BitGoto(0,1);
				LCD_vid4BitWriteStr(LCD_Wel);
				_delay_ms(300);
				LCD_vid4BitWriteCmd(DISPLAY_OFF);
				_delay_ms(300);
				LCD_vid4BitWriteCmd(DISPLAY_ON);
				_delay_ms(300);
				LCD_vid4BitWriteCmd(DISPLAY_OFF);
				_delay_ms(300);
				LCD_vid4BitWriteCmd(DISPLAY_ON);
				_delay_ms(1000);
				LCD_vid4BitClrDisp();
				LCD_vid4BitWriteStr(LCD_pas);
				LCD_On = 1;
			}else if((Keypad_Val != 'N') && (Keypad_Val != '=') && (keypad_flag == 1) && (Go < 4) && (LCD_On == 1) ){
				input_pass = (input_pass * 10) + (Keypad_Val - '0');
				LCD_vid4BitGoto(1,Go);
				LCD_vid4BitWriteChar(Keypad_Val);
				_delay_ms(300);
				LCD_vid4BitGoto(1,Go);
				LCD_vid4BitWriteChar('*');
				Go++;
			}else if((Keypad_Val == '=') && (keypad_flag == 1)&& (LCD_On == 1)){
				if(input_pass == def_pass){
					LCD_vid4BitClrDisp();
					LCD_vid4BitWriteStr("Hi");
					input_pass = 0;
					TIMER1_vidStart();
					HTIMER2_vidSwitchAsy();
				}else{
					LCD_vid4BitClrDisp();
					Pass_cou++;
					LCD_vid4BitWriteStr(LCD_Wrong);
					LCD_vid4BitWriteInt(Pass_cou);
					input_pass = 0;
					Go = 0;
					if(Pass_cou == 3){
						LCD_vid4BitClrDisp();
						LCD_vid4BitGoto(0,0);
						LCD_vid4BitWriteStr(LCD_Admin);
					}

				}
			}
		}else{
			if((Keypad_Val != 'N') && (Keypad_Val != '=') && (keypad_flag == 1) && (Go < 4) && (LCD_On == 1) ){
				input_pass = (input_pass * 10) + (Keypad_Val - '0');
				LCD_vid4BitGoto(1,Go);
				LCD_vid4BitWriteChar(Keypad_Val);
				_delay_ms(300);
				LCD_vid4BitGoto(1,Go);
				LCD_vid4BitWriteChar('*');
				Go++;
			}else if((Keypad_Val == '=') && (keypad_flag == 1)&& (LCD_On == 1)){
				if(input_pass == Admin_pass){
					LCD_vid4BitClrDisp();
					LCD_vid4BitWriteStr(LCD_pas);
					input_pass = 0;
					Go = 0;
					Pass_cou = 0;
				}else{
					LCD_vid4BitClrDisp();
					LCD_vid4BitWriteStr(LCD_Wrong);
					_delay_ms(500);
					LCD_vid4BitClrDisp();
					LCD_vid4BitWriteStr(LCD_Admin);
					input_pass = 0;
					Go = 0;
				}
			}

		}

	}
	return 0;
}
void Timer2_INT(){
	TIMER1_vidOCRAWrite(1000);
	LCD_vid4BitClrDisp();
	LCD_On = 0;
	Go=0;
    HTIMER2_vidSwitchNormal();

}
