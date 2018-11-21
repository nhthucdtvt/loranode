################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../radio/sx1276.c 

OBJS += \
./radio/sx1276.o 

C_DEPS += \
./radio/sx1276.d 


# Each subdirectory must supply rules for building sources it contributes
radio/sx1276.o: ../radio/sx1276.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DUSE_BAND_868=1' '-DREGION_EU868=1' '-DEFM32JG1B100F128GM32=1' -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/boards" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//arm-none-eabi/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/toolchains/gnu_arm/4.8_2013q4//lib/gcc/arm-none-eabi/4.8.3/include-fixed" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system/crypto" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/inc" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/system" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/radio" -I"/home/thucnh/SimplicityStudio/v4_workspace/EFM32JG1B100F128GM32_thucnh_testLoriot/mac" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/emlib/inc" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/Device/SiliconLabs/EFM32JG1B/Include" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/drivers" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//hardware/kit/common/bsp" -I"/home/thucnh/Apps/SimplicityStudio_v4/developer/sdks/exx32/v5.0.0.0//platform/CMSIS/Include" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"radio/sx1276.d" -MT"radio/sx1276.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


