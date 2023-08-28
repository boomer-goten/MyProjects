#include "s21_3DViewer.h"

void find_min_max(data_vertex* vertex, float* min_X, float* max_X, float* min_Y,
                  float* max_Y, float* min_Z, float* max_Z) {
  *max_X = (vertex->matrix_vertex[0][0]);
  *min_X = *max_X;
  *max_Y = (vertex->matrix_vertex[0][1]);
  *min_Y = *max_Y;
  *max_Z = (vertex->matrix_vertex[0][2]);
  *min_Z = *max_Z;
  float* tmp = NULL;
  for (int i = 0; i < vertex->count_v; ++i) {
    for (int j = 0; j < 3; ++j) {
      tmp = vertex->matrix_vertex[i];
      if (tmp[0] > *max_X) *max_X = tmp[0];
      if (tmp[0] < *min_X) *min_X = tmp[0];
      if (tmp[1] > *max_Y) *max_Y = tmp[1];
      if (tmp[1] < *min_Y) *min_Y = tmp[1];
      if (tmp[2] > *max_Z) *max_Z = tmp[2];
      if (tmp[2] < *min_Z) *min_Z = tmp[2];
    }
  }
}
