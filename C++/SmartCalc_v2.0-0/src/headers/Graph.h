#ifndef CALC_HEADERS_GRAPH_H_
#define CALC_HEADERS_GRAPH_H_

#include <QWidget>
#include <clocale>

#include "Controller.h"

namespace Ui {
class Graph;
}

namespace s21 {
class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(Controller *controller, std::string expression,
                 QWidget *parent = nullptr);
  ~Graph();

 private slots:
  void on_reduce_scale_clicked();

  void on_increase_scale_clicked();

 private:
  Controller *controller_;
  Ui::Graph *ui;
  int x_max_range_;
  int x_min_range_;
  int y_max_range_;
  int y_min_range_;
  std::string expression_;

  void SetScales();
  void PrintGraph();
};
}  // namespace s21

#endif  // CALC_HEADERS_GRAPH_H_
