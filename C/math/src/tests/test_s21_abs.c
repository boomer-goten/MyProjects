#include "../header.h"

START_TEST(test1_s21_abs) {
    int x = 5;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test2_s21_abs) {
    int x = -2147483647;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test3_s21_abs) {
    int x = INT_MIN;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test4_s21_abs) {
    int x = 0;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test5_s21_abs) {
    int x = INT_MAX;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(test6_s21_abs) {
    int x = -35.600000;
    ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST


Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_abs;
    s = suite_create("Math s21_abs");
    tc_s21_abs = tcase_create("Check s21_abs");
    tcase_add_test(tc_s21_abs, test1_s21_abs);
    tcase_add_test(tc_s21_abs, test2_s21_abs);
    tcase_add_test(tc_s21_abs, test3_s21_abs);
    tcase_add_test(tc_s21_abs, test4_s21_abs);
    tcase_add_test(tc_s21_abs, test5_s21_abs);
    tcase_add_test(tc_s21_abs, test6_s21_abs);
    suite_add_tcase(s, tc_s21_abs);
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

