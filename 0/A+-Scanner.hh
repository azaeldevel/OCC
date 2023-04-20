
#ifndef OCTETOT_CC_V0_AII_SCANNER
#define OCTETOT_CC_V0_AII_SCANNER

#if ! defined(yyFlexLexerOnce)
    #include <FlexLexer.h>
#endif
#include <A+/oas-intel-parser.hh>

namespace oct::cc::v0::AII
{

class Scanner : public yyFlexLexer
{
public:
    Scanner(std::ifstream *in,core_here::Block&);
    ~Scanner();

    using FlexLexer::yylex;
    int yylex(parser::semantic_type * const lval, parser::location_type *loc);

private:
    parser::semantic_type *yylval = nullptr;
    core_here::Block& block;
};

}

#endif
