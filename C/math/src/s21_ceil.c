/* Функция s21_ceil(double x) - Возвращает ближайшее целое число, не меньшее  
 * заданного значения.
 *
 * Пример: если x = 1.02, то функция вернет 2; если x = -1.02, то функция вернет -1.
 */

#include "s21_math.h"

long double s21_ceil(double x) {
    long long int y = 0;
    long double res = 0.0;

    if (__builtin_isnan(x)) {
        res = s21_NAN;
    } else if (__builtin_isinf(x)) {
        res = x;
    } else if (x > (long long int)DBL_MAX * 1.0) {
        res = DBL_MAX;
    } else {
        if (x > (long long int)x) {
            y = (long long int)x + 1;
        } else {
            y = (long long int)x;
        }
        res = (long double)y;
    }
    return res;
}
