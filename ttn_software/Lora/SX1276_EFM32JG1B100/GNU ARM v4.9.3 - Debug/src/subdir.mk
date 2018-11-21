################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc.c \
../src/config.c \
../src/delay.c \
../src/i2c-MMA8652.c \
../src/main.c 

OBJS += \
./src/adc.o \
./src/config.o \
./src/delay.o \
./src/i2c-MMA8652.o \
./src/main.o 

C_DEPS += \
./src/adc.d \
./src/config.d \
./src/delay.d \
./src/i2c-MMA8652.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/adc.o: ../src/adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/adc.d" -MT"src/adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/config.o: ../src/config.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/config.d" -MT"src/config.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/delay.o: ../src/delay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/delay.d" -MT"src/delay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/i2c-MMA8652.o: ../src/i2c-MMA8652.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/i2c-MMA8652.d" -MT"src/i2c-MMA8652.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


