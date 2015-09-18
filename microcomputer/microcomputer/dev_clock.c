#include "dev_clock.h"

//---------------------------------

void *ClockTask() {
	if ( gate_get_val( devClock->g_clock ) == 0 ) {
		gate_set_val( devClock->g_clock, 1 );
	} else {
		gate_set_val( devClock->g_clock, 0 );
	}

	return NULL;
}

void *ClockInit() {
	devClock = malloc( sizeof(t_Clock) );

	devClock->w_clock = wire_new( "CLOCK", '\0' );
	devClock->g_clock = gate_new( "G_CLOCK", GATEMODE_OUTPUT, devClock->w_clock );
	devClock->task = (FNINPUT)ClockTask;

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
