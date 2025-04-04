/**
 * @file std_type.hpp
 * @author Ziad Mohammed Fathy
 * @brief This file defines various types, constants, and inline functions used in embedded systems programming.
 * @version 0.1
 * @date 2025-03-31
 */

#ifndef _LIB_STD_TYPE_HPP_
#define _LIB_STD_TYPE_HPP_

/* ------------ includes ------------ */
#include <stdint.h>

namespace StdType {
    /**
     * @brief Define custom data types for unsigned integers of 8, 16, 32, and 64 bits.
     */
    typedef uint8_t  	uint8;  ///< 8-bit unsigned integer
    typedef uint16_t  	uint16; ///< 16-bit unsigned integer
    typedef uint32_t  	uint32; ///< 32-bit unsigned integer
    typedef uint64_t  	uint64; ///< 64-bit unsigned integer

    /**
     * @brief Define custom data types for signed integers of 8, 16, 32, and 64 bits.
     */
    typedef int8_t  	sint8;  ///< 8-bit signed integer
    typedef int16_t  	sint16; ///< 16-bit signed integer
    typedef int32_t  	sint32; ///< 32-bit signed integer
    typedef int64_t  	sint64; ///< 64-bit signed integer

    typedef float  		float32; ///< 32-bit floating point
    typedef double 	 	float64; ///< 64-bit floating point

    typedef uint8 		Std_Return; ///< Return type, typically used for status codes (e.g., success or error)
} // namespace StdType


namespace Status {
    /**
     * @brief Constants to represent common status values.
     */
    constexpr StdType::uint8 ON = 1; ///< Represent "on" state
    constexpr StdType::uint8 OFF = 0; ///< Represent "off" state

    constexpr StdType::uint8 Std_Active = 1; ///< Represent active state
    constexpr StdType::uint8 Std_Idle = 0; ///< Represent idle state

    constexpr StdType::uint8 Std_High = 1; ///< Represent high state
    constexpr StdType::uint8 Std_Low = 0; ///< Represent low state

    constexpr StdType::Std_Return R_OK = 1; ///< Represent success status
    constexpr StdType::Std_Return R_ERROR = 0; ///< Represent error status
}

namespace BitMath {

	#define REG32(x) (*((volatile StdType::uint8 *)(x)))

    /**
     * @brief Bitwise manipulation functions for modifying bits in registers.
     */

    /**
     * @brief Clear a specific bit in a register.
     * 
     * @param reg The register to modify.
     * @param bit The bit position to clear.
     */
    inline void CLR_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg &= ~(1 << bit);
    }

    /**
     * @brief Set a specific bit in a register.
     * 
     * @param reg The register to modify.
     * @param bit The bit position to set.
     */
    inline void SET_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg |= (1 << bit);
    }

    /**
     * @brief Toggle a specific bit in a register.
     * 
     * @param reg The register to modify.
     * @param bit The bit position to toggle.
     */
    inline void TOG_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg ^= (1 << bit);
    }

    /**
     * @brief Get the value of a specific bit in a register.
     * 
     * @param reg The register to check.
     * @param bit The bit position to check.
     * @return `true` if the bit is set, `false` if it is clear.
     */
    inline bool GET_BIT(volatile uint8_t &reg, uint8_t bit) {
        return (reg >> bit) & 1;
    }
} // namespace BitMath

namespace baseAddressesPeripheral {
    /**
     * @brief Base addresses of various peripheral registers in an STM32 microcontroller.
     */
    constexpr StdType::uint32 TIM2 			= 0x40000000; ///< Timer 2 base address
    constexpr StdType::uint32 TIM3 			= 0x40000400; ///< Timer 3 base address
    constexpr StdType::uint32 TIM4 			= 0x40000800; ///< Timer 4 base address
    constexpr StdType::uint32 RTC 			= 0x40002800; ///< Real-Time Clock base address
    constexpr StdType::uint32 WWDG 			= 0x40002C00; ///< Window Watchdog base address
    constexpr StdType::uint32 IWDG 			= 0x40003000; ///< Independent Watchdog base address
    constexpr StdType::uint32 SPI2 			= 0x40003800; ///< SPI 2 base address
    constexpr StdType::uint32 USART2 		= 0x40004400; ///< USART 2 base address
    constexpr StdType::uint32 USART3 		= 0x40004800; ///< USART 3 base address
    constexpr StdType::uint32 I2C1 			= 0x40005400; ///< I2C 1 base address
    constexpr StdType::uint32 I2C2 			= 0x40005800; ///< I2C 2 base address
    constexpr StdType::uint32 USBreg 		= 0x40005C00; ///< USB peripheral register base address
    constexpr StdType::uint32 CAN_USB_SRAM 	= 0x40006000; ///< CAN/USB SRAM base address
    constexpr StdType::uint32 bxCAN 		= 0x40006400; ///< bxCAN base address
    constexpr StdType::uint32 BKP	 		= 0x40006C00; ///< Backup registers base address
    constexpr StdType::uint32 PWR 			= 0x40007000; ///< Power control base address
    constexpr StdType::uint32 AFIO 			= 0x40010000; ///< Alternate function I/O base address
    constexpr StdType::uint32 EXTI 			= 0x40010400; ///< External interrupt base address
    constexpr StdType::uint32 PortA	 		= 0x40010800; ///< Port A base address
    constexpr StdType::uint32 PortB 		= 0x40010C00; ///< Port B base address
    constexpr StdType::uint32 PortC 		= 0x40011000; ///< Port C base address
    constexpr StdType::uint32 PortD 		= 0x40011400; ///< Port D base address
    constexpr StdType::uint32 PortE 		= 0x40011800; ///< Port E base address
    constexpr StdType::uint32 ADC1 			= 0x40012400; ///< ADC 1 base address
    constexpr StdType::uint32 ADC2	 		= 0x40012800; ///< ADC 2 base address
    constexpr StdType::uint32 TIM1 			= 0x40012C00; ///< Timer 1 base address
    constexpr StdType::uint32 SPI1 			= 0x40013000; ///< SPI 1 base address
    constexpr StdType::uint32 USART1 		= 0x40013800; ///< USART 1 base address
    constexpr StdType::uint32 DMA 			= 0x40020000; ///< DMA controller base address
    constexpr StdType::uint32 RCC 			= 0x40021000; ///< Reset and clock control base address
    constexpr StdType::uint32 Flash 		= 0x40022000; ///< Flash memory control base address
    constexpr StdType::uint32 CRC 			= 0x40023000; ///< CRC calculation unit base address
}

#endif
