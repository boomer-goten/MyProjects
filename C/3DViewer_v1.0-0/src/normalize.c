#include "s21_3DViewer.h"

void normalize(data_vertex* vertex) {
  float min_X = 0., max_X = 0., min_Y = 0., max_Y = 0., min_Z = 0., max_Z = 0.;
  float center_X = 0, center_Y = 0., center_Z = 0.;
  float scale = 0;
  find_min_max(vertex, &min_X, &max_X, &min_Y, &max_Y, &min_Z, &max_Z);
  center_X = (min_X + max_X) / 2.;
  center_Y = (min_Y + max_Y) / 2.;
  center_Z = (min_Z + max_Z) / 2.;
  max_X -= center_X;
  max_Y -= center_Y;
  max_Z -= center_Z;
  scale = max_X;
  if (max_Y >= scale) scale = max_Y;
  if (max_Z > scale) scale = max_Z;
  for (int i = 0; i < vertex->count_v; ++i) {
    vertex->matrix_vertex[i][0] -= center_X;
    vertex->matrix_vertex[i][1] -= center_Y;
    vertex->matrix_vertex[i][2] -= center_Z;
    vertex->matrix_vertex[i][0] /= scale;
    vertex->matrix_vertex[i][1] /= scale;
    vertex->matrix_vertex[i][2] /= scale;
    vertex->matrix_vertex[i][2] -= 1.;
  }
}
