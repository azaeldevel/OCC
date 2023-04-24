
#ifndef OCTETOS_CC_V0_AII_DRIVER_HH
#define OCTETOS_CC_V0_AII_DRIVER_HH
#include <string>
#include <fstream>
#include <list>
#include <A+.hh>
#include <A+/oas-intel-parser.hh>

//#include <A+/location.hh>

namespace AII_here = oct::cc::v0::AII;
namespace cc_here = oct::cc::v0;


namespace oct::cc::v0::AII
{

class Driver : public cc_here::Driver
{
public:
	Driver ();
	Driver (core_here::Block& memory);
	virtual ~Driver ();

	virtual bool parse(const std::filesystem::path& sources);
	virtual void print(std::ostream&)const;
	virtual void generate(std::ostream&)const;

	//A_here::location loc;

private:
    AI::File file;

private:
    const nodes::external_declaration* unit;
    core_here::Block* block;
    bool block_new;

};
}

#endif
