/*
 * ext_init.h
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */

#ifndef HAL_HEXT_INT_HEXT_INIT_H_
#define HAL_HEXT_INT_HEXT_INIT_H_


#define INT0    (uint8)0
#define INT1    (uint8)1
#define INT2    (uint8)2


#define FALLING   (uint8)0
#define RISSING   (uint8)1
#define LOW       (uint8)2
#define ANY_LOG   (uint8)3



void (*ISR_FUN_INT0)(void);
void (*ISR_FUN_INT1)(void);
void (*ISR_FUN_INT2)(void);

void HEXT_vidInit(uint8 u8ExtIntNum , uint8 u8ISRStCont);


#endif /* MCAL_EXT_EXT_INIT_H_ */
