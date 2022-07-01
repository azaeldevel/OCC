

#ifndef OCTETOS_CC_PARSER_HH
#define OCTETOS_CC_PARSER_HH

/*
 * Lexer.hh
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


#include "Lexer.hh"

#include <list>

namespace oct::cc
{



class Parser
{
protected:

public:
	Parser(Lexer&,const Tray&);
	/**
	*\return true si la compilacion es correcta, false si hubo algun error
	*/
	virtual bool next() = 0;
	
protected:
	Lexer* lexer;
	const Tray* tray;
	std::size_t begin, end;

};


namespace A
{
	class Parser : public oct::cc::Parser
	{
	public:
		
	public:
		Parser(Lexer&,const Tray&);
		virtual bool next();
		
	private:

		bool is_label();
		bool is_inst();

		bool is_insts(const char*);

		void fill_insts();
		
		struct inst_pair
		{
			const char* inst;
			Code code;
			
			inst_pair();
			inst_pair(const char*);

			bool operator == (const inst_pair&);

		};
		static bool cmp(const inst_pair& f, const inst_pair& s);

		std::vector<inst_pair> insts;
		
	};
}


}




#endif