

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
#include <algorithm>


#include "Buffer.hh"
#include "Exception.hh"

namespace oct::cc
{

typedef unsigned long long int Word;
typedef Word Status;

enum class Indicator : unsigned char
{
	None,
	Accept,
	Reject,
	End
};
template<typename T>
struct Transition
{
	Status current;
	T input;
	Indicator indicator;
	Status next;

	bool operator < (const Transition<T>& obj) const
	{
		if(current < obj.current) return true;
		else if(current > obj.current) return false;
		else 
		{
			if(input < obj.input) return true;
			else if(input > obj.input) return false;
			else throw Exception(Exception::NOT_UNIQUE,__FILE__,__LINE__);
		}

		return false;
	}
	bool operator > (const Transition<T>& obj) const
	{
		if(current > obj.current) return true;
		else if(current < obj.current) return false;
		else 
		{
			if(input > obj.input) return true;
			else if(input < obj.input) return false;
			else throw Exception(Exception::NOT_UNIQUE,__FILE__,__LINE__);
		}

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
		else if(this->current > current) return false;
		else 
		{
			if(this->input < input) return true;
			else if(this->input > input) return false;
			else return false;
		}

		return false;
	}
	bool great(Status current,T input)const
	{
		if(this->current > current) return true;
		else if(this->current < current) return false;
		else 
		{
			if(this->input > input) return true;
			else if(this->input < input) return false;
			else return false;
		}

		return false;
	}

	void print(std::ostream&) const;
	void print(std::wostream&) const;
	
};

template<typename T>
class Table : public std::vector<Transition<T>>
{
public:
	Table(std::initializer_list<Transition<T>>t) : std::vector<Transition<T>>(t)
	{
		sort();
	}
	Table() 
	{
	}

	void sort()
	{
		std::sort(std::vector<Transition<T>>::begin(),std::vector<Transition<T>>::end());
	}

	Transition<T>* search(Status current,T input)
	{
		return search(current,input, 0,std::vector<Transition<T>>::size() - 1);
	}
	const Transition<T>* search(Status current,T input) const
	{
		return search(current,input, 0,std::vector<Transition<T>>::size() - 1);
	}
	Transition<T>* search(Status current,T input,size_t b, size_t e)
	{
		if(b > e) return NULL;
		if(b - e == 1) return NULL;

		//std::cout << "b = " << b << "\n";
		//std::cout << "e = " << e << "\n";
		size_t middle = b + ((e - b)/ 2);
		//std::cout << "middle = " << middle << "\n";

		if(std::vector<Transition<T>>::at(middle).less(current,input))
		{
			//std::cout << "\t --> " << value << "\n";
			return search(current,input,middle + 1,e);
		}
		else if(std::vector<Transition<T>>::at(middle).great(current,input))
		{
			//std::cout << "\t --> " << value << "\n";
			return search(current,input,b,middle - 1);
		}
		else if(std::vector<Transition<T>>::at(middle).equal(current,input))
		{
			return &std::vector<Transition<T>>::at(middle);
		}
			
		return NULL;		
	}
	const Transition<T>* search(Status current,T input,size_t b, size_t e) const
	{
		if(b > e) return NULL;
		if(b - e == 1) return NULL;

		//std::cout << "b = " << b << "\n";
		//std::cout << "e = " << e << "\n";
		size_t middle = b + ((e - b)/ 2);
		//std::cout << "middle = " << middle << "\n";

		if(std::vector<Transition<T>>::at(middle).less(current,input))
		{
			//std::cout << "\t --> " << value << "\n";
			return search(current,input,middle + 1,e);
		}
		else if(std::vector<Transition<T>>::at(middle).great(current,input))
		{
			//std::cout << "\t --> " << value << "\n";
			return search(current,input,b,middle - 1);
		}
		else if(std::vector<Transition<T>>::at(middle).equal(current,input))
		{
			return &std::vector<Transition<T>>::at(middle);
		}
			
		return NULL;		
	}

	void print(std::ostream&) const;
	void print(std::wostream&) const;
private:
};

/**
*\brief Una AF-A(Automata finita Tipo A), es una 5-tupla (Q, Σ, q0, δ, F) donde :\n
*	\tQ es un conjunto finityos de estados
*	\tΣ es un albate finito
*	\tq0 no pertenece a Q
*	\tδ: Q x Σ -> Q
*	\tF incluido en Q
*	\thttps://es.wikipedia.org/wiki/Aut%C3%B3mata_finito
*
*/
template<typename T>
class AFA
{

public:
	AFA() : current(0),reset(0),table(NULL)
	{
	}
	AFA(const Table<T>& t) : current(0),reset(0),table(&t)
	{
		if(not check(t)) throw Exception(Exception::Q0_NOT_ACCEPTABLE,__FILE__,__LINE__);
	}
	AFA(Status i,const Table<T>& t) : current(i),reset(i),table(&t)
	{
		if(not check(t)) throw Exception(Exception::Q0_NOT_ACCEPTABLE,__FILE__,__LINE__);
	}

	const Transition<T>* transition(T symbol)
	{
		//std::cout << "current : " << current << "\n";
		//std::cout << "symbol : " << symbol << "\n";
		const Transition<T>* ret = table->search(current,symbol);
		//ret? std::cout << "Found\n" : std::cout << "Not Fount\n" ;
		if(ret)
		{
			//ret->print(std::cout);
			current = ret->next;
			//std::cout << "current : " << current << "\n";
			//std::cout << "symbol : " << symbol << "\n";
			return ret;
		}

		return NULL;
	}
	/**
	*\brief determina hasta donde la string indicada pertence al lenguaje del automata indicado
	*\return la cantidad de caracteres acpetados par el lenguaje
	*/
	unsigned short transition(const T* string)
	{
		if(not string) return false;
		
		current = reset;
		unsigned short  i = 0;	
		const Transition<T> *prev = NULL, *actual;
		do
		{
			//std::cout << string[i] << "\n";
			actual = transition(string[i]);
			if(not actual) 
			{
				if(prev) if(prev->indicator == Indicator::Accept) return i;//i es 0-base index
				return 0;//si no se encontrontro transiscion
			}
			else if(actual->indicator == Indicator::Reject)
			{
				if(prev) if(prev->indicator == Indicator::Accept) return i;
				return 0;//si no se encontrontro transiscion
			}
			else if(string[i] == '\0')
			{
				if(i == 0) return 0;
				else if(prev) if(prev->indicator == Indicator::Accept) return i;
				return 0;//si no se encontrontro transiscion
			}
			prev = actual;
			i++;
		}
		while(actual);

		
		
		return i;
	}


	const Table<T>* get_table() const
	{
		return table;
	}
	void load(Status initial,const Table<T>& table)
	{
		current = initial;
		reset = initial;
		this->table = &table;
	}
private:
	bool check(const Table<T>& tb)
	{
		//std::cout << "reset :" << reset << "\n";
		for(const Transition<T>& t : tb)
		{
			if(t.next == reset) return false;
		}

		return true;
	}
	
protected:
	const Table<T>* table;
	Status current;
	Status reset;
};

}

#endif