

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
		
		{0,Tokens::file_section,Indicator::None,1,Tokens::none},
		{1,Tokens::file_code,Indicator::None,2,Tokens::none},
		{2,Tokens::gram_list_insts,Indicator::Prefix_Accept,3,Tokens::none},
		{3,(Tokens)0,Indicator::Prefix_Accept,0,Tokens::none},
	};

	/*static const cc::tt::b::TT<Tokens,Tokens> file_list_insts{
		
		{0,(tt::Tokens)'{',Indicator::None,1,Tokens::none},
		
		{1,tt::Tokens::gram_inst_mov,Indicator::Accept,1,Tokens::gram_inst_mov},
		{1,tt::Tokens::gram_inst_int,Indicator::Accept,1,Tokens::gram_inst_int},

		{1,(tt::Tokens)'}',cc::tt::Indicator::Accept_Inmediatly,0,Tokens::gram_list_insts},

	};*/

	static const cc::tt::b::TT<tt::Tokens,tt::Tokens> list_insts{
			
		//mov
		{0,Tokens::i8086_mov,Indicator::None,1,Tokens::none},
			
			//memory,accumulator
			{1,Tokens::Integer_0x,Indicator::None,2,Tokens::none},
			{1,Tokens::Identifier,Indicator::None,2,Tokens::none},
			{2,Tokens::i8086_reg_al,Indicator::Accept,3,Tokens::none},
			{2,Tokens::i8086_reg_ah,Indicator::Accept,3,Tokens::none},
			{2,Tokens::i8086_reg_ax,Indicator::Accept,3,Tokens::none},
			{3,(Tokens)' ',Indicator::Left_Eat,3,(Tokens)' '},
			{3,(Tokens)'\n',Indicator::Left_Eat,3,(Tokens)'\t'},
			{3,(Tokens)'\t',Indicator::Left_Eat,3,(Tokens)'\n'},
			{3,(Tokens)';',Indicator::Accept_Inmediatly,0,Tokens::gram_inst_mov},
						
			//register,inmendiate
			{1,Tokens::i8086_reg_al,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_ah,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_bl,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_bh,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_cl,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_ch,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_dl,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_dh,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_ax,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_bx,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_cx,Indicator::None,4,Tokens::none},
			{1,Tokens::i8086_reg_dx,Indicator::None,4,Tokens::none},
			{4,Tokens::Integer_0x,Indicator::Accept,5,Tokens::none},
			{4,Tokens::Integer,Indicator::Accept,5,Tokens::none},
			{4,Tokens::char_literal,Indicator::Accept,5,Tokens::none},
			{5,(Tokens)' ',Indicator::Left_Eat,5,(Tokens)' '},
			{5,(Tokens)'\n',Indicator::Left_Eat,5,(Tokens)'\t'},
			{5,(Tokens)'\t',Indicator::Left_Eat,5,(Tokens)'\n'},
			{5,(Tokens)';',Indicator::Accept_Inmediatly,0,Tokens::gram_inst_mov},
			
		//int
		{0,Tokens::i8086_int_token,Indicator::None,6},
		{7,Tokens::Integer_0x,Indicator::Accept,8,Tokens::gram_inst_int},		
		{8,(Tokens)' ',Indicator::Left_Eat,0,Tokens::none},		
		{8,(Tokens)'\t',Indicator::Left_Eat,0,Tokens::none},
		{8,(Tokens)'\n',Indicator::Left_Eat,0,Tokens::none},
		{8,(Tokens)';',Indicator::Prefix_Accept,0,Tokens::none},
		
	};

	static const cc::tt::b::TT<tt::Tokens,tt::Tokens> register_8{

		{0,Tokens::i8086_reg_al,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_ah,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_bl,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_bh,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_cl,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_ch,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_dl,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		{0,Tokens::i8086_reg_dh,Indicator::Accept_Inmediatly,0,Tokens::regs_8},
		
	};
	
	static const cc::tt::b::TT<tt::Tokens,tt::Tokens> register_16{

		{0,Tokens::i8086_reg_ax,Indicator::Accept_Inmediatly,0,Tokens::regs_16},
		{0,Tokens::i8086_reg_bx,Indicator::Accept_Inmediatly,0,Tokens::regs_16},
		{0,Tokens::i8086_reg_cx,Indicator::Accept_Inmediatly,0,Tokens::regs_16},
		{0,Tokens::i8086_reg_dx,Indicator::Accept_Inmediatly,0,Tokens::regs_16},
		
	};
}



#endif