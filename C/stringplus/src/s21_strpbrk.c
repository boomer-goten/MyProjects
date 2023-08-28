#include "./s21_string.h"

// Функция strpbrk ищет первое вхождение в строке str1 одного из символов, входящих в строку str2
// В случае отсутствия совпадений, возвращает NULL
char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = s21_NULL;
    int i = 0;
    if (s21_strlen(str1) == 0 || s21_strlen(str2) == 0) {
    } else {
        while (s21_strrchr(str2, str1[i]) == 0) {
            i++;
        }
        if (str1[i] == '\0') {
        } else {
            res = (char*)str1+i;
        }
    }
    return (res != s21_NULL) ? res : 0;
}
