/*
 * TIMER1_Init.h
 *
 *  Created on: Feb 10, 2023
 *      Author: Bunny
 */

#ifndef MCAL_TIMER1_TIMER1_INIT_H_
#define MCAL_TIMER1_TIMER1_INIT_H_






void TIMER1_vidInit(void);

void TIMER1_vidOCRAWrite(uint16 Copy_u16ValueOCRA);
void TIMER1_vidOCRBWrite(uint16 Copy_u16ValueOCRB);
void TIMER1_vidICRWrite(uint16 Copy_u16ValueICR);


void TIMER1_vidStart(void);
void TIMER1_vidStop(void);
void TIMER1_vidReset(void);


void TIMER1_vidINCAPFalling(void);
void TIMER1_vidINCAPRissing(void);
uint16 TIMER1_u16INCAPRead(void);


void (*TIMER1_OVF_INT)(void);
void (*TIMER1_COMPA_INT)(void);
void (*TIMER1_COMPB_INT)(void);
void (*TIMER1_CAP_INT)(void);


void TIMER1_vidOVRInterruptEnable(void);
void TIMER1_vidCOMPAInterruptEnable(void);
void TIMER1_vidCOMBInterruptEnable(void);
void TIMER1_vidCAPInterruptEnable(void);

void TIMER1_vidOVRInterruptDisable(void);
void TIMER1_vidCOMPAInterruptDisable(void);
void TIMER1_vidCOMBInterruptDisable(void);
void TIMER1_vidCAPInterruptDisable(void);


#endif /* MCAL_TIMER1_TIMER1_INIT_H_ */
