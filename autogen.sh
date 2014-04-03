#!/bin/sh

set -e

rm -rf config.cache build
mkdir build
libtoolize --force
aclocal
automake --add-missing --foreign
autoconf
CFLAGS="-O0 -ggdb" ./configure \
        --prefix=/usr/local/stow/libcm4all-http \
    --enable-silent-rules \
        --enable-debug \
        "$@"
