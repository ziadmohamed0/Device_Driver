/* 
 * File:   Mcal_EEPROM_init.h
 * Author: s
 *
 * Created on November 6, 2024, 2:59 AM
 */

#ifndef MCAL_EEPROM_INIT_H
#define	MCAL_EEPROM_INIT_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_interrupt/Mcal_internal_interrupt.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ACCESS_FLASH_MEMORY                         1U
#define ACCESS_EEPROM_MEMORY                        0U

#define ACCESS_CONFIG_REGISTER                      1U
#define ACCESS_FLASH_EEPROM_MEMORY                  0U

#define ALLOW_EEPROM_MEMORY                         1U
#define INHIBITS_EEPROM_MEMORY                      0U

#define INITIATES_EEPROM_WRITE_ERASE                1U
#define Data_EEPROM_WRITE_ERASE_COMPLETED       `   0U

#define INITIATES_EEPROM_READ                       1U

/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return MCAL_EEPROM_DataWriteByte(uint16_t copybAdd, uint8_t copybData);
Std_Return MCAL_EEPROM_DataReadByte(uint16_t copybAdd, uint8_t *copybData);
/* -------------------- API End -------------------- */

#endif	/* MCAL_EEPROM_INIT_H */

