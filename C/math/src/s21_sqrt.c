/* Функция s21_sqrt(double x).
 * Вычисляет квадратный корень из аргумента x. При этом аргумент x задается числом с плавающей точкой
 * с двойной точностью (тип double: точность не менее 10-ти значащих цифр, разрядность - 64).
 */

#include "s21_math.h"

double _s21_max(double x) {
    double y = 0.0;
    if (x > 1.000000) {
        y = x;
    } else {
        y = 1.000000;
    }
    return y;
}

long double s21_sqrt(double x) {
    long double result = 0.0;
    if (x < 0.000000 || __builtin_isnan(x)) {
        result = s21_NAN;
    } else if (__builtin_isinf(x)) {
        result = s21_INF;
    } else {
        long double a = 0.0;
        long double b = _s21_max(x);
        long double c = (a + b) / 2;
        while (s21_fabs(c - a) > 1e-14) {
            if (c * c > x) {
                b = c;
            } else {
                a = c;
            }
            c = (a + b) / 2;
        }
        result = c;
    }
    return result;
}
