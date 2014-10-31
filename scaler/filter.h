/*
* filter.h
*
* Scaling filters and definitons.
*
* author: Jason Wu
*/

#include "types.h"

typedef struct tagFILTER {
	uint32 sz;			// Size of filter. 
	uint32 coefs[];		// coefficients
} FILTER;
