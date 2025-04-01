/*
 * spi_prog.c
 *
 *  Created on: Feb 3, 2023
 *      Author: Bunny
 */
#include "../../SERV/std_type.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"
#include "spi_private.h"
#include "spi_confg.h"
#include "spi_init.h"





void SPI_vidInit(){
	SET_BIT(SPCR,SPE);
#if SPI_DATA_ORDER == SPI_LSB
	SET_BIT(SPCR,DORD);
#elif SPI_DATA_ORDER == SPI_MSB
	CLR_BIT(SPCR,DORD);
#endif

#if SPI_MODE  ==  SPI_SLAVE
	CLR_BIT(SPCR,MSTR);
#elif SPI_MODE  ==   SPI_MASTER
	SET_BIT(SPCR,MSTR);
	SPI_PRESCALER;
#endif
	SET_BIT(SPCR,CPOL);
	SET_BIT(SPCR,CPHA);
}



uint8 SPI_u8Master(uint8 DataCopy){
	SPDR = DataCopy;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}
uint8 SPI_u8Slave(uint8 DataCopy){
	SPDR =DataCopy;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

