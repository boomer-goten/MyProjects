#include "../header.h"

START_TEST(test_sin_1) {
    ck_assert_double_eq_tol(sqrt(pow(s21_sin(156), 2) + pow(s21_sin(156), 2)),
                            sqrt(pow(sin(156), 2) + pow(sin(156), 2)), 1e-06);
}
END_TEST

START_TEST(test_sin_2) {
    ck_assert_double_nan(s21_sin(NAN));
}
END_TEST

START_TEST(test_sin_3) {
    ck_assert_double_nan(s21_sin(INFINITY));
}
END_TEST

START_TEST(test_sin_4) {
    ck_assert_double_nan(s21_sin(-INFINITY));
}
END_TEST

START_TEST(test_sin_5) {
    ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-06);
}
END_TEST

START_TEST(test_sin_6) {
    ck_assert_double_eq_tol(s21_sin(s21_pi / 6), sin(s21_pi / 6), 1e-06);
}
END_TEST

START_TEST(test_sin_7) {
    ck_assert_double_eq_tol(s21_sin(s21_pi / 4), sin(s21_pi / 4), 1e-06);
}
END_TEST

START_TEST(test_sin_8) {
    ck_assert_double_eq_tol(s21_sin(s21_pi / 3), sin(s21_pi / 3), 1e-06);
}
END_TEST

START_TEST(test_sin_9) {
    ck_assert_double_eq_tol(s21_sin(s21_pi / 2), sin(s21_pi / 2), 1e-06);
}
END_TEST

START_TEST(test_sin_10) {
    ck_assert_double_eq_tol(s21_sin(3 * s21_pi / 2), sin(3 * s21_pi / 2), 1e-06);
}
END_TEST

START_TEST(test_sin_11) {
    ck_assert_double_eq_tol(s21_sin(2 * s21_pi), sin(2 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_sin_12) {
    ck_assert_double_eq_tol(s21_sin(-2 * s21_pi), sin(-2 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_sin_13) {
    ck_assert_double_eq_tol(s21_sin(-3 * s21_pi), sin(-3 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_sin_14) {
    ck_assert_double_eq_tol(s21_sin(-s21_pi), sin(-s21_pi), 1e-06);
}
END_TEST

START_TEST(test_sin_15) {
    ck_assert_double_eq_tol(s21_sin(90 * s21_pi / 180), sin(90 * s21_pi / 180), 1e-06);
}


Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_sin1;

    s = suite_create("s21_sin");

    tc_sin1 = tcase_create("sin");
    tcase_add_test(tc_sin1, test_sin_1);
    tcase_add_test(tc_sin1, test_sin_2);
    tcase_add_test(tc_sin1, test_sin_3);
    tcase_add_test(tc_sin1, test_sin_4);
    tcase_add_test(tc_sin1, test_sin_5);
    tcase_add_test(tc_sin1, test_sin_6);
    tcase_add_test(tc_sin1, test_sin_7);
    tcase_add_test(tc_sin1, test_sin_8);
    tcase_add_test(tc_sin1, test_sin_9);
    tcase_add_test(tc_sin1, test_sin_10);
    tcase_add_test(tc_sin1, test_sin_11);
    tcase_add_test(tc_sin1, test_sin_12);
    tcase_add_test(tc_sin1, test_sin_13);
    tcase_add_test(tc_sin1, test_sin_14);
    tcase_add_test(tc_sin1, test_sin_15);
    suite_add_tcase(s, tc_sin1);

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
