#include "./s21_string.h"

s21_size_t s21_strlen(const char *a) {
    s21_size_t i = 0;
    while (a[i] != '\0') {
        i++;
    }
    return ((i > 0) ? (i) : 0);
}
