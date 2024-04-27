
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
    *\brief Node Base para instruciones
    **/
    struct Instruction : public node
    {
        Instruction* next;
        unsigned char* mcode;
        size_t msize;

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

        virtual void print(std::ostream&)const = 0;
        virtual void generate(std::ostream&)const;

        void mode(size_t, const node& );
    };



    /**
    *\brief Node de Identificar
    **/
    struct Unit : public Node
    {
        Unit();
        Unit(const Statemants&);

        virtual void print(std::ostream&) const;
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
        virtual void generate(std::ostream&)const;
    };


    /**
    *\brief Node de Identificar
    **/
    struct Declaration : public Statement
    {
        Declaration();
        Declaration(Statemants);
        Declaration(node& specifiers);
        Declaration(node& specifiers,node& initlist);

        node *specifiers,*initlist;

        virtual void print(std::ostream&)const;
    };


    /**
    *\brief Node de Identificar
    **/
    struct Declarator : public Statement
    {
        virtual void print(std::ostream&)const;
    };

    /**
    *\brief Node de Identificar
    **/
    struct Direct_Declarator : public Statement
    {
    public:
        Direct_Declarator(Identifier&);
        Direct_Declarator(Declarator&);

        virtual void print(std::ostream&)const;
    };


    /**
    *\brief Node de Texto
    **/
    struct Segment : public Keyword
    {
        Segment() = default;
        Segment(const char*, size_t);
        Segment(Tokens,const char*, size_t);
        Segment(Statemants,const char*, size_t);
        Segment(Statemants,Tokens,const char*, size_t);

    };


    /**
    *\brief Node de Texto
    **/
    class Memory : public node
    {
    public:
        Memory();

        void set(node&);


        virtual void print(std::ostream&)const;
        char mode() const;
        
    private:

    };

    /**
    *\brief Node de Texto
    **/
    class Register : public Keyword
    {
    public:
        Register() =default;
        Register(const char*, size_t);
        Register(Tokens,const char*, size_t);
        Register(Statemants,const char*, size_t);
        Register(Statemants,Tokens,const char*, size_t);
        Register(Tokens);


        unsigned char size() const;
        unsigned char mode() const;
        void word(unsigned char&) const;
        //void code(unsigned char&) const;
        void mode(unsigned char&) const;
        void rm(unsigned char&) const;
        //unsigned char reg() const;
    };


    /**
    *\brief Node de Identificar
    **/
    struct Init_Declarator : public Statement
    {
        Init_Declarator();
        Init_Declarator(Declarator&);
        Init_Declarator(Declarator&,node& initializer);
        virtual void print(std::ostream&)const;
    };

}


#endif
