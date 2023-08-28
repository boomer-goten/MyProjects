#include "../header.h"

START_TEST(test_strpbrk1) {
    char *a = "0123456789";
    char *a1 = "369";
    char *b1 = s21_strpbrk(a, a1);
    char *b2 = strpbrk(a, a1);
    ck_assert_ptr_eq(b1, b2);
}
END_TEST

START_TEST(test_strpbrk2) {
    char *a = "Hello, world";
    char *a1 = "alw";
    char *b1 = s21_strpbrk(a, a1);
    char *b2 = strpbrk(a, a1);
    ck_assert_ptr_eq(b1, b2);
}
END_TEST

START_TEST(test_strpbrk3) {
    char *a = "\0";
    char *a1 = "369";
    char *b1 = s21_strpbrk(a, a1);
    char *b2 = strpbrk(a, a1);
    ck_assert_ptr_eq(b1, b2);
}
END_TEST

START_TEST(test_strpbrk4) {
    char *a = "abcdefg";
    char *a1 = "3hij";
    char *b1 = s21_strpbrk(a, a1);
    char *b2 = strpbrk(a, a1);
    ck_assert_ptr_eq(b1, b2);
}
END_TEST

Suite * strpbrk_test(void) {
    Suite *s;
    TCase *tc_strpbrk1;
    TCase *tc_strpbrk2;
    TCase *tc_strpbrk3;
    TCase *tc_strpbrk4;

    s = suite_create("String s21_strpbrk");

    tc_strpbrk1 = tcase_create("letter includes in str1");
    tc_strpbrk2 = tcase_create("letter includes in str1");
    tc_strpbrk3 = tcase_create("The letter doesn't include in str1");
    tc_strpbrk4 = tcase_create("The letter doesn't include in str1");

    tcase_add_test(tc_strpbrk1, test_strpbrk1);
    tcase_add_test(tc_strpbrk2, test_strpbrk2);
    tcase_add_test(tc_strpbrk3, test_strpbrk3);
    tcase_add_test(tc_strpbrk2, test_strpbrk4);

    suite_add_tcase(s, tc_strpbrk1);
    suite_add_tcase(s, tc_strpbrk2);
    suite_add_tcase(s, tc_strpbrk3);
    suite_add_tcase(s, tc_strpbrk4);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strpbrk_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
