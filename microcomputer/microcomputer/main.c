
#include "window.h"
#include "board.h"
#include "dev_power.h"
#include "dev_clock.h"
#include "dev_reset.h"
#include "dev_mproc.h"
#include "dev_memory.h"

#include <stdlib.h>
#include <time.h>

#ifdef __MINGW32__
#define _C_WIN
#else
#define _C_CYGWIN
#endif

#ifdef __MINGW32__
#include <ncursest/ncurses.h>
#else
#include <curses.h>
#endif

//---------------------------------

typedef struct {
	t_window Main;
	t_window MProc;
#ifdef _C_CYGWIN
	t_window Bus;
	t_window Gates;
	t_window Memory;
#endif
} t_windows;

typedef t_windows* p_windows;

p_windows pWindows;

void wndInit() {
	pWindows = malloc( sizeof( t_windows ) );
	
	wndInitWindow( &pWindows->Main, 	NULL, 0, 0, 0, 0 );
	wndInitWindow( &pWindows->MProc, 	&pWindows->Main, 1, 1,  90, 9 );
#ifdef _C_CYGWIN
	wndInitWindow( &pWindows->Bus, 		&pWindows->Main, 1, 10, 90, 15 );
//	wndInitWindow( &pWindows->Gates, 	&pWindows->Main, 1, 15, 90, 12 );
	wndInitWindow( &pWindows->Memory, 	&pWindows->Main, 1, 25, 90, 15 );
#endif
}

//---------------------------------

void sleepMs( long ms ) {
    struct timespec ts;
	if ( ms > 0 ) {
		ts.tv_sec  = ms/1000;
		ts.tv_nsec = ( ms*1000000 ) % 1000000000;

		nanosleep(&ts, NULL);
	}
}

//---------------------------------

void* Programma() {
	
	//----------------------------------------------------------------------------------
	//	Programma:
	
	//	Test LD r, r'
	/*
	*devMProc->Reg->A		= 0xAA;
	*devMProc->Reg->B		= 0xBB;
	*devMProc->Reg->C		= 0xCC;
	devMemory->memory[ 0 ] 	= OP_CODE_R_R1( OP_EM_LD_R_R , REG_B , REG_A );	//	LD B, A		A -> B
	devMemory->memory[ 1 ] 	= OP_CODE_R_R1( OP_EM_LD_R_R , REG_C , REG_B );	//	LD C, B		B -> C
	*/
	
	//	Test LD r,n
	/*
	devMemory->memory[ 0 ] = OP_CODE_R( OP_EM_LD_R_N , REG_A );	//	LD A, N		N -> A
	devMemory->memory[ 1 ] = 0x80;
	*/
	
	//	Test LD r, (HL)	
	/*
	//		Metto 0x44 in (0x0105), metto 0x01 in H, 0x05 in L così (HL) = (0x0105), poi eseguo LD A, (HL) ed alla fine in A ci sarà 0x44
	//	LD H, N		N -> H
	*devMProc->Reg->HL		= 0x0105;
	devMemory->memory[ 0x0105 ] = 0x44;						
	//	LD A, (HL)	(HL) -> A
	devMemory->memory[ 0 ] = OP_CODE_R(OP_EM_LD_R_HL,REG_A);	
	*/
	
	//	Test LD r, (IX+d) : r=A, d=4, IX=1 => (IX+d)=(0x05)=0xBB => A=0xBB
	/*
	*devMProc->Reg->IX	   = 1;
	devMemory->memory[ 0 ] = 0xDD;
	devMemory->memory[ 1 ] = OP_CODE_R(0b01000110,REG_A);
	devMemory->memory[ 2 ] = 0x04;
	devMemory->memory[ 3 ] = 0x00;
	devMemory->memory[ 5 ] = 0xBB;
	*/

	//	Test LD r, (IY+d) : r=A, d=4, IY=1 => (IY+d)=(0x05)=0xCC => A=0xCC
	/*
	*devMProc->Reg->IY	   = 1;
	devMemory->memory[ 0 ] = 0xFD;
	devMemory->memory[ 1 ] = OP_CODE_R(0b01000110,REG_A);
	devMemory->memory[ 2 ] = 0x04;
	devMemory->memory[ 3 ] = 0x00;
	devMemory->memory[ 5 ] = 0xCC;
	*/
	
	//	Test LD (HL), r
	/*
	*devMProc->Reg->HL		= 0x0001;
	*devMProc->Reg->A		= 0xAA;
	devMemory->memory[ 0 ] 	= OP_CODE_R1(0b01110000,REG_A);
	devMemory->memory[ 1 ] 	= 0x00;
	*/
	
	//	Test LD (IX+d), r
	/*
	*devMProc->Reg->A		= 0xAA;
	*devMProc->Reg->IX	   	= 1;
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= OP_CODE_R1(0b01110000,REG_A);
	devMemory->memory[ 2 ] 	= 0x05;	//	d
	devMemory->memory[ 3 ] 	= 0x00;
	devMemory->memory[ 5 ] 	= 0x99;	//	IX+d
	*/
	
	//	LD (IY+d), r
	/*
	*devMProc->Reg->A		= 0xCC;
	*devMProc->Reg->IY	   	= 2;
	devMemory->memory[ 0 ] 	= 0xFD;
	devMemory->memory[ 1 ] 	= OP_CODE_R1(0b01110000,REG_A);
	devMemory->memory[ 2 ] 	= 0x05;	//	d
	devMemory->memory[ 3 ] 	= 0x00;
	devMemory->memory[ 5 ] 	= 0x99;	//	IX+d
	*/
	
	//	LD (HL), n
	/*
	*devMProc->Reg->HL		= 0x0002;
	devMemory->memory[ 0 ] 	= 0x36;
	devMemory->memory[ 1 ] 	= 0xAA;
	devMemory->memory[ 2 ] 	= 0x44;
	*/

	//	LD (IX+d), n
	/*
	*devMProc->Reg->IX	   	= 1;
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= 0x36;
	devMemory->memory[ 2 ] 	= 0x04;	//	d
	devMemory->memory[ 3 ] 	= 0x40;	//	n
	*/

	//	LD (IX+d), n
	/*
	*devMProc->Reg->IY	   	= 1;
	devMemory->memory[ 0 ] 	= 0xFD;
	devMemory->memory[ 1 ] 	= 0x36;
	devMemory->memory[ 2 ] 	= 0x03;	//	d
	devMemory->memory[ 3 ] 	= 0xF1;	//	n
	*/

	//	Test LD A, (BC)
	/*
	*devMProc->Reg->BC			= 0x0105;
	devMemory->memory[ 0x0105 ] = 0x15;
	//	LD A, (BC)	(BC) -> A
	devMemory->memory[ 0 ] 		= 0x0A;
	*/

	//	Test LD A, (DE)
	/*
	*devMProc->Reg->DE			= 0x0105;
	devMemory->memory[ 0x0105 ] = 0x15;
	//	LD A, (DE)	(DE) -> A
	devMemory->memory[ 0 ] 		= 0x1A;
	*/

	//	LD A, (nn)
	/*
	devMemory->memory[ 0x0132 ] = 0x04;
	//	LD A, (nn)	(nn) -> A
	devMemory->memory[ 0 ] = 0x3A;	
	devMemory->memory[ 1 ] = 0x32;	//	ll
	devMemory->memory[ 2 ] = 0x01;	//	hh
	*/
	
	//	LD (nn), A
	/*
	*devMProc->Reg->A		= 0xCC;
	devMemory->memory[ 0 ] 	= 0x32;
	devMemory->memory[ 1 ] 	= 0x32;	//	ll
	devMemory->memory[ 2 ] 	= 0x01;	//	hh
	*/
	
	//	LD (BC), A
	/*
	*devMProc->Reg->A		= 0xBC;
	*devMProc->Reg->BC		= 0x0100;
	devMemory->memory[ 0 ] 	= 0x02;	
	*/
	
	//	LD (DE), A
	/*
	*devMProc->Reg->A		= 0xDE;
	*devMProc->Reg->DE		= 0x0100;
	devMemory->memory[ 0 ] 	= 0x12;	
	*/
	
	//LD A, I
	/*
	*devMProc->Reg->A		= 0xFF;
	*devMProc->Reg->I		= 0x00;
	devMemory->memory[ 0 ] 	= 0xED;	
	devMemory->memory[ 1 ] 	= 0x57;	
	*/
	
	//LD A, R
	/*
	*devMProc->Reg->A		= 0x0D;
	*devMProc->Reg->R		= 0xFF;
	devMemory->memory[ 0 ] 	= 0xED;	
	devMemory->memory[ 1 ] 	= 0x5F;	
	*/
	
	//LD I, A
	/*
	*devMProc->Reg->A		= 0xAF;
	devMemory->memory[ 0 ] 	= 0xED;
	devMemory->memory[ 1 ] 	= 0x47;	
	*/
	
	//LD R, A
	/*
	*devMProc->Reg->A		= 0xAF;
	devMemory->memory[ 0 ] 	= 0xED;
	devMemory->memory[ 1 ] 	= 0x4F;	
	*/

	//	LD dd, nn
	devMemory->memory[ 0 ] 	= 0b00110001;
	devMemory->memory[ 1 ] 	= 0x50;
	devMemory->memory[ 2 ] 	= 0x00;
	/*
	*/

	//	LD IX, nn
	/*
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= 0x21;
	devMemory->memory[ 2 ] 	= 0x1F;
	devMemory->memory[ 3 ] 	= 0x00;
	*/

	//	LD HL, (nn)
	/*
	devMemory->memory[ 0 ] 	= 0x2A;
	devMemory->memory[ 1 ] 	= 0x45;		//	*n
	devMemory->memory[ 2 ] 	= 0x01;		//	n*
	devMemory->memory[ 0x0145 ] = 0x37;	//	(nn)
	devMemory->memory[ 0x0146 ] = 0xA1;	//	(nn+1)
	*/

	//	LD dd, (nn)
	/*
	devMemory->memory[ 0 ] 	= 0xED;
	devMemory->memory[ 1 ] 	= 0b01001011 | 0b00110000;
	devMemory->memory[ 2 ] 	= 0x30;
	devMemory->memory[ 3 ] 	= 0x01;
	devMemory->memory[ 0x0130 ] = 0x65;
	devMemory->memory[ 0x0131 ] = 0x78;
	*/

	//	LD IX, (nn)	;	0xB1A0 -> IX
/*
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= 0x2A;
	devMemory->memory[ 2 ] 	= 0x45;		//	*n
	devMemory->memory[ 3 ] 	= 0x01;		//	n*
	devMemory->memory[ 0x0145 ] = 0xA0;	//	(nn)
	devMemory->memory[ 0x0146 ] = 0xB1;	//	(nn+1)
*/

	//	LD IY, (nn)
/*
	devMemory->memory[ 0 ] 	= 0xFD;
	devMemory->memory[ 1 ] 	= 0x2A;
	devMemory->memory[ 2 ] 	= 0x45;		//	*n
	devMemory->memory[ 3 ] 	= 0x01;		//	n*
	devMemory->memory[ 0x0145 ] = 0x10;	//	(nn)
	devMemory->memory[ 0x0146 ] = 0x20;	//	(nn+1)
*/

	//	LD (nn), HL
/*
	*devMProc->Reg->HL		= 0x0102;
	devMemory->memory[ 0 ] 	= 0x22;
	devMemory->memory[ 1 ] 	= 0x45;		//	*n
	devMemory->memory[ 2 ] 	= 0x01;		//	n*
*/

	//	LD (nn), dd		;	SP -> (0x0130)
/*
	devMemory->memory[ 0 ] 	= 0xED;
	devMemory->memory[ 1 ] 	= 0b01000011 | 0b00110000;
	devMemory->memory[ 2 ] 	= 0x30;
	devMemory->memory[ 3 ] 	= 0x01;
*/

	//	LD (nn), IX
/*
	*devMProc->Reg->IX		= 0x0102;
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= 0x22;
	devMemory->memory[ 2 ] 	= 0x45;		//	*n
	devMemory->memory[ 3 ] 	= 0x01;		//	n*
*/

	//	LD (nn), IY
/*
	*devMProc->Reg->IY		= 0x0102;
	devMemory->memory[ 0 ] 	= 0xFD;
	devMemory->memory[ 1 ] 	= 0x22;
	devMemory->memory[ 2 ] 	= 0x10;		//	*n
	devMemory->memory[ 3 ] 	= 0x01;		//	n*
*/

	//	LD SP, HL
/*
	*devMProc->Reg->HL		= 0x0102;
	devMemory->memory[ 0 ] 	= 0xF9;
*/

	//	LD SP, IX
/*
	*devMProc->Reg->IX		= 0x0102;
	devMemory->memory[ 0 ] 	= 0xDD;
	devMemory->memory[ 1 ] 	= 0xF9;
*/

	//----------------------------------------------------------------------------------

	return NULL;
}

void *Init() {
	wndInit();

	return NULL;
}

//---------------------------------

void busShow( t_window* dsp ) {

	p_wlist r;
	p_slist	c;

	dsp->cursor.y = dsp->start.y;
	for ( r = p_all_wires; r != NULL; r=r->w_next ) {
		
		if ( r->Wire->visible == W_VISIBLE ) {
			dsp->cursor.x = dsp->start.x;
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%s: ", r->Wire->nome );
			dsp->cursor.x += 9;
			for ( c = r->Wire->stato->oldest ; c != NULL; c = c->s_next ) {

				if ( TSTBIT( c->flag, STATO_FLAG_LOW ) )
					mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "_" );

				if ( TSTBIT( c->flag, STATO_FLAG_HIGH ) )
					mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "'" );

				if ( TSTBIT( c->flag, STATO_FLAG_RAISE ) )
					mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "/" );

				if ( TSTBIT( c->flag, STATO_FLAG_FALL ) )
					mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "\\" );

				//mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%d", c->valore );
				dsp->cursor.x += 1;

			}
			dsp->cursor.y++;
		}
	}

	wrefresh( dsp->wnd );
}

void gatesShow( t_window* dsp ) {
	p_glist g;
	char c;
	
	dsp->cursor.y = dsp->start.y;
	c = 0;
	for ( g = devMProc->dev->pGates; g != NULL; g=g->g_next ) {
		if ( c == 4 ) {
			c = 0;
			dsp->cursor.y++;
		}
		if ( c == 0 ) 
			dsp->cursor.x = dsp->start.x;
		
		mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%s: ", g->Gate->nome );
		dsp->cursor.x += 9;

		if ( g->Gate->gate_mode == GATEMODE_THREE_STATE || g->Gate->Wire == NULL ) {
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "-" );
		} else {
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%d", g->Gate->Wire->stato->att->valore );
		}
		dsp->cursor.x += 3;

		c++;

		wrefresh( dsp->wnd );
	}

	wrefresh( dsp->wnd );
}

void mprocShow( t_window* dsp ) {
	
	dsp->cursor.x = dsp->start.x;
	dsp->cursor.y = dsp->start.y;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "A : %02X B : %02X C : %02X D : %02X E : %02X H : %02X L : %02X ", *devMProc->Reg->A, *devMProc->Reg->B, *devMProc->Reg->C, *devMProc->Reg->D, *devMProc->Reg->E, *devMProc->Reg->H, *devMProc->Reg->L );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "A': %02X B': %02X C': %02X D': %02X E': %02X H': %02X L': %02X ", *devMProc->Reg->_A, *devMProc->Reg->_B, *devMProc->Reg->_C, *devMProc->Reg->_D, *devMProc->Reg->_E, *devMProc->Reg->_H, *devMProc->Reg->_L );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "F : %02X F': %02X ", *devMProc->Reg->F, *devMProc->Reg->_F );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "I : %02X R : %02X ", *devMProc->Reg->I, *devMProc->Reg->R );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "PC: %04X SP: %04X IX: %04X IY: %04X ", *devMProc->Reg->PC, *devMProc->Reg->SP, *devMProc->Reg->IX, *devMProc->Reg->IY );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "AF: %04X BC: %04X DE: %04X HL: %04X ", *devMProc->Reg->AF, *devMProc->Reg->BC, *devMProc->Reg->DE, *devMProc->Reg->HL );
	dsp->cursor.y++;
	mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "OP_CODE : %02X T_CYCLE: %02X M_CYCLE: %s", *devMProc->Op->Code, (devMProc->Cycle->t>>1)+1, ( (devMProc->Cycle->m == M_CYCLE_FETCH && devMProc->Cycle->m <= M_CYCLE_M1) ? "FETCH" : (devMProc->Cycle->m == M_CYCLE_M2 ? "M2   " : (devMProc->Cycle->m == M_CYCLE_M3 ? "M3   " : "     ") ) ) );

	wrefresh( dsp->wnd );
}

void memoryShow( t_window* dsp ) {

	dt_8bit 	r	= 0;
	dt_8bit		c	= 0;
	dt_16bit	ad	= 0;

	ad	= 0x0000;
	dsp->cursor.y = dsp->start.y;
	for ( r = 0; r < 1; r++ ) {
		
		dsp->cursor.x = dsp->start.x;
		for ( c = 0 ; c < 16; c++ ) {

			if ( c==0 ) {
				mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%04X: ", ad );
				dsp->cursor.x += 6;
			}

			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%02X", devMemory->memory[ ad ] );
			dsp->cursor.x += 3;

			ad++;
		}
		dsp->cursor.y++;
		
	}

	ad	= 0x0100;
	dsp->cursor.y++;
	for ( r = 0; r < 8; r++ ) {

		dsp->cursor.x = dsp->start.x;
		for ( c = 0 ; c < 16; c++ ) {

			if ( c==0 ) {
				mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%04X: ", ad );
				dsp->cursor.x += 6;
			}

			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%02X", devMemory->memory[ ad ] );
			dsp->cursor.x += 3;

			ad++;
		}
		dsp->cursor.y++;

	}
	wrefresh( dsp->wnd );
}

//---------------------------------

int main( int argc, char *argv[] ) {

//	p_gate g0;
//	p_gate g1;
//	p_wire w_reset, w_clock;
//	p_bus  b_signals;

	//------------------------------------------------------------------------
	//	Callback Init

	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) Init );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) boardInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) PowerInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) ClockInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) ResetInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) MProcInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) MemoryInit );
	lfunct_accoda( &p_all_inits, (FN_VOID_VOID) Programma );
	
	p_ListFunct p_fList;
	for ( p_fList = p_all_inits; p_fList != NULL; p_fList = p_fList->nList ) {
		p_fList->fFunc();
	}

	//------------------------------------------------------------------------
	//	Callback self connect

	lfunct_accoda( &p_all_self_connect, (FN_VOID_VOID) devPower->self_connect );
	lfunct_accoda( &p_all_self_connect, (FN_VOID_VOID) devMProc->self_connect );
	lfunct_accoda( &p_all_self_connect, (FN_VOID_VOID) devMemory->self_connect );

	for ( p_fList = p_all_self_connect; p_fList != NULL; p_fList = p_fList->nList ) {
		p_fList->fFunc();
	}

	//------------------------------------------------------------------------
	//	Callback task

	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) all_wires_add_tick );
//	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) devPower->task );
//	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) devReset->task );
	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) devClock->task );
	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) devMProc->task );
	lfunct_accoda( &p_all_tasks, (FN_VOID_VOID) devMemory->task );

	//------------------------------------------------------------------------
	//	Visualizzazione
	//lFnDisp_accoda( &p_all_display, *(gatesShow)(&pWindows->Bus) );
	devMProc->mp_gate[ MP__CLOCK ]->Wire->visible 	= W_VISIBLE;
	//devMProc->mp_gate[ MP_VCC ]->Wire->visible 		= W_VISIBLE;
	//devMProc->mp_gate[ MP_GND ]->Wire->visible 		= W_VISIBLE;
	//devMProc->mp_gate[ MP__RESET ]->Wire->visible 	= W_VISIBLE;	
	devMProc->mp_gate[ MP__M1 ]->Wire->visible 		= W_VISIBLE;
	devMProc->mp_gate[ MP__MREQ ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP__RD ]->Wire->visible 		= W_VISIBLE;
	devMProc->mp_gate[ MP__WR ]->Wire->visible 		= W_VISIBLE;
	
	devMProc->mp_gate[ MP_Data_00 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_01 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_02 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_03 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_04 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_05 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_06 ]->Wire->visible 	= W_VISIBLE;
	devMProc->mp_gate[ MP_Data_07 ]->Wire->visible 	= W_VISIBLE;
	
	//------------------------------------------------------------------------
	//	Board

	//b_signals = new_bus( "SIGNALS", NULL );
	//bus_add_wire( b_signals,  devClock->w_clock );

	//------------------------------------------------------------------------
	//	Esecuzione procedure

	while ( 1 ) {

		for ( p_fList = p_all_tasks; p_fList != NULL; p_fList = p_fList->nList ) {
			p_fList->fFunc();
		}

		mprocShow( &pWindows->MProc );
#ifdef _C_CYGWIN
		busShow( &pWindows->Bus );
//		gatesShow( &pWindows->Gates );
		memoryShow( &pWindows->Memory );
#endif
		
		sleepMs(200);
	}

	//------------------------------------------------------------------------
	//	FINE

	return 0;

}