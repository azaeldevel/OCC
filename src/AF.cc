
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
#include "Exception.hh"



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







Automata::Automata() : current(0),reset(0),table(NULL)
{
}
Automata::Automata(const Table& t) : current(0),reset(0),table(&t)
{
	if(not check(t)) throw Exception(Exception::Q0_NOT_ACCEPTABLE,__FILE__,__LINE__);
}
Automata::Automata(Status i,const Table& t) : current(i),reset(i),table(&t)
{
	if(not check(t)) throw Exception(Exception::Q0_NOT_ACCEPTABLE,__FILE__,__LINE__);
}

const Transition<Char>* Automata::transition(Char symbol)
{
	std::cout << "current : " << current << "\n";
	std::cout << "symbol : " << symbol << "\n";
	const Transition<Char>* ret = table->search(current,symbol);
	if(ret)
	{
		ret->print(std::cout);
		current = ret->next;
		//std::cout << "current : " << current << "\n";
		//std::cout << "symbol : " << symbol << "\n";
		return ret;
	}

	return NULL;
}
bool Automata::transition(const Char* string)
{
	if(not string) return false;
	
	current = reset;
	Word i = 0;	
	const Transition<Char>* ret;
	do
	{
		//std::cout << string[i] << "\n";
		ret = transition(string[i]);
		if(not ret) return false;//si no se encontrontro transiscion
		if(ret->indicator == Indicator::Reject) return false;//si no pertenece al lenguaje
		if(ret->indicator == Indicator::Accept) return true;
		if(string[i] == '\0') return false;
		//std::cout << string[i] << "\n";
		i++;
	}
	while(ret->indicator == Indicator::None);
	
	return false;
}

/*Table& AF::get_table()
{
	return table;
}*/
const Table* Automata::get_table() const
{
	return table;
}
void Automata::load(Status initial,const Table& table)
{
	current = initial;
	reset = initial;
	this->table = &table;
}
bool Automata::check(const Table& t)
{
	//std::cout << "reset :" << reset << "\n";
	for(const Transition<Char>& t : t)
	{
		if(t.next == reset) return false;
	}

	return true;
}
	


}