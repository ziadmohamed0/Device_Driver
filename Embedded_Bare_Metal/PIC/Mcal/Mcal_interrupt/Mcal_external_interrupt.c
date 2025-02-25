/*
 * File:   Mcal_external_interrupt.c
 * Author: s
 *
 * Created on 24 ??????, 2024, 02:36 ?
 */


#include "Mcal_external_interrupt.h"

static void (*INT0_interruptHandler)(void) = NULL;
static void (*INT1_interruptHandler)(void) = NULL;
static void (*INT2_interruptHandler)(void) = NULL;

static void (*RB4_interruptHandler_High)(void) = NULL;
static void (*RB4_interruptHandler_Low)(void)  = NULL;
static void (*RB5_interruptHandler_High)(void) = NULL;
static void (*RB5_interruptHandler_Low)(void)  = NULL;
static void (*RB6_interruptHandler_High)(void) = NULL;
static void (*RB6_interruptHandler_Low)(void)  = NULL;
static void (*RB7_interruptHandler_High)(void) = NULL;
static void (*RB7_interruptHandler_Low)(void)  = NULL;

static Std_Return INTERRUPT_INTx_Enable(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_Disable(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_PrioretyInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_EdgInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_PinInit(const Interrupt_INTx_t *copyINTx);
static Std_Return INTERRUPT_INTx_ClearFlag(const Interrupt_INTx_t *copyINTx);


static Std_Return INT0_setInterruprHandler(void (*interruptHandler)(void));
static Std_Return INT1_setInterruprHandler(void (*interruptHandler)(void));
static Std_Return INT2_setInterruprHandler(void (*interruptHandler)(void));
static Std_Return INTERRUPT_INTx_setInterruptHandler(const Interrupt_INTx_t *copyINTx);

static Std_Return INTERRUPT_RBx_Enable(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_Disable(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_PrioretyInit(const Interrupt_RBx_t *copyINTx);
static Std_Return INTERRUPT_RBx_PinInit(const Interrupt_RBx_t *copyINTx);

Std_Return MCAL_INTERRUPT_INTx_init(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        /* Disable External Interrupt */
        INTERRUPT_INTx_Disable(copyINTx);
        
        /* Clear Flag External Interrupt */
        INTERRUPT_INTx_ClearFlag(copyINTx);
        
        #if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
        /* Configure Priority External Interrupt */
        INTERRUPT_INTx_PrioretyInit(copyINTx);
        #endif

        /* Configure EDG State External Interrupt */
        INTERRUPT_INTx_EdgInit(copyINTx);
        
        /* Configure Pin I/O External Interrupt */
        INTERRUPT_INTx_PinInit(&copyINTx);
        
        /* Configure Default iInterrupt CallBack */
        INTERRUPT_INTx_setInterruptHandler(copyINTx);
        
        /* Enable External Interrupt */
        INTERRUPT_INTx_Enable(copyINTx);
        retValue = R_OK;
    } 
    return retValue;
}

void INT0_ISR(void) {
    /* External Interrupt Must Flag is Clear */
    MCAL_EX_INT0_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(INT0_interruptHandler) {
        INT0_interruptHandler();
    }
    else {
        /* Nothing */
    }
}

void INT1_ISR(void) {
    /* External Interrupt Must Flag is Clear */
    MCAL_EX_INT1_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(INT1_interruptHandler) {
        INT1_interruptHandler();
    }
    else {
        /* Nothing */
    }
}

void INT2_ISR(void) {
    /* External Interrupt Must Flag is Clear */
    MCAL_EX_INT2_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(INT2_interruptHandler) {
        INT2_interruptHandler();
    }
    else {
        /* Nothing */
    }
}

void RB4_ISR(uint8_t copySource) {
    /* External Interrupt Must Flag is Clear */
    MCAL_RBx_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(copySource == 0) {
        if(RB4_interruptHandler_High) {
            RB4_interruptHandler_High();
        }
        else {
            /* Nothing */
        }
    }
    else if(copySource == 0) {
        if(RB4_interruptHandler_Low) {
            RB4_interruptHandler_Low();
        }
        else {
            /* Nothing */
        }        
    }
}

void RB5_ISR(uint8_t copySource) {
    /* External Interrupt Must Flag is Clear */
    MCAL_RBx_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(copySource == 0) {
        if(RB5_interruptHandler_High) {
            RB5_interruptHandler_High();
        }
        else {
            /* Nothing */
        }
    }
    else if(copySource == 0) {
        if(RB5_interruptHandler_Low) {
            RB5_interruptHandler_Low();
        }
        else {
            /* Nothing */
        }        
    }
}

void RB6_ISR(uint8_t copySource) {
    /* External Interrupt Must Flag is Clear */
    MCAL_RBx_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(copySource == 0) {
        if(RB6_interruptHandler_High) {
            RB6_interruptHandler_High();
        }
        else {
            /* Nothing */
        }
    }
    else if(copySource == 0) {
        if(RB6_interruptHandler_Low) {
            RB6_interruptHandler_Low();
        }
        else {
            /* Nothing */
        }        
    }
}

void RB7_ISR(uint8_t copySource) {
    /* External Interrupt Must Flag is Clear */
    MCAL_RBx_clearInterruptFlage();
    /* Code */
    
    /*Call Back Function get Called Every time this ISR Execute */
    if(copySource == 0) {
        if(RB7_interruptHandler_High) {
            RB7_interruptHandler_High();
        }
        else {
            /* Nothing */
        }
    }
    else if(copySource == 0) {
        if(RB7_interruptHandler_Low) {
            RB7_interruptHandler_Low();
        }
        else {
            /* Nothing */
        }        
    }
}

Std_Return MCAL_INTERRUPT_INTx_DeInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        INTERRUPT_INTx_Disable(copyINTx);
        retValue = R_OK;
    }
    return retValue;    
}

Std_Return MCAL_INTERRUPT_RBx_init(const Interrupt_RBx_t *copyRBx) {
    uint8_t retValue = R_ERROR;
    if(copyRBx == NULL) {
        retValue = R_ERROR;
    }
    else {
        MCAL_RBx_InterruptDisable();
        MCAL_RBx_clearInterruptFlage();
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
        MCAL_INTERRUPT_PriorityLevelEnable();
        switch(copyRBx->Priorety) {
            case INTERRUPT_PRIORETY_LOW:  
                MCAL_INTERRUPT_GlobaleInterruptLowEnable(); 
                MCAL_EX_RBx_LowPrioritySet();
                break;
            case INTERRUPT_PRIORETY_HIGH: 
                MCAL_INTERRUPT_GlobaleInterruptHighEnable(); 
                MCAL_EX_RBx_HighPrioritySet();
                break;
            default: retValue = R_ERROR; break;
        }
#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
        MCAL_INTERRUPT_GlobaleInterruptEnable();
        MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif
        MCAL_GPIO_init(&(copyRBx->MCU_Pin));
        switch(copyRBx->MCU_Pin.Pin) {
            case GPIO_Pin_Index_4:
                RB4_interruptHandler_High = copyRBx->EX_InterruptHandler_High;
                RB4_interruptHandler_Low = copyRBx->EX_InterruptHandler_Low;
                break;
            case GPIO_Pin_Index_5:
                RB5_interruptHandler_High = copyRBx->EX_InterruptHandler_High;
                RB5_interruptHandler_Low = copyRBx->EX_InterruptHandler_Low;
                break;    
            case GPIO_Pin_Index_6:
                RB6_interruptHandler_High = copyRBx->EX_InterruptHandler_High;
                RB6_interruptHandler_Low = copyRBx->EX_InterruptHandler_Low;
                break;    
            case GPIO_Pin_Index_7:
                RB7_interruptHandler_High = copyRBx->EX_InterruptHandler_High;
                RB7_interruptHandler_Low = copyRBx->EX_InterruptHandler_Low;
                break;    
        }
        MCAL_RBx_InterruptEnable();
        retValue = R_OK;
    }
    return retValue;    
}
Std_Return MCAL_INTERRUPT_RBx_DeInit(const Interrupt_RBx_t *copyRBx) {
    uint8_t retValue = R_ERROR;
    if(copyRBx == NULL) {
        retValue = R_ERROR;
    }
    else {
        
        retValue = R_OK;
    }
    return retValue;    
}


static Std_Return INTERRUPT_INTx_Enable(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
                MCAL_INTERRUPT_PriorityLevelEnable();
                MCAL_INTERRUPT_GlobaleInterruptHighEnable();
#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
                MCAL_INTERRUPT_GlobaleInterruptEnable();
                MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif
                MCAL_EX_INT0_InterruptEnable();
                retValue = R_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
                MCAL_INTERRUPT_PriorityLevelEnable();
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_INTERRUPT_GlobaleInterruptLowEnable();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_INTERRUPT_GlobaleInterruptHighEnable(); break;
                    default: retValue = R_ERROR; break;
                }
#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
                MCAL_INTERRUPT_GlobaleInterruptEnable();
                MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif
                MCAL_EX_INT1_InterruptEnable();
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
                MCAL_INTERRUPT_PriorityLevelEnable();
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_INTERRUPT_GlobaleInterruptLowEnable();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_INTERRUPT_GlobaleInterruptHighEnable(); break;
                    default: retValue = R_ERROR; break;
                }
#elif INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_DISABLE_FUTURE
                MCAL_INTERRUPT_GlobaleInterruptEnable();
                MCAL_INTERRUPT_PeripheralInterruptEnable();
#endif
                MCAL_EX_INT2_InterruptEnable();
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }
    }
    return retValue;        
}
static Std_Return INTERRUPT_INTx_Disable(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                MCAL_EX_INT0_InterruptDisable();
                retValue = R_OK; 
                break;
            case INTERRUPT_EXTERNAL_INT1:
                MCAL_EX_INT1_InterruptDisable();
                retValue = R_OK; 
                break;
            case INTERRUPT_EXTERNAL_INT2:
                MCAL_EX_INT2_InterruptDisable();
                retValue = R_OK; 
                break; 
            default : 
                retValue = R_OK; 
                break;
        } 
    }
    return retValue;        
}

#if INTERRUPT_PRIORETY_LEVELS_ENABLE == INTERRUPT_ENABLE_FUTURE
static Std_Return INTERRUPT_INTx_PrioretyInit(const Interrupt_INTx_t *copyINTx) {
     uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT1:
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_EX_INT1_LowPrioritySet();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_EX_INT1_HighPrioritySet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                switch(copyINTx->Priorety) {
                    case INTERRUPT_PRIORETY_LOW:  MCAL_EX_INT2_LowPrioritySet();  break;
                    case INTERRUPT_PRIORETY_HIGH: MCAL_EX_INT2_HighPrioritySet(); break;
                    default: retValue = R_ERROR; break;
                }                 
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }        
        retValue = R_OK;
    }
    return retValue;       
}
#endif
static Std_Return INTERRUPT_INTx_EdgInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT0_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT0_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;              
            
            case INTERRUPT_EXTERNAL_INT1:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT1_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT1_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }              
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                switch(copyINTx->Edge) {
                    case INTERRUPT_EDGE_RISING:  MCAL_EX_INT2_rissingSet();  break;
                    case INTERRUPT_EDGE_FALLING: MCAL_EX_INT2_fallingSet(); break;
                    default: retValue = R_ERROR; break;
                }                 
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }           
        retValue = R_OK;
    }
    return retValue;        
}
static Std_Return INTERRUPT_INTx_PinInit(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        Mcal_GPIO_initPinDirection(&(copyINTx->MCU_Pin));
        retValue = R_OK;
    }
    return retValue;         
}
static Std_Return INTERRUPT_INTx_ClearFlag(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                MCAL_EX_INT0_clearInterruptFlage();
                retValue = R_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                MCAL_EX_INT1_clearInterruptFlage();
                retValue = R_OK;
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                MCAL_EX_INT2_clearInterruptFlage();
                retValue = R_OK;
                break;
            default : 
                retValue = R_OK; 
                break;
        }
        retValue = R_OK;
    }
    return retValue;    
}

static Std_Return INT0_setInterruprHandler(void (*interruptHandler)(void)) {
    uint8_t retValue = R_ERROR;
    if(interruptHandler == NULL) {
        retValue = R_ERROR;
    }
    else {
        INT0_interruptHandler = interruptHandler;
    }
    return retValue;        
}

static Std_Return INT1_setInterruprHandler(void (*interruptHandler)(void)) {
    uint8_t retValue = R_ERROR;
    if(interruptHandler == NULL) {
        retValue = R_ERROR;
    }
    else {
        INT1_interruptHandler = interruptHandler;
    }
    return retValue;      
}

static Std_Return INT2_setInterruprHandler(void (*interruptHandler)(void)) {
    uint8_t retValue = R_ERROR;
    if(interruptHandler == NULL) {
        retValue = R_ERROR;
    }
    else {
        INT2_interruptHandler = interruptHandler;
    }
    return retValue;      
}

static Std_Return INTERRUPT_INTx_setInterruptHandler(const Interrupt_INTx_t *copyINTx) {
    uint8_t retValue = R_ERROR;
    if(copyINTx == NULL) {
        retValue = R_ERROR;
    }
    else {
        switch(copyINTx->Source) {
            case INTERRUPT_EXTERNAL_INT0:
                retValue = INT0_setInterruprHandler(copyINTx->EX_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                retValue = INT1_setInterruprHandler(copyINTx->EX_InterruptHandler);
                break;  
            case INTERRUPT_EXTERNAL_INT2:
                retValue = INT2_setInterruprHandler(copyINTx->EX_InterruptHandler);
                break;
            default : 
                retValue = R_OK; 
                break;
        }
        retValue = R_OK;
    }
    return retValue;     
}
