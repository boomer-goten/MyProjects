#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodMulNumber1) {
  S21Matrix matrix_1(2, 2);
  matrix_1.MulNumber(2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 0);
    }
  }
}

TEST(S21Matrix, MethodMulNumber2) {
  S21Matrix matrix_1(4, 4);
  matrix_1.MulNumber(3);
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 0);
    }
  }
}

TEST(S21Matrix, MethodMulNumber4) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
    }
  }
  matrix_1.MulNumber(6);
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 6 * i);
    }
  }
}

TEST(S21Matrix, MethodMulNumber5) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
    }
  }
  matrix_1.MulNumber(6);
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 6 * j);
    }
  }
}

TEST(S21Matrix, MethodMulNumber6) {
  S21Matrix matrix_1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
    }
  }
  matrix_1.MulNumber(-2);
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), -2 * (i + j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}