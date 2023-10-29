
#ifndef OCTETOS_OCC_V1_A_HH
#define OCTETOS_OCC_V1_A_HH


/*
 * main.cc
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include <iostream>

#include "occ.hh"


namespace oct::cc::v1::A
{
	namespace core_here = oct::core::v3;
	namespace core = oct::core::v3;


	enum class Tokens : int
	{//https://www.charset.org/utf-8,https://www.asciitable.com/,https://www.rapidtables.com/code/text/ascii-table.html
		command = -100,
		eoi,//end of input
		none,
		//ASCII>>>
		NUL = 0,
		SOH,
		STX,
		ETX,
		EOT,
		ENQ,
		ACK,
		BEL,
		BS,
		TAB,
		LF,
		VT,
		FF,
		CR,
		SO,
		SIC,//SI control char
		DLE,
		DC1,
		DC2,
		DC3,
		DC4,
		NAK,
		SYN,
		ETB,
		CAN,
		EM,
		SUBSTITUTE,
		ESCC,//ESC control char
		FS,
		GS,
		RS,
		US = 31,
		space,
		exclamation_mark,
		double_quote,
		symbol_numbers,
		symbol_money,
		percen,
		ampersan,
		single_quote,
		parenthesis_open,
		parenthesis_close,
		asterisk,
		plus,
		minus,
		dot,
		symbol_diagonal,
		digit_0 = 48,
		digit_1,
		digit_2,
		digit_3,
		digit_4,
		digit_5,
		digit_6,
		digit_7,
		digit_8,
		digit_9,
		symbol_column,
		semicolumn,
		less,
		equal,
		grater,
		question,
		arroba,
		//>>upper case
		char_A = 65,
		char_B,
		char_C,
		char_D,
		char_E,
		char_F,
		char_G,
		char_H,
		char_I,
		char_J,
		char_K,
		char_L,
		char_M,
		char_N,
		char_O,
		char_P,
		char_Q,
		char_R,
		char_S,
		char_T,
		char_U,
		char_V,
		char_W,
		char_X,
		char_Y,
		char_Z,
		//>>
		brackets_open,
		diagonal_inverted,
		brackets_close,
		hat,
		guion_down,
		//>>>
		char_a = 97,
		char_b,
		char_c,
		char_d,
		char_e,
		char_f,
		char_g,
		char_h,
		char_i,
		char_j,
		char_k,
		char_l,
		char_m,
		char_n,
		char_o,
		char_p,
		char_q,
		char_r,
		char_s,
		char_t,
		char_u,
		char_v,
		char_w,
		char_x,
		char_y,
		char_z,
		curly_brackets_open,
		bar,
		curly_brackets_close,
		umlaut,
		EuroSign = 218,
		//>>>Extended ASCII






		y_Diaeresis = 255,//ÿ
		//>>>UTF-8
		a_Macron = 256,

		s_Coptic = 999,
		//Inicode >>>


		//>>>Tokens
		base = 0x110000,

		//C-keywords
		AUTO = 110200,
		BREAK = 110202,
		CASE,
		CHAR,
		CONST,
		CONTINUE,
		DEFAULT,
		DO,
		DOUBLE,
		ELSE,
		ENUM,
		EXTERN,
		FLOAT,
		FOR,
		GOTO,
		IF,
		INT,
		LONG,
		REGISTER,
		RETURN,
		SHORT,
		SIGNED,
		SIZEOF,
		STATIC,
		STRUCT,
		SWITCH,
		TYPEDEF,
		UNION,
		UNSIGNED,
		VOID,
		VOLATIL,
		WHILE,

		//Intel instruction set
		AAA,
		AAD,
		AAM,
		AAS,
		ADC,
		ADD,
		AND,
		CALL,
		CBW,
		CLC,
		CLD,
		CLI,
		CMC,
		CMP,
		CMPS,
		CWD,
		DAA,
		DAS,
		DEC,
		DIV,
		ESC,
		HLT,
		IDIV,
		IMUL,
		IN,
		INC,
		INTR,
		INTO,
		IRET,
		JA,
		JNBE,
		JAE,
		JNB,
		JB,
		JNAE,
		JBE,
		JNA,
		JC,
		JCXZ,
		JE,
		JZ,
		JG,
		JNLE,
		JGE,
		JNL,
		JL,
		JNGE,
		JLE,
		JNG,
		JMP,
		JNC,
		JNE,
		JNZ,
		JNO,
		JNP,
		JPO,
		JNS,
		JO,
		JP,
		JPE,
		JS,
		LAHF,
		LDS,
		LEA,
		LES,
		LOCK,
		LODS,
		LOOP,
		LOOPE,
		LOOPNE,
		NMI,
		MOV,
		MOVS,
		MOVSB,
		MOVSW,
		MUL,
		NEG,
		NOP,
		NOT,
		OR,
		OUT,
		POP,
		POPF,
		PUSH,
		PUSHF,
		RCL,
		RCR,
		REPE,
		REPZ,
		REPNE,
		REPNZ,
		RET,
		ROL,
		ROR,
		SAHF,
		SAL,
		SHL,
		SAR,
		SBB,
		SCAS,
		SEGMENT,
		SHR,
		SINGLE,
		STEP,
		STC,
		STD,
		STI,
		STOS,
		SUB,
		TEST,
		WAIT,
		XCHG,
		XLAT,
		XORG,

		//intel registers
		AL,
		AH,
		AX,
		BL,
		BH,
		BX,
		CL,
		CH,
		CX,
		DL,
		DH,
		DX,

		//Ponters
		SP,
		BP,
		SI,
		DI,

		//Segments
		CS,
		DS,
		SS,
		ES,

        BYTE,
		TINY,

		//consttantes
		CONSTANT_INTEGER_DEC_8b,
		CONSTANT_INTEGER_DEC_16b,
		CONSTANT_INTEGER_DEC,
		LITERAL_INTEGER_DEC_SCHAR,
		LITERAL_INTEGER_DEC_UCHAR,
		LITERAL_INTEGER_DEC_SHORT,
		LITERAL_INTEGER_DEC_USHORT,
		LITERAL_INTEGER_DEC_INT,
		LITERAL_INTEGER_DEC_UINT,
		LITERAL_INTEGER_DEC_LONG,
		LITERAL_INTEGER_DEC_ULONG,
		LITERAL_INTEGER_DEC_LONGLONG,
		LITERAL_INTEGER_DEC_ULONGLONG,
		CONSTANT_INTEGER_HEX,
		CONSTANT_INTEGER_HEX_8b,
		CONSTANT_INTEGER_HEX_16b,
		LITERAL_INTEGER_HEX_SCHAR,
		LITERAL_INTEGER_HEX_UCHAR,
		LITERAL_INTEGER_HEX_SHORT,
		LITERAL_INTEGER_HEX_USHORT,
		LITERAL_INTEGER_HEX_INT,
		LITERAL_INTEGER_HEX_UINT,
		LITERAL_INTEGER_HEX_LONG,
		LITERAL_INTEGER_HEX_ULONG,
		CONSTANT_INTEGER_OCT,
		CONSTANT_CHAR,
		LITERAL_STRING,
		//LITERAL_FLOAT,
		//LITERAL_DOUBLE,
		//LITERAL_LONGDOUBLE,

		//new_line,

		identifier,
		//integer,

	};


}


#endif
