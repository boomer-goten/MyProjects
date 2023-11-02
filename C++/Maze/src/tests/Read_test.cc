#include <gtest/gtest.h>

#include <vector>

#include "../headers/Controller.h"

bool compareFiles(const std::string& file1, const std::string& file2) {
  std::ifstream stream1(file1, std::ios::binary);
  std::ifstream stream2(file2, std::ios::binary);
  if (!stream1.is_open() || !stream2.is_open()) {
    return false;
  }
  char c1, c2;
  while (stream1.get(c1) && stream2.get(c2)) {
    if (c1 != c2) {
      return false;
    }
  }
  return true;
}

TEST(Maze, ReadLoad_lab_1) {
  Controller controller;
  const string read = "examples/test_lab.txt";
  const string save = "output/test_output_lab.txt";
  controller.ReadMazeFile(read);
  controller.SaveMazeFile(save);
  int rows, cols;
  vector<vector<int>> vertical, horizontal;
  controller.get_data(rows, cols, vertical, horizontal);
  ASSERT_TRUE(compareFiles(read, save));
  ASSERT_TRUE(rows == 5 && cols == 5);
}

TEST(Maze, ReadLoad_lab_2) {
  Controller controller;
  const string read = "examples/test_lab.txt";
  const string save = "output/test_output_lab1.txt";
  controller.ReadMazeFile(read);
  controller.SaveMazeFile(save);
  ASSERT_TRUE(compareFiles(read, save));
}

TEST(Maze, ReadLoad_cave) {
  Controller controller;
  const string read = "examples/cave.txt";
  const string save = "output/test_output_cave.txt";
  controller.ReadCaveFile(read);
  controller.SaveCaveFile(save);
  int rows, cols;
  vector<vector<int>> vertical;
  controller.get_data(rows, cols, vertical);
  ASSERT_TRUE(compareFiles(read, save));
  ASSERT_TRUE(rows == 10 && cols == 10);
}

TEST(Maze, ReadLoad_cave_2) {
  Controller controller;
  const string read = "examples/cave.txt";
  const string save = "output/test_output_cave1.txt";
  controller.ReadCaveFile(read);
  controller.SaveCaveFile(save);
  ASSERT_TRUE(compareFiles(read, save));
}

TEST(Maze, ReadLoad_lab_exception) {
  Controller controller;
  const string read = "examples/lol.txt";
  vector<vector<int>> vertical;
  vector<vector<int>> horizontal;
  std::string error_str = controller.ReadMazeFile(read);
  ASSERT_TRUE(!error_str.empty());
}

TEST(Maze, ReadLoad_cave_exception) {
  Controller controller;
  const string read = "examples/lol.txt";
  std::string error_str = controller.ReadCaveFile(read);
  ASSERT_TRUE(!error_str.empty());
}

TEST(Maze, ReadLoad_lab_rows) {
  Controller controller;
  const string read = "tests/false_lab_test.txt";
  std::string error_str = controller.ReadMazeFile(read);
  ASSERT_TRUE(!error_str.empty());
}

TEST(Maze, ReadLoad_cave_rows) {
  Controller controller;
  const string read = "tests/false_lab_test.txt";
  std::string error_str = controller.ReadCaveFile(read);
  ASSERT_TRUE(!error_str.empty());
}

TEST(Maze, ReadLoad_lab_rows_miss) {
  Controller controller;
  const string read = "tests/false_lab_test_1.txt";
  std::string error_str = controller.ReadMazeFile(read);
  ASSERT_TRUE(!error_str.empty());
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
