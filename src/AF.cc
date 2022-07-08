
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
	//if(current > (*e).current) return NULL;//no existe el elemento

	size_t middle = b + (e - b)/ 2;
	//std::cout << "middle = " << middle << "\n";

	if(at(middle).equal(current,input))
	{
		return &at(middle);
	}
	else if(at(middle).less(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,middle + 1,e);
	}
	else if(at(middle).great(current,input))
	{
		//std::cout << "\t --> " << value << "\n";
		return search(current,input,b,middle - 1);
	}
	
	return NULL;		
}








	


const Transition<Char>* AF::transition(Char symbol)
{
	
}
const Transition<Char>* AF::transition(const Char* string)
{
	Word i = 0;
	const Transition<Char>* trans;
	while(string[i])
	{
		trans = transition(string[i]);
		if(trans->type == Type::Reject) return trans;
		i++;
	}
	
	return trans;
}

Table& AF::get_table()
{
	return table;
}


Number::Number()
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

	table.push_back({'0',Type::Incomplete,1,2});
	table.push_back({'1',Type::Incomplete,1,2});
	table.push_back({'2',Type::Incomplete,1,2});
	table.push_back({'3',Type::Incomplete,1,2});
	table.push_back({'4',Type::Incomplete,1,2});
	table.push_back({'5',Type::Incomplete,1,2});
	table.push_back({'6',Type::Incomplete,1,2});
	table.push_back({'7',Type::Incomplete,1,2});
	table.push_back({'8',Type::Incomplete,1,2});
	table.push_back({'9',Type::Incomplete,1,2});

	table.push_back({' ',Type::Ending,2,3});
	table.push_back({'\n',Type::Ending,2,3});
	table.push_back({'\t',Type::Ending,2,3});
	table.push_back({NULL,Type::Ending,2,3});
	table.push_back({EOF,Type::Ending,2,3});
		

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