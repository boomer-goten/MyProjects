#ifndef _S21_3DVIEWER_H
#define _S21_3DVIEWER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// typedef struct matrix_struct {
//   double **matrix;
//   int rows;
//   int columns;
// } matrix_t;

typedef struct data_vertex  // вершины
{
  float **matrix_vertex;
  int count_v;
} data_vertex;

typedef struct data_facet  // грани
{
  unsigned *facets;
  int count_v_in_f;
  int count_f;
} data_facet;

enum m_errors {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALCULATION_ERROR = 2,
  MEMORY_FAIL = 3
};

int parsing_obj_file(data_vertex *v, data_facet *f, char *file_name);
int counting(data_vertex *v, data_facet *f, char *file_name);
int parsing(data_vertex *v, data_facet *f, char *file_name);
void parsing_vertex(char *str, data_vertex *v, int m);
int parsing_facet(char *str, data_facet *f, int *k);
void init_data_vertex(data_vertex *v);
void init_data_facet(data_facet *f);
int s21_create_matrix(int rows, int columns, data_vertex *result);
void s21_remove_matrix(data_vertex *A);
void find_min_max(data_vertex *vertex, float *min_X, float *max_X, float *min_Y,
                  float *max_Y, float *min_Z, float *max_Z);
void normalize(data_vertex *vertex);

// При передаче пустого указателя на структуру или матрицу возвращает 1
// При успехе возвращает 0
// у матрицы которая подается обязательно должно быть три столбца
// Перемещение матрицы по осям x,y,z
int matrix_of_move(float move_x, float move_y, float move_z,
                   data_vertex *result);
// Поворот матрицы по осям x,y,z
// Принимаем что наша система координат является правосторонней с положительным
// вращением по часовой стрелке
// Значения подаются в градусах При отрицательных
// значениях любого из мерок масштаба выкидывает ошибку 2
int matrix_of_turn(float x_angle, float y_angle, float z_angle,
                   data_vertex *result);
// Масштабирование матрицы по осям x,y,z
int matrix_of_scale(float scale, data_vertex *result);

#endif  // _S21_3DVIEWER_H
