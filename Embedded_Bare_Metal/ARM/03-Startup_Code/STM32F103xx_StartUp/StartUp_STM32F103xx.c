/**
 * @file StartUp_STM32F103xx.c
 * @author Ziad Mohammed Fathi Mohammed.
 * @brief StartUp Code For STM32F103xx Cortex-M3.
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* Define Null macro */
#define NULL 0

/* User Created Data Type 32 Bit Size */
typedef unsigned long uint32_t; 

/* extern variables declarations */
extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _erodata;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern int main (void);

/* Address of main stack pointer */
const uint32_t * MSP_Val = (uint32_t *)&_estack;

/* Handler ISR functions declarations */
// void Default_Handler(void);
void Reset_Handler              (void);   /* Reset */
void NMI_Handler                (void) __attribute__ ((alias("Default_Handler")));   /* Non maskable interrupt. The RCC Clock Security System (CSS) is linked to the NMI vector. */
void HardFault_Handler          (void) __attribute__ ((alias("Default_Handler")));   /* All class of fault */
void MemManage_Handler          (void) __attribute__ ((alias("Default_Handler")));   /* Memory management */
void BusFault_Handler           (void) __attribute__ ((alias("Default_Handler")));   /* Pre-fetch fault, memory access fault */
void UsageFault_Handler         (void) __attribute__ ((alias("Default_Handler")));   /* Undefined instruction or illegal state */
void SVCall_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* System service call via SWI instruction */
void Debug_Monitor_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* Debug Monitor */
void PendSV_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* Pendable request for system service */
void SysTick_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* System tick timer */
void WWDG_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* Window Watchdog interrupt */
void PVD_Handler                (void) __attribute__ ((alias("Default_Handler")));   /* PVD through EXTI Line detection interrupt */
void TAMPER_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* Tamper interrupt */
void RTC_Handler                (void) __attribute__ ((alias("Default_Handler")));   /* RTC global interrupt */
void FLASH_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* Flash global interrupt */
void RCC_Handler                (void) __attribute__ ((alias("Default_Handler")));   /* RCC global interrupt */
void EXTI0_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line0 interrupt */
void EXTI1_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line1 interrupt */
void EXTI2_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line2 interrupt */
void EXTI3_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line3 interrupt */
void EXTI4_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line4 interrupt */
void DMA1_Channel1_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel1 global interrupt */
void DMA1_Channel2_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel2 global interrupt */
void DMA1_Channel3_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel3 global interrupt */
void DMA1_Channel4_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel4 global interrupt */
void DMA1_Channel5_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel5 global interrupt */
void DMA1_Channel6_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel6 global interrupt */
void DMA1_Channel7_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA1 Channel7 global interrupt */
void ADC1_2_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* ADC1 and ADC2 global interrupt */
void USB_HP_CAN_TX_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* CAN1 TX interrupts */
void USB_LP_CAN_RX0_Handler     (void) __attribute__ ((alias("Default_Handler")));   /* CAN1 RX0 interrupts */
void CAN_RX1_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* CAN1 RX1 interrupt */
void CAN_SCE_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* CAN1 SCE interrupt */
void EXTI9_5_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line[9:5] interrupts */
void TIM1_BRK_Handler           (void) __attribute__ ((alias("Default_Handler")));   /* TIM1 Break interrupt */
void TIM1_UP_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* TIM1 Update interrupt */
void TIM1_TRG_COM_Handler       (void) __attribute__ ((alias("Default_Handler")));   /* TIM1 Trigger and Commutation interrupts */
void TIM1_CC_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* TIM1 Capture Compare interrupt */
void TIM2_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM2 global interrupt */
void TIM3_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM3 global interrupt */
void TIM4_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM4 global interrupt */
void I2C1_EV_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* I2C1 event interrupt */
void I2C1_ER_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* I2C1 error interrupt */
void I2C2_EV_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* I2C2 event interrupt */
void I2C2_ER_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* I2C2 error interrupt */
void SPI1_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* SPI1 global interrupt */
void SPI2_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* SPI2 global interrupt */
void USART1_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* USART1 global interrupt */
void USART2_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* USART2 global interrupt */
void USART3_Handler             (void) __attribute__ ((alias("Default_Handler")));   /* USART3 global interrupt */
void EXTI15_10_Handler          (void) __attribute__ ((alias("Default_Handler")));   /* EXTI Line[15:10] interrupts */
void RTCAlarm_Handler           (void) __attribute__ ((alias("Default_Handler")));   /* RTC alarm through EXTI lineinterrupt */
void USBWakeup_Handler          (void) __attribute__ ((alias("Default_Handler")));   /* USB wakeup from suspend through EXTI line interrupt */
void TIM8_BRK_Handler           (void) __attribute__ ((alias("Default_Handler")));   /* TIM8 Break interrupt */
void TIM8_UP_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* TIM8 Update interrupt */
void TIM8_TRG_COM_Handler       (void) __attribute__ ((alias("Default_Handler")));   /* TIM8 Trigger and Commutation interrupt */
void TIM8_CC_Handler            (void) __attribute__ ((alias("Default_Handler")));   /* TIM8 Capture Compare interrupt */
void ADC3_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* ADC3 global interrupt */
void FSMC_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* FSMC global interrupt */
void SDIO_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* SDIO global interrupt */
void TIM5_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM5 global interrupt */
void SPI3_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* SPI3 global interrupt */
void UART4_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* UART4 global interrupt */
void UART5_Handler              (void) __attribute__ ((alias("Default_Handler")));   /* UART5 global interrupt */
void TIM6_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM6 global interrupt */
void TIM7_Handler               (void) __attribute__ ((alias("Default_Handler")));   /* TIM7 global interrupt */
void DMA2_Channel1_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA2 Channel1 global interrupt */
void DMA2_Channel2_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA2 Channel2 global interrupt */
void DMA2_Channel3_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA2 Channel3 global interrupt */
void DMA2_Channel4_Handler      (void) __attribute__ ((alias("Default_Handler")));   /* DMA2 Channel4 global interrupt */
void DMA2_Channel4_5_Handler    (void) __attribute__ ((alias("Default_Handler")));   /* DMA2 Channel4 and DMA2 Channel5 global interrupts */

/**
 * @brief array of interrupt servce rotine (vector table).
 * 
 */
uint32_t *Vector_Table[] __attribute__ ((section(".isr_vector")))= 
{
    (uint32_t *)&MSP_Val,
    (uint32_t *)&Reset_Handler,          
    (uint32_t *)&NMI_Handler,            
    (uint32_t *)&HardFault_Handler,      
    (uint32_t *)&MemManage_Handler,      
    (uint32_t *)&BusFault_Handler,      
    (uint32_t *)&UsageFault_Handler,  
    0,
    0,   
    0,   
    0,   
    (uint32_t *)&SVCall_Handler,         
    (uint32_t *)&Debug_Monitor_Handler, 
    0, 
    (uint32_t *)&PendSV_Handler,         
    (uint32_t *)&SysTick_Handler,        
    (uint32_t *)&WWDG_Handler,           
    (uint32_t *)&PVD_Handler,           
    (uint32_t *)&TAMPER_Handler,         
    (uint32_t *)&RTC_Handler,            
    (uint32_t *)&FLASH_Handler,          
    (uint32_t *)&RCC_Handler,            
    (uint32_t *)&EXTI0_Handler,          
    (uint32_t *)&EXTI1_Handler,          
    (uint32_t *)&EXTI2_Handler,          
    (uint32_t *)&EXTI3_Handler,          
    (uint32_t *)&EXTI4_Handler,          
    (uint32_t *)&DMA1_Channel1_Handler,  
    (uint32_t *)&DMA1_Channel2_Handler,  
    (uint32_t *)&DMA1_Channel3_Handler,  
    (uint32_t *)&DMA1_Channel4_Handler,  
    (uint32_t *)&DMA1_Channel5_Handler,  
    (uint32_t *)&DMA1_Channel6_Handler,  
    (uint32_t *)&DMA1_Channel7_Handler,  
    (uint32_t *)&ADC1_2_Handler,         
    (uint32_t *)&USB_HP_CAN_TX_Handler,  
    (uint32_t *)&USB_LP_CAN_RX0_Handler, 
    (uint32_t *)&CAN_RX1_Handler,        
    (uint32_t *)&CAN_SCE_Handler,        
    (uint32_t *)&EXTI9_5_Handler,        
    (uint32_t *)&TIM1_BRK_Handler,       
    (uint32_t *)&TIM1_UP_Handler,        
    (uint32_t *)&TIM1_TRG_COM_Handler,   
    (uint32_t *)&TIM1_CC_Handler,        
    (uint32_t *)&TIM2_Handler,           
    (uint32_t *)&TIM3_Handler,           
    (uint32_t *)&TIM4_Handler,           
    (uint32_t *)&I2C1_EV_Handler,        
    (uint32_t *)&I2C1_ER_Handler,        
    (uint32_t *)&I2C2_EV_Handler,        
    (uint32_t *)&I2C2_ER_Handler,        
    (uint32_t *)&SPI1_Handler,           
    (uint32_t *)&SPI2_Handler,           
    (uint32_t *)&USART1_Handler,         
    (uint32_t *)&USART2_Handler,         
    (uint32_t *)&USART3_Handler,         
    (uint32_t *)&EXTI15_10_Handler,      
    (uint32_t *)&RTCAlarm_Handler,      
    (uint32_t *)&USBWakeup_Handler,      
    (uint32_t *)&TIM8_BRK_Handler,       
    (uint32_t *)&TIM8_UP_Handler,        
    (uint32_t *)&TIM8_TRG_COM_Handler,   
    (uint32_t *)&TIM8_CC_Handler,        
    (uint32_t *)&ADC3_Handler,           
    (uint32_t *)&FSMC_Handler,           
    (uint32_t *)&SDIO_Handler,           
    (uint32_t *)&TIM5_Handler,           
    (uint32_t *)&SPI3_Handler,           
    (uint32_t *)&UART4_Handler,          
    (uint32_t *)&UART5_Handler,          
    (uint32_t *)&TIM6_Handler,           
    (uint32_t *)&TIM7_Handler,           
    (uint32_t *)&DMA2_Channel1_Handler,  
    (uint32_t *)&DMA2_Channel2_Handler,  
    (uint32_t *)&DMA2_Channel3_Handler,  
    (uint32_t *)&DMA2_Channel4_Handler,  
    (uint32_t *)&DMA2_Channel4_5_Handler,   
};

static void System_Intitialization(void){
    /* Clock intitialization */

}

/**
 * @brief when the cpu power on this function handling memory.
 * 
 */
void Reset_Handler (void)
{
    /* Local Variables */
    uint32_t Section_Size   = 0;
    uint32_t *MemSourceAddr = NULL;
    uint32_t *MemDesAddr    = NULL;

    /* 1) Copy the data segment initializers from flash to SRAM */
    Section_Size  = &_edata - &_sdata;      /* Length of .data segment */
    MemSourceAddr = (uint32_t *)&_sidata;   /* Start address of .data sengement (LMA) -> Load Memory Address */
    MemDesAddr    = (uint32_t *)&_sdata;    /* Start address of .data sengement (VMA) -> Virtual Memory Address */

    for (uint32_t Counter = 0; Counter < Section_Size; Counter++)
    {
        *MemDesAddr++ = *MemSourceAddr++;
    }

    /* 2) Initialize the .bss segment with zero */
    Section_Size = &_ebss- &_sbss;        /* Length of .bss segment */
    MemDesAddr = (uint32_t *)&_sbss;     /* Start address of .bss sengement */

    for(uint32_t MemCounter = 0; MemCounter < Section_Size; MemCounter++)
    {
        *MemDesAddr++ = 0;
    }

    /* 3) Call the system intitialization function */
    System_Intitialization();

    /* 4) Call the main function */
    main();
}


void Default_Handler (void)
{

}
