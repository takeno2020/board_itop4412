# Description: LED2 --> KP_COL0  --> AA4(XGNSS_GPIO_0/GPL2_0)
#              LED3 --> VDD50_EN --> J2(Xmmc1CMD/GPK1_1)
#              高电平点亮，低电平熄灭

.text
.global _start
_start:
    BL LED_CONFIG
LOOP:
    BL LED_ON
    BL DELAY
    BL LED_OFF
    BL DELAY
    B LOOP

    

LED_CONFIG:
    LDR R0,=0x11000100
    MOV R1,#0x00000001
    STR R1,[R0]
    MOV PC,LR

LED_ON:
    LDR R0,=0x11000104
    MOV R1,#0x01
    STR R1,[R0]
    MOV PC,LR

LED_OFF:
    LDR R0,=0x11000104
    MOV R1,#0x00
    STR R1,[R0]
    MOV PC,LR

DELAY:
    LDR R1,=0xffffffff
T:
    SUB R1,R1,#0x1
    CMP R1,#0
    BNE T
    MOVEQ PC,LR

stop:
    b stop
