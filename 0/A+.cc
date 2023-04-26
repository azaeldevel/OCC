


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

#include <A+/oas-intel-parser.hh>
//#include <oas-intel-A+.tab.h>
#include <limits>
#include <core/3/Exception.hh>
#include <core/3/math.hh>

#include "A+.hh"



namespace oct::cc::v0::AII
{

    namespace nodes
    {
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
                        switch(((A_here::nodes::instruction*)stmt)->inst)
                        {
                        case A_here::Tokens::MOV :
                            //out << "\n\tmov " << register_to_string(((move_8b_reg_byte*)stmt)->registe) << " ";
                            //if(((move_8b_reg_byte*)stmt)->type == 'C') out << "'" << (char)((move_8b_reg_byte*)stmt)->byte << "'";
                            ((A_here::nodes::Move*)stmt)->print(out);
                            break;
                        case A_here::Tokens::INT :
                            //out << "\n\tint " << int(((instruction_int*)stmt)->service) << "";
                            ((A_here::nodes::instruction_int*)stmt)->print(out);
                            break;
                        default:
                            out << "\n\tunknow";
                        }
                    }
                    stmt = (const statement*)stmt->next;
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
                        switch(((A_here::nodes::instruction*)stmt)->inst)
                        {
                        case A_here::Tokens::MOV :
                            //out << "\n\tmov " << register_to_string(((move_8b_reg_byte*)stmt)->registe) << " ";
                            //if(((move_8b_reg_byte*)stmt)->type == 'C') out << "'" << (char)((move_8b_reg_byte*)stmt)->byte << "'";
                            ((A_here::nodes::Move*)stmt)->generate(out);
                            break;
                        case A_here::Tokens::INT :
                            //out << "\n\tint " << int(((instruction_int*)stmt)->service) << "";
                            ((A_here::nodes::instruction_int*)stmt)->generate(out);
                            break;
                        default:
                            ;
                        }
                    }
                    stmt = (const statement*)stmt->next;
                }
            }
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
