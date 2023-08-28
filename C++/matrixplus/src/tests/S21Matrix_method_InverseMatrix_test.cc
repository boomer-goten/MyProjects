#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodInverseMatrix1) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  S21Matrix true_result(4, 4);
  matrix_1(0, 0) = 0;
  matrix_1(0, 1) = 3;
  matrix_1(0, 2) = -1;
  matrix_1(0, 3) = 2;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 1;
  matrix_1(1, 2) = 0;
  matrix_1(1, 3) = 0;
  matrix_1(2, 0) = -2;
  matrix_1(2, 1) = -1;
  matrix_1(2, 2) = 0;
  matrix_1(2, 3) = 2;
  matrix_1(3, 0) = -5;
  matrix_1(3, 1) = 7;
  matrix_1(3, 2) = 1;
  matrix_1(3, 3) = 1;

  true_result(0, 0) = -1.0 / 25;
  true_result(0, 1) = 23.0 / 50;
  true_result(0, 2) = 3.0 / 50;
  true_result(0, 3) = -1.0 / 25;
  true_result(1, 0) = 2.0 / 25;
  true_result(1, 1) = 2.0 / 25;
  true_result(1, 2) = -3.0 / 25;
  true_result(1, 3) = 2.0 / 25;
  true_result(2, 0) = -19.0 / 25;
  true_result(2, 1) = 31.0 / 25;
  true_result(2, 2) = 16.0 / 25;
  true_result(2, 3) = 6.0 / 25;
  true_result(3, 0) = 0;
  true_result(3, 1) = 1.0 / 2;
  true_result(3, 2) = 1.0 / 2;
  true_result(3, 3) = 0;
  matrix_2 = matrix_1.InverseMatrix();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_NEAR(matrix_2(i, j), true_result(i, j), S21MATRIX_DELTA);
    }
  }
}

TEST(S21Matrix, MethodInverseMatrix2) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix true_result;
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 5;
  matrix_1(0, 2) = 7;
  matrix_1(1, 0) = 6;
  matrix_1(1, 1) = 3;
  matrix_1(1, 2) = 4;
  matrix_1(2, 0) = 5;
  matrix_1(2, 1) = -2;
  matrix_1(2, 2) = -3;

  true_result(0, 0) = 1;
  true_result(0, 1) = -1;
  true_result(0, 2) = 1;
  true_result(1, 0) = -38;
  true_result(1, 1) = 41;
  true_result(1, 2) = -34;
  true_result(2, 0) = 27;
  true_result(2, 1) = -29;
  true_result(2, 2) = 24;
  matrix_2 = matrix_1.InverseMatrix();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_NEAR(matrix_2(i, j), true_result(i, j), S21MATRIX_DELTA);
    }
  }
}

TEST(S21Matrix, MethodInverseMatrix3) {
  S21Matrix matrix_1(4, 4);
  EXPECT_THROW(
      {
        matrix_1.InverseMatrix();
        throw std::domain_error(
            "Incorrect value determinant must not be equal 0");
      },
      std::domain_error);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}