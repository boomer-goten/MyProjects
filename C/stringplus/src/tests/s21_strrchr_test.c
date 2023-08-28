#include "../header.h"

START_TEST(test_strrchr1) {
    char *a = "Hello, world";
    int b = 'H';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr2) {
    char *a = "abcdefg";
    int b = 'h';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr3) {
    char *a = "abcde\0fg";
    int b = 'e';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

// с пустым символом внутри строки
START_TEST(test_strrchr4) {
    char *a = "abcde\0fg";
    int b = 'g';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr5) {
    char str[] = "Hello world";
    int b = ' ';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr6) {
    char str[] = "john.smith\0@microsoft.com";
    int b = 'm';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr7) {
    char str[] = "john.smith@microsoft.com";
    int b = 'h';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr8) {
    char str[] = "john";
    int b = '\0';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr9) {
    char str[] = "john.smith@microsoft.com";
    int b = 0;
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr10) {
    char str[] = "john.smit\0h@microsoft.com";
    int b = '\0';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr11) {
    char str[] = "john.smit\nh@microsoft.com";
    int b = '\n';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr12) {
    char str[] = "abcdefg";
    int b = 'h';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr13) {
    char str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, '\0'};
    int b = 14;
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr14) {
    char str[] = {'a', 'b', 'c', 'd', 'e', 127, 'f', '\0'};
    int b = 127;
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr15) {
    char str[] = "";
    int b = 'a';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr16) {
    char str[] = "\0";
    int b = 'a';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr17) {
    char str[] = "\n";
    int b = 10;
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr18) {
    char str[] = "123450567";
    int b = 0;
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr19) {
    char str[] = "john.smit\0h@micros\noft.com";
    int b = '\n';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr20) {
    char str[] = "\0";
    int b = '\0';
    char *a1 = s21_strrchr(str, b);
    char *a2 = strrchr(str, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

Suite * strrchr_test(void) {
    Suite *s;
    TCase *tc_strrchr1;

    s = suite_create("String s21_strrchr");

    tc_strrchr1 = tcase_create("The letter includes in string");

    tcase_add_test(tc_strrchr1, test_strrchr1);
    tcase_add_test(tc_strrchr1, test_strrchr2);
    tcase_add_test(tc_strrchr1, test_strrchr3);
    tcase_add_test(tc_strrchr1, test_strrchr4);
    tcase_add_test(tc_strrchr1, test_strrchr5);
    tcase_add_test(tc_strrchr1, test_strrchr6);
    tcase_add_test(tc_strrchr1, test_strrchr7);
    tcase_add_test(tc_strrchr1, test_strrchr8);
    tcase_add_test(tc_strrchr1, test_strrchr9);
    tcase_add_test(tc_strrchr1, test_strrchr10);
    tcase_add_test(tc_strrchr1, test_strrchr11);
    tcase_add_test(tc_strrchr1, test_strrchr12);
    tcase_add_test(tc_strrchr1, test_strrchr13);
    tcase_add_test(tc_strrchr1, test_strrchr14);
    tcase_add_test(tc_strrchr1, test_strrchr15);
    tcase_add_test(tc_strrchr1, test_strrchr16);
    tcase_add_test(tc_strrchr1, test_strrchr17);
    tcase_add_test(tc_strrchr1, test_strrchr18);
    tcase_add_test(tc_strrchr1, test_strrchr19);
    tcase_add_test(tc_strrchr1, test_strrchr20);

    suite_add_tcase(s, tc_strrchr1);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strrchr_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
