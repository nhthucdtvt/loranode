################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lmic-master/src/hal/hal.c 

OBJS += \
./lmic-master/src/hal/hal.o 

C_DEPS += \
./lmic-master/src/hal/hal.d 


# Each subdirectory must supply rules for building sources it contributes
lmic-master/src/hal/hal.o: ../lmic-master/src/hal/hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"lmic-master/src/hal/hal.d" -MT"lmic-master/src/hal/hal.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


