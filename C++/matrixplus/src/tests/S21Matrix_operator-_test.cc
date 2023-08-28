#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorSubtraction1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  S21Matrix result = matrix_1 - matrix_2;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorSubtraction2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  S21Matrix result = matrix_1 - matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), 0);
    }
  }
}

TEST(S21Matrix, OperatorSubtraction3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  EXPECT_THROW(
      {
        S21Matrix result = matrix_1 - matrix_2;
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, OperatorSubtraction4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = 2 * i;
      matrix_2(i, j) = i;
    }
  }
  S21Matrix result = matrix_1 - matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), i);
    }
  }
}

TEST(S21Matrix, OperatorSubtraction5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = 2 * j;
      matrix_2(i, j) = j;
    }
  }
  S21Matrix result = matrix_1 - matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), j);
    }
  }
}

TEST(S21Matrix, OperatorSubtraction6) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = 2 * (i + j);
      matrix_2(i, j) = i + j;
    }
  }
  S21Matrix result = matrix_1 - matrix_2;
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getColumns(); j++) {
      ASSERT_DOUBLE_EQ(result(i, j), i + j);
    }
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}