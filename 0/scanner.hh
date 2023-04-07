
#ifndef OASI_SCANNER_HH
#define OASI_SCANNER_HH


#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include <oas-intel-parser-A+.hh>
//#include <oas-intel-A+.tab.h>
//#include <location.hh>

class Scanner : public yyFlexLexer
{
public:
    Scanner(std::istream *in);

    using FlexLexer::yylex;
    int yylex(yy::parser::semantic_type * const lval, yy::parser::location_type *loc);

private:
    yy::parser::semantic_type *yylval = nullptr;
};


#endif
