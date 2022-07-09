

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
	const Transition<Char>* search(Status current,Char input) const;
	Transition<Char>* search(Status current,Char input,size_t begin, size_t end);
	const Transition<Char>* search(Status current,Char input,size_t begin, size_t end)const;

	
private:
};


class AFD
{

public:
	//AF();
	AFD(Status initial,const Table& table);
	const Transition<Char>* transition(Char symbol);
	bool transition(const Char* );
	
	//Table& get_table();
	const Table& get_table()const;

protected:
	const Table& table;
	Status current;
	const Status reset;
};

namespace afs
{
	class Numberx10 : public AFD
	{

	public:
		Numberx10();

	private:
		static const Table table;
		static const Status initial;
	};


	class Numberx16 : public AFD
	{

	public:
		Numberx16();
		Numberx16(const Table&);



		static const Table table;
		static const Table table_beautifull;//se deve poner todo en mayusculas o todo en minusculas

	private:
		static const Status initial;
	};
}

}

#endif