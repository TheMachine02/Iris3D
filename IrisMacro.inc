#if	IVERSION==$0100

; vertex model include

#macro	__ivertex_src_(x,y,z)
; include vertex information
.dl	x&$00FFFF
.dl	y&$00FFFF
.dl	z&$00FFFF
#endmacro

; normal model include

#macro	__inormal_src_(x,y,z)
; include normal information
	.db	x,y,z
#endmacro

; value absolute (compile-time)

#macro	IAbs16(val)
#if	val&$8000
val=-val
#endif
val
#endmacro

#macro	IAbs24(val)
#if	val&$800000
val=-val
#endif
val
#endmacro

#macro	srf()
	#define	r0	1
#endmacro
#macro	crf()
	#define	r0	eval(1-r0)
#endmacro

; Fused multiply and add macro
; fma [bc,a,hl]
; Do hl = (bc x a) + hl
; bc:16bits, a:8bits, hl:24bits, accumulated on 24 bits
; From 122 to 132 TStates on 4 wait-states RAM [122,125,129,132]
; From 096 to 101 TStates on 3 wait-states RAM [096,97,100,101]
; 31 Bytes
#macro	__ifma_src_()
#if	r0==0
	ex	de, hl
	ld	h, b
	ld	l, a
	mlt	hl
	cp	$80
	jr	c, $+4
	sbc	hl, bc
	bit	7, b
	ld	b, a
	jr	z, $+5
	ld	a, h
	sub	a, b
	ld	h, a
	slhl
	mlt	bc
	add	hl, bc
	add	hl, de
#else
	ld	d, c	
	ld	e, a
	mlt	de
	add	hl, de
	ex	de, hl
	ld	h, b
	ld	l, a	
	mlt	hl
; watch the carry flag !
	cp	$80
	jr	c, $+4
	sbc	hl, bc
	bit	7, b
	jr	z, $+5
	cpl
	adc	a, h
	ld	h, a
	slhl
	add	hl, de
; ok, that was fast !
#endif
#endmacro

; Linear interpolation macro
; lrp [b,c,a] [src0,src1,src2]
; Do a = src0 * src1 + (1-src0) * src2
; b:8bits, c:8bits, a:6bits
; 72 TStates on 4 wait-states RAM
; 56 TStates on 3 wait-states RAM
; 16 Bytes
#macro	__ilrp_src_()
	ld	l, a
	ld	h, b
	mlt	hl
	add	hl, hl
	add	hl, hl
	neg
	ld	l, a
	ld	a, h
	ld	h, c
	mlt	hl
	add	hl, hl
	add	hl, hl
	add	a, h
#endmacro

; Power macro
; pow [a]
; Do hl = 2^a (overflow if a>23)
; a:8bits
; Max 500 TStates on 4 wait-states RAM
; 9 Bytes
#macro	__ipow_src_()
	ld	b,a
	inc	b			; assume no carry
	sbc	hl, hl		; hl = 0
	scf
	adc	hl,hl
	djnz	$-1
#endmacro

#macro	__islhl_src_()
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
#endmacro

#macro	__ircp_src_()
	call	IReciprocal
#endmacro


#comment
; From 105 to 129 TStates on 4 Wait States RAM
; 53 Bytes

; old routine
;__ifma_routine_FP6:
	tst	a, $80	; [8]
	jr	nz, $+25	; [13/8]
	ld	c, a		; [4]
	ld	b, h		; [4]
	ld	h, a		; [4]
	mlt	bc		; [12]
	mlt	hl		; [12]
	ld	b, c		; [4]
	ld	c, 0		; [8]
	add	hl, bc	; [4]
	bit	7, h		; [8]
	jr	z, $+7	; [13/8]
	ld	bc, IMATH_EXTEND	; [16]
	add	hl, bc	; [4]
;__ifma_skipext:
	add	hl, de	; [4]
	jr	$+27		; [12]
;__ifma_negate:
	neg			; [8]
	ld	c, a		; [4]
	ld	b, h		; [4]
	ld	h, a		; [4]
	mlt	bc		; [12]
	mlt	hl		; [12]
	ld	b, c		; [4]
	ld	c, 0		; [8]
	add	hl, bc	; [4]
	bit	7, h		; [8]
	jr	z, $+7	; [13/8]
	ld	bc, IMATH_EXTEND	; [16]
	add	hl, bc	; [4]
;__ifma_skipext:
	ex	de, hl	; [4]
	sbc	hl, de	; [8]
;__ifma_end:
#endcomment

#else
	.echo	"IrisMacro.inc version doesn't correspond to Iris3D.inc version"
#endif
