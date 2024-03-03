/*

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <AI/occ-intel.parser.hh>

#include "Driver.hh"

namespace oct::cc::v1::A::I
{
    Driver::Driver(Tray& t) : tray(&t)
    {
    }
    Driver::~Driver()
    {
    }







    void Driver::print(std::ostream& out) const
    {
        //std::cout << "Imprimiendo fuente..\n";
        tray->unit->print(out);
    }
    void Driver::print(std::ostream& out,const Unit* tree) const
    {
        //std::cout << "Imprimiendo apartir de arbol semantico\n";
        tree->print(out);
    }
    void Driver::generate(std::ostream& out) const
    {
        //if(tray->unit) tray->unit->generate(out);
    }
    void Driver::generate(std::ostream& out,const Unit* tree)const
    {
        //std::cout << "Generando apartir de arbol semantico\n";
        if(tree) tree->generate(out);
    }
    bool Driver::semantic(std::ostream& out)
    {
        return tray->unit->semantic(out);
    }

    bool occ::A::I::Driver::parse(const std::filesystem::path& path)
    {
        //std::cout << "Parsing fuente..\n";
        buffer = Buffer(path);
        Buffer::active(buffer);
        if(yyparse(buffer,tray) == 0) return true;
        return false;
    }

}
