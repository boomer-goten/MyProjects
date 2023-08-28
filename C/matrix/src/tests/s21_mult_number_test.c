#include "../header.h"

START_TEST(mult_1) {
    matrix_t A, result;
    int rows = 5, columns = 5;
    double number = (double)(rand()) / RAND_MAX;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j], 1e-8);
        }
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_2) {
    matrix_t A, result;
    int rows = 5, columns = 5;
    double number = (double)(rand()) / RAND_MAX;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j], 1e-8);
        }
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_3) {
    matrix_t A, result;
    int rows = 5, columns = 5;
    double number = (double)(rand()) / RAND_MAX;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j], 1e-8);
        }
    }
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_4) {
    matrix_t A, result;
    A.matrix = NULL;
    double number = (double)(rand()) / RAND_MAX;
    ck_assert_int_eq(s21_mult_number(&A, number, &result), 1);
}
END_TEST

START_TEST(mult_5) {
    matrix_t A, result;
    int Arows = 0, Acolumns = 0;
    double number = (double)(rand()) / RAND_MAX;
    s21_create_matrix(Arows, Acolumns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, &result), 1);
    s21_remove_matrix(&A);
}
END_TEST

Suite *sprintf_test(void) {
    Suite *s;
    TCase *tc_mult_number;

    s = suite_create("mult_number");

    tc_mult_number = tcase_create("mult_number");
    tcase_add_test(tc_mult_number, mult_1);
    tcase_add_test(tc_mult_number, mult_2);
    tcase_add_test(tc_mult_number, mult_3);
    tcase_add_test(tc_mult_number, mult_4);
    tcase_add_test(tc_mult_number, mult_5);
    suite_add_tcase(s, tc_mult_number);

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
