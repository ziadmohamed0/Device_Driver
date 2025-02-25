/* 
 * File:   Mcal_interrupt_manager.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:35 ?
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8_t copySource);
void RB5_ISR(uint8_t copySource);
void RB6_ISR(uint8_t copySource);
void RB7_ISR(uint8_t copySource);
void ADC_ISR(void);
void Timer0_ISR(void);
/* -------------------- API End -------------------- */

#endif	/* MCAL_INTERRUPT_MANAGER_H */

