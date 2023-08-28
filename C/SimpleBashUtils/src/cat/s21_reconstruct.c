#include "s21_cat.h"

void s21_reconstruct(char *argument, config *pointer) {
    char *arg = argument+1;
    #if defined (__linux__)
        if (strcmp(argument, "--number-nonblank") == 0) {
            pointer->b = 1;
        } else if (strcmp(argument, "--number") == 0) {
            pointer->n = 1;
        } else if (strcmp(argument, "--squeeze-blank") == 0) {
            pointer->s = 1;
        }
    #endif
    while (*arg != '\0') {
        if (*arg == 'b') {
            pointer->b = 1;
        }
        if (*arg == 'e') {
            pointer->e = 1;
            pointer->v = 1;
        }
        if (*arg == 'n') {
            pointer->n = 1;
        }
        if (*arg == 's') {
            pointer->s = 1;
        }
        if (*arg == 't') {
            pointer->t = 1;
            pointer->v = 1;
        }
        #if defined (__linux__)
        if (*arg == 'E') {
            pointer->e = 1;
        }
        if (*arg == 'T') {
            pointer->t = 1;
        }
        #endif
        arg++;
    }
}

