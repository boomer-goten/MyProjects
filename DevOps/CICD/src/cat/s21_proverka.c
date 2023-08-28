#include "s21_cat.h"

void s21_proverka(char *argument, int *flag) {
    char *pointer = argument + 1;
    int status = 0;
#if defined(__linux__)
    status = 1;
#endif
    if ((strcmp(argument, "--number-nonblank") == 0 || strcmp(argument, "--number") == 0 ||
         strcmp(argument, "--squeeze-blank") == 0) &&
        status == 1) {
    } else if (argument[0] == '-' && argument[1] != '-') {
        while (*pointer != '\0') {
#if defined(__linux__)
            if (*pointer == 'b' || *pointer == 'e' || *pointer == 'n' || *pointer == 's' || *pointer == 't' ||
                *pointer == 'E' || *pointer == 'T') {
#endif
#if defined(__APPLE__)
                if (*pointer == 'b' || *pointer == 'e' || *pointer == 'n' || *pointer == 's' ||
                    *pointer == 't') {
#endif
                    pointer++;
                } else {
                    *flag = 0;
                    exit(1);
                    break;
                }
            }
        }
        else {
            *flag = 0;
        }
    }
