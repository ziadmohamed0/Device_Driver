/*
 * TIMER_Config.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_


/******Timer Waveform Generation Mode******/
/*
 * -NORMAL_MODE   -PWM_MODE (Phase Correct)   -CTC_MODE    -FAST_PWM_MODE
 * */
/***** TIMER MODE *****/
#define NORMAL_MODE    0U
#define PWM_MODE       1U
#define CTC_MODE       2U
#define FAST_PWM_MODE  3U

#define TIMER2_MODE_WAVE       NORMAL_MODE
#define TIMER2_CLOCK_STOP     (uint8)0xF8

/***** Clock Select ENABLE TIMER*****/
/*---TIMER SELSET FACTOR---*/
#define TIMER2_FACTOR_NO            (uint8)0x00    // 0U   //CLOCK STOPED No_Clock_Source
#define TIMER2_FACTOR_1             (uint8)0x01    // 1U
#define TIMER2_FACTOR_8             (uint8)0x02    // 2U
#define TIMER2_FACTOR_32            (uint8)0x03    // 3U
#define TIMER2_FACTOR_64            (uint8)0x04    // 4U
#define TIMER2_FACTOR_128           (uint8)0x05    // 5U
#define TIMER2_FACTOR_256           (uint8)0x06    // 6U   //using Counter with S.W
#define TIMER2_FACTOR_1024          (uint8)0x07    // 7U   //using Counter with S.W

#define TIMER2_SELECT_ENABLE         TIMER2_FACTOR_128

/*---Compare Output Mode USED In PWM Mode---*/
/******- START_CLEAR_COMP - TOGGLE_CTC_MODE - START_SET_COMP - NURMAL_MODE_OUTPUT******/
/*---Compare Output Mode USED In PWM Mode---*/

#define NURMAL_MODE_OUTPUT       (( 0 << COM21) | (0 << COM20))         //(0U << COM00)
#define TOGGLE_CTC_MODE          (( 0 << COM21) | (1 << COM20))
#define START_CLEAR_COMP         (( 1 << COM21) | (0 << COM20))        //(2U << COM00)
#define START_SET_COMP           (( 1 << COM21) | (1 << COM20))         //(3U << COM00)


#define TIMER2_COMP_OUTPUT_MODE   NURMAL_MODE_OUTPUT



/*-------Timer Clock Source-------*/
#define TIEMR2_INT    0
#define TIMER2_EXTR   1

#define TIMER2_CLK_SOURCE  TIMER2_EXTR


#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
