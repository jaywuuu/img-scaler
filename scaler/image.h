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
	uint32 width;
	uint32 height;
	uint32 depth;		// number of colour channels
} IMAGE;

uint32 loadImage();