.text
.global _start
_start:
    ldr r0, =0x10060000
    mov r1, #0x00000000
    str r1, [r0]

    ldr sp, =0x50008000+1024*2 # sp的位置要在代码段、数据段的最上面，否则程序运行失败
    bl main

stop:
    b stop
