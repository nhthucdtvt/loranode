################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EepromData.c \
../src/Gps.c \
../src/InitDevice.c \
../src/MCUInit.c \
../src/main.c 

OBJS += \
./src/EepromData.o \
./src/Gps.o \
./src/InitDevice.o \
./src/MCUInit.o \
./src/main.o 

C_DEPS += \
./src/EepromData.d \
./src/Gps.d \
./src/InitDevice.d \
./src/MCUInit.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/EepromData.o: ../src/EepromData.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/EepromData.d" -MT"src/EepromData.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Gps.o: ../src/Gps.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/Gps.d" -MT"src/Gps.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.o: ../src/InitDevice.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/InitDevice.d" -MT"src/InitDevice.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MCUInit.o: ../src/MCUInit.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/MCUInit.d" -MT"src/MCUInit.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"src/main.d" -MT"src/main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


