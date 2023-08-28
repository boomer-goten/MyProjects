#include "./s21_string.h"

/* Функция s21_strncmp:
 * 
 * Сравнивает не более n байтов str1 и str2
 * 
 * Функция побайтно сравнивает коды символов двух строк, на которые указывают аргументы функции. 
 * Сравнение прекращается если встретились отличающиеся символы. При этом возвращается
 * отрицательное или положительное число. 
 * Если были проверены n символов или обе сравниваемые строки закончились, и отличий не 
 * было, то сравнение прекращается и возвращается ноль.
 */
int s21_strncmp(const char* s1, const char* s2, s21_size_t n) {
    int result = 0;
    s21_size_t num = 0;
    unsigned char* str1 = (unsigned char*)s1;
    unsigned char* str2 = (unsigned char*)s2;
    if (n != 0) {
        while (!(result = *(unsigned char *)str1 - *(unsigned char *)str2) && *str2 && num != n-1) {
            str1++;
            str2++;
            num++;
        }
    } else {
        result = 0;
    }
    return result;
}
