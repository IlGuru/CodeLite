#include "dev_clock.h"

//---------------------------------

void *ClockTask() {
	p_gate pGate = NULL;

	pGate = devClock->g_clock;

	switch ( devClock->counter ) {
		case 0:
			gate_set_val( pGate, STATO_VAL_MIN );
			break;
		case 1:
			gate_set_val( pGate, STATO_VAL_MIN );
			break;
		case 2:
			gate_set_val( pGate, STATO_VAL_MAX );
			break;
		case 3:
			gate_set_val( pGate, STATO_VAL_MAX );
			break;
		default:
			break;
	}

	devClock->counter++;

	devClock->counter &= 0b00000011;	//	Contiamo solo da 0 a 3

	return NULL;
}

void *ClockInit() {
	devClock = malloc( sizeof(t_Clock) );

	devClock->counter = 0;

	devClock->w_clock = wire_new( "_CLOCK", STATO_VAL_MIN );

	devClock->g_clock = gate_new( "_CLOCK", GATEMODE_OUTPUT, 1, devClock->w_clock );

	devClock->task = (FN_VOID_VOID)ClockTask;

	return NULL;
}
/*
void task( p_wire w_clock ) {
	if ( wire_get_value( w_clock ) == 0 ) {
		wire_set_value( w_clock, 1 );
	} else {
		wire_set_value( w_clock, 0 );
	}

}
*/
