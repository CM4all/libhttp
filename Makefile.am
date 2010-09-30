AUTOMAKE_OPTIONS = foreign 1.10 dist-bzip2

AM_CPPFLAGS += -Iinclude

lib_LIBRARIES = src/libcm4all-was-simple.a
src_libcm4all_was_simple_a_SOURCES = \
	src/method.c \
	src/status.c \
	src/header.c

httpincludedir = $(includedir)/http
httpinclude_HEADERS = \
	include/http/method.h \
	include/http/status.h \
	include/http/header.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libcm4all-http.pc
