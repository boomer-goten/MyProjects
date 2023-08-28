#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (A && A->rows > 0 && A->columns > 0 && A->matrix && result) {
    if (A->rows == A->columns) {
      double det = 0.0;
      s21_determinant(A, &det);
      if (fabs(det - 0.0) > 1e-6) {
        matrix_t algebr_dop = {0};
        matrix_t transpose_algebr_dop = {0};
        s21_calc_complements(A, &algebr_dop);
        s21_transpose(&algebr_dop, &transpose_algebr_dop);
        s21_mult_number(&transpose_algebr_dop, 1.0 / det, result);
        s21_remove_matrix(&algebr_dop);
        s21_remove_matrix(&transpose_algebr_dop);
      } else {
        status = CALCULATION_ERROR;
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}
