/* 
 * File:   Hall_Dc_Motor_init.h
 * Author: s
 *
 * Created on 19 ??????, 2024, 12:56 ?
 */

#ifndef HALL_DC_MOTOR_INIT_H
#define	HALL_DC_MOTOR_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define DC_MOTOR_STATUS_ON     0X01U
#define DC_MOTOR_STATUS_OFF    0X00U
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef struct {
    uint8_t DC_Motor_Port    : 4;
    uint8_t DC_Motor_Pin     : 3;
    uint8_t DC_Motor_Status  : 1;
}DC_Motor_pin_t;

typedef struct {
    DC_Motor_pin_t DC_MOTOR[2];
}DC_Motor_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_DC_MOTOR_init(const DC_Motor_t* copyDC_motor);
Std_Return HALL_DC_MOTOR_right(const DC_Motor_t* copyDC_motor);
Std_Return HALL_DC_MOTOR_left(const DC_Motor_t* copyDC_motor);
Std_Return HALL_DC_MOTOR_stop(const DC_Motor_t* copyDC_motor);
/* -------------------- API End -------------------- */

#endif	/* HALL_DC_MOTOR_INIT_H */

