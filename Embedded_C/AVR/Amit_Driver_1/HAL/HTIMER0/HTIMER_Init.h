/*
 * TIMER_Init.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */

#ifndef HAL_HTIMER0_HTIMER_INIT_H_
#define HAL_HTIMER0_HTIMER_INIT_H_

void (*HTIMER0_OVF_INT)(void);

void (*HTIMER0_CTC_INT)(void);


void HTIMER0_vidInit(void);

void HTIMER0_vidStart(void);
void HTIMER0_vidStop(void);



void HTIMER0_vidWriteOVRTCNT0(uint8 Copy_Start_Value);
void HTIMER0_vidWriteCOMPOCR0(uint8 Copy_Start_Value);



void HTIMER0_vidOVRInterruptEnable(void);
void HTIMER0_vidOVRInterruptDisable(void);


void HTIMER0_vidCOMPInterruptEnable(void);
void HTIMER0_vidCOMPInterruptDisable(void);


#endif /* MCAL_TIMER_TIMER_INIT_H_ */
