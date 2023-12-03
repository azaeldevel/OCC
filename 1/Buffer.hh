
#ifndef OCTETOS_CC_V1_BUFFER_HH
#define OCTETOS_CC_V1_BUFFER_HH

/*
 *
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
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
 //#undef YY_DECL

#include <stdio.h>
#include <filesystem>
#include <AI/oas-intel-parser.hh>
#include <AI/oas-intel.lexer.hh>

namespace oct::cc::v1
{

    class Buffer
    {
    private:
        YY_BUFFER_STATE buffer;
        yyscan_t scanner;
        FILE* file;
        std::filesystem::path filename;

    public:
        Buffer();
        Buffer(const std::filesystem::path&);
        ~Buffer();

        static void switch_buffer(Buffer&);
    };

}


#endif
