/*
 * File:   Hall_Led_prog.c
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:33 ?
 */

#include "Hall_Led_init.h"

Std_Return  HALL_Led_init(const Led_t* copyLed) {
    uint8_t retVal = R_OK;
    if(copyLed == NULL) {
        retVal = R_ERROR;
    }
    else {
        Pin_cfg_t objLed = {
            .Port       = copyLed->LED_PORTx,
            .Pin        = copyLed->LED_PINx,
            .Direction  = GPIO_Dircetion_Output,
            .Status     = copyLed->LED_Status,
        };
        
        MCAL_GPIO_init(&objLed);
    }
    return retVal;
}

Std_Return  HALL_Led_trunON(const Led_t* copyLed) {
    uint8_t retVal = R_OK;
    if(copyLed == NULL) {
        retVal = R_ERROR;
    }
    else {
        Pin_cfg_t objLed = {
            .Port       = copyLed->LED_PORTx,
            .Pin        = copyLed->LED_PINx,
            .Direction  = GPIO_Dircetion_Output,
            .Status     = copyLed->LED_Status,
        };

        MCAL_GPIO_writePinStatus(&objLed, GPIO_Status_High);
    }
    return retVal;
}

Std_Return  HALL_Led_trunOFF(const Led_t* copyLed) {
    uint8_t retVal = R_OK;
    if(copyLed == NULL) {
        retVal = R_ERROR;
    }
    else {
        Pin_cfg_t objLed = {
            .Port       = copyLed->LED_PORTx,
            .Pin        = copyLed->LED_PINx,
            .Direction  = GPIO_Dircetion_Output,
            .Status     = copyLed->LED_Status,
        };

        MCAL_GPIO_writePinStatus(&objLed, GPIO_Status_Low);        
    }
    return retVal;    
}

Std_Return  HALL_Led_trunToggle(const Led_t* copyLed) {
    uint8_t retVal = R_OK;
    if(copyLed == NULL) {
        retVal = R_ERROR;
    }
    else {
        Pin_cfg_t objLed = {
            .Port       = copyLed->LED_PORTx,
            .Pin        = copyLed->LED_PINx,
            .Direction  = GPIO_Dircetion_Output,
            .Status     = copyLed->LED_Status,
        };

        MCAL_GPIO_togglePin(&objLed);        
    }
    return retVal;    
}