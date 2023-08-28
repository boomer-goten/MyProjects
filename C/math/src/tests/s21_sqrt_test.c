#include "../header.h"

START_TEST(test_s21_sqrt_00) {
    double x = 1.000000;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_01) {
    double x = 0.0400;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_02) {
    double x = DBL_MAX;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_03) {
    double x = 0.0;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_04) {
    double x = -578.000000;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_05) {
    double x = s21_NAN;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_06) {
    double x = s21_INF;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_07) {
    double x = 596834.4358305;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_sqrt_00, *tc_s21_sqrt_01;
    s = suite_create("Math s21_sqrt");
    tc_s21_sqrt_00 = tcase_create("Check s21_sqrt_00");
    tcase_add_test(tc_s21_sqrt_00, test_s21_sqrt_00);
    tcase_add_test(tc_s21_sqrt_00, test_s21_sqrt_01);
    tcase_add_test(tc_s21_sqrt_00, test_s21_sqrt_07);
    suite_add_tcase(s, tc_s21_sqrt_00);  // Рандомные обычные значения
    tc_s21_sqrt_01 = tcase_create("Check s21_sqrt_01");
    tcase_add_test(tc_s21_sqrt_01, test_s21_sqrt_02);
    tcase_add_test(tc_s21_sqrt_01, test_s21_sqrt_03);
    tcase_add_test(tc_s21_sqrt_01, test_s21_sqrt_04);
    tcase_add_test(tc_s21_sqrt_01, test_s21_sqrt_05);
    tcase_add_test(tc_s21_sqrt_01, test_s21_sqrt_06);
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
