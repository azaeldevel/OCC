
#ifndef OCTETOS_CC_TT_HH
#define OCTETOS_CC_TT_HH


/*
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 * 
 * octetos-CC is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define LENGTH_TT(TABLE) sizeof (TABLE) / sizeof (TABLE[0])
#define TABLE(T) T,sizeof (T) / sizeof (T[0])


#include <vector>
#include <octetos/core/core.hh>
#include <initializer_list>

#include "Exception.hh"

namespace oct::cc::tt
{

	//typedef unsigned long long int Word;
	typedef Word Status;
	typedef Word Token;

	static const unsigned char MAX_SIMBOLS = 128;
	static const Token base_token = 1024;

	enum class Indicator : Status
	{
		None,
		Accept,
		Reject,
		Prefix_Accept,
		Eat,
		Accept_Inmediatly
	};

	enum class Tokens : Token
	{
		none = base_token,

		error,

		file,
		file_section,
		file_code,
		file_list_instructions,
		
		i8086,
		i8086_aaa,
		i8086_aad,
		i8086_aam,
		i8086_aas,
		i8086_adc,
		i8086_add,
		i8086_and_token,
		i8086_call,
		i8086_cbw,
		i8086_clc,
		i8086_cld,
		i8086_cli,
		i8086_cmc,
		i8086_cmp,
		i8086_cmps,
		i8086_cwd,
		i8086_daa,
		i8086_das,
		i8086_dec,
		i8086_div,
		i8086_esc,
		i8086_hlt,
		i8086_idiv,
		i8086_imul,
		i8086_in,
		i8086_inc,
		i8086_int_token,
		i8086_intr,
		i8086_into,
		i8086_iret,
		i8086_ja,
		i8086_jae,
		i8086_jb,
		i8086_jbe,
		i8086_jc,
		i8086_jcxz,
		i8086_je,
		i8086_jz,
		i8086_jg,
		i8086_jge,
		i8086_jl,
		i8086_jle,
		i8086_jmp,
		i8086_jnc,
		i8086_jne,
		i8086_jno,
		i8086_jnp,
		i8086_jns,
		i8086_jo,
		i8086_jp,
		i8086_js,
		i8086_lahf,
		i8086_lds,
		i8086_lea,
		i8086_les,
		i8086_lock,
		i8086_lods,
		i8086_loop,
		i8086_loope,
		i8086_loopne,
		i8086_nmi,
		i8086_mov,

		regs,
		i8086_reg_al,
		i8086_reg_ah,
		i8086_reg_ax,
		i8086_reg_bl,
		i8086_reg_bh,
		i8086_reg_bx,
		i8086_reg_cl,
		i8086_reg_ch,
		i8086_reg_cx,
		i8086_reg_dl,
		i8086_reg_dh,
		i8086_reg_dx,
		
		Identifier,
		Integer,
		Integer_0x,

		grammar,
		
		gram_file,
		gram_list_insts,
		gram_inst,
		gram_inst_mov,
		gram_inst_int,
	};

	const char* token_str(Tokens tok);
	
namespace a
{
	struct Transition
	{
		Indicator indicator;
		Status next;
		Word token;
	};
	
	struct Selector
	{
		unsigned int i;
		unsigned short j;
	};

	//static const Token base_token = 1024;
	
	bool check(const Transition (*t)[MAX_SIMBOLS],size_t s, std::vector<Selector>& errors);

	struct tt_element
	{
		const Transition (*tt)[MAX_SIMBOLS];
		size_t length;
	};
	
/*
	static const Transition [][tt::MAX_SIMBOLS] = {
	//0
		{
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//tab
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},	
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//' '
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//0
			{Indicator::Reject,0},//1
			{Indicator::Reject,0},//2
			{Indicator::Reject,0},//3
			{Indicator::Reject,0},//4
			{Indicator::Reject,0},//5
			{Indicator::Reject,0},//6
			{Indicator::Reject,0},//7
			{Indicator::Reject,0},//8
			{Indicator::Reject,0},//9
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//A
			{Indicator::Reject,0},//B
			{Indicator::Reject,0},//C
			{Indicator::Reject,0},//D
			{Indicator::Reject,0},//E
			{Indicator::Reject,0},//F
			{Indicator::Reject,0},//G
			{Indicator::Reject,0},//H
			{Indicator::Reject,0},//I
			{Indicator::Reject,0},//J
			{Indicator::Reject,0},//K
			{Indicator::Reject,0},//L
			{Indicator::Reject,0},//M
			{Indicator::Reject,0},//N
			{Indicator::Reject,0},//O
			{Indicator::Reject,0},//P
			{Indicator::Reject,0},//Q
			{Indicator::Reject,0},//R
			{Indicator::Reject,0},//S
			{Indicator::Reject,0},//T
			{Indicator::Reject,0},//U
			{Indicator::Reject,0},//V
			{Indicator::Reject,0},//W
			{Indicator::Reject,0},//X
			{Indicator::Reject,0},//Y
			{Indicator::Reject,0},//Z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},//_
			{Indicator::Reject,0},
			{Indicator::Reject,0},//a
			{Indicator::Reject,0},//b
			{Indicator::Reject,0},//c
			{Indicator::Reject,0},//d
			{Indicator::Reject,0},//e
			{Indicator::Reject,0},//f
			{Indicator::Reject,0},//g
			{Indicator::Reject,0},//h
			{Indicator::Reject,0},//i
			{Indicator::Reject,0},//j
			{Indicator::Reject,0},//k
			{Indicator::Reject,0},//l
			{Indicator::Reject,0},//m
			{Indicator::Reject,0},//n
			{Indicator::Reject,0},//o
			{Indicator::Reject,0},//p
			{Indicator::Reject,0},//q
			{Indicator::Reject,0},//r
			{Indicator::Reject,0},//s
			{Indicator::Reject,0},//t
			{Indicator::Reject,0},//u
			{Indicator::Reject,0},//v
			{Indicator::Reject,0},//w
			{Indicator::Reject,0},//x
			{Indicator::Reject,0},//y
			{Indicator::Reject,0},//z
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
			{Indicator::Reject,0},
		},
	};
*/
	

}

namespace b
{
	template<typename T,typename Token>
	struct Transition //transition B
	{
		Status current;
		T input;
		Indicator indicator;
		Status next;
		Token token;

		bool operator < (const Transition<T,Token>& obj) const
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
		bool operator > (const Transition<T,Token>& obj) const
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
	
#if OCTETOS_CC_DEGUB
		void print(std::ostream& out) const;
		void print(std::wostream& out) const;
#endif
	
	};

	template<typename T,typename Token,typename I = size_t> class TT
	{
	public:
		//
		TT(std::initializer_list<Transition<T,Token>> d) : _size(d.size())
		{
			table = new Transition<T,Token>[d.size()];
			unsigned int i = 0;
			for(const Transition<T,Token>& t : d)
			{
				table[i] = t;
				i++;
			}
			sort(table,d.size());
		}
		~TT() 
		{	
			delete[] table;
		}

		Transition<T,Token>& operator [](size_t index) const
		{
			return table[index];
		}
		
		inline size_t size() const
		{
			return _size;
		}
	private:
		Transition<T,Token>* table;	
		size_t _size;

		void copy(I begin, I end,Transition<T,Token>* in, Transition<T,Token>* out)
		{
			for(I i = begin; i < end; i++)
			{
				out[i] = in[i];
			}
		}
		void merge(Transition<T,Token>* in,I begin, I middle, I end,Transition<T,Token>* out)
		{
			I i = begin;
			I j = middle;
			I k = begin;

			while(i < middle && j <= end)
			{
				if (in[i] < in[j])
				{
						//std::cout << " : Cierto\n";
						out[k] = in[i];
						i++;
				}
				else
				{
						//std::cout << " : Falso\n";
						out[k] = in[j];
						j++;
				}
				k++;
			}
			while(i < middle )
			{
					//std::cout << "\tvaciando " << in[i]->index << "\n";
					out[k] = in[i];
					i++;
					k++;
			}
			while(j <= end )
			{
					//std::cout << "\tvaciando " << in[j]->index << "\n";
					out[k] = in[j];
					j++;
					k++;
			}
		}
		void split(Transition<T,Token>* out,I begin, I end,Transition<T,Token>* in)
		{
			if (end - begin < 1) return;
				
			I middle = begin + (end - begin) / 2;

			split(in,begin,middle,out);
			split(in,middle + 1,end,out);

			merge(out,begin,middle+1,end,in);
		}
		void sort(Transition<T,Token>* data, size_t length)
		{
			Transition<T,Token> work[length];	

			copy(0,length,data,work);
			split(work,0,length - 1,data);
		}
	};


	static const TT<char,Tokens> Identifier{
		
		{0,'A',Indicator::Accept,1,Tokens::Identifier},
		{0,'B',Indicator::Accept,1,Tokens::Identifier},
		{0,'C',Indicator::Accept,1,Tokens::Identifier},
		{0,'D',Indicator::Accept,1,Tokens::Identifier},
		{0,'E',Indicator::Accept,1,Tokens::Identifier},
		{0,'F',Indicator::Accept,1,Tokens::Identifier},
		{0,'G',Indicator::Accept,1,Tokens::Identifier},
		{0,'H',Indicator::Accept,1,Tokens::Identifier},
		{0,'I',Indicator::Accept,1,Tokens::Identifier},
		{0,'J',Indicator::Accept,1,Tokens::Identifier},
		{0,'K',Indicator::Accept,1,Tokens::Identifier},
		{0,'L',Indicator::Accept,1,Tokens::Identifier},
		{0,'M',Indicator::Accept,1,Tokens::Identifier},
		{0,'N',Indicator::Accept,1,Tokens::Identifier},
		{0,'O',Indicator::Accept,1,Tokens::Identifier},
		{0,'P',Indicator::Accept,1,Tokens::Identifier},
		{0,'Q',Indicator::Accept,1,Tokens::Identifier},
		{0,'R',Indicator::Accept,1,Tokens::Identifier},
		{0,'S',Indicator::Accept,1,Tokens::Identifier},
		{0,'T',Indicator::Accept,1,Tokens::Identifier},
		{0,'U',Indicator::Accept,1,Tokens::Identifier},
		{0,'V',Indicator::Accept,1,Tokens::Identifier},
		{0,'W',Indicator::Accept,1,Tokens::Identifier},
		{0,'X',Indicator::Accept,1,Tokens::Identifier},
		{0,'Y',Indicator::Accept,1,Tokens::Identifier},
		{0,'Z',Indicator::Accept,1,Tokens::Identifier},

		{0,'_',Indicator::Accept,1,Tokens::Identifier},

		{0,'a',Indicator::Accept,1,Tokens::Identifier},
		{0,'b',Indicator::Accept,1,Tokens::Identifier},
		{0,'c',Indicator::Accept,1,Tokens::Identifier},
		{0,'d',Indicator::Accept,1,Tokens::Identifier},
		{0,'e',Indicator::Accept,1,Tokens::Identifier},
		{0,'f',Indicator::Accept,1,Tokens::Identifier},
		{0,'g',Indicator::Accept,1,Tokens::Identifier},
		{0,'h',Indicator::Accept,1,Tokens::Identifier},
		{0,'i',Indicator::Accept,1,Tokens::Identifier},
		{0,'j',Indicator::Accept,1,Tokens::Identifier},
		{0,'k',Indicator::Accept,1,Tokens::Identifier},
		{0,'l',Indicator::Accept,1,Tokens::Identifier},
		{0,'m',Indicator::Accept,1,Tokens::Identifier},
		{0,'n',Indicator::Accept,1,Tokens::Identifier},
		{0,'o',Indicator::Accept,1,Tokens::Identifier},
		{0,'p',Indicator::Accept,1,Tokens::Identifier},
		{0,'q',Indicator::Accept,1,Tokens::Identifier},
		{0,'r',Indicator::Accept,1,Tokens::Identifier},
		{0,'s',Indicator::Accept,1,Tokens::Identifier},
		{0,'t',Indicator::Accept,1,Tokens::Identifier},
		{0,'u',Indicator::Accept,1,Tokens::Identifier},
		{0,'v',Indicator::Accept,1,Tokens::Identifier},
		{0,'w',Indicator::Accept,1,Tokens::Identifier},
		{0,'x',Indicator::Accept,1,Tokens::Identifier},
		{0,'y',Indicator::Accept,1,Tokens::Identifier},
		{0,'z',Indicator::Accept,1,Tokens::Identifier},

		{0,' ',Indicator::Prefix_Accept,0,Tokens::none},
		{0,'\t',Indicator::Prefix_Accept,0,Tokens::none},
		{0,'\n',Indicator::Prefix_Accept,0,Tokens::none},

		{1,'0',Indicator::Accept,1,Tokens::Identifier},
		{1,'1',Indicator::Accept,1,Tokens::Identifier},
		{1,'2',Indicator::Accept,1,Tokens::Identifier},
		{1,'3',Indicator::Accept,1,Tokens::Identifier},
		{1,'4',Indicator::Accept,1,Tokens::Identifier},
		{1,'5',Indicator::Accept,1,Tokens::Identifier},
		{1,'6',Indicator::Accept,1,Tokens::Identifier},
		{1,'7',Indicator::Accept,1,Tokens::Identifier},
		{1,'8',Indicator::Accept,1,Tokens::Identifier},
		{1,'9',Indicator::Accept,1,Tokens::Identifier},

		{1,'A',Indicator::Accept,1,Tokens::Identifier},
		{1,'B',Indicator::Accept,1,Tokens::Identifier},
		{1,'C',Indicator::Accept,1,Tokens::Identifier},
		{1,'D',Indicator::Accept,1,Tokens::Identifier},
		{1,'E',Indicator::Accept,1,Tokens::Identifier},
		{1,'F',Indicator::Accept,1,Tokens::Identifier},
		{1,'G',Indicator::Accept,1,Tokens::Identifier},
		{1,'H',Indicator::Accept,1,Tokens::Identifier},
		{1,'I',Indicator::Accept,1,Tokens::Identifier},
		{1,'J',Indicator::Accept,1,Tokens::Identifier},
		{1,'K',Indicator::Accept,1,Tokens::Identifier},
		{1,'L',Indicator::Accept,1,Tokens::Identifier},
		{1,'M',Indicator::Accept,1,Tokens::Identifier},
		{1,'N',Indicator::Accept,1,Tokens::Identifier},
		{1,'O',Indicator::Accept,1,Tokens::Identifier},
		{1,'P',Indicator::Accept,1,Tokens::Identifier},
		{1,'Q',Indicator::Accept,1,Tokens::Identifier},
		{1,'R',Indicator::Accept,1,Tokens::Identifier},
		{1,'S',Indicator::Accept,1,Tokens::Identifier},
		{1,'T',Indicator::Accept,1,Tokens::Identifier},
		{1,'U',Indicator::Accept,1,Tokens::Identifier},
		{1,'V',Indicator::Accept,1,Tokens::Identifier},
		{1,'W',Indicator::Accept,1,Tokens::Identifier},
		{1,'X',Indicator::Accept,1,Tokens::Identifier},
		{1,'Y',Indicator::Accept,1,Tokens::Identifier},
		{1,'Z',Indicator::Accept,1,Tokens::Identifier},

		{1,'_',Indicator::Accept,1,Tokens::Identifier},

		{1,'a',Indicator::Accept,1,Tokens::Identifier},
		{1,'b',Indicator::Accept,1,Tokens::Identifier},
		{1,'c',Indicator::Accept,1,Tokens::Identifier},
		{1,'d',Indicator::Accept,1,Tokens::Identifier},
		{1,'e',Indicator::Accept,1,Tokens::Identifier},
		{1,'f',Indicator::Accept,1,Tokens::Identifier},
		{1,'g',Indicator::Accept,1,Tokens::Identifier},
		{1,'h',Indicator::Accept,1,Tokens::Identifier},
		{1,'i',Indicator::Accept,1,Tokens::Identifier},
		{1,'j',Indicator::Accept,1,Tokens::Identifier},
		{1,'k',Indicator::Accept,1,Tokens::Identifier},
		{1,'l',Indicator::Accept,1,Tokens::Identifier},
		{1,'m',Indicator::Accept,1,Tokens::Identifier},
		{1,'n',Indicator::Accept,1,Tokens::Identifier},
		{1,'o',Indicator::Accept,1,Tokens::Identifier},
		{1,'p',Indicator::Accept,1,Tokens::Identifier},
		{1,'q',Indicator::Accept,1,Tokens::Identifier},
		{1,'r',Indicator::Accept,1,Tokens::Identifier},
		{1,'s',Indicator::Accept,1,Tokens::Identifier},
		{1,'t',Indicator::Accept,1,Tokens::Identifier},
		{1,'u',Indicator::Accept,1,Tokens::Identifier},
		{1,'v',Indicator::Accept,1,Tokens::Identifier},
		{1,'w',Indicator::Accept,1,Tokens::Identifier},
		{1,'x',Indicator::Accept,1,Tokens::Identifier},
		{1,'y',Indicator::Accept,1,Tokens::Identifier},
		{1,'z',Indicator::Accept,1,Tokens::Identifier},

		{1,' ',Indicator::Prefix_Accept,0,Tokens::none},
		{1,'\t',Indicator::Prefix_Accept,0,Tokens::none},
		{1,'\n',Indicator::Prefix_Accept,0,Tokens::none},
	};


	static const TT<char,Tokens> Integer  {
		{0,'0',Indicator::Accept,1},
		{0,'1',Indicator::Accept,1},
		{0,'2',Indicator::Accept,1},
		{0,'3',Indicator::Accept,1},
		{0,'4',Indicator::Accept,1},
		{0,'5',Indicator::Accept,1},
		{0,'6',Indicator::Accept,1},
		{0,'7',Indicator::Accept,1},
		{0,'8',Indicator::Accept,1},
		{0,'9',Indicator::Accept,1},
		{0,' ',Indicator::Prefix_Accept,1},		
		
		{1,'0',Indicator::Accept,1},
		{1,'1',Indicator::Accept,1},
		{1,'2',Indicator::Accept,1},
		{1,'3',Indicator::Accept,1},
		{1,'4',Indicator::Accept,1},
		{1,'5',Indicator::Accept,1},
		{1,'6',Indicator::Accept,1},
		{1,'7',Indicator::Accept,1},
		{1,'8',Indicator::Accept,1},
		{1,'9',Indicator::Accept,1},
		{1,' ',Indicator::Prefix_Accept,1},		
	};
}



}

#endif