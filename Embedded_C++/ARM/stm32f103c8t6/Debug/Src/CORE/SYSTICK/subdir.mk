################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/CORE/SYSTICK/SYSTICK.cpp 

OBJS += \
./Src/CORE/SYSTICK/SYSTICK.o 

CPP_DEPS += \
./Src/CORE/SYSTICK/SYSTICK.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CORE/SYSTICK/%.o Src/CORE/SYSTICK/%.su Src/CORE/SYSTICK/%.cyclo: ../Src/CORE/SYSTICK/%.cpp Src/CORE/SYSTICK/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-CORE-2f-SYSTICK

clean-Src-2f-CORE-2f-SYSTICK:
	-$(RM) ./Src/CORE/SYSTICK/SYSTICK.cyclo ./Src/CORE/SYSTICK/SYSTICK.d ./Src/CORE/SYSTICK/SYSTICK.o ./Src/CORE/SYSTICK/SYSTICK.su

.PHONY: clean-Src-2f-CORE-2f-SYSTICK

