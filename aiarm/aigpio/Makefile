AICOMPIER := arm-none-linux-gnueabi-

.PHONY:all clean

all:led_on.bin

led_on.bin : led_on.S
	$(AICOMPIER)gcc -g -c -o led_on.o led_on.S
	$(AICOMPIER)ld -Ttext 0x40008000 -g led_on.o -o led_on.elf
	$(AICOMPIER)objcopy -O binary -S led_on.elf led_on.bin

clean:
	rm -f led_on.bin led_on.elf *.o
