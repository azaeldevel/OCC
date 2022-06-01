
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
 
#include "Exception.hh"

namespace oct::cc
{
	
Exception::Exception()
{

}
Exception::Exception(unsigned int c) : core::v3::Exception(c)
{
}
Exception::Exception(unsigned int c,const char* s) : core::v3::Exception(c,s)
{
}
Exception::Exception(unsigned int c,const char* f, unsigned int l) : core::v3::Exception(c,f,l)
{
}
Exception::Exception(unsigned int c,const char* s,const char* f, unsigned int l) : core::v3::Exception(c,s,f,l)
{
}

const char* Exception::what () const throw ()
{
	switch(code())
	{
	case Errors::NO_ERROR:
		return "No error.";
	case Errors::FILE_TERGET_NOT_FOUND:
		return "Archivo objetivo no encontrado";
	case Errors::INDEX_OUT_OF_RANGE:
		return "Indice furea de rango";
	case Errors::DESSYNCHRONIZATION_BUFEER_SENTINEL:
		return "Los sentinelas del buffer no cumplem con el criterio de sincrinizacion";
	case Errors::NEGATIVE_STRING:
		return "Secuencia negativa de caracteres";
	case Errors::NULL_STRING:
		return "Null string";
	default:
		return "Error desconocido.";
	}
	return "Error desconocido.";
}
	
}