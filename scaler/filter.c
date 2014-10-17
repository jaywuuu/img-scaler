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


UINT32 initFilter(FILTER *filt, UINT32 sz) {
	UINT32 retval = OK;

	filt->sz = sz;
	filt->coefs = (UINT32)malloc()

	return retval;
}