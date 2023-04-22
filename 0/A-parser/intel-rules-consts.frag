
const_expression : CONSTANT_CHAR
	{
		//std::cout << "'" << (char)$1 << "' ";
		$$ = block.create<AI_here::nodes::initializer_literal<char>>();
		reinterpret_cast<AI_here::nodes::initializer_literal<char>*>($$)->value = $1;
		$$->data_type = AI_here::Tokens::CONSTANT_CHAR;
	}
	|
	CONSTANT_INTEGER_HEX
	{
		//std::cout << $1 << " ";
		$$ = block.create<AI_here::nodes::initializer_literal<long long>>();
		reinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;
		$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_HEX;
	}
	|
	CONSTANT_INTEGER_DEC
	{
		//std::cout << $1 << " ";
		$$ = block.create<AI_here::nodes::initializer_literal<long long>>();
		reinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;
		$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_DEC;
	}
	;
	
consts_integer : CONSTANT_INTEGER_HEX {$$ = $1;}| CONSTANT_INTEGER_DEC {$$ = $1;};


