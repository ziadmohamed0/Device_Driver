/*
 * uart_private.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Bunny
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_



#define UDR        *((volatile uint8 *) 0x2C)
#define UCSRA      *((volatile uint8 *) 0x2B)
#define UCSRB      *((volatile uint8 *) 0x2A)
#define UCSRC      *((volatile uint8 *) 0x40)
#define UBRRH      *((volatile uint8 *) 0x40)
#define UBRRL      *((volatile uint8 *) 0x29)


/*------ UCSRA -------*/
#define UDRE     (uint8)5
#define TXC      (uint8)6
#define RXC      (uint8)7

/*------ UCSRB --------*/

#define RXEN  (uint8)4
#define TXEN  (uint8)3
#define UCSZ2 (uint8)2

/*------ UCSRC --------*/

#define URSEL  (uint8)7
#define UMSEL  (uint8)6
#define UPM1   (uint8)5
#define UPM0   (uint8)4
#define USBS   (uint8)3
#define UCSZ1  (uint8)2
#define UCSZ0  (uint8)1
#define UCPOL  (uint8)0




#endif /* MCAL_UART_UART_PRIVATE_H_ */
