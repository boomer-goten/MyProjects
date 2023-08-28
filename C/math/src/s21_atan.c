#include "s21_math.h"

long double s21_atan(double x) {
    long double result = 0;
    double parametr__1 = 1;
    double parametr_1 = -1;
    double parametr_x = x;
    double parametr_2n_1 = 1;
    if (x == s21_INF) {
        result = 1.570796;
    } else if (x >= 0.944 || x <= -0.944) {
        if (x >= 0) {
            result += s21_atan((x-10.25)/(1+10.25*x)) + 1.4735431;
        } else {
            result += s21_atan((x-10.25)/(1+10.25*x)) + 1.4735431 - s21_pi;
        }
    } else {
        for (int i = 1; i < 85; i++) {
            result += ((parametr__1*parametr_x)/(parametr_2n_1));
            parametr__1 = s21_pow(parametr_1, i);
            parametr_x = parametr_x * x * x;
            parametr_2n_1 = 2*i+1;
        }
    }
    return (long double)result;
}
