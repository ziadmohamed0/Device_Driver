/* 
 * File:   Mcal_internal_interrupt.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:34 ?
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
/* @brief : Macros Enable ADC interrupt */
#define Mcal_ADC_InterruptEnable(void)                  (PIE1bits.ADIE = 1)
/* @brief : Macros Disable ADC interrupt */
#define Mcal_ADC_InterruptDisable(void)                 (PIE1bits.ADIE = 0)
/* @brief : Macros Clear Flag ADC interrupt */
#define Mcal_ADC_ClearFlage(void)                       (PIR1bits.ADIF = 0)
//#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
/* @brief : Macros Set high priority ADC interrupt */
#define Mcal_ADC_HighPrioritySet(void)                  (IPR1bits.ADIP = 1)
/* @brief : Macros Set low priority ADC interrupt */
#define Mcal_ADC_LowPrioritySet(void)                   (IPR1bits.ADIP = 0)
#endif

#if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
/* @brief : Macros Enable Timer0 interrupt */
#define Mcal_TIMER0_InterruptEnable(void)               (INTCONbits.TMR0IE = 1)
/* @brief : Macros Disable Timer0 interrupt */
#define Mcal_TIMER0_InterruptDisable(void)              (INTCONbits.TMR0IE = 0)
/* @brief : Macros Clear Flag Timer0 interrupt */
#define Mcal_TIMER0_ClearFlage(void)                    (INTCONbits.TMR0IF = 0)
#endif

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
/* @brief : Macros Set high priority Timer0 interrupt */
#define Mcal_TIMER0_HighPrioritySet(void)               (INTCON2bits.TMR0IP = 1)
/* @brief : Macros Set low priority Timer0 interrupt */
#define Mcal_TIMER0_LowPrioritySet(void)                (INTCON2bits.TMR0IP = 0)
#endif
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_INTERNAL_INTERRUPT_H */

