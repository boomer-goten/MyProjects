#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Cave.h"
#include "Maze.h"

using std::invalid_argument;
using std::istringstream;
using std::ofstream;
using std::string;
using std::vector;

template <FilenameType T>
class FileLoader {
  FileLoader() = delete;
  FileLoader(const FileLoader&) = delete;
  FileLoader& operator=(const FileLoader&) = delete;
};

template <>
class FileLoader<Cave> {
 public:
  FileLoader() = delete;
  FileLoader(const FileLoader&) = delete;
  FileLoader& operator=(const FileLoader&) = delete;
  static bool LoadFile(const string& path, Table<Cave>& cave_table);
  static void SaveMatrix(ofstream& stream, const vector<vector<int>>& vector);
};

template <>
class FileLoader<Maze> {
 public:
  FileLoader() = delete;
  FileLoader(const FileLoader&) = delete;
  FileLoader& operator=(const FileLoader&) = delete;
  static bool LoadFile(const string& path, Table<Maze>& maze_table);
};

bool FileLoader<Cave>::LoadFile(const string& path, Table<Cave>& cave_table) {
  ofstream file_saver(path);
  if (!file_saver.is_open()) return false;
  file_saver << cave_table.get_rows() << ' ' << cave_table.get_columns()
             << '\n';
  vector<vector<int>> first_vector;
  cave_table.get_tables(first_vector);
  SaveMatrix(file_saver, first_vector);
  file_saver.close();
  return true;
}

bool FileLoader<Maze>::LoadFile(const string& path, Table<Maze>& maze_table) {
  ofstream file_saver(path);
  if (!file_saver.is_open()) return false;
  file_saver << maze_table.get_rows() << ' ' << maze_table.get_columns()
             << '\n';
  vector<vector<int>> first_vector;
  vector<vector<int>> second_vector;
  maze_table.get_tables(first_vector, second_vector);
  FileLoader<Cave>::SaveMatrix(file_saver, first_vector);
  file_saver << '\n' << '\n';
  FileLoader<Cave>::SaveMatrix(file_saver, second_vector);
  file_saver.close();
  return true;
}

void FileLoader<Cave>::SaveMatrix(ofstream& stream,
                                  const vector<vector<int>>& vector) {
  for (size_t row = 0; row != vector.size(); ++row) {
    for (size_t col = 0; col != vector[0].size(); ++col) {
      stream << vector[row][col];
      if (col != vector[0].size() - 1) stream << ' ';
    }
    if (row != vector.size() - 1) stream << '\n';
  }
}
