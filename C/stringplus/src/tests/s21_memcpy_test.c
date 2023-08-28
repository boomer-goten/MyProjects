#include "../header.h"

START_TEST(test_s21_memcpy1) {
    // dest и src содержат строки, n < len(src) n < len (dest) case 1
    char dest[] = "Dest";
    char dest2[] = "Dest";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 3;
    void *d = s21_memcpy(dest, src, n);
    void *p = memcpy(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memcpy2) {
    // dest и src содержат строки, n < len(src) n < len (dest) case 1
    char dest[] = "Dest";
    char dest2[] = "Dest";
    char src[] = "So2rse";
    char src_check[] = "So2rse";
    int n = 3;
    void *d = s21_memcpy(dest, src, n);
    void *p = memcpy(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memcpy3) {
    // dest и src содержат строки, n = len(src) n < len (dest) case 2
    char dest[] = "Desting";
    char dest2[] = "Desting";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 6;
    void *d = s21_memcpy(dest, src, n);
    void *p = memcpy(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memcpy5) {
    // dest содержит src case 5
    char dest[] = "DestSorce";
    char dest2[] = "DestSorce";
    char *src = (dest + 4);
    char *src2 = (dest2 + 4);
    int n = 2;
    void *d = s21_memcpy(dest, src, n);
    void *p = memcpy(dest2, src2, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_memcpy1, *tc_s21_memcpy2, *tc_s21_memcpy4;
    s = suite_create("String s21_memcpy");
    tc_s21_memcpy1 = tcase_create("Core_s21_memcpy");
    tcase_add_test(tc_s21_memcpy1, test_s21_memcpy1);
    tcase_add_test(tc_s21_memcpy1, test_s21_memcpy2);
    suite_add_tcase(s, tc_s21_memcpy1);
    tc_s21_memcpy2 = tcase_create("Core_s21_memcpy");
    tcase_add_test(tc_s21_memcpy2, test_s21_memcpy3);
    suite_add_tcase(s, tc_s21_memcpy2);
    tc_s21_memcpy4 = tcase_create("Core_s21_memcpy");
    tcase_add_test(tc_s21_memcpy4, test_s21_memcpy5);
    suite_add_tcase(s, tc_s21_memcpy4);
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
