#include "../header.h"

START_TEST(test_strspn1) {
    char *a = "Hello, world";
    char *b = "Hel";
    size_t a1 = s21_strspn(a, b);
    size_t a2 = strspn(a, b);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_strspn2) {
    char *a = "abcdef";
    char *b = "ghij";
    size_t a1 = s21_strspn(a, b);
    size_t a2 = strspn(a, b);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_strspn3) {
    char *a = "\0";
    char *b = "elh";
    size_t a1 = s21_strspn(a, b);
    size_t a2 = strspn(a, b);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_strspn4) {
    char *a = "absdefg";
    char *b = "abe";
    size_t a1 = s21_strspn(a, b);
    size_t a2 = strspn(a, b);
    ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_strspn5) {
    char *a = "absdefg";
    char *b = "sbax";
    size_t a1 = s21_strspn(a, b);
    size_t a2 = strspn(a, b);
    ck_assert_int_eq(a1, a2);
}
END_TEST

Suite * strspn_test(void) {
    Suite *s;
    TCase *tc_strspn1;
    TCase *tc_strspn2;
    TCase *tc_strspn3;

    s = suite_create("String s21_strspn");

    tc_strspn1 = tcase_create("Match");
    tc_strspn2 = tcase_create("Don't match");
    tc_strspn3 = tcase_create("Empty source str");

    tcase_add_test(tc_strspn1, test_strspn1);
    tcase_add_test(tc_strspn2, test_strspn2);
    tcase_add_test(tc_strspn3, test_strspn3);
    tcase_add_test(tc_strspn1, test_strspn4);
    tcase_add_test(tc_strspn1, test_strspn5);

    suite_add_tcase(s, tc_strspn1);
    suite_add_tcase(s, tc_strspn2);
    suite_add_tcase(s, tc_strspn3);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strspn_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
