#include "registry.h"

void * _init_registry( p_Register Reg ) {
	Reg->F 		= (p_reg   )(Reg->reg +  0);
	Reg->A 		= (p_reg   )(Reg->reg +  1);
	Reg->C 		= (p_reg   )(Reg->reg +  2);
	Reg->B 		= (p_reg   )(Reg->reg +  3);
	Reg->E 		= (p_reg   )(Reg->reg +  4);
	Reg->D 		= (p_reg   )(Reg->reg +  5);
	Reg->L 		= (p_reg   )(Reg->reg +  6);
	Reg->H 		= (p_reg   )(Reg->reg +  7);
	Reg->_F 	= (p_reg   )(Reg->reg +  8);
	Reg->_A 	= (p_reg   )(Reg->reg +  9);
	Reg->_C 	= (p_reg   )(Reg->reg + 10);
	Reg->_B 	= (p_reg   )(Reg->reg + 11);
	Reg->_E 	= (p_reg   )(Reg->reg + 12);
	Reg->_D 	= (p_reg   )(Reg->reg + 13);
	Reg->_L 	= (p_reg   )(Reg->reg + 14);
	Reg->_H 	= (p_reg   )(Reg->reg + 15);
	Reg->I 		= (p_reg   )(Reg->reg + 16);
	Reg->R 		= (p_reg   )(Reg->reg + 17);
	Reg->PC 	= (p_reg16 )(Reg->reg + 18);
	Reg->SP 	= (p_reg16 )(Reg->reg + 20);
	Reg->IX 	= (p_reg16 )(Reg->reg + 22);
	Reg->IY 	= (p_reg16 )(Reg->reg + 24);

	Reg->AF 	= (p_reg16 )Reg->F;
	Reg->BC 	= (p_reg16 )Reg->C;
	Reg->DE 	= (p_reg16 )Reg->E;
	Reg->HL 	= (p_reg16 )Reg->L;
	Reg->_AF	= (p_reg16 )Reg->_F;
	Reg->_BC	= (p_reg16 )Reg->_C;
	Reg->_DE	= (p_reg16 )Reg->_E;
	Reg->_HL	= (p_reg16 )Reg->_L;

	_reset_registry( Reg );

	return NULL;
}

void * _reset_registry( p_Register Reg ) {
	*Reg->AF		= 0x00;
	*Reg->BC		= 0x00;
	*Reg->DE		= 0x00;
	*Reg->HL		= 0x00;
	*Reg->_AF		= 0x00;
	*Reg->_BC		= 0x00;
	*Reg->_DE		= 0x00;
	*Reg->_HL		= 0x00;
	*Reg->I 		= 0x00;
	*Reg->R 		= 0x00;
	*Reg->PC		= 0x0000;
	*Reg->SP		= 0x1FFF;
	*Reg->IX		= 0x0000;
	*Reg->IY		= 0x0000;

	return NULL;
}

void * _set_flag( p_Register Reg, t_flag_bit flag ) {
	SETBIT( *Reg->F, flag );
	return NULL;
}

void * _reset_flag( p_Register Reg, t_flag_bit flag ) {
	CLRBIT( *Reg->F, flag );
	return NULL;
}
