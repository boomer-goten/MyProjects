#include "./s21_string.h"
// Добавляем в начало строки знак "+", если в первом элементе массива стоит "-"
// после передачи от функции float_to_string, то функция пропускается
// Если нет флага "+", но есть флаг " ", то для положительных чисел результат на выходе не меняется
char *s21_do_plus(char *dest, config *pointer) {
    char temp[1024] = {'\0'};;
    int i = 0;
    if (dest[0] == '-') {
    } else if (pointer->space == 1 && pointer->plus == 0) {
        temp[i] = ' ';
        temp[i+1] = '\0';
        s21_strcat(temp, dest);
        s21_strcpy(dest, temp);
    } else {
        temp[i] = '+';
        temp[i+1] = '\0';
        s21_strcat(temp, dest);
        s21_strcpy(dest, temp);
    }
    return dest;
}
