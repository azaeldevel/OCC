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






#include <iostream>
#include <algorithm>

#include "Exception.hh"
#include "tt.hh"
#include "base.hh"
#include "Buffer.hh"

namespace oct::cc
{



template<typename C/*char*/,typename S/*Status*/,typename O/*Offset*/>
class DFA
{

public:
	DFA() : current(0), i(0),prev(NULL),actual(NULL),accepted(NULL)
	{
#if OCTETOS_CC_DEGUB
		echo = false;
#endif
	}
	DFA(S s) : current(s), i(0),prev(NULL),actual(NULL),accepted(NULL)
	{
#if OCTETOS_CC_DEGUB
		echo = false;
#endif
	}
		
	virtual O transition(const C* string) = 0;
	virtual O transition(Buffer<C>&) = 0;
		
#if OCTETOS_CC_DEGUB
	void enable_echo(bool e)
	{
		echo = e;
	}
#endif

	void print(std::ostream& out,S next) const
	{
			if(c == '\n')
			{
				out << current << "--New line->" << next << "\n";
			}
			else if(c == '\t')
			{
				out << current << "--Tabulator->" << next << "\n";
			}
			else if(c == ' ')
			{
				out << current << "--Espace->" << next << "\n";
			}
			else if(c == '\0')
			{
				out << current << "--\\0->" << next << "\n";
			}
			else
			{
				out << current << "--" << c << "->" << next << "\n";
			}
	}
	void print(std::wostream& out,S next) const
	{
			if(c == '\n')
			{
				out << current << "--New line->" << next << "\n";
			}
			else if(c == '\t')
			{
				out << current << "--Tabulator->" << next << "\n";
			}
			else if(c == ' ')
			{
				out << current << "--Espace->" << next << "\n";
			}
			else if(c == '\0')
			{
				out << current << "--\\0->" << next << "\n";
			}
			else
			{
				out << current << "--" << c << "->" << next << "\n";
			}
	}

protected:
	O i;
	S current;
	C c;
	const tt::a::Transition *prev;
	const tt::a::Transition *actual;
	const tt::a::Transition *accepted;
#if OCTETOS_CC_DEGUB
	bool echo;
#endif
};
	

namespace a
{
	/**
	*\brief 
	*
	*/
	template<typename T>
	class DFA : public cc::DFA<T,Word,Word>
	{

	public:
		DFA(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l) : cc::DFA<T,Word,Word>(0), table(t), reset(0), length(l)
		{
		}
		

		inline const tt::a::Transition * get_actual()const
		{
			return cc::DFA<T,Word,Word>::actual;
		}
		inline const tt::a::Transition * get_accepted()const
		{
			return cc::DFA<T,Word,Word>::accepted;
		}
		Word transition(const T* string)
		{
			if(not string) return 0;
			
			cc::DFA<T,Word,Word>::current = reset;
			cc::DFA<T,Word,Word>::i = 0;	
			cc::DFA<T,Word,Word>::accepted = NULL;

			do
			{
				cc::DFA<T,Word,Word>::c = string[cc::DFA<T,Word,Word>::i];
#if OCTETOS_CC_DEGUB
				if(cc::DFA<T,Word,Word>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,Word,Word>::current << "\n";
					//std::cout << "c : '" << cc::DFA<T,Word,Word>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) cc::DFA<T,Word,Word>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(cc::DFA<T,Word,Word>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(cc::DFA<T,Word,Word>::echo)
					{
						if(cc::DFA<T,Word,Word>::prev) 
						{
							//std::cout << "prev registered..\n";
							if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,Word,Word>::i << "..\n";
					}
#endif
					if(cc::DFA<T,Word,Word>::i == 0) return 0;
					else if(cc::DFA<T,Word,Word>::prev) if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						cc::DFA<T,Word,Word>::accepted = cc::DFA<T,Word,Word>::prev;
						return cc::DFA<T,Word,Word>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(cc::DFA<T,Word,Word>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				cc::DFA<T,Word,Word>::actual = &table[cc::DFA<T,Word,Word>::current][(unsigned char)cc::DFA<T,Word,Word>::c];
				
#if OCTETOS_CC_DEGUB
				if(cc::DFA<T,Word,Word>::echo)
				{
					cc::DFA<T,Word,Word>::print(std::cout,cc::DFA<T,Word,Word>::actual->next);
				}
#endif

				if(cc::DFA<T,Word,Word>::actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
					//std::cout << " i : " << i  << "\n";
					if(cc::DFA<T,Word,Word>::prev) if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						cc::DFA<T,Word,Word>::accepted = cc::DFA<T,Word,Word>::prev;
						return cc::DFA<T,Word,Word>::i;
					}
					return 0;
				}
				else if(cc::DFA<T,Word,Word>::actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				cc::DFA<T,Word,Word>::current = cc::DFA<T,Word,Word>::actual->next;
				cc::DFA<T,Word,Word>::prev = cc::DFA<T,Word,Word>::actual;
				cc::DFA<T,Word,Word>::i++;
			}
			while(cc::DFA<T,Word,Word>::actual->indicator != tt::Indicator::Reject);

			return 0;
		}
		virtual Word transition(Buffer<T>& buff)
		{
			if(buff.size() == 0) return 0;
			
			cc::DFA<T,Word,Word>::current = reset;
			cc::DFA<T,Word,Word>::i = 0;	
			cc::DFA<T,Word,Word>::accepted = NULL;

			do
			{
				cc::DFA<T,Word,Word>::c = buff[cc::DFA<T,Word,Word>::i];
#if OCTETOS_CC_DEGUB
				if(cc::DFA<T,Word,Word>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,Word,Word>::current << "\n";
					//std::cout << "c : '" << cc::DFA<T,Word,Word>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) cc::DFA<T,Word,Word>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(cc::DFA<T,Word,Word>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(cc::DFA<T,Word,Word>::echo)
					{
						if(cc::DFA<T,Word,Word>::prev) 
						{
							//std::cout << "prev registered..\n";
							if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,Word,Word>::i << "..\n";
					}
#endif
					if(cc::DFA<T,Word,Word>::i == 0) return 0;
					else if(cc::DFA<T,Word,Word>::prev) if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						cc::DFA<T,Word,Word>::accepted = cc::DFA<T,Word,Word>::prev;
						buff.walk((size_t)cc::DFA<T,Word,Word>::i);
						return cc::DFA<T,Word,Word>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(cc::DFA<T,Word,Word>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				cc::DFA<T,Word,Word>::actual = &table[cc::DFA<T,Word,Word>::current][(unsigned char)cc::DFA<T,Word,Word>::c];
				
#if OCTETOS_CC_DEGUB
				if(cc::DFA<T,Word,Word>::echo)
				{
					cc::DFA<T,Word,Word>::print(std::cout,cc::DFA<T,Word,Word>::actual->next);
				}
#endif

				if(cc::DFA<T,Word,Word>::actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << buff[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
					//std::cout << " i : " << i  << "\n";
					if(cc::DFA<T,Word,Word>::prev) if(cc::DFA<T,Word,Word>::prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << buff[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						cc::DFA<T,Word,Word>::accepted = cc::DFA<T,Word,Word>::prev;
						buff.walk((size_t)cc::DFA<T,Word,Word>::i);
						return cc::DFA<T,Word,Word>::i;
					}
					return 0;
				}
				else if(cc::DFA<T,Word,Word>::actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				cc::DFA<T,Word,Word>::current = cc::DFA<T,Word,Word>::actual->next;
				cc::DFA<T,Word,Word>::prev = cc::DFA<T,Word,Word>::actual;
				cc::DFA<T,Word,Word>::i++;
			}
			while(cc::DFA<T,Word,Word>::actual->indicator != tt::Indicator::Reject);

			return 0;
		}

		const tt::a::Transition** get_table() const
		{
			return (const tt::a::Transition**)table;
		}
		
	private:
		const tt::a::Transition (*table)[tt::MAX_SIMBOLS];  
		size_t length;
		//tt::Status current;
		Word reset;
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
					else if(is_whitespace(DFA<C,S,O>::c)) return DFA<C,S,O>::i;
					DFA<C,S,O>::i++;
					break;
				};
			}
			while(true);

			return 0;
		}
		virtual O transition(Buffer<C>& buff)
		{
			DFA<C,S,O>::current = (S)Status::initial;
			DFA<C,S,O>::i = 0;
			
			do
			{
				//std::cout << "Step " << AFDC<C,S,O>::i << "\n";
				DFA<C,S,O>::c = buff[DFA<C,S,O>::i];
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
					buff.walk((size_t)DFA<C,S,O>::i);
					break;
				case (S)Status::identifier:
					if(isalnum(DFA<C,S,O>::c)) ; //se mantiene en el mismo estado
					else if(DFA<C,S,O>::c == '_') ; //se mantiene en el mismo estado
					else if(is_whitespace(DFA<C,S,O>::c)) 
					{
						buff.walk((size_t)DFA<C,S,O>::i);
						return DFA<C,S,O>::i;
					}
					DFA<C,S,O>::i++;
					buff.walk((size_t)DFA<C,S,O>::i);
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
					else if(is_whitespace(DFA<C,S,O>::c)) return DFA<C,S,O>::i;
					else if(isalpha(DFA<C,S,O>::c)) return 0;
					DFA<C,S,O>::i++;
					break;
				};
			}
			while(true);

			return 0;
		}
		virtual O transition(Buffer<C>& buff)
		{
			DFA<C,S,O>::current = (S)Status::initial;
			DFA<C,S,O>::i = 0;			
			
			do
			{
				//std::cout << "Step " << AFDC<C,S,O>::i << "\n";
				DFA<C,S,O>::c = buff[DFA<C,S,O>::i];
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
					buff.walk((size_t)DFA<C,S,O>::i);
					break;
				case (S)Status::integer:
					if(isdigit(DFA<C,S,O>::c)) ; //se mantiene en el mismo estado
					else if(is_whitespace(DFA<C,S,O>::c)) return DFA<C,S,O>::i;
					else if(isalpha(DFA<C,S,O>::c)) return 0;
					DFA<C,S,O>::i++;	
					buff.walk((size_t)DFA<C,S,O>::i);
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