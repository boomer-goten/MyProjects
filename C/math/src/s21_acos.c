#include "s21_math.h"

long double s21_acos(double x) {
    long double result = 0.0;
    if (x > 1 || x < -1) {
        result = s21_NAN;
    } else {
        double dva = 2;
        result = s21_pi/dva - s21_asin(x);
    }
    return result;
}
