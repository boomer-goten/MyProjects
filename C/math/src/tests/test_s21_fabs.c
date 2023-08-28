#include "../header.h"

START_TEST(test1_s21_fabs) {
    double x = 0;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test2_s21_fabs) {
    double x = -2147483647;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test3_s21_fabs) {
    double x = DBL_MIN;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test4_s21_fabs) {
    double x = -DBL_MAX;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test5_s21_fabs) {
    double x = DBL_MAX;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(test6_s21_fabs) {
    double x = -35.600000;
    ck_assert_double_eq(s21_fabs(x), fabs(x));
}
END_TEST


Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_fabs;
    s = suite_create("Math s21_fabs");
    tc_s21_fabs = tcase_create("Check s21_fabs");
    tcase_add_test(tc_s21_fabs, test1_s21_fabs);
    tcase_add_test(tc_s21_fabs, test2_s21_fabs);
    tcase_add_test(tc_s21_fabs, test3_s21_fabs);
    tcase_add_test(tc_s21_fabs, test4_s21_fabs);
    tcase_add_test(tc_s21_fabs, test5_s21_fabs);
    tcase_add_test(tc_s21_fabs, test6_s21_fabs);
    suite_add_tcase(s, tc_s21_fabs);
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
