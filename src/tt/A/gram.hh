

#ifndef OCTETOS_CC_TT_A_GRAM_HH
#define OCTETOS_CC_TT_A_GRAM_HH

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

#include "../../tt.hh" 

//transition table
namespace oct::cc::tt::a::gram
{

static const cc::tt::b::TT<cc::tt::Tokens,cc::tt::Tokens> file{
	
	{0,cc::tt::Tokens::file_section,cc::tt::Indicator::None,1,cc::tt::Tokens::none},
	{1,cc::tt::Tokens::file_code,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
	{2,(cc::tt::Tokens)'{',cc::tt::Indicator::None,3,cc::tt::Tokens::none},
	{3,cc::tt::Tokens::file_list_instructions,cc::tt::Indicator::None,4,cc::tt::Tokens::none},
	{4,(cc::tt::Tokens)'}',cc::tt::Indicator::Accept,5,cc::tt::Tokens::none},
	{5,(cc::tt::Tokens)0,cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
};


static const cc::tt::b::TT<tt::Tokens,tt::Tokens> insts{
		
		{0,(Tokens)' ',tt::Indicator::Eat,0,tt::Tokens::none},
		{0,(Tokens)'\t',tt::Indicator::Eat,0,tt::Tokens::none},
		{0,(Tokens)'\n',tt::Indicator::Eat,0,tt::Tokens::none},
		{0,(Tokens)';',tt::Indicator::Eat,0,tt::Tokens::none},
		
		//mov
		{0,tt::Tokens::i8086_mov,tt::Indicator::None,1,tt::Tokens::none},
			
			{1,(Tokens)' ',tt::Indicator::None,1,tt::Tokens::none},
			{1,(Tokens)'\t',tt::Indicator::None,1,tt::Tokens::none},
			{1,(Tokens)'\n',tt::Indicator::None,1,tt::Tokens::none},
			
			{2,(Tokens)' ',tt::Indicator::Eat,2,tt::Tokens::none},
			{2,(Tokens)'\n',tt::Indicator::Eat,2,tt::Tokens::none},
			{2,(Tokens)'\t',tt::Indicator::Eat,2,tt::Tokens::none},
			
			{3,(Tokens)' ',tt::Indicator::Eat,3,tt::Tokens::none},
			{3,(Tokens)'\n',tt::Indicator::Eat,3,tt::Tokens::none},
			{3,(Tokens)'\t',tt::Indicator::Eat,3,tt::Tokens::none},
			
			//memory,accumulator
			{1,tt::Tokens::Identifier,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::i8086_reg_al,tt::Indicator::Accept,3,tt::Tokens::none},			
			
			//memory,accumulator
			{1,tt::Tokens::i8086_reg_ax,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::Identifier,tt::Indicator::Accept,3,tt::Tokens::none},
			
			//registro,registro
			{1,tt::Tokens::regs,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::regs,tt::Indicator::Accept,3,tt::Tokens::none},	
			
			//
			{3,(Tokens)';',tt::Indicator::Accept_Inmediatly,0,tt::Tokens::gram_inst_mov},
			
			
		//int
		{0,tt::Tokens::i8086_int_token,cc::tt::Indicator::None,6},
		{7,tt::Tokens::Integer_0x,cc::tt::Indicator::Accept,8,tt::Tokens::gram_inst_int},		
		{8,(Tokens)' ',tt::Indicator::Eat,0,tt::Tokens::none},		
		{8,(Tokens)'\t',tt::Indicator::Eat,0,tt::Tokens::none},
		{8,(Tokens)'\n',tt::Indicator::Eat,0,tt::Tokens::none},
		{8,(Tokens)';',tt::Indicator::Prefix_Accept,0,tt::Tokens::none},
		
	};
	
}




#endif