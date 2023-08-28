#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(S21Matrix, MethodDeterminant1) {
  S21Matrix matrix_1(2, 2);
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 0);
}

TEST(S21Matrix, MethodDeterminant2) {
  S21Matrix matrix_1(4, 4);
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 0);
}

TEST(S21Matrix, MethodDeterminant3) {
  S21Matrix matrix_1(3, 4);
  EXPECT_THROW(
      {
        matrix_1.Determinant();
        throw std::out_of_range(
            "Incorrect input, matrices should have the same size");
      },
      std::out_of_range);
}

TEST(S21Matrix, MethodDeterminant4) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = i;
    }
  }
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 0);
}

TEST(S21Matrix, MethodDeterminant5) {
  S21Matrix matrix_1(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_1(i, j) = j;
    }
  }
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 0);
}

TEST(S21Matrix, MethodDeterminant6) {
  S21Matrix matrix_1(4, 4);
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 3;
  matrix_1(0, 2) = 4;
  matrix_1(0, 3) = 7;
  matrix_1(1, 0) = 12;
  matrix_1(1, 1) = 8;
  matrix_1(1, 2) = 2;
  matrix_1(1, 3) = 7;
  matrix_1(2, 0) = 2;
  matrix_1(2, 1) = 9;
  matrix_1(2, 2) = 12;
  matrix_1(2, 3) = 15;
  matrix_1(3, 0) = 17;
  matrix_1(3, 1) = 18;
  matrix_1(3, 2) = 14;
  matrix_1(3, 3) = 11;
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, -1404);
}

TEST(S21Matrix, MethodDeterminant8) {
  S21Matrix matrix_1(4, 4);
  matrix_1(0, 0) = 0;
  matrix_1(0, 1) = 3;
  matrix_1(0, 2) = -1;
  matrix_1(0, 3) = 2;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 1;
  matrix_1(1, 2) = 0;
  matrix_1(1, 3) = 0;
  matrix_1(2, 0) = -2;
  matrix_1(2, 1) = -1;
  matrix_1(2, 2) = 0;
  matrix_1(2, 3) = 2;
  matrix_1(3, 0) = -5;
  matrix_1(3, 1) = 7;
  matrix_1(3, 2) = 1;
  matrix_1(3, 3) = 1;
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, 50);
}

TEST(S21Matrix, MethodDeterminant7) {
  S21Matrix matrix_1(4, 4);
  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 4;
  matrix_1(3, 2) = 5;
  matrix_1(2, 3) = 1;
  matrix_1(3, 3) = 1;
  double determinant = matrix_1.Determinant();
  ASSERT_DOUBLE_EQ(determinant, -20);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}