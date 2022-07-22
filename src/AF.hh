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
#include <algorithm>


namespace oct::cc
{


	
template<typename C/*char*/,typename S/*Status*/,typename O/*Offset*/>
class DFA
{

public:
	DFA() : current(0), i(0)
	{
	}
	DFA(S s) : current(s), i(0)
	{
	}
		
	virtual O transition(const C* string) = 0;

	inline bool is_whitespace(C c)
	{
		return c == ' ' or c == '\t' or c == '\n';
	}

protected:
	O i;
	S current;
	C c;
};
	

namespace a
{
	/**
	*\brief 
	*
	*/
	template<typename T>
	class DFA
	{

	public:
		DFA(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l) : table(t), current(0), reset(0), length(l)
		{
		}
		
		unsigned short transition(const T* string)
		{
			if(not string) return 0;
			
			current = reset;
			unsigned short  i = 0;	
			const tt::a::Transition *prev = NULL, *actual;
			do
			{
				//std::cout << "'" << string[i]  << "'" << "\n";
				//std::cout << "current : " << current << "\n";
				//std::cout << "symbol : " << string[i] << "\n";
				//std::cout << "symbol : " << (unsigned short) string[i] << "\n";
				//std::cout << "length : " << length << "\n";
				if(string[i] == '\0')
				{
					if(i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;//si no se encontrontro transiscion
				}
				
				if(current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				actual = &table[current][(unsigned char)string[i]];
				
				if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
					//std::cout << "'" << string[i]  << "'" << "\n";
					//std::cout << " i : " << i  << "\n";
					if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				else if(actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				current = actual->next;
				prev = actual;
				i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			return 0;
		}
		
	private:
		const tt::a::Transition (*table)[tt::MAX_SIMBOLS];  
		size_t length;
		tt::Status current;
		tt::Status reset;
	};
}


namespace b
{
	template<typename T>
	class DFA
	{

	public:
		DFA() : current(0),reset(0),table(NULL),length(0)
		{
		}
		DFA(const tt::b::Transition<T> t[], size_t l) : current(0),reset(0),table(t),length(l)
		{		 
		}

		const tt::b::Transition<T>* search(tt::Status current,T input)
		{
			return search(current,input,0,length - 1);
		}
		const tt::b::Transition<T>* search(tt::Status current,T input,size_t b, size_t e)
		{
			if(b > e) return NULL;
			if(b - e == 1) return NULL;

			//std::cout << "b = " << b << "\n";
			//std::cout << "e = " << e << "\n";
			size_t middle = b + ((e - b)/ 2);
			//std::cout << "middle = " << middle << "\n";

			if(table[middle].less(current,input))
			{
				//std::cout << "\t --> " << value << "\n";
				return search(current,input,middle + 1,e);
			}
			else if(table[middle].great(current,input))
			{
				//std::cout << "\t --> " << value << "\n";
				return search(current,input,b,middle - 1);
			}
			else if(table[middle].equal(current,input))
			{
				return &table[middle];
			}
				
			return NULL;		
		}
		const tt::b::Transition<T>* transition(T symbol)
		{
			//std::cout << "current : " << current << "\n";
			//std::cout << "symbol : " << symbol << "\n";
			const tt::b::Transition<T>* ret = search(current,symbol);
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
			const tt::b::Transition<T> *prev = NULL, *actual;
			do
			{
				//std::cout << string[i] << "\n";
				if(string[i] == '\0')
				{
					if(i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;//si no se encontrontro transiscion
				}

				actual = transition(string[i]);

				if(not actual) 
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;//i es 0-base index
					return 0;//si no se encontrontro transiscion
				}
				else if(actual->indicator == tt::Indicator::Reject)
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;//si no se encontrontro transiscion
				}
				else if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
					if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;//si no se encontrontro transiscion
				}
				 
				prev = actual;
				i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			
			
			return i;
		}


		const tt::b::Transition<T>* get_table() const
		{
			return table;
		}
		void load(tt::Status initial,const tt::b::Transition<T> t[])
		{
			current = initial;
			reset = initial;
			this->table = t;
		}
	private:

		
	protected:
		const tt::b::Transition<T>* table;
		tt::Status current;
		tt::Status reset;
		const size_t length;
	};
}

namespace c
{	
	template<typename C,typename S = Word,typename O = Word>
	class Identifier : public DFA<C,S,O>
	{
	private:
		enum class Status : S
		{
			initial,
			identifier,
		};
	public:
		Identifier() : DFA<C,S,O>((S)Status::initial)
		{		
		}
		
		virtual O transition(const C* string)
		{
			DFA<C,S,O>::current = (S)Status::initial;
			DFA<C,S,O>::i = 0;
			
			do
			{
				//std::cout << "Step " << AFDC<C,S,O>::i << "\n";
				DFA<C,S,O>::c = string[DFA<C,S,O>::i];
				if(DFA<C,S,O>::c == '\0')
				{
					if(DFA<C,S,O>::current == (S)Status::identifier) return DFA<C,S,O>::i;
					else return 0;
				}

				switch(DFA<C,S,O>::current)
				{
				case (S)Status::initial:
					if(isalpha(DFA<C,S,O>::c)) DFA<C,S,O>::current = (S)Status::identifier;
					else if(DFA<C,S,O>::c == '_') DFA<C,S,O>::current = (S)Status::identifier;
					else return 0;
					DFA<C,S,O>::i++;
					break;
				case (S)Status::identifier:
					if(isalnum(DFA<C,S,O>::c)) ; //se mantiene en el mismo estado
					else if(DFA<C,S,O>::c == '_') ; //se mantiene en el mismo estado
					else if(DFA<C,S,O>::is_whitespace(DFA<C,S,O>::c)) return DFA<C,S,O>::i;
					DFA<C,S,O>::i++;
					break;
				};
			}
			while(true);

			return 0;
		}

	protected:
	};

	template<typename C,typename S = Word,typename O = Word>
	class Integer : public DFA<C,S,O>
	{
	private:
		enum class Status : S
		{
			initial,
			integer,
		};
	public:
		Integer() : DFA<C,S,O>((S)Status::initial)
		{		
		}
		
		virtual O transition(const C* string)
		{
			DFA<C,S,O>::current = (S)Status::initial;
			DFA<C,S,O>::i = 0;			
			
			do
			{
				//std::cout << "Step " << AFDC<C,S,O>::i << "\n";
				DFA<C,S,O>::c = string[DFA<C,S,O>::i];
				if(DFA<C,S,O>::c == '\0')
				{
					if(DFA<C,S,O>::current == (S)Status::integer) return DFA<C,S,O>::i;
					else return 0;
				}

				switch(DFA<C,S,O>::current)
				{
				case (S)Status::initial:
					if(isdigit(DFA<C,S,O>::c)) DFA<C,S,O>::current = (S)Status::integer;
					else return 0;
					DFA<C,S,O>::i++;
					break;
				case (S)Status::integer:
					if(isdigit(DFA<C,S,O>::c)) ; //se mantiene en el mismo estado
					else if(DFA<C,S,O>::is_whitespace(DFA<C,S,O>::c)) return DFA<C,S,O>::i;
					else if(isalpha(DFA<C,S,O>::c)) return 0;
					DFA<C,S,O>::i++;
					break;
				};
			}
			while(true);

			return 0;
		}

	protected:
	};
}


}

#endif