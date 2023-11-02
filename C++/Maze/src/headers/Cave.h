#pragma once

#include <random>

#include "Table.h"

template <>
class Table<Cave> {
 public:
  Table() : columns_(0), rows_(0) {}
  ~Table() {}
  void get_tables(vector<vector<int>>& first_vector) const noexcept {
    first_vector = first_vector_;
  }
  void set_tables(vector<vector<int>>& first_vector) noexcept {
    first_vector_ = first_vector;
    set_size();
  }
  void InitializeRandomCave(const size_t& rows, const size_t& columns,
                            const int& chance_initialization);
  void OneStepGeneration(const int& limit_life, const int& limit_death);
  void GenerateCave(const int& limit_life, const int& limit_death);
  const size_t& get_rows() const noexcept { return rows_; }
  const size_t& get_columns() const noexcept { return columns_; }
  void set_size() noexcept {
    rows_ = first_vector_.size();
    columns_ = 0;
    if (rows_ > 0) {
      columns_ = first_vector_[0].size();
    }
  }

 private:
  size_t columns_;
  size_t rows_;
  vector<vector<int>> first_vector_;
  void CreateMatrix(const size_t& rows, const size_t& columns);
  int CheckIndex(const int row, const int col) const noexcept;
  int CountLiveAround(const int& row, const int& col);
};

void Table<Cave>::InitializeRandomCave(const size_t& rows,
                                       const size_t& columns,
                                       const int& chance_initialization) {
  CreateMatrix(rows, columns);
  std::default_random_engine random_value(time(nullptr));
  std::uniform_int_distribution<int> distribution(0, 100);
  for (int i = 0; i < (int)rows; ++i) {
    auto generateRandomNumber = [&]() {
      return chance_initialization >= distribution(random_value) ? 1 : 0;
    };
    std::generate(first_vector_[i].begin(), first_vector_[i].end(),
                  generateRandomNumber);
  }
}

void Table<Cave>::CreateMatrix(const size_t& rows, const size_t& columns) {
  first_vector_ = vector<vector<int>>(rows, vector<int>(columns));
  rows_ = rows;
  columns_ = columns;
}

void Table<Cave>::GenerateCave(const int& limit_life, const int& limit_death) {
  if (first_vector_.empty()) {
    return;
  }
  int count_generations = 40;
  for (int generation = 0; generation < count_generations; ++generation) {
    OneStepGeneration(limit_life, limit_death);
  }
}

void Table<Cave>::OneStepGeneration(const int& limit_life,
                                    const int& limit_death) {
  if (first_vector_.empty()) {
    return;
  }
  vector<vector<int>> tmp(rows_, vector<int>(columns_));
  for (int i = 0; i < (int)rows_; ++i) {
    for (int j = 0; j < (int)columns_; ++j) {
      int count = CountLiveAround(i, j);
      if (first_vector_[i][j] == 1 && count < limit_death)
        tmp[i][j] = 0;
      else if (first_vector_[i][j] == 0 && count > limit_life)
        tmp[i][j] = 1;
      else
        tmp[i][j] = first_vector_[i][j];
    }
  }
  first_vector_ = tmp;
}

int Table<Cave>::CountLiveAround(const int& row, const int& col) {
  return CheckIndex(row - 1, col - 1) + CheckIndex(row - 1, col) +
         CheckIndex(row - 1, col + 1) + CheckIndex(row, col - 1) +
         CheckIndex(row, col + 1) + CheckIndex(row + 1, col - 1) +
         CheckIndex(row + 1, col) + CheckIndex(row + 1, col + 1);
}

int Table<Cave>::CheckIndex(const int row, const int col) const noexcept {
  if (row < 0 || row >= (int)rows_ || col < 0 || col >= (int)columns_) {
    return 1;
  } else {
    return first_vector_[row][col];
  }
}
