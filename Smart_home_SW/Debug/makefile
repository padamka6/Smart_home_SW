################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
diplomaterv_smart_home.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
diplomaterv_smart_home.list \


# All Target
all: diplomaterv_smart_home.elf secondary-outputs

# Tool invocations
diplomaterv_smart_home.elf: $(OBJS) $(USER_OBJS) /Users/pasztoradam/Library/Mobile\ Documents/com~apple~CloudDocs/Diplomaterv/SW/Smart_home_SW/STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "diplomaterv_smart_home.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/pasztoradam/Library/Mobile Documents/com~apple~CloudDocs/Diplomaterv/SW/Smart_home_SW/STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="diplomaterv_smart_home.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

diplomaterv_smart_home.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "diplomaterv_smart_home.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
