#include "./s21_string.h"

/* Функция получает на вход указатель на элемент строки и возвращает количество символов которое занимает флаг
 * проверяет вхождение ширины в строку format
 */

int s21_add_width(config *pointer, const char *format) {
    int length = 0;
    int i = 0;
    // Сравниваем значения с 0 и 9 пока не наткнёмся на другой символ
    // В случае, если число составное, мы умножаем результат на 10 и продолжаем перебирать массив
    if (*format == 48) {
        pointer->zero = 1;
        length++;
    }
    while (*(format + length) >= 48 && *(format + length) <= 57) {
        i = 10*i+(*(format + length) - '0');
        length++;
    }
    if (length != 0) {
        pointer->width = i;
    }
    return length;
}
