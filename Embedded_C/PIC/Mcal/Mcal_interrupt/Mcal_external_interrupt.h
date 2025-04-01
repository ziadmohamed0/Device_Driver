/* 
 * File:   Mcal_external_interrupt.h
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:34 ?
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* -------------------- Include Start -------------------- */
#include "Mcal_interrupt_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#if EXTERNAL_INTERRUPT_INTx_ENABLE_FUTURE == INTERRUPT_ENABLE_FUTURE

        /* @groupMacros : INT0 interrupt */
/* @brief : Macros Enable External interrupt 0 */
#define MCAL_EX_INT0_InterruptEnable(void)                      (INTCONbits.INT0IE = 1)
/* @brief : Macros Disable External interrupt 0 */
#define MCAL_EX_INT0_InterruptDisable(void)                     (INTCONbits.INT0IE = 0)
/* @brief : Macros Clear Flag External interrupt 0 */
#define MCAL_EX_INT0_clearInterruptFlage(void)                  (INTCONbits.INT0IF = 0)
/* @brief : Macros Set Rising Age External interrupt 0 */
#define MCAL_EX_INT0_rissingSet(void)                           (INTCON2bits.INTEDG0 = 1)
/* @brief : Macros Set Falling Age External interrupt 0 */
#define MCAL_EX_INT0_fallingSet(void)                           (INTCON2bits.INTEDG0 = 0)

        /* @groupMacros : INT1 interrupt */
/* @brief : Macros Enable External interrupt 1 */
#define MCAL_EX_INT1_InterruptEnable(void)                      (INTCON3bits.INT1IE = 1)
/* @brief : Macros Disable External interrupt 1 */
#define MCAL_EX_INT1_InterruptDisable(void)                     (INTCON3bits.INT1IE = 0)
/* @brief : Macros Clear Flag External interrupt 1 */
#define MCAL_EX_INT1_clearInterruptFlage(void)                  (INTCON3bits.INT1IF = 0)
/* @brief : Macros Set Rising Age External interrupt 1 */
#define MCAL_EX_INT1_rissingSet(void)                           (INTCON2bits.INTEDG1 = 1)
/* @brief : Macros Set Falling Age External interrupt 1 */
#define MCAL_EX_INT1_fallingSet(void)                           (INTCON2bits.INTEDG1 = 0)

        /* @groupMacros : INT2 interrupt */
/* @brief : Macros Enable External interrupt 2 */
#define MCAL_EX_INT2_InterruptEnable(void)                      (INTCON3bits.INT2IE = 1)
/* @brief : Macros Disable External interrupt 2 */
#define MCAL_EX_INT2_InterruptDisable(void)                     (INTCON3bits.INT2IE = 0)
/* @brief : Macros Clear Flag External interrupt 2 */
#define MCAL_EX_INT2_clearInterruptFlage(void)                  (INTCON3bits.INT2IF = 0)
/* @brief : Macros Set Rising Age External interrupt 2 */
#define MCAL_EX_INT2_rissingSet(void)                           (INTCON2bits.INTEDG2 = 1)
/* @brief : Macros Set Falling Age External interrupt 2 */
#define MCAL_EX_INT2_fallingSet(void)                           (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Set high priority External interrupt 1 */
#define MCAL_EX_INT1_HighPrioritySet()                      (INTCON3bits.INT1IP = 1)

/* @brief : Macros Set low priority External interrupt 1 */
#define MCAL_EX_INT1_LowPrioritySet()                       (INTCON3bits.INT1IP = 0)

/* @brief : Macros Set high priority External interrupt 2 */
#define MCAL_EX_INT2_HighPrioritySet()                      (INTCON3bits.INT2IP = 1)
/* @brief : Macros Set low priority External interrupt 2 */
#define MCAL_EX_INT2_LowPrioritySet()                       (INTCON3bits.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_ENABLE_FUTURE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Enable External interrupt Port B */
#define MCAL_RBx_InterruptEnable()                          (INTCONbits.RBIE = 1)

/* @brief : Macros Disable External interrupt Port B */
#define MCAL_RBx_InterruptDisable()                         (INTCONbits.RBIE = 0)

/* @brief : Macros Clear Flag External interrupt Port B */
#define MCAL_RBx_clearInterruptFlage()                      (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE

/* @brief : Macros Set high priority External interrupt Port B */
#define MCAL_EX_RBx_HighPrioritySet()                      (INTCON2bits.RBIP = 1)
/* @brief : Macros Set low priority External interrupt Port B */
#define MCAL_EX_RBx_LowPrioritySet()                       (INTCON2bits.RBIP  = 0)

#endif

#endif /* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
typedef enum {
    INTERRUPT_EDGE_FALLING,
    INTERRUPT_EDGE_RISING
}Interrupt_INTx_edge_t;

typedef enum {
    INTERRUPT_EXTERNAL_INT0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}Interrupt_INTx_src_t;

typedef struct {
    void (* EX_InterruptHandler)(void);
    Pin_cfg_t                   MCU_Pin;
    Interrupt_INTx_edge_t       Edge;
    Interrupt_INTx_src_t        Source;
    Interrupt_Priorety_cfg_t    Priorety;
}Interrupt_INTx_t;

typedef struct {
    void (* EX_InterruptHandler_High)(void);
    void (* EX_InterruptHandler_Low)(void);
    Pin_cfg_t                   MCU_Pin;
    Interrupt_Priorety_cfg_t    Priorety;
}Interrupt_RBx_t;
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
Std_Return MCAL_INTERRUPT_INTx_init(const Interrupt_INTx_t *copyINTx);
Std_Return MCAL_INTERRUPT_INTx_DeInit(const Interrupt_INTx_t *copyINTx);

Std_Return MCAL_INTERRUPT_RBx_init(const Interrupt_RBx_t *copyRBx);
Std_Return MCAL_INTERRUPT_RBx_DeInit(const Interrupt_RBx_t *copyRBx);

/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

