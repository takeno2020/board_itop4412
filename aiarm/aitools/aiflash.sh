#/bin/bash
################################################################################
#
# Description: SDcard裸机程序烧写程序
#     Created: 06/25/2020 22:48:39 PM
#      Author: takeno
#
################################################################################
if [ $# -ne 1 ]
then
    echo -e "Usage: \e[1;32m$0 <image>\e[0m"
    exit 0
fi

if [ ! -f $1 ]
then
    echo "Error: $1 is nonexistence!"
    exit 0
fi

if [ -b /dev/sdb ]
then
    mkfs.vfat -F 32 -I /dev/sdb
    # 清除1MB大小的连续空间，不是必须，比要烧写镜像大就可以
    dd if=/dev/zero of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync count=2048
    # FAT32文件系统的每个扇区512Bytes，第0扇区为存放MBR的地方，
    # 所以起始从第1扇区开始烧写程序
    dd if=$1 of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync
    echo -e "\e[1;32mSuccess to program /dev/sdb\e[0m"
else
    echo -e "\e[1;31mFail to program /dev/sdb\e[0m"
fi
