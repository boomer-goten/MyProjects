#include "./s21_string.h"

/* Функция s21_strtok:
 * 
 * Функция библиотеки C char *strtok(char *str, const char *delim) разбивает 
 * строку str на серию токенов, используя разделитель delim.
 * 
 * str — содержимое этой строки изменяется и разбивается на более мелкие строки (токены).
 * delim — это строка C, содержащая разделители. Они могут варьироваться от одного 
 * вызова к другому.
 * Эта функция возвращает указатель на первый токен, найденный в строке. Нулевой указатель
 * возвращается, если не осталось токенов для извлечения.
 */

char *s21_strtok(char *str, const char *delim) {
    static char *p_past = s21_NULL;
    char *end;
    if (str == s21_NULL &&  p_past == s21_NULL) {
    } else {
        if (str == s21_NULL) {
            str = p_past;
        }
        if (*str == '\0') {
            p_past = str;
            str = s21_NULL;
        } else {
            str += s21_strspn(str, delim);
            if (*str == '\0') {
                p_past = str;
                str = s21_NULL;
            } else {
                end = str + s21_strcspn(str, delim);
                if (*end == '\0') {
                    p_past = end;
                } else {
                    *end = '\0';
                    p_past = end +1;
                }
            }
        }
    }
    return str;
}
