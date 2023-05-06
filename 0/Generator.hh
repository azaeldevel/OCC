
#ifndef OCTETOS_CORE_CC_TOOLS_GENERATOR
#define OCTETOS_CORE_CC_TOOLS_GENERATOR

#include <fstream>

#include "A.hh"


namespace oct::cc::v0::tools
{
    class Generator
    {
    public:
        Generator(Language l);

        virtual void save(std::ostream& out) const = 0;

    protected:
        Language lang;

    protected:
        const char* header_file() const;
        const char* header_file(int) const;
        const char* space() const;
        const char* space(int) const;
        const char* tree_node() const;
        bool is_disnastic_A()const;
        /**
        *\brief true si la gramática del lenguaje tiene operador de asignación, false en otro caso.
        */
        bool has_assignment_operator()const;
        /**
        *\brief true si la gramática del lenguaje tiene operador de asignación, false en otro caso.
        */
        bool has_return_statement()const;
        /**
        *\brief Retorna el nombre del lenguaje
        *\param ornament si es true, returno el nombre del lenguaje con adorno de otra forma retorna el nombre formal.
        */
        const char* language(bool ornament) const;
        /**
        *\brief Retorna el prefijo que se agrega para el opcion de flex/bison
        */
        const char* prefix() const;
    };


    class Lexer :  public Generator
    {
    public:
        Lexer(Language l);

        virtual void declaration(std::ostream& out) const;
        virtual void rules(std::ostream& out) const;
        virtual void functions(std::ostream& out) const;
        virtual void save(std::ostream& out) const;

    };

    class Parser :  public Generator
    {
    public:
        Parser(Language l);

        virtual void declaration(std::ostream& out) const;
        virtual void declaration_code_required(std::ostream& out) const;
        virtual void declaration_types_AI(std::ostream& out) const;
        virtual void declaration_types_AII(std::ostream& out) const;
        virtual void rules(std::ostream& out) const;
        virtual void rules_finals(std::ostream& out) const;
        virtual void rules_constants(std::ostream& out) const;
        virtual void rules_primary_expression(std::ostream& out) const;
        virtual void rules_instructions(std::ostream& out) const;
        virtual void rules_instructions_AI(std::ostream& out) const;
        virtual void rules_instructions_AII(std::ostream& out) const;
        //virtual void rules_declaration(std::ostream& out) const;
        virtual void rules_declarations(std::ostream& out) const;
        virtual void rules_declarator(std::ostream& out) const;
        virtual void rules_translation_unit_AI(std::ostream& out) const;
        virtual void rules_translation_unit_AII(std::ostream& out) const;
        virtual void functions(std::ostream& out) const;
        virtual void save(std::ostream& out) const;

    };
}


#endif // OCTETOS_CORE_CC_TOOLS_GENERATOR
