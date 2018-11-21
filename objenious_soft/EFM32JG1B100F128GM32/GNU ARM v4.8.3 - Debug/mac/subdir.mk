################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mac/LoRaMac.c \
../mac/LoRaMacCrypto.c 

OBJS += \
./mac/LoRaMac.o \
./mac/LoRaMacCrypto.o 

C_DEPS += \
./mac/LoRaMac.d \
./mac/LoRaMacCrypto.d 


# Each subdirectory must supply rules for building sources it contributes
mac/LoRaMac.o: ../mac/LoRaMac.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/LoRaMac.d" -MT"mac/LoRaMac.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/LoRaMacCrypto.o: ../mac/LoRaMacCrypto.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/boards" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system/crypto" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/inc" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/system" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/radio" -I"/home/khiemtt/Workspaces/Geolocation/objenious_soft/EFM32JG1B100F128GM32/mac" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/emlib/inc" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/drivers" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//hardware/kit/common/bsp" -I"/home/khiemtt/Apps/SimplicityStudio_v4/developer/sdks/Gecko_SDK//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/LoRaMacCrypto.d" -MT"mac/LoRaMacCrypto.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


