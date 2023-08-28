#include "../header.h"

START_TEST(test_s21_strtok1) {
    // str - содержит элементы, delim - содержит элементы, которые есть в str case 1
    char str[] = "TEST.ing1.code";
    char delim[] = ".";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok2) {
    // str - содержит элементы, delim - содержит элементы, которые нет в str case 2
    char str[] = "TEST.ing1.code";
    char delim[] = ",";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok3) {
    // str - содержит элементы, delim - содержит элементы,
    // которые есть в str притом delim состоит из строки разных символов case 5
    char str[] = "TEST,ing1.code";
    char delim[] = ".,";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok4) {
    // str - содержит элементы, delim - содержит элементы,
    // которые есть в str притом delim состоит из строки разных символов,
    // включающих символы, которых нет в str case 6
    char str[] = "TEST,ing1.code";
    char delim[] = "/.,";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok5) {
    // str - содержит элементы, delim - содержит элементы, которые есть в str,
    // несколько раз вызываем функцию с одним delim case 5
    char str1[] = "TEST.ing1.code";
    char str2[] = "TEST.ing1.code";
    char delim[] = ".";
    char *p1 = s21_strtok(str1, delim);
    char *p2 = s21_strtok(s21_NULL, delim);
    char *d1 = strtok(str2, delim);
    char *d2 = strtok(s21_NULL, delim);
    ck_assert_str_eq(p1, d1);
    ck_assert_str_eq(p2, d2);
}
END_TEST

START_TEST(test_s21_strtok6) {
    // str - содержит элементы, delim - содержит элементы, которые есть в str,
    // несколько раз вызываем функцию с разными delim case 6
    char str1[] = "TEST.ing1.code, CODE,";
    char str2[] = "TEST.ing1.code, CODE,";
    char delim[] = ".";
    char delim1[] = ",";
    char *p1 = s21_strtok(str1, delim);
    char *p2 = s21_strtok(s21_NULL, delim1);
    char *d1 = strtok(str2, delim);
    char *d2 = strtok(s21_NULL, delim1);
    ck_assert_str_eq(p1, d1);
    ck_assert_str_eq(p2, d2);
}
END_TEST

START_TEST(test_s21_strtok7) {
    // str - содержит элементы, delim - содержит элементы, которые есть в str,
    // несколько раз вызываем функцию с одним delim case 7
    char str1[] = "TEST.ing1.code";
    char str2[] = "TEST.ing1.code";
    char delim[] = ".";
    char *p1 = s21_strtok(str1, delim);
    char *p2 = s21_strtok(s21_NULL, delim);
    char *p3 = s21_strtok(s21_NULL, delim);
    char *d1 = strtok(str2, delim);
    char *d2 = strtok(s21_NULL, delim);
    char *d3 = strtok(s21_NULL, delim);
    ck_assert_str_eq(p1, d1);
    ck_assert_str_eq(p2, d2);
    ck_assert_str_eq(p3, d3);
}
END_TEST

START_TEST(test_s21_strtok8) {
    // *str = '\0'
    char str[] = "\0";
    char delim[] = "/.,";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_s21_strtok9) {
    // *delim нет в str
    char str[] = "Tesitng";
    char delim[] = "/.,";
    ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

// test for str 27, 28
START_TEST(test_s21_strtok10) {
    // str - состоит только из разделителей
    char str1[] = "///";
    char str2[] = "///";
    char delim[] = "/";
    char *p = s21_strtok(str1, delim);
    char *d = strtok(str2, delim);
    ck_assert_ptr_eq(p, d);
    if (p != s21_NULL && d != s21_NULL) {
        ck_assert_str_eq(p, d);
    }
    p = s21_strtok(s21_NULL, delim);
    d = strtok(s21_NULL, delim);
    ck_assert_ptr_eq(p, d);
    if (p && d) {
        ck_assert_str_eq(p, d);
    }
}
END_TEST

START_TEST(test_s21_strtok11) {
    // str - содержит несколько разделителей подряд
    char str1[] = "///shtern/";
    char str2[] = "///shtern/";
    char delim[] = "/";
    char *p1 = s21_strtok(str1, delim);
    char *p2 = s21_strtok(s21_NULL, delim);
    char *p3 = s21_strtok(s21_NULL, delim);
    char *d1 = strtok(str2, delim);
    char *d2 = strtok(s21_NULL, delim);
    char *d3 = strtok(s21_NULL, delim);
        if (p1 && d1)
            ck_assert_str_eq(p1, d1);
    ck_assert_ptr_eq(p2, d2);
    if (p2 && d2)
            ck_assert_str_eq(p2, d2);
    ck_assert_ptr_eq(p3, d3);
    if (p3 && d3)
            ck_assert_str_eq(p3, d3);
}
END_TEST


Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_strtok1, *tc_s21_strtok2, *tc_s21_strtok3, *tc_s21_strtok4;
    TCase *tc_s21_strtok5, *tc_s21_strtok6, *tc_s21_strtok7, *tc_s21_strtok8, *tc_s21_strtok9;
    s = suite_create("String s21_strtok");
    tc_s21_strtok1 = tcase_create("Core_stirng1");
    tcase_add_test(tc_s21_strtok1, test_s21_strtok1);
    suite_add_tcase(s, tc_s21_strtok1);
    tc_s21_strtok2 = tcase_create("Core_stirng2");
    tcase_add_test(tc_s21_strtok2, test_s21_strtok2);
    suite_add_tcase(s, tc_s21_strtok2);
    tc_s21_strtok3 = tcase_create("Core_stirng3");
    tcase_add_test(tc_s21_strtok3, test_s21_strtok3);
    suite_add_tcase(s, tc_s21_strtok3);
    tc_s21_strtok4 = tcase_create("Core_stirng4");
    tcase_add_test(tc_s21_strtok4, test_s21_strtok4);
    suite_add_tcase(s, tc_s21_strtok4);
    tc_s21_strtok5 = tcase_create("Core_stirng5");
    tcase_add_test(tc_s21_strtok5, test_s21_strtok5);
    suite_add_tcase(s, tc_s21_strtok5);
    tc_s21_strtok6 = tcase_create("Core_stirng6");
    tcase_add_test(tc_s21_strtok6, test_s21_strtok6);
    suite_add_tcase(s, tc_s21_strtok6);
    tc_s21_strtok7 = tcase_create("Core_stirng7");
    tcase_add_test(tc_s21_strtok7, test_s21_strtok7);
    suite_add_tcase(s, tc_s21_strtok7);
    tc_s21_strtok8 = tcase_create("Core_stirng8");
    tcase_add_test(tc_s21_strtok8, test_s21_strtok8);
    suite_add_tcase(s, tc_s21_strtok8);
    tc_s21_strtok9 = tcase_create("Core_stirng9");
    tcase_add_test(tc_s21_strtok9, test_s21_strtok9);
    tcase_add_test(tc_s21_strtok9, test_s21_strtok10);
    tcase_add_test(tc_s21_strtok9, test_s21_strtok11);
    suite_add_tcase(s, tc_s21_strtok9);
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
