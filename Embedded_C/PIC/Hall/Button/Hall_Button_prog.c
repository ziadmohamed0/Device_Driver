/*
 * File:   Hall_Button_prog.c
 * Author: s
 *
 * Created on 18 ??????, 2024, 02:01 ?
 */


#include "Hall_Button_init.h"


Std_Return HALL_BTN_init(const BTN_t *copyBTN) {
    uint8_t retvalue = R_OK;
    if(copyBTN == NULL) {
        retvalue = R_ERROR;
    }
    else {
        retvalue = Mcal_GPIO_initPinDirection(&copyBTN);
    }
    return retvalue;    
}

Std_Return HALL_BTN_readStatus(const BTN_t *copyBTN, BTN_status_t *copyBTN_State) {
    uint8_t retvalue = R_ERROR;
    Status_t objStatus_pin  = GPIO_Status_Low;
    if((copyBTN == NULL) || (copyBTN_State == NULL)) {
        retvalue = R_ERROR;
    }
    else {
        MCAL_GPIO_getPinStatus(&(copyBTN->BTN_Pin), &objStatus_pin);

        if(copyBTN->BTN_Connection == BTN_Active_High) {
            if(objStatus_pin == GPIO_Status_High) {
                *copyBTN_State = BTN_Pressed;
            }
            else {
                *copyBTN_State = BTN_Released;
            }
        }
        else if(copyBTN->BTN_Connection == BTN_Active_Low) {
            if(objStatus_pin == GPIO_Status_High) {
                *copyBTN_State = BTN_Released;
            }
            else {
                *copyBTN_State = BTN_Pressed;
            }
        }
        else { /* Nothing */}
        retvalue = R_OK;
    }
    return retvalue;
}