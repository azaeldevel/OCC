

#ifndef OCTETOS_CC_TT_HH
#define OCTETOS_CC_TT_HH


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


#include "AF.hh"

namespace oct::cc::tt
{

static const Table<char> table_number_10 {
		{0,'0',Indicator::None,1},
		
		{0,'1',Indicator::None,1},
		{0,'2',Indicator::None,1},
		{0,'3',Indicator::None,1},
		{0,'4',Indicator::None,1},
		{0,'5',Indicator::None,1},
		{0,'6',Indicator::None,1},
		{0,'7',Indicator::None,1},
		{0,'8',Indicator::None,1},
		{0,'9',Indicator::None,1},

		{1,'0',Indicator::None,1},
		{1,'1',Indicator::None,1},
		{1,'2',Indicator::None,1},
		{1,'3',Indicator::None,1},
		{1,'4',Indicator::None,1},
		{1,'5',Indicator::None,1},
		{1,'6',Indicator::None,1},
		{1,'7',Indicator::None,1},
		{1,'8',Indicator::None,1},
		{1,'9',Indicator::None,1},

		{1,' ',Indicator::Accept,2},
		{1,'\n',Indicator::Accept,2},
		{1,'\t',Indicator::Accept,2},
		{1,'\0',Indicator::Accept,2},
	};
static const Table<wchar_t> table_number_10L {
		{0,'0',Indicator::None,1},
		
		{0,'1',Indicator::None,1},
		{0,'2',Indicator::None,1},
		{0,'3',Indicator::None,1},
		{0,'4',Indicator::None,1},
		{0,'5',Indicator::None,1},
		{0,'6',Indicator::None,1},
		{0,'7',Indicator::None,1},
		{0,'8',Indicator::None,1},
		{0,'9',Indicator::None,1},

		{1,'0',Indicator::None,1},
		{1,'1',Indicator::None,1},
		{1,'2',Indicator::None,1},
		{1,'3',Indicator::None,1},
		{1,'4',Indicator::None,1},
		{1,'5',Indicator::None,1},
		{1,'6',Indicator::None,1},
		{1,'7',Indicator::None,1},
		{1,'8',Indicator::None,1},
		{1,'9',Indicator::None,1},

		{1,' ',Indicator::Accept,2},
		{1,'\n',Indicator::Accept,2},
		{1,'\t',Indicator::Accept,2},
		{1,'\0',Indicator::Accept,2},
	};

static const Table<char> table_number_16 {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},
		{1,'X',Indicator::None,2},

		{2,'0',Indicator::None,2},
		{2,'1',Indicator::None,2},
		{2,'2',Indicator::None,2},
		{2,'3',Indicator::None,2},
		{2,'4',Indicator::None,2},
		{2,'5',Indicator::None,2},
		{2,'6',Indicator::None,2},
		{2,'7',Indicator::None,2},
		{2,'8',Indicator::None,2},
		{2,'9',Indicator::None,2},
		
		{2,'a',Indicator::None,2},
		{2,'b',Indicator::None,2},
		{2,'c',Indicator::None,2},
		{2,'d',Indicator::None,2},
		{2,'e',Indicator::None,2},
		{2,'f',Indicator::None,2},
		{2,'A',Indicator::None,2},
		{2,'B',Indicator::None,2},
		{2,'C',Indicator::None,2},
		{2,'D',Indicator::None,2},
		{2,'E',Indicator::None,2},
		{2,'F',Indicator::None,2},

		{2,' ',Indicator::Accept,3},
		{2,'\n',Indicator::Accept,3},
		{2,'\t',Indicator::Accept,3},
		{2,'\0',Indicator::Accept,3},
	};
static const Table<wchar_t> table_number_16L {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},
		{1,'X',Indicator::None,2},

		{2,'0',Indicator::None,2},
		{2,'1',Indicator::None,2},
		{2,'2',Indicator::None,2},
		{2,'3',Indicator::None,2},
		{2,'4',Indicator::None,2},
		{2,'5',Indicator::None,2},
		{2,'6',Indicator::None,2},
		{2,'7',Indicator::None,2},
		{2,'8',Indicator::None,2},
		{2,'9',Indicator::None,2},
		
		{2,'a',Indicator::None,2},
		{2,'b',Indicator::None,2},
		{2,'c',Indicator::None,2},
		{2,'d',Indicator::None,2},
		{2,'e',Indicator::None,2},
		{2,'f',Indicator::None,2},
		{2,'A',Indicator::None,2},
		{2,'B',Indicator::None,2},
		{2,'C',Indicator::None,2},
		{2,'D',Indicator::None,2},
		{2,'E',Indicator::None,2},
		{2,'F',Indicator::None,2},

		{2,' ',Indicator::Accept,3},
		{2,'\n',Indicator::Accept,3},
		{2,'\t',Indicator::Accept,3},
		{2,'\0',Indicator::Accept,3},
	};
static const Table<char> table_number_beautifull_16 {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},
		{2,'0',Indicator::None,2},
		{2,'1',Indicator::None,2},
		{2,'2',Indicator::None,2},
		{2,'3',Indicator::None,2},
		{2,'4',Indicator::None,2},
		{2,'5',Indicator::None,2},
		{2,'6',Indicator::None,2},
		{2,'7',Indicator::None,2},
		{2,'8',Indicator::None,2},
		{2,'9',Indicator::None,2},		
		{2,'a',Indicator::None,2},
		{2,'b',Indicator::None,2},
		{2,'c',Indicator::None,2},
		{2,'d',Indicator::None,2},
		{2,'e',Indicator::None,2},
		{2,'f',Indicator::None,2},
		
		{2,' ',Indicator::Accept,5},
		{2,'\n',Indicator::Accept,5},
		{2,'\t',Indicator::Accept,5},
		{2,'\0',Indicator::Accept,5},
		
		{1,'X',Indicator::None,3},
		{3,'0',Indicator::None,3},
		{3,'1',Indicator::None,3},
		{3,'2',Indicator::None,3},
		{3,'3',Indicator::None,3},
		{3,'4',Indicator::None,3},
		{3,'5',Indicator::None,3},
		{3,'6',Indicator::None,3},
		{3,'7',Indicator::None,3},
		{3,'8',Indicator::None,3},
		{3,'9',Indicator::None,3},
		{3,'A',Indicator::None,3},
		{3,'B',Indicator::None,3},
		{3,'C',Indicator::None,3},
		{3,'D',Indicator::None,3},
		{3,'E',Indicator::None,3},
		{3,'F',Indicator::None,3},
		
		{3,' ',Indicator::Accept,5},
		{3,'\n',Indicator::Accept,5},
		{3,'\t',Indicator::Accept,5},
		{3,'\0',Indicator::Accept,5},
	};
static const Table<wchar_t> table_number_beautifull_16L {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},
		{2,'0',Indicator::None,2},
		{2,'1',Indicator::None,2},
		{2,'2',Indicator::None,2},
		{2,'3',Indicator::None,2},
		{2,'4',Indicator::None,2},
		{2,'5',Indicator::None,2},
		{2,'6',Indicator::None,2},
		{2,'7',Indicator::None,2},
		{2,'8',Indicator::None,2},
		{2,'9',Indicator::None,2},		
		{2,'a',Indicator::None,2},
		{2,'b',Indicator::None,2},
		{2,'c',Indicator::None,2},
		{2,'d',Indicator::None,2},
		{2,'e',Indicator::None,2},
		{2,'f',Indicator::None,2},
		
		{2,' ',Indicator::Accept,5},
		{2,'\n',Indicator::Accept,5},
		{2,'\t',Indicator::Accept,5},
		{2,'\0',Indicator::Accept,5},
		
		{1,'X',Indicator::None,3},
		{3,'0',Indicator::None,3},
		{3,'1',Indicator::None,3},
		{3,'2',Indicator::None,3},
		{3,'3',Indicator::None,3},
		{3,'4',Indicator::None,3},
		{3,'5',Indicator::None,3},
		{3,'6',Indicator::None,3},
		{3,'7',Indicator::None,3},
		{3,'8',Indicator::None,3},
		{3,'9',Indicator::None,3},
		{3,'A',Indicator::None,3},
		{3,'B',Indicator::None,3},
		{3,'C',Indicator::None,3},
		{3,'D',Indicator::None,3},
		{3,'E',Indicator::None,3},
		{3,'F',Indicator::None,3},
		
		{3,' ',Indicator::Accept,5},
		{3,'\n',Indicator::Accept,5},
		{3,'\t',Indicator::Accept,5},
		{3,'\0',Indicator::Accept,5},
	};

static const unsigned char OP_MAX_ZISE = 12;//es el numero de estado mas lejano
//intel-80-210201-001.pdf
static const Table<char> i86 {
		//
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'a',Indicator::None,3},
		
		{0,'A',Indicator::None,4},
		{4,'A',Indicator::None,5},
		{5,'A',Indicator::None,6},


		//
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'d',Indicator::None,3},

		{0,'A',Indicator::None,4},
		{4,'A',Indicator::None,5},
		{5,'D',Indicator::None,6},


		//
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'m',Indicator::None,3},

		{0,'A',Indicator::None,4},
		{4,'A',Indicator::None,5},
		{5,'M',Indicator::None,6},


		//
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'s',Indicator::None,3},

		{0,'A',Indicator::None,4},
		{4,'A',Indicator::None,5},
		{5,'S',Indicator::None,6},


		//
		{0,'a',Indicator::None,1},
		{1,'d',Indicator::None,2},
		{2,'c',Indicator::None,3},

		{0,'A',Indicator::None,4},
		{4,'D',Indicator::None,5},
		{5,'C',Indicator::None,6},


		//
		{0,'a',Indicator::None,1},
		{1,'d',Indicator::None,2},
		{2,'d',Indicator::None,3},

		{0,'A',Indicator::None,4},
		{4,'D',Indicator::None,5},
		{5,'D',Indicator::None,6},


		//acepting
		{3,' ',Indicator::Accept,OP_MAX_ZISE},
		{3,'\n',Indicator::Accept,OP_MAX_ZISE},
		{3,'\t',Indicator::Accept,OP_MAX_ZISE},
		{3,'\0',Indicator::Accept,OP_MAX_ZISE},

		{6,' ',Indicator::Accept,OP_MAX_ZISE},
		{6,'\n',Indicator::Accept,OP_MAX_ZISE},
		{6,'\t',Indicator::Accept,OP_MAX_ZISE},
		{6,'\0',Indicator::Accept,OP_MAX_ZISE},
};


}

#endif