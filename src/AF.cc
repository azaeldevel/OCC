
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








AF::AF() : current(0),reset(0)
{
}	
AF::AF(Status initial) : current(initial),reset(initial)
{
}

const Transition<Char>* AF::transition(Char symbol)
{
	const Transition<Char>* ret = table.search(current,symbol);

	if(ret)
	{
		current = ret->current;
		return ret;
	}

	return NULL;
}
bool AF::transition(const Char* string)
{
	current = reset;
	Word i = 0;
	while(string[i])
	{
		if(transition(string[i]) == NULL) return false;
		i++;
	}
	
	return true;
}

Table& AF::get_table()
{
	return table;
}


Number::Number()
{	
	init();	
}
Number::Number(Status initial) : cc::AF(initial)
{	
	init();
}
void Number::init()
{
	table.push_back({'0',Type::Incomplete,0,1});
	table.push_back({'1',Type::Incomplete,0,1});
	table.push_back({'2',Type::Incomplete,0,1});
	table.push_back({'3',Type::Incomplete,0,1});
	table.push_back({'4',Type::Incomplete,0,1});
	table.push_back({'5',Type::Incomplete,0,1});
	table.push_back({'6',Type::Incomplete,0,1});
	table.push_back({'7',Type::Incomplete,0,1});
	table.push_back({'8',Type::Incomplete,0,1});
	table.push_back({'9',Type::Incomplete,0,1});

	table.push_back({'0',Type::Incomplete,1,1});
	table.push_back({'1',Type::Incomplete,1,1});
	table.push_back({'2',Type::Incomplete,1,1});
	table.push_back({'3',Type::Incomplete,1,1});
	table.push_back({'4',Type::Incomplete,1,1});
	table.push_back({'5',Type::Incomplete,1,1});
	table.push_back({'6',Type::Incomplete,1,1});
	table.push_back({'7',Type::Incomplete,1,1});
	table.push_back({'8',Type::Incomplete,1,1});
	table.push_back({'9',Type::Incomplete,1,1});

	table.push_back({' ',Type::Acepting,1,2});
	table.push_back({'\n',Type::Acepting,1,2});
	table.push_back({'\t',Type::Acepting,1,2});
	table.push_back({NULL,Type::Acepting,1,2});
	table.push_back({EOF,Type::Acepting,1,2});
		

		/*{'A',Type::Incomplete,0,1},
		{'B',Type::Incomplete,0,1},
		{'C',Type::Incomplete,0,1},
		{'D',Type::Incomplete,0,1},
		{'E',Type::Incomplete,0,1},
		{'F',Type::Incomplete,0,1},

		{'a',Type::Incomplete,0,1},
		{'b',Type::Incomplete,0,1},
		{'c',Type::Incomplete,0,1},
		{'d',Type::Incomplete,0,1},
		{'e',Type::Incomplete,0,1},
		{'f',Type::Incomplete,0,1},

		{'#',Type::Incomplete,0,1},
		{'D',Type::Incomplete,0,1},	
		{'d',Type::Incomplete,0,1},
		{'B',Type::Incomplete,0,1},	
		{'b',Type::Incomplete,0,1},
		{'x',Type::Incomplete,0,1},
		{'H',Type::Incomplete,0,1},	
		{'h',Type::Incomplete,0,1},*/
	table.sort();
}



}