
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
        const char* space() const;
        const char* tree_node() const;
        /*
        *\brief Retorna el nombre del lenguaje
        *\param ornament si es true, returno el nombre del lenguaje con adorno de otra forma retorna el nombre formal.
        */
        const char* language(bool ornament) const;
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
        virtual void declaration_types_AII(std::ostream& out) const;
        virtual void rules(std::ostream& out) const;
        virtual void rules_finals(std::ostream& out) const;
        virtual void rules_instructios(std::ostream& out) const;
        virtual void rules_statement_AII(std::ostream& out) const;
        virtual void rules_instructios_statment_AI(std::ostream& out) const;
        virtual void rules_instructios_statment_AII(std::ostream& out) const;
        virtual void rules_declaration(std::ostream& out) const;
        virtual void rules_unit_AI(std::ostream& out) const;
        virtual void rules_unit_AII(std::ostream& out) const;
        virtual void functions(std::ostream& out) const;
        virtual void save(std::ostream& out) const;

    };
}


#endif // OCTETOS_CORE_CC_TOOLS_GENERATOR
