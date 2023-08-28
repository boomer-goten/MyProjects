#include "./s21_math.h"

long double s21_cos(double x) {
    long double res = 1.0;
    int i = 1;
    long double num = 1.0;
    int sign = 1;
    if (x == s21_INF || x == -s21_INF || x == s21_NAN) {
        res = -s21_NAN;
    } else if (x == 90 * s21_pi / 180 || x == -90 * s21_pi / 180) {
        res = 0.0;
    } else {
        while ((x > s21_pi || x < -s21_pi)) {
            if (x > s21_pi) {
                x -= 2 * s21_pi;
            } else if (x < -s21_pi) {
                x += 2 * s21_pi;
            }
        }
        while (s21_fabs(num) > 0.0000001) {
            sign = (-1) * sign;
            num *= x / i++;
            num *= x / i++;
            res += sign * num;
        }
    }
    return res;
}
