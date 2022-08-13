

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

	static const cc::tt::b::TT<tt::Tokens,tt::Tokens> file{
		
		{0,tt::Tokens::file_section,Indicator::None,1,Tokens::none},
		{1,tt::Tokens::file_code,Indicator::None,2,Tokens::none},
		{2,tt::Tokens::gram_list_insts,Indicator::Prefix_Accept,3,Tokens::none},
		{3,(tt::Tokens)0,Indicator::Prefix_Accept,0,Tokens::none},
	};

	/*static const cc::tt::b::TT<Tokens,Tokens> file_list_insts{
		
		{0,(tt::Tokens)'{',Indicator::None,1,Tokens::none},
		
		{1,tt::Tokens::gram_inst_mov,Indicator::Accept,1,Tokens::gram_inst_mov},
		{1,tt::Tokens::gram_inst_int,Indicator::Accept,1,Tokens::gram_inst_int},

		{1,(tt::Tokens)'}',cc::tt::Indicator::Accept_Inmediatly,0,Tokens::gram_list_insts},

	};*/

	static const cc::tt::b::TT<tt::Tokens,tt::Tokens> list_insts{
			
		//mov
		{0,tt::Tokens::i8086_mov,tt::Indicator::None,1,tt::Tokens::none},
			
			//memory,accumulator
			{1,tt::Tokens::Identifier,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::i8086_reg_al,tt::Indicator::Accept,3,tt::Tokens::none},

			//memory,accumulator
			{1,tt::Tokens::Integer_0x,tt::Indicator::None,2,tt::Tokens::none},
			//{2,tt::Tokens::i8086_reg_al,tt::Indicator::Accept,3,tt::Tokens::none},				
			
			//memory,accumulator
			{1,tt::Tokens::i8086_reg_ax,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::Identifier,tt::Indicator::Accept,3,tt::Tokens::none},
			
			//registro,registro
			{1,tt::Tokens::regs,tt::Indicator::None,2,tt::Tokens::none},
			{2,tt::Tokens::regs,tt::Indicator::Accept,3,tt::Tokens::none},	
			
			//			
			{3,(Tokens)' ',tt::Indicator::Eat,3,(Tokens)' '},
			{3,(Tokens)'\n',tt::Indicator::Eat,3,(Tokens)'\t'},
			{3,(Tokens)'\t',tt::Indicator::Eat,3,(Tokens)'\n'},			
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