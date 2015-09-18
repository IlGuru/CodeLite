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

			devMProc->IFF[0]	= 0;
			devMProc->IFF[1]	= 0;
			devMProc->reg_PC	= 0;
			devMProc->reg_I		= 0;
			devMProc->reg_R		= 0;
			devMProc->int_stat	= INT_STATUS_M0;
			
			devMProc->t_cycle	= T_CYCLE_START;
			devMProc->m_cycle	= M_CYCLE_FETCH;

		}
		
	}

	return NULL;
}

static void * _fetch( dt_8bit	*pRStore ) {	//	4 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->reg_I ) 
	
	switch ( devMProc->t_cycle ) {
		
		case T_CYCLE_T1:	//	Fronte di salita di T1
		
			devMProc->f_op_code	= NULL;	//	Magari non è il posto migliore per azzerare la funzione, ma qui è sicuramente prima della lettura dell' op code e della successiva decodifica

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
				devMProc->t_cycle -= 1;
				
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
			devMProc->t_cycle		= T_CYCLE_START;
			devMProc->m_cycle 		= M_CYCLE_NEXT;
			
			break;
			
	}
	
	return NULL;
	
}

static void * _mem_read( dt_16bit *pAddress, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->reg_I ) 
	
	switch ( devMProc->t_cycle ) {
		
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
				devMProc->t_cycle -= 1;
				
			break;
			
		case T_CYCLE_T2_2:
		
			break;
			
		case T_CYCLE_T3:	//	Fronte di salita di T3
			
			*pRStore = _get_data_bus();
			gate_set_val( devMProc->mp_gate[ MP__RD ], 		STATO_VAL_MAX );
			gate_set_val( devMProc->mp_gate[ MP__MREQ ], 	STATO_VAL_MAX );
			
			break;
			
		case T_CYCLE_T3_2:
			
			devMProc->t_cycle		= T_CYCLE_START;
			devMProc->m_cycle 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

static void * _mem_write( dt_16bit *pAddress, dt_8bit* pRStore ) {	//	3 T CYCLE

	//	*pRStore indirizzo di memoria dove inserire il valore letto durante il fetch ( es &devMProc->reg_I ) 
	
	switch ( devMProc->t_cycle ) {
		
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
				devMProc->t_cycle -= 1;
				
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
			
			devMProc->t_cycle		= T_CYCLE_START;
			devMProc->m_cycle 		= M_CYCLE_NEXT;

			break;
			
	}
	
	return NULL;
	
}

FN_OP_CODE _op_ld_r_r() {

	dt_8bit	r	= 0;
	
	if ( devMProc->m_cycle == M_CYCLE_EXECUTE || devMProc->m_cycle == M_CYCLE_M1 ) {
		r = devMProc->reg_I & 0b00000111;
		switch ( r ) {
			case 0b00000000:
				devMProc->pR1 = &devMProc->reg_B[0];
				break;
			case 0b00000001:
				devMProc->pR1 = &devMProc->reg_C[0];
				break;
			case 0b00000010:
				devMProc->pR1 = &devMProc->reg_D[0];
				break;
			case 0b00000011:
				devMProc->pR1 = &devMProc->reg_E[0];
				break;
			case 0b00000100:
				devMProc->pR1 = &devMProc->reg_H[0];
				break;
			case 0b00000101:
				devMProc->pR1 = &devMProc->reg_L[0];
				break;
			case 0b00000110:
				break;
			case 0b00000111:
				devMProc->pR1 = &devMProc->reg_A[0];
				break;
		}
		
		r = ( devMProc->reg_I & 0b00111000 ) >> 3;
		switch ( r ) {
			case 0b00000000:
				devMProc->pR = &devMProc->reg_B[0];
				break;
			case 0b00000001:
				devMProc->pR = &devMProc->reg_C[0];
				break;
			case 0b00000010:
				devMProc->pR = &devMProc->reg_D[0];
				break;
			case 0b00000011:
				devMProc->pR = &devMProc->reg_E[0];
				break;
			case 0b00000100:
				devMProc->pR = &devMProc->reg_H[0];
				break;
			case 0b00000101:
				devMProc->pR = &devMProc->reg_L[0];
				break;
			case 0b00000110:
				break;
			case 0b00000111:
				devMProc->pR = &devMProc->reg_A[0];
				break;
		}

		*devMProc->pR 		= *devMProc->pR1;

		devMProc->t_cycle	= T_CYCLE_START;
		devMProc->m_cycle 	= M_CYCLE_END;

		return NULL;
	}
	
	return NULL;
		
}
FN_OP_CODE _op_ld_r_n() {

	dt_8bit	r	= 0;
	
	if ( devMProc->m_cycle == M_CYCLE_EXECUTE || devMProc->m_cycle == M_CYCLE_M1 ) {
		r = ( devMProc->reg_I & 0b00111000 ) >> 3;
		switch ( r ) {
			case 0b00000000:
				devMProc->pR = &devMProc->reg_B[0];
				break;
			case 0b00000001:
				devMProc->pR = &devMProc->reg_C[0];
				break;
			case 0b00000010:
				devMProc->pR = &devMProc->reg_D[0];
				break;
			case 0b00000011:
				devMProc->pR = &devMProc->reg_E[0];
				break;
			case 0b00000100:
				devMProc->pR = &devMProc->reg_H[0];
				break;
			case 0b00000101:
				devMProc->pR = &devMProc->reg_L[0];
				break;
			case 0b00000110:
				break;
			case 0b00000111:
				devMProc->pR = &devMProc->reg_A[0];
				break;
		}
		
		devMProc->t_cycle		= T_CYCLE_START;
		devMProc->m_cycle 		= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->reg_PC, devMProc->pR );
		
		if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->t_cycle		= T_CYCLE_START;
			devMProc->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	return NULL;
		
}
FN_OP_CODE _op_ld_r_hl() {

	dt_8bit		r = 0;
	
	if ( devMProc->m_cycle == M_CYCLE_EXECUTE || devMProc->m_cycle == M_CYCLE_M1 ) {
		r = ( devMProc->reg_I & 0b00111000 ) >> 3;
		switch ( r ) {
			case 0b00000000:
				devMProc->pR = &devMProc->reg_B[0];
				break;
			case 0b00000001:
				devMProc->pR = &devMProc->reg_C[0];
				break;
			case 0b00000010:
				devMProc->pR = &devMProc->reg_D[0];
				break;
			case 0b00000011:
				devMProc->pR = &devMProc->reg_E[0];
				break;
			case 0b00000100:
				devMProc->pR = &devMProc->reg_H[0];
				break;
			case 0b00000101:
				devMProc->pR = &devMProc->reg_L[0];
				break;
			case 0b00000110:
				break;
			case 0b00000111:
				devMProc->pR = &devMProc->reg_A[0];
				break;
		}
		
		devMProc->pA		= 0;
		devMProc->pA		|= devMProc->reg_H[0];
		devMProc->pA		<<= 8;
		devMProc->pA		|= devMProc->reg_L[0];
		
		devMProc->t_cycle	= T_CYCLE_START;
		devMProc->m_cycle 	= M_CYCLE_NEXT;
		
		return NULL;
	}
	if ( devMProc->m_cycle == M_CYCLE_M2 ) {
		
		_mem_read( &devMProc->pA, devMProc->pR );
		
		if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
			devMProc->reg_PC++;
			devMProc->t_cycle		= T_CYCLE_START;
			devMProc->m_cycle 		= M_CYCLE_END;
		}

		return NULL;
	}	

	return NULL;
		
}

static void * _decode() {
	
	
	if ( ( ( devMProc->reg_I & OP_AM_LD_R_R ) == OP_EM_LD_R_R ) && OP_EXCLUDE_RES_R( devMProc->reg_I ) && OP_EXCLUDE_RES_R1( devMProc->reg_I ) ) {
		//	01rrrRRR
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_r non può contenere questo codice per r o r1
		devMProc->f_op_code = (FN_OP_CODE) _op_ld_r_r;
	}
	if ( ( ( devMProc->reg_I & OP_AM_LD_R_N ) == OP_EM_LD_R_N ) && OP_EXCLUDE_RES_R( devMProc->reg_I ) ) {
		//	00rrr110
		//	Non esiste un registro con opdoce 110 quindi l'op code di ld_r_N non può contenere questo codice per r
		devMProc->f_op_code = (FN_OP_CODE) _op_ld_r_n;
	}
	if ( ( ( devMProc->reg_I & OP_AM_LD_R_HL ) == OP_EM_LD_R_HL ) && OP_EXCLUDE_RES_R( devMProc->reg_I ) ) {
		//	01rrr110
		devMProc->f_op_code = (FN_OP_CODE) _op_ld_r_hl;
	}
	
	devMProc->t_cycle		= T_CYCLE_T1;
	devMProc->m_cycle		= M_CYCLE_NEXT;
	
	return NULL;
	
}

void *MProcTask() {

	p_gate pClock  	= devMProc->mp_gate[ MP__CLOCK ];
	p_slist pSClock	= NULL;

	if ( pClock->Wire != NULL )
		pSClock = pClock->Wire->stato->att;

	//MP__CLOCK
	if ( pSClock != NULL ) {

		//	Conteggio i mezzi cicli di clock sui fronti di salita e discesa del clock;
		if ( TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) ) {	//	1/2 T Cycle dispari
			devMProc->t_cycle &= 11111110;
			devMProc->t_cycle++;
		}
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) ) {	//	1/2 T Cycle pari
			devMProc->t_cycle++;
		}
		
		//MP__RESET
		_check_reset();
		
		if ( TSTBIT( pSClock->flag , STATO_FLAG_FALL ) || TSTBIT( pSClock->flag , STATO_FLAG_RAISE ) ) {	//	1/2 T Cycle

			if ( devMProc->m_cycle == M_CYCLE_FETCH ) {														//	Ci si arriva solo tramite RESET o tramite M_CYCLE_END
				
				_fetch( &devMProc->reg_I );
				
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_DECODE;
				} else {
					return NULL;
				}
				
			}
			if ( devMProc->m_cycle == M_CYCLE_DECODE ) {													//	Ci si arriva solo tramite M_CYCLE_FETCH
				
				_decode();
				
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_EXECUTE;
				} else {
					return NULL;
				}
				
			}
			
			if ( devMProc->m_cycle == M_CYCLE_EXECUTE || devMProc->m_cycle == M_CYCLE_M1 ) {				//	Ci si arriva solo tramite M_CYCLE_DECODE
				devMProc->f_op_code();
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_M2;
					return NULL;
				}
				if ( devMProc->m_cycle != M_CYCLE_END )
					return NULL;
			}
			if ( devMProc->m_cycle == M_CYCLE_M2 ) {
				devMProc->f_op_code();
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_M3;
					return NULL;
				}
				if ( devMProc->m_cycle != M_CYCLE_END )
					return NULL;
			}
			if ( devMProc->m_cycle == M_CYCLE_M3 ) {
				devMProc->f_op_code();
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_M4;
					return NULL;
				}
				if ( devMProc->m_cycle != M_CYCLE_END )
					return NULL;
			}
			if ( devMProc->m_cycle == M_CYCLE_M4 ) {
				devMProc->f_op_code();
				if ( devMProc->m_cycle == M_CYCLE_NEXT ) {
					devMProc->m_cycle = M_CYCLE_M5;
					return NULL;
				}
				if ( devMProc->m_cycle != M_CYCLE_END )
					return NULL;
			}
			
			if ( devMProc->m_cycle == M_CYCLE_END ) {														//	Ci si arriva solo tramite la fine di un' operazione op code
				devMProc->t_cycle		= T_CYCLE_START;
				devMProc->m_cycle		= M_CYCLE_FETCH;
				return NULL;
			}
			
			if ( devMProc->m_cycle == M_CYCLE_NULL ) {
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

	for ( pGList = devMProc->pGates; pGList != NULL; pGList = pGList->g_next ) {
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

	devMProc->n_reset_down_clock 		= 0;
	
	devMProc->t_cycle					= T_CYCLE_START;
	devMProc->m_cycle					= M_CYCLE_FETCH;
	
	devMProc->f_op_code					= NULL;
	
	devMProc->pR						= NULL;		//	Puntatori a indirizzi di memoria dei registri da usare nella decode degli op code
	devMProc->pR1						= NULL;		//	Puntatori a indirizzi di memoria dei registri da usare nella decode degli op code
	devMProc->pA						= 0;		//	Puntatore ad un valore a 16 bit ( Indirizzo di mem ) 
	
	devMProc->reg_A[ MP_MAIN_REG_SET ] = 0;	//
	devMProc->reg_A[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_F[ MP_MAIN_REG_SET ] = 0;
	devMProc->reg_F[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_B[ MP_MAIN_REG_SET ] = 0;	//
	devMProc->reg_B[ MP_ALTE_REG_SET ] = 0;
	devMProc->reg_C[ MP_MAIN_REG_SET ] = 0;	//
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

	//	GATES E WIRES
	
	devMProc->pGates = NULL;
	
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

	devMProc->mp_gate[ MP__CLOCK     ] = gate_new( "_CLOCK", 	GATEMODE_INPUT,	  6, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP_VCC        ] = gate_new( "VCC", 		GATEMODE_INPUT,	 11, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP_GND        ] = gate_new( "GND", 		GATEMODE_INPUT,  29, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP__M1        ] = gate_new( "_M1", 		GATEMODE_OUTPUT, 17, devMProc->mp_wire[ MP__M1        ] );
	devMProc->mp_gate[ MP__MREQ      ] = gate_new( "_MREQ", 	GATEMODE_OUTPUT, 19, devMProc->mp_wire[ MP__MREQ      ] );
	devMProc->mp_gate[ MP__IORQ      ] = gate_new( "_IORQ", 	GATEMODE_OUTPUT, 20, devMProc->mp_wire[ MP__IORQ      ] );
	devMProc->mp_gate[ MP__RD        ] = gate_new( "_RD", 		GATEMODE_OUTPUT, 21, devMProc->mp_wire[ MP__RD        ] );
	devMProc->mp_gate[ MP__WR        ] = gate_new( "_WR", 		GATEMODE_OUTPUT, 22, devMProc->mp_wire[ MP__WR        ] );
	devMProc->mp_gate[ MP__RFSH      ] = gate_new( "_RFSH", 	GATEMODE_OUTPUT, 28, devMProc->mp_wire[ MP__RFSH      ] );
	devMProc->mp_gate[ MP__HALT      ] = gate_new( "_HALT", 	GATEMODE_OUTPUT, 18, devMProc->mp_wire[ MP__HALT      ] );
	devMProc->mp_gate[ MP__WAIT      ] = gate_new( "_WAIT", 	GATEMODE_INPUT,  24, devMProc->mp_wire[ MP__WAIT      ] );
	devMProc->mp_gate[ MP__INT       ] = gate_new( "_INT", 		GATEMODE_INPUT,  16, devMProc->mp_wire[ MP__INT       ] );
	devMProc->mp_gate[ MP__NMI       ] = gate_new( "_NMI", 		GATEMODE_INPUT,  17, devMProc->mp_wire[ MP__NMI       ] );
	devMProc->mp_gate[ MP__RESET     ] = gate_new( "_RESET", 	GATEMODE_INPUT,  26, NULL                               );	// Wires esterni
	devMProc->mp_gate[ MP__BUSRQ     ] = gate_new( "_BUSRQ", 	GATEMODE_INPUT,  25, devMProc->mp_wire[ MP__BUSRQ     ] );
	devMProc->mp_gate[ MP__BUSACK    ] = gate_new( "_BUSACK", 	GATEMODE_OUTPUT, 23, devMProc->mp_wire[ MP__BUSACK    ] );
	devMProc->mp_gate[ MP_Address_00 ] = gate_new( "A00", 		GATEMODE_OUTPUT, 30, devMProc->mp_wire[ MP_Address_00 ] );
	devMProc->mp_gate[ MP_Address_01 ] = gate_new( "A01", 		GATEMODE_OUTPUT, 31, devMProc->mp_wire[ MP_Address_01 ] );
	devMProc->mp_gate[ MP_Address_02 ] = gate_new( "A02", 		GATEMODE_OUTPUT, 32, devMProc->mp_wire[ MP_Address_02 ] );
	devMProc->mp_gate[ MP_Address_03 ] = gate_new( "A03", 		GATEMODE_OUTPUT, 33, devMProc->mp_wire[ MP_Address_03 ] );
	devMProc->mp_gate[ MP_Address_04 ] = gate_new( "A04", 		GATEMODE_OUTPUT, 34, devMProc->mp_wire[ MP_Address_04 ] );
	devMProc->mp_gate[ MP_Address_05 ] = gate_new( "A05", 		GATEMODE_OUTPUT, 35, devMProc->mp_wire[ MP_Address_05 ] );
	devMProc->mp_gate[ MP_Address_06 ] = gate_new( "A06", 		GATEMODE_OUTPUT, 36, devMProc->mp_wire[ MP_Address_06 ] );
	devMProc->mp_gate[ MP_Address_07 ] = gate_new( "A07", 		GATEMODE_OUTPUT, 37, devMProc->mp_wire[ MP_Address_07 ] );
	devMProc->mp_gate[ MP_Address_08 ] = gate_new( "A08", 		GATEMODE_OUTPUT, 38, devMProc->mp_wire[ MP_Address_08 ] );
	devMProc->mp_gate[ MP_Address_09 ] = gate_new( "A09", 		GATEMODE_OUTPUT, 39, devMProc->mp_wire[ MP_Address_09 ] );
	devMProc->mp_gate[ MP_Address_10 ] = gate_new( "A10", 		GATEMODE_OUTPUT, 40, devMProc->mp_wire[ MP_Address_10 ] );
	devMProc->mp_gate[ MP_Address_11 ] = gate_new( "A11", 		GATEMODE_OUTPUT,  1, devMProc->mp_wire[ MP_Address_11 ] );
	devMProc->mp_gate[ MP_Address_12 ] = gate_new( "A12", 		GATEMODE_OUTPUT,  2, devMProc->mp_wire[ MP_Address_12 ] );
	devMProc->mp_gate[ MP_Address_13 ] = gate_new( "A13", 		GATEMODE_OUTPUT,  3, devMProc->mp_wire[ MP_Address_13 ] );
	devMProc->mp_gate[ MP_Address_14 ] = gate_new( "A14", 		GATEMODE_OUTPUT,  4, devMProc->mp_wire[ MP_Address_14 ] );
	devMProc->mp_gate[ MP_Address_15 ] = gate_new( "A15", 		GATEMODE_OUTPUT,  5, devMProc->mp_wire[ MP_Address_15 ] );
	devMProc->mp_gate[ MP_Data_00    ] = gate_new( "D0", 		GATEMODE_INPUT,	 14, devMProc->mp_wire[ MP_Data_00    ] );
	devMProc->mp_gate[ MP_Data_01    ] = gate_new( "D1", 		GATEMODE_INPUT,	 15, devMProc->mp_wire[ MP_Data_01    ] );
	devMProc->mp_gate[ MP_Data_02    ] = gate_new( "D2", 		GATEMODE_INPUT,	 12, devMProc->mp_wire[ MP_Data_02    ] );
	devMProc->mp_gate[ MP_Data_03    ] = gate_new( "D3", 		GATEMODE_INPUT,	  8, devMProc->mp_wire[ MP_Data_03    ] );
	devMProc->mp_gate[ MP_Data_04    ] = gate_new( "D4", 		GATEMODE_INPUT,	  7, devMProc->mp_wire[ MP_Data_04    ] );
	devMProc->mp_gate[ MP_Data_05    ] = gate_new( "D5", 		GATEMODE_INPUT,	  9, devMProc->mp_wire[ MP_Data_05    ] );
	devMProc->mp_gate[ MP_Data_06    ] = gate_new( "D6", 		GATEMODE_INPUT,	 10, devMProc->mp_wire[ MP_Data_06    ] );
	devMProc->mp_gate[ MP_Data_07    ] = gate_new( "D7", 		GATEMODE_INPUT,	 13, devMProc->mp_wire[ MP_Data_07    ] );

	//	Compila la gatelist con l'array di gates
	for ( i=0; i<MP_NUM_PIN; i++) {
		if ( devMProc->pGates == NULL ) {								// devMProc->pGates
			glist_node_accoda( &devMProc->pGates, devMProc->mp_gate[i] );
		} else {
			pGlist = devMProc->pGates;
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
