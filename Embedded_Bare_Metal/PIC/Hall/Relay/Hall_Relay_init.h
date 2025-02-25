/* 
 * File:   Hall_Relay_init.h
 * Author: s
 *
 * Created on 19 ??????, 2024, 12:05 ?
 */

#ifndef HALL_RELAY_INIT_H
#define	HALL_RELAY_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define RELAY_STATUS_ON     0X01U
#define RELAY_STATUS_OFF    0X00U
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef struct {
    uint8_t Relay_Port    : 4;
    uint8_t Relay_Pin     : 3;
    uint8_t Relay_Status  : 1;
}Relay_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_Relay_init(const Relay_t* copyRelay);
Std_Return HALL_Relay_turnON(const Relay_t* copyRelay);
Std_Return HALL_Relay_turnOFF(const Relay_t* copyRelay);
/* -------------------- API End -------------------- */

#endif	/* HALL_RELAY_INIT_H */

