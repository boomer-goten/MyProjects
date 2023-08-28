#include "../header.h"

START_TEST(test_s21_memcmp1) {
    // Проверка двух одинаковых строк вся длина case 1
    char str1[] = "Testing";
    char str2[] = "Testing";
    int n = 5;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp2) {
    // Отличаюстся лишь \n case 1
    char str1[] = "Testing\n";
    char str2[] = "Testing";
    int n = 5;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp3) {
    // Проверка двух одинаковых строк часть строк case 1
    char str1[] = "Testing";
    char str2[] = "Testing";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp4) {
    // Проверка двух одинаковых строк n = 0 case 1
    char str1[] = "Testing";
    char str2[] = "Testing";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp5) {
    // 1-я строка < 2 вся длина case 2
    char str1[] = "Test";
    char str2[] = "Testing";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp6) {
    // Отличаюстся лишь \n case 2
    char str2[] = "Teslint";
    char str1[] = "Test\n";
    size_t n = 5;
    ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(test_s21_memcmp7) {
    // 1-я строка < 2 часть длины case 2
    char str1[] = "Test";
    char str2[] = "Testing";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp8) {
    // 1-я строка < 2 n = 0 case 2
    char str1[] = "Test";
    char str2[] = "Testing";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp9) {
    // 1-я строка > 2 вся длина case 3
    char str1[] = "Testing";
    char str2[] = "Test";
    int n = 3;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp10) {
    // Отличаюстся лишь \n case 3
    char str1[] = "T3sting\n";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_lt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(test_s21_memcmp11) {
    // 1-я строка > 2 часть длины case 3
    char str1[] = "Testing";
    char str2[] = "Test";
    int n = 1;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp12) {
    // 1-я строка > 2 n = 0 case 3
    char str1[] = "Testing";
    char str2[] = "Test";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp13) {
    // Если одна строка пустая case 4
    char str1[20] = "\0";
    char str2[20] = "Testing";
    int n = 5;
    ck_assert_int_lt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(test_s21_memcmp14) {
    // Если одна строка пустая n = 0 case 4
    char str1[] = "Sexting\0";
    char str2[] = "Testing";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp15) {
    // Отличаюстся лишь \n case 4
    char str1[20] = "\n\0";
    char str2[20] = "Testing";
    int n = 5;
    ck_assert_int_lt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(test_s21_memcmp16) {
    // Отличаюстся лишь \n n = 0 case 4
    char str1[] = "\n\0";
    char str2[] = "Testing";
    int n = 0;
    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_memcmp1, *tc_s21_memcmp2, *tc_s21_memcmp3, *tc_s21_memcmp4;
    s = suite_create("String s21_memcmp");
    tc_s21_memcmp1 = tcase_create("Core_s21_memcmp_Checking_two_identical_strings");
    // Проверка двух одинаковых строк
    tcase_add_test(tc_s21_memcmp1, test_s21_memcmp1);
    tcase_add_test(tc_s21_memcmp1, test_s21_memcmp2);
    tcase_add_test(tc_s21_memcmp1, test_s21_memcmp3);
    tcase_add_test(tc_s21_memcmp1, test_s21_memcmp4);
    suite_add_tcase(s, tc_s21_memcmp1);
    tc_s21_memcmp2 = tcase_create("Core_s21_memcmp_1st_string_<_2");
    // 1-я строка < 2
    tcase_add_test(tc_s21_memcmp2, test_s21_memcmp5);
    tcase_add_test(tc_s21_memcmp2, test_s21_memcmp6);
    tcase_add_test(tc_s21_memcmp2, test_s21_memcmp7);
    tcase_add_test(tc_s21_memcmp2, test_s21_memcmp8);
    suite_add_tcase(s, tc_s21_memcmp2);
    tc_s21_memcmp3 = tcase_create("Core_s21_memcmp_1st_string_>_2");
    // 1-я строка > 2
    tcase_add_test(tc_s21_memcmp3, test_s21_memcmp9);
    tcase_add_test(tc_s21_memcmp3, test_s21_memcmp10);
    tcase_add_test(tc_s21_memcmp3, test_s21_memcmp11);
    tcase_add_test(tc_s21_memcmp3, test_s21_memcmp12);
    suite_add_tcase(s, tc_s21_memcmp3);
    tc_s21_memcmp4 = tcase_create("Core_s21_memcmp_one_string_is_empty");
    // Если одна строка пустая
    tcase_add_test(tc_s21_memcmp4, test_s21_memcmp13);
    tcase_add_test(tc_s21_memcmp4, test_s21_memcmp14);
    tcase_add_test(tc_s21_memcmp4, test_s21_memcmp15);
    tcase_add_test(tc_s21_memcmp4, test_s21_memcmp16);
    suite_add_tcase(s, tc_s21_memcmp4);
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = string_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
