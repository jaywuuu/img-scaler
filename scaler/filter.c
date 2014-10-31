/*
* filter.c
*
* Initialize default scaling filters.
*
* author: Jason Wu
*/

#include "filter.h"

extern FILTER Dflt_Filter_3x3 = {
	3,
	{
		1, 3, 1,
		3, 5, 3,
		1, 3, 1
	}
};


uint32 initFilter(FILTER *filt, uint32 sz) {
	uint32 retval = OK;

	filt->sz = sz;
	filt->coefs = (uint32)malloc(sizeof(uint32)*sz);

	return retval;
}