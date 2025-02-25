/* 
 * File:   Hall_Button_init.h
 * Author: s
 *
 * Created on 18 ??????, 2024, 02:03 ?
 */

#ifndef HALL_BUTTON_INIT_H
#define	HALL_BUTTON_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
typedef enum {
    BTN_Pressed,
    BTN_Released    
}BTN_status_t;

typedef enum {
    BTN_Active_High,
    BTN_Active_Low
}BTN_Active_t;

typedef struct {
    Pin_cfg_t       BTN_Pin;
    BTN_status_t    BTN_Status;
    BTN_Active_t    BTN_Connection;
}BTN_t;
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_BTN_init(const BTN_t *copyBTN);
Std_Return HALL_BTN_readStatus(const BTN_t *copyBTN, BTN_status_t *copyBTN_State);
/* -------------------- API End -------------------- */

#endif	/* HALL_BUTTON_INIT_H */

