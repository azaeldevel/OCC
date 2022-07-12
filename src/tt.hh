

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


//intel-80-210201-001.pdf
static const Table<char> i86l {//instruction set, lowwer case
		//aaa
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'a',Indicator::None,3},
		//accept
		{3,' ',Indicator::Accept,4},
		{3,'\n',Indicator::Accept,4},
		{3,'\t',Indicator::Accept,4},
		{3,'\0',Indicator::Accept,4},

		//aad
		{2,'d',Indicator::None,5},
		//accept
		{5,' ',Indicator::Accept,6},
		{5,'\n',Indicator::Accept,6},
		{5,'\t',Indicator::Accept,6},
		{5,'\0',Indicator::Accept,6},

		//aam
		{2,'m',Indicator::None,7},
		//accept
		{7,' ',Indicator::Accept,8},
		{7,'\n',Indicator::Accept,8},
		{7,'\t',Indicator::Accept,8},
		{7,'\0',Indicator::Accept,8},

		//aas
		{2,'s',Indicator::None,9},
		//accept
		{9,' ',Indicator::Accept,10},
		{9,'\n',Indicator::Accept,10},
		{9,'\t',Indicator::Accept,10},
		{9,'\0',Indicator::Accept,10},

		//adc		
		{1,'d',Indicator::None,11},
		{11,'c',Indicator::None,12},
		//accept
		{12,' ',Indicator::Accept,13},
		{12,'\n',Indicator::Accept,13},
		{12,'\t',Indicator::Accept,13},
		{12,'\0',Indicator::Accept,13},

		//add
		{11,'d',Indicator::None,14},
		//accept
		{14,' ',Indicator::Accept,15},
		{14,'\n',Indicator::Accept,15},
		{14,'\t',Indicator::Accept,15},
		{14,'\0',Indicator::Accept,15},

		//and
		{1,'n',Indicator::None,16},
		{16,'d',Indicator::None,17},
		//accept
		{17,' ',Indicator::Accept,18},
		{17,'\n',Indicator::Accept,18},
		{17,'\t',Indicator::Accept,18},
		{17,'\0',Indicator::Accept,18},

		//call
		{0,'c',Indicator::None,19},
		{19,'a',Indicator::None,20},
		{20,'l',Indicator::None,21},
		{21,'l',Indicator::None,22},
		//accept
		{22,' ',Indicator::Accept,23},
		{22,'\n',Indicator::Accept,23},
		{22,'\t',Indicator::Accept,23},
		{22,'\0',Indicator::Accept,23},

		//cbw
		{19,'b',Indicator::None,24},
		{24,'w',Indicator::None,25},
		//accept
		{25,' ',Indicator::Accept,26},
		{25,'\n',Indicator::Accept,26},
		{25,'\t',Indicator::Accept,26},
		{25,'\0',Indicator::Accept,26},

		//clc
		{19,'l',Indicator::None,27},
		{27,'c',Indicator::None,28},
		//accept
		{28,' ',Indicator::Accept,29},
		{28,'\n',Indicator::Accept,29},
		{28,'\t',Indicator::Accept,29},
		{28,'\0',Indicator::Accept,29},

		//cld
		{27,'d',Indicator::None,30},
		//accept
		{30,' ',Indicator::Accept,31},
		{30,'\n',Indicator::Accept,31},
		{30,'\t',Indicator::Accept,31},
		{30,'\0',Indicator::Accept,31},

		//cli
		{27,'i',Indicator::None,32},
		//accept
		{32,' ',Indicator::Accept,33},
		{32,'\n',Indicator::Accept,33},
		{32,'\t',Indicator::Accept,33},
		{32,'\0',Indicator::Accept,33},

		//cmc
		{19,'m',Indicator::None,34},
		{34,'c',Indicator::None,35},
		//accept
		{35,' ',Indicator::Accept,36},
		{35,'\n',Indicator::Accept,36},
		{35,'\t',Indicator::Accept,36},
		{35,'\0',Indicator::Accept,36},

		//cmp
		{34,'p',Indicator::None,37},
		//accept
		{37,' ',Indicator::Accept,38},
		{37,'\n',Indicator::Accept,38},
		{37,'\t',Indicator::Accept,38},
		{37,'\0',Indicator::Accept,38},

		//cmps
		{37,'s',Indicator::None,39},
		//accept
		{39,' ',Indicator::Accept,40},
		{39,'\n',Indicator::Accept,40},
		{39,'\t',Indicator::Accept,40},
		{39,'\0',Indicator::Accept,40},

		//cwd
		{19,'w',Indicator::None,41},
		{41,'d',Indicator::None,42},
		//accept
		{42,' ',Indicator::Accept,43},
		{42,'\n',Indicator::Accept,43},
		{42,'\t',Indicator::Accept,43},
		{42,'\0',Indicator::Accept,43},

		//daa
		{0,'d',Indicator::None,44},
		{44,'a',Indicator::None,45},
		{45,'a',Indicator::None,46},
		//accept
		{46,' ',Indicator::Accept,47},
		{46,'\n',Indicator::Accept,47},
		{46,'\t',Indicator::Accept,47},
		{46,'\0',Indicator::Accept,47},

		//das
		{45,'s',Indicator::None,48},
		//accept
		{48,' ',Indicator::Accept,49},
		{48,'\n',Indicator::Accept,49},
		{48,'\t',Indicator::Accept,49},
		{48,'\0',Indicator::Accept,49},

		//dec
		{44,'e',Indicator::None,50},
		{50,'c',Indicator::None,51},
		//accept
		{51,' ',Indicator::Accept,52},
		{51,'\n',Indicator::Accept,52},
		{51,'\t',Indicator::Accept,52},
		{51,'\0',Indicator::Accept,52},

		//div
		{44,'i',Indicator::None,53},
		{53,'v',Indicator::None,54},
		//accept
		{54,' ',Indicator::Accept,55},
		{54,'\n',Indicator::Accept,55},
		{54,'\t',Indicator::Accept,55},
		{54,'\0',Indicator::Accept,55},

		//esc
		{0,'e',Indicator::None,56},
		{56,'s',Indicator::None,57},
		{57,'c',Indicator::None,58},
		//accept
		{58,' ',Indicator::Accept,59},
		{58,'\n',Indicator::Accept,59},
		{58,'\t',Indicator::Accept,59},
		{58,'\0',Indicator::Accept,59},

		//hlt
		{0,'h',Indicator::None,60},
		{60,'l',Indicator::None,61},
		{61,'t',Indicator::None,62},
		//accept
		{62,' ',Indicator::Accept,63},
		{62,'\n',Indicator::Accept,63},
		{62,'\t',Indicator::Accept,63},
		{62,'\0',Indicator::Accept,63},

		//idiv
		{0,'i',Indicator::None,64},
		{64,'d',Indicator::None,65},
		{65,'i',Indicator::None,66},
		{66,'v',Indicator::None,67},
		//accept
		{67,' ',Indicator::Accept,68},
		{67,'\n',Indicator::Accept,68},
		{67,'\t',Indicator::Accept,68},
		{67,'\0',Indicator::Accept,68},		

		//imul
		{64,'m',Indicator::None,69},
		{69,'u',Indicator::None,70},
		{70,'l',Indicator::None,71},
		//accept
		{71,' ',Indicator::Accept,72},
		{71,'\n',Indicator::Accept,72},
		{71,'\t',Indicator::Accept,72},
		{71,'\0',Indicator::Accept,72},
};


}

#endif