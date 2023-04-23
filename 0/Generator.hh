
#ifndef OCTETOS_CORE_CC_TOOLS_GENERATOR
#define OCTETOS_CORE_CC_TOOLS_GENERATOR

#include <fstream>

#include "A.hh"


namespace oct::cc::v0::tools
{
    class Generator
    {
    public:
        virtual void save(std::ostream& out) const = 0;
    };

    class Parser :  public Generator
    {
    public:
        Parser(Language l);


        virtual void declaration(std::ostream& out) const;
        virtual void declaration_code_required(std::ostream& out) const;
        virtual void rules(std::ostream& out) const;
        virtual void functions(std::ostream& out) const;
        virtual void save(std::ostream& out) const;

    private:
        Language lang;

    private:
        const char* header_file() const;
        const char* space() const;
        /*
        *\brief Retorna el nombre del lenguaje
        *\param ornament si es true, returno el nombre del lenguaje con adorno de otra forma retorna el nombre formal.
        */
        const char* language(bool ornament) const;
    };
}


#endif // OCTETOS_CORE_CC_TOOLS_GENERATOR
