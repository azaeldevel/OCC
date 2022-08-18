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
#include <stack>

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
	bool get_echo(void)
	{
		return echo;
	}
#endif

	
protected:
	O i;
	S current,reset;
	Symbol c;
	unsigned short tab_size = 4;
	static unsigned short line, column;	
	unsigned short eating;
	
#if OCTETOS_CC_DEGUB
	bool echo;
#endif
};
	
template<typename Symbol/*char*/,typename S/*Status*/,typename O/*Offset*/> unsigned short DFA<Symbol,S,O>::line = 0;
template<typename Symbol/*char*/,typename S/*Status*/,typename O/*Offset*/> unsigned short DFA<Symbol,S,O>::column = 0;

	/**
	*\brief DFA type A
	*
	*/
	template<typename T/*char*/,typename S = Word/*Status*/,typename O = Word/*Offset*/>
	class A : public dfa::DFA<T,S,O>
	{
	
	public:
		A() : table(NULL), length(0), prev(NULL), actual(NULL)
		{
		}
		A(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l) : dfa::DFA<T,S,O>(0), table(t), length(l),prev(NULL),actual(NULL)
		{
		}

		void load(const tt::a::Transition (*t)[tt::MAX_SIMBOLS],size_t l)
		{
			table = t;
			length = l;
		}		

		const tt::a::Transition* get_actual()const
		{
			return actual;
		}	

		const tt::a::Transition* get_accepted()const
		{
			return accepted;
		}
		
		/*
		inline const tt::a::Transition * get_accepted()const
		{
			return accepted;
		}
		*/

		const char* indicator_string() const
		{			
			
			if(actual->indicator == tt::Indicator::None) return "None";
			else if(actual->indicator == tt::Indicator::Accept_Inmediatly) return "Aceppt Inmediatly";
			else if(actual->indicator == tt::Indicator::Accept) return "Aceppted";
			else if(actual->indicator == tt::Indicator::Prefix_Accept) return "Prefijo de acceptacion";
			else if(actual->indicator == tt::Indicator::Left_Eat) return "Left Eating";
			else if(actual->indicator == tt::Indicator::Reject) return "Reject";
			else return "Desconocido";
		}
		void print(std::ostream& out) const
		{
			if(dfa::DFA<T,S,O>::c == '\n')
			{
				out << dfa::DFA<T,S,O>::current << "--New line->" << actual->next << " : " << indicator_string() << "\n";
			}
			else if(dfa::DFA<T,S,O>::c == '\t')
			{
				out << dfa::DFA<T,S,O>::current << "--Tabulator->" << actual->next << " : "  << indicator_string()  << "\n";
			}
			else if(dfa::DFA<T,S,O>::c == ' ')
			{
				out << dfa::DFA<T,S,O>::current << "--Espace->" << actual->next << " : "  << indicator_string()  << "\n";
			}
			else if(dfa::DFA<T,S,O>::c == '\0')
			{
				out << dfa::DFA<T,S,O>::current << "--\\0->" << actual->next << " : "  << indicator_string()  << "\n";
			}
			else
			{
				out << dfa::DFA<T,S,O>::current << "--" << dfa::DFA<T,S,O>::c << "->" << actual->next << " : "  << indicator_string()  << "\n";
			}
		}
		void print(std::wostream& out) const
		{
				if(dfa::DFA<T,S,O>::c == '\n')
				{
					out << dfa::DFA<T,S,O>::current << "--New line->" << actual->next << " : "  << indicator_string()  << "\n";
				}
				else if(dfa::DFA<T,S,O>::c == '\t')
				{
					out << dfa::DFA<T,S,O>::current << "--Tabulator->" << actual->next << " : "  << indicator_string()  << "\n";
				}
				else if(dfa::DFA<T,S,O>::c == ' ')
				{
					out << dfa::DFA<T,S,O>::current << "--Espace->" << actual->next << " : "  << indicator_string()  << "\n";
				}
				else if(dfa::DFA<T,S,O>::c == '\0')
				{
					out << dfa::DFA<T,S,O>::current << "--\\0->" << actual->next << " : "  << indicator_string()  << "\n";
				}
				else
				{
					out << dfa::DFA<T,S,O>::current << "--" << dfa::DFA<T,S,O>::c << "->" << actual->next << " : " << indicator_string()  << "\n";
				}
		}
		Word transition(const T* string)
		{
			if(not string) return 0;
			
			dfa::DFA<T,S,O>::current = dfa::DFA<T,S,O>::reset;
			dfa::DFA<T,S,O>::i = 0;	
			//accepted = NULL;

			do
			{
				dfa::DFA<T,S,O>::c = string[dfa::DFA<T,S,O>::i];
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,S,O>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,S,O>::current << "\n";
					//std::cout << "c : '" << cc::DFA<T,S,O>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) cc::DFA<T,S,O>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(dfa::DFA<T,S,O>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(dfa::DFA<T,S,O>::echo)
					{
						if(prev) 
						{
							//std::cout << "prev registered..\n";
							if(prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,S,O>::i << "..\n";
					}
#endif
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,S,O>::echo) std::cout << "'" << string[cc::DFA<T,S,O>::i]  << "'" << "\n";
#endif
						actual = prev;
						return dfa::DFA<T,S,O>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(dfa::DFA<T,S,O>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				actual = &table[dfa::DFA<T,S,O>::current][(unsigned char)dfa::DFA<T,S,O>::c];
				
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,S,O>::echo)
				{
					print(std::cout);
				}
#endif

				if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					//if(cc::DFA<T,S,O>::echo) std::cout << "'" << string[cc::DFA<T,S,O>::i]  << "'" << "\n";
#endif
					//std::cout << " i : " << i  << "\n";
					if(prev) if(prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(dfa::DFA<T,S,O>::echo) std::cout << "'" << string[dfa::DFA<T,S,O>::i]  << "'" << "\n";
#endif
						actual = prev;
						return dfa::DFA<T,S,O>::i;
					}
					return 0;
				}
				else if(actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				dfa::DFA<T,S,O>::current = actual->next;
				prev = actual;
				dfa::DFA<T,S,O>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			return 0;
		}
		Word transition(Buffer<T>& buff)
		{
			if(buff.empty()) return 0;
			
			dfa::DFA<T,S,O>::current = dfa::DFA<T,S,O>::reset;
			dfa::DFA<T,S,O>::i = 0;	
			accepted = NULL;
			dfa::DFA<T,S,O>::eating = 0;
			
			do
			{
				dfa::DFA<T,S,O>::c = buff[dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i];
#if OCTETOS_CC_DEGUB
				//if(dfa::DFA<T,S,O>::echo) std::cout << "Step : " << dfa::DFA<T,S,O>::i << "\n";
				if(dfa::DFA<T,S,O>::echo)
				{
					//std::cout << "current : " << cc::DFA<T,S,O>::current << "\n";
					//std::cout << "c : '" << DFA<T,S,O>::c  << "'\n";
					//std::cout << "symbol : " << (unsigned short) DFA<T,S,O>::c << "\n";
					//std::cout << "length : " << length << "\n";
				}
#endif
				if(dfa::DFA<T,S,O>::c == '\0')
				{
#if OCTETOS_CC_DEGUB
					if(dfa::DFA<T,S,O>::echo)
					{
						if(prev) 
						{
							//std::cout << "prev registered..\n";
							if(prev->indicator == tt::Indicator::Accept) std::cout << "prev Accetable..\n";
						}
						//std::cout << "endign..\n";
						//std::cout << "i = " << cc::DFA<T,S,O>::i << "..\n";
					}
#endif
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept)
					{
#if OCTETOS_CC_DEGUB
						//if(cc::DFA<T,S,O>::echo) std::cout << "'" << string[cc::DFA<T,S,O>::i]  << "'" << "\n";
#endif
						//actual = prev;
						accepted = prev;
						buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
						return dfa::DFA<T,S,O>::i;
					}

					return 0;//si no se encontrontro transiscion
				}
				
				if(dfa::DFA<T,S,O>::current > length - 1) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
				actual = &table[dfa::DFA<T,S,O>::current][(unsigned char)dfa::DFA<T,S,O>::c];
				
#if OCTETOS_CC_DEGUB
				if(dfa::DFA<T,S,O>::echo)
				{
					print(std::cout);
				}
#endif

				if(actual->token == (tt::Tokens)'\n')
				{
					dfa::DFA<T,S,O>::line++;
				}
				else if(actual->token == (tt::Tokens)' ')
				{
					dfa::DFA<T,S,O>::column++;
				}
				else if(actual->token == (tt::Tokens)'\t')
				{
					dfa::DFA<T,S,O>::column += dfa::DFA<T,S,O>::tab_size;
				}

				if(actual->indicator == tt::Indicator::Left_Eat)
				{
					dfa::DFA<T,S,O>::i = 0;
					dfa::DFA<T,S,O>::current = actual->next;
					prev = actual;
					//std::cout << "Eating\n";
					dfa::DFA<T,S,O>::eating++;
					continue;
				}
				else if(actual->indicator == tt::Indicator::Accept_Inmediatly)
				{					
					dfa::DFA<T,S,O>::i++;
					buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
					accepted = actual;
					return dfa::DFA<T,S,O>::i;
				}
				else if(actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					//if(cc::DFA<T,S,O>::echo) std::cout << "'" << string[cc::DFA<T,S,O>::i]  << "'" << "\n";
#endif
					
					if(prev) if(prev->indicator == tt::Indicator::Accept) 
					{
#if OCTETOS_CC_DEGUB
						if(dfa::DFA<T,S,O>::echo) 
						{
							//std::cout << (unsigned int) buff[dfa::DFA<T,S,O>::i] << "\n";
							//std::cout << " i : " << dfa::DFA<T,S,O>::i  << "\n";
						}
#endif
						//actual = prev;
						accepted = prev;
						buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
						return dfa::DFA<T,S,O>::i;
					}
					return 0;
				}
				else if(actual->indicator == tt::Indicator::Reject)//preanalisis solo para 1
				{
					//if(prev) if(prev->indicator == tt::Indicator::Accept) return i;
					return 0;
				}
				
				dfa::DFA<T,S,O>::current = actual->next;
				prev = actual;
				dfa::DFA<T,S,O>::i++;
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
		const tt::a::Transition *prev;
		const tt::a::Transition *actual;
		const tt::a::Transition *accepted;
		const tt::a::Transition *eat;
		//tt::Status current;
		//Word reset;
		//const tt::a::Transition *accepted;
	};


	
	
	template<typename T/*char*/,typename Token,typename S = Word/*Status*/,typename O = Word/*Offset*/>
	class B : public dfa::DFA<T,S,O>
	{

	public:
		B() : table(NULL),accepted(NULL)
		{
		}
		B(const tt::b::TT<T,Token>& t) : table(&t), accepted(NULL)
		{
		}
		
		/*
		void load(const tt::b::TT<T,Token>& t)
		{
			table = &t;
		}*/

		const tt::b::Transition<T,Token>* search(tt::Status current,T input)
		{
			return search(current,input,0,table->size() - 1);
		}
		
		/**
		*\brief determina hasta donde la string indicada pertence al lenguaje del automata indicado
		*\return la cantidad de caracteres acpetados par el lenguaje
		*/
		O transition(const T* string)
		{
			if(not string) return 0;
			
			DFA<T,S,O>::current = dfa::DFA<T,S,O>::reset;
			DFA<T,S,O>::i = 0;	
			prev = NULL;

			do
			{
#if OCTETOS_CC_DEGUB
				//std::cout << string[DFA<T,S,O>::i] << "\n";
#endif				
				if(string[DFA<T,S,O>::i] == '\0')
				{
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else if(prev) if(prev->indicator == tt::Indicator::Accept) return DFA<T,S,O>::i;
					return 0;//si no se encontrontro transiscion
				}

				actual = next(string[dfa::DFA<T,S,O>::i]);
				
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
				dfa::DFA<T,S,O>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);

			
			
			return dfa::DFA<T,S,O>::i;
		}
		O transition(Buffer<T>& buff)
		{
			if(buff.empty()) return 0;
			
			DFA<T,S,O>::current = dfa::DFA<T,S,O>::reset;
			DFA<T,S,O>::i = 0;	
			prev = NULL;
			accepted = NULL;
			dfa::DFA<T,S,O>::eating = 0;
			
			do
			{
#if OCTETOS_CC_DEGUB
				if(DFA<T,S,O>::echo)
				{
					//std::cout << "current : '"<<  dfa::DFA<T,S,O>::current << "'\n";
					//std::cout << "i : '"<<  DFA<T,S,O>::i << "'\n";
					//std::cout << "c : '"<< buff[DFA<T,S,O>::i] << "'\n";
					//std::cout << "code : '"<< (unsigned int)buff[DFA<T,S,O>::i] << "'\n";		
				}
#endif				
				if(Token(buff[DFA<T,S,O>::i]) == Token(0))
				{
					if(dfa::DFA<T,S,O>::i == 0) return 0;
					else 
					{
						if(prev) if(prev->indicator == tt::Indicator::Accept) 
						{
							buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
							accepted = prev;
							return DFA<T,S,O>::i;
						}
					}
					return 0;//si no se encontrontro transiscion
				}
				
				actual = next(buff[dfa::DFA<T,S,O>::i]);
				
				if(not actual) 
				{
#if OCTETOS_CC_DEGUB
					//if(DFA<T,S,O>::echo) std::cout << "not actual\n";
#endif	
					return 0;//si no se encontrontro transiscion
				}
				
#if OCTETOS_CC_DEGUB
				if(DFA<T,S,O>::echo) actual->print(std::cout);				
#endif

				if(actual->token == (tt::Tokens)'\n')
				{
					dfa::DFA<T,S,O>::line++;
				}
				else if(actual->token == (tt::Tokens)' ')
				{
					dfa::DFA<T,S,O>::column++;
				}
				else if(actual->token == (tt::Tokens)'\t')
				{
					dfa::DFA<T,S,O>::column += DFA<T,S,O>::tab_size;
				}

				if(actual->indicator == tt::Indicator::Accept_Inmediatly)
				{
					accepted = actual;
					buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
					return ++DFA<T,S,O>::i;
				}
				else if(actual->indicator == tt::Indicator::Left_Eat)
				{
					if(actual->input == buff[DFA<T,S,O>::i])
					{
						dfa::DFA<T,S,O>::i++;
						continue;
					}
				}
				else if(actual->indicator == tt::Indicator::Prefix_Accept)
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
							accepted = prev;
							buff.walk((size_t)(dfa::DFA<T,S,O>::eating + dfa::DFA<T,S,O>::i));
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
				
				prev = actual;
				dfa::DFA<T,S,O>::i++;
			}
			while(actual->indicator != tt::Indicator::Reject);			
			
			return dfa::DFA<T,S,O>::i;
		}
		
		const tt::b::TT<T,Token>& get_table() const
		{
			return *table;
		}
				
		void print(std::ostream& out) const
		{
			//std::cout << "size : " << table->size() << "\n";
			for(size_t i = 0; i < table->size(); i++)
			{	
				//std::cout << "Transition : ";
				(*table)[i].print(out);
			}
		}

		const tt::b::Transition<T,Token>* get_accepted()const
		{
			return accepted;
		}
		
	protected:
		const tt::b::Transition<T,Token>* next(T symbol)
		{
#if OCTETOS_CC_DEGUB
			/*if(DFA<T,S,O>::echo)
			{
				std::cout << "current : " << dfa::DFA<T,S,O>::current << "\n";
				std::cout << "symbol : " << (int)symbol << "\n";
				//std::cout << "char : " << (char)symbol << "\n";
			}*/
#endif
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
	private:	
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
	protected:
		const tt::b::TT<T,Token>* table;
		const tt::b::Transition<T,Token>* accepted,*prev, *actual;
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


	
}
namespace oct::cc::pda
{

/*
template <typename C,typename Token,typename Status = Word,typename O = Word> class B : public dfa::B1<C,Token,Status,O>
{
public:
	B1()
	{
	}
	B1(const tt::b::TT<C,Token>& t) 
	{
	}
private:
	std::stack<Token> stack;
};
*/

template<typename C, typename Token, typename S = Word, typename O = Word> class BA : public dfa::B<Token,Token,S,O>
{
public:
	BA(const tt::a::tt_element* lextt, size_t lexl, const tt::b::TT<Token,Token>& t) : dfa::B<Token,Token,S,O>(t), lex_tt(lextt), lex_length(lexl)
	{
		//lexer.enable_echo(true);
	}
	

	
	O transition(Buffer<C>& buff)
	{
		if(buff.empty()) return 0;
			
			dfa::B<Token,Token,S,O>::current = dfa::B<Token,Token,S,O>::reset;
			dfa::B<Token,Token,S,O>::i = 0;
			j = 0;
			dfa::B<Token,Token,S,O>::prev = NULL;
			dfa::B<Token,Token,S,O>::accepted = NULL;
			dfa::DFA<Token,S,O>::eating = 0;

			do
			{
#if OCTETOS_CC_DEGUB
				lexer.enable_echo(dfa::B<Token,Token,S,O>::echo);
				if(dfa::B<Token,Token,S,O>::echo)
				{
					//std::cout << "\n";
					//std::cout << "\nStep 1\n";
					//std::cout << "current : '"<<  dfa::DFA<T,S,O>::current << "'\n";
					//std::cout << "i : '"<<  DFA<T,S,O>::i << "'\n";
					//std::cout << "c : '"<< buff[DFA<T,S,O>::i] << "'\n";
					//std::cout << "code : '"<< (unsigned int)buff[DFA<T,S,O>::i] << "'\n";		
				}
#endif
				//std::cout << "Step 2\n";				
				//std::cout << "Step 3\n";
				for(size_t ilex = 0; ilex < lex_length; ilex++)	
				{
					//std::cout << "Lex rule : " << ilex << "\n";
					lexer.load(lex_tt[ilex].tt,lex_tt[ilex].length);
					if(lexer.transition(buff) > 0) break;
				}
				//std::cout << "Step 4\n";				
				if(lexer.get_accepted()) 
				{
#if OCTETOS_CC_DEGUB
					//std::cout << "Finding next token.\n";
					if(lexer.get_echo()) 
					{
						//std::cout << "Lexer analyzer\n";
						//std::cout << "Token : " << (int)lexer.get_accepted()->token << "\n";
						const char* str =  tt::token_str((Token)lexer.get_accepted()->token);
						if(str)
						{
							//std::cout << "Step str : " << str;
							if(lexer.get_accepted()->indicator == tt::Indicator::Accept or lexer.get_accepted()->indicator == tt::Indicator::Accept_Inmediatly) std::cout << " : Acceptado.";
							//std::cout << "\n";
						}
					}
#endif
					dfa::B<Token,Token,S,O>::actual = dfa::B<Token,Token,S,O>::next((Token)lexer.get_accepted()->token);
					if(not dfa::B<Token,Token,S,O>::actual) return 0;
					//if(dfa::B<Token,Token,S,O>::actual != NULL) std::cout << "running..\n";
				}
				else
				{
#if OCTETOS_CC_DEGUB
					if(dfa::B<Token,Token,S,O>::echo)
					{
						//std::cout << "Grammar analyzer : " << buff[dfa::B<Token,Token,S,O>::i] << "\n";
						//std::cout << "Grammar analyzer Buffer base: " << buff.get_base() << "\n";
						//std::cout << "Grammar analyzer Buffer j: " << j << "\n";
						//std::cout << "Grammar analyzer Buffer base: \"" << buff.get_base_string() << "\"\n";
					}
#endif
					dfa::B<Token,Token,S,O>::actual = dfa::B<Token,Token,S,O>::next((tt::Tokens)buff[j]);
					//if(dfa::B<Token,Token,S,O>::actual != NULL) std::cout << "running..\n";
					if(not dfa::B<Token,Token,S,O>::actual) return 0;
					j++;
				}
				
				//std::cout << "Step 5\n";
				//std::cout << "Step 6\n";
				
#if OCTETOS_CC_DEGUB
				if(dfa::B<Token,Token,S,O>::echo) 
				{
					//std::cout << "Gram : " << (int)dfa::B<Token,Token,S,O>::actual->token << "\n";
					const char* str =  tt::token_str(dfa::B<Token,Token,S,O>::actual->token);
					//std::cout << "Gram : ";
					//if(str) std::cout << str << "\n";
					//dfa::B<Token,Token,S,O>::actual->print(std::cout);
				}
#endif

				//std::cout << "Step 7\n";
								
				if(dfa::B<Token,Token,S,O>::actual->token == (tt::Tokens)'\n')
				{
					dfa::B<Token,Token,S,O>::line++;
				}
				else if(dfa::B<Token,Token,S,O>::actual->token == (tt::Tokens)' ')
				{
					dfa::B<Token,Token,S,O>::column++;
				}
				else if(dfa::B<Token,Token,S,O>::actual->token == (tt::Tokens)'\t')
				{
					dfa::B<Token,Token,S,O>::column += dfa::B<Token,Token,S,O>::tab_size;
				}
				
				//std::cout << "Step 8\n";
				
				if(dfa::B<Token,Token,S,O>::actual->indicator == tt::Indicator::Left_Eat)
				{
					//dfa::B<Token,Token,S,O>::i = 0;
					dfa::B<Token,Token,S,O>::current = dfa::B<Token,Token,S,O>::actual->next;
					dfa::B<Token,Token,S,O>::prev = dfa::B<Token,Token,S,O>::actual;
					//buff.next_char();
					dfa::DFA<Token,S,O>::eating++;
					//std::cout << "Eating\n";
					continue;
				}
				else if(dfa::B<Token,Token,S,O>::actual->indicator == tt::Indicator::Accept_Inmediatly)
				{
#if OCTETOS_CC_DEGUB
					//std::cout << "Accept_Inmediatly\n";
#endif	
					dfa::B<Token,Token,S,O>::accepted = dfa::B<Token,Token,S,O>::actual;
					buff.walk((size_t) j);
					return ++dfa::B<Token,Token,S,O>::i;
				}
				else if(dfa::B<Token,Token,S,O>::actual->indicator == tt::Indicator::Prefix_Accept)
				{
#if OCTETOS_CC_DEGUB
					//std::cout << "Prefix_Accept\n";
#endif				
					if(dfa::B<Token,Token,S,O>::prev) 
					{
#if OCTETOS_CC_DEGUB
						//std::cout << "prev exist\n";
#endif
						if(dfa::B<Token,Token,S,O>::prev->indicator == tt::Indicator::Accept) 
						{
#if OCTETOS_CC_DEGUB
							//std::cout << "prev exist acepted\n";
#endif
							dfa::B<Token,Token,S,O>::accepted = dfa::B<Token,Token,S,O>::actual;
							buff.walk((size_t)j);
							return dfa::B<Token,Token,S,O>::i;
						}
					}
					return 0;//si no se encontrontro transiscion
				}
				 
#if OCTETOS_CC_DEGUB
				//std::cout << "Next token\n";
#endif		
				dfa::B<Token,Token,S,O>::prev = dfa::B<Token,Token,S,O>::actual;
				dfa::B<Token,Token,S,O>::i++;
				//std::cout << "Step 9\n";
			}
			while(dfa::B<Token,Token,S,O>::actual->indicator != tt::Indicator::Reject);
			
		return 0;
	}
	
private:
	dfa::A<C,S,O> lexer;
	const tt::a::tt_element* lex_tt;
	size_t lex_length;
	unsigned short j;
};

}

#endif