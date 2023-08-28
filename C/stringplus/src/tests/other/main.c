#include "../header.h"

int main() {
    char str1[] = "///";
    char str2[] = "///";
    char delim[] = "/";
    char *p = s21_strtok(str1, delim);
    char *d = strtok(str2, delim);
    if (p != s21_NULL && d != s21_NULL) {
        printf("IN 9.:%s\n", p);
        printf("IN 9.:%s\n", d);
    }
    p = s21_strtok(s21_NULL, delim);
    d = strtok(s21_NULL, delim);
    printf("IN 15.:%s\n", p);
    printf("IN 15.:%s\n", d);
    if (p && d) {
        printf("IN 18.:%s\n", p);
        printf("IN 18.:%s\n", d);
    }
    return 0;
}
