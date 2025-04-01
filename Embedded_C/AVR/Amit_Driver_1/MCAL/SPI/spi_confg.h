/*
 * spi_confg.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bunny
 */

#ifndef MCAL_SPI_SPI_CONFG_H_
#define MCAL_SPI_SPI_CONFG_H_




#define SS         4
#define MOSI       5
#define MISO       6
#define SCK        7



/*------ Data_order--------*/
#define SPI_LSB   0
#define SPI_MSB   1
#define SPI_DATA_ORDER  SPI_LSB



/*------ Master_Slave--------*/
#define SPI_MASTER    0
#define SPI_SLAVE     1
#define SPI_MODE       SPI_SLAVE



/*------ CLOCK Rate Prescaler ------*/
#define SPI_Clock_Rate2            SPCR |= 0x00; SPSR |= 0x01
#define SPI_Clock_Rate4            SPCR |= 0x00; SPSR |= 0x00
#define SPI_Clock_Rate8            SPCR |= 0x01; SPSR |= 0x01
#define SPI_Clock_Rate16           SPCR |= 0x01; SPSR |= 0x00
#define SPI_Clock_Rate32           SPCR |= 0x02; SPSR |= 0x01
#define SPI_Clock_Rate64           SPCR |= 0x03; SPSR |= 0x01
#define SPI_Clock_Rate128          SPCR |= 0x03; SPSR |= 0x00
#define SPI_PRESCALER      SPI_Clock_Rate8

#endif /* MCAL_SPI_SPI_CONFG_H_ */
