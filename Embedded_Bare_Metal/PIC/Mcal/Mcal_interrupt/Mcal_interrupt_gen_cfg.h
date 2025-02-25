/* 
 * File:   Mcal_interrupt_gen_cfg.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:40 ?
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define INTERRUPT_ENABLE_FUTURE                             1     
#define INTERRUPT_DISABLE_FUTURE                            0
#define ADC_INTERRUPT_FUTUR_ENABLE                          1
#define ADC_INTERRUPT_FUTUR_DISABLE                         0
#define TIMER0_INTERRUPT_FUTUR_ENABLE                       1
#define TIMER0_INTERRUPT_FUTUR_DISABLE                      0

#define TIMER0_INTERRUPT_FUTUR                              TIMER0_INTERRUPT_FUTUR_ENABLE
#define ADC_INTERRUPT_FUTUR                                 ADC_INTERRUPT_FUTUR_ENABLE
#define INTERRUPT_PRIORETY_LEVELS_ENABLE                    INTERRUPT_DISABLE_FUTURE
#define EXTERNAL_INTERRUPT_INTx_ENABLE_FUTURE               INTERRUPT_ENABLE_FUTURE
#define EXTERNAL_INTERRUPT_OnChange_ENABLE_FUTURE           INTERRUPT_ENABLE_FUTURE

/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

