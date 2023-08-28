#include "s21_grep.h"

void s21_pars(char *argument, config *pointer) {
    char *arg = argument + 1;
    while (*arg != '\0') {
        if (*arg == 'e') {
            pointer->e = 1;
        } else if (*arg == 'i') {
            pointer->i = 1;
        } else if (*arg == 'v') {
            pointer->v = 1;
        } else if (*arg == 'c') {
            pointer->c = 1;
        } else if (*arg == 'l') {
            pointer->l = 1;
        } else if (*arg == 'n') {
            pointer->n = 1;
        } else if (*arg == 'h') {
            pointer->h = 1;
        } else if (*arg == 's') {
            pointer->s = 1;
        } else if (*arg == 'f') {
            pointer->f = 1;
        } else if (*arg == 'o') {
            pointer->o = 1;
        }
        arg++;
    }
}
