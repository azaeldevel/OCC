


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
//#include <oas-intel-A+.tab.h>
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


namespace nodes
{
/*
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
}*/


/*
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
}*/

    statement::statement() : is_instruction(false),next(NULL)
    {
    }

    void declaration_specifiers::print()const
    {
        /*if(std::variant::get<type_specifier*>())
        {
            //std::cout << $$->specifer->type << "\n";
            switch(get<type_specifier*>()->type)
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
			default:
				std::cout << "unknow";
            }
        }*/
    }
    void direct_declarator::print()const
    {
        std::cout << id->name;
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
            statement* stmt = body->statement_list;
            while(stmt)
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
					default:
						std::cout << "\tunknow\n";
                    }
                }
                stmt = stmt->next;
            }
        }
        std::cout << "}";
    }




    bool move_8b_reg_byte::generate(std::fstream& out) const
    {
        unsigned char instruction[2];
        instruction[0] = 0b1011;//opcode
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        instruction[0] = instruction[0] << 1;//w = one byte
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        switch(registe)//reg
        {
            case Tokens::AL:
                instruction[0] = instruction[0] << 3;
                break;
            case Tokens::CL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b001;
                break;
            case Tokens::DL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b010;
                break;
            case Tokens::BL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b011;
                break;
            case Tokens::AH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b100;
                break;
            case Tokens::CH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b101;
                break;
            case Tokens::DH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b110;
                break;
            case Tokens::BH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
        instruction[1] = integer;
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,2);

        return true;
    }

    bool instruction_int::generate(std::fstream& out) const
    {
        unsigned char instruction[2];
		instruction[0] = 0b11001101;//opcode
		instruction[1] = service;
		out.write((char*)&instruction,2);

		return true;
    }
}

}
