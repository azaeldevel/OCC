#include <string.h>
#include <iostream>
#include <algorithm>

#include "Parser.hh"


namespace oct::cc::A
{
	
Parser::Parser(Lexer& l,const Tray& t) : oct::cc::Parser(l,t)
{
	fill_insts();
}


bool Parser::next()
{
	if(not is_label())
	{

	}
	else if(not is_inst())
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


Parser::inst_pair::inst_pair(const char* s) : inst(s), code(0)
{
}
Parser::inst_pair::inst_pair() : inst(NULL), code(0)
{
}
bool Parser::inst_pair::operator == (const inst_pair& e) 
{
	return strcmp(inst, e.inst) == 0;
}


bool Parser::is_insts(const char* str)
{
	inst_pair inst(str);
	auto it = std::find(insts.begin(), insts.end(), inst);
	return (it != insts.end());
}


bool Parser::cmp(const Parser::inst_pair& f, const Parser::inst_pair& s) 
{
	unsigned int i = 0;
	while(f.inst[i] == 0 or s.inst[i] == 0)
	{
		if(f.inst[i] < s.inst[i]) return true;
		i++;
	}

	return false;
}
void Parser::fill_insts()
{
	inst_pair inst;
	inst.inst = "mov";
	insts.push_back(inst);
	inst.inst = "add";
	insts.push_back(inst);
	inst.inst = "adc";
	insts.push_back(inst);
	
	insts.resize(3);
	
	std::sort(insts.begin(),insts.end(),cmp);
	
}
}