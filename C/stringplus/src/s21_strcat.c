#include "./s21_string.h"

/*Функция добавляет cтроки src(откуда копируем) в конец строки dest(куда копируем)
 *Cтрока копируется полностью
 *На вход подается 2 строки src(строка источник) и dest(строка на которую воздействуем)
 */
char *s21_strcat(char *dest, const char *src) {
    char *temp = dest;
    int j = 0;
    int count = s21_strlen(dest);
    do {
        temp[count+j] = src[j];
        j++;
    } while (src[j] != '\0');
    temp[count+j] = '\0';
    return dest;
}
