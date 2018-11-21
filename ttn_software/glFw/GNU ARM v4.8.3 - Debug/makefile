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
all: glFw.axf

# Tool invocations
glFw.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "glFw.ld" -Xlinker --gc-sections -Xlinker -Map="glFw.map" --specs=nano.specs -o glFw.axf "./CMSIS/EFM32ZG/startup_gcc_efm32zg.o" "./CMSIS/EFM32ZG/system_efm32zg.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_leuart.o" "./emlib/em_system.o" "./src/InitDevice.o" "./src/main.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: glFw.hex'
	arm-none-eabi-objcopy -O ihex "glFw.axf" "glFw.hex"
	@echo ' '

	@echo 'Building bin file: glFw.bin'
	arm-none-eabi-objcopy -O binary "glFw.axf" "glFw.bin"
	@echo ' '

	@echo 'Building s37 file: glFw.s37'
	arm-none-eabi-objcopy -O srec "glFw.axf" "glFw.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "glFw.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) glFw.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
