
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
#include <vector>

#include <core/3/math.hh>

//namespace core_here =  oct::core::v3;

namespace oct::core::v3
{
//https://en.cppreference.com/w/cpp/string/byte/atoi

class Block
{
public:
	Block() : page_size(1024),actual(NULL)
	{
		actual = malloc(page_size);
		blocks.push_back(actual);
	}
	Block(size_t size) : page_size(size),actual(NULL)
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
		//std::cout << "Block::create begin\n";
		if((long)actual >= page_size)
		{
			//std::cout << "Block::create malloc\n";
			actual = malloc(page_size);
			blocks.push_back(actual);
		}
		void* now = actual;
		char* newptr = static_cast<char*>(actual);
		//std::cout << "Block::create actual : " << (long)actual << "\n";
		newptr += sizeof(T) + 1;
		//std::cout << "Block::create newptr : " << (long)newptr << "\n";
		//std::cout << "Block::create sizeof(T) : " << sizeof(T) << "\n";
		actual = (void*)newptr;
		//std::cout << "Block::create end\n";
		return (T*)now;
	}
protected:
	void* actual;//last block memory assignable
	//size_t index;//firs posistion usable in actual block memory
	std::list<void*> blocks;
	std::list<void*>::iterator it;
	size_t page_size;

private:


};

}


namespace oct::cc::v0::A
{
    /**
	*\brief Convierte el string dao en el intero indicado
	*/
	template<std::signed_integral T, typename C> T to_number(const C* str)
	{
		while (std::isspace(static_cast<unsigned char>(*str)))
		{
			++str;
		}

		bool negative = false;

		if (*str == '+')
		{
			++str;
		}
		else if (*str == '-')
		{
			++str;
			negative = true;
		}

		T result = 0;
		for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
		{
			T digit = *str - '0';
			result *= 10;
			result -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
		}

		return negative ? result : -result;
	}
	/**
	*\brief Convierte el string dado en el intero indicado
	*/
	template<std::unsigned_integral T, typename C> T to_number(const C* str, int base = 10)
	{
		while (std::isspace(static_cast<unsigned char>(*str)))
		{
			++str;
		}
		if(base == 16)
        {
            if(str[0] == '0' and str[1] == 'x')
            {
                str++;
                str++;
            }
        }

		bool negative = false;

		if (*str == '+')
		{
			++str;
		}
		else if (*str == '-')
		{
			++str;
			negative = true;
			//throw error
		}

		T result = 0;
		if(base == 10)
        {
            for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
            {
                T digit = *str - '0';
                result *= base;
                result -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
            }
        }
        else if(base == 16)
        {
            T digit;
            for (; std::isxdigit(static_cast<unsigned char>(*str)); ++str)
            {
                //digit = 0;
                switch((char)*str)
                {
                    case 'a':
                    case 'A' :
                        digit = 10;
                        break;
                    case 'b':
                    case 'B' :
                        digit = 11;
                        break;
                    case 'c':
                    case 'C' :
                        digit = 12;
                        break;
                    case 'd':
                    case 'D' :
                        digit = 13;
                        break;
                    case 'e':
                    case 'E' :
                        digit = 14;
                        break;
                    case 'f':
                    case 'F' :
                        digit = 15;
                        break;
                    default:
                        digit = *str - '0';
                }
                //std::cout << "Hex : " << *str << " - " << (unsigned char)digit << "\n";
                result *= base;
                result += digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
            }
        }

		return result;
	}

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
		LITERAL_INTEGER_HEX_SCHAR,
		LITERAL_INTEGER_HEX_UCHAR,
		LITERAL_INTEGER_HEX_SHORT,
		LITERAL_INTEGER_HEX_USHORT,
		LITERAL_INTEGER_HEX_INT,
		LITERAL_INTEGER_HEX_UINT,
		LITERAL_INTEGER_HEX_LONG,
		LITERAL_INTEGER_HEX_ULONG,
		LITERAL_CHAR,
		LITERAL_STRING,
		LITERAL_FLOAT,
		LITERAL_DOUBLE,
		LITERAL_LONGDOUBLE,

		new_line,

		identifier,
		integer,

	};


	template<typename Token> std::string to_string(Token t)
	{
		std::string str;

		if (t >= Token::AUTO and t <= Token::WHILE)
		{
			switch(t)
			{
			case Token::AUTO : return "auto";
			case Token::BREAK : return "break";
			case Token::CASE : return "case";
			case Token::CHAR : return "char";
			case Token::CONST : return "const";
			case Token::CONTINUE : return "continue";
			case Token::DEFAULT : return "default";
			case Token::DO : return "do";
			case Token::ELSE : return "else";
			case Token::ENUM : return "enum";
			case Token::EXTERN : return "extern";
			case Token::FLOAT : return "float";
			case Token::FOR : return "for";
			case Token::GOTO : return "goto";
			case Token::IF : return "if";
			case Token::INT : return "int";
			case Token::LONG : return "long";
			case Token::REGISTER : return "register";
			case Token::RETURN : return "return";
			case Token::SHORT : return "short";
			case Token::SIGNED : return "signed";
			case Token::SIZEOF : return "sizeof";
			case Token::STATIC : return "static";
			case Token::STRUCT : return "struct";
			case Token::SWITCH : return "switch";
			case Token::TYPEDEF : return "typedef";
			case Token::UNION : return "union";
			case Token::UNSIGNED : return "unsgined";
			case Token::VOID : return "void";
			case Token::VOLATIL : return "volatil";
			case Token::WHILE : return "while";
			}
		}

		return std::to_string((int)t);
	}
void add_identifier(int line,const char* filename,const char* word, int leng);


Tokens integer_token(long long number);

struct Symbol
{
	Tokens token;
	std::vector<Symbol*> childs;
	unsigned int line;
	std::string strvalue;
};

struct Integer : public Symbol
{
	long long number;
	char format;//Decimal, Hexadecimal

	Tokens reduced_token()const;

};


struct Identifier : public Symbol
{
	int number;
	std::string name;
	long long llvalue;
	int line;
	unsigned int memory;
};

class SymbolTable : public std::list<Identifier*>
{

public:

protected:

private:

};

class File
{
public:
	File(SymbolTable& symbols);
	~File();

	FILE* get_file();
	void* get_scanner();

	const std::filesystem::path& get_filename()const;
	bool open(const std::filesystem::path& file);
protected:

private:
	FILE* file;
	std::filesystem::path filename;
	void* buffer;
	size_t index;
	void* scanner;
	SymbolTable* symbols;
};




class Block : public core_here::Block
{
public:
	Block();


	Symbol* next();

protected:


private:
	Symbol* actual;
	size_t index;


	size_t get_size(Symbol*) const;
	Symbol* get(size_t at);
};

//https://www.lkouniv.ac.in/site/writereaddata/siteContent/202004101310174347kalpana_singh_engg_Microprocessor_instruction_format.pdf
//http://www.mathemainzel.info/files/x86asmref.html#mov
class Instruction
{

public:
	void movbi(int reg,unsigned char data);
	void set_opcode(Tokens inst);

	void print(std::ostream& );
public:
	int size;


private:
	/*unsigned char rbp : 3;
	unsigned char none : 2;
	unsigned char wb : 2;
	unsigned char aa : 2;
	unsigned char w : 1;
	unsigned char opcode : 6;
	unsigned char mm : 2;*/

	unsigned char D1,D2,D3,D4;
	unsigned char length;
};




//extern File current_file;
extern core_here::Block block;
extern Symbol* symbol_current;
}


#endif
