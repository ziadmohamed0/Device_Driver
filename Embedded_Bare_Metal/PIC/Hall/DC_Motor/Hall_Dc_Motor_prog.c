/*
 * File:   Hall_Dc_Motor_prog.c
 * Author: s
 *
 * Created on 19 ??????, 2024, 12:55 ?
 */


#include "Hall_Dc_Motor_init.h"


static Pin_cfg_t objPin_motor_1;
static Pin_cfg_t objPin_motor_2;

Std_Return HALL_DC_MOTOR_init(const DC_Motor_t* copyDC_motor) {
    uint8_t retvalue = R_ERROR;
    if(copyDC_motor == NULL) {
        retvalue = R_ERROR;
    }
    else {
        objPin_motor_1.Port = copyDC_motor->DC_MOTOR[0].DC_Motor_Port;
        objPin_motor_1.Pin = copyDC_motor->DC_MOTOR[0].DC_Motor_Pin;
        objPin_motor_1.Status = copyDC_motor->DC_MOTOR[0].DC_Motor_Status;
        objPin_motor_1.Direction = GPIO_Dircetion_Output;
        
        objPin_motor_2.Port = copyDC_motor->DC_MOTOR[1].DC_Motor_Port;
        objPin_motor_2.Pin = copyDC_motor->DC_MOTOR[1].DC_Motor_Pin;
        objPin_motor_2.Status = copyDC_motor->DC_MOTOR[1].DC_Motor_Status;
        objPin_motor_2.Direction = GPIO_Dircetion_Output;        
        
        MCAL_GPIO_init(&objPin_motor_1);
        MCAL_GPIO_init(&objPin_motor_2);        
        retvalue = R_OK;
    }
    return retvalue;
}

Std_Return HALL_DC_MOTOR_right(const DC_Motor_t* copyDC_motor) {
    uint8_t retvalue = R_ERROR;
    if(copyDC_motor == NULL) {
        retvalue = R_ERROR;
    }
    else {
        objPin_motor_1.Port = copyDC_motor->DC_MOTOR[0].DC_Motor_Port;
        objPin_motor_1.Pin = copyDC_motor->DC_MOTOR[0].DC_Motor_Pin;
        objPin_motor_1.Status = copyDC_motor->DC_MOTOR[0].DC_Motor_Status;
        objPin_motor_1.Direction = GPIO_Dircetion_Output;
        
        objPin_motor_2.Port = copyDC_motor->DC_MOTOR[1].DC_Motor_Port;
        objPin_motor_2.Pin = copyDC_motor->DC_MOTOR[1].DC_Motor_Pin;
        objPin_motor_2.Status = copyDC_motor->DC_MOTOR[1].DC_Motor_Status;
        objPin_motor_2.Direction = GPIO_Dircetion_Output;  
        
        MCAL_GPIO_writePinStatus(&objPin_motor_1,GPIO_Status_High);
        MCAL_GPIO_writePinStatus(&objPin_motor_2,GPIO_Status_Low);
        retvalue = R_OK;
    }
    return retvalue;    
}

Std_Return HALL_DC_MOTOR_left(const DC_Motor_t* copyDC_motor) {
    uint8_t retvalue = R_ERROR;
    if(copyDC_motor == NULL) {
        retvalue = R_ERROR;
    }
    else {
        objPin_motor_1.Port = copyDC_motor->DC_MOTOR[0].DC_Motor_Port;
        objPin_motor_1.Pin = copyDC_motor->DC_MOTOR[0].DC_Motor_Pin;
        objPin_motor_1.Status = copyDC_motor->DC_MOTOR[0].DC_Motor_Status;
        objPin_motor_1.Direction = GPIO_Dircetion_Output;
        
        objPin_motor_2.Port = copyDC_motor->DC_MOTOR[1].DC_Motor_Port;
        objPin_motor_2.Pin = copyDC_motor->DC_MOTOR[1].DC_Motor_Pin;
        objPin_motor_2.Status = copyDC_motor->DC_MOTOR[1].DC_Motor_Status;
        objPin_motor_2.Direction = GPIO_Dircetion_Output;  
        
        MCAL_GPIO_writePinStatus(&objPin_motor_1,GPIO_Status_Low);
        MCAL_GPIO_writePinStatus(&objPin_motor_2,GPIO_Status_High);
        retvalue = R_OK;
    }
    return retvalue;    
}

Std_Return HALL_DC_MOTOR_stop(const DC_Motor_t* copyDC_motor) {
    uint8_t retvalue = R_ERROR;
    if(copyDC_motor == NULL) {
        retvalue = R_ERROR;
    }
    else {
        objPin_motor_1.Port = copyDC_motor->DC_MOTOR[0].DC_Motor_Port;
        objPin_motor_1.Pin = copyDC_motor->DC_MOTOR[0].DC_Motor_Pin;
        objPin_motor_1.Status = copyDC_motor->DC_MOTOR[0].DC_Motor_Status;
        objPin_motor_1.Direction = GPIO_Dircetion_Output;
        
        objPin_motor_2.Port = copyDC_motor->DC_MOTOR[1].DC_Motor_Port;
        objPin_motor_2.Pin = copyDC_motor->DC_MOTOR[1].DC_Motor_Pin;
        objPin_motor_2.Status = copyDC_motor->DC_MOTOR[1].DC_Motor_Status;
        objPin_motor_2.Direction = GPIO_Dircetion_Output;  
        
        MCAL_GPIO_writePinStatus(&objPin_motor_1,GPIO_Status_Low);
        MCAL_GPIO_writePinStatus(&objPin_motor_2,GPIO_Status_Low);        
        retvalue = R_OK;
    }
    return retvalue;    
}
