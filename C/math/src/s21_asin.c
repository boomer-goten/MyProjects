#include "s21_math.h"

long double s21_asin(double x) {
    long double result = 0.0;
    if (x > 1 || x < -1) {
        result = s21_NAN;
    } else {
        double parametr_2n = 1;
        double parametr_n = 1;
        double parametr_n_step = 1;
        double parametr_4 = 1;
        double parametr_x = x;
        double parametr_2n_1 = 1;
        result = 0;
        if (x >= 0.944 || x <= -0.944) {
            result = s21_pi/2-2*s21_asin(s21_sqrt((1-x)/2));
        } else {
            for (int i = 1; i < 87; i++) {
                result += ((parametr_2n)/(parametr_4*parametr_n_step*parametr_2n_1))*parametr_x;
                parametr_2n = parametr_2n*(2*i-1)*(2*i);
                parametr_4 = parametr_4*4;
                parametr_n = parametr_n*i;
                parametr_n_step = parametr_n*parametr_n;
                parametr_x = parametr_x * x * x;
                parametr_2n_1 = 2*i+1;
            }
        }
    }
    return (long double)result;
}
