#!/bin/sh
bison -y -d gpp_interpreter.y
flex gpp_interpreter.l
gcc -std=c99 -D_GNU_SOURCE=1 -D_POSIX_SOURCE=1 gpp_interpreter.c lex.yy.c y.tab.c -o gpp_interpreter.out -g -lm
