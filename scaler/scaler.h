/*
* scaler.h
*
* author: Jason Wu
*/

#ifndef _SCALER_H_
#define _SCALER_H_

#include "types.h"
#include "image.h"
#include "filter.h"

// Default moving window size N x N
#define DFLT_SCL_WIN_SZ 3

/*
* Main scaling algorithm.
* input:	BYTE *	pointer to image structure
*			UINT32	scaling factor
*/
IMAGE *scale(IMAGE *img, uint32 scaleFactor);
uint32 expandImage(IMAGE *src, IMAGE *dst, uint32 scale);
uint32 apply1DScaleFilter(IMAGE *img, FILTER *filt, uint32 scale);

#endif
