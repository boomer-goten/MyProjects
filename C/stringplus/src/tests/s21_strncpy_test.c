#include "../header.h"

START_TEST(test_s21_strncpy3) {
    // dest и src содержат строки, n = len(src) n < len (dest) case 2
    char dest[] = "Destination";
    char dest2[] = "Destination";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 6;
    char *d = s21_strncpy(dest, src, n);
    char *p = strncpy(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_strncpy4) {
    // dest и src содержат строки, n > len(src) n < len (dest) case 3
    char dest[] = "Destination";
    char dest2[] = "Destination";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 8;
    char *d = s21_strncpy(dest, src, n);
    char *p = strncpy(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_strncpy2, *tc_s21_strncpy3;
    s = suite_create("String s21_strncpy");
    tc_s21_strncpy2 = tcase_create("Core_s21_strncpy");
    tcase_add_test(tc_s21_strncpy2, test_s21_strncpy3);
    suite_add_tcase(s, tc_s21_strncpy2);
    tc_s21_strncpy3 = tcase_create("Core_s21_strncpy");
    tcase_add_test(tc_s21_strncpy3, test_s21_strncpy4);
    suite_add_tcase(s, tc_s21_strncpy3);
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
