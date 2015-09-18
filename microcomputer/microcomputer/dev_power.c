#include "dev_power.h"

//---------------------------------

void *PowerTask() {
	
	return NULL;

}

void *PowerSelfConnect() {

	p_gate	pGate	= NULL;
	p_glist	pGList	= NULL;
	p_wire	pWire	= NULL;
	p_wlist	pWList	= NULL;

	for ( pGList = devPower->pGates; pGList != NULL; pGList = pGList->g_next ) {
		pGate = pGList->Gate;

		if ( pGate->Wire == NULL ) {
			for ( pWList = p_all_wires; pWList != NULL; pWList = pWList->w_next ) {
				pWire = pWList->Wire;

				if ( strcmp( pGate->nome, pWire->nome ) == 0 ) {
					gate_connect( pGate, pWire );
				}
			}
		}
	}

	return NULL;

}

void *PowerInit() {
	p_glist 	pGlist;
	short int 	i;
	
	devPower = malloc( sizeof(t_Power) );

	//	Device
	devPower->dev			= malloc( sizeof( t_device ) );
	devPower->dev->nome		= "POWER SUPPLY";
	devPower->dev->pGates	= NULL;
	
	//	GATES E WIRES
	
	devPower->pGates = NULL;
	
	devPower->pw_wire[ PW_GND ] = wire_new( "GND", 	STATO_VAL_MIN );
	devPower->pw_wire[ PW_VCC ] = wire_new( "VCC", 	STATO_VAL_MAX );

	devPower->pw_gate[ PW_GND ] = gate_new( "GND", 		devPower->dev, 	GATEMODE_OUTPUT, 1, devPower->pw_wire[ PW_GND ] );
	devPower->pw_gate[ PW_VCC ] = gate_new( "VCC", 		devPower->dev, 	GATEMODE_OUTPUT, 2, devPower->pw_wire[ PW_VCC ] );

	for ( i=0; i<PW_NUM_PIN; i++) {
		if ( devPower->pGates == NULL ) {								// devPower->pGates
			glist_node_accoda( &devPower->pGates, devPower->pw_gate[i] );
		} else {
			pGlist = devPower->pGates;
			while ( pGlist->g_next != NULL ) {							// Cerco l'ultimo nodo della lista
				pGlist = pGlist->g_next;
			}
			glist_node_accoda( &pGlist, devPower->pw_gate[i] );
		}
	}

	//	Callback
	
	devPower->self_connect	= (FN_VOID_VOID)PowerSelfConnect;
	devPower->task 			= (FN_VOID_VOID)PowerTask;

	return NULL;
}
