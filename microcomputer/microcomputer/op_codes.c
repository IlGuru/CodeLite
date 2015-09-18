#include "op_codes.h"

void * _init_op_code( p_op_code Op ) {
	Op->Code		= (dt_8bit  *)(Op->opcode + 0);
	Op->OperL		= (dt_8bit  *)(Op->opcode + 1);
	Op->OperH		= (dt_8bit  *)(Op->opcode + 2);
	Op->OperDL		= (dt_8bit  *)(Op->opcode + 3);
	Op->OperDH		= (dt_8bit  *)(Op->opcode + 4);
	Op->OperNL		= (dt_8bit  *)(Op->opcode + 5);
	Op->OperNH		= (dt_8bit  *)(Op->opcode + 6);
//	Op->CodeOper	= (dt_16bit *)(Op->Code);
	Op->Operands	= (dt_16bit *)(Op->OperL);
	Op->OperandsD	= (dt_16bit *)(Op->OperDL);
	Op->OperandsN	= (dt_16bit *)(Op->OperNL);

	_reset_op_code( Op );

	return NULL;
}

void * _reset_op_code( p_op_code Op ) {
	*Op->Code		= 0;
	*Op->OperL		= 0;
	*Op->OperH		= 0;
	*Op->OperDL		= 0;
	*Op->OperDH		= 0;
	*Op->OperNL		= 0;
	*Op->OperNH		= 0;
	Op->f_op_code	= NULL;

	Op->pR			= NULL;
	Op->pR1			= NULL;
	Op->dt16bit		= 0;
	Op->pRR			= NULL;

	return NULL;
}

