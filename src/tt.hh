

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
static const Table<char> Identifier {
		{0,'a',Indicator::None,1},
		{0,'b',Indicator::None,1},
		{0,'c',Indicator::None,1},
		{0,'d',Indicator::None,1},
		{0,'e',Indicator::None,1},
		{0,'f',Indicator::None,1},
		{0,'g',Indicator::None,1},
		{0,'h',Indicator::None,1},
		{0,'i',Indicator::None,1},
		{0,'j',Indicator::None,1},
		{0,'k',Indicator::None,1},
		{0,'l',Indicator::None,1},
		{0,'m',Indicator::None,1},
		{0,'n',Indicator::None,1},
		{0,'o',Indicator::None,1},
		{0,'p',Indicator::None,1},
		{0,'q',Indicator::None,1},
		{0,'r',Indicator::None,1},
		{0,'s',Indicator::None,1},
		{0,'t',Indicator::None,1},
		{0,'u',Indicator::None,1},
		{0,'v',Indicator::None,1},
		{0,'w',Indicator::None,1},
		{0,'x',Indicator::None,1},
		{0,'y',Indicator::None,1},
		{0,'z',Indicator::None,1},

		{0,'A',Indicator::None,1},
		{0,'B',Indicator::None,1},
		{0,'C',Indicator::None,1},
		{0,'D',Indicator::None,1},
		{0,'E',Indicator::None,1},
		{0,'F',Indicator::None,1},
		{0,'G',Indicator::None,1},
		{0,'H',Indicator::None,1},
		{0,'I',Indicator::None,1},
		{0,'J',Indicator::None,1},
		{0,'K',Indicator::None,1},
		{0,'L',Indicator::None,1},
		{0,'M',Indicator::None,1},
		{0,'N',Indicator::None,1},
		{0,'O',Indicator::None,1},
		{0,'P',Indicator::None,1},
		{0,'Q',Indicator::None,1},
		{0,'R',Indicator::None,1},
		{0,'S',Indicator::None,1},
		{0,'T',Indicator::None,1},
		{0,'U',Indicator::None,1},
		{0,'V',Indicator::None,1},
		{0,'W',Indicator::None,1},
		{0,'X',Indicator::None,1},
		{0,'Y',Indicator::None,1},
		{0,'Z',Indicator::None,1},

		{0,'_',Indicator::None,1},

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

		{1,'a',Indicator::None,1},
		{1,'b',Indicator::None,1},
		{1,'c',Indicator::None,1},
		{1,'d',Indicator::None,1},
		{1,'e',Indicator::None,1},
		{1,'f',Indicator::None,1},
		{1,'g',Indicator::None,1},
		{1,'h',Indicator::None,1},
		{1,'i',Indicator::None,1},
		{1,'j',Indicator::None,1},
		{1,'k',Indicator::None,1},
		{1,'l',Indicator::None,1},
		{1,'m',Indicator::None,1},
		{1,'n',Indicator::None,1},
		{1,'o',Indicator::None,1},
		{1,'p',Indicator::None,1},
		{1,'q',Indicator::None,1},
		{1,'r',Indicator::None,1},
		{1,'s',Indicator::None,1},
		{1,'t',Indicator::None,1},
		{1,'u',Indicator::None,1},
		{1,'v',Indicator::None,1},
		{1,'w',Indicator::None,1},
		{1,'x',Indicator::None,1},
		{1,'y',Indicator::None,1},
		{1,'z',Indicator::None,1},

		{1,'A',Indicator::None,1},
		{1,'B',Indicator::None,1},
		{1,'C',Indicator::None,1},
		{1,'D',Indicator::None,1},
		{1,'E',Indicator::None,1},
		{1,'F',Indicator::None,1},
		{1,'G',Indicator::None,1},
		{1,'H',Indicator::None,1},
		{1,'I',Indicator::None,1},
		{1,'J',Indicator::None,1},
		{1,'K',Indicator::None,1},
		{1,'L',Indicator::None,1},
		{1,'M',Indicator::None,1},
		{1,'N',Indicator::None,1},
		{1,'O',Indicator::None,1},
		{1,'P',Indicator::None,1},
		{1,'Q',Indicator::None,1},
		{1,'R',Indicator::None,1},
		{1,'S',Indicator::None,1},
		{1,'T',Indicator::None,1},
		{1,'U',Indicator::None,1},
		{1,'V',Indicator::None,1},
		{1,'W',Indicator::None,1},
		{1,'X',Indicator::None,1},
		{1,'Y',Indicator::None,1},
		{1,'Z',Indicator::None,1},

		{1,'_',Indicator::None,1},

		{1,' ',Indicator::Accept,2},
		{1,'\n',Indicator::Accept,2},
		{1,'\t',Indicator::Accept,2},
		{1,'\0',Indicator::Accept,2},
	};

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
static const Table<char> i86_instset_l {//instruction set, lowwer case
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

		//in
		{64,'n',Indicator::None,73},
		//accept
		{73,' ',Indicator::Accept,74},
		{73,'\n',Indicator::Accept,74},
		{73,'\t',Indicator::Accept,74},
		{73,'\0',Indicator::Accept,74},

		//inc
		{73,'c',Indicator::None,74},
		//accept
		{74,' ',Indicator::Accept,75},
		{74,'\n',Indicator::Accept,75},
		{74,'\t',Indicator::Accept,75},
		{74,'\0',Indicator::Accept,75},

		//int
		{73,'t',Indicator::None,76},
		//accept
		{76,' ',Indicator::Accept,77},
		{76,'\n',Indicator::Accept,77},
		{76,'\t',Indicator::Accept,77},
		{76,'\0',Indicator::Accept,77},

		//intr
		{76,'r',Indicator::None,78},
		//accept
		{78,' ',Indicator::Accept,79},
		{78,'\n',Indicator::Accept,79},
		{78,'\t',Indicator::Accept,79},
		{78,'\0',Indicator::Accept,79},

		//into
		{76,'o',Indicator::None,80},
		//accept
		{80,' ',Indicator::Accept,81},
		{80,'\n',Indicator::Accept,81},
		{80,'\t',Indicator::Accept,81},
		{80,'\0',Indicator::Accept,81},

		//iret
		{64,'r',Indicator::None,82},
		{82,'e',Indicator::None,83},
		{83,'t',Indicator::None,84},
		//accept
		{84,' ',Indicator::Accept,85},
		{84,'\n',Indicator::Accept,85},
		{84,'\t',Indicator::Accept,85},
		{84,'\0',Indicator::Accept,85},
};

static const Table<char> i86_regs_l {//instruction set, lowwer case
		//ah
		{0,'a',Indicator::None,1},
		{1,'h',Indicator::None,2},
		//accept
		{2,' ',Indicator::Accept,3},
		{2,'\n',Indicator::Accept,3},
		{2,'\t',Indicator::Accept,3},
		{2,'\0',Indicator::Accept,3},
		
		//al
		{1,'l',Indicator::None,4},
		//accept
		{4,' ',Indicator::Accept,5},
		{4,'\n',Indicator::Accept,5},
		{4,'\t',Indicator::Accept,5},
		{4,'\0',Indicator::Accept,5},
		
		//ax
		{1,'x',Indicator::None,6},
		//accept
		{6,' ',Indicator::Accept,7},
		{6,'\n',Indicator::Accept,7},
		{6,'\t',Indicator::Accept,7},
		{6,'\0',Indicator::Accept,7},

		//bh
		{0,'b',Indicator::None,8},
		{8,'h',Indicator::None,9},
		//accept
		{9,' ',Indicator::Accept,10},
		{9,'\n',Indicator::Accept,10},
		{9,'\t',Indicator::Accept,10},
		{9,'\0',Indicator::Accept,10},

		//bl
		{8,'l',Indicator::None,11},
		//accept
		{11,' ',Indicator::Accept,12},
		{11,'\n',Indicator::Accept,12},
		{11,'\t',Indicator::Accept,12},
		{11,'\0',Indicator::Accept,12},

		//bx
		{8,'x',Indicator::None,13},
		//accept
		{13,' ',Indicator::Accept,14},
		{13,'\n',Indicator::Accept,14},
		{13,'\t',Indicator::Accept,14},
		{13,'\0',Indicator::Accept,14},

		//ch
		{0,'c',Indicator::None,15},
		{15,'h',Indicator::None,16},
		//accept
		{16,' ',Indicator::Accept,17},
		{16,'\n',Indicator::Accept,17},
		{16,'\t',Indicator::Accept,17},
		{16,'\0',Indicator::Accept,17},

		//cl
		{15,'l',Indicator::None,18},
		//accept
		{18,' ',Indicator::Accept,19},
		{18,'\n',Indicator::Accept,19},
		{18,'\t',Indicator::Accept,19},
		{18,'\0',Indicator::Accept,19},

		//cx
		{15,'x',Indicator::None,20},
		//accept
		{20,' ',Indicator::Accept,21},
		{20,'\n',Indicator::Accept,21},
		{20,'\t',Indicator::Accept,21},
		{20,'\0',Indicator::Accept,21},

		//ch
		{0,'d',Indicator::None,22},
		{22,'h',Indicator::None,23},
		//accept
		{23,' ',Indicator::Accept,24},
		{23,'\n',Indicator::Accept,24},
		{23,'\t',Indicator::Accept,24},
		{23,'\0',Indicator::Accept,24},

		//cl
		{22,'l',Indicator::None,25},
		//accept
		{25,' ',Indicator::Accept,26},
		{25,'\n',Indicator::Accept,26},
		{25,'\t',Indicator::Accept,26},
		{25,'\0',Indicator::Accept,26},

		//cx
		{22,'x',Indicator::None,27},
		//accept
		{27,' ',Indicator::Accept,28},
		{27,'\n',Indicator::Accept,28},
		{27,'\t',Indicator::Accept,28},
		{27,'\0',Indicator::Accept,28},

};
}

#endif