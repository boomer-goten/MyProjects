#include "s21_matrix.h"

void create_minor_matrix(matrix_t* original, matrix_t* minor, int rows,
                         int columns) {
  int i_min = 0;
  int j_min = 0;
  for (int i = 0; i < original->rows; i++) {
    j_min = 0;
    if (i == rows) continue;
    for (int j = 0; j < original->columns; j++) {
      if (j == columns) continue;
      minor->matrix[i_min][j_min] = original->matrix[i][j];
      j_min++;
    }
    i_min++;
  }
}