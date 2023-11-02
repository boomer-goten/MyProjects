#pragma once

#include "Table.h"

template <>
class Table<Maze> {
 public:
  Table() : columns_(0), rows_(0) {}
  ~Table() {}
  void get_tables(vector<vector<int>>& first_vector,
                  vector<vector<int>>& second_vector) const noexcept {
    first_vector = (const vector<vector<int>>)first_vector_;
    second_vector = (const vector<vector<int>>)second_vector_;
  }
  void set_tables(vector<vector<int>>& first_vector,
                  vector<vector<int>>& second_vector) noexcept {
    first_vector_ = first_vector;
    second_vector_ = second_vector;
    set_size();
  }
  void GenerateLabirynth(const size_t& rows, const size_t& columns) noexcept;
  const size_t& get_rows() const noexcept { return rows_; }
  const size_t& get_columns() const noexcept { return columns_; }

 private:
  size_t columns_;
  size_t rows_;
  vector<vector<int>> first_vector_;
  vector<vector<int>> second_vector_;

  void set_size() noexcept;
  void CreateMatrix(const size_t& rows, const size_t& columns);
  vector<int> InitailizeSerialVector() const;
  void FillFirstMatrixAndSetSets(vector<int>& vec, const int& index) noexcept;
  void FillSecondMatrix(vector<int>& vec, const int& index) noexcept;
  void BuildLastRow() noexcept;
  bool CheckExistZeroInSet(const int& start_set, vector<int>& vec,
                           const int& index) const noexcept;
  void SetRandomZeroInSet(const int& start_set, vector<int>& vec,
                          const int& index) noexcept;
  void Rebuild(vector<int>& vec, const int& index) const noexcept;
  int GetRandomValue() const noexcept;
  void MergeSets(const int& index, vector<int>& vec) const noexcept;
  void RemoveWalls(vector<int>& vec) noexcept;
};

void Table<Maze>::GenerateLabirynth(const size_t& rows,
                                    const size_t& columns) noexcept {
  srand(time(nullptr));
  CreateMatrix(rows, columns);
  vector<int> current_row(InitailizeSerialVector());
  for (int i = 0; i < (int)rows - 1; i++) {
    FillFirstMatrixAndSetSets(current_row, i);
    FillSecondMatrix(current_row, i);
    Rebuild(current_row, i);
  }
  BuildLastRow();
  FillFirstMatrixAndSetSets(current_row, rows_ - 1);
  RemoveWalls(current_row);
}

void Table<Maze>::CreateMatrix(const size_t& rows, const size_t& columns) {
  first_vector_ = vector<vector<int>>(rows, vector<int>(columns));
  second_vector_ = vector<vector<int>>(rows, vector<int>(columns));
  rows_ = rows;
  columns_ = columns;
}

vector<int> Table<Maze>::InitailizeSerialVector() const {
  vector<int> new_fill_vector(columns_);
  for (size_t i = 0; i < columns_; ++i) {
    new_fill_vector[i] = i + 1;
  }
  return new_fill_vector;
}

void Table<Maze>::FillFirstMatrixAndSetSets(vector<int>& vec,
                                            const int& index) noexcept {
  for (size_t i = 0; i < columns_ - 1; ++i) {
    if (vec[i] == vec[i + 1] || GetRandomValue()) {
      first_vector_[index][i] = 1;
    } else {
      MergeSets(i, vec);
    }
  }
  first_vector_[index][columns_ - 1] = 1;
}

void Table<Maze>::MergeSets(const int& index, vector<int>& vec) const noexcept {
  int value = vec[index + 1];
  for (int i = 0; i < (int)columns_; i++) {
    if (vec[i] == value) {
      vec[i] = vec[index];
    }
  }
}

int Table<Maze>::GetRandomValue() const noexcept { return std::rand() % 2; }

void Table<Maze>::FillSecondMatrix(vector<int>& vec,
                                   const int& index) noexcept {
  for (size_t i = 0; i < columns_; ++i) {
    if (GetRandomValue()) {
      if (std::count(vec.begin(), vec.end(), vec[i]) != 1) {
        second_vector_[index][i] = 1;
      }
      if (!CheckExistZeroInSet(i, vec, index)) {
        SetRandomZeroInSet(i, vec, index);
      }
    }
  }
}

bool Table<Maze>::CheckExistZeroInSet(const int& start_set, vector<int>& vec,
                                      const int& index) const noexcept {
  int value = vec[start_set];
  for (int i = 0; i < (int)columns_; ++i) {
    if (vec[i] == value && second_vector_[index][i] == 0) {
      return true;
    }
  }
  return false;
}

void Table<Maze>::SetRandomZeroInSet(const int& start_set, vector<int>& vec,
                                     const int& index) noexcept {
  int count_in_set = std::count(vec.begin(), vec.end(), vec[start_set]);
  int random_position = 1 + rand() % (count_in_set);
  int true_position = 0;
  for (int i = 0; i < (int)columns_; ++i) {
    if (vec[start_set] == vec[i]) {
      ++true_position;
    }
    if (true_position == random_position) {
      second_vector_[index][i] = 0;
      return;
    }
  }
}

void Table<Maze>::Rebuild(vector<int>& vec, const int& index) const noexcept {
  for (int i = 0; i < (int)columns_; ++i) {
    if (second_vector_[index][i] == 1) {
      vec[i] = 0;
    }
  }
  for (int i = 0; i < (int)columns_; ++i) {
    if (second_vector_[index][i] == 1) {
      vec[i] = *(std::max_element(vec.begin(), vec.end())) + 1;
    }
  }
}

void Table<Maze>::BuildLastRow() noexcept {
  for (int i = 0; i < (int)columns_; ++i) {
    second_vector_[rows_ - 1][i] = 1;
  }
}

void Table<Maze>::set_size() noexcept {
  rows_ = first_vector_.size();
  columns_ = 0;
  if (rows_ > 0) {
    columns_ = first_vector_[0].size();
  }
}

void Table<Maze>::RemoveWalls(vector<int>& vec) noexcept {
  for (int i = 0; i < (int)columns_ - 1; i++) {
    if (vec[i] != vec[i + 1]) {
      MergeSets(i, vec);
      first_vector_[rows_ - 1][i] = 0;
    }
  }
}