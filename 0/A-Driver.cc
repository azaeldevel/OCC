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

#include "A-Driver.hh"
//#include <A/oas-intel-parser.hh>

namespace oct::cc::v0::AI
{
    Driver::Driver() : symbols(new SymbolTable),symbols_new(true)
    {
    }
    Driver::Driver(core_here::Block& b) : cc_here::Driver(b),symbols(new SymbolTable),symbols_new(true)
    {
    }
    Driver::Driver(core_here::Block& b,SymbolTable& s) : cc_here::Driver(b),symbols(&s),symbols_new(false)
    {
    }
    Driver::Driver(SymbolTable& s) : symbols(&s),symbols_new(false)
    {
    }
    Driver::~Driver()
    {
        if(symbols_new) if(symbols)
        {
            delete symbols;
            symbols = NULL;
        }
    }







    void Driver::print(std::ostream& out) const
    {
        if(unit) unit->print(out);
    }
    void Driver::generate(std::ostream& out) const
    {
        if(unit) unit->generate(out);
    }
}
