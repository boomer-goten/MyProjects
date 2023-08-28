#include "../header.h"
/* Проверка поведения программы при нормальной работе функции не в краевых случаях
 * подается число, которое входит в диапозон ошибок
 */
START_TEST(test_strerror1) {
    int errnum = 50;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при нормальной работе функции не в краевых случаях
 * подается число, которое входит в диапозон ошибок
 */
START_TEST(test_strerror2) {
    int errnum = 70;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при нормальной работе функции в краевых случаях
 * подается число, которое не входит в диапозон ошибок
 */
START_TEST(test_strerror3) {
    int errnum = 0;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при нормальной работе функции в краевых случаях
 * подается число, которое не входит в диапозон ошибок
 */
START_TEST(test_strerror4) {
    int errnum = 150;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при нормальной работе функции в краевых случаях
 * подается число, которое не входит в диапозон ошибок
 */
START_TEST(test_strerror5) {
    int errnum = -10;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при ненормальной работе функции в краевых случаях
 * подается неправильное число(типа float без приведения), которое входит в диапозон ошибок
 */
START_TEST(test_strerror6) {
    int errnum = (int)1.5;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST
/* Проверка поведения программы при ненормальной работе функции в краевых случаях
 * подается неправильное число(типа float с приведением), которое не входит в диапозон ошибок
 */
START_TEST(test_strerror7) {
    float errnum = 1.5;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_strerror1, *tc_strerror2, *tc_strerror3;
    s = suite_create("String strerror");
    tc_strerror1 = tcase_create("Core_strerror1");
    tcase_add_test(tc_strerror1, test_strerror1);
    tcase_add_test(tc_strerror1, test_strerror2);
    suite_add_tcase(s, tc_strerror1);
    tc_strerror2 = tcase_create("Core_strerror2");
    tcase_add_test(tc_strerror2, test_strerror3);
    tcase_add_test(tc_strerror2, test_strerror4);
    tcase_add_test(tc_strerror2, test_strerror5);
    suite_add_tcase(s, tc_strerror2);
    tc_strerror3 = tcase_create("Core_strerror3");
    tcase_add_test(tc_strerror3, test_strerror6);
    tcase_add_test(tc_strerror3, test_strerror7);
    suite_add_tcase(s, tc_strerror3);
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
