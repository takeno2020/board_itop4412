/*
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *              http://www.samsung.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define BL2_SIZE    (14 * 1024)
#define CS_SIZE     (4)
#define CS_START    (BL2_SIZE - CS_SIZE)


static void calc_bl2_chksum(unsigned long addr)
{
    int i;
    unsigned long checksum;

    for(i = 0, checksum = 0;i < CS_START;i++)
    {
        checksum += *(unsigned char*)addr++;
    }

    *(unsigned long*)addr = checksum;
    printf("\nchecksum = 0x%08lx\n\n", checksum);
}


static void do_chksum(char* src_file,char* dst_file)
{
    FILE *fp_src_uboot = NULL;
    FILE *fp_dst_uboot = NULL;

    char *fn_src_uboot = src_file;
    char *fn_dst_uboot = dst_file;
    unsigned char *src = NULL;
    int fs = 0;

    fp_src_uboot = fopen(fn_src_uboot, "rb");
    if (NULL == fp_src_uboot) {
        printf("can't open uboot file for read(%s)\n", fn_src_uboot);
        return;
    }

    fp_dst_uboot = fopen(fn_dst_uboot, "wb");
    if (NULL == fp_src_uboot) {
        printf("can't open uboot file for read(%s)\n", fn_src_uboot);
        return;
    }

    fseek(fp_src_uboot, 0L, SEEK_END);
    fs = ftell(fp_src_uboot);
    printf("%s file size= %dB\n", fn_src_uboot, fs);
    rewind(fp_src_uboot);


    src = (unsigned char *)calloc((size_t)BL2_SIZE, 1);
    memset(src, 0x00, BL2_SIZE);
    if (fs != fread(src, 1, (size_t)fs, fp_src_uboot)) {
        printf("%s file read error!\n", fn_src_uboot);
    } else {
        calc_bl2_chksum((unsigned long)src);
        if (BL2_SIZE != fwrite(src, 1, (size_t)BL2_SIZE, fp_dst_uboot))
            printf("%s file write error!\n", fn_dst_uboot);
        else
            printf("%s file write ok!\n", fn_dst_uboot);
    }
    free(src);
    src = NULL;
    fclose(fp_src_uboot);
    fclose(fp_dst_uboot);
}


int main(int argc, char *argv[])
{
    char des_file[1024] = {0};
    char *dirc = NULL, *basec = NULL;
    char *dname = NULL, *bname = NULL;
    int ret = -1;

    if (argc != 2) {
        printf("Usage: mkbl2 <source file>\n");
        return -1;
    }

    dirc = strdup(argv[1]);
    basec = strdup(argv[1]);
    dname = dirname(dirc);
    bname = basename(basec);
    printf("dirname=%s, basename=%s\n", dname, bname);

    ret = snprintf(des_file, sizeof(des_file), "%s/checksum_%s", dname, bname);
    if (ret < 0) {
        printf("Fail to create file checksum_%s\n", argv[1]);
        return -1;
    }
    printf("des_file = %s\n", des_file);

    do_chksum(argv[1], des_file);
    free(dirc);
    free(basec);
	return 0;
}

