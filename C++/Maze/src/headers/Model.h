#pragma once

#include <iostream>
#include <vector>

#include "Cave.h"
#include "Loader.h"
#include "Maze.h"
#include "Path.h"
#include "Reader.h"

using std::string;
using std::vector;

class Model {
 public:
  Model();
  ~Model();
  void ReadMazeFile(const string& path);
  void ReadCaveFile(const string& path);
  bool SaveMazeFile(const string& path);
  bool SaveCaveFile(const string& path);
  void get_data(vector<vector<int>>& first_vector,
                vector<vector<int>>& second_vector) const noexcept {
    maze_table_.get_tables(first_vector, second_vector);
  }
  void get_data(vector<vector<int>>& first_vector) const noexcept {
    cave_table_.get_tables(first_vector);
  }
  const size_t& get_maze_rows() const noexcept {
    return maze_table_.get_rows();
  }
  const size_t& get_maze_columns() const noexcept {
    return maze_table_.get_columns();
  }
  const size_t& get_cave_rows() const noexcept {
    return cave_table_.get_rows();
  }
  const size_t& get_cave_columns() const noexcept {
    return cave_table_.get_columns();
  }
  void GenerateLabirynth(const size_t& rows, const size_t& columns) noexcept {
    maze_table_.GenerateLabirynth(rows, columns);
  }
  void OneStepGeneration(const int& limit_life, const int& limit_death) {
    cave_table_.OneStepGeneration(limit_life, limit_death);
  }
  void GenerateCave(const int& limit_life, const int& limit_death) {
    cave_table_.GenerateCave(limit_life, limit_death);
  }
  void InitCave(const size_t& rows, const size_t& columns,
                const int& chance_initialization) {
    cave_table_.InitializeRandomCave(rows, columns, chance_initialization);
  }
  vector<vector<int>>& FindPath(const int (&start_arg)[2],
                                const int (&finish_arg)[2]) {
    vector<vector<int>> vertical;
    vector<vector<int>> horizontal;
    maze_table_.get_tables(vertical, horizontal);
    return path_.get_path(start_arg, finish_arg, vertical, horizontal);
  }

 private:
  Table<Maze> maze_table_;
  Table<Cave> cave_table_;
  Path path_;
};

Model::Model() : maze_table_(), cave_table_() {}

Model::~Model() {}

void Model::ReadMazeFile(const string& path) {
  maze_table_ = FileReader<Maze>::ReadFile(path);
}

void Model::ReadCaveFile(const string& path) {
  cave_table_ = FileReader<Cave>::ReadFile(path);
}

bool Model::SaveMazeFile(const string& path) {
  return FileLoader<Maze>::LoadFile(path, maze_table_);
}

bool Model::SaveCaveFile(const string& path) {
  return FileLoader<Cave>::LoadFile(path, cave_table_);
}
