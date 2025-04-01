/*
----------------------------------------------------
----------------------------------------------------
*   @name           :   MPU6050_init.h
*   @author         :   Ziad Fathi
*   @date           :   5/11/2024
*   @version        :   _v1
*   @brief          :	MPU6050 header file 
*						all initalizations of 
*						mpu6050 sensor. 
----------------------------------------------------
----------------------------------------------------
*/

#ifndef _HAL_MPU6050_H_
#define _HAL_MPU6050_H_

/* -------------------- Include Start -------------------- */
#include "../../Core/Inc/main.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19
#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75
/* -------------------- Macro End  -------------------- */

/* -------------------- Global Variables Start -------------------- */
/* Accelometer Variables */
extern int16_t Accel_X_RAW;
extern int16_t Accel_Y_RAW ;
extern int16_t Accel_Z_RAW;
extern float Ax, Ay, Az;

/* Gyroscope Variables */
extern int16_t Gyro_X_RAW;
extern int16_t Gyro_Y_RAW;
extern int16_t Gyro_Z_RAW;
extern float Gx, Gy, Gz;
/* -------------------- Global Variables End -------------------- */



/* -------------------- API Start -------------------- */
void MPU6050_Init (void);
void MPU6050_Read_Accel (void);
void MPU6050_Read_Gyro (void);
/* -------------------- API End -------------------- */


#endif