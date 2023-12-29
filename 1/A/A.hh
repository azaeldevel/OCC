
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
    struct Instruction;

    /**
    *\brief Node de Identificar
    **/
    struct Unit : public Node
    {
        Unit();
        Unit(const Statemants&);

        virtual void print(std::ostream&)const;
        virtual bool semantic(std::ostream&);
    };


    /**
    *\brief Node de Identificar
    **/
    struct Function : public Statement
    {
        Identifier* identifier;
        Instruction* insts;

        Function();
        Function(Statemants);
        virtual void print(std::ostream&)const;
    };


    /**
    *\brief Node de Identificar
    **/
    struct Declaration : public Statement
    {
        Declaration();
        Declaration(Statemants);
        virtual void print(std::ostream&)const;
    };


    /**
    *\brief Node de Identificar
    **/
    struct Direct_Declarator : public Statement
    {
        enum class Form
        {
            identifier,
            declarator,
        };
        Direct_Declarator();
        Direct_Declarator(Statemants);
        Direct_Declarator(Statemants,Node*,Form);
        Direct_Declarator(Node*,Form);
        virtual void print(std::ostream&)const;

        Node* first;
        Form form;
    };


    /**
    *\brief Node de Texto
    **/
    struct Register : public Keyword
    {
        Register(const char*, size_t);
        Register(Tokens,const char*, size_t);
        Register(Statemants,const char*, size_t);
        Register(Statemants,Tokens,const char*, size_t);


        unsigned char register_size() const;
    };


    /**
    *\brief Node Base para instruciones
    **/
    struct Instruction : public Node
    {
        Instruction* next;
        char* inscode;

        /**
        *\brief
        *
        */
        Instruction();
        /**
        *\brief Crea un nodo para la instruccion indicada
        *\param type tipo de instruccion
        */
        Instruction(Statemants type);
        /**
        *\brief Crea un nodo para la instruccion indicada
        *\param type tipo de instruccion
        *\param instsize bytes usados para especificar el codigo de instrccion
        */
        Instruction(Statemants type,size_t instsize);

        ~Instruction();

        virtual void print(std::ostream&)const;
    };




    /**
    *\brief Node Base para instruciones mov
    **/
    struct Move : public Instruction
    {
        enum class Form
        {
            none,
            register_to_register,
            register_to_memory,
            memory_to_register,
            inmediate_to_register,
            inmediate_to_memory,
        };

        Move();
        Move(Statemants,size_t instsize);
        Move(Statemants,size_t instsize,Node* nTo,Node* nFront);

        /**
        *\biref Crea la instraccion move
        *\param instsize cantidad de bytes la instracion
        *\param nTo Valor semantico del primer paramtro
        *\param nFront Valor semantico del segundo paramtro
        **/
        Move(size_t instsize,Node* nTo,Node* nFront);

        /**
        *\biref Crea la instraccion move
        *\param instsize cantidad de bytes la instracion
        *\param nTo Valor semantico del primer paramtro
        *\param nFront Valor semantico del segundo paramtro
        *\param form indiocador de stamtement of instrccion, refereced to intel manual
        **/
        Move(size_t instsize,Node* nTo,Node* nFront,Form form);

        virtual void print(std::ostream&)const;

        /**
        *\biref Bind a instruction, is called whe all data is stored
        **/
        void bind();

        /**
        *\biref Bind a instruction, use when contructor o not get form paramter
        *\param form if 0 will call bind(), if > 0 will set form and call bind()
        **/
        void bind(Form form);

        Node *from, *to;
        Form form;
    };


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Return : public Instruction
    {
        Return();
        Return(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Empty : public Instruction
    {
        Empty();
        Empty(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Interrupt : public Instruction
    {
        Interrupt();
        Interrupt(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

        void make(Number*);

        //
        Number* service;
    };


    /**
    *\brief Instruccion call
    **/
    struct Call : public Instruction
    {
        Call();
        Call(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Instruccion call
    **/
    struct Push : public Instruction
    {
        Push();
        Push(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Instruccion call
    **/
    struct Pop : public Instruction
    {
        Pop();
        Pop(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


}


#endif
