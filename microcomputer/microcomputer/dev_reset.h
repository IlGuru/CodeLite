#ifndef _DEV_RESET

#define _DEV_RESET

#include "board.h"

struct s_Reset {
	char	counter;
	p_wire 	w_reset;
	p_gate 	g_reset;
	FN_VOID_VOID	task;
};

typedef struct s_Reset  t_Reset;

typedef struct s_Reset* p_Reset;

p_Reset devReset;

void *ResetTask();

void *ResetInit();

#endif