/* 
 * File:   Hall_LCD_init.h
 * Author: s
 *
 * Created on 20 ??????, 2024, 10:18 ?
 */

#ifndef HALL_LCD_INIT_H
#define	HALL_LCD_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
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
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef struct {
    Pin_cfg_t LCD_rs;
    Pin_cfg_t LCD_en;
    Pin_cfg_t LCD_D[4];
}LCD_4Bit_t;

typedef struct {
    Pin_cfg_t LCD_rs;
    Pin_cfg_t LCD_en;
    Pin_cfg_t LCD_D[8];
}LCD_8Bit_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_LCD_4bit_init(const LCD_4Bit_t* copyLCD);
Std_Return HALL_LCD_4bit_sendCMD(const LCD_4Bit_t* copyLCD, uint8_t copyCMD);
Std_Return HALL_LCD_4bit_sendChar(const LCD_4Bit_t* copyLCD, uint8_t copyData);
Std_Return HALL_LCD_4bit_sendCharPos(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t copyData);
Std_Return HALL_LCD_4bit_sendSTR(const LCD_4Bit_t* copyLCD, uint8_t *copyData);
Std_Return HALL_LCD_4bit_sendSTRPos(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t *copyData);
Std_Return HALL_LCD_4bit_goto(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn);

Std_Return HALL_LCD_8bit_init(const LCD_8Bit_t* copyLCD);
Std_Return HALL_LCD_8bit_sendCMD(const LCD_8Bit_t* copyLCD, uint8_t copyCMD);
Std_Return HALL_LCD_8bit_sendChar(const LCD_8Bit_t* copyLCD, uint8_t copyData);
Std_Return HALL_LCD_8bit_sendCharPos(const LCD_8Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t copyData);
Std_Return HALL_LCD_8bit_sendSTR(const LCD_8Bit_t* copyLCD, uint8_t *copyData);
Std_Return HALL_LCD_8bit_sendSTRPos(const LCD_8Bit_t* copyLCD, uint8_t coptRow, uint8_t copyColumn, uint8_t *copyData);
Std_Return HALL_LCD_8bit_goto(const LCD_8Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn);


Std_Return HALL_LCD_convertU8toSTR(uint8_t copyValue, uint8_t* copySTR);
Std_Return HALL_LCD_convertU16toSTR(uint16_t copyValue, uint8_t* copySTR);
Std_Return HALL_LCD_convertU32toSTR(uint32_t copyValue, uint8_t* copySTR);
/* -------------------- API End -------------------- */

#endif	/* HALL_LCD_INIT_H */

