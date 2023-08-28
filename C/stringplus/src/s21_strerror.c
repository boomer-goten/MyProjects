/*Функция получает на вход номер ошибки, возращает указатель на строку.
 *Наша задача определить на какой ОС сидит пользователь и в соответствии с ОС вывести сообщение,
 cоответствующее этой ошибке. Определять ОС нужно между MacOS и Linux.
 *Нужно создать директивы, определяющие ОС
 *Обьявить макросы(как я понял есть define c массивами) на массивы ошибок
 */
#include "./s21_string.h"

char *s21_strerror(int errnum) {
    char *string;
    static char *p[] = ERRORS;
    #if defined(__APPLE__) && defined(__MACH__)
    int max = 106;
    static char error[40] = "Unknown error: ";
    #else
    int max = 133;
    static char error[40] = "Unknown error ";
    #endif
    if (errnum > max || errnum < 0) {
        int flag = 0;
        if (errnum < 0) {
            flag = 1;
        }
        errnum = abs(errnum);
        char error_name[] = "0123456789-";
        // static char *temp_mass;
        // char *temp_cat;
        char numb_error[10];
        int tmp_errnum;
        int count = 0;
        do {
            tmp_errnum = errnum;
            errnum = errnum / 10;
            tmp_errnum = tmp_errnum % 10;
            for (int z = count; z >= 0; z--) {
                numb_error[z+1] = numb_error[z];
            }
            numb_error[0] = error_name[tmp_errnum];
            count++;
        } while (errnum);
        if (flag == 1) {
            for (int q = count; q >= 0; q--) {
                numb_error[q+1] = numb_error[q];
            }
            numb_error[0] = error_name[10];
            count++;
        }
        numb_error[count] = '\0';
        string = s21_strcat(error, numb_error);
        // string = s21_strcpy(temp_mass, temp_cat);
    } else {
        string = p[errnum];
    }
    return string;
}
