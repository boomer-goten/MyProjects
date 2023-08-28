#include "../header.h"

START_TEST(test_s21_memchr1) {
    // str - заполнена, c - не больше len(str), n - вся строка case 1
    char str1[20] = "TESTing1code";
    int c = 5;
    s21_size_t n = 13;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr2) {
    // str - заполнена, c - не больше len(str) (просто изменил c), n - вся строка case 1
    char str1[20] = "TESTing1code";
    int c = 3;
    s21_size_t n = 13;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr3) {
    // str - заполнена, c - не больше len(str), n - часть строки, c не включает case 1
    char str1[] = "TESTing1code";
    int c = 7;
    s21_size_t n = 2;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr4) {
    // str - заполнена, c - не больше len(str), n - часть строки, c включает case 1
    char str1[] = "2221code";
    int c = 1;
    s21_size_t n = 5;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr5) {
    // str - пустая, c - не больше len(str), n - часть строки, c включает case 2
    char str1[] = "\0";
    int c = 2;
    s21_size_t n = 1;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr6) {
    // str - заполнена, c - существует, n > len(str), c включает case 3
    char str1[20] = "2221code";
    int c = 1;
    s21_size_t n = 15;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr7) {
    // str - заполнена, c -  не существует, n < len(str), c включает case 3
    char str1[] = "222133332";
    int c = 4;
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr8) {
    // str - заполненная строка, c -  не существует, n > len(str), c включает case 4
    char str[] = "privetChel";
    int c = 'd';
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr9) {
    char str[] = "abcde\0fg";
    int c = 'e';
    s21_size_t n = 8;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr10) {
    char str[] = "abcde\0fg";
    int c = 'g';
    s21_size_t n = 1;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr11) {
    char str[] = "Hello world";
    int c = ' ';
    s21_size_t n = 14;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr12) {
    char str[] = "john.smith\0@microsoft.com";
    int c = 'm';
    s21_size_t n = 14;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr13) {
    char str[] = "john.smith@microsoft.com";
    int c = 'h';
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr14) {
    char str[] = "john";
    int c = '\0';
    s21_size_t n = 6;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr15) {
    char str[] = "john.smith@microsoft.com";
    int c = 0;
    s21_size_t n = 26;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr16) {
    char str[] = "john.smit\0h@microsoft.com";
    int c = '\0';
    s21_size_t n = 14;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr17) {
    char str[] = "john.smit\nh@microsoft.com";
    int c = '\n';
    s21_size_t n = 5;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr18) {
    char str[50] = "abcdefg";
    int c = 'h';
    s21_size_t n = 10;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr19) {
    char str[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, '\0'};
    int c = 14;
    s21_size_t n = 15;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr20) {
    char str[50] = {'a', 'b', 'c', 'd', 'e', 127, 'f', '\0'};
    int c = 127;
    s21_size_t n = 10;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr21) {
    char str[50] = "";
    int c = 'a';
    s21_size_t n = 24;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr22) {
    char str[50] = "\0";
    int c = 'a';
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr23) {
    char str[50] = "\n";
    int c = 10;
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr24) {
    char str[50] = "123450567";
    int c = 0;
    s21_size_t n = 10;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(test_s21_memchr25) {
    char str[50] = "john.smit\0h@micros\noft.com";
    int c = '\n';
    s21_size_t n = 22;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_memchr;
    s = suite_create("String memchr");
    tc_s21_memchr = tcase_create("Core_stirng1");
    tcase_add_test(tc_s21_memchr, test_s21_memchr1);
    tcase_add_test(tc_s21_memchr, test_s21_memchr2);
    tcase_add_test(tc_s21_memchr, test_s21_memchr3);
    tcase_add_test(tc_s21_memchr, test_s21_memchr4);
    tcase_add_test(tc_s21_memchr, test_s21_memchr5);
    tcase_add_test(tc_s21_memchr, test_s21_memchr6);
    tcase_add_test(tc_s21_memchr, test_s21_memchr7);
    tcase_add_test(tc_s21_memchr, test_s21_memchr8);
    tcase_add_test(tc_s21_memchr, test_s21_memchr9);
    tcase_add_test(tc_s21_memchr, test_s21_memchr10);
    tcase_add_test(tc_s21_memchr, test_s21_memchr11);
    tcase_add_test(tc_s21_memchr, test_s21_memchr12);
    tcase_add_test(tc_s21_memchr, test_s21_memchr13);
    tcase_add_test(tc_s21_memchr, test_s21_memchr14);
    tcase_add_test(tc_s21_memchr, test_s21_memchr15);
    tcase_add_test(tc_s21_memchr, test_s21_memchr16);
    tcase_add_test(tc_s21_memchr, test_s21_memchr17);
    tcase_add_test(tc_s21_memchr, test_s21_memchr18);
    tcase_add_test(tc_s21_memchr, test_s21_memchr19);
    tcase_add_test(tc_s21_memchr, test_s21_memchr20);
    tcase_add_test(tc_s21_memchr, test_s21_memchr21);
    tcase_add_test(tc_s21_memchr, test_s21_memchr22);
    tcase_add_test(tc_s21_memchr, test_s21_memchr23);
    tcase_add_test(tc_s21_memchr, test_s21_memchr24);
    tcase_add_test(tc_s21_memchr, test_s21_memchr25);

    suite_add_tcase(s, tc_s21_memchr);
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
