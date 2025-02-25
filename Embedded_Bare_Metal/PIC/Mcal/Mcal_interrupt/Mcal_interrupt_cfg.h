/* 
 * File:   Mcal_interrupt_cfg.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:38 ?
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_Std_Types.h"
#include "Mcal_interrupt_gen_cfg.h"
#include "../Mcal_GPIO/Mcal_GPIO_init.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define MCAL_INTERRUPT_ENABLE                                   1
#define MCAL_INTERRUPT_DISABLE                                  0
#define MCAL_INTERRUPT_OCCUR                                    1
#define MCAL_INTERRUPT_NOT_OCCUR                                0
#define MCAL_INTERRUPT_PRIORETY_ENABLE                          1
#define MCAL_INTERRUPT_PRIORETY_DISABLE                         0
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Enable priority levels */
#define MCAL_INTERRUPT_PriorityLevelEnable(void)                (RCONbits.IPEN = 1)

/* @brief : Macros Disable priority levels */
#define MCAL_INTERRUPT_PriorityLevelDisable(void)               (RCONbits.IPEN = 0)

/* @brief : Macros Enable High priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptHighEnable(void)         (INTCONbits.GIEH = 1)

/* @brief : Macros Disable High priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptHighDisable(void)        (INTCONbits.GIEH = 0)

/* @brief : Macros Enable Low priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptLowEnable(void)          (INTCONbits.GIEL = 1)

/* @brief : Macros Disable Low priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptLowDisable(void)         (INTCONbits.GIEL = 0)

#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE

/* @brief : Macros Enable High priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptEnable(void)             (INTCONbits.GIE = 1)

/* @brief : Macros Disable High priority Global interrupt */
#define MCAL_INTERRUPT_GlobaleInterruptDisable(void)            (INTCONbits.GIE = 0)

/* @brief : Macros Enable Peripheral interrupt */
#define MCAL_INTERRUPT_PeripheralInterruptEnable(void)          (INTCONbits.PEIE = 1)

/* @brief : Macros Disable Peripheral interrupt */
#define MCAL_INTERRUPT_PeripheralInterruptDisable(void)         (INTCONbits.PEIE = 0)

#endif
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    INTERRUPT_PRIORETY_LOW,
    INTERRUPT_PRIORETY_HIGH        
}Interrupt_Priorety_cfg_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_INTERRUPT_CFG_H */

