#ifndef _BUS

#define _BUS

#include <stdlib.h>

#ifdef __MINGW32__
#include <ncursest/ncurses.h>
#else
#include <curses.h>
#endif

#include "./bit_oper.h"
#include "./window.h"

#define SIG_HIST    8

#define BUS_NUM     16

#define SIG_BASE    0
#define SIG_GND 	0
#define SIG_VCC 	1
#define SIG_RESET	2
#define SIG_CLOCK	3

#define DATA_BASE   8
#define DATA_0   	0
#define DATA_1   	1
#define DATA_2   	2
#define DATA_3   	3
#define DATA_4   	4
#define DATA_5   	5
#define DATA_6   	6
#define DATA_7   	7

#define LMA_BASE   16
#define HMA_BASE   24

typedef struct {
	char	_b_signals;
	char	_data;
	char	_lma;
	char	_hma;
} t_bus;
t_bus	p_bus[ SIG_HIST ];

char* busSigName[ BUS_NUM ];

void busInit();

void busShow( t_window* dsp );

#endif