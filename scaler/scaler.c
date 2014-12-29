/*
* scaler.c
*
* Scaling algorithms
*
* author: Jason Wu
*/

#include <stdlib.h>
#include "scaler.h"
#include "filter.h"

/* only scales by multiple of 2 for now */
IMAGE *scale(IMAGE *img, uint32 scaleFactor) {
	IMAGE *out = (IMAGE*)malloc(sizeof(IMAGE));
	initImage(out, scaleFactor*img->width, scaleFactor*img->height, img->depth);
	
	if (expandImage(img, out, scaleFactor) == ERR) return NULL;
	if (apply1DScaleFilter(out, &Dflt_1DFilter_1x3, scaleFactor) == ERR) return NULL;

	return out;
}

uint32 expandImage(IMAGE *src, IMAGE *dst, uint32 scale) {
	uint32 retval = OK;
	if (src == NULL || dst == NULL) return ERR;
	int x = src->width;
	int y = src->height;
	int n = src->depth;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < n; k++) {
				int idxSrc = i*x*n + j*n + k;
				int idxDst = scale*scale*i*x*n + scale*j*n + k;
				dst->data[idxDst] = src->data[idxSrc];
			}
		}
	}

	return retval;
}

/* applies filter only on empty pixels according to scale factor */
/* TODO: need to make this more safe and general */
uint32 apply1DScaleFilter(IMAGE *img, FILTER *filt, uint32 scale) {
	if (img == NULL || filt == NULL) return ERR;
	int x = img->width;
	int y = img->height;
	int n = img->depth;
	int pixels = x*y;
	int numBytes = pixels*n;
	int filtSize = filt->sz;
	int filtA = 0;

	// calculate filter total
	for (int fi = 0; fi < filtSize; fi++) filtA += filt->coefs[fi];

	// do horizonatally first
	for (int i = 0; i < y; i+=scale) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < n; k++) {
				// skip this pixel because we already have it
				if (j % scale == 0) continue;
				int idx = i*x*n + j*n + k;
				int pixelVal = 0;
				for (int f = 0; f < filtSize; f++) {
					pixelVal += img->data[idx - (filtSize / 2)*n + f*n + k];
				}
				img->data[idx] = pixelVal / filtA;
			}
		}
	}

	// do vertically
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < n; k++) {
				if (i % scale == 0) continue;
				int idx = i*x*n + j*n + k;
				int pixelVal = 0;
				for (int f = 0; f < filtSize; f++) {
					if (i - filtSize / 2 + f >= y) break;
					pixelVal += img->data[idx - (filtSize / 2)*x*n + f*x*n + k];
				}
				img->data[idx] = pixelVal / filtA;
			}
		}
	}

	return OK;
}