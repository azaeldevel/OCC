


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

#include <AI/occ-intel.parser.hh>
#include <AI/occ-intel.lexer.hh>

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
    Buffer::Buffer(const Buffer& b) : buffer(b.buffer),scanner(b.scanner),file(b.file)
    {
    }
    Buffer::Buffer(Buffer&& b) : buffer(b.buffer),scanner(b.scanner),file(b.file)
    {
        b.buffer = NULL;
        b.scanner = NULL;
        b.file = NULL;
    }
    Buffer::~Buffer()
    {

    }
    void Buffer::active(Buffer& b)
    {
        yy_switch_to_buffer((YY_BUFFER_STATE)b.buffer,(yyscan_t)b.scanner);
    }


    Buffer::operator void*()
    {
        return scanner;
    }
    Buffer&  Buffer::operator =(Buffer&& b)
    {
       close();

        buffer = b.buffer;
        scanner = b.scanner;
        file = b.file;
        b.buffer = NULL;
        b.scanner = NULL;
        b.file = NULL;

        return *this;
    }
    void Buffer::close()
    {
        if(buffer) yy_delete_buffer ((YY_BUFFER_STATE)buffer, scanner);
        if(scanner) yylex_destroy (scanner);
        if(file) fclose(file);
    }

    void Buffer::clean()
    {
        if(buffer)
        {
            yy_delete_buffer ((YY_BUFFER_STATE)buffer, scanner);
            buffer = NULL;
        }
        if(scanner)
        {
            yylex_destroy (scanner);
            scanner = NULL;
        }
        if(file)
        {
            fclose(file);
            file = NULL;
        }

    }
}
