################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/u8glib/src/u8g_arm.c \
../Drivers/u8glib/src/u8g_bitmap.c \
../Drivers/u8glib/src/u8g_circle.c \
../Drivers/u8glib/src/u8g_clip.c \
../Drivers/u8glib/src/u8g_com_api.c \
../Drivers/u8glib/src/u8g_com_api_16gr.c \
../Drivers/u8glib/src/u8g_com_i2c.c \
../Drivers/u8glib/src/u8g_com_io.c \
../Drivers/u8glib/src/u8g_com_msp430_hw_spi.c \
../Drivers/u8glib/src/u8g_com_null.c \
../Drivers/u8glib/src/u8g_com_std_sw_spi.c \
../Drivers/u8glib/src/u8g_cursor.c \
../Drivers/u8glib/src/u8g_delay.c \
../Drivers/u8glib/src/u8g_dev_gprof.c \
../Drivers/u8glib/src/u8g_dev_null.c \
../Drivers/u8glib/src/u8g_dev_ssd1306_128x32.c \
../Drivers/u8glib/src/u8g_dev_ssd1306_128x64.c \
../Drivers/u8glib/src/u8g_dev_ssd1306_64x48.c \
../Drivers/u8glib/src/u8g_dev_ssd1309_128x64.c \
../Drivers/u8glib/src/u8g_ellipse.c \
../Drivers/u8glib/src/u8g_font.c \
../Drivers/u8glib/src/u8g_font_data.c \
../Drivers/u8glib/src/u8g_line.c \
../Drivers/u8glib/src/u8g_ll_api.c \
../Drivers/u8glib/src/u8g_page.c \
../Drivers/u8glib/src/u8g_pb.c \
../Drivers/u8glib/src/u8g_pb14v1.c \
../Drivers/u8glib/src/u8g_pb16h1.c \
../Drivers/u8glib/src/u8g_pb16h2.c \
../Drivers/u8glib/src/u8g_pb16v1.c \
../Drivers/u8glib/src/u8g_pb16v2.c \
../Drivers/u8glib/src/u8g_pb32h1.c \
../Drivers/u8glib/src/u8g_pb8h1.c \
../Drivers/u8glib/src/u8g_pb8h1f.c \
../Drivers/u8glib/src/u8g_pb8h2.c \
../Drivers/u8glib/src/u8g_pb8h8.c \
../Drivers/u8glib/src/u8g_pb8v1.c \
../Drivers/u8glib/src/u8g_pb8v2.c \
../Drivers/u8glib/src/u8g_pbxh16.c \
../Drivers/u8glib/src/u8g_pbxh24.c \
../Drivers/u8glib/src/u8g_polygon.c \
../Drivers/u8glib/src/u8g_rect.c \
../Drivers/u8glib/src/u8g_rot.c \
../Drivers/u8glib/src/u8g_scale.c \
../Drivers/u8glib/src/u8g_state.c \
../Drivers/u8glib/src/u8g_u16toa.c \
../Drivers/u8glib/src/u8g_u8toa.c \
../Drivers/u8glib/src/u8g_virtual_screen.c 

OBJS += \
./Drivers/u8glib/src/u8g_arm.o \
./Drivers/u8glib/src/u8g_bitmap.o \
./Drivers/u8glib/src/u8g_circle.o \
./Drivers/u8glib/src/u8g_clip.o \
./Drivers/u8glib/src/u8g_com_api.o \
./Drivers/u8glib/src/u8g_com_api_16gr.o \
./Drivers/u8glib/src/u8g_com_i2c.o \
./Drivers/u8glib/src/u8g_com_io.o \
./Drivers/u8glib/src/u8g_com_msp430_hw_spi.o \
./Drivers/u8glib/src/u8g_com_null.o \
./Drivers/u8glib/src/u8g_com_std_sw_spi.o \
./Drivers/u8glib/src/u8g_cursor.o \
./Drivers/u8glib/src/u8g_delay.o \
./Drivers/u8glib/src/u8g_dev_gprof.o \
./Drivers/u8glib/src/u8g_dev_null.o \
./Drivers/u8glib/src/u8g_dev_ssd1306_128x32.o \
./Drivers/u8glib/src/u8g_dev_ssd1306_128x64.o \
./Drivers/u8glib/src/u8g_dev_ssd1306_64x48.o \
./Drivers/u8glib/src/u8g_dev_ssd1309_128x64.o \
./Drivers/u8glib/src/u8g_ellipse.o \
./Drivers/u8glib/src/u8g_font.o \
./Drivers/u8glib/src/u8g_font_data.o \
./Drivers/u8glib/src/u8g_line.o \
./Drivers/u8glib/src/u8g_ll_api.o \
./Drivers/u8glib/src/u8g_page.o \
./Drivers/u8glib/src/u8g_pb.o \
./Drivers/u8glib/src/u8g_pb14v1.o \
./Drivers/u8glib/src/u8g_pb16h1.o \
./Drivers/u8glib/src/u8g_pb16h2.o \
./Drivers/u8glib/src/u8g_pb16v1.o \
./Drivers/u8glib/src/u8g_pb16v2.o \
./Drivers/u8glib/src/u8g_pb32h1.o \
./Drivers/u8glib/src/u8g_pb8h1.o \
./Drivers/u8glib/src/u8g_pb8h1f.o \
./Drivers/u8glib/src/u8g_pb8h2.o \
./Drivers/u8glib/src/u8g_pb8h8.o \
./Drivers/u8glib/src/u8g_pb8v1.o \
./Drivers/u8glib/src/u8g_pb8v2.o \
./Drivers/u8glib/src/u8g_pbxh16.o \
./Drivers/u8glib/src/u8g_pbxh24.o \
./Drivers/u8glib/src/u8g_polygon.o \
./Drivers/u8glib/src/u8g_rect.o \
./Drivers/u8glib/src/u8g_rot.o \
./Drivers/u8glib/src/u8g_scale.o \
./Drivers/u8glib/src/u8g_state.o \
./Drivers/u8glib/src/u8g_u16toa.o \
./Drivers/u8glib/src/u8g_u8toa.o \
./Drivers/u8glib/src/u8g_virtual_screen.o 

C_DEPS += \
./Drivers/u8glib/src/u8g_arm.d \
./Drivers/u8glib/src/u8g_bitmap.d \
./Drivers/u8glib/src/u8g_circle.d \
./Drivers/u8glib/src/u8g_clip.d \
./Drivers/u8glib/src/u8g_com_api.d \
./Drivers/u8glib/src/u8g_com_api_16gr.d \
./Drivers/u8glib/src/u8g_com_i2c.d \
./Drivers/u8glib/src/u8g_com_io.d \
./Drivers/u8glib/src/u8g_com_msp430_hw_spi.d \
./Drivers/u8glib/src/u8g_com_null.d \
./Drivers/u8glib/src/u8g_com_std_sw_spi.d \
./Drivers/u8glib/src/u8g_cursor.d \
./Drivers/u8glib/src/u8g_delay.d \
./Drivers/u8glib/src/u8g_dev_gprof.d \
./Drivers/u8glib/src/u8g_dev_null.d \
./Drivers/u8glib/src/u8g_dev_ssd1306_128x32.d \
./Drivers/u8glib/src/u8g_dev_ssd1306_128x64.d \
./Drivers/u8glib/src/u8g_dev_ssd1306_64x48.d \
./Drivers/u8glib/src/u8g_dev_ssd1309_128x64.d \
./Drivers/u8glib/src/u8g_ellipse.d \
./Drivers/u8glib/src/u8g_font.d \
./Drivers/u8glib/src/u8g_font_data.d \
./Drivers/u8glib/src/u8g_line.d \
./Drivers/u8glib/src/u8g_ll_api.d \
./Drivers/u8glib/src/u8g_page.d \
./Drivers/u8glib/src/u8g_pb.d \
./Drivers/u8glib/src/u8g_pb14v1.d \
./Drivers/u8glib/src/u8g_pb16h1.d \
./Drivers/u8glib/src/u8g_pb16h2.d \
./Drivers/u8glib/src/u8g_pb16v1.d \
./Drivers/u8glib/src/u8g_pb16v2.d \
./Drivers/u8glib/src/u8g_pb32h1.d \
./Drivers/u8glib/src/u8g_pb8h1.d \
./Drivers/u8glib/src/u8g_pb8h1f.d \
./Drivers/u8glib/src/u8g_pb8h2.d \
./Drivers/u8glib/src/u8g_pb8h8.d \
./Drivers/u8glib/src/u8g_pb8v1.d \
./Drivers/u8glib/src/u8g_pb8v2.d \
./Drivers/u8glib/src/u8g_pbxh16.d \
./Drivers/u8glib/src/u8g_pbxh24.d \
./Drivers/u8glib/src/u8g_polygon.d \
./Drivers/u8glib/src/u8g_rect.d \
./Drivers/u8glib/src/u8g_rot.d \
./Drivers/u8glib/src/u8g_scale.d \
./Drivers/u8glib/src/u8g_state.d \
./Drivers/u8glib/src/u8g_u16toa.d \
./Drivers/u8glib/src/u8g_u8toa.d \
./Drivers/u8glib/src/u8g_virtual_screen.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/u8glib/src/%.o: ../Drivers/u8glib/src/%.c Drivers/u8glib/src/subdir.mk
	arm-none-eabi-gcc -fdata-sections "$<" -mcpu=cortex-m3 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

