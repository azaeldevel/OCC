

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
namespace oct::cc::tt::a
{

static const cc::tt::b::TT<cc::tt::Tokens,cc::tt::Tokens> file{
	
	{0,cc::tt::Tokens::file_section,cc::tt::Indicator::None,1,cc::tt::Tokens::none},
	{1,cc::tt::Tokens::file_code,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
	{2,(cc::tt::Tokens)'{',cc::tt::Indicator::None,3,cc::tt::Tokens::none},
	{3,cc::tt::Tokens::file_list_instructions,cc::tt::Indicator::None,4,cc::tt::Tokens::none},
	{4,(cc::tt::Tokens)'}',cc::tt::Indicator::Accept,5,cc::tt::Tokens::none},
	{5,(cc::tt::Tokens)0,cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
};


static const cc::tt::b::TT<cc::tt::Tokens,cc::tt::Tokens> insts{

		//mov
		{0,cc::tt::Tokens::i8086_mov,cc::tt::Indicator::None,1,cc::tt::Tokens::none},
			//memory,accumulator
			{1,cc::tt::Tokens::Identifier,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
				//memory, al
				{2,cc::tt::Tokens::i8086_reg_al,cc::tt::Indicator::Accept,3,cc::tt::Tokens::gram_inst_mov},
				//memory, ax
				{2,cc::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::Accept,3,cc::tt::Tokens::gram_inst_mov},

			//accumulator,memory
			{1,cc::tt::Tokens::i8086_reg_al,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
			{1,cc::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
			{2,cc::tt::Tokens::Identifier,cc::tt::Indicator::None,3,cc::tt::Tokens::none},

			//register, register
			//-->repeat{1,cc::a::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::None,2,a::tt::Tokens::none},
				{2,cc::tt::Tokens::i8086_reg_bx,cc::tt::Indicator::Accept,3,cc::tt::Tokens::none},
				{2,cc::tt::Tokens::i8086_reg_cx,cc::tt::Indicator::Accept,3,cc::tt::Tokens::none},
				{2,cc::tt::Tokens::i8086_reg_dx,cc::tt::Indicator::Accept,3,cc::tt::Tokens::none},
			{1,cc::tt::Tokens::i8086_reg_bx,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_cx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_dx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
			{1,cc::tt::Tokens::i8086_reg_cx,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_bx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_dx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},			
			{1,cc::tt::Tokens::i8086_reg_dx,cc::tt::Indicator::None,2,cc::tt::Tokens::none},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_ax,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_bx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},
				//-->repeat{2,cc::a::tt::Tokens::i8086_reg_cx,cc::tt::Indicator::Accept,3,a::tt::Tokens::gram_inst_mov},

		{3,(cc::tt::Tokens)';',cc::tt::Indicator::Accept,4,cc::tt::Tokens::gram_inst_mov},

		{4,(cc::tt::Tokens)' ',cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
		{4,(cc::tt::Tokens)'\n',cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},

		//int
		{0,cc::tt::Tokens::i8086_int_token,cc::tt::Indicator::None,6},
		{7,cc::tt::Tokens::Integer_0x,cc::tt::Indicator::Accept,8,cc::tt::Tokens::gram_inst_int},
		{8,(cc::tt::Tokens)';',cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
		{8,(cc::tt::Tokens)' ',cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
		{8,(cc::tt::Tokens)'\n',cc::tt::Indicator::Prefix_Accept,0,cc::tt::Tokens::none},
	};



}




#endif