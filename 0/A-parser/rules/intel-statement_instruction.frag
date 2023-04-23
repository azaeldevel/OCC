

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
    ;

