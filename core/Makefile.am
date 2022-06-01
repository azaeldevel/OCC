
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"
	
lib_LTLIBRARIES = liboctetos-cc.la

liboctetos_cc_la_CXXFLAGS = $(OCTETOS_CC_CFLGAS)  -DOCTETOS_CC_FULL_CHECK
liboctetos_cc_la_LIBADD = $(OCTETOS_CC_LIBS)
liboctetos_cc_la_SOURCES = Exception.cc Buffer.cc Lexer.cc

octetos_cc_includedir = $(includedir)/octetos/cc
octetos_cc_include_HEADERS = Buffer.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-cc.pc