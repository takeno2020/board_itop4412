AIOBJ := aimkbl2
CC := gcc
CFLAGS := -Wall -g -static


.PHONY : all clean clobber
all : $(AIOBJ)

aimkbl2 : aimkbl2.o
	$(CC) $(CFLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.dis *.o *.elf

clobber : clean
	rm -f $(AIOBJ)
