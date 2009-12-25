## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

AM_CCASFLAGS = $(INCLUDES) 

SUBDIRS = $(EXTRA_SUBDIRS) \
	  .

SUBLIBS = $(EXTRA_SUBLIBS) \
	  $(NUCLEOS_MACH_LIB)

GENERAL_SOURCES =

NET_SOURCES =

DONT_COMPILE =

ADD_OBJS = $(NUCLEOS_MACH_LIB)

noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(GENERAL_SOURCES) $(NET_SOURCES)
lib_a_LIBADD = $(ADD_OBJS)
lib_a_DEPENDENCIES = $(ADD_OBJS)
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all: crt0.o

include $(srcdir)/../../../Makefile.shared

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
