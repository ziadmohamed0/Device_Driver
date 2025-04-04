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

#define TIMER_MODE_WAVE       CTC_MODE

#define TIMER0_CLOCK_STOP     (uint8)0xF8//

/***** Clock Select ENABLE TIMER*****/


/*---TIMER SELSET FACTOR---*/
#define TIMER_FACTOR_NO                    (uint8)0x00    // 0U      //CLOCK STOPED No_Clock_Source
#define TIMER_FACTOR_1                     (uint8)0x01    // 1U
#define TIMER_FACTOR_8                     (uint8)0x02    // 2U
#define TIMER_FACTOR_64                    (uint8)0x03    // 3U
#define TIMER_FACTOR_256                   (uint8)0x04    // 4U
#define TIMER_FACTOR_1024                  (uint8)0x05    // 5U
#define TIMER_FACTOR_EXT_FALLING_PIN_T0    (uint8)0x06    // 6U   //using Counter with S.W
#define TIMER_FACTOR_EXT_RISING_PIN_T0     (uint8)0x07    // 7U   //using Counter with S.W

#define TIMER_SELECT_ENABLE         TIMER_FACTOR_1024

/*---Compare Output Mode USED In PWM Mode---*/
/******- START_CLEAR_COMP - TOGGLE_CTC_MODE - START_SET_COMP - NURMAL_MODE_OUTPUT******/

/*---Compare Output Mode USED In PWM Mode---*/

#define NURMAL_MODE_OUTPUT       (( 0 << COM01) | (0 << COM00))         //(0U << COM00)
#define TOGGLE_CTC_MODE          (( 0 << COM01) | (1 << COM00))
#define START_CLEAR_COMP         (( 1 << COM01) | (0 << COM00))        //(2U << COM00)
#define START_SET_COMP           (( 1 << COM01) | (1 << COM00))         //(3U << COM00)


#define TIMER_COMP_OUTPUT_MODE   TOGGLE_CTC_MODE


#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
