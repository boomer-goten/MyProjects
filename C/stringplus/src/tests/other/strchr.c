#include "../header.h"

int main() {
    char str[] = "john.smith@microsoft.com";
    int b = '\0';
    char *a1 = strchr(str, b);
    char *a2 = s21_strchr(str, b);
    printf("STRCHR = %p\n", a1);
    printf("s21_STRCHR = %p\n", a2);
    return 0;
}
