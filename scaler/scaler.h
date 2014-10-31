/*
* scaler.h
*
* author: Jason Wu
*/

#include "types.h"
#include "image.h"

// Default moving window size N x N
#define DFLT_SCL_WIN_SZ 3

/*
* Main scaling algorithm.
* input:	BYTE *	pointer to image structure
*			UINT32	scaling factor
*/
uint32 scale(IMAGE *, uint32, );

