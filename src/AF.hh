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

namespace oct::cc::dfa
{



template<typename Symbol/*char*/,typename S/*Status*/,typename O/*Offset*/>
class DFA 
{

public:
	DFA() : current(0), i(0),reset(0)
	{
#if OCTETOS_CC_DEGUB
		echo = false;
#endif
	}
	DFA(S s) : current(s), i(0),reset(0)
	{
#if OCTETOS_CC_DEGUB
		echo = false;
#endif
	}
	DFA(S s,S r) : current(s),reset(r), i(0)
	{
#if OCTETOS_CC_DEGUB
		echo = false;
#endif
	}
		
	//virtual O transition(const Symbol* string) = 0;
	//virtual O transition(Buffer<Symbol>&);
		
#if OCTETOS_CC_DEGUB
	void enable_echo(bool e)
	{
		echo = e;
	}
#endif

	
protected:
	O i;
	S current,reset;
	Symbol c;
#if OCTETOS_CC_DEGUB
	bool echo;
#endif
};
	

	/**
	*\brief DFA type A
	*
	*/
	template<typename T/*char*/,typename S = Word/*Status*/,typename O = Word/*Offset*/>
	class A : public dfa::DFA<T,S,O>
	{

	public:
		A() : dfa::DFA<T,Word,Word>(0), table(NULL), length(0),prev(NULL),actual(NULL),accepted(NULL)
		{
		}
		A(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l) : dfa::DFA<T,Word,Word>(0), table(t), length(l),prev(NULL),actual(NULL),accepted(NULL)
		{
		}

		void load(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l)
		{
			table = t;
			length = l;
		}
		

		inline const tt::a::Transition * get_actual()const
		{
			return actual;
		}
		
		inline const tt::a::Transition * get_accepted()const
		{
			return accepted;
		}

		void print(std::ostream& out) const
		{
				if(dfa::DFA<T,Word,Word>::c == '\n')
				{
					out << dfa::DFA<T,Word,Word>::current << "--New line->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == '\t')
				{
					out << dfa::DFA<T,Word,Word>::current << "--Tabulator->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == ' ')
				{
					out << dfa::DFA<T,Word,Word>::current << "--Espace->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == '\0')
				{
					out << dfa::DFA<T,Word,Word>::current << "--\\0->" << actual->next << "\n";
				}
				else
				{
					out << dfa::DFA<T,Word,Word>::current << "--" << dfa::DFA<T,Word,Word>::c << "->" << actual->next << "\n";
				}
		}
		void print(std::wostream& out) const
		{
				if(dfa::DFA<T,Word,Word>::c == '\n')
				{
					out << dfa::DFA<T,Word,Word>::current << "--New line->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == '\t')
				{
					out << dfa::DFA<T,Word,Word>::current << "--Tabulator->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == ' ')
				{
					out << dfa::DFA<T,Word,Word>::current << "--Espace->" << actual->next << "\n";
				}
				else if(dfa::DFA<T,Word,Word>::c == '\0')
				{
					out << dfa::DFA<T,Word,Word>::current << "--\\0->" << actual->next << "\n";
				}
				else
				{
					out << dfa::DFA<T,Word,Word>::current << "--" << dfa::DFA<T,Word,Word>::c << "->" << actual->next << "\n";
				}
		}

		Word transition(const T* string)
		{
			if(not string) return 0;
			
			dfa::DFA<T,Word,Word>::current = dfa::DFA<T,Word,Word>::reset;
			dfa::DFA<T,Word,Word>::i = 0;	
			accepted = NULL;

			do
			{
				dfa::DFA<T,Word,Word>::c = string[dfa::DFA<T,Word,Word>::i];
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,Word,Word>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,Word,Word>::current << "\n";
					//std::cout << "c : '" << cc::DFA<T,Word,Word>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) cc::DFA<T,Word,Word>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(dfa::DFA<T,Word,Word>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(dfa::DFA<T,Word,Word>::echo)
					{
						if(prev) 
						{
							//std::cout << "prev registered..\n";
							if(prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,Word,Word>::i << "..\n";
					}
#endif
					if(dfa::DFA<T,Word,Word>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						accepted = prev;
						return dfa::DFA<T,Word,Word>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(dfa::DFA<T,Word,Word>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				actual = &table[dfa::DFA<T,Word,Word>::current][(unsigned char)dfa::DFA<T,Word,Word>::c];
				
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,Word,Word>::echo)
				{
					print(std::cout);
				}
#endif

				if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
					//std::cout << " i : " << i  << "\n";
					if(prev) if(prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(dfa::DFA<T,Word,Word>::echo) std::cout << "'" << string[dfa::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						accepted = prev;
						return dfa::DFA<T,Word,Word>::i;
					}
					return 0;
				}
				else if(actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				dfa::DFA<T,Word,Word>::current = actual->next;
				prev = actual;
				dfa::DFA<T,Word,Word>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			return 0;
		}
		Word transition(Buffer<T>& buff)
		{
			if(buff.empty()) return 0;
			
			dfa::DFA<T,Word,Word>::current = dfa::DFA<T,Word,Word>::reset;
			dfa::DFA<T,Word,Word>::i = 0;	
			accepted = NULL;

			do
			{
				dfa::DFA<T,Word,Word>::c = buff[dfa::DFA<T,Word,Word>::i];
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,Word,Word>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,Word,Word>::current << "\n";
					//std::cout << "c : '" << cc::DFA<T,Word,Word>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) cc::DFA<T,Word,Word>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(dfa::DFA<T,Word,Word>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(dfa::DFA<T,Word,Word>::echo)
					{
						if(prev) 
						{
							//std::cout << "prev registered..\n";
							if(prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,Word,Word>::i << "..\n";
					}
#endif
					if(dfa::DFA<T,Word,Word>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						accepted = prev;
						buff.walk((size_t)DFA<T,Word,Word>::i);
						return dfa::DFA<T,Word,Word>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(dfa::DFA<T,Word,Word>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				actual = &table[dfa::DFA<T,Word,Word>::current][(unsigned char)dfa::DFA<T,Word,Word>::c];
				
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,Word,Word>::echo)
				{
					print(std::cout);
				}
#endif

				if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					//if(cc::DFA<T,Word,Word>::echo) std::cout << "'" << string[cc::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
					//std::cout << " i : " << i  << "\n";
					if(prev) if(prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(dfa::DFA<T,Word,Word>::echo) std::cout << "'" << buff[dfa::DFA<T,Word,Word>::i]  << "'" << "\n";
#endif
						accepted = prev;
						buff.walk((size_t)DFA<T,Word,Word>::i);
						return dfa::DFA<T,Word,Word>::i;
					}
					return 0;
				}
				else if(actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				dfa::DFA<T,Word,Word>::current = actual->next;
				prev = actual;
				dfa::DFA<T,Word,Word>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

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
		//Word reset;
		const tt::a::Transition *prev;
		const tt::a::Transition *actual;
		const tt::a::Transition *accepted;
	};


	
	
	template<typename T/*char*/,typename Token,typename S = Word/*Status*/,typename O = Word/*Offset*/>
	class B : public dfa::DFA<T,S,O>
	{

	public:
		B() : table(NULL)
		{
		}
		B(const tt::b::TT<T,Token>& t) : table(&t)
		{
		}

		void load(const tt::b::TT<T,Token>& t)
		{
			table = &t;
		}

		const tt::b::Transition<T,Token>* search(tt::Status current,T input)
		{
			return search(current,input,0,table->size() - 1);
		}
		const tt::b::Transition<T,Token>* search(tt::Status current,T input,size_t b, size_t e)
		{
			if(b > e) return NULL;
			if(b - e == 1) return NULL;

			//std::cout << "b = " << b << "\n";
			//std::cout << "e = " << e << "\n";
			size_t middle = b + ((e - b)/ 2);
			//std::cout << "middle = " << middle << "\n";

			if((*table)[middle].less(current,input))
			{
				//std::cout << "\t --> " << value << "\n";
				return search(current,input,middle + 1,e);
			}
			else if((*table)[middle].great(current,input))
			{
				//std::cout << "\t --> " << value << "\n";
				return search(current,input,b,middle - 1);
			}
			else if((*table)[middle].equal(current,input))
			{
				return &(*table)[middle];
			}
				
			return NULL;		
		}
		const tt::b::Transition<T,Token>* transition(T symbol)
		{
			//std::cout << "current : " << current << "\n";
			//std::cout << "symbol : " << symbol << "\n";
			const tt::b::Transition<T,Token>* ret = search(dfa::DFA<T,S,O>::current,symbol);
			//ret? std::cout << "Found\n" : std::cout << "Not Fount\n" ;
			if(ret)
			{
#if OCTETOS_CC_DEGUB
				//if(dfa::DFA<T,S,O>::echo) ret->print(std::cout);
#endif
				dfa::DFA<T,S,O>::current = ret->next;
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
		O transition(const T* string)
		{
			if(not string) return false;
			
			DFA<T,S,O>::current = dfa::DFA<T,Word,Word>::reset;
			DFA<T,S,O>::i = 0;	
			const tt::b::Transition<T,Token> *prev = NULL, *actual;
			do
			{
#if OCTETOS_CC_DEGUB
				//std::cout << string[DFA<T,Word,Word>::i] << "\n";
#endif				
				if(string[DFA<T,S,O>::i] == '\0')
				{
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept) return DFA<T,S,O>::i;
					return 0;//si no se encontrontro transiscion
				}

				actual = transition(string[dfa::DFA<T,Word,Word>::i]);				
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,S,O>::echo and actual)
				{
					actual->print(std::cout);
				}
#endif
				if(not actual) 
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;//i es 0-base index
					return 0;//si no se encontrontro transiscion
				}
				else if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
					if(prev) if(prev->indicator == tt::Indicator::Accept) return DFA<T,S,O>::i;
					return 0;//si no se encontrontro transiscion
				}
				else if(actual->indicator == tt::Indicator::Reject)
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;//si no se encontrontro transiscion
				}
				 
				prev = actual;
				dfa::DFA<T,Word,Word>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			
			
			return dfa::DFA<T,Word,Word>::i;
		}
		
		O transition(Buffer<T>& buff)
		{
			if(buff.empty()) return 0;
			
			DFA<T,S,O>::current = dfa::DFA<T,S,O>::reset;
			DFA<T,S,O>::i = 0;	
			const tt::b::Transition<T,Token> *prev = NULL, *actual;
			do
			{
#if OCTETOS_CC_DEGUB
				if(DFA<T,Word,Word>::echo)
				{
					std::cout << "current : '"<<  dfa::DFA<T,Word,Word>::current << "'\n";
					std::cout << "i : '"<<  DFA<T,Word,Word>::i << "'\n";
					std::cout << "c : '"<< buff[DFA<T,S,O>::i] << "'\n";
					std::cout << "code : '"<< (unsigned int)buff[DFA<T,S,O>::i] << "'\n";		
				}
#endif				
				if(buff[DFA<T,S,O>::i] == '\0')
				{
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else 
					{
						if(prev) 
						{
							if(prev->indicator == tt::Indicator::Accept) 
							{
								buff.walk((size_t)dfa::DFA<T,S,O>::i);
								return DFA<T,Word,Word>::i;
							}
						}
					}
					return 0;//si no se encontrontro transiscion
				}
				
				actual = transition(buff[dfa::DFA<T,S,O>::i]);
				
				if(not actual) 
				{
#if OCTETOS_CC_DEGUB
					//if(DFA<T,Word,Word>::echo) std::cout << "not actual\n";
#endif	
					return 0;//si no se encontrontro transiscion
				}
				
#if OCTETOS_CC_DEGUB
				//actual->print(std::cout);				
#endif

				if(actual->indicator == tt::Indicator::Prefix_Accept)
				{	
#if OCTETOS_CC_DEGUB
					//std::cout << "Prefix_Accept\n";
#endif				
					if(prev) 
					{
#if OCTETOS_CC_DEGUB
						//std::cout << "prev exist\n";
#endif
						if(prev->indicator == tt::Indicator::Accept) 
						{
#if OCTETOS_CC_DEGUB
							//std::cout << "prev exist acepted\n";
#endif
							buff.walk((size_t)dfa::DFA<T,S,O>::i);
							return DFA<T,S,O>::i;
						}
					}
					return 0;//si no se encontrontro transiscion
				}
				else if(actual->indicator == tt::Indicator::Reject)
				{
#if OCTETOS_CC_DEGUB
					//std::cout << "Rejected\n";
#endif
					return 0;//si no se encontrontro transiscion
				}
				 
				//dfa::DFA<T,Word,Word>::current = actual->next;
				prev = actual;
				dfa::DFA<T,Word,Word>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);			
			
			return dfa::DFA<T,Word,Word>::i;
		}


		const tt::b::TT<T,Token>& get_table() const
		{
			return *table;
		}
				
		void print(std::ostream& out) const
		{
			for(unsigned int i = 0; i < table->size(); i++)
			{
				(*table)[i].print(out);
			}
		}
		
	private:

	protected:
		const tt::b::TT<T,Token>* table;
		//tt::Status current;
		//tt::Status reset;
		//const size_t length;
	};

	
	
	
	template<typename C,typename S = Word,typename O = Word>
	class C_Identifier : public DFA<C,S,O>
	{
	private:
		enum class Status : S
		{
			initial,
			identifier,
		};
	public:
		C_Identifier() : DFA<C,S,O>((S)Status::initial)
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
	class C_Integer : public DFA<C,S,O>
	{
	private:
		enum class Status : S
		{
			initial,
			integer,
		};
	public:
		C_Integer() : DFA<C,S,O>((S)Status::initial)
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


	template<typename Char,typename Symbol,typename Status,typename Index>
	class Grammar
	{
	public:
		Grammar()
		{			
		}
		
		virtual Index lexing(Buffer<Char>& buff) = 0;
		virtual Index parsing(Buffer<Char>& buff) = 0;
		
	protected:
		A<Char,Status,Index> lexer;
		B<Symbol,Status,Index> parser;
	};

	template<typename Char,typename Symbol,typename Status,typename Index>
	class Parser : public B<Symbol,Status,Index>
	{
	public:
		Parser()
		{			
		}
		
		
		
	protected:
		A<Char,Status,Index> lexer;
	};
	
}

#endif