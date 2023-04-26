
#ifndef OCTETOS_CC_V0_AI_HH
#define OCTETOS_CC_V0_AI_HH


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


#include <core/3/math.hh>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <variant>

#include "cc.hh"


namespace oct::cc::v0::AI
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
		BYTE,
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


		//leterals
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
		LITERAL_INTEGER_HEX_SCHAR,
		LITERAL_INTEGER_HEX_UCHAR,
		LITERAL_INTEGER_HEX_SHORT,
		LITERAL_INTEGER_HEX_USHORT,
		LITERAL_INTEGER_HEX_INT,
		LITERAL_INTEGER_HEX_UINT,
		LITERAL_INTEGER_HEX_LONG,
		LITERAL_INTEGER_HEX_ULONG,
		CONSTANT_CHAR,
		LITERAL_STRING,
		LITERAL_FLOAT,
		LITERAL_DOUBLE,
		LITERAL_LONGDOUBLE,

		new_line,

		identifier,
		integer,

	};

	class File
    {
    public:
        File();
        ~File();

        void* get_scanner();

        const std::filesystem::path& get_filename()const;
        bool open(const std::filesystem::path& file);
    protected:

    private:
        FILE* file;
        std::filesystem::path filename;
        void* buffer;
        void* scanner;
    };

    typedef long long integer;


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

    namespace nodes
    {
        struct declarator;
        typedef unsigned int Line;
        const char* register_to_string(Tokens);
        const char* type_specifier_to_string(Tokens);
        enum class source_type : unsigned char
        {
            none,
            inmediate,
            registers,
            memory,
        };

        struct Node
        {
            const Node* next;

            Node();
        };

        template<class T>
        struct Token : public Node
        {
            T token;
        };

        struct statement : public Node
        {
            bool is_instruction;

            statement();

            void print(std::ostream&)const;
        };
        struct instruction : public statement
        {
            Tokens inst;
            unsigned char word_size;
        };
        struct assembler_instruction : public instruction
        {
        };


    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Nodes
        struct Integer : public Node
        {
            long long number;
            char format;//Decimal, Hexadecimal

            Tokens reduced_token()const;

        };
        struct identifier : public Node
        {
            int number;
            std::string string;
            int line;
            unsigned int memory;
        };


        struct space : public Node, std::map<const char*,nodes::Node*>
        {
            identifier* name;
        };


    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Not C statment



        struct Move : public assembler_instruction
        {
            enum class operands_type : unsigned char
            {
                none,
                //regiter_inmediate,
                regiter_integer,
                regiter_char,
            };


            unsigned char word_size;
            operands_type op_type;
            //char data_type;//I : integer, C : char
            Node* destine;
            Node* source;

            void generate(std::ostream&) const;
            void print(std::ostream&)const;

        private:
            void generate_8b_inmediate(std::ostream&) const;//source inmediate
        };

        /*struct move_8b_reg_byte : public Move
        {
            Tokens registe;
            unsigned char byte;
            char type;//I : integer, C : char

            void generate(std::ostream& ) const;
            void print(std::ostream&)const;
        };*/

        struct instruction_int : public assembler_instruction
        {
            unsigned char service;

            void generate(std::ostream& ) const;
            void print(std::ostream&)const;
        };

        struct instruction_label : public assembler_instruction
        {
            const identifier* id;
        };

        struct return_statement : public statement
        {
        };


        struct instruction_ret : public assembler_instruction
        {
        };
        struct instruction_iret : public assembler_instruction
        {
        };





    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>C statment


        struct type_qualifer : public statement
        {
            Tokens qualifer;
        };

        struct initializer : public statement
        {
            Tokens data_type;

            void print(std::ostream& out) const;
        };


        struct const_expression : public initializer
        {
        };
        template<typename T> struct initializer_literal : public const_expression
        {
            T value;

            void print(std::ostream& out) const
            {
                //std::cout << "Valor : \n";
                out << value;
            }
        };


        struct init_declarator : public statement
        {
            const declarator* dec;
            const initializer* value;

            void print(std::ostream&)const;
        };


        struct pointer : public statement
        {
            std::list<type_qualifer*>* qualifiers;
            const pointer* point;
        };

        struct direct_declarator : public statement
        {
            const identifier* id;
            const direct_declarator* direct;
            const identifier* identifier_list;

            void print(std::ostream&)const;
        };


        struct declarator : public statement
        {
            const pointer* point;
            const direct_declarator* direct;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;
        };


        struct type_specifier : public statement
        {
            Tokens type;

            void print(std::ostream& out) const;
            void generate(std::ostream&)const;
        };

        struct declaration : public statement
        {
            const type_specifier* specifiers;
            const init_declarator* list;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;
        };

        struct function : public space //public statement
        {
            const identifier* id;
            const statement* body_list;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;

        };


        struct translation_unit : public statement
        {
            const declaration* declarations;
            const function* functions;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;
        };

    }

    //typedef std::variant<nodes::identifier*> element;

    class SymbolTable : public nodes::space
    {
    public:
        void add(nodes::declaration*);
        void add(nodes::declarator*);
        void add(nodes::space*);
        void add(nodes::function*);

    protected:

    private:

    };

    template<class UNIT>
    struct Tray
    {
        core_here::Block block;
        SymbolTable symbols;
        UNIT* unit;
    };


    //extern core_here::Block block;
}


#endif
