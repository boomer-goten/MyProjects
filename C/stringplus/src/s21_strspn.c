#include "./s21_string.h"

// Фцнкция strspn определяет наибольшую длину начального участка строки,
// на которую указывает аргумент str, который содержит только символы строки sym.
// Если первый символ строки str не входит в строку sym, то возвращается 0

s21_size_t s21_strspn(const char *str, const char *sym) {
    s21_size_t res = 0;
    size_t length = s21_strlen(str);
    size_t i = 0;
    if (s21_strlen(str) == 0 || s21_strlen(sym) == 0) {
    } else {
        while (s21_strchr(sym, str[i]) && i != length) {
            res++;
            i++;
        }
    }
    return res;
}
