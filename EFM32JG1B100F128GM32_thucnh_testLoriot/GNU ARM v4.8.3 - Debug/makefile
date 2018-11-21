################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include system/crypto/subdir.mk
-include system/subdir.mk
-include src/subdir.mk
-include radio/subdir.mk
-include mac/region/subdir.mk
-include mac/subdir.mk
-include emlib/subdir.mk
-include boards/subdir.mk
-include CMSIS/EFM32JG1B/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: EFM32JG1B100F128GM32_thucnh_testLoriot.axf

# Tool invocations
EFM32JG1B100F128GM32_thucnh_testLoriot.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "EFM32JG1B100F128GM32_thucnh_testLoriot.ld" -Xlinker --gc-sections -Xlinker -Map="EFM32JG1B100F128GM32_thucnh_testLoriot.map" --specs=nano.specs -o EFM32JG1B100F128GM32_thucnh_testLoriot.axf "./CMSIS/EFM32JG1B/startup_gcc_efm32jg1b.o" "./CMSIS/EFM32JG1B/system_efm32jg1b.o" "./boards/adc-board.o" "./boards/board.o" "./boards/gpio-board.o" "./boards/i2c-EEPROM.o" "./boards/i2c-MMA8652.o" "./boards/rtc-board.o" "./boards/spi-board.o" "./boards/sx1276-board.o" "./boards/utilities.o" "./emlib/em_adc.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_cryotimer.o" "./emlib/em_crypto.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_leuart.o" "./emlib/em_rtcc.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./emlib/em_wdog.o" "./mac/LoRaMac.o" "./mac/LoRaMacCrypto.o" "./mac/region/Region.o" "./mac/region/RegionAS923.o" "./mac/region/RegionAU915.o" "./mac/region/RegionCN470.o" "./mac/region/RegionCN779.o" "./mac/region/RegionCommon.o" "./mac/region/RegionEU433.o" "./mac/region/RegionEU868.o" "./mac/region/RegionIN865.o" "./mac/region/RegionKR920.o" "./mac/region/RegionUS915-Hybrid.o" "./mac/region/RegionUS915.o" "./radio/sx1276.o" "./src/EepromData.o" "./src/Gps.o" "./src/InitDevice.o" "./src/MCUInit.o" "./src/main.o" "./system/adc.o" "./system/delay.o" "./system/gpio.o" "./system/timer.o" "./system/crypto/aes.o" "./system/crypto/cmac.o" -lm -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: EFM32JG1B100F128GM32_thucnh_testLoriot.hex'
	arm-none-eabi-objcopy -O ihex "EFM32JG1B100F128GM32_thucnh_testLoriot.axf" "EFM32JG1B100F128GM32_thucnh_testLoriot.hex"
	@echo ' '

	@echo 'Building bin file: EFM32JG1B100F128GM32_thucnh_testLoriot.bin'
	arm-none-eabi-objcopy -O binary "EFM32JG1B100F128GM32_thucnh_testLoriot.axf" "EFM32JG1B100F128GM32_thucnh_testLoriot.bin"
	@echo ' '

	@echo 'Building s37 file: EFM32JG1B100F128GM32_thucnh_testLoriot.s37'
	arm-none-eabi-objcopy -O srec "EFM32JG1B100F128GM32_thucnh_testLoriot.axf" "EFM32JG1B100F128GM32_thucnh_testLoriot.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "EFM32JG1B100F128GM32_thucnh_testLoriot.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) EFM32JG1B100F128GM32_thucnh_testLoriot.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
