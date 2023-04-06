


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

#include <oas-intel-parser-A+.hh>
#include <oas-intel-A+.tab.h>
#include <limits>
#include <core/3/Exception.hh>
#include <core/3/math.hh>

#include "A+.hh"



namespace oct::cc::v0::A
{


File::File(SymbolTable& s) : file(NULL),buffer(NULL),scanner(NULL),symbols(&s)
{
}

void* File::get_scanner()
{
	return scanner;
}
FILE* File::get_file()
{
	return file;
}


const std::filesystem::path& File::get_filename() const
{
	return filename;
}




/*
Block::Block() : actual(NULL),index(0)
{
	if(blocks.empty()) return;
	it = blocks.begin();
	actual = (Symbol*)*it;
}


size_t Block::get_size(Symbol* symbol) const
{
	switch(symbol->token)
	{
	case Tokens::identifier:
		//std::cout << "Block::next : identifier\n";
		return sizeof(Identifier);
	case Tokens::LITERAL_INTEGER_DEC:
	case Tokens::LITERAL_INTEGER_HEX:
		//std::cout << "Block::next : LITERAL_INTEGER\n";
		return sizeof(Integer);
	default:
		return sizeof(Symbol);
	}
}
Symbol* Block::next()
{
	//std::cout << "Block::next begin\n";
	if(not actual) return NULL;
	if(get_size(actual) + index >= page_size)
	{
		//std::cout << "Block::create malloc\n";
		it++;
		actual = (Symbol*)*it;
		index = 0;
	}

	char* newptr = (char*)actual;
	//std::cout << "Block::next actual : " << (long)actual << "\n";
	//std::cout << "Block::next index : " << index << "\n";
	newptr += index;
	Symbol* obj = (Symbol*)newptr;
	index += get_size(actual) + 1;
	//std::cout << "Block::create newptr : " << (long)newptr << "\n";
	actual = (Symbol*)obj;
	//std::cout << "Block::next end\n";
	return obj;
}
*/

namespace nodes
{

Tokens Integer::reduced_token() const
{
	//std::cout << "reduced_token : step 1 " << number << "\n";
	if(0 > number)
	{
		if(std::numeric_limits<signed char>::min()  < number)
        {
            if(format == 'D') return Tokens::LITERAL_INTEGER_DEC_SCHAR;
            else if(format == 'H') return Tokens::LITERAL_INTEGER_HEX_UCHAR;
        }
		else if(std::numeric_limits<short>::min()  < number)
        {
            return Tokens::LITERAL_INTEGER_DEC_SHORT;
        }
		else if(std::numeric_limits<int>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_INT;
		else if(std::numeric_limits<long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONG;
		else if(std::numeric_limits<long long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONGLONG;
	}
	else
	{
		if(std::numeric_limits<unsigned char>::max() > number) return Tokens::LITERAL_INTEGER_DEC_UCHAR;
		else if(std::numeric_limits<unsigned short>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_USHORT;
		else if(std::numeric_limits<unsigned int>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_UINT;
		else if(std::numeric_limits<unsigned long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONG;
		else if(std::numeric_limits<unsigned long long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONGLONG;
	}

	return Tokens::LITERAL_INTEGER_DEC_LONGLONG;
}



Tokens integer_token(long long number)
{
	if(0 > number)
	{
		if(std::numeric_limits<signed char>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_SCHAR;
		else if(std::numeric_limits<short>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_SHORT;
		else if(std::numeric_limits<int>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_INT;
		else if(std::numeric_limits<long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONG;
		else if(std::numeric_limits<long long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONGLONG;
	}
	else
	{
		if(std::numeric_limits<unsigned char>::max() > number) return Tokens::LITERAL_INTEGER_DEC_UCHAR;
		else if(std::numeric_limits<unsigned short>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_USHORT;
		else if(std::numeric_limits<unsigned int>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_UINT;
		else if(std::numeric_limits<unsigned long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONG;
		else if(std::numeric_limits<unsigned long long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONGLONG;
	}

	return Tokens::LITERAL_INTEGER_DEC_LONGLONG;
}

    statement::statement() : is_instruction(false)
    {
    }

    void declaration_specifiers::print()const
    {
        if(type)
        {
            //std::cout << $$->specifer->type << "\n";
            switch(type->type)
            {
            case Tokens::VOID :
                std::cout << "void";
                break;
            case Tokens::CHAR :
                std::cout << "char";
                break;
            case Tokens::SHORT :
                std::cout << "short";
                break;
            case Tokens::INT :
                std::cout << "int";
                break;
            case Tokens::LONG :
                std::cout << "long";
                break;
            case Tokens::FLOAT :
                std::cout << "float";
                break;
            case Tokens::DOUBLE :
                std::cout << "double";
                break;
            case Tokens::SIGNED :
                std::cout << "signed";
                break;
            case Tokens::UNSIGNED : std::cout << "unsigned";
                break;
            }
        }
    }
    void direct_declarator::print()const
    {
        std::cout << identity->name;
    }
    void declarator::print()const
    {
        if(direct) direct->print();
    }
    void function_implementation::print() const
    {
        specifier->print();
        std::cout << " ";
        if(declaration) declaration->print();
        std::cout << "\n{\n";
        if(body->statement_list)
        {
            //std::cout << "statement_list\n";
            std::list<statement*>* list = body->statement_list;
            for(statement* stmt : *list)
            {
                if(stmt->is_instruction)
                {
                    switch(((instruction*)stmt)->inst)
                    {
                    case Tokens::MOV :
                        std::cout << "\tmove\n";
                        break;
                    case Tokens::INT :
                        std::cout << "\tinterruption\n";
                        break;
                    }
                }
            }
        }
        std::cout << "}";
    }


}

}
