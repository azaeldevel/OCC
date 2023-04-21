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
#include "A-Scanner.hh"
#include <A/oas-intel-parser.hh>

namespace oct::cc::v0::AI
{
    Driver::Driver() : block(new core_here::Block),block_new(true)
    {
    }
    Driver::Driver(core_here::Block& b) : block(&b),block_new(false)
    {
    }
    Driver::~Driver()
    {
        for(Source& s : sources)
        {
            s.stream->close();
            delete s.stream;
        }
        if(block_new)
        {
            delete block;
            block = NULL;
        }
    }



    bool Driver::parse(const std::filesystem::path& path)
    {
        sources.push_back({&path,NULL});
        Source* source = &sources.back();
        source->path = &path;
        source->stream = new std::ifstream(path);
        //location.initialize(path.string());
        if(not source->stream->good()) return false;
        return parse(source->stream);
    }

    bool Driver::parse(std::ifstream* stream)
    {
        Scanner scanner(stream,*block);
        unit = NULL;
        parser parser(scanner,*this,&unit,*block);
        if(parser.parse() != 0) return false;
        return true;
    }




    void Driver::print(std::ostream& out) const
    {
        if(unit) unit->print(out);
    }
    bool Driver::generate(std::ostream& out) const
    {
        /*const nodes::translation_unit* ext = unit;
        while(ext)
        {
            ext->generate(out);

            ext = (nodes::translation_unit*)ext->next;
        }*/

        return true;
    }
}
