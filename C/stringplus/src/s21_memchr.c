/* Функция s21_memchr возвращает указатель на расположение символа c в str. Если 
 * символ c не будет обнаружен в первых n байтах str, возвращается NULL.
 */

#include "./s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char* s = (unsigned char*)str;
    unsigned char simbol = (unsigned char)c;
    if (str != s21_NULL) {
        for (; n != 0; n--) {
        if (*s == simbol)
            break;
        s += 1;
    }
    if (*s != simbol)
        s = s21_NULL;
    }
    return (void*)s;
}
