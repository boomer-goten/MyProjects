#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>
#include <new>

#define S21MATRIX_DELTA 1e-6

class S21Matrix {
 private:
  // attributes
  int rows_, columns_;  // rows and columns attributes
  double** matrix_;  // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int columns);   // parameterized constructor
  S21Matrix(const S21Matrix& other);  // copy cnstructor
  S21Matrix(S21Matrix&& other);       // move cnstructor
  ~S21Matrix();                       // destructor

  // friends functions
  // defines a matrix of certain dimensions
  friend double** CreateMatrix(int& rows, int& columns);
  // cretate minor matrix
  friend void CreateMinorMatrix(S21Matrix& original, S21Matrix& minor, int row,
                                int column);

  // operators overloads
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);

  // some public methods
  // Checks matrices for equality with each other
  bool EqMatrix(const S21Matrix& other) noexcept;
  // Adds the second matrix to the current one
  void SumMatrix(const S21Matrix& other);
  // Subtracts another matrix from the current one
  void SubMatrix(const S21Matrix& other);
  // Multiplies the current matrix by a number
  void MulNumber(const double num) noexcept;
  // Multiplies the current matrix by the second matrix
  void MulMatrix(const S21Matrix& other);
  // Creates a new transposed matrix from the current one and returns it
  S21Matrix Transpose() noexcept;
  // Calculates the algebraic addition matrix of the current one and returns it
  S21Matrix CalcComplements();
  // Calculates and returns the determinant of the current matrix
  double Determinant();
  // Calculates and returns the inverse matrix
  S21Matrix InverseMatrix();

  // set methods
  // fills the matrix with random values
  void setMatrixRandomValue() noexcept;
  void setRows(int rows);
  void setColumns(int columns);
  // get methods
  double** getMatrix() noexcept;
  int getRows();
  int getColumns();
};

#endif
