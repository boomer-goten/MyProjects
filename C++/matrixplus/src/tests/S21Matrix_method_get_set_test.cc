#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"
double** CreateMatrix(int& rows, int& columns);

TEST(S21Matrix, MethodgetMatrix1) {
  S21Matrix matrix_1(2, 2);
  matrix_1.setRows(5);
  EXPECT_EQ(matrix_1.getRows(), 5);
}

TEST(S21Matrix, MethodgetMatrix2) {
  S21Matrix matrix_1(2, 2);
  matrix_1.setColumns(5);
  EXPECT_EQ(matrix_1.getColumns(), 5);
}

TEST(S21Matrix, MethodgetMatrix3) {
  S21Matrix matrix_1(2, 2);
  matrix_1.setRows(1);
  EXPECT_EQ(matrix_1.getRows(), 1);
}

TEST(S21Matrix, MethodgetMatrix4) {
  S21Matrix matrix_1(2, 2);
  matrix_1.setColumns(1);
  EXPECT_EQ(matrix_1.getColumns(), 1);
}

TEST(S21Matrix, MethodgetMatrix5) {
  S21Matrix matrix_1(4, 4);
  EXPECT_THROW(
      {
        matrix_1.setRows(-5);
        throw std::domain_error(
            "Incorrect input, the matrix must have the correct size");
      },
      std::domain_error);
}

TEST(S21Matrix, MethodgetMatrix6) {
  S21Matrix matrix_1(4, 4);
  EXPECT_THROW(
      {
        matrix_1.setColumns(-5);
        throw std::domain_error(
            "Incorrect input, the matrix must have the correct size");
      },
      std::domain_error);
}

TEST(S21Matrix, MethodgetMatrix7) {
  EXPECT_THROW(
      {
        S21Matrix matrix_1(-2, -2);
        throw std::domain_error(
            "Incorrect input, the matrix must have the correct size");
      },
      std::domain_error);
}

TEST(S21Matrix, MethodgetMatrix8) {
  int rows = 500000, columns = 500;
  double** matrix = nullptr;
  try {
    matrix = CreateMatrix(rows, columns);
  } catch (std::bad_alloc& error) {
    EXPECT_EQ(matrix, nullptr);
    EXPECT_EQ(rows, 0);
    EXPECT_EQ(columns, 0);
  }
}

TEST(S21Matrix, MethodgetMatrix9) {
  S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  S21Matrix matrix_2(std::move(matrix_1));

  ASSERT_EQ(matrix_2.getRows(), 3);
  ASSERT_EQ(matrix_2.getColumns(), 3);

  ASSERT_EQ(matrix_2(0, 0), 1);
  ASSERT_EQ(matrix_2(0, 1), 2);
  ASSERT_EQ(matrix_2(0, 2), 3);
  ASSERT_EQ(matrix_2(1, 0), 4);
  ASSERT_EQ(matrix_2(1, 1), 5);
  ASSERT_EQ(matrix_2(1, 2), 6);
  ASSERT_EQ(matrix_2(2, 0), 7);
  ASSERT_EQ(matrix_2(2, 1), 8);
  ASSERT_EQ(matrix_2(2, 2), 9);
}

TEST(S21Matrix, MethodgetMatrix10) {
  S21Matrix matrix_1(2, 2);
  EXPECT_THROW(
      {
        matrix_1(-2, -2) = 2;
        throw std::out_of_range(
            "Incorrect value, indexes are outside the array");
      },
      std::out_of_range);
}

TEST(S21Matrix, MethodgetMatrix11) {
  S21Matrix matrix_1(2, 2);
  matrix_1.setMatrixRandomValue();
  EXPECT_EQ(0, 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}