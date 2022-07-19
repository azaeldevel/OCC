

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

#include "tt.hh"


namespace oct::cc::a
{

/*
constexpr static const tt::Transition [][tt::MAX_SIMBOLS] = {
	//0
		{
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//backspace
			{tt::Indicator::Reject,0},//tab
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},	
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//0
			{tt::Indicator::Reject,0},//1
			{tt::Indicator::Reject,0},//2
			{tt::Indicator::Reject,0},//3
			{tt::Indicator::Reject,0},//4
			{tt::Indicator::Reject,0},//5
			{tt::Indicator::Reject,0},//6
			{tt::Indicator::Reject,0},//7
			{tt::Indicator::Reject,0},//8
			{tt::Indicator::Reject,0},//9
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//A
			{tt::Indicator::Reject,0},//B
			{tt::Indicator::Reject,0},//C
			{tt::Indicator::Reject,0},//D
			{tt::Indicator::Reject,0},//E
			{tt::Indicator::Reject,0},//F
			{tt::Indicator::Reject,0},//G
			{tt::Indicator::Reject,0},//H
			{tt::Indicator::Reject,0},//I
			{tt::Indicator::Reject,0},//J
			{tt::Indicator::Reject,0},//K
			{tt::Indicator::Reject,0},//L
			{tt::Indicator::Reject,0},//M
			{tt::Indicator::Reject,0},//N
			{tt::Indicator::Reject,0},//O
			{tt::Indicator::Reject,0},//P
			{tt::Indicator::Reject,0},//Q
			{tt::Indicator::Reject,0},//R
			{tt::Indicator::Reject,0},//S
			{tt::Indicator::Reject,0},//T
			{tt::Indicator::Reject,0},//U
			{tt::Indicator::Reject,0},//V
			{tt::Indicator::Reject,0},//W
			{tt::Indicator::Reject,0},//X
			{tt::Indicator::Reject,0},//Y
			{tt::Indicator::Reject,0},//Z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//_
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//a
			{tt::Indicator::Reject,0},//b
			{tt::Indicator::Reject,0},//c
			{tt::Indicator::Reject,0},//d
			{tt::Indicator::Reject,0},//e
			{tt::Indicator::Reject,0},//f
			{tt::Indicator::Reject,0},//g
			{tt::Indicator::Reject,0},//h
			{tt::Indicator::Reject,0},//i
			{tt::Indicator::Reject,0},//j
			{tt::Indicator::Reject,0},//k
			{tt::Indicator::Reject,0},//l
			{tt::Indicator::Reject,0},//m
			{tt::Indicator::Reject,0},//n
			{tt::Indicator::Reject,0},//o
			{tt::Indicator::Reject,0},//p
			{tt::Indicator::Reject,0},//q
			{tt::Indicator::Reject,0},//r
			{tt::Indicator::Reject,0},//s
			{tt::Indicator::Reject,0},//t
			{tt::Indicator::Reject,0},//u
			{tt::Indicator::Reject,0},//v
			{tt::Indicator::Reject,0},//w
			{tt::Indicator::Reject,0},//x
			{tt::Indicator::Reject,0},//y
			{tt::Indicator::Reject,0},//z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
		},
	};
}
*/

constexpr static const tt::Transition i8086_regs[][tt::MAX_SIMBOLS] = {
	//0
		{
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},	
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//0
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//9
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//A
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//Z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//_
			{tt::Indicator::Reject,0},
			{tt::Indicator::None,1},//a
			{tt::Indicator::None,4},//b
			{tt::Indicator::None,7},//c
			{tt::Indicator::None,10},//d
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
		},
	//1 : a?
		{
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},	
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//0
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//9
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//A
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//Z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//_
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//a
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Accept,2},//h
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Accept,2},//l
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Accept,2},//x
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
		},
	//2 : a?
		{
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},	
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//0
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//9
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//A
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//Z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//_
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//a
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//h
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//l
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//x
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},//z
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
			{tt::Indicator::Reject,0},
		},

	};



}




#endif