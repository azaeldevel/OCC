
#ifndef OCTETOS_CC_V0_AII_DRIVER_HH
#define OCTETOS_CC_V0_AII_DRIVER_HH
#include <string>
#include <fstream>
#include <list>
#include <A+.hh>
#include <A-Driver.hh>
//#include <A+/oas-intel-parser.hh>
//#include <A+/location.hh>

namespace AII_here = oct::cc::v0::AII;
namespace core_here = oct::core::v3;
namespace cc_here = oct::cc::v0;


namespace oct::cc::v0::AII
{

class Driver : public cc_here::Driver
{
public:
	Driver (AI_here::Tray<nodes::external_declaration>&);
	virtual ~Driver ();

	virtual bool parse(const std::filesystem::path& sources);
	virtual void print(std::ostream&)const;
	virtual void generate(std::ostream&)const;
	virtual const AI_here::nodes::translation_unit* translate();

private:

private:
    AI::File file;
    AI_here::Tray<nodes::external_declaration>* tray;
};
}

#endif
