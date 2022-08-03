

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
#include "A/tt.hh"
#include "A/tt/i8086/insts.hh"
#include "AF.hh"

//assembler
namespace oct::cc::a
{
	
	template<typename Char,typename Symbol = cc::tt::Token,typename Status = cc::tt::Status,typename Index = Word>
	class Instruction : public dfa::Grammar<Char,Symbol,Status,Index>
	{
	public:
		Instruction()
		{
			
		}
		
		Symbol lexing(Buffer<Char>& buff)
		{
			if(buff.empty()) return (Symbol)a::tt::Tokens::none;

			buff.consume_whites();
			
			dfa::Grammar<Char,Symbol,Status,Index>::lexer.load(TABLE(a::tt::i8086::insts));
			if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.transition(buff) > 0) 
			{
				if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted() != NULL) 
				{
					return dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted()->token;
				}
			}
				
			dfa::Grammar<Char,Symbol,Status,Index>::lexer.load(TABLE(a::tt::i8086_regs));
			if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.transition(buff) > 0) 
			{
				if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted() != NULL) 
				{
					return dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted()->token;
				}
			}
			
			dfa::Grammar<Char,Symbol,Status,Index>::lexer.load(TABLE(a::tt::Identifier));
			if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.transition(buff) > 0) 
			{
				if(dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted() != NULL) 
				{
					return dfa::Grammar<Char,Symbol,Status,Index>::lexer.get_accepted()->token;
				}
			}

			
			return (Symbol)buff.next_char();
		}
			
		Symbol parsing(Buffer<Char>& buff)
		{
			
		}
		
		
	private:
	};

}




#endif