#include "../header.h"

START_TEST(create_matrix_1) {
    matrix_t result;
    int rows = 2, columns = 10;
    int exit_code = s21_create_matrix(rows, columns, &result);
    ck_assert_int_eq(0, exit_code);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_2) {
    matrix_t result;
    int rows = 2, columns = 2;
    int exit_code = s21_create_matrix(rows, columns, &result);
    ck_assert_int_eq(0, exit_code);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_3) {
    matrix_t result;
    int rows = 0;
    int columns = 2;
    int exit_code = s21_create_matrix(rows, columns, &result);
    ck_assert_int_eq(1, exit_code);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_4) {
    matrix_t result;
    int rows = 0, columns = 0;
    int exit_code = s21_create_matrix(rows, columns, &result);
    ck_assert_int_eq(1, exit_code);
    s21_remove_matrix(&result);
}
END_TEST

Suite *sprintf_test(void) {
    Suite *s;
    TCase *tc_create_matrix;

    s = suite_create("s21_create_matrix");

    tc_create_matrix = tcase_create("s21_create_matrix");
    tcase_add_test(tc_create_matrix, create_matrix_1);
    tcase_add_test(tc_create_matrix, create_matrix_2);
    tcase_add_test(tc_create_matrix, create_matrix_3);
    tcase_add_test(tc_create_matrix, create_matrix_4);
    suite_add_tcase(s, tc_create_matrix);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = sprintf_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
