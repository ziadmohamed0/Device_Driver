/*
 * TIMER_Prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/TIMER2/TIMER2_Config.h"
#include "../../MCAL/TIMER2/TIMER2_Praivate.h"
#include "HTIMER2_Init.h"

ISR(__vector_5){
	HTIMER2_OVF_INT();
}

ISR(__vector_4){
	HTIMER2_CTC_INT();
}


void HTIMER2_vidInit(void){

#if TIMER2_CLK_SOURCE == TIEMR2_INT
	CLEAR_BIT(ASSR,AS2);
#elif TIMER2_CLK_SOURCE == TIMER2_EXTR
	SET_BIT(ASSR,AS2);
#endif


#if TIMER2_MODE_WAVE == NORMAL_MODE
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
#elif TIMER2_MODE_WAVE == PWM_MODE
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#elif TIMER2_MODE_WAVE == CTC_MODE
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#elif TIMER2_MODE_WAVE == FAST_PWM_MODE
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	TCCR2 |= TIMER2_COMP_OUTPUT_MODE;
#endif

}


void HTIMER2_vidStart(void){
	TCCR2 |= TIMER2_SELECT_ENABLE;
}
void HTIMER2_vidStop(void){
	TCCR2 &= TIMER2_CLOCK_STOP;
}


void HTIMER2_vidWriteOVRTCNT0(uint8 Copy_Start_Value){
	TCNT2 = Copy_Start_Value;
}

void HTIMER2_vidWriteCOMPOCR0(uint8 Copy_Start_Value){
	OCR2 = Copy_Start_Value;
}




void HTIMER2_vidOVRInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE2);
}
void HTIMER2_vidOVRInterruptDisable(void){
	CLR_BIT(TIMSK,TOIE2);
}
void HTIMER2_vidCOMPInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE2);
}
void HTIMER2_vidCOMPInterruptDisable(void){
	CLR_BIT(TIMSK,OCIE2);
}
