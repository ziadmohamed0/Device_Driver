/*
 * RCC.hpp
 *
 *  Created on: Apr 1, 2025
 *      Author: ziad
 */

#ifndef MCAL_RCC_RCC_HPP_
#define MCAL_RCC_RCC_HPP_

/* --------------- includes --------------- */
#include "../../LIB/common.hpp"

namespace RCC {
	namespace CR {
		constexpr StdType::uint32 Base_Addresses  = (baseAddressesPeripheral::RCC + 0x000);

		/**
		 * @brief : Clock control register.
		 */
		enum class PIN : StdType::uint8{
			HSION, HSIRDY, HSITRIM0 = 3, HSITRIM1, HSITRIM2, HSITRIM3, HSITRIM4,
			HSICAL0, HSICAL1, HSICAL2, HSICAL3, HSICAL4, HSICAL5, HSICAL6, HSICAL7,
			HSEON, HSERD, HSEBYP, CSSON, PLLON = 24, PLLRDY, PLL2ON, PLL2RDY,
			PLL3ON, PLL3RDY
		};
	}

	namespace CFGR{
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x004);

		/**
		 * @brief : Clock configuration register.
		 */
		enum class PIN : StdType::uint8 {
			SW0, SW1, SWS0, SWS1, HPRE0, HPRE1, HPRE2, HPRE3, PPRE10,
			PPRE11, PPRE12, PPRE20, PPRE21, PPRE22,ADC_PRE0, ADC_PRE1,
			PLLSRC, PLLXTPRE, PLLMUL0, PLLMUL1, PLLMUL2, PLLMUL3, OTGFSPRE,
			MCO0 = 24, MCO1, MCO2, MCO3
		};
	}

	namespace CIR{
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x008);
		/**
		 * @brief : Clock interrupt register.
		 */
		enum class PIN : StdType::uint8 {
			LSIRDYF, LSERDYF, HSIRDYF, HSERDYF, PLLRDYF, PLL2RDYF, PLL3RDYF,
			CSSF, LSIRDYIE, LSERDYIE, HSIRDYIE, HSERDYIE, PLLRDYIE, PLL2RDYIE,
			PLL3RDYIE, LSIRDYC = 16, LSERDYC, HSIRDYC, HSERDYC, PLLRDYC, PLL2RDYC,
			PLL3RDYC, CSSC
		};
	}

	namespace APB2RSTR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x00C);
		/**
		 * @brief : APB2 peripheral reset register.
		 */
		enum class PIN : StdType::uint8 {
			AFIORST, IOPARST = 2, IOPBRST, IOPCRST, IOPDRST, IOPERST, ADC1RST = 9, ADC2RST,
			TIM1RST, SPI1RST, USART1RST = 14,
		};
	}

	namespace APB1RSTR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x010);

		/**
		 * @brief : APB1 peripheral reset register.
		 */
		enum class PIN : StdType::uint8 {
			TIM2RST, TIM3RST, TIM4RST, TIM5RST, TIM6RST, TIM7RST, WWDGRST = 11, SPI2RST = 14,
			SPI3RST, USART2RST = 17, USART3RST, USART4RST, USART5RST, I2C1RST, I2C2RST, CAN1RST = 25,
			CAN2RST, BKPRST, PWRRST, DACRST
		};
	}

	namespace AHBENR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x014);

		/**
		 * @brief : AHB Peripheral Clock enable register
		 */
		enum class PIN : StdType::uint8 {
			DMA1EN, DMA2EN, SRAMEN, FLITFEN = 4, CRCEN = 6, OTGFSEN = 12,
			ETHMACEN = 14, ETHMACTXEN, ETHMACRXEN
		};
	}

	namespace APB2ENR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x018);

		/**
		 * @brief : APB2 peripheral clock enable register.
		 */
		enum class PIN : StdType::uint8 {
			AFIOEN, IOPAEN = 2, IOPBEN, IOPCEN, IOPDEN, IOPEEN, ADC1EN = 9, ADC2EN,
			TIM1EN, SPI1EN, USART1EN = 14,
		};
	}

	namespace APB1ENR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x01C);

		/**
		 * @brief : APB1 peripheral clock enable register.
		 */
		enum class PIN : StdType::uint8 {
			TIM2EN, TIM3EN, TIM4EN, TIM5EN, TIM6EN, TIM7EN, WWDGEN = 11, SPI2EN = 14,
			SPI3EN, USART2EN = 17, USART3EN, USART4EN, USART5EN, I2C1EN, I2C2EN, CAN1EN = 25,
			CAN2EN, BKPEN, PWREN, DACEN
		};
	}

	namespace {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x020);

		/**
		 * @brief : Backup domain control register.
		 */
		enum class PIN : StdType::uint8 {
			LSEON, LSERDY, LSEBYP, RTCSEL0 = 8, RTCSEL1, RTCEN = 15, BDRST
		};
	}

	namespace CSR {
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x024);

		/**
		 * @brief : Control/status register.
		 */
		enum class PIN : StdType::uint8 {
			LSION, LSIRDY, RMVF = 24, PINRSTF = 26, PORRSTF, SFTRSTF, IWDGRSTF,
			WWDGRSTF, LPWRRSTF
		};
	}

	namespace AHBSTR{
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x028);

		/**
		 * @brief : AHB peripheral clock reset register.
		 */
		enum class PIN : StdType::uint8 {
			OTGFSRST = 12, ETHMACRST = 14
		};
	}

	namespace CFGR2{
		constexpr StdType::uint32 Base_Addresses = (baseAddressesPeripheral::RCC + 0x02C);

		/**
		 * brief : Clock configuration register2.
		 */
		enum class PIN  : StdType::uint8 {
			PREDIV10, PREDIV11, PREDIV12, PREDIV13, PREDIV20, PREDIV21, PREDIV22, PREDIV23,
			PLL2MUL0, PLL2MUL1, PLL2MUL2, PLL2MUL3, PLL3MUL0, PLL3MUL1, PLL3MUL2, PLL3MUL3,
			PREDIV1SRC, I2S2SRC, I2S3SRC
		};
	}


	class RCC {
	private:
		CFGR::PIN copyClockSource;
	public:
		RCC(CFGR::PIN copyClock_Source);

        static void enablePeripheral(AHBENR::PIN copyPeriph);
        static void enablePeripheral(APB1ENR::PIN copyPeriph);
        static void enablePeripheral(APB2ENR::PIN copyPeriph);

        static void disablePeripheral(AHBENR::PIN copyPeriph);
        static void disablePeripheral(APB1ENR::PIN copyPeriph);
        static void disablePeripheral(APB2ENR::PIN copyPeriph);

        static void resetPeripheral(AHBSTR::PIN copyPeriph);
        static void resetPeripheral(APB1RSTR::PIN copyPeriph);
        static void resetPeripheral(APB2RSTR::PIN copyPeriph);

        static void setSystemClock(CFGR::PIN copyClockSource);
        static void setPLLMultiplier(StdType::uint8 copyMultiplier);
	};
}



#endif /* MCAL_RCC_RCC_HPP_ */
