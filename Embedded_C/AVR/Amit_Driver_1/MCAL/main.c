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
#include "../MCAL/SPI/spi_init.h"
#include <util/delay.h>

int main(){
	LCD_vid4BitInit();
	DIO_vidSetPinDir(PB5,INPUT_PIN);
	DIO_vidSetPinDir(PB6,OUTPUT_PIN);
	DIO_vidSetPinDir(PB7,INPUT_PIN);
	SPI_vidInit();
	while(1){
		LCD_vid4BitWriteInt(SPI_u8Slave(0));
		_delay_ms(300);
		LCD_vid4BitClrDisp();

	}
	return 0;
}

