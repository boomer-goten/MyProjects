#include "./s21_string.h"

// Устанавливает точность для подаваемой строки dest.
// Если точность меньше или равна длине подаваемого массива, то сразу происходит копирование
// в char *dest
char *s21_do_accuracy(char *dest, config *pointer) {
    char temp[1024] = {'\0'};
    int sign_exist = 0;
    int str_lenght = s21_strlen(dest);
    if (*dest == '+' || *dest == '-' || *dest == ' ') {
        *temp = *dest;
        sign_exist = 1;
        temp[1] = '\0';
        dest++;
    }
    if (pointer->accuracy <= str_lenght && pointer->type == 's') {
        dest[pointer->accuracy - sign_exist] = '\0';
    } else if (pointer->accuracy < str_lenght) {
    } else if (pointer->type != 's') {
        for (int i = sign_exist; i < (pointer->accuracy - str_lenght + sign_exist) + sign_exist; i++) {
            temp[i] = '0';
            if (i == (pointer->accuracy - str_lenght + sign_exist) - 1 + sign_exist)
                temp[i + 1] = '\0';
        }
        s21_strcat(temp, dest);
        s21_strcpy(dest - sign_exist, temp);
    }
    return dest;
}
