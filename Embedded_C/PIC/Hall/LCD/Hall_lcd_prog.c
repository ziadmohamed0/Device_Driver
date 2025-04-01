/*
 * File:   Hall_lcd_prog.c
 * Author: s
 *
 * Created on 20 ??????, 2024, 10:19 ?
 */


#include "Hall_lcd_init.h"

static Std_Return LCD_send4Bits(const LCD_4Bit_t* copyLCD, uint8_t copyCMD);
static Std_Return LCD_sendEnableSignal4Bits(const LCD_4Bit_t* copyLCD);
static Std_Return LCD_sendEnableSignal8Bits(const LCD_8Bit_t* copyLCD);

Std_Return HALL_LCD_4bit_init(const LCD_4Bit_t* copyLCD) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_init(&(copyLCD->LCD_rs));
        MCAL_GPIO_init(&(copyLCD->LCD_en));
        for(uint8_t Counter = Zero_init; Counter < 4; Counter++) {
            MCAL_GPIO_init(&(copyLCD->LCD_D[Counter]));
        }
        __delay_ms(20);
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        __delay_ms(5);
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        __delay_us(150);
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);      
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_CLEAR_DIS);
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_RETURN_HOME);
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_ENTERY_INC);   
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_DISPLAY_ON);  
        HALL_LCD_4bit_sendCMD(copyLCD, _LCD_4_BIT_MODE);
        HALL_LCD_4bit_sendCMD(copyLCD, 0x80);
        RetValue = R_OK;
    }
    return RetValue;
}
Std_Return HALL_LCD_4bit_sendCMD(const LCD_4Bit_t* copyLCD, uint8_t copyCMD){
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_writePinStatus(&(copyLCD->LCD_rs),GPIO_Status_Low);
        LCD_send4Bits(copyLCD, copyCMD >> 4);
        LCD_sendEnableSignal4Bits(copyLCD);
        LCD_send4Bits(copyLCD, copyCMD);
        LCD_sendEnableSignal4Bits(copyLCD);
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_4bit_sendChar(const LCD_4Bit_t* copyLCD, uint8_t copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_writePinStatus(&(copyLCD->LCD_rs),GPIO_Status_High);
        LCD_send4Bits(copyLCD, copyData >> 4);
        LCD_sendEnableSignal4Bits(copyLCD);
        LCD_send4Bits(copyLCD, copyData);
        LCD_sendEnableSignal4Bits(copyLCD);       
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_4bit_sendCharPos(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        HALL_LCD_4bit_goto(copyLCD, copyRow, copyColumn);
        HALL_LCD_4bit_sendChar(copyLCD, copyData);
        RetValue = R_OK;
    }
    return RetValue;
}
Std_Return HALL_LCD_4bit_sendSTR(const LCD_4Bit_t* copyLCD, uint8_t *copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        while (*copyData) {
            HALL_LCD_4bit_sendChar(copyLCD, *copyData++);
        }
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_4bit_sendSTRPos(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t *copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        HALL_LCD_4bit_goto(copyLCD,copyRow, copyColumn);
        while(*copyData) {
           HALL_LCD_4bit_sendChar(copyLCD, *copyData++); 
        }
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_4bit_goto(const LCD_4Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        switch (copyRow) {
            case RAW1 : HALL_LCD_4bit_sendCMD(copyLCD, (0x80 + copyColumn)); break;
            case RAW2 : HALL_LCD_4bit_sendCMD(copyLCD, (0xc0 + copyColumn)); break;
            case RAW3 : HALL_LCD_4bit_sendCMD(copyLCD, (0x94 + copyColumn)); break;
            case RAW4 : HALL_LCD_4bit_sendCMD(copyLCD, (0xd4 + copyColumn)); break;
            default: RetValue = R_ERROR; break;
        }        
        RetValue = R_OK;
    }
    return RetValue;     
}


Std_Return HALL_LCD_8bit_init(const LCD_8Bit_t* copyLCD) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_init(&(copyLCD->LCD_rs));
        MCAL_GPIO_init(&(copyLCD->LCD_en));
        for(uint8_t Counter = Zero_init; Counter < 8; Counter++) {
            MCAL_GPIO_init(&(copyLCD->LCD_D[Counter]));
        }
        __delay_ms(20);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        __delay_ms(5);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        __delay_us(150);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);      
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_CLEAR_DIS);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_RETURN_HOME);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_ENTERY_INC);   
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_DISPLAY_ON);  
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        HALL_LCD_8bit_sendCMD(copyLCD, _LCD_8_BIT_MODE);
        
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_sendCMD(const LCD_8Bit_t* copyLCD, uint8_t copyCMD) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_writePinStatus(&(copyLCD->LCD_rs),GPIO_Status_Low);
        for(uint8_t Counter = Zero_init; Counter < 8; Counter++) {
            MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[Counter]),(copyCMD >> Counter) & (uint8_t)0x01);
        }
        LCD_sendEnableSignal8Bits(copyLCD);
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_sendChar(const LCD_8Bit_t* copyLCD, uint8_t copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        MCAL_GPIO_writePinStatus(&(copyLCD->LCD_rs),GPIO_Status_High);
        for(uint8_t Counter = Zero_init; Counter < 8; Counter++) {
            MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[Counter]),(copyData >> Counter) & (uint8_t)0x01);
        }
        LCD_sendEnableSignal8Bits(copyLCD);
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_sendCharPos(const LCD_8Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        HALL_LCD_8bit_goto(copyLCD, copyRow, copyColumn);
        HALL_LCD_8bit_sendChar(copyLCD, copyData);
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_sendSTR(const LCD_8Bit_t* copyLCD, uint8_t *copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        while(*copyData) {
            HALL_LCD_8bit_sendChar(copyLCD, *copyData++);
        }
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_sendSTRPos(const LCD_8Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn, uint8_t *copyData) {
    uint8_t RetValue = R_ERROR;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        HALL_LCD_8bit_goto(copyLCD, copyRow, copyColumn);        
        while(*copyData) {
            HALL_LCD_8bit_sendChar(copyLCD, *copyData++);
        }        
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_8bit_goto(const LCD_8Bit_t* copyLCD, uint8_t copyRow, uint8_t copyColumn) {
    uint8_t RetValue = R_ERROR;
    copyColumn--;
    if(copyLCD == NULL) {
        RetValue = R_ERROR;
    }
    else {
        switch (copyRow) {
            case RAW1 : HALL_LCD_8bit_sendCMD(copyLCD, (0x80 + copyColumn)); break;
            case RAW2 : HALL_LCD_8bit_sendCMD(copyLCD, (0xc0 + copyColumn)); break;
            case RAW3 : HALL_LCD_8bit_sendCMD(copyLCD, (0x94 + copyColumn)); break;
            case RAW4 : HALL_LCD_8bit_sendCMD(copyLCD, (0xd4 + copyColumn)); break;
            default: RetValue = R_ERROR; break;
        }
        RetValue = R_OK;
    }
    return RetValue;     
}

Std_Return HALL_LCD_convertU8toSTR(uint8_t copyValue, uint8_t* copySTR) {
    uint8_t RetValue = R_ERROR;
    if(copySTR == NULL) {
        RetValue = R_ERROR;
    }
    else {
        memset(copySTR, '\0', 4);
        sprintf(copySTR, "%i", copyValue);        
        RetValue = R_OK;
    }
    return RetValue;    
}
Std_Return HALL_LCD_convertU16toSTR(uint16_t copyValue, uint8_t* copySTR) {
    uint8_t RetValue = R_ERROR;
    uint8_t tempString[6] = {0};
    uint8_t DataCounter = Zero_init;
    if(copySTR == NULL) {
        RetValue = R_ERROR;
    }
    else {
        memset(copySTR, ' ', 5);
        sprintf(tempString, "%i", copyValue);
        while(tempString[DataCounter] != '\0') {
            copySTR[DataCounter] = tempString[DataCounter];
            DataCounter++;
        }
        RetValue = R_OK;
    }
    return RetValue;     
}

Std_Return HALL_LCD_convertU32toSTR(uint32_t copyValue, uint8_t* copySTR) {
    uint8_t RetValue = R_ERROR;
    if(copySTR == NULL) {
        RetValue = R_ERROR;
    }
    else {
        memset(copySTR, '\0', 11);
        sprintf(copySTR, "%i", copyValue);        
        RetValue = R_OK;
    }
    return RetValue;     
}

static Std_Return LCD_send4Bits(const LCD_4Bit_t* copyLCD, uint8_t copyData) {
    uint8_t RetValue = R_OK;
    RetValue = MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[0]),(copyData >> 0) & (uint8_t)0x01);
    RetValue = MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[1]),(copyData >> 1) & (uint8_t)0x01);
    RetValue = MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[2]),(copyData >> 2) & (uint8_t)0x01);
    RetValue = MCAL_GPIO_writePinStatus(&(copyLCD->LCD_D[3]),(copyData >> 3) & (uint8_t)0x01);
    return  RetValue;
}
static Std_Return LCD_sendEnableSignal4Bits(const LCD_4Bit_t* copyLCD) {
    uint8_t RetValue = R_OK;
    MCAL_GPIO_writePinStatus(&(copyLCD->LCD_en), GPIO_Status_High);
    __delay_us(5);
    MCAL_GPIO_writePinStatus(&(copyLCD->LCD_en), GPIO_Status_Low);
    return  RetValue;    
}
static Std_Return LCD_sendEnableSignal8Bits(const LCD_8Bit_t* copyLCD) {
    uint8_t RetValue = R_OK;
    MCAL_GPIO_writePinStatus(&(copyLCD->LCD_en), GPIO_Status_High);
    __delay_us(5);
    MCAL_GPIO_writePinStatus(&(copyLCD->LCD_en), GPIO_Status_Low);
    return  RetValue;    
}