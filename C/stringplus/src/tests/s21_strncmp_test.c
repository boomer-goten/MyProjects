#include "../header.h"

START_TEST(test_s21_strncmp1) {
    // Проверка двух одинаковых строк вся длина case 1
    char str1[] = "Test";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp2) {
    // Отличаюстся лишь \n case 1
    char str1[] = "Test\n";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp3) {
    // Проверка двух одинаковых строк часть строк case 1
    char str1[] = "Test";
    char str2[] = "Test";
    int n = 3;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp4) {
    // Проверка двух одинаковых строк n = 0 case 1
    char str1[] = "Test";
    char str2[] = "Test";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp5) {
    // 1-я строка < 2 вся длина case 2
    char str1[] = "Te";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp6) {
    // Отличаюстся лишь \n case 2
    char str1[] = "Te\n";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp7) {
    // 1-я строка < 2 часть длины case 2
    char str1[] = "Te";
    char str2[] = "Test";
    int n = 1;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp8) {
    // 1-я строка < 2 n = 0 case 2
    char str1[] = "Te";
    char str2[] = "Test";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp9) {
    // 1-я строка > 2 вся длина case 3
    char str1[] = "Test";
    char str2[] = "Te";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp10) {
    // Отличаюстся лишь \n case 3
    char str1[] = "Test\n";
    char str2[] = "Te";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp11) {
    // 1-я строка > 2 часть длины case 3
    char str1[] = "Test";
    char str2[] = "Te";
    int n = 1;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp12) {
    // 1-я строка > 2 n = 0 case 3
    char str1[] = "Test";
    char str2[] = "Te";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp13) {
    // Если одна строка пустая case 4
    char str1[] = "\0";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp14) {
    // Если одна строка пустая n = 0 case 4
    char str1[] = "\0";
    char str2[] = "Test";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp15) {
    // Отличаюстся лишь \n case 4
    char str1[] = "\n\0";
    char str2[] = "Test";
    int n = 5;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp16) {
    // Отличаюстся лишь \n n = 0 case 4
    char str1[] = "\n\0";
    char str2[] = "Test";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_strncmp17) {
    // Проверка двух одинаковых строк n больше длин строк case 1
    char str1[] = "Test";
    char str2[] = "Test";
    int n = 10;
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_strncmp1, *tc_s21_strncmp2, *tc_s21_strncmp3, *tc_s21_strncmp4;
    s = suite_create("String s21_strncmp");
    tc_s21_strncmp1 = tcase_create("Core_s21_strncmp");
    // Проверка двух одинаковых строк
    tcase_add_test(tc_s21_strncmp1, test_s21_strncmp1);
    tcase_add_test(tc_s21_strncmp1, test_s21_strncmp2);
    tcase_add_test(tc_s21_strncmp1, test_s21_strncmp3);
    tcase_add_test(tc_s21_strncmp1, test_s21_strncmp4);
    tcase_add_test(tc_s21_strncmp1, test_s21_strncmp17);
    suite_add_tcase(s, tc_s21_strncmp1);
    tc_s21_strncmp2 = tcase_create("Core_s21_strncmp");
    // 1-я строка < 2
    tcase_add_test(tc_s21_strncmp2, test_s21_strncmp5);
    tcase_add_test(tc_s21_strncmp2, test_s21_strncmp6);
    tcase_add_test(tc_s21_strncmp2, test_s21_strncmp7);
    tcase_add_test(tc_s21_strncmp2, test_s21_strncmp8);
    suite_add_tcase(s, tc_s21_strncmp2);
    tc_s21_strncmp3 = tcase_create("Core_s21_strncmp");
    // 1-я строка > 2
    tcase_add_test(tc_s21_strncmp3, test_s21_strncmp9);
    tcase_add_test(tc_s21_strncmp3, test_s21_strncmp10);
    tcase_add_test(tc_s21_strncmp3, test_s21_strncmp11);
    tcase_add_test(tc_s21_strncmp3, test_s21_strncmp12);
    suite_add_tcase(s, tc_s21_strncmp3);
    tc_s21_strncmp4 = tcase_create("Core_s21_strncmp");
    // Если одна строка пустая
    tcase_add_test(tc_s21_strncmp4, test_s21_strncmp13);
    tcase_add_test(tc_s21_strncmp4, test_s21_strncmp14);
    tcase_add_test(tc_s21_strncmp4, test_s21_strncmp15);
    tcase_add_test(tc_s21_strncmp4, test_s21_strncmp16);
    suite_add_tcase(s, tc_s21_strncmp4);
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
