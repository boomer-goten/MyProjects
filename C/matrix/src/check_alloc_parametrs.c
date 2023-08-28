#include "s21_matrix.h"

int check_alloc_parametrs(matrix_t* result) {
  int status = SUCCESS;
  if (result->matrix) {
    if (result->rows <= 0 || result->columns <= 0) {
      status = FAILURE;
    } else if (result->rows > 0 && result->columns > 0) {
      int space = 0;
      for (int i = 0; i < result->rows; i++) {
        if (result->matrix[i]) {
          for (int j = 0; j < result->columns; j++) {
            space++;
          }
        }
      }
      if (space != (result->columns * result->rows)) {
        status = FAILURE;
      }
    }
  } else {
    status = FAILURE;
  }
  return status;
}