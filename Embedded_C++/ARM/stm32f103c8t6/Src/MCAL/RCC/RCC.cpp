/*
 * RCC.cpp
 *
 *  Created on: Apr 1, 2025
 *      Author: Ziad Mohammed Fathy
 */

#include "MCAL/RCC/RCC.hpp"

/**
 * @brief RCC Constructor.
 * Initializes RCC with the provided clock source.
 * @param clock The clock source to be set (HSE, HSI, PLL, etc.).
 */
RCC::RCC::RCC(CFGR::PIN	copyClock_Source) : copyClockSource(copyClock_Source) {
	RCC::setSystemClock(copyClockSource);
}

/**
 * @brief Enables a specific peripheral on the AHB bus.
 *
 * @param copyPeriph The peripheral to enable.
 */
void RCC::RCC::enablePeripheral(AHBENR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(AHBENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Enables a specific peripheral on the APB1 bus.
 *
 * @param copyPeriph The peripheral to enable.
 */
void RCC::RCC::enablePeripheral(APB1ENR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(APB1ENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Enables a specific peripheral on the APB2 bus.
 *
 * @param copyPeriph The peripheral to enable.
 */
void RCC::RCC::enablePeripheral(APB2ENR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(APB2ENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Disables a specific peripheral on the AHB bus.
 *
 * @param copyPeriph The peripheral to disable.
 */
void RCC::RCC::disablePeripheral(AHBENR::PIN copyPeriph) {
	BitMath::CLR_BIT(REG32(AHBENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Disables a specific peripheral on the APB1 bus.
 *
 * @param copyPeriph The peripheral to disable.
 */
void RCC::RCC::disablePeripheral(APB1ENR::PIN copyPeriph) {
	BitMath::CLR_BIT(REG32(APB1ENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Disables a specific peripheral on the APB2 bus.
 *
 * @param copyPeriph The peripheral to disable.
 */
void RCC::RCC::disablePeripheral(APB2ENR::PIN copyPeriph) {
	BitMath::CLR_BIT(REG32(APB2ENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Resets a specific peripheral on the AHB bus.
 *
 * @param copyPeriph The peripheral to reset.
 */
void RCC::RCC::resetPeripheral(AHBSTR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(AHBENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
	BitMath::CLR_BIT(REG32(AHBENR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Resets a specific peripheral on the APB1 bus.
 *
 * @param copyPeriph The peripheral to reset.
 */
void RCC::RCC::resetPeripheral(APB1RSTR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(APB1RSTR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
	BitMath::CLR_BIT(REG32(APB1RSTR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Resets a specific peripheral on the APB2 bus.
 *
 * @param copyPeriph The peripheral to reset.
 */
void RCC::RCC::resetPeripheral(APB2RSTR::PIN copyPeriph) {
	BitMath::SET_BIT(REG32(APB2RSTR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
	BitMath::CLR_BIT(REG32(APB2RSTR::Base_Addresses), static_cast<StdType::uint8>(copyPeriph));
}

/**
 * @brief Sets the system clock source.
 *
 * @param copyClockSource The clock source to set.
 */
void RCC::RCC::setSystemClock(CFGR::PIN copyClockSource) {
	StdType::uint32 cfgr = REG32(CFGR::Base_Addresses);
    cfgr &= ~(0x3);
    cfgr |= static_cast<StdType::uint32>(copyClockSource);
    REG32(CFGR::Base_Addresses) = cfgr;
}

/**
 * @brief Configures the PLL multiplier factor.
 *
 * @param copyMultiplier The PLL multiplier (valid range: 2 to 16).
 */
void RCC::RCC::setPLLMultiplier(StdType::uint8 copyMultiplier) {
    if (copyMultiplier < 2 || copyMultiplier > 16) return;

    StdType::uint32 cfgr = REG32(CFGR::Base_Addresses);
    cfgr &= ~(0xF << 18);
    cfgr |= ((copyMultiplier - 2) << 18);
    REG32(CFGR::Base_Addresses) = cfgr;
}
