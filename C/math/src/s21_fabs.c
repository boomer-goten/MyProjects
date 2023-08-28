#include "./s21_math.h"

// вычисляет абсолютное значение вещественного числа

long double s21_fabs(double x) {
    long double z = x;
    if (z < 0)
        z = -1 * z;
    return z;
}
