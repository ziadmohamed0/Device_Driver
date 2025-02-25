/*
 * File:   Mcal_GPIO_prog.c
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:35 ?
 */


#include "Mcal_GPIO_init.h"

Std_Return Mcal_GPIO_initPinDirection(const Pin_cfg_t* copyPinCFG) {
    
    uint8_t retVal = R_OK;    
    if(copyPinCFG == NULL) {
        retVal = R_ERROR;  
    }
    else {
        switch(copyPinCFG->Port) {
            case GPIO_Port_Index_A:
                switch(copyPinCFG->Direction) {
                    case GPIO_Dircetion_Output:
                        CLR_BIT(TRISA,copyPinCFG->Pin);
                        break;
                    case GPIO_Dircetion_Input:
                        SET_BIT(TRISA,copyPinCFG->Pin);
                        break;
                }
                break;
                
            case GPIO_Port_Index_B:
                switch(copyPinCFG->Direction) {
                    case GPIO_Dircetion_Output:
                        CLR_BIT(TRISB,copyPinCFG->Pin);
                        break;
                    case GPIO_Dircetion_Input:
                        SET_BIT(TRISB,copyPinCFG->Pin);
                        break;
                }
                break;
                
            case GPIO_Port_Index_C:
                switch(copyPinCFG->Direction) {
                    case GPIO_Dircetion_Output:
                        CLR_BIT(TRISC,copyPinCFG->Pin);
                        break;
                    case GPIO_Dircetion_Input:
                        SET_BIT(TRISC,copyPinCFG->Pin);
                        break;          
                }
                break;
                
            case GPIO_Port_Index_D:
                switch(copyPinCFG->Direction) {
                    case GPIO_Dircetion_Output:
                        CLR_BIT(TRISD,copyPinCFG->Pin);
                        break;
                    case GPIO_Dircetion_Input:
                        SET_BIT(TRISD,copyPinCFG->Pin);
                        break;
                }
                break;
                
            case GPIO_Port_Index_E:
                switch(copyPinCFG->Direction) {
                    case GPIO_Dircetion_Output:
                        CLR_BIT(TRISE,copyPinCFG->Pin);
                        break;
                    case GPIO_Dircetion_Input:
                        SET_BIT(TRISE,copyPinCFG->Pin);
                        break;
                }
                break;
                default:
                    retVal = R_ERROR;
                    break;
        }
    }
    return retVal;
}

Std_Return MCAL_GPIO_getPinDirection(const Pin_cfg_t* copyPinCFG, Direction_t *copyDirectionPin) {
    uint8_t retVal = R_OK; 
    if(copyPinCFG == NULL) {
        retVal = R_ERROR;
    }
    else {
        switch(copyPinCFG->Port) {
            case GPIO_Port_Index_A :
                *copyDirectionPin = GET_BIT(TRISA, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_B :
                *copyDirectionPin = GET_BIT(TRISB, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_C :
                *copyDirectionPin = GET_BIT(TRISC, copyPinCFG->Pin);
                break;
                
                
            case GPIO_Port_Index_D :
                *copyDirectionPin = GET_BIT(TRISD, copyPinCFG->Pin);
                break;
              
            case GPIO_Port_Index_E :
                *copyDirectionPin = GET_BIT(TRISE, copyPinCFG->Pin);
                break; 
                
            default:
                retVal = R_ERROR;
                break;                
        }    
    }
    return retVal;
}

Std_Return MCAL_GPIO_writePinStatus(const Pin_cfg_t* copyPinCFG, Status_t copyStatusPin) {
    uint8_t retVal = R_OK; 
    if(copyPinCFG == NULL) {
        retVal = R_ERROR;
    }
    else {
        switch(copyPinCFG->Port) {
            case GPIO_Port_Index_A :
                switch(copyStatusPin) {
                    case GPIO_Status_High:
                        SET_BIT(LATA,copyPinCFG->Pin);
                        break;
                    case GPIO_Status_Low:
                        CLR_BIT(LATA,copyPinCFG->Pin);
                        break;
                    default:
                        retVal = R_ERROR;
                        break;
                }
                break;
                
            case GPIO_Port_Index_B :
                switch(copyStatusPin) {
                    case GPIO_Status_High:
                        SET_BIT(LATB,copyPinCFG->Pin);
                        break;
                    case GPIO_Status_Low:
                        CLR_BIT(LATB,copyPinCFG->Pin);
                        break;
                    default:
                        retVal = R_ERROR;
                        break;
                }
                break;
                
            case GPIO_Port_Index_C :
                switch(copyStatusPin) {
                    case GPIO_Status_High:
                        SET_BIT(LATC,copyPinCFG->Pin);
                        break;
                    case GPIO_Status_Low:
                        CLR_BIT(LATC,copyPinCFG->Pin);
                        break;
                    default:
                        retVal = R_ERROR;
                        break;
                }
                break;
                
                
            case GPIO_Port_Index_D :
                switch(copyStatusPin) {
                    case GPIO_Status_High:
                        SET_BIT(LATD,copyPinCFG->Pin);
                        break;
                    case GPIO_Status_Low:
                        CLR_BIT(LATD,copyPinCFG->Pin);
                        break;
                    default:
                        retVal = R_ERROR;
                        break;
                }
                break;
                
                
            case GPIO_Port_Index_E :
                switch(copyStatusPin) {
                    case GPIO_Status_High:
                        SET_BIT(LATE,copyPinCFG->Pin);
                        break;
                    case GPIO_Status_Low:
                        CLR_BIT(LATE,copyPinCFG->Pin);
                        break;
                    default:
                        retVal = R_ERROR;
                        break;
                }
                break;  
            default:
                retVal = R_ERROR;
                break;                
        }
    }
    return retVal;
}

Std_Return MCAL_GPIO_getPinStatus(const Pin_cfg_t* copyPinCFG, Status_t* copyStatusPin) {
    uint8_t retVal = R_OK; 
    if((copyPinCFG == NULL) || (copyStatusPin == NULL)) {
        retVal = R_ERROR;
    }
    else {
        switch(copyPinCFG->Port) {
            case GPIO_Port_Index_A :
                *copyStatusPin = GET_BIT(PORTA, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_B :
                *copyStatusPin = GET_BIT(PORTB, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_C :
                *copyStatusPin = GET_BIT(PORTC, copyPinCFG->Pin);
                break;
                
                
            case GPIO_Port_Index_D :
                *copyStatusPin = GET_BIT(PORTD, copyPinCFG->Pin);
                break;
              
            case GPIO_Port_Index_E :
                *copyStatusPin = GET_BIT(PORTE, copyPinCFG->Pin);
                break; 
                
            default:
                retVal = R_ERROR;
                break;                
        }        
    }
    return retVal;
}

Std_Return MCAL_GPIO_togglePin(const Pin_cfg_t* copyPinCFG) {
    uint8_t retVal = R_OK; 
    if(copyPinCFG == NULL) {
        retVal = R_ERROR;
    }
    else {
        switch(copyPinCFG->Port) {
            case GPIO_Port_Index_A :
                TOGGLE_BIT(LATA, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_B :
                TOGGLE_BIT(LATB, copyPinCFG->Pin);
                break;
                
            case GPIO_Port_Index_C :
                TOGGLE_BIT(LATC, copyPinCFG->Pin);
                break;
                
                
            case GPIO_Port_Index_D :
                TOGGLE_BIT(LATD, copyPinCFG->Pin);
                break;
              
            case GPIO_Port_Index_E :
                TOGGLE_BIT(LATE, copyPinCFG->Pin);
                break; 
                
            default:
                retVal = R_ERROR;
                break;                
        }          
    }
    return retVal;
}
Std_Return MCAL_GPIO_init(const Pin_cfg_t* copyPinCFG) {
    uint8_t retVal = R_OK; 
    if(copyPinCFG == NULL) {
        retVal = R_ERROR;
    }
    else {
        retVal = Mcal_GPIO_initPinDirection(copyPinCFG);
        retVal = MCAL_GPIO_writePinStatus(copyPinCFG,copyPinCFG->Status);
    }
    return retVal;
}


Std_Return Mcal_GPIO_initPortDirection(Port_Index_t copyPortCFG, uint8_t copyDirection) {
    uint8_t retValue = R_OK;
    
    if(copyPortCFG == GPIO_Port_Index_A) {
        TRISA = copyDirection;
    }
    else if(copyPortCFG == GPIO_Port_Index_B) {
        TRISB = copyDirection;
    }
    else if(copyPortCFG == GPIO_Port_Index_C) {
        TRISC = copyDirection;
    }
    else if(copyPortCFG == GPIO_Port_Index_D) {
        TRISD = copyDirection;
    }
    else if(copyPortCFG == GPIO_Port_Index_E) {
        TRISE = copyDirection;
    }
    else {
        retValue = R_ERROR;
    }
    return retValue;
}

Std_Return MCAL_GPIO_getPortDirection(Port_Index_t copyPortCFG, uint8_t* copyDirectionPort) {
    uint8_t retVal = R_OK; 
    if(copyDirectionPort == NULL) {
        retVal = R_ERROR;
    }
    else {
        uint8_t retValue = R_OK;
    
        if(copyPortCFG == GPIO_Port_Index_A) {
            *copyDirectionPort = TRISA;
        }
        else if(copyPortCFG == GPIO_Port_Index_B) {
            *copyDirectionPort = TRISB;
        }
        else if(copyPortCFG == GPIO_Port_Index_C) {
            *copyDirectionPort = TRISC;
        }
        else if(copyPortCFG == GPIO_Port_Index_D) {
            *copyDirectionPort = TRISD;
        }
        else if(copyPortCFG == GPIO_Port_Index_E) {
            *copyDirectionPort = TRISE;
        }
        else {
            retValue = R_ERROR;
        }
    }
    return retVal;
}
Std_Return MCAL_GPIO_writePortStatus(Port_Index_t copyPortCFG, uint8_t copyStatusPort) {
    uint8_t retValue = R_OK;
    
    if(copyPortCFG == GPIO_Port_Index_A) {
        LATA = copyStatusPort;
    }
    else if(copyPortCFG == GPIO_Port_Index_B) {
        LATB = copyStatusPort;
    }
    else if(copyPortCFG == GPIO_Port_Index_C) {
        LATC = copyStatusPort;
    }
    else if(copyPortCFG == GPIO_Port_Index_D) {
        LATD = copyStatusPort;
    }
    else if(copyPortCFG == GPIO_Port_Index_E) {
        LATE = copyStatusPort;
    }
    else {
        retValue = R_ERROR;
    }
    return retValue;    
}

Std_Return MCAL_GPIO_getPortStatus(Port_Index_t copyPortCFG, uint8_t* copyStatusPort) {
    uint8_t retVal = R_OK; 
    if(copyStatusPort == NULL) {
        retVal = R_ERROR;
    }
    else {
        uint8_t retValue = R_OK;
    
        if(copyPortCFG == GPIO_Port_Index_A) {
            *copyStatusPort = PORTA;
        }
        else if(copyPortCFG == GPIO_Port_Index_B) {
            *copyStatusPort = PORTB;
        }
        else if(copyPortCFG == GPIO_Port_Index_C) {
            *copyStatusPort = PORTC;
        }
        else if(copyPortCFG == GPIO_Port_Index_D) {
            *copyStatusPort = PORTD;
        }
        else if(copyPortCFG == GPIO_Port_Index_E) {
            *copyStatusPort = PORTE;
        }
        else {
            retValue = R_ERROR;
        }
    }
    return retVal;
}
