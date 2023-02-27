#!/bin/bash
CC=/usr/bin/x86_64-w64-mingw32-gcc
CXX=/usr/bin/x86_64-w64-mingw32-g++
CFLAGS=-I/usr/x86_64-w64-mingw32/include/
cp PDCurses_Makefile ../PDCurses/wincon/Makefile
cd ../PDCurses/wincon
make -f Makefile pdcurses.a