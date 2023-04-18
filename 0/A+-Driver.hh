
#ifndef DRIVER_HH
#define DRIVER_HH
#include <string>
#include <fstream>
#include <list>
#include <oas-intel-parser-A+.hh>
//#include <oas-intel-A+.tab.h>

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <location.hh>
//#include "scanner.hh"

namespace A_here = oct::cc::v0::A;
namespace oct::cc::v0::A
{

class Driver
{
public:
	Driver () = default;
	Driver (std::filesystem::path outpath);
	~Driver ();

	bool parse(const std::filesystem::path& sources);
	void print(std::ostream&)const;

	A_here::location loc;

private:
    bool parse(std::ifstream*);

private:
    struct Source
    {
        const std::filesystem::path* path;
        std::ifstream *stream;
    };
    std::list<Source> sources;
    std::filesystem::path outpath;
    std::ofstream outstream;
    const nodes::external_declaration* unit;

};
}

#endif
