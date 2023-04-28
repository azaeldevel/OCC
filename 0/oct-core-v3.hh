
#ifndef OCTETOS_CORE_V3_OCC_HH
#define OCTETOS_CORE_V3_OCC_HH


/*
 * main.cc
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

#include <iostream>
#include <string>
#include <stdio.h>
#include <filesystem>
#include <list>
#include <vector>
#include <variant>
#include <core/3/math.hh>


namespace oct::core::v3
{
    class Block
    {
    public:
        Block() : page_size(1024),actual(NULL)
        {
            actual = malloc(page_size);
            blocks.push_back(actual);
        }
        Block(size_t size) : page_size(size),actual(NULL)
        {
            actual = malloc(page_size);
            blocks.push_back(actual);
        }
        ~Block()
        {
            for(void* m : blocks)
            {
                free(m);
            }
        }

        template<typename T> T* create()
        {
            //std::cout << "Block::create begin\n";
            if((long)actual >= (long)page_size)
            {
                //std::cout << "Block::create malloc\n";
                actual = malloc(page_size);
                blocks.push_back(actual);
            }
            void* now = actual;
            char* newptr = reinterpret_cast<char*>(actual);
            //std::cout << "Block::create actual : " << (long)actual << "\n";
            newptr += sizeof(T) + 1;
            //std::cout << "Block::create newptr : " << (long)newptr << "\n";
            //std::cout << "Block::create sizeof(T) : " << sizeof(T) << "\n";
            actual = (void*)newptr;
            //std::cout << "Block::create end\n";
            return new(now) T;
        }
    protected:
        size_t page_size;
        void* actual;//last block memory assignable
        //size_t index;//firs posistion usable in actual block memory
        std::list<void*> blocks;
        std::list<void*>::iterator it;

    private:


    };

}

#endif
