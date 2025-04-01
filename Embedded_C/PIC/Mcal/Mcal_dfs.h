/* 
 * File:   Mcal_dfs.h
 * Author: s
 *
 * Created on 26 ??????, 2024, 02:38 ?
 */

#ifndef MCAL_DFS_H
#define	MCAL_DFS_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt/Mcal_external_interrupt.h"
#include "Mcal_interrupt/Mcal_internal_interrupt.h"
#include "Mcal_interrupt/Mcal_interrupt_manager.h"
#include "Mcal_GPIO/Mcal_GPIO_init.h"
#include "Mcal_EEPROM/Mcal_EEPROM_init.h"
#include "Mcal_ADC/Mcal_ADC_init.h"
#include "Mcal_Timer_0/Mcal_Timer_0_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Global Variables Start -------------------- */
/* -------------------- Global Variables End  -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* External interrupt INTx ISR Functions Definetions */
void INT0_isr(void);
void INT1_isr(void);
void INT2_isr(void);

/* External interrupt RBx ISR Functions Definetions */
void RB4_isr(void);
void RB5_isr(void);
void RB6_isr(void);
void RB7_isr(void);

/* Analog to Digital Converter ISR Functions Definetions */
void ADC_isr(void);
/* -------------------- API End -------------------- */

/* -------------------- peripherals init Start -------------------- */
    /* External Interrupt INTx */
Interrupt_INTx_t EX_INT0;
Interrupt_INTx_t EX_INT1;
Interrupt_INTx_t EX_INT2;

    /* External Interrupt RBx */
Interrupt_RBx_t RB_4;
Interrupt_RBx_t RB_5;
Interrupt_RBx_t RB_6;
Interrupt_RBx_t RB_7;

    /* ADC Variables return value */
uint16_t retADC1;
uint16_t retADC2;
uint16_t retADC3;
uint16_t retADC4;

    /* ADC Bits */
ADC_t adc1;
ADC_t adc2;
ADC_t adc3;
ADC_t adc4;
/* -------------------- peripherals init End -------------------- */

#endif	/* MCAL_DFS_H */

