#ifndef	IRIS_MODELGUARD
#define	IRIS_MODELGUARD

IVERTEX_BASE=$D09466

#macro  _ivertex_(x,y,z)
.dw x,y,z 
#endmacro
#define .v _ivertex_(
#macro _iface_(i,j,k)
.dl i*8+IVERTEX_BASE
.dl j*8+IVERTEX_BASE
.dl k*8+IVERTEX_BASE
#endmacro
#define .f _iface_(
#macro	_ivorg_(new)
IVERTEX_BASE=new*8+IVERTEX_BASE
#endmacro
#define	.vorg	_ivorg_(
.org $0

#endif
