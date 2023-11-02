#include <gtest/gtest.h>

#include <vector>

#include "../headers/Controller.h"

TEST(Cave, Init_cave_1) {
  Controller controller;
  controller.InitCave(1, 1, 0);
  int rows, cols;
  vector<vector<int>> data;
  controller.get_data(rows, cols, data);
  vector<vector<int>> tru_vector = {{0}};
  ASSERT_TRUE(data == tru_vector);
}

TEST(Cave, Genarate_cave_1) {
  Controller controller;
  const string read = "examples/cave.txt";
  controller.ReadCaveFile(read);
  int limit_life = 4;
  int limit_death = 3;
  controller.OneStepGeneration(limit_life, limit_death);
  int rows, cols;
  vector<vector<int>> data;
  controller.get_data(rows, cols, data);
  vector<vector<int>> tru_vector = {
      {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}, {0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
      {0, 0, 1, 1, 1, 1, 1, 0, 0, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
      {1, 0, 1, 1, 1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, {1, 1, 1, 0, 1, 1, 1, 1, 0, 1}};
  ASSERT_TRUE(data == tru_vector);
}

TEST(Cave, Genarate_cave_2) {
  Controller controller;
  const string read = "examples/cave_3.txt";
  controller.ReadCaveFile(read);
  int limit_life = 2;
  int limit_death = 5;
  for (int i = 0; i < 19; i++) {
    controller.OneStepGeneration(limit_life, limit_death);
  }
  int rows, cols;
  vector<vector<int>> data;
  controller.get_data(rows, cols, data);
  vector<vector<int>> tru_vector(50, vector<int>(50, 1));
  ASSERT_TRUE(data == tru_vector);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
