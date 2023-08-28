#include "./s21_string.h"


/* Вспомогательная функция для спринтф, 
 * которая конвертирует целое число int_var в строку,
 * записывает полученную строку по указателю str и
 * добавляет '\0' в конец строки.
 * 
 * Кроме того функция приводит int_var к нужному типу: short int, int
 * в соотвтествии с флагами  спринтф (h, l), т.е. со значениями, 
 * хранимыми в структуре config: length_h и length_l;
 * 
 * Возвращает указатель на начало той же строки str
 */ 


char *s21_int_to_string(char *str, long long int int_var, config *pointer) {
    char *temp = {'\0'};
    temp = str;
    int ost = 1;
    char c = 0;
    int flag = 0;
    int positive = 1;  // 1 - positive int, -1 - negative
    // приведение к нужному типу: short int, int
    if (pointer->length_h == 1) {
        int_var = (short int)int_var;
        if (int_var < 0 && int_var == -32768) {
            int_var++;
            flag = 1;
        }
    } else if (pointer->length_l == 1) {
        int_var = (long int)int_var;
        if (int_var < 0 && int_var < -9223372036854775807) {
            int_var++;
            flag = 1;
        }
    } else {
        int_var = (int)int_var;
    }
    // берем модуль числа (знак добавляем в конце)
    if (int_var < 0) {
        positive = -1;
        int_var = -1 * int_var;
    }
    if (int_var == 0 && pointer->tochka == 1 && pointer->accuracy == 0) {
    } else if (int_var == 0) {
        *temp = '0';
        temp++;
    }
    for (int k = 0; int_var > 0; k++) {
        ost = int_var % 10;
        if (k == 0 && flag == 1) {
            ost++;
        }
        c = ost + '0';
        int_var = int_var / 10;
        *temp = c;
        temp++;
    }
    //  add sign at the end
    if (positive == -1) {
        *temp = '-';
        temp++;
    }
    *temp = '\0';
    // reverse string
    s21_reverse_str(str);
    return str;
}

/* Вспомогательная функция для спринтф, 
 * которая переворачивает строку (до '\0')
 */ 
void s21_reverse_str(char *str) {
    char c = 0;
    for (int i = 0, j = s21_strlen(str) - 1; i < j; j--, i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return;
}
