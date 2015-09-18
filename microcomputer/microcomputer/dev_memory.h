#ifndef _DEV_MEMORY

#define _DEV_MEMORY

#include "board.h"
#include "op_codes.h"

#define	MEM_NUM_PIN		28

#define	MEM_VCC          0
#define	MEM_GND          1
#define	MEM__CE1         2
#define	MEM__CE2         3
#define	MEM_Address_00   4
#define	MEM_Address_01   5
#define	MEM_Address_02   6
#define	MEM_Address_03   7
#define	MEM_Address_04   8
#define	MEM_Address_05   9
#define	MEM_Address_06  10
#define	MEM_Address_07  11
#define	MEM_Address_08  12
#define	MEM_Address_09  13
#define	MEM_Address_10  14
#define	MEM_Address_11  15
#define	MEM_Address_12  16
#define	MEM_Address_13  17
#define	MEM_Address_14  18
#define	MEM_Address_15  19
#define	MEM_Data_00     20
#define	MEM_Data_01     21
#define	MEM_Data_02     22
#define	MEM_Data_03     23
#define	MEM_Data_04     24
#define	MEM_Data_05     25
#define	MEM_Data_06     26
#define	MEM_Data_07     27

#define MEM_SIZE        8192

struct s_Memory {
	//	GATES
	p_gate	mem_gate[MEM_NUM_PIN];
	p_wire	mem_wire[MEM_NUM_PIN];
	p_glist	pGates;

	dt_8bit	memory[ MEM_SIZE ];

	//	Callback
	FN_VOID_VOID		self_connect;
	FN_VOID_VOID		task;
};

typedef struct s_Memory  t_Memory;

typedef struct s_Memory* p_Memory;

p_Memory devMemory;

void *MemorySelfConnect();

void *MemoryTask();

void *MemoryInit();

#endif