
#ifndef OCTETOS_CC_V0_CC_HH
#define OCTETOS_CC_V0_CC_HH

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

#include "oct-core-v3.hh"

namespace oct::cc::v0
{
    namespace core_here = oct::core::v3;
	enum class Language
	{
	    none,
	    AI,
	    AII,
	    AIII,
	    C,
	    CPP,
	};

	class Driver
    {
    public:
        Driver ();
        Driver (core_here::Block& memory);
        virtual ~Driver ();

        virtual bool parse(const std::filesystem::path& source) = 0;
        virtual bool parse(const std::list<std::filesystem::path>& sources);
        virtual void generate(std::ostream&)const = 0;

        //location loc;

    protected:
        core_here::Block* block;
        bool block_new;
    };
}

#endif
