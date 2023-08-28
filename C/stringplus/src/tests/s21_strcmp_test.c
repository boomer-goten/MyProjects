#include "../header.h"

START_TEST(test_s21_strcmp1) {
    // Проверка двух одинаковых строк case 1
    char str1[] = "Test";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp2) {
    // Отличаюстся лишь \n case 1
    char str1[] = "Test\n";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp3) {
    // 1-я строка < 2 case 2
    char str1[] = "Te";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp4) {
    // Отличаюстся лишь \n case 2
    char str1[] = "Te\n";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp5) {
    // 1-я строка > 2 case 3
    char str1[] = "Test";
    char str2[] = "Te";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp6) {
    // Отличаюстся лишь \n case 3
    char str1[] = "Test\n";
    char str2[] = "Te";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp7) {
    // Если одна строка пустая case 4
    char str1[] = "\0";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp8) {
    // Отличаюстся лишь \n case 4
    char str1[] = "\n\0";
    char str2[] = "Test";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_strcmp1, *tc_s21_strcmp2, *tc_s21_strcmp3, *tc_s21_strcmp4;
    s = suite_create("String s21_strcmp");
    tc_s21_strcmp1 = tcase_create("Core_s21_strcmp");  // Проверка двух одинаковых строк
    tcase_add_test(tc_s21_strcmp1, test_s21_strcmp1);
    tcase_add_test(tc_s21_strcmp1, test_s21_strcmp2);
    suite_add_tcase(s, tc_s21_strcmp1);
    tc_s21_strcmp2 = tcase_create("Core_s21_strcmp");  // 1-я строка < 2
    tcase_add_test(tc_s21_strcmp2, test_s21_strcmp3);
    tcase_add_test(tc_s21_strcmp2, test_s21_strcmp4);
    suite_add_tcase(s, tc_s21_strcmp2);
    tc_s21_strcmp3 = tcase_create("Core_s21_strcmp");  // 1-я строка > 2
    tcase_add_test(tc_s21_strcmp3, test_s21_strcmp5);
    tcase_add_test(tc_s21_strcmp3, test_s21_strcmp6);
    suite_add_tcase(s, tc_s21_strcmp3);
    tc_s21_strcmp4 = tcase_create("Core_s21_strcmp");  // Отличаюстся лишь \n
    tcase_add_test(tc_s21_strcmp4, test_s21_strcmp7);
    tcase_add_test(tc_s21_strcmp4, test_s21_strcmp8);
    suite_add_tcase(s, tc_s21_strcmp4);
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
