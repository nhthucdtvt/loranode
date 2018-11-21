################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/Device/SiliconLabs/EFM32JG1B/Source/system_efm32jg1b.c 

S_UPPER_SRCS += \
/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/Device/SiliconLabs/EFM32JG1B/Source/GCC/startup_efm32jg1b.S 

OBJS += \
./CMSIS/EFM32JG1B/startup_efm32jg1b.o \
./CMSIS/EFM32JG1B/system_efm32jg1b.o 

C_DEPS += \
./CMSIS/EFM32JG1B/system_efm32jg1b.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFM32JG1B/startup_efm32jg1b.o: /home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/Device/SiliconLabs/EFM32JG1B/Source/GCC/startup_efm32jg1b.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -c -x assembler-with-cpp -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" '-DEFM32JG1B100F128GM32=1' -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFM32JG1B/system_efm32jg1b.o: /home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/Device/SiliconLabs/EFM32JG1B/Source/system_efm32jg1b.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"CMSIS/EFM32JG1B/system_efm32jg1b.d" -MT"CMSIS/EFM32JG1B/system_efm32jg1b.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


