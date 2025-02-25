/*
----------------------------------------------------
----------------------------------------------------
*   @name           :   PCA9685_init.h
*   @author         :   Ziad Fathi
*   @date           :   5/11/2024
*   @version        :   _v1
*   @brief          :	PCA9685 header file 
*						all initalizations of 
*						PCA9685. 
----------------------------------------------------
----------------------------------------------------
*/

#ifndef _HAL_PCA9685_INIT_H_
#define _HAL_PCA9685_INIT_H_

/* -------------------- Include Start -------------------- */
#include "../../Core/Inc/main.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define PCA9685_ADDRESS 				0x80
#define PCA9685_MODE1         			0x0         
#define PCA9685_PRE_SCALE     			0xFE
#define PCA9685_LED0_ON_L     			0x6
#define PCA9685_MODE1_SLEEP_BIT      	4
#define PCA9685_MODE1_AI_BIT         	5
#define PCA9685_MODE1_RESTART_BIT    	7

/* -------------------- Macro End  -------------------- */

/* -------------------- API Start -------------------- */
void PCA9685_Init(uint16_t frequency);
void PCA9685_SetPWM(uint8_t Channel, uint16_t OnTime, uint16_t OffTime);
void PCA9685_SetServoAngle(uint8_t Channel, float Angle);
void PCA9685_SetBit(uint8_t Register, uint8_t Bit, uint8_t Value);
void PCA9685_SetPWMFrequency(uint16_t frequency);
/* -------------------- API End -------------------- */

#endif