
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" 
	


noinst_PROGRAMS = oas-intel-lexer-A+ oas-intel-parser-A+

octetos_cc_includedir = $(includedir)/octetos/cc
octetos_cc_include_HEADERS = 

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-cc.pc

develop_lexer_occ_c90_SOURCES = develop-lexer-occ-c90.cc
develop_lexer_occ_c90_LDADD = 
develop_lexer_occ_c90_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true -I/home/azael/develop/octetos

develop_lexer_flex_c90_SOURCES = lexer-c90.l
develop_lexer_flex_c90_LDADD = -lfl
develop_lexer_flex_c90_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true -I/home/azael/develop/octetos

occ_c90_SOURCES = main-occ-c90.cc
occ_c90_LDADD = 
occ_c90_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true -I/home/azael/develop/octetos

BUILT_SOURCES = oas-intel-A+-sources

oas-intel-sources : $(top_srcdir)/0/oas-intel-lexer.l $(top_srcdir)/0/oas-intel-parser.y
	bison -Wcounterexamples --header $(top_srcdir)/0/oas-intel-parser.y -o oas-intel-parser.cc
	flex -o oas-intel.lexer.cc --header=oas-intel.tab.h $(top_srcdir)/0/oas-intel-lexer.l

oas-intel-A+-sources : $(top_srcdir)/0/oas-intel-lexer-A+.l $(top_srcdir)/0/oas-intel-parser-A+.y
	bison --header $(top_srcdir)/0/oas-intel-parser-A+.y -o oas-intel-parser-A+.cc
	flex -o oas-intel-A+.lexer.cc --header=oas-intel-A+.tab.h $(top_srcdir)/0/oas-intel-lexer-A+.l

oas_intel_SOURCES = oas-main.cc A+.cc oas-intel-parser-A+.cc oas-intel-A+.lexer.cc
oas_intel_CFLAGS = -I$(top_srcdir)/0 -I$(top_builddir)/0 -I$(top_srcdir)/. -I/home/azael/develop/octetos/
oas_intel_CXXFLAGS = -I/home/azael/develop/octetos/

oas_intel_lexer_A__SOURCES = A+.cc A+-flex.cc oas-intel-A+.lexer.cc oas-intel-lexer-A+-main.cc 
oas_intel_lexer_A__CFLAGS = -I$(top_srcdir)/0 -I$(top_builddir)/0 -DLEXER_DEFAUL
oas_intel_lexer_A__CXXFLAGS = -I/home/azael/develop/octetos/ -DLEXER_DEFAUL

oas_intel_parser_A__SOURCES = A+.cc A+-occ.cc oas-intel-parser-A+-main.cc oas-intel-parser-A+.cc 
oas_intel_parser_A__CFLAGS = -I$(top_srcdir)/0 -I$(top_builddir)/0 -DLEXER_POSTERIOR
oas_intel_parser_A__CXXFLAGS = -I/home/azael/develop/octetos/ -DLEXER_POSTERIOR



 