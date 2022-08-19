


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

#include <iostream>
#include <cctype>

#include "tt.hh"


namespace oct::cc::tt
{

	const char* token_str(Tokens tok)
	{
		switch(tok)
		{
		case (Tokens)'e': return "e";
		case (Tokens)';': return ";";
		case Tokens::none: return "none";
		case Tokens::i8086_mov: return "i808x-mov";
		case Tokens::Integer: return "Integer";
		case Tokens::Integer_0x: return "Integer-0x";
		case Tokens::i8086_reg_al: return "i808x-register-AL";
		case Tokens::i8086_reg_ah: return "i808x-register-AH";
		case Tokens::i8086_reg_bl: return "i808x-register-BL";
		case Tokens::i8086_reg_bh: return "i808x-register-BH";
		case Tokens::i8086_reg_cl: return "i808x-register-CL";
		case Tokens::i8086_reg_ch: return "i808x-register-CH";
		case Tokens::i8086_reg_dl: return "i808x-register-DL";
		case Tokens::i8086_reg_dh: return "i808x-register-DH";
		case Tokens::i8086_reg_ax: return "i808x-register-AX";
		case Tokens::i8086_reg_bx: return "i808x-register-BX";
		case Tokens::i8086_reg_cx: return "i808x-register-BX";
		case Tokens::i8086_reg_dx: return "i808x-register-BX";
		case Tokens::gram_inst_mov: return "gram-inst-mov";
		case Tokens::char_literal: return "char lireal";
		}
		
		return NULL;
	}
	 
namespace a
{
	bool check(const Transition (*t)[MAX_SIMBOLS],size_t length, std::vector<Selector>& errors)
	{
		for(unsigned int i = 0; i < length; i++)
		{
			for(unsigned short j = 0; j < 128; j++)
			{
				//std::cout << "cheking (" << i << "," << j << ")\n";
				if(t[i][j].indicator ==  Indicator::Reject and t[i][j].next == 0 and t[i][j].token == Tokens::none) continue;
				if(t[i][j].indicator ==  Indicator::None and t[i][j].next > 0 and t[i][j].token == Tokens::none) continue;
				if(t[i][j].indicator ==  Indicator::Prefix_Accept and t[i][j].next == 0 and t[i][j].token == Tokens::none) continue;
				if(t[i][j].indicator ==  Indicator::Accept and t[i][j].token != (Tokens)0) continue;
				if(t[i][j].indicator ==  Indicator::Left_Eat and t[i][j].token == Tokens::none) continue;
				if(t[i][j].indicator ==  Indicator::Left_Eat and t[i][j].token < Tokens::none) continue;
				errors.push_back({i,j});
			}
		}

		return true;
	}
 }


namespace b
{
#if OCTETOS_CC_DEGUB
	template<> void  Transition<char,Tokens>::print(std::ostream& out) const
	{
		if(input == '\n')
		{
			out << current << "--New line->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == '\t')
		{
			out << current << "--Tabulator->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == ' ')
		{
			out << current << "--Espace->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == '\0')
		{
			out << current << "--\\0->" << next << "\n";
		}
		else if((Status) input > 128)
		{
			out << current << "--" << (unsigned int)input << "->" << next  << " : " << indicator_string() << "\n";
		}
		else
		{
			out << current << "--" << input << "->" << next  << " : " << indicator_string() << "\n";
		}
	}
	template<> void  Transition<char,Tokens>::print(std::wostream& out) const
	{
	}

	
	template<> void  Transition<wchar_t,Tokens>::print(std::ostream& out) const
	{
	}
	template<> void  Transition<wchar_t,Tokens>::print(std::wostream& out) const
	{
		if(input == '\n')
		{
				out << current << "--New line->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == '\t')
		{
				out << current << "--Tabulator->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == ' ')
		{
				out << current << "--Espace->" << next  << " : " << indicator_string() << "\n";
		}
		else if(input == '\0')
		{
				out << current << "--\\0->" << next  << " : " << indicator_string() << "\n";
		}
		else if((Status) input > 128)
		{
			out << current << "--" << (unsigned int)input << "->" << next  << " : " << indicator_string() << "\n";
		}
		else
		{
			out << current << "--" << input << "->" << next  << " : " << indicator_string() << "\n";
		}
	}



	template<> void  Transition<Tokens,Tokens>::print(std::ostream& out) const
	{
		if(input < (Tokens)tt::MAX_SIMBOLS)
		{
			if(isalpha((char)input) or isdigit((char)input) or ispunct((char)input))
			{
				out << current << "--" << (char)input << "->" << next  << " : " << indicator_string() << "\n";
			}
			else if(input == (Tokens)'\n')
			{
				out << current << "--New line->" << next  << " : " << indicator_string() << "\n";
			}
			else if(input == (Tokens)'\t')
			{
				out << current << "--Tabulator->" << next  << " : " << indicator_string() << "\n";
			}
			else if(input == (Tokens)' ')
			{
				out << current << "--Espace->" << next  << " : " << indicator_string() << "\n";
			}
			else if(input == (Tokens)'\0')
			{
				out << current << "--\\0->" << next  << " : " << indicator_string() << "\n";
			}
			else 
			{
				out << current << "--" << (char)input << "->" << next  << " : " << indicator_string() << "\n";
			}
		}
		else if(input >= (Tokens)tt::MAX_SIMBOLS)
		{
			//out << current << "--" << token_str(input) << "->" << next << "\n";
			out << current << "--" << (int)input << "->" << next  << " : " << indicator_string() << "\n";
		}
	}	
	template<> void  Transition<Tokens,Tokens>::print(std::wostream& out) const
	{		
	}
	
#endif
}


}
