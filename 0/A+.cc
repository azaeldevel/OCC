


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
    const char* register_to_string(Tokens tk)
    {
        switch(tk)
        {
            case Tokens::AL : return "AL";
            case Tokens::AH : return "AH";
            case Tokens::AX : return "AX";
            case Tokens::BL : return "BL";
            case Tokens::BH : return "BH";
            case Tokens::BX : return "BX";
            case Tokens::CL : return "CL";
            case Tokens::CH : return "CH";
            case Tokens::CX : return "CX";
            case Tokens::DL : return "DL";
            case Tokens::DH : return "DH";
            case Tokens::DX : return "DX";
            default:
                return "no register";
        }
    }

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
    void direct_declarator::print(std::ostream& out)const
    {
        if(id) out << id->name;
    }
    void declarator::print(std::ostream& out)const
    {
        if(direct) direct->print(out);
    }
    void function_implementation::print(std::ostream& out) const
    {
        if(specifier) specifier->print();
        out << " ";
        if(declaration) declaration->print(out);
        out << "\n{\n";
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
                        out << "\n\tmov " << register_to_string(((move_8b_reg_byte*)stmt)->registe) << " ";
                        if(((move_8b_reg_byte*)stmt)->type == 'C') out << "'" << (char)((move_8b_reg_byte*)stmt)->byte << "'";
                        break;
                    case Tokens::INT :
                        out << "\n\tint " << int(((instruction_int*)stmt)->service) << "";
                        break;
					default:
						out << "\n\tunknow";
                    }
                }
                stmt = stmt->next;
            }
        }
        out << "\n}";
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
        instruction[1] = byte;
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

    void initializer::print(std::ostream& out)const
    {
        if(data_type == Tokens::LITERAL_CHAR)
        {
            //std::cout << "Tokens::LITERAL_CHAR\n";
            const initializer_literal<char>* literial = reinterpret_cast<const initializer_literal<char>*>(this);
            literial->print(out);
        }
        else if(data_type == Tokens::LITERAL_INTEGER_HEX or data_type == Tokens::LITERAL_INTEGER_DEC)
        {
            //std::cout << "Tokens::LITERAL_..\n";
            const initializer_literal<long long>* literial = reinterpret_cast<const initializer_literal<long long>*>(this);
            literial->print(out);
        }
        else
        {
                //std::cout << "no se encotro constate\n";
        }
    }

    void init_declarator::print(std::ostream& out)const
    {
        if(dec) dec->print(out);
        if(value)
        {
            out << " = ";
            value->print(out);
        }
    }

    void declaration::print(std::ostream& out)const
    {
        init_declarator* dec = list;
        while(dec)
        {
            dec->print(out);
            if(dec->next) out << ", ";

            dec = (init_declarator*)dec->next;
        }
        out << ";\n";
    }
}

}
