/* Функция s21_pow(double base, double exp).
 *
 */

#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double result = 0.0;
    if (__builtin_isnan(base) || __builtin_isnan(exp)) {
        if (base == 1.0) {
            result = 1.0;
        } else if (exp == 0) {
            result = 1.0;
        } else {
            result = s21_NAN;
        }
    } else if ((base == +0 || base == -0 || base == 0) &&
    exp > 0 && (exp == s21_ceil(exp) && s21_fmod(exp, 2) == 0)) {
        if (base == +0 || base == 0) {
            result = +0;
        }
        if (base == -0) {
            result = -0;
        }
    } else if (base == -1 && (exp == +s21_INF || exp == -s21_INF)) {
        result = 1.0;
    } else if (s21_fabs(base) < 1 && exp == -s21_INF) {
        result = +s21_INF;
    } else if (s21_fabs(base) > 1 && exp == -s21_INF) {
        result = +0;
    } else if (s21_fabs(base) < 1 && exp == +s21_INF) {
        result = +0;
    } else if (s21_fabs(base) > 1 && exp == +s21_INF) {
        result = +s21_INF;
    } else if (base == -s21_INF && exp < 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 1) {
        result = -0;
    } else if (base == -s21_INF && exp < 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 0) {
        result = +0;
    } else if (base == -s21_INF && exp > 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 1) {
        result = -s21_INF;
    } else if (base == -s21_INF && exp > 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 0) {
        result = +s21_INF;
    } else if (base == +s21_INF && exp < 0) {
        result = +0;
    } else if (base == +s21_INF && exp > 0) {
        result = +s21_INF;
    } else if (base == 0 && exp < 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 1) {
        result = +s21_HUGE_VAL;
    } else if (base == 0 && exp < 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 1) {
        result = -s21_HUGE_VAL;
    } else if ((base == 0 || base == -0) && exp < 0 && exp == s21_ceil(exp) && s21_fmod(exp, 2) == 0) {
        result = +s21_HUGE_VAL;
    } else if (exp == 0) {
        result = 1;
    } else {
        if (base < 0.0) {
            if (exp != s21_ceil(exp)) {
                result = s21_NAN;
            } else {
                base = base * -1;
                long double temp1 = exp * s21_log(base);
                if (temp1 < -DBL_MAX) {
                    return 0;
                }
                result = s21_exp(temp1);
                if (result == s21_HUGE_VAL && s21_log(base) != -s21_HUGE_VAL) {
                    return 0;
                }
                if (s21_fmod(exp, 2) != 0) {
                    result *= -1;
                }
            }
        } else {
            result = s21_exp(exp * s21_log(base));
            if (result == s21_HUGE_VAL && s21_log(base) != -s21_HUGE_VAL) {
                return 0;
            }
        }
        if (s21_fabs(result) > DBL_MAX) {
            result = s21_HUGE_VAL;
        } else if (s21_fabs(result) < DBL_MIN) {
            result = 0.0;
        }
    }
    return result;
}
