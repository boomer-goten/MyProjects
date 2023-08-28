#include "s21_string.h"

/*Возвращает новую строку, в которой удаляются все начальные и конечные 
 *вхождения набора заданных символов (trim_chars) из данной строки (src). 
 *В случае какой-либо ошибки следует вернуть значение NULL
 */
/* В случае успеха возращается обрезанная строка
 * Если src=NULL возвращаем NULL
 * Если trim_chars указывает на ноль либо на пустой массив удаляются пробелы в начале и конце строки
 * Если символа нет в строке возращается полная копия строки src
 */

void *s21_trim(const char *src, const char *trim_chars) {
    void *pointer = s21_NULL;
    if (src) {
        static char *copy = {'\0'};
        const char *ukaz = {'\0'};
        int flag = 0;
        int i = 0;
        int fuck = 0;
        if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) {
            ukaz = " ";
        } else {
            ukaz = trim_chars;
        }
        if (src != s21_NULL) {
            int str = s21_strlen(src);
            int j = 1;
            copy = (char *)malloc(sizeof(char)*(str+1));
            if (copy) {
                if ((s21_strcmp(src, ukaz) == 0)) {
                    fuck = 1;
                }
                while (*src != '\0') {
                    char *temp;
                    temp = s21_strchr(ukaz, *src);
                    if ((temp == s21_NULL) || (flag == 1))  {
                        copy[i] = *src;
                        src++;
                        i++;
                        flag = 1;
                    } else if (flag == 0) {
                        src++;
                    }
                }
                while (j <= str) {
                    char *temp1;
                    temp1 = s21_strchr(ukaz, *(src-j));
                    if (temp1 == s21_NULL || fuck == 1)  {
                        break;
                    } else {
                        j++;
                    }
                }
                copy[i-j+1] = '\0';
            }
        }
        pointer = (void *)copy;
    }
    return pointer;
}
