
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


statement_instruction :
    instruction_mov
    {
        $$ = $1;
    }
    |
    instruction_int
    {
        $$ = $1;
    }
    |
    instruction_label
    {
        $$ = $1;
    }
    |
    statement_return
    {
        $$ = $1;
    }
    ;

