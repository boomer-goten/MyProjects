#include "./s21_string.h"

// Функция strchr ищет первое вхождение символа, код которого указан в аргументе int c в строке,
// на которую указывает аргумент str.
// Возвращает указатель на искомый символ
// В случае отсутствия искомого символа, возвращает NULL

char *s21_strchr(const char *str, int c) {
    s21_size_t length = s21_strlen(str);
    char *res = s21_NULL;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            res = (char*)str+i;
            break;
        }
        i++;
        length--;
    }
    if (length == 0 && c == '\0') {
        res = (char*)str + i;
    }
    return res;
}

    // if (s21_strlen(str)) {
    //     while (str[i] != '\0') {
    //         if (str[i] == c) {
    //             res = (char*)str+i;
    //             break;
    //         }
    //     }
    //     if (str[i] == '\0' && c == '\0') {
    //         res = (char*)str;
    //     }
    // }
    // return res;
