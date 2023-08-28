/*
 Функция memcpy копирует n байт из массива (области памяти),
 на который указывает аргумент src, в массив (область памяти),
 на который указывает аргумент dest.
 
 Если массивы перекрываются, результат копирования будет не определен. (?)
 */

#include "./s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        if ((char*)src + i) {
            *((char*)dest + i) = *((char*)src + i);
        }
    }
    return (dest);
}
