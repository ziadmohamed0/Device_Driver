cmake_minimum_required(VERSION 3.10)

project(ATmega32_Driver LANGUAGES CXX)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)

set(MCU atmega32)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -Os -Wall -std=c++11 -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections")

set(SOURCE_FILES
    APP/main.cpp
    MCAL/GPIO/GPIO.cpp
    HAL/Led/prog.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/LIB
    ${CMAKE_SOURCE_DIR}/MCAL/GPIO
    ${CMAKE_SOURCE_DIR}/HAL/Led
)

add_executable(ATmega32_Driver.elf ${SOURCE_FILES})

add_custom_target(ATmega32_Driver.hex ALL
    COMMAND ${CMAKE_OBJCOPY} -O ihex ATmega32_Driver.elf ATmega32_Driver.hex
    DEPENDS ATmega32_Driver.elf
)
