#include <string.h>

#include "Parser.hh"


namespace oct::cc::A
{
	
Parser::Parser(Lexer& l,const Tray& t) : oct::cc::Parser(l,t)
{
}


bool Parser::run()
{
	lexer->load();
	begin = 0;
	end = 1;
	
	stmts();
	
	return true;
}
void Parser::stmts()
{
	
}
void Parser::stmt_inst()
{
	std::size_t b = 0, e = 0;
		
}
void Parser::stmt_label()
{
	std::size_t b = begin, e = end;
	if(lexer->get_tokens()[b]->get_type() != Lexer::Token::Type::Unknow) return;
	
	if(lexer->get_tokens()[e]->get_type() != Lexer::Token::Type::Symbol) return;
	if(strcmp(lexer->get_tokens()[e]->get_text(),":") != 0) return;
	
	lexer->get_tokens()[e - 1]->up_type(Lexer::Token::Type::Identifier);
}

}