#include "../header.h"
/* Проверка поведения программы при нормальной работе функции не в краевых случаях
 * В первой строке str1 содержиться символ из str2
 */
START_TEST(test_strcspn1) {
    int flag = 0;
    char str1_test[20] = "0123456789";
    char str2_test[20] = "52";
    if (strcspn(str1_test, str2_test) == s21_strcspn(str1_test, str2_test)) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST
/* Проверка поведения программы при нормальной работе функции не в краевых случаях
 * В первой строке str1 не содержиться символ из str2
 */
START_TEST(test_strcspn2) {
    int flag = 0;
    char str1_test[20] = "0123456789";
    char str2_test[20] = "g";
    if (strcspn(str1_test, str2_test) == s21_strcspn(str1_test, str2_test)) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST
/* Проверка поведения программы при пустой строке str1
 * В первой строке str1 не содержиться символ из str2
 */
START_TEST(test_strcspn3) {
    int flag = 0;
    char str1_test[20] = "";
    char str2_test[20] = "g";
    if (strcspn(str1_test, str2_test) == s21_strcspn(str1_test, str2_test)) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST
/* Проверка поведения программы при пустой строке str2
 * В первой строке str1 не содержиться символ из str2
 */
START_TEST(test_strcspn4) {
    int flag = 0;
    char str1_test[20] = "0123456789";
    char str2_test[20] = "";
    if (strcspn(str1_test, str2_test) == s21_strcspn(str1_test, str2_test)) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST
/* Проверка поведения программы при пустой строке при наличии '\n'
 * В первой строке str1 содержиться символ из str2
 */
START_TEST(test_strcspn5) {
    int flag = 0;
    char str1_test[20] = "01\n2345 6789";
    char str2_test[20] = "89";
    if (strcspn(str1_test, str2_test) == s21_strcspn(str1_test, str2_test)) {
        flag = 1;
    }
    ck_assert_int_eq(flag, 1);
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_strcspn1, *tc_strcspn2, *tc_strcspn3;
    s = suite_create("String strcspn");
    tc_strcspn1 = tcase_create("Core_strcspn1");
    tcase_add_test(tc_strcspn1, test_strcspn1);
    tcase_add_test(tc_strcspn1, test_strcspn2);
    suite_add_tcase(s, tc_strcspn1);
    tc_strcspn2 = tcase_create("Core_strcspn2");
    tcase_add_test(tc_strcspn2, test_strcspn3);
    tcase_add_test(tc_strcspn2, test_strcspn4);
    suite_add_tcase(s, tc_strcspn2);
    tc_strcspn3 = tcase_create("Core_strcspn3");
    tcase_add_test(tc_strcspn3, test_strcspn5);
    suite_add_tcase(s, tc_strcspn3);
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
