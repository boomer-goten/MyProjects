#include "../header.h"

START_TEST(determinant_1) {
    matrix_t A;
    int rows = 5, columns = 5;
    s21_create_matrix(rows, columns, &A);
    double result = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
    matrix_t A;
    int rows = 6, columns = 6;
    s21_create_matrix(rows, columns, &A);
    double result = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), SUCCESS);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
    matrix_t A;
    int rows = 10, columns = 7;
    s21_create_matrix(rows, columns, &A);
    double result = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
    matrix_t A;
    A.matrix = NULL;
    double result = 0.0;
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_5) {
    matrix_t A;
    int rows = 4, columns = 4;
    s21_create_matrix(rows, columns, &A);
    double result = 0.0;
    A.matrix[0][0] = 4;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 6;
    A.matrix[0][3] = 7;
    A.matrix[1][0] = 8;
    A.matrix[1][1] = 12;
    A.matrix[1][2] = 11;
    A.matrix[1][3] = 9;
    A.matrix[2][0] = 3;
    A.matrix[2][1] = 7;
    A.matrix[2][2] = 4;
    A.matrix[2][3] = 5;
    A.matrix[3][0] = 6;
    A.matrix[3][1] = 9;
    A.matrix[3][2] = 10;
    A.matrix[3][3] = 4;
    s21_determinant(&A, &result);
    ck_assert_double_eq(result, -135);
    s21_remove_matrix(&A);
}
END_TEST

Suite *sprintf_test(void) {
    Suite *s;
    TCase *tc_determinant;

    s = suite_create("determinant");

    tc_determinant = tcase_create("determinant");
    tcase_add_test(tc_determinant, determinant_1);
    tcase_add_test(tc_determinant, determinant_2);
    tcase_add_test(tc_determinant, determinant_3);
    tcase_add_test(tc_determinant, determinant_4);
    tcase_add_test(tc_determinant, determinant_5);
    suite_add_tcase(s, tc_determinant);

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
