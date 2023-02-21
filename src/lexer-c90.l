
/* 
 * Sample Scanner2: 
 * Description: Count the number of characters and the number of lines 
 *              from standard input
 * Usage: (1) $ flex sample2.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> whatever you like
 *	      stdin> Ctrl-D
 * Questions: Is it ok if we do not indent the first line?
 *            What will happen if we remove the second rule?
 */

	int num_lines = 0, num_chars = 0;
DIGIT [0-9]
LETTER [a-zA-Z]
INT {DIGIT}+

ID [a-zA-Z_][a-zA-Z0-9_]*

%%
"auto"					{printf("Keyword auto\n");}
"break"					{printf("Keyword break\n");}
"case"					{printf("Keyword case\n");}
"char"					{printf("Keyword char\n");}
"const"					{printf("Keyword const\n");}
"continue"				{printf("Keyword continue\n");}
"default"				{printf("Keyword default\n");}
"do"					{printf("Keyword do\n");}
"double"				{printf("Keyword double\n");}
"else"					{printf("Keyword enum\n");}
"enum"					{printf("Keyword auto\n");}
"extern"				{printf("Keyword extern\n");}
"float"					{printf("Keyword float\n");}
"for"					{printf("Keyword for\n");}
"goto"					{printf("Keyword goto\n");}
"if"					{printf("Keyword if\n");}
"int"					{printf("Keyword int\n");}
"long"					{printf("Keyword long\n");}
"register"				{printf("Keyword register\n");}
"return"				{printf("Keyword return\n");}
"short"					{printf("Keyword short\n");}
"signed"				{printf("Keyword signed\n");}
"sizeof"				{printf("Keyword sizeof\n");}
"static"				{printf("Keyword static\n");}
"struct"				{printf("Keyword struct\n");}
"switch"				{printf("Keyword switch\n");}
"typedef"				{printf("Keyword typedef\n");}
"union"					{printf("Keyword union\n");}
"unsigned"				{printf("Keyword unsigned\n");}
"void"					{printf("Keyword void\n");}
"volatil"				{printf("Keyword volatil\n");}
"while"					{printf("Keyword while\n");}

{INT}					{printf("Entero %s\n",yytext);}
{ID}					{printf("Identificador %s\n",yytext);}

[!"#%'()*+,-./:;<=>?\[\\\]^_\{|\}~]						{printf("Simbolo %s\n",yytext);}

[.\n\t ]				;

%%

int main()
{
  yylex();
}
