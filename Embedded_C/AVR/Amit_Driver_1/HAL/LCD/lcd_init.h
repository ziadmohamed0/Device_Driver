/*
 * lcd_init.h
 *
 *  Created on: Sep 15, 2023
 *      Author: hp
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

#define CLEAR_DIS          (uint8)0x01
#define Return_Home        (uint8)0x02
#define DISPLAY_ON         (uint8)0x0C
#define DISPLAY_OFF        (uint8)0x08
#define CURSOR_ON_BLINK    (uint8)0x0F
#define CURSOR_OFF_BLINK   (uint8)0x0E
#define SHIFT_DIS_R        (uint8)0x1C
#define SHIFT_DIS_L        (uint8)0x18
#define ENTRY_MODE_INC     (uint8)0X06
#define ENTRY_MODE_DEC     (uint8)0X04
#define BIT_8_MODE         (uint8)0x38
#define BIT_4_MODE         (uint8)0x28
#define AD_CGRAM           (uint8)0x40
#define AD_DDRAM           (uint8)0x80



void LCD_vidInit();
void LCD_vidWriteCmd(uint8 u8CmdCopy);
void LCD_vidWriteChar(uint8 u8CharCopy);
void LCD_vidClrDisp();
void LCD_vidShiftLeft();
void LCD_vidShiftRight();
void LCD_vidWriteInt(sint32 u32NumCopy);
void LCD_vidWriteStr(uint8 *u8StrCopy);
void LCD_vidGoto(uint8 u8RowCopy,uint8 u8ColCopy);
void LCD_vidWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc);

void LCD_vid4BitInit();
void LCD_vid4BitWriteCmd(uint8 u8CmdCopy);
void LCD_vid4BitWriteChar(uint8 u8CharCopy);
void LCD_vid4BitClrDisp();
void LCD_vid4BitShiftLeft();
void LCD_vid4BitShiftRight();
void LCD_vid4BitWriteInt(sint32 u32NumCopy);
void LCD_vid4BitWriteStr(uint8 *u8StrCopy);
void LCD_vid4BitGoto(uint8 u8RowCopy,uint8 u8ColCopy);
void LCD_vid4BitWritePatternCGRAM(uint8 *u8Pattern,uint8 u8Loc);


#endif /* HAL_LCD_LCD_INIT_H_ */
