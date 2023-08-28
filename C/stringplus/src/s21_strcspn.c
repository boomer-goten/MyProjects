#include "./s21_string.h"

/*Функция выполняет поиск первого вхождения в строку str1 любого из символов строки str2, 
 *и возвращает количество символов до найденного первого вхождения.
 */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t count = 0;
    while ((*str1) && (s21_strchr(str2, *str1) == 0)) {
        count++;
        str1++;
    }
    return count;
}
