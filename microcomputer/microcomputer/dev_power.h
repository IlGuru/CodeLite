#ifndef _DEV_POWER

#define _DEV_POWER

#include "board.h"

#define	PW_NUM_PIN		2

#define	PW_GND       	0
#define	PW_VCC          1

struct s_Power {

	//	DEVICE
	p_device	dev;

	//	GATES
	p_gate	pw_gate[PW_NUM_PIN];
	p_wire	pw_wire[PW_NUM_PIN];
	p_glist	pGates;
	
	//	Callback
	FN_VOID_VOID	self_connect;
	FN_VOID_VOID	task;
	
};

typedef struct s_Power  t_Power;

typedef struct s_Power* p_Power;

p_Power devPower;

void *PowerSelfConnect();

void *PowerTask();

void *PowerInit();

#endif