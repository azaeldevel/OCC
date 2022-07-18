

#ifndef OCTETOS_CC_TT2_HH
#define OCTETOS_CC_TT2_HH


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

namespace oct::cc::tt
{

typedef unsigned long long int Word;
typedef Word Status;
constexpr static const unsigned char MAX_SIMBOLS = 128;

enum class Indicator : unsigned char
{
	None,
	Accept,
	Reject,
	End
};


struct Transition
{
	Indicator indicator;
	Status next;
};

constexpr static const Transition Identifier_C[][MAX_SIMBOLS] = {
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
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
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

}

#endif