
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







/*AF::AF() : current(0),reset(0)
{
}*/	
AFD::AFD(Status i,const Table& t) : current(i),reset(i),table(t)
{
}

const Transition<Char>* AFD::transition(Char symbol)
{
	//std::cout << "current : " << current << "\n";
	//std::cout << "symbol : " << symbol << "\n";
	const Transition<Char>* ret = table.search(current,symbol);
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
const Table& AFD::get_table() const
{
	return table;
}


namespace afs
{
	
	const Table Numberx10::table {
		{0,'0',false,1},
		
		{0,'1',false,1},
		{0,'2',false,1},
		{0,'3',false,1},
		{0,'4',false,1},
		{0,'5',false,1},
		{0,'6',false,1},
		{0,'7',false,1},
		{0,'8',false,1},
		{0,'9',false,1},

		{1,'0',false,1},
		{1,'1',false,1},
		{1,'2',false,1},
		{1,'3',false,1},
		{1,'4',false,1},
		{1,'5',false,1},
		{1,'6',false,1},
		{1,'7',false,1},
		{1,'8',false,1},
		{1,'9',false,1},

		{1,' ',true,2},
		{1,'\n',true,2},
		{1,'\t',true,2},
		{1,NULL,true,2},
	};
	const Status Numberx10::initial = 0;
	Numberx10::Numberx10() : cc::AFD(Numberx10::initial,Numberx10::table)
	{
	}




	const Table Numberx16::table {
		{0,'0',false,1},

		{1,'x',false,2},
		{1,'X',false,2},

		{2,'0',false,2},
		{2,'1',false,2},
		{2,'2',false,2},
		{2,'3',false,2},
		{2,'4',false,2},
		{2,'5',false,2},
		{2,'6',false,2},
		{2,'7',false,2},
		{2,'8',false,2},
		{2,'9',false,2},
		
		{2,'a',false,2},
		{2,'b',false,2},
		{2,'c',false,2},
		{2,'d',false,2},
		{2,'e',false,2},
		{2,'f',false,2},
		{2,'A',false,2},
		{2,'B',false,2},
		{2,'C',false,2},
		{2,'D',false,2},
		{2,'E',false,2},
		{2,'F',false,2},

		{2,' ',true,3},
		{2,'\n',true,3},
		{2,'\t',true,3},
		{2,NULL,true,3},
	};
	const Table Numberx16::table_beautifull {
		{0,'0',false,1},

		{1,'x',false,2},
		{2,'0',false,2},
		{2,'1',false,2},
		{2,'2',false,2},
		{2,'3',false,2},
		{2,'4',false,2},
		{2,'5',false,2},
		{2,'6',false,2},
		{2,'7',false,2},
		{2,'8',false,2},
		{2,'9',false,2},		
		{2,'a',false,2},
		{2,'b',false,2},
		{2,'c',false,2},
		{2,'d',false,2},
		{2,'e',false,2},
		{2,'f',false,2},
		
		{2,' ',true,5},
		{2,'\n',true,5},
		{2,'\t',true,5},
		{2,NULL,true,5},
		
		{1,'X',false,4},
		{4,'0',false,4},
		{4,'1',false,4},
		{4,'2',false,4},
		{4,'3',false,4},
		{4,'4',false,4},
		{4,'5',false,4},
		{4,'6',false,4},
		{4,'7',false,4},
		{4,'8',false,4},
		{4,'9',false,4},
		{4,'A',false,4},
		{4,'B',false,4},
		{4,'C',false,4},
		{4,'D',false,4},
		{4,'E',false,4},
		{4,'F',false,4},
		
		{4,' ',true,5},
		{4,'\n',true,5},
		{4,'\t',true,5},
		{4,NULL,true,5},
	};
	const Status Numberx16::initial = 0;
	Numberx16::Numberx16() : cc::AFD(Numberx16::initial,Numberx16::table)
	{
	}
	Numberx16::Numberx16(const Table& t) : cc::AFD(Numberx16::initial,t)
	{
	}
}

}