#ifndef _BOARD

#define _BOARD

#include <stdlib.h>
#include <string.h>

//-------------------------

typedef struct s_slist 	t_slist;
typedef struct s_stato  t_stato;
typedef struct s_slist*	p_slist;
typedef struct s_stato* p_stato;

typedef struct s_wlist	t_wlist;
typedef struct s_wire 	t_wire;
typedef struct s_wlist*	p_wlist;
typedef struct s_wire* 	p_wire;

typedef struct s_blist	t_blist;
typedef struct s_bus   	t_bus;
typedef struct s_blist*	p_blist;
typedef struct s_bus*  	p_bus;

typedef struct s_glist 	t_glist;
typedef struct s_gate 	t_gate;
typedef struct s_glist*	p_glist;
typedef struct s_gate* 	p_gate;

//-------------------------

// -----------
//	STATI

#define STATO_MAX_HIST	32

typedef char 		tValStato;
typedef short int 	tDimHistory;

struct s_stato {
	p_slist			att;		//	Stato attuale
	p_slist			oldest;		//	Stato più vecchio ( ->s_next == NULL )
	char			entries;
};

struct s_slist {
	tValStato		valore;
	tDimHistory		hist_pos;
	p_slist			s_prev;
	p_slist			s_next;
};

// -----------
//	WIRES

p_wlist	p_all_wires;

struct s_wire {
	char 		*nome;		//	Nome linea
	p_stato  	stato;		//	Stato linea
	p_glist		gatelist;	//	LIsta di gates collegati
};

struct s_wlist {
	p_wire		Wire;		//	Linea
	p_wlist		w_prev;		//	Linea precedente
	p_wlist		w_next;		//	Linea successiva
};

// -----------
//	GATES

p_glist	p_all_gates;

typedef char t_gatemode;

#define GATEMODE_THREE_STATE	0
#define GATEMODE_INPUT			1
#define GATEMODE_OUTPUT			2
#define GATEMODE_ERR 			4

struct s_gate {
	char* 		nome;			//	Nome porta
	char		gate_mode;		//
	p_wire		Wire;			//	Linea collegata
};

struct s_glist {
	p_gate		Gate;			//	Porta
	p_glist		g_prev;			//	Porta precedente
	p_glist		g_next;			//	Porta successiva
};

// -----------
//	BUS

p_blist	p_all_buses;

struct s_blist {
	p_bus		Bus;			//	Bus
	p_blist		b_prev;			//	Bus precedente
	p_blist		b_next;			//	Bus successivo
};

struct s_bus {
	char* 		nome;			//	Nome bus
	p_wlist		lWires;			//	Lista linee del bus
};

// -----------
//	DEVICE

struct s_device {
	char* 		nome;		//	Nome dispositivo
	p_glist		p_gates;	//	Lista porte
};

//-------------------------

p_wire wire_new( char* nome, tValStato valore );

void wire_set_value( p_wire p_wire, tValStato valore );

tValStato wire_get_value( p_wire pWire );

void all_wires_add_tick();



p_bus new_bus( char *nome, p_wire pWire );

void bus_add_wire( p_bus pBus,  p_wire pWire );



p_gate gate_new( char* nome, t_gatemode gatemode, p_wire pWire );

void gate_connect( p_gate pGate, p_wire pWire );

t_gatemode gate_check_output( p_gate pGate );

void gate_set_state( p_gate pGate, t_gatemode gatemode );

void gate_set_val( p_gate pGate, tValStato val );

tValStato gate_get_val( p_gate pGate );

//-----------------------------------------------------------------
//	CALLBACK FUNCTIONS

typedef void (*FNINPUT)(void);

typedef struct s_ListFunct  t_ListFunct;

typedef struct s_ListFunct*	p_ListFunct;

struct s_ListFunct {
	FNINPUT		fFunc;
	p_ListFunct	nList;
};

p_ListFunct p_all_inits;
p_ListFunct p_all_tasks;

void lfunct_accoda( p_ListFunct *p_fList, FNINPUT fFunct );

//-------------------------
//	INIT

void *boardInit();

#endif
