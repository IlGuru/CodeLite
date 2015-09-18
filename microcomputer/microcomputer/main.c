
#include "window.h"
#include "board.h"
#include "dev_clock.h"
#include "dev_mproc.h"

#include <stdlib.h>
#include <time.h>

#ifdef __MINGW32__
#include <ncursest/ncurses.h>
#else
#include <curses.h>
#endif

//---------------------------------

typedef struct {
	t_window Main;
	t_window Bus;
} t_windows;

typedef t_windows* p_windows;

p_windows pWindows;

void wndInit() {
	pWindows = malloc( sizeof( t_windows ) );
	
	wndInitWindow( &pWindows->Main, NULL, 0, 0, 0, 0 );
	wndInitWindow( &pWindows->Bus, &pWindows->Main, 1, 1, 60, 30 );
	
}

//---------------------------------

void sleepMs( long ms ) {
    struct timespec ts;
	if ( ms > 0 ) {
		ts.tv_sec  = ms/1000;
		ts.tv_nsec = ( ms*1000 ) % 1000000;

		nanosleep(&ts, NULL);
	}
}

//---------------------------------

void *Init() {
	wndInit();

	return NULL;
}

//---------------------------------

void busShow( t_window* dsp ) {

	p_wlist r;
	p_glist g;
	p_slist	c;

	dsp->cursor.y = dsp->start.y;
	for ( r = p_all_wires; r != NULL; r=r->w_next ) {
		
		dsp->cursor.x = dsp->start.x;
		mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%s: ", r->Wire->nome );
		dsp->cursor.x += 9;
		for ( c = r->Wire->stato->oldest ; c != NULL; c = c->s_next ) {

			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%d", c->valore );
			dsp->cursor.x += 1;

		}
		dsp->cursor.y++;
	}

	dsp->cursor.y++;
	for ( g = p_all_gates; g != NULL; g=g->g_next ) {
		dsp->cursor.x = dsp->start.x;
		mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%s: ", g->Gate->nome );
		dsp->cursor.x += 9;

		if ( g->Gate->gate_mode == GATEMODE_THREE_STATE || g->Gate->Wire == NULL ) {
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "-" );
		} else {
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%d", g->Gate->Wire->stato->att->valore );
		}

		dsp->cursor.y++;
	}

	wrefresh( dsp->wnd );
}

//---------------------------------

int main( int argc, char *argv[] ) {

	p_gate g0;
	p_gate g1;
	p_wire w_reset, w_clock;
	p_bus  b_signals;

	//------------------------------------------------------------------------
	//	Callback Init

	lfunct_accoda( &p_all_inits, (FNINPUT)Init );
	lfunct_accoda( &p_all_inits, (FNINPUT)boardInit );
	lfunct_accoda( &p_all_inits, (FNINPUT)ClockInit );
	lfunct_accoda( &p_all_inits, (FNINPUT)MProcInit );

	p_ListFunct p_fList;
	for ( p_fList = p_all_inits; p_fList != NULL; p_fList = p_fList->nList ) {
		p_fList->fFunc();
	}

	//------------------------------------------------------------------------
	//	Callback task

	lfunct_accoda( &p_all_tasks, all_wires_add_tick );
	lfunct_accoda( &p_all_tasks, devClock->task );
	lfunct_accoda( &p_all_tasks, devMProc->task );

	//------------------------------------------------------------------------
	//	Board

//	w_reset = wire_new( "WIRE1", '\0' );
//	w_clock = wire_new( "WIRE2", '\0' );

	b_signals = new_bus( "SIGNALS", NULL );
	bus_add_wire( b_signals,  devClock->w_clock );
	bus_add_wire( b_signals,  devClock->w_clock );
//	bus_add_wire( b_signals,  w_reset );
//	bus_add_wire( b_signals,  w_clock );
//	g0 = gate_new( "G0", GATEMODE_INPUT, devClock->w_clock );
//	g1 = gate_new( "G1", GATEMODE_INPUT, devClock->w_clock );

	gate_connect( devMProc->g_Clock, devClock->w_clock );

	//------------------------------------------------------------------------
	//	Esecuzione procedure

	while ( 1 ) {
		busShow( &pWindows->Bus );

		for ( p_fList = p_all_tasks; p_fList != NULL; p_fList = p_fList->nList ) {
			p_fList->fFunc();
		}

		sleepMs(1000);
	}

	wrefresh( pWindows->Bus.wnd );

	//------------------------------------------------------------------------
	//	FINE

	free(g0);
	free(g1);

	return 0;

/*

	//Init();
	//boardInit();

	b_signals = new_bus( "SIGNALS", NULL );
	w_reset = wire_new( "RESET", '\0' );
	bus_add_wire( b_signals,  w_reset );
	w_clock = wire_new( "CLOCK", '\0' );
	bus_add_wire( b_signals,  w_clock );

	g0 = gate_new( "G0", GATEMODE_OUTPUT, w_clock );
	g1 = gate_new( "G1", GATEMODE_OUTPUT, w_clock );

	sleepMs(1000);
	busShow( &pWindows->Bus );

	all_wires_add_tick();
	task( w_clock );

	sleepMs(1000);
	busShow( &pWindows->Bus );

	all_wires_add_tick();
	task( w_clock );

	sleepMs(1000);
	busShow( &pWindows->Bus );

	all_wires_add_tick();
	task( w_clock );

	sleepMs(1000);
	busShow( &pWindows->Bus );

	all_wires_add_tick();
	task( w_clock );

	sleepMs(1000);
	busShow( &pWindows->Bus );

	while ( 1 ) {
		wrefresh( pWindows->Bus.wnd );
	}
*/
/*
	b_data = new_bus( "DATA", NULL );
	bus_add_wire( b_data,  wire_new( "D0", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D1", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D2", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D3", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D4", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D5", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D6", '\0' ) );
	bus_add_wire( b_data,  wire_new( "D7", '\0' ) );

	b_address = new_bus( "ADDRESS", NULL );
	bus_add_wire( b_address,  wire_new( "A00", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A01", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A02", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A03", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A04", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A05", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A06", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A07", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A08", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A09", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A10", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A11", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A12", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A13", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A14", '\0' ) );
	bus_add_wire( b_address,  wire_new( "A15", '\0' ) );
	
	w0 = bus_get_wire( b_data, 		"D0" );
	w1 = bus_get_wire( b_address, 	"A00" );
	
	wire_add_tick();
	wire_add_tick();
	wire_add_tick();
	
//	slist_del_last( w1->stato );
	wire_del_last_tick();
*/
	
/*	
	w_d0 = bus_get_wire( b_data, "D3" );
	wire_set_value( w_d0, '1' );
	w_val = wire_get_value( w_d0 );
	
	w_d0->stato = slist_add( w_d0->stato );
	wire_set_value( w_d0, '2' );

	w_d0 = bus_get_wire( b_data, "D1" );
	wire_add_set( w_d0, '1' );
	wire_add_set( w_d0, '2' );
*/
	
/*
	Init();
	
	//------------------------------
	
	busDoReset();
	busTick();
	busTick();
	busTick();
	
	busShow( &pWindows->Bus );
	
	while ( 1 ) {
	
	}
*/	

}