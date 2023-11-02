#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Table.h"

using std::ifstream;
using std::invalid_argument;
using std::istringstream;
using std::string;
using std::vector;

template <FilenameType T>
class FileReader {
  FileReader() = delete;
  FileReader(const FileReader&) = delete;
  FileReader& operator=(const FileReader&) = delete;
};

template <>
class FileReader<Cave> {
 public:
  FileReader() = delete;
  FileReader(const FileReader&) = delete;
  FileReader& operator=(const FileReader&) = delete;
  static void CheckFile(const string& path);
  static Table<Cave> ReadFile(const string& path);
  static void ReadMatrix(vector<vector<int>>& matrix, const size_t& rows,
                         const size_t& columns, ifstream& stream);
};

template <>
class FileReader<Maze> {
 public:
  FileReader() = delete;
  FileReader(const FileReader&) = delete;
  FileReader& operator=(const FileReader&) = delete;
  static void CheckFile(const string& path);
  static void BaseCheckFile(const string& path, int& rows, int& cols,
                            string& first_string, int& size_file,
                            int& size_first_string);
  static Table<Maze> ReadFile(const string& path);
};

Table<Cave> FileReader<Cave>::ReadFile(const string& path) {
  CheckFile(path);
  std::ifstream file_table(path);
  string line{};
  getline(file_table, line);
  size_t columns{};
  size_t rows{};
  istringstream stream_line(line);
  stream_line >> rows >> columns;
  if (rows > 50 || columns > 50 || rows < 1 || columns < 1) {
    file_table.close();
    throw invalid_argument("Размер столбцов и строк не должно превышать 50");
  }
  vector<vector<int>> first_matrix(rows, vector<int>(columns));
  ReadMatrix(first_matrix, rows, columns, file_table);
  Table<Cave> table;
  table.set_tables(first_matrix);
  file_table.close();
  return table;
}

Table<Maze> FileReader<Maze>::ReadFile(const string& path) {
  CheckFile(path);
  std::ifstream file_table(path);
  string line{};
  getline(file_table, line);
  size_t columns{};
  size_t rows{};
  istringstream stream_line(line);
  stream_line >> rows >> columns;
  if (rows > 50 || columns > 50 || rows < 1 || columns < 1) {
    file_table.close();
    throw invalid_argument("Размер столбцов и строк не должно превышать 50");
  }
  vector<vector<int>> first_matrix(rows, vector<int>(columns));
  vector<vector<int>> second_matrix(rows, vector<int>(columns));
  FileReader<Cave>::ReadMatrix(first_matrix, rows, columns, file_table);
  file_table.ignore();
  FileReader<Cave>::ReadMatrix(second_matrix, rows, columns, file_table);
  Table<Maze> table;
  table.set_tables(first_matrix, second_matrix);
  file_table.close();
  return table;
}

void FileReader<Cave>::ReadMatrix(vector<vector<int>>& matrix,
                                  const size_t& rows, const size_t& columns,
                                  ifstream& stream) {
  string number_line;
  for (int i = 0; i < (int)rows; i++) {
    getline(stream, number_line);
    istringstream string_stream(number_line);
    for (int j = 0; j < (int)columns; j++) {
      string_stream >> matrix[i][j];
      if (matrix[i][j] != 0 && matrix[i][j] != 1) {
        stream.close();
        throw invalid_argument("Некорректный файл");
      }
    }
  }
}

void FileReader<Cave>::CheckFile(const string& path) {
  int rows{}, cols{}, file_size{}, size_first_string{};
  string first_string{};
  FileReader<Maze>::BaseCheckFile(path, rows, cols, first_string, file_size,
                                  size_first_string);
  if (2 * rows * cols != file_size - size_first_string) {
    throw invalid_argument("Некорректный файл");
  }
}

void FileReader<Maze>::CheckFile(const string& path) {
  int rows{}, cols{}, file_size{}, size_first_string{};
  string first_string{};
  BaseCheckFile(path, rows, cols, first_string, file_size, size_first_string);
  if (4 * rows * cols != file_size - size_first_string - 1) {
    throw invalid_argument("Некорректный файл");
  }
}

void FileReader<Maze>::BaseCheckFile(const string& path, int& rows, int& cols,
                                     string& first_string, int& size_file,
                                     int& size_first_string) {
  std::ifstream file(path, std::ios::binary);
  if (!file) {
    throw invalid_argument("Не удалось открыть файл");
  }
  std::getline(file, first_string);
  std::istringstream stream_l(first_string);
  stream_l >> rows >> cols;
  if (!rows || !cols) {
    file.close();
    throw invalid_argument("Некорректный файл");
  }
  size_first_string = sizeof(first_string[0]) * first_string.size();
  file.seekg(0, std::ios::end);
  size_file = static_cast<int>(file.tellg());
  file.close();
}
