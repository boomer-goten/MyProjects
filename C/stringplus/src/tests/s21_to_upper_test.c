#include "../header.h"
/*Функция получает указатель str типа void, 
 * Нужно вернуть копию строки str с условием что буквы нижнего регистра станут буквами верхнего регистра*/
/* Подается строка только с буквами */
START_TEST(test_upper1) {
    const char upper_test[20] = "test";
    const char upper_test1[20] = "TEST";
    char *d = s21_to_upper(upper_test);
    int a = strcmp(d, upper_test1);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST

/* Подается строка только с буквами и цифрами */
START_TEST(test_upper2) {
    const char upper_test[20] = "228test1337";
    const char upper_test1[20] = "228TEST1337";
    char *d = s21_to_upper(upper_test);
    int a = strcmp(d, upper_test1);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST

/* Подается строка только цифры */
START_TEST(test_upper3) {
    const char upper_test[20] = "TVARI";
    const char upper_test1[20] = "TVARI";
    char *d = s21_to_upper(upper_test);
    int a = strcmp(d, upper_test1);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Подается пустая строка */
START_TEST(test_upper4) {
    int flag = 0;
    const char upper_test[20] = "\0";
    char *d = s21_to_upper(upper_test);
    if (s21_strlen(d) == 0) {
        flag = 1;
    }
    free(d);
    ck_assert_int_eq(flag, 1);
}
END_TEST

/* Подается NULL строка */
START_TEST(test_upper5) {
    int flag = 0;
    const char *upper_test = s21_NULL;
    char *p = s21_to_upper(upper_test);
    if (p == s21_NULL) {
        flag = 1;
    }
    free(p);
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_upper6) {
    char str[] = "good job";
    char expected[] = "GOOD JOB";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(test_upper7) {
    char str[] = "empty";
    char expected[] = "EMPTY";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(test_upper8) {
    char str[] = "1+1*1";
    char expected[] = "1+1*1";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(test_upper9) {
    char str[] = " ";
    char expected[] = " ";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(test_upper10) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_upper(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_to_upper1, *tc_to_upper2;
    s = suite_create("String upper");
    tc_to_upper1 = tcase_create("Core_upper1");
    tcase_add_test(tc_to_upper1, test_upper1);
    tcase_add_test(tc_to_upper1, test_upper2);
    suite_add_tcase(s, tc_to_upper1);
    tc_to_upper2 = tcase_create("Core_upper2");
    tcase_add_test(tc_to_upper2, test_upper3);
    tcase_add_test(tc_to_upper2, test_upper4);
    tcase_add_test(tc_to_upper2, test_upper5);
    tcase_add_test(tc_to_upper2, test_upper6);
    tcase_add_test(tc_to_upper2, test_upper7);
    tcase_add_test(tc_to_upper2, test_upper8);
    tcase_add_test(tc_to_upper2, test_upper9);
    tcase_add_test(tc_to_upper2, test_upper10);

    suite_add_tcase(s, tc_to_upper2);
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
