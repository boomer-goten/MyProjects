/*
 Аналогична функции memcpy(), но массивы (области памяти) могут пересекаться,
 копирование при этом происходит корректно. Исходная строка тоже меняется
 
 Функция memmove копирует n байт из массива (области памяти),
 на который указывает аргумент src, в массив (область памяти),
 на который указывает аргумент dest.
 */

#include "./s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    if (dest < src) {
        s21_memcpy(dest, src, n);
    } else {
        for (s21_size_t i = n; i > 0; i--) {
            *((char*)dest + i - 1) = *((char*)src + i - 1);
        }
    }
    return (dest);
}
