


/*
 * main.cc
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compiler Collection is free software: you can redistribute it and/or modify it
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

#include "Buffer.hh"

namespace oct::cc::v1
{

    Buffer::Buffer() : buffer(NULL),file(NULL)
    {
        yylex_init (&scanner);
    }
    Buffer::Buffer(const std::filesystem::path& f) : filename(f)
    {
        yylex_init(&scanner);
        file = fopen(filename.string().c_str(), "r");
        buffer = yy_create_buffer(file, YY_BUF_SIZE, scanner);
    }
    Buffer::~Buffer()
    {

    }
    void Buffer::switch_buffer(Buffer& b)
    {
        yy_switch_to_buffer((YY_BUFFER_STATE)b.buffer,(yyscan_t)b.scanner);
    }
}
