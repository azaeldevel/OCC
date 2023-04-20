
#ifndef OCTETOT_CC_V0_AI_DRIVER_HH
#define OCTETOT_CC_V0_AI_DRIVER_HH
#include <string>
#include <fstream>
#include <list>
#include <A/oas-intel-parser.hh>
#include <A.hh>

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <A/location.hh>

namespace AI_here = oct::cc::v0::AI;
namespace oct::cc::v0::AI
{

class Driver
{
public:
	Driver ();
	Driver (core_here::Block& memory);
	~Driver ();

	bool parse(const std::filesystem::path& sources);
	void print(std::ostream&)const;
	bool generate(std::ostream&)const;

	//location loc;

private:
    bool parse(std::ifstream*);

private:
    struct Source
    {
        const std::filesystem::path* path;
        std::ifstream *stream;
    };
    std::list<Source> sources;
    const nodes::external_declaration* unit;
    core_here::Block* block;
    bool block_new;
};

}

#endif
