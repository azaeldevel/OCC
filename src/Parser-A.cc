#include <string.h>
#include <iostream>


#include "Parser.hh"


namespace oct::cc::A
{
	
Parser::Parser(Lexer& l,const Tray& t) : oct::cc::Parser(l,t)
{
		
}


bool Parser::next()
{
	if(not is_label())
	{

	}
	else if(not is_label())
	{

	}
	
	return true;
}


bool Parser::is_label()
{
	std::size_t b = begin, e = end;
	if(lexer->get_tokens()[b]->get_type() != Lexer::Token::Type::Unknow) return false;
	
	if(lexer->get_tokens()[e]->get_type() != Lexer::Token::Type::Symbol) return false;
	if(strcmp(lexer->get_tokens()[e]->get_text(),":") != 0) return false;
	
	lexer->get_tokens()[e]->up_type(Lexer::Token::Type::Identifier);

	//std::cout << "Label : " << lexer->get_tokens()[b]->get_text() << "\n";

	begin = e;
	end = ++e;
	
	return true;
}
bool Parser::is_inst()
{
	std::size_t b = begin, e = end;
	

	begin = e;
	end = ++e;
	
	return true;
}
}