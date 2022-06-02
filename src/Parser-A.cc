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
	end = 0;
	do
	{
		if(stmt_inst())
		{
			
		}
		else if(stmt_label())
		{
			
		}
	}
	while(true);

	return true;
}

bool Parser::stmt_inst()
{
	std::size_t b = 0, e = 0;

	
}

bool Parser::stmt_label()
{
	std::size_t b = begin, e = end;
	if(lexer->get_tokens()[b]->get_type() != Lexer::Token::Type::Unknow) return false;

	b++;
	if(lexer->get_tokens()[b]->get_type() != Lexer::Token::Type::Symbol) return false;
	if(strcmp(lexer->get_tokens()[b]->get_text(),":") != 0) return false;

	lexer->get_tokens()[b - 1]->up_type(Lexer::Token::Type::Identifier);

	return true;
}

}