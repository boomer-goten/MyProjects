#include "../header.h"

START_TEST(test_s21_floor_00) {
    double x = 5.000000;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_01) {
    double x = 5.500056;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_02) {
    double x = -5.000000;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_03) {
    double x = -5.000535;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_04) {
    for (int i = 0; i < 100000; i++) {
        double x = 5.000001;
        ck_assert_ldouble_eq(s21_floor(x), floor(x));
        x += 68386.004111;
    }
}
END_TEST

START_TEST(test_s21_floor_05) {
    for (int i = 0; i < 100000; i++) {
        double x = -5.000001;
        ck_assert_ldouble_eq(s21_floor(x), floor(x));
        x -= 55784.003111;
    }
}
END_TEST

START_TEST(test_s21_floor_06) {
    double x = 0.000000;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_07) {
    double x = s21_NAN;
    ck_assert_ldouble_nan(s21_floor(x));
    ck_assert_ldouble_nan(floor(x));
}
END_TEST

START_TEST(test_s21_floor_08) {
    double x = s21_INF;
    ck_assert_ldouble_infinite(s21_floor(x));
}
END_TEST

START_TEST(test_s21_floor_09) {
    double x = -s21_INF;
    ck_assert_ldouble_infinite(s21_floor(x));
    ck_assert_ldouble_infinite(floor(x));
}
END_TEST

START_TEST(test_s21_floor_10) {
    double x = DBL_MAX;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_11) {
    double x = DBL_MIN;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_12) {
    double x = DBL_MAX - 0.010000;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_13) {
    double x = floor(DBL_MAX);
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_14) {
    double x = floor(DBL_MIN);
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_s21_floor_15) {
    double x = DBL_MIN + 0.010000;
    ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_floor_01, *tc_s21_floor_02, *tc_s21_floor_03;
    s = suite_create("Math s21_floor");
    tc_s21_floor_01 = tcase_create("Check s21_floor_01");
    tcase_add_test(tc_s21_floor_01, test_s21_floor_00);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_01);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_02);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_03);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_04);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_05);
    tcase_add_test(tc_s21_floor_01, test_s21_floor_06);
    suite_add_tcase(s, tc_s21_floor_01);  // Рандомные обычные значения
    tc_s21_floor_02 = tcase_create("Check s21_floor_02");
    tcase_add_test(tc_s21_floor_02, test_s21_floor_07);
    tcase_add_test(tc_s21_floor_02, test_s21_floor_08);
    tcase_add_test(tc_s21_floor_02, test_s21_floor_09);
    suite_add_tcase(s, tc_s21_floor_02);
    tc_s21_floor_03 = tcase_create("Check s21_floor_03");
    tcase_add_test(tc_s21_floor_03, test_s21_floor_10);
    tcase_add_test(tc_s21_floor_03, test_s21_floor_11);
    tcase_add_test(tc_s21_floor_03, test_s21_floor_12);
    tcase_add_test(tc_s21_floor_03, test_s21_floor_13);
    tcase_add_test(tc_s21_floor_03, test_s21_floor_14);
    tcase_add_test(tc_s21_floor_03, test_s21_floor_15);
    suite_add_tcase(s, tc_s21_floor_03);
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
