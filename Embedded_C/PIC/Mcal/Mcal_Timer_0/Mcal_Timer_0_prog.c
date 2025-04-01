/*
 * File:   Mcal_Timer_0_prog.c
 * Author: s
 *
 * Created on November 17, 2024, 7:49 PM
 */


#include "Mcal_Timer_0_init.h"

static inline void Timer0_prescaler_config(const Timer0_t *copyTimer);
static inline void Timer0_Mode_config(const Timer0_t *copyTimer);
static inline void Timer0_Register_Size(const Timer0_t *copyTimer);
static uint16_t Timer0_Preloaded = Zero_init;

#if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
static void (*Timer0_interruptHandler)(void) = NULL;
#endif

Std_Return MCAL_TIMER0_init(const Timer0_t *copyTimer) {
    uint8_t retValue = R_ERROR;
    if(copyTimer == NULL) {
        retValue = R_ERROR;
    }
    else {
        MCAL_TIMER0_DISABLE();
        Timer0_prescaler_config(copyTimer); 
        Timer0_Mode_config(copyTimer); 
        Timer0_Register_Size(copyTimer);
        TMR0H = (copyTimer->Timer0_preloaValue) >> 8;
        TMR0L = (uint8_t)(copyTimer->Timer0_preloaValue) ;
        Timer0_Preloaded = copyTimer->Timer0_preloaValue;
#if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
        MCAL_INTERRUPT_GlobaleInterruptEnable();
        MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif 
        Mcal_TIMER0_InterruptEnable();
        Mcal_TIMER0_ClearFlage();
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
        MCAL_INTERRUPT_PriorityLevelEnable();
        switch(copyTimer->Priorety) {
            case INTERRUPT_PRIORETY_LOW:  
                Mcal_TIMER0_LowPrioritySet();
                MCAL_INTERRUPT_GlobaleInterruptLowEnable();
                break;
            case INTERRUPT_PRIORETY_HIGH: 
                Mcal_TIMER0_HighPrioritySet(); 
                MCAL_INTERRUPT_GlobaleInterruptHighEnable();
                break;
        }
#endif
        Timer0_interruptHandler = copyTimer->Timer0_InterruptHandler;
 #endif
        MCAL_TIMER0_ENABLE();
        retValue = R_OK;
    }
    return retValue;
}

Std_Return MCAL_TIMER0_DeInit(const Timer0_t *copyTimer) {
    uint8_t retValue = R_ERROR;
    if(copyTimer == NULL) {
        retValue = R_ERROR;
    }
    else {
        MCAL_TIMER0_DISABLE();
        #if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
        Mcal_TIMER0_InterruptDisable();
        #endif        
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_TIMER0_writeValue(const Timer0_t *copyTimer, uint16_t copyValue) {
    uint8_t retValue = R_ERROR;
    if(copyTimer == NULL) {
        retValue = R_ERROR;
    }
    else {
        TMR0H = (copyValue) >> 8;
        TMR0L = (uint8_t)(copyValue) ;
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_TIMER0_readValue(const Timer0_t *copyTimer, uint16_t *copyValue) {
    uint8_t retValue = R_ERROR;
    uint8_t timer0L = Zero_init;
    uint8_t timer0H = Zero_init;
    if((copyTimer == NULL) && (copyTimer == NULL)) {
        retValue = R_ERROR;
    }
    else {
        timer0L = TMR0L;
        timer0H = TMR0H;
        *copyValue = (uint8_t)((timer0H << 8) + timer0L);
        retValue = R_OK;
    }
    return retValue;    
}


#if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
void Timer0_ISR(void) {
    Mcal_TIMER0_ClearFlage();
    TMR0H = (Timer0_Preloaded) >> 8;
    TMR0L = (uint8_t)(Timer0_Preloaded) ;
    if(Timer0_interruptHandler) {
        Timer0_interruptHandler();
    }
}
#endif

static inline void Timer0_prescaler_config(const Timer0_t *copyTimer) {
    if(copyTimer->Presacler_Enable == Timer0_Prescaler_Enable) {
        MCAL_TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS = copyTimer->Prescaler;
    }
    else if(copyTimer->Presacler_Enable == Timer0_Prescaler_Disable) {
        MCAL_TIMER0_PRESCALER_DISABLE();
    }
    else {
        /* Nothing */
    }
}

static inline void Timer0_Mode_config(const Timer0_t *copyTimer) {
    if(copyTimer->Timer0_Mode == Timer0_Timer_Mode) {
        MCAL_TIMER0_TIMER_MODE_ENABLE();
    }
    else if(copyTimer->Timer0_Mode == Timer0_Counter_Mode) {
        MCAL_TIMER0_COUNTER_MODE_ENABLE();
        if(copyTimer->Timer0_Counter_Edge == Timer0_Config_Rising_Edge_cfg) {
            MCAL_TIMER0_RISING_EDGE_ENABLE();
        }
        else if (copyTimer->Timer0_Counter_Edge == Timer0_Config_Falling_Edge_cfg) {
            MCAL_TIMER0_FALLING_EDGE_ENABLE();
        }
        else {
            /* Nothing */
        }
    }
    else {
        /* Nothing */
    }
}

static inline void Timer0_Register_Size(const Timer0_t *copyTimer) {
    if(copyTimer->Timer0_Register_Size == Timer0_8Bit_Register_Mode) {
        MCAL_TIMER0_8BIT_REGISTER_MODE_ENABLE();
    }
    else if (copyTimer->Timer0_Register_Size == Timer0_16Bit_Register_Mode) {
        MCAL_TIMER0_16BIT_REGISTER_MODE_ENABLE();
    }
    else {
        /* Nothing */
    }
}