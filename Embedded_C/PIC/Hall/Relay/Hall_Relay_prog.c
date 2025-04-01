/*
 * File:   Hall_Relay_prog.c
 * Author: s
 *
 * Created on 19 ??????, 2024, 12:04 ?
 */


#include "Hall_Relay_init.h"


Std_Return HALL_Relay_init(const Relay_t* copyRelay) {
    uint8_t retValue = R_ERROR;
    if(copyRelay == NULL) {
        retValue = R_ERROR;
    }
    else {
        Pin_cfg_t objPin = {
            .Port       = copyRelay->Relay_Port,
            .Pin        = copyRelay->Relay_Pin,
            .Status     = copyRelay->Relay_Status,
            .Direction  = GPIO_Dircetion_Output
        };
        MCAL_GPIO_init(&objPin);
        retValue = R_OK;
    }
    return retValue = R_ERROR;;
}
Std_Return HALL_Relay_turnON(const Relay_t* copyRelay) {
    uint8_t retValue = R_ERROR;
    if(copyRelay == NULL) {
        retValue = R_ERROR;
    }
    else {
        Pin_cfg_t objPin = {
            .Port       = copyRelay->Relay_Port,
            .Pin        = copyRelay->Relay_Pin,
            .Status     = copyRelay->Relay_Status,
            .Direction  = GPIO_Dircetion_Output
        };
        MCAL_GPIO_writePinStatus(&objPin, GPIO_Status_High);
        retValue = R_OK;
    }
    return retValue = R_ERROR;;
}
Std_Return HALL_Relay_turnOFF(const Relay_t* copyRelay) {
    uint8_t retValue = R_ERROR;
    if(copyRelay == NULL) {
        retValue = R_ERROR;
    }
    else {
        Pin_cfg_t objPin = {
            .Port       = copyRelay->Relay_Port,
            .Pin        = copyRelay->Relay_Pin,
            .Status     = copyRelay->Relay_Status,
            .Direction  = GPIO_Dircetion_Output
        };
        MCAL_GPIO_writePinStatus(&objPin, GPIO_Status_Low);        
        retValue = R_OK;
    }
    return retValue = R_ERROR;;    
}
