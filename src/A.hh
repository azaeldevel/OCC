

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

#include <cctype>
#include "A-tt.hh"


namespace oct::cc::a
{

template<typename C> class BuildUnit : public dfa::a::DFA<C>
{

public:
	BuildUnit(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l) : dfa::a::DFA<C>(t,l)
	{		
	}

	Word transition(const C* string)
	{
		
		
	}
	
	
private:
	
};

}




#endif