
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" 
	


noinst_PROGRAMS = develop-lexer-flex-c90 develop-lexer-occ-c90 occ-c90

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


AM_YFLAGS = -d
BUILT_SOURCES = oas-intel

oas-intel : $(top_srcdir)/0/oas-intel.l $(top_srcdir)/0/oas-intel.y
	bison --header $(top_srcdir)/0/oas-intel.y -o oas-intel-parser.c
	flex --header=$(top_builddir)/0/oas-intel.tab.h -o oas-intel-lexer.c $(top_srcdir)/0/oas-intel.l
	$(CC) $(CFLAGS) -lfl oas-intel.tab.c oas-intel-lexer.c oas-intel-parser.c  
	

