

statement_return  :
	RETURN ';'
	{
        $$ = block.create<A_here::nodes::return_statement>();
	}
    |
	RETURN consts_integer ';'
	{
        $$ = block.create<A_here::nodes::return_statement>();
	}
	;


compound_statement :
	'{' statement_list '}'
    {
		//std::cout << "compound_statement : '{' statement_list '}'\n";
        $$ = block.create<AII_here::nodes::compound_statement>();
        $$->statement_list = $2;
    }
    |
	'{' '}'
    {
        $$ = block.create<AII_here::nodes::compound_statement>();
        $$->statement_list = NULL;
    }
	;


function_implementation :
	declaration_specifiers declarator compound_statement
	{
        //std::cout << "function_implementation - 2\n";
        $$ = block.create<AII_here::nodes::function_implementation>();
        $$->body = $3;
        $$->declaration = $2;
        $$->specifiers = $1;
        //std::cout << $$->declaration->direct->id->name << "\n";
        //std::cout << "function_implementation - 2\n";
	}
	|
	declarator compound_statement
	{
        std::cout << "function_implementation - 3\n";
        $$ = block.create<AII_here::nodes::function_implementation>();
        $$->body = $2;
        $$->declaration = $1;
        $$->specifiers = NULL;
        //std::cout << "Function 3\n";
	}
	;


external_declaration :
	function_implementation
	{
		//std::cout << "external_declaration : function_implementation\n";
        //$1->print(std::cout);
        $$ = block.create<AII_here::nodes::external_declaration>();
        $$->func = $1;
        $$->decl = NULL;
	}
	|
	declaration ';'
	{
		//std::cout << "storage_class_specifier : declaration ';'\n";
		//std::cout << ";\n";
		//$1->print(std::cout);
        $$ = block.create<AII_here::nodes::external_declaration>();
        $$->func = NULL;
        $$->decl = $1;
	}
	;


translation_unit :
    external_declaration
	{
		//std::cout << "external_declaration\n";
		$$ = $1;
		*unit = $1;
	}
	|
	translation_unit external_declaration
	{
		//std::cout << "external_declaration translation_unit\n";
        static AII_here::nodes::external_declaration* statement_prev = NULL;
		$$ = $1;
		//$2->print(std::cout);
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;


