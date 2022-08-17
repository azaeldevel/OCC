
#ifndef OCTETOS_CC_TT_NUMBERS_HH
#define OCTETOS_CC_TT_NUMBERS_HH


/*
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 * 
 * octetos-CC is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define LENGTH_TT(TABLE) sizeof (TABLE) / sizeof (TABLE[0])
#define TABLE(T) T,sizeof (T) / sizeof (T[0])

#include "../tt.hh"


namespace oct::cc::tt
{
	
	static const a::Transition Interger[][MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prev_Eat,0,(Tokens)'\t'},//tab
			{Indicator::Prev_Eat,0,(Tokens)'\n'},//new line
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},	
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prev_Eat,0,(Tokens)' '},// ' '
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Accept,1,(Tokens)'0'},//0
			{Indicator::Accept,1,(Tokens)'1'},
			{Indicator::Accept,1,(Tokens)'2'},
			{Indicator::Accept,1,(Tokens)'3'},
			{Indicator::Accept,1,(Tokens)'4'},
			{Indicator::Accept,1,(Tokens)'5'},
			{Indicator::Accept,1,(Tokens)'6'},
			{Indicator::Accept,1,(Tokens)'7'},
			{Indicator::Accept,1,(Tokens)'8'},
			{Indicator::Accept,1,(Tokens)'9'},//9
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//A
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//Z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//_
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//a
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
		},
	//1
		{
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},	
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Accept,1,(Tokens)'0'},//0
			{Indicator::Accept,1,(Tokens)'1'},
			{Indicator::Accept,1,(Tokens)'2'},
			{Indicator::Accept,1,(Tokens)'3'},
			{Indicator::Accept,1,(Tokens)'4'},
			{Indicator::Accept,1,(Tokens)'5'},
			{Indicator::Accept,1,(Tokens)'6'},
			{Indicator::Accept,1,(Tokens)'7'},
			{Indicator::Accept,1,(Tokens)'8'},
			{Indicator::Accept,1,(Tokens)'9'},//9
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//A
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//Z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//_
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//a
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
		}
	};

	static const a::Transition Integer_0x[][tt::MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prev_Eat,0,(Tokens)'\t'},//tab
			{Indicator::Prev_Eat,0,(Tokens)'\n'},//new line
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},	
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prev_Eat,0,(Tokens)' '},//' '
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::None,1,(Tokens)'0'},//0
			{Indicator::Reject,0,Tokens::none},//1
			{Indicator::Reject,0,Tokens::none},//2
			{Indicator::Reject,0,Tokens::none},//3
			{Indicator::Reject,0,Tokens::none},//4
			{Indicator::Reject,0,Tokens::none},//5
			{Indicator::Reject,0,Tokens::none},//6
			{Indicator::Reject,0,Tokens::none},//7
			{Indicator::Reject,0,Tokens::none},//8
			{Indicator::Reject,0,Tokens::none},//9
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//A
			{Indicator::Reject,0,Tokens::none},//B
			{Indicator::Reject,0,Tokens::none},//C
			{Indicator::Reject,0,Tokens::none},//D
			{Indicator::Reject,0,Tokens::none},//E
			{Indicator::Reject,0,Tokens::none},//F
			{Indicator::Reject,0,Tokens::none},//G
			{Indicator::Reject,0,Tokens::none},//H
			{Indicator::Reject,0,Tokens::none},//I
			{Indicator::Reject,0,Tokens::none},//J
			{Indicator::Reject,0,Tokens::none},//K
			{Indicator::Reject,0,Tokens::none},//L
			{Indicator::Reject,0,Tokens::none},//M
			{Indicator::Reject,0,Tokens::none},//N
			{Indicator::Reject,0,Tokens::none},//O
			{Indicator::Reject,0,Tokens::none},//P
			{Indicator::Reject,0,Tokens::none},//Q
			{Indicator::Reject,0,Tokens::none},//R
			{Indicator::Reject,0,Tokens::none},//S
			{Indicator::Reject,0,Tokens::none},//T
			{Indicator::Reject,0,Tokens::none},//U
			{Indicator::Reject,0,Tokens::none},//V
			{Indicator::Reject,0,Tokens::none},//W
			{Indicator::Reject,0,Tokens::none},//X
			{Indicator::Reject,0,Tokens::none},//Y
			{Indicator::Reject,0,Tokens::none},//Z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//_
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//a
			{Indicator::Reject,0,Tokens::none},//b
			{Indicator::Reject,0,Tokens::none},//c
			{Indicator::Reject,0,Tokens::none},//d
			{Indicator::Reject,0,Tokens::none},//e
			{Indicator::Reject,0,Tokens::none},//f
			{Indicator::Reject,0,Tokens::none},//g
			{Indicator::Reject,0,Tokens::none},//h
			{Indicator::Reject,0,Tokens::none},//i
			{Indicator::Reject,0,Tokens::none},//j
			{Indicator::Reject,0,Tokens::none},//k
			{Indicator::Reject,0,Tokens::none},//l
			{Indicator::Reject,0,Tokens::none},//m
			{Indicator::Reject,0,Tokens::none},//n
			{Indicator::Reject,0,Tokens::none},//o
			{Indicator::Reject,0,Tokens::none},//p
			{Indicator::Reject,0,Tokens::none},//q
			{Indicator::Reject,0,Tokens::none},//r
			{Indicator::Reject,0,Tokens::none},//s
			{Indicator::Reject,0,Tokens::none},//t
			{Indicator::Reject,0,Tokens::none},//u
			{Indicator::Reject,0,Tokens::none},//v
			{Indicator::Reject,0,Tokens::none},//w
			{Indicator::Reject,0,Tokens::none},//x
			{Indicator::Reject,0,Tokens::none},//y
			{Indicator::Reject,0,Tokens::none},//z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
		},
		// 1 : x
		{
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//tab
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},	
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//' '
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//0
			{Indicator::Reject,0,Tokens::none},//1
			{Indicator::Reject,0,Tokens::none},//2
			{Indicator::Reject,0,Tokens::none},//3
			{Indicator::Reject,0,Tokens::none},//4
			{Indicator::Reject,0,Tokens::none},//5
			{Indicator::Reject,0,Tokens::none},//6
			{Indicator::Reject,0,Tokens::none},//7
			{Indicator::Reject,0,Tokens::none},//8
			{Indicator::Reject,0,Tokens::none},//9
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//A
			{Indicator::Reject,0,Tokens::none},//B
			{Indicator::Reject,0,Tokens::none},//C
			{Indicator::Reject,0,Tokens::none},//D
			{Indicator::Reject,0,Tokens::none},//E
			{Indicator::Reject,0,Tokens::none},//F
			{Indicator::Reject,0,Tokens::none},//G
			{Indicator::Reject,0,Tokens::none},//H
			{Indicator::Reject,0,Tokens::none},//I
			{Indicator::Reject,0,Tokens::none},//J
			{Indicator::Reject,0,Tokens::none},//K
			{Indicator::Reject,0,Tokens::none},//L
			{Indicator::Reject,0,Tokens::none},//M
			{Indicator::Reject,0,Tokens::none},//N
			{Indicator::Reject,0,Tokens::none},//O
			{Indicator::Reject,0,Tokens::none},//P
			{Indicator::Reject,0,Tokens::none},//Q
			{Indicator::Reject,0,Tokens::none},//R
			{Indicator::Reject,0,Tokens::none},//S
			{Indicator::Reject,0,Tokens::none},//T
			{Indicator::Reject,0,Tokens::none},//U
			{Indicator::Reject,0,Tokens::none},//V
			{Indicator::Reject,0,Tokens::none},//W
			{Indicator::Reject,0,Tokens::none},//X
			{Indicator::Reject,0,Tokens::none},//Y
			{Indicator::Reject,0,Tokens::none},//Z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//_
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//a
			{Indicator::Reject,0,Tokens::none},//b
			{Indicator::Reject,0,Tokens::none},//c
			{Indicator::Reject,0,Tokens::none},//d
			{Indicator::Reject,0,Tokens::none},//e
			{Indicator::Reject,0,Tokens::none},//f
			{Indicator::Reject,0,Tokens::none},//g
			{Indicator::Reject,0,Tokens::none},//h
			{Indicator::Reject,0,Tokens::none},//i
			{Indicator::Reject,0,Tokens::none},//j
			{Indicator::Reject,0,Tokens::none},//k
			{Indicator::Reject,0,Tokens::none},//l
			{Indicator::Reject,0,Tokens::none},//m
			{Indicator::Reject,0,Tokens::none},//n
			{Indicator::Reject,0,Tokens::none},//o
			{Indicator::Reject,0,Tokens::none},//p
			{Indicator::Reject,0,Tokens::none},//q
			{Indicator::Reject,0,Tokens::none},//r
			{Indicator::Reject,0,Tokens::none},//s
			{Indicator::Reject,0,Tokens::none},//t
			{Indicator::Reject,0,Tokens::none},//u
			{Indicator::Reject,0,Tokens::none},//v
			{Indicator::Reject,0,Tokens::none},//w
			{Indicator::None,2,(Tokens)'x'},//x
			{Indicator::Reject,0,Tokens::none},//y
			{Indicator::Reject,0,Tokens::none},//z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
		},
		//2 : ae10		
		{
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prefix_Accept,0,(Tokens)'\t'},//tab
			{Indicator::Prefix_Accept,0,(Tokens)'\n'},//new line
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},	
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Prefix_Accept,0,(Tokens)' '},//' '
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Accept,2,Tokens::Integer_0x},//0
			{Indicator::Accept,2,Tokens::Integer_0x},//1
			{Indicator::Accept,2,Tokens::Integer_0x},//2
			{Indicator::Accept,2,Tokens::Integer_0x},//3
			{Indicator::Accept,2,Tokens::Integer_0x},//4
			{Indicator::Accept,2,Tokens::Integer_0x},//5
			{Indicator::Accept,2,Tokens::Integer_0x},//6
			{Indicator::Accept,2,Tokens::Integer_0x},//7
			{Indicator::Accept,2,Tokens::Integer_0x},//8
			{Indicator::Accept,2,Tokens::Integer_0x},//9
			{Indicator::Reject,0,Tokens::none},//:
			{Indicator::Prefix_Accept,0,(Tokens)';'},//;
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Accept,2,Tokens::Integer_0x},//A
			{Indicator::Accept,2,Tokens::Integer_0x},//B
			{Indicator::Accept,2,Tokens::Integer_0x},//C
			{Indicator::Accept,2,Tokens::Integer_0x},//D
			{Indicator::Accept,2,Tokens::Integer_0x},//E
			{Indicator::Accept,2,Tokens::Integer_0x},//F
			{Indicator::Reject,0,Tokens::none},//G
			{Indicator::Reject,0,Tokens::none},//H
			{Indicator::Reject,0,Tokens::none},//I
			{Indicator::Reject,0,Tokens::none},//J
			{Indicator::Reject,0,Tokens::none},//K
			{Indicator::Reject,0,Tokens::none},//L
			{Indicator::Reject,0,Tokens::none},//M
			{Indicator::Reject,0,Tokens::none},//N
			{Indicator::Reject,0,Tokens::none},//O
			{Indicator::Reject,0,Tokens::none},//P
			{Indicator::Reject,0,Tokens::none},//Q
			{Indicator::Reject,0,Tokens::none},//R
			{Indicator::Reject,0,Tokens::none},//S
			{Indicator::Reject,0,Tokens::none},//T
			{Indicator::Reject,0,Tokens::none},//U
			{Indicator::Reject,0,Tokens::none},//V
			{Indicator::Reject,0,Tokens::none},//W
			{Indicator::Reject,0,Tokens::none},//X
			{Indicator::Reject,0,Tokens::none},//Y
			{Indicator::Reject,0,Tokens::none},//Z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},//_
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Accept,2,Tokens::Integer_0x},//a
			{Indicator::Accept,2,Tokens::Integer_0x},//b
			{Indicator::Accept,2,Tokens::Integer_0x},//c
			{Indicator::Accept,2,Tokens::Integer_0x},//d
			{Indicator::Accept,2,Tokens::Integer_0x},//e
			{Indicator::Accept,2,Tokens::Integer_0x},//f
			{Indicator::Reject,0,Tokens::none},//g
			{Indicator::Reject,0,Tokens::none},//h
			{Indicator::Reject,0,Tokens::none},//i
			{Indicator::Reject,0,Tokens::none},//j
			{Indicator::Reject,0,Tokens::none},//k
			{Indicator::Reject,0,Tokens::none},//l
			{Indicator::Reject,0,Tokens::none},//m
			{Indicator::Reject,0,Tokens::none},//n
			{Indicator::Reject,0,Tokens::none},//o
			{Indicator::Reject,0,Tokens::none},//p
			{Indicator::Reject,0,Tokens::none},//q
			{Indicator::Reject,0,Tokens::none},//r
			{Indicator::Reject,0,Tokens::none},//s
			{Indicator::Reject,0,Tokens::none},//t
			{Indicator::Reject,0,Tokens::none},//u
			{Indicator::Reject,0,Tokens::none},//v
			{Indicator::Reject,0,Tokens::none},//w
			{Indicator::Reject,0,Tokens::none},//x
			{Indicator::Reject,0,Tokens::none},//y
			{Indicator::Reject,0,Tokens::none},//z
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
			{Indicator::Reject,0,Tokens::none},
		},
	};

}

#endif