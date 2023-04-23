
registers_8b :
    AL
    {
        $$ = token::token_kind_type::AL;
    }
    |
    AH
    {
        $$ = token::token_kind_type::AH;
    }
    |
    BL
    {
        $$ = token::token_kind_type::BL;
    }
    |
    BH
    {
        $$ = token::token_kind_type::BH;
    }
    |
    CL
    {
        $$ = token::token_kind_type::CL;
    }
    |
    CH
    {
        $$ = token::token_kind_type::CH;
    }
    |
    DL
    {
        $$ = token::token_kind_type::DL;
    }
    |
    DH
    {
        $$ = token::token_kind_type::DH;
    }
    ;



registers_16b :
    AX
	{
        $$ = token::token_kind_type::AX;
	}
	;

instruction_mov :
	MOV registers_8b consts_integer ';'
	{
		//std::cout << "mov register-8b integer\n";
        AI_here::nodes::move_8b_reg_byte* mv8 = block.create<AI_here::nodes::move_8b_reg_byte>();
        mv8->registe = (AI_here::Tokens)$2;
        mv8->byte = (unsigned char)$3;
        mv8->inst = AI_here::Tokens::MOV;
        mv8->is_instruction = true;
        mv8->type = 'I';
        $$ = mv8;
	}
	|
	MOV registers_8b CONSTANT_CHAR ';'
	{
		//std::cout << "mov register-8b char\n";
		AI_here::nodes::move_8b_reg_byte* mv8 = block.create<AI_here::nodes::move_8b_reg_byte>();
        mv8->registe = (AI_here::Tokens)$2;
        mv8->byte = (unsigned char)$3;
        mv8->inst = AI_here::Tokens::MOV;
        mv8->is_instruction = true;
        mv8->type = 'C';
        $$ = mv8;
	}
	|
	MOV registers_16b consts_integer
	{
		$$ = NULL;
	}
	;


instruction_int : INT consts_integer ';'
	{
		//std::cout << "int " << $2 << "\n";
		AI_here::nodes::instruction_int* serv = block.create<AI_here::nodes::instruction_int>();
		//if($2 > 127) yyerror("El parametro para la instruccion int dever ser un numero no mayo de de 128");
		serv->service = $2;
		serv->inst = AI_here::Tokens::INT;
		serv->is_instruction = true;
		$$ = serv;
	}
	;

instruction_label : IDENTIFIER ':'
	{
		$$ = block.create<AI_here::nodes::instruction_label>();
		$$->id = $1;
	}
	;

assembler_instruction :
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

