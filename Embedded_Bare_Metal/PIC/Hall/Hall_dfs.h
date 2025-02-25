/* 
 * File:   Hall_dfs.h
 * Author: s
 *
 * Created on 20 ??????, 2024, 08:53 ?
 */

#ifndef HALL_DFS_H
#define	HALL_DFS_H

/* -------------------- Include Start -------------------- */
#include "Led/Hall_Led_init.h"
#include "Button/Hall_Button_init.h"
#include "Relay/Hall_Relay_init.h"
#include "DC_Motor/Hall_Dc_Motor_init.h"
#include "Seven_seg/Hall_Seven_seg_init.h"
#include "Key_Pad/Hall_Key_Pad_init.h"
#include "LCD/Hall_lcd_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Global Variables Start -------------------- */
uint8_t *RetValue_KeyPad = NULL;
uint8_t *RetValue_BTN = NULL;
/* -------------------- Global Variables End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- peripherals init Start -------------------- */
    /* Led Pins */
Led_t Led1;
Led_t Led2;
Led_t Led3;

    /* DC Motor Pins */
DC_Motor_t Motor1;
DC_Motor_t Motor2;

    /* 7-Segment Pins */
Segement_t Seg1;

    /* Button Pins */
BTN_t BTN1;

    /* Key Pad Pins */
KeyPad_t KeyPad1;

    /* LCD Pins */
LCD_4Bit_t LCD1_4Bit;
LCD_8Bit_t LCD1_8Bit;
/* -------------------- peripherals init End -------------------- */

#endif	/* HALL_DFS_H */

