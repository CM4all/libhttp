AUTOMAKE_OPTIONS = foreign 1.11 dist-bzip2

AM_CPPFLAGS += -Iinclude

lib_LIBRARIES = src/libcm4all-http.a
src_libcm4all_http_a_SOURCES = \
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
