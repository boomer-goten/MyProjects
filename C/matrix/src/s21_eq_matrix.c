#include "s21_matrix.h"
#define SUCCESS_EQ 1
#define FAILURE_EQ 0
#define DELTA 1e-6

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS_EQ;
  if (A && A->rows > 0 && A->columns > 0 && A->matrix && B && B->rows > 0 &&
      B->columns > 0 && B->matrix) {
    if (only_for_equal(A) == SUCCESS && only_for_equal(B) == SUCCESS) {
      if (A->rows == B->rows && A->columns == B->columns) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (fabs(A->matrix[i][j] - B->matrix[i][j]) > DELTA) {
              status = FAILURE_EQ;
              break;
            }
          }
          if (status == FAILURE_EQ) {
            break;
          }
        }
      } else {
        status = FAILURE_EQ;
      }
    } else {
      status = FAILURE_EQ;
    }
  } else {
    status = FAILURE_EQ;
  }
  return status;
}
