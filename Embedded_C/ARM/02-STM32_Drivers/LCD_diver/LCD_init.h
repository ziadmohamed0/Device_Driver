/*
 * LCD_init.h
 *
 *  Created on: Nov 1, 2024
 *      Author: s
 */

#ifndef LCD_INIT_H_
#define LCD_INIT_H_

/* -------------------- Include Start -------------------- */
#include "main.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
    /* @GroupMacros : LCD Commands */
#define _LCD_CLEAR_DIS                              0x01
#define _LCD_RETURN_HOME                            0x02
#define _LCD_ENTERY_INC                             0x06
#define _LCD_ENTERY_DEC                             0x04
#define _LCD_DISPLAY_ON                             0x0C
#define _LCD_DISPLAY_OFF                            0x08
#define _LCD_CURSOR_ON                              0x0E
#define _LCD_CURSOR_BLINK                           0x0F
#define _LCD_SHIFT_RIGHT                            0x1C
#define _LCD_SHIFT_LEFT                             0x18
#define _LCD_8_BIT_MODE                             0x38
#define _LCD_4_BIT_MODE                             0x28
#define _LCD_CG_RAM_SET                             0x40
#define _LCD_DD_RAM_SET                             0x80

    /* @GroupMacros : Raws Macros */
#define RAW1                                        1
#define RAW2                                        2
#define RAW3                                        3
#define RAW4                                        4

#define High										1
#define Low											0
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef struct {
	uint8_t LCD_rs;
	uint8_t LCD_en;
	uint8_t LCD_D[4];
}LCD_4Bit_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void HALL_LCD_4bit_init(void);
void HALL_LCD_4bit_sendCMD(uint8_t copyCMD);
void HALL_LCD_4bit_sendChar(uint8_t copyData);
void HALL_LCD_4bit_sendCharPos(uint8_t copyRow, uint8_t copyColumn, uint8_t copyData);
void HALL_LCD_4bit_sendSTR(uint8_t *copyData);
void HALL_LCD_4bit_sendSTRPos(uint8_t copyRow, uint8_t copyColumn, uint8_t *copyData);
void HALL_LCD_4bit_goto(uint8_t copyRow, uint8_t copyColumn);
void HALL_LCD_4bit_sendInt(uint32_t u32NumCopy);
/* -------------------- API End -------------------- */

#endif /* LCD_INIT_H_ */
