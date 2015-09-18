#include "window.h"

void wndInitWindow( p_window W, p_window P, char px, char py, char sx, char sy ) {
	if ( P == NULL ) {
		
		W->wnd = initscr();
		noecho();
		curs_set(FALSE);

		W->position.x = 0;
		W->position.y = 0;
		getmaxyx(stdscr, W->size.y, W->size.x);
		
	} else {
	
		W->wnd = subwin( P->wnd, sy, sx, py, px );

		if ( W->wnd == NULL && P->wnd != NULL ) {
			W->wnd 			= P->wnd;
			W->position.x 	= P->position.x;
			W->position.y 	= P->position.y;
			W->size.x	  	= P->size.x;
			W->size.y	  	= P->size.y;
			mvwprintw( P->wnd, P->end.y , P->start.x, "Errore creazione subwindow. Utilizzo window parent." );
		} else {
			W->position.x 	= px;
			W->position.y 	= py;
			W->size.x	  	= sx;
			W->size.y	  	= sy;
		}
		
	}

	W->cursor.x = 1;
	W->cursor.y = 1;
	W->start.x = 1;
	W->start.y = 1;
	W->end.x = W->size.x - 1;
	W->end.y = W->size.y - 1;

	wclear( W->wnd );
	box( W->wnd, ACS_VLINE, ACS_HLINE );
	wrefresh( W->wnd );

}

