#ifndef _WINDOW

#define _WINDOW

#ifdef __MINGW32__
#include <ncursest/ncurses.h>
#else
#include <curses.h>
#endif

typedef struct {
	char	x;
	char	y;
} t_coord;

typedef struct {
	WINDOW* wnd;
	t_coord	position;
	t_coord	size;
	t_coord	cursor;
	t_coord	start;
	t_coord	end;
} t_window;

typedef t_window* p_window;

void wndInitWindow( p_window W, p_window P, char px, char py, char sx, char sy );

#endif