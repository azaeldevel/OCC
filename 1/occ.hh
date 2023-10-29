
#ifndef OCTETOS_OCC_V1_CC_HH
#define OCTETOS_OCC_V1_CC_HH

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

#include <filesystem>
#include <list>


#include <core/3/tree.hh>


namespace oct::cc::v1
{
    namespace core_here = oct::core::v3;
    namespace core = oct::core::v3;

	enum class Language
	{
	    none,
	    AI,
	    AII,
	    AIII,
	    C,
	    CPP,
	};
	enum class CPU
	{
	    none,
	    intel_8088,
	    intel_8086,
        arduino,
	};
	enum class Environment
	{
	    none,
	    freestanding,
	    freestanding_boot,
	    hosted
	};
	enum class OutputType
	{
        none,
        runnable,
        static_library,
        dinamic_library,
	};

	class Driver
    {
    public:
        Driver () = default;
        virtual ~Driver();

        virtual bool parse(const std::filesystem::path& source) = 0;
        virtual bool parse(const std::list<std::filesystem::path>& sources);
        virtual void generate(std::ostream&) const = 0;

    protected:

    };


}

#endif
