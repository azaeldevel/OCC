
#ifndef OCTETOS_CC_TRAY_HH
#define OCTETOS_CC_TRAY_HH


namespace oct::cc
{

struct Tray
{
	enum class Arch
	{
		None,
		x86,		
	};
	enum class Format
	{
		None,
		Raw,
	};
	
	unsigned char word_size;
	Arch arch;
	Format format;
};

}


#endif