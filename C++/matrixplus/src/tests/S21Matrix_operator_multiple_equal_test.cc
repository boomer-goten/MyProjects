#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorMultiplicationAssignment1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  matrix_1 *= matrix_2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorMultiplicationAssignment2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  matrix_1 *= matrix_2;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorMultiplicationAssignment3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  EXPECT_THROW(
      {
        matrix_1 *= matrix_2;
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, OperatorMultiplicationAssignment4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
      matrix_2(i, j) = i;
    }
  }
  matrix_1 *= matrix_2;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 6 * i);
    }
  }
}

TEST(S21Matrix, OperatorMultiplicationAssignment5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
      matrix_2(i, j) = j;
    }
  }
  matrix_1 *= matrix_2;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), 6 * j);
    }
  }
}

TEST(S21Matrix, OperatorMultiplicationAssignment6) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  matrix_1 *= matrix_2;
  S21Matrix matrix_1_true(matrix_1);
  matrix_1_true(0, 0) = 5;
  matrix_1_true(0, 1) = 8;
  matrix_1_true(0, 2) = 11;
  matrix_1_true(1, 0) = 8;
  matrix_1_true(1, 1) = 14;
  matrix_1_true(1, 2) = 20;
  matrix_1_true(2, 0) = 11;
  matrix_1_true(2, 1) = 20;
  matrix_1_true(2, 2) = 29;
  for (int i = 0; i < matrix_1.getRows(); i++) {
    for (int j = 0; j < matrix_1.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(matrix_1(i, j), matrix_1_true(i, j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}