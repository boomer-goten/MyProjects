#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, OperatorEqual1) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  bool result = (matrix_1 == matrix_2 ? 1 : 0);
  EXPECT_EQ(result, 1);
}

TEST(S21Matrix, OperatorEqual2) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  bool result = (matrix_1 == matrix_2 ? 1 : 0);
  EXPECT_EQ(result, 1);
}

TEST(S21Matrix, OperatorEqual3) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(3, 3);
  EXPECT_THROW(
      {
        matrix_1 == matrix_2;
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, OperatorEqual4) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
      matrix_2(i, j) = j;
    }
  }
  bool result = (matrix_1 == matrix_2 ? 1 : 0);
  EXPECT_EQ(result, 0);
}

TEST(S21Matrix, OperatorEqual5) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  bool result = (matrix_1 == matrix_2 ? 1 : 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
      matrix_2(i, j) = j;
    }
  }
  EXPECT_EQ(result, 1);
}

TEST(S21Matrix, OperatorEqual6) {
  S21Matrix matrix_1(4, 4);
  S21Matrix matrix_2(4, 4);
  bool result = (matrix_1 == matrix_2 ? 1 : 0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i + j;
      matrix_2(i, j) = i + j;
    }
  }
  EXPECT_EQ(result, 1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}