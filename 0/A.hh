
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
            Node* next;

            Node();
        };

        /**
        *\brief solo para agregaqr el token como un nodo, cuando a demas de un token pueder recibir un algun statem mas complejo
        *
        */
        template<class T>
        struct Token : public Node
        {
            T token;
        };



        struct identifier : public Node
        {
            int number;
            std::string string;
            int line;
            unsigned int memory;
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

            virtual void generate(std::ostream& ) const = 0;
            virtual void print(std::ostream&) const = 0;
        };

        template <class T> concept integer_type = std::is_same_v<T, integer> or std::is_same_v<T, int> or std::is_same_v<T, unsigned int> or std::is_same_v<T, long> or std::is_same_v<T, unsigned long>;
        template <class T> concept charater_type = std::is_same_v<T, char>;



        struct constant : public Node
        {
            virtual void print(std::ostream& out) const = 0;
        };

        template<integer_type T> class constant_integer : public constant
        {
        public:

        public:
            enum class Format
            {
                none,
                decimal,
                hexadecimal,
                octal,
                binary,
            };

        public:
            constant_integer() = default;
            void set(const std::string&,Format);

            bool is(Tokens) const;
            Format get_format() const
            {
                return format;
            }
            T get_value()const
            {
                return value;
            }

            virtual void print(std::ostream& out) const
            {
                out << value;
            }

            bool is_data_8b()const;
            bool is_data_16b()const;
            short get_data_size()const
            {
                return data_size;
            }
            Tokens get_type_data()const
            {
                return type_data;
            }
            Tokens get_type_singed()const
            {
                return type_singed;
            }
            /*auto get_value_type()const
            {
                if(type_data == Tokens::CHAR and type_singed == Tokens::SIGNED)
                {
                    return (signed char)value;
                }
                else if(type_data == Tokens::CHAR and type_singed == Tokens::UNSIGNED)
                {
                    return (unsigned char)value;
                }
                else if(type_data == Tokens::SHORT and type_singed == Tokens::SIGNED)
                {
                    return (short)value;
                }
                else if(type_data == Tokens::SHORT and type_singed == Tokens::UNSIGNED)
                {
                    return (unsigned short)value;
                }
                else
                {
                    return integer(value);
                }
            }*/

        private:
            void sizes();

        private:
            Format format;
            std::string string;
            bool suffix_u;
            bool suffix_l;
            T value;
            Tokens type_data;
            Tokens type_singed;
            short data_size;

        };
        template<charater_type T> struct charater_constant : public constant
        {
            T value;


            virtual void print(std::ostream& out) const
            {
                out << value;
            }
        };



    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Nodes

        /*
        struct Integer : public Node
        {
            long long number;
            char format;//Decimal, Hexadecimal

            Tokens reduced_token()const;

        };
        */

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Not C statment


        struct Move : public instruction
        {
            enum class operands_type : unsigned char
            {
                none,
                //regiter_inmediate,
                regiter_integer,
                regiter_char,
            };

            //unsigned char word_size;
            operands_type op_type;
            //char data_type;//I : integer, C : char
            Node* destine;
            Node* source;

        };

        /*struct move_8b_reg_byte : public Move
        {
            Tokens registe;
            unsigned char byte;
            char type;//I : integer, C : char

            void generate(std::ostream& ) const;
            void print(std::ostream&)const;
        };*/

        struct Interruption : public instruction
        {
            constant_integer<integer>* service;
        };

        struct Label : public instruction
        {
            identifier* id;
        };

        /**
        *\brief is usada por el ensambalador con RET, IRET y en C con return keywork, solo cambia respectivo valor de token.
        */
        struct Return : public instruction
        {
        };





    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>C statment
        class primary_expression : public std::variant<identifier*,charater_constant<char>* ,constant_integer<integer>* , primary_expression*>
        {
        public:

        private:

        };


        struct type_qualifer : public statement
        {
            Tokens qualifer;
        };

        /*struct initializer : public statement
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
        };*/


        struct init_declarator : public statement
        {
            declarator* dec;
            constant* value;

            void print(std::ostream&)const;
        };


        struct pointer : public statement
        {
            std::list<type_qualifer*>* qualifiers;
            pointer* point;
        };

        struct direct_declarator : public statement
        {
            identifier* id;
            direct_declarator* direct;
            identifier* identifier_list;

            void print(std::ostream&)const;
        };


        struct declarator : public statement
        {
            pointer* point;
            direct_declarator* direct;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;

            identifier* get_name() const;
        };


        struct type_specifier : public statement
        {
            Tokens type;

            void print(std::ostream& out) const;
            void generate(std::ostream&)const;
        };

        struct declaration : public statement
        {
            type_specifier* specifiers;
            init_declarator* list;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;

            bool semantic()const;
        };

        struct function : public statement //public statement
        {
            identifier* id;
            statement* body_list;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;

            bool semantic()const;
        };


        struct translation_unit : public statement
        {
            declaration* declarations;
            function* functions;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;
        };

        namespace intel
        {
            namespace i8086
            {
                struct Move : nodes::Move
                {

                    virtual void print(std::ostream&)const;
                    virtual void generate(std::ostream&) const;
                private:
                    //void generate_8b_inmediate(std::ostream&) const;//source inmediate
                    void generate_reg_char(std::ostream&) const;//source inmediate
                    void generate_reg_integer(std::ostream&) const;//source inmediate
                    void generate_16b_inmediate(std::ostream&) const;//source inmediate
                };
                struct Interruption : nodes::Interruption
                {

                    virtual void print(std::ostream&)const;
                    virtual void generate(std::ostream&) const;
                };
                struct Label : nodes::Label
                {

                    virtual void print(std::ostream&)const;
                    virtual void generate(std::ostream&) const;
                };
                struct Return : nodes::Return
                {

                    virtual void print(std::ostream&)const;
                    virtual void generate(std::ostream&) const;
                };
            }
        }
        namespace C
        {
            struct Return : nodes::Return
            {

                virtual void print(std::ostream&)const{};
                virtual void generate(std::ostream&) const{};
            };

        }
    }



    struct space : public nodes::Node, std::map<const char*,const nodes::Node*>
    {
        nodes::identifier* name;
    };

    //typedef std::variant<nodes::identifier*> element;

    class SymbolTable : public space
    {
    public:
        void add(const nodes::declaration*);
        //void add(nodes::declarator*);
        void add(const space*);
        void add(const nodes::function*);

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
