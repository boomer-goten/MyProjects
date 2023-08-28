#include "s21_grep.h"

void s21_prov(char *argument, int *flag) {
    char *pointer = argument + 1;
    if (argument[0] == '-') {
        while (*pointer != '\0') {
            if (*pointer == 'e' || *pointer == 'i' || *pointer == 'v' || *pointer == 'c' || *pointer == 'l' ||
                *pointer == 'n' || *pointer == 'h' || *pointer == 's' || *pointer == 'f' || *pointer == 'o') {
                pointer++;
            } else {
                fprintf(stderr, "неверный флаг\n");
                exit(1);
            }
        }
    } else {
        *flag = 0;
    }
}
