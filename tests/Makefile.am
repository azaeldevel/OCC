
check_PROGRAMS = v0
TESTS= $(check_PROGRAMS)


v0_LDFLAGS =
v0_LDADD = $(CUNIT_LIBS) $(OCTETOS_CC_LIBS) $(top_builddir)/core/liboctetos-cc.la
v0_CPPFLAGS = $(CUNIT_CFLAGS) -DOCTETOS_CC_V0 -I$(top_srcdir)/core
v0_SOURCES = main.cc v0.cc
		 