#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodCalcComplements1) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix true_result;
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 0;
  matrix_1(1, 1) = 4;
  matrix_1(1, 2) = 2;
  matrix_1(2, 0) = 5;
  matrix_1(2, 1) = 2;
  matrix_1(2, 2) = 1;

  true_result(0, 0) = 0;
  true_result(0, 1) = 10;
  true_result(0, 2) = -20;
  true_result(1, 0) = 4;
  true_result(1, 1) = -14;
  true_result(1, 2) = 8;
  true_result(2, 0) = -8;
  true_result(2, 1) = -2;
  true_result(2, 2) = 4;
  matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), true_result(i, j));
    }
  }
}

TEST(S21Matrix, MethodCalcComplements2) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix true_result;
  matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), true_result(i, j));
    }
  }
}

TEST(S21Matrix, MethodCalcComplements3) {
  S21Matrix matrix_1(3, 4);
  EXPECT_THROW(
      {
        matrix_1.CalcComplements();
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, MethodCalcComplements4) {
  S21Matrix matrix_1;
  S21Matrix matrix_2;
  S21Matrix true_result;
  matrix_1(0, 0) = 3;
  matrix_1(0, 1) = 4;
  matrix_1(0, 2) = -2;
  matrix_1(1, 0) = -2;
  matrix_1(1, 1) = 1;
  matrix_1(1, 2) = 0;
  matrix_1(2, 0) = 2;
  matrix_1(2, 1) = 3;
  matrix_1(2, 2) = 0;

  true_result(0, 0) = 0;
  true_result(0, 1) = 0;
  true_result(0, 2) = -8;
  true_result(1, 0) = -6;
  true_result(1, 1) = 4;
  true_result(1, 2) = -1;
  true_result(2, 0) = 2;
  true_result(2, 1) = 4;
  true_result(2, 2) = 11;
  matrix_2 = matrix_1.CalcComplements();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), true_result(i, j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}