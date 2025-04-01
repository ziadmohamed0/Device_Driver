/*
 * TIMER_Init.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */

#ifndef HAL_HTIMER2_TIMER2_INIT_H_
#define HAL_HTIMER2_TIMER2_INIT_H_

void (*HTIMER2_OVF_INT)(void);

void (*HTIMER2_CTC_INT)(void);


void HTIMER2_vidInit(void);

void HTIMER2_vidStart(void);
void HTIMER2_vidStop(void);



void HTIMER2_vidWriteOVRTCNT2(uint8 Copy_Start_Value);
void HTIMER2_vidWriteCOMPOCR2(uint8 Copy_Start_Value);




void HTIMER2_vidOVRInterruptEnable(void);
void HTIMER2_vidOVRInterruptDisable(void);
void HTIMER2_vidCOMPInterruptEnable(void);
void HTIMER2_vidCOMPInterruptDisable(void);


#endif /* HAL_TIMER_TIMER_INIT_H_ */
