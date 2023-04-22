%{
	#include <##NAME####SUCCESSOR_ORNAMENT##.hh>
	#include <##NAME####SUCCESSOR_ORNAMENT##-Scanner.hh>
	#include <##NAME####SUCCESSOR_ORNAMENT##/oas-intel-parser.hh>

	namespace AI_here = oct::cc::v0::AI;
	namespace ##NAME####SUCCESSOR_DINASTI##_here = oct::cc::v0::##NAME####SUCCESSOR_DINASTI##;
	namespace core_here = oct::core::v3;

    #undef  YY_DECL
    #define YY_DECL int ##NAME####SUCCESSOR_DINASTI##_here::Scanner::yylex( parser::semantic_type * const lval, parser::location_type *loc)

    /* typedef to make the returns for the tokens shorter */
    using token = ##NAME####SUCCESSOR_DINASTI##_here::parser::token;

    /* define yyterminate as this instead of NULL */
    //#define yyterminate() return( token::END )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}
