# Source files
# look at test (cubie workspace under debug )
C_SRC = ./Src
Inc = ./Inc
C_SRCS = $(wildcard $(C_SRC)/*.c)
# Object files
C_OBJS = $(patsubst $(C_SRC)/%.c, ./Build/%.o, $(C_SRCS) )

HAL_SRC = ./CMSIS/STM32F4xx_HAL_Driver/Src
HAL_Inc = ./CMSIS/STM32F4xx_HAL_Driver/Inc

HAL_SRCS = $(wildcard $(HAL_SRC)/*.c)
HAL_OBJS = $(patsubst $(HAL_SRC)/%.c, ./Build/Hal/%.o, $(HAL_SRCS))

#Statrtup 
S_SRCS = ./Startup/startup_stm32f401retx.s
OBJS_s = ./Build/startup_stm32f401retx.o 

#Linker 
Linker = ./STM32F401RETX_FLASH.ld  

# Dependency files
C_DEPS = $(C_OBJS:.o=.d)
#inlcue path 

# Compiler flags
CFLAGS = -mcpu=cortex-m4 -std=gnu11 -gdwarf-2 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE \
		 -I./Inc -I./CMSIS/Include -I./CMSIS/STM32F4_Headers -I$(HAL_Inc) -I$(HAL_Inc)/Legacy -O0 -ffunction-sections -fdata-sections \
		 -Wall -fstack-usage -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
# Linker flags 
LD_flags = -mcpu=cortex-m4 -T${Linker} \
	--specs=nosys.specs -Wl,--gc-sections -static --specs=nano.specs \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
# Compiler command
CC = arm-none-eabi-gcc

# Rule to include all object files for the 'all' target
all: Template_proj.elf

bin: Template_proj.elf
	arm-none-eabi-objcopy -O binary Template_proj.elf Template_proj.bin 

	
		
hal_build: $(HAL_OBJS)
	@echo "HAL files compiled succ essfully"

# target 
Template_proj.elf : $(C_OBJS) $(OBJS_s) $(HAL_OBJS)
	$(CC) $(LD_flags) $^ -o $@ 
	@echo 'Finished building target: $@'
	@echo ' '
Flash: bin
	st-flash --reset write Template_proj.bin 0x8000000
	# openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program Template_proj.elf verify reset exit"


# Rule to build object files from source files
$(C_OBJS): ./Build/%.o: ./Src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build Hal objs 
$(HAL_OBJS): ./Build/Hal/%.o: $(HAL_SRC)/%.c 
	$(CC) $(CFLAGS)    -c $< -o $@  

# Rule to build object files from assembly files
$(OBJS_s): $(S_SRCS)
	$(CC) -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

# Phony target to prevent conflicts with files named 'clean'
.PHONY: clean

clean:
	rm Template_proj.elf
	rm Build/*
