CC=arm-none-eabi-gcc
CPU=cortex-m4
CFLAGS= -c -mcpu=$(CPU) -mthumb -std=gnu11 -Wall -o0
LDFLAGS= -nostdlib -T stm32l476_ls.ld -Wl,-Map=final.map
OPENOCD_BOARD_CONFIG=stm32l476g-disco.cfg
#stm32l4discovery.cfg

all:main.o init.o  final.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

init.o:init.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:main.o init.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o *.elf *.map

load:
	openocd -f board/$(OPENOCD_BOARD_CONFIG)
