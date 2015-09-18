#include "dev_mproc.h"

//---------------------------------

static void * _set_addr_bus( dt_16bit Address ) {
 	gate_set_val( devMProc->mp_gate[ MP_Address_00 ], ( TSTBIT( Address,  0 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_01 ], ( TSTBIT( Address,  1 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_02 ], ( TSTBIT( Address,  2 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_03 ], ( TSTBIT( Address,  3 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_04 ], ( TSTBIT( Address,  4 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_05 ], ( TSTBIT( Address,  5 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_06 ], ( TSTBIT( Address,  6 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_07 ], ( TSTBIT( Address,  7 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_08 ], ( TSTBIT( Address,  8 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_09 ], ( TSTBIT( Address,  9 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_10 ], ( TSTBIT( Address, 10 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_11 ], ( TSTBIT( Address, 11 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_12 ], ( TSTBIT( Address, 12 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_13 ], ( TSTBIT( Address, 13 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_14 ], ( TSTBIT( Address, 14 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_15 ], ( TSTBIT( Address, 15 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );

	return NULL;
}

static dt_8bit _get_data_bus() {
	dt_8bit b	= 0;

	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_07 ] ) == STATO_VAL_MIN ) ? 0 : 0x80 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_06 ] ) == STATO_VAL_MIN ) ? 0 : 0x40 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_05 ] ) == STATO_VAL_MIN ) ? 0 : 0x20 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_04 ] ) == STATO_VAL_MIN ) ? 0 : 0x10 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_03 ] ) == STATO_VAL_MIN ) ? 0 : 0x08 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_02 ] ) == STATO_VAL_MIN ) ? 0 : 0x04 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_01 ] ) == STATO_VAL_MIN ) ? 0 : 0x02 );
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_00 ] ) == STATO_VAL_MIN ) ? 0 : 0x01 );

	return b;
}

static void * _set_data_bus( dt_8bit *pRStore ) {

	gate_set_val( devMProc->mp_gate[ MP_Data_00 ], ( TSTBIT( *pRStore,  0 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_01 ], ( TSTBIT( *pRStore,  1 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_02 ], ( TSTBIT( *pRStore,  2 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_03 ], ( TSTBIT( *pRStore,  3 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_04 ], ( TSTBIT( *pRStore,  4 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_05 ], ( TSTBIT( *pRStore,  5 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_06 ], ( TSTBIT( *pRStore,  6 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
	gate_set_val( devMProc->mp_gate[ MP_Data_07 ], ( TSTBIT( *pRStore,  7 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );

	return NULL;
}

static void * _refresh_address() {
 	gate_set_val( devMProc->mp_gate[ MP_Address_00 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_01 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_02 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_03 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_04 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_05 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_06 ], STATO_VAL_MAX );
 	gate_set_val( devMProc->mp_gate[ MP_Address_07 ], STATO_VAL_MAX );

	return NULL;
}

//----------------------------------------------------------------------------------------------

static void * _check_reset() {
	p_gate pReset	= devMProc->mp_gate[ MP__RESET ];
	p_gate pClock	= devMProc->mp_gate[ MP__CLOCK ];
	p_slist pSReset	= NULL;
	p_slist pSClock	= NULL;

	if ( pClock->Wire == NULL || pReset->Wire == NULL ) 
		return NULL;
		
	if ( pClock->Wire != NULL )
		pSClock = pClock->Wire->stato->att;
	if ( pReset->Wire != NULL )
		pSReset = pReset->Wire->stato->att;

	if ( pSReset != NULL ) {

		if ( TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) && TSTBIT( pSReset->flag , STATO_FLAG_LOW ) ) {
			devMProc->n_reset_down_clock++;
		}
		
		if ( devMProc->n_reset_down_clock == 3 ) {	//	Reset request

			devMProc->n_reset_down_clock = 0;

			devMProc->IFF1		= 0;
			devMProc->IFF2		= 0;

			*devMProc->Reg->PC	= 0;
			*devMProc->Reg->I	= 0;
			*devMProc->Reg->R	= 0;

			devMProc->int_stat	= INT_STATUS_M0;
			
			devMProc->Cycle->t	= T_CYCLE_START;
			devMProc->Cycle->m	= M_CYCLE_FETCH;

		}
		
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------

static void * _fetch( dt_8bit	*pRStore ) {	//	4 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->Op->code )
	
	switch ( devMProc->Cycle->t ) {
		
		case T_CYCLE_START:

			//	Magari non è il posto migliore per azzerare op_code e la funzione, ma qui è sicuramente prima della lettura dell' op code e della successiva decodifica
			_reset_op_code( devMProc->Op );

			break;
			
		case T_CYCLE_T1:	//	Fronte di salita di T1
			
			gate_set_val( devMProc->mp_gate[ MP__M1 ], 		STATO_VAL_MIN );
			_set_addr_bus( *devMProc->Reg->PC );

			break;
			
		case T_CYCLE_T1_2:
		
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MIN );
			
			gate_set_state( devMProc->mp_gate[ MP_Data_00 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_01 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_02 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_03 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_04 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_05 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_06 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_07 ], GATEMODE_INPUT );
			
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MIN );
			
			break;
			
		case T_CYCLE_T2:	//	Fronte di salita di T2
			
			//	WAIT SIGNAL
			//		Se la memoria ha attivato _WAIT rimango dentro T_CYCLE_T2
			if ( gate_get_val( devMProc->mp_gate[ MP__WAIT ] ) == STATO_VAL_MIN ) 
				devMProc->Cycle->t -= 1;
				
			break;
			
		case T_CYCLE_T2_2:
		
			break;
			
		case T_CYCLE_T3:	//	Fronte di salita di T3
			
			*pRStore = _get_data_bus();
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__M1 ], 		STATO_VAL_MAX );
			
			//	REFRESH DYNAMIC MEMORIES
			_refresh_address();
			gate_set_val( devMProc->mp_gate[ MP__RFSH ], 	STATO_VAL_MIN );
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MIN );
			//	DECODE FETCHED OP CODE
			//	EXECUTE FETCHED OP CODE
			break;
			
		case T_CYCLE_T3_2:
			
			//	REFRESH DYNAMIC MEMORIES
			//	DECODE FETCHED OP CODE
			//	EXECUTE FETCHED OP CODE
			break;
			
		case T_CYCLE_T4:	//	Fronte di salita di T4
			
			//	REFRESH DYNAMIC MEMORIES
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			//	DECODE FETCHED OP CODE
			//	EXECUTE FETCHED OP CODE
			break;
			
		case T_CYCLE_T4_2:
			
			//	REFRESH DYNAMIC MEMORIES
			gate_set_val( devMProc->mp_gate[ MP__RFSH ], 	STATO_VAL_MAX );
			//	DECODE FETCHED OP CODE
			//	EXECUTE FETCHED OP CODE
			
			(*devMProc->Reg->PC)++;
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= M_CYCLE_NEXT;
			
			break;
			
	}
	
	return NULL;
	
}

static void * _mem_read( dt_16bit Address, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->Op->code )
	
	switch ( devMProc->Cycle->t ) {
		
		case T_CYCLE_T1:	//	Fronte di salita di T1
		
			_set_addr_bus( Address );
			
			break;
			
		case T_CYCLE_T1_2:
		
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MIN );
			
			gate_set_state( devMProc->mp_gate[ MP_Data_00 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_01 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_02 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_03 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_04 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_05 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_06 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_07 ], GATEMODE_INPUT );
			
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MIN );
			
			break;
			
		case T_CYCLE_T2:	//	Fronte di salita di T2
			
			//	WAIT SIGNAL
			//		Se la memoria ha attivato _WAIT rimango dentro T_CYCLE_T2
			if ( gate_get_val( devMProc->mp_gate[ MP__WAIT ] ) == STATO_VAL_MIN ) 
				devMProc->Cycle->t -= 1;
				
			break;
			
		case T_CYCLE_T2_2:
		
			break;
			
		case T_CYCLE_T3:	//	Fronte di salita di T3
			
			*pRStore = _get_data_bus();
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			
			break;
			
		case T_CYCLE_T3_2:
			
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

static void * _mem_write( dt_16bit Address, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->Op->code )
	
	switch ( devMProc->Cycle->t ) {
		
		case T_CYCLE_T1:	//	Fronte di salita di T1
		
			_set_addr_bus( Address );
			
			break;
			
		case T_CYCLE_T1_2:
		
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MIN );
			
			gate_set_state( devMProc->mp_gate[ MP_Data_00 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_01 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_02 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_03 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_04 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_05 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_06 ], GATEMODE_OUTPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_07 ], GATEMODE_OUTPUT );
			
			_set_data_bus( pRStore );
			
			break;
			
		case T_CYCLE_T2:	//	Fronte di salita di T2

			//	WAIT SIGNAL
			//		Se la memoria ha attivato _WAIT rimango dentro T_CYCLE_T2
			if ( gate_get_val( devMProc->mp_gate[ MP__WAIT ] ) == STATO_VAL_MIN ) 
				devMProc->Cycle->t -= 1;
				
			break;
			
		case T_CYCLE_T2_2:
		
			gate_set_val( devMProc->mp_gate[ MP__WR ], 	STATO_VAL_MIN );

			break;
			
		case T_CYCLE_T3:	//	Fronte di salita di T3
			
			break;
			
		case T_CYCLE_T3_2:
			
			gate_set_state( devMProc->mp_gate[ MP_Data_00 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_01 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_02 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_03 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_04 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_05 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_06 ], GATEMODE_INPUT );
			gate_set_state( devMProc->mp_gate[ MP_Data_07 ], GATEMODE_INPUT );
			
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__WR ], 		STATO_VAL_MAX );
			
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

p_reg _get_reg( dt_8bit reg_op_code ) {
	switch ( reg_op_code ) {
		case 0b00000000:
			return devMProc->Reg->B;
			break;
		case 0b00000001:
			return devMProc->Reg->C;
			break;
		case 0b00000010:
			return devMProc->Reg->D;
			break;
		case 0b00000011:
			return devMProc->Reg->E;
			break;
		case 0b00000100:
			return devMProc->Reg->H;
			break;
		case 0b00000101:
			return devMProc->Reg->L;
			break;
		case 0b00000110:
			break;
		case 0b00000111:
			return devMProc->Reg->A;
			break;
	}
	
	return NULL;
}

p_reg16 _get_reg16_dd( dt_8bit reg_op_code ) {
	switch ( reg_op_code ) {
		case 0b00000000:
			return devMProc->Reg->BC;
			break;
		case 0b00000001:
			return devMProc->Reg->DE;
			break;
		case 0b00000010:
			return devMProc->Reg->HL;
			break;
		case 0b00000011:
			return devMProc->Reg->SP;
			break;
	}

	return NULL;
}

p_reg16 _get_reg16_qq( dt_8bit reg_op_code ) {
	switch ( reg_op_code ) {
		case 0b00000000:
			return devMProc->Reg->BC;
			break;
		case 0b00000001:
			return devMProc->Reg->DE;
			break;
		case 0b00000010:
			return devMProc->Reg->HL;
			break;
		case 0b00000011:
			return devMProc->Reg->AF;
			break;
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------

void * _cycle_change( t_mcycle m_att, t_mcycle m_next ) {
	if ( devMProc->Cycle->m == m_att ) {

		devMProc->Cycle->t	= T_CYCLE_START;
		devMProc->Cycle->m 	= m_next;

		return NULL;
	}
	return NULL;
}
void * _cycle_reg_copy( t_mcycle m_att, t_mcycle m_next, p_reg r_source, p_reg r_dest ) {

	if ( devMProc->Cycle->m == m_att ) {

		*r_dest 	= *r_source;

		devMProc->Cycle->t	= T_CYCLE_START;
		devMProc->Cycle->m 	= m_next;

		return NULL;
	}

	return NULL;
}
void * _cycle_reg16_copy( t_mcycle m_att, t_mcycle m_next, p_reg16 r_source, p_reg16 r_dest ) {

	if ( devMProc->Cycle->m == m_att ) {

		*r_dest 	= *r_source;

		devMProc->Cycle->t	= T_CYCLE_START;
		devMProc->Cycle->m 	= m_next;

		return NULL;
	}

	return NULL;
}
void * _cycle_reg16_set( t_mcycle m_att, t_mcycle m_next, p_reg16 r_dest, dt_16bit val ) {

	if ( devMProc->Cycle->m == m_att ) {

		*r_dest 	= val;

		devMProc->Cycle->t	= T_CYCLE_START;
		devMProc->Cycle->m 	= m_next;

		return NULL;
	}

	return NULL;
}
void * _cycle_pc_reg_memread( t_mcycle m_att, t_mcycle m_next, p_reg r_reg ) {
	if ( devMProc->Cycle->m == m_att ) {

		_mem_read( *devMProc->Reg->PC, r_reg );

		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			(*devMProc->Reg->PC)++;
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= m_next;
		}

		return NULL;
	}
	return NULL;
}
void * _cycle_get_reg( t_mcycle m_att, t_mcycle m_next, dt_8bit r_reg_mask, p_reg *r_reg ) {
	if ( devMProc->Cycle->m == m_att ) {

		*r_reg = _get_reg( r_reg_mask );

		devMProc->Cycle->t		= T_CYCLE_START;
		devMProc->Cycle->m 		= m_next;

		return NULL;
	}
	return NULL;
}
void * _cycle_set_reg( t_mcycle m_att, t_mcycle m_next, p_reg r_reg ) {
	if ( devMProc->Cycle->m == m_att ) {

		devMProc->Op->pR		= r_reg;

		devMProc->Cycle->t		= T_CYCLE_START;
		devMProc->Cycle->m 		= m_next;

		return NULL;
	}
	return NULL;
}
void * _cycle_addr_reg_memread( t_mcycle m_att, t_mcycle m_next, dt_16bit dt16bit, p_reg r_reg ) {
	if ( devMProc->Cycle->m == m_att ) {

		_mem_read( dt16bit, r_reg );

		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= m_next;
			return NULL;
		}

	}
	return NULL;
}
void * _cycle_addr_reg_memwrite( t_mcycle m_att, t_mcycle m_next, dt_16bit dt16bit, p_reg r_reg ) {
	if ( devMProc->Cycle->m == m_att ) {

		_mem_write( dt16bit, r_reg );

		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= m_next;
			return NULL;
		}

	}
	return NULL;
}


//----------------------------------------------------------------------------------------------

//	Source: Reg
//	Dest: 	Reg
void * _op_reg_reg( p_reg* r_source, p_reg* r_dest ) {

	_cycle_get_reg( M_CYCLE_M1, M_CYCLE_M1, OP_REG_BMASK( *devMProc->Op->Code ), 		r_source );
	_cycle_get_reg( M_CYCLE_M1, M_CYCLE_END, OP_SHIFT_3R_MASK( *devMProc->Op->Code ), 	r_dest );
	_cycle_reg_copy( M_CYCLE_END, M_CYCLE_END, *r_source, *r_dest );

	return NULL;
}
void * _op_reg16_reg16( p_reg16* r_source, p_reg16* r_dest ) {

	_cycle_reg16_copy( M_CYCLE_M1, M_CYCLE_END, *r_source, *r_dest );

	return NULL;
}
void * _op_REG16_REG16( p_reg16* r_source, p_reg16* r_dest ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_reg16_copy( M_CYCLE_M2, M_CYCLE_END, *r_source, *r_dest );

	return NULL;
}


//	Source: Immediate
//	Dest: 	Reg
void * _op_reg_imm( p_reg r_reg ) {

	_cycle_set_reg( M_CYCLE_M1, M_CYCLE_NEXT, r_reg );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_END, devMProc->Op->pR );

	return NULL;
}

//	Source: Reg
//	Dest: 	Indexed
void * _op_ind_reg( p_reg* r_reg, p_reg16 r_ind ) {
	//	r_reg viene valorizzato dal valore di oper_1

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_change( M_CYCLE_M2, M_CYCLE_NEXT );
	//	LD r, (IX+d)
	if ( ( *devMProc->Op->OperL & 0b11000111 )==0b01000110 ) {	// 01rrr110
		//	M_CYCLE_M3
		_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperH );
		//	M_CYCLE_M4
		_cycle_get_reg( M_CYCLE_M4, M_CYCLE_NEXT, OP_SHIFT_3R_MASK( *devMProc->Op->OperL ), r_reg );
		//	M_CYCLE_M5
		_cycle_addr_reg_memread( M_CYCLE_M5, M_CYCLE_END, (*r_ind + *devMProc->Op->OperH), *r_reg );
	}
	//	LD (IX+d), r
	if ( ( *devMProc->Op->OperL & 0b11111000 )==0b01110000 ) {	// 01110rrr
		//	M_CYCLE_M3
		_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperH );
		//	M_CYCLE_M4
		_cycle_get_reg( M_CYCLE_M4, M_CYCLE_NEXT, OP_REG_BMASK( *devMProc->Op->OperL ), r_reg );
		//	M_CYCLE_M5
		_cycle_addr_reg_memwrite( M_CYCLE_M5, M_CYCLE_END, (*r_ind + *devMProc->Op->OperH), *r_reg );
	}

	return NULL;

}

//	Source: Immediate
//	Dest: 	Indexed
void * _op_ind_imm( p_reg16 r_ind ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_change( M_CYCLE_M2, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperDL );
	_cycle_pc_reg_memread( M_CYCLE_M4, M_CYCLE_NEXT, devMProc->Op->OperNL );
	_cycle_addr_reg_memwrite( M_CYCLE_M5, M_CYCLE_END, (*r_ind + *devMProc->Op->OperDL), devMProc->Op->OperNL );

	return NULL;
}

//	Source: Reg Indirect
//	Dest: Reg
void * _op_reg_regind( p_reg r_dest, p_reg16 r_source ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_addr_reg_memread( M_CYCLE_M2, M_CYCLE_END, *r_source, r_dest );

	return NULL;
		
}

//	Source: Reg
//	Dest: Reg Indirect
void * _op_regind_reg( p_reg16 r_dest, p_reg r_source ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_addr_reg_memwrite( M_CYCLE_M2, M_CYCLE_END, *r_dest, r_source );

	return NULL;
}

//	Source: Immediate
//	Dest: Reg Indirect
void * _op_regind_imm( p_reg16 r_dest ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperL );
	_cycle_addr_reg_memwrite( M_CYCLE_M3, M_CYCLE_END, *r_dest, devMProc->Op->OperL );

	return NULL;
}

//	Source: Immediate Extended
//	Dest: Reg
void *  _op_reg_immext( p_reg16 r_dest ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_change( M_CYCLE_M2, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperNH );
	_cycle_pc_reg_memread( M_CYCLE_M4, M_CYCLE_END, devMProc->Op->OperNL );
	_cycle_reg16_copy( M_CYCLE_END, M_CYCLE_END, devMProc->Op->OperandsN, r_dest );

	return NULL;

}

//	Source: Extended
//	Dest: Reg
void *  _op_REG_ext( p_reg16 r_dest ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperNL );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperNH );
	_cycle_addr_reg_memread( M_CYCLE_M4, M_CYCLE_NEXT, (*devMProc->Op->OperandsN    ), devMProc->Op->OperDL );
	_cycle_addr_reg_memread( M_CYCLE_M5, M_CYCLE_END,  (*devMProc->Op->OperandsN + 1), devMProc->Op->OperDH );
	_cycle_reg16_copy( M_CYCLE_END, M_CYCLE_END, devMProc->Op->OperandsD, r_dest );

	return NULL;

}

//	Source: Extended
//	Dest: 	Reg (decodficato da parametro)
//		E' come _op_REG_ext ma con un ciclo macchina in più
void *  _op_reg_ext( p_reg16 r_dest ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_change( M_CYCLE_M2, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperNL );
	_cycle_pc_reg_memread( M_CYCLE_M4, M_CYCLE_NEXT, devMProc->Op->OperNH );
	_cycle_addr_reg_memread( M_CYCLE_M5, M_CYCLE_NEXT, (*devMProc->Op->OperandsN    ), devMProc->Op->OperDL );
	_cycle_addr_reg_memread( M_CYCLE_M6, M_CYCLE_END,  (*devMProc->Op->OperandsN + 1), devMProc->Op->OperDH );
	_cycle_reg16_copy( M_CYCLE_END, M_CYCLE_END, devMProc->Op->OperandsD, r_dest );

	return NULL;
}

//	Source: Reg
//	Dest: 	Extended
void *  _op_ext_REG( p_reg16 r_source ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperNL );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperNH );
	_cycle_addr_reg_memwrite( M_CYCLE_M4, M_CYCLE_NEXT, (*devMProc->Op->OperandsN    ), (p_reg)(r_source)+0 );
	_cycle_addr_reg_memwrite( M_CYCLE_M5, M_CYCLE_END,  (*devMProc->Op->OperandsN + 1), (p_reg)(r_source)+1 );

	return NULL;

}

//	Source: Reg (decodficato da parametro)
//	Dest: 	Extended
//		E' come _op_ext_REG ma con un ciclo macchina in più
void *  _op_ext_reg( p_reg16 r_source ) {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_change( M_CYCLE_M2, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperNL );
	_cycle_pc_reg_memread( M_CYCLE_M4, M_CYCLE_NEXT, devMProc->Op->OperNH );
	_cycle_addr_reg_memwrite( M_CYCLE_M5, M_CYCLE_NEXT, (*devMProc->Op->OperandsN    ), (p_reg)(r_source)+0 );
	_cycle_addr_reg_memwrite( M_CYCLE_M6, M_CYCLE_END,  (*devMProc->Op->OperandsN + 1), (p_reg)(r_source)+1 );

	return NULL;

}

//----------------------------------------------------------------------------------------------

//	8bit op codes

FN_OP_CODE _op_nop() {
	devMProc->Cycle->t	= T_CYCLE_START;
	devMProc->Cycle->m 	= M_CYCLE_END;
	return NULL;
}	
FN_OP_CODE _op_ld_r_r() {
	return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );
}
FN_OP_CODE _op_ld_r_n() {
	return _op_reg_imm( _get_reg( OP_SHIFT_3R_MASK( *devMProc->Op->Code ) ) );
}
FN_OP_CODE _op_ld_r_hl() {
	return _op_reg_regind( _get_reg( OP_SHIFT_3R_MASK( *devMProc->Op->Code ) ), devMProc->Reg->HL );
}
FN_OP_CODE _op_ld_hl_r() {
	return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );
}
FN_OP_CODE _op_ld_hl_n() {
	return _op_regind_imm( devMProc->Reg->HL );
}

FN_OP_CODE _op_ld_a_bc() {
	return _op_reg_regind( devMProc->Reg->A, devMProc->Reg->BC );
}
FN_OP_CODE _op_ld_a_de() {
	return _op_reg_regind( devMProc->Reg->A, devMProc->Reg->DE );
}
FN_OP_CODE _op_ld_bc_a() {
	return _op_regind_reg( devMProc->Reg->BC, devMProc->Reg->A );
}
FN_OP_CODE _op_ld_de_a() {
	return _op_regind_reg( devMProc->Reg->DE, devMProc->Reg->A );
}

FN_OP_CODE _op_ld_a_nn() {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperL );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperH );
	_cycle_addr_reg_memread( M_CYCLE_M4, M_CYCLE_END, *devMProc->Op->Operands, devMProc->Reg->A );

	return NULL;		
}
FN_OP_CODE _op_ld_nn_a() {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperL );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_NEXT, devMProc->Op->OperH );
	_cycle_addr_reg_memwrite( M_CYCLE_M4, M_CYCLE_END, *devMProc->Op->Operands, devMProc->Reg->A );

	return NULL;
		
}

//	16bit op codes

FN_OP_CODE _op_ld_dd_nn() {

	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperH );
	_cycle_pc_reg_memread( M_CYCLE_M3, M_CYCLE_M3_A, devMProc->Op->OperL );
	_cycle_reg16_set( M_CYCLE_M3_A, M_CYCLE_END, _get_reg16_dd( OP_REG_RR( *devMProc->Op->Code )), *devMProc->Op->Operands );

	return NULL;

}

FN_OP_CODE _op_ld_IX_nn() {
	return _op_reg_immext( devMProc->Reg->IX );
}

FN_OP_CODE _op_ld_IY_nn() {
	return _op_reg_immext( devMProc->Reg->IY );
}

FN_OP_CODE _op_ld_HL_NN() {
	return _op_REG_ext( devMProc->Reg->HL );
}

FN_OP_CODE _op_ld_dd_NN() {
	devMProc->Op->pRR		= _get_reg16_dd( OP_REG_RR( *devMProc->Op->OperL ) );
	return _op_reg_ext( devMProc->Op->pRR );
}

FN_OP_CODE _op_ld_IX_NN() {
	return _op_reg_ext( devMProc->Reg->IX );
}
FN_OP_CODE _op_ld_IY_NN() {
	return _op_reg_ext( devMProc->Reg->IY );
}

FN_OP_CODE _op_ld_NN_HL() {
	return _op_ext_REG( devMProc->Reg->HL );
}

FN_OP_CODE _op_ld_NN_dd() {
	devMProc->Op->pRR		= _get_reg16_dd( OP_REG_RR( *devMProc->Op->OperL ) );
	return _op_ext_reg( devMProc->Op->pRR );
}

FN_OP_CODE _op_ld_NN_IX() {
	return _op_ext_reg( devMProc->Reg->IX );
}
FN_OP_CODE _op_ld_NN_IY() {
	return _op_ext_reg( devMProc->Reg->IY );
}

FN_OP_CODE _op_ld_SP_HL() {
	return _op_reg16_reg16( &devMProc->Reg->HL, &devMProc->Reg->SP );
}
FN_OP_CODE _op_ld_SP_IX() {
	return _op_REG16_REG16( &devMProc->Reg->IX, &devMProc->Reg->SP );
}

//--------------------------------------------

FN_OP_CODE _op_DD() {
	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_M2_A, devMProc->Op->OperL );
	if ( devMProc->Cycle->m == M_CYCLE_M2_A ) {

		_cycle_change( M_CYCLE_M2_A, M_CYCLE_M2 );
		switch ( *devMProc->Op->OperL ) {
			//	LD SP, IX
			case	0xF9:
				_op_ld_SP_IX();
				break;
			default:
				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_NEXT;
		}
	}
	if ( devMProc->Cycle->m != M_CYCLE_M1 && devMProc->Cycle->m != M_CYCLE_M2 && devMProc->Cycle->m != M_CYCLE_NEXT && devMProc->Cycle->m != M_CYCLE_END ) {

		switch ( *devMProc->Op->OperL ) {
			//	LD r, (IX+d)
			case	0b01000110:	//	LD B, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01001110:	//	LD C, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01010110:	//	LD D, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01011110:	//	LD E, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01100110:	//	LD H, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01101110:	//	LD L, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01111110:	//	LD A, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			//	LD (IX+d), r
			case	0b01110000:	//	LD (IX+d), B
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110001:	//	LD (IX+d), C
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110010:	//	LD (IX+d), D
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110011:	//	LD (IX+d), E
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110100:	//	LD (IX+d), H
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110101:	//	LD (IX+d), L
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			case	0b01110111:	//	LD (IX+d), A
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IX );
				break;
			//	LD IX, nn
			case	0x21:		//	LD IX, nn
				_op_ld_IX_nn();
				break;
			//	LD (nn), IX
			case	0x22:		//	LD (nn), IX
				_op_ld_NN_IX();
				break;
			//	LD IX, (nn)
			case	0x2A:		//	LD IX, (nn)
				_op_ld_IX_NN();
				break;
			//	LD (IX+d), n
			case	0x36:		//	LD (IX+d), n
				_op_ind_imm( devMProc->Reg->IX );
				break;
		}

		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= M_CYCLE_NEXT;
		}

		return NULL;
	}

	return NULL;
}

FN_OP_CODE _op_ED() {
	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_M2_A, devMProc->Op->OperL );
	if ( devMProc->Cycle->m == M_CYCLE_M2_A ) {
		
		switch ( *devMProc->Op->OperL ) {
			case	0x47:	//	LD I,A
				*devMProc->Reg->I = *devMProc->Reg->A;

				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_END;
				return NULL;

				break;
			case	0x4F:	//	LD R, A
				*devMProc->Reg->R = *devMProc->Reg->A;

				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_END;
				return NULL;

				break;
			case	0x57:	//	LD A, I
				*devMProc->Reg->A = *devMProc->Reg->I;
				if ( *devMProc->Reg->I < 0 ) {
					_set_flag( devMProc->Reg, FLAG_REG_S );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_S );
				}
				if ( *devMProc->Reg->I == 0 ) {
					_set_flag( devMProc->Reg, FLAG_REG_Z );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_Z );
				}
				_reset_flag( devMProc->Reg, FLAG_REG_H );
				if ( devMProc->IFF2 == 0 ) {	// IFF2
					_reset_flag( devMProc->Reg, FLAG_REG_PV );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_PV );
				}
				_reset_flag( devMProc->Reg, FLAG_REG_N );

				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_END;
				return NULL;

				break;
			case	0x5F:	//	LD A, R
				*devMProc->Reg->A = *devMProc->Reg->R;
				if ( *devMProc->Reg->R < 0 ) {
					_set_flag( devMProc->Reg, FLAG_REG_S );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_S );
				}
				if ( *devMProc->Reg->R == 0 ) {
					_set_flag( devMProc->Reg, FLAG_REG_Z );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_Z );
				}
				_reset_flag( devMProc->Reg, FLAG_REG_H );
				if ( devMProc->IFF2 == 0 ) {	// IFF2
					_reset_flag( devMProc->Reg, FLAG_REG_PV );
				} else {
					_reset_flag( devMProc->Reg, FLAG_REG_PV );
				}
				_reset_flag( devMProc->Reg, FLAG_REG_N );

				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_END;
				return NULL;

				break;
			default:
				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_NEXT;
		}

	}
	if ( devMProc->Cycle->m != M_CYCLE_M1 && devMProc->Cycle->m != M_CYCLE_M2 && devMProc->Cycle->m != M_CYCLE_NEXT && devMProc->Cycle->m != M_CYCLE_END ) {

		switch ( *devMProc->Op->OperL ) {
			//	LD dd, (nn)
			case 0b01001011:
				_op_ld_dd_NN();
				break;
			case 0b01011011:
				_op_ld_dd_NN();
				break;
			case 0b01101011:
				_op_ld_dd_NN();
				break;
			case 0b01111011:
				_op_ld_dd_NN();
				break;
			//	LD (nn), dd
			case 0b01000011:
				_op_ld_NN_dd();
				break;
			case 0b01010011:
				_op_ld_NN_dd();
				break;
			case 0b01100011:
				_op_ld_NN_dd();
				break;
			case 0b01110011:
				_op_ld_NN_dd();
				break;
		}

		return NULL;
	}

	return NULL;
}

FN_OP_CODE _op_FD() {
	_cycle_change( M_CYCLE_M1, M_CYCLE_NEXT );
	_cycle_pc_reg_memread( M_CYCLE_M2, M_CYCLE_NEXT, devMProc->Op->OperL );
	if ( devMProc->Cycle->m == M_CYCLE_M2_A ) {

		_cycle_change( M_CYCLE_M2_A, M_CYCLE_M2 );
		switch ( *devMProc->Op->OperL ) {
			default:
				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m 		= M_CYCLE_NEXT;
		}

	}
	if ( devMProc->Cycle->m != M_CYCLE_M1 && devMProc->Cycle->m != M_CYCLE_M2 && devMProc->Cycle->m != M_CYCLE_NEXT && devMProc->Cycle->m != M_CYCLE_END ) {

		switch ( *devMProc->Op->OperL ) {
			//	LD r, (IX+d)
			case	0b01000110:	//	LD B, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01001110:	//	LD C, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01010110:	//	LD D, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01011110:	//	LD E, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01100110:	//	LD H, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01101110:	//	LD L, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01111110:	//	LD A, (IX+d)
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			//	LD (IX+d), r
			case	0b01110000:	//	LD (IX+d), B
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110001:	//	LD (IX+d), C
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110010:	//	LD (IX+d), D
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110011:	//	LD (IX+d), E
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110100:	//	LD (IX+d), H
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110101:	//	LD (IX+d), L
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			case	0b01110111:	//	LD (IX+d), A
				_op_ind_reg( &devMProc->Op->pR, devMProc->Reg->IY );
				break;
			//	LD IY, nn
			case	0x21:		//	LD IY, nn
				_op_ld_IY_nn();
				break;
			//	LD (nn), IY
			case	0x22:		//	LD (nn), IY
				_op_ld_NN_IY();
				break;
			//	LD IY, (nn)
			case	0x2A:		//	LD IY, (nn)
				_op_ld_IY_NN();
				break;
			//	LD (IY+d), n
			case	0x36:		//	LD (IY+d), n
				_op_ind_imm( devMProc->Reg->IY );
				break;
		}

		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			devMProc->Cycle->t		= T_CYCLE_START;
			devMProc->Cycle->m 		= M_CYCLE_NEXT;
		}

		return NULL;
	}

	return NULL;
}

//--------------------------------------------
/*
void * _op_load_group_ld() {
	
	switch ( *devMProc->Op->Code ) {
		
		//	Register - Register Indirect
		case	0x02:
			return _op_regind_reg( devMProc->Reg->BC, devMProc->Reg->A );			//	LD (BC), A
			break;
		case	0x12:
			return _op_regind_reg( devMProc->Reg->DE, devMProc->Reg->A );			//	LD (DE), A
			break;
			
		case	0x70:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), B
			break;
		case	0x71:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), C
			break;
		case	0x72:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), D
			break;
		case	0x73:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), E
			break;
		case	0x74:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), F
			break;
		case	0x75:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), L
			break;
		case	0x77:
			return _op_regind_reg( devMProc->Reg->HL, _get_reg( OP_REG_BMASK( *devMProc->Op->Code ) ) );	//	LD (HL), A
			break;

		//	Register Indirect - Register
		case	0x0A:
			return _op_reg_regind( devMProc->Reg->A, devMProc->Reg->BC );			//	LD A, (BC)
			break;
		case	0x1A:
			return _op_reg_regind( devMProc->Reg->A, devMProc->Reg->DE );			//	LD A, (DE)
			break;

		case	0x46:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD B, (HL)
			break;
		case	0x4E:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD C, (HL)
			break;
		case	0x56:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD D, (HL)
			break;
		case	0x5E:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD E, (HL)
			break;
		case	0x66:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD H, (HL)
			break;
		case	0x6E:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD L, (HL)
			break;
		case	0x7E:
			return _op_reg_regind( devMProc->Op->pR, devMProc->Reg->HL );								//	LD A, (HL)
			break;

		//	Ind Ext
		case	0x32:
			return _op_ld_nn_a();											//	LD (nn), A
			break;
		case	0x3A:
			return _op_ld_a_nn();											//	LD A, (nn)
			break;

		//	Register - Register
		case	0x40:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, B
			break;
		case	0x41:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, C
			break;
		case	0x42:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, D
			break;
		case	0x43:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, E
			break;
		case	0x44:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, F
			break;
		case	0x45:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, L
			break;
		case	0x47:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD B, A
			break;

		case	0x48:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, B
			break;
		case	0x49:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, C
			break;
		case	0x4A:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, D
			break;
		case	0x4B:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, E
			break;
		case	0x4C:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, F
			break;
		case	0x4D:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, L
			break;
		case	0x4F:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD C, A
			break;

		case	0x50:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, B
			break;
		case	0x51:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, C
			break;
		case	0x52:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, D
			break;
		case	0x53:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, E
			break;
		case	0x54:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, F
			break;
		case	0x55:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, L
			break;
		case	0x57:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD D, A
			break;

		case	0x58:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, B
			break;
		case	0x59:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, C
			break;
		case	0x5A:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, D
			break;
		case	0x5B:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, E
			break;
		case	0x5C:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, F
			break;
		case	0x5D:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, L
			break;
		case	0x5F:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD E, A
			break;

		case	0x60:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, B
			break;
		case	0x61:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, C
			break;
		case	0x62:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, D
			break;
		case	0x63:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, E
			break;
		case	0x64:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, F
			break;
		case	0x65:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, L
			break;
		case	0x67:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD H, A
			break;

		case	0x68:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, B
			break;
		case	0x69:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, C
			break;
		case	0x6A:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, D
			break;
		case	0x6B:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, E
			break;
		case	0x6C:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, F
			break;
		case	0x6D:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, L
			break;
		case	0x6F:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD L, A
			break;

		case	0x78:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, B
			break;
		case	0x79:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, C
			break;
		case	0x7A:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, D
			break;
		case	0x7B:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, E
			break;
		case	0x7C:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, F
			break;
		case	0x7D:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, L
			break;
		case	0x7F:
			return _op_reg_reg( &devMProc->Op->pR1, &devMProc->Op->pR );	//	LD A, A
			break;

		//	---------
		case	0x76:
			break;

		//	Indexed	/ Imm.
		case	0xDD:
			break;
		case	0xFD:
			break;

		//	Implied
		case	0xED:
			return _op_ED();
			break;

	}
	
	return NULL;
}
*/
static void * _decode() {
	
	//	Default
	devMProc->Op->f_op_code = (FN_OP_CODE) _op_nop;

	if ( ( ( *devMProc->Op->Code & OP_AM_NOP ) == OP_EM_NOP ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_nop;
	}
	
	//	01rrrRRR	->	LD r, r'
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_R_R ) == OP_EM_LD_R_R ) && OP_EXCLUDE_RES_R( *devMProc->Op->Code ) && OP_EXCLUDE_RES_R1( *devMProc->Op->Code ) ) {
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_r non può contenere questo codice per r o r1
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_r_r;
	}
	//	00rrr110	->	LD r,n
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_R_N ) == OP_EM_LD_R_N ) && OP_EXCLUDE_RES_R( *devMProc->Op->Code ) ) {
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_N non può contenere questo codice per r
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_r_n;
	}
	//	01rrr110	->	LD r, (HL)
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_R_HL ) == OP_EM_LD_R_HL ) && OP_EXCLUDE_RES_R( *devMProc->Op->Code ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_r_hl;
	}
	//	11011101	->	LD r, (IX+d) ; LD (IX+d), r
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_DD ) == OP_EM_LD_DD ) ) {
//		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_dd;
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_DD;
	}
	//	11111101	->	LD r, (IY+d) ;  LD (IY+d), r
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_FD ) == OP_EM_LD_FD ) ) {
//		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_fd;
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_FD;
	}
	//	01110rrr	->	LD (HL), r
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_HL_R ) == OP_EM_LD_HL_R ) && OP_EXCLUDE_RES_R1( *devMProc->Op->Code ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_hl_r;
	}
	//	LD (HL), n
	if ( ( *devMProc->Op->Code & OP_AM_LD_HL_N ) == OP_EM_LD_HL_N ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_hl_n;
	}

	//	00001010	->	LD A, (BC)
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_A_BC ) == OP_EM_LD_A_BC ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_a_bc;
	}
	//	00011010	->	LD A, (DE)
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_A_DE ) == OP_EM_LD_A_DE ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_a_de;
	}
	//	00000010	->	LD (BC), A
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_BC_A ) == OP_EM_LD_BC_A ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_bc_a;
	}
	//	00010010	->	LD (DE), A
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_DE_A ) == OP_EM_LD_DE_A ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_de_a;
	}

	//	0x3A = 00111010	->	LD A, (nn)
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_A_NN ) == OP_EM_LD_A_NN ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_a_nn;
	}
	//	0x32 = 00110010	->	LD (nn), A
	if ( ( ( *devMProc->Op->Code & OP_AM_LD_NN_A ) == OP_EM_LD_NN_A ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_nn_a;
	}
	
	//	0xED	-> LD A, I ; LD A, R ; LD I, A ; LD R, A ; LD dd, (nn)
	if ( ( *devMProc->Op->Code == 0xED ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ED;
	}

	//	LD dd, nn
	if ( ( ( *devMProc->Op->Code & 0b11001111 ) == 0b00000001 ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_dd_nn;
	}

	if ( ( ( *devMProc->Op->Code & 0xFF ) == 0x2A ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_HL_NN;
	}

	//	LD (nn), HL
	if ( ( ( *devMProc->Op->Code & 0xFF ) == 0x22 ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_NN_HL;
	}

	//	LD (nn), HL
	if ( ( ( *devMProc->Op->Code & 0xFF ) == 0xF9 ) ) {
		devMProc->Op->f_op_code = (FN_OP_CODE) _op_ld_SP_HL;
	}

	devMProc->Cycle->t		= T_CYCLE_T1;
	devMProc->Cycle->m		= M_CYCLE_NEXT;
	
	return NULL;
	
}

char _do_mcycle( unsigned char curr_cycle, unsigned char next_cyle ) {

	if ( devMProc->Cycle->m == curr_cycle ) {
		//	Esecuzione loopback impostata durante _decode()
		devMProc->Op->f_op_code();
		if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
			devMProc->Cycle->m = next_cyle;
			return 1;
		}
		if ( devMProc->Cycle->m != M_CYCLE_END )
			return 1;
	}
	
	return 0;
}

//----------------------------------------------------------------------------------------------

void *MProcTask() {

	p_gate pClock  	= devMProc->mp_gate[ MP__CLOCK ];
	p_slist pSClock	= NULL;

	if ( pClock->Wire != NULL )
		pSClock = pClock->Wire->stato->att;

	//MP__CLOCK
	if ( pSClock != NULL ) {

		//	Conteggio i mezzi cicli di clock sui fronti di salita e discesa del clock;
		if ( TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) ) {	//	1/2 T Cycle dispari
			devMProc->Cycle->t &= 11111110;
			devMProc->Cycle->t++;
		}
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) ) {	//	1/2 T Cycle pari
			devMProc->Cycle->t++;
		}
		
		//MP__RESET
		_check_reset();
		
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) || TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) ) {	//	1/2 T Cycle

			if ( devMProc->Cycle->m == M_CYCLE_FETCH ) {														//	Ci si arriva solo tramite RESET o tramite M_CYCLE_END
				
				_fetch( devMProc->Op->Code );
				
				if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
					devMProc->Cycle->m = M_CYCLE_DECODE;
				} else {
					return NULL;
				}
				
			}
			if ( devMProc->Cycle->m == M_CYCLE_DECODE ) {													//	Ci si arriva solo tramite M_CYCLE_FETCH
				
				_decode();
				
				if ( devMProc->Cycle->m == M_CYCLE_NEXT ) {
					devMProc->Cycle->m = M_CYCLE_M1;
				} else {
					return NULL;
				}
				
			}

			if ( _do_mcycle( M_CYCLE_M1, M_CYCLE_M2 ) )															//	Ci si arriva solo da DECODE
				return NULL;
			if ( _do_mcycle( M_CYCLE_M2, M_CYCLE_M3 ) )															//	Ci si arriva solo da M_CYCLE_M1
				return NULL;
			if ( _do_mcycle( M_CYCLE_M3, M_CYCLE_M4 ) )
				return NULL;
			if ( _do_mcycle( M_CYCLE_M4, M_CYCLE_M5 ) )
				return NULL;
			if ( _do_mcycle( M_CYCLE_M5, M_CYCLE_M6 ) )
				return NULL;
			if ( _do_mcycle( M_CYCLE_M6, M_CYCLE_M7 ) )
				return NULL;
			
			if ( devMProc->Cycle->m == M_CYCLE_END ) {														//	Ci si arriva solo tramite la fine di un' operazione op code
				devMProc->Cycle->t		= T_CYCLE_START;
				devMProc->Cycle->m		= M_CYCLE_FETCH;
				return NULL;
			}
			
			if ( devMProc->Cycle->m == M_CYCLE_NULL ) {
				return NULL;
			}
			
		}

	}

	return NULL;
}

void *MProcSelfConnect() {

	p_gate	pGate	= NULL;
	p_glist	pGList	= NULL;
	p_wire	pWire	= NULL;
	p_wlist	pWList	= NULL;

	for ( pGList = devMProc->dev->pGates; pGList != NULL; pGList = pGList->g_next ) {
		pGate = pGList->Gate;

		for ( pWList = p_all_wires; pGate->Wire == NULL && pWList != NULL; pWList = pWList->w_next ) {
			pWire = pWList->Wire;

			if ( strcmp( pGate->nome, pWire->nome ) == 0 ) {
				gate_connect( pGate, pWire );
			}
		}

	}

	return NULL;

}

void *MProcInit() {
	p_glist 	pGlist	= NULL;
	dt_16bit 	i		= 0;
	
	devMProc = malloc( sizeof(t_MProc) );

	//	----------------------------------------------------------------------------------------------------------
	//	Device
	devMProc->dev			= malloc( sizeof( t_device ) );
	devMProc->dev->nome		= "Z80 CPU";
	devMProc->dev->pGates	= NULL;
	
	//	----------------------------------------------------------------------------------------------------------
	//	Inizializzazione valori
	
	devMProc->n_reset_down_clock 		= 0;
	
	//	----------------------------------------------------------------------------------------------------------
	//		Registri
	devMProc->Reg						= malloc( sizeof( t_Register ) );
	_init_registry( devMProc->Reg );

	//	----------------------------------------------------------------------------------------------------------
	//		Cicli macchina
	devMProc->Cycle						= malloc( sizeof( t_cycle ) );
	devMProc->Cycle->t					= T_CYCLE_START;
	devMProc->Cycle->m					= M_CYCLE_FETCH;

	//	----------------------------------------------------------------------------------------------------------
	//		OpCode
	devMProc->Op						= malloc( sizeof( t_op_code ) );
	_init_op_code( devMProc->Op );

	//	----------------------------------------------------------------------------------------------------------
	//		GATES E WIRES

	//devMProc->mp_wire[ _CLOCK        ] = wire_new( "_CLOCK",	STATO_VAL_MAX );
	//devMProc->mp_wire[ VCC           ] = wire_new( "VCC",	    STATO_VAL_MAX );
	//devMProc->mp_wire[ GND           ] = wire_new( "GND",	    STATO_VAL_MIN );
	devMProc->mp_wire[ MP__M1        ] = wire_new( "_M1", 		STATO_VAL_MAX );
	devMProc->mp_wire[ MP__MREQ      ] = wire_new( "_MREQ", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__IORQ      ] = wire_new( "_IORQ", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__RD        ] = wire_new( "_RD", 		STATO_VAL_MAX );
	devMProc->mp_wire[ MP__WR        ] = wire_new( "_WR", 		STATO_VAL_MAX );
	devMProc->mp_wire[ MP__RFSH      ] = wire_new( "_RFSH", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__HALT      ] = wire_new( "_HALT", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__WAIT      ] = wire_new( "_WAIT", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__INT       ] = wire_new( "_INT", 		STATO_VAL_MAX );
	devMProc->mp_wire[ MP__NMI       ] = wire_new( "_NMI", 		STATO_VAL_MAX );
	//devMProc->mp_wire[ MP__RESET     ] = wire_new( "_RESET",	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__BUSRQ     ] = wire_new( "_BUSRQ",	STATO_VAL_MAX );
	devMProc->mp_wire[ MP__BUSACK    ] = wire_new( "_BUSACK", 	STATO_VAL_MAX );
	devMProc->mp_wire[ MP_Address_00 ] = wire_new( "A00",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_01 ] = wire_new( "A01",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_02 ] = wire_new( "A02",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_03 ] = wire_new( "A03",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_04 ] = wire_new( "A04",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_05 ] = wire_new( "A05",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_06 ] = wire_new( "A06",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_07 ] = wire_new( "A07",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_08 ] = wire_new( "A08",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_09 ] = wire_new( "A09",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_10 ] = wire_new( "A10",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_11 ] = wire_new( "A11",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_12 ] = wire_new( "A12",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_13 ] = wire_new( "A13",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_14 ] = wire_new( "A14",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Address_15 ] = wire_new( "A15",		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_00    ] = wire_new( "D0", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_01    ] = wire_new( "D1", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_02    ] = wire_new( "D2", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_03    ] = wire_new( "D3", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_04    ] = wire_new( "D4", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_05    ] = wire_new( "D5", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_06    ] = wire_new( "D6", 		STATO_VAL_MIN );
	devMProc->mp_wire[ MP_Data_07    ] = wire_new( "D7", 		STATO_VAL_MIN );

	devMProc->mp_gate[ MP__CLOCK     ] = gate_new( "_CLOCK", 	devMProc->dev, 	GATEMODE_INPUT,	  6, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP_VCC        ] = gate_new( "VCC", 		devMProc->dev, 	GATEMODE_INPUT,	 11, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP_GND        ] = gate_new( "GND", 		devMProc->dev, 	GATEMODE_INPUT,  29, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP__M1        ] = gate_new( "_M1", 		devMProc->dev, 	GATEMODE_OUTPUT, 17, devMProc->mp_wire[ MP__M1        ] );
	devMProc->mp_gate[ MP__MREQ      ] = gate_new( "_MREQ", 	devMProc->dev, 	GATEMODE_OUTPUT, 19, devMProc->mp_wire[ MP__MREQ      ] );
	devMProc->mp_gate[ MP__IORQ      ] = gate_new( "_IORQ", 	devMProc->dev, 	GATEMODE_OUTPUT, 20, devMProc->mp_wire[ MP__IORQ      ] );
	devMProc->mp_gate[ MP__RD        ] = gate_new( "_RD", 		devMProc->dev, 	GATEMODE_OUTPUT, 21, devMProc->mp_wire[ MP__RD        ] );
	devMProc->mp_gate[ MP__WR        ] = gate_new( "_WR", 		devMProc->dev, 	GATEMODE_OUTPUT, 22, devMProc->mp_wire[ MP__WR        ] );
	devMProc->mp_gate[ MP__RFSH      ] = gate_new( "_RFSH", 	devMProc->dev, 	GATEMODE_OUTPUT, 28, devMProc->mp_wire[ MP__RFSH      ] );
	devMProc->mp_gate[ MP__HALT      ] = gate_new( "_HALT", 	devMProc->dev, 	GATEMODE_OUTPUT, 18, devMProc->mp_wire[ MP__HALT      ] );
	devMProc->mp_gate[ MP__WAIT      ] = gate_new( "_WAIT", 	devMProc->dev, 	GATEMODE_INPUT,  24, devMProc->mp_wire[ MP__WAIT      ] );
	devMProc->mp_gate[ MP__INT       ] = gate_new( "_INT", 		devMProc->dev, 	GATEMODE_INPUT,  16, devMProc->mp_wire[ MP__INT       ] );
	devMProc->mp_gate[ MP__NMI       ] = gate_new( "_NMI", 		devMProc->dev, 	GATEMODE_INPUT,  17, devMProc->mp_wire[ MP__NMI       ] );
	devMProc->mp_gate[ MP__RESET     ] = gate_new( "_RESET", 	devMProc->dev, 	GATEMODE_INPUT,  26, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP__BUSRQ     ] = gate_new( "_BUSRQ", 	devMProc->dev, 	GATEMODE_INPUT,  25, devMProc->mp_wire[ MP__BUSRQ     ] );
	devMProc->mp_gate[ MP__BUSACK    ] = gate_new( "_BUSACK", 	devMProc->dev, 	GATEMODE_OUTPUT, 23, devMProc->mp_wire[ MP__BUSACK    ] );
	devMProc->mp_gate[ MP_Address_00 ] = gate_new( "A00", 		devMProc->dev, 	GATEMODE_OUTPUT, 30, devMProc->mp_wire[ MP_Address_00 ] );
	devMProc->mp_gate[ MP_Address_01 ] = gate_new( "A01", 		devMProc->dev, 	GATEMODE_OUTPUT, 31, devMProc->mp_wire[ MP_Address_01 ] );
	devMProc->mp_gate[ MP_Address_02 ] = gate_new( "A02", 		devMProc->dev, 	GATEMODE_OUTPUT, 32, devMProc->mp_wire[ MP_Address_02 ] );
	devMProc->mp_gate[ MP_Address_03 ] = gate_new( "A03", 		devMProc->dev, 	GATEMODE_OUTPUT, 33, devMProc->mp_wire[ MP_Address_03 ] );
	devMProc->mp_gate[ MP_Address_04 ] = gate_new( "A04", 		devMProc->dev, 	GATEMODE_OUTPUT, 34, devMProc->mp_wire[ MP_Address_04 ] );
	devMProc->mp_gate[ MP_Address_05 ] = gate_new( "A05", 		devMProc->dev, 	GATEMODE_OUTPUT, 35, devMProc->mp_wire[ MP_Address_05 ] );
	devMProc->mp_gate[ MP_Address_06 ] = gate_new( "A06", 		devMProc->dev, 	GATEMODE_OUTPUT, 36, devMProc->mp_wire[ MP_Address_06 ] );
	devMProc->mp_gate[ MP_Address_07 ] = gate_new( "A07", 		devMProc->dev, 	GATEMODE_OUTPUT, 37, devMProc->mp_wire[ MP_Address_07 ] );
	devMProc->mp_gate[ MP_Address_08 ] = gate_new( "A08", 		devMProc->dev, 	GATEMODE_OUTPUT, 38, devMProc->mp_wire[ MP_Address_08 ] );
	devMProc->mp_gate[ MP_Address_09 ] = gate_new( "A09", 		devMProc->dev, 	GATEMODE_OUTPUT, 39, devMProc->mp_wire[ MP_Address_09 ] );
	devMProc->mp_gate[ MP_Address_10 ] = gate_new( "A10", 		devMProc->dev, 	GATEMODE_OUTPUT, 40, devMProc->mp_wire[ MP_Address_10 ] );
	devMProc->mp_gate[ MP_Address_11 ] = gate_new( "A11", 		devMProc->dev, 	GATEMODE_OUTPUT,  1, devMProc->mp_wire[ MP_Address_11 ] );
	devMProc->mp_gate[ MP_Address_12 ] = gate_new( "A12", 		devMProc->dev, 	GATEMODE_OUTPUT,  2, devMProc->mp_wire[ MP_Address_12 ] );
	devMProc->mp_gate[ MP_Address_13 ] = gate_new( "A13", 		devMProc->dev, 	GATEMODE_OUTPUT,  3, devMProc->mp_wire[ MP_Address_13 ] );
	devMProc->mp_gate[ MP_Address_14 ] = gate_new( "A14", 		devMProc->dev, 	GATEMODE_OUTPUT,  4, devMProc->mp_wire[ MP_Address_14 ] );
	devMProc->mp_gate[ MP_Address_15 ] = gate_new( "A15", 		devMProc->dev, 	GATEMODE_OUTPUT,  5, devMProc->mp_wire[ MP_Address_15 ] );
	devMProc->mp_gate[ MP_Data_00    ] = gate_new( "D0", 		devMProc->dev, 	GATEMODE_INPUT,	 14, devMProc->mp_wire[ MP_Data_00    ] );
	devMProc->mp_gate[ MP_Data_01    ] = gate_new( "D1", 		devMProc->dev, 	GATEMODE_INPUT,	 15, devMProc->mp_wire[ MP_Data_01    ] );
	devMProc->mp_gate[ MP_Data_02    ] = gate_new( "D2", 		devMProc->dev, 	GATEMODE_INPUT,	 12, devMProc->mp_wire[ MP_Data_02    ] );
	devMProc->mp_gate[ MP_Data_03    ] = gate_new( "D3", 		devMProc->dev, 	GATEMODE_INPUT,	  8, devMProc->mp_wire[ MP_Data_03    ] );
	devMProc->mp_gate[ MP_Data_04    ] = gate_new( "D4", 		devMProc->dev, 	GATEMODE_INPUT,	  7, devMProc->mp_wire[ MP_Data_04    ] );
	devMProc->mp_gate[ MP_Data_05    ] = gate_new( "D5", 		devMProc->dev, 	GATEMODE_INPUT,	  9, devMProc->mp_wire[ MP_Data_05    ] );
	devMProc->mp_gate[ MP_Data_06    ] = gate_new( "D6", 		devMProc->dev, 	GATEMODE_INPUT,	 10, devMProc->mp_wire[ MP_Data_06    ] );
	devMProc->mp_gate[ MP_Data_07    ] = gate_new( "D7", 		devMProc->dev, 	GATEMODE_INPUT,	 13, devMProc->mp_wire[ MP_Data_07    ] );

	//	Compila la gatelist con l'array di gates
	for ( i=0; i<MP_NUM_PIN; i++) {
		if ( devMProc->dev->pGates == NULL ) {								// devMProc->dev->pGates
			glist_node_accoda( &devMProc->dev->pGates, devMProc->mp_gate[i] );
		} else {
			pGlist = devMProc->dev->pGates;
			while ( pGlist->g_next != NULL ) {							// Cerco l'ultimo nodo della lista
				pGlist = pGlist->g_next;
			}
			glist_node_accoda( &pGlist, devMProc->mp_gate[i] );
		}
	}

	//	Callback
	devMProc->self_connect	= (FN_VOID_VOID)MProcSelfConnect;
	devMProc->task 			= (FN_VOID_VOID)MProcTask;

	return NULL;
}
