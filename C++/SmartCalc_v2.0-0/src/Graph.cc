#include "headers/Graph.h"

#include "QVector"
#include "ui_Graph.h"

namespace s21 {
Graph::Graph(Controller *controller, std::string expression, QWidget *parent)
    : QWidget(parent),
      controller_(controller),
      ui(new Ui::Graph),
      expression_(expression) {
  ui->setupUi(this);
  x_max_range_ = 10;
  x_min_range_ = -10;
  y_max_range_ = 10;
  y_min_range_ = -10;
  PrintGraph();
}

Graph::~Graph() { delete ui; }

void Graph::on_reduce_scale_clicked() {
  if (x_max_range_ != 1) {
    x_max_range_ /= 10;
    x_min_range_ /= 10;
    y_max_range_ /= 10;
    y_min_range_ /= 10;
    SetScales();
    ui->increase_scale->setEnabled(true);
    ui->widget->replot();
    PrintGraph();
  }
  if (x_max_range_ == 1) {
    ui->reduce_scale->setEnabled(false);
  }
}

void Graph::on_increase_scale_clicked() {
  if (x_max_range_ != 1000000) {
    x_max_range_ *= 10;
    x_min_range_ *= 10;
    y_max_range_ *= 10;
    y_min_range_ *= 10;
    SetScales();
    ui->reduce_scale->setEnabled(true);
    PrintGraph();
  }
  if (x_max_range_ == 1000000) {
    ui->increase_scale->setEnabled(false);
  }
}

void Graph::SetScales() {
  ui->widget->xAxis->setRange(x_min_range_, x_max_range_);
  ui->widget->yAxis->setRange(y_min_range_, y_max_range_);
}

void Graph::PrintGraph() {
  try {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    ui->notification->setText("График построен");
    QVector<double> x_vector, y_vecotr;
    if (expression_.empty()) {
      expression_ = "0";
    }
    double height = (x_max_range_ - x_min_range_) / 5000.0;
    double x = x_min_range_;
    while (x <= x_max_range_) {
      x_vector.push_back(x);
      std::string x_value = std::to_string(x);
      std::string result =
          controller_->CalculateExpression(std::string(expression_), x_value);
      y_vecotr.push_back(std::stod(result));
      x += height;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x_vector, y_vecotr);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    SetScales();
    ui->widget->replot();
  } catch (...) {
    ui->notification->setText("Выражение некорректно");
  }
}
}  // namespace s21
