/*
 * Timer1_prog.c
 *
 *  Created on: Jan 7, 2025
 *      Author: s
 */
#include "Timer1_init.h"


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
	CLR_BIT(TCCR1B,ICES1);
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
	CLR_BIT(TIMSK,TOIE1);
}
void TIMER1_vidCOMPAInterruptDisable(void){
	CLR_BIT(TIMSK,OCIE1A);
}
void TIMER1_vidCOMBInterruptDisable(void){
	CLR_BIT(TIMSK,OCIE1B);
}
void TIMER1_vidCAPInterruptDisable(void){
	CLR_BIT(TIMSK,TICIE1);
}
