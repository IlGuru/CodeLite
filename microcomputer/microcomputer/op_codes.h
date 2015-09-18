#ifndef _OP_CODES

#define _OP_CODES

//--------------------------------------

typedef unsigned char 		dt_8bit;
typedef unsigned char 		t_tcyle;
typedef unsigned char 		t_mcycle;
typedef unsigned short int 	dt_16bit;

typedef unsigned char 		t_reg;
typedef unsigned short int 	t_reg16;

typedef void (*FN_OP_CODE)(void);

typedef t_reg*				p_reg;
typedef t_reg16*			p_reg16;

typedef struct s_op_code 	t_op_code;
typedef struct s_op_code*	p_op_code;

typedef struct s_regind 	t_regind;
typedef struct s_regind*	p_regind;

//--------------------------------------

//	Struttura dati per memorizzare tutte le informazioni necessarie alla lettura, decodifica ed esecuzione dell' op code
struct s_op_code {
	t_tcyle			t_cycle;			//	T CYCLE
	t_mcycle		m_cycle;			//	M CYCLE
	dt_8bit			code;				//	OP CODE
	dt_8bit			oper_1;				//	PRIMO OPERANDO
	dt_8bit			oper_2;				//	SECONDO OPERANDO
	p_reg			pR;					//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	p_reg			pR1;				//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	dt_16bit		pA;					//	Memorizzo un valore a 16 bit
	FN_OP_CODE		f_op_code;			//	funzione che implementa l'operazione corrispondente all' op-code da eseguire
};

//	Struttura dati per l'indirizzamento indiretto.
struct s_regind {
	p_reg	h;
	p_reg	l;
};

//--------------------------------------

#define REG_A	0b111
#define REG_B	0b000
#define REG_C	0b001
#define REG_D	0b010
#define REG_E	0b011
#define REG_H	0b100
#define REG_L	0b101
#define REG_RES	0b110		//	REGISTRO RISERVATO
#define REG_BM  0b111		//	BITMASK PER I REGISTRI

//--------------------------------------

#define OP_AM_NOP		0b11111111
#define OP_EM_NOP 	    0b00000000

#define OP_AM_LD_R_R	0b11000000
#define OP_EM_LD_R_R	0b01000000

#define OP_AM_LD_R_N	0b11000111
#define OP_EM_LD_R_N	0b00000110

#define OP_AM_LD_R_HL	0b11000111
#define OP_EM_LD_R_HL	0b01000110

#define OP_AM_LD_DD		0b11111111
#define OP_EM_LD_DD 	0b11011101

#define OP_AM_LD_FD		0b11111111
#define OP_EM_LD_FD 	0b11111101

#define OP_AM_LD_HL_R	0b11111000
#define OP_EM_LD_HL_R	0b01110000

#define OP_AM_LD_HL_N	0b11111111
#define OP_EM_LD_HL_N	0b00110110

#define OP_AM_LD_A_BC	0xFF
#define OP_EM_LD_A_BC	0x0A

#define OP_AM_LD_A_DE	0xFF
#define OP_EM_LD_A_DE	0x1A

#define OP_AM_LD_A_NN	0xFF
#define OP_EM_LD_A_NN	0x3A

#define OP_AM_LD_BC_A	0xFF
#define OP_EM_LD_BC_A	0x02

#define OP_AM_LD_DE_A	0xFF
#define OP_EM_LD_DE_A	0x12

#define OP_AM_LD_NN_A	0xFF
#define OP_EM_LD_NN_A	0x32

//------------------------------

#define OP_SHIFT_3R( r ) ( r >> 3 )
#define OP_SHIFT_3L( r ) ( r << 3 )
#define OP_REG_BMASK( r ) ( r & 0b111 )
#define OP_SHIFT_3R_MASK( r ) ( OP_REG_BMASK( OP_SHIFT_3R( r ) ) )

//	r  nell' op code si trova in ccRRRccc
#define	OP_REG_R( r ) ( OP_SHIFT_3L( r ) )	
//	r1 nell' op code si trova in cccccRRR
#define	OP_REG_R1( r ) ( r )		

#define OP_CODE( o ) ( o )
//	OP_CODE_R( o , r ) => oorrrooo
#define OP_CODE_R( o , r ) ( o | OP_REG_R( r ) )
//	OP_CODE_R1( o , s ) => ooooosss
#define OP_CODE_R1( o , s ) ( o | OP_REG_R1( s ) )
//	OP_CODE_R_R1( o , r , s ) => oorrrsss
#define OP_CODE_R_R1( o , r , s ) ( o | OP_REG_R( r ) | OP_REG_R1( s ) )

#define OP_EXCLUDE_RES_R( o )  ( ( (  OP_SHIFT_3R( o ) ) & REG_BM ) != REG_RES )
#define OP_EXCLUDE_RES_R1( o ) ( (    o     & REG_BM ) != REG_RES )

//------------------------------

#define T_CYCLE_START	0
#define T_CYCLE_T1		1
#define T_CYCLE_T1_2	2
#define T_CYCLE_T2		3
#define T_CYCLE_T2_2	4
#define T_CYCLE_T3		5
#define T_CYCLE_T3_2	6
#define T_CYCLE_T4		7
#define T_CYCLE_T4_2	8
#define T_CYCLE_T5		9
#define T_CYCLE_T5_2	10
#define T_CYCLE_T6		11
#define T_CYCLE_T6_2	12
#define T_CYCLE_T7		13
#define T_CYCLE_T7_2	14

//--------------------------------------

#define M_CYCLE_FETCH	0	//	Stesso ciclo macchina
#define M_CYCLE_DECODE	1	//	Stesso ciclo macchina
#define M_CYCLE_EXECUTE	2	//	Stesso ciclo macchina
#define M_CYCLE_M1		3	//	Stesso ciclo macchina
#define M_CYCLE_M2		4
#define M_CYCLE_M3		5
#define M_CYCLE_M4		6
#define M_CYCLE_M5		7
#define M_CYCLE_M6		8
#define M_CYCLE_M7		9
#define M_CYCLE_NEXT	252	//	Per indicare di passare al prossimo ciclo macchina
#define M_CYCLE_END		253	//	Per indicare la fine di un' operazione

#define M_CYCLE_NULL	254

//--------------------------------------

#endif