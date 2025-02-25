/*
 * File:   Hall_Seven_seg_prog.c
 * Author: s
 *
 * Created on 20 ??????, 2024, 06:32 ?
 */


#include "Hall_Seven_seg_init.h"

Std_Return HALL_SEVEN_SEGEMENT_init(const Segement_t* copySevenSegement) {
    uint8_t retValue = R_ERROR;
    if(copySevenSegement == NULL) {
        retValue = R_ERROR;
    }
    
    else {
        MCAL_GPIO_init(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN0]));
        MCAL_GPIO_init(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN1]));
        MCAL_GPIO_init(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN2]));
        MCAL_GPIO_init(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN3]));
        retValue = R_OK;
    }
    return retValue;
}
Std_Return HALL_SEVEN_SEGEMENT_writeNumber(const Segement_t* copySevenSegement, uint8_t copyNumber) {
    uint8_t retValue = R_ERROR;
    if(copySevenSegement == NULL) {
        retValue = R_ERROR;
    }
    
    else {
        MCAL_GPIO_writePinStatus(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN0]), (copyNumber & 0x01));
        MCAL_GPIO_writePinStatus(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN1]), ((copyNumber >> 1) & 0x01));
        MCAL_GPIO_writePinStatus(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN2]), ((copyNumber >> 2) & 0x01));
        MCAL_GPIO_writePinStatus(&(copySevenSegement->Segement_Pins[SEGEMENT_PIN3]), ((copyNumber >> 3) & 0x01));
        
        retValue = R_OK;
    }
    return retValue;
}