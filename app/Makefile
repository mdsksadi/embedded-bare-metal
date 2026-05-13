PROJECT = firmware

BUILD_DIR = build
APP_DIR = app

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CPU = cortex-m4
CFLAGS = -mcpu=$(CPU) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -Wall -Wextra -Werror -std=c11
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -g3 -O0
CFLAGS += -I$(APP_DIR)

LDFLAGS = -T linkerscript.ld
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(PROJECT).map
LDFLAGS += -nostartfiles

SRCS = startup_stm32l432kc.c \
       $(APP_DIR)/firmware.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

ELF = $(BUILD_DIR)/$(PROJECT).elf
BIN = $(BUILD_DIR)/$(PROJECT).bin
HEX = $(BUILD_DIR)/$(PROJECT).hex

all: $(ELF) $(BIN) $(HEX)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(HEX): $(ELF)
	$(OBJCOPY) -O ihex $< $@

flash: $(ELF)
	openocd -f interface/stlink.cfg -f target/stm32l4x.cfg \
	-c "program $(ELF) verify reset exit"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean flash
