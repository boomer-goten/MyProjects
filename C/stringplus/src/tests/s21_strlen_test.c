#include "../header.h"
/* Проверка программы при пустой строке*/
START_TEST(test_strlen1) {
    char test[20] = "";
    ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST
/* Проверка программы при обычной строке*/
START_TEST(test_strlen2) {
    char test[20] = "Hello, world!";
    ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test_strlen3) {
    char test[20] = "Hello, wo\0rld!";
    ck_assert_int_eq(s21_strlen(test), strlen(test));
}
END_TEST

START_TEST(test_strlen4) {
    char *c = "\0";
    ck_assert_int_eq(s21_strlen(c), strlen(c));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_strlen1, *tc_strlen2;
    s = suite_create("String strlen");
    tc_strlen1 = tcase_create("Core_strlen1");
    tcase_add_test(tc_strlen1, test_strlen1);
    tcase_add_test(tc_strlen1, test_strlen3);
    suite_add_tcase(s, tc_strlen1);
    tc_strlen2 = tcase_create("Core_strcat2");
    tcase_add_test(tc_strlen2, test_strlen2);
    tcase_add_test(tc_strlen2, test_strlen4);
    suite_add_tcase(s, tc_strlen2);
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
