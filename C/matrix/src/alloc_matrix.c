#include "s21_matrix.h"

double** alloc_matrix(int rows, int columns, int* status) {
  double** matrix = NULL;
  matrix = (double**)malloc(rows * sizeof(double*));
  *status = SUCCESS;
  if (matrix) {
    for (int i = 0; i < rows; i++) {
      matrix[i] = (double*)malloc(columns * sizeof(double));
      if (matrix[i]) {
        for (int j = 0; j < columns; j++) {
          matrix[i][j] = 0.0;
        }
      } else {
        // matrix = NULL;
        *status = FAILURE;
      }
    }
  } else {
    // matrix = NULL;
    *status = FAILURE;
  }
  return matrix;
}