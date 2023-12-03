
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

namespace oct::cc::v1
{

    class Buffer
    {
    private:
        void* buffer;
        void* scanner;
        FILE* file;
        std::filesystem::path filename;

    private:
        inline void close();
        inline void clean();

    public:
        Buffer();
        Buffer(const Buffer&);
        Buffer(Buffer&&);
        Buffer(const std::filesystem::path&);
        ~Buffer();

        operator void*();
        Buffer& operator =(Buffer&&);

        static void active(Buffer&);
    };

}


#endif
