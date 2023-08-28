#include "s21_3DViewer.h"

int matrix_of_move(float move_x, float move_y, float move_z,
                   data_vertex* result) {
  if (!result || !result->matrix_vertex) {
    return 1;
  } else {
    for (int i = 0; i < result->count_v; i++) {
      result->matrix_vertex[i][0] += move_x;
      result->matrix_vertex[i][1] += move_y;
      result->matrix_vertex[i][2] += move_z;
    }
  }
  return 0;
}

int matrix_of_turn(float x_angle, float y_angle, float z_angle,
                   data_vertex* result) {
  if (!result || !result->matrix_vertex) {
    return 1;
  } else {
    float x1 = cosf(y_angle * M_PI / 180) * cosf(z_angle * M_PI / 180);
    float x2 = sinf(x_angle * M_PI / 180) * sinf(y_angle * M_PI / 180) *
                   cosf(z_angle * M_PI / 180) -
               sinf(z_angle * M_PI / 180) * cosf(x_angle * M_PI / 180);
    float x3 = sinf(x_angle * M_PI / 180) * sinf(z_angle * M_PI / 180) +
               sinf(y_angle * M_PI / 180) * cosf(x_angle * M_PI / 180) *
                   cosf(z_angle * M_PI / 180);
    float y1 = sinf(z_angle * M_PI / 180) * cosf(y_angle * M_PI / 180);
    float y2 = sinf(x_angle * M_PI / 180) * sinf(y_angle * M_PI / 180) *
                   sinf(z_angle * M_PI / 180) +
               cosf(z_angle * M_PI / 180) * cosf(x_angle * M_PI / 180);
    float y3 = sinf(y_angle * M_PI / 180) * sinf(z_angle * M_PI / 180) *
                   cosf(x_angle * M_PI / 180) -
               sinf(x_angle * M_PI / 180) * cosf(z_angle * M_PI / 180);
    float z1 = -sinf(y_angle * M_PI / 180);
    float z2 = sinf(x_angle * M_PI / 180) * cosf(y_angle * M_PI / 180);
    float z3 = cosf(x_angle * M_PI / 180) * cosf(y_angle * M_PI / 180);
    float tmp_x = 0;
    float tmp_y = 0;
    float tmp_z = 0;
    for (int i = 0; i < result->count_v; i++) {
      tmp_x = result->matrix_vertex[i][0];
      tmp_y = result->matrix_vertex[i][1];
      tmp_z = result->matrix_vertex[i][2];
      result->matrix_vertex[i][0] = tmp_x * x1 + tmp_y * y1 + tmp_z * z1;
      result->matrix_vertex[i][1] = tmp_x * x2 + tmp_y * y2 + tmp_z * z2;
      result->matrix_vertex[i][2] = tmp_x * x3 + tmp_y * y3 + tmp_z * z3;
    }
  }
  return 0;
}

int matrix_of_scale(float scale, data_vertex* result) {
  if (!result || !result->matrix_vertex) {
    return 1;
  } else if (scale < 1e-3) {
    return 2;
  } else {
    for (int i = 0; i < result->count_v; i++) {
      result->matrix_vertex[i][0] *= scale;
      result->matrix_vertex[i][1] *= scale;
      result->matrix_vertex[i][2] *= scale;
    }
  }
  return 0;
}

// int main() {
//   matrix_t matrix = {0};
//   s21_create_matrix(10, 3, &matrix);
//   for (int i = 0; i < 10; i++) {
//     matrix.matrix[i][0] = i + 1;
//     matrix.matrix[i][1] = i + 1;
//     matrix.matrix[i][2] = i + 1;
//     printf("%lf %lf %lf\n", matrix.matrix[i][0], matrix.matrix[i][1],
//            matrix.matrix[i][2]);
//   }
//   printf("\n");
//   matrix_of_move(2, 3, 2, &matrix);
//   for (int i = 0; i < 10; i++) {
//     printf("%lf %lf %lf\n", matrix.matrix[i][0], matrix.matrix[i][1],
//            matrix.matrix[i][2]);
//   }
//   printf("\n");
//   matrix_of_scale(-3, 1, 2, &matrix);
//   for (int i = 0; i < 10; i++) {
//     printf("%lf %lf %lf\n", matrix.matrix[i][0], matrix.matrix[i][1],
//            matrix.matrix[i][2]);
//   }
//   printf("\n");
//   matrix_of_turn(75, 0, 0, &matrix);
//   for (int i = 0; i < 10; i++) {
//     printf("%lf %lf %lf\n", matrix.matrix[i][0], matrix.matrix[i][1],
//            matrix.matrix[i][2]);
//   }
//   s21_remove_matrix(&matrix);
// }