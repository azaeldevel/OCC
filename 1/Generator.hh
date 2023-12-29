
#ifndef OCTETOS_OCC_V1_GENERATOR_HH
#define OCTETOS_OCC_V1_GENERATOR_HH

#include <fstream>

#include "occ.hh"


namespace oct::cc::v1
{
    class Generator
    {
    public:
        Generator(Language l);

    protected:
        Language lang;

    protected:

    };


    namespace A::I
    {
        class Lexer :  public Generator
        {
        public:
            Lexer(Language l);

            virtual void declaration(std::ostream& out) const;
            virtual void rules(std::ostream& out) const;
            virtual void rules_add_keyword(std::ostream& out,const std::string& string,const std::string& token) const;
            virtual void rules_add_keyword(std::ostream& out,const std::string& string) const;
            virtual void rules_add_keyword_register(std::ostream& out,const std::string& string) const;
            virtual void rules_keywords(std::ostream& out,Language) const;
            virtual void functions(std::ostream& out) const;
            virtual void save(std::ostream& out) const;
        };

        class Parser :  public Generator
        {
        public:
            Parser(Language l);

            virtual void declaration(std::ostream& out) const;
            virtual void declaration_add_keyword(std::ostream& out,const std::string& string,const std::string& token) const;
            virtual void declaration_add_keyword(std::ostream& out,const std::string& string) const;
            virtual void declaration_add_keyword_register(std::ostream& out,const std::string& string) const;
            virtual void declaration_occ(std::ostream& out) const;
            virtual void declaration_A(std::ostream& out) const;
            virtual void declaration_AI(std::ostream& out) const;
            virtual void declaration_C_expression(std::ostream& out) const;
            virtual void declaration_C_declaration(std::ostream& out) const;
            virtual void rules(std::ostream& out) const;
            virtual void rules_types(std::ostream& out) const;
            virtual void rules_identifier(std::ostream& out) const;
            virtual void rules_memory(std::ostream& out) const;
            virtual void rules_instructions(std::ostream& out) const;
            virtual void rules_regiters(std::ostream& out) const;
            virtual void rules_segments(std::ostream& out) const;
            virtual void rules_functions(std::ostream& out) const;
            virtual void rules_unit(std::ostream& out) const;
            virtual void rules_occ(std::ostream& out) const;
            virtual void rules_C_expression(std::ostream& out) const;
            virtual void rules_C_declaration(std::ostream& out) const;
            virtual void rules_A(std::ostream& out) const;
            virtual void rules_AI(std::ostream& out) const;
            virtual void functions(std::ostream& out) const;
            virtual void save(std::ostream& out) const;

            const char* instruction_string(Tokens)const;

        };

    }
}


#endif // OCTETOS_CORE_CC_TOOLS_GENERATOR
