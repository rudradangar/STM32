################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/src/STM32F446xx_GPIO_driver.c \
../driver/src/STM32F446xx_I2C_Drivers.c \
../driver/src/STM32F446xx_SPI_Drivers.c 

OBJS += \
./driver/src/STM32F446xx_GPIO_driver.o \
./driver/src/STM32F446xx_I2C_Drivers.o \
./driver/src/STM32F446xx_SPI_Drivers.o 

C_DEPS += \
./driver/src/STM32F446xx_GPIO_driver.d \
./driver/src/STM32F446xx_I2C_Drivers.d \
./driver/src/STM32F446xx_SPI_Drivers.d 


# Each subdirectory must supply rules for building sources it contributes
driver/src/%.o driver/src/%.su driver/src/%.cyclo: ../driver/src/%.c driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"E:/worksop/009STM32F446RE/driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-driver-2f-src

clean-driver-2f-src:
	-$(RM) ./driver/src/STM32F446xx_GPIO_driver.cyclo ./driver/src/STM32F446xx_GPIO_driver.d ./driver/src/STM32F446xx_GPIO_driver.o ./driver/src/STM32F446xx_GPIO_driver.su ./driver/src/STM32F446xx_I2C_Drivers.cyclo ./driver/src/STM32F446xx_I2C_Drivers.d ./driver/src/STM32F446xx_I2C_Drivers.o ./driver/src/STM32F446xx_I2C_Drivers.su ./driver/src/STM32F446xx_SPI_Drivers.cyclo ./driver/src/STM32F446xx_SPI_Drivers.d ./driver/src/STM32F446xx_SPI_Drivers.o ./driver/src/STM32F446xx_SPI_Drivers.su

.PHONY: clean-driver-2f-src

