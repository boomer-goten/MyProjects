#include "s21_matrix_oop.h"

// This file defines the class methods and also defines a friend function
// CreateMinorMatrix

// The function creates a matrix based on the original without i row and j
// column
void CreateMinorMatrix(S21Matrix& original, S21Matrix& minor, int row,
                       int column) {
  int i_minor = 0;
  int j_minor = 0;
  int original_rows = original.getRows();
  int original_cols = original.getColumns();
  double** original_matrix = original.getMatrix();
  double** minor_matrix = minor.getMatrix();
  for (int i = 0; i < original_rows; i++) {
    j_minor = 0;
    if (i == row) continue;
    for (int j = 0; j < original_cols; j++) {
      if (j == column) continue;
      minor_matrix[i_minor][j_minor] = original_matrix[i][j];
      j_minor++;
    }
    i_minor++;
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  bool status_equal = true;
  if (matrix_ && other.matrix_ && rows_ == other.rows_ &&
      columns_ == other.columns_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < columns_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > S21MATRIX_DELTA) {
          status_equal = false;
        }
      }
    }
  } else {
    status_equal = false;
  }
  return status_equal;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || columns_ != other.columns_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (columns_ != other.rows_) {
    throw std::out_of_range(
        "Incorrect input, the number of columns of one matrix must be equal to "
        "the number of rows of another matrix");
  }
  S21Matrix tmp_matrix(rows_, other.columns_);
  double tmp_value = 0.0;
  for (int i = 0; i < tmp_matrix.rows_; i++) {
    for (int j = 0; j < tmp_matrix.columns_; j++) {
      for (int y = 0; y < columns_; y++) {
        tmp_value += matrix_[i][y] * other.matrix_[y][j];
      }
      tmp_matrix.matrix_[i][j] = tmp_value;
      tmp_value = 0.0;
    }
  }
  std::swap(matrix_, tmp_matrix.matrix_);
  std::swap(columns_, tmp_matrix.columns_);
}

S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix Transpose_matrix(columns_, rows_);
  for (int i = 0; i < Transpose_matrix.rows_; i++) {
    for (int j = 0; j < Transpose_matrix.columns_; j++) {
      Transpose_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return Transpose_matrix;
}

// The matrix determinant is found by the Gaussian method with the choice of the
// main element (That is, the rows change until the maximum values of the column
// are on the main diagonal)
double S21Matrix::Determinant() {
  if (columns_ != rows_) {
    throw std::out_of_range("Incorrect input, matrix must be square");
  }
  S21Matrix triangular_matrix(*this);
  int flag_permutation_rows = 1;
  // main element selection
  for (int j = 0; j < columns_ - 1; j++) {
    double max_col_value = matrix_[j][j];
    for (int i = j + 1; i < rows_; i++) {
      if (fabs(matrix_[i][j]) > fabs(max_col_value)) {
        max_col_value = matrix_[i][j];
        std::swap(triangular_matrix.matrix_[i], triangular_matrix.matrix_[j]);
        flag_permutation_rows *= -1;
      }
    }
  }
  for (int k = 1; k < rows_; k++) {
    for (int i = k; i < rows_; i++) {
      if (fabs(triangular_matrix.matrix_[k - 1][k - 1]) < S21MATRIX_DELTA)
        break;
      double сoeff = triangular_matrix.matrix_[i][k - 1] /
                     triangular_matrix.matrix_[k - 1][k - 1];
      for (int j = 0; j < columns_; j++)
        triangular_matrix.matrix_[i][j] =
            triangular_matrix.matrix_[i][j] -
            triangular_matrix.matrix_[k - 1][j] * сoeff;
    }
  }

  double determinant = 1.0 * flag_permutation_rows;
  for (int i = 0; i != triangular_matrix.rows_; i++) {
    determinant *= triangular_matrix.matrix_[i][i];
  }
  return determinant;
}

S21Matrix S21Matrix::CalcComplements() {
  if (columns_ != rows_) {
    throw std::out_of_range("Incorrect input, matrix must be square");
  }
  S21Matrix CalcComplementsMatrix(this->rows_, this->columns_);
  double** result_matrix = CalcComplementsMatrix.getMatrix();
  S21Matrix MinorMatrix(this->rows_ - 1, this->columns_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      double minor_determinant = 0.0;
      CreateMinorMatrix(*this, MinorMatrix, i, j);
      minor_determinant = MinorMatrix.Determinant();
      if ((i + j) % 2 == 0) {
        result_matrix[i][j] = minor_determinant;
      } else {
        result_matrix[i][j] = minor_determinant * (-1);
      }
    }
  }
  return CalcComplementsMatrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (fabs(determinant) < S21MATRIX_DELTA) {
    throw std::domain_error("Incorrect value determinant must not be equal 0");
  }
  S21Matrix AlgerbrDop = this->CalcComplements();
  S21Matrix TransposeMatrix = AlgerbrDop.Transpose();
  TransposeMatrix.MulNumber(1 / determinant);
  return TransposeMatrix;
}