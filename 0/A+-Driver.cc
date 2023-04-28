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

#include "A+-Driver.hh"
//#include <A+/oas-intel-parser.hh>

namespace oct::cc::v0::AII
{

    Driver::Driver(AI_here::Tray<nodes::external_declaration>& t) : tray(&t)
    {
    }
    Driver::~Driver()
    {
    }



    void Driver::print(std::ostream& out) const
    {
        const nodes::external_declaration* ext = tray->unit;
        while(ext)
        {
            ext->print(out);
            if(ext->next) out << "\n";

            ext = (nodes::external_declaration*)ext->next;
        }
    }
    void Driver::generate(std::ostream& out) const
    {
        const nodes::external_declaration* ext = tray->unit;
        while(ext)
        {
            ext->generate(out);

            ext = (nodes::external_declaration*)ext->next;
        }

    }
}
