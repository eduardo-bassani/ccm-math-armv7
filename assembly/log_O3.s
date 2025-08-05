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
	movw	ip, #:lower16:.LANCHOR0
	mov	r1, r0
	push	{r4, lr}
	movgt	r1, r0
	movle	r1, r3
	movgt	r0, #0
	movle	r0, #-1073741824
	mov	r4, r2
	movt	ip, #:upper16:.LANCHOR0
.L4:
	sub	r3, r2, #1
	add	r3, r1, r4, lsl r3
	add	r3, r1, r3, lsr r2
	ldr	lr, [ip, #4]!
	cmp	r3, #1073741824
	add	r2, r2, #1
	movle	r1, r3
	suble	r0, r0, lr
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
	@ link register save eliminated.
	lsl	r3, r0, #1
	cmp	r3, #1073741824
	mov	r2, r0
	movle	r2, r3
	add	r1, r2, #1
	add	r1, r2, r1, lsr #1
	movle	r3, #-1073741824
	movle	r0, r2
	movgt	r3, #0
	cmp	r1, #1073741824
	movle	r2, r1
	suble	r3, r3, #1664
	add	r1, r2, #3
	suble	r3, r3, #536870926
	movle	r0, r2
	add	r2, r2, r1, lsr #2
	suble	r3, r3, #91226112
	cmp	r2, #1073741824
	movle	r0, r2
	addle	r3, r3, #-352321536
	addle	r3, r3, #6619136
	add	r1, r0, #7
	addle	r3, r3, #34560
	add	r1, r0, r1, lsr #3
	addle	r3, r3, #180
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	suble	r3, r3, #182452224
	add	r1, r2, #15
	suble	r3, r3, #3344
	add	r1, r2, r1, lsr #4
	suble	r3, r3, #13
	cmp	r1, #1073741824
	bgt	.L15
	mov	r2, r1
	mov	r0, r1
	add	r3, r3, #-100663296
	add	r3, r3, #6750208
	add	r3, r3, #576
	add	r3, r3, #1
.L15:
	add	r1, r2, #31
	add	r2, r2, r1, lsr #5
	cmp	r2, #1073741824
	movle	r0, r2
	addle	r3, r3, #-50331648
	addle	r3, r3, #2654208
	add	r1, r0, #63
	addle	r3, r3, #9600
	add	r1, r0, r1, lsr #6
	addle	r3, r3, #17
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	suble	r3, r3, #23855104
	add	r1, r2, #127
	suble	r3, r3, #161792
	add	r1, r2, r1, lsr #7
	suble	r3, r3, #360
	cmp	r1, #1073741824
	movle	r2, r1
	suble	r3, r3, #11993088
	add	r1, r2, #255
	movle	r0, r2
	suble	r3, r3, #61952
	add	r2, r2, r1, lsr #8
	suble	r3, r3, #134
	cmp	r2, #1073741824
	movle	r0, r2
	add	r2, r0, #508
	suble	r3, r3, #6029312
	add	r2, r2, #3
	suble	r3, r3, #9984
	add	r1, r0, r2, lsr #9
	suble	r3, r3, #18
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	add	r1, r2, #1020
	suble	r3, r3, #3014656
	add	r1, r1, #3
	suble	r3, r3, #7936
	add	r1, r2, r1, lsr #10
	suble	r3, r3, #8
	cmp	r1, #1073741824
	movle	r2, r1
	add	r1, r2, #2032
	suble	r3, r3, #1507328
	add	r1, r1, #15
	movle	r0, r2
	suble	r3, r3, #4672
	add	r2, r2, r1, lsr #11
	suble	r3, r3, #37
	cmp	r2, #1073741824
	movle	r0, r2
	add	r2, r0, #4080
	suble	r3, r3, #753664
	add	r2, r2, #15
	suble	r3, r3, #2528
	add	r1, r0, r2, lsr #12
	suble	r3, r3, #11
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	add	r1, r2, #8128
	suble	r3, r3, #376832
	add	r1, r1, #63
	suble	r3, r3, #1312
	add	r1, r2, r1, lsr #13
	suble	r3, r3, #4
	cmp	r1, #1073741824
	movle	r2, r1
	add	r1, r2, #16320
	suble	r3, r3, #188416
	add	r1, r1, #63
	movle	r0, r2
	suble	r3, r3, #668
	add	r2, r2, r1, lsr #14
	suble	r3, r3, #1
	cmp	r2, #1073741824
	movle	r0, r2
	add	r2, r0, #32512
	suble	r3, r3, #94208
	add	r2, r2, #255
	suble	r3, r3, #336
	add	r1, r0, r2, lsr #15
	suble	r3, r3, #2
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	add	r1, r2, #65280
	add	r1, r1, #255
	suble	r3, r3, #47104
	add	r1, r2, r1, lsr #16
	suble	r3, r3, #170
	cmp	r1, #1073741824
	movle	r2, r1
	movw	r1, #65535
	movt	r1, 1
	add	r1, r2, r1
	movle	r0, r2
	suble	r3, r3, #23552
	add	r2, r2, r1, lsr #17
	suble	r3, r3, #85
	cmp	r2, #1073741824
	movle	r0, r2
	sub	r2, r0, #-67108863
	sub	r2, r2, #66846720
	suble	r3, r3, #11776
	add	r1, r0, r2, lsr #18
	suble	r3, r3, #43
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	sub	r1, r2, #-67108863
	sub	ip, r1, #66584576
	suble	r3, r3, #5888
	add	ip, r2, ip, lsr #19
	suble	r3, r3, #21
	cmp	ip, #1073741824
	movle	r2, ip
	suble	r1, r2, #-67108863
	sub	r1, r1, #66060288
	movle	r0, r2
	suble	r3, r3, #2944
	add	r2, r2, r1, lsr #20
	suble	r3, r3, #11
	cmp	r2, #1073741824
	movle	r0, r2
	sub	r2, r0, #-67108863
	sub	r2, r2, #65011712
	suble	r3, r3, #1472
	add	r1, r0, r2, lsr #21
	suble	r3, r3, #5
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	sub	r1, r2, #-67108863
	sub	ip, r1, #62914560
	suble	r3, r3, #736
	add	ip, r2, ip, lsr #22
	suble	r3, r3, #3
	cmp	ip, #1073741824
	movle	r2, ip
	suble	r1, r2, #-67108863
	sub	r1, r1, #58720256
	movle	r0, r2
	suble	r3, r3, #368
	add	r2, r2, r1, lsr #23
	suble	r3, r3, #1
	cmp	r2, #1073741824
	movle	r0, r2
	add	r2, r0, #16777216
	sub	r2, r2, #1
	add	r1, r0, r2, lsr #24
	suble	r3, r3, #185
	cmp	r1, #1073741824
	mov	r2, r0
	movle	r0, r1
	movle	r2, r0
	add	r1, r2, #33554432
	sub	r1, r1, #1
	add	r1, r2, r1, lsr #25
	suble	r3, r3, #92
	cmp	r1, #1073741824
	movle	r2, r1
	sub	r1, r2, #-67108863
	movle	r0, r2
	add	r2, r2, r1, lsr #26
	suble	r3, r3, #46
	cmp	r2, #1073741824
	movle	r0, r2
	sub	r2, r0, #-134217727
	add	r2, r0, r2, lsr #27
	suble	r3, r3, #23
	cmp	r2, #1073741824
	movle	r0, r2
	sub	r2, r0, #-268435455
	add	r2, r0, r2, lsr #28
	suble	r3, r3, #12
	cmp	r2, #1073741824
	movle	r0, r2
	sub	r2, r0, #-536870911
	add	r0, r0, r2, lsr #29
	suble	r3, r3, #6
	cmp	r0, #1073741824
	suble	r3, r3, #3
	mov	r0, r3
	bx	lr
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
