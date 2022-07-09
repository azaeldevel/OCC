
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

#include <algorithm>


#include "AF.hh"



namespace oct::cc
{





	 
Table::Table(std::initializer_list<Transition<Char>>t) : std::vector<Transition<Char>>(t)
{
	sort();
}
Table::Table() 
{
}

void Table::sort()
{
	std::sort(begin(),end());
}

Transition<Char>* Table::search(Status current,Char input)
{
	return search(current,input, 0,size() - 1);
}
const Transition<Char>* Table::search(Status current,Char input) const
{
	return search(current,input, 0,size() - 1);
}
Transition<Char>* Table::search(Status current,Char input,size_t b, size_t e)
{
	if(b > e) return NULL;
	if(b - e == 1) return NULL;

	//std::cout << "b = " << b << "\n";
	//std::cout << "e = " << e << "\n";
	size_t middle = b + ((e - b)/ 2);
	//std::cout << "middle = " << middle << "\n";

	if(at(middle).less(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,middle + 1,e);
	}
	else if(at(middle).great(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,b,middle - 1);
	}
	else if(at(middle).equal(current,input))
	{
		return &at(middle);
	}
		
	return NULL;		
}
const Transition<Char>* Table::search(Status current,Char input,size_t b, size_t e) const
{
	if(b > e) return NULL;
	if(b - e == 1) return NULL;

	//std::cout << "b = " << b << "\n";
	//std::cout << "e = " << e << "\n";
	size_t middle = b + ((e - b)/ 2);
	//std::cout << "middle = " << middle << "\n";

	if(at(middle).less(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,middle + 1,e);
	}
	else if(at(middle).great(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,b,middle - 1);
	}
	else if(at(middle).equal(current,input))
	{
		return &at(middle);
	}
		
	return NULL;		
}







AFD::AFD() : current(0),reset(0),table(NULL)
{
}
AFD::AFD(Status i,const Table& t) : current(i),reset(i),table(&t)
{
}

const Transition<Char>* AFD::transition(Char symbol)
{
	//std::cout << "current : " << current << "\n";
	//std::cout << "symbol : " << symbol << "\n";
	const Transition<Char>* ret = table->search(current,symbol);
	if(ret != NULL)
	{
		current = ret->next;
		//std::cout << "current : " << current << "\n";
		//std::cout << "symbol : " << symbol << "\n";
		return ret;
	}

	return NULL;
}
bool AFD::transition(const Char* string)
{
	current = reset;
	Word i = 0;
	while(string[i])
	{
		//std::cout << string[i] << "\n";
		if(not transition(string[i])) return false;
		//std::cout << string[i] << "\n";
		i++;
	}
	
	return true;
}

/*Table& AF::get_table()
{
	return table;
}*/
const Table* AFD::get_table() const
{
	return table;
}
void AFD::load(Status initial,const Table& table)
{
	current = initial;
	reset = initial;
	this->table = &table;
}

	


}