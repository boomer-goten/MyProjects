#include "./s21_math.h"

long double s21_sin(double x) {
    long double res = 0;
    if (x == s21_INF || x == -s21_INF || x == s21_NAN) {
        res = -s21_NAN;
    } else {
        while (x > s21_pi || x < -s21_pi) {
            if (x > s21_pi) {
                x -= 2 * s21_pi;
            } else if (x < -s21_pi) {
                x += 2 * s21_pi;
            }
        }
        res = x;
        int i = 1, sign = 1;
        long double num = x / i++;
        while (s21_fabs(num) > 0.0000001) {
            sign = (-1) * sign;
            num *= x / i++;
            num *= x / i++;
            res += sign * num;
        }
    }
    return res;
}
