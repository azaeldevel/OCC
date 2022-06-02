
#include "Parser.hh"


namespace oct::cc
{

Parser::Parser(Lexer& l,const Tray& t) : lexer(&l), tray(&t)
{
}

}