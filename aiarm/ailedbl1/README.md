注意的几个事情：
    1.bl1程序的开头16Bytes一定要空出给制作程序填写校验等信息；
    2.bl1的链接地址是0x02021400，并不是0x00，因为Exynos4412启动时
      首先执行的是iROM中的程序，它会转到该地址执行bl1阶段的程序；
      详细参考三星官方文档：
      <<SEC_Solution Training doc_uboot mr structure.pdf>>
    3.开始执行时需要自己做电源的保持、cache和mmu关闭功能，同时，需要
      屏蔽看门狗的复位标志，否则系统会不断重启；
