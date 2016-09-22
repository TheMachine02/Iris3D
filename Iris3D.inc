 ; ;
 ; Iris-3D library, version 1.0
 ;
 ; Copyright (c) 2016, ''
 ; All rights reserved.
 ; 
 ; Redistribution and use in source and binary forms, with or without
 ; modification, are permitted provided that the following conditions are met:
 ; 
 ; ; Redistributions of source code must retain the above copyright notice, this
 ; list of conditions and the following disclaimer.
 ; 
 ; ; Redistributions in binary form must reproduce the above copyright notice,
 ; this list of conditions and the following disclaimer in the documentation
 ; and/or other materials provided with the distribution.
 ; 
 ; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 ; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 ; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 ; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 ; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 ; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 ; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 ; CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 ; OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ; ;
 
#ifndef __iris_h_
#define __iris_h_

.nolist
#define OS__FLAGS           $D00080	
#ifndef TI84PCE
#include "ti84pce.inc"
.nolist
#endif

; standard defines ;

#define IRIS_VERSION        $10
#define ITRUE               $01
#define IFALSE              $00

; geometry ;

#define IPOINT              %00000001
#define ILINE               %00000010
#define ITRIANGLE           %00000011
#define IQUADRI             %00000100
#define ILINE_FAN           %10000010
#define ITRIANGLE_FAN       %10000011
#define IBACK_CULL          %00000001

#define IVERTEX_BUFFER      $D09466

; mesh ;

#define IMESH_C1N3I9        13
#define IMESH_C3N3I9        15
#define IMESH_C3I9          12
#define IMESH_C1I9          10
#define IMESH_N3I9          12
#define IMESH_I9            9
#define IMESH_PACKED        $80

; maths ;
#define IMATH_EXTEND        $FF0000
#define IMPI_FP8            804
#define IMPI_FP16           205887
#define IMATRIX_SIZE        $12
#define IQUATERNION_SIZE    $0C
#define IQW                 $0
#define IQX                 $3
#define IQY                 $6
#define IQZ                 $9

; RAM and VRAM ;

#define IFRAMEBUFFER_AUX0   $D40000	; first VRAM buffer
#define IFRAMEBUFFER_AUX1   $D52C00	; second VRAM buffer
#define IFRAMEBUFFER_SIZE   $12C00
#define IVRAM               $E30800
; 1024 bytes fast RAM (2TStates), routine reallocate ;
#define IDOUBLEBUFFER       %00000001
;#define IFramebuffer        $D03403
#define IFramebuffer        $E30014
#define ISCREEN_WIDTH       320
#define ISCREEN_HEIGHT      240

; color LCD ;

#define IBPP8               lcdBpp8   ; LCD 8 bpp mode bits
#define IBPP16              lcdBpp16	; LCD 16 bpp mode bits
#define ILCD_CTRL           mpLcdCtrl	; LCD control port
#define ILCD_IMSC           $E3001C	; LCD Interrupt Mask Register
#define ILCD_ICR            $E30028	; LCD Interrupt Clear/Set Register
#define ILCD_ISR            $E30020	; LCD Interrupt Status Register
#define ILCD_BUFFER         $E30010	; base adress of LCD
#define ILCD_PALETTE        mpLcdPalette ; palette (r3g3b2)
#define ILCD_VSYNC          %00000001	; vertical synchronisation
#define IPALETTE_RBG        %00000001
#define IRED_BITS           %11100000
#define IGREEN_BITS         %00000111
#define IBLUE_BITS          %00011000

; batch ;

#define IBATCH_DATA         IMAX_TRIANGLE*3+ITRIANGLE_LIST
#define IBATCH_DATA_SIZE    3
#define IBatchSize          $D03400

; depth test ;

#define IDEPTH_TEST         $01
#define IDEPTH_OFFSET       8388608
#define IDEPTH_BITS         24
#define IDEPTH_BUCKET       $D03200 ; 512 bytes of buckets
#define IDEPTH_MIN          -8388608
#define IDEPTH_MAX          8388608

; texture ;

#define ITEXTURE
#define ITEXTURE_FORMAT

; limits ;

#define IMAX_TRIANGLE       4096
#define IMAX_VERTEX         2048
#define IMAX_VRAM           1024
#define IMAX_TEXTURE_SIZE   256

; static variables ;

#define IPosition           $D03406
#define IPositionX          $D03406
#define IPositionY          $D03409
#define IPositionZ          $D0340C
#define ILayer              $D0340F

; functions ;

#ifdef  IRIS_CORE
#define IRIS_CORE_depthsort
#define IRIS_CORE_quatidentity
#define IRIS_CORE_quatmlt
#define IRIS_CORE_quatgetmatrix
#define IRIS_CORE_quatrotaxis
#define IRIS_CORE_matidentity
#define IRIS_CORE_matmlt
#define IRIS_CORE_rastertriangle
#define IRIS_CORE_veccross
#define IRIS_CORE_vecdot
#define IRIS_CORE_veclength
#define IRIS_CORE_vecnormalize
#define IRIS_CORE_vecproject
#define IRIS_CORE_vectransform
#endif

;#define	IRIS_EXT_color
;#define	IRIS_EXT_quaternion
;#define	IRIS_EXT_vector
;#define	IRIS_EXT_ecaa

#ifdef  IRIS_EXT_color
#define IRIS_EXT_colormlt
#define IRIS_EXT_colorscale
#define IRIS_EXT_colormix
#endif

#ifdef  IRIS_EXT_quaternion
#define IRIS_EXT_quatloadrotation
#define IRIS_EXT_quatmagnitude
#define IRIS_EXT_quatconjugate
#define IRIS_EXT_quatnormalize
#define IRIS_EXT_quatdot
#define IRIS_EXT_quatslerp
#endif

#ifdef  IRIS_EXT_vector
#define IRIS_EXT_vecmlt
#define IRIS_EXT_vecreflect
#endif

#define IRIS_DEBUG
#ifdef  IRIS_DEBUG
#define assert(cc) call IAbortProgram 
#else
#define assert(cc)
#endif

#define fma                  __ifma_src_()
#define slhl                 __islhl_src_()
#define .align               align(
.addinstr  ld a,hlu 3BF133E5 4
.addinstr  ld a,deu 3BF133D5 4
#define r0 $0
#define p0 $0

#macro srf()
   #define r0 1
#endmacro
#macro crf()
   #define r0 eval(1-r0)
#endmacro

; Fused multiply and add macro
; fma [bc,a,hl]
; Do hl = (bc x a) + hl
; bc:16bits, a:8bits, hl:24bits, accumulated on 24 bits
; From 122 to 132 TStates on 4 wait-states RAM [122,125,129,132]
; From 096 to 101 TStates on 3 wait-states RAM [096,97,100,101]
; 31 Bytes
#macro __ifma_src_()
#if  r0==0
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
#macro  __ilrp_src_()
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
#macro  __ipow_src_()
	ld	b,a
	inc	b			; assume no carry
	sbc	hl, hl		; hl = 0
	scf
	adc	hl,hl
	djnz	$-1
#endmacro

#macro  __islhl_src_()
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
#endmacro

#macro align(bound)
	.fill bound-($%bound)
#endmacro
#macro  __flrp__(src1,src2,alpha)
	push	hl
	ld	b, (hl)
; c is good
	ld	e, a
; e is good
	ld	l, e
	ld	a, b
	and	IGREEN_BITS
	ld	h, a
	mlt	hl
	ld	a, c
	and	IGREEN_BITS
	ld	d, a
	ld	a, e
	fneg	a
	ld	e, a
	mlt	de
	add	hl, de
	add	hl, hl
	add	hl, hl
	ld	l, a
	ld	e, a

	ld	a, h
	and	IGREEN_BITS
;	ld	MB, a
	.db	$ED,$6D

	ld	a, c
	and	IBLUE_BITS
	ld	h, a
	mlt	hl
	ld	a, b
	and	IBLUE_BITS
	ld	d, a
	ld	a, e
	fneg	a
	ld	e, a
	mlt	de
	add	hl, de
	add	hl, hl
	add	hl, hl
	ld	l, a
	ld	e, a
	ld	a, h
	and	IBLUE_BITS
	ld	h, a
	ld	a, MB
#define	IMAGIC_COMPENSATE0	$27
;;	sub	IMAGIC_COMPENSATE0
	or	h
;	ld	MB, a
	.db	$ED,$6D

	ld	a, b
	and	IRED_BITS
	ld	h, a
	mlt	hl
	ld	a, c
	and	IRED_BITS
	ld	d, a
	ld	a, e
	fneg	a
	ld	e, a
	mlt	de
	add	hl, de
	add	hl, hl
	add	hl, hl
	ld	a, h
	and	IRED_BITS
	ld	h, a
	ld	a, MB
#define	ICOMPENSATE_REGR1	$25
;;	sub	ICOMPENSATE_REGR1
	or	h
	pop	hl

#comment
	push	hl
	ld	b, (hl)
; b,c,e
	ld	e, a
	ld	a, b
	and	IGREEN_BITS	
	ld	h, a
	ld	a, c
	and	IGREEN_BITS
	sub	h
	jr	nc, $+4
	cpl
	inc	a
	ld	h, a
	ld	l, e
; convert flag
	sbc	a, a
	or	a, a
; c=nz, nc=z
	mlt	hl
	add	hl, hl
	add	hl, hl
	ld	a, h
	jr	z, $+4
	neg	
	ld	h, a
	ld	a, b
	and	IGREEN_BITS
	add	a, h
	ld	d, a
; 138

	ld	a, b
	and	IBLUE_BITS
	ld	h, a
	ld	a, c
	and	IBLUE_BITS
	sub	h
	jr	nc, $+4
	cpl
	inc	a
	ld	h, a
	ld	l, e
	mlt	hl
	rl	h	; push down carry flag	
	add	hl, hl
	ld	a, h
	and	IBLUE_BITS
	bit	1, h
	jr	z, $+4
	neg
	ld	h, a
	ld	a, b
	and	IBLUE_BITS
	add	a, h
	or	d
	ld	d, a
; 280

	ld	a, b
	and	IRED_BITS
	ld	h, a
	ld	a, c
	and	IRED_BITS
	sub	h
	jr	nc, $+4
	cpl
	inc	a ; neg, put different flag output
	ld	h, a
	ld	l, e
	mlt	hl
	rl	h ; push down carry flag
	ld	a, h
	and	IRED_BITS>>1
	bit	0, h
	jr	z, $+4
	neg
	ld	h, a
	ld	a, b
	rra
	and	IRED_BITS>>1
	add	a, h
	sla	a
	or	d

	pop	hl
; 452 TStates
#endcomment
#endmacro
#define	flrp	__flrp__(
#macro	__fmlt__(x)
	mlt	hl
	add	hl, hl
	add	hl, hl
	ld	a, h
#endmacro
#define	fmlt	__fmlt__(
.addinstr	fneg a 41C62F 3 NOP 1
.addinstr  ld a,(hl+) 000000 3 NOP 1
.addinstr  ld (hl+),a 000000 3 NOP 1

.list

; global compilation variable ;

#define IRIS_fine_pxlcoverage ; slower but better coverage calculation at pxl level
; about 200 TStates slower setup + more writed pxl
;#define IRIS_fast_AAx2       ; a fast x2 AA at triangle edge (one color gradient)

#endif