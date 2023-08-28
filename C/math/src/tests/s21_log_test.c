#include "../header.h"
START_TEST(test_log_1) { ck_assert_ldouble_infinite(s21_log(INFINITY)); }
END_TEST

START_TEST(test_log_2) { ck_assert_ldouble_nan(s21_log(-INFINITY)); }
END_TEST

START_TEST(test_log_3) { ck_assert_ldouble_nan(s21_log(s21_NAN)); }
END_TEST

START_TEST(test_log_4) { ck_assert_ldouble_nan(s21_log(-1)); }
END_TEST

START_TEST(test_log_5) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
}
END_TEST

START_TEST(test_log_6) {
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST

START_TEST(test_log_7) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(test_log_8) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6); }
END_TEST

START_TEST(test_log_9) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6);
}
END_TEST

START_TEST(test_log_10) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(test_log_11) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(test_log_13) {
  ck_assert_ldouble_eq_tol(s21_log(s21_pi / 3), log(s21_pi / 3), 1e-6);
}
END_TEST

START_TEST(test_log_14) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           1e-6);
}
END_TEST

START_TEST(test_log_15) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           1e-6);
}
END_TEST

START_TEST(test_log_16) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(test_log_17) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
}
END_TEST

START_TEST(test_log_18) {
  ck_assert_ldouble_nan(s21_log(-1264.000000004));
  ck_assert_ldouble_nan(log(-1264.000000004));
}
END_TEST

Suite *sprintf_test(void) {
  Suite *s;
  TCase *tc_log1;

  s = suite_create("s21_log");

  tc_log1 = tcase_create("log");
  tcase_add_test(tc_log1, test_log_1);
  tcase_add_test(tc_log1, test_log_2);
  tcase_add_test(tc_log1, test_log_3);
  tcase_add_test(tc_log1, test_log_4);
  tcase_add_test(tc_log1, test_log_5);
  tcase_add_test(tc_log1, test_log_6);
  tcase_add_test(tc_log1, test_log_7);
  tcase_add_test(tc_log1, test_log_8);
  tcase_add_test(tc_log1, test_log_9);
  tcase_add_test(tc_log1, test_log_10);
  tcase_add_test(tc_log1, test_log_11);
  tcase_add_test(tc_log1, test_log_13);
  tcase_add_test(tc_log1, test_log_14);
  tcase_add_test(tc_log1, test_log_15);
  tcase_add_test(tc_log1, test_log_16);
  tcase_add_test(tc_log1, test_log_17);
  tcase_add_test(tc_log1, test_log_18);
  suite_add_tcase(s, tc_log1);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = sprintf_test();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
