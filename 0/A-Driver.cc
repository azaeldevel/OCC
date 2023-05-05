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

#include "A-Driver.hh"
//#include <A/oas-intel-parser.hh>

namespace oct::cc::v0::AI
{
    Driver::Driver(Tray<nodes::translation_unit>& t) : tray(&t)
    {
    }
    Driver::~Driver()
    {
    }







    void Driver::print(std::ostream& out) const
    {
        if(tray->unit) tray->unit->print(out);
    }
    void Driver::print(std::ostream& out,const nodes::translation_unit* tree) const
    {
        //std::cout << "Imprimiendo apartir de arbol semantico\n";
        tree->print(out);
    }
    void Driver::generate(std::ostream& out) const
    {
        if(tray->unit) tray->unit->generate(out);
    }
    void Driver::generate(std::ostream& out,const nodes::translation_unit* tree)const
    {
        //std::cout << "Generando apartir de arbol semantico\n";
        if(tree) tree->generate(out);
    }
    bool Driver::semantic() const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        const nodes::declaration* dec = tray->unit->declarations;
        while(dec)
        {
            //std::cout << "Step 1.1\n";
            if(dec->semantic())
            {

            }
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";
            dec = (const nodes::declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 2\n";
        const nodes::function* func = tray->unit->functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            if(func->semantic())
            {

            }
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";
            func = (const nodes::function*)func->next;
            //std::cout << "Step 1.4\n";
        }

        return true;
    }

}
