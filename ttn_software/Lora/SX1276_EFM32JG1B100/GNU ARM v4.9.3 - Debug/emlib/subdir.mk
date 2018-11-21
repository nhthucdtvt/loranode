################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../emlib/em_adc.c \
../emlib/em_assert.c \
../emlib/em_cmu.c \
../emlib/em_cryotimer.c \
../emlib/em_dma.c \
../emlib/em_emu.c \
../emlib/em_gpio.c \
../emlib/em_i2c.c \
../emlib/em_int.c \
../emlib/em_ldma.c \
../emlib/em_leuart.c \
../emlib/em_rmu.c \
../emlib/em_rtcc.c \
/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/emlib/src/em_system.c \
../emlib/em_usart.c 

OBJS += \
./emlib/em_adc.o \
./emlib/em_assert.o \
./emlib/em_cmu.o \
./emlib/em_cryotimer.o \
./emlib/em_dma.o \
./emlib/em_emu.o \
./emlib/em_gpio.o \
./emlib/em_i2c.o \
./emlib/em_int.o \
./emlib/em_ldma.o \
./emlib/em_leuart.o \
./emlib/em_rmu.o \
./emlib/em_rtcc.o \
./emlib/em_system.o \
./emlib/em_usart.o 

C_DEPS += \
./emlib/em_adc.d \
./emlib/em_assert.d \
./emlib/em_cmu.d \
./emlib/em_cryotimer.d \
./emlib/em_dma.d \
./emlib/em_emu.d \
./emlib/em_gpio.d \
./emlib/em_i2c.d \
./emlib/em_int.d \
./emlib/em_ldma.d \
./emlib/em_leuart.d \
./emlib/em_rmu.d \
./emlib/em_rtcc.d \
./emlib/em_system.d \
./emlib/em_usart.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/em_adc.o: ../emlib/em_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_adc.d" -MT"emlib/em_adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_assert.o: ../emlib/em_assert.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_assert.d" -MT"emlib/em_assert.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cmu.o: ../emlib/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_cmu.d" -MT"emlib/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cryotimer.o: ../emlib/em_cryotimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_cryotimer.d" -MT"emlib/em_cryotimer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_dma.o: ../emlib/em_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_dma.d" -MT"emlib/em_dma.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: ../emlib/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_emu.d" -MT"emlib/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_gpio.o: ../emlib/em_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_gpio.d" -MT"emlib/em_gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_i2c.o: ../emlib/em_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_i2c.d" -MT"emlib/em_i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_int.o: ../emlib/em_int.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_int.d" -MT"emlib/em_int.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_ldma.o: ../emlib/em_ldma.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_ldma.d" -MT"emlib/em_ldma.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_leuart.o: ../emlib/em_leuart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_leuart.d" -MT"emlib/em_leuart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rmu.o: ../emlib/em_rmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_rmu.d" -MT"emlib/em_rmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rtcc.o: ../emlib/em_rtcc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_rtcc.d" -MT"emlib/em_rtcc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: /home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1/platform/emlib/src/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_system.d" -MT"emlib/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_usart.o: ../emlib/em_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DEFM32JG1B100F128GM32=1' '-DDEBUG=1' -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"/home/khiemtt/Downloads/SimplicityStudio_v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFM32JG1B/Include" -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/lmic -I/home/khiemtt/workspace/Geolocation/ttn_software/Lora/SX1276_EFM32JG1B100/lmic-master/hal -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"emlib/em_usart.d" -MT"emlib/em_usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


