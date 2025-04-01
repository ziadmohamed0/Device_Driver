/*
 * File:   Mcal_EEPROM_prog.c
 * Author: s
 *
 * Created on November 6, 2024, 3:01 AM
 */


#include "Mcal_EEPROM_init.h"

Std_Return MCAL_EEPROM_DataWriteByte(uint16_t copybAdd, uint8_t copybData) {
    uint8_t retValue = R_OK;
    
    /* Read the interrupt Status "Enabled or Disabled" */
    uint8_t Globale_interrupt_Status = INTCONbits.GIE;
    
    /* Update the address register */
    EEADRH = ((uint8_t)((copybAdd >> 8) & 0x03));
    EEADR = ((uint8_t)(copybAdd & 0xFF));
    
    /* Update the Data register */
    EEDATA = copybData;
    
    /* Select access data EEPROM memory */
    EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
    EECON1bits.CFGS  = ACCESS_FLASH_EEPROM_MEMORY;
    
    /* Allows write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = ALLOW_EEPROM_MEMORY;
    
    /* Disable all interrupt "General Interrupt" */
    MCAL_INTERRUPT_GlobaleInterruptDisable();
    
    /* Write the required sequence : 0x55 -> 0xAA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    
    /* Inhibits a data EEPROM erase/Write cycle */
    EECON1bits.WR = INITIATES_EEPROM_WRITE_ERASE;
    
    /* Wait for write to complete */
    while(EECON1bits.WR);
    
    /* Inhibits write to Flash program/data EEPROM */
    EECON1bits.WREN = INHIBITS_EEPROM_MEMORY;
    
    /* restore the interrupt status "Enabled or Disabled" */
    INTCONbits.GIE = Globale_interrupt_Status;
    
    return retValue;
}
Std_Return MCAL_EEPROM_DataReadByte(uint16_t copybAdd, uint8_t *copybData) {
    uint8_t retValue = R_ERROR;
    if(copybData == NULL) {
        
    }
    else {
        /* Update The Addresses Registers */
        EEADRH = ((uint8_t)((copybAdd >> 8) & 0x03));
        EEADR = ((uint8_t)(copybAdd & 0xFF));
        
        /* Select Access data EEPROM memory */
        EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
        EECON1bits.CFGS  = ACCESS_FLASH_EEPROM_MEMORY;
    
        /* Initiates a data EEPROM read Cycle */
        EECON1bits.RD = INITIATES_EEPROM_READ;
        NOP();
        NOP();
        
        /* Return Data */
        *copybData = EEDATA;
         
        retValue = R_OK;
    }
    return retValue;    
}