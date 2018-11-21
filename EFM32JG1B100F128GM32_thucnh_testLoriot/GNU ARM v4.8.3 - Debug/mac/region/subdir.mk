################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mac/region/Region.c \
../mac/region/RegionAS923.c \
../mac/region/RegionAU915.c \
../mac/region/RegionCN470.c \
../mac/region/RegionCN779.c \
../mac/region/RegionCommon.c \
../mac/region/RegionEU433.c \
../mac/region/RegionEU868.c \
../mac/region/RegionIN865.c \
../mac/region/RegionKR920.c \
../mac/region/RegionUS915-Hybrid.c \
../mac/region/RegionUS915.c 

OBJS += \
./mac/region/Region.o \
./mac/region/RegionAS923.o \
./mac/region/RegionAU915.o \
./mac/region/RegionCN470.o \
./mac/region/RegionCN779.o \
./mac/region/RegionCommon.o \
./mac/region/RegionEU433.o \
./mac/region/RegionEU868.o \
./mac/region/RegionIN865.o \
./mac/region/RegionKR920.o \
./mac/region/RegionUS915-Hybrid.o \
./mac/region/RegionUS915.o 

C_DEPS += \
./mac/region/Region.d \
./mac/region/RegionAS923.d \
./mac/region/RegionAU915.d \
./mac/region/RegionCN470.d \
./mac/region/RegionCN779.d \
./mac/region/RegionCommon.d \
./mac/region/RegionEU433.d \
./mac/region/RegionEU868.d \
./mac/region/RegionIN865.d \
./mac/region/RegionKR920.d \
./mac/region/RegionUS915-Hybrid.d \
./mac/region/RegionUS915.d 


# Each subdirectory must supply rules for building sources it contributes
mac/region/Region.o: ../mac/region/Region.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/Region.d" -MT"mac/region/Region.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionAS923.o: ../mac/region/RegionAS923.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionAS923.d" -MT"mac/region/RegionAS923.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionAU915.o: ../mac/region/RegionAU915.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionAU915.d" -MT"mac/region/RegionAU915.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionCN470.o: ../mac/region/RegionCN470.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionCN470.d" -MT"mac/region/RegionCN470.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionCN779.o: ../mac/region/RegionCN779.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionCN779.d" -MT"mac/region/RegionCN779.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionCommon.o: ../mac/region/RegionCommon.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionCommon.d" -MT"mac/region/RegionCommon.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionEU433.o: ../mac/region/RegionEU433.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionEU433.d" -MT"mac/region/RegionEU433.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionEU868.o: ../mac/region/RegionEU868.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionEU868.d" -MT"mac/region/RegionEU868.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionIN865.o: ../mac/region/RegionIN865.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionIN865.d" -MT"mac/region/RegionIN865.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionKR920.o: ../mac/region/RegionKR920.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionKR920.d" -MT"mac/region/RegionKR920.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionUS915-Hybrid.o: ../mac/region/RegionUS915-Hybrid.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionUS915-Hybrid.d" -MT"mac/region/RegionUS915-Hybrid.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mac/region/RegionUS915.o: ../mac/region/RegionUS915.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"mac/region/RegionUS915.d" -MT"mac/region/RegionUS915.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


