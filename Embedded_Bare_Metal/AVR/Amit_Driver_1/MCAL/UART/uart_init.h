/*
 * uart_init.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Bunny
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_

void uart_vidInit();
void uart_vidSendData(uint8 u8DataCopy);
uint8 uart_u8RecevieData();

#endif /* MCAL_UART_UART_INIT_H_ */
