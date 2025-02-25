/*
 * File:   Hall_dfs.c
 * Author: s
 *
 * Created on 20 ??????, 2024, 09:57 ?
 */


#include "Hall_dfs.h"

    /* Led Pins */
Led_t Led1 = {
    .LED_PORTx  = GPIO_Port_Index_C,
    .LED_PINx   = GPIO_Pin_Index_0,
    .LED_Status = GPIO_Status_Low,
};

Led_t Led2 = {
    .LED_PORTx  = GPIO_Port_Index_C,
    .LED_PINx   = GPIO_Pin_Index_1,
    .LED_Status = GPIO_Status_Low,
};

Led_t Led3 = {
    .LED_PORTx  = GPIO_Port_Index_C,
    .LED_PINx   = GPIO_Pin_Index_2,
    .LED_Status = GPIO_Status_Low,
};

    /* DC Motor Pins */
DC_Motor_t Motor1 = {
    .DC_MOTOR[0].DC_Motor_Port                      = GPIO_Port_Index_B,
    .DC_MOTOR[0].DC_Motor_Pin                       = GPIO_Pin_Index_0,
    .DC_MOTOR[0].DC_Motor_Status                    = GPIO_Status_Low,
    
    .DC_MOTOR[1].DC_Motor_Port                      = GPIO_Port_Index_B,
    .DC_MOTOR[1].DC_Motor_Pin                       = GPIO_Pin_Index_1,
    .DC_MOTOR[1].DC_Motor_Status                    = GPIO_Status_Low,    
};

DC_Motor_t Motor2 = {
    .DC_MOTOR[0].DC_Motor_Port                      = GPIO_Port_Index_B,
    .DC_MOTOR[0].DC_Motor_Pin                       = GPIO_Pin_Index_2,
    .DC_MOTOR[0].DC_Motor_Status                    = GPIO_Status_Low,
    
    .DC_MOTOR[1].DC_Motor_Port                      = GPIO_Port_Index_B,
    .DC_MOTOR[1].DC_Motor_Pin                       = GPIO_Pin_Index_3,
    .DC_MOTOR[1].DC_Motor_Status                    = GPIO_Status_Low,    
};

    /* 7-Segment Pins */
Segement_t Seg1 = {
    .Segement_Pins[SEGEMENT_PIN0].Port              = GPIO_Port_Index_B,
    .Segement_Pins[SEGEMENT_PIN0].Pin               = GPIO_Pin_Index_0,
    .Segement_Pins[SEGEMENT_PIN0].Direction         = GPIO_Dircetion_Output,
    .Segement_Pins[SEGEMENT_PIN0].Status            = GPIO_Status_Low,
    
    .Segement_Pins[SEGEMENT_PIN1].Port              = GPIO_Port_Index_B,
    .Segement_Pins[SEGEMENT_PIN1].Pin               = GPIO_Pin_Index_1,
    .Segement_Pins[SEGEMENT_PIN1].Direction         = GPIO_Dircetion_Output,
    .Segement_Pins[SEGEMENT_PIN1].Status            = GPIO_Status_Low,
    
    .Segement_Pins[SEGEMENT_PIN2].Port              = GPIO_Port_Index_B,
    .Segement_Pins[SEGEMENT_PIN2].Pin               = GPIO_Pin_Index_2,
    .Segement_Pins[SEGEMENT_PIN2].Direction         = GPIO_Dircetion_Output,
    .Segement_Pins[SEGEMENT_PIN2].Status            = GPIO_Status_Low,  
    
    .Segement_Pins[SEGEMENT_PIN3].Port              = GPIO_Port_Index_B,
    .Segement_Pins[SEGEMENT_PIN3].Pin               = GPIO_Pin_Index_3,
    .Segement_Pins[SEGEMENT_PIN3].Direction         = GPIO_Dircetion_Output,
    .Segement_Pins[SEGEMENT_PIN3].Status            = GPIO_Status_Low,
    
    .SegmentType                                    = SEGEMENT_COMMON_ANODE,    
};

    /* Button Pins */
BTN_t BTN1 = {
    .BTN_Pin.Port                                   = GPIO_Port_Index_B,
    .BTN_Pin.Pin                                    = GPIO_Pin_Index_0,
    .BTN_Pin.Direction                              = GPIO_Dircetion_Input,
    .BTN_Pin.Status                                 = GPIO_Status_Low,
    .BTN_Connection                                 = BTN_Active_High,
    .BTN_Status                                     = BTN_Released
};

    /* Key Pad Pins */
KeyPad_t KeyPad1 = {
    .Keypad_Row_Pins[0].Port                        = GPIO_Port_Index_C,
    .Keypad_Row_Pins[0].Pin                         = GPIO_Pin_Index_0,
    .Keypad_Row_Pins[0].Direction                   = GPIO_Dircetion_Output,
    .Keypad_Row_Pins[0].Status                      = GPIO_Status_Low,
    
    .Keypad_Row_Pins[1].Port                        = GPIO_Port_Index_C,
    .Keypad_Row_Pins[1].Pin                         = GPIO_Pin_Index_1,
    .Keypad_Row_Pins[1].Direction                   = GPIO_Dircetion_Output,
    .Keypad_Row_Pins[1].Status                      = GPIO_Status_Low,
    
    .Keypad_Row_Pins[2].Port                        = GPIO_Port_Index_C,
    .Keypad_Row_Pins[2].Pin                         = GPIO_Pin_Index_2,
    .Keypad_Row_Pins[2].Direction                   = GPIO_Dircetion_Output,
    .Keypad_Row_Pins[2].Status                      = GPIO_Status_Low,
    
    .Keypad_Row_Pins[3].Port                        = GPIO_Port_Index_C,
    .Keypad_Row_Pins[3].Pin                         = GPIO_Pin_Index_3,
    .Keypad_Row_Pins[3].Direction                   = GPIO_Dircetion_Output,
    .Keypad_Row_Pins[3].Status                      = GPIO_Status_Low, 
    
    .Keypad_Column_Pins[0].Port                     = GPIO_Port_Index_C,
    .Keypad_Column_Pins[0].Pin                      = GPIO_Pin_Index_4,
    .Keypad_Column_Pins[0].Direction                = GPIO_Dircetion_Input,
    .Keypad_Column_Pins[0].Status                   = GPIO_Status_Low,
    
    .Keypad_Column_Pins[1].Port                     = GPIO_Port_Index_C,
    .Keypad_Column_Pins[1].Pin                      = GPIO_Pin_Index_5,
    .Keypad_Column_Pins[1].Direction                = GPIO_Dircetion_Input,
    .Keypad_Column_Pins[1].Status                   = GPIO_Status_Low,
    
    .Keypad_Column_Pins[2].Port                     = GPIO_Port_Index_C,
    .Keypad_Column_Pins[2].Pin                      = GPIO_Pin_Index_6,
    .Keypad_Column_Pins[2].Direction                = GPIO_Dircetion_Input,
    .Keypad_Column_Pins[2].Status                   = GPIO_Status_Low,
    
    .Keypad_Column_Pins[3].Port                     = GPIO_Port_Index_C,
    .Keypad_Column_Pins[3].Pin                      = GPIO_Pin_Index_7,
    .Keypad_Column_Pins[3].Direction                = GPIO_Dircetion_Input,
    .Keypad_Column_Pins[3].Status                   = GPIO_Status_Low,  
};

    /* LCD Pins */
LCD_4Bit_t LCD1_4Bit = {
    .LCD_rs.Port                                    = GPIO_Port_Index_D,
    .LCD_rs.Pin                                     = GPIO_Pin_Index_0,
    .LCD_rs.Direction                               = GPIO_Dircetion_Output,
    .LCD_rs.Status                                  = GPIO_Status_Low,
    
    .LCD_en.Port                                    = GPIO_Port_Index_D,
    .LCD_en.Pin                                     = GPIO_Pin_Index_1,
    .LCD_en.Direction                               = GPIO_Dircetion_Output,
    .LCD_en.Status                                  = GPIO_Status_Low,  
    
    .LCD_D[0].Port                                  = GPIO_Port_Index_D,
    .LCD_D[0].Pin                                   = GPIO_Pin_Index_2,
    .LCD_D[0].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[0].Status                                = GPIO_Status_Low,
    
    .LCD_D[1].Port                                  = GPIO_Port_Index_D,
    .LCD_D[1].Pin                                   = GPIO_Pin_Index_3,
    .LCD_D[1].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[1].Status                                = GPIO_Status_Low, 
    
    .LCD_D[2].Port                                  = GPIO_Port_Index_D,
    .LCD_D[2].Pin                                   = GPIO_Pin_Index_4,
    .LCD_D[2].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[2].Status                                = GPIO_Status_Low,
    
    .LCD_D[3].Port                                  = GPIO_Port_Index_D,
    .LCD_D[3].Pin                                   = GPIO_Pin_Index_5,
    .LCD_D[3].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[3].Status                                = GPIO_Status_Low,    
};

LCD_8Bit_t LCD1_8Bit = {
    .LCD_rs.Port                                    = GPIO_Port_Index_C,
    .LCD_rs.Pin                                     = GPIO_Pin_Index_0,
    .LCD_rs.Direction                               = GPIO_Dircetion_Output,
    .LCD_rs.Status                                  = GPIO_Status_Low,
    
    .LCD_en.Port                                    = GPIO_Port_Index_C,
    .LCD_en.Pin                                     = GPIO_Pin_Index_1,
    .LCD_en.Direction                               = GPIO_Dircetion_Output,
    .LCD_en.Status                                  = GPIO_Status_Low,  
    
    .LCD_D[0].Port                                  = GPIO_Port_Index_D,
    .LCD_D[0].Pin                                   = GPIO_Pin_Index_0,
    .LCD_D[0].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[0].Status                                = GPIO_Status_Low,
    
    .LCD_D[1].Port                                  = GPIO_Port_Index_D,
    .LCD_D[1].Pin                                   = GPIO_Pin_Index_1,
    .LCD_D[1].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[1].Status                                = GPIO_Status_Low, 
    
    .LCD_D[2].Port                                  = GPIO_Port_Index_D,
    .LCD_D[2].Pin                                   = GPIO_Pin_Index_2,
    .LCD_D[2].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[2].Status                                = GPIO_Status_Low,
    
    .LCD_D[3].Port                                  = GPIO_Port_Index_D,
    .LCD_D[3].Pin                                   = GPIO_Pin_Index_3,
    .LCD_D[3].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[3].Status                                = GPIO_Status_Low, 
    
    .LCD_D[4].Port                                  = GPIO_Port_Index_D,
    .LCD_D[4].Pin                                   = GPIO_Pin_Index_4,
    .LCD_D[4].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[4].Status                                = GPIO_Status_Low, 
    
    .LCD_D[5].Port                                  = GPIO_Port_Index_D,
    .LCD_D[5].Pin                                   = GPIO_Pin_Index_5,
    .LCD_D[5].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[5].Status                                = GPIO_Status_Low,
    
    .LCD_D[6].Port                                  = GPIO_Port_Index_D,
    .LCD_D[6].Pin                                   = GPIO_Pin_Index_6,
    .LCD_D[6].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[6].Status                                = GPIO_Status_Low,  
    
    .LCD_D[7].Port                                  = GPIO_Port_Index_D,
    .LCD_D[7].Pin                                   = GPIO_Pin_Index_7,
    .LCD_D[7].Direction                             = GPIO_Dircetion_Output,
    .LCD_D[7].Status                                = GPIO_Status_Low,    
};