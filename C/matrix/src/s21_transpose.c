#include "s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (check_alloc_parametrs(A) == SUCCESS) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}
