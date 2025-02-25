/*
 * uart_prog.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Bunny
 */

#include "../../Serv/std.h"
#include "../../Serv/bit_math.h"
#include "uart_private.h"
#include "uart_confg.h"
#include "uart_init.h"

void uart_vidInit(){
	 UBRRL = baud_rate_select ;                   /* Set baud rate */

  #if    (Mode_Select == Synchronous_Operation)
         SET_BIT(UCSRC,UMSEL);
  #elif  (Mode_Select == Asynchronous_Operation)
         CLEAR_BIT(UCSRC,UMSEL);
  #endif

	#if   (Parity_Mode==Even_Parity)
	      SET_BIT(UCSRC,UPM1);
	#elif (Parity_Mode==Odd_Parity )
	      SET_BIT(UCSRC,UPM1);
		  SET_BIT(UCSRC,UPM0);
   #endif
   #if   (Stop_Bit_Select==_2_bit)
         SET_BIT(UCSRC,USBS);
  #elif  (Stop_Bit_Select==_1_bit)
         CLEAR_BIT(UCSRC,USBS);
   #endif

   #if (Data_bits==_5_bit)             //number of data bits
       CLEAR_BIT(UCSRC,UCSZ0);
       CLEAR_BIT(UCSRC,UCSZ1);
	   CLEAR_BIT(UCSRC,UCSZ2);
  #elif 	(Data_bits==_6_bit)
      SET_BIT(UCSRC,UCSZ0);
      CLEAR_BIT(UCSRC,UCSZ1);
      CLEAR_BIT(UCSRC,UCSZ2);
  #elif 	(Data_bits==_7_bit)
     CLEAR_BIT(UCSRC,UCSZ0);
     SET_BIT(UCSRC,UCSZ1);
     CLEAR_BIT(UCSRC,UCSZ2);
	 #elif 	(Data_bits==_8_bit)
	 SET_BIT(UCSRC,UCSZ0);
	 SET_BIT(UCSRC,UCSZ1);
	 CLEAR_BIT(UCSRC,UCSZ2);
	  #elif 	(Data_bits==_9_bit)
	  SET_BIT(UCSRC,UCSZ0);
	  SET_BIT(UCSRC,UCSZ1);
	  SET_BIT(UCSRC,UCSZ2);
   #endif
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);


 }
 uint8 uart_u8RecevieData(){
	 while(GET(UCSRA,RXC) == 0);	    /* Wait for data to be received */
	 return UDR;                      // why ?? /* Get and return received data from buffer */
 }
 void uart_vidSendData(uint8 u8DataCopy){
	 while(GET(UCSRA,UDRE) == 0);  /* Wait for empty transmit buffer */
	 UDR = u8DataCopy;       /* Put data into buffer, sends the data */
 }
