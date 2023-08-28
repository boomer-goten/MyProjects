#include "./s21_string.h"

/* Функция получает на вход указатель на элемент строки и возвращает 
 * количество символов которое занимает флаг */

int s21_add_flag(config *pointer, const char *format) {
    int length = 0;
    while (*format == '-' || *format == '+' || *format == ' ') {
        if (*format == '-') {
            pointer->minus = 1;
            format++;
            length++;
        } else if (*format == '+') {
            pointer->plus = 1;
            format++;
            length++;
        } else if (*format == ' ') {
            pointer->space = 1;
            format++;
            length++;
        }
    }
    return length;
}
