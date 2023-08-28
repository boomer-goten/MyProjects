#ifndef PROJECTS_C4_S21_MATH_2_SRC_S21_MATH_H_
// #ifndef SRC_S21_MATH_H_
#define PROJECTS_C4_S21_MATH_2_SRC_S21_MATH_H_
// #define SRC_S21_MATH_H_

#define s21_pi 3.14159265358979323846264338327950288
#define s21_MAL 0.000001
#define s21_NAN (0.0f / 0.0f)
#define s21_INF 1.0 / 0.0
#define s21_E 2.71828182845904523536028747135266250

#define s21_HUGE_VAL __builtin_huge_val()
#define s21_HUGE_VALF __builtin_huge_valf()
#define s21_HUGE_VALL __builtin_huge_vall()

#include <float.h>
#include <limits.h>
#include <stdio.h>

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_log(double x);
long double s21_ceil(double x);
long double s21_pow(double base, double exp);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_sqrt(double x);

// #endif  // SRC_S21_MATH_H_
#endif  // PROJECTS_C4_S21_MATH_2_SRC_S21_MATH_H_
