#ifndef _HEAD4AUDIO_H_
#define _HEAD4AUDIO_H_


#include <stdio.h>  
#include <stdint.h>  
#include <malloc.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  
#include <getopt.h>  
#include <fcntl.h>  
#include <ctype.h>  
#include <errno.h>  
#include <limits.h>  
#include <time.h> 
#include <locale.h>  
#include <signal.h>  

#include <sys/unistd.h>  
#include <sys/stat.h>  
#include <sys/types.h>  

#include "alsa/asoundlib.h"

#define WAV_FMT_PCM             0x0001  

#define MIN(a, b) \
	({ \
		typeof(a) _a = a; \
		typeof(b) _b = b; \
		(void)(_a == _b); \
		_a < _b ? _a : _b; \
	})

typedef long long off64_t;

// ============================================================== //

// 1: the RIFF chunk
struct wav_header
{
	uint32_t id;	// 固定为'RIFF'
	uint32_t size;	// 除了id和size之外，整个WAV文件的大小
	uint32_t format;// fmt chunk的格式，此处为'WAVE'
};

// 2: the fmt chunk
struct wav_fmt
{
	uint32_t fmt_id;	// 固定为'fmt '
	uint32_t fmt_size;	// 在fmt chunk中除了fmt_id和fmt_size之外的大小，固定为16字节
	uint16_t fmt;		// data chunk中数据的格式代码，PCM的代码是0x0001
	uint16_t channels;	// 声道数目，由用户设置：1为单声道，2为立体声
	uint32_t sample_rate;		// 采样频率，由用户设置：典型值是11025Hz、22050Hz和44100Hz
	uint32_t byte_rate;		// 码率 = 采样率 * 帧大小
	uint16_t block_align;		// 帧大小 = 声道数 * 量化级/8
	uint16_t bits_per_sample;	// 量化位数，由用户设置：典型值是8、16、32
};

// 3: the data chunk
struct wav_data
{
	uint32_t data_id;	// 固定为'data'
	uint32_t data_size;	// 除了WAV格式头之外的音频数据大小
};

typedef struct
{
	struct wav_header head;
	struct wav_fmt format;
	struct wav_data data;

}wav_format;

// ============================================================== //

typedef struct
{  
    snd_pcm_t *handle; // PCM设备操作句柄
    snd_pcm_format_t format; // 数据格式

    uint16_t channels;
    size_t bits_per_sample;   // 一个采样点内的位数（8位、16位）
    size_t bytes_per_frame;   // 一个帧内的字节个数

    snd_pcm_uframes_t frames_per_period; // 一个周期内的帧个数
    snd_pcm_uframes_t frames_per_buffer; // 系统buffer的帧个数

    uint8_t *period_buf; // 用以存放从WAV文件中读取的最多一个周期的数据

}pcm_container;  
  
#endif
