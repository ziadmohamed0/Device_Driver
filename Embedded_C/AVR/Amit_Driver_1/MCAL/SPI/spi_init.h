/*
 * spi_init.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bunny
 */

#ifndef MCAL_SPI_SPI_INIT_H_
#define MCAL_SPI_SPI_INIT_H_


void SPI_vidInit();
uint8 SPI_u8Master(uint8 DataCopy);
uint8 SPI_u8Slave(uint8 DataCopy);

#endif /* MCAL_SPI_SPI_INIT_H_ */
