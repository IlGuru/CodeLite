#ifndef _DEV_MPROC

#define _DEV_MPROC

#include "board.h"

#define	MP_NUM_PIN		40

#define	MP__CLOCK       0
#define	MP_VCC          1
#define	MP_GND          2
#define	MP__M1          3
#define	MP__MREQ        4
#define	MP__IORQ        5
#define	MP__RD          6
#define	MP__WR          7
#define	MP__RFSH        8
#define	MP__HALT        9
#define MP__WAIT       10
#define MP__INT        11
#define MP__NMI        12
#define MP__RESET      13
#define	MP__BUSRQ      14
#define MP__BUSACK     15
#define	MP_Address_00  16
#define	MP_Address_01  17
#define	MP_Address_02  18
#define	MP_Address_03  19
#define	MP_Address_04  20
#define	MP_Address_05  21
#define	MP_Address_06  22
#define	MP_Address_07  23
#define	MP_Address_08  24
#define	MP_Address_09  25
#define	MP_Address_10  26
#define	MP_Address_11  27
#define	MP_Address_12  28
#define	MP_Address_13  29
#define	MP_Address_14  30
#define	MP_Address_15  31
#define	MP_Data_00     32
#define	MP_Data_01     33
#define	MP_Data_02     34
#define	MP_Data_03     35
#define	MP_Data_04     36
#define	MP_Data_05     37
#define	MP_Data_06     38
#define	MP_Data_07     39

struct s_MProc {

	p_gate	mp_gate[MP_NUM_PIN];
	p_wire	mp_wire[MP_NUM_PIN];
	p_glist	pGates;
	
	//	Callback
	FN_VOID_VOID	task;
};

typedef struct s_MProc  t_MProc;

typedef struct s_MProc* p_MProc;

p_MProc devMProc;

void *MProcTask();

void *MProcInit();

#endif