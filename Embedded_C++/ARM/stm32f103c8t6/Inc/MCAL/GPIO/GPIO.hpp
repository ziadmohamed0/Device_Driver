/*
 * GPIO.hpp
 *
 *  Created on: Apr 1, 2025
 *      Author: ziad
 */

#ifndef MCAL_GPIO_GPIO_HPP_
#define MCAL_GPIO_GPIO_HPP_

/* --------------- includes --------------- */
#include "LIB/common.hpp"

namespace GPIO {
	enum class PORT : StdType::uint32 {
		A = baseAddressesPeripheral::PortA,
		B = baseAddressesPeripheral::PortB,
		C = baseAddressesPeripheral::PortC,
		D = baseAddressesPeripheral::PortD,
		E = baseAddressesPeripheral::PortE,
	};

	enum class PIN : StdType::uint8 {
		PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,
		PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,
		PIN14,PIN15
	};

	enum class Mode : StdType::uint8 {
		InPut = 0b00,
		OutPut = 0b01,
		Alternate = 0b10,
		Analog	= 0b11,
	};

	enum class OutputType : StdType::uint8 {
		Push_Pull,
		Open_Drain,
	};

	/**
	 * @brief Enum for GPIO speed.
	 */
	enum class Speed : StdType::uint8 {
	    LOW  = 0b00, ///< Low speed
	    MED  = 0b01, ///< Medium speed
	    HIGH = 0b11  ///< High speed
	};

	/**
	 * @brief Enum for GPIO pull-up/pull-down configurations.
	 */
	enum class Pull : StdType::uint8 {
	    NONE  = 0b00, ///< No pull-up, no pull-down
	    UP    = 0b01, ///< Pull-up enabled
	    DOWN  = 0b10  ///< Pull-down enabled
	};

	/**
	 * @brief GPIO driver class.
	 */
	class GPIO {
	private:
	    PORT port; ///< GPIO port instance
	    PIN pin;   ///< GPIO pin instance
	    Mode mode;	///< GPIO mode instance
	public:
	    GPIO(PORT copyPort, PIN copyPin);

	    void configurePin(Mode copyMode, OutputType copyType, Speed copySpeed, Pull copyPull);
	    void setPinStatus();
	    bool getPinStatus();

	    void configurePort(OutputType copyType, Speed copySpeed, Pull copyPull);
	    void setPortStatus();
	    bool getPortStatus();
	};
}

#endif /* MCAL_GPIO_GPIO_HPP_ */
