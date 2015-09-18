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

//-----------------------------

typedef unsigned char t_flag_bit;

#define FLAG_REG_C		0
#define FLAG_REG_N		1
#define FLAG_REG_PV		2
#define FLAG_REG_H		4
#define FLAG_REG_Z		6
#define FLAG_REG_S		7

//-----------------------------

typedef struct s_Register	t_Register;
typedef struct s_Register* 	p_Register;

struct s_Register {
	t_reg		reg[26];
	
	//	Main Register Set
	p_reg		A;
	p_reg		F;
	p_reg		B;
	p_reg		C;
	p_reg		D;
	p_reg		E;
	p_reg		H;
	p_reg		L;
	p_reg16		AF;
	p_reg16		BC;
	p_reg16		DE;
	p_reg16		HL;

	//	Alternate Register Set
	p_reg		_A;
	p_reg		_F;
	p_reg		_B;
	p_reg		_C;
	p_reg		_D;
	p_reg		_E;
	p_reg		_H;
	p_reg		_L;
	p_reg16		_AF;
	p_reg16		_BC;
	p_reg16		_DE;
	p_reg16		_HL;

	//	Register
	p_reg		I;
	p_reg		R;
	p_reg16		PC;
	p_reg16		SP;
	p_reg16		IX;
	p_reg16		IY;
};

struct s_MProc {

	//	DEVICE
	p_device	dev;

	//	GATES
	p_gate	mp_gate[MP_NUM_PIN];
	p_wire	mp_wire[MP_NUM_PIN];
	
	//	REGISTRI DEL MICROPROCESSORE
	p_Register	Reg;
	
	//	REGISTRI //	MP_MAIN_REG_SET, MP_ALT_REG_SET
	t_reg		reg_A[2];		//	ACCUMULATORE
	t_reg		reg_F[2];		//	FLAGS
	t_reg		reg_B[2];	
	t_reg		reg_C[2];
	t_reg		reg_D[2];
	t_reg		reg_E[2];
	t_reg		reg_H[2];
	t_reg		reg_L[2];
	t_reg		reg_I;			//	INTERRUPT PAGE ADDRESS REGISTER
	t_reg		reg_R;			//	MEMORY REFRESH REGISTER
	t_reg16		reg_PC;			//	PROGRAM COUNTER
	t_reg16		reg_SP;			//	STACK POINTER
	t_reg16		reg_IX;			//	INDEX REGISTER
	t_reg16		reg_IY;			//	INDEX REGISTER
	//	Puntatori a coppie di registri per l'indirizzamento registo-indiretto.
	p_regind	reg_HL[2];			
	p_regind	reg_BC[2];			
	p_regind	reg_DE[2];			
	p_regind	reg_AF[2];			
	
	dt_8bit		IFF1;			//	Interrupt Enable Flip Flop ( 1 e 2 )
	dt_8bit		IFF2;			//	Interrupt Enable Flip Flop ( 1 e 2 )

	dt_8bit     int_stat;			//	Interrupt status ( Mode0, ... )
	
//	unsigned char	t_cycle;
//	unsigned char	m_cycle;
	p_op_code		op;
//	dt_8bit			op_code;
//	dt_8bit		*pR;			//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
//	dt_8bit		*pR1;			//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
//	dt_16bit	pA;				//	Memorizzo un valore a 16 bit
//	FN_OP_CODE	f_op_code;			//	funzione che implementa l'operazione corrispondente all' op-code da eseguire
	
	dt_8bit		n_reset_down_clock;	//	Numero di impulsi di clock con reset basso
	
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