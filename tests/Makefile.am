

check_PROGRAMS = v0
TESTS= $(check_PROGRAMS)

BUILT_SOURCES = oas-intel-A+-sources

oas-intel-sources : $(top_srcdir)/0/oas-intel-lexer.l $(top_srcdir)/0/oas-intel-parser.y
	bison -Wcounterexamples --header $(top_srcdir)/0/oas-intel-parser.y -o oas-intel-parser.cc
	flex -o oas-intel.lexer.cc --header=oas-intel.tab.h $(top_srcdir)/0/oas-intel-lexer.l

oas-intel-A+-sources : $(top_srcdir)/0/oas-intel-lexer-A+.l $(top_srcdir)/0/oas-intel-parser-A+.y
	bison --header $(top_srcdir)/0/oas-intel-parser-A+.y -o oas-intel-parser-A+.cc
	flex -o oas-intel-A+.lexer.cc --header=oas-intel-A+.tab.h $(top_srcdir)/0/oas-intel-lexer-A+.l

v0_LDFLAGS =
v0_LDADD = $(CUNIT_LIBS) $(OCTETOS_CC_LIBS) 
v0_CXXFLAGS = $(CUNIT_CFLAGS) -DOCTETOS_CC_V0 -I$(top_srcdir)/src -I$(top_srcdir)/0 -I/home/azael/develop/octetos/  -DOCTETOS_CC_DEGUB=true
v0_SOURCES = main.cc v0.cc $(top_srcdir)/0/A+.cc $(top_srcdir)/0/A+-flex.cc oas-intel-A+.lexer.cc oas-intel-parser-A+.cc





