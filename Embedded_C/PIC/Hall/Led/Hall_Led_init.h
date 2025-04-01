/* 
 * File:   Hall_Led_init.h
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:21 ?
 */

#ifndef HALL_LED_INIT_H
#define	HALL_LED_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    LED_OFF,
    LED_ON
}Led_State_t;

typedef struct {
    uint8_t LED_PORTx   : 4;
    uint8_t LED_PINx    : 3;
    uint8_t LED_Status  : 1;
}Led_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return  HALL_Led_init(const Led_t* copyLed);
Std_Return  HALL_Led_trunON(const Led_t* copyLed);
Std_Return  HALL_Led_trunOFF(const Led_t* copyLed);
Std_Return  HALL_Led_trunToggle(const Led_t* copyLed);
/* -------------------- API End -------------------- */

#endif	/* HALL_LED_INIT_H */

