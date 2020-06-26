AIPWD := $(shell pwd)
AITOP_DIR := $(AIPWD)/..
AIOUT_DIR := $(AIPWD)/out
AITOOLS_DIR := $(AITOP_DIR)/aitools

CROSS_COMPILE := arm-none-linux-gnueabi-
CROSS_COMPILE_FLAGS := -Wall -g -nostdlib

AIOBJ := ailed
.PHONY : $(AIOBJ) all aiprepare aitools clean clobber
all : $(AIOBJ)

ailed : aiprepare aitools $(AIOUT_DIR)/$(AIOBJ).bin
	@rm *.o
	cp $(AIOUT_DIR)/$(AIOBJ).bin $(AIOUT_DIR)/checksum_$(AIOBJ).bin
	$(AIOUT_DIR)/aimkbl1/aimkbl1 $(AIOUT_DIR)/checksum_$(AIOBJ).bin
	mv $(AIOUT_DIR)/checksum_$(AIOBJ).bin $(AIOUT_DIR)/ailed_boot.bin
	@echo "-------- Success!!! --------"


aiprepare:
	-mkdir $(AIOUT_DIR)

aitools : aiprepare
	cp -arf $(AITOOLS_DIR)/aimkbl1 $(AIOUT_DIR)/
	cp -f $(AITOOLS_DIR)/aiflash.sh $(AIOUT_DIR)/
	make -C $(AIOUT_DIR)/aimkbl1

$(AIOUT_DIR)/$(AIOBJ).bin : $(AIOUT_DIR)/$(AIOBJ).elf 
	$(CROSS_COMPILE)objcopy -O binary $< $@
	$(CROSS_COMPILE)objdump -D $< > $(@:.bin=.dis)

$(AIOUT_DIR)/$(AIOBJ).elf : $(AIOBJ).o aiboot.lds
	$(CROSS_COMPILE)ld -T aiboot.lds -o $@ $^

%.o : %.S
	$(CROSS_COMPILE)gcc $(CROSS_COMPILE_FLAGS) -c -o $@ $<

clean:
	cd $(AIOUT_DIR) && rm -f *.dis *.o *.elf

clobber:
	rm -rf $(AIOUT_DIR)
