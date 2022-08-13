

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


#include "AF.hh"
#include "tt.hh"
#include "tt/i808x.hh"
#include "tt/A/gram.hh"
#include "tt/A/lex.hh"
#include "tt/identifier.hh"
#include "tt/numbers.hh"



//assembler
namespace oct::cc::a
{

template<typename C ,typename Token = cc::tt::Token,typename S = Word,typename O = Word> class List_Instructions : public dfa::B<Token,Token,S,O>
{
public:
	List_Instructions() : i(0), dfa::B<Token,Token,S,O>(tt::a::gram::insts)
	{
	}
	
	/*
	Token parsing(Buffer<C>& buff)
	{
		O i = 0;
		do
		{	
			i = transition(lexing(buff));
		}
		while(i > 0);		
		
		return Token(tt::Tokens::error);
	}
	*/
	
	Token lexing(Buffer<C>& buff)
	{
		if(buff.empty()) return (Token)0;		
	
		//std::cout << "\nStep 1\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";
		
		buff.consume_whites();
	
		//>>>>keyword
		lexer.load(TABLE(tt::i808x::insts));
		i = lexer.transition(buff);
		if(i > 0) return (Token)lexer.get_actual()->token;	
	
		//std::cout << "Step 2\n";	
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(tt::i808x::regs));
		i = lexer.transition(buff);
		//std::cout << "i : " << i << "\n";
		if(i > 0) return (Token)lexer.get_actual()->token;
	
		//std::cout << "Step 3\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";

		lexer.load(TABLE(tt::i808x::segs));
		i = lexer.transition(buff);
		if(i > 0) return (Token)lexer.get_actual()->token;
	
		//std::cout << "Step 4\n";
		//std::cout << "base : \"" << buff.get_base_string() << "\"\n";
		
		//>>>>
		lexer.load(TABLE(tt::Identifier));
		i = lexer.transition(buff);
		if(i > 0) return (Token)lexer.get_actual()->token;

		lexer.load(TABLE(tt::Interger));
		i = lexer.transition(buff);
		if(i > 0) return (Token)lexer.get_actual()->token;

		lexer.load(TABLE(tt::Integer_0x));
		i = lexer.transition(buff);
		if(i > 0) return (Token)lexer.get_actual()->token;

		//std::cout << "Step 5\n";
		//std::cout << "char : '" << buff[0] << "'\n";
		if(buff[0] > 0 and buff[0] < 129) 
		{
			return (Token)buff.next_char();
		}
		
		return Token(tt::Tokens::error);
	}

private:
	dfa::A<C,S,O> lexer;
	//dfa::B<Token,Token,S,O> parser;
	O i;


};



template<typename C ,typename Token = tt::Tokens,typename S = Word,typename O = Word> class File
{
public:
	File() : i(0), lexer(TABLE(tt::a::lex::file)), file_parser(tt::a::gram::file)
	{
	}
	
	Token parsing(Buffer<C>& buff)
	{
		if(buff.empty()) return 0;	
		
		i = file_parser.transition(buff);	
		if(i > 0) 
		{
			i = list_insts.transition(buff);
			if(i > 0) return  list_insts.get_accept()->token;
		}
		
		return Token(tt::Tokens::error);
	}
	
private:
	dfa::A<C,S,O> lexer;
	dfa::B<Token,Token,S,O> file_parser;
	O i;
	List_Instructions<C,S,O> list_insts;
	
};




}




#endif