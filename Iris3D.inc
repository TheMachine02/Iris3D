.nolist
#ifndef	__IGUARD__
#define	__IGUARD__


#define	IVERSION		$0100
#define	IVERMAJOR		1
#define	IVERMINOR		0
#define	ICODENAME		"Colorfull"

.echo	"Using Iris API 'Colorfull' version 1.0"

#define	ITRUE			$01
#define	IFALSE		$00
#define	ISCREEN_W		320
#define	ISCREEN_H		240

; OS define and OS specific stuffs

#define	__OS__FLAGS	$D00080	
#ifndef	TI84PCE
#include	"ti84pce.inc"
.nolist
#endif

; Math include

#define	IMATH_EXTEND	$FF0000
#define	IMATH_FP6		$26	; integer 2 bits | fractionnal 6 bits
#define	IMATH_FP12		$2C	; integer 2 bits | fractionnal 12 bits (double precision)
#define	IMATH_FP8		$88	; Integer 8 bits | fractionnal 8 bits
#define	IMATH_FP16		$F8	; integer 8 bits | fractionnal 16 bits (double precision)
#define	IMHTAN_FP8		197
#define	IMHTAN_FP6		45
#define	IMHTAN_FP16	45889
#define	IMPI_FP6		201
#define	IMPI_FP8		804
#define	IMPI_FP16		205887

#define	IMATRIX_SIZE	(3*3)+(9*1)
#define	IQUATERNION_SIZE	(3*4)

#define	IQW	0
#define	IQX	3
#define	IQY	6
#define	IQZ	9

#define	__iwritetmp__	$D03603

#define	fma			__ifma_src_()
;#define	lrp			__ilrp_src_()
#define	pow			__ipow_src_()
#define	slhl			__islhl_src_()
#define	rcp			call	IReciprocal
#define	xpd			call	IVectorCross
#define	dp3			call	IVectorDot
#define	.vertex		__ivertex_src_(
#define	.normal		__inormal_src_(

; math block register save flags
#define	r0			0
; jump prediction flag
#define	p0			0

; geometry include

#define	IPOINT		%00000001
#define	ILINE			%00000010
#define	ITRIANGLE		%00000011
#define	IQUADRI		%00000100
#define	ILINE_FAN		%10000010
#define	ITRIANGLE_FAN	%10000011
#define	IBACK_CULL		%00000001

; raster system include

; Color LCD include

#define	IBPP8			lcdBpp8	; LCD 8 bpp mode bits
#define	IBPP16		lcdBpp16	; LCD 16 bpp mode bits
#define	ILCD_CTRL		mpLcdCtrl	; LCD control port
#define	ILCD_IMSC		$E3001C	; LCD Interrupt Mask Register
#define	ILCD_ICR		$E30028	; LCD Interrupt Clear/Set Register
#define	ILCD_RIS		$E30020	; LCD Interrupt Status Register
#define	ILCD_BUFFER	$E30010	; base adress of LCD
#define	ILCD_PALETTE	mpLcdPalette	; palette (r3g3b2)
#define	ILCD_VSYNC		%00000001	; vertical synchronisation
#define	IPALETTE_RBG	%00000001
#define	IPALETTE_RGB	%00000011
#define	IPALETTE_IRBG	%00000100
#define	IPALETTE_IRGB	%00001100


; target buffers, 76800 bytes each

#define	IVRAMF0		$D40000	; first VRAM buffer
#define	IVRAMF1		$D52C00	; second VRAM buffer

; Structure/data include

#define	IPositionX		$D03603
#define	IPositionY		$D03606
#define	IPositionZ		$D03609

#define	IBUFFER_ADRESS	$D03200
#define	IPIPE_ADRESS	IBUFFER_ADRESS + 512
#define	IPipelineState	IPIPE_ADRESS
#define	IVertexShader	IPIPE_ADRESS
#define	IGeomShader	IPIPE_ADRESS + 4
#define	IPixelShader	IPIPE_ADRESS + 8
#define	IFramebuffer	IPIPE_ADRESS + 12
#define	IPipelineFlags	IPIPE_ADRESS + 15
; 16 bytes structure

#define	IVRAM			$E30800
; 1024 bytes fast RAM (2TStates), texture, routine reallocate

; limits

#define	IMAX_LIGHT		0
#define	IMAX_TEXTURE	0
#define	IMAX_VSH_IN	0
#define	IMAX_VSH_OUT	0
#define	IMAX_GSH_OUT	0
#define	IMAX_FSH_IN	0

; functions include

; vectors
#define	IUSE_FN_VECCROSS
#define	IUSE_FN_VECDOT
#define	IUSE_FN_VECNORMALIZE
#define	IUSE_FN_VECLENGTH
#define	IUSE_FN_VECAPPROXLENGTH
#define	IUSE_FN_VECCOPY
; quaternions
#define	IUSE_FN_QUATLOADIDENTITY
#define	IUSE_FN_QUATLOADROTATION
#define	IUSE_FN_QUATMAGNITUDE
#define	IUSE_FN_QUATMULT
#define	IUSE_FN_QUATCONJUGATE
#define	IUSE_FN_QUATNORMALIZE
#define	IUSE_FN_QUATGETMATRIX
; matrix
#define	IUSE_FN_MATLOADIDENTITY
#define	IUSE_FN_MATLOADROTATION
#define	IUSE_FN_MATTRANSPOSE
#define	IUSE_FN_MATMULT
#define	IUSE_FN_VECTRANSFORM
#define	IUSE_FN_VECPROJECT
; colors
#define	IUSE_FN_MIXR5G6B5
#define	IUSE_FN_MIXR3G3B2

; vertex model include

#macro	__ivertex_src_(x,y,z)
	.dw	x,y,z
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

#macro align(boundary)
	.fill boundary-($%boundary)
#endmacro
#define .align align(

.addinstr ld a,hlu 3BF133E5 4

#endif
.list
