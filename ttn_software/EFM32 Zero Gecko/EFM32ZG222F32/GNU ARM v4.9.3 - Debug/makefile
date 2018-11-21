################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32ZG/subdir.mk
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
all: EFM32ZG222F32.axf

# Tool invocations
EFM32ZG222F32.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "EFM32ZG222F32.ld" -Xlinker --gc-sections -Xlinker -Map="EFM32ZG222F32.map" --specs=nano.specs -o EFM32ZG222F32.axf "./CMSIS/EFM32ZG/startup_gcc_efm32zg.o" "./CMSIS/EFM32ZG/system_efm32zg.o" "./emlib/em_adc.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_dma.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_leuart.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./src/InitDevice.o" "./src/main.o" -lm -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: EFM32ZG222F32.hex'
	arm-none-eabi-objcopy -O ihex "EFM32ZG222F32.axf" "EFM32ZG222F32.hex"
	@echo ' '

	@echo 'Building bin file: EFM32ZG222F32.bin'
	arm-none-eabi-objcopy -O binary "EFM32ZG222F32.axf" "EFM32ZG222F32.bin"
	@echo ' '

	@echo 'Building s37 file: EFM32ZG222F32.s37'
	arm-none-eabi-objcopy -O srec "EFM32ZG222F32.axf" "EFM32ZG222F32.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "EFM32ZG222F32.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) EFM32ZG222F32.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
