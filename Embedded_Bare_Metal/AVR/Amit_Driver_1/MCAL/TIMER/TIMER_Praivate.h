/*
 * TIMER_Praivate.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Bunny
 */

#ifndef MCAL_TIMER_TIMER_PRAIVATE_H_
#define MCAL_TIMER_TIMER_PRAIVATE_H_


#define ISR(vector)  															\
	void vector(void)	__attribute__((signal,used,externally_visible));		\
	void vector(void)

#define TCCR0_ADDRESS  (0x53)
#define TCNT0_ADDRESS  (0x52)
#define OCR0_ADDRESS   (0x5C)
#define TIMSK_ADDRESS  (0x59)
#define TIFR_ADDRESS   (0x58)


#define TCCR0   *((volatile uint8 *) TCCR0_ADDRESS )
#define TCNT0   *((volatile uint8 *) TCNT0_ADDRESS )
#define OCR0    *((volatile uint8 *) OCR0_ADDRESS  )
#define TIMSK   *((volatile uint8 *) TIMSK_ADDRESS )
#define TIFR    *((volatile uint8 *) TIFR_ADDRESS  )
#define SREG    *((volatile uint8 *) 0x5F)//


typedef enum {
	CS00 = 0 ,
	CS01     ,
	CS02     ,
	WGM01    ,
	COM00    ,
	COM01    ,
	WGM00    ,
	FOC0
}TCCR0_BIT_Reg;

#define TOIE0    (uint8)0
#define OCIE0    (uint8)1





#define GIE   7//








#endif /* MCAL_TIMER_TIMER_PRAIVATE_H_ */
