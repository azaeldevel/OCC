


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




    template<> void integer_constant<integer>::convert(const std::string& string)
    {

    }
    template<> bool integer_constant<integer>::is_data_8b() const
    {
        return false;
    }
    template<> bool integer_constant<integer>::is_data_16b() const
    {
        return false;
    }












    void initializer::print(std::ostream& out)const
    {
        //std::cout << "void init_declarator::print(std::ostream& out)const\n";
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
        //std::cout << "void init_declarator::print(std::ostream& out)const\n";
        if(dec) dec->print(out);
        if(value)
        {
            out << " ";
            value->print(out);
        }
    }


    void direct_declarator::print(std::ostream& out)const
    {
        //std::cout << "void direct_declarator::print(std::ostream& out)const\n";
        //std::cout << " id : " << id << "\n";
        //std::cout << " id : " << id->string << "\n";
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
    identifier* declarator::get_name() const
    {
        return direct->id;
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
        //std::cout << "Step 1\n";
        type_specifier* spec = specifiers;
        while(spec)
        {
            spec->print(out);
            out << " ";
            spec = (type_specifier*)spec->next;
        }

        //std::cout << "Step 2\n";
        init_declarator* dec = list;
        while(dec)
        {
            dec->print(out);
            if(dec->next) out << ", ";

            dec = (init_declarator*)dec->next;
        }
        out << ";";
        //std::cout << "Step 3\n";
    }
    void declaration::generate(std::ostream& out) const
    {
        ;
    }
    bool declaration::semantic()const
    {

        return true;
    }




    void function::print(std::ostream& out)const
    {
        //std::cout << "void function::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        if(not body_list) return;
        //std::cout << "Step 2\n";
        if(id) out << "\n" << id->string << ":";
        //std::cout << "Step 3\n";
        statement* inst = (statement*)body_list;
        //std::cout << "Step 4\n";
        while(inst)
        {
            //std::cout << "Step 4.1\n";
            if(inst->is_instruction)
            {
                switch(((instruction*)inst)->inst)
                {
                    case Tokens::MOV :
                        //std::cout << "Step 4.1.1\n";
                        ((instruction*)inst)->print(out);
                        break;
                    case Tokens::INT :
                        //std::cout << "Step 4.1.2\n";
                        ((instruction*)inst)->print(out);
                        break;
                    case Tokens::RET :
                        //std::cout << "Step 4.1.3\n";
                        out << "\n\tRET;\n";
                        break;
                    default:
                        ;
                }
            }
            //std::cout << "Step 4.2\n";
            inst = (statement*)inst->next;
            //std::cout << "Step 4.3\n";
        }
        //std::cout << "Step 5\n";
    }
    void function::generate(std::ostream& out) const
    {
        statement* inst = (statement*)body_list;
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
            inst = (statement*)inst->next;
        }
    }
    bool function::semantic()const
    {

        return true;
    }

    void translation_unit::print(std::ostream& out)const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        declaration* dec = declarations;
        while(dec)
        {
            //std::cout << "Step 1.1\n";
            dec->print(out);
            //std::cout << "Step 1.2\n";
            if(dec->next) out << "\n";
            //std::cout << "Step 1.3\n";

            dec = (declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 2\n";
        function* func = functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            func->print(out);
            //std::cout << "Step 1.2\n";
            if(func->next) out << "\n";
            //std::cout << "Step 1.3\n";

            func = (function*)func->next;
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


    void SymbolTable::add(const nodes::declaration* d)
    {
        insert(std::pair(d->list->dec->direct->id->string.c_str(),d));
    }

    /*
    void SymbolTable::add(nodes::declarator* d)
    {
        insert(std::pair(d->direct->id->string.c_str(),d));
    }
    */

    void SymbolTable::add(const space* s)
    {
        insert(std::pair(s->name->string.c_str(),s));
    }

    void SymbolTable::add(const nodes::function* f)
    {
        insert(std::pair(f->id->string.c_str(),f));
    }


}
