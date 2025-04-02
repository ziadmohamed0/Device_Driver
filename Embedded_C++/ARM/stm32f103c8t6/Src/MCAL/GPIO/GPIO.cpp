/*
 * GPIO.cpp
 *
 *  Created on: Apr 1, 2025
 *      Author: ziad
 */

#include "MCAL/GPIO/GPIO.hpp"
#include "MCAL/RCC/RCC.hpp"

GPIO::GPIO::GPIO(PORT copyPort, PIN copyPin) : port(copyPort), pin(copyPin) {
	switch(port) {
	case PORT::A:
		RCC::RCC::enablePeripheral(RCC::APB2ENR::PIN::IOPAEN);
		break;
	case PORT::B:
		RCC::RCC::enablePeripheral(RCC::APB2ENR::PIN::IOPBEN);
		break;
	case PORT::C:
		RCC::RCC::enablePeripheral(RCC::APB2ENR::PIN::IOPCEN);
		break;
	case PORT::D:
		RCC::RCC::enablePeripheral(RCC::APB2ENR::PIN::IOPDEN);
		break;
	case PORT::E:
		RCC::RCC::enablePeripheral(RCC::APB2ENR::PIN::IOPEEN);
		break;
	}
}

void GPIO::GPIO::configurePin(Mode copyMode, OutputType copyType, Speed copySpeed, Pull copyPull) {

}

void GPIO::GPIO::setPinStatus() {

}

bool GPIO::GPIO::getPinStatus() {
	return true;
}
