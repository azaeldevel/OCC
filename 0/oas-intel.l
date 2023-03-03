

DIGIT [0-9]
LETTER [a-zA-Z]
INTEGER {DIGIT}+
LITERAL_CHAR 'LETTER'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"byte"			{printf("byte\n");}
"char"			{printf("char\n");}
"tiny"			{printf("tiny\n");}
"short"			{printf("short\n");}
"medium"		{printf("medium\n");}
"long"			{printf("long\n");}
"integer"		{printf("integer\n");}

"int"			{printf("int\n");}
"mov"			{printf("mov\n");}

{INTEGER}		{printf("Entero \"%s\"\n",yytext);}
{IDENTIFIER}		{printf("Identificador \"%s\"\n",yytext);}
{LITERAL_CHAR}		{printf("Literal char \"%s\"\n",yytext);}

[!"#%'()*+,-./:;<=>?\[\\\]^_\{|\}~]	{printf("Simbolo \"%s\"\n",yytext);}

[.\n\t ]				;

%%

int main()
{
  yylex();
}
