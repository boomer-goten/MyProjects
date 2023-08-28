#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodTranspose1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_2(j, i));
    }
  }
}

TEST(S21Matrix, MethodTranspose2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_2(j, i));
    }
  }
}

TEST(S21Matrix, MethodTranspose4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
    }
  }
  matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_2(j, i));
    }
  }
}

TEST(S21Matrix, MethodTranspose5) {
  S21Matrix matrix_1(2, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
    }
  }
  matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_2(j, i));
    }
  }
}

TEST(S21Matrix, MethodTranspose6) {
  S21Matrix matrix_1(4, 2);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  matrix_2 = matrix_1.Transpose();
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_2(j, i));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}