/*
 * File:   Mcal_interrupt_manager.c
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:36 ?
 */


#include "Mcal_interrupt_manager.h"

static volatile uint8_t RB4_Flag = 1;
static volatile uint8_t RB5_Flag = 1;
static volatile uint8_t RB6_Flag = 1;
static volatile uint8_t RB7_Flag = 1;

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

void __interrupt() MCAL_InterruptManagerHigh(void) {
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.INT0IE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.INT0IF)) {
        INT0_ISR();
    }
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT2IF)) {
        INT2_ISR();
    }    
}

void __interrupt(low_priority) MCAL_InterruptManagerLow(void) {
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT1IF)) {
        INT1_ISR();
    }
}

#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE

void __interrupt() MCAL_InterruptManager(void) {
    /* ----------------------------- External interrupt INTx ISR Start ----------------------------- */
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.INT0IE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.INT0IF)) {
        INT0_ISR();
    }
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT1IF)) {
        INT1_ISR();
    }
    if((MCAL_INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (MCAL_INTERRUPT_OCCUR == INTCON3bits.INT2IF)) {
        INT2_ISR();
    }    
    /* ----------------------------- External interrupt INTx ISR End ----------------------------- */
    
    /* ----------------------------- External interrupt RBx ISR Start ----------------------------- */
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB4 == GPIO_Status_Low) && (RB4_Flag == 1)) {
        RB4_Flag = 0;
        RB4_ISR(0);
    }  
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB4 == GPIO_Status_High) && (RB4_Flag == 0)) {
        RB4_Flag = 1;
        RB4_ISR(1);
    }  
    
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB5 == GPIO_Status_Low) && (RB5_Flag == 1)) {
        RB5_Flag = 0;
        RB5_ISR(0);
    }  
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB5 == GPIO_Status_High) && (RB5_Flag == 0)) {
        RB5_Flag = 0;
        RB5_ISR(1);
    } 
    
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB6 == GPIO_Status_Low) && (RB6_Flag == 1)) {
        RB6_Flag = 0;
        RB6_ISR(0);
    }  
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB6 == GPIO_Status_High) && (RB6_Flag == 0)) {
        RB6_Flag = 1;
        RB6_ISR(1);
    }
    
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB7 == GPIO_Status_Low) && (RB7_Flag == 1)) {
        RB7_Flag = 0;
        RB7_ISR(0);
    }  
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.RBIE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.RBIF) && 
            (PORTBbits.RB7 == GPIO_Status_High) && (RB7_Flag == 0)) {
        RB7_Flag = 1;
        RB7_ISR(1);
    }
    /* ----------------------------- External interrupt RBx ISR End ----------------------------- */
    
    /* ----------------------------- ADC interrupt ISR Start ----------------------------- */
    if((MCAL_INTERRUPT_ENABLE == PIE1bits.ADIE) && (MCAL_INTERRUPT_OCCUR == PIR1bits.ADIF)) {
        ADC_ISR();
    }
    /* ----------------------------- ADC interrupt ISR End ----------------------------- */
    
    /* ----------------------------- Timer0 interrupt ISR Start ----------------------------- */
    if((MCAL_INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (MCAL_INTERRUPT_OCCUR == INTCONbits.TMR0IF)) {
        Timer0_ISR();
    }
    /* ----------------------------- Timer0 interrupt ISR End ----------------------------- */    
}

#endif