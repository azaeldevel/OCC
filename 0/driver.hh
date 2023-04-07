
#ifndef DRIVER_HH
#define DRIVER_HH
#include <string>
#include <oas-intel-parser-A+.hh>
//#include <oas-intel-A+.tab.h>

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <location.hh>
//#include "scanner.hh"

class Driver
{
public:
  Driver () = default;

  int parse(const std::list<std::filesystem::path>& sources);

  // The token's location used by the scanner.
  yy::location location;

private:

};


#endif
