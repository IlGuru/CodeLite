#include "dev_reset.h"

//---------------------------------

void *ResetTask() {
	/*
	p_gate pGate = NULL;

	pGate = devReset->g_reset;

	//	Va a 0 tra il 5 ed il 23 tick ( 4 impulsi di clock e 1/4 )
	if ( devReset->counter < 23 ) {
	
		if ( devReset->counter >= 5 )
			gate_set_val( pGate, STATO_VAL_MIN );
			
		devReset->counter++;
	} else {
		gate_set_val( pGate, STATO_VAL_MAX );
	}
	*/
	return NULL;
}

void *ResetInit() {
	devReset = malloc( sizeof(t_Reset) );

	//	Device
	devReset->dev			= malloc( sizeof( t_device ) );
	devReset->dev->nome		= "RESET BTN";
	devReset->dev->pGates	= NULL;
	
	//	Inizializzazione valori
	
	devReset->counter = 0;

	//	GATES E WIRES

	devReset->w_reset = wire_new( "_RESET", STATO_VAL_MAX );

	devReset->g_reset = gate_new( "_RESET", devReset->dev, 	GATEMODE_OUTPUT, 1, devReset->w_reset );

	//	Callback

	devReset->task = (FN_VOID_VOID)ResetTask;

	return NULL;
}

