#include "../header.h"

START_TEST(test_s21_memmove1) {
    // dest и src содержат строки, n < len(src) n < len (dest) case 1
    char dest[] = "Dest";
    char dest2[] = "Dest";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 3;
    void *d = s21_memmove(dest, src, n);
    void *p = memmove(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memmove2) {
    // dest и src содержат строки, n < len(src) n < len (dest) case 1
    char dest[] = "Dest";
    char dest2[] = "Dest";
    char src[] = "So2rse";
    char src_check[] = "So2rse";
    int n = 3;
    void *d = s21_memmove(dest, src, n);
    void *p = memmove(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memmove3) {
    // dest и src содержат строки, n = len(src) n < len (dest) case 2
    char dest[] = "Desting";
    char dest2[] = "Desting";
    char src[] = "Sorse";
    char src_check[] = "Sorse";
    int n = 6;
    void *d = s21_memmove(dest, src, n);
    void *p = memmove(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memmove4) {
    // dest и src содержат строки, n > len(src) n < len (dest) case 3
    char dest[20] = "Desting";
    char dest2[20] = "Desting";
    char src[20] = "Sorse";
    char src_check[20] = "Sorse";
    int n = 7;
    void *d = s21_memmove(dest, src, n);
    void *p = memmove(dest2, src, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
    ck_assert_str_eq(src, src_check);
}
END_TEST

START_TEST(test_s21_memmove5) {
    // dest содержит src case 4
    char dest[] = "DestSorce";
    char dest2[] = "DestSorce";
    char *src = (dest + 4);
    char *src2 = (dest2 +4);
    int n = 2;
    void *d = s21_memmove(dest, src, n);
    void *p = memmove(dest2, src2, n);
    if (d && p) {
        ck_assert_str_eq(d, p);
    }
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_memmove1, *tc_s21_memmove2, *tc_s21_memmove3, *tc_s21_memmove4;
    s = suite_create("String s21_memmove");
    tc_s21_memmove1 = tcase_create("Core_s21_memmove");
    tcase_add_test(tc_s21_memmove1, test_s21_memmove1);
    tcase_add_test(tc_s21_memmove1, test_s21_memmove2);
    suite_add_tcase(s, tc_s21_memmove1);
    tc_s21_memmove2 = tcase_create("Core_s21_memmove");
    tcase_add_test(tc_s21_memmove2, test_s21_memmove3);
    suite_add_tcase(s, tc_s21_memmove2);
    tc_s21_memmove3 = tcase_create("Core_s21_memmove");
    tcase_add_test(tc_s21_memmove3, test_s21_memmove4);
    suite_add_tcase(s, tc_s21_memmove3);
    tc_s21_memmove4 = tcase_create("Core_s21_memmove");
    tcase_add_test(tc_s21_memmove4, test_s21_memmove5);
    suite_add_tcase(s, tc_s21_memmove4);
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
