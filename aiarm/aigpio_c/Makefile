AICOMPIER := arm-none-linux-gnueabi-

.PHONY:all clean

all:led_on_c.bin

led_on_c.bin : start.S led_on_c.c
	$(AICOMPIER)gcc -g -c -o start.o start.S
	$(AICOMPIER)gcc -g -c -o led_on_c.o led_on_c.c -nostdinc -fno-builtin -nostdlib
	$(AICOMPIER)ld -Ttext 0x40008000 -g start.o led_on_c.o -o led_on_c.elf
	$(AICOMPIER)objcopy -O binary -S led_on_c.elf led_on_c.bin

clean:
	rm -f led_on_c.bin led_on_c.elf *.o
