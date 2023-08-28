#include "../header.h"

START_TEST(test_s21_pow_00) {
    double x = 1.000000;
    double y = 1.000000;
    for (int i = 0; i < 2; i++) {
        ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
        x *= 1.500000;
        y *= 1.500000;
    }
}
END_TEST

START_TEST(test_s21_pow_01) {
    double x = 5.000000;
    double y = 1.000000;
    for (int i = 0; i < 2; i++) {
        ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
        x *= 1.500000;
        y += 1;
    }
}
END_TEST

START_TEST(test_s21_pow_02) {
    double x = -5.0;
    double y = 1.100000;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_08) {
    double x = -5.0;
    double y = 1.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_09) {
    double x = -5.0;
    double y = 2.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_10) {
    double x = -5.0;
    double y = -2.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_03) {
    double x = 5.000000;
    double y = 0.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_04) {
    double x = 0.000000;
    double y = 0.000000;
    ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_05) {
    double x = 0.000000;
    double y = -5.000000;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_06) {
    double x = s21_NAN;
    double y = -5.000000;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_07) {
    double x = 5.0;
    double y = s21_NAN;
    ck_assert_ldouble_nan(s21_pow(x, y));
    ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_11) {
    double x = -2;
    double y = 2.5;
    ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_13) {
    double x = 10;
    double y = -5.8;
    ck_assert_ldouble_le_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_14) {
    double x = -18.9;
    double y = 7;
    ck_assert_ldouble_le_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_15) {
    double x = -1000;
    double y = -10000;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_16) {
    double x = s21_NAN;
    double y = 5.5;
    ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_17) {
    double x = 4.6;
    double y = s21_NAN;
    ck_assert_ldouble_nan(s21_pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_18) {
    double x = s21_NAN;
    double y = 0;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_19) {
    double x = 1;
    double y = s21_NAN;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_20) {
    double x = +0;
    double y = 13;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_21) {
    double x = -0;
    double y = 15;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_22) {
    double x = 0;
    double y = 11;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_23) {
    double x = -1;
    double y = +s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_24) {
    double x = -1;
    double y = -s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_25) {
    double x = 0.5;
    double y = -s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_26) {
    double x = -5;
    double y = +s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_27) {
    double x = 100.5;
    double y = -s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_28) {
    double x = 0.6;
    double y = +s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_29) {
    double x = 55.7;
    double y = +s21_INF;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_30) {
    double x = -s21_INF;
    double y = -11;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_31) {
    double x = -s21_INF;
    double y = -12;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_32) {
    double x = -s21_INF;
    double y = 13;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_33) {
    double x = -s21_INF;
    double y = 14;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_34) {
    double x = +s21_INF;
    double y = -5.543;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_35) {
    double x = +s21_INF;
    double y = 13.95;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_36) {
    double x = 0;
    double y = -11;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_37) {
    double x = 0;
    double y = -13;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_38) {
    double x = +0;
    double y = -14;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(test_s21_pow_39) {
    double x = -0;
    double y = -16;
    ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

Suite * math_test(void) {
    Suite *s;
    TCase *tc_s21_pow_00, *tc_s21_pow_01;
    s = suite_create("Math s21_pow");
    tc_s21_pow_00 = tcase_create("Check s21_pow_00");
    tcase_add_test(tc_s21_pow_00, test_s21_pow_00);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_01);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_08);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_09);
    tcase_add_test(tc_s21_pow_00, test_s21_pow_10);
    suite_add_tcase(s, tc_s21_pow_00);  // Рандомные обычные значения
    tc_s21_pow_01 = tcase_create("Check s21_pow_01");
    tcase_add_test(tc_s21_pow_01, test_s21_pow_02);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_03);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_04);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_05);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_06);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_07);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_11);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_13);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_14);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_15);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_16);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_17);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_18);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_19);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_20);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_21);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_22);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_23);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_24);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_25);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_26);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_27);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_28);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_29);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_30);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_31);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_32);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_33);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_34);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_35);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_36);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_37);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_38);
    tcase_add_test(tc_s21_pow_01, test_s21_pow_39);
    suite_add_tcase(s, tc_s21_pow_01);
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
