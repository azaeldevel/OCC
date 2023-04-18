


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



namespace oct::cc::v0::AII
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
                return "unknow";
        }
    }
    const char* type_specifier_to_string(Tokens type)
    {
        switch(type)
        {
            case Tokens::VOID :
                return "void";
            case Tokens::CHAR :
                return "char";
            case Tokens::SHORT :
                return "short";
            case Tokens::INT :
                return "int";
            case Tokens::LONG :
                return "long";
            case Tokens::FLOAT :
                return "float";
            case Tokens::DOUBLE :
                return "double";
            case Tokens::SIGNED :
                return "signed";
            case Tokens::UNSIGNED :
                return "unsigned";
			default:
				return "unknow";
        }
    }







    statement::statement() : is_instruction(false),next(NULL)
    {
    }
    void statement::print(std::ostream&)const
    {
        ;
    }




    void instruction_mov::print(std::ostream&)const
    {
        ;
    }


    void move_8b_reg_byte::generate(std::ostream& out) const
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
    }
    void move_8b_reg_byte::print(std::ostream& out) const
    {
        out << "\n\tmov " << register_to_string(registe) << " ";
        if(type == 'C') out << "'" << (char)byte << "'";
        else if(type == 'I') out << (int)byte;
    }

    void instruction_int::generate(std::ostream& out) const
    {
        unsigned char instruction[2];
		instruction[0] = 0b11001101;//opcode
		instruction[1] = service;
		out.write((char*)&instruction,2);
    }
    void instruction_int::print(std::ostream& out) const
    {
        out << "\n\tint " << int(service) << "";
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


    void direct_declarator::print(std::ostream& out)const
    {
        if(id) out << id->name;
    }

    void declarator::print(std::ostream& out)const
    {
        if(direct) direct->print(out);
    }
    void declarator::generate(std::ostream& out) const
    {
        ;
    }

    void type_specifier::print(std::ostream& out)const
    {
        switch(type)
        {
            case Tokens::VOID :
                out << "void";
                break;
            case Tokens::CHAR :
                out << "char";
                break;
            case Tokens::SHORT :
                out << "short";
                break;
            case Tokens::INT :
                out << "int";
                break;
            case Tokens::LONG :
                out << "long";
                break;
            case Tokens::FLOAT :
                out << "float";
                break;
            case Tokens::DOUBLE :
                out << "double";
                break;
            case Tokens::SIGNED :
                out << "signed";
                break;
            case Tokens::UNSIGNED :
                out << "unsigned";
                break;
			default:
				;
        }
    }
    void type_specifier::generate(std::ostream& out) const
    {
        ;
    }


    void function_implementation::print(std::ostream& out) const
    {
        if(specifiers) specifiers->print(out);
        out << " ";
        if(declaration) declaration->print(out);
        out << "()\n{\n";
        if(body->statement_list)
        {
            //std::cout << "statement_list\n";
            const statement* stmt = body->statement_list;
            while(stmt)
            {
                if(stmt->is_instruction)
                {
                    switch(((instruction*)stmt)->inst)
                    {
                    case Tokens::MOV :
                        //out << "\n\tmov " << register_to_string(((move_8b_reg_byte*)stmt)->registe) << " ";
                        //if(((move_8b_reg_byte*)stmt)->type == 'C') out << "'" << (char)((move_8b_reg_byte*)stmt)->byte << "'";
                        ((move_8b_reg_byte*)stmt)->print(out);
                        break;
                    case Tokens::INT :
                        //out << "\n\tint " << int(((instruction_int*)stmt)->service) << "";
                        ((instruction_int*)stmt)->print(out);
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
    void function_implementation::generate(std::ostream& out) const
    {
        if(specifiers) specifiers->generate(out);
        if(declaration) declaration->generate(out);
        if(body->statement_list)
        {
            //std::cout << "statement_list\n";
            const statement* stmt = body->statement_list;
            while(stmt)
            {
                if(stmt->is_instruction)
                {
                    switch(((instruction*)stmt)->inst)
                    {
                    case Tokens::MOV :
                        //out << "\n\tmov " << register_to_string(((move_8b_reg_byte*)stmt)->registe) << " ";
                        //if(((move_8b_reg_byte*)stmt)->type == 'C') out << "'" << (char)((move_8b_reg_byte*)stmt)->byte << "'";
                        ((move_8b_reg_byte*)stmt)->generate(out);
                        break;
                    case Tokens::INT :
                        //out << "\n\tint " << int(((instruction_int*)stmt)->service) << "";
                        ((instruction_int*)stmt)->generate(out);
                        break;
					default:
                        ;
                    }
                }
                stmt = stmt->next;
            }
        }
    }
    void declaration::print(std::ostream& out)const
    {
        const type_specifier* spec = specifiers;
        while(spec)
        {
            spec->print(out);
            out << " ";
            spec = (type_specifier*)spec->next;
        }

        const init_declarator* dec = list;
        while(dec)
        {
            dec->print(out);
            if(dec->next) out << ", ";

            dec = (init_declarator*)dec->next;
        }
        out << ";";
    }
    void declaration::generate(std::ostream& out) const
    {
        ;
    }


    void external_declaration::print(std::ostream& out) const
    {
        if(decl) decl->print(out);
        if(func) func->print(out);
    }
    void external_declaration::generate(std::ostream& out) const
    {
        if(decl) decl->generate(out);
        if(func) func->generate(out);
    }
}

}
