/*
 * bcd_init.h
 *
 *  Created on: Nov 24, 2023
 *      Author: Bunny
 */

#ifndef HAL_BCD_BCD_INIT_H_
#define HAL_BCD_BCD_INIT_H_


//#define ENABLE     (uint8)1
//#define DISABLE    (uint8)0

#define EN1        (uint8)0
#define EN2        (uint8)1

void BCD_vidInit();

void BCD_vidDisply(uint8 Copyu8Num);

//void BCD_vidEnDis(uint8 Copyu8Sel,uint8 Copyu8Stat);

void BCD_vidEnable(uint8 Copyu8Sel);
#endif /* HAL_BCD_BCD_INIT_H_ */
