#ifndef _DEV_CLOCK

#define _DEV_CLOCK

#include "board.h"

struct s_Clock {
	p_wire 	w_clock;
	p_gate 	g_clock;
	FN_VOID_VOID	task;
};

typedef struct s_Clock  t_Clock;

typedef struct s_Clock* p_Clock;

p_Clock devClock;

void *ClockTask();

void *ClockInit();

#endif