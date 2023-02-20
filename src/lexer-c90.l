
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


%%
"auto"				{printf("keyword auto\n");}
"break"				{printf("keyword break\n");}
"case"				{printf("keyword case\n");}
"char"				{printf("keyword char\n");}
"const"				{printf("keyword const\n");}
"continue"				{printf("keyword continue\n");}
"default"				{printf("keyword default\n");}
"do"				{printf("keyword do\n");}
"double"				{printf("keyword double\n");}
"else"				{printf("keyword enum\n");}
"enum"				{printf("keyword auto\n");}
"extern"				{printf("keyword extern\n");}
"float"				{printf("keyword float\n");}
"for"				{printf("keyword for\n");}
"goto"				{printf("keyword goto\n");}
"if"				{printf("keyword if\n");}
"int"				{printf("keyword int\n");}
"long"				{printf("keyword long\n");}
"register"				{printf("keyword register\n");}
"return"				{printf("keyword return\n");}
"short"				{printf("keyword short\n");}
"signed"				{printf("keyword signed\n");}
"sizeof"				{printf("keyword sizeof\n");}
"static"				{printf("keyword static\n");}
"struct"				{printf("keyword struct\n");}
"switch"				{printf("keyword switch\n");}
"typedef"				{printf("keyword typedef\n");}
"union"				{printf("keyword union\n");}
"unsigned"				{printf("keyword unsigned\n");}
"void"				{printf("keyword void\n");}
"volatil"				{printf("keyword volatil\n");}
"while"				{printf("keyword while\n");}

\n	++num_lines; ++num_chars;
.	++num_chars;

%%

int main()
{
  yylex();
  printf("# of lines = %d, # of chars = %d\n", num_lines, num_chars);
}
