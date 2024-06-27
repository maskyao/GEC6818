#ifndef __COMMON_H
#define __COMMON_H

#include <time.h> 
#include <stdio.h> 
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <linux/fb.h>
#include <linux/input.h>

#define MATRIX_X0     0   //整个棋盘的左上角顶点的x轴坐标
#define MATRIX_Y0     0   //整个棋盘的左上角顶点的y轴坐标

#define BOARDSIZE  4  // 整个棋盘的大小BORADSIZE * BOARDSIZE

#define MOVE_LEFT  1
#define MOVE_RIGHT 2
#define MOVE_UP    3
#define MOVE_DOWN  4

extern int g_lcd_width;
extern int g_lcd_height;
extern int g_lcd_bpp;

//游戏结束标志
bool game_over = false;

int *plcd = NULL;//指向framebuffer(屏幕显存第一个点的内存)

//将所有的图片名保存到一个数组中
const char * bmpfiles[] =	
{
	"res/2.bmp", 
	"res/4.bmp",
	"res/8.bmp",
	"res/16.bmp",
	"res/32.bmp",
	"res/64.bmp",
	"res/128.bmp",
	"res/256.bmp",
	"res/512.bmp",
	"res/1024.bmp",
	"res/2048.bmp",
	"res/4096.bmp",
	"res/8192.bmp",
	"res/16384.bmp",
	"res/32768.bmp",
	"res/65536.bmp",
};


#endif
