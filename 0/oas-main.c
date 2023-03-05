
/*
 * Octetos Assembler
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <oas-intel.tab.h>
#include <oas-intel-parser.tab.h>


result
parse (void)
{
  yyscan_t scanner;
  yylex_init (&scanner);
  result res = {1, 0, 0};
  yyparse (scanner, &res);
  yylex_destroy (scanner);
  return res;
}

result
parse_string (const char *str)
{
  yyscan_t scanner;
  yylex_init (&scanner);
  YY_BUFFER_STATE buf = yy_scan_string (str ? str : "", scanner);
  result res = {0, 0, 0};
  yyparse (scanner, &res);
  yy_delete_buffer (buf, scanner);
  yylex_destroy (scanner);
  return res;
}

void
yyerror (yyscan_t scanner, result *res,
         const char *msg, ...)
{
  (void) scanner;
  va_list args;
  va_start (args, msg);
  vfprintf (stderr, msg, args);
  va_end (args);
  fputc ('\n', stderr);
  res->nerrs += 1;
}

int
main (void)
{
  // Possibly enable parser runtime debugging.
  yydebug = !!getenv ("YYDEBUG");
  result res = parse ();
  // Exit on failure if there were errors.
  return !!res.nerrs;
}

