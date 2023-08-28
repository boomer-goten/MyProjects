#include "../header.h"

START_TEST(test_tan_1) {
    ck_assert_double_nan(s21_tan(INFINITY));
}
END_TEST

START_TEST(test_tan_2) {
    ck_assert_double_nan(s21_tan(-INFINITY));
}
END_TEST

START_TEST(test_tan_3) {
    ck_assert_double_nan(s21_tan(NAN));
}
END_TEST

START_TEST(test_tan_4) {
    ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-06);
}
END_TEST

START_TEST(test_tan_5) {
    ck_assert_double_eq_tol(s21_tan(s21_pi / 6), tan(s21_pi / 6), 1e-06);
}
END_TEST

START_TEST(test_tan_6) {
    ck_assert_double_eq_tol(s21_tan(s21_pi / 4), tan(s21_pi / 4), 1e-06);
}
END_TEST

START_TEST(test_tan_7) {
    ck_assert_double_eq_tol(s21_tan(s21_pi / 3), tan(s21_pi / 3), 1e-06);
}
END_TEST

START_TEST(test_tan_8) {
    ck_assert_double_eq_tol(s21_tan(2 * s21_pi), tan(2 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_tan_9) {
    ck_assert_double_eq_tol(s21_tan(-2 * s21_pi), tan(-2 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_tan_10) {
    ck_assert_double_eq_tol(s21_tan(-3 * s21_pi), tan(-3 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_tan_11) {
    ck_assert_double_eq_tol(s21_tan(-s21_pi), tan(-s21_pi), 1e-06);
}
END_TEST

START_TEST(test_tan_12) {
    ck_assert_double_eq_tol(s21_tan(90), tan(90), 1e-06);
}

START_TEST(test_tan_13) {
    long double deg90 = 90 * s21_pi / 180;
    ck_assert_ldouble_infinite(s21_tan(deg90));
}


Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_tan1;

    s = suite_create("s21_tan");

    tc_tan1 = tcase_create("tan");
    tcase_add_test(tc_tan1, test_tan_1);
    tcase_add_test(tc_tan1, test_tan_2);
    tcase_add_test(tc_tan1, test_tan_3);
    tcase_add_test(tc_tan1, test_tan_4);
    tcase_add_test(tc_tan1, test_tan_5);
    tcase_add_test(tc_tan1, test_tan_6);
    tcase_add_test(tc_tan1, test_tan_7);
    tcase_add_test(tc_tan1, test_tan_8);
    tcase_add_test(tc_tan1, test_tan_9);
    tcase_add_test(tc_tan1, test_tan_10);
    tcase_add_test(tc_tan1, test_tan_11);
    tcase_add_test(tc_tan1, test_tan_12);
    tcase_add_test(tc_tan1, test_tan_13);
    suite_add_tcase(s, tc_tan1);

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
