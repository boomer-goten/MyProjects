#include "s21_matrix_oop.h"
// This file defines the constructors and destructors of the class S21Matrix, as
// well as the mutators of this class, and also defines a friend function
// CreateMatrix

double** CreateMatrix(int& rows, int& columns) {
  double** pointer_matrix = nullptr;
  try {
    pointer_matrix = new double*[rows]();
    for (int i = 0; i < rows; i++) {
      pointer_matrix[i] = new double[columns]();
    }
  } catch (std::bad_alloc& error) {
    std::cout << "bad_alloc: " << error.what() << std::endl;
    for (int j = 0; j < rows; j++) {
      if (pointer_matrix[j]) delete[] pointer_matrix[j];
    }
    if (pointer_matrix) {
      delete[] pointer_matrix;
    }
    pointer_matrix = nullptr;
    rows = 0;
    columns = 0;
  }
  return pointer_matrix;
}

S21Matrix::S21Matrix() : rows_(3), columns_(3) {
  matrix_ = CreateMatrix(rows_, columns_);
}

S21Matrix::S21Matrix(int rows, int columns) {
  if (rows <= 0 || columns <= 0) {
    throw std::domain_error(
        "Incorrect input, the matrix must have the correct size");
  }
  rows_ = rows;
  columns_ = columns;
  matrix_ = CreateMatrix(rows, columns);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), columns_(other.columns_) {
  matrix_ = CreateMatrix(rows_, columns_);
  for (int i = 0; i < rows_; i++) {
    std::memcpy(matrix_[i], other.matrix_[i], sizeof(double) * columns_);
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), columns_(other.columns_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.columns_ = 0;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  if (matrix_) {
    delete[] matrix_;
  }
}

double** S21Matrix::getMatrix() noexcept { return matrix_; }

int S21Matrix::getRows() { return rows_; }

int S21Matrix::getColumns() { return columns_; }

void S21Matrix::setMatrixRandomValue() noexcept {
  for (int i = 0; i != rows_; i++) {
    for (int j = 0; j != columns_; j++) {
      matrix_[i][j] = rand() % 10;
    }
  }
}

void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw std::domain_error(
        "Incorrect input, the matrix must have the correct size");
  }
  if (rows_ != rows) {
    double** new_matrix_ = CreateMatrix(rows, columns_);
    int i = 0;
    for (; i < (rows_ < rows ? rows_ : rows); i++) {
      std::memcpy(new_matrix_[i], matrix_[i], sizeof(double) * columns_);
      delete[] matrix_[i];
    }
    if (rows_ > rows) {
      for (int j = i + 1; j != rows_; j++) {
        delete[] matrix_[j];
      }
    }
    delete[] matrix_;
    rows_ = rows;
    matrix_ = new_matrix_;
  }
}

void S21Matrix::setColumns(int cols) {
  if (cols <= 0) {
    throw std::domain_error(
        "Incorrect input, the matrix must have the correct size");
  }
  if (cols != columns_) {
    double** new_matrix_ = CreateMatrix(rows_, cols);
    for (int i = 0; i < rows_; i++) {
      std::memcpy(new_matrix_[i], matrix_[i],
                  sizeof(double) * (columns_ <= cols ? columns_ : cols));
      delete[] matrix_[i];
    }
    delete[] matrix_;
    columns_ = cols;
    matrix_ = new_matrix_;
  }
}