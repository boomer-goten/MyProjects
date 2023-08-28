#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

// Вспомогательные функции для создания матрица и ее проверка корректности
double** alloc_matrix(int rows, int columns, int* status);
int check_alloc_parametrs(matrix_t* result);
void create_minor_matrix(matrix_t* original, matrix_t* minor, int rows,
                         int columns);
int only_for_equal(matrix_t* result);
double s21_rek_deter(matrix_t A, int size);

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

#endif  // SRC_S21_MATRIX_H_