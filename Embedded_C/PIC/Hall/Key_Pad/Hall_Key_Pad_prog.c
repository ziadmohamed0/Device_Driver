/*
 * File:   Hall_Key_Pad_prog.c
 * Author: s
 *
 * Created on 20 ??????, 2024, 07:44 ?
 */


#include "Hall_Key_Pad_init.h"

static const uint8_t btn_Value[HALL_KEYPAD_ROWS][HALL_KEYPAD_COLUMNS] ={
                                                                            {7,8,9,'/'},
                                                                            {4,5,6,'*'},
                                                                            {1,2,3,'-'},
                                                                            {'#',0,'=','+'}
                                                                        };

Std_Return HALL_KeyPad_init(const KeyPad_t* copyKeyPad) {
    uint8_t retvalue = R_ERROR;
    uint8_t Rows_Conter = Zero_init;
    uint8_t Columns_Conter = Zero_init;
    if(copyKeyPad == NULL) {
        retvalue = R_ERROR;
    }
    else {
        for(Rows_Conter = Zero_init; Rows_Conter < HALL_KEYPAD_ROWS; Rows_Conter++) {
            MCAL_GPIO_init(&(copyKeyPad->Keypad_Row_Pins[Rows_Conter]));
        }
        for(Columns_Conter = Zero_init; Columns_Conter < HALL_KEYPAD_COLUMNS; Columns_Conter++) {
            Mcal_GPIO_initPinDirection(&(copyKeyPad->Keypad_Column_Pins[Columns_Conter]));
        }
        retvalue =  R_OK;
    }
    return retvalue;
}
Std_Return HALL_KeyPad_getValue(const KeyPad_t* copyKeyPad, uint8_t *copyValueStore) {
    uint8_t retvalue = R_ERROR;
    uint8_t Rows_Conter = Zero_init;
    uint8_t Columns_Conter = Zero_init;   
    uint8_t Counter = Zero_init;
    uint8_t Column_Value = Zero_init;
    if(copyKeyPad == NULL) {
        retvalue = R_ERROR;
    }
    else {
        for(Rows_Conter = Zero_init; Rows_Conter < HALL_KEYPAD_ROWS; Rows_Conter++) {
            for(Counter = Zero_init; Counter < HALL_KEYPAD_ROWS; Counter++) {
                MCAL_GPIO_writePinStatus(&(copyKeyPad->Keypad_Row_Pins[Counter]), GPIO_Status_Low);
            } 
            MCAL_GPIO_writePinStatus(&(copyKeyPad->Keypad_Row_Pins[Rows_Conter]), GPIO_Status_High);
            for(Columns_Conter = Zero_init; Columns_Conter < HALL_KEYPAD_ROWS; Columns_Conter++) {
                MCAL_GPIO_getPinStatus(&(copyKeyPad->Keypad_Column_Pins[Columns_Conter]), &Column_Value);
                if(Column_Value == GPIO_Status_High) {
                    *copyValueStore = btn_Value[Rows_Conter][Columns_Conter];
                }
            } 
        }        
        retvalue =  R_OK;
    }
    return retvalue;    
}
