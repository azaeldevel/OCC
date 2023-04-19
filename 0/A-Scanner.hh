
#ifndef OCTETOT_CC_V0_AI_SCANNER
#define OCTETOT_CC_V0_AI_SCANNER

#if ! defined(yyFlexLexerOnce)
    #include <FlexLexer.h>
#endif

#include <AI/oas-intel-parser-A.hh>

namespace oct::cc::v0::AI
{


class Scanner : public yyFlexLexer
{
public:
    Scanner(std::ifstream *in);
    ~Scanner();

    using FlexLexer::yylex;
    int yylex(parser::semantic_type * const lval, parser::location_type *loc);

private:
    parser::semantic_type *yylval = nullptr;
};

}

#endif
