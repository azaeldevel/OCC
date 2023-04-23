

statement_list :
    statement_instruction
	{
		//std::cout << "statement_list : statement\n";
		$$ = $1;
	}
	|
	statement_list statement_instruction
	{
        static AI_here::nodes::statement *statement_prev = NULL;

		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;

