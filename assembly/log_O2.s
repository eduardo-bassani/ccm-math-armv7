	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
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
	mov	r2, #1
	lsl	r3, r0, r2
	cmp	r3, #1073741824
	push	{r4, lr}
	movw	lr, #1678
	mov	r1, r0
	mov	r4, r2
	movgt	r1, r0
	movle	r1, r3
	movgt	r0, #0
	movle	r0, #-1073741824
	ldr	ip, .L10
	movt	lr, 9584
.L5:
	sub	r3, r2, #1
	add	r3, r1, r4, lsl r3
	add	r3, r1, r3, lsr r2
	cmp	r3, #1073741824
	add	r2, r2, #1
	movle	r1, r3
	suble	r0, r0, lr
	cmp	r2, #30
	popeq	{r4, pc}
	ldr	lr, [ip, #4]!
	b	.L5
.L11:
	.align	2
.L10:
	.word	.LANCHOR0+4
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
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr}
	mov	r4, #0
	movw	r5, #:lower16:.LANCHOR0
	movw	r7, #30796
	movw	r8, #1678
	mov	r2, r4
	mov	r6, r4
	mov	fp, #1073741824
	movt	r5, #:upper16:.LANCHOR0
	movt	r7, 5274
	movt	r8, 9584
	b	.L17
.L20:
	ldr	fp, [r5, #12]
	ldr	r8, [r5, #16]
	ldr	r7, [r5, #20]
	add	r5, r5, #12
.L17:
	lsl	r3, r2, #1
	add	r2, r0, r2
	add	r2, r0, r2, lsr r4
	cmp	r2, #1073741824
	mov	r1, r0
	movle	r0, r2
	movle	r1, r0
	orr	r3, r3, #1
	add	r2, r3, r1
	add	r10, r4, #1
	add	r2, r1, r2, lsr r10
	suble	r6, r6, fp
	cmp	r2, #1073741824
	movle	r1, r2
	lsl	lr, r3, #1
	orr	lr, lr, #1
	add	r9, r4, #2
	add	r3, lr, r1
	add	r3, r1, r3, lsr r9
	movle	r0, r1
	suble	r6, r6, r8
	add	r4, r4, #3
	cmp	r3, #1073741824
	lsl	ip, lr, #1
	movle	r0, r3
	suble	r6, r6, r7
	cmp	r4, #30
	orr	r2, ip, #1
	bne	.L20
	mov	r0, r6
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, pc}
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
