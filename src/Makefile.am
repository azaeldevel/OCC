
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" 
	
lib_LTLIBRARIES = liboctetos-cc.la

noinst_PROGRAMS = devel

liboctetos_cc_la_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true
liboctetos_cc_la_LIBADD = $(OCTETOS_CC_LIBS)
liboctetos_cc_la_SOURCES = Exception.cc Buffer.cc AF.cc AF-A.cc base.cc tt.cc

octetos_cc_includedir = $(includedir)/octetos/cc
octetos_cc_include_HEADERS = Buffer.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-cc.pc

devel_SOURCES = main.cc AF.cc
devel_LDADD = $(OCTETOS_CC_LIBS) liboctetos-cc.la 
devel_CXXFLAGS = $(OCTETOS_CC_CFLGAS) -DOCTETOS_CC_DEGUB=true