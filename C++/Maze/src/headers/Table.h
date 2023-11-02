#pragma once

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

enum FilenameType { Cave = 0, Maze = 1 };

using std::rand;
using std::size_t;
using std::srand;
using std::time;
using std::vector;

template <FilenameType T>
class Table {
  Table() = delete;
  Table(const Table&) = delete;
  Table& operator=(const Table&) = delete;
};
