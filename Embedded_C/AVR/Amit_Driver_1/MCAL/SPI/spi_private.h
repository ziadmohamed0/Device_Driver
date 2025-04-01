/*
 * spi_private.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bunny
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_



#define SPCR_ADD       (0x2D)
#define SPSR_ADD       (0x2E)
#define SPDR_ADD       (0x2F)

#define SPCR           (*(volatile uint8 *) SPCR_ADD)
#define SPSR           (*(volatile uint8 *) SPSR_ADD)
#define SPDR           (*(volatile uint8 *) SPDR_ADD)


//typedef enum {
//	SPR0 = 0 ,
//	SPR1     ,
//	CPHA     ,
//	CPOL     ,
//	MSTR     ,
//	DORD     ,
//	SPE      ,
//	SPIE
//}SPI_SPCR;

/* SPCR Refister */

#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

/*  SPSR Register BIT*/

#define SPI2X     0
#define WCOL      6
#define SPIF      7



#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
