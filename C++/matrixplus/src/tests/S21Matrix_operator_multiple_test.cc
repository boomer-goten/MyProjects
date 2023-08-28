#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorMultiplication1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  S21Matrix result = matrix_1 * matrix_2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorMultiplication2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  S21Matrix result = matrix_1 * matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorMultiplication3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  EXPECT_THROW(
      {
        S21Matrix result = matrix_1 * matrix_2;
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, OperatorMultiplication4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
      matrix_2(i, j) = i;
    }
  }
  S21Matrix result = matrix_1 * matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 6 * i);
    }
  }
}

TEST(S21Matrix, OperatorMultiplication5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
      matrix_2(i, j) = j;
    }
  }
  S21Matrix result = matrix_1 * matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 6 * j);
    }
  }
}

TEST(S21Matrix, OperatorMultiplication6) {
  S21Matrix matrix_1(3, 3);
  S21Matrix matrix_2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  S21Matrix result = matrix_1 * matrix_2;
  S21Matrix result_true(result);
  result_true(0, 0) = 5;
  result_true(0, 1) = 8;
  result_true(0, 2) = 11;
  result_true(1, 0) = 8;
  result_true(1, 1) = 14;
  result_true(1, 2) = 20;
  result_true(2, 0) = 11;
  result_true(2, 1) = 20;
  result_true(2, 2) = 29;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), result_true(i, j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}