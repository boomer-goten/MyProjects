#include "../header.h"

// haystack - содержит строку needle, needle входит в haystack 1 раз
START_TEST(test_s21_strstr1) {
    char haystack[] = "123456789";
    char needle[] = "45";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
// haystack - содержит строку needle, needle входит в haystack несколько раз
START_TEST(test_s21_strstr2) {
    char haystack[] = "12345845945";
    char needle[] = "45";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
// haystack - не содержит строку needle,
START_TEST(test_s21_strstr3) {
    char haystack[] = "12345845945";
    char needle[] = "t";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
// haystack - не содержит строку needle, cтрока needle длинее haystack
START_TEST(test_s21_strstr4) {
    char haystack[] = "123456789";
    char needle[] = "1234567891";
    ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_strstr1, *tc_s21_strstr2;
    s = suite_create("String strstr");
    tc_s21_strstr1 = tcase_create("Core_strstr1");
    tcase_add_test(tc_s21_strstr1, test_s21_strstr1);
    tcase_add_test(tc_s21_strstr1, test_s21_strstr2);
    suite_add_tcase(s, tc_s21_strstr1);
    tc_s21_strstr2 = tcase_create("Core_strstr2");
    tcase_add_test(tc_s21_strstr2, test_s21_strstr3);
    tcase_add_test(tc_s21_strstr2, test_s21_strstr4);
    suite_add_tcase(s, tc_s21_strstr2);
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
