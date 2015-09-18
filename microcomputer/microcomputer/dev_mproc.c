#include "dev_mproc.h"

//---------------------------------

void *MProcTask() {
/*
	p_slist pStato = NULL;
	p_gate pClock, pData00, pData01;
	
	pClock  = devMProc->mp_gate[ MP__CLOCK ];
	pData00 = devMProc->mp_gate[ MP_Data_00 ];
	pData01 = devMProc->mp_gate[ MP_Data_01 ];
	pStato = pClock->Wire->stato->att;	
	if ( TSTBIT( pStato->flag , STATO_FLAG_RAISE ) ) {
		if ( gate_get_val( pData00 ) == STATO_VAL_MAX ) {
			gate_set_val( pData00, STATO_VAL_MIN );
		} else {
			gate_set_val( pData00, STATO_VAL_MAX );
		}
		
		pStato = pData00->Wire->stato->att;		
		if ( TSTBIT( pStato->flag , STATO_FLAG_RAISE ) ) {
			if ( gate_get_val( pData01 ) == STATO_VAL_MAX ) {
				gate_set_val( pData01, STATO_VAL_MIN );
			} else {
				gate_set_val( pData01, STATO_VAL_MAX );
			}
		}
	}
*/
	p_gate pReset	= NULL;
	p_gate pClock	= NULL;
	p_slist pStato	= NULL;

	//MP__RESET
	pReset  = devMProc->mp_gate[ MP__RESET ];	
	pStato = pClock->Wire->stato->att;	
	if ( TSTBIT( pStato->flag , STATO_FLAG_FALL ) ) {	//	Reset request
	
		return NULL;
		
	}
	
	//MP__CLOCK
	pClock  = devMProc->mp_gate[ MP__CLOCK ];	
	pStato = pClock->Wire->stato->att;	
	if ( TSTBIT( pStato->flag , STATO_FLAG_FALL ) ) {	//	Clock down
	
		return NULL;
		
	}
	
	return NULL;
}

void *MProcInit() {
	p_glist pGlist;
	char 	i;
	
	devMProc = malloc( sizeof(t_MProc) );

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

	//	GATES E WIRES
	
	devMProc->pGates = NULL;
	
	devMProc->mp_wire[ MP__M1        ] = wire_new( "_M1", 		1 );
	devMProc->mp_wire[ MP__MREQ      ] = wire_new( "_MREQ", 	1 );
	devMProc->mp_wire[ MP__IORQ      ] = wire_new( "_IORQ", 	1 );
	devMProc->mp_wire[ MP__RD        ] = wire_new( "_RD", 		1 );
	devMProc->mp_wire[ MP__WR        ] = wire_new( "_WR", 		1 );
	devMProc->mp_wire[ MP__RFSH      ] = wire_new( "_RFSH", 	1 );
	devMProc->mp_wire[ MP__HALT      ] = wire_new( "_HALT", 	1 );
	devMProc->mp_wire[ MP__WAIT      ] = wire_new( "_WAIT", 	1 );
	devMProc->mp_wire[ MP__INT       ] = wire_new( "_INT", 		1 );
	devMProc->mp_wire[ MP__NMI       ] = wire_new( "_NMI", 		1 );
	devMProc->mp_wire[ MP__RESET     ] = wire_new( "_RESET",	1 );
	devMProc->mp_wire[ MP__BUSRQ     ] = wire_new( "_BUSRQ",	1 );
	devMProc->mp_wire[ MP__BUSACK    ] = wire_new( "_BUSACK", 	1 );
	devMProc->mp_wire[ MP_Address_00 ] = wire_new( "A00",		0 );
	devMProc->mp_wire[ MP_Address_01 ] = wire_new( "A01",		0 );
	devMProc->mp_wire[ MP_Address_02 ] = wire_new( "A02",		0 );
	devMProc->mp_wire[ MP_Address_03 ] = wire_new( "A03",		0 );
	devMProc->mp_wire[ MP_Address_04 ] = wire_new( "A04",		0 );
	devMProc->mp_wire[ MP_Address_05 ] = wire_new( "A05",		0 );
	devMProc->mp_wire[ MP_Address_06 ] = wire_new( "A06",		0 );
	devMProc->mp_wire[ MP_Address_07 ] = wire_new( "A07",		0 );
	devMProc->mp_wire[ MP_Address_08 ] = wire_new( "A08",		0 );
	devMProc->mp_wire[ MP_Address_09 ] = wire_new( "A09",		0 );
	devMProc->mp_wire[ MP_Address_10 ] = wire_new( "A10",		0 );
	devMProc->mp_wire[ MP_Address_11 ] = wire_new( "A11",		0 );
	devMProc->mp_wire[ MP_Address_12 ] = wire_new( "A12",		0 );
	devMProc->mp_wire[ MP_Address_13 ] = wire_new( "A13",		0 );
	devMProc->mp_wire[ MP_Address_14 ] = wire_new( "A14",		0 );
	devMProc->mp_wire[ MP_Address_15 ] = wire_new( "A15",		0 );
	devMProc->mp_wire[ MP_Data_00    ] = wire_new( "D0", 		0 );
	devMProc->mp_wire[ MP_Data_01    ] = wire_new( "D1", 		0 );
	devMProc->mp_wire[ MP_Data_02    ] = wire_new( "D2", 		0 );
	devMProc->mp_wire[ MP_Data_03    ] = wire_new( "D3", 		0 );
	devMProc->mp_wire[ MP_Data_04    ] = wire_new( "D4", 		0 );
	devMProc->mp_wire[ MP_Data_05    ] = wire_new( "D5", 		0 );
	devMProc->mp_wire[ MP_Data_06    ] = wire_new( "D6", 		0 );
	devMProc->mp_wire[ MP_Data_07    ] = wire_new( "D7", 		0 );

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
	devMProc->mp_gate[ MP__RESET     ] = gate_new( "_RESET", 	GATEMODE_INPUT,  26, devMProc->mp_wire[ MP__RESET     ] );
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

	for ( i=0; i<MP_NUM_PIN; i++) {
		if ( devMProc->pGates == NULL ) {								// Inizializza p_all_gates
			glist_node_accoda( &devMProc->pGates, devMProc->mp_gate[i] );
		} else {
			pGlist = devMProc->pGates;
			while ( pGlist->g_next != NULL ) {						// Cerco l'ultimo nodo della lista
				pGlist = pGlist->g_next;
			}
			glist_node_accoda( &pGlist, devMProc->mp_gate[i] );
		}
	}

	//	Callback
	devMProc->task = (FN_VOID_VOID)MProcTask;

	return NULL;
}
