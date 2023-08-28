#include "./s21_string.h"
// Выставляет ширину поля. Пропускает тело функции, если ширина поля
// меньше или равна ширине подаваемой строки
// Работает сразу с использованием флага "-". В случае, если он выставлен,
// идёт заполнение массива пробелами с конца.
// В случае, если он не выставлен, идет заполнение пробелами слева,
// за которыми приклеивается строка

char *s21_do_width(char *dest, config *pointer) {
    char temp[1024] = {'\0'};
    // temp[0] = '\0';
    int str_lenght = s21_strlen(dest);
    int i = 0;
    if (pointer->width <= str_lenght) {
    } else if (pointer->minus == 1) {
        for (i = str_lenght; i < pointer->width; i++) {
            dest[i] = ' ';
        }
        dest[i] = '\0';
      } else {
            if (pointer->zero == 0) {
                for (i = 0; i < (pointer->width - str_lenght); i++) {
                    temp[i] = ' ';
                }
            } else {
                for (i = 0; i < (pointer->width - str_lenght); i++) {
                    temp[i] = '0';
                }
            }
            temp[i] = '\0';
            s21_strcat(temp, dest);
            s21_strcpy(dest, temp);
        }
    return dest;
}
