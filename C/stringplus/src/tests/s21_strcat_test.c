#include "../header.h"
/* Проверка программы при подаче пустой строки src(строка источник) в 
 *dest(строка, в конец которой подается src)*/
START_TEST(test_strcat1) {
    char dest_test[20] = "test";
    char src_test[20] = "";
    char dest_test1[20] = "test";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)*/
START_TEST(test_strcat2) {
    char dest_test[20] = "test";
    char src_test[20] = "src";
    char dest_test1[20] = "test";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * dest содержит в себе \n
 */
START_TEST(test_strcat3) {
    char dest_test[20] = "tes\nt";
    char src_test[20] = "src";
    char dest_test1[20] = "tes\nt";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * dest содержит в себе \0
 */
START_TEST(test_strcat4) {
    char dest_test[20] = "tes\0t";
    char src_test[20] = "src";
    char dest_test1[20] = "tes\0t";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * dest содержит в себе только \0
 */
START_TEST(test_strcat5) {
    char dest_test[20] = "\0";
    char src_test[20] = "src";
    char dest_test1[20] = "\0";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * src содержит в себе \0
 */
START_TEST(test_strcat6) {
    char dest_test[20] = "test";
    char src_test[20] = "s\0rc";
    char dest_test1[20] = "test";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * src содержит в себе только \0
 */
START_TEST(test_strcat7) {
    char dest_test[20] = "test";
    char src_test[20] = "\0";
    char dest_test1[20] = "test";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Проверка программы при подаче строки src(строка источник) в dest(строка, в конец которой подается src)
 * src содержит в себе \n и \0
 */
START_TEST(test_strcat8) {
    char dest_test[20] = "test";
    char src_test[20] = "s\nr\0c";
    char dest_test1[20] = "test";
    strcat(dest_test, src_test);
    s21_strcat(dest_test1, src_test);
    int a = strcmp(dest_test, dest_test1);
    ck_assert_int_eq(a, 0);
}
END_TEST
Suite * string_test(void) {
    Suite *s;
    TCase *tc_strcat1, *tc_strcat2, *tc_strcat3, *tc_strcat4;
    s = suite_create("String strcat");
    tc_strcat1 = tcase_create("Core_strcat1");
    tcase_add_test(tc_strcat1, test_strcat1);
    suite_add_tcase(s, tc_strcat1);
    tc_strcat2 = tcase_create("Core_strcat2");
    tcase_add_test(tc_strcat2, test_strcat2);
    suite_add_tcase(s, tc_strcat2);
    tc_strcat3 = tcase_create("Core_strcat3");
    tcase_add_test(tc_strcat3, test_strcat3);
    tcase_add_test(tc_strcat3, test_strcat4);
    tcase_add_test(tc_strcat3, test_strcat5);
    suite_add_tcase(s, tc_strcat3);
    tc_strcat4 = tcase_create("Core_strcat4");
    tcase_add_test(tc_strcat4, test_strcat6);
    tcase_add_test(tc_strcat4, test_strcat7);
    tcase_add_test(tc_strcat4, test_strcat8);
    suite_add_tcase(s, tc_strcat4);
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
