#ifndef _DEV_MPROC

#define _DEV_MPROC

#include "board.h"

struct s_MProc {
	p_wire	w_Data[8];
	p_wire	w_Address[16];

	p_gate	g_Clock;
	p_gate	g_Data[8];
	p_gate	g_Address[16];

	FNINPUT	task;
};

typedef struct s_MProc  t_MProc;

typedef struct s_MProc* p_MProc;

p_MProc devMProc;

void *MProcTask();

void *MProcInit();

#endif