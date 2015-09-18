#include "dev_memory.h"

//---------------------------------

static dt_16bit _mem_read_address() {
	dt_16bit b	= 0;

	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_15 ] ) == STATO_VAL_MIN ) ? 0 : 0x8000 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_14 ] ) == STATO_VAL_MIN ) ? 0 : 0x4000 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_13 ] ) == STATO_VAL_MIN ) ? 0 : 0x2000 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_12 ] ) == STATO_VAL_MIN ) ? 0 : 0x1000 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_11 ] ) == STATO_VAL_MIN ) ? 0 : 0x0800 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_10 ] ) == STATO_VAL_MIN ) ? 0 : 0x0400 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_09 ] ) == STATO_VAL_MIN ) ? 0 : 0x0200 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_08 ] ) == STATO_VAL_MIN ) ? 0 : 0x0100 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_07 ] ) == STATO_VAL_MIN ) ? 0 : 0x0080 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_06 ] ) == STATO_VAL_MIN ) ? 0 : 0x0040 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_05 ] ) == STATO_VAL_MIN ) ? 0 : 0x0020 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_04 ] ) == STATO_VAL_MIN ) ? 0 : 0x0010 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_03 ] ) == STATO_VAL_MIN ) ? 0 : 0x0008 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_02 ] ) == STATO_VAL_MIN ) ? 0 : 0x0004 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_01 ] ) == STATO_VAL_MIN ) ? 0 : 0x0002 );
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Address_00 ] ) == STATO_VAL_MIN ) ? 0 : 0x0001 );	//	8192

	return b;
}

static dt_8bit _mem_read_data() {
	dt_8bit b	= 0;
	
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_07 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_06 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_05 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_04 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_03 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_02 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_01 ] ) == STATO_VAL_MIN ) ? 0 : 1 );
	b <<= 1;
	b |= ( ( gate_get_val( devMemory->mem_gate[ MEM_Data_00 ] ) == STATO_VAL_MIN ) ? 0 : 1 );

	return b;
}

static void _mem_send_data( dt_8bit dt ) {
	
 	gate_set_val( devMemory->mem_gate[ MEM_Data_00 ], (TSTBIT(dt,0)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_01 ], (TSTBIT(dt,1)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_02 ], (TSTBIT(dt,2)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_03 ], (TSTBIT(dt,3)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_04 ], (TSTBIT(dt,4)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_05 ], (TSTBIT(dt,5)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_06 ], (TSTBIT(dt,6)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );
 	gate_set_val( devMemory->mem_gate[ MEM_Data_07 ], (TSTBIT(dt,7)==STATO_VAL_MIN ? STATO_VAL_MIN : STATO_VAL_MAX) );

}

void *MemorySelfConnect() {

	p_gate	pGate	= NULL;
	p_glist	pGList	= NULL;
	p_wire	pWire	= NULL;
	p_wlist	pWList	= NULL;

	for ( pGList = devMemory->dev->pGates; pGList != NULL; pGList = pGList->g_next ) {
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

void *MemoryTask() {
	p_gate 	pCE1	= NULL;
	p_gate 	pCE2	= NULL;
	p_gate 	pRD	    = NULL;
	p_gate 	pWR	    = NULL;
	p_slist pSCE1	= NULL;
	p_slist pSCE2	= NULL;
	p_slist pSRD	= NULL;
	p_slist pSWR	= NULL;

	dt_16bit 	ma	= 0;
	dt_8bit		dt	= 0;
	
	pCE1  = devMemory->mem_gate[ MEM__CE1 ];
	pCE2  = devMemory->mem_gate[ MEM__CE2 ];
	pRD  = devMemory->mem_gate[ MEM__RD ];
	pWR   = devMemory->mem_gate[ MEM__WR ];

	if ( pCE1->Wire != NULL )
		pSCE1 = pCE1->Wire->stato->att;
	if ( pCE2->Wire != NULL )
		pSCE2 = pCE2->Wire->stato->att;
	if ( pRD->Wire != NULL )
		pSRD = pRD->Wire->stato->att;
	if ( pWR->Wire != NULL )
		pSWR = pWR->Wire->stato->att;

	//	Lettura
	if ( pSCE1 != NULL && pSRD != NULL ) {

		if ( (TSTBIT( pSCE1->flag , STATO_FLAG_FALL ) || TSTBIT( pSCE1->flag , STATO_FLAG_LOW )) && TSTBIT( pSRD->flag , STATO_FLAG_FALL ) ) {

			ma = _mem_read_address();
			dt = devMemory->memory[ ma ];

			gate_set_state( devMemory->mem_gate[ MEM_Data_00 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_01 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_02 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_03 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_04 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_05 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_06 ], GATEMODE_OUTPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_07 ], GATEMODE_OUTPUT );

			_mem_send_data( dt );
			
		}
	
		if ( ( gate_get_state( devMemory->mem_gate[ MEM_Data_00 ] ) == GATEMODE_OUTPUT ) && ( TSTBIT( pSCE1->flag , STATO_FLAG_HIGH ) || TSTBIT( pSCE2->flag , STATO_FLAG_HIGH ) ) ) {

			gate_set_state( devMemory->mem_gate[ MEM_Data_00 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_01 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_02 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_03 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_04 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_05 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_06 ], GATEMODE_INPUT );
			gate_set_state( devMemory->mem_gate[ MEM_Data_07 ], GATEMODE_INPUT );

		}
	
	}

	//	Scrittura
	if ( pSCE1 != NULL && pSWR != NULL ) {

		if ( (TSTBIT( pSCE1->flag , STATO_FLAG_FALL ) || TSTBIT( pSCE1->flag , STATO_FLAG_LOW )) && TSTBIT( pSWR->flag , STATO_FLAG_FALL ) ) {

			ma = _mem_read_address();
			dt = _mem_read_data();

			devMemory->memory[ ma ] = dt;
			
		}
	
	}

	return NULL;
}

void *MemoryInit() {
	p_glist 	pGlist	= NULL;
	dt_16bit 	i		= 0;

	devMemory = malloc( sizeof(t_Memory) );

	for ( i=0; i<MEM_SIZE; i++ )
		devMemory->memory[ i ] = 0;
	
	//	Device
	devMemory->dev			= malloc( sizeof( t_device ) );
	devMemory->dev->nome	= "8K RAM";
	devMemory->dev->pGates	= NULL;
	
	//	Gates
	devMemory->mem_gate[ MEM_VCC        ] = gate_new( "VCC", 		devMemory->dev, GATEMODE_INPUT,	 11, NULL );
	devMemory->mem_gate[ MEM_GND        ] = gate_new( "GND", 		devMemory->dev, GATEMODE_INPUT,  29, NULL );
	devMemory->mem_gate[ MEM__CE1       ] = gate_new( "_MREQ", 		devMemory->dev, GATEMODE_INPUT,  17, NULL );
	devMemory->mem_gate[ MEM__CE2       ] = gate_new( "_MREQ", 		devMemory->dev, GATEMODE_INPUT,  17, NULL );	//
	devMemory->mem_gate[ MEM__RD        ] = gate_new( "_RD", 		devMemory->dev, GATEMODE_INPUT,  19, NULL );
	devMemory->mem_gate[ MEM__WR        ] = gate_new( "_WR", 		devMemory->dev, GATEMODE_INPUT,  19, NULL );
	devMemory->mem_gate[ MEM_Address_00 ] = gate_new( "A00", 		devMemory->dev, GATEMODE_INPUT,  30, NULL );
	devMemory->mem_gate[ MEM_Address_01 ] = gate_new( "A01", 		devMemory->dev, GATEMODE_INPUT,  31, NULL );
	devMemory->mem_gate[ MEM_Address_02 ] = gate_new( "A02", 		devMemory->dev, GATEMODE_INPUT,  32, NULL );
	devMemory->mem_gate[ MEM_Address_03 ] = gate_new( "A03", 		devMemory->dev, GATEMODE_INPUT,  33, NULL );
	devMemory->mem_gate[ MEM_Address_04 ] = gate_new( "A04", 		devMemory->dev, GATEMODE_INPUT,  34, NULL );
	devMemory->mem_gate[ MEM_Address_05 ] = gate_new( "A05", 		devMemory->dev, GATEMODE_INPUT,  35, NULL );
	devMemory->mem_gate[ MEM_Address_06 ] = gate_new( "A06", 		devMemory->dev, GATEMODE_INPUT,  36, NULL );
	devMemory->mem_gate[ MEM_Address_07 ] = gate_new( "A07", 		devMemory->dev, GATEMODE_INPUT,  37, NULL );
	devMemory->mem_gate[ MEM_Address_08 ] = gate_new( "A08", 		devMemory->dev, GATEMODE_INPUT,  38, NULL );
	devMemory->mem_gate[ MEM_Address_09 ] = gate_new( "A09", 		devMemory->dev, GATEMODE_INPUT,  39, NULL );
	devMemory->mem_gate[ MEM_Address_10 ] = gate_new( "A10", 		devMemory->dev, GATEMODE_INPUT,  40, NULL );
	devMemory->mem_gate[ MEM_Address_11 ] = gate_new( "A11", 		devMemory->dev, GATEMODE_INPUT,   1, NULL );
	devMemory->mem_gate[ MEM_Address_12 ] = gate_new( "A12", 		devMemory->dev, GATEMODE_INPUT,   2, NULL );
	devMemory->mem_gate[ MEM_Address_13 ] = gate_new( "A13", 		devMemory->dev, GATEMODE_INPUT,   3, NULL );
	devMemory->mem_gate[ MEM_Address_14 ] = gate_new( "A14", 		devMemory->dev, GATEMODE_INPUT,   4, NULL );
	devMemory->mem_gate[ MEM_Address_15 ] = gate_new( "A15", 		devMemory->dev, GATEMODE_INPUT,   5, NULL );
	devMemory->mem_gate[ MEM_Data_00    ] = gate_new( "D0", 		devMemory->dev, GATEMODE_INPUT,	 14, NULL );
	devMemory->mem_gate[ MEM_Data_01    ] = gate_new( "D1", 		devMemory->dev, GATEMODE_INPUT,	 15, NULL );
	devMemory->mem_gate[ MEM_Data_02    ] = gate_new( "D2", 		devMemory->dev, GATEMODE_INPUT,	 12, NULL );
	devMemory->mem_gate[ MEM_Data_03    ] = gate_new( "D3", 		devMemory->dev, GATEMODE_INPUT,	  8, NULL );
	devMemory->mem_gate[ MEM_Data_04    ] = gate_new( "D4", 		devMemory->dev, GATEMODE_INPUT,	  7, NULL );
	devMemory->mem_gate[ MEM_Data_05    ] = gate_new( "D5", 		devMemory->dev, GATEMODE_INPUT,	  9, NULL );
	devMemory->mem_gate[ MEM_Data_06    ] = gate_new( "D6", 		devMemory->dev, GATEMODE_INPUT,	 10, NULL );
	devMemory->mem_gate[ MEM_Data_07    ] = gate_new( "D7", 		devMemory->dev, GATEMODE_INPUT,	 13, NULL );

	//	Compila la gatelist con l'array di gates
	for ( i=0; i<MEM_NUM_PIN; i++) {
		if ( devMemory->dev->pGates == NULL ) {								// devMemory->dev->pGates
			glist_node_accoda( &devMemory->dev->pGates, devMemory->mem_gate[i] );
		} else {
			pGlist = devMemory->dev->pGates;
			while ( pGlist->g_next != NULL ) {							// Cerco l'ultimo nodo della lista
				pGlist = pGlist->g_next;
			}
			glist_node_accoda( &pGlist, devMemory->mem_gate[i] );
		}
	}

	//	Callback
	devMemory->self_connect	= (FN_VOID_VOID)MemorySelfConnect;
	devMemory->task 		= (FN_VOID_VOID)MemoryTask;

	return NULL;
}
