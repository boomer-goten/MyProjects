#include <gtest/gtest.h>

#include <vector>

#include "../headers/Controller.h"

TEST(Path, No_path) {
  Controller controller;
  const string file = "tests/lab_path_test_1.txt";
  controller.ReadMazeFile(file);
  vector<vector<int>> path;
  controller.FindPath({0, 3}, {2, 2}, path);
  ASSERT_EQ(path.size(), 0);
}

TEST(Path, path_1) {
  Controller controller;
  const string file = "tests/lab_path_test_1.txt";
  controller.ReadMazeFile(file);
  vector<vector<int>> path;
  controller.FindPath({0, 0}, {2, 3}, path);
  ASSERT_EQ(path.size(), 6);
}

TEST(Path, path_2) {
  Controller controller;
  const string file = "examples/lab.txt";
  controller.ReadMazeFile(file);
  vector<vector<int>> path;
  controller.FindPath({0, 0}, {2, 3}, path);
  ASSERT_EQ(path.size(), 16);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
