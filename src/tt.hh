

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
		{0,'a',Indicator::Accept,1},
		{0,'b',Indicator::Accept,1},
		{0,'c',Indicator::Accept,1},
		{0,'d',Indicator::Accept,1},
		{0,'e',Indicator::Accept,1},
		{0,'f',Indicator::Accept,1},
		{0,'g',Indicator::Accept,1},
		{0,'h',Indicator::Accept,1},
		{0,'i',Indicator::Accept,1},
		{0,'j',Indicator::Accept,1},
		{0,'k',Indicator::Accept,1},
		{0,'l',Indicator::Accept,1},
		{0,'m',Indicator::Accept,1},
		{0,'n',Indicator::Accept,1},
		{0,'o',Indicator::Accept,1},
		{0,'p',Indicator::Accept,1},
		{0,'q',Indicator::Accept,1},
		{0,'r',Indicator::Accept,1},
		{0,'s',Indicator::Accept,1},
		{0,'t',Indicator::Accept,1},
		{0,'u',Indicator::Accept,1},
		{0,'v',Indicator::Accept,1},
		{0,'w',Indicator::Accept,1},
		{0,'x',Indicator::Accept,1},
		{0,'y',Indicator::Accept,1},
		{0,'z',Indicator::Accept,1},

		{0,'A',Indicator::Accept,1},
		{0,'B',Indicator::Accept,1},
		{0,'C',Indicator::Accept,1},
		{0,'D',Indicator::Accept,1},
		{0,'E',Indicator::Accept,1},
		{0,'F',Indicator::Accept,1},
		{0,'G',Indicator::Accept,1},
		{0,'H',Indicator::Accept,1},
		{0,'I',Indicator::Accept,1},
		{0,'J',Indicator::Accept,1},
		{0,'K',Indicator::Accept,1},
		{0,'L',Indicator::Accept,1},
		{0,'M',Indicator::Accept,1},
		{0,'N',Indicator::Accept,1},
		{0,'O',Indicator::Accept,1},
		{0,'P',Indicator::Accept,1},
		{0,'Q',Indicator::Accept,1},
		{0,'R',Indicator::Accept,1},
		{0,'S',Indicator::Accept,1},
		{0,'T',Indicator::Accept,1},
		{0,'U',Indicator::Accept,1},
		{0,'V',Indicator::Accept,1},
		{0,'W',Indicator::Accept,1},
		{0,'X',Indicator::Accept,1},
		{0,'Y',Indicator::Accept,1},
		{0,'Z',Indicator::Accept,1},

		{0,'_',Indicator::Accept,1},

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

		{1,'a',Indicator::Accept,1},
		{1,'b',Indicator::Accept,1},
		{1,'c',Indicator::Accept,1},
		{1,'d',Indicator::Accept,1},
		{1,'e',Indicator::Accept,1},
		{1,'f',Indicator::Accept,1},
		{1,'g',Indicator::Accept,1},
		{1,'h',Indicator::Accept,1},
		{1,'i',Indicator::Accept,1},
		{1,'j',Indicator::Accept,1},
		{1,'k',Indicator::Accept,1},
		{1,'l',Indicator::Accept,1},
		{1,'m',Indicator::Accept,1},
		{1,'n',Indicator::Accept,1},
		{1,'o',Indicator::Accept,1},
		{1,'p',Indicator::Accept,1},
		{1,'q',Indicator::Accept,1},
		{1,'r',Indicator::Accept,1},
		{1,'s',Indicator::Accept,1},
		{1,'t',Indicator::Accept,1},
		{1,'u',Indicator::Accept,1},
		{1,'v',Indicator::Accept,1},
		{1,'w',Indicator::Accept,1},
		{1,'x',Indicator::Accept,1},
		{1,'y',Indicator::Accept,1},
		{1,'z',Indicator::Accept,1},

		{1,'A',Indicator::Accept,1},
		{1,'B',Indicator::Accept,1},
		{1,'C',Indicator::Accept,1},
		{1,'D',Indicator::Accept,1},
		{1,'E',Indicator::Accept,1},
		{1,'F',Indicator::Accept,1},
		{1,'G',Indicator::Accept,1},
		{1,'H',Indicator::Accept,1},
		{1,'I',Indicator::Accept,1},
		{1,'J',Indicator::Accept,1},
		{1,'K',Indicator::Accept,1},
		{1,'L',Indicator::Accept,1},
		{1,'M',Indicator::Accept,1},
		{1,'N',Indicator::Accept,1},
		{1,'O',Indicator::Accept,1},
		{1,'P',Indicator::Accept,1},
		{1,'Q',Indicator::Accept,1},
		{1,'R',Indicator::Accept,1},
		{1,'S',Indicator::Accept,1},
		{1,'T',Indicator::Accept,1},
		{1,'U',Indicator::Accept,1},
		{1,'V',Indicator::Accept,1},
		{1,'W',Indicator::Accept,1},
		{1,'X',Indicator::Accept,1},
		{1,'Y',Indicator::Accept,1},
		{1,'Z',Indicator::Accept,1},

		{1,'_',Indicator::Accept,1},

	};

static const Table<char> table_number_10 {
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
	};
static const Table<wchar_t> table_number_10L {
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
	};

static const Table<char> table_number_16 {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},

		{2,'0',Indicator::Accept,2},
		{2,'1',Indicator::Accept,2},
		{2,'2',Indicator::Accept,2},
		{2,'3',Indicator::Accept,2},
		{2,'4',Indicator::Accept,2},
		{2,'5',Indicator::Accept,2},
		{2,'6',Indicator::Accept,2},
		{2,'7',Indicator::Accept,2},
		{2,'8',Indicator::Accept,2},
		{2,'9',Indicator::Accept,2},
		
		{2,'a',Indicator::Accept,2},
		{2,'b',Indicator::Accept,2},
		{2,'c',Indicator::Accept,2},
		{2,'d',Indicator::Accept,2},
		{2,'e',Indicator::Accept,2},
		{2,'f',Indicator::Accept,2},
		{2,'A',Indicator::Accept,2},
		{2,'B',Indicator::Accept,2},
		{2,'C',Indicator::Accept,2},
		{2,'D',Indicator::Accept,2},
		{2,'E',Indicator::Accept,2},
		{2,'F',Indicator::Accept,2},
	};
static const Table<wchar_t> table_number_16L {
		{0,'0',Indicator::None,1},

		{1,'x',Indicator::None,2},
		{1,'X',Indicator::None,2},

		{2,'0',Indicator::Accept,2},
		{2,'1',Indicator::Accept,2},
		{2,'2',Indicator::Accept,2},
		{2,'3',Indicator::Accept,2},
		{2,'4',Indicator::Accept,2},
		{2,'5',Indicator::Accept,2},
		{2,'6',Indicator::Accept,2},
		{2,'7',Indicator::Accept,2},
		{2,'8',Indicator::Accept,2},
		{2,'9',Indicator::Accept,2},
		
		{2,'a',Indicator::Accept,2},
		{2,'b',Indicator::Accept,2},
		{2,'c',Indicator::Accept,2},
		{2,'d',Indicator::Accept,2},
		{2,'e',Indicator::Accept,2},
		{2,'f',Indicator::Accept,2},
		{2,'A',Indicator::Accept,2},
		{2,'B',Indicator::Accept,2},
		{2,'C',Indicator::Accept,2},
		{2,'D',Indicator::Accept,2},
		{2,'E',Indicator::Accept,2},
		{2,'F',Indicator::Accept,2},
	};
static const Table<char> table_number_beautifull_16 {
		{0,'0',Indicator::None,1},
		{1,'x',Indicator::None,2},

		{2,'0',Indicator::Accept,2},
		{2,'1',Indicator::Accept,2},
		{2,'2',Indicator::Accept,2},
		{2,'3',Indicator::Accept,2},
		{2,'4',Indicator::Accept,2},
		{2,'5',Indicator::Accept,2},
		{2,'6',Indicator::Accept,2},
		{2,'7',Indicator::Accept,2},
		{2,'8',Indicator::Accept,2},
		{2,'9',Indicator::Accept,2},		
		{2,'a',Indicator::Accept,2},
		{2,'b',Indicator::Accept,2},
		{2,'c',Indicator::Accept,2},
		{2,'d',Indicator::Accept,2},
		{2,'e',Indicator::Accept,2},
		{2,'f',Indicator::Accept,2},
		
		{1,'X',Indicator::None,3},

		{3,'0',Indicator::Accept,3},
		{3,'1',Indicator::Accept,3},
		{3,'2',Indicator::Accept,3},
		{3,'3',Indicator::Accept,3},
		{3,'4',Indicator::Accept,3},
		{3,'5',Indicator::Accept,3},
		{3,'6',Indicator::Accept,3},
		{3,'7',Indicator::Accept,3},
		{3,'8',Indicator::Accept,3},
		{3,'9',Indicator::Accept,3},
		{3,'A',Indicator::Accept,3},
		{3,'B',Indicator::Accept,3},
		{3,'C',Indicator::Accept,3},
		{3,'D',Indicator::Accept,3},
		{3,'E',Indicator::Accept,3},
		{3,'F',Indicator::Accept,3},
	};
static const Table<wchar_t> table_number_beautifull_16L {
		{0,'0',Indicator::None,1},
		{1,'x',Indicator::None,2},

		{2,'0',Indicator::Accept,2},
		{2,'1',Indicator::Accept,2},
		{2,'2',Indicator::Accept,2},
		{2,'3',Indicator::Accept,2},
		{2,'4',Indicator::Accept,2},
		{2,'5',Indicator::Accept,2},
		{2,'6',Indicator::Accept,2},
		{2,'7',Indicator::Accept,2},
		{2,'8',Indicator::Accept,2},
		{2,'9',Indicator::Accept,2},		
		{2,'a',Indicator::Accept,2},
		{2,'b',Indicator::Accept,2},
		{2,'c',Indicator::Accept,2},
		{2,'d',Indicator::Accept,2},
		{2,'e',Indicator::Accept,2},
		{2,'f',Indicator::Accept,2},
		
		{1,'X',Indicator::None,3},

		{3,'0',Indicator::Accept,3},
		{3,'1',Indicator::Accept,3},
		{3,'2',Indicator::Accept,3},
		{3,'3',Indicator::Accept,3},
		{3,'4',Indicator::Accept,3},
		{3,'5',Indicator::Accept,3},
		{3,'6',Indicator::Accept,3},
		{3,'7',Indicator::Accept,3},
		{3,'8',Indicator::Accept,3},
		{3,'9',Indicator::Accept,3},
		{3,'A',Indicator::Accept,3},
		{3,'B',Indicator::Accept,3},
		{3,'C',Indicator::Accept,3},
		{3,'D',Indicator::Accept,3},
		{3,'E',Indicator::Accept,3},
		{3,'F',Indicator::Accept,3},
	};


//intel-80-210201-001.pdf
static const Table<char> i86_instset_l {//instruction set, lowwer case
		//aaa
		{0,'a',Indicator::None,1},
		{1,'a',Indicator::None,2},
		{2,'a',Indicator::Accept,3},

		//aad
		{2,'d',Indicator::Accept,5},

		//aam
		{2,'m',Indicator::Accept,7},

		//aas
		{2,'s',Indicator::Accept,9},

		//adc		
		{1,'d',Indicator::None,11},
		{11,'c',Indicator::Accept,12},

		//add
		{11,'d',Indicator::Accept,14},
		
		//and
		{1,'n',Indicator::None,16},
		{16,'d',Indicator::Accept,17},

		//call
		{0,'c',Indicator::None,19},
		{19,'a',Indicator::None,20},
		{20,'l',Indicator::None,21},
		{21,'l',Indicator::Accept,22},

		//cbw
		{19,'b',Indicator::None,24},
		{24,'w',Indicator::Accept,25},

		//clc
		{19,'l',Indicator::None,27},
		{27,'c',Indicator::Accept,28},

		//cld
		{27,'d',Indicator::Accept,30},

		//cli
		{27,'i',Indicator::Accept,32},

		//cmc
		{19,'m',Indicator::None,34},
		{34,'c',Indicator::Accept,35},

		//cmp
		{34,'p',Indicator::Accept,37},

		//cmps
		{37,'s',Indicator::Accept,39},

		//cwd
		{19,'w',Indicator::None,41},
		{41,'d',Indicator::Accept,42},

		//daa
		{0,'d',Indicator::None,44},
		{44,'a',Indicator::None,45},
		{45,'a',Indicator::Accept,46},

		//das
		{45,'s',Indicator::Accept,48},

		//dec
		{44,'e',Indicator::None,50},
		{50,'c',Indicator::Accept,51},

		//div
		{44,'i',Indicator::None,53},
		{53,'v',Indicator::Accept,54},

		//esc
		{0,'e',Indicator::None,56},
		{56,'s',Indicator::None,57},
		{57,'c',Indicator::Accept,58},

		//hlt
		{0,'h',Indicator::None,60},
		{60,'l',Indicator::None,61},
		{61,'t',Indicator::Accept,62},

		//idiv
		{0,'i',Indicator::None,64},
		{64,'d',Indicator::None,65},
		{65,'i',Indicator::None,66},
		{66,'v',Indicator::Accept,67},

		//imul
		{64,'m',Indicator::None,69},
		{69,'u',Indicator::None,70},
		{70,'l',Indicator::Accept,71},

		//in
		{64,'n',Indicator::Accept,73},

		//inc
		{73,'c',Indicator::Accept,74},
		
		//int
		{73,'t',Indicator::Accept,76},

		//intr
		{76,'r',Indicator::Accept,78},

		//into
		{76,'o',Indicator::Accept,80},

		//iret
		{64,'r',Indicator::None,82},
		{82,'e',Indicator::None,83},
		{83,'t',Indicator::Accept,84},
};

static const Table<char> i86_regs_l {//instruction set, lowwer case
		//ah
		{0,'a',Indicator::None,1},
		{1,'h',Indicator::Accept,2},
		
		//al
		{1,'l',Indicator::Accept,4},
		
		//ax
		{1,'x',Indicator::Accept,6},

		//bh
		{0,'b',Indicator::None,8},
		{8,'h',Indicator::Accept,9},

		//bl
		{8,'l',Indicator::Accept,11},

		//bx
		{8,'x',Indicator::Accept,13},

		//ch
		{0,'c',Indicator::None,15},
		{15,'h',Indicator::Accept,16},

		//cl
		{15,'l',Indicator::Accept,18},

		//cx
		{15,'x',Indicator::Accept,20},

		//ch
		{0,'d',Indicator::None,22},
		{22,'h',Indicator::Accept,23},

		//cl
		{22,'l',Indicator::Accept,25},

		//cx
		{22,'x',Indicator::Accept,27},

};

static const Table<char> i86_segs_l {//instruction set, lowwer case
		//bp
		{0,'b',Indicator::None,1},
		{1,'p',Indicator::Accept,2},

		//cs
		{0,'c',Indicator::None,4},
		{4,'s',Indicator::Accept,5},

		//di
		{0,'d',Indicator::None,7},
		{7,'i',Indicator::Accept,8},
		
		//ds
		{7,'s',Indicator::Accept,10},

		//es
		{0,'e',Indicator::None,12},
		{12,'s',Indicator::Accept,13},
		
		//ip
		{0,'i',Indicator::None,15},
		{15,'p',Indicator::Accept,16},
		
		//si
		{0,'s',Indicator::None,18},
		{18,'i',Indicator::Accept,19},
		
		//sp
		{18,'p',Indicator::Accept,21},
		
		//ss
		{18,'s',Indicator::Accept,23},
};

}

#endif