

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


namespace oct::cc
{



class Parser
{

public:
	Parser(Lexer&,const Tray&);
	virtual bool run() = 0;

protected:
	Lexer* lexer;
	const Tray* tray;
};


namespace A
{
	class Parser : public oct::cc::Parser
	{

	public:
		Parser(Lexer&,const Tray&);
		bool run();
	private:
		bool stmt_inst();
		bool stmt_label();
	};
}


}




#endif