/**
 * @file GPIO.hpp
 * @author Ziad Mohammed Fathy
 * @brief 
 * @version 0.1
 * @date 2025-03-31
 */

#ifndef _GPIO_HPP_
#define _GPIO_HPP_

/* ------------ includes ------------ */
#include "reg.hpp"

namespace GPIO {
    enum class portNumber : StdType::uint8 {
        A,
        B,
        C,
        D
    };

    enum class pinDirection : StdType::uint8 {
        input,
        output
    };

    enum class portDirection : StdType::uint8 {
        input = 0x00,
        output  = 0xFF
    };

    enum class pinStatus : StdType::uint8 {
        Low,
        High,
        Toggle
    };

    enum class portStatus : StdType::uint8 {
        Low = 0x00,
        High = 0xFF
    };

    class GPIO_PIN {
        private:
            portNumber Port_Number;  
            StdType::uint8 Pin_Number;
        public:
            GPIO_PIN(portNumber copyPortNumber, StdType::uint8 copyPinNumber) : 
            Port_Number(copyPortNumber), Pin_Number(copyPinNumber) {}
            void setDirection(pinDirection copyDirection);
            void setValue(pinStatus copyState);
            bool getValue();
    };

    class GPIO_PORT {
        private:
            portNumber Port_Number;  
        public:
            GPIO_PORT(portNumber copyPortNumber) : 
            Port_Number(copyPortNumber) {}
            void setDirection(portDirection copyDirection);
            void setValue(portStatus copyState);
            bool getValue();
    };
} // namespace GPIO


#endif