################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include lmic-master/src/lmic/subdir.mk
-include lmic-master/src/hal/subdir.mk
-include emlib/subdir.mk
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
all: SX1276_EFM32JG1B100.axf

# Tool invocations
SX1276_EFM32JG1B100.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "SX1276_EFM32JG1B100.ld" -Xlinker --gc-sections -Xlinker -Map="SX1276_EFM32JG1B100.map" --specs=nano.specs -o SX1276_EFM32JG1B100.axf "./CMSIS/EFM32JG1B/startup_efm32jg1b.o" "./CMSIS/EFM32JG1B/system_efm32jg1b.o" "./emlib/em_adc.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_cryotimer.o" "./emlib/em_dma.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_int.o" "./emlib/em_ldma.o" "./emlib/em_leuart.o" "./emlib/em_rmu.o" "./emlib/em_rtcc.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./lmic-master/src/hal/hal.o" "./lmic-master/src/lmic/aes.o" "./lmic-master/src/lmic/lmic.o" "./lmic-master/src/lmic/oslmic.o" "./lmic-master/src/lmic/radio.o" "./src/adc.o" "./src/config.o" "./src/delay.o" "./src/i2c-MMA8652.o" "./src/main.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: SX1276_EFM32JG1B100.hex'
	arm-none-eabi-objcopy -O ihex "SX1276_EFM32JG1B100.axf" "SX1276_EFM32JG1B100.hex"
	@echo ' '

	@echo 'Building bin file: SX1276_EFM32JG1B100.bin'
	arm-none-eabi-objcopy -O binary "SX1276_EFM32JG1B100.axf" "SX1276_EFM32JG1B100.bin"
	@echo ' '

	@echo 'Building s37 file: SX1276_EFM32JG1B100.s37'
	arm-none-eabi-objcopy -O srec "SX1276_EFM32JG1B100.axf" "SX1276_EFM32JG1B100.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "SX1276_EFM32JG1B100.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) SX1276_EFM32JG1B100.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
