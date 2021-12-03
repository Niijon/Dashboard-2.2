################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GUI/displays.c \
../Src/GUI/gui.c \
../Src/GUI/ws_leds.c 

OBJS += \
./Src/GUI/displays.o \
./Src/GUI/gui.o \
./Src/GUI/ws_leds.o 

C_DEPS += \
./Src/GUI/displays.d \
./Src/GUI/gui.d \
./Src/GUI/ws_leds.d 


# Each subdirectory must supply rules for building sources it contributes
Src/GUI/%.o: ../Src/GUI/%.c Src/GUI/subdir.mk
	arm-none-eabi-gcc -fdata-sections "$<" -mcpu=cortex-m3 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

