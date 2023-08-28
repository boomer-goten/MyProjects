#include "s21_string.h"
/*Возвращает новую строку, в которой указанная строка (str) вставлена 
 *в указанную позицию (start_index) в данной строке (src). 
 *В случае какой-либо ошибки следует вернуть значение NULL
 */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    void *pointer = s21_NULL;
    if (src && str && start_index <= s21_strlen(src)) {
        static char *copy = {'\0'};
        s21_size_t d = s21_strlen(str) + s21_strlen(src);
        copy = (char *)malloc(sizeof(char)*(d + 10));
        s21_size_t i = 0;
        if (copy) {
            s21_size_t j = 0;
            s21_size_t g = 0;
            while (i <= d) {
                if (i >= start_index && i < start_index + s21_strlen(str)) {
                    copy[i] = str[j];
                    j++;
                } else if (i <= start_index || i >= start_index + s21_strlen(str)) {
                    copy[i] = src[g];
                    g++;
                }
                i++;
            }
            copy[j + g - 1] = '\0';
        }
        pointer = (void *)copy;
    }
    return pointer;
}
