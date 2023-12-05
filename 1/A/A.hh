
#ifndef OCTETOS_OCC_V1_A_A_HH
#define OCTETOS_OCC_V1_A_A_HH


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



#include <iostream>

#include "../occ.hh"


namespace oct::cc::v1::A
{

    /**
    *\brief Node de Identificar
    **/
    struct Unit : public Node
    {
        Unit() = default;
        Unit(size_t);
        Unit(const Types&);
        Unit(const Types&,size_t);

        void print(std::ostream&)const;
        virtual bool semantic(std::ostream&);
    };

    /**
    *\brief Node de Identificar
    **/
    struct Identifier : public Node
    {
        std::string string;
        Node* next;

        Identifier();
        Identifier(Types);

        void print(std::ostream&)const;
    };

    /**
    *\brief Node de Identificar
    **/
    struct Function : public Node
    {
        Identifier* identifier;
        Node* next;

        Function();
        Function(Types);
        void print(std::ostream&)const;
    };



    /**
    *\brief Node Base para instruciones
    **/
    struct Instruction : public Node
    {
        Node* next;
        char* inscode;

        /**
        *\brief
        *
        */
        Instruction();
        /**
        *\brief Crea un nodo para la instruccion indicada
        *\param type tipo de instruccion
        *\param instsize bytes usados para especificar el codigo de instrccion
        */
        Instruction(Types type,size_t instsize);
        ~Instruction();

        void print(std::ostream&)const;
    };




    /**
    *\brief Node Base para instruciones mov
    **/
    struct Move : public Instruction
    {
        Move();
        Move(Types,size_t instsize);
        void print(std::ostream&)const;

        void make(Tokens to, Tokens front);
        void make(Tokens to, Tokens front,const Node* nTo,const Node* nFront);

    };
}


#endif
