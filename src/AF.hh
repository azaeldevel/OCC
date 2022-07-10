

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

#include <vector>
#include <iostream>

#include "Buffer.hh"

namespace oct::cc
{

typedef unsigned long long int Word;
typedef Word Status;


template<typename T>
struct Transition
{
	Status current;
	T input;
	bool accepted;
	Status next;

	bool operator < (const Transition<Char>& obj) const
	{
		if(current < obj.current) return true;
		else if(current == obj.current)  return input < obj.input;

		return false;
	}
	bool operator > (const Transition<Char>& obj) const
	{
		if(current > obj.current) return true;
		else if(current == obj.current)  return input > obj.input;

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
		else if(this->current == current)  return this->input < input;

		return false;
	}
	bool great(Status current,T input)const
	{
		if(this->current > current) return true;
		else if(this->current == current)  return this->input > input;

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
			out << current << "--\0->" << next << "\n";
		}
		else if(input == EOF)
		{
			out << current << "--EOF->" << next << "\n";
		}
		else
		{
			out << current << "--" << input << "->" << next << "\n";
		}
	}
};

class Table : public std::vector<Transition<Char>>
{
public:
	Table();
	Table(std::initializer_list<Transition<Char>>);
	void sort();

	Transition<Char>* search(Status current,Char input);
	const Transition<Char>* search(Status current,Char input) const;
	Transition<Char>* search(Status current,Char input,size_t begin, size_t end);
	const Transition<Char>* search(Status current,Char input,size_t begin, size_t end)const;

	
private:
};


class AFD
{

public:
	AFD();
	AFD(const Table& table);
	AFD(Status initial,const Table& table);
	const Transition<Char>* transition(Char symbol);
	bool transition(const Char* );
	
	//Table& get_table();
	void load(Status initial,const Table& table);
	const Table* get_table()const;

protected:
	const Table* table;
	Status current;
	Status reset;
};

namespace tt//transition tables
{
static const Table table_number_10 {
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
		{1,'\0',true,2},
	};

static const Table table_number_16 {
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
		{2,'\0',true,3},
	};
static const Table table_number_beautifull_16 {
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
		{2,'\0',true,5},
		
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
		{4,'\0',true,5},
	};

static const unsigned char OP_MAX_ZISE= 12;
//intel-80-210201-001.pdf
static const Table i86 {

		//
		{0,'a',false,1},
		{1,'a',false,2},
		{2,'a',false,3},
		
		{0,'A',false,4},
		{4,'A',false,5},
		{5,'A',false,6},


		//
		{0,'a',false,1},
		{1,'a',false,2},
		{2,'d',false,3},

		{0,'A',false,1},
		{1,'A',false,2},
		{2,'D',false,3},


		//
		{0,'a',false,1},
		{1,'a',false,2},
		{2,'m',false,3},

		{0,'A',false,1},
		{1,'A',false,2},
		{2,'M',false,3},


		//
		{0,'a',false,1},
		{1,'a',false,2},
		{2,'s',false,3},

		{0,'A',false,1},
		{1,'A',false,2},
		{2,'S',false,3},


		//
		{0,'a',false,1},
		{1,'d',false,2},
		{2,'c',false,3},

		{0,'A',false,1},
		{1,'D',false,2},
		{2,'C',false,3},


		//
		{0,'a',false,1},
		{1,'d',false,2},
		{2,'d',false,3},

		{0,'A',false,1},
		{1,'D',false,2},
		{2,'D',false,3},


		//acepting
		{3,' ',true,OP_MAX_ZISE},
		{3,'\n',true,OP_MAX_ZISE},
		{3,'\t',true,OP_MAX_ZISE},
		{3,'\0',true,OP_MAX_ZISE},

		{6,' ',true,OP_MAX_ZISE},
		{6,'\n',true,OP_MAX_ZISE},
		{6,'\t',true,OP_MAX_ZISE},
		{6,'\0',true,OP_MAX_ZISE},
};
}

}

#endif