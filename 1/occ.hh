
#ifndef OCTETOS_OCC_V1_CC_HH
#define OCTETOS_OCC_V1_CC_HH

/*
 *
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

#include <filesystem>
#include <list>
#include <map>


#include <core/3/tree.hh>
#include <core/3/Exception.hh>



namespace oct::cc::v1
{
    namespace core = oct::core::v3;
    typedef unsigned char byte;

	enum class Language
	{
	    none,
	    AI,//octetos assembler
	    AII,//octetos assembler
	    AIII,//octetos assembler
	    B,//octetos hihg lever compiler
	    C,//C compiler
            C90,
            C99,
	    CPP,//C++ compiler
            CPP98,
            CPP11,
	};
	enum class CPU
	{
	    none,
	    intel_8088,
	    intel_8086,
        arduino,
	};
	enum class Environment
	{
	    none,
	    freestanding,
	    freestanding_boot,
	    hosted
	};
	enum class OutputType
	{
        none,
        runnable,
        static_library,
        dinamic_library,
	};

	class Driver
    {
    public:
        Driver () = default;
        virtual ~Driver();

        virtual bool parse(const std::filesystem::path& source) = 0;
        virtual bool parse(const std::list<std::filesystem::path>& sources);
        virtual void generate(std::ostream&) const = 0;

    protected:

    };



    /**
     * \brief For identifier diferent tokens
    */
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

		//C-keywords begins here
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

		//Intel instruction set begin here
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

		IDENTIFIER,

		//consttantes
		INTEGER,
		INTEGER_DECIMAL,
		INTEGER_HEXDECIMAL,


	};


    /**
    *\brief convert the parameter to its string representation
    **/
    constexpr const char* to_string(Tokens t)
    {
        switch(t)
        {
        case Tokens::AL:
            return "AL";
        case Tokens::AH:
            return "AH";
        case Tokens::AX:
            return "AX";
        case Tokens::BL:
            return "BL";
        case Tokens::BH:
            return "BH";
        case Tokens::BX:
            return "BX";
        case Tokens::CL:
            return "CL";
        case Tokens::CH:
            return "CH";
        case Tokens::CX:
            return "CX";
        case Tokens::DL:
            return "DL";
        case Tokens::DH:
            return "DH";
        case Tokens::DX:
            return "DX";

        case Tokens::SP:
            return "SP";
        case Tokens::BP:
            return "BP";
        case Tokens::SI:
            return "SI";
        case Tokens::DI:
            return "DI";

        case Tokens::CS:
            return "CS";
        case Tokens::DS:
            return "DS";
        case Tokens::SS:
            return "SS";
        case Tokens::ES:
            return "ES";

        case Tokens::BYTE:
            return "byte";
        case Tokens::TINY:
            return "tiny";

        case Tokens::AUTO:
            return "auto";
        case Tokens::BREAK:
            return "break";
        case Tokens::CASE:
            return "case";
        case Tokens::CHAR:
            return "char";
        case Tokens::CONST:
            return "const";
        case Tokens::CONTINUE:
            return "continue";
        case Tokens::DEFAULT:
            return "default";
        case Tokens::DO:
            return "do";
        case Tokens::DOUBLE:
            return "double";
        case Tokens::ELSE:
            return "else";
        case Tokens::ENUM:
            return "enum";
        case Tokens::EXTERN:
            return "extern";
        case Tokens::FLOAT:
            return "float";
        case Tokens::FOR:
            return "for";
        case Tokens::GOTO:
            return "goto";
        case Tokens::IF:
            return "if";
        case Tokens::INT:
            return "int";
        case Tokens::LONG:
            return "long";
        case Tokens::REGISTER:
            return "register";
        case Tokens::RETURN:
            return "return";
        case Tokens::SHORT:
            return "short";
        case Tokens::SIGNED:
            return "signed";
        case Tokens::SIZEOF:
            return "sizeof";
        case Tokens::STATIC:
            return "static";
        case Tokens::STRUCT:
            return "struct";
        case Tokens::SWITCH:
            return "switch";
        case Tokens::TYPEDEF:
            return "typedef";
        case Tokens::UNION:
            return "union";
        case Tokens::UNSIGNED:
            return "unsigned";
        case Tokens::VOID:
            return "void";
        case Tokens::VOLATIL:
            return "volatil";
        case Tokens::WHILE:
            return "while";

        default:
            return "?";
        }
    }




    /**
    *\brief get string size for the parameter t
    **/
    constexpr size_t string_size(Tokens t)
    {
        switch(t)
        {
        case Tokens::AL:
        case Tokens::AH:
        case Tokens::AX:
        case Tokens::BL:
        case Tokens::BH:
        case Tokens::BX:
        case Tokens::CL:
        case Tokens::CH:
        case Tokens::CX:
        case Tokens::DL:
        case Tokens::DH:
        case Tokens::DX:
            return 2;

        case Tokens::SP:
        case Tokens::BP:
        case Tokens::SI:
        case Tokens::DI:
            return 2;

        //C 90 keywords from here
        case Tokens::AUTO: return 4;
        case Tokens::BREAK: return 5;
        case Tokens::CASE: return 4;
        case Tokens::CHAR: return 4;
        case Tokens::CONST: return 4;
        case Tokens::CONTINUE: return 9;
        case Tokens::DEFAULT: return 7;

        default:
            return 1;
        }
    }

	constexpr bool is_general_register(Tokens t)
    {
        switch(t)
        {
        case Tokens::AL:
        case Tokens::AH:
        case Tokens::AX:
        case Tokens::BL:
        case Tokens::BH:
        case Tokens::BX:
        case Tokens::CL:
        case Tokens::CH:
        case Tokens::CX:
        case Tokens::DL:
        case Tokens::DH:
        case Tokens::DX:
            return true;
        default:
            return false;
        }

		return false;
    }


	constexpr bool is_pointer(Tokens t)
    {
        switch(t)
        {
        case Tokens::SP:
        case Tokens::BP:
        case Tokens::DI:
        case Tokens::SI:
            return true;
        default:
            return false;
        }

		return false;
    }

	constexpr bool is_segment(Tokens t)
    {
        switch(t)
        {
        case Tokens::SP:
        case Tokens::DS:
        case Tokens::ES:
        case Tokens::SS:
            return true;
        default:
            return false;
        }

		return false;
    }

    enum class Statemants
    {
        none,
        token,
            number,
            integer,
            keyword,
            identifier,
            tab,
            space,
            newline,
            letter,
            memory,
            reg,
            segment,
        unit,
        AI,
            declaration,
                pointer,
            init_declarator,
            function,
            instruction,
                move,
                ret,
                iret,
                empty,
                interrupt,
                call,
                push,
                pop,
        AII,
        AIII,
        B,
        C,
        CPP,
    };

    constexpr Statemants to_statement(Tokens t)
    {
        switch(t)
        {
        case Tokens::INTEGER:
        case Tokens::INTEGER_DECIMAL:
            case Tokens::INTEGER_HEXDECIMAL:
            return Statemants::number;
        case Tokens::IDENTIFIER:
            return Statemants::identifier;
        default:
            if(t >= Tokens::AUTO and t<= Tokens::WHILE) return Statemants::keyword;
        }

        return Statemants::none;
    }



    /**
    *\brief Crea un nodo
    *\param T parametro de plantilla para determinar el tipo de nodo
    **/
    struct node : public core::node<Statemants>
    {
        node() = default;
        node(const Statemants& t);

        node* next;

        virtual void print(std::ostream&)const;
        bool is_addressable()const;
    };



    /**
    *\brief Crea un nodo
    **/
    struct Node : public core::Node<Statemants,node>
    {
        Node();
        Node(Statemants);
        Node(Statemants,size_t);

        virtual void print(std::ostream&)const;
    };

    /**
    *\brief Node de Texto
    **/
    class Word : public node
    {
    protected:
        Tokens _token_;

        std::string _string_;
        Word* _yylexnext_;

    public:
        Word() = default;
        Word(const Word&);
        Word(const char*, size_t);
        Word(Tokens,const char*, size_t);
        Word(Statemants,const char*, size_t);
        Word(Statemants,const Word&);
        Word(Statemants,Tokens,const char*, size_t);
        Word(short);
        Word(int);

        Word& operator=(const Word&);
        Word& operator=(Word&&);

        virtual void print(std::ostream&)const;
        bool is_register()const;

        const std::string& string() const;
        void yylexnext(Word*);
        Word* yylexnext();
		Tokens token()const;
    };


    typedef Word Identifier;

    /**
    *\brief Node de Texto
    **/
    class Letter : public node
    {
    protected:
        char _letter_;

    public:
        Letter() = default;
        Letter(char);

        Letter& operator=(const Letter&);
        Letter& operator=(Letter&&);

        virtual void print(std::ostream&)const;

        void letter(char);
        char letter()const;
    };



    /**
    *\brief Node de Texto
    **/
    class Keyword : public Word
    {
    public:
        Keyword() = default;
        Keyword(const char*, size_t);
        Keyword(Tokens,const char*, size_t);
        Keyword(Statemants,const char*, size_t);
        Keyword(Statemants,Tokens,const char*, size_t);

        Keyword& operator=(const Keyword&);
        Keyword& operator=(Keyword&&);

        virtual void print(std::ostream&)const;

        bool is_register() const;
        bool is_general_register() const;
        bool is_pointer_register() const;
        bool is_segment_register() const;
        bool is_memory() const;
    };


    /**
    *\brief Node de Texto
    **/
    class Number : public Word
    {
    public:
        Number() = default;
        Number(const Number& );
        Number(const char*, size_t);
        Number(Tokens,const char*, size_t);
        Number(Statemants,const char*, size_t);
        Number(Statemants,const Number&);
        Number(Statemants,Tokens,const char*, size_t);
        Number(Statemants,Tokens,const char*, size_t,char base);
        Number(short);
        Number(int);

        Number& operator=(const Number&);
        Number& operator=(Number&&);

        virtual void print(std::ostream&)const;

        char size()const;
        char base()const;
        void to_short(unsigned char* from)const ;

    private:
        char _base_;
    };

    typedef Number Integer;

    /**
    *\brief Node de Identificar
    **/
    struct Statement : public node
    {
        Statement* next;

        Statement();
        Statement(Statemants);
    };

    /**
    *\brief Node de Space,namespace, package, file scope,etc..
    **/
    template<typename N,typename K = const char*>
    class Symbols : public std::map<K,N*>, public Statement
    {
    public:
        typedef std::map<K,N*> BASE;

    public:
        Symbols()= default;

        bool add(Identifier& id)
        {
            BASE::insert(std::pair(id.string().c_str(),id));

            return true;
        }
        bool add(Symbols& s)
        {
            BASE::insert(std::pair(s.name->string().c_str(),s));

            return true;
        }

    public:
        Identifier* name;

    protected:

    };

    template<typename N,typename K = const char*>
    class TableSymbols : public Symbols<K,N>
    {
    public:
        typedef Symbols<K,N> BASE;
    public:
        TableSymbols()= default;

    protected:

    };

    template<class T>
    class Block : public std::list<core::array<T>>
    {
    private:
        typedef std::list<core::array<T>> BASE;
        static const size_t default_size = 1024;

    public:
        Block() : index(0)
        {
            BASE::push_back(core::array<T>(default_size));
            block = BASE::begin();
        }
        Block(size_t s) : index(0)
        {
            BASE::push_back(core::array<T>(s));
            block = BASE::begin();
        }

        T* next()
        {
            T* t;
            if(index < block->size())
            {
                t = &block->at(index);
                index++;
            }
            else
            {
                BASE::push_back(core::array<T>(default_size));
                block++;
                index = 0;
                t = &block->at(index);
                index++;
            }

            return NULL;
        }

        template <typename... Args>
        T* next(Args... args)
        {
            T* t;
            if(index < block->size())
            {
                t = &block->at(index);
                index++;
            }
            else
            {
                BASE::push_back(core::array<T>(default_size));
                block++;
                index = 0;
                t = &block->at(index);
                index++;
            }

            t->operator = (T(args...));

            return t;
        }

        T* get()
        {
            return &block->at(index);
        }

    private:
        BASE::iterator block;
        size_t index;

    };


    template<class U,class N = Node>
    struct Tray
    {
        TableSymbols<N>* table;
        U* unit;
    };

}

namespace occ = oct::cc::v1;

#endif
