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
#include	"IrisMacro.inc"

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

#define	fma			__ifma_src_(
#define	lrp			__ilrp_src_(
#define	pow			__ipow_src_(
#define	rcp			__ircp_src_(
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

#define	IRASTER_TILE	8
#define	IRASTER_CDIST	(ISCREEN_W*32768)/IMHTAN_FP16
#define	IRASTER_ADIST	256
#define	IRASTER_DX		1
#define	IRASTER_DY		1

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
#define	IR3G3B2		$000332	; standard Iris3D format
#define	IR5G6B5		$000565	; 16bits color format

; target buffers, 76800 bytes each

#define	IVRAM0		$D40000	; first VRAM buffer
#define	IVRAM1		$D52C00	; second VRAM buffer

; Structure/data include

#define	IPositionX		$D03303
#define	IPositionY		$D03306
#define	IPositionZ		$D03309

#define	IBUFFER_ADRESS	$D03200
#define	ISIN_TABLE		IBUFFER_ADRESS
#define	ISIN_TABLE_SIZE	256
#define	IPIPE_ADRESS	IBUFFER_ADRESS + 256
#define	IPipelineState	IPIPE_ADRESS
#define	IVertexShader	IPIPE_ADRESS
#define	IGeomShader	IPIPE_ADRESS + 4
#define	IPixelShader	IPIPE_ADRESS + 8
#define	IFramebuffer	IPIPE_ADRESS + 12
#define	IPipelineFlags	IPIPE_ADRESS + 15
; 16 bytes structure

#define	IVERTEX_CACHE	$E30800
; 64 entries : 384 bytes
#define	ICACHE		$E30980
; 128 bytes free
#define	IVRAM			$E30A00
; 512 bytes, texture, routine reallocate

; limits

#define	IMAX_LIGHT		0
#define	IMAX_TEXTURE	0
#define	IMAX_VSH_IN	0
#define	IMAX_VSH_OUT	0
#define	IMAX_GSH_OUT	0
#define	IMAX_FSH_IN	0

; functions include

; vectors
#define	IUSE_FN_SPVECCROSS
#define	IUSE_FN_SPVECDOT
#define	IUSE_FN_DPVECCROSS
#define	IUSE_FN_DPVECDOT
#define	IUSE_FN_SPVECNORMALIZE
#define	IUSE_FN_SPVECLENGTH
#define	IUSE_FN_SPVECAPPROXLENGTH
#define	IUSE_FN_SPVECCOPY
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
#define	IUSE_FN_TRANSFORM
; colors
#define	IUSE_FN_MIXR5G6B5
#define	IUSE_FN_MIXR3G3B2
#endif
.list
