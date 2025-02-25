/*
 * TIMER_Prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/TIMER/TIMER_Praivate.h"
#include "../../MCAL/TIMER/TIMER_Config.h"
#include "HTIMER_Init.h"


ISR(__vector_11){
	HTIMER0_OVF_INT();
}

ISR(__vector_10){
	HTIMER0_CTC_INT();//
}


void HTIMER0_vidInit(void){

#if TIMER_MODE_WAVE == NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER_MODE_WAVE == PWM_MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#elif TIMER_MODE_WAVE == FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCCR0 |= TIMER_COMP_OUTPUT_MODE;
#endif



}


void HTIMER0_vidStart(void){
	TCCR0 |= TIMER_SELECT_ENABLE;
}
void HTIMER0_vidStop(void){
	TCCR0 &= TIMER0_CLOCK_STOP;
}

void HTIMER0_vidWriteOVRTCNT0(uint8 Copy_Start_Value){
	TCNT0 = Copy_Start_Value;
}

void HTIMER0_vidWriteCOMPOCR0(uint8 Copy_Start_Value){
	OCR0 = Copy_Start_Value;
}

void HTIMER0_vidOVRInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE0);
}
void HTIMER0_vidOVRInterruptDisable(void){
	CLR_BIT(TIMSK,TOIE0);
}
void HTIMER0_vidCOMPInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE0);
}
void HTIMER0_vidCOMPInterruptDisable(void){
	CLR_BIT(TIMSK,OCIE0);
}
