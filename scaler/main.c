/* main */

#include <stdio.h>
#include "image.h"
#include "scaler.h"

void main(int argc, void *argv[]) {
	if (argc < 2 || argc > 3) {
		printf("Wrong number of arguments.\n");
		return;
	}
	
	IMAGE in;
	printf("Decoding image...\n");
	if (decodeImage((char*)argv[1], &in) == ERR) {
		printf("Error decoding image.\n");
		freeImageData(&in);
		return;
	}
	printf("Scaling...\n");
	IMAGE *out = scale(&in, 2);
	printf("Writing image out...\n");
	if (encodeImage((char*)argv[2], out, BMP) == ERR) {
		printf("Error writing image.\n");
		freeImage(out);
		freeImageData(&in);
		return;
	}
	freeImage(out);
	freeImageData(&in);
}