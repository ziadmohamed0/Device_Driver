/* 
 * File:   Mcal_Timer_0_init.h
 * Author: s
 *
 * Created on November 17, 2024, 7:48 PM
 */

#ifndef MCAL_TIMER_0_INIT_H
#define	MCAL_TIMER_0_INIT_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_dfs.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define Timer0_Prescaler_Enable                         1U
#define Timer0_Prescaler_Disable                        0U

#define Timer0_Config_Rising_Edge_cfg                   1U
#define Timer0_Config_Falling_Edge_cfg                  0U

#define Timer0_Timer_Mode                               1U
#define Timer0_Counter_Mode                             0U

#define Timer0_8Bit_Register_Mode                       1U
#define Timer0_16Bit_Register_Mode                      0U
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define MCAL_TIMER0_ENABLE(void)                                (T0CONbits.TMR0ON = 1)
#define MCAL_TIMER0_DISABLE(void)                               (T0CONbits.TMR0ON = 0 )

#define MCAL_TIMER0_PRESCALER_ENABLE(void)                      (T0CONbits.PSA = 0)
#define MCAL_TIMER0_PRESCALER_DISABLE(void)                     (T0CONbits.PSA = 1)

#define MCAL_TIMER0_RISING_EDGE_ENABLE(void)                    (T0CONbits.T0SE = 0)
#define MCAL_TIMER0_FALLING_EDGE_ENABLE(void)                   (T0CONbits.T0SE = 1)

#define MCAL_TIMER0_TIMER_MODE_ENABLE(void)                     (T0CONbits.T0CS = 0)
#define MCAL_TIMER0_COUNTER_MODE_ENABLE(void)                   (T0CONbits.T0CS = 1)

#define MCAL_TIMER0_8BIT_REGISTER_MODE_ENABLE(void)             (T0CONbits.T08BIT = 1)
#define MCAL_TIMER0_16BIT_REGISTER_MODE_ENABLE(void)            (T0CONbits.T08BIT = 0)
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    TIMR0_PRESCALER_DIV_BY_2,
    TIMR0_PRESCALER_DIV_BY_4,
    TIMR0_PRESCALER_DIV_BY_8,
    TIMR0_PRESCALER_DIV_BY_16,
    TIMR0_PRESCALER_DIV_BY_32,
    TIMR0_PRESCALER_DIV_BY_64,
    TIMR0_PRESCALER_DIV_BY_128,
    TIMR0_PRESCALER_DIV_BY_256,           
}Timer0_Prescaler_t;

typedef struct {
#if TIMER0_INTERRUPT_FUTUR == TIMER0_INTERRUPT_FUTUR_ENABLE
    void (* Timer0_InterruptHandler)(void);
    Interrupt_Priorety_cfg_t Priorety;
#endif
    uint8_t             Presacler_Enable : 1;
    uint16_t            Timer0_preloaValue;
    uint8_t             Timer0_Counter_Edge : 1;
    uint8_t             Timer0_Mode : 1;
    uint8_t             Timer0_Register_Size : 1;
    Timer0_Prescaler_t  Prescaler;
    uint8_t             timer0_reserved : 4;
}Timer0_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return MCAL_TIMER0_init(const Timer0_t *copyTimer);
Std_Return MCAL_TIMER0_DeInit(const Timer0_t *copyTimer);
Std_Return MCAL_TIMER0_writeValue(const Timer0_t *copyTimer, uint16_t copyValue);
Std_Return MCAL_TIMER0_readValue(const Timer0_t *copyTimer, uint16_t *copyValue);
/* -------------------- API End -------------------- */

#endif	/* MCAL_TIMER_0_INIT_H */

