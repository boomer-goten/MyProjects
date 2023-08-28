#include "./s21_string.h"
#include <math.h>

/* Вспомогательная функция для спринтф, 
 * которая конвертирует дробное число в строку
 * в соответствии с правилами округления до заданной точности n 
 * и записывает строку по указателю str и
 * добавляет '\0' в конец строки
 * Возвращает указатель на ту же строку
 */ 

char *s21_float_to_string(char *str, double float_var, int n) {
    // конвертируем целую и дробную часть отдельно
    char *temp  = {'\0'};
    temp = str;
    long long int left_part = 0;
    long long int right_part = 0;
    int sign = 0;  // -1 when negative, 1 when positive float_var
    config cfg;  // для s21_int_to_string()
    s21_initialization(&cfg);
    cfg.length_h = 0;
    cfg.length_l = 1;
    // обработка отрицательного числа
    if (float_var < 0 || (1.0 / float_var == -INFINITY)) {
        sign = -1;
        *temp = '-';
        temp += 1;
    } else {
        sign = 1;
    }
    float_var *= sign;  // модуль числа float_var
    left_part = (long long int)float_var;
    if (n == 0 && (((long int)(float_var * 10)) % 10 >= 5)) {
        left_part += 1;
    }
    long long int i = 1;
    // добавляем точку в строку, если точность отлична от 0
    if (n > 0) {
        float_var -= left_part;
        // цикл преобразования дробной части в string
        long long int k = 0;
        for (; k < n; i *= 10, k++) {
        }
        right_part = float_var * i;
        // процесс округления
        if (k == n && ((long int)(float_var * i * 10)) % 10 >= 5) {
            right_part += 1;
        }
        if ((right_part / (i-1)) >= 1) {
            left_part += 1;
            right_part = right_part - i;
        }
    }
    // добавляем целую часть в строку
    s21_int_to_string(temp, left_part, &cfg);
    temp = temp + s21_strlen(temp);
    if (n > 0) {
        *temp = '.';
        temp += 1;
        i = i/10;
        while (((right_part / i) == 0) && (i > 1)) {
            *temp = '0';
            temp++;
            i = i/10;
        }
        // добавляем дробную часть в строку
        s21_int_to_string(temp, right_part, &cfg);
        temp += n;
    }
    *temp = '\0';
    return str;
}
