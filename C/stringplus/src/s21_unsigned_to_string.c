#include "./s21_string.h"

/* Вспомогательная функция для спринтф, 
 * которая конвертирует чило типа unsigned в строку
 * и записывает строку по указателю str и
 * добавляет '\0' в конец строки
 * Возвращает указатель на ту же строку
 */ 

char *s21_unsigned_to_string(char *str, long long unsigned unsigned_var, config *pointer) {
    char *temp = {'\0'};
    temp = str;
    int ost = 1;
    char c;
    // приведение к нужному типу: short int, int
    if (pointer->length_h == 1) {
        unsigned_var = (short unsigned)unsigned_var;
    } else if (pointer->length_l == 1) {
        unsigned_var = (long unsigned)unsigned_var;
    } else {
        unsigned_var = (unsigned)unsigned_var;
    }
    // берем модуль числа (знак добавляем в конце)
    if (unsigned_var == 0 && pointer->tochka == 1 && pointer->accuracy == 0) {
    } else if (unsigned_var == 0 && pointer->tochka == 0) {
        *temp = '0';
        temp++;
    }
    for (int k = 0; unsigned_var > 0; k++) {
        ost = unsigned_var % 10;
        c = ost + '0';
        unsigned_var = unsigned_var / 10;
        *temp = c;
        temp++;
    }
    //  add sign at the end
    *temp = '\0';
    // reverse string
    s21_reverse_str(str);
    return str;
}
