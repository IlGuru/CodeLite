#include "./bus.h"

void busInit() {
	//p_bus = malloc( sizeof( t_bus )*SIG_HIST );
	
	//CLRBIT(p_bus->_b_signals,SIG_RESET);
	//CLRBIT(p_bus->_b_signals,SIG_CLOCK);
	char i;
	for ( i=0; i<SIG_HIST; i++ ) {
		p_bus[i]._b_signals	= '\0';
		p_bus[i]._data 		= '\0';
		p_bus[i]._lma		= '\0';
		p_bus[i]._hma		= '\0';
		busSigName[i]		= '\0';
	}
	busSigName[SIG_BASE + SIG_RESET]= "RESET\0";
	busSigName[SIG_BASE + SIG_CLOCK]= "CLOCK\0";
	busSigName[DATA_BASE+ DATA_0] 	= "D0\0";
	busSigName[DATA_BASE+ DATA_1] 	= "D1\0";
	busSigName[DATA_BASE+ DATA_2] 	= "D2\0";
	busSigName[DATA_BASE+ DATA_3] 	= "D3\0";
	busSigName[DATA_BASE+ DATA_4] 	= "D4\0";
	busSigName[DATA_BASE+ DATA_5] 	= "D5\0";
	busSigName[DATA_BASE+ DATA_6] 	= "D6\0";
	busSigName[DATA_BASE+ DATA_7] 	= "D7\0";
}

void busDoReset() {
	SETBIT(p_bus->_b_signals,SIG_RESET);
}

void busReset() {
	if ( TSTBIT(p_bus->_b_signals,SIG_RESET) )
		CLRBIT(p_bus->_b_signals,SIG_RESET);
}

void busClock() {
	TGLBIT(p_bus->_b_signals,SIG_CLOCK);
}

void busTick() {
	char c;
	
	for ( c = SIG_HIST-1; c > 0; c-- ) {
		p_bus[c] = p_bus[c-1];
	}
	
	busReset();
	busClock();
}

char busLevel( char bit ) {
	if ( bit ) {
		return '^';
	} else {
		return '_';
	}
}
void busShow( t_window* dsp ) {

	char r,c,bith,bitl,bitv,do_print;
	
	dsp->cursor.y = dsp->start.y;
	for ( r = 0; r < BUS_NUM; r++ ) {
		bith = r & 0b11111000;
		bitl = r & 0b00000111;
		dsp->cursor.x = dsp->start.x;
		if ( r==0 ) {
			dsp->cursor.y = dsp->start.y;
		}
		if ( busSigName[r] != '\0' ) {
			mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%s: ", busSigName[r] );
			dsp->cursor.x += 7;
			do_print = 1;
		} else {
			do_print = 0;
		}
		if ( do_print ) {
			for ( c = 0; c < SIG_HIST; c++ ) {

				switch ( bith ) {
					case SIG_BASE:
						bitv = busLevel( TSTBIT(p_bus[SIG_HIST-c-1]._b_signals,	bitl) );
						break;
					case DATA_BASE:
						bitv = busLevel( TSTBIT(p_bus[SIG_HIST-c-1]._data,		bitl) );
						break;
					case LMA_BASE:
						bitv = busLevel( TSTBIT(p_bus[SIG_HIST-c-1]._lma,		bitl) );
						break;
					case HMA_BASE:
						bitv = busLevel( TSTBIT(p_bus[SIG_HIST-c-1]._hma,		bitl) );
						break;
					default:
						break;
				}
				mvwprintw( dsp->wnd, dsp->cursor.y , dsp->cursor.x, "%c", bitv );
				dsp->cursor.x += 1;
			}
			dsp->cursor.y++;
		}
	}
	wrefresh( dsp->wnd );
}