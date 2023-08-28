#include "./s21_string.h"


/* Функция получает на вход строку и в зависимости от значения 
 * cfg.type переводит переменную из одного типа
 * в тип строки с параметрами указанными в структуре.
 * функция получает на вход указатель на строку,
 * куда будет записываться результат, указатель на структуру
 * и переменную типа va_list 
 * Функция возвращает указаетль на конец строки результата
 */ 


char *s21_memarg(char *str, va_list argptr, config *pointer) {
    long long int i_value = 0;
    long unsigned int u_value = 0;
    long double d_value = 0;
    int c_value = 0;
    char temp[1024] = {'\0'};
    s21_memset(temp, '\0', sizeof(temp));
    switch (pointer->type) {
        case 'i':
        case 'd':
            i_value = va_arg(argptr, long long int);
            s21_int_to_string(temp, i_value, pointer);
            if ((pointer->plus != 0) || (pointer->space != 0)) {
                s21_do_plus(temp, pointer);
            }
            if (pointer->accuracy != 0) {
                s21_do_accuracy(temp, pointer);
            }
            if (pointer->width != 0) {
                s21_do_width(temp, pointer);
            }
            s21_strcat(str, temp);
            str += s21_strlen(temp);
            break;
        case 'u':
            pointer->plus = 0;
            pointer->space = 0;
            u_value = va_arg(argptr, long long unsigned int);
            s21_unsigned_to_string(temp, u_value, pointer);
            if (pointer->accuracy != 0) {
                s21_do_accuracy(temp, pointer);
            }
            if (pointer->width != 0) {
                s21_do_width(temp, pointer);
            }
            s21_strcat(str, temp);
            str += s21_strlen(temp);
            break;
        case 'f':
            d_value = va_arg(argptr, double);
            s21_float_to_string(temp, d_value, pointer->accuracy);
            if ((pointer->plus != 0) || (pointer->space != 0)) {
                s21_do_plus(temp, pointer);
            }
            if (pointer->width != 0) {
                s21_do_width(temp, pointer);
            }
            s21_strcat(str, temp);
            str += s21_strlen(temp);
            break;
        case 's':
            if (pointer->length_l == 1) {
                wchar_t *arg = va_arg(argptr, wchar_t *);
                s21_memset(temp, '\0', sizeof(temp));
                wcstombs(temp, arg, sizeof(temp));
                if (pointer->tochka != 0) {
                    s21_do_accuracy(temp, pointer);
                }
                if (pointer->width != 0) {
                    s21_do_width(temp, pointer);
                }
                s21_strcat(str, temp);
                str += s21_strlen(temp);
            } else {
                s21_strcpy(temp, va_arg(argptr, char *));
                if (pointer->tochka != 0) {
                    s21_do_accuracy(temp, pointer);
                }
                if (pointer->width != 0) {
                    s21_do_width(temp, pointer);
                }
                s21_strcat(str, temp);
                str += s21_strlen(temp);
            }
            break;
        case 'c':
            if (pointer->length_l == 1) {
                s21_memset(temp, '\0', 1024);
                wchar_t arg = va_arg(argptr, wchar_t);
                wcstombs(temp, &arg, sizeof(temp));
#if defined __APPLE__
                temp[1] = '\0';
#endif
                if (pointer->width != 0) {
                    if (arg == '\0') {
                        pointer->width--;
                    }
                    s21_do_width(temp, pointer);
                }
                s21_strcat(str, temp);
                str += s21_strlen(temp);
                if (arg == '\0')
                    str++;
                s21_memset(temp, '\0', sizeof(temp));
            } else {
                c_value = va_arg(argptr, int);
                temp[0] = c_value;
                temp[1] = '\0';
                if (pointer->width != 0) {
                    if (c_value == '\0') {
                        pointer->width--;
                    }
                    s21_do_width(temp, pointer);
                }
                s21_strcat(str, temp);
                str += s21_strlen(temp);
                if (c_value == '\0')
                    str++;
            }
            break;
        default:
            // делать отступ, даже если нет спецификатора
#if defined __APPLE__
            pointer->width--;
            s21_do_width(temp, pointer);
            s21_strcat(str, temp + 1);
            str += s21_strlen(temp + 1);
#endif
            {;}
    }
    return str;
}
