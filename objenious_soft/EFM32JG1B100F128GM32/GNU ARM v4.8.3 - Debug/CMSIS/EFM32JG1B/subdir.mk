################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../CMSIS/EFM32JG1B/startup_gcc_efm32jg1b.s 

C_SRCS += \
../CMSIS/EFM32JG1B/system_efm32jg1b.c 

OBJS += \
./CMSIS/EFM32JG1B/startup_gcc_efm32jg1b.o \
./CMSIS/EFM32JG1B/system_efm32jg1b.o 

C_DEPS += \
./CMSIS/EFM32JG1B/system_efm32jg1b.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFM32JG1B/%.o: ../CMSIS/EFM32JG1B/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Assembler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -c -x assembler-with-cpp -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" '-DEFM32JG1B100F128GM32=1' -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

CMSIS/EFM32JG1B/system_efm32jg1b.o: ../CMSIS/EFM32JG1B/system_efm32jg1b.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"CMSIS/EFM32JG1B/system_efm32jg1b.d" -MT"CMSIS/EFM32JG1B/system_efm32jg1b.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


