%%
%{
    /** Code executed at the beginning of yylex **/
	yylval = lval;// A handy shortcut to the location held by the driver.
	//yy::location& loc = driver.location;
	loc->step ();
%}


"auto"		return token::AUTO;
"byte"		return token::BYTE;
"const"		return token::CONST;
"char"		return token::CHAR;
"double"	return token::DOUBLE;
"float"		return token::FLOAT;
"register"	return token::REGISTER;
"short"		return token::SHORT;
"signed"	return token::SIGNED;
"sizeof"	return token::SIZEOF;
"static"	return token::STATIC;
"typedef"	return token::TYPEDEF;
"unsigned"	return token::UNSIGNED;
"void"		return token::VOID;
"volatil"	return token::VOLATIL;
"extern"	return token::EXTERN;
"goto"		return token::GOTO;
"int"		return token::INT;
"long"		return token::LONG;
"default"	return token::DEFAULT;

"mov"   return token::MOV;
"al"	return token::AL;
"ah"	return token::AH;


"break"		return token::BREAK;
"case"		return token::CASE;
"continue"	return token::CONTINUE;
"do"		return token::DO;
"else"		return token::ELSE;
"enum"		return token::ENUM;
"for"		return token::FOR;
"if"		return token::IF;
"return"	return token::RETURN;
"struct"	return token::STRUCT;
"switch"	return token::SWITCH;
"union"		return token::UNION;
"while"		return token::WHILE;



[[:space:]]			;

{IDENTIFIER}	{
                    //std::cout << "Line IDENTIFIER : " << yylineno << " : " << yytext << "\n";
                    ##NAME####SUCCESSOR##_here::nodes::identifier* identifer = block.create<##NAME####SUCCESSOR##_here::nodes::identifier>();
                    identifer->line = yylineno;
                    identifer->name = yytext;
                    yylval->build<##NAME####SUCCESSOR##_here::nodes::identifier*>(identifer);
                    return token::IDENTIFIER;
                }

{CONSTANT_INTEGER_HEX}  {
                            //std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
                            ##NAME####SUCCESSOR##_here::nodes::Integer* integer = block.create<##NAME####SUCCESSOR##_here::nodes::Integer>();
                            integer->format = 'H';
                            integer->number = std::stoll(yytext, nullptr, 16);
                            yylval->build<long long>(integer->number);
                            return token::CONSTANT_INTEGER_HEX;
                        }
{CONSTANT_INTEGER_DEC}  {
                            //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                            ##NAME####SUCCESSOR##_here::nodes::Integer* integer = block.create<##NAME####SUCCESSOR##_here::nodes::Integer>();
                            integer->format = 'D';
                            integer->number = std::stoll(yytext);
                            yylval->build<long long>(integer->number);
                            return token::CONSTANT_INTEGER_HEX;
                        }
{CONSTANT_CHAR} {
                    //std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
                    yylval->build<char>(yytext[1]);
                    return token::CONSTANT_CHAR;
                }
