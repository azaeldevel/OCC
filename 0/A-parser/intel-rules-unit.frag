
translation_unit :
    declaration_list instruction_list
	{
        $$ = block.create<AI_here::nodes::translation_unit>();
        $$->declarations = $1;
        $$->instructions = $2;
        *unit = $$;
	}
	;

