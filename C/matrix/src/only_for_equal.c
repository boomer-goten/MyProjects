#include "s21_matrix.h"

int only_for_equal(matrix_t* result) {
  int status = SUCCESS;
  if (!result || !result->matrix) {
    status = FAILURE;
  }
  return status;
}