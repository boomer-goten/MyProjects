#include "../header.h"

START_TEST(test_strchr1) {
    char *a = "Hello, world";
    int b = 'H';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr2) {
    char *a = "abcdefg";
    int b = 'h';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

// с пустым символом внутри строки
START_TEST(test_strchr3) {
    char *a = "abcde\0fg";
    int b = 'e';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

// с пустым символом внутри строки
START_TEST(test_strchr4) {
    char *a = "abcde\0fg";
    int b = 'g';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr5) {
    char str[] = "Hello world";
    int b = ' ';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr6) {
    char str[] = "john.smith\0@microsoft.com";
    int b = 'm';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr7) {
    char str[] = "john.smith@microsoft.com";
    int b = 'h';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr8) {
    char str[] = "john";
    int b = '\0';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr9) {
    char str[] = "john.smith@microsoft.com";
    int b = 0;
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr10) {
    char str[] = "john.smit\0h@microsoft.com";
    int b = '\0';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr11) {
    char str[] = "john.smit\nh@microsoft.com";
    int b = '\n';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr12) {
    char str[] = "abcdefg";
    int b = 'h';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr13) {
    char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, '\0'};
    int b = 14;
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr14) {
    char str[] = {'a', 'b', 'c', 'd', 'e', 127, 'f', '\0'};
    int b = 127;
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr15) {
    char str[] = "";
    int b = 'a';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr16) {
    char str[] = "\0";
    int b = 'a';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr17) {
    char str[] = "\n";
    int b = 10;
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr18) {
    char str[] = "123450567";
    int b = 0;
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr19) {
    char str[] = "john.smit\0h@micros\noft.com";
    int b = '\n';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr20) {
    char str[] = "\0";
    int b = '\0';
    char *a1 = s21_strchr(str, b);
    char *a2 = strchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

Suite * strchr_test(void) {
    Suite *s;
    TCase *tc_strchr1;

    s = suite_create("String s21_strchr");

    tc_strchr1 = tcase_create("The letter includes in string");

    tcase_add_test(tc_strchr1, test_strchr1);
    tcase_add_test(tc_strchr1, test_strchr2);
    tcase_add_test(tc_strchr1, test_strchr3);
    tcase_add_test(tc_strchr1, test_strchr4);
    tcase_add_test(tc_strchr1, test_strchr5);
    tcase_add_test(tc_strchr1, test_strchr6);
    tcase_add_test(tc_strchr1, test_strchr7);
    tcase_add_test(tc_strchr1, test_strchr8);
    tcase_add_test(tc_strchr1, test_strchr9);
    tcase_add_test(tc_strchr1, test_strchr10);
    tcase_add_test(tc_strchr1, test_strchr11);
    tcase_add_test(tc_strchr1, test_strchr12);
    tcase_add_test(tc_strchr1, test_strchr13);
    tcase_add_test(tc_strchr1, test_strchr14);
    tcase_add_test(tc_strchr1, test_strchr15);
    tcase_add_test(tc_strchr1, test_strchr16);
    tcase_add_test(tc_strchr1, test_strchr17);
    tcase_add_test(tc_strchr1, test_strchr18);
    tcase_add_test(tc_strchr1, test_strchr19);
    tcase_add_test(tc_strchr1, test_strchr20);

    suite_add_tcase(s, tc_strchr1);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strchr_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
