/* Driver for calc++.   -*- C++ -*-

   Copyright (C) 2005-2015, 2018-2021 Free Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

#ifndef DRIVER_HH
#define DRIVER_HH
#include <string>
#include <oas-intel-parser-A+.hh>

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include "location.hh"


class Scanner : public yyFlexLexer
{
public:
    Scanner(std::istream *in);

    using FlexLexer::yylex;
    int yylex(yy::parser::semantic_type * const lval, yy::parser::location_type *location);
};
// Conducting the whole scanning and parsing of Calc++.
class Driver
{
public:
  Driver ();

  int parse(const std::list<std::filesystem::path>& sources);

  // Whether to generate parser debug traces.
  bool trace_parsing;

  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  // Whether to generate scanner debug traces.
  bool trace_scanning;
  // The token's location used by the scanner.
  yy::location location;

private:

};
#endif // ! DRIVER_HH
