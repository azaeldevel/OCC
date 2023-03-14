
#ifndef OCTETOS_CC_AA_HH
#define OCTETOS_CC_AA_HH


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
#include <string>
#include <stdio.h>
#include <filesystem>
#include <list>

#include <core/3/math.hh>

namespace oct::core::v3
{

class Block
{
public:
	Block() : page_size(1024),actual(NULL),index(0)
	{
		actual = malloc(page_size);
		blocks.push_back(actual);
	}
	Block(size_t size) : page_size(size),actual(NULL),index(0)
	{
		actual = malloc(page_size);
		blocks.push_back(actual);		
	}
	~Block()
	{
		for(void* m : blocks)
		{
			free(m);
		}
	}

	template<typename T> T* create()
	{
		if(sizeof(T) + index >= page_size)
		{
			actual = malloc(page_size);
			blocks.push_back(actual);
			index = 0;			
		}

		T* obj = (T*) ((char*)actual + index);
		index += sizeof(T) + 1;		
		return obj;
	}
private:
	std::list<void*> blocks;
	size_t page_size;
	void* actual;//last block memory assignable
	size_t index;//firs posistion usable in actual block memory
	
};

}


namespace oct::cc::v0::A
{
namespace core_here = oct::core::v3;
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
		SUB,
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
		AUTO,
		BREAK,
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

		
		MOV,

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
	

		//leterals
		LITERAL_INTEGER_DEC,
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
		LITERAL_INTEGER_HEX,
		LITERAL_INTEGER_HEX_CHAR,		
		LITERAL_INTEGER_HEX_UCHAR,
		LITERAL_INTEGER_HEX_SHORT,
		LITERAL_INTEGER_HEX_USHORT,
		LITERAL_CHAR,
		LITERAL_STRING,
		LITERAL_FLOAT,
		LITERAL_DOUBLE,
		LITERAL_LONGDOUBLE,

		new_line,
		
		identifier,
		integer,

	};


void add_identifier(int line,const char* filename,const char* word, int leng);

class File
{
public:
	File();
	~File();

	FILE* get_file();

	const std::filesystem::path& get_filename()const;
	bool open(const std::filesystem::path& file);
protected:
	
private:
	FILE* file;
	std::filesystem::path filename;
	void* buffer;
};


class SymbolTable
{
public:

	 int add(int line, const char filename,char* string, size_t leng);
	 
protected:

private:
	 
};

struct Symbol
{
	Tokens number;
};

struct Identifier : public Symbol
{
	std::string name;
};

struct Integer : public Symbol
{
	long long number;
};

struct Char : public Symbol
{
	char letter;
};


extern File current_file;
extern core_here::Block block;
extern Symbol* current_symbol;
}


#endif