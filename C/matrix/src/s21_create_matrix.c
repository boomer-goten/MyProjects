#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int status = INCORRECT_MATRIX;
  result->rows = rows;
  result->columns = columns;
  if (rows > 0 && columns > 0) {
    result->matrix = alloc_matrix(rows, columns, &status);
    if (status == SUCCESS) {
      status = check_alloc_parametrs(result);
    }
  }
  return status;
}
