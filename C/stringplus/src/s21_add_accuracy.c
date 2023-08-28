#include "./s21_string.h"

// #define MAX_CHARS 6 //Количество символов точности по умолчанию

/* Функция получает на вход указатель на элемент строки и возвращает количество символов которое занимает флаг
 * проверяет вхождение точности в строку format
 */

int s21_add_accuracy(config *pointer, const char *format) {
    int length = 0;
    int i = 0;
    // Если первый элемент это точка, то перебираем элементы массива и считаем цифры
    if (*format == '.') {
        // сдвигаем указатель на одну позицию и считаем числа
        pointer->tochka = 1;
        length += 1;
        format++;
        while (*format >= 48 && *format <= 57) {
            i = 10 * i + (*format - '0');
            length++;
            format++;
        }
    }
    if (length != 0) {
        pointer->accuracy = i;
    }
    return length;
}
