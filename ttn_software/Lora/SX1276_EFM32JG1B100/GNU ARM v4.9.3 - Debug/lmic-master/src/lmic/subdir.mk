################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lmic-master/src/lmic/aes.c \
../lmic-master/src/lmic/lmic.c \
../lmic-master/src/lmic/oslmic.c \
../lmic-master/src/lmic/radio.c 

OBJS += \
./lmic-master/src/lmic/aes.o \
./lmic-master/src/lmic/lmic.o \
./lmic-master/src/lmic/oslmic.o \
./lmic-master/src/lmic/radio.o 

C_DEPS += \
./lmic-master/src/lmic/aes.d \
./lmic-master/src/lmic/lmic.d \
./lmic-master/src/lmic/oslmic.d \
./lmic-master/src/lmic/radio.d 


# Each subdirectory must supply rules for building sources it contributes
lmic-master/src/lmic/aes.o: ../lmic-master/src/lmic/aes.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"lmic-master/src/lmic/aes.d" -MT"lmic-master/src/lmic/aes.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lmic-master/src/lmic/lmic.o: ../lmic-master/src/lmic/lmic.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"lmic-master/src/lmic/lmic.d" -MT"lmic-master/src/lmic/lmic.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lmic-master/src/lmic/oslmic.o: ../lmic-master/src/lmic/oslmic.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"lmic-master/src/lmic/oslmic.d" -MT"lmic-master/src/lmic/oslmic.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lmic-master/src/lmic/radio.o: ../lmic-master/src/lmic/radio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"lmic-master/src/lmic/radio.d" -MT"lmic-master/src/lmic/radio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


