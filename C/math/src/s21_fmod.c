#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double result = s21_NAN;
    if (__builtin_isnan(x) != 0 || __builtin_isnan(y) != 0 || __builtin_isinf(x) != 0) {
    } else {
        if (__builtin_isinf(y) != 0) {
            result = x;
        } else if (s21_fabs(x) < s21_MAL) {
            result = 0;
        } else {
            long double z = x/y;
            result = (long double)z - (long int)z;
            result = result*y;
        }
    }
    if (s21_fabs(y) < s21_MAL && s21_fabs(y) != 0) {
        result = 0;
    }
    if (s21_fabs(y) == 0) {
        result = s21_NAN;
    }
    return result;
}
