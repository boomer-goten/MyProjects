#include "../header.h"

/*Функция получает указатель str типа void, 
 * Нужно вернуть копию строки str с условием что буквы нижнего регистра станут буквами верхнего регистра*/
/* Подается строка только с буквами */
START_TEST(test_lower1) {
    const char lower_test[40] = "FUCK";
    const char lower_test1[40] = "fuck";
    char *p = s21_to_lower(lower_test);
    int a = strcmp(p, lower_test1);
    free(p);
    ck_assert_int_eq(a, 0);
}
END_TEST

/* Подается строка только с буквами и цифрами */
START_TEST(test_lower2) {
    const char lower_test2[20] = "228test1337";
    const char lower_test3[20] = "228TEST1337";
    char *p = s21_to_lower(lower_test3);
    int a = strcmp(p, lower_test2);
    free(p);
    ck_assert_int_eq(a, 0);
}
END_TEST

/* Подается строка только цифры */
START_TEST(test_lower3) {
    const char lower_test[20] = "tvari";
    const char lower_test1[20] = "TVARI";
    char *p = s21_to_lower(lower_test1);
    int a = strcmp(p, lower_test);
    free(p);
    ck_assert_int_eq(a, 0);
}
END_TEST

/* Подается пустая строка */
START_TEST(test_lower4) {
    int flag = 0;
    const char lower_test[20] = "";
    char *p = s21_to_lower(lower_test);
    if (s21_strlen(p) == 0) {
        flag = 1;
    }
    free(p);
    ck_assert_int_eq(flag, 1);
}
END_TEST

/* Подается NULL строка */
START_TEST(test_lower5) {
    int flag = 0;
    const char *lower_test = s21_NULL;
    char *p = s21_to_lower(lower_test);
    if (p == s21_NULL) {
        flag = 1;
    }
    free(p);
    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(test_lower6) {
    char str[] = "ShLePa V TaZ1Ke?";
    char expected[] = "shlepa v taz1ke?";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

START_TEST(test_lower7) {
    char str[] = "123456789Q";
    char expected[] = "123456789q";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(test_lower8) {
    char str[] = "Space created";
    char expected[] = "space created";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(test_lower9) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST


START_TEST(test_lower10) {
    char str[] = "";
    char expected[] = "";
    char *got = s21_to_lower(str);
    ck_assert_str_eq(got, expected);
    if (got) free(got);
} END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_to_lower1, *tc_to_lower2;
    s = suite_create("String lower");
    tc_to_lower1 = tcase_create("Core_lower1");
    tcase_add_test(tc_to_lower1, test_lower1);
    tcase_add_test(tc_to_lower1, test_lower2);
    suite_add_tcase(s, tc_to_lower1);
    tc_to_lower2 = tcase_create("Core_lower2");
    tcase_add_test(tc_to_lower2, test_lower3);
    tcase_add_test(tc_to_lower2, test_lower4);
    tcase_add_test(tc_to_lower2, test_lower5);
    tcase_add_test(tc_to_lower2, test_lower6);
    tcase_add_test(tc_to_lower2, test_lower7);
    tcase_add_test(tc_to_lower2, test_lower8);
    tcase_add_test(tc_to_lower2, test_lower9);
    tcase_add_test(tc_to_lower2, test_lower10);
    suite_add_tcase(s, tc_to_lower2);
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
