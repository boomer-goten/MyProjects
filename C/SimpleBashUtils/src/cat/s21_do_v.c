#include "s21_cat.h"

void s21_do_v(int sym) {
    char *p[] = SYMBOLS;
    #if defined (__linux__)
        int count = sym;
    #endif
    #if defined (__APPLE__)
        int count = (char)sym;
    #endif
    printf("%s", p[count]);
}

