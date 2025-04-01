/**
 * @file GPIO.cpp
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 */

#include "GPIO.hpp"

void GPIO::GPIO_PIN::setDirection(pinDirection copyDirection) {
    switch(copyDirection) {
    case pinDirection::output:
        BitMath::SET_BIT(*DDR[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
        (GPIO::GPIO_PIN::Pin_Number));
        break;
    case pinDirection::input:
        BitMath::CLR_BIT(*DDR[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
        (GPIO::GPIO_PIN::Pin_Number));
        break;
    }
}

void GPIO::GPIO_PIN::setValue(pinStatus copyState) {
    switch(copyState) {
    case pinStatus::High:
        BitMath::SET_BIT(*PORT[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
        (GPIO::GPIO_PIN::Pin_Number));
        break;
    case pinStatus::Low:
        BitMath::CLR_BIT(*PORT[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
        (GPIO::GPIO_PIN::Pin_Number));
        break;
    case pinStatus::Toggle:
        BitMath::TOG_BIT(*PORT[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
        (GPIO::GPIO_PIN::Pin_Number));
        break;
    }
}

bool GPIO::GPIO_PIN::getValue() {
    return BitMath::GET_BIT(*PIN[static_cast<StdType::uint8> (GPIO::GPIO_PIN::Port_Number)], 
    (GPIO::GPIO_PIN::Pin_Number));
}



void GPIO::GPIO_PORT::setDirection(portDirection copyDirection) {
    *DDR[static_cast<StdType::uint8> (GPIO::GPIO_PORT::Port_Number)] = static_cast<StdType::uint8>(copyDirection);
}

void GPIO::GPIO_PORT::setValue(portStatus copyState) {
    *PORT[static_cast<StdType::uint8> (GPIO::GPIO_PORT::Port_Number)] = static_cast<StdType::uint8>(copyState);
}

bool GPIO::GPIO_PORT::getValue() {
    return *PIN[static_cast<StdType::uint8> (GPIO::GPIO_PORT::Port_Number)];
}