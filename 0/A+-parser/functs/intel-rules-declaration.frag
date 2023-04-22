
identifier_list : IDENTIFIER
	{
        $$ = NULL;
	}
	|
	identifier_list IDENTIFIER
	{
		$$ = NULL;
	}
	;


declarator :
	direct_declarator
	{
        //std::cout << "declarator : direct_declarator\n";
        $$ = block.create<AI_here::nodes::declarator>();
        $$->point = NULL;
        $$->direct = $1;
        //std::cout << "declarator 2\n";
	}
	;

direct_declarator : IDENTIFIER
	{
		//std::cout << "direct_declarator : IDENTIFIER\n";
		$$ = block.create<AI_here::nodes::direct_declarator>();
		$$->id = $1;
		$$->direct = NULL;
		//std::cout << $$->id->name << " ";
	}
	|
	'(' declarator ')'
	{
        $$ = NULL;
	}
	|
	direct_declarator '[' const_expression ']'
	{
        $$ = NULL;
	}
	|
	direct_declarator '['  ']'
	{
        $$ = $1;
	}
	|
	direct_declarator '(' identifier_list ')'
	{
        $$ = NULL;
		$$->identifier_list = NULL;
	}
	|
	direct_declarator '('  ')'
	{
		$$ = $1;
		$$->identifier_list = NULL;
	}
	;


initializer : const_expression
	{
		$$ = $1;
	}
	;



init_declarator_list : init_declarator
	{
		//std::cout << "init_declarator_list : init_declarator\n";
		$$ = $1;
	}
	|
	init_declarator_list ',' init_declarator
	{
        static AI_here::nodes::init_declarator* statement_prev = NULL;
		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $3;


		statement_prev = $3;
	}
	;
init_declarator : declarator
	{
		//std::cout << "init_declarator : declarator\n";
		$$ = block.create<AI_here::nodes::init_declarator>();
		$$->dec = $1;
		$$->value = NULL;
	}
	|
	declarator  initializer
	{
		//std::cout << "init_declarator : declarator '=' initializer\n";
		$$ = block.create<AI_here::nodes::init_declarator>();
		$$->dec = $1;
		$$->value = $2;
	}
	;


type_specifier :
	VOID
    {
		//std::cout << "type_specifier : VOID\n";
		//std::cout << "void ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::VOID;
    }
    |
    CHAR
    {
		//std::cout << "type_specifier : CHAR\n";
		//std::cout << "char ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::CHAR;
        //$$->next = NULL;
		//std::cout << "type_specifier\n";
    }
    |
    SHORT
    {
		//std::cout << "type_specifier : SHORT\n";
		//std::cout << "short ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::SHORT;
    }
    |
    INT
    {
		//std::cout << "type_specifier : INT\n";
		//std::cout << "int ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::INT;
    }
    |
    LONG
    {
		//std::cout << "type_specifier : INT\n";
		//std::cout << "int ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::LONG;
    }
    |
    FLOAT
    {
		//std::cout << "type_specifier : FLOAT\n";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::FLOAT;
    }
    |
    DOUBLE
    {
		//std::cout << "type_specifier : DOUBLE\n";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::DOUBLE;
    }
    |
    SIGNED
    {
		//std::cout << "type_specifier : SIGNED\n";
		//std::cout << "signed ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::SIGNED;
    }
    |
    UNSIGNED
    {
		//std::cout << "type_specifier : UNSIGNED\n";
		//std::cout << "unsigned ";
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::UNSIGNED;
    }
    |
    BYTE
    {
        $$ = block.create<AI_here::nodes::type_specifier>();
        $$->type = AI_here::Tokens::BYTE;
    }
    ;


declaration_specifiers :
	type_specifier
	{
		$$ = $1;
	}
	|
    declaration_specifiers type_specifier
	{
        static AI_here::nodes::type_specifier* statement_prev = NULL;
		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;


declaration :
	declaration_specifiers
	{
		//std::cout << "declaration : declaration_specifiers\n";
		$$ = block.create<AI_here::nodes::declaration>();
		$$->specifiers = $1;
		$$->list = NULL;
	}
	|
	declaration_specifiers init_declarator_list
	{
		//std::cout << "declaration : declaration_specifiers init_declarator_list\n";
		$$ = block.create<AI_here::nodes::declaration>();
		$$->specifiers = $1;
		$$->list = $2;
	}
	;


declaration_list :
    declaration ';'
    {
		$$ = $1;
    }
    |
    declaration_list declaration ';'
    {
        static AI_here::nodes::declaration* statement_prev = NULL;
		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
    }
    ;

