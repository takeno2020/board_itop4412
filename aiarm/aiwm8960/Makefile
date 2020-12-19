APP = aiwm8960
OUT_DIR := out
CROSS_COMPLIE = arm-none-linux-gnueabi-

################################################################################
# 编译工具配置及编译选项设置
################################################################################
CC = $(CROSS_COMPLIE)gcc
LD = $(CROSS_COMPLIE)ld
STRIP = $(CROSS_COMPLIE)strip
OBJCOPY = $(CROSS_COMPLIE)objcopy
OBJDUMP = $(CROSS_COMPLIE)objdump

CFLAGS += -Wall \
		  -g \
		  -O0 \
		  -mabi=apcs-gnu \
		  -mfpu=neon \
		  -mfloat-abi=softfp \
		  -fno-builtin \
		  -nostdinc

################################################################################
# 头文件和源文件
################################################################################
INCLUDES = -I./core/include \
		   -I./hardware/uart \
		   -I./hardware/i2c \
		   -I./hardware/i2s \
		   -I./hardware/wm8960

SRC_FILES = $(wildcard core/src/*.c) \
			$(wildcard start/*.S) \
			$(wildcard hardware/uart/*.c) \
			$(wildcard hardware/i2c/*.c) \
			$(wildcard hardware/i2s/*.c) \
			$(wildcard hardware/wm8960/*.c) \
			$(wildcard *.c)

OBJS := $(patsubst %.S, %.o, $(filter %.S, $(SRC_FILES)))
OBJS += $(patsubst %.c, %.o, $(filter %.c, $(SRC_FILES)))
OBJS := $(addprefix $(OUT_DIR)/, $(OBJS))

TARGET = $(OUT_DIR)/$(APP)

################################################################################
# aiprint: 用于显示编译信息
# Commands:
#          tput setaf [0 - 7] 
#          a foreground color using ANSI escape, Color Code for tput:
#          0 - Black;    1 - Red;    2 - Green
#          3 - Yellow;   4 - Blue;   5 - Magenta
#          6 - Cyan;     7 - White
################################################################################
define aiprint
	@tput setaf $(1)
	@echo "$(2)"
	@tput sgr0
endef

.PHONY: all clean
all : $(TARGET) 
	$(call aiprint, 4,"Done!!!")

$(OUT_DIR)/%.o : %.c
	$(call aiprint, 6,"Compiling object file $@ ...")
	$(Q_)mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OUT_DIR)/%.o : %.S
	$(call aiprint, 6,"Compiling object file $@ ...")
	$(Q_)mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET) : $(OBJS)
	$(call aiprint, 6,"Compiling object file $@ ...")
	$(Q_)mkdir -p $(dir $@)
	$(LD) $(OBJS) -T start/aistart.lds -o $(basename $@).elf
	$(OBJCOPY) -O binary $(basename $@).elf $(basename $@).bin
	$(OBJDUMP) -D $(basename $@).elf > $(basename $@).dis

clean:
	rm -rf $(OUT_DIR)
