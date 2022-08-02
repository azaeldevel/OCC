
#ifndef OCTETOS_CC_TT_HH
#define OCTETOS_CC_TT_HH


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


#include <vector>
#include <octetos/core/core.hh>


#include "Exception.hh"

namespace oct::cc::tt
{

//typedef unsigned long long int Word;
typedef Word Status;
typedef Word Token;

constexpr static const unsigned char MAX_SIMBOLS = 128;

enum class Indicator : Status
{
	None,
	Accept,
	Reject,
	Prefix_Accept,
};

namespace a
{
	struct Transition
	{
		Indicator indicator;
		Status next;
		Word token;
	};
	
	struct Selector
	{
		unsigned int i;
		unsigned short j;
	};

	static const Token base_token = 1024;
	
	bool check(const Transition (*t)[MAX_SIMBOLS],Word s, std::vector<Selector>& errors);
	
/*
constexpr static const Transition [][tt::MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//0
			{Indicator::Reject,0},//1
			{Indicator::Reject,0},//2
			{Indicator::Reject,0},//3
			{Indicator::Reject,0},//4
			{Indicator::Reject,0},//5
			{Indicator::Reject,0},//6
			{Indicator::Reject,0},//7
			{Indicator::Reject,0},//8
			{Indicator::Reject,0},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},//B
			{Indicator::Reject,0},//C
			{Indicator::Reject,0},//D
			{Indicator::Reject,0},//E
			{Indicator::Reject,0},//F
			{Indicator::Reject,0},//G
			{Indicator::Reject,0},//H
			{Indicator::Reject,0},//I
			{Indicator::Reject,0},//J
			{Indicator::Reject,0},//K
			{Indicator::Reject,0},//L
			{Indicator::Reject,0},//M
			{Indicator::Reject,0},//N
			{Indicator::Reject,0},//O
			{Indicator::Reject,0},//P
			{Indicator::Reject,0},//Q
			{Indicator::Reject,0},//R
			{Indicator::Reject,0},//S
			{Indicator::Reject,0},//T
			{Indicator::Reject,0},//U
			{Indicator::Reject,0},//V
			{Indicator::Reject,0},//W
			{Indicator::Reject,0},//X
			{Indicator::Reject,0},//Y
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},//b
			{Indicator::Reject,0},//c
			{Indicator::Reject,0},//d
			{Indicator::Reject,0},//e
			{Indicator::Reject,0},//f
			{Indicator::Reject,0},//g
			{Indicator::Reject,0},//h
			{Indicator::Reject,0},//i
			{Indicator::Reject,0},//j
			{Indicator::Reject,0},//k
			{Indicator::Reject,0},//l
			{Indicator::Reject,0},//m
			{Indicator::Reject,0},//n
			{Indicator::Reject,0},//o
			{Indicator::Reject,0},//p
			{Indicator::Reject,0},//q
			{Indicator::Reject,0},//r
			{Indicator::Reject,0},//s
			{Indicator::Reject,0},//t
			{Indicator::Reject,0},//u
			{Indicator::Reject,0},//v
			{Indicator::Reject,0},//w
			{Indicator::Reject,0},//x
			{Indicator::Reject,0},//y
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
	};
*/


constexpr static const Transition Identifier[][MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//0
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//A
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//_
			{Indicator::Reject,0},
			{Indicator::Accept,1},//a
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
	//1
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Prefix_Accept,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Prefix_Accept,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//0
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//A
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//_
			{Indicator::Reject,0},
			{Indicator::Accept,1},//a
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		}
};

constexpr static const Transition Interger[][MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Prefix_Accept,0},// ' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//0
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
	//1
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,1},//0
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},
			{Indicator::Accept,1},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		}
	};

constexpr static const tt::a::Transition Integer_0x[][tt::MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::None,1},//0
			{Indicator::Reject,0},//1
			{Indicator::Reject,0},//2
			{Indicator::Reject,0},//3
			{Indicator::Reject,0},//4
			{Indicator::Reject,0},//5
			{Indicator::Reject,0},//6
			{Indicator::Reject,0},//7
			{Indicator::Reject,0},//8
			{Indicator::Reject,0},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},//B
			{Indicator::Reject,0},//C
			{Indicator::Reject,0},//D
			{Indicator::Reject,0},//E
			{Indicator::Reject,0},//F
			{Indicator::Reject,0},//G
			{Indicator::Reject,0},//H
			{Indicator::Reject,0},//I
			{Indicator::Reject,0},//J
			{Indicator::Reject,0},//K
			{Indicator::Reject,0},//L
			{Indicator::Reject,0},//M
			{Indicator::Reject,0},//N
			{Indicator::Reject,0},//O
			{Indicator::Reject,0},//P
			{Indicator::Reject,0},//Q
			{Indicator::Reject,0},//R
			{Indicator::Reject,0},//S
			{Indicator::Reject,0},//T
			{Indicator::Reject,0},//U
			{Indicator::Reject,0},//V
			{Indicator::Reject,0},//W
			{Indicator::Reject,0},//X
			{Indicator::Reject,0},//Y
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},//b
			{Indicator::Reject,0},//c
			{Indicator::Reject,0},//d
			{Indicator::Reject,0},//e
			{Indicator::Reject,0},//f
			{Indicator::Reject,0},//g
			{Indicator::Reject,0},//h
			{Indicator::Reject,0},//i
			{Indicator::Reject,0},//j
			{Indicator::Reject,0},//k
			{Indicator::Reject,0},//l
			{Indicator::Reject,0},//m
			{Indicator::Reject,0},//n
			{Indicator::Reject,0},//o
			{Indicator::Reject,0},//p
			{Indicator::Reject,0},//q
			{Indicator::Reject,0},//r
			{Indicator::Reject,0},//s
			{Indicator::Reject,0},//t
			{Indicator::Reject,0},//u
			{Indicator::Reject,0},//v
			{Indicator::Reject,0},//w
			{Indicator::Reject,0},//x
			{Indicator::Reject,0},//y
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
		// 1 : x
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//0
			{Indicator::Reject,0},//1
			{Indicator::Reject,0},//2
			{Indicator::Reject,0},//3
			{Indicator::Reject,0},//4
			{Indicator::Reject,0},//5
			{Indicator::Reject,0},//6
			{Indicator::Reject,0},//7
			{Indicator::Reject,0},//8
			{Indicator::Reject,0},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},//B
			{Indicator::Reject,0},//C
			{Indicator::Reject,0},//D
			{Indicator::Reject,0},//E
			{Indicator::Reject,0},//F
			{Indicator::Reject,0},//G
			{Indicator::Reject,0},//H
			{Indicator::Reject,0},//I
			{Indicator::Reject,0},//J
			{Indicator::Reject,0},//K
			{Indicator::Reject,0},//L
			{Indicator::Reject,0},//M
			{Indicator::Reject,0},//N
			{Indicator::Reject,0},//O
			{Indicator::Reject,0},//P
			{Indicator::Reject,0},//Q
			{Indicator::Reject,0},//R
			{Indicator::Reject,0},//S
			{Indicator::Reject,0},//T
			{Indicator::Reject,0},//U
			{Indicator::Reject,0},//V
			{Indicator::Reject,0},//W
			{Indicator::Reject,0},//X
			{Indicator::Reject,0},//Y
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},//b
			{Indicator::Reject,0},//c
			{Indicator::Reject,0},//d
			{Indicator::Reject,0},//e
			{Indicator::Reject,0},//f
			{Indicator::Reject,0},//g
			{Indicator::Reject,0},//h
			{Indicator::Reject,0},//i
			{Indicator::Reject,0},//j
			{Indicator::Reject,0},//k
			{Indicator::Reject,0},//l
			{Indicator::Reject,0},//m
			{Indicator::Reject,0},//n
			{Indicator::Reject,0},//o
			{Indicator::Reject,0},//p
			{Indicator::Reject,0},//q
			{Indicator::Reject,0},//r
			{Indicator::Reject,0},//s
			{Indicator::Reject,0},//t
			{Indicator::Reject,0},//u
			{Indicator::Reject,0},//v
			{Indicator::Reject,0},//w
			{Indicator::None,2},//x
			{Indicator::Reject,0},//y
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
		//2 : ae10		
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Prefix_Accept,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Prefix_Accept,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,2},//0
			{Indicator::Accept,2},//1
			{Indicator::Accept,2},//2
			{Indicator::Accept,2},//3
			{Indicator::Accept,2},//4
			{Indicator::Accept,2},//5
			{Indicator::Accept,2},//6
			{Indicator::Accept,2},//7
			{Indicator::Accept,2},//8
			{Indicator::Accept,2},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Accept,2},//A
			{Indicator::Accept,2},//B
			{Indicator::Accept,2},//C
			{Indicator::Accept,2},//D
			{Indicator::Accept,2},//E
			{Indicator::Accept,2},//F
			{Indicator::Reject,0},//G
			{Indicator::Reject,0},//H
			{Indicator::Reject,0},//I
			{Indicator::Reject,0},//J
			{Indicator::Reject,0},//K
			{Indicator::Reject,0},//L
			{Indicator::Reject,0},//M
			{Indicator::Reject,0},//N
			{Indicator::Reject,0},//O
			{Indicator::Reject,0},//P
			{Indicator::Reject,0},//Q
			{Indicator::Reject,0},//R
			{Indicator::Reject,0},//S
			{Indicator::Reject,0},//T
			{Indicator::Reject,0},//U
			{Indicator::Reject,0},//V
			{Indicator::Reject,0},//W
			{Indicator::Reject,0},//X
			{Indicator::Reject,0},//Y
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Accept,2},//a
			{Indicator::Accept,2},//b
			{Indicator::Accept,2},//c
			{Indicator::Accept,2},//d
			{Indicator::Accept,2},//e
			{Indicator::Accept,2},//f
			{Indicator::Reject,0},//g
			{Indicator::Reject,0},//h
			{Indicator::Reject,0},//i
			{Indicator::Reject,0},//j
			{Indicator::Reject,0},//k
			{Indicator::Reject,0},//l
			{Indicator::Reject,0},//m
			{Indicator::Reject,0},//n
			{Indicator::Reject,0},//o
			{Indicator::Reject,0},//p
			{Indicator::Reject,0},//q
			{Indicator::Reject,0},//r
			{Indicator::Reject,0},//s
			{Indicator::Reject,0},//t
			{Indicator::Reject,0},//u
			{Indicator::Reject,0},//v
			{Indicator::Reject,0},//w
			{Indicator::Reject,0},//x
			{Indicator::Reject,0},//y
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
	};

}
namespace b
{
	template<typename T>
	struct Transition //transition B
	{
		Status current;
		T input;
		Indicator indicator;
		Status next;

		bool operator < (const Transition<T>& obj) const
		{
			if(current < obj.current) return true;
			else if(current > obj.current) return false;
			else 
			{
				if(input < obj.input) return true;
				else if(input > obj.input) return false;
				else throw Exception(Exception::NOT_UNIQUE,__FILE__,__LINE__);
			}

			return false;
		}
		bool operator > (const Transition<T>& obj) const
		{
			if(current > obj.current) return true;
			else if(current < obj.current) return false;
			else 
			{
				if(input > obj.input) return true;
				else if(input < obj.input) return false;
				else throw Exception(Exception::NOT_UNIQUE,__FILE__,__LINE__);
			}

			return false;
		}
		bool equal(Status current,T input)const
		{
			if(this->current == current and this->input == input) return true;

			return false;
		}
		bool less(Status current,T input)const
		{
			if(this->current < current) return true;
			else if(this->current > current) return false;
			else 
			{
				if(this->input < input) return true;
				else if(this->input > input) return false;
				else return false;
			}

			return false;
		}
		bool great(Status current,T input)const
		{
			if(this->current > current) return true;
			else if(this->current < current) return false;
			else 
			{
				if(this->input > input) return true;
				else if(this->input < input) return false;
				else return false;
			}

			return false;
		}

		void print(std::ostream& out) const
		{
			if(input == '\n')
			{
				out << current << "--New line->" << next << "\n";
			}
			else if(input == '\t')
			{
				out << current << "--Tabulator->" << next << "\n";
			}
			else if(input == ' ')
			{
				out << current << "--Espace->" << next << "\n";
			}
			else if(input == '\0')
			{
				out << current << "--\\0->" << next << "\n";
			}
			else if((Status) input > 128)
			{
				out << current << "--" << (unsigned int)input << "->" << next << "\n";
			}
			else
			{
				out << current << "--" << input << "->" << next << "\n";
			}
		}
		void print(std::wostream& out) const
		{
			if(input == '\n')
			{
				out << current << "--New line->" << next << "\n";
			}
			else if(input == '\t')
			{
				out << current << "--Tabulator->" << next << "\n";
			}
			else if(input == ' ')
			{
				out << current << "--Espace->" << next << "\n";
			}
			else if(input == '\0')
			{
				out << current << "--\\0->" << next << "\n";
			}
			else if((Status) input > 128)
			{
				out << current << "--" << (unsigned int)input << "->" << next << "\n";
			}
			else
			{
				out << current << "--" << input << "->" << next << "\n";
			}
		}
	};

constexpr static const Transition<char> Identifier[] = {

		{0,'A',Indicator::Accept,1},
		{0,'B',Indicator::Accept,1},
		{0,'C',Indicator::Accept,1},
		{0,'D',Indicator::Accept,1},
		{0,'E',Indicator::Accept,1},
		{0,'F',Indicator::Accept,1},
		{0,'G',Indicator::Accept,1},
		{0,'H',Indicator::Accept,1},
		{0,'I',Indicator::Accept,1},
		{0,'J',Indicator::Accept,1},
		{0,'K',Indicator::Accept,1},
		{0,'L',Indicator::Accept,1},
		{0,'M',Indicator::Accept,1},
		{0,'N',Indicator::Accept,1},
		{0,'O',Indicator::Accept,1},
		{0,'P',Indicator::Accept,1},
		{0,'Q',Indicator::Accept,1},
		{0,'R',Indicator::Accept,1},
		{0,'S',Indicator::Accept,1},
		{0,'T',Indicator::Accept,1},
		{0,'U',Indicator::Accept,1},
		{0,'V',Indicator::Accept,1},
		{0,'W',Indicator::Accept,1},
		{0,'X',Indicator::Accept,1},
		{0,'Y',Indicator::Accept,1},
		{0,'Z',Indicator::Accept,1},

		{0,'_',Indicator::Accept,1},

		{0,'a',Indicator::Accept,1},
		{0,'b',Indicator::Accept,1},
		{0,'c',Indicator::Accept,1},
		{0,'d',Indicator::Accept,1},
		{0,'e',Indicator::Accept,1},
		{0,'f',Indicator::Accept,1},
		{0,'g',Indicator::Accept,1},
		{0,'h',Indicator::Accept,1},
		{0,'i',Indicator::Accept,1},
		{0,'j',Indicator::Accept,1},
		{0,'k',Indicator::Accept,1},
		{0,'l',Indicator::Accept,1},
		{0,'m',Indicator::Accept,1},
		{0,'n',Indicator::Accept,1},
		{0,'o',Indicator::Accept,1},
		{0,'p',Indicator::Accept,1},
		{0,'q',Indicator::Accept,1},
		{0,'r',Indicator::Accept,1},
		{0,'s',Indicator::Accept,1},
		{0,'t',Indicator::Accept,1},
		{0,'u',Indicator::Accept,1},
		{0,'v',Indicator::Accept,1},
		{0,'w',Indicator::Accept,1},
		{0,'x',Indicator::Accept,1},
		{0,'y',Indicator::Accept,1},
		{0,'z',Indicator::Accept,1},

		{1,'0',Indicator::Accept,1},
		{1,'1',Indicator::Accept,1},
		{1,'2',Indicator::Accept,1},
		{1,'3',Indicator::Accept,1},
		{1,'4',Indicator::Accept,1},
		{1,'5',Indicator::Accept,1},
		{1,'6',Indicator::Accept,1},
		{1,'7',Indicator::Accept,1},
		{1,'8',Indicator::Accept,1},
		{1,'9',Indicator::Accept,1},

		{1,'A',Indicator::Accept,1},
		{1,'B',Indicator::Accept,1},
		{1,'C',Indicator::Accept,1},
		{1,'D',Indicator::Accept,1},
		{1,'E',Indicator::Accept,1},
		{1,'F',Indicator::Accept,1},
		{1,'G',Indicator::Accept,1},
		{1,'H',Indicator::Accept,1},
		{1,'I',Indicator::Accept,1},
		{1,'J',Indicator::Accept,1},
		{1,'K',Indicator::Accept,1},
		{1,'L',Indicator::Accept,1},
		{1,'M',Indicator::Accept,1},
		{1,'N',Indicator::Accept,1},
		{1,'O',Indicator::Accept,1},
		{1,'P',Indicator::Accept,1},
		{1,'Q',Indicator::Accept,1},
		{1,'R',Indicator::Accept,1},
		{1,'S',Indicator::Accept,1},
		{1,'T',Indicator::Accept,1},
		{1,'U',Indicator::Accept,1},
		{1,'V',Indicator::Accept,1},
		{1,'W',Indicator::Accept,1},
		{1,'X',Indicator::Accept,1},
		{1,'Y',Indicator::Accept,1},
		{1,'Z',Indicator::Accept,1},

		{1,'_',Indicator::Accept,1},

		{1,'a',Indicator::Accept,1},
		{1,'b',Indicator::Accept,1},
		{1,'c',Indicator::Accept,1},
		{1,'d',Indicator::Accept,1},
		{1,'e',Indicator::Accept,1},
		{1,'f',Indicator::Accept,1},
		{1,'g',Indicator::Accept,1},
		{1,'h',Indicator::Accept,1},
		{1,'i',Indicator::Accept,1},
		{1,'j',Indicator::Accept,1},
		{1,'k',Indicator::Accept,1},
		{1,'l',Indicator::Accept,1},
		{1,'m',Indicator::Accept,1},
		{1,'n',Indicator::Accept,1},
		{1,'o',Indicator::Accept,1},
		{1,'p',Indicator::Accept,1},
		{1,'q',Indicator::Accept,1},
		{1,'r',Indicator::Accept,1},
		{1,'s',Indicator::Accept,1},
		{1,'t',Indicator::Accept,1},
		{1,'u',Indicator::Accept,1},
		{1,'v',Indicator::Accept,1},
		{1,'w',Indicator::Accept,1},
		{1,'x',Indicator::Accept,1},
		{1,'y',Indicator::Accept,1},
		{1,'z',Indicator::Accept,1},
	};



constexpr static const Transition<char> Integer[]  {
		{0,'0',Indicator::Accept,1},
		{0,'1',Indicator::Accept,1},
		{0,'2',Indicator::Accept,1},
		{0,'3',Indicator::Accept,1},
		{0,'4',Indicator::Accept,1},
		{0,'5',Indicator::Accept,1},
		{0,'6',Indicator::Accept,1},
		{0,'7',Indicator::Accept,1},
		{0,'8',Indicator::Accept,1},
		{0,'9',Indicator::Accept,1},
		{0,' ',Indicator::Prefix_Accept,1},		
		
		{1,'0',Indicator::Accept,1},
		{1,'1',Indicator::Accept,1},
		{1,'2',Indicator::Accept,1},
		{1,'3',Indicator::Accept,1},
		{1,'4',Indicator::Accept,1},
		{1,'5',Indicator::Accept,1},
		{1,'6',Indicator::Accept,1},
		{1,'7',Indicator::Accept,1},
		{1,'8',Indicator::Accept,1},
		{1,'9',Indicator::Accept,1},
		{1,' ',Indicator::Prefix_Accept,1},		
	};


}



}

#endif