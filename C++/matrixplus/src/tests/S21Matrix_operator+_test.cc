#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorAddition1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  S21Matrix result = matrix_1 + matrix_2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorAddition2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  S21Matrix result = matrix_1 + matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorAddition3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  EXPECT_THROW(
      {
        S21Matrix result = matrix_1 + matrix_2;
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, OperatorAddition4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
      matrix_2(i, j) = i;
    }
  }
  S21Matrix result = matrix_1 + matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 2 * i);
    }
  }
}

TEST(S21Matrix, OperatorAddition5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
      matrix_2(i, j) = j;
    }
  }
  S21Matrix result = matrix_1 + matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 2 * j);
    }
  }
}

TEST(S21Matrix, OperatorAddition6) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  S21Matrix result = matrix_1 + matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 2 * (i + j));
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}