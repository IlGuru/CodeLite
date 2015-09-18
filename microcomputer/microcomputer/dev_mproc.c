#include "dev_mproc.h"

//---------------------------------

void *MProcTask() {

	/*
	if ( gate_get_val( devMProc->g_Clock ) == 1 ) {
		gate_set_val( devMProc->g_Data[0], 0 );
	} else {
		gate_set_val( devMProc->g_Data[0], 1 );
	}
	*/
	if ( devMProc->g_Clock->Wire->stato->entries > 1) {
		if ( ( devMProc->g_Clock->Wire->stato->att->valore == 1 ) && ( devMProc->g_Clock->Wire->stato->att->s_prev->valore == 0 ) ) {
			if ( gate_get_val( devMProc->g_Data[0] ) == 1 ) {
				gate_set_val( devMProc->g_Data[0], 0 );
			} else {
				gate_set_val( devMProc->g_Data[0], 1 );
			}
			if ( ( devMProc->g_Data[0]->Wire->stato->att->valore == 1 ) && ( devMProc->g_Data[0]->Wire->stato->att->s_prev->valore == 0 ) ) {
				if ( gate_get_val( devMProc->g_Data[1] ) == 1 ) {
					gate_set_val( devMProc->g_Data[1], 0 );
				} else {
					gate_set_val( devMProc->g_Data[1], 1 );
				}
			}
		}
	}

	return NULL;
}

void *MProcInit() {
	devMProc = malloc( sizeof(t_MProc) );

	devMProc->w_Data[0] = wire_new( "DATA_0", '\0' );
	devMProc->w_Data[1] = wire_new( "DATA_1", '\0' );

	devMProc->g_Clock   = gate_new( "MP_CLOCK", GATEMODE_INPUT, NULL );

	devMProc->g_Data[0] = gate_new( "MP_D0", GATEMODE_OUTPUT, devMProc->w_Data[0] );
	devMProc->g_Data[1] = gate_new( "MP_D1", GATEMODE_OUTPUT, devMProc->w_Data[1] );
	devMProc->g_Data[2] = gate_new( "MP_D2", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Data[3] = gate_new( "MP_D3", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Data[4] = gate_new( "MP_D4", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Data[5] = gate_new( "MP_D5", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Data[6] = gate_new( "MP_D6", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Data[7] = gate_new( "MP_D7", GATEMODE_THREE_STATE, NULL );
/*
	devMProc->g_Address[0]  = gate_new( "MP_A00", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[1]  = gate_new( "MP_A01", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[2]  = gate_new( "MP_A02", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[3]  = gate_new( "MP_A03", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[4]  = gate_new( "MP_A04", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[5]  = gate_new( "MP_A05", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[6]  = gate_new( "MP_A06", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[7]  = gate_new( "MP_A07", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[8]  = gate_new( "MP_A08", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[9]  = gate_new( "MP_A09", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[10] = gate_new( "MP_A10", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[11] = gate_new( "MP_A11", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[12] = gate_new( "MP_A12", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[13] = gate_new( "MP_A13", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[14] = gate_new( "MP_A14", GATEMODE_THREE_STATE, NULL );
	devMProc->g_Address[15] = gate_new( "MP_A15", GATEMODE_THREE_STATE, NULL );
*/
	devMProc->task = (FNINPUT)MProcTask;

	return NULL;
}
/*
void task( p_wire w_MProc ) {
	if ( wire_get_value( w_MProc ) == 0 ) {
		wire_set_value( w_MProc, 1 );
	} else {
		wire_set_value( w_MProc, 0 );
	}

}
*/
