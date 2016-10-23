#define  ITEXTURE_COMPRESSED     %00000001
#define  ITEXTURE_ARBG           %00000010
#define  ITEXTURE_RBG            %00000100
#define  ITEXTURE_MIPMAP         %00001000	; 4 lvl
#define  ITEXTURE_LINEAR         %00010000
#define  ITEXTURE_PERSPECTIVE    %00100000
#define  ITEXTURE_OFFSET         3

; max ;

#define  ITEXTURE_MAX_SIZE       21763		; 128²+64²+32²+16²
#define  ITEXTURE_MAX_HEIGHT     128
#define  ITEXTURE_MAX_WIDTH      128

; texture format :
; .db flags
; .db height
; .db width
; .db data