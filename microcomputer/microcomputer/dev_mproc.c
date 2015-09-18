#include "dev_mproc.h"

//---------------------------------

static void * _set_addr_bus( dt_16bit *pAddress ) {
 	gate_set_val( devMProc->mp_gate[ MP_Address_00 ], ( TSTBIT( *pAddress,  0 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_01 ], ( TSTBIT( *pAddress,  1 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_02 ], ( TSTBIT( *pAddress,  2 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_03 ], ( TSTBIT( *pAddress,  3 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_04 ], ( TSTBIT( *pAddress,  4 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_05 ], ( TSTBIT( *pAddress,  5 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_06 ], ( TSTBIT( *pAddress,  6 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_07 ], ( TSTBIT( *pAddress,  7 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_08 ], ( TSTBIT( *pAddress,  8 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_09 ], ( TSTBIT( *pAddress,  9 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_10 ], ( TSTBIT( *pAddress, 10 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_11 ], ( TSTBIT( *pAddress, 11 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_12 ], ( TSTBIT( *pAddress, 12 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_13 ], ( TSTBIT( *pAddress, 13 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_14 ], ( TSTBIT( *pAddress, 14 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );
 	gate_set_val( devMProc->mp_gate[ MP_Address_15 ], ( TSTBIT( *pAddress, 15 ) ? STATO_VAL_MAX : STATO_VAL_MIN ) );

	return NULL;
}

static dt_8bit _get_data_bus() {
	dt_8bit b	= 0;
	
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_07 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_06 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_05 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_04 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_03 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_02 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_01 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMProc->mp_gate[ MP_Data_00 ] ) == STATO_VAL_MIN ) ? 0 : 1 );

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

static void * _set_flag( t_flag_bit flag ) {
	SETBIT( devMProc->reg_F[ MP_MAIN_REG_SET ], flag );
	return NULL;
}
static void * _reset_flag( t_flag_bit flag ) {
	CLRBIT( devMProc->reg_F[ MP_MAIN_REG_SET ], flag );
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
			devMProc->reg_PC	= 0;
			devMProc->reg_I		= 0;
			devMProc->reg_R		= 0;
			devMProc->int_stat	= INT_STATUS_M0;
			
			devMProc->op->t_cycle	= T_CYCLE_START;
			devMProc->op->m_cycle	= M_CYCLE_FETCH;

		}
		
	}

	return NULL;
}

//----------------------------------------------------------------------------------------------

static void * _reset_op_code( p_op_code op ) {
	devMProc->op->code		= 0;
	devMProc->op->oper_1	= 0;
	devMProc->op->oper_2	= 0;
	devMProc->op->pR		= NULL;
	devMProc->op->pR1		= NULL;
	devMProc->op->pA		= 0;	
	devMProc->op->f_op_code	= NULL;	

	return NULL;
}

static void * _fetch( dt_8bit	*pRStore ) {	//	4 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->op->code ) 
	
	switch ( devMProc->op->t_cycle ) {
		
		case T_CYCLE_START:

			//	Magari non è il posto migliore per azzerare op_code e la funzione, ma qui è sicuramente prima della lettura dell' op code e della successiva decodifica
			_reset_op_code( devMProc->op );

			break;
			
		case T_CYCLE_T1:	//	Fronte di salita di T1
			
			gate_set_val( devMProc->mp_gate[ MP__M1 ], 		STATO_VAL_MIN );
			_set_addr_bus( &devMProc->reg_PC );
			
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
				devMProc->op->t_cycle -= 1;
				
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
			
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
			
			break;
			
	}
	
	return NULL;
	
}

static void * _mem_read( dt_16bit *pAddress, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->op->code ) 
	
	switch ( devMProc->op->t_cycle ) {
		
		case T_CYCLE_T1:	//	Fronte di salita di T1
		
			_set_addr_bus( pAddress );
			
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
				devMProc->op->t_cycle -= 1;
				
			break;
			
		case T_CYCLE_T2_2:
		
			break;
			
		case T_CYCLE_T3:	//	Fronte di salita di T3
			
			*pRStore = _get_data_bus();
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			
			break;
			
		case T_CYCLE_T3_2:
			
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

static void * _mem_write( dt_16bit *pAddress, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->op->code ) 
	
	switch ( devMProc->op->t_cycle ) {
		
		case T_CYCLE_T1:	//	Fronte di salita di T1
		
			_set_addr_bus( pAddress );
			
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
				devMProc->op->t_cycle -= 1;
				
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
			
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

dt_8bit* _get_reg( dt_8bit reg_op_code ) {
	switch ( reg_op_code ) {
		case 0b00000000:
			return &devMProc->reg_B[ MP_MAIN_REG_SET ];
			break;
		case 0b00000001:
			return &devMProc->reg_C[ MP_MAIN_REG_SET ];
			break;
		case 0b00000010:
			return &devMProc->reg_D[ MP_MAIN_REG_SET ];
			break;
		case 0b00000011:
			return &devMProc->reg_E[ MP_MAIN_REG_SET ];
			break;
		case 0b00000100:
			return &devMProc->reg_H[ MP_MAIN_REG_SET ];
			break;
		case 0b00000101:
			return &devMProc->reg_L[ MP_MAIN_REG_SET ];
			break;
		case 0b00000110:
			break;
		case 0b00000111:
			return &devMProc->reg_A[ MP_MAIN_REG_SET ];
			break;
	}
	
	return NULL;
}

//----------------------------------------------------------------------------------------------

//	Source: Reg
//	Dest: 	Reg
void * _op_reg_reg( p_reg* r_source, p_reg* r_dest ) {
	
	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {

		*r_source	= _get_reg( OP_REG_BMASK( devMProc->op->code ) );
		*r_dest 	= _get_reg( OP_SHIFT_3R_MASK( devMProc->op->code ) );
		**r_dest 	= **r_source;

		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_END;
		return NULL;
	}
	
	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}

//	Source: Reg
//	Dest: 	Indexed
void * _op_reg_ind( p_reg* r_reg, p_reg16 r_ind ) {	
	//	r_reg viene valorizzato dal valore di oper_1
	
	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		
		//	FINE DEL CICLO DI FETCH
		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M3 ) {
		
		//	LD r, (IX+d)
		if ( (devMProc->op->oper_1 & 0b11000111)==0b01000110 ) {	// 01rrr110
			_mem_read( &devMProc->reg_PC, &devMProc->op->oper_2 );
		}
		//	LD (IX+d), r
		if ( (devMProc->op->oper_1 & 0b11111000)==0b01110000 ) {	// 01110rrr
			_mem_read( &devMProc->reg_PC, &devMProc->op->oper_2 );
		}
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M4 ) {
		
		//	LD r, (IX+d)
		if ( (devMProc->op->oper_1 & 0b11000111)==0b01000110 ) {	// 01rrr110
			*r_reg = _get_reg( OP_SHIFT_3R_MASK( devMProc->op->oper_1 ) );

			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
			return NULL;
		}
		//	LD (IX+d), r
		if (  (devMProc->op->oper_1 & 0b11111000)==0b01110000 ) {	// 01110rrr
			*r_reg = _get_reg( devMProc->op->oper_1 & 0b00000111 );

			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
			return NULL;
		}
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M5 ) {
		
		//	LD r, (IX+d)
		if ( (devMProc->op->oper_1 & 0b11000111)==0b01000110 ) {	// 01rrr110
			
			devMProc->op->pA = *r_ind + devMProc->op->oper_2;	//	TO_DO Complemento a 2
			_mem_read( &devMProc->op->pA, *r_reg );
			
			if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
				devMProc->op->t_cycle		= T_CYCLE_START;
				devMProc->op->m_cycle 		= M_CYCLE_END;
				return NULL;
			}
			
		}
		//	LD (IX+d), r
		if ( (devMProc->op->oper_1 & 0b11111000)==0b01110000 ) {	// 01110rrr
			
			devMProc->op->pA = *r_ind + devMProc->op->oper_2;	//	TO_DO Complemento a 2
			_mem_write( &devMProc->op->pA, *r_reg );
			
			if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
				devMProc->op->t_cycle		= T_CYCLE_START;
				devMProc->op->m_cycle 		= M_CYCLE_END;
				return NULL;
			}
			
		}

		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}

//	Source: Reg Indexed	
//	Dest: Reg
void * _op_reg_regind( p_reg r_dest, p_regind r_source ) {
	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		devMProc->op->pR	= r_dest;
		
		devMProc->op->pA	|= *r_source->l;
		devMProc->op->pA	|= *r_source->h << 8;
		
		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->op->pA, devMProc->op->pR );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}
//	Source: Reg	
//	Dest: Reg Indexed
void * _op_regind_reg( p_regind r_dest, p_reg r_source ) {

	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		devMProc->op->pR	= r_source;
		
		devMProc->op->pA	|= *r_dest->l;
		devMProc->op->pA	|= *r_dest->h << 8;
		
		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_write( &devMProc->op->pA, devMProc->op->pR );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
}

//----------------------------------------------------------------------------------------------

FN_OP_CODE _op_nop() {
	devMProc->op->t_cycle	= T_CYCLE_START;
	devMProc->op->m_cycle 	= M_CYCLE_END;
	return NULL;
}	
FN_OP_CODE _op_ld_r_r() {
	return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );
}
FN_OP_CODE _op_ld_r_n() {

	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		devMProc->op->pR	= _get_reg( OP_SHIFT_3R_MASK( devMProc->op->code ) );
		
		devMProc->op->t_cycle		= T_CYCLE_START;
		devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, devMProc->op->pR );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}
FN_OP_CODE _op_ld_r_hl() {
	return _op_reg_regind( _get_reg( OP_SHIFT_3R_MASK( devMProc->op->code ) ), devMProc->reg_HL[MP_MAIN_REG_SET] );
}
FN_OP_CODE _op_ld_dd() {
	return _op_reg_ind( &devMProc->op->pR, &devMProc->reg_IX );
}
FN_OP_CODE _op_ld_fd() {
	return _op_reg_ind( &devMProc->op->pR, &devMProc->reg_IY );
}
FN_OP_CODE _op_ld_hl_r() {
	return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );
}
FN_OP_CODE _op_ld_hl_n() {

	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		
		devMProc->op->pA	= 0;
		devMProc->op->pA	|= devMProc->reg_H[0];
		devMProc->op->pA	<<= 8;
		devMProc->op->pA	|= devMProc->reg_L[0];
		
		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	

	if ( devMProc->op->m_cycle == M_CYCLE_M3 ) {
		
		_mem_write( &devMProc->op->pA, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}

FN_OP_CODE _op_ld_a_bc() {
	return _op_reg_regind( &devMProc->reg_A[ MP_MAIN_REG_SET ], devMProc->reg_BC[MP_MAIN_REG_SET] );
}
FN_OP_CODE _op_ld_a_de() {
	return _op_reg_regind( &devMProc->reg_A[ MP_MAIN_REG_SET ], devMProc->reg_DE[MP_MAIN_REG_SET] );
}
FN_OP_CODE _op_ld_bc_a() {
	return _op_regind_reg( devMProc->reg_BC[MP_MAIN_REG_SET], &devMProc->reg_A[ MP_MAIN_REG_SET ] );
}
FN_OP_CODE _op_ld_de_a() {
	return _op_regind_reg( devMProc->reg_DE[MP_MAIN_REG_SET], &devMProc->reg_A[ MP_MAIN_REG_SET ] );
}

FN_OP_CODE _op_ld_a_nn() {

	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		devMProc->op->pR		= &devMProc->reg_A[ MP_MAIN_REG_SET ];
		
		devMProc->op->t_cycle			= T_CYCLE_START;
		devMProc->op->m_cycle 			= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M3 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_2 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M4 ) {
		
		devMProc->op->pA	|= devMProc->op->oper_1;
		devMProc->op->pA	|= devMProc->op->oper_2 << 8;

		_mem_read( &devMProc->op->pA, devMProc->op->pR );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}
FN_OP_CODE _op_ld_nn_a() {

	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		devMProc->op->pR		= &devMProc->reg_A[ MP_MAIN_REG_SET ];
		
		devMProc->op->t_cycle			= T_CYCLE_START;
		devMProc->op->m_cycle 			= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M3 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_2 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	
	if ( devMProc->op->m_cycle == M_CYCLE_M4 ) {
		
		devMProc->op->pA	|= devMProc->op->oper_1;
		devMProc->op->pA	|= devMProc->op->oper_2 << 8;

		_mem_write( &devMProc->op->pA, devMProc->op->pR );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
		
}

FN_OP_CODE _op_ED() {
	if ( devMProc->op->m_cycle == M_CYCLE_EXECUTE || devMProc->op->m_cycle == M_CYCLE_M1 ) {
		
		//	FINE DEL CICLO DI FETCH
		devMProc->op->t_cycle	= T_CYCLE_START;
		devMProc->op->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->op->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, &devMProc->op->oper_1 );
		
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			
			switch ( devMProc->op->oper_1 ) {
				case	0x47:	//	LD I,A
					devMProc->reg_I = devMProc->reg_A[ MP_MAIN_REG_SET ];
					break;
				case	0x4F:	//	LD R, A
					devMProc->reg_R = devMProc->reg_A[ MP_MAIN_REG_SET ];
					break;
				case	0x57:	//	LD A, I
					devMProc->reg_A[ MP_MAIN_REG_SET ] = devMProc->reg_I;
					if ( devMProc->reg_I < 0 ) {
						_set_flag( FLAG_REG_S );
					} else {
						_reset_flag( FLAG_REG_S );
					}
					if ( devMProc->reg_I == 0 ) {
						_set_flag( FLAG_REG_Z );
					} else {
						_reset_flag( FLAG_REG_Z );
					}
					_reset_flag( FLAG_REG_H );
					if ( devMProc->IFF2 == 0 ) {	// IFF2
						_reset_flag( FLAG_REG_PV );
					} else {
						_reset_flag( FLAG_REG_PV );
					}
					_reset_flag( FLAG_REG_N );
					break;
				case	0x5F:	//	LD A, R
					devMProc->reg_A[ MP_MAIN_REG_SET ] = devMProc->reg_R;
					if ( devMProc->reg_R < 0 ) {
						_set_flag( FLAG_REG_S );
					} else {
						_reset_flag( FLAG_REG_S );
					}
					if ( devMProc->reg_R == 0 ) {
						_set_flag( FLAG_REG_Z );
					} else {
						_reset_flag( FLAG_REG_Z );
					}
					_reset_flag( FLAG_REG_H );
					if ( devMProc->IFF2 == 0 ) {	// IFF2
						_reset_flag( FLAG_REG_PV );
					} else {
						_reset_flag( FLAG_REG_PV );
					}
					_reset_flag( FLAG_REG_N );
					break;
			}
		
			devMProc->reg_PC++;
			devMProc->op->t_cycle		= T_CYCLE_START;
			devMProc->op->m_cycle 		= M_CYCLE_NEXT;
		}

		return NULL;
	}	

	devMProc->op->t_cycle		= T_CYCLE_START;
	devMProc->op->m_cycle 		= M_CYCLE_END;
	return NULL;
}

//--------------------------------------------
void * _op_load_group_ld() {
	
	switch ( devMProc->op->code ) {
		
		//	Register - Register Indirect
		case	0x02:
			return _op_regind_reg( devMProc->reg_BC[MP_MAIN_REG_SET], &devMProc->reg_A[ MP_MAIN_REG_SET ] );			//	LD (BC), A
			break;
		case	0x12:
			return _op_regind_reg( devMProc->reg_DE[MP_MAIN_REG_SET], &devMProc->reg_A[ MP_MAIN_REG_SET ] );			//	LD (DE), A
			break;
			
		case	0x70:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), B
			break;
		case	0x71:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), C
			break;
		case	0x72:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), D
			break;
		case	0x73:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), E
			break;
		case	0x74:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), F
			break;
		case	0x75:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), L
			break;
		case	0x77:
			return _op_regind_reg( devMProc->reg_HL[MP_MAIN_REG_SET], _get_reg( OP_REG_BMASK( devMProc->op->code ) ) );	//	LD (HL), A
			break;

		//	Register Indirect - Register
		case	0x0A:
			return _op_reg_regind( &devMProc->reg_A[ MP_MAIN_REG_SET ], devMProc->reg_BC[MP_MAIN_REG_SET] );			//	LD A, (BC)
			break;
		case	0x1A:
			return _op_reg_regind( &devMProc->reg_A[ MP_MAIN_REG_SET ], devMProc->reg_DE[MP_MAIN_REG_SET] );			//	LD A, (DE)
			break;

		case	0x46:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD B, (HL)
			break;
		case	0x4E:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD C, (HL)
			break;
		case	0x56:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD D, (HL)
			break;
		case	0x5E:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD E, (HL)
			break;
		case	0x66:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD H, (HL)
			break;
		case	0x6E:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD L, (HL)
			break;
		case	0x7E:
			return _op_reg_regind( devMProc->op->pR, devMProc->reg_HL[MP_MAIN_REG_SET] );								//	LD A, (HL)
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
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, B
			break;
		case	0x41:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, C
			break;
		case	0x42:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, D
			break;
		case	0x43:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, E
			break;
		case	0x44:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, F
			break;
		case	0x45:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, L
			break;
		case	0x47:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD B, A
			break;

		case	0x48:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, B
			break;
		case	0x49:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, C
			break;
		case	0x4A:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, D
			break;
		case	0x4B:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, E
			break;
		case	0x4C:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, F
			break;
		case	0x4D:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, L
			break;
		case	0x4F:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD C, A
			break;

		case	0x50:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, B
			break;
		case	0x51:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, C
			break;
		case	0x52:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, D
			break;
		case	0x53:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, E
			break;
		case	0x54:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, F
			break;
		case	0x55:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, L
			break;
		case	0x57:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD D, A
			break;

		case	0x58:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, B
			break;
		case	0x59:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, C
			break;
		case	0x5A:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, D
			break;
		case	0x5B:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, E
			break;
		case	0x5C:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, F
			break;
		case	0x5D:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, L
			break;
		case	0x5F:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD E, A
			break;

		case	0x60:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, B
			break;
		case	0x61:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, C
			break;
		case	0x62:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, D
			break;
		case	0x63:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, E
			break;
		case	0x64:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, F
			break;
		case	0x65:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, L
			break;
		case	0x67:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD H, A
			break;

		case	0x68:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, B
			break;
		case	0x69:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, C
			break;
		case	0x6A:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, D
			break;
		case	0x6B:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, E
			break;
		case	0x6C:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, F
			break;
		case	0x6D:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, L
			break;
		case	0x6F:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD L, A
			break;

		case	0x78:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, B
			break;
		case	0x79:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, C
			break;
		case	0x7A:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, D
			break;
		case	0x7B:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, E
			break;
		case	0x7C:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, F
			break;
		case	0x7D:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, L
			break;
		case	0x7F:
			return _op_reg_reg( &devMProc->op->pR1, &devMProc->op->pR );	//	LD A, A
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

static void * _decode() {
	
	//	Default
	devMProc->op->f_op_code = (FN_OP_CODE) _op_nop;

	if ( ( ( devMProc->op->code & OP_AM_NOP ) == OP_EM_NOP ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_nop;
	}
	
	//	01rrrRRR	->	LD r, r'
	if ( ( ( devMProc->op->code & OP_AM_LD_R_R ) == OP_EM_LD_R_R ) && OP_EXCLUDE_RES_R( devMProc->op->code ) && OP_EXCLUDE_RES_R1( devMProc->op->code ) ) {
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_r non può contenere questo codice per r o r1
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_r_r;
	}
	//	00rrr110	->	LD r,n
	if ( ( ( devMProc->op->code & OP_AM_LD_R_N ) == OP_EM_LD_R_N ) && OP_EXCLUDE_RES_R( devMProc->op->code ) ) {
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_N non può contenere questo codice per r
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_r_n;
	}
	//	01rrr110	->	LD r, (HL)
	if ( ( ( devMProc->op->code & OP_AM_LD_R_HL ) == OP_EM_LD_R_HL ) && OP_EXCLUDE_RES_R( devMProc->op->code ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_r_hl;
	}
	//	11011101	->	LD r, (IX+d) ; LD (IX+d), r
	if ( ( ( devMProc->op->code & OP_AM_LD_DD ) == OP_EM_LD_DD ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_dd;
	}
	//	11111101	->	LD r, (IY+d) ;  LD (IY+d), r
	if ( ( ( devMProc->op->code & OP_AM_LD_FD ) == OP_EM_LD_FD ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_fd;
	}
	//	01110rrr	->	LD (HL), r
	if ( ( ( devMProc->op->code & OP_AM_LD_HL_R ) == OP_EM_LD_HL_R ) && OP_EXCLUDE_RES_R1( devMProc->op->code ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_hl_r;
	}
	//	LD (HL), n
	if ( ( devMProc->op->code & OP_AM_LD_HL_N ) == OP_EM_LD_HL_N ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_hl_n;
	}

	//	00001010	->	LD A, (BC)
	if ( ( ( devMProc->op->code & OP_AM_LD_A_BC ) == OP_EM_LD_A_BC ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_a_bc;
	}
	//	00011010	->	LD A, (DE)
	if ( ( ( devMProc->op->code & OP_AM_LD_A_DE ) == OP_EM_LD_A_DE ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_a_de;
	}
	//	00000010	->	LD (BC), A
	if ( ( ( devMProc->op->code & OP_AM_LD_BC_A ) == OP_EM_LD_BC_A ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_bc_a;
	}
	//	00010010	->	LD (DE), A
	if ( ( ( devMProc->op->code & OP_AM_LD_DE_A ) == OP_EM_LD_DE_A ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_de_a;
	}

	//	00111010	->	LD A, (nn)
	if ( ( ( devMProc->op->code & OP_AM_LD_A_NN ) == OP_EM_LD_A_NN ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_a_nn;
	}
	//	00110010	->	LD (nn), A
	if ( ( ( devMProc->op->code & OP_AM_LD_NN_A ) == OP_EM_LD_NN_A ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ld_nn_a;
	}
	
	//	0xED	-> LD A, I ; LD A, R ; LD I, A ; LD R, A
	if ( ( devMProc->op->code == 0xED ) ) {
		devMProc->op->f_op_code = (FN_OP_CODE) _op_ED;
	}
	
	devMProc->op->t_cycle		= T_CYCLE_T1;
	devMProc->op->m_cycle		= M_CYCLE_NEXT;
	
	return NULL;
	
}

char _do_mcycle( unsigned char curr_cycle, unsigned char next_cyle ) {

	if ( devMProc->op->m_cycle == curr_cycle ) {
		//	Esecuzione loopback impostata durante _decode()
		devMProc->op->f_op_code();
		if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
			devMProc->op->m_cycle = next_cyle;
			return 1;
		}
		if ( devMProc->op->m_cycle != M_CYCLE_END )
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
			devMProc->op->t_cycle &= 11111110;
			devMProc->op->t_cycle++;
		}
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) ) {	//	1/2 T Cycle pari
			devMProc->op->t_cycle++;
		}
		
		//MP__RESET
		_check_reset();
		
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) || TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) ) {	//	1/2 T Cycle

			if ( devMProc->op->m_cycle == M_CYCLE_FETCH ) {														//	Ci si arriva solo tramite RESET o tramite M_CYCLE_END
				
				_fetch( &devMProc->op->code );
				
				if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
					devMProc->op->m_cycle = M_CYCLE_DECODE;
				} else {
					return NULL;
				}
				
			}
			if ( devMProc->op->m_cycle == M_CYCLE_DECODE ) {													//	Ci si arriva solo tramite M_CYCLE_FETCH
				
				_decode();
				
				if ( devMProc->op->m_cycle == M_CYCLE_NEXT ) {
					devMProc->op->m_cycle = M_CYCLE_EXECUTE;
				} else {
					return NULL;
				}
				
			}
			if ( _do_mcycle( M_CYCLE_EXECUTE, M_CYCLE_M2 ) )													//	Ci si arriva solo da DECODE
				return NULL;
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
			
			if ( devMProc->op->m_cycle == M_CYCLE_END ) {														//	Ci si arriva solo tramite la fine di un' operazione op code
				devMProc->op->t_cycle		= T_CYCLE_START;
				devMProc->op->m_cycle		= M_CYCLE_FETCH;
				return NULL;
			}
			
			if ( devMProc->op->m_cycle == M_CYCLE_NULL ) {
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

	//	Device
	devMProc->dev			= malloc( sizeof( t_device ) );
	devMProc->dev->nome		= "Z80 CPU";
	devMProc->dev->pGates	= NULL;
	
	//	Inizializzazione valori
	
	devMProc->n_reset_down_clock 		= 0;
	
	//		OpCode
	devMProc->op						= malloc( sizeof( t_op_code ) );
	_reset_op_code( devMProc->op );
	devMProc->op->t_cycle				= T_CYCLE_START;
	devMProc->op->m_cycle				= M_CYCLE_FETCH;
	
	//		Registri
	devMProc->Reg	= malloc( sizeof( t_Register ) );
	
	devMProc->Reg->F 	= (p_reg   )(devMProc->Reg->reg +  0);
	devMProc->Reg->A 	= (p_reg   )(devMProc->Reg->reg +  1);
	devMProc->Reg->C 	= (p_reg   )(devMProc->Reg->reg +  2);
	devMProc->Reg->B 	= (p_reg   )(devMProc->Reg->reg +  3);
	devMProc->Reg->E 	= (p_reg   )(devMProc->Reg->reg +  4);
	devMProc->Reg->D 	= (p_reg   )(devMProc->Reg->reg +  5);
	devMProc->Reg->L 	= (p_reg   )(devMProc->Reg->reg +  6);
	devMProc->Reg->H 	= (p_reg   )(devMProc->Reg->reg +  7);
	devMProc->Reg->_F 	= (p_reg   )(devMProc->Reg->reg +  8);
	devMProc->Reg->_A 	= (p_reg   )(devMProc->Reg->reg +  9);
	devMProc->Reg->_C 	= (p_reg   )(devMProc->Reg->reg + 10);
	devMProc->Reg->_B 	= (p_reg   )(devMProc->Reg->reg + 11);
	devMProc->Reg->_E 	= (p_reg   )(devMProc->Reg->reg + 12);
	devMProc->Reg->_D 	= (p_reg   )(devMProc->Reg->reg + 13);
	devMProc->Reg->_L 	= (p_reg   )(devMProc->Reg->reg + 14);
	devMProc->Reg->_H 	= (p_reg   )(devMProc->Reg->reg + 15);
	devMProc->Reg->I 	= (p_reg   )(devMProc->Reg->reg + 16);
	devMProc->Reg->R 	= (p_reg   )(devMProc->Reg->reg + 17);
	devMProc->Reg->PC 	= (p_reg16 )(devMProc->Reg->reg + 18);
	devMProc->Reg->SP 	= (p_reg16 )(devMProc->Reg->reg + 20);
	devMProc->Reg->IX 	= (p_reg16 )(devMProc->Reg->reg + 22);
	devMProc->Reg->IY 	= (p_reg16 )(devMProc->Reg->reg + 24);

	devMProc->Reg->AF 	= (p_reg16 )devMProc->Reg->F;
	devMProc->Reg->BC 	= (p_reg16 )devMProc->Reg->C;
	devMProc->Reg->DE 	= (p_reg16 )devMProc->Reg->E;
	devMProc->Reg->HL 	= (p_reg16 )devMProc->Reg->L;
	devMProc->Reg->_AF	= (p_reg16 )devMProc->Reg->_F;
	devMProc->Reg->_BC	= (p_reg16 )devMProc->Reg->_C;
	devMProc->Reg->_DE	= (p_reg16 )devMProc->Reg->_E;
	devMProc->Reg->_HL	= (p_reg16 )devMProc->Reg->_L;

	*devMProc->Reg->AF		= 0x00;
	*devMProc->Reg->BC		= 0x00;
	*devMProc->Reg->DE		= 0x00;
	*devMProc->Reg->HL		= 0x00;
	*devMProc->Reg->_AF		= 0x00;
	*devMProc->Reg->_BC		= 0x00;
	*devMProc->Reg->_DE		= 0x00;
	*devMProc->Reg->_HL		= 0x00;
	*devMProc->Reg->I 		= 0x00;
	*devMProc->Reg->R 		= 0x00;
	*devMProc->Reg->PC		= 0x0000;
	*devMProc->Reg->SP		= 0x1FFF;
	*devMProc->Reg->IX		= 0x0000;
	*devMProc->Reg->IY		= 0x0000;

	*devMProc->Reg->A = 0x01;
	*devMProc->Reg->F = 0x02;
	*devMProc->Reg->AF= 0x0304;
	
	devMProc->reg_A[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_A[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_F[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_F[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_B[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_B[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_C[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_C[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_D[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_D[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_E[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_E[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_H[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_H[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_L[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_L[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_I                    = 0;
	devMProc->reg_R                    = 0;
	devMProc->reg_IX                   = 0;
	devMProc->reg_IY                   = 0;
	devMProc->reg_SP                   = 0;
	devMProc->reg_PC                   = 0;
	
	//	Puntatori a coppie di registri per l'indirizzamento registo-indiretto.
	devMProc->reg_HL[MP_MAIN_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_HL[MP_ALTE_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_BC[MP_MAIN_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_BC[MP_ALTE_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_DE[MP_MAIN_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_DE[MP_ALTE_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_AF[MP_MAIN_REG_SET] 		= malloc( sizeof( t_regind ) );
	devMProc->reg_AF[MP_ALTE_REG_SET] 		= malloc( sizeof( t_regind ) );

	devMProc->reg_HL[MP_MAIN_REG_SET]->h	= &devMProc->reg_H[ MP_MAIN_REG_SET ];
	devMProc->reg_HL[MP_MAIN_REG_SET]->l	= &devMProc->reg_L[ MP_MAIN_REG_SET ];
	devMProc->reg_HL[MP_ALTE_REG_SET]->h	= &devMProc->reg_H[ MP_ALTE_REG_SET ];
	devMProc->reg_HL[MP_ALTE_REG_SET]->l	= &devMProc->reg_L[ MP_ALTE_REG_SET ];

	devMProc->reg_BC[MP_MAIN_REG_SET]->h	= &devMProc->reg_B[ MP_MAIN_REG_SET ];
	devMProc->reg_BC[MP_MAIN_REG_SET]->l	= &devMProc->reg_C[ MP_MAIN_REG_SET ];
	devMProc->reg_BC[MP_ALTE_REG_SET]->h	= &devMProc->reg_B[ MP_ALTE_REG_SET ];
	devMProc->reg_BC[MP_ALTE_REG_SET]->l	= &devMProc->reg_C[ MP_ALTE_REG_SET ];

	devMProc->reg_DE[MP_MAIN_REG_SET]->h	= &devMProc->reg_D[ MP_MAIN_REG_SET ];
	devMProc->reg_DE[MP_MAIN_REG_SET]->l	= &devMProc->reg_E[ MP_MAIN_REG_SET ];
	devMProc->reg_DE[MP_ALTE_REG_SET]->h	= &devMProc->reg_D[ MP_ALTE_REG_SET ];
	devMProc->reg_DE[MP_ALTE_REG_SET]->l	= &devMProc->reg_E[ MP_ALTE_REG_SET ];

	devMProc->reg_AF[MP_MAIN_REG_SET]->h	= &devMProc->reg_A[ MP_MAIN_REG_SET ];
	devMProc->reg_AF[MP_MAIN_REG_SET]->l	= &devMProc->reg_F[ MP_MAIN_REG_SET ];
	devMProc->reg_AF[MP_ALTE_REG_SET]->h	= &devMProc->reg_A[ MP_ALTE_REG_SET ];
	devMProc->reg_AF[MP_ALTE_REG_SET]->l	= &devMProc->reg_F[ MP_ALTE_REG_SET ];

	//	GATES E WIRES

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
