

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

enum class Type : Word
{
	None,
	Initial,
	Ending,
	Acepting,
	Incomplete,
	Reject,
};
template<typename T>
struct Transition
{
	T input;
	Type type;
	Status current;
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
		else if(input == NULL)
		{
			out << current << "--NULL->" << next << "\n";
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
	Transition<Char>* search(Status current,Char input,size_t begin, size_t end);

	
private:
};


class AF
{

public:
	AF();
	AF(Status initial);
	const Transition<Char>* transition(Char symbol);
	bool transition(const Char* );
	
	Table& get_table();

protected:
	Table table;
	Status current;
	const Status reset;
};


class Number : public AF
{

public:
	Number();
	Number(Status initial);

private:
	void init();
};

}

#endif