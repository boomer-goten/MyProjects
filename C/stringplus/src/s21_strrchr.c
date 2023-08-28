#include "./s21_string.h"

// Функция strrchr ищет первое вхождение символа, код которого указан в аргументе int c в строке,
// на которую указывает аргумент str. Поиск идёт с конца строки
// Возвращает указатель на искомый символ
// В случае отсутствия искомого символа, возвращает NULL

char *s21_strrchr(const char *str, int ch) {
    int i = s21_strlen(str);
    char *res = s21_NULL;
    if (i != 0) {
        while (i >= 0) {
            if (str[i] == ch) {
                res = (char*)str+i;
                break;
            }
            i--;
        }
    }
    if (str[0] == '\0' && ch == '\0') {
        res = (char*)str + i;
    }
    return res;
}
