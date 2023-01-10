

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
#include "tt/chars.hh"



//assembler
namespace oct::cc::AI
{
	
	template<typename C, typename Token, typename S = Word, typename O = Word> 
	class Parser : public pda::BA<C,Token,S,O>
	{
	public:
		Parser(const tt::a::tt_element* lextt, size_t lexl, const tt::b::TT<Token,Token>& t) : pda::BA<C,Token,S,O>(lextt,lexl,t)
		{
		}
		virtual bool parse(Buffer<C>& ) = 0;
	};


	template<typename C, typename Token, typename S = Word, typename O = Word>
	class instructions : protected Parser<C,Token,S,O>
	{
	public:
		instructions() : Parser<C,Token,S,O>(NULL,0,tt::a::gram::instructions)
		{
			//lextt_insts[0].tt = tt::i808x::insts;
			//lextt_insts[0].length = (size_t)LENGTH_TT(tt::i808x::insts);
		}
		
		virtual bool parse(Buffer<C>& buff)
		{
			
			
			return true;
		}
	private:
		pda::BA<C,Token> gram_memory;
		const tt::a::tt_element* lexs_Integer_0x;
		tt::a::tt_element lextt_insts[6];
	};
}




#endif