#include "../header.h"
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, куда копируется src)*/
START_TEST(test_strcpy1) {
    char dest_test[20] = "test";
    char src_test[20] = "";
    ck_assert_ptr_eq(s21_strcpy(dest_test, src_test), strcpy(dest_test, src_test));
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, куда копируется src)*/
START_TEST(test_strcpy2) {
    char dest_test[20] = "test";
    char src_test[20] = "\0";
    ck_assert_ptr_eq(s21_strcpy(dest_test, src_test), strcpy(dest_test, src_test));
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, куда копируется src)*/
START_TEST(test_strcpy3) {
    char dest_test[20] = "te\nst";
    char src_test[20] = "\0";
    ck_assert_ptr_eq(s21_strcpy(dest_test, src_test), strcpy(dest_test, src_test));
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, куда копируется src)
 * при этом src < dest
 */
START_TEST(test_strcpy4) {
    char dest_test[20] = "test";
    char src_test[20] = "thx";
    ck_assert_ptr_eq(s21_strcpy(dest_test, src_test), strcpy(dest_test, src_test));
}
END_TEST
/* Проверка программы при подаче пустой строки src(строка источник) в dest(строка, куда копируется src)
 * при этом src > dest
 */
START_TEST(test_strcpy5) {
    char dest_test[20] = "test";
    char src_test[20] = "Hello";
    ck_assert_ptr_eq(s21_strcpy(dest_test, src_test), strcpy(dest_test, src_test));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_strcpy1, *tc_strcpy2, *tc_strcpy3;
    s = suite_create("String s21_strcpy");
    tc_strcpy1 = tcase_create("Core_strcpy1");
    tcase_add_test(tc_strcpy1, test_strcpy1);
    tcase_add_test(tc_strcpy1, test_strcpy2);
    tcase_add_test(tc_strcpy1, test_strcpy3);
    suite_add_tcase(s, tc_strcpy1);
    tc_strcpy2 = tcase_create("Core_strcpy2");
    tcase_add_test(tc_strcpy2, test_strcpy4);
    suite_add_tcase(s, tc_strcpy2);
    tc_strcpy3 = tcase_create("Core_strcpy3");
    tcase_add_test(tc_strcpy3, test_strcpy5);
    suite_add_tcase(s, tc_strcpy3);
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
