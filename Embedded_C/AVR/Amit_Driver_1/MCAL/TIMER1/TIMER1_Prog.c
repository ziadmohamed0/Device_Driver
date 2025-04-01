/*
 * TIMER1_Prog.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "TIMER1_Praivate.h"
#include "TIMER1_Config.h"
#include "TIMER1_Init.h"


ISR(__vector_6){
	TIMER1_CAP_INT();
}
ISR(__vector_7){
	TIMER1_COMPA_INT();
}
ISR(__vector_8){
	TIMER1_COMPB_INT();
}
ISR(__vector_9){
	TIMER1_OVF_INT();
}



void TIMER1_vidOCRAWrite(uint16 Copy_u16ValueOCR){
	OCR1A = Copy_u16ValueOCR;
}
void TIMER1_vidOCRBWrite(uint16 Copy_u16ValueOCRB){
	OCR1B = Copy_u16ValueOCRB ;
}
void TIMER1_vidICRWrite(uint16 Copy_u16ValueICR){
	ICR1 = Copy_u16ValueICR;
}


void TIMER1_vidInit(void){

	TIMER1_MODE;
//	TCCR1A &= 0x0F;
	TCCR1A |= TIMER1_COMP_OUTPUT;
}




void TIMER1_vidINCAPFalling(void){
	CLEAR_BIT(TCCR1B,ICES1);
}
void TIMER1_vidINCAPRissing(void){
	SET_BIT(TCCR1B,ICES1);
}

uint16 TIMER1_u16INCAPRead(void){
	return ICR1;
}

void TIMER1_vidStart(void){
	TCCR1B |= TIMER1_CLOCK_SELECT;
}
void TIMER1_vidStop(void){
	TCCR1B &= TIMER1_CLOCK_STOP;
}

void TIMER1_vidOVRInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_vidCOMPAInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE1A);
}
void TIMER1_vidCOMBInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,OCIE1B);
}
void TIMER1_vidCAPInterruptEnable(void){
	SET_BIT(SREG,GIE);
	SET_BIT(TIMSK,TICIE1);
}

void TIMER1_vidOVRInterruptDisable(void){
	CLEAR_BIT(TIMSK,TOIE1);
}
void TIMER1_vidCOMPAInterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE1A);
}
void TIMER1_vidCOMBInterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE1B);
}
void TIMER1_vidCAPInterruptDisable(void){
	CLEAR_BIT(TIMSK,TICIE1);
}

