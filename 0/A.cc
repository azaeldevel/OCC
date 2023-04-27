


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

#include <A/oas-intel-parser.hh>

#include <limits>
#include <core/3/Exception.hh>
#include <core/3/math.hh>

#include "A.hh"



namespace oct::cc::v0::AI
{



File::File() : file(NULL),buffer(NULL),scanner(NULL)
{
}


void* File::get_scanner()
{
	return scanner;
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



    Node::Node() : next(NULL)
    {
    }

    statement::statement() : is_instruction(false)
    {
    }
    void statement::print(std::ostream&)const
    {
    }




    void Move::print(std::ostream& out)const
    {
        //out << "void Move::print(std::ostream& out)const\n";
        switch(op_type)
        {
        case operands_type::regiter_integer:
            {
                auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
                auto source = reinterpret_cast<Token<integer>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                out << source->token;
            }
            break;
        case operands_type::regiter_char:
            {
                auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
                auto source = reinterpret_cast<Token<char>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                out << "'" << source->token << "'";
            }
            break;
        default:
            ;//error
        }
    }
    void Move::generate(std::ostream& out)const
    {
        switch(word_size)
        {
        case 8:
            switch(op_type)
            {
            case operands_type::regiter_integer:
            case operands_type::regiter_char:
                generate_8b_inmediate(out);
                break;
            default:
                ;
            }
            break;
        default:
            ;
        }
    }
    void Move::generate_8b_inmediate(std::ostream& out)const
    {
        auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
        auto source = reinterpret_cast<Token<char>*>(this->source);

        unsigned char instruction[2];
        instruction[0] = 0b1011;//opcode
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        instruction[0] = instruction[0] << 1;//w = one byte
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        switch(destine->token)//reg
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
        instruction[1] = source->token;
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,2);
    }

    /*
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
    */

    void Interruption::generate(std::ostream& out) const
    {
        unsigned char instruction[2];
		instruction[0] = 0b11001101;//opcode
		instruction[1] = service;
		out.write((char*)&instruction,2);
    }
    void Interruption::print(std::ostream& out) const
    {
        out << "\n\tint " << int(service) << "";
    }













    void initializer::print(std::ostream& out)const
    {
        if(data_type == Tokens::CONSTANT_CHAR)
        {
            //std::cout << "Tokens::LITERAL_CHAR\n";
            const initializer_literal<char>* literial = reinterpret_cast<const initializer_literal<char>*>(this);
            literial->print(out);
        }
        else if(data_type == Tokens::CONSTANT_INTEGER_HEX or data_type == Tokens::CONSTANT_INTEGER_DEC)
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
        if(id) out << id->string;
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
            case Tokens::BYTE :
                out << "byte";
                break;
			default:
				;
        }
    }
    void type_specifier::generate(std::ostream& out) const
    {
        ;
    }


    void declaration::print(std::ostream& out)const
    {
        //std::cout << "void declaration::print(std::ostream& out)const\n";
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




    void function::print(std::ostream& out)const
    {
        if(not body_list) return;
        if(id) out << "\n" << id->string << ":";
        const statement* inst = (const statement*)body_list;
        while(inst)
        {
            if(inst->is_instruction)
            {
                switch(((instruction*)inst)->inst)
                {
                    case Tokens::MOV :
                        ((Move*)inst)->print(out);
                        break;
                    case Tokens::INT :
                        ((Interruption*)inst)->print(out);
                        break;
                    case Tokens::RET :
                        out << "\n\tret;\n";
                        break;
                    default:
                        ;
                }
            }
            inst = (const statement*)inst->next;
        }
    }
    void function::generate(std::ostream& out) const
    {
        const statement* inst = (const statement*)body_list;
        while(inst)
        {
            if(inst->is_instruction)
            {
                switch(((instruction*)inst)->inst)
                {
                    case Tokens::MOV :
                        ((Move*)inst)->generate(out);
                        break;
                    case Tokens::INT :
                        ((Interruption*)inst)->generate(out);
                        break;
                    case Tokens::RET :
                        ;
                        break;
                    default:
                        ;
                }
            }
            inst = (const statement*)inst->next;
        }
    }

    void translation_unit::print(std::ostream& out)const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        const declaration* dec = declarations;
        while(dec)
        {
            //::cout << "Step 1.1\n";
            dec->print(out);
           // std::cout << "Step 1.2\n";
            if(dec->next) out << "\n";
            //std::cout << "Step 1.3\n";

            dec = (const declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 2\n";
        const function* func = functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            func->print(out);
            //std::cout << "Step 1.2\n";
            if(func->next) out << "\n";
            //std::cout << "Step 1.3\n";

            func = (const function*)func->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 3\n";
    }
    void translation_unit::generate(std::ostream& out) const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        if(functions) functions->generate(out);
    }
}

    void SymbolTable::add(nodes::declaration* d)
    {
        insert(std::pair(d->list->dec->direct->id->string.c_str(),d));
    }

    void SymbolTable::add(nodes::declarator* d)
    {
        insert(std::pair(d->direct->id->string.c_str(),d));
    }

    void SymbolTable::add(nodes::space* s)
    {
        insert(std::pair(s->name->string.c_str(),s));
    }

    void SymbolTable::add(nodes::function* f)
    {
        insert(std::pair(f->id->string.c_str(),f));
    }


}
