/**
 * @file std_type.hpp
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 */

#ifndef STD_TYPE_HPP_
#define STD_TYPE_HPP_

/* ------------ includes ------------ */
#include <stdint.h>

namespace StdType {

    typedef uint8_t  uint8;
    typedef uint16_t  uint16;
    typedef uint32_t  uint32;
    typedef uint64_t  uint64;

    typedef int8_t  sint8;
    typedef int16_t sint16;
    typedef int32_t sint32;
    typedef int64_t sint64;
    typedef int8_t  sint8;

    typedef float  float32;
    typedef double  float64;

    typedef uint8 Std_Return;
} // namespac StdType

namespace Status {
    constexpr StdType::uint8 On = 1;
    constexpr StdType::uint8 Off = 0;

    constexpr StdType::uint8 Std_Active = 1;
    constexpr StdType::uint8 Std_Idle = 0;

    constexpr StdType::uint8 Std_High = 1;
    constexpr StdType::uint8 Std_Low = 0;

    constexpr StdType::Std_Return R_OK = 1;
    constexpr StdType::Std_Return R_ERROR = 0;
}

namespace BitMath {
    /**
     * @brief clear bit in register.
     * 
     * @param reg 
     * @param bit 
     */
    inline void CLR_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg &= ~(1 << bit);
    }

    /**
     * @brief set bit in register.
     * 
     * @param reg 
     * @param bit 
     */
    inline void SET_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg |= (1 << bit);
    }

    /**
     * @brief toggle bit in register.
     * 
     * @param reg 
     * @param bit 
     */
    inline void TOG_BIT(volatile uint8_t &reg, uint8_t bit) {
        reg ^= (1 << bit);
    }

    /**
     * @brief Get the bit from register.
     * 
     * @param reg 
     * @param bit 
     */
    inline bool GET_BIT(volatile uint8_t &reg, uint8_t bit) {
        return (reg >> bit) & 1;
    }
} // namespac BitMath

#endif