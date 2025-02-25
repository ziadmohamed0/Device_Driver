/*
 * File:   Mcal_dfs.c
 * Author: s
 *
 * Created on 26 ??????, 2024, 02:37 ?
 */


#include "Mcal_dfs.h"

    /* External Interrupt INTx */
Interrupt_INTx_t EX_INT0 = {
    .EX_InterruptHandler    = INT0_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT0,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_0,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};

Interrupt_INTx_t EX_INT1 = {
    .EX_InterruptHandler    = INT1_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT1,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_1,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};

Interrupt_INTx_t EX_INT2 = {
    .EX_InterruptHandler    = INT2_isr,
    .Edge                   = INTERRUPT_EDGE_RISING,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
    .Source                 = INTERRUPT_EXTERNAL_INT2,
    .MCU_Pin.Port           = GPIO_Port_Index_B, 
    .MCU_Pin.Pin            = GPIO_Pin_Index_2,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
};


    /* External Interrupt RBx */
Interrupt_RBx_t RB_4 = {
    .EX_InterruptHandler_High    = RB4_isr,
    .MCU_Pin.Port           = GPIO_Port_Index_B,
    .MCU_Pin.Pin            = GPIO_Pin_Index_4,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
};

Interrupt_RBx_t RB_5 = {
    .EX_InterruptHandler_High    = RB5_isr,
    .MCU_Pin.Port           = GPIO_Port_Index_B,
    .MCU_Pin.Pin            = GPIO_Pin_Index_5,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
};

Interrupt_RBx_t RB_6 = {
    .EX_InterruptHandler_High    = RB6_isr,
    .MCU_Pin.Port           = GPIO_Port_Index_B,
    .MCU_Pin.Pin            = GPIO_Pin_Index_6,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
};

Interrupt_RBx_t RB_7 = {
    .EX_InterruptHandler_High    = RB7_isr,
    .MCU_Pin.Port           = GPIO_Port_Index_B,
    .MCU_Pin.Pin            = GPIO_Pin_Index_7,
    .MCU_Pin.Direction      = GPIO_Dircetion_Input,
    .MCU_Pin.Status         = GPIO_Status_Low,
    .Priorety               = INTERRUPT_PRIORETY_HIGH,
};


    /* ADC Bits */
ADC_t adc1 = {
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
    .ADCinterruptHandler = ADC_isr,
    .Priorety           = INTERRUPT_PRIORETY_LOW,
#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
    
#endif
    .AcquisitionClock = ADC_CLK_CONVERSION_FOSC_DIV_16,
    .AdcChanall = ADC_CHANAL_AN1,
    .AcquisitionClock = ADC_TAD_12,
    .ResultFormat = ADC_RESULT_FORMAT_RIGHT,
    .VolatageRefrance = ADC_VOLTAGE_REF_DISABLE,
};

ADC_t adc2 = {
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
    .ADCinterruptHandler = ADC_isr,
    .Priorety           = INTERRUPT_PRIORETY_LOW,
#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
    
#endif
    .AcquisitionClock = ADC_CLK_CONVERSION_FOSC_DIV_16,
    .AdcChanall = ADC_CHANAL_AN2,
    .AcquisitionClock = ADC_TAD_12,
    .ResultFormat = ADC_RESULT_FORMAT_RIGHT,
    .VolatageRefrance = ADC_VOLTAGE_REF_DISABLE,
};

ADC_t adc3 = {
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
    .ADCinterruptHandler = ADC_isr,
    .Priorety           = INTERRUPT_PRIORETY_LOW,
#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
    
#endif
    .AcquisitionClock = ADC_CLK_CONVERSION_FOSC_DIV_16,
    .AdcChanall = ADC_CHANAL_AN3,
    .AcquisitionClock = ADC_TAD_12,
    .ResultFormat = ADC_RESULT_FORMAT_RIGHT,
    .VolatageRefrance = ADC_VOLTAGE_REF_DISABLE,
};

ADC_t adc4 = {
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
    .ADCinterruptHandler = ADC_isr,
    .Priorety           = INTERRUPT_PRIORETY_LOW,
#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
    
#endif
    .AcquisitionClock = ADC_CLK_CONVERSION_FOSC_DIV_16,
    .AdcChanall = ADC_CHANAL_AN4,
    .AcquisitionClock = ADC_TAD_12,
    .ResultFormat = ADC_RESULT_FORMAT_RIGHT,
    .VolatageRefrance = ADC_VOLTAGE_REF_DISABLE,
};