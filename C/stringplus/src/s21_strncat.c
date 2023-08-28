#include "./s21_string.h"

/*Функция добавляет n символов cтроки src(откуда копируем) в конец строки dest(куда копируем)
дописывает не более n начальных символов строки src (или всю src, если её длина меньше) в конец dest
 *На вход подается 2 строки src(строка источник) и dest(строка на которую воздействуем) и n(количество символов)
 */
/*SOS используются функция strlen стандартной библиотеки SOS*/
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *temp = dest;
    int z = 0;
    int i = s21_strlen(dest);
    int j = s21_strlen(src);
    if (n != 0) {
        do {
            temp[i+z] = src[z];
            z++;
        } while ((z != (int)n) && (z != j));
    }
    temp[i+z] = '\0';
    return dest;
}
