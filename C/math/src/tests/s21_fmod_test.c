#include "../header.h"

START_TEST(s21_fmod_test_1) {
    double x = 2.34;
    double y = 2.0;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_2) {
    double x = -2.34;
    double y = 2.0;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_3) {
    double x = 2.34;
    double y = -2.0;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_4) {
    double x = -2.34;
    double y = -2.0;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_5) {
    double x = 21.21;
    double y = 3;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_6) {
    double y = 21.21;
    double x = 3;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_7) {
    double x = -21.21;
    double y = 3;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_8) {
    double y = -21.21;
    double x = 3;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_9) {
    double x = 100500;
    double y = 9;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_10) {
    double x = -100500;
    double y = -9;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_11) {
    double y = -100500;
    double x = -9;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_12) {
    double x = -9;
    double y = -9;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_13) {
    double x = 10;
    double y = 5;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(s21_fmod_test_14) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_15) {
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(s21_fmod_test_16) {
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
  ck_assert_ldouble_nan(fmod(2.45, 0));
}
END_TEST

START_TEST(s21_fmod_test_17) {
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmod(0, 0));
}
END_TEST

START_TEST(s21_fmod_test_18) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
  ck_assert_ldouble_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(s21_fmod_test_19) {
  double num = NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_20) {
  double num = NAN;
  long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_21) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_22) {
  double num = INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_23) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_24) {
  ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_25) {
  double num = -INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_26) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_27) {
  ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
}
END_TEST

START_TEST(test_fmod_1) {
    double x = 32342.4;
    double y = 0;
    int flag = 0;
    if (isnan(fmod(x, y)) != 0 && isnan(s21_fmod(x, y)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_2) {
    double x = 32342.4;
    double y = 12.44;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST


START_TEST(test_fmod_3) {
    double x = 42.4;
    double y = 0.0024;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_4) {
    double x = -1244.4;
    double y = -2.444;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_5) {
    double x = -1244.4;
    double y = -2.444;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_6) {
    double x = -124234.4;
    double y = 142.444;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_7) {
    double x = 12658.4;
    double y = -248.294;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_8) {
    double x = 100.400000;
    double y = -248.294000;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_10) {
    double x = NAN;
    double y = 0.010000;
    int flag = 0;
    if (isnan(fmod(x, y)) != 0 && isnan(s21_fmod(x, y)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_11) {
    double x = 125125;
    double y = NAN;
    int flag = 0;
    if (isnan(fmod(x, y)) != 0 && isnan(s21_fmod(x, y)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_12) {
    double x = INFINITY;
    double y = 214;
    int flag = 0;
    if (isnan(fmod(x, y)) != 0 && isnan(s21_fmod(x, y)) != 0) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_13) {
    double x = 214;
    double y = INFINITY;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_14) {
    double x = 21784162;
    double y = 2;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_fmod_15) {
    double x = 21784162;
    double y = 1e-7;
    int flag = 0;
    if (fabs((double)s21_fmod(x, y) - fmod(x, y)) < s21_MAL) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

Suite * sprintf_test(void) {
    Suite *s;
    TCase *tc_fmod2;

    s = suite_create("s21_fmod");

    tc_fmod2 = tcase_create("fmod");
    tcase_add_test(tc_fmod2, s21_fmod_test_1);
    tcase_add_test(tc_fmod2, s21_fmod_test_2);
    tcase_add_test(tc_fmod2, s21_fmod_test_3);
    tcase_add_test(tc_fmod2, s21_fmod_test_4);
    tcase_add_test(tc_fmod2, s21_fmod_test_5);
    tcase_add_test(tc_fmod2, s21_fmod_test_6);
    tcase_add_test(tc_fmod2, s21_fmod_test_7);
    tcase_add_test(tc_fmod2, s21_fmod_test_8);
    tcase_add_test(tc_fmod2, s21_fmod_test_9);
    tcase_add_test(tc_fmod2, s21_fmod_test_10);
    tcase_add_test(tc_fmod2, s21_fmod_test_11);
    tcase_add_test(tc_fmod2, s21_fmod_test_12);
    tcase_add_test(tc_fmod2, s21_fmod_test_13);
    tcase_add_test(tc_fmod2, s21_fmod_test_14);
    tcase_add_test(tc_fmod2, s21_fmod_test_15);
    tcase_add_test(tc_fmod2, s21_fmod_test_16);
    tcase_add_test(tc_fmod2, s21_fmod_test_17);
    tcase_add_test(tc_fmod2, s21_fmod_test_18);
    tcase_add_test(tc_fmod2, s21_fmod_test_19);
    tcase_add_test(tc_fmod2, s21_fmod_test_20);
    tcase_add_test(tc_fmod2, s21_fmod_test_21);
    tcase_add_test(tc_fmod2, s21_fmod_test_22);
    tcase_add_test(tc_fmod2, s21_fmod_test_23);
    tcase_add_test(tc_fmod2, s21_fmod_test_24);
    tcase_add_test(tc_fmod2, s21_fmod_test_25);
    tcase_add_test(tc_fmod2, s21_fmod_test_26);
    tcase_add_test(tc_fmod2, s21_fmod_test_27);
    tcase_add_test(tc_fmod2, test_fmod_1);
    tcase_add_test(tc_fmod2, test_fmod_2);
    tcase_add_test(tc_fmod2, test_fmod_3);
    tcase_add_test(tc_fmod2, test_fmod_4);
    tcase_add_test(tc_fmod2, test_fmod_5);
    tcase_add_test(tc_fmod2, test_fmod_6);
    tcase_add_test(tc_fmod2, test_fmod_7);
    tcase_add_test(tc_fmod2, test_fmod_8);
    tcase_add_test(tc_fmod2, test_fmod_10);
    tcase_add_test(tc_fmod2, test_fmod_11);
    tcase_add_test(tc_fmod2, test_fmod_12);
    tcase_add_test(tc_fmod2, test_fmod_13);
    tcase_add_test(tc_fmod2, test_fmod_14);
    tcase_add_test(tc_fmod2, test_fmod_15);

    suite_add_tcase(s, tc_fmod2);

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
