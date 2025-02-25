/* 
 * File:   Hall_Key_Pad_init.h
 * Author: s
 *
 * Created on 20 ??????, 2024, 07:45 ?
 */

#ifndef HALL_KEY_PAD_INIT_H
#define	HALL_KEY_PAD_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define HALL_KEYPAD_ROWS                4
#define HALL_KEYPAD_COLUMNS             4
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef struct {
    Pin_cfg_t Keypad_Row_Pins[HALL_KEYPAD_ROWS];
    Pin_cfg_t Keypad_Column_Pins[HALL_KEYPAD_COLUMNS];
}KeyPad_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_KeyPad_init(const KeyPad_t* copyKeyPad);
Std_Return HALL_KeyPad_getValue(const KeyPad_t* copyKeyPad, uint8_t *copyValueStore);
/* -------------------- API End -------------------- */

#endif	/* HALL_KEY_PAD_INIT_H */

