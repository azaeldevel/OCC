
#include "Parser.hh"


namespace oct::cc::A
{
	
Parser::Parser(Lexer& l,const Tray& t) : oct::cc::Parser(l,t)
{
}


bool Parser::run()
{
	do
	{
		if(stmt_inst())
		{
			
		}
	}
	while(true);

	return true;
}

bool Parser::stmt_inst()
{
	Lexer::Token* token = lexer->next();

	
}

bool Parser::stmt_label()
{
	Lexer::Token* token = lexer->next();

	
}

}