#ifndef _OP_CODES

#define _OP_CODES

typedef void (*FN_OP_CODE)(void);

typedef unsigned char 		dt_8bit;
typedef unsigned short int 	dt_16bit;

typedef struct s_op_code 	t_op_code;
typedef struct s_op_code*	p_op_code;

struct s_op_code {
	dt_8bit		code;
	dt_8bit		oper_1;
	dt_8bit		oper_2;
	dt_8bit		*pR;				//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	dt_8bit		*pR1;				//	Memorizzo l'indirizzo di memoria dei registri da utilizzare durante la cedodifica dell' OPCODE ecc (Puntatore a registri)
	dt_16bit	pA;					//	Memorizzo un valore a 16 bit
	FN_OP_CODE	f_op_code;			//	funzione che implementa l'operazione corrispondente all' op-code da eseguire
};

#define REG_A	0b111
#define REG_B	0b000
#define REG_C	0b001
#define REG_D	0b010
#define REG_E	0b011
#define REG_H	0b100
#define REG_L	0b101

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

//------------------------------

#define	OP_REG_R( r ) ( r << 3 )
#define	OP_REG_R1( r ) ( r )

#define OP_CODE( o ) ( o )
//	OP_CODE_R( o , r ) => oorrrooo
#define OP_CODE_R( o , r ) ( o | OP_REG_R( r ) )
//	OP_CODE_R1( o , s ) => ooooosss
#define OP_CODE_R1( o , s ) ( o | OP_REG_R1( s ) )
//	OP_CODE_R_R1( o , r , s ) => oorrrsss
#define OP_CODE_R_R1( o , r , s ) ( o | OP_REG_R( r ) | OP_REG_R1( s ) )

#define OP_EXCLUDE_RES_R( o ) ( ( o & 0b111000 ) != 0b110000 )
#define OP_EXCLUDE_RES_R1( o ) ( ( o & 0b111 ) != 0b110 )

#endif