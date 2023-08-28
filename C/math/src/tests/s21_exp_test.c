#include "../header.h"

START_TEST(test_s21_exp_00) {
  double x = 5.000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_01) {
  double x = -5.000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_02) {
  double x = 0.001000;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_03) {
  double x = -0.501000;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_04) {
  double x = DBL_MAX;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(test_s21_exp_05) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_06) {
  double x = 55.5235254;
  ck_assert_double_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_07) {
  double x = s21_NAN;
  ck_assert_ldouble_nan(s21_exp(x));
  ck_assert_ldouble_nan(exp(x));
}
END_TEST

START_TEST(test_s21_exp_08) {
  double x = s21_INF;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(test_s21_exp_09) {
  double x = -s21_INF;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_10) {
  double x = 0.000001;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_11) {
  double x = -0.000001;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_12) {
  double x = -0.000007;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_13) {
  double x = 0.000017;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_14) {
  double x = 0.000007;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_15) {
  double x = -25.535;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_16) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(s21_expClassic) {
  double x = 3;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
}
END_TEST

START_TEST(s21_expBig) {
  double x = 20;
  long double a2 = expl(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_eq_tol(a2, b2, 0.001);
}
END_TEST

START_TEST(s21_expLow) {
  double x = -32.0;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
}
END_TEST

START_TEST(s21_expZero) {
  double x = 0;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
}
END_TEST

START_TEST(s21_expBelowzero) {
  double x = -2;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
}
END_TEST

START_TEST(s21_expNan) {
  double x = s21_NAN;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert_ldouble_nan(a2);
  ck_assert_ldouble_nan(b2);
}
END_TEST

START_TEST(s21_expInf) {
  double x = s21_INF;
  long double a2 = exp(x);
  long double b2 = s21_exp(x);
  ck_assert(a2 == b2);
}
END_TEST

START_TEST(test_s21_s_exp_00) {
  double x = +0;
  ck_assert_int_eq(s21_exp(x), 1);
  ck_assert_int_eq(exp(x), 1);
}
END_TEST

START_TEST(test_s21_s_exp_01) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), 1);
  ck_assert_int_eq(exp(x), 1);
}
END_TEST

START_TEST(test_s21_s_exp_02) {
  double x = -INFINITY;
  ck_assert_int_eq(s21_exp(x), +0);
  ck_assert_int_eq(exp(x), +0);
}
END_TEST

START_TEST(test_s21_s_exp_03) {
  double x = +INFINITY;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(test_s21_s_exp_04) {
  double x = -10000;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(test_s21_s_exp_05) {
  double x = -20;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

Suite *math_test(void) {
  Suite *s;
  TCase *tc_s21_exp_00, *tc_s21_exp_01, *tc_core, *tc_s21_exp_02;
  s = suite_create("Math s21_exp");
  tc_s21_exp_00 = tcase_create("Check s21_exp_01");
  tcase_add_test(tc_s21_exp_00, test_s21_exp_00);
  tcase_add_test(tc_s21_exp_00, test_s21_exp_01);
  tcase_add_test(tc_s21_exp_00, test_s21_exp_02);
  tcase_add_test(tc_s21_exp_00, test_s21_exp_03);
  tcase_add_test(tc_s21_exp_00, test_s21_exp_06);
  suite_add_tcase(s, tc_s21_exp_00);  // Рандомные обычные значения
  tc_s21_exp_01 = tcase_create("Check s21_exp_01");
  tcase_add_test(tc_s21_exp_01, test_s21_exp_04);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_05);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_07);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_08);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_09);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_10);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_11);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_12);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_13);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_14);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_15);
  tcase_add_test(tc_s21_exp_01, test_s21_exp_16);
  suite_add_tcase(s, tc_s21_exp_01);
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_expClassic);
  tcase_add_test(tc_core, s21_expBig);
  tcase_add_test(tc_core, s21_expLow);
  tcase_add_test(tc_core, s21_expZero);
  tcase_add_test(tc_core, s21_expBelowzero);
  tcase_add_test(tc_core, s21_expNan);
  tcase_add_test(tc_core, s21_expInf);
  suite_add_tcase(s, tc_core);
  tc_s21_exp_02 = tcase_create("Special Values");
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_00);
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_01);
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_02);
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_03);
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_04);
  tcase_add_test(tc_s21_exp_02, test_s21_s_exp_05);
  suite_add_tcase(s, tc_s21_exp_02);
  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = math_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
