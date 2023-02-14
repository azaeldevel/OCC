
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" 
	

noinst_PROGRAMS = develop_lexer_c90


octetos_cc_includedir = $(includedir)/octetos/cc
octetos_cc_include_HEADERS = Buffer.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-cc.pc



develop_lexer_c90_SOURCES = develop-lexer-c90.cc
develop_lexer_c90_LDADD = 
develop_lexer_c90_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true -I/home/azael/develop/octetos