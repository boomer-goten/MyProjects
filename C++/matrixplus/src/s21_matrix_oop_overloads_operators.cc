#include "s21_matrix_oop.h"

// This file defines overloaded class operators S21Matrix

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= columns_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect value, indexes are outside the array");
  }
  return matrix_[row][col];
}
// the method SumMatrix itself will throw an exception if necessary
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result_sum(*this);
  result_sum.SumMatrix(other);
  return result_sum;
}

// the method SubMatrix itself will throw an exception if necessary
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result_sum(*this);
  result_sum.SubMatrix(other);
  return result_sum;
}

// the method MulMatrix itself will throw an exception if necessary
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result_sum(*this);
  result_sum.MulMatrix(other);
  return result_sum;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) noexcept {
  this->setColumns(other.columns_);
  this->setRows(other.rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}
