	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 1
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"log.c"
	.text
	.align	2
	.global	log2_non_optimized
	.arch armv7-a
	.syntax unified
	.arm
	.fpu vfpv3-d16
	.type	log2_non_optimized, %function
log2_non_optimized:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, lr}
	mov	r1, r0
	lsl	r3, r0, #1
	cmp	r3, #1073741824
	movle	r1, r3
	cmp	r3, #1073741824
	movgt	r0, #0
	movle	r0, #-1073741824
	movw	ip, #:lower16:.LANCHOR0
	movt	ip, #:upper16:.LANCHOR0
	mov	r2, #1
	mov	r4, r2
.L4:
	sub	r3, r2, #1
	add	r3, r1, r4, lsl r3
	add	r3, r1, r3, lsr r2
	ldr	lr, [ip, #4]!
	cmp	r3, #1073741824
	suble	r0, r0, lr
	movle	r1, r3
	add	r2, r2, #1
	cmp	r2, #30
	bne	.L4
	pop	{r4, pc}
	.size	log2_non_optimized, .-log2_non_optimized
	.align	2
	.global	log2_optimized
	.syntax unified
	.arm
	.fpu vfpv3-d16
	.type	log2_optimized, %function
log2_optimized:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, lr}
	mov	r2, r0
	ldr	r4, .L17
	mov	r1, #0
	mov	r3, r1
	mov	r0, r1
.L13:
	add	ip, r2, r3
	add	ip, r2, ip, lsr r1
	mov	r5, r4
	ldr	lr, [r4, #-12]
	cmp	ip, #1073741824
	suble	r0, r0, lr
	movle	r2, ip
	lsl	r3, r3, #1
	orr	r3, r3, #1
	mov	r6, r1
	add	lr, r2, r3
	add	ip, r1, #1
	add	lr, r2, lr, lsr ip
	ldr	ip, [r4, #-8]
	cmp	lr, #1073741824
	suble	r0, r0, ip
	movle	r2, lr
	lsl	r3, r3, #1
	orr	r3, r3, #1
	add	ip, r2, r3
	add	lr, r1, #2
	add	ip, r2, ip, lsr lr
	ldr	lr, [r4, #-4]
	cmp	ip, #1073741824
	suble	r0, r0, lr
	movle	r2, ip
	lsl	r3, r3, #1
	orr	r3, r3, #1
	add	r1, r1, #3
	add	r4, r4, #12
	cmp	r1, #30
	bne	.L13
	pop	{r4, r5, r6, pc}
.L18:
	.align	2
.L17:
	.word	.LANCHOR0+12
	.size	log2_optimized, .-log2_optimized
	.section	.rodata
	.align	2
	.set	.LANCHOR0,. + 0
	.type	log2_tab, %object
	.size	log2_tab, 120
log2_tab:
	.word	1073741824
	.word	628098702
	.word	345667660
	.word	182455581
	.word	93912511
	.word	47667823
	.word	24017256
	.word	12055174
	.word	6039314
	.word	3022600
	.word	1512037
	.word	756203
	.word	378148
	.word	189085
	.word	94546
	.word	47274
	.word	23637
	.word	11819
	.word	5909
	.word	2955
	.word	1477
	.word	739
	.word	369
	.word	185
	.word	92
	.word	46
	.word	23
	.word	12
	.word	6
	.word	3
	.ident	"GCC: (GNU) 8.2.1 20180801 (Red Hat 8.2.1-2)"
	.section	.note.GNU-stack,"",%progbits
