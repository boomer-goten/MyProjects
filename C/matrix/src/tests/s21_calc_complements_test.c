#include "../header.h"

START_TEST(calc_complements_1) {
    matrix_t A, result;
    int rows = 5, columns = 5;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_2) {
    matrix_t A, result;
    int rows = 6, columns = 6;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
    matrix_t A, result;
    int rows = 10, columns = 7;
    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            A.matrix[i][j] = (double)(rand()) / RAND_MAX;
        }
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_4) {
    matrix_t A, result;
    A.matrix = NULL;
    result.matrix = NULL;
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(calc_complements_5) {
    matrix_t A, result, result_true;
    int rows = 3, columns = 3;
    int sum = 0;
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &result_true);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;
    result_true.matrix[0][0] = 0;
    result_true.matrix[0][1] = 10;
    result_true.matrix[0][2] = -20;
    result_true.matrix[1][0] = 4;
    result_true.matrix[1][1] = -14;
    result_true.matrix[1][2] = 8;
    result_true.matrix[2][0] = -8;
    result_true.matrix[2][1] = -2;
    result_true.matrix[2][2] = 4;
    s21_calc_complements(&A, &result);
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.columns; j++) {
            if (fabs(result.matrix[i][j] - result_true.matrix[i][j]) > 1e-8) {
                sum++;
            }
        }
    }
    ck_assert_int_eq(sum, 0);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result_true);
    s21_remove_matrix(&result);
}
END_TEST

Suite *sprintf_test(void) {
    Suite *s;
    TCase *tc_calc_complements;

    s = suite_create("calc_complements");

    tc_calc_complements = tcase_create("calc_complements");
    tcase_add_test(tc_calc_complements, calc_complements_1);
    tcase_add_test(tc_calc_complements, calc_complements_2);
    tcase_add_test(tc_calc_complements, calc_complements_3);
    tcase_add_test(tc_calc_complements, calc_complements_4);
    tcase_add_test(tc_calc_complements, calc_complements_5);
    suite_add_tcase(s, tc_calc_complements);

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
