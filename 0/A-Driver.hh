
#ifndef OCTETOT_CC_V0_AI_DRIVER_HH
#define OCTETOT_CC_V0_AI_DRIVER_HH
#include <string>
#include <fstream>
#include <list>
#include <A/oas-intel-parser.hh>
#include <A.hh>

//#include <A/location.hh>

namespace AI_here = oct::cc::v0::AI;
namespace cc_here = oct::cc::v0;

namespace oct::cc::v0::AI
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

	//location loc;

private:

private:
    File file;
    const nodes::translation_unit* unit;
    core_here::Block* block;
    bool block_new;
};

}

#endif
