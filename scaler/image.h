/*
* image.h
*
* Wrapper for STB
*
* author: Jason Wu
*/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "types.h"

typedef struct tagIMAGE {
	uint32 width;
	uint32 height;
	uint32 depth;		// number of colour channels
	byte *data;			// pointer to pixels
} IMAGE;

typedef enum {
	BMP = 0,
	PNG,
	TGA
} ImageEncoding;

typedef enum {
	Y = 1,
	YA,
	RGB,
	RGBA
} ImageComponents;

void initImage(IMAGE *img, uint32 x, uint32 y, uint32 n);
void freeImage(IMAGE *img);
uint32 decodeImage(char *fileName, IMAGE *decodeTo);
uint32 encodeImage(char *fileName, IMAGE *encodeFrom, ImageEncoding code);
void freeImageData(IMAGE *img);


#endif