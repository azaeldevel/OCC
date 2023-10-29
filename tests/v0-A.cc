
#include "v0.hh"

#include "A-Driver.hh"
#include <A/oas-intel-parser.hh>

namespace AI_here = oct::cc::v0::AI;


void v0_AI_developing()
{
    AI_here::nodes::constant_integer<AI_here::integer> const1;
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::min() << "\n";

    const1.set("12",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("0x0e",AI_here::nodes::constant_integer<AI_here::integer>::Format::hexadecimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("127",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("128",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::UNSIGNED);

    const1.set("255",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::UNSIGNED);


    const1.set("-12",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-127",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-128",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 8);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::CHAR);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("256",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-129",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size data : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    //std::cout << "max : "<< (AI_here::integer)std::numeric_limits<signed char>::max() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("257",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("300",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-257",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-300",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("32767",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("-32768",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    const1.set("35000",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::UNSIGNED);

    const1.set("65535",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 16);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::SHORT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::UNSIGNED);

    const1.set("65536",AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);
    //std::cout << "size : " << const1.get_data_size() << "\n";
    //std::cout << "value : " << const1.get_value() << "\n";
    CU_ASSERT(const1.get_data_size() == 32);
    CU_ASSERT(const1.get_type_data() == AI_here::Tokens::INT);
    CU_ASSERT(const1.get_type_singed() == AI_here::Tokens::SIGNED);

    oct::core::v3::Block block1;
    int* data1 = (int*)block1.create(sizeof(int));
    *data1 = 100;
    int* data2 = (int*)block1.create(sizeof(int));
    *data2 = 200;
    int* data3 = (int*)block1.create(sizeof(int));
    *data3 = 300;
    CU_ASSERT(*data1 == 100);
    CU_ASSERT(*data2 == 200);
    CU_ASSERT(*data3 == 300);

    //
    int* data4 = block1.create<int>();
    *data4 = 400;
    int* data5 = block1.create<int>();
    *data5 = 500;
    int* data6 = block1.create<int>();
    *data6 = 600;
    CU_ASSERT(*data4 == 400);
    CU_ASSERT(*data5 == 500);
    CU_ASSERT(*data6 == 600);

    int* array1 = block1.array<int>(6);
    array1[0] = 100;
    array1[1] = 200;
    array1[2] = 300;
    array1[3] = 400;
    array1[4] = 500;
    array1[5] = 600;
    CU_ASSERT(array1[0] == 100);
    CU_ASSERT(array1[1] == 200);
    CU_ASSERT(array1[2] == 300);
    CU_ASSERT(array1[3] == 400);
    CU_ASSERT(array1[4] == 500);
    CU_ASSERT(array1[5] == 600);




    ///>>>>>
    AI_here::nodes::Memory::Base* base1 = block1.create<AI_here::nodes::Memory::Base>();
    base1->base = AI_here::Tokens::BX;
    base1->index = AI_here::Tokens::DI;

    AI_here::nodes::Memory* mem1 = block1.create<AI_here::nodes::Memory>();
    mem1->set(base1);

    AI_here::nodes::constant_integer<AI_here::integer>* const_integer1 = block1.create<AI_here::nodes::constant_integer<AI_here::integer>>();
    const_integer1->set("0x5632",AI_here::nodes::constant_integer<AI_here::integer>::Format::hexadecimal,AI_here::Tokens::CONSTANT_INTEGER_HEX_16b);
    AI_here::nodes::Memory* mem2 = block1.create<AI_here::nodes::Memory>();
    mem2->set(base1,const_integer1);
}

void v0_AI_components()
{
}

void v0_AI_constans()
{
	CU_ASSERT((int)AI_here::Tokens::AUTO == (int)yytoken_kind_t::AUTO);
	//std::cout << "AUTO : " << (int)A_here::Tokens::AUTO << " " << (int)yytoken_kind_t::AUTO << "\n";

	CU_ASSERT((int)AI_here::Tokens::BREAK == (int)yytoken_kind_t::BREAK);
	//std::cout << "BREAK : " << (int)A_here::Tokens::BREAK << " " << (int)yytoken_kind_t::BREAK << "\n";

	CU_ASSERT((int)AI_here::Tokens::CASE == (int)yytoken_kind_t::CASE);
	//std::cout << "CASE : " << (int)A_here::Tokens::CASE << " " << (int)yytoken_kind_t::CASE << "\n";

	CU_ASSERT((int)AI_here::Tokens::CHAR == (int)yytoken_kind_t::CHAR);
	//std::cout << "CHAR : " << (int)A_here::Tokens::CHAR << " " << (int)yytoken_kind_t::CHAR << "\n";

	CU_ASSERT((int)AI_here::Tokens::CONST == (int)yytoken_kind_t::CONST);
	//std::cout << "CONST : " << (int)A_here::Tokens::CONST << " " << (int)yytoken_kind_t::CONST << "\n";

	CU_ASSERT((int)AI_here::Tokens::DO == (int)yytoken_kind_t::DO);
	//std::cout << "DO : " << (int)A_here::Tokens::DO << " " << (int)yytoken_kind_t::DO << "\n";

	CU_ASSERT((int)AI_here::Tokens::GOTO == (int)yytoken_kind_t::GOTO);
	//std::cout << "GOTO : " << (int)A_here::Tokens::GOTO << " " << (int)yytoken_kind_t::GOTO << "\n";

	CU_ASSERT((int)AI_here::Tokens::WHILE == (int)yytoken_kind_t::WHILE);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_INT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_INT);
	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_SHORT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_SHORT);
	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_LONG == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_LONG);

	CU_ASSERT((int)AI_here::Tokens::AAA == (int)yytoken_kind_t::AAA);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::INC == (int)yytoken_kind_t::INC);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::MOV == (int)yytoken_kind_t::MOV);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::AL == (int)yytoken_kind_t::AL);
	//std::cout << "AL : "  << (int)A_here::Tokens::AL << " " << (int)yytoken_kind_t::AL << "\n";

	CU_ASSERT((int)AI_here::Tokens::DL == (int)yytoken_kind_t::DL);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";

	CU_ASSERT((int)AI_here::Tokens::ES == (int)yytoken_kind_t::ES);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";

	CU_ASSERT((int)AI_here::Tokens::CS == (int)yytoken_kind_t::CS);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";

	CU_ASSERT((int)AI_here::Tokens::SS == (int)yytoken_kind_t::SS);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";

	CU_ASSERT((int)AI_here::Tokens::SS == (int)yytoken_kind_t::SS);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";



}





