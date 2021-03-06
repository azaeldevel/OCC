
#ifndef OCTETOS_CC_EXCEPTION_HH
#define OCTETOS_CC_EXCEPTION_HH

/*
 * Copyright (C) 2022 Azael R. <azael.devel@gmail.com>
 *
 * octetos-cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * octetos-cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if EXPORTING_OCTETOS_CC_DLL
#if _MSC_VER
#define OCTETOS_CC_DECLSPCE_DLL __declspec(dllexport)
#elif __GNUG__

#endif
#elif IMPORTING_OCTETOS_CC_DLL
#if _MSC_VER
#define OCTETOS_CC_DECLSPCE_DLL __declspec(dllimport)
#elif __GNUG__

#endif
#else
	#define OCTETOS_CC_DECLSPCE_DLL
#endif

#if defined(__linux__)
    #include <octetos/core/Exception-v3.hh>
#elif defined(_WIN32) || defined(_WIN64)
    #include <Exception-v3.hh>
#else
	#error "Plataforma desconocida"
#endif

namespace oct::cc
{

class Exception : public core::v3::Exception
{
public:
	enum Errors
	{
		NO_ERROR,
		FILE_TERGET_NOT_FOUND,
		INDEX_OUT_OF_RANGE,
		DESSYNCHRONIZATION_BUFEER_SENTINEL,
		NEGATIVE_STRING,
		NULL_STRING,
		UNCLASIFIED,
		Q0_NOT_ACCEPTABLE,
		NOT_UNIQUE,
	};

public:
	Exception();
	Exception(unsigned int code);
	Exception(unsigned int code,const char* subject);
	Exception(unsigned int code,const char* filename, unsigned int line);
	Exception(unsigned int code,const char* subject,const char* filename, unsigned int line);

	virtual const char* what () const throw ();

private:
};

}

#endif
