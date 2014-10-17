/*
* filter.h
*
* Scaling filters and definitons.
*
* author: Jason Wu
*/

#include "types.h"

typedef struct tagFILTER {
	UINT32 sz;			// Size of filter. 
	UINT32[] coefs;		// coefficients
} FILTER;

UINT32 initDefaultFilters();