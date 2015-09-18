#ifndef _REGISTRY

#define _REGISTRY

#include <stdlib.h>
#include "bit_oper.h"

//	Tipi per registri

typedef unsigned char 		t_reg;
typedef unsigned short int 	t_reg16;

typedef t_reg*				p_reg;
typedef t_reg16*			p_reg16;

//--------------------------------------

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

//-----------------------------

typedef unsigned char t_flag_bit;

#define FLAG_REG_C		0
#define FLAG_REG_N		1
#define FLAG_REG_PV		2
#define FLAG_REG_H		4
#define FLAG_REG_Z		6
#define FLAG_REG_S		7

//--------------------------------------

void * _init_registry( p_Register Reg );

void * _reset_registry( p_Register Reg );

void * _set_flag( p_Register Reg, t_flag_bit flag );

void * _reset_flag( p_Register Reg, t_flag_bit flag );

#endif