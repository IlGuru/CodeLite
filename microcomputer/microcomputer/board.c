#include "./board.h"

//-------------------------
//	STATI

void *slist_flags( p_slist pLAtt ) {
	
	p_slist pLPrev	= NULL;
	
	if ( pLAtt != NULL ) {
		
		pLAtt->flag = 0;
		
		if ( pLAtt->valore == STATO_VAL_MIN )
			SETBIT( pLAtt->flag , STATO_FLAG_LOW );
		if ( pLAtt->valore == STATO_VAL_MAX )
			SETBIT( pLAtt->flag , STATO_FLAG_HIGH );

		if ( pLAtt->s_prev != NULL ) {
			pLPrev = pLAtt->s_prev;
			if ( pLPrev->valore  < pLAtt->valore )
				SETBIT( pLAtt->flag , STATO_FLAG_RAISE );
			if ( pLPrev->valore == pLAtt->valore )
				SETBIT( pLAtt->flag , STATO_FLAG_EQUAL );
			if ( pLPrev->valore  > pLAtt->valore )
				SETBIT( pLAtt->flag , STATO_FLAG_FALL );
		}
		
	}
	
	return NULL;
}

void *slist_set( p_slist pSlist, tValStato valore ) {			//	Scrive il valore dello stato nel nodo dalla lista
	pSlist->valore = valore;

	slist_flags( pSlist );
	
	return NULL;
}

void *slist_del( p_slist pSlist ) {								//	Elimina il nodo dalla lista collegando tra loro precedente e successivo
	p_slist p_sprev;
	p_slist p_snext;

	p_sprev  = pSlist->s_prev;
	p_snext  = pSlist->s_next;
	free( pSlist );
	if ( p_sprev != NULL ) 
		p_sprev->s_next = p_snext;
	if ( p_snext != NULL ) 
		p_snext->s_prev = p_sprev;

	return NULL;
}

void *slist_add( p_slist *pListaStati ) {						//	Aggiunge un nuovo stato e ne accoda il precedente
	p_slist pSlist;
	pSlist = malloc( sizeof(t_slist) );

	pSlist->flag 		= 0;
	pSlist->s_next		= NULL;
	if ( *pListaStati == NULL ) {
		pSlist->hist_pos		= STATO_ENTRIES_MIN;
		pSlist->s_prev			= NULL;
		slist_set( pSlist, STATO_VAL_MIN );
	} else {
		pSlist->s_prev = *pListaStati;
		if ( pSlist->s_prev != NULL ) {
			pSlist->s_prev->s_next	= pSlist;
			pSlist->hist_pos		= pSlist->s_prev->hist_pos + 1;
			slist_set( pSlist, pSlist->s_prev->valore );
		} else {
			pSlist->hist_pos		= STATO_ENTRIES_MIN;
			slist_set( pSlist, STATO_VAL_MIN );
		}
	}

	*pListaStati = pSlist;

	return NULL;
}

p_stato stato_new() {											//	Crea un nuovo stato
	p_stato pStato;
	pStato = malloc( sizeof(t_stato) );

	pStato->att			= NULL;
	slist_add( &pStato->att );									//	Puntatore al nodo attuale della lista e creazione del primo nodo
	pStato->oldest		= pStato->att;							//	Puntatore all'ultimo nodo della lista
	pStato->entries		= 1;									//	Numero di nodi

	return pStato;
}

void *stato_add( p_stato pStato ) {								//	Aggiunta di un valore allo stato
	slist_add( &pStato->att );
	pStato->entries++;

	return NULL;
}

void *stato_del_last( p_stato pStato ) {						//	Eliminazione dell'ultimo stato
	p_slist p_snewoldest;

	p_snewoldest 	= pStato->oldest->s_next;
	slist_del( pStato->oldest );
	pStato->oldest = p_snewoldest;
	pStato->entries--;

	return NULL;
}

//-------------------------
//	WIRES

char wlist_node_exists( p_wlist pWList, p_wire pWire ) {
	p_wlist pWStart = NULL;
	if ( pWList != NULL && pWire != NULL) {
		pWStart = pWList;
		while ( pWList->w_next != NULL && pWList->w_next != pWStart ) {	//	Cerco la fine della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			pWList = pWList->w_next;
		}
		pWStart = pWList;
		while ( pWList != NULL && pWList->w_prev != pWStart ) {			//	Cerco l'inizio della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			if ( pWList->Wire == pWire )
				return 1;
				
			pWList = pWList->w_prev;
		}
	}
	return 0;
}

void *wlist_node_add( p_wlist *w_prev, p_wlist *w_next, p_wire pWire ) {
	p_wlist pWlist;

	if ( ( w_prev != NULL ) && ( wlist_node_exists( *w_prev, pWire ) != 0 ) )
		return NULL;
	if ( ( w_next != NULL ) && ( wlist_node_exists( *w_next, pWire ) != 0 ) )
		return NULL;
		
	pWlist = malloc( sizeof(t_wlist) );

	pWlist->Wire	= pWire;
	if ( w_prev != NULL ) {
		pWlist->w_prev 	= *w_prev;								//	Accodamento
		if ( pWlist->w_prev != NULL )
			pWlist->w_prev->w_next = pWlist;					//	Link dal precedente a questo
	} else {
		pWlist->w_prev	= NULL;
		*w_next         = pWlist;								//	Feedback
	}
	if ( w_next != NULL ) {
		pWlist->w_next 	= *w_next;								//	Impilamento
		if ( pWlist->w_next != NULL )
			pWlist->w_next->w_prev = pWlist;					//	Link dal successivo a questo
	} else {
		pWlist->w_next	= NULL;
		*w_prev         = pWlist;								//	Feedback
	}

	return NULL;
}

void *wlist_node_impila( p_wlist *wList, p_wire pWire ) {
	wlist_node_add( NULL, wList, pWire );

	return NULL;
}

void *wlist_node_accoda( p_wlist *wList, p_wire pWire ) {
	wlist_node_add( wList, NULL, pWire );

	return NULL;
}

void *wire_set_value( p_wire pWire, tValStato valore ) {		//	Scrive il valore nello stato attuale di wire
	//pWire->stato->att->valore = valore;
	slist_set( pWire->stato->att, valore );
	
	return NULL;
}

tValStato wire_get_value( p_wire pWire ) {						//	Legge il valore dello stato attuale di wire
	return pWire->stato->att->valore;
}

void *wire_add_stato( p_wire pWire ) {							//	Aggiunge una posizione nella history dello stato di wire
	stato_add( pWire->stato );
	
	return NULL;
}

void *wire_add_set( p_wire pWire, tValStato valore ) {			//	Aggiunge una posizione nella history dello stato di wire e ne scrive il valore nello stato attuale
	wire_add_stato( pWire );
	wire_set_value( pWire, valore );
	
	return NULL;
}

p_wire wire_new( char* nome, tValStato valore ) {				//	Crea un nuovo wire e ne scrive il valore attuale
	p_wire 	pWire;
	p_wlist pWlist;

	pWire = malloc( sizeof(t_wire) );

	pWire->nome 	= nome;
	pWire->stato   	= stato_new();
	pWire->visible	= W_INVISIBLE;
	pWire->gatelist	= NULL;
	wire_set_value( pWire, valore );

	if ( p_all_wires == NULL ) {								// Inizializza p_all_wires
		wlist_node_accoda( &p_all_wires, pWire );
	} else {
		pWlist = p_all_wires;
		while ( pWlist->w_next != NULL ) {						// Cerco l'ultimo nodo della lista
			pWlist = pWlist->w_next;
		}
		wlist_node_accoda( &pWlist, pWire );
	}

	return pWire;
}

p_wire wire_get( char *nome, p_wlist pWlist ) {					//	Cerca un wire da una lista ( p_all_wires )
	if ( pWlist == NULL )
		pWlist = p_all_wires;

	while ( pWlist != NULL ) {
		if  ( strcmp(pWlist->Wire->nome, nome)==0 )
			return pWlist->Wire;

		pWlist = pWlist->w_next;
	}

	return NULL;
}

//-------------------------
//	Sincronizzazione wires
void *all_wires_add_tick() {										//	Aggiunge uno stato copiandolo dal presendente su ogni wire mantenendoli sincronizzati
	p_wlist pWlist;
	p_wire  pWire;

	pWlist = p_all_wires;
	while ( pWlist != NULL ) {

		pWire	= pWlist->Wire;
		wire_add_stato( pWire );

		if ( pWire->stato->entries > STATO_ENTRIES_MAX )
			stato_del_last( pWire->stato );

		pWlist = pWlist->w_next;

	}
	
	return NULL;
}

void *all_wires_del_last_tick() {								//	Aggiunge uno stato copiandolo dal presendente su ogni wire mantenendoli sincronizzati
	p_wlist pWlist;
	p_wire  pWire;

	pWlist = p_all_wires;
	while ( pWlist != NULL ) {
		pWire			= pWlist->Wire;
		stato_del_last( pWire->stato );

		pWlist = pWlist->w_next;
	}
	
	return NULL;
}


//-------------------------
//	BUS

char blist_node_exists( p_blist pBList, p_bus pBus ) {
	p_blist pGStart = NULL;
	if ( pBList != NULL && pBus != NULL) {
		pGStart = pBList;
		while ( pBList->b_next != NULL && pBList->b_next != pGStart ) {	//	Cerco la fine della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			pBList = pBList->b_next;
		}
		pGStart = pBList;
		while ( pBList != NULL && pBList->b_prev != pGStart ) {			//	Cerco l'inizio della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			if ( pBList->Bus == pBus )
				return 1;
				
			pBList = pBList->b_prev;
		}
	}
	return 0;
}

void *blist_node_add( p_blist *b_prev, p_blist *b_next, p_bus pBus ) {
	p_blist pBList;

	if ( ( b_prev != NULL ) && ( blist_node_exists( *b_prev, pBus ) != 0 ) )
		return NULL;
	if ( ( b_next != NULL ) && ( blist_node_exists( *b_next, pBus ) != 0 ) )
		return NULL;
		
	pBList = malloc( sizeof(t_blist) );

	pBList->Bus		= pBus;
	if ( b_prev != NULL ) {
		pBList->b_prev 	= *b_prev;				//	Accodamento
		if ( pBList->b_prev != NULL )
			pBList->b_prev->b_next = pBList;	//	Link dal precedente a questo
	} else {
		pBList->b_prev	= NULL;
		*b_next         = pBList;				//	Feedback
	}
	if ( b_next != NULL ) {
		pBList->b_next 	= *b_next;				//	Impilamento
		if ( pBList->b_next != NULL )
			pBList->b_next->b_prev = pBList;	//	Link dal successivo a questo
	} else {
		pBList->b_next	= NULL;
		*b_prev         = pBList;				//	Feedback
	}

	return NULL;
}

void *blist_node_impila( p_blist *bList, p_bus pBus ) {
	blist_node_add( NULL, bList, pBus );

	return NULL;
}

void *blist_node_accoda( p_blist *bList, p_bus pBus ) {
	blist_node_add( bList, NULL, pBus );

	return NULL;
}


p_bus new_bus( char *nome, p_wire pWire ) {						//	Crea un nuovo BUS di wires
	p_bus	pBus;
	p_wlist	pWlist = NULL;
	p_blist	pBList = NULL;

	pBus 	= malloc( sizeof(t_bus) );
	pBus->nome 	= nome;

	if ( pWire != NULL )
		wlist_node_accoda( &pWlist, pWire );

	pBus->lWires	= pWlist;

	if ( p_all_buses == NULL ) {								// Inizializza p_all_buses
		blist_node_accoda( &p_all_buses, pBus );
	} else {
		pBList = p_all_buses;
		while ( pBList->b_next != NULL ) {						// Cerco l'ultimo nodo della lista
			pBList = pBList->b_next;
		}
		blist_node_accoda( &pBList, pBus );
	}

	return pBus;
}

/*
p_wire bus_get_wire( p_bus pBus, char *nome ) {					//	Cerca un wire in un bus
	p_wlist pWlist;
	if ( pBus != NULL ) {
		if ( pBus->pWires != NULL ) {
			pWlist = pBus->pWires;
			while ( pWlist != NULL ) {
				if  ( strcmp(pWlist->pWire->nome, nome)==0 )
					return pWlist->pWire;

				pWlist = pWlist->w_next;
			}
		}
	}
	return NULL;
}
*/

void *bus_add_wire( p_bus pBus,  p_wire pWire ) {				//	Aggiunge un wire al bus

	p_wlist pWlist;

	if ( pBus != NULL ) {

		if ( pBus->lWires == NULL ) {
			wlist_node_accoda( &pBus->lWires, pWire );
		} else {
			pWlist = pBus->lWires;
			while ( pWlist->w_next != NULL ) {							// Cerco l'ultimo nodo della lista
				pWlist = pWlist->w_next;
			}
			wlist_node_accoda( &pWlist, pWire );						//	Aggiungo il nuovo nodo alla fine della lista
		}

	}
	
	return NULL;
}

//-------------------------
//	GATES

char glist_node_exists( p_glist pGList, p_gate pGate ) {
	p_glist pGStart = NULL;
	if ( pGList != NULL && pGate != NULL) {
		pGStart = pGList;
		while ( pGList->g_next != NULL && pGList->g_next != pGStart ) {	//	Cerco la fine della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			pGList = pGList->g_next;
		}
		pGStart = pGList;
		while ( pGList != NULL && pGList->g_prev != pGStart ) {			//	Cerco l'inizio della lista prevenendo la possibilità di loopare all'infinito su liste cicliche.
			if ( pGList->Gate == pGate )
				return 1;
				
			pGList = pGList->g_prev;
		}
	}
	return 0;
}

void *glist_node_add( p_glist *g_prev, p_glist *g_next, p_gate pGate ) {
	p_glist pGlist;

	if ( ( g_prev != NULL ) && ( glist_node_exists( *g_prev, pGate ) != 0 ) )
		return NULL;
	if ( ( g_next != NULL ) && ( glist_node_exists( *g_next, pGate ) != 0 ) )
		return NULL;
		
	pGlist = malloc( sizeof(t_glist) );

	pGlist->Gate	= pGate;
	if ( g_prev != NULL ) {
		pGlist->g_prev 	= *g_prev;								//	Accodamento
		if ( pGlist->g_prev != NULL )
			pGlist->g_prev->g_next = pGlist;					//	Link dal precedente a questo
	} else {
		pGlist->g_prev	= NULL;
		*g_next         = pGlist;								//	Feedback
	}
	if ( g_next != NULL ) {
		pGlist->g_next 	= *g_next;								//	Impilamento
		if ( pGlist->g_next != NULL )
			pGlist->g_next->g_prev = pGlist;					//	Link dal successivo a questo
	} else {
		pGlist->g_next	= NULL;
		*g_prev         = pGlist;								//	Feedback
	}

	return NULL;
}

void *glist_node_impila( p_glist *gList, p_gate pGate ) {
	glist_node_add( NULL, gList, pGate );

	return NULL;
}

void *glist_node_accoda( p_glist *gList, p_gate pGate ) {
	glist_node_add( gList, NULL, pGate );

	return NULL;
}

p_gate gate_new( char* nome, p_device ParentDevice, t_gatemode gatemode, char pin, p_wire pWire ) {				//	Crea un nuovo wire e ne scrive il valore attuale
	p_gate 	pGate;
	p_glist pGlist;

	pGate = malloc( sizeof(t_gate) );

	pGate->nome 		= nome;
	pGate->Device		= ParentDevice;
	pGate->pin 			= pin;
	if ( pWire != NULL ) {
		gate_connect( pGate, pWire );
	} else {
		pGate->Wire	= NULL;
	}
	gate_set_state( pGate, gatemode );

	if ( p_all_gates == NULL ) {								// Inizializza p_all_gates
		glist_node_accoda( &p_all_gates, pGate );
	} else {
		pGlist = p_all_gates;
		while ( pGlist->g_next != NULL ) {						// Cerco l'ultimo nodo della lista
			pGlist = pGlist->g_next;
		}
		glist_node_accoda( &pGlist, pGate );
	}

	return pGate;
}

void *gate_connect( p_gate pGate, p_wire pWire ) {
	if ( pGate != NULL && pWire != NULL ) {
		pGate->Wire 	= pWire;
		glist_node_accoda( &pWire->gatelist, pGate );
	}
	
	return NULL;
}

t_gatemode gate_check_output( p_gate pGate ) {
	p_glist gList;

	if ( pGate == NULL )
		return GATEMODE_ERR;
	if ( pGate->gate_mode != GATEMODE_OUTPUT )
		return GATEMODE_ERR;

	if ( pGate->Wire != NULL ) {

		gList = pGate->Wire->gatelist;
		while ( gList != NULL ) {

			if ( gList->Gate != pGate && gList->Gate->gate_mode == GATEMODE_OUTPUT )	//	Se un altro gate collegato al wire è output segnalo conflitto
				return GATEMODE_ERR;

			gList = gList->g_prev;

		}

	}

	return GATEMODE_OUTPUT;
}

void *gate_set_state( p_gate pGate, t_gatemode gatemode ) {

	if ( pGate != NULL ) {
		pGate->gate_mode = gatemode;
	}

	if ( pGate->gate_mode == GATEMODE_OUTPUT )					//	Se è OUTPUT e ci sono conflitti sulla linea collegata metto THREE_STATE
		if ( gate_check_output( pGate ) == GATEMODE_ERR )
			pGate->gate_mode = GATEMODE_THREE_STATE;

	return NULL;
}

t_gatemode gate_get_state( p_gate pGate ) {
	if ( pGate != NULL ) {
		return pGate->gate_mode;
	}
	return GATEMODE_ERR;
}

void *gate_set_val( p_gate pGate, tValStato val ) {
	if ( pGate != NULL ) {
		if ( pGate->Wire != NULL ) {
			wire_set_value( pGate->Wire, val );
		}
	}

	return NULL;
}

tValStato gate_get_val( p_gate pGate ) {
	if ( pGate != NULL ) {
		if ( pGate->Wire != NULL ) {
			return wire_get_value( pGate->Wire );
		}
	}
	return 255;
}

//-------------------------
//	CALLBACK FUNCTIONS

void *lfunct_accoda( p_ListFunct *p_fList, FN_VOID_VOID fFunct ) {
	p_ListFunct p_Funct, p_Node;

	p_Funct = malloc( sizeof(t_ListFunct) );	//	Ultimo nodo della lista
	p_Funct->fFunc = fFunct;
	p_Funct->nList = NULL;

	if ( *p_fList == NULL ) {
		*p_fList = p_Funct;
	} else {
		p_Node = *p_fList;
		while ( p_Node->nList != NULL ) {
			p_Node = p_Node->nList;
		}
		p_Node->nList = p_Funct;
	}
	
	return NULL;
}

/*
void *lFnDisp_accoda( p_LFnDisp *p_fList, FN_VOID_DISP fFunct ) {
	p_ListFunct p_Funct, p_Node;

	p_Funct = malloc( sizeof(t_LFnDisp) );	//	Ultimo nodo della lista
	p_Funct->fFunc = fFunct;
	p_Funct->nList = NULL;

	if ( *p_fList == NULL ) {
		*p_fList = p_Funct;
	} else {
		p_Node = *p_fList;
		while ( p_Node->nList != NULL ) {
			p_Node = p_Node->nList;
		}
		p_Node->nList = p_Funct;
	}
	
	return NULL;
}
*/

//-------------------------
//	INIT

void *boardInit() {
	
	p_all_wires 		= NULL;
	p_all_gates 		= NULL;

	p_all_self_connect	= NULL;
	p_all_tasks			= NULL;
	
	return NULL;
}
