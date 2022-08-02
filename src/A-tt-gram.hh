

#ifndef OCTETOS_CC_A_GRAM_HH
#define OCTETOS_CC_A_GRAM_HH

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


#include "tt.hh"


//transition table
namespace oct::cc::a::gram::tt
{

constexpr static const cc::b::Transition<cc::tt::Token> i8086_insts[] = {

		//mov
		{0,cc::a::tt::Tokens::i8086_mov,Indicator::None,1},
		{1,cc::a::tt::Tokens::Integer_0x,Indicator::None,2},
		{2,cc::a::tt::Tokens::i8086_reg_al,Indicator::Accept,3},
		{3,';',Indicator::Prefix_Accept,0},
		{3,' ',Indicator::Prefix_Accept,0},
		{3,'\n',Indicator::Prefix_Accept,0},

		//int
		{0,cc::a::tt::Tokens::i8086_int,Indicator::None,6},
		{7,cc::a::tt::Tokens::Integer_0x,Indicator::None,8},
		{8,';',Indicator::Prefix_Accept,0},
		{8,' ',Indicator::Prefix_Accept,0},
		{8,'\n',Indicator::Prefix_Accept,0},
	};


}




#endif