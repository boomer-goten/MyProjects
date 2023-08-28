#include "../header.h"

START_TEST(test_asin_1) {
    double d = -12345.128000;
    int flag = 0;
    if (isnan(asin(d)) != 0 && isnan(s21_asin(d)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_2) {
    double d = 20;
    int flag = 0;
    if (isnan(asin(d)) != 0 && isnan(s21_asin(d)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST


START_TEST(test_asin_3) {
    double d = -20;
    int flag = 0;
    if (isnan(asin(d)) != 0 && isnan(s21_asin(d)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_4) {
    double d = -1;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_5) {
    double d = 1;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_6) {
    double d = 0.850000;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_7) {
    double d = 0.500000;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_8) {
    double d = -0.500000;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_9) {
    double d = -0.300000;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_10) {
    double d = 0.300000;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_11) {
    double d = 0;
    int flag = 0;
    if (fabs((double)s21_asin(d) - asin(d)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_12) {
    double d = NAN;
    int flag = 0;
    if (isnan(asin(d)) != 0 && isnan(s21_asin(d)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_asin_13) {
    double d = INFINITY;
    int flag = 0;
    if (isnan(asin(d)) != 0 && isnan(s21_asin(d)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_asin2;

    s = suite_create("s21_asin");

    tc_asin2 = tcase_create("asin");
    tcase_add_test(tc_asin2, test_asin_1);
    tcase_add_test(tc_asin2, test_asin_2);
    tcase_add_test(tc_asin2, test_asin_3);
    tcase_add_test(tc_asin2, test_asin_4);
    tcase_add_test(tc_asin2, test_asin_5);
    tcase_add_test(tc_asin2, test_asin_6);
    tcase_add_test(tc_asin2, test_asin_7);
    tcase_add_test(tc_asin2, test_asin_8);
    tcase_add_test(tc_asin2, test_asin_9);
    tcase_add_test(tc_asin2, test_asin_10);
    tcase_add_test(tc_asin2, test_asin_11);
    tcase_add_test(tc_asin2, test_asin_12);
    tcase_add_test(tc_asin2, test_asin_13);
    suite_add_tcase(s, tc_asin2);

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
