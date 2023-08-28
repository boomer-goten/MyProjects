#include "../header.h"
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 0 символов из src*/
START_TEST(test_strncat1) {
    char dest_test[20] = "test";
    char src_test[20] = "";
    char dest_test1[20] = "test";
    /*подача 0 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 0);
    s21_strncat(dest_test1, src_test, 0);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 0 символов из src
 * dest содержит в себе \0
 */
START_TEST(test_strncat2) {
    char dest_test[20] = "te\0st";
    char src_test[20] = "";
    char dest_test1[20] = "te\0st";
    /*подача 0 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 0);
    s21_strncat(dest_test1, src_test, 0);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 0 символов из src*/
START_TEST(test_strncat3) {
    char dest_test[20] = "test";
    char src_test[20] = "\0";
    char dest_test1[20] = "test";
    /*подача 0 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 0);
    s21_strncat(dest_test1, src_test, 0);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 0 символов из src
 * dest содержит в себе \0
 */
START_TEST(test_strncat4) {
    char dest_test[20] = "te\0st";
    char src_test[20] = "\0";
    char dest_test1[20] = "te\0st";
    /*подача 0 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 0);
    s21_strncat(dest_test1, src_test, 0);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 2 символов из src*/
START_TEST(test_strncat5) {
    char dest_test[20] = "test";
    char src_test[20] = "";
    char dest_test1[20] = "test";
    /*подача 2 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 2);
    s21_strncat(dest_test1, src_test, 2);
    int b = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(b, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 2 символов из src
 * dest содержит в себе \0
 */
START_TEST(test_strncat6) {
    char dest_test[20] = "te\0st";
    char src_test[20] = "\0";
    char dest_test1[20] = "te\0st";
    /*подача 0 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 0);
    s21_strncat(dest_test1, src_test, 0);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, в конец которой подается src)
при подаче 2 символов из src
 * src содержит \0 
 */
START_TEST(test_strncat7) {
    char dest_test[20] = "te\nst";
    char src_test[20] = "\0";
    char dest_test1[20] = "te\nst";
    /*подача 2 символов пустой строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 2);
    s21_strncat(dest_test1, src_test, 2);
    int b = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(b, 0);
}
END_TEST
/*Проверка при подаче строки, состоящей из 3 символов, src(строка источник) в dest(строка, в конец которой подается src)
при подаче 2 символов из src*/
START_TEST(test_strncat8) {
    char dest_test[20] = "test";
    char src_test[20] = "thx";
    char dest_test1[20] = "test";
    /*подача 2 символов строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 2);
    s21_strncat(dest_test1, src_test, 2);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Проверка при подаче строки, состоящей из 3 символов, src(строка источник) в dest(строка, в конец которой подается src)
при подаче 4 символов из src*/
START_TEST(test_strncat9) {
    char dest_test[20] = "test";
    char src_test[20] = "thx";
    char dest_test1[20] = "test";
    /*подача 4 символов строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 4);
    s21_strncat(dest_test1, src_test, 4);
    int b = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(b, 0);
}
END_TEST
/*Проверка при подаче строки, состоящей из 3 символов, src(строка источник) в dest(строка, в конец которой подается src)
при подаче 4 символов из src*/
START_TEST(test_strncat10) {
    char dest_test[20] = "te\0st";
    char src_test[20] = "thx";
    char dest_test1[20] = "te\0st";
    /*подача 4 символов строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 4);
    s21_strncat(dest_test1, src_test, 4);
    int b = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(b, 0);
}
END_TEST
/*Проверка при подаче строки, состоящей из 3 символов, src(строка источник) в dest(строка, в конец которой подается src)
при подаче 4 символов из src
 * src содержит \0
 */
START_TEST(test_strncat11) {
    char dest_test[20] = "test";
    char src_test[20] = "t\0hx";
    char dest_test1[20] = "test";
    /*подача 4 символов строки src_test в строку dest_test*/
    strncat(dest_test, src_test, 4);
    s21_strncat(dest_test1, src_test, 4);
    int b = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(b, 0);
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_strncat1, *tc_strncat2, *tc_strncat3, *tc_strncat4, *tc_strncat5;
    s = suite_create("String s21_strncat");
    tc_strncat1 = tcase_create("Core_strncat1");
    tcase_add_test(tc_strncat1, test_strncat1);
    tcase_add_test(tc_strncat1, test_strncat2);
    suite_add_tcase(s, tc_strncat1);
    tc_strncat2 = tcase_create("Core_strncat2");
    tcase_add_test(tc_strncat2, test_strncat3);
    tcase_add_test(tc_strncat2, test_strncat4);
    suite_add_tcase(s, tc_strncat2);
    tc_strncat3 = tcase_create("Core_strncat3");
    tcase_add_test(tc_strncat3, test_strncat5);
    tcase_add_test(tc_strncat3, test_strncat6);
    tcase_add_test(tc_strncat3, test_strncat7);
    suite_add_tcase(s, tc_strncat3);
    tc_strncat4 = tcase_create("Core_strncat4");
    tcase_add_test(tc_strncat4, test_strncat8);
    suite_add_tcase(s, tc_strncat4);
    tc_strncat5 = tcase_create("Core_strncat5");
    tcase_add_test(tc_strncat5, test_strncat9);
    tcase_add_test(tc_strncat5, test_strncat10);
    tcase_add_test(tc_strncat5, test_strncat11);
    suite_add_tcase(s, tc_strncat5);
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
