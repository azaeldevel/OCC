#ifndef OCTETOS_CC_AF_HH
#define OCTETOS_CC_AF_HH


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




#include "Exception.hh"
#include "tt.hh"

#include <iostream>

namespace oct::cc
{


/**
*\brief 
*
*/
template<typename T>
class AFD
{

public:
	AFD(const tt::Transition t[][tt::MAX_SIMBOLS],size_t l) : table(t), current(0), reset(0),length(l)
	{
		
	}


	unsigned short transition(const T* string)
	{
		if(not string) return 0;
		
		current = reset;
		unsigned short  i = 0;	
		const tt::Transition *prev = NULL, *actual;
		do
		{
			//std::cout << string[i] << "\n";
			//std::cout << "current : " << current << "\n";
			//std::cout << "symbol : " << string[i] << "\n";
			//std::cout << "symbol : " << (unsigned short) string[i] << "\n";
			//std::cout << "length : " << length << "\n";
			if(current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
			actual = &table[current][(unsigned char)string[i]];
			if(string[i] == '\0')
			{
				if(i == 0) return 0;
				else if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
				return 0;//si no se encontrontro transiscion
			}
			else if(actual->indicator == tt::Indicator::Reject)
			{
				if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
				return 0;
			}
			
			current = actual->next;
			prev = actual;
			i++;
		}
		while(true);

		return i;
	}
	
private:
	const tt::Transition (*table)[tt::MAX_SIMBOLS];  
	size_t length;
	tt::Status current;
	tt::Status reset;
};

}

#endif