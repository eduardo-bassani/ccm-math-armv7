	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"log.c"
	.text
	.section	.rodata
	.align	2
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
	.text
	.align	2
	.global	log2_non_optimized
	.arch armv7-a
	.syntax unified
	.arm
	.fpu vfpv3-d16
	.type	log2_non_optimized, %function
log2_non_optimized:
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #44
	str	r0, [fp, #-40]
	ldr	r3, [fp, #-40]
	str	r3, [fp, #-8]
	mov	r3, #0
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #1
	str	r3, [fp, #-20]
	mov	r2, #1073741824
	ldr	r3, [fp, #-12]
	sub	r3, r3, r2
	str	r3, [fp, #-24]
	ldr	r3, [fp, #-20]
	cmp	r3, #1073741824
	bgt	.L2
	ldr	r3, [fp, #-20]
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-24]
	str	r3, [fp, #-12]
.L2:
	mov	r3, #1
	str	r3, [fp, #-16]
	b	.L3
.L5:
	ldr	r3, [fp, #-16]
	sub	r3, r3, #1
	mov	r2, #1
	lsl	r2, r2, r3
	ldr	r3, [fp, #-8]
	add	r2, r2, r3
	ldr	r3, [fp, #-16]
	lsr	r2, r2, r3
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	str	r3, [fp, #-28]
	movw	r3, #:lower16:log2_tab
	movt	r3, #:upper16:log2_tab
	ldr	r2, [fp, #-16]
	ldr	r3, [r3, r2, lsl #2]
	ldr	r2, [fp, #-12]
	sub	r3, r2, r3
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-28]
	cmp	r3, #1073741824
	bgt	.L4
	ldr	r3, [fp, #-28]
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-32]
	str	r3, [fp, #-12]
.L4:
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L3:
	ldr	r3, [fp, #-16]
	cmp	r3, #29
	ble	.L5
	ldr	r3, [fp, #-12]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	log2_non_optimized, .-log2_non_optimized
	.align	2
	.global	log2_optimized
	.syntax unified
	.arm
	.fpu vfpv3-d16
	.type	log2_optimized, %function
log2_optimized:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r4, r5, r6, r7, r8, r9, r10, fp}
	add	fp, sp, #28
	sub	sp, sp, #8
	str	r0, [fp, #-32]
	ldr	r10, [fp, #-32]
	mov	r7, #0
	movw	r5, #:lower16:log2_tab
	movt	r5, #:upper16:log2_tab
	mov	r4, #0
	mov	r6, #0
	b	.L8
.L12:
	mov	r3, r10
	add	r3, r4, r3
	lsr	r3, r3, r6
	mov	r2, r10
	add	r3, r3, r2
	mov	r8, r3
	mov	r3, r5
	add	r5, r3, #4
	ldr	r3, [r3]
	sub	r9, r7, r3
	cmp	r8, #1073741824
	bgt	.L9
	mov	r10, r8
	mov	r7, r9
.L9:
	lsl	r3, r4, #1
	orr	r4, r3, #1
	mov	r3, r10
	add	r2, r4, r3
	add	r3, r6, #1
	lsr	r3, r2, r3
	mov	r2, r10
	add	r3, r3, r2
	mov	r8, r3
	mov	r3, r5
	add	r5, r3, #4
	ldr	r3, [r3]
	sub	r9, r7, r3
	cmp	r8, #1073741824
	bgt	.L10
	mov	r10, r8
	mov	r7, r9
.L10:
	lsl	r3, r4, #1
	orr	r4, r3, #1
	mov	r3, r10
	add	r2, r4, r3
	add	r3, r6, #2
	lsr	r3, r2, r3
	mov	r2, r10
	add	r3, r3, r2
	mov	r8, r3
	mov	r3, r5
	add	r5, r3, #4
	ldr	r3, [r3]
	sub	r9, r7, r3
	cmp	r8, #1073741824
	bgt	.L11
	mov	r10, r8
	mov	r7, r9
.L11:
	lsl	r3, r4, #1
	orr	r4, r3, #1
	add	r6, r6, #3
.L8:
	cmp	r6, #29
	ble	.L12
	mov	r3, r7
	mov	r0, r3
	sub	sp, fp, #28
	@ sp needed
	pop	{r4, r5, r6, r7, r8, r9, r10, fp}
	bx	lr
	.size	log2_optimized, .-log2_optimized
	.ident	"GCC: (GNU) 8.2.1 20180801 (Red Hat 8.2.1-2)"
	.section	.note.GNU-stack,"",%progbits
