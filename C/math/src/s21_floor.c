/* Функция s21_floor(double x) - возвращает ближайшее целое число, не больше  
 * заданного значения.
 *
 * Пример: если x = 1.92, то функция вернет 1; 
 *         если x = -1.02, то функция вернет -2.
 */

#include "s21_math.h"

long double s21_floor(double x) {
    long double res = 0.0;
    if (__builtin_isinf(x)) {
        res = x;
    } else if (x > (long long int)DBL_MAX * 1.0) {
        res = DBL_MAX;
    } else {
        double negative_x = -1 * x;
        res = -1.0 * s21_ceil(negative_x);
    }
    return res;
}
