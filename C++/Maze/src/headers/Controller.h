#pragma once

#include "Model.h"

class Controller {
 public:
  Controller(){};
  ~Controller(){};
  std::string ReadMazeFile(const string& path) {
    try {
      model_.ReadMazeFile(path);
    } catch (const invalid_argument& e) {
      return std::string(e.what());
    }
    return "";
  }

  std::string ReadCaveFile(const string& path) {
    try {
      model_.ReadCaveFile(path);
    } catch (const invalid_argument& e) {
      return std::string(e.what());
    }
    return "";
  }

  bool SaveMazeFile(const string& path) { return model_.SaveMazeFile(path); }
  bool SaveCaveFile(const string& path) { return model_.SaveCaveFile(path); }
  void get_data(int& rows, int& cols,
                vector<vector<int>>& first_vector) const noexcept {
    rows = model_.get_cave_rows();
    cols = model_.get_cave_columns();
    model_.get_data(first_vector);
  }
  void get_data(int& rows, int& cols, vector<vector<int>>& first_vector,
                vector<vector<int>>& second_vector) {
    rows = model_.get_maze_rows();
    cols = model_.get_maze_columns();
    model_.get_data(first_vector, second_vector);
  }
  void GenerateLabirynth(const size_t& rows, const size_t& columns) noexcept {
    model_.GenerateLabirynth(rows, columns);
  }
  void OneStepGeneration(const int& limit_life, const int& limit_death) {
    model_.OneStepGeneration(limit_life, limit_death);
  }
  void InitCave(const size_t& rows, const size_t& columns,
                const int& chance_initialization) {
    model_.InitCave(rows, columns, chance_initialization);
  }
  void FindPath(const int (&start_arg)[2], const int (&finish_arg)[2],
                vector<vector<int>>& path) {
    path = model_.FindPath(start_arg, finish_arg);
  }

 private:
  Model model_;
};
