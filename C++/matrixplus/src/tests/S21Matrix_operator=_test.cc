#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorAssignment1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), matrix_1(i, j));
    }
  }
}

TEST(S21Matrix, OperatorAssignment2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), matrix_1(i, j));
    }
  }
}

TEST(S21Matrix, OperatorAssignment4) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
    }
  }
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), matrix_1(i, j));
    }
  }
}

TEST(S21Matrix, OperatorAssignment5) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
    }
  }
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), matrix_1(i, j));
    }
  }
}

TEST(S21Matrix, OperatorAssignment6) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i + j;
    }
  }
  S21Matrix matrix_2(4, 4);
  matrix_2 = matrix_1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_DOUBLE_EQ(matrix_2(i, j), matrix_1(i, j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}