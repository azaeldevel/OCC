/* Driver for calc++.   -*- C++ -*-

   Copyright (C) 2005-2015, 2018-2021 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <stdio.h>
#include <stdlib.h>

#include "driver.hh"
#include <oas-intel-parser-A+.hh>
#include <oas-intel-A+.tab.h>



Scanner::Scanner(std::istream *in) : yyFlexLexer(in)
{
    loc = new yy::location_type();
};




Driver::Driver () : trace_parsing (false), trace_scanning (false)
{
}


int Driver::parse(const std::list<std::filesystem::path>& sources)
{
}

void Driver::scan_begin ()
{

}

void Driver::scan_end ()
{

}
