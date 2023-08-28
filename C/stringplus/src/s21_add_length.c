#include "./s21_string.h"

/* Функция получает на вход указатель на элемент строки и возвращает количество символов которое занимает флаг
 * Проверяет длинну переменной
 */
int s21_add_length(config *pointer, const char *format) {
    int length = 0;
    if (*format == 'h') {
        pointer->length_h = 1;
        length++;
    } else if (*format == 'l') {
        pointer->length_l = 1;
        length++;
    }
    return length;
}
