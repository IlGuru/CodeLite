#ifndef _DEV_MPROC

#define _DEV_MPROC

#include "board.h"
#include "op_codes.h"

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

#define MP_MAIN_REG_SET	0
#define MP_ALTE_REG_SET	1

#define INT_STATUS_M0	0	//	Interrupt status mode 0

#define T_CYCLE_START	0
#define T_CYCLE_T1		1
#define T_CYCLE_T1_2	2
#define T_CYCLE_T2		3
#define T_CYCLE_T2_2	4
#define T_CYCLE_T3		5
#define T_CYCLE_T3_2	6
#define T_CYCLE_T4		7
#define T_CYCLE_T4_2	8
#define T_CYCLE_T5		9
#define T_CYCLE_T5_2	10
#define T_CYCLE_T6		11
#define T_CYCLE_T6_2	12
#define T_CYCLE_T7		13
#define T_CYCLE_T7_2	14

#define M_CYCLE_FETCH	0	//	Stesso ciclo macchina
#define M_CYCLE_DECODE	1	//	Stesso ciclo macchina
#define M_CYCLE_EXECUTE	2	//	Stesso ciclo macchina
#define M_CYCLE_M1		3	//	Stesso ciclo macchina
#define M_CYCLE_M2		4
#define M_CYCLE_M3		5
#define M_CYCLE_M4		6
#define M_CYCLE_M5		7
#define M_CYCLE_NEXT	253	//	Per indicare di passare al prossimo ciclo macchina
#define M_CYCLE_END		254	//	Per indicare la fine di un' operazione

#define M_CYCLE_NULL	254

typedef void (*FN_OP_CODE)(void);

struct s_MProc {

	//	GATES
	p_gate	mp_gate[MP_NUM_PIN];
	p_wire	mp_wire[MP_NUM_PIN];
	p_glist	pGates;

	//	REGISTRI //	MP_MAIN_REG_SET, MP_ALT_REG_SET
	dt_8bit		reg_A[2];		//	ACCUMULATORE
	dt_8bit		reg_F[2];		//	FLAGS
	dt_8bit		reg_B[2];	
	dt_8bit		reg_C[2];
	dt_8bit		reg_D[2];
	dt_8bit		reg_E[2];
	dt_8bit		reg_H[2];
	dt_8bit		reg_L[2];
	dt_8bit		reg_I;			//	INTERRUPT PAGE ADDRESS REGISTER
	dt_8bit		reg_R;			//	MEMORY REFRESH REGISTER
	dt_16bit	reg_IX;			//	INDEX REGISTER
	dt_16bit	reg_IY;			//	INDEX REGISTER
	dt_16bit	reg_SP;			//	STACK POINTER
	dt_16bit	reg_PC;			//	PROGRAM COUNTER

	dt_8bit		IFF[2];			//	Interrupt Enable Flip Flop ( 1 e 2 )
	
	dt_8bit		*pR;			//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	dt_8bit		*pR1;			//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	dt_16bit	pA;				//	Memorizzo un valore a 16 bit
	
	dt_8bit		t_cycle;
	dt_8bit     m_cycle;
	FN_OP_CODE	f_op_code;			//	funzione che implementa l'operazione corrispondente all' op-code da eseguire
	
	dt_8bit		n_reset_down_clock;	//	Numero di impulsi di clock con reset basso
	dt_8bit       int_stat;			//	Interrupt status ( Mode0, ... )
	
	//	Callback
	FN_VOID_VOID		self_connect;
	FN_VOID_VOID		task;
};

typedef struct s_MProc  t_MProc;

typedef struct s_MProc* p_MProc;

p_MProc devMProc;

void *MProcSelfConnect();

void *MProcTask();

void *MProcInit();

#endif