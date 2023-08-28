#include "./s21_string.h"

int s21_strcmp(const char *s1, const char *s2) {
    int result = 0;
    unsigned char* str1 = (unsigned char*)s1;
    unsigned char* str2 = (unsigned char*)s2;
    while (!(result = *str1 - *str2) && *str2) {
        str1 +=1;
        str2 +=1;
    }
    return result;
}
