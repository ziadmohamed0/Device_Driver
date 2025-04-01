#ifndef _GPIO_REG_HPP
#define _GPIO_REG_HPP

/* ------------ includes ------------ */
#include "../../LIB/std_type.hpp"

constexpr StdType::uint8 MAX_REG = 4;

namespace GPIO {
    /* GPIOx Output State Registers */
    constexpr volatile uint8_t* PORT[4] = { (volatile uint8_t*)0x3B, (volatile uint8_t*)0x38, (volatile uint8_t*)0x35, (volatile uint8_t*)0x32 };

    /* GPIOx Direction Registers */
    constexpr volatile uint8_t* DDR[4] = { (volatile uint8_t*)0x3A, (volatile uint8_t*)0x37, (volatile uint8_t*)0x34, (volatile uint8_t*)0x31 };

    /* GPIOx Input State Registers */
    constexpr volatile uint8_t* PIN[4] = { (volatile uint8_t*)0x39, (volatile uint8_t*)0x36, (volatile uint8_t*)0x33, (volatile uint8_t*)0x30 };

} // namespace GPIO

#endif
