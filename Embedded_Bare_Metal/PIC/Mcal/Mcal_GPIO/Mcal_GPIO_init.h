/* 
 * File:   Mcal_GPIO_init.h
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:26 ?
 */

#ifndef MCAL_GPIO_INIT_H
#define	MCAL_GPIO_INIT_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_Device_cfg.h"
#include "../Mcal_Std_Types.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define GPIO_Port_Direction_Input       0xFF
#define GPIO_Port_Direction_Output      0x00

#define GPIO_Port_Status_High           0xFF
#define GPIO_Port_Status_Low            0x00
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define HWREG(REG)                      (*((volatile uint8_t*)(REG)))
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    GPIO_Status_Low = 0,
    GPIO_Status_High    
}Status_t;

typedef enum {
    GPIO_Dircetion_Input = 0,
    GPIO_Dircetion_Output,
}Direction_t;

typedef enum {
    GPIO_Pin_Index_0 = 0,
    GPIO_Pin_Index_1,            
    GPIO_Pin_Index_2,            
    GPIO_Pin_Index_3,            
    GPIO_Pin_Index_4,            
    GPIO_Pin_Index_5,            
    GPIO_Pin_Index_6,            
    GPIO_Pin_Index_7           
}Pin_Index_t;

typedef enum {
    GPIO_Port_Index_A = 0,
    GPIO_Port_Index_B,
    GPIO_Port_Index_C,
    GPIO_Port_Index_D,
    GPIO_Port_Index_E,
}Port_Index_t;

typedef struct {
    uint8_t Port        :3;
    uint8_t Pin         :3;
    uint8_t Direction   :1;
    uint8_t Status      :1 ;
}Pin_cfg_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return Mcal_GPIO_initPinDirection(const Pin_cfg_t* copyPinCFG);
Std_Return MCAL_GPIO_getPinDirection(const Pin_cfg_t* copyPinCFG, Direction_t *copyDirectionPin);
Std_Return MCAL_GPIO_writePinStatus(const Pin_cfg_t* copyPinCFG, Status_t copyStatusPin);
Std_Return MCAL_GPIO_getPinStatus(const Pin_cfg_t* copyPinCFG, Status_t* copyStatusPin);
Std_Return MCAL_GPIO_togglePin(const Pin_cfg_t* copyPinCFG);
Std_Return MCAL_GPIO_init(const Pin_cfg_t* copyPinCFG);


Std_Return Mcal_GPIO_initPortDirection(Port_Index_t copyPortCFG, uint8_t copyDirection);
Std_Return MCAL_GPIO_getPortDirection(Port_Index_t copyPortCFG, uint8_t* copyDirectionPort);
Std_Return MCAL_GPIO_writePortStatus(Port_Index_t copyPortCFG, uint8_t copyStatusPort);
Std_Return MCAL_GPIO_getPortStatus(Port_Index_t copyPortCFG, uint8_t* copyStatusPort);
/* -------------------- API End -------------------- */

#endif	/* MCAL_GPIO_INIT_H */

