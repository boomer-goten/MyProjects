#include "../header.h"
/*Функция получает указатель str типа void, число n(cколько нужно повторить) и количество символов типа int c,
начиная с указателя str.*/
/*Подается массив типа чар, где меняется количество символов больше чем есть в массиве
 *Подается n = 7 > длины строки равной 4
 */
START_TEST(test_memset1) {
    char dest_test[20] = "test";
    char dest_test1[20] = "test";
    /*подача 7 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 7);
    s21_memset(dest_test1, 49, 7);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов больше чем есть в массиве
 *Подается n = 7 > длины строки равной 4
 *dest соcтоит из  \0
 */
START_TEST(test_memset2) {
    char dest_test[20] = "\0";
    char dest_test1[20] = "\0";
    /*подача 7 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 7);
    s21_memset(dest_test1, 49, 7);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов больше чем есть в массиве
 *Подается n = 7 > длины строки равной 4
 *dest содержит \n
 */
START_TEST(test_memset3) {
    char dest_test[20] = "te\nst";
    char dest_test1[20] = "te\nst";
    /*подача 7 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 7);
    s21_memset(dest_test1, 49, 7);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов меньше чем есть в массиве
 *Подается n = 3 < длины строки равной 4
 */
START_TEST(test_memset4) {
    char dest_test[20] = "test";
    char dest_test1[20] = "test";
    /*подача 3 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 3);
    s21_memset(dest_test1, 49, 3);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов меньше чем есть в массиве
 *Подается n = 3 < длины строки равной 4
 *dest содержит \n
 */
START_TEST(test_memset5) {
    char dest_test[20] = "te\nst";
    char dest_test1[20] = "te\nst";
    /*подача 3 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 3);
    s21_memset(dest_test1, 49, 3);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов меньше чем есть в массиве
 *Подается n = 3 < длины строки равной 4
 *dest состоит из \0
 */
START_TEST(test_memset6) {
    char dest_test[20] = "\0";
    char dest_test1[20] = "\0";
    /*подача 3 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 3);
    s21_memset(dest_test1, 49, 3);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа чар, где меняется количество символов меньше чем есть в массиве
 *Подается n = 0 < длины строки равной 4
 */
START_TEST(test_memset7) {
    char dest_test[20] = "test";
    char dest_test1[20] = "test";
    /*подача 0 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 1);
    s21_memset(dest_test1, 49, 1);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/*Подается массив типа int, где меняется количество символов больше чем есть в массиве
 *Подается n = 11 > длинна массива 10
 */
START_TEST(test_memset8) {
    int dest_test[10] = {1, 2, 3, 4, 5};
    int dest_test1[10] = {1, 2, 3, 4, 5};
    /*подача 11 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 11);
    s21_memset(dest_test1, 49, 11);
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (dest_test[i] != dest_test1[i]) {
            flag = 1;
        }
    }
    ck_assert_int_eq(flag, 0);
}
END_TEST
/*Подается массив типа int, где меняется количество символов меньше чем есть в массиве
 *Подается n = 0 < длинна массива 10
 */
START_TEST(test_memset9) {
    int dest_test[10] = {1, 2, 3, 4, 5};
    int dest_test1[10] = {1, 2, 3, 4, 5};
    /*подача 11 раз числа соответствующую коду 49*/
    memset(dest_test, 49, 1);
    s21_memset(dest_test1, 49, 1);
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (dest_test[i] != dest_test1[i]) {
            flag = 1;
        }
    }
    ck_assert_int_eq(flag, 0);
}
END_TEST


Suite * string_test(void) {
    Suite *s;
    TCase *tc_memset1, *tc_memset2, *tc_memset3, *tc_memset4;
    s = suite_create("String memset");
    tc_memset1 = tcase_create("Core_memset1");
    tcase_add_test(tc_memset1, test_memset1);
    tcase_add_test(tc_memset1, test_memset2);
    tcase_add_test(tc_memset1, test_memset3);
    suite_add_tcase(s, tc_memset1);
    tc_memset2 = tcase_create("Core_memset2");
    tcase_add_test(tc_memset2, test_memset4);
    tcase_add_test(tc_memset2, test_memset5);
    tcase_add_test(tc_memset2, test_memset6);
    suite_add_tcase(s, tc_memset2);
    tc_memset3 = tcase_create("Core_memset3");
    tcase_add_test(tc_memset3, test_memset7);
    suite_add_tcase(s, tc_memset3);
    tc_memset4 = tcase_create("Core_memset4");
    tcase_add_test(tc_memset4, test_memset8);
    tcase_add_test(tc_memset4, test_memset9);
    suite_add_tcase(s, tc_memset4);
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
