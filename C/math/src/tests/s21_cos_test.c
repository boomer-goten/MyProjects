#include "../header.h"

START_TEST(test_cos_1) {
    ck_assert_double_nan(s21_cos(NAN));
}
END_TEST

START_TEST(test_cos_2) {
    ck_assert_double_nan(s21_cos(INFINITY));
}
END_TEST

START_TEST(test_cos_3) {
    ck_assert_double_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(test_cos_4) {
    ck_assert_double_eq(s21_cos(0.0), cos(0.0));
}
END_TEST

START_TEST(test_cos_5) {
    ck_assert_double_eq_tol(s21_cos(-1), cos(-1), 1e-06);
}
END_TEST

START_TEST(test_cos_6) {
    ck_assert_double_eq_tol(s21_cos(-1), cos(-1), 1e-06);
}
END_TEST

START_TEST(test_cos_7) {
    ck_assert_double_eq_tol(s21_cos(s21_pi / 4), cos(s21_pi / 4), 1e-06);
}
END_TEST

START_TEST(test_cos_8) {
    ck_assert_double_eq_tol(s21_cos(s21_pi / 6), cos(s21_pi / 6), 1e-06);
}
END_TEST

START_TEST(test_cos_9) {
    ck_assert_double_eq_tol(s21_cos(s21_pi / 3), cos(s21_pi / 3), 1e-06);
}
END_TEST

START_TEST(test_cos_10) {
    ck_assert_double_eq_tol(s21_cos(s21_pi / 2), cos(s21_pi / 2), 1e-06);
}
END_TEST

START_TEST(test_cos_11) {
    ck_assert_double_eq_tol(s21_cos(3 * s21_pi / 2), cos(3 * s21_pi / 2), 1e-06);
}
END_TEST

START_TEST(test_cos_12) {
    ck_assert_double_eq_tol(s21_cos(2 * s21_pi), cos(2 * s21_pi), 1e-06);
}
END_TEST

START_TEST(test_cos_13) {
    double deg90 = 90 * s21_pi / 180;
    ck_assert_double_eq(s21_cos(deg90), 0.0);
}
END_TEST

START_TEST(test_cos_14) {
    double deg90 = -90 * s21_pi / 180;
    ck_assert_double_eq(s21_cos(deg90), 0.0);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_cos1;

    s = suite_create("s21_cos");

    tc_cos1 = tcase_create("cos");
    tcase_add_test(tc_cos1, test_cos_1);
    tcase_add_test(tc_cos1, test_cos_2);
    tcase_add_test(tc_cos1, test_cos_3);
    tcase_add_test(tc_cos1, test_cos_4);
    tcase_add_test(tc_cos1, test_cos_5);
    tcase_add_test(tc_cos1, test_cos_6);
    tcase_add_test(tc_cos1, test_cos_7);
    tcase_add_test(tc_cos1, test_cos_8);
    tcase_add_test(tc_cos1, test_cos_9);
    tcase_add_test(tc_cos1, test_cos_10);
    tcase_add_test(tc_cos1, test_cos_11);
    tcase_add_test(tc_cos1, test_cos_12);
    tcase_add_test(tc_cos1, test_cos_13);
    tcase_add_test(tc_cos1, test_cos_14);
    suite_add_tcase(s, tc_cos1);

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
