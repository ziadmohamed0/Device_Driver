/* 
 * File:   Hall_Seven_seg_init.h
 * Author: s
 *
 * Created on 20 ??????, 2024, 06:31 ?
 */

#ifndef HALL_SEVEN_SEG_INIT_H
#define	HALL_SEVEN_SEG_INIT_H

/* -------------------- Include Start -------------------- */
#include "../../Mcal/Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define SEGEMENT_PIN0                   0
#define SEGEMENT_PIN1                   1
#define SEGEMENT_PIN2                   2
#define SEGEMENT_PIN3                   3
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    SEGEMENT_COMMON_ANODE,
    SEGEMENT_COMMON_CATHOD,
}Segement_type_t;

typedef struct {
    Pin_cfg_t       Segement_Pins[4];
    Segement_type_t SegmentType;
}Segement_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return HALL_SEVEN_SEGEMENT_init(const Segement_t* copySevenSegement);
Std_Return HALL_SEVEN_SEGEMENT_writeNumber(const Segement_t* copySevenSegement, uint8_t copyNumber);
/* -------------------- API End -------------------- */

#endif	/* HALL_SEVEN_SEG_INIT_H */

