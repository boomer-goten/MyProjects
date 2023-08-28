#include "./s21_string.h"

/*Функция получает указатель str типа void, число n(cколько нужно повторить) b количество символов типа int c,
 *Повторение происходит побайтово
 *начиная с указателя str
 */
/*SOS используются функция strlen стандартной библиотеки SOS*/
void *s21_memset(void *str, int c, s21_size_t n) {
    int i = 0;
    if (str) {
        char* p = (char*)str;
        int j = s21_strlen((char*)str);
        while ((n-- > 0)) {
            *(p+i) = c;
            i++;
            if ((n == 0) && (i >= j) && c != '\0') {
                *(p+i) = '\0';
            }
        }
    }
    return str;
}
