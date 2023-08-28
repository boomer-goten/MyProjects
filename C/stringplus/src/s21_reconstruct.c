#include "./s21_string.h"


/* Функция получает проинициализированную структуру и строку format со всеми спецификаторами 
 * с указателем на текущую позицию.
 * Функция, проходя строку до  спецификатора c, d, i, f, s, u, % или конца строки,
 * заполняет структуру и возвращает длину полстроки строки format со спец символами
 * функция получает на вход указатель на структуру, куда будет записываться результат, 
 * указатель на строку формат
 */ 


int s21_reconstruct(config *pointer, const char *format) {
    int len_shift = 0;
    int flag_sign = 0, flag_width = 0, flag_accuracy = 0, flag_length = 0, flag_type = 0;
    int len_accuracy = 0;
    // Перебираем массив, пока поле спецификатора type пустое
    while (*format != '\0' && pointer->type == '\0' && *format != '%') {
        // Если все флаги нулевые, ищем флаг "-" "+" " "
        if (flag_sign == 0 && flag_width == 0 &&
            flag_accuracy == 0 && flag_length == 0 && flag_type == 0) {
            len_shift += s21_add_flag(pointer, format);
            flag_sign = 1;
            format += s21_add_flag(pointer, format);
            // Если флаг знака 1, то мы начинаем смотреть следующий элемент строки format
            // и ищем в нём флаг ширины
        } else if (flag_sign == 1 && flag_width == 0 &&
                   flag_accuracy == 0 && flag_length == 0 && flag_type == 0) {
            len_shift += s21_add_width(pointer, format);
            flag_width = 1;
            format += s21_add_width(pointer, format);
            // Если предыдущие флаги выставлены, ищем флаг точности
        } else if (flag_sign == 1 && flag_width == 1 &&
                   flag_accuracy == 0 && flag_length == 0 && flag_type == 0) {
            len_accuracy = s21_add_accuracy(pointer, format);
            len_shift += len_accuracy;
            flag_accuracy = 1;
            format += s21_add_accuracy(pointer, format);
            // Если предыдущие флаги выставлены, ищем флаг модификаторов длины (h или l)
        } else if (flag_sign == 1 && flag_width == 1 &&
                   flag_accuracy == 1 && flag_length == 0 && flag_type == 0) {
            len_shift += s21_add_length(pointer, format);
            flag_length = 1;
            format += s21_add_length(pointer, format);
            // Если предыдущие флаги выставлены, ищем флаг спецификатора
        } else if (flag_sign == 1 && flag_width == 1 &&
                   flag_accuracy == 1 && flag_length == 1 && flag_type == 0) {
            len_shift += s21_add_type(pointer, format);
            flag_type = 1;
            format += s21_add_type(pointer, format);
            // если точность не задана, то по умолчанию = 6
            if (len_accuracy == 0 && pointer->type == 'f') {
                pointer->accuracy = 6;
            }
        } else {
            break;
        }
    }
    return len_shift;
}
