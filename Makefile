CC=arm-none-eabi-gcc
CPU=cortex-m4
CFLAGS= -c -mcpu=$(CPU) -mthumb -std=gnu11 -Wall -o0
LDFLAGS= -nostdlib -T stm32l476_ls.ld -Wl,-Map=build/final.map
OPENOCD_BOARD_CONFIG=stm32l476g-disco.cfg

BUILD_PATH := build
SRC_PATH := src

SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(BUILD_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
TARGET := $(BUILD_PATH)/final.elf

default: makedir all

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@if [ ! -d "$(BUILD_PATH)" ]; then \
  	  	echo "There is no build directory"; \
    else \
        rm -rf $(BUILD_PATH); \
        echo "Build directory has been removed"; \
   	fi

.PHONY: makedir
makedir:
	@mkdir -p $(BUILD_PATH)

.PHONY: flash
flash:
	openocd -f board/$(OPENOCD_BOARD_CONFIG)
