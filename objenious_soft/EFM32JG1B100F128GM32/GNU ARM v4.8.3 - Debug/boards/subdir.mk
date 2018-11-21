################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../boards/adc-board.c \
../boards/board.c \
../boards/gpio-board.c \
../boards/i2c-EEPROM.c \
../boards/i2c-MMA8652.c \
../boards/rtc-board.c \
../boards/spi-board.c \
../boards/sx1276-board.c \
../boards/utilities.c 

OBJS += \
./boards/adc-board.o \
./boards/board.o \
./boards/gpio-board.o \
./boards/i2c-EEPROM.o \
./boards/i2c-MMA8652.o \
./boards/rtc-board.o \
./boards/spi-board.o \
./boards/sx1276-board.o \
./boards/utilities.o 

C_DEPS += \
./boards/adc-board.d \
./boards/board.d \
./boards/gpio-board.d \
./boards/i2c-EEPROM.d \
./boards/i2c-MMA8652.d \
./boards/rtc-board.d \
./boards/spi-board.d \
./boards/sx1276-board.d \
./boards/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
boards/adc-board.o: ../boards/adc-board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/adc-board.d" -MT"boards/adc-board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/board.o: ../boards/board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/board.d" -MT"boards/board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/gpio-board.o: ../boards/gpio-board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/gpio-board.d" -MT"boards/gpio-board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/i2c-EEPROM.o: ../boards/i2c-EEPROM.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/i2c-EEPROM.d" -MT"boards/i2c-EEPROM.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/i2c-MMA8652.o: ../boards/i2c-MMA8652.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/i2c-MMA8652.d" -MT"boards/i2c-MMA8652.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/rtc-board.o: ../boards/rtc-board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/rtc-board.d" -MT"boards/rtc-board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/spi-board.o: ../boards/spi-board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/spi-board.d" -MT"boards/spi-board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/sx1276-board.o: ../boards/sx1276-board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/sx1276-board.d" -MT"boards/sx1276-board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

boards/utilities.o: ../boards/utilities.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"boards/utilities.d" -MT"boards/utilities.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


