#include "./s21_math.h"

long double s21_tan(double x) {
    long double res = -s21_INF;
    if (x == s21_INF || x == -s21_INF || x == s21_NAN) {
        res = -s21_NAN;
    } else if ((x == 90 * s21_pi / 180) || (x == -90 * s21_pi / 180)) {
        res = s21_INF;
    } else {
        res = s21_sin(x) / s21_cos(x);
    }
    return res;
}
