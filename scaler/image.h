/*
* image.h
*
* Image structure and definitions and IO functions.
*
* author: Jason Wu
*/

#include "types.h"

typedef struct tagBITMAP_FILE_HEADER {

} BITMAP_FILE_HEADER;

typedef struct tagIMAGE {
	UINT32 width;
	UINT32 height;
	UINT32 depth;		// number of colour channels
} IMAGE;

UINT32 loadImage();