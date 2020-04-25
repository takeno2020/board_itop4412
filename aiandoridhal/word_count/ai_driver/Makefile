DRV_NAME = ai_word_count
APP_NAME = test_ai_word_count

KERNEL_DIR = /home/takeno/projects/linux/iTop4412_Kernel_3.0
PWD = $(shell pwd)
CROSS_COMPILE = /home/takeno/tools/arm-2009q3/bin/arm-none-linux-gnueabi-
CC = $(CROSS_COMPILE)gcc-4.4.1

ifeq ($(KERNELRELEASE), )
	
all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	$(CC) -o $(APP_NAME) $(APP_NAME).c -static

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	rm $(APP_NAME)

aiclean:
	rm /mnt/hgfs/share/$(DRV_NAME).ko
	rm /mnt/hgfs/share/$(APP_NAME)
aiinstall:
	cp $(DRV_NAME).ko /mnt/hgfs/share/
	cp $(APP_NAME) /mnt/hgfs/share/
else
	obj-m += $(DRV_NAME).o
endif
