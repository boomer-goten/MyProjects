#include "./s21_string.h"

/*Находит первое вхождение всей строки needle (не включая завершающий нулевой символ),
 *которая появляется в строке haystack*/
char *s21_strstr(const char *haystack, const char *needle) {
    char *pnul = s21_NULL;
    s21_size_t count;
    for (s21_size_t z = 0; z < s21_strlen(haystack); z++) {
       count = 0;
       if (haystack[z] == needle[0]) {
           for (s21_size_t k = 0; k < s21_strlen(needle); k++) {
               if (haystack[z+k] == needle[k]) {
                   count++;
               }
           }
       }
       if (count == s21_strlen(needle)) {
           pnul = (char*)(haystack+z);
           break;
       }
    }
    return pnul;
}
