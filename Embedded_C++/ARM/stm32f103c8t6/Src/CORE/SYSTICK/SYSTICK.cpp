/*
 * SYSTICK.cpp
 *
 *  Created on: Apr 2, 2025
 *      Author: Ziad
 */

#include "CORE/SYSTICK/SYSTICK.hpp"

namespace SYSTICK {

/**
 * @brief Constructor for SYSTICK driver.
 * @param systemClockHz System clock frequency in Hz (e.g., 16MHz → 16000000)
 * @param tickMs Time per tick in milliseconds (e.g., 1ms for SysTick)
 */
SYSTICK::SYSTICK(StdType::uint32 systemClockHz, StdType::uint32 tickMs)
    : clockFrequency(systemClockHz), tickTimeMs(tickMs) {

    // Configure the reload value for the desired tick time
	StdType::uint32 reloadValue = (clockFrequency / 1000) * tickTimeMs;
	if (reloadValue > 0xFFFFFF) {
	    reloadValue = 0xFFFFFF;
	}
	REG32(RVR::Register) = reloadValue;

    // Reset the current value register
    REG32(CVR::Register) = 0;

    // Enable SysTick with processor clock and interrupt
    BitMath::SET_BIT(REG32(CSR::Register), static_cast<StdType::uint8>(CSR::PIN::ENABLE));
    BitMath::SET_BIT(REG32(CSR::Register), static_cast<StdType::uint8>(CSR::PIN::CLKSOURCE));
}

/**
 * @brief Starts the SYSTICK timer.
 */
void SYSTICK::start() {
    BitMath::SET_BIT(REG32(CSR::Register), static_cast<StdType::uint8>(CSR::PIN::ENABLE));
}

/**
 * @brief Stops the SYSTICK timer.
 */
void SYSTICK::stop() {
    BitMath::CLR_BIT(REG32(CSR::Register), static_cast<StdType::uint8>(CSR::PIN::ENABLE));
}

/**
 * @brief Checks if the SysTick timer has elapsed.
 * @return true if the COUNTFLAG is set, false otherwise.
 */
bool SYSTICK::hasElapsed() {
    return BitMath::GET_BIT(REG32(CSR::Register), static_cast<StdType::uint8>(CSR::PIN::COUNTFLAG));
}

/**
 * @brief Delays execution for a specific amount of milliseconds.
 * @param ms The number of milliseconds to delay.
 */
void SYSTICK::delayMs(StdType::uint32 ms) {
    for (StdType::uint32 i = 0; i < ms; i++) {
        while (!hasElapsed()); // Wait for the COUNTFLAG to be set
    }
}

} // namespace SYSTICK
