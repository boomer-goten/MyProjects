#include <vector>

class Path {
 public:
  vector<vector<int>>& get_path(const int (&start_arg)[2],
                                const int (&finish_arg)[2],
                                const vector<vector<int>>& vertical,
                                const vector<vector<int>>& horizontal);

 private:
  int rows_ = 0, cols_ = 0;
  const vector<vector<int>>* vertical_;
  const vector<vector<int>>* horizontal_;
  vector<vector<int>> maze_;
  vector<vector<int>> path_;
  bool TryLeftRight(int i, int j, int step) const;
  bool TryTopBottom(int i, int j, int step) const;
  bool TryAllWays(int i, int j, int current);
  bool FindShortestPath(const int (&start_arg)[2], const int (&finish_arg)[2]);
};

inline vector<vector<int>>& Path::get_path(
    const int (&start_arg)[2], const int (&finish_arg)[2],
    const vector<vector<int>>& vertical,
    const vector<vector<int>>& horizontal) {
  maze_.clear();
  path_.clear();
  vertical_ = &vertical;
  horizontal_ = &horizontal;
  if (!FindShortestPath(start_arg, finish_arg)) {
    return path_;
  }
  int i = finish_arg[0], j = finish_arg[1];
  int& current_num = maze_[i][j];
  int& start = maze_[start_arg[0]][start_arg[1]];
  path_.push_back({i, j});
  do {
    if (TryLeftRight(i, j, 0) && maze_[i][j + 1] == current_num - 1) {
      ++j;
    } else if (TryLeftRight(i, j, -1) && maze_[i][j - 1] == current_num - 1) {
      --j;
    } else if (TryTopBottom(i, j, 0) && maze_[i + 1][j] == current_num - 1) {
      ++i;
    } else if (TryTopBottom(i, j, -1) && maze_[i - 1][j] == current_num - 1) {
      --i;
    }
    --current_num;
    path_.push_back({i, j});
  } while (current_num != start);
  return path_;
}

inline bool Path::FindShortestPath(const int (&start_arg)[2],
                                   const int (&finish_arg)[2]) {
  rows_ = vertical_->size();
  cols_ = vertical_->at(0).size();
  maze_ = vector<vector<int>>(rows_, vector<int>(cols_, -2));
  int& start = maze_[start_arg[0]][start_arg[1]];
  int& finish = maze_[finish_arg[0]][finish_arg[1]];
  int current = 0, result = 0;
  start = 0;
  do {
    result = 0;
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) {
        if (maze_[i][j] == current) result += TryAllWays(i, j, current);
      }
    ++current;
  } while (finish < 0 && result != 0);
  return finish >= 0;
}

inline bool Path::TryLeftRight(int i, int j, int step) const {
  if (j + step < 0 || j + step >= cols_) return false;
  if ((*vertical_)[i][j + step] == 1) {
    return false;
  }
  return true;
}

inline bool Path::TryTopBottom(int i, int j, int step) const {
  if (i + step < 0 || i + step >= rows_) return false;
  if ((*horizontal_)[i + step][j] == 1) {
    return false;
  }
  return true;
}

inline bool Path::TryAllWays(int i, int j, int current) {
  bool res = 0;
  if (TryLeftRight(i, j, 0) && maze_[i][j + 1] != current - 1) {
    res = 1;
    maze_[i][j + 1] = current + 1;
  }
  if (TryLeftRight(i, j, -1) && maze_[i][j - 1] != current - 1) {
    res = 1;
    maze_[i][j - 1] = current + 1;
  }
  if (TryTopBottom(i, j, 0) && maze_[i + 1][j] != current - 1) {
    res = 1;
    maze_[i + 1][j] = current + 1;
  }
  if (TryTopBottom(i, j, -1) && maze_[i - 1][j] != current - 1) {
    res = 1;
    maze_[i - 1][j] = current + 1;
  }
  return res;
}
