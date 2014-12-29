/*
* filter.h
*
* Scaling filters and definitons.
*
* author: Jason Wu
*/

#ifndef _FILTER_H_
#define _FILTER_H_

#include "types.h"

typedef struct tagFILTER {
	uint32 sz;			// Size of filter. 
	uint32 coefs[];		// coefficients
} FILTER;

extern FILTER Dflt_1DFilter_1x3;

#endif
