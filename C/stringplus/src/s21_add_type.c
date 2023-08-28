#include "./s21_string.h"

/* Функция получает на вход указатель на элемент строки и возвращает количество символов которое занимает флаг
 * Проверяет тип переменной
 */
int s21_add_type(config *pointer, const char *format) {
    int length = 0;
    if (*format == 'i' || *format == 'd' || *format == 'u' ||
        *format == 'c' || *format == 's' || *format == 'f') {
        pointer->type = *format;
        length++;
    }
    return length;
}
