################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include user_c/subdir.mk
-include hefei_peripheral/subdir.mk
-include hefei_libraries/board/subdir.mk
-include hefei_libraries/subdir.mk
-include CODE/subdir.mk
-include CH32V30x/Core/subdir.mk
-include CH32V30x/CH32V30x_p/Startup/subdir.mk
-include CH32V30x/CH32V30x_p/CH32V30x_Lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
testA.hex \

SECONDARY_LIST += \
testA.lst \

SECONDARY_SIZE += \
testA.siz \


# 所有目标
all: testA.elf secondary-outputs

# 工具调用
testA.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -T "D:\IDE\A车\A车\A车\基础组摄像头资料（摄像头）资料A\4.Demo\testA\MounRiver\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"testA.map" --specs=nano.specs --specs=nosys.specs -o "testA.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
testA.hex: testA.elf
	@	riscv-none-embed-objcopy -O ihex "testA.elf"  "testA.hex"
	@	@
testA.lst: testA.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "testA.elf" > "testA.lst"
	@	@
testA.siz: testA.elf
	@	riscv-none-embed-size --format=berkeley "testA.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) testA.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
