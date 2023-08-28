#include "s21_3DViewer.h"

int parsing_obj_file(
    data_vertex *v, data_facet *f,
    char *file_name) {  // основная функция, которую вызываем из qt
  init_data_vertex(v);
  init_data_facet(f);
  int res = counting(v, f, file_name);
  if (res == 0) {
    res = parsing(v, f, file_name);
  }
  return res;
}

int counting(data_vertex *v, data_facet *f, char *file_name) {
  int res = 0;
  FILE *obj = NULL;
  obj = fopen(file_name, "r");
  if (obj != NULL) {
    char *str = NULL;
    size_t read = 0, len = 0;
    while ((read = getline(&str, &len, obj)) != (size_t)-1) {
      if (str[0] == 'v' && str[1] == ' ') {
        v->count_v++;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        for (int i = 1; str[i]; i++) {
          if (str[i] == ' ' &&
              ((i + 1) <= (int)strlen(str) && str[i + 1] != ' ' &&
               str[i + 1] != '\n' && str[i + 1] != '\0')) {
            f->count_v_in_f++;
          }
        }
      }
    }
    free(str);
    fclose(obj);
  } else {
    res = 1;
  }
  f->count_v_in_f *= 2;
  return res;
}

int parsing(data_vertex *v, data_facet *f, char *file_name) {
  s21_create_matrix(v->count_v, 3, v);
  if (f->count_v_in_f > 0) {
    f->facets = (unsigned *)calloc((size_t)f->count_v_in_f, sizeof(unsigned));
  }
  int res = 0;
  FILE *obj = NULL;
  obj = fopen(file_name, "r");
  if (obj != NULL) {
    char *str = NULL;
    size_t read = 0, len = 0;
    int m = 0, k = 0, count_index = 0;
    while ((read = getline(&str, &len, obj)) != (size_t)-1) {
      if (str[0] == 'v' && str[1] == ' ') {
        parsing_vertex(str, v, m);
        m++;
      }
      if (str[0] == 'f' && str[1] == ' ') {
        count_index = parsing_facet(str, f, &k);
        if (count_index == 2) {
          f->count_f += 1;
        }
        if (count_index > 2) {
          f->count_f += count_index;
        }
      }
    }
    free(str);
    fclose(obj);
  } else {
    res = 1;
    if (f->facets != NULL) {
      free(f->facets);
    }
    s21_remove_matrix(v);
  }
  return res;
}

void parsing_vertex(char *str, data_vertex *v, int m) {
  int n = 0;
  for (int i = 1; i < (int)strlen(str); i++) {
    if (str[i] == ' ' &&
        (i + 1 <= (int)strlen(str) && str[i + 1] != ' ' && str[i + 1] != '\n' &&
         str[i + 1] != '\0' && n < v->count_v)) {
      sscanf(&str[i + 1], "%f", &v->matrix_vertex[m][n]);
      n++;
    }
  }
}

int parsing_facet(char *str, data_facet *f, int *k) {
  int j = *k;
  unsigned first_vertex_index;
  int first_index_check = 0;
  unsigned vertex_index;
  int count_index = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == ' ' &&
        (i + 1 <= (int)strlen(str) && str[i + 1] != ' ' && str[i + 1] != '\n' &&
         str[i + 1] != '\0' && j < f->count_v_in_f)) {
      count_index++;
      if (first_index_check == 0) {
        sscanf(&str[i + 1], "%u", &first_vertex_index);
        f->facets[j++] = first_vertex_index - 1;
        first_index_check++;
      } else {
        sscanf(&str[i + 1], "%u", &vertex_index);
        f->facets[j++] = vertex_index - 1;
        f->facets[j++] = vertex_index - 1;
      }
    }
  }
  if (count_index) f->facets[j++] = first_vertex_index - 1;
  *k = j;
  return count_index;
}

void init_data_vertex(data_vertex *v) {
  v->matrix_vertex = NULL;
  v->count_v = 0;
}

void init_data_facet(data_facet *f) {
  f->facets = NULL;
  f->count_v_in_f = 0;
  f->count_f = 0;
}

int s21_create_matrix(int rows, int columns, data_vertex *result) {
  int res = OK;
  if (rows <= 0 || columns <= 0) {
    res = INCORRECT_MATRIX;
  } else {
    result->count_v = rows;
    result->matrix_vertex = (float **)calloc(rows, sizeof(float *));
    float *values = (float *)calloc(rows * columns, sizeof(float));
    if (!result->matrix_vertex || !values) return MEMORY_FAIL;
    for (int i = 0; i < rows; i++) {
      result->matrix_vertex[i] = values + columns * i;
    }
  }
  return res;
}

void s21_remove_matrix(data_vertex *A) {
  if (A->matrix_vertex) {
    free(A->matrix_vertex[0]);
    free(A->matrix_vertex);
  }
  if (A->count_v) {
    A->count_v = 0;
  }
  A->matrix_vertex = NULL;
}

// int main() {
//   char name[] = "test.obj";
//   data_vertex v;
//   data_facet f;
//   parsing_obj_file(&v, &f, name);

//   for (int i = 0; i < v.count_v; i++) {
//     for (int j = 0; j < 3; j++) {
//       printf("%.6f ", v.matrix_vertex[i][j]);
//     }
//     printf("\n");
//   }

//   for (int i = 0; i < f.count_v_in_f; i++) {
//     printf("%u _ ", f.facets[i]);
//   }

//   if (f.facets != NULL) {
//     free(f.facets);
//   }
//   s21_remove_matrix(&v);
// }
