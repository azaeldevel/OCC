
#ifndef OCTETOS_CC_V0_AII_HH
#define OCTETOS_CC_V0_AII_HH


/*
 * main.cc
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


#include "A.hh"

namespace A_here = oct::cc::v0::AI;
namespace AI_here = oct::cc::v0::AI;

namespace oct::cc::v0::AII
{
    namespace core_here = oct::core::v3;


    namespace nodes
    {


        struct compound_statement : public A_here::nodes::statement
        {
            statement* statement_list;
        };


        struct function_definition : public A_here::nodes::statement
        {
            A_here::nodes::Token<AI_here::Tokens>* specifiers;
            A_here::nodes::declarator* declaration;
            compound_statement* body;

            void print(std::ostream&)const;
            void generate(std::ostream&)const;

        };


        struct external_declaration : public A_here::nodes::statement
        {
            function_definition* func;
            A_here::nodes::declaration* decl;

            void print(std::ostream&)const;
            void generate(std::ostream&) const;

            const AI_here::nodes::translation_unit* translate(AI_here::Tray<nodes::external_declaration>*)const ;

            AI_here::nodes::function* convert(AI_here::Tray<nodes::external_declaration>*,function_definition*)const;
            AI_here::nodes::declaration* convert(AI_here::Tray<nodes::external_declaration>*,A_here::nodes::declaration*)const;
        };
    }
}


#endif
