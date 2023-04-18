
#ifndef OCTETOT_CC_V0_AII_SCANNER
#define OCTETOT_CC_V0_AII_SCANNER

#if ! defined(yyFlexLexerOnce)
    #include <FlexLexer.h>
#endif
#include <oas-intel-parser-A+.hh>

namespace oct::cc::v0::AII
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
