/*
 * File:   Mcal_ADC_prog.c
 * Author: s
 *
 * Created on November 11, 2024, 1:42 AM
 */


#include "Mcal_ADC_init.h"


static void (*ADC_interruptHandler)(void) = NULL;


static inline void ADC_input_chanal_configuration(ADC_chanal_select_t copyChanal);
static inline void ADC_SelectResultFormat(const ADC_t * copyADC);
static inline void ADC_VolatgeReferance(const ADC_t * copyADC);

Std_Return MCAL_ADC_init(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        /* Disable the ADC */
        MCAL_ADC_CONVERSION_Disable();

        /* Configure The Acquisition time */
        ADCON2bits.ACQT = copyADC->AcquisitionClock;
        
        /* Configure The Conversion Clock */
        ADCON2bits.ADCS = copyADC->ConversionClock;
        
        /* Configure The Default Channel */
        ADCON0bits.CHS = copyADC->AdcChanall;
        ADC_input_chanal_configuration(copyADC->AdcChanall);
        
        /* Configure The interrupt */
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
            MCAL_INTERRUPT_GlobaleInterruptEnable();
            MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif
            Mcal_ADC_InterruptEnable();
            Mcal_ADC_ClearFlage();
            ADC_interruptHandler = copyADC->ADCinterruptHandler;
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
            switch(copyADC->Priorety) {
                case INTERRUPT_PRIORETY_HIGH : Mcal_ADC_HighPrioritySet(); break;
                case INTERRUPT_PRIORETY_LOW : Mcal_ADC_LowPrioritySet(); break;
            }            
#endif
            
#endif
                
        /* Configure The result Format */
        ADC_SelectResultFormat(copyADC);
        
        /* Configure The voltage Reference */
        ADC_VolatgeReferance(copyADC);
        /* Enable ADC */
        MCAL_ADC_CONVERSION_Enable();
        retValue = R_OK;
    }
    return retValue;
}

Std_Return MCAL_ADC_Deinit(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        /* Disable the ADC */
        MCAL_ADC_CONVERSION_Disable();
        
        /* Configure The interrupt */
        #if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
            Mcal_ADC_InterruptDisable();
        #elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE

        #endif        
        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_SelectChanal(const ADC_t *copyADC, ADC_chanal_select_t copyChanal) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        /* Configure The Default Channel */
        ADCON0bits.CHS = copyADC->AdcChanall;
        ADC_input_chanal_configuration(copyChanal);
                
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_StartConversion(const ADC_t *copyADC) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        MCAL_ADC_START_CONVERSION();
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_isConversionDone(const ADC_t *copyADC, uint8_t *copyConversionStatus) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionStatus ==NULL)) {
        
    }
    else {
        *copyConversionStatus = ((uint8_t)(!(ADCON0bits.GO_nDONE)));
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_ADC_getConversionResult(const ADC_t *copyADC, ADC_Resulte_t *copyConversionResult) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionResult ==NULL)) {
        
    }
    else {
        switch(copyADC->ResultFormat) {
            case ADC_RESULT_FORMAT_RIGHT : *copyConversionResult =  (ADC_Resulte_t)((ADRESH << 8)+(ADRESL));  break;
            case ADC_RESULT_FORMAT_LEFT  : *copyConversionResult =  (ADC_Resulte_t)(((ADRESH << 8)+(ADRESL)) >> 6); break;
        }        
        retValue = R_OK;
    }
    return retValue;      
}

Std_Return MCAL_ADC_getConversion_Blocking(const ADC_t *copyADC, ADC_chanal_select_t copyChanal, ADC_Resulte_t* copyConversionResult) {
    uint8_t retValue = R_ERROR;
    if((copyADC == NULL) && (copyConversionResult ==NULL)) {
        
    }
    else {
        retValue = MCAL_ADC_SelectChanal(copyADC, copyChanal);
        retValue = MCAL_ADC_StartConversion(copyADC);
        while(ADCON0bits.GO_nDONE);
        retValue = MCAL_ADC_getConversionResult(copyADC, copyConversionResult);
        retValue = R_OK;
    }
    return retValue;     
}

Std_Return MCAL_ADC_startConversion_Interrupt(const ADC_t *copyADC, ADC_chanal_select_t copyChanal) {
    uint8_t retValue = R_ERROR;
    if(copyADC == NULL) {
        
    }
    else {
        retValue = MCAL_ADC_SelectChanal(copyADC, copyChanal);
        retValue = MCAL_ADC_StartConversion(copyADC);
        retValue = R_OK;
    }
    return retValue;      
}

static inline void ADC_input_chanal_configuration(ADC_chanal_select_t copyChanal) {    
    switch(copyChanal) {
        case ADC_CHANAL_AN1  : SET_BIT(TRISA, _TRISA_RA0_POSN); break;
        case ADC_CHANAL_AN2  : SET_BIT(TRISA, _TRISA_RA1_POSN); break;
        case ADC_CHANAL_AN3  : SET_BIT(TRISA, _TRISA_RA2_POSN); break;
        case ADC_CHANAL_AN4  : SET_BIT(TRISA, _TRISA_RA3_POSN); break;
        case ADC_CHANAL_AN5  : SET_BIT(TRISA, _TRISA_RA5_POSN); break;
        case ADC_CHANAL_AN6  : SET_BIT(TRISE, _TRISE_RE0_POSN); break;
        case ADC_CHANAL_AN7  : SET_BIT(TRISE, _TRISE_RE1_POSN); break;
        case ADC_CHANAL_AN8  : SET_BIT(TRISE, _TRISE_RE2_POSN); break;
        case ADC_CHANAL_AN9  : SET_BIT(TRISB, _TRISB_RB2_POSN); break;
        case ADC_CHANAL_AN10 : SET_BIT(TRISB, _TRISB_RB3_POSN); break;
        case ADC_CHANAL_AN11 : SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case ADC_CHANAL_AN12 : SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        case ADC_CHANAL_AN13 : SET_BIT(TRISB, _TRISB_RB0_POSN); break;
    } 
}

static inline void ADC_SelectResultFormat(const ADC_t * copyADC) {
    switch(copyADC->ResultFormat) {
        case ADC_RESULT_FORMAT_RIGHT : MCAL_ADC_RESULT_RIGHT_FORMAT(); break;
        case ADC_RESULT_FORMAT_LEFT : MCAL_ADC_RESULT_LEFT_FORMAT(); break;
    }
}    

static inline void ADC_VolatgeReferance(const ADC_t * copyADC) { 
    switch(copyADC->VolatageRefrance) {
        case ADC_VOLTAGE_REF_ENABLE  : MCAL_ADC_VOLATGE_ENABLE(); break;
        case ADC_VOLTAGE_REF_DISABLE : MCAL_ADC_VOLATGE_DISABLE(); break;
    }
}

void ADC_ISR() {
    Mcal_ADC_ClearFlage();
    if(ADC_interruptHandler) {
        ADC_interruptHandler();
    }
}