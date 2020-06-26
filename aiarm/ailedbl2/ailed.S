# Description: LED2 --> KP_COL0  --> AA4(XGNSS_GPIO_0/GPL2_0)
#              LED3 --> VDD50_EN --> J2(Xmmc1CMD/GPK1_1)
#              高电平点亮，低电平熄灭

.global _start
    .word 0x2000
    .word 0x0
    .word 0x0
    .word 0x0
_start:
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0xd3
    msr cpsr, r0

	mrc	p15, 0, r0, c0, c0, 0            @ read main ID register
	and	r1, r0, #0x00f00000	             @ variant
	and	r2, r0, #0x0000000f	             @ revision
	orr	r2, r2, r1, lsr #20-4	         @ combine variant and revision
	cmp	r2, #0x30
	mrceq p15, 0, r0, c1, c0, 1	         @ read ACTLR
	orreq r0, r0, #0x6		             @ Enable DP1(2), DP2(1)
	mcreq p15, 0, r0, c1, c0, 1	         @ write ACTLR

	/* Invalidate L1 I/D */
	mov	r0, #0			                 @ set up for MCR
	mcr	p15, 0, r0, c8, c7, 0	         @ invalidate TLBs
	mcr	p15, 0, r0, c7, c5, 0	         @ invalidate icache

	/* disable MMU stuff and caches */
	mrc	p15, 0, r0, c1, c0, 0
	bic	r0, r0, #0x00002000	             @ clear bits 13 (--V-)
	bic	r0, r0, #0x00000007	             @ clear bits 2:0 (-CAM)
	orr	r0, r0, #0x00001000	             @ set bit 12 (---I) Icache
	orr	r0, r0, #0x00000002	             @ set bit 1  (--A-) Align
	orr	r0, r0, #0x00000800	             @ set bit 11 (Z---) BTB
	mcr	p15, 0, r0, c1, c0, 0

    /* PS-Hold high */
    ldr r0, =0x1002330c
    ldr r1, [r0]
    orr r1, r1, #0x300
    str r1, [r0]

    ldr r0, =0x11000c08
    ldr r1, =0x0
    str r1, [r0]

    /* Clear MASK_WDT_RESET_REQUEST */
    ldr r0, =0x1002040c
    ldr r1, =0x00
    str r1, [r0]

    ldr r0, =0x11000104
    ldr r1, =0x00000001
    str r1, [r0]
    ldr r0, =0x11000100
    ldr r1, =0x00000001
    str r1, [r0]
loop:
    b loop
