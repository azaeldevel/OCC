
%type <AI_here::nodes::direct_declarator*> direct_declarator
%type <AI_here::nodes::declarator*> declarator
%type <AI_here::nodes::type_specifier*> type_specifier
%type <AI_here::nodes::type_specifier*> declaration_specifiers
%type <AI_here::nodes::identifier*> identifier_list
%type <AI_here::nodes::const_expression*> const_expression
%type <AI_here::nodes::init_declarator*> init_declarator
%type <AI_here::nodes::init_declarator*> init_declarator_list
%type <AI_here::nodes::initializer*> initializer
%type <AI_here::nodes::declaration*> declaration
%type <AI_here::nodes::statement*> statement_list
%type <AI_here::nodes::assembler_instruction*> assembler_instruction
%type <AI_here::nodes::instruction_label*> instruction_label
%type <AI_here::nodes::instruction_mov*> instruction_mov
%type <AI_here::nodes::instruction_int*> instruction_int
%type <AI_here::nodes::declaration*> declaration_list
