#ifndef _OP_CODES

#define _OP_CODES

#define REG_A	0b111
#define REG_B	0b000
#define REG_C	0b001
#define REG_D	0b010
#define REG_E	0b011
#define REG_H	0b100
#define REG_L	0b101

#define OP_AM_LD_R_R	0b11000000
#define OP_EM_LD_R_R	0b01000000

#define OP_AM_LD_R_N	0b11000111
#define OP_EM_LD_R_N	0b00000110

#define OP_AM_LD_R_HL	0b11000111
#define OP_EM_LD_R_HL	0b01000110

#define	OP_REG_R( r ) ( r << 3 )
#define	OP_REG_R1( r ) ( r )

#define OP_CODE( o ) ( o )
#define OP_CODE_R( o , r ) ( o | OP_REG_R( r ) )
#define OP_CODE_R_R1( o , r , r1 ) ( o | OP_REG_R( r ) | OP_REG_R1( r1 ) )

#define OP_EXCLUDE_RES_R( o ) ( ( o & 0b111000 ) != 0b110000 )
#define OP_EXCLUDE_RES_R1( o ) ( ( o & 0b111 ) != 0b110 )

typedef unsigned char 		dt_8bit;
typedef unsigned short int 	dt_16bit;

#endif