/* 
 * File:   Mcal_ADC_init.h
 * Author: s
 *
 * Created on November 11, 2024, 1:42 AM
 */

#ifndef MCAL_ADC_INIT_H
#define	MCAL_ADC_INIT_H

/* -------------------- Include Start -------------------- */
#include "../Mcal_interrupt/Mcal_internal_interrupt.h"
#include "MCAL_ADC_cfg.h"
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
#define ADC_AN0_ANALOG_FUNCTIONALITY                        0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY                        0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY                        0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY                        0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY                        0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY                        0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY                        0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY                        0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY                        0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY                        0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY                       0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY                       0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY                       0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY                        0x01
#define ADC_ALL_DIGITAL_FUNCTIONALITY                       0x0F


#define ADC_RESULT_FORMAT_RIGHT                             0x01U
#define ADC_RESULT_FORMAT_LEFT                              0x00U

#define ADC_VOLTAGE_REF_ENABLE                              0x01U
#define ADC_VOLTAGE_REF_DISABLE                             0x00U

#define ADC_CONVERSION_COMPLETED                            1U
#define ADC_CONVERSION_INPROGRESS                           0U

/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define MCAL_ADC_CONVERSION_STATUS(void)                    (ADCON0bits.GO_nDONE)

#define MCAL_ADC_START_CONVERSION(void)                     (ADCON0bits.GODONE = 1)

#define MCAL_ADC_CONVERSION_Enable(void)                    (ADCON0bits.ADON = 1)
#define MCAL_ADC_CONVERSION_Disable(void)                   (ADCON0bits.ADON = 0)

#define MCAL_ADC_VOLATGE_ENABLE(void)                       do{ADCON1bits.VCFG1 = 1;\
                                                                ADCON1bits.VCFG0 = 1;\
                                                            }while(0)

#define MCAL_ADC_VOLATGE_DISABLE(void)                      do{ADCON1bits.VCFG1 = 0;\
                                                                ADCON1bits.VCFG0 = 0;\
                                                            }while(0)

#define MCAL_ADC_ANALOGE_DIGITAL_PORT_CONFIG(_CFG)          (ADCON1bits.PCFG = _CFG)


#define MCAL_ADC_RESULT_RIGHT_FORMAT(void)                  (ADCON2bits.ADFM = 1)
#define MCAL_ADC_RESULT_LEFT_FORMAT(void)                   (ADCON2bits.ADFM = 0)
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
typedef enum {
    ADC_CHANAL_AN1 = 0,
    ADC_CHANAL_AN2,
    ADC_CHANAL_AN3,
    ADC_CHANAL_AN4,
    ADC_CHANAL_AN5,
    ADC_CHANAL_AN6,
    ADC_CHANAL_AN7,
    ADC_CHANAL_AN8,
    ADC_CHANAL_AN9,
    ADC_CHANAL_AN10,
    ADC_CHANAL_AN11,
    ADC_CHANAL_AN12,
    ADC_CHANAL_AN13,
}ADC_chanal_select_t;

typedef enum {
    ADC_TAD_0 = 0,
    ADC_TAD_2,
    ADC_TAD_4,
    ADC_TAD_6,
    ADC_TAD_8,
    ADC_TAD_12,
    ADC_TAD_16,
    ADC_TAD_20,
}ADC_TAD_t;

typedef enum {
    ADC_CLK_CONVERSION_FOSC_DIV_2 = 0,
    ADC_CLK_CONVERSION_FOSC_DIV_8,
    ADC_CLK_CONVERSION_FOSC_DIV_32,
    ADC_CLK_CONVERSION_FOSC_DIV_FRC,
    ADC_CLK_CONVERSION_FOSC_DIV_4,
    ADC_CLK_CONVERSION_FOSC_DIV_16,
    ADC_CLK_CONVERSION_FOSC_DIV_64,
}ADC_Conversion_CLK_t;

typedef struct {
#if ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_ENABLE
    void(* ADCinterruptHandler)(void);
    Interrupt_Priorety_cfg_t Priorety;
#elif ADC_INTERRUPT_FUTUR == ADC_INTERRUPT_FUTUR_DISABLE
    
#endif
    ADC_TAD_t               AcquisitionClock;
    ADC_Conversion_CLK_t    ConversionClock;
    ADC_chanal_select_t     AdcChanall;
    uint8_t                 VolatageRefrance    :1;
    uint8_t                 ResultFormat        :1;
    uint8_t                 ADC_Reserved        :6;
}ADC_t;

typedef uint16_t                            ADC_Resulte_t;
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
Std_Return MCAL_ADC_init(const ADC_t *copyADC);
Std_Return MCAL_ADC_Deinit(const ADC_t *copyADC);
Std_Return MCAL_ADC_SelectChanal(const ADC_t *copyADC, ADC_chanal_select_t copyChanal);
Std_Return MCAL_ADC_StartConversion(const ADC_t *copyADC);
Std_Return MCAL_ADC_isConversionDone(const ADC_t *copyADC, uint8_t *copyConversionStatus);
Std_Return MCAL_ADC_getConversionResult(const ADC_t *copyADC, ADC_Resulte_t *copyConversionResult);
Std_Return MCAL_ADC_getConversion_Blocking(const ADC_t *copyADC, ADC_chanal_select_t copyChanal, ADC_Resulte_t* copyConversionResult);
Std_Return MCAL_ADC_startConversion_Interrupt(const ADC_t *copyADC, ADC_chanal_select_t copyChanal);
/* -------------------- API End -------------------- */

#endif	/* MCAL_ADC_INIT_H */

