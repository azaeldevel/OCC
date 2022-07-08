

#ifndef OCTETOS_CC_AF_A_HH
#define OCTETOS_CC_AF_A_HH


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


#include "Buffer.hh"
#include "AF.hh"


namespace oct::cc::a
{

static Table table{
	{'A',Type::Incomplete,0,1},
	{'B',Type::Incomplete,0,1},
	{'C',Type::Incomplete,0,1},
	{'D',Type::Incomplete,0,1},
	{'E',Type::Incomplete,0,1},
	{'F',Type::Incomplete,0,1},
	{'G',Type::Incomplete,0,1},
	{'H',Type::Incomplete,0,1},
	{'I',Type::Incomplete,0,1},
	{'J',Type::Incomplete,0,1},
	{'K',Type::Incomplete,0,1},
	{'L',Type::Incomplete,0,1},
	{'M',Type::Incomplete,0,1},
	{'N',Type::Incomplete,0,1},
	{'O',Type::Incomplete,0,1},
	{'P',Type::Incomplete,0,1},
	{'Q',Type::Incomplete,0,1},
	{'R',Type::Incomplete,0,1},
	{'S',Type::Incomplete,0,1},
	{'T',Type::Incomplete,0,1},
	{'U',Type::Incomplete,0,1},
	{'V',Type::Incomplete,0,1},
	{'W',Type::Incomplete,0,1},
	{'X',Type::Incomplete,0,1},
	{'Y',Type::Incomplete,0,1},
	{'Z',Type::Incomplete,0,1},
	{'a',Type::Incomplete,0,1},
	{'b',Type::Incomplete,0,1},
	{'c',Type::Incomplete,0,1},
	{'d',Type::Incomplete,0,1},
	{'e',Type::Incomplete,0,1},
	{'f',Type::Incomplete,0,1},
	{'g',Type::Incomplete,0,1},
	{'h',Type::Incomplete,0,1},
	{'i',Type::Incomplete,0,1},
	{'j',Type::Incomplete,0,1},
	{'k',Type::Incomplete,0,1},
	{'l',Type::Incomplete,0,1},
	{'m',Type::Incomplete,0,1},
	{'n',Type::Incomplete,0,1},
	{'o',Type::Incomplete,0,1},
	{'p',Type::Incomplete,0,1},
	{'q',Type::Incomplete,0,1},
	{'r',Type::Incomplete,0,1},
	{'s',Type::Incomplete,0,1},
	{'t',Type::Incomplete,0,1},
	{'u',Type::Incomplete,0,1},
	{'v',Type::Incomplete,0,1},
	{'w',Type::Incomplete,0,1},
	{'x',Type::Incomplete,0,1},
	{'y',Type::Incomplete,0,1},
	{'z',Type::Incomplete,0,1}
};

class AF : public cc::AF
{
public:

private:

};

}

#endif