/*
*
*	 Wrapper for stb_image.h and stb_image_write.h
*
*
*/

#include "image.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../stb/stb_image.h"
#include "../stb/stb_image_write.h"

void initImage(IMAGE *img, uint32 x, uint32 y, uint32 n) {
	img->width = x;
	img->height = y;
	img->depth = n;
	img->data = (byte*)malloc(x*y*n*sizeof(byte));
	memset(img->data, 0, x*y*n*sizeof(byte));
}

void freeImage(IMAGE *img) {
	free(img->data);
	free(img);
}

uint32 decodeImage(char *fileName, IMAGE *decodeTo) {
	decodeTo->data = stbi_load(fileName, &decodeTo->width, &decodeTo->height, &decodeTo->depth, 0);
	if (decodeTo->data == NULL) return ERR;
	return OK;
}

uint32 encodeImage(char *fileName, IMAGE *encodeFrom, ImageEncoding code) {
	if (encodeFrom == NULL) return ERR;

	int w = encodeFrom->width;
	int h = encodeFrom->height;
	int comp = encodeFrom->depth;

	int retval = 1;

	if (code == BMP) {
		retval = stbi_write_bmp(fileName, w, h, comp, encodeFrom->data);
	}
	else if (code == PNG) {
		retval = stbi_write_png(fileName, w, h, comp, encodeFrom->data, w*comp*sizeof(byte));
	}
	else if (code == TGA) {
		retval = stbi_write_tga(fileName, w, h, comp, encodeFrom->data);
	}

	if (retval == 0) return ERR;

	return OK;
}

void freeImageData(IMAGE *img) {
	stbi_image_free(img->data);
}