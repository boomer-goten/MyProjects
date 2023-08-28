#include "./s21_string.h"

/* Функция s21_memcmp:
 * 
 * Сравнивает первые n байтов str1 и str2.
 * 
 * str1 и str2 - указатели на блок памяти, n - количество сравниваемых байтов.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char* s1 = (unsigned char*)str1;
    const unsigned char* s2 = (unsigned char*)str2;
#if defined __APPLE__
    int res = 0;
    if (n != 0) {
        while (!(*s1 - *s2) && n--) {
            s1 += 1;
            s2 += 1;
        }
        res = *s1 - *s2;
    }
    return res;
#endif
#if defined __linux__
    while (n-- > 0) {
        if (*s1++ != *s2++)
            return s1[-1] < s2[-1] ? -1 : 1;
    }
    return 0;
#endif
}
