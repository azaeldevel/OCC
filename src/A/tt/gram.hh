

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

/*
static const cc::tt::b::TT<cc::a::tt::Tokens,cc::a::tt::Tokens> i8086_insts{

		//mov
		{0,cc::a::tt::Tokens::i8086_mov,cc::tt::Indicator::None,1,a::tt::Tokens::none},
		{1,cc::a::tt::Tokens::Integer_0x,cc::tt::Indicator::None,2,a::tt::Tokens::none},
		{2,cc::a::tt::Tokens::i8086_reg_al,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
		{3,';',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},
		{3,' ',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},
		{3,'\n',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},

		//int
		{0,cc::a::tt::Tokens::i8086_int_token,cc::tt::Indicator::None,6},
		{7,cc::a::tt::Tokens::Integer_0x,cc::tt::Indicator::Accept,8,a::tt::Tokens::gram_inst_int},
		{8,';',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},
		{8,' ',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},
		{8,'\n',cc::tt::Indicator::Prefix_Accept,0,a::tt::Tokens::none},
	};
*/


}




#endif