

#ifndef OCTETOS_CC_A_HH
#define OCTETOS_CC_A_HH

/*
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 * 
 * CC is free software: you can redistribute it and/or modify it
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

#include <cctype>

#include "AF.hh"
#include "A/tt.hh"
#include "A/tt/i8086/insts.hh"
#include "A/tt/gram.hh"


//assembler
namespace oct::cc::a
{

template<typename C ,typename Token = cc::tt::Token,typename S = Word,typename O = Word> class File
{
public:
	File() : i(0)
	{
	}
	
	Token lexing(Buffer<C>& buff)
	{
		if(buff.empty()) return 0;		
	
		//std::cout << "\nStep 1\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";
		
		buff.consume_whites();
	
		//>>>>keyword
		lexer.load(TABLE(a::tt::i8086::insts));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_accepted()->token;	
	
		//std::cout << "Step 2\n";	
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(a::tt::i8086::regs));
		i = lexer.transition(buff);
		//std::cout << "i : " << i << "\n";
		if(i > 0) return lexer.get_accepted()->token;
	
		//std::cout << "Step 3\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(a::tt::i8086::segs));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_accepted()->token;
	
		//std::cout << "Step 4\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";


		//>>>>
		lexer.load(TABLE(a::tt::Identifier));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_accepted()->token;

		lexer.load(TABLE(a::tt::Interger));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_accepted()->token;

		lexer.load(TABLE(a::tt::Integer_0x));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_accepted()->token;

		//std::cout << "Step 5\n";
		//std::cout << "char : '" << buff[0] << "'\n";
		if((Token)buff[0] > 0 and (Token)buff[0] < 129) 
		{			
			return buff.next_char();
		}
		
		return Token(0);
	}

	Token parsing(Buffer<C>& buff)
	{

		return Token(0);
	}

private:
	dfa::A<C,S,O> lexer;
	dfa::B<Token,S,O> parser;
	O i;
	
};

template<typename C ,typename Token = cc::tt::Token,typename S = Word,typename O = Word> class Code
{
public:
	Code() : i(0)
	{
	}
	
	Token lexing(Buffer<C>& buff)
	{
		if(buff.empty()) return 0;		
	
		//std::cout << "\nStep 1\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";
		
		buff.consume_whites();
	
		//>>>>keyword
		lexer.load(TABLE(a::tt::i8086::insts));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_actual()->token;	
	
		//std::cout << "Step 2\n";	
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(a::tt::i8086::regs));
		i = lexer.transition(buff);
		//std::cout << "i : " << i << "\n";
		if(i > 0) return lexer.get_actual()->token;
	
		//std::cout << "Step 3\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(a::tt::i8086::segs));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_actual()->token;
	
		//std::cout << "Step 4\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";


		//>>>>
		lexer.load(TABLE(a::tt::Identifier));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_actual()->token;

		lexer.load(TABLE(a::tt::Interger));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_actual()->token;

		lexer.load(TABLE(a::tt::Integer_0x));
		i = lexer.transition(buff);
		if(i > 0) return lexer.get_actual()->token;

		//std::cout << "Step 5\n";
		//std::cout << "char : '" << buff[0] << "'\n";
		if((Token)buff[0] > 0 and (Token)buff[0] < 129) 
		{			
			return buff.next_char();
		}
		
		return Token(0);
	}

	Token parsing(Buffer<C>& buff)
	{
		dfa::B<Token,S,O> parser(gram::tt::i8086::file);

		return Token(0);
	}

private:
	dfa::A<C,S,O> lexer;
	//dfa::B<Token,S,O> parser;
	O i;
	
};

}




#endif