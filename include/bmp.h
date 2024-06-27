#ifndef __BMP_H
#define __BMP_H

struct header
{
	int16_t type;
	int32_t size;
	int16_t reserved1;
	int16_t reserved2;
	int32_t offbytes;
}__attribute__((packed));


struct info
{
	int32_t size;
	int32_t width;
	int32_t height;
	int16_t planes;

	int16_t bit_count;
	int32_t compression;
	int32_t size_img;
	int32_t xpel;
	int32_t ypel;
	int32_t clrused;
	int32_t partant;
}__attribute__((packed));

#endif
