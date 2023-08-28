#include "s21_grep.h"

int do_pattern(regex_t *str_pattern, char *argument, config *pointer) {
    int status = 1;
    if (pointer->i == 1) {
        if (regcomp(str_pattern, argument, REG_ICASE | REG_NEWLINE) == 0) {
            status = 0;
        }
    }
    if (pointer->i == 0) {
        if (regcomp(str_pattern, argument, REG_NEWLINE) == 0) {
            status = 0;
        }
    }
    return status;
}
