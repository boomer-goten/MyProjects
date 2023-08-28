#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodEqMatrix1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 1);
}

TEST(S21Matrix, MethodEqMatrix2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 1);
}

TEST(S21Matrix, MethodEqMatrix3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 0);
}

TEST(S21Matrix, MethodEqMatrix4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
      matrix_2(i, j) = i;
    }
  }
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 1);
}

TEST(S21Matrix, MethodEqMatrix5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
      matrix_2(i, j) = j;
    }
  }
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 1);
}

TEST(S21Matrix, MethodEqMatrix6) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 1);
}

TEST(S21Matrix, MethodEqMatrix7) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = j;
    }
  }
  bool result_equal = matrix_1.EqMatrix(matrix_2);
  EXPECT_EQ(result_equal, 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}